#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;
struct FSafeSock;
struct D2InAddrStrc;
struct D2TSLinkStrc;
struct D2TSListStrc;
struct D2ImageHlpLineStrc;
struct D2PeDosHeaderStrc;
struct D2PeNtHeadersStrc;
struct D2PeSectionStrc;
struct List20C;
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
struct D2AddressStrc;
struct D2StackFrameStrc;
struct D2ImageHlpSymbolStrc;
struct D2ImageHlpModuleStrc;
struct D2ContextStrc;
struct T0040D1C0;
struct D2CrashDumpEntryStrc;
struct D2SystemTimeStrc;
struct D2ModuleInfoStrc;
struct D2MemoryBasicInfoStrc;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

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

struct D2InAddrStrc
{
    unsigned long s_addr;
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

struct List20C
{
    char gap00[0x20C];
    List20C* next;
};

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

typedef char List20C_next[OFFSET(List20C,next)==0x20C?1:-1];

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

struct D2AddressStrc
{
    unsigned long dwOffset;
    unsigned short wSegment;
    int nMode;
};

struct D2StackFrameStrc
{
    D2AddressStrc tAddrPC;
    D2AddressStrc tAddrReturn;
    D2AddressStrc tAddrFrame;
    D2AddressStrc tAddrStack;
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

struct D2ContextStrc
{
    char unk0x00[0xB4];
    unsigned long dwEbp;
    unsigned long dwEip;
    unsigned long dwSegCs;
    unsigned long dwEFlags;
    unsigned long dwEsp;
};

typedef int (__stdcall* StackWalkFn)(unsigned long dwMachine, void* hProcess, void* hThread, D2StackFrameStrc* pFrame, void* pContext, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase, void* pfnTranslateAddress);

typedef int (__stdcall* SymGetSymFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpSymbolStrc* pSymbol);

typedef int (__stdcall* SymGetModuleInfoFn)(void* hProcess, unsigned long dwAddress, D2ImageHlpModuleStrc* pModuleInfo);

typedef int (__stdcall* SymGetLineFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" const char gszEmptyString_006FFC44[]; // 0x006FFC44
const char* __fastcall sub_00408000_StripSourcePath(const char* szPath); // 0x00408000
int __stdcall SStrLen(const char* szString); // 0x00413750
int __cdecl sub_0040C620_SymInitializeOnce(); // 0x0040C620
int __fastcall sub_0040C720_SymCleanupOnce(int bAll); // 0x0040C720
extern SymGetLineFromAddrFn gpfnSymGetLineFromAddr_0075CFE4; // 0x0075CFE4
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
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0

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
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
int __stdcall SMemCmp(const void* pLocation1, const void* pLocation2, unsigned int nSize); // 0x0041D200
extern "C" const char gszReadBinary_006CDC90[]; // 0x006CDC90
extern D2CriticalSectionStrc gtImageHlpLock_0075CFBC; // 0x0075CFBC
extern int gnSymInitCount_0075CFD4; // 0x0075CFD4
extern int (__stdcall *gpCleanup_0075CFDC)(void*); // 0x0075CFDC

static void __stdcall sub_0040C520_GetLogicalAddress(char* szModule, unsigned long* pnSection, unsigned long* pnOffset, void* pAddress, unsigned int nSize);

char gszAddressText_0075D020[32]; // 0x0075D020

int ganLogNewFile_0075D298[20]; // 0x0075D298

int gbLogInitialized_0075D2EC; // 0x0075D2EC

char gaszLogFilePaths_0075D340[20][0x104]; // 0x0075D340

unsigned long gnLogThreadId_0075E834; // 0x0075E834

int gnLogQueueCount_0075E870; // 0x0075E870

// 0x0040B320
void __cdecl FOG_10082_Noop()
{
}

char gszSymSearchPath_0075BFB8[4096]; // 0x0075BFB8

int gbSymQuiet_0075CFB8; // 0x0075CFB8

D2CriticalSectionStrc gtImageHlpLock_0075CFBC; // 0x0075CFBC

int gnSymInitCount_0075CFD4; // 0x0075CFD4

int (__stdcall* gpfnSymGetLineFromAddr_0075CFE4)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine); // 0x0075CFE4

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

__declspec(noinline) int sub_H13_EmitLineRetry(void* hProcess, unsigned long dwAddress, unsigned long dwDisplacement)
{
    D2ImageHlpLineStrc tLine;
    unsigned long dwDisp = dwDisplacement;
    tLine.dwSizeOfStruct = 0x14;
    const int bResult = sub_0040B600_GetLineFromAddrRetry(hProcess, dwAddress, &dwDisp, &tLine);
    sub_H13_EmitUse(tLine.szFileName, dwDisp, tLine.dwLineNumber, bResult);
    return bResult;
}

__declspec(noinline) void sub_H13_EmitLogicalAddress(void* pAddress)
{
    char szModule[0x104];
    unsigned long nSection;
    unsigned long nOffset;
    sub_0040C520_GetLogicalAddress(szModule, &nSection, &nOffset, pAddress, sizeof(szModule));
    sub_H13_EmitUse(szModule, nSection, nOffset, 0);
}

// 0x0040B660
extern "C" void __fastcall sub_0040B660_FreeList(List20C* node)
{
    while (node)
    {
        List20C* next = node->next;
        FOG_Free(node, gSource_006CD628, 0x1F7, 0);
        node = next;
    }
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
int __cdecl sub_0040C620_SymInitializeOnce()
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
        gpCleanup_0075CFDC(GetCurrentProcess());
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
int __fastcall sub_0040C7A0_QuickStackWalk(const char* szPrefix, void* hThread, D2ContextStrc* pContext)
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
    if (!sub_0040C620_SymInitializeOnce())
    {
        --gnStackWalkDepth_0075D018;
        return 0;
    }
    aTotals[3] += aEnd[3] - aStart[3];

    D2StackFrameStrc tFrame;
    memset(&tFrame, 0, sizeof(tFrame));
    tFrame.tAddrPC.dwOffset = pContext->dwEip;
    tFrame.tAddrPC.nMode = 3;
    tFrame.tAddrStack.dwOffset = pContext->dwEsp;
    tFrame.tAddrStack.nMode = 3;
    tFrame.tAddrFrame.dwOffset = pContext->dwEbp;
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

    sub_0040C720_SymCleanupOnce(0);
    sub_00410660_LogWritePrefixed(szPrefix, "QuickStackWalk: %d entries, %I64d+%I64d+%I64d+%I64d cycles, %I64d avg", nEntries, aTotals[0], aTotals[1], aTotals[2], aTotals[3], (aTotals[0] + aTotals[1] + aTotals[2] + aTotals[3]) / nEntries);
    --gnStackWalkDepth_0075D018;
    return 1;
}

// 0x0040D1C0
void __fastcall sub_0040D1C0_AppendCrashDump(unsigned long dwHeader0, unsigned long dwHeader1, unsigned long dwType, int nCount, const void* pData)
{
    char szPath[0x104];
    T0040D1C0 tRecord;
    sub_0040F000_GetLogDirectory(szPath, 0x104);
    sub_00413800(szPath, "Crashdump", 0x104);
    _iobuf* pFile = fopen(szPath, "ab");
    if (pFile)
    {
        tRecord.f_0 = dwHeader0;
        tRecord.f_4 = dwHeader1;
        tRecord.dwType = dwType;
        tRecord.nCount = nCount;
        sub_0041D2A0_MemCopy(tRecord.adwData, pData, nCount * 4);
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
    sub_00413800(szPath, "Crashdump", 0x104);
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

// 0x0040DBD0
void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock)
{
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    pSafeSock->bStopping = 1;
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    if (pSafeSock->hThread)
    {
        WaitForSingleObject(pSafeSock->hThread, 5000);
    }
    if (pSafeSock->hThread)
    {
        CloseHandle(pSafeSock->hThread);
        pSafeSock->hThread = 0;
    }
    if (pSafeSock->nSocket != (unsigned int)-1)
    {
        const unsigned int nSocket = pSafeSock->nSocket;
        pSafeSock->nSocket = (unsigned int)-1;
        pSafeSock->bConnected = 0;
        if (closesocket(nSocket) == -1)
        {
            pSafeSock->nWSALastError = WSAGetLastError();
            pSafeSock->nFogErrorCode = 5;
        }
    }
    DeleteCriticalSection(&pSafeSock->tCriticalSection);
    FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 387, 0);
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

// 0x0040F8A0
void __cdecl sub_0040F8A0_CloseLogFilesNow()
{
    D2_ASSERT(gbLogInitialized_0075D2EC, 456);
    const unsigned long dwStart = GetTickCount();
    while (GetTickCount() - dwStart < 1000)
    {
        EnterCriticalSection(&gtLogQueueLock_0075E838);
        const int nQueued = gnLogQueueCount_0075E870 > 0 ? gnLogQueueCount_0075E870 : 0;
        LeaveCriticalSection(&gtLogQueueLock_0075E838);
        if (!nQueued)
        {
            break;
        }
        Sleep(10);
    }
    for (int i = 0; i < 20; i++)
    {
        EnterCriticalSection(&gtLogLock_0075E850);
        if (gapLogFiles_0075E790[i])
        {
            fclose(gapLogFiles_0075E790[i]);
            gapLogFiles_0075E790[i] = 0;
        }
        LeaveCriticalSection(&gtLogLock_0075E850);
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

// 0x006B9B00
extern "C" void __cdecl sub_006B9B00_FreeGlobal()
{
    if (gAllocation_009897D0)
    {
        FOG_Free(gAllocation_009897D0, ".\\Src\\d3dSmack.cpp", 0x5E, 0);
        gAllocation_009897D0 = 0;
    }
}
