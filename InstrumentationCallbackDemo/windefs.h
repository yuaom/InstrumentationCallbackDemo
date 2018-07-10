#pragma once
#include <Windows.h>

typedef struct _CLIENT_ID                                                       // 2 / 2 elements; 0x0008 / 0x0010 Bytes
{
	PVOID                       UniqueProcess;                                  // 0x0000 / 0x0000; 0x0004 / 0x0008 Bytes
	PVOID                       UniqueThread;                                   // 0x0004 / 0x0008; 0x0004 / 0x0008 Bytes
} CLIENT_ID, *PCLIENT_ID;

typedef struct _PEB_LDR_DATA                                                    // 11 / 11 elements; 0x0030 / 0x0058 Bytes
{
	ULONG32                     Length;                                         // 0x0000 / 0x0000; 0x0004 / 0x0004 Bytes
	UINT8                       Initialized;                                    // 0x0004 / 0x0004; 0x0001 / 0x0001 Bytes
	UINT8                       _PADDING0_[3];                                  // 0x0005 / 0x0005; 0x0003 / 0x0003 Bytes
	PVOID                       SsHandle;                                       // 0x0008 / 0x0008; 0x0004 / 0x0008 Bytes
	LIST_ENTRY                  InLoadOrderModuleList;                          // 0x000C / 0x0010; 0x0008 / 0x0010 Bytes
	LIST_ENTRY                  InMemoryOrderModuleList;                        // 0x0014 / 0x0020; 0x0008 / 0x0010 Bytes
	LIST_ENTRY                  InInitializationOrderModuleList;                // 0x001C / 0x0030; 0x0008 / 0x0010 Bytes
	PVOID                       EntryInProgress;                                // 0x0024 / 0x0040; 0x0004 / 0x0008 Bytes
	UINT8                       ShutdownInProgress;                             // 0x0028 / 0x0048; 0x0001 / 0x0001 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING1_[7];                                  // ------ / 0x0049; ------ / 0x0007 Bytes
#else                                                                           // #if defined(_M_X64)
	UINT8                       _PADDING1_[3];                                  // 0x0029 / ------; 0x0003 / ------ Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       ShutdownThreadId;                               // 0x002C / 0x0050; 0x0004 / 0x0008 Bytes
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef struct _UNICODE_STRING                                                  // 3 / 4 elements; 0x0008 / 0x0010 Bytes
{
	UINT16                      Length;                                         // 0x0000 / 0x0000; 0x0002 / 0x0002 Bytes
	UINT16                      MaximumLength;                                  // 0x0002 / 0x0002; 0x0002 / 0x0002 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING0_[4];                                  // ------ / 0x0004; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PUINT16                     Buffer;                                         // 0x0004 / 0x0008; 0x0004 / 0x0008 Bytes
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _CURDIR                                                          // 2 / 2 elements; 0x000C / 0x0018 Bytes
{
	UNICODE_STRING              DosPath;                                        // 0x0000 / 0x0000; 0x0008 / 0x0010 Bytes
	PVOID                       Handle;                                         // 0x0008 / 0x0010; 0x0004 / 0x0008 Bytes
} CURDIR, *PCURDIR;

typedef struct _STRING                                                          // 3 / 4 elements; 0x0008 / 0x0010 Bytes
{
	UINT16                      Length;                                         // 0x0000 / 0x0000; 0x0002 / 0x0002 Bytes
	UINT16                      MaximumLength;                                  // 0x0002 / 0x0002; 0x0002 / 0x0002 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING0_[4];                                  // ------ / 0x0004; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	CHAR *                      Buffer;                                         // 0x0004 / 0x0008; 0x0004 / 0x0008 Bytes
} STRING, *PSTRING;

typedef struct _RTL_DRIVE_LETTER_CURDIR                                         // 4 / 4 elements; 0x0010 / 0x0018 Bytes
{
	UINT16                      Flags;                                          // 0x0000 / 0x0000; 0x0002 / 0x0002 Bytes
	UINT16                      Length;                                         // 0x0002 / 0x0002; 0x0002 / 0x0002 Bytes
	ULONG32                     TimeStamp;                                      // 0x0004 / 0x0004; 0x0004 / 0x0004 Bytes
	STRING                      DosPath;                                        // 0x0008 / 0x0008; 0x0008 / 0x0010 Bytes
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

typedef struct _RTL_USER_PROCESS_PARAMETERS                                     // 33 / 35 elements; 0x02A4 / 0x0410 Bytes
{
	ULONG32                     MaximumLength;                                  // 0x0000 / 0x0000; 0x0004 / 0x0004 Bytes
	ULONG32                     Length;                                         // 0x0004 / 0x0004; 0x0004 / 0x0004 Bytes
	ULONG32                     Flags;                                          // 0x0008 / 0x0008; 0x0004 / 0x0004 Bytes
	ULONG32                     DebugFlags;                                     // 0x000C / 0x000C; 0x0004 / 0x0004 Bytes
	PVOID                       ConsoleHandle;                                  // 0x0010 / 0x0010; 0x0004 / 0x0008 Bytes
	ULONG32                     ConsoleFlags;                                   // 0x0014 / 0x0018; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING0_[4];                                  // ------ / 0x001C; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       StandardInput;                                  // 0x0018 / 0x0020; 0x0004 / 0x0008 Bytes
	PVOID                       StandardOutput;                                 // 0x001C / 0x0028; 0x0004 / 0x0008 Bytes
	PVOID                       StandardError;                                  // 0x0020 / 0x0030; 0x0004 / 0x0008 Bytes
	CURDIR                      CurrentDirectory;                               // 0x0024 / 0x0038; 0x000C / 0x0018 Bytes
	UNICODE_STRING              DllPath;                                        // 0x0030 / 0x0050; 0x0008 / 0x0010 Bytes
	UNICODE_STRING              ImagePathName;                                  // 0x0038 / 0x0060; 0x0008 / 0x0010 Bytes
	UNICODE_STRING              CommandLine;                                    // 0x0040 / 0x0070; 0x0008 / 0x0010 Bytes
	PVOID                       Environment;                                    // 0x0048 / 0x0080; 0x0004 / 0x0008 Bytes
	ULONG32                     StartingX;                                      // 0x004C / 0x0088; 0x0004 / 0x0004 Bytes
	ULONG32                     StartingY;                                      // 0x0050 / 0x008C; 0x0004 / 0x0004 Bytes
	ULONG32                     CountX;                                         // 0x0054 / 0x0090; 0x0004 / 0x0004 Bytes
	ULONG32                     CountY;                                         // 0x0058 / 0x0094; 0x0004 / 0x0004 Bytes
	ULONG32                     CountCharsX;                                    // 0x005C / 0x0098; 0x0004 / 0x0004 Bytes
	ULONG32                     CountCharsY;                                    // 0x0060 / 0x009C; 0x0004 / 0x0004 Bytes
	ULONG32                     FillAttribute;                                  // 0x0064 / 0x00A0; 0x0004 / 0x0004 Bytes
	ULONG32                     WindowFlags;                                    // 0x0068 / 0x00A4; 0x0004 / 0x0004 Bytes
	ULONG32                     ShowWindowFlags;                                // 0x006C / 0x00A8; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING1_[4];                                  // ------ / 0x00AC; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	UNICODE_STRING              WindowTitle;                                    // 0x0070 / 0x00B0; 0x0008 / 0x0010 Bytes
	UNICODE_STRING              DesktopInfo;                                    // 0x0078 / 0x00C0; 0x0008 / 0x0010 Bytes
	UNICODE_STRING              ShellInfo;                                      // 0x0080 / 0x00D0; 0x0008 / 0x0010 Bytes
	UNICODE_STRING              RuntimeData;                                    // 0x0088 / 0x00E0; 0x0008 / 0x0010 Bytes
	RTL_DRIVE_LETTER_CURDIR     CurrentDirectores[32];                          // 0x0090 / 0x00F0; 0x0200 / 0x0300 Bytes
	UINT_PTR                    EnvironmentSize;                                // 0x0290 / 0x03F0; 0x0004 / 0x0008 Bytes
	UINT_PTR                    EnvironmentVersion;                             // 0x0294 / 0x03F8; 0x0004 / 0x0008 Bytes
	PVOID                       PackageDependencyData;                          // 0x0298 / 0x0400; 0x0004 / 0x0008 Bytes
	ULONG32                     ProcessGroupId;                                 // 0x029C / 0x0408; 0x0004 / 0x0004 Bytes
	ULONG32                     LoaderThreads;                                  // 0x02A0 / 0x040C; 0x0004 / 0x0004 Bytes
} RTL_USER_PROCESS_PARAMETERS, *PRTL_USER_PROCESS_PARAMETERS;

typedef struct _ACTIVATION_CONTEXT_STACK                                        // 5 / 6 elements; 0x0018 / 0x0028 Bytes
{
	PVOID ActiveFrame;                                    // 0x0000 / 0x0000; 0x0004 / 0x0008 Bytes
	LIST_ENTRY                  FrameListCache;                                 // 0x0004 / 0x0008; 0x0008 / 0x0010 Bytes
	ULONG32                     Flags;                                          // 0x000C / 0x0018; 0x0004 / 0x0004 Bytes
	ULONG32                     NextCookieSequenceNumber;                       // 0x0010 / 0x001C; 0x0004 / 0x0004 Bytes
	ULONG32                     StackId;                                        // 0x0014 / 0x0020; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING0_[4];                                  // ------ / 0x0024; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
} ACTIVATION_CONTEXT_STACK, *PACTIVATION_CONTEXT_STACK;

typedef struct _PEB                                                             // 100 / 106 elements; 0x0460 / 0x07A0 Bytes
{
	UINT8                       InheritedAddressSpace;                          // 0x0000 / 0x0000; 0x0001 / 0x0001 Bytes
	UINT8                       ReadImageFileExecOptions;                       // 0x0001 / 0x0001; 0x0001 / 0x0001 Bytes
	UINT8                       BeingDebugged;                                  // 0x0002 / 0x0002; 0x0001 / 0x0001 Bytes
	union                                                                       // 2 / 2 elements; 0x0001 / 0x0001 Bytes
	{
		UINT8                   BitField;                                       // 0x0003 / 0x0003; 0x0001 / 0x0001 Bytes
		struct                                                                  // 8 / 8 elements; 0x0001 / 0x0001 Bytes
		{
			UINT8               ImageUsesLargePages : 1; // 0x0003 / 0x0003; Bit:   0
			UINT8               IsProtectedProcess : 1; // 0x0003 / 0x0003; Bit:   1
			UINT8               IsImageDynamicallyRelocated : 1; // 0x0003 / 0x0003; Bit:   2
			UINT8               SkipPatchingUser32Forwarders : 1; // 0x0003 / 0x0003; Bit:   3
			UINT8               IsPackagedProcess : 1; // 0x0003 / 0x0003; Bit:   4
			UINT8               IsAppContainer : 1; // 0x0003 / 0x0003; Bit:   5
			UINT8               IsProtectedProcessLight : 1; // 0x0003 / 0x0003; Bit:   6
			UINT8               SpareBits : 1; // 0x0003 / 0x0003; Bit:   7
		};
	};
#if defined(_M_X64)
	UINT8                       Padding0[4];                                    // ------ / 0x0004; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       Mutant;                                         // 0x0004 / 0x0008; 0x0004 / 0x0008 Bytes
	PVOID                       ImageBaseAddress;                               // 0x0008 / 0x0010; 0x0004 / 0x0008 Bytes
	PPEB_LDR_DATA               Ldr;                                            // 0x000C / 0x0018; 0x0004 / 0x0008 Bytes
	PRTL_USER_PROCESS_PARAMETERS
		ProcessParameters;                              // 0x0010 / 0x0020; 0x0004 / 0x0008 Bytes
	PVOID                       SubSystemData;                                  // 0x0014 / 0x0028; 0x0004 / 0x0008 Bytes
	PVOID                       ProcessHeap;                                    // 0x0018 / 0x0030; 0x0004 / 0x0008 Bytes
	PRTL_CRITICAL_SECTION       FastPebLock;                                    // 0x001C / 0x0038; 0x0004 / 0x0008 Bytes
	PVOID                       AtlThunkSListPtr;                               // 0x0020 / 0x0040; 0x0004 / 0x0008 Bytes
	PVOID                       IFEOKey;                                        // 0x0024 / 0x0048; 0x0004 / 0x0008 Bytes
	union                                                                       // 2 / 2 elements; 0x0004 / 0x0004 Bytes
	{
		ULONG32                 CrossProcessFlags;                              // 0x0028 / 0x0050; 0x0004 / 0x0004 Bytes
		struct                                                                  // 6 / 6 elements; 0x0004 / 0x0004 Bytes
		{
			ULONG32             ProcessInJob : 1; // 0x0028 / 0x0050; Bit:   0
			ULONG32             ProcessInitializing : 1; // 0x0028 / 0x0050; Bit:   1
			ULONG32             ProcessUsingVEH : 1; // 0x0028 / 0x0050; Bit:   2
			ULONG32             ProcessUsingVCH : 1; // 0x0028 / 0x0050; Bit:   3
			ULONG32             ProcessUsingFTH : 1; // 0x0028 / 0x0050; Bit:   4
			ULONG32             ReservedBits0 : 27; // 0x0028 / 0x0050; Bits:  5 - 31
		};
	};
#if defined(_M_X64)
	UINT8                       Padding1[4];                                    // ------ / 0x0054; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	union                                                                       // 2 / 2 elements; 0x0004 / 0x0008 Bytes
	{
		PVOID                   KernelCallbackTable;                            // 0x002C / 0x0058; 0x0004 / 0x0008 Bytes
		PVOID                   UserSharedInfoPtr;                              // 0x002C / 0x0058; 0x0004 / 0x0008 Bytes
	};
	ULONG32                     SystemReserved[1];                              // 0x0030 / 0x0060; 0x0004 / 0x0004 Bytes
	ULONG32                     AtlThunkSListPtr32;                             // 0x0034 / 0x0064; 0x0004 / 0x0004 Bytes
	PVOID                       ApiSetMap;                                      // 0x0038 / 0x0068; 0x0004 / 0x0008 Bytes
	ULONG32                     TlsExpansionCounter;                            // 0x003C / 0x0070; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding2[4];                                    // ------ / 0x0074; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       TlsBitmap;                                      // 0x0040 / 0x0078; 0x0004 / 0x0008 Bytes
	ULONG32                     TlsBitmapBits[2];                               // 0x0044 / 0x0080; 0x0008 / 0x0008 Bytes
	PVOID                       ReadOnlySharedMemoryBase;                       // 0x004C / 0x0088; 0x0004 / 0x0008 Bytes
	PVOID                       SparePvoid0;                                    // 0x0050 / 0x0090; 0x0004 / 0x0008 Bytes
	PVOID *                     ReadOnlyStaticServerData;                       // 0x0054 / 0x0098; 0x0004 / 0x0008 Bytes
	PVOID                       AnsiCodePageData;                               // 0x0058 / 0x00A0; 0x0004 / 0x0008 Bytes
	PVOID                       OemCodePageData;                                // 0x005C / 0x00A8; 0x0004 / 0x0008 Bytes
	PVOID                       UnicodeCaseTableData;                           // 0x0060 / 0x00B0; 0x0004 / 0x0008 Bytes
	ULONG32                     NumberOfProcessors;                             // 0x0064 / 0x00B8; 0x0004 / 0x0004 Bytes
	ULONG32                     NtGlobalFlag;                                   // 0x0068 / 0x00BC; 0x0004 / 0x0004 Bytes
#if !defined(_M_X64)
	UINT8                       _PADDING0_[4];                                  // 0x006C / ------; 0x0004 / ------ Bytes
#endif                                                                          // #if !defined(_M_X64)
	LARGE_INTEGER               CriticalSectionTimeout;                         // 0x0070 / 0x00C0; 0x0008 / 0x0008 Bytes
	UINT_PTR                    HeapSegmentReserve;                             // 0x0078 / 0x00C8; 0x0004 / 0x0008 Bytes
	UINT_PTR                    HeapSegmentCommit;                              // 0x007C / 0x00D0; 0x0004 / 0x0008 Bytes
	UINT_PTR                    HeapDeCommitTotalFreeThreshold;                 // 0x0080 / 0x00D8; 0x0004 / 0x0008 Bytes
	UINT_PTR                    HeapDeCommitFreeBlockThreshold;                 // 0x0084 / 0x00E0; 0x0004 / 0x0008 Bytes
	ULONG32                     NumberOfHeaps;                                  // 0x0088 / 0x00E8; 0x0004 / 0x0004 Bytes
	ULONG32                     MaximumNumberOfHeaps;                           // 0x008C / 0x00EC; 0x0004 / 0x0004 Bytes
	PVOID *                     ProcessHeaps;                                   // 0x0090 / 0x00F0; 0x0004 / 0x0008 Bytes
	PVOID                       GdiSharedHandleTable;                           // 0x0094 / 0x00F8; 0x0004 / 0x0008 Bytes
	PVOID                       ProcessStarterHelper;                           // 0x0098 / 0x0100; 0x0004 / 0x0008 Bytes
	ULONG32                     GdiDCAttributeList;                             // 0x009C / 0x0108; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding3[4];                                    // ------ / 0x010C; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PRTL_CRITICAL_SECTION       LoaderLock;                                     // 0x00A0 / 0x0110; 0x0004 / 0x0008 Bytes
	ULONG32                     OSMajorVersion;                                 // 0x00A4 / 0x0118; 0x0004 / 0x0004 Bytes
	ULONG32                     OSMinorVersion;                                 // 0x00A8 / 0x011C; 0x0004 / 0x0004 Bytes
	UINT16                      OSBuildNumber;                                  // 0x00AC / 0x0120; 0x0002 / 0x0002 Bytes
	UINT16                      OSCSDVersion;                                   // 0x00AE / 0x0122; 0x0002 / 0x0002 Bytes
	ULONG32                     OSPlatformId;                                   // 0x00B0 / 0x0124; 0x0004 / 0x0004 Bytes
	ULONG32                     ImageSubsystem;                                 // 0x00B4 / 0x0128; 0x0004 / 0x0004 Bytes
	ULONG32                     ImageSubsystemMajorVersion;                     // 0x00B8 / 0x012C; 0x0004 / 0x0004 Bytes
	ULONG32                     ImageSubsystemMinorVersion;                     // 0x00BC / 0x0130; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding4[4];                                    // ------ / 0x0134; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	UINT_PTR                    ActiveProcessAffinityMask;                      // 0x00C0 / 0x0138; 0x0004 / 0x0008 Bytes
#if defined(_M_X64)
	ULONG32                     GdiHandleBuffer[60];                            // ------ / 0x0140; ------ / 0x00F0 Bytes
#else                                                                           // #if defined(_M_X64)
	ULONG32                     GdiHandleBuffer[34];                            // 0x00C4 / ------; 0x0088 / ------ Bytes
#endif                                                                          // #if defined(_M_X64)
	void                        (WINAPI * PostProcessInitRoutine)
		(void);         // 0x014C / 0x0230; 0x0004 / 0x0008 Bytes
	PVOID                       TlsExpansionBitmap;                             // 0x0150 / 0x0238; 0x0004 / 0x0008 Bytes
	ULONG32                     TlsExpansionBitmapBits[32];                     // 0x0154 / 0x0240; 0x0080 / 0x0080 Bytes
	ULONG32                     SessionId;                                      // 0x01D4 / 0x02C0; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding5[4];                                    // ------ / 0x02C4; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	ULARGE_INTEGER              AppCompatFlags;                                 // 0x01D8 / 0x02C8; 0x0008 / 0x0008 Bytes
	ULARGE_INTEGER              AppCompatFlagsUser;                             // 0x01E0 / 0x02D0; 0x0008 / 0x0008 Bytes
	PVOID                       pShimData;                                      // 0x01E8 / 0x02D8; 0x0004 / 0x0008 Bytes
	PVOID                       AppCompatInfo;                                  // 0x01EC / 0x02E0; 0x0004 / 0x0008 Bytes
	UNICODE_STRING              CSDVersion;                                     // 0x01F0 / 0x02E8; 0x0008 / 0x0010 Bytes
	PVOID						ActivationContextData;                          // 0x01F8 / 0x02F8; 0x0004 / 0x0008 Bytes
	PVOID						ProcessAssemblyStorageMap;                      // 0x01FC / 0x0300; 0x0004 / 0x0008 Bytes
	PVOID						SystemDefaultActivationContextData;             // 0x0200 / 0x0308; 0x0004 / 0x0008 Bytes
	PVOID						SystemAssemblyStorageMap;                       // 0x0204 / 0x0310; 0x0004 / 0x0008 Bytes
	UINT_PTR                    MinimumStackCommit;                             // 0x0208 / 0x0318; 0x0004 / 0x0008 Bytes
	PVOID						FlsCallback;                                    // 0x020C / 0x0320; 0x0004 / 0x0008 Bytes
	LIST_ENTRY                  FlsListHead;                                    // 0x0210 / 0x0328; 0x0008 / 0x0010 Bytes
	PVOID                       FlsBitmap;                                      // 0x0218 / 0x0338; 0x0004 / 0x0008 Bytes
	ULONG32                     FlsBitmapBits[4];                               // 0x021C / 0x0340; 0x0010 / 0x0010 Bytes
	ULONG32                     FlsHighIndex;                                   // 0x022C / 0x0350; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING0_[4];                                  // ------ / 0x0354; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       WerRegistrationData;                            // 0x0230 / 0x0358; 0x0004 / 0x0008 Bytes
	PVOID                       WerShipAssertPtr;                               // 0x0234 / 0x0360; 0x0004 / 0x0008 Bytes
	PVOID                       pUnused;                                        // 0x0238 / 0x0368; 0x0004 / 0x0008 Bytes
	PVOID                       pImageHeaderHash;                               // 0x023C / 0x0370; 0x0004 / 0x0008 Bytes
	union                                                                       // 2 / 2 elements; 0x0004 / 0x0004 Bytes
	{
		ULONG32                 TracingFlags;                                   // 0x0240 / 0x0378; 0x0004 / 0x0004 Bytes
		struct                                                                  // 4 / 4 elements; 0x0004 / 0x0004 Bytes
		{
			ULONG32             HeapTracingEnabled : 1; // 0x0240 / 0x0378; Bit:   0
			ULONG32             CritSecTracingEnabled : 1; // 0x0240 / 0x0378; Bit:   1
			ULONG32             LibLoaderTracingEnabled : 1; // 0x0240 / 0x0378; Bit:   2
			ULONG32             SpareTracingBits : 29; // 0x0240 / 0x0378; Bits:  3 - 31
		};
	};
#if defined(_M_X64)
	UINT8                       Padding6[4];                                    // ------ / 0x037C; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	UINT64                      CsrServerReadOnlySharedMemoryBase;              // 0x0248 / 0x0380; 0x0008 / 0x0008 Bytes
	UINT_PTR                    TppWorkerpListLock;                             // 0x0250 / 0x0388; 0x0004 / 0x0008 Bytes
	LIST_ENTRY                  TppWorkerpList;                                 // 0x0254 / 0x0390; 0x0008 / 0x0010 Bytes
	PVOID                       WaitOnAddressHashTable[128];                    // 0x025C / 0x03A0; 0x0200 / 0x0400 Bytes
#if !defined(_M_X64)
	UINT8                       _PADDING1_[4];                                  // 0x045C / ------; 0x0004 / ------ Bytes
#endif                                                                          // #if !defined(_M_X64)
} PEB, *PPEB;

typedef struct _GDI_TEB_BATCH                                                   // 4 / 4 elements; 0x04E0 / 0x04E8 Bytes
{
	struct                                                                      // 2 / 2 elements; 0x0004 / 0x0004 Bytes
	{
		ULONG32                 Offset : 31; // 0x0000 / 0x0000; Bits:  0 - 30
		ULONG32                 HasRenderingCommand : 1; // 0x0000 / 0x0000; Bit:  31
	};
	UINT_PTR                    HDC;                                            // 0x0004 / 0x0008; 0x0004 / 0x0008 Bytes
	ULONG32                     Buffer[310];                                    // 0x0008 / 0x0010; 0x04D8 / 0x04D8 Bytes
} GDI_TEB_BATCH, *PGDI_TEB_BATCH;

typedef struct _TEB                                                             // 112 / 121 elements; 0x1000 / 0x1838 Bytes
{
	NT_TIB                      NtTib;                                          // 0x0000 / 0x0000; 0x001C / 0x0038 Bytes
	PVOID                       EnvironmentPointer;                             // 0x001C / 0x0038; 0x0004 / 0x0008 Bytes
	CLIENT_ID                   ClientId;                                       // 0x0020 / 0x0040; 0x0008 / 0x0010 Bytes
	PVOID                       ActiveRpcHandle;                                // 0x0028 / 0x0050; 0x0004 / 0x0008 Bytes
	PVOID                       ThreadLocalStoragePointer;                      // 0x002C / 0x0058; 0x0004 / 0x0008 Bytes
	PPEB                        ProcessEnvironmentBlock;                        // 0x0030 / 0x0060; 0x0004 / 0x0008 Bytes
	ULONG32                     LastErrorValue;                                 // 0x0034 / 0x0068; 0x0004 / 0x0004 Bytes
	ULONG32                     CountOfOwnedCriticalSections;                   // 0x0038 / 0x006C; 0x0004 / 0x0004 Bytes
	PVOID                       CsrClientThread;                                // 0x003C / 0x0070; 0x0004 / 0x0008 Bytes
	PVOID                       Win32ThreadInfo;                                // 0x0040 / 0x0078; 0x0004 / 0x0008 Bytes
	ULONG32                     User32Reserved[26];                             // 0x0044 / 0x0080; 0x0068 / 0x0068 Bytes
	ULONG32                     UserReserved[5];                                // 0x00AC / 0x00E8; 0x0014 / 0x0014 Bytes
#if defined(_M_X64)
	UINT8                       _PADDING0_[4];                                  // ------ / 0x00FC; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       WOW32Reserved;                                  // 0x00C0 / 0x0100; 0x0004 / 0x0008 Bytes
	ULONG32                     CurrentLocale;                                  // 0x00C4 / 0x0108; 0x0004 / 0x0004 Bytes
	ULONG32                     FpSoftwareStatusRegister;                       // 0x00C8 / 0x010C; 0x0004 / 0x0004 Bytes
	PVOID                       ReservedForDebuggerInstrumentation[16];         // 0x00CC / 0x0110; 0x0040 / 0x0080 Bytes
	PVOID                       SystemReserved1[38];                            // 0x010C / 0x0190; 0x0098 / 0x0130 Bytes
	LONG32                      ExceptionCode;                                  // 0x01A4 / 0x02C0; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding0[4];                                    // ------ / 0x02C4; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PACTIVATION_CONTEXT_STACK   ActivationContextStackPointer;                  // 0x01A8 / 0x02C8; 0x0004 / 0x0008 Bytes
	UINT_PTR                    InstrumentationCallbackSp;                      // 0x01AC / 0x02D0; 0x0004 / 0x0008 Bytes
	UINT_PTR                    InstrumentationCallbackPreviousPc;              // 0x01B0 / 0x02D8; 0x0004 / 0x0008 Bytes
	UINT_PTR                    InstrumentationCallbackPreviousSp;              // 0x01B4 / 0x02E0; 0x0004 / 0x0008 Bytes
#if !defined(_M_X64)
	UINT8                       InstrumentationCallbackDisabled;                // 0x01B8 / ------; 0x0001 / ------ Bytes
	UINT8                       SpareBytes[23];                                 // 0x01B9 / ------; 0x0017 / ------ Bytes
#endif                                                                          // #if !defined(_M_X64)
	ULONG32                     TxFsContext;                                    // 0x01D0 / 0x02E8; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       InstrumentationCallbackDisabled;                // ------ / 0x02EC; ------ / 0x0001 Bytes
	UINT8                       Padding1[3];                                    // ------ / 0x02ED; ------ / 0x0003 Bytes
#endif                                                                          // #if defined(_M_X64)
	GDI_TEB_BATCH               GdiTebBatch;                                    // 0x01D4 / 0x02F0; 0x04E0 / 0x04E8 Bytes
	CLIENT_ID                   RealClientId;                                   // 0x06B4 / 0x07D8; 0x0008 / 0x0010 Bytes
	PVOID                       GdiCachedProcessHandle;                         // 0x06BC / 0x07E8; 0x0004 / 0x0008 Bytes
	ULONG32                     GdiClientPID;                                   // 0x06C0 / 0x07F0; 0x0004 / 0x0004 Bytes
	ULONG32                     GdiClientTID;                                   // 0x06C4 / 0x07F4; 0x0004 / 0x0004 Bytes
	PVOID                       GdiThreadLocalInfo;                             // 0x06C8 / 0x07F8; 0x0004 / 0x0008 Bytes
	UINT_PTR                    Win32ClientInfo[62];                            // 0x06CC / 0x0800; 0x00F8 / 0x01F0 Bytes
	PVOID                       glDispatchTable[233];                           // 0x07C4 / 0x09F0; 0x03A4 / 0x0748 Bytes
	UINT_PTR                    glReserved1[29];                                // 0x0B68 / 0x1138; 0x0074 / 0x00E8 Bytes
	PVOID                       glReserved2;                                    // 0x0BDC / 0x1220; 0x0004 / 0x0008 Bytes
	PVOID                       glSectionInfo;                                  // 0x0BE0 / 0x1228; 0x0004 / 0x0008 Bytes
	PVOID                       glSection;                                      // 0x0BE4 / 0x1230; 0x0004 / 0x0008 Bytes
	PVOID                       glTable;                                        // 0x0BE8 / 0x1238; 0x0004 / 0x0008 Bytes
	PVOID                       glCurrentRC;                                    // 0x0BEC / 0x1240; 0x0004 / 0x0008 Bytes
	PVOID                       glContext;                                      // 0x0BF0 / 0x1248; 0x0004 / 0x0008 Bytes
	ULONG32                     LastStatusValue;                                // 0x0BF4 / 0x1250; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding2[4];                                    // ------ / 0x1254; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	UNICODE_STRING              StaticUnicodeString;                            // 0x0BF8 / 0x1258; 0x0008 / 0x0010 Bytes
	WCHAR                       StaticUnicodeBuffer[261];                       // 0x0C00 / 0x1268; 0x020A / 0x020A Bytes
#if defined(_M_X64)
	UINT8                       Padding3[6];                                    // ------ / 0x1472; ------ / 0x0006 Bytes
#else                                                                           // #if defined(_M_X64)
	UINT8                       _PADDING0_[2];                                  // 0x0E0A / ------; 0x0002 / ------ Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       DeallocationStack;                              // 0x0E0C / 0x1478; 0x0004 / 0x0008 Bytes
	PVOID                       TlsSlots[64];                                   // 0x0E10 / 0x1480; 0x0100 / 0x0200 Bytes
	LIST_ENTRY                  TlsLinks;                                       // 0x0F10 / 0x1680; 0x0008 / 0x0010 Bytes
	PVOID                       Vdm;                                            // 0x0F18 / 0x1690; 0x0004 / 0x0008 Bytes
	PVOID                       ReservedForNtRpc;                               // 0x0F1C / 0x1698; 0x0004 / 0x0008 Bytes
	PVOID                       DbgSsReserved[2];                               // 0x0F20 / 0x16A0; 0x0008 / 0x0010 Bytes
	ULONG32                     HardErrorMode;                                  // 0x0F28 / 0x16B0; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding4[4];                                    // ------ / 0x16B4; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
#if defined(_M_X64)
	PVOID                       Instrumentation[11];                            // ------ / 0x16B8; ------ / 0x0058 Bytes
#else                                                                           // #if defined(_M_X64)
	PVOID                       Instrumentation[9];                             // 0x0F2C / ------; 0x0024 / ------ Bytes
#endif                                                                          // #if defined(_M_X64)
	GUID                        ActivityId;                                     // 0x0F50 / 0x1710; 0x0010 / 0x0010 Bytes
	PVOID                       SubProcessTag;                                  // 0x0F60 / 0x1720; 0x0004 / 0x0008 Bytes
	PVOID                       PerflibData;                                    // 0x0F64 / 0x1728; 0x0004 / 0x0008 Bytes
	PVOID                       EtwTraceData;                                   // 0x0F68 / 0x1730; 0x0004 / 0x0008 Bytes
	PVOID                       WinSockData;                                    // 0x0F6C / 0x1738; 0x0004 / 0x0008 Bytes
	ULONG32                     GdiBatchCount;                                  // 0x0F70 / 0x1740; 0x0004 / 0x0004 Bytes
	union                                                                       // 3 / 3 elements; 0x0004 / 0x0004 Bytes
	{
		PROCESSOR_NUMBER        CurrentIdealProcessor;                          // 0x0F74 / 0x1744; 0x0004 / 0x0004 Bytes
		ULONG32                 IdealProcessorValue;                            // 0x0F74 / 0x1744; 0x0004 / 0x0004 Bytes
		struct                                                                  // 4 / 4 elements; 0x0004 / 0x0004 Bytes
		{
			UINT8               ReservedPad0;                                   // 0x0F74 / 0x1744; 0x0001 / 0x0001 Bytes
			UINT8               ReservedPad1;                                   // 0x0F75 / 0x1745; 0x0001 / 0x0001 Bytes
			UINT8               ReservedPad2;                                   // 0x0F76 / 0x1746; 0x0001 / 0x0001 Bytes
			UINT8               IdealProcessor;                                 // 0x0F77 / 0x1747; 0x0001 / 0x0001 Bytes
		};
	};
	ULONG32                     GuaranteedStackBytes;                           // 0x0F78 / 0x1748; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding5[4];                                    // ------ / 0x174C; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       ReservedForPerf;                                // 0x0F7C / 0x1750; 0x0004 / 0x0008 Bytes
	PVOID                       ReservedForOle;                                 // 0x0F80 / 0x1758; 0x0004 / 0x0008 Bytes
	ULONG32                     WaitingOnLoaderLock;                            // 0x0F84 / 0x1760; 0x0004 / 0x0004 Bytes
#if defined(_M_X64)
	UINT8                       Padding6[4];                                    // ------ / 0x1764; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       SavedPriorityState;                             // 0x0F88 / 0x1768; 0x0004 / 0x0008 Bytes
	UINT_PTR                    ReservedForCodeCoverage;                        // 0x0F8C / 0x1770; 0x0004 / 0x0008 Bytes
	PVOID                       ThreadPoolData;                                 // 0x0F90 / 0x1778; 0x0004 / 0x0008 Bytes
	PVOID *                     TlsExpansionSlots;                              // 0x0F94 / 0x1780; 0x0004 / 0x0008 Bytes
#if defined(_M_X64)
	PVOID                       DeallocationBStore;                             // ------ / 0x1788; ------ / 0x0008 Bytes
	PVOID                       BStoreLimit;                                    // ------ / 0x1790; ------ / 0x0008 Bytes
#endif                                                                          // #if defined(_M_X64)
	ULONG32                     MuiGeneration;                                  // 0x0F98 / 0x1798; 0x0004 / 0x0004 Bytes
	ULONG32                     IsImpersonating;                                // 0x0F9C / 0x179C; 0x0004 / 0x0004 Bytes
	PVOID                       NlsCache;                                       // 0x0FA0 / 0x17A0; 0x0004 / 0x0008 Bytes
	PVOID                       pShimData;                                      // 0x0FA4 / 0x17A8; 0x0004 / 0x0008 Bytes
	UINT16                      HeapVirtualAffinity;                            // 0x0FA8 / 0x17B0; 0x0002 / 0x0002 Bytes
	UINT16                      LowFragHeapDataSlot;                            // 0x0FAA / 0x17B2; 0x0002 / 0x0002 Bytes
#if defined(_M_X64)
	UINT8                       Padding7[4];                                    // ------ / 0x17B4; ------ / 0x0004 Bytes
#endif                                                                          // #if defined(_M_X64)
	PVOID                       CurrentTransactionHandle;                       // 0x0FAC / 0x17B8; 0x0004 / 0x0008 Bytes
	PVOID						ActiveFrame;                                    // 0x0FB0 / 0x17C0; 0x0004 / 0x0008 Bytes
	PVOID                       FlsData;                                        // 0x0FB4 / 0x17C8; 0x0004 / 0x0008 Bytes
	PVOID                       PreferredLanguages;                             // 0x0FB8 / 0x17D0; 0x0004 / 0x0008 Bytes
	PVOID                       UserPrefLanguages;                              // 0x0FBC / 0x17D8; 0x0004 / 0x0008 Bytes
	PVOID                       MergedPrefLanguages;                            // 0x0FC0 / 0x17E0; 0x0004 / 0x0008 Bytes
	ULONG32                     MuiImpersonation;                               // 0x0FC4 / 0x17E8; 0x0004 / 0x0004 Bytes
	union                                                                       // 2 / 2 elements; 0x0002 / 0x0002 Bytes
	{
		UINT16                  CrossTebFlags;                                  // 0x0FC8 / 0x17EC; 0x0002 / 0x0002 Bytes
		UINT16                  SpareCrossTebBits : 16; // 0x0FC8 / 0x17EC; Bits:  0 - 15
	};
	union                                                                       // 2 / 2 elements; 0x0002 / 0x0002 Bytes
	{
		UINT16                  SameTebFlags;                                   // 0x0FCA / 0x17EE; 0x0002 / 0x0002 Bytes
		struct                                                                  // 15 / 15 elements; 0x0002 / 0x0002 Bytes
		{
			UINT16              SafeThunkCall : 1; // 0x0FCA / 0x17EE; Bit:   0
			UINT16              InDebugPrint : 1; // 0x0FCA / 0x17EE; Bit:   1
			UINT16              HasFiberData : 1; // 0x0FCA / 0x17EE; Bit:   2
			UINT16              SkipThreadAttach : 1; // 0x0FCA / 0x17EE; Bit:   3
			UINT16              WerInShipAssertCode : 1; // 0x0FCA / 0x17EE; Bit:   4
			UINT16              RanProcessInit : 1; // 0x0FCA / 0x17EE; Bit:   5
			UINT16              ClonedThread : 1; // 0x0FCA / 0x17EE; Bit:   6
			UINT16              SuppressDebugMsg : 1; // 0x0FCA / 0x17EE; Bit:   7
			UINT16              DisableUserStackWalk : 1; // 0x0FCA / 0x17EE; Bit:   8
			UINT16              RtlExceptionAttached : 1; // 0x0FCA / 0x17EE; Bit:   9
			UINT16              InitialThread : 1; // 0x0FCA / 0x17EE; Bit:  10
			UINT16              SessionAware : 1; // 0x0FCA / 0x17EE; Bit:  11
			UINT16              LoadOwner : 1; // 0x0FCA / 0x17EE; Bit:  12
			UINT16              LoaderWorker : 1; // 0x0FCA / 0x17EE; Bit:  13
			UINT16              SpareSameTebBits : 2; // 0x0FCA / 0x17EE; Bits: 14 - 15
		};
	};
	PVOID                       TxnScopeEnterCallback;                          // 0x0FCC / 0x17F0; 0x0004 / 0x0008 Bytes
	PVOID                       TxnScopeExitCallback;                           // 0x0FD0 / 0x17F8; 0x0004 / 0x0008 Bytes
	PVOID                       TxnScopeContext;                                // 0x0FD4 / 0x1800; 0x0004 / 0x0008 Bytes
	ULONG32                     LockCount;                                      // 0x0FD8 / 0x1808; 0x0004 / 0x0004 Bytes
	LONG32                      WowTebOffset;                                   // 0x0FDC / 0x180C; 0x0004 / 0x0004 Bytes
	PVOID                       ResourceRetValue;                               // 0x0FE0 / 0x1810; 0x0004 / 0x0008 Bytes
	PVOID                       ReservedForWdf;                                 // 0x0FE4 / 0x1818; 0x0004 / 0x0008 Bytes
	UINT64                      ReservedForCrt;                                 // 0x0FE8 / 0x1820; 0x0008 / 0x0008 Bytes
	GUID                        EffectiveContainerId;                           // 0x0FF0 / 0x1828; 0x0010 / 0x0010 Bytes
} TEB, *PTEB;