#include "Fog.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"
#include "D2FogTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct FSafeSock;

struct D2TSLinkStrc;

struct D2TSListStrc;

struct D2ImageHlpLineStrc;

struct D2PeDosHeaderStrc;

struct D2PeNtHeadersStrc;

struct D2PeSectionStrc;

struct List204;

struct List08;

struct ListCD;

struct PoolOwner;

struct SingleWord;

struct FourWords;

struct QuestView;

struct Extra11;

struct Extra14;

struct GameMode;

struct D2ImageHlpAddressStrc;

struct D2ImageHlpStackFrameStrc;

struct D2ImageHlpSymbolStrc;

struct D2ImageHlpModuleStrc;

struct T0040D1C0;

struct D2CrashDumpEntryStrc;

struct D2SystemTimeStrc;

struct D2ModuleInfoStrc;

struct D2MemoryBasicInfoStrc;

struct FSafeSock
{
    int bConnected;
    int bConnecting;
    unsigned int nSocket;
    D2CriticalSectionStrc tCriticalSection;
    void* hThread;
    unsigned long nThreadId;
    int bStopping;
    unsigned long nFogErrorCode;
    unsigned long nWSALastError;
    char szName[64];
};

struct D2TSLinkStrc
{
    D2TSLinkStrc* pPrevLink;
    D2TSLinkStrc* pNext;

    D2TSLinkStrc* NextLink(int nLinkOffset)
    {
        const int nNext = (int)pNext;
        if (nNext < 0)
        {
            return (D2TSLinkStrc*)~nNext;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        }
        return (D2TSLinkStrc*)(nNext + nLinkOffset);
    }

    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink(-1)->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct D2TSListStrc
{
    int nLinkOffset;
    D2TSLinkStrc tTerminator;

    D2TSLinkStrc* Head()
    {
        return (int)tTerminator.pNext > 0 ? tTerminator.pNext : 0;
    }

    void sub_0040FD00_UnlinkAll();
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pnThreadId); // 0x006CC250

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pTime); // 0x006CC1D4

extern "C" int __stdcall closesocket(unsigned int nSocket); // 0x006B012C

extern "C" int __stdcall WSAGetLastError(); // 0x006B0168

extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress); // 0x006B013E

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

unsigned long __stdcall sub_004101C0_LogThreadProc(void* pParam); // 0x004101C0

extern D2SystemTimeStrc gLogStartTime_0075D288; // 0x0075D288

extern void* ghLogThread_0075D2E8; // 0x0075D2E8

extern D2CriticalSectionStrc gtLogQueueLock_0075E838; // 0x0075E838

extern D2CriticalSectionStrc gtLogLock_0075E850; // 0x0075E850

struct D2ModuleInfoStrc
{
    char szPath[0x104];
    char szName[0x100];
    unsigned long dwBase;
    unsigned long dwSize;
    D2ModuleInfoStrc* pNext;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize); // 0x0040C220

D2ModuleInfoStrc* __stdcall sub_0040B690_GetModuleListToolhelp(unsigned long dwPid); // 0x0040B690

extern int (__stdcall* gpfnSymCleanup_0075CFDC)(void* hProcess); // 0x0075CFDC

extern unsigned long (__stdcall* gpfnSymGetOptions_0075CFF0)(); // 0x0075CFF0

extern int (__stdcall* gpfnSymInitialize_0075CFF8)(void* hProcess, const char* szSearchPath, int bInvadeProcess); // 0x0075CFF8

extern unsigned long (__stdcall* gpfnSymLoadModule_0075CFFC)(void* hProcess, void* hFile, const char* szImageName, const char* szModuleName, unsigned long dwBase, unsigned long dwSize); // 0x0075CFFC

extern unsigned long (__stdcall* gpfnSymSetOptions_0075D004)(unsigned long dwOptions); // 0x0075D004

extern int gbImageHlpLoaded_0075D014; // 0x0075D014

void __stdcall sub_H13_EmitUse(const char* szText, unsigned long nValue1, unsigned long nValue2, unsigned long nValue3);

struct List204
{
    char gap00[0x204];
    List204* next;
};

struct List08
{
    char gap00[0x8];
    List08* next;
};

#pragma pack(push, 1)

struct ListCD
{
    char gap00[0xCD];
    ListCD* next;
};

#pragma pack(pop)

struct PoolOwner
{
    char gap00[0x1C];
    void* pool;
};

struct SingleWord
{
    int value;
};

struct FourWords
{
    int first;
    int second;
    int third;
    int fourth;
};

struct QuestView
{
    char gap00[0x9];
    unsigned char active;
    char gapAfterActive[2];
    unsigned char state;
    char gapAfterState[0xB];
    void* extra;
};

struct Extra11
{
    char gap00[0x11];
    unsigned char flag;
};

struct Extra14
{
    char gap00[0x14];
    unsigned char flag;
};

struct GameMode
{
    char gap00[0x70];
    int mode;
};

typedef char pointer_width[sizeof(void*)==4?1:-1];

typedef char List204_next[OFFSET(List204,next)==0x204?1:-1];

typedef char List08_next[OFFSET(List08,next)==0x8?1:-1];

typedef char ListCD_next[OFFSET(ListCD,next)==0xCD?1:-1];

typedef char PoolOwner_pool[OFFSET(PoolOwner,pool)==0x1C?1:-1];

typedef char SingleWord_value[OFFSET(SingleWord,value)==0x0?1:-1];

typedef char FourWords_first[OFFSET(FourWords,first)==0x0?1:-1];

typedef char FourWords_second[OFFSET(FourWords,second)==0x4?1:-1];

typedef char FourWords_third[OFFSET(FourWords,third)==0x8?1:-1];

typedef char FourWords_fourth[OFFSET(FourWords,fourth)==0xC?1:-1];

typedef char QuestView_active[OFFSET(QuestView,active)==0x9?1:-1];

typedef char QuestView_state[OFFSET(QuestView,state)==0xC?1:-1];

typedef char QuestView_extra[OFFSET(QuestView,extra)==0x18?1:-1];

typedef char Extra11_flag[OFFSET(Extra11,flag)==0x11?1:-1];

typedef char Extra14_flag[OFFSET(Extra14,flag)==0x14?1:-1];

typedef char GameMode_mode[OFFSET(GameMode,mode)==0x70?1:-1];

typedef char packed_ListCD_size[sizeof(ListCD)==0xD1?1:-1];

extern "C" void* __fastcall FOG_AllocPool(void* pool,int size,const char* file,int line,int flags);

extern "C" QuestView* __fastcall QUESTS_GetQuestData(void* game,int id);

extern "C" List204* gList_0077BDB4;

extern "C" List08* gList_007BB5C8;

extern "C" ListCD* gList_007BF014;

extern "C" void* gAllocation_009897D0; // 0x009897D0

extern "C" const char gSource_006CD628[]; // 0x006CD628

extern "C" const char gSource_006D5460[];

extern "C" const char gSource_006D7268[];

extern "C" const char gSource_006DA04C[];

extern "C" const char gSource_006E1560[];

struct D2ImageHlpAddressStrc
{
    unsigned long dwOffset;
    unsigned short wSegment;
    int nMode;
};

struct D2ImageHlpStackFrameStrc
{
    D2ImageHlpAddressStrc tAddrPC;
    D2ImageHlpAddressStrc tAddrReturn;
    D2ImageHlpAddressStrc tAddrFrame;
    D2ImageHlpAddressStrc tAddrStack;
    void* pFuncTableEntry;
    unsigned long dwParams[4];
    int bFar;
    int bVirtual;
    unsigned long dwReserved[3];
    unsigned long dwKdHelp[19];
};

struct D2ImageHlpSymbolStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwAddress;
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwMaxNameLength;
    char szName[1];
};

struct D2ImageHlpModuleStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwBaseOfImage;
    unsigned long dwImageSize;
    unsigned long dwTimeDateStamp;
    unsigned long dwCheckSum;
    unsigned long dwNumSyms;
    int nSymType;
    char szModuleName[32];
    char szImageName[256];
    char szLoadedImageName[256];
};

typedef int (__stdcall* StackWalkFn)(unsigned long dwMachine, void* hProcess, void* hThread, D2ImageHlpStackFrameStrc* pFrame, void* pContext, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase, void* pfnTranslateAddress);

typedef int (__stdcall* SymGetSymFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpSymbolStrc* pSymbol);

typedef int (__stdcall* SymGetModuleInfoFn)(void* hProcess, unsigned long dwAddress, D2ImageHlpModuleStrc* pModuleInfo);

typedef int (__stdcall* SymGetLineFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" const char gszEmptyString_006FFC44[]; // 0x006FFC44

const char* __fastcall sub_00408000_StripSourcePath(const char* szPath); // 0x00408000

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

int __cdecl s_DoSymInitialize(); // 0x0040C620

int __fastcall sub_0040C720_ReleaseReferences(int all); // 0x0040C720

int (__stdcall* gpfnSymGetLineFromAddr_0075CFE4)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine); // 0x0075CFE4

extern void* gpfnSymFunctionTableAccess_0075CFE0; // 0x0075CFE0

extern void* gpfnSymGetModuleBase_0075CFE8; // 0x0075CFE8

extern SymGetModuleInfoFn gpfnSymGetModuleInfo_0075CFEC; // 0x0075CFEC

extern SymGetSymFromAddrFn gpfnSymGetSymFromAddr_0075CFF4; // 0x0075CFF4

extern StackWalkFn gpfnStackWalk_0075D008; // 0x0075D008

extern unsigned int gnStackWalkDepth_0075D018; // 0x0075D018

struct T0040D1C0
{
    unsigned long f_0;
    unsigned long f_4;
    unsigned long dwType;
    int nCount;
    unsigned long adwData[8];
};

void __fastcall sub_0040F000_GetLogDirectory(char* szDirectory, int nSize); // 0x0040F000

void __stdcall SMemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0

#pragma pack(push, 1)

struct D2CrashDumpEntryStrc
{
    unsigned short nHits;
    unsigned long f_2;
    unsigned long f_6;
    unsigned long dwType;
    unsigned char nCount;
    unsigned long adwData[8];
};

#pragma pack(pop)

extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684782

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize); // 0x0041D200

extern "C" const char gszReadBinary_006CDC90[]; // 0x006CDC90

D2CriticalSectionStrc gtImageHlpLock_0075CFBC; // 0x0075CFBC

int gnSymInitCount_0075CFD4; // 0x0075CFD4

static void __stdcall sub_0040C520_GetLogicalAddress(char* szModule, unsigned long* pnSection, unsigned long* pnOffset, void* pAddress, unsigned int nSize);

char gszAddressText_0075D020[32]; // 0x0075D020

int ganLogNewFile_0075D298[20]; // 0x0075D298

int gbLogInitialized_0075D2EC; // 0x0075D2EC

char gaszLogFilePaths_0075D340[20][0x104]; // 0x0075D340

unsigned long gnLogThreadId_0075E834; // 0x0075E834

int gnLogQueueCount_0075E870; // 0x0075E870

struct D2ToolhelpModuleEntryStrc;

struct D2ToolhelpModuleEntryStrc
{
    unsigned long dwSize;
    unsigned long th32ModuleID;
    unsigned long th32ProcessID;
    unsigned long GlblcntUsage;
    unsigned long ProccntUsage;
    unsigned int modBaseAddr;
    unsigned int modBaseSize;
    void* hModule;
    char szModule[0x100];
    char szExePath[0x104];
};

typedef void* (__stdcall* CreateToolhelp32SnapshotFn)(unsigned long dwFlags, unsigned long dwProcessId);

typedef int (__stdcall* Module32Fn)(void* hSnapshot, D2ToolhelpModuleEntryStrc* pEntry);

typedef int (__stdcall* EnumProcessModulesFn)(void* hProcess, void** phModules, unsigned long nSize, unsigned long* pnNeeded);

typedef unsigned long (__stdcall* GetModuleNameFn)(void* hProcess, void* hModule, char* szName, unsigned long nSize);

typedef int (__stdcall* GetModuleInformationFn)(void* hProcess, void* hModule, D2PsapiModuleInfoStrc* pInfo, unsigned long nSize);

extern "C" const char gszExceptionsCpp_006CD628[]; // 0x006CD628

struct D2ImageHlpSymbolBufferStrc
{
    D2ImageHlpSymbolStrc tSymbol;
    char szNameBuffer[0x100];
};

extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* lp, unsigned int ucb); // 0x006CC238

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9

#pragma intrinsic(strlen)

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...); // 0x00410740

char* __fastcall sub_004113E0_EscapeString(char* szDst, const char* szSrc, int nSize, char cQuote); // 0x004113E0

D2ModuleInfoStrc* __fastcall sub_0040BCB0_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList); // 0x0040BCB0

extern const char gszStackEipLine_006CD938[]; // 0x006CD938

extern const char gszStackRowEnd_006CD90C[]; // 0x006CD90C

extern const char gszStackStringLine_006CD8C8[]; // 0x006CD8C8

extern const char gszStackSymbolLine_006CD890[]; // 0x006CD890

extern const char gszStackPad_006FFC44[]; // 0x006FFC44

static int __stdcall sub_0040B600_GetLineFromAddrRetry(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine);

static D2ModuleInfoStrc* __stdcall sub_0040BC50_GetModuleList(void* hProcess, unsigned long dwPid);

static D2ModuleInfoStrc* __stdcall sub_0040C0F0_EnumModuleSymbols(unsigned long dwPid, void* hProcess);

static char* sub_0040C290_ComposeSymbolPath(char* szPath);

void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...);               // 0x004106B0

void __cdecl sub_0040F960_CloseLogFiles();                                                                  // 0x0040F960

extern "C" void __fastcall sub_0040B660_FreeList(D2ModuleInfoStrc* pList);                                  // 0x0040B660

void __fastcall sub_0040BCF0_DumpAnnotatedStack(void* hProcess, D2ThreadContextStrc* pContext, D2ModuleInfoStrc* pModules); // 0x0040BCF0

struct D2FpoDataStrc
{
    unsigned long dwOffStart;
    unsigned long dwProcSize;
    unsigned long dwLocals;
    unsigned short wParams;
    unsigned short cbProlog : 8;
    unsigned short cbRegs : 3;
    unsigned short fHasSEH : 1;
    unsigned short fUseBP : 1;
    unsigned short reserved : 1;
    unsigned short cbFrame : 2;
};

// 0x0040B320
void __cdecl FOG_10082_Noop()
{
}

char gszSymSearchPath_0075BFB8[4096]; // 0x0075BFB8

int gbSymQuiet_0075CFB8; // 0x0075CFB8

// 0x0040B600
static int __stdcall sub_0040B600_GetLineFromAddrRetry(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine)
{
    if (!gpfnSymGetLineFromAddr_0075CFE4)
    {
        return 0;
    }

    unsigned long nBack = 0;
    while (!gpfnSymGetLineFromAddr_0075CFE4(hProcess, dwAddress - nBack, pdwDisplacement, pLine))
    {
        if (++nBack == 100)
        {
            return 0;
        }
    }

    if (nBack)
    {
        *pdwDisplacement = nBack;
    }

    return 1;
}

int sub_H13_EmitLineRetry(void* hProcess, unsigned long dwAddress, unsigned long dwDisplacement)
{
    D2ImageHlpLineStrc tLine;
    unsigned long dwDisp = dwDisplacement;
    tLine.dwSizeOfStruct = 0x14;
    const int bResult = sub_0040B600_GetLineFromAddrRetry(hProcess, dwAddress, &dwDisp, &tLine);
    sub_H13_EmitUse(tLine.szFileName, dwDisp, tLine.dwLineNumber, bResult);
    return bResult;
}

void sub_H13_EmitLogicalAddress(void* pAddress)
{
    char szModule[0x104];
    unsigned long nSection;
    unsigned long nOffset;
    sub_0040C520_GetLogicalAddress(szModule, &nSection, &nOffset, pAddress, sizeof(szModule));
    sub_H13_EmitUse(szModule, nSection, nOffset, 0);
}

// 0x0040B660
extern "C" void __fastcall sub_0040B660_FreeList(D2ModuleInfoStrc* pList)
{
    while (pList)
    {
        D2ModuleInfoStrc* pNext = pList->pNext;
        FOG_Free(pList, gSource_006CD628, 0x1F7, 0);
        pList = pNext;
    }
}

// 0x0040B690
D2ModuleInfoStrc* __stdcall sub_0040B690_GetModuleListToolhelp(unsigned long dwPid)
{
    D2ToolhelpModuleEntryStrc tModuleEntry;
    D2ModuleInfoStrc* pList = 0;
    CreateToolhelp32SnapshotFn pfnCreateToolhelp32Snapshot = 0;
    Module32Fn pfnModule32First = 0;
    Module32Fn pfnModule32Next = 0;
    void* hLibrary;
    const char* aszLibraries[2];
    aszLibraries[0] = "kernel32.dll";
    aszLibraries[1] = "tlhelp32.dll";

    for (int i = 0; i < 2; ++i)
    {
        hLibrary = LoadLibraryA(aszLibraries[i]);
        if (hLibrary)
        {
            pfnCreateToolhelp32Snapshot = (CreateToolhelp32SnapshotFn)GetProcAddress(hLibrary, "CreateToolhelp32Snapshot");
            pfnModule32First = (Module32Fn)GetProcAddress(hLibrary, "Module32First");
            pfnModule32Next = (Module32Fn)GetProcAddress(hLibrary, "Module32Next");
            if (pfnCreateToolhelp32Snapshot && pfnModule32First && pfnModule32Next)
            {
                break;
            }

            FreeLibrary(hLibrary);
            hLibrary = 0;
        }
    }

    if (!hLibrary)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to load toolhelp library");
        return 0;
    }

    void* hSnapshot = pfnCreateToolhelp32Snapshot(8, dwPid);
    if (hSnapshot == (void*)-1)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to get toolhelp snapshot");
        return 0;
    }

    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Enumerate modules...");
    for (int bFound = pfnModule32First(hSnapshot, &tModuleEntry); bFound; bFound = pfnModule32Next(hSnapshot, &tModuleEntry))
    {
        D2ModuleInfoStrc* pEntry = (D2ModuleInfoStrc*)FOG_Alloc(sizeof(D2ModuleInfoStrc), ".\\Src\\Exceptions.cpp", 0x253, 0);
        memset(pEntry, 0, sizeof(D2ModuleInfoStrc));
        strcpy(pEntry->szPath, tModuleEntry.szExePath);
        strcpy(pEntry->szName, tModuleEntry.szModule);
        pEntry->dwBase = tModuleEntry.modBaseAddr;
        pEntry->dwSize = tModuleEntry.modBaseSize;
        pEntry->pNext = pList;
        pList = pEntry;
        D2ModuleInfoStrc* pPrevious = 0;
        for (D2ModuleInfoStrc* pCurrent = pEntry; pCurrent; pCurrent = pPrevious->pNext)
        {
            D2ModuleInfoStrc* pNext = pCurrent->pNext;
            if (!pNext || pCurrent->dwBase <= pNext->dwBase)
            {
                break;
            }
            if (pCurrent == pList)
            {
                pList = pNext;
            }
            else
            {
                pPrevious->pNext = pNext;
            }
            pCurrent->pNext = pNext->pNext;
            pNext->pNext = pCurrent;
            pPrevious = pNext;
        }
    }

    CloseHandle(hSnapshot);
    FreeLibrary(hLibrary);
    return pList;
}

// 0x0040B920
D2ModuleInfoStrc* __stdcall sub_0040B920_BuildModuleList(void* hProcess)
{
    void* ahModules[0x100];
    char szFileName[0x104];
    char szBaseName[0x100];
    unsigned long nNeeded;
    D2PsapiModuleInfoStrc tInfo;
    D2ModuleInfoStrc* pList = 0;
    void* hPsapi = LoadLibraryA("psapi.dll");
    if (!hPsapi)
    {
        return 0;
    }
    EnumProcessModulesFn pfnEnumProcessModules = (EnumProcessModulesFn)GetProcAddress(hPsapi, "EnumProcessModules");
    GetModuleNameFn pfnGetModuleFileNameEx = (GetModuleNameFn)GetProcAddress(hPsapi, "GetModuleFileNameExA");
    GetModuleNameFn pfnGetModuleBaseName = (GetModuleNameFn)GetProcAddress(hPsapi, "GetModuleBaseNameA");
    GetModuleInformationFn pfnGetModuleInformation = (GetModuleInformationFn)GetProcAddress(hPsapi, "GetModuleInformation");
    if (!pfnEnumProcessModules || !pfnGetModuleFileNameEx || !pfnGetModuleBaseName || !pfnGetModuleInformation)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to load psapi library");
        goto failed;
    }
    if (!pfnEnumProcessModules(hProcess, ahModules, sizeof(ahModules), &nNeeded))
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Error enumerating modules using PSAPI:  error(%d)", GetLastError());
        goto failed;
    }
    {
        const int nModules = nNeeded / sizeof(void*);
        if (nModules > 0x100)
        {
            sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "PSAPI EnumProcessModules returned invalid number of modules");
            goto failed;
        }
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "\nEnumerate modules...");
        for (int i = 0; i < nModules; ++i)
        {
            if (!pfnGetModuleInformation(hProcess, ahModules[i], &tInfo, sizeof(tInfo)))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: PSAPI GetModuleInformation (%d)", GetLastError());
                goto failed;
            }
            if (!pfnGetModuleFileNameEx(hProcess, ahModules[i], szFileName, sizeof(szFileName)))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: PSAPI GetModuleFileNameExA (%d)", GetLastError());
                goto failed;
            }
            if (!pfnGetModuleBaseName(hProcess, ahModules[i], szBaseName, sizeof(szBaseName) - 1))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: PSAPI GetModuleBaseNameA (%d)", GetLastError());
                goto failed;
            }
            D2ModuleInfoStrc* pEntry = (D2ModuleInfoStrc*)FOG_Alloc(sizeof(D2ModuleInfoStrc), gszExceptionsCpp_006CD628, 0x2D3, 0);
            memset(pEntry, 0, sizeof(D2ModuleInfoStrc));
            strcpy(pEntry->szPath, szFileName);
            strcpy(pEntry->szName, szBaseName);
            pEntry->dwBase = tInfo.nBase;
            pEntry->dwSize = tInfo.nSize;
            pEntry->pNext = pList;
            pList = pEntry;
            D2ModuleInfoStrc* pPrevious = 0;
            for (D2ModuleInfoStrc* pCurrent = pEntry; pCurrent; pCurrent = pPrevious->pNext)
            {
                D2ModuleInfoStrc* pNext = pCurrent->pNext;
                if (!pNext || pCurrent->dwBase <= pNext->dwBase)
                {
                    break;
                }
                if (pCurrent == pList)
                {
                    pList = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }
                pCurrent->pNext = pNext->pNext;
                pNext->pNext = pCurrent;
                pPrevious = pNext;
            }
        }
    }
    FreeLibrary(hPsapi);
    return pList;

failed:
    FreeLibrary(hPsapi);
    sub_0040B660_FreeList(pList);
    return 0;
}

// 0x0040BC50
static D2ModuleInfoStrc* __stdcall sub_0040BC50_GetModuleList(void* hProcess, unsigned long dwPid)
{
    D2ModuleInfoStrc* pList = sub_0040B690_GetModuleListToolhelp(dwPid);
    if (!pList)
    {
        pList = sub_0040B920_GetModuleListPsapi(hProcess);
    }

    for (D2ModuleInfoStrc* pModule = pList; pModule; pModule = pModule->pNext)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "    Base:%08lXh  Size:%7lXh  Name:%-15.15s  Path:%s", pModule->dwBase, pModule->dwSize, pModule->szName, pModule->szPath);
    }

    return pList;
}

extern "C" FourWords* __stdcall sub_006BD040_AllocateFourWords(const char* file, int line)
{
    FourWords* result = (FourWords*)FOG_AllocPool(0, 0x10, file, line, 0);
    result->first = 0;
    result->second = 0;
    result->third = 0;
    result->fourth = 0;
    return result;
}

extern "C" unsigned char __fastcall sub_0059D7E0_QuestStateCheck(void* game)
{
    QuestView* quest = QUESTS_GetQuestData(game, 0xD);
    if (quest && quest->active != 0 && quest->state == 1)
        return 1;
    return 0;
}

// 0x0040BCB0
D2ModuleInfoStrc* __fastcall sub_0040BCB0_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList)
{
    for (D2ModuleInfoStrc* pModule = pList; pModule; pModule = pModule->pNext)
    {
        if (dwAddress >= pModule->dwBase && dwAddress < pModule->dwBase + pModule->dwSize)
            return pModule;
    }
    return 0;
}

// 0x0040BCF0
void __fastcall sub_0040BCF0_DumpAnnotatedStack(void* hProcess, D2ThreadContextStrc* pContext, D2ModuleInfoStrc* pModules)
{
    D2ImageHlpSymbolBufferStrc tSymbol;
    char szEscaped[0x50];
    char szLine[0x100];

    unsigned char* pStack = (unsigned char*)pContext->Esp;
    tSymbol.tSymbol.dwSizeOfStruct = 0x18;
    tSymbol.tSymbol.dwMaxNameLength = 0x100;
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Annotated stack dump");

    {
        unsigned long dwDisplacement;
        unsigned long dwEip = pContext->Eip;
        D2ModuleInfoStrc* pModule = sub_0040BCB0_FindModuleByAddress(dwEip, pModules);
        const char* szSymbol = gpfnSymGetSymFromAddr_0075CFF4(hProcess, dwEip, &dwDisplacement, &tSymbol.tSymbol) ? tSymbol.tSymbol.szName : "unknown";
        const char* szModule = pModule ? pModule->szName : "unknown";
        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackEipLine_006CD938, dwEip, szModule, szSymbol, dwDisplacement);
    }

    int nLines = 0;
    unsigned int nRemaining = 0x1000;
    while (nRemaining > 0)
    {
        if (nLines >= 400)
            break;
        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "              %08X:", pStack);
        int nCount = nRemaining < 16 ? nRemaining : 16;
        szLine[0] = 0;
        int bFound = 0;
        if (IsBadReadPtr(pStack, nCount))
        {
            SStrCopy(szLine, "<unreadable>", 0x7FFFFFFF);
            break;
        }

        int i;
        for (i = 0; i < nCount; i += 4)
        {
            int nLen = strlen(szLine);
            SStrPrintf(&szLine[nLen], 0x100 - nLen, " %02X%02X%02X%02X", pStack[i], pStack[i + 1], pStack[i + 2], pStack[i + 3]);
            if (sub_0040BCB0_FindModuleByAddress(*(unsigned long*)&pStack[i], pModules))
            {
                bFound = 1;
                i += 4;
                break;
            }
        }

        int nBytes = i;
        for (i = (unsigned int)((16 - i) * 9) / 4 + 2; i > 0; i--)
            SStrPack(szLine, gszStackPad_006FFC44, 0x100);

        int nLen = strlen(szLine);
        int j = nLen;
        for (i = 0; i < nBytes; i++)
        {
            unsigned char c = pStack[i];
            szLine[j++] = (c & 0x7F) < 0x20 ? '.' : c;
        }
        szLine[nLen + i] = 0;
        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackRowEnd_006CD90C, szLine);

        if (bFound)
        {
            unsigned long dwValue = *(unsigned long*)&pStack[nBytes - 4];
            D2ModuleInfoStrc* pValueModule = sub_0040BCB0_FindModuleByAddress(dwValue, pModules);
            D2_ASSERT(pValueModule, 0x3A5);
            unsigned long dwValueDisplacement;
            const char* szName = gpfnSymGetSymFromAddr_0075CFF4(hProcess, dwValue, &dwValueDisplacement, &tSymbol.tSymbol) ? tSymbol.tSymbol.szName : "unknown";
            if (!_stricmp(szName, "`string'") && !dwValueDisplacement)
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackStringLine_006CD8C8, dwValue, pValueModule->szName, szName, sub_004113E0_EscapeString(szEscaped, (const char*)dwValue, 0x50, 0));
            else
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszStackSymbolLine_006CD890, dwValue, pValueModule->szName, szName, dwValueDisplacement);
            nLines += 3;
        }

        nLines++;
        nRemaining -= nBytes;
        pStack += nBytes;
    }
}

// 0x0040C0F0
static D2ModuleInfoStrc* __stdcall sub_0040C0F0_EnumModuleSymbols(unsigned long dwPid, void* hProcess)
{
    char szImageName[0x104];
    char szModuleName[0x100];

    D2ModuleInfoStrc* pList = sub_0040BC50_GetModuleList(hProcess, dwPid);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Load symbols...");

    D2ModuleInfoStrc* pModule = pList;
    while (pModule)
    {
        D2ModuleInfoStrc* pNext = pModule->pNext;
        strcpy(szImageName, pModule->szPath);
        strcpy(szModuleName, pModule->szName);
        const unsigned long dwLoaded = gpfnSymLoadModule_0075CFFC(hProcess, 0, szImageName, szModuleName, pModule->dwBase, pModule->dwSize);
        if (!gbSymQuiet_0075CFB8)
        {
            if (!dwLoaded)
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Error (%d) loading symbols for '%s'", GetLastError(), szModuleName);
            }
            else
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Symbols Loaded for '%s'", szModuleName);
            }
        }

        pModule = pNext;
    }

    return pList;
}

// 0x0040C220
int __fastcall sub_0040C220_GetAppPath(char* szPath, unsigned int nSize)
{
    szPath[0] = 0;
    if (!GetModuleFileNameA(0, szPath, nSize))
    {
        return 0;
    }
    int i;
    for (i = (int)strlen(szPath) - 1; i > 0; i--)
    {
        if (szPath[i] == '\\' || szPath[i] == '/' || szPath[i] == ':')
        {
            break;
        }
    }
    if (i <= 0)
    {
        return 0;
    }
    if (szPath[i] == ':')
    {
        i += 1;
    }
    szPath[i] = 0;
    return 1;
}

// 0x0040C290
static char* sub_0040C290_ComposeSymbolPath(char* szPath)
{
    char szCurrentDir[0x200];
    char szBuffer[0x200];

    *szPath = 0;
    if (!sub_0040C220_GetAppPath(szBuffer, 0x200))
    {
        szBuffer[0] = 0;
    }
    else
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetCurrentDirectoryA(0x200, szCurrentDir))
    {
        if (!szBuffer[0] || _stricmp(szBuffer, szCurrentDir))
        {
            strcat(szPath, szCurrentDir);
            strcat(szPath, ";");
        }
    }

    if (GetEnvironmentVariableA("_NT_SYMBOL_PATH", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetEnvironmentVariableA("_NT_ALTERNATE_SYMBOL_PATH", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetEnvironmentVariableA("SYSTEMROOT", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    const size_t nLength = strlen(szPath);
    if (nLength)
    {
        szPath[nLength - 1] = 0;
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "User defined symbols path: %s", szPath);
    }
    else
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Unable to generate symbols search path");
    }

    return *szPath ? szPath : 0;
}

// 0x0040C520
static void __stdcall sub_0040C520_GetLogicalAddress(char* szModule, unsigned long* pnSection, unsigned long* pnOffset, void* pAddress, unsigned int nSize)
{
    D2MemoryBasicInfoStrc tInfo;

    SStrCopy(szModule, gszUnknown_006CD5FC, nSize);
    *pnSection = 0;
    *pnOffset = 0;
    if (!VirtualQuery(pAddress, &tInfo, sizeof(tInfo)))
    {
        return;
    }

    void* hModule = tInfo.AllocationBase;
    if (!hModule)
    {
        hModule = GetModuleHandleA(0);
    }

    if (!GetModuleFileNameA(hModule, szModule, nSize))
    {
        SStrCopy(szModule, gszUnknown_006CD5FC, nSize);
        return;
    }

    D2PeDosHeaderStrc* pDosHeader = (D2PeDosHeaderStrc*)hModule;
    if (!pDosHeader || pDosHeader->f_0 != 0x5A4D || !pDosHeader->nNtHeadersOffset)
    {
        return;
    }

    D2PeNtHeadersStrc* pNtHeaders = (D2PeNtHeadersStrc*)((char*)pDosHeader + pDosHeader->nNtHeadersOffset);
    if (pNtHeaders->dwSignature != 0x4550)
    {
        return;
    }

    D2PeSectionStrc* pSection = (D2PeSectionStrc*)(pNtHeaders->aOptionalHeader + pNtHeaders->wSizeOfOptionalHeader);
    const unsigned long dwRva = (char*)pAddress - (char*)hModule;
    for (unsigned int i = 0; i < pNtHeaders->wNumberOfSections; ++i, ++pSection)
    {
        const unsigned long dwStart = pSection->dwVirtualAddress;
        const unsigned long dwLength = pSection->dwSizeOfRawData > pSection->dwVirtualSize ? pSection->dwSizeOfRawData : pSection->dwVirtualSize;
        if (dwRva >= dwStart && dwRva <= dwStart + dwLength)
        {
            *pnSection = i + 1;
            *pnOffset = dwRva - dwStart;
            return;
        }
    }
}

// 0x0040C620
int __cdecl s_DoSymInitialize()
{
    int bResult = 0;
    EnterCriticalSection(&gtImageHlpLock_0075CFBC);
    if (gbImageHlpLoaded_0075D014)
    {
        bResult = 1;
        if (gnSymInitCount_0075CFD4++ <= 0)
        {
            if (!gszSymSearchPath_0075BFB8[0])
            {
                sub_0040C290_ComposeSymbolPath(gszSymSearchPath_0075BFB8);
            }

            void* hProcess = GetCurrentProcess();
            if (!gpfnSymInitialize_0075CFF8(hProcess, gszSymSearchPath_0075BFB8, 0))
            {
                sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "s_DoSymInitialize(): err = %lu", GetLastError());
                gpfnSymCleanup_0075CFDC(hProcess);
                bResult = 0;
                gnSymInitCount_0075CFD4 = 0;
            }
            else
            {
                ++gnSymInitCount_0075CFD4;
                gpfnSymSetOptions_0075D004(gpfnSymGetOptions_0075CFF0() | 0x10);
                D2ModuleInfoStrc* pModule = sub_0040C0F0_EnumModuleSymbols(GetCurrentProcessId(), hProcess);
                if (pModule)
                {
                    do
                    {
                        D2ModuleInfoStrc* pNext = pModule->pNext;
                        FOG_Free(pModule, gszExceptionsCppFile_006CD628, 0x1F7, 0);
                        pModule = pNext;
                    }
                    while (pModule);
                }
            }
        }
    }

    LeaveCriticalSection(&gtImageHlpLock_0075CFBC);
    return bResult;
}

// 0x0040C720
int __fastcall sub_0040C720_ReleaseReferences(int all)
{
    int result = 0;
    if (!gbImageHlpLoaded_0075D014)
    {
        return 0;
    }
    EnterCriticalSection(&gtImageHlpLock_0075CFBC);
    int nCount = gnSymInitCount_0075CFD4;
    do
    {
        if (!nCount)
        {
            break;
        }
        gnSymInitCount_0075CFD4 = --nCount;
        if (nCount)
        {
            result = 1;
            break;
        }
        gpfnSymCleanup_0075CFDC(GetCurrentProcess());
        if (!all)
        {
            break;
        }
        nCount = gnSymInitCount_0075CFD4;
    } while (nCount);
    LeaveCriticalSection(&gtImageHlpLock_0075CFBC);
    return result;
}

// 0x0040C7A0
int __fastcall QuickStackWalk(const char* szPrefix, void* hThread, D2ThreadContextStrc* pContext)
{
    if (gnStackWalkDepth_0075D018 > 0)
    {
        return 0;
    }

    ++gnStackWalkDepth_0075D018;

    __int64 aTotals[4] = {};
    __int64 aStart[4] = {};
    __int64 aEnd[4] = {};

    void* hProcess = GetCurrentProcess();
    if (!s_DoSymInitialize())
    {
        --gnStackWalkDepth_0075D018;
        return 0;
    }
    aTotals[3] += aEnd[3] - aStart[3];

    D2ImageHlpStackFrameStrc tFrame;
    memset(&tFrame, 0, sizeof(tFrame));
    tFrame.tAddrPC.dwOffset = pContext->Eip;
    tFrame.tAddrPC.nMode = 3;
    tFrame.tAddrStack.dwOffset = pContext->Esp;
    tFrame.tAddrStack.nMode = 3;
    tFrame.tAddrFrame.dwOffset = pContext->Ebp;
    tFrame.tAddrFrame.nMode = 3;

    char aSymbolBuffer[sizeof(D2ImageHlpSymbolStrc) + 0x100];
    D2ImageHlpSymbolStrc* pSymbol = (D2ImageHlpSymbolStrc*)aSymbolBuffer;
    pSymbol->dwSizeOfStruct = sizeof(D2ImageHlpSymbolStrc);
    pSymbol->dwMaxNameLength = 0x100;

    unsigned long aStack[64];
    int nFailures = 0;
    int nEntries;
    for (nEntries = 0; nEntries < 16; ++nEntries)
    {
        if (nFailures >= 3)
        {
            break;
        }

        if (!gpfnStackWalk_0075D008(0x14C, hProcess, hThread, &tFrame, pContext, 0, gpfnSymFunctionTableAccess_0075CFE0, gpfnSymGetModuleBase_0075CFE8, 0))
        {
            aTotals[0] += aEnd[0] - aStart[0];
            break;
        }
        aTotals[0] += aEnd[0] - aStart[0];

        if (nEntries >= 1)
        {
            aStack[nEntries] = tFrame.tAddrPC.dwOffset;
            const char* szSymbol;
            unsigned long dwDisplacement = 0;
            D2ImageHlpLineStrc tLine;
            memset(&tLine, 0, sizeof(tLine));
            tLine.dwSizeOfStruct = sizeof(tLine);
            if (gpfnSymGetSymFromAddr_0075CFF4(hProcess, tFrame.tAddrPC.dwOffset, &dwDisplacement, pSymbol))
            {
                szSymbol = pSymbol->szName;
                unsigned long dwLineDisplacement = dwDisplacement;
                if (!sub_0040B600_GetLineFromAddrRetry(hProcess, tFrame.tAddrPC.dwOffset, &dwLineDisplacement, &tLine))
                {
                    tLine.dwLineNumber = 0;
                }
            }
            else
            {
                ++nFailures;
                szSymbol = gszUnknown_006CD5FC;
            }
            aTotals[1] += aEnd[1] - aStart[1];

            D2ImageHlpModuleStrc tModule;
            memset(&tModule, 0, sizeof(tModule));
            tModule.dwSizeOfStruct = sizeof(tModule);
            if (!gpfnSymGetModuleInfo_0075CFEC(hProcess, tFrame.tAddrPC.dwOffset, &tModule))
            {
                GetLastError();
                tModule.szModuleName[0] = 0;
            }
            aTotals[2] += aEnd[2] - aStart[2];

            if (tLine.dwLineNumber)
            {
                const char* szFile = sub_00408000_StripSourcePath(tLine.szFileName);
                int nPad = 40 - SStrLen(tModule.szModuleName) - SStrLen(szSymbol);
                if (nPad < 1)
                {
                    nPad = 1;
                }
                sub_00410660_LogWritePrefixed(szPrefix, "    %08X  %s!%s+%04X  %*s%s,%d", tFrame.tAddrPC.dwOffset, tModule.szModuleName, szSymbol, dwDisplacement, nPad, gszEmptyString_006FFC44, szFile, tLine.dwLineNumber);
            }
            else
            {
                sub_00410660_LogWritePrefixed(szPrefix, "    %08X  %s!%s+%04X", tFrame.tAddrPC.dwOffset, tModule.szModuleName, szSymbol, dwDisplacement);
            }
        }
    }

    sub_0040C720_ReleaseReferences(0);
    sub_00410660_LogWritePrefixed(szPrefix, "QuickStackWalk: %d entries, %I64d+%I64d+%I64d+%I64d cycles, %I64d avg", nEntries, aTotals[0], aTotals[1], aTotals[2], aTotals[3], (aTotals[0] + aTotals[1] + aTotals[2] + aTotals[3]) / nEntries);
    --gnStackWalkDepth_0075D018;
    return 1;
}

// 0x0040CC10
int __fastcall sShowStack(void* hThread, D2ThreadContextStrc* pContext)
{
    unsigned long dwNoStackDump = 0;
    SRegLoadValue("Diablo II", "NoStackDump", 0, &dwNoStackDump);
    if (dwNoStackDump)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "sShowStack: Stack dump turned off in registry");
        return 0;
    }

    if (!gbImageHlpLoaded_0075D014)
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "sShowStack: imagehlp.dll not loaded");
        return 0;
    }

    void* hProcess = 0;
    DuplicateHandle(GetCurrentProcess(), GetCurrentProcess(), GetCurrentProcess(), &hProcess, 0, 0, 2);

    char szSearchPath[0x1000];
    const char* szPath = sub_0040C290_ComposeSymbolPath(szSearchPath);
    if (!gpfnSymInitialize_0075CFF8(hProcess, szPath, 0))
    {
        sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "SymInitialize(): gle = %lu", GetLastError());
        gpfnSymCleanup_0075CFDC(hProcess);
        CloseHandle(hProcess);
        return 0;
    }

    gpfnSymSetOptions_0075D004(gpfnSymGetOptions_0075CFF0() | 0x10);
    const unsigned long dwProcessId = GetCurrentProcessId();
    D2ModuleInfoStrc* pModules = sub_0040C0F0_EnumModuleSymbols(dwProcessId, hProcess);
    sub_0040BCF0_DumpAnnotatedStack(hProcess, pContext, pModules);
    sub_0040B660_FreeList(pModules);
    sub_0040F960_CloseLogFiles();

    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Stack Crawl:");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Address  Frame    Module       Return    Stack");

    D2ImageHlpStackFrameStrc tFrame;
    memset(&tFrame, 0, sizeof(tFrame));
    tFrame.tAddrPC.dwOffset = pContext->Eip;
    tFrame.tAddrPC.nMode = 3;
    tFrame.tAddrStack.dwOffset = pContext->Esp;
    tFrame.tAddrStack.nMode = 3;
    tFrame.tAddrFrame.dwOffset = pContext->Ebp;
    tFrame.tAddrFrame.nMode = 3;

    D2ImageHlpSymbolBufferStrc tSymbol;
    D2ImageHlpSymbolStrc* pSymbol = &tSymbol.tSymbol;
    pSymbol->dwSizeOfStruct = 0x18;
    pSymbol->dwMaxNameLength = 0x100;

    D2ImageHlpModuleStrc tModule;
    char szModule[0x104];
    int nUnknown = 0;
    int nFrames;
    for (nFrames = 0; nFrames < 0x40; ++nFrames)
    {
        if (nUnknown >= 3)
        {
            break;
        }

        if (!gpfnStackWalk_0075D008(0x14C, hProcess, hThread, &tFrame, pContext, 0, gpfnSymFunctionTableAccess_0075CFE0, gpfnSymGetModuleBase_0075CFE8, 0))
        {
            sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "Stack walk error: %d", GetLastError());
            break;
        }

        unsigned long dwSymDisplacement = 0;
        D2ImageHlpLineStrc tLine;
        memset(&tLine, 0, sizeof(tLine));
        const char* szSymbol;
        if (gpfnSymGetSymFromAddr_0075CFF4(hProcess, tFrame.tAddrPC.dwOffset, &dwSymDisplacement, pSymbol))
        {
            szSymbol = pSymbol->szName;
            unsigned long dwLineDisplacement = dwSymDisplacement;
            tLine.dwSizeOfStruct = 0x14;
            if (!sub_0040B600_GetLineFromAddrRetry(hProcess, tFrame.tAddrPC.dwOffset, &dwLineDisplacement, &tLine))
            {
                tLine.dwLineNumber = 0;
            }
        }
        else
        {
            ++nUnknown;
            szSymbol = gszUnknown_006CD5FC;
        }

        unsigned long nSection;
        unsigned long dwOffset;
        sub_0040C520_GetLogicalAddress(szModule, &nSection, &dwOffset, (void*)tFrame.tAddrPC.dwOffset, sizeof(szModule));
        const char* szModuleName = strrchr(szModule, '\\');
        sub_004106B0_LogWritePrefixed0(&gszEmptyAssertText, "%08x %08x %-12s ", tFrame.tAddrPC.dwOffset, tFrame.tAddrFrame.dwOffset, szModuleName ? szModuleName + 1 : szModule);

        tModule.dwSizeOfStruct = 0x23C;
        if (gpfnSymGetModuleInfo_0075CFEC(hProcess, tFrame.tAddrPC.dwOffset, &tModule))
        {
            sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "%s!", tModule.szModuleName);
        }

        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "%s+%04X ", szSymbol, dwSymDisplacement);
        if (pSymbol->dwFlags & 3)
        {
            sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "[omap] ");
        }

        if (tFrame.pFuncTableEntry)
        {
            D2FpoDataStrc* pFpo = (D2FpoDataStrc*)tFrame.pFuncTableEntry;
            switch (pFpo->cbFrame)
            {
            case 0:
                if (pFpo->fHasSEH)
                {
                    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "(FPO: [SEH])");
                }
                else
                {
                    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, " (FPO:");
                    if (pFpo->fUseBP)
                    {
                        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, " [EBP 0x%08x]", tFrame.dwReserved[0]);
                    }

                    sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, " [%d, %d, %d])", pFpo->wParams, pFpo->dwLocals, pFpo->cbRegs);
                }
                break;

            case 3:
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "(FPO: Non-FPO [%d, %d, %d])", pFpo->wParams, pFpo->dwLocals, pFpo->cbRegs);
                break;

            default:
                sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "(UNKNOWN FPO TYPE)");
                break;
            }
        }

        if (tLine.dwLineNumber)
        {
            const char* szFile = strrchr(tLine.szFileName, '\\');
            szFile = szFile ? szFile + 1 : tLine.szFileName;
            int nPad = 0x18 - SStrLen(szSymbol);
            if (nPad < 1)
            {
                nPad = 1;
            }

            sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, "%*s %s, %d", nPad, gszSpace_006FFC44, szFile, tLine.dwLineNumber);
        }

        sub_00410740_LogWritePrefixed00(&gszEmptyAssertText, gszNewline_006FFCB0);
    }

    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "%d frames dumped", nFrames);
    sub_0040F960_CloseLogFiles();
    gpfnSymCleanup_0075CFDC(hProcess);
    CloseHandle(hProcess);
    return 1;
}

// 0x0040D1C0
void __fastcall sub_0040D1C0_AppendCrashDump(unsigned long dwHeader0, unsigned long dwHeader1, unsigned long dwType, int nCount, const void* pData)
{
    char szPath[0x104];
    T0040D1C0 tRecord;
    sub_0040F000_GetLogDirectory(szPath, 0x104);
    SStrPack(szPath, "Crashdump", 0x104);
    _iobuf* pFile = fopen(szPath, "ab");
    if (pFile)
    {
        tRecord.f_0 = dwHeader0;
        tRecord.f_4 = dwHeader1;
        tRecord.dwType = dwType;
        tRecord.nCount = nCount;
        SMemCopy(tRecord.adwData, pData, nCount * 4);
        fwrite(&tRecord, nCount * 4 + 0x10, 1, pFile);
        fclose(pFile);
    }
}

// 0x0040D290
int __fastcall sub_0040D290_GetData(char* pBuffer, unsigned int* pnSize)
{
    char szPath[0x104];
    unsigned long adwData[8];

    sub_0040F000_GetLogDirectory(szPath, 0x104);
    SStrPack(szPath, "Crashdump", 0x104);
    if (GetFileAttributesA(szPath) == 0xFFFFFFFF)
    {
        return 0;
    }

    const unsigned int nMaxSize = *pnSize;
    _iobuf* pFile = fopen(szPath, gszReadBinary_006CDC90);
    if (!pFile)
    {
        return 0;
    }

    if (fseek(pFile, 0, 2))
    {
        fclose(pFile);
        return 0;
    }

    const long nFileSize = ftell(pFile);
    fseek(pFile, 0, 0);
    char* pData = (char*)FOG_Alloc(nFileSize, gSource_006CD628, 0x75B, 0);
    fread(pData, 1, nFileSize, pFile);
    fclose(pFile);
    DeleteFileA(szPath);

    *pnSize = 1;
    int nEntries = 0;
    const unsigned long* pEnd = (const unsigned long*)(pData + nFileSize);
    const unsigned long* pRecord = (const unsigned long*)pData;
    if (pRecord < pEnd)
    {
        const char* pLimit = pBuffer + nMaxSize;
        do
        {
            const unsigned long dwHeader0 = *pRecord++;
            const unsigned long dwHeader1 = *pRecord++;
            const unsigned long dwType = *pRecord++;
            const int nCount = *pRecord++;
            const unsigned int nDataSize = nCount * 4;
            SMemCopy(adwData, pRecord, nDataSize);
            pRecord = (const unsigned long*)((const char*)pRecord + nDataSize);

            D2CrashDumpEntryStrc* pEntry = (D2CrashDumpEntryStrc*)(pBuffer + 1);
            int i;
            for (i = 0; i < nEntries; ++i)
            {
                if (pEntry->f_2 == dwHeader0 && pEntry->f_6 == dwHeader1 && pEntry->dwType == dwType
                    && pEntry->nCount == (unsigned char)nCount && !SMemCmp(pEntry->adwData, adwData, nDataSize))
                {
                    ++pEntry->nHits;
                    break;
                }
                pEntry = (D2CrashDumpEntryStrc*)((char*)pEntry + nDataSize + 0xF);
            }

            if (i == nEntries)
            {
                if ((char*)(pEntry + 1) >= pLimit)
                {
                    break;
                }

                pEntry->nHits = 1;
                pEntry->f_2 = dwHeader0;
                pEntry->f_6 = dwHeader1;
                pEntry->dwType = dwType;
                pEntry->nCount = (unsigned char)nCount;
                SMemCopy(pEntry->adwData, adwData, nDataSize);
                ++nEntries;
                *pnSize += nDataSize + 0xF;
            }
        }
        while (pRecord < pEnd);
    }

    *pBuffer = (char)nEntries;
    return 1;
}


// 0x0040E080
char* __fastcall sub_0040E080_AddressToString(int nAddress)
{
    D2InAddrStrc tAddress;
    tAddress.s_addr = nAddress;
    return strcpy(gszAddressText_0075D020, inet_ntoa(tAddress));
}

// 0x0040EB90
unsigned int __fastcall sub_0040EB90_GetLogFiles(char** apszFiles, unsigned int nCount)
{
    unsigned int i;
    for (i = 0; i < nCount; i++)
    {
        if (i >= 20)
        {
            break;
        }
        apszFiles[i] = gaszLogFilePaths_0075D340[i];
    }
    return i;
}

// 0x0040F470
void __fastcall sub_0040F470_LookupLog(const char* szName)
{
    for (int i = 0; i < 20; i++)
    {
        if (gapLogFiles_0075E790[i] && !strcmp(gaszLogNames_0075D148[i], szName))
        {
            if (gapLogFiles_0075E790[i])
            {
                fclose(gapLogFiles_0075E790[i]);
                gapLogFiles_0075E790[i] = 0;
            }
            return;
        }
    }
}

// 0x0040FD00
void D2TSListStrc::sub_0040FD00_UnlinkAll()
{
    D2TSLinkStrc* pNode;
    while ((pNode = Head()) != 0)
    {
        pNode->Unlink();
    }
}

// 0x00410540
void __cdecl sub_00410540_InitLogSystem()
{
    gbLogThreadStop_0075E830 = 0;
    ghLogThread_0075D2E8 = CreateThread(0, 0, sub_004101C0_LogThreadProc, 0, 0, &gnLogThreadId_0075E834);
    gbLogInitialized_0075D2EC = 1;
    GetLocalTime(&gLogStartTime_0075D288);
    for (unsigned int i = 0; i < 20; i++)
    {
        ganLogNewFile_0075D298[i] = 1;
    }
    for (unsigned int i = 0; i < 20; i++)
    {
        gaszLogFilePaths_0075D340[i][0] = 0;
    }
}

extern "C" void __cdecl sub_0043F800_FreeList()
{
    List204* node = gList_0077BDB4;
    while (node)
    {
        List204* next = node->next;
        FOG_Free(node, gSource_006D5460, 0x1C01, 0);
        node = next;
    }
    gList_0077BDB4 = 0;
}

extern "C" void __cdecl sub_004797C0_FreeList()
{
    List08* node = gList_007BB5C8;
    while (node)
    {
        List08* next = node->next;
        FOG_Free(node, gSource_006D7268, 0x22F, 0);
        node = next;
    }
    gList_007BB5C8 = 0;
}

extern "C" void __cdecl sub_0049A020_FreeList()
{
    ListCD* node = gList_007BF014;
    while (node)
    {
        ListCD* next = node->next;
        FOG_Free(node, gSource_006DA04C, 0x108, 0);
        node = next;
    }
    gList_007BF014 = 0;
}


#include "gen/data/Source/Fog/Src/Exceptions.inc"
