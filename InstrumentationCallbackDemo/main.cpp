#include "windefs.h"

#include <map>
#include <DbgHelp.h>

#pragma comment(lib, "ntdll.lib")
#pragma comment (lib, "imagehlp.lib")

using namespace std; //fuck you im lazy
typedef void (*SyscallHook)(CONTEXT *context);

map<string, SyscallHook> Hooks;

using CallbackFn = void(*)();

using PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION = struct _PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION
{
	ULONG Version;
	ULONG Reserved;
	CallbackFn Callback;
};

using MEMORY_INFORMATION_CLASS = enum _MEMORY_INFORMATION_CLASS {
	MemoryBasicInformation
};


extern "C" VOID InstrumentationCallbackThunk(VOID);

extern "C" NTSTATUS DECLSPEC_IMPORT NTAPI NtSetInformationProcess(HANDLE, PROCESS_INFORMATION_CLASS, PVOID, ULONG);
extern "C" NTSTATUS DECLSPEC_IMPORT NTAPI NtQueryVirtualMemory(HANDLE, PVOID, MEMORY_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T);

PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION callback;

extern "C" void InstrumentationCallback(CONTEXT *context)
{
	TEB *teb = NtCurrentTeb();

	context->Rip = teb->InstrumentationCallbackPreviousPc;
	context->Rsp = teb->InstrumentationCallbackPreviousSp;
	context->Rcx = context->R10;

	// Prevent recursion
	if (!teb->InstrumentationCallbackDisabled) {
		teb->InstrumentationCallbackDisabled = TRUE;

		uint8_t buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME] = { 0 };
		const auto symbol_info = (PSYMBOL_INFO)buffer;
		symbol_info->SizeOfStruct = sizeof(SYMBOL_INFO);
		symbol_info->MaxNameLen = MAX_SYM_NAME;
		uintptr_t displacement;

		// MSDN: Retrieves symbol information for the specified address.
		const auto result = SymFromAddr(GetCurrentProcess(), context->Rip, &displacement, symbol_info); 
		for (pair<string, SyscallHook> sc : Hooks)
			if (!strcmp(sc.first.c_str(), symbol_info->Name))
				sc.second(context);

		teb->InstrumentationCallbackDisabled = FALSE;
	}

	RtlRestoreContext(context, NULL);
}

void QueryVirtualMemoryHook(CONTEXT *ctx) {
	printf("CALLED\n");
	ctx->Rax = 0xC00005;
}

int RunQueryExample() {
	MEMORY_BASIC_INFORMATION region = { nullptr };
	NTSTATUS r2 = NtQueryVirtualMemory(GetCurrentProcess(), GetModuleHandle(nullptr), MemoryBasicInformation, &region, sizeof(region), nullptr);

	printf("%X\n", r2);
}

int main()
{
	SymSetOptions(SYMOPT_UNDNAME);
	SymInitialize(GetCurrentProcess(), nullptr, TRUE);

	Hooks.emplace("NtQueryVirtualMemory", QueryVirtualMemoryHook);

	callback.Reserved = 0;
	callback.Version = 0;
	callback.Callback = InstrumentationCallbackThunk;

	NtSetInformationProcess(GetCurrentProcess(), (PROCESS_INFORMATION_CLASS)0x28, &callback, sizeof(callback));

	RunQueryExample();

	callback.Callback = nullptr;
	NtSetInformationProcess(GetCurrentProcess(), (PROCESS_INFORMATION_CLASS)0x28, &callback, sizeof(callback));

	printf("%X\n", r3);

	system("pause");
}