#include "D2Launch.h"
#include "D2FogTypes.h"

#pragma intrinsic(_ReadWriteBarrier)
#pragma intrinsic(strcmp)

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

struct D2ServiceStatusStrc;
struct D2PoolSystemStrc;
struct D2MemoryStatusStrc;
struct D2MenuCallbackArgStrc;
struct D2SlotEntryStrc;
struct SMSGHANDLER_PARAMS;
struct D2WinMsgStrc;
struct D2CoordPairStrc;
struct D2LaunchRecordStrc;
struct D2CriticalSectionStrc;
struct Unicode;
struct D2FuncTable_0077ABF0Strc;
struct D2LaunchThreadRecordStrc;
struct D2LaunchPayloadStrc;

typedef char* va_list;

struct D2ServiceStatusStrc
{
    unsigned long dwServiceType;
    unsigned long dwCurrentState;
    unsigned long dwControlsAccepted;
    unsigned long dwWin32ExitCode;
    unsigned long dwServiceExitCode;
    unsigned long dwCheckPoint;
    unsigned long dwWaitHint;
};

struct D2MemoryStatusStrc
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};

struct D2MenuCallbackArgStrc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    unsigned int nArg;
};

typedef int (__stdcall* D2GetDiskFreeSpaceExFn)(const char* szDirectory, unsigned __int64* pnFreeToCaller, unsigned __int64* pnTotal, unsigned __int64* pnTotalFree);

extern "C" __declspec(dllimport) void* __stdcall RegisterServiceCtrlHandlerA(const char* szServiceName, void (__stdcall* pfnHandler)(unsigned long dwCtrlCode)); // 0x006CC024
extern "C" __declspec(dllimport) int __stdcall SetServiceStatus(void* hServiceStatus, D2ServiceStatusStrc* pStatus); // 0x006CC048
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pBuffer); // 0x006CC1F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(); // 0x006CC20C
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0
extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1
extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5
void __stdcall D2ServerServiceHandlerProc(unsigned long dwCtrlCode); // 0x00406410
int __fastcall GameInit(int argc, const char** argv); // 0x004064C0
int __cdecl sub_00406650_StartServiceDispatcher(); // 0x00406650
int __cdecl sub_004061C0_DenyProcessAccess(); // 0x004061C0
void __fastcall sub_00410340_LogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340
void __cdecl sub_00410660_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410660
char* __fastcall sub_00411540_FormatNumber(char* szBuffer, unsigned int nBufferSize, __int64 nValue); // 0x00411540
int __stdcall sub_00415F70(int nFlags); // 0x00415F70
void __stdcall sub_00415F90_SetValue(int nValue); // 0x00415F90
int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0
int __stdcall SFileSetIoErrorMode(int nValueA, int nValueB); // 0x004166B0
int __stdcall sub_0041BFC0(unsigned int nOption, const void* pInput, unsigned int nSize); // 0x0041BFC0
void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
int __stdcall sub_004269C0_RegisterHandler(unsigned long dwId, void* pContext); // 0x004269C0
int __fastcall sub_004307A0(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
int __stdcall sub_00431600_ShowLevelScreen(int nArg); // 0x00431600
extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58
extern "C" const char gszKernel32_006CD6E4[]; // 0x006CD6E4
extern char gszServiceName_007065DC[]; // 0x007065DC
extern D2ServiceStatusStrc gD2ServerServiceStatus; // 0x007065FC
extern void* ghD2ServerServiceStatus; // 0x0074C714
extern void* ghCurrentProcess_0074C718; // 0x0074C718
extern int gbD2ServerStopEvent_0074C720; // 0x0074C720
extern int gnStormDirectFlags_0074C82C; // 0x0074C82C
extern void* gpStormOwnerB_007790C4; // 0x007790C4
extern unsigned long gdwStormOwnerThread_007790C8; // 0x007790C8
extern int gnFlag_007798D0; // 0x007798D0

struct D2SlotEntryStrc
{
    int unk0x00;
    int nField04;
};

extern void** gppSlots_00779988; // 0x00779988
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
extern D2WinControlStrc* gpList_0077995C; // 0x0077995C
extern D2WinControlStrc* gpList_00779960; // 0x00779960
extern int gdwGlobal_00779990; // 0x00779990
extern D2WinControlStrc* gpList_00779964; // 0x00779964
void __cdecl sub_0042F480_Reset(); // 0x0042F480
int __fastcall sub_0042F2E0_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
D2WinControlStrc* __fastcall sub_0042F430_CreateControl(int nId); // 0x0042F430
int __fastcall sub_00431050_ShowCredits(int nUnused); // 0x00431050
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
static __declspec(noinline) unsigned char sub_004313A0_GetFlagIndex(unsigned char nFlags);

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
    unsigned int dwTime;
    int f_14;
    int nPointY;
};

struct D2CoordPairStrc
{
    int nX;
    int nY;
};

extern "C" int __cdecl abs(int nValue);
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg); // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg); // 0x006CC47C
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall GetCursorPos(D2CoordPairStrc* pPoint); // 0x006CC48C
extern int gnLastClickX_00779998; // 0x00779998
extern int gnLastClickY_0077999C; // 0x0077999C
extern int gnLastClickTick_007799A0; // 0x007799A0

struct Unicode
{
    unsigned short wChar;
};

void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
void __cdecl sub_0042FFE0_CreateScreen(); // 0x0042FFE0
int __cdecl CLIENT_GetConnectionStatus(); // 0x0052B050
D2WinControlStrc* __fastcall sub_0042F3A0_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox); // 0x004F91C0
int __fastcall D2Win_10082(D2WinControlStrc* pEditBox); // 0x004FDD00
int __fastcall sub_004F9190(); // 0x004F9190
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
void __cdecl sub_00431970_CreateScreen(); // 0x00431970
extern int gnLoaderFlag_007798E0; // 0x007798E0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
extern D2WinControlStrc* gpEdit_007799CC; // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0; // 0x007799D0
extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4

struct D2LaunchRecordStrc
{
    char unk0x000[0x85];
    unsigned char nFlag085;
    unsigned char nFlag086;
    unsigned char nFlag087;
    unsigned char nFlag088;
    unsigned char nFlag089;
    unsigned char nFlag08A;
    unsigned char nFlag08B;
    unsigned char unk_8C[0x1];
    char szAccount[0x18];
    unsigned char unk_A5[0x30];
    union
    {
        struct
        {
            char szNameD5[0x158];
        };
        struct
        {
            unsigned char unk_D5[0x119];
            char nMode;
        };
    };
    char szName22D[0x100];
};

extern D2LaunchRecordStrc* gpLaunchRecord_007795D4; // 0x007795D4
void __cdecl sub_00515020_FadeOutWaves();
void __cdecl sub_0043B080();
void __cdecl sub_00432100_CreateLoginScreen();

struct D2FuncTable_0077ABF0Strc
{
    char unk0x00[0x44];
    D2LaunchPayloadStrc* (__fastcall* pfn0x44)(const char* szRealm, const char* szKey);
    unsigned char unk_48[0x20];
    int (__fastcall* pfnSlot68)();
};

void __cdecl sub_0043C4F0(); // 0x0043C4F0
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall sub_00433450_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0
void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0
void __cdecl sub_0043B810_SetFlag(); // 0x0043B810
void __cdecl sub_00436AD0_UpdateStatus(); // 0x00436AD0
int __cdecl sub_004F5D60(); // 0x004F5D60
int __stdcall sub_0042FE70_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FE70
int __stdcall sub_0042FEF0_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0
int __stdcall sub_00436F20_OnEditChange(int nArg); // 0x00436F20
int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0
void __cdecl sub_00436EB0_UpdateOkButton(); // 0x00436EB0
void __cdecl sub_004371E0_UpdatePasswordOk(); // 0x004371E0
extern D2WinControlStrc* gpEdit_007795A8; // 0x007795A8
extern D2WinControlStrc* gpPasswordOk_007799A4; // 0x007799A4
extern D2WinControlStrc* gpStatusText_007799A8; // 0x007799A8
extern D2WinControlStrc* gpCounterText_007799AC; // 0x007799AC
extern int gnStatusStringId_007799B0; // 0x007799B0
extern int gnStatusDots_007799B4; // 0x007799B4
extern unsigned long gdwStatusStart_007799B8; // 0x007799B8
extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4
extern int gdwGlobal_007D55B8; // 0x007D55B8
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
int __cdecl sub_00449AC0(); // 0x00449AC0
int __cdecl sub_00449C50(); // 0x00449C50
int __cdecl sub_00449C70(); // 0x00449C70
void __stdcall sub_00449C60_SetValue(int nValue); // 0x00449C60
void __stdcall sub_00449C80_SetValue(int nValue); // 0x00449C80
void __cdecl sub_00430620_UpdateNameOk(); // 0x00430620
void __cdecl sub_004306C0_UpdateOk(); // 0x004306C0
extern int gdwGlobal_00779974; // 0x00779974
void __fastcall sub_00433380_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00433380
extern "C" void _ReadWriteBarrier(void);
void* __cdecl sub_00449AC0_GetHandle(); // 0x00449AC0
int __cdecl sub_00432350_GetStatus(); // 0x00432350
extern "C" int __cdecl strcmp(const char* szA, const char* szB);

struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};

struct D2LaunchPayloadStrc
{
    unsigned int nSize;
    D2LaunchThreadRecordStrc tRecord;
};
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __cdecl sub_0042F6E0(); // 0x0042F6E0
int __stdcall sub_00432450_OnWait(int nArg); // 0x00432450
void __stdcall sub_0044A130_StartThread(D2LaunchThreadRecordStrc* pRecord); // 0x0044A130

int gnCmdShow_0074C71C; // 0x0074C71C

void* gpStormOwnerA_007790C0; // 0x007790C0

// 0x004065E0
void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** lpszArgv)
{
    gbD2ServerStopEvent_0074C720 = 1;
    ghD2ServerServiceStatus = RegisterServiceCtrlHandlerA(gszServiceName_007065DC, D2ServerServiceHandlerProc);
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    GameInit(dwArgc, (const char**)lpszArgv);
    gD2ServerServiceStatus.dwCurrentState = 1;
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    gbD2ServerStopEvent_0074C720 = 0;
}

// 0x004066E0
extern "C" int __stdcall WinMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nShowCmd)
{
    ghCurrentProcess_0074C718 = hInstance;
    gnCmdShow_0074C71C = nShowCmd;
    if (!sub_00406650_StartServiceDispatcher())
    {
        const char* argv[2];
        argv[0] = "d2server";
        argv[1] = lpCmdLine;
        sub_004061C0_DenyProcessAccess();
        GameInit(2, argv);
    }
    return 0;
}

// 0x00406870
void __fastcall sub_00406870_InitStorm(int nDirectFlags, int nValue)
{
    SFileSetBasePath(".\\");
    sub_00415F70(nDirectFlags);
    SFileSetIoErrorMode(0, 0);
    sub_00415F90_SetValue(nValue);
    gnStormDirectFlags_0074C82C = nDirectFlags;
    int nChunkSize = 0x8000;
    sub_0041BFC0(2, &nChunkSize, 4);
    int bEnable = 1;
    sub_0041BFC0(1, &bEnable, 4);
    sub_0041BFC0(3, &bEnable, 4);
}

// 0x00409020
void __cdecl sub_00409020_LogPoolError(const char* szFormat, ...)
{
    char szText[0x1000];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "--------------------------------------------------------");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "ERROR: Out of memory!");
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, gszPercentS_006FFC58, szText);
    D2MemoryStatusStrc tStatus;
    GlobalMemoryStatus(&tStatus);
    char szNumber[0x20];
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total physical:     %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwTotalPhys));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available physical: %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwAvailPhys));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total page:         %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwTotalPageFile));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available page:     %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwAvailPageFile));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "total virtual:      %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwTotalVirtual));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, "available virtual:  %s", sub_00411540_FormatNumber(szNumber, sizeof(szNumber), tStatus.dwAvailVirtual));
    sub_00410660_LogWritePrefixed(&gszEmptyAssertText, &gszEmptyAssertText);
}

// 0x004098B0
void* __fastcall sub_004098B0_PoolReallocLarge(D2PoolSystemStrc* pSystem, int* pBlock, int nSize, const char* szFile, int nLine)
{
    pBlock -= 1;
    const int nBucket = (int)pBlock % 1023;
    int* pPrevious = 0;
    EnterCriticalSection(&pSystem->tLock);
    int* pCurrent = pSystem->apLargeBlocks[nBucket];
    while (pCurrent)
    {
        if (pCurrent == pBlock)
        {
            if (!pPrevious)
            {
                pSystem->apLargeBlocks[nBucket] = (int*)*pCurrent;
            }
            else
            {
                *pPrevious = *pCurrent;
            }
            int* pNewBlock = (int*)realloc(pBlock, nSize + 4);
            if (!pNewBlock)
            {
                sub_00409020_LogPoolError("Unable to allocate free block of %s", nSize);
                D2_ASSERT(pNewBlock, 1057);
            }
            const int nNewBucket = (int)pNewBlock % 1023;
            *pNewBlock = (int)pSystem->apLargeBlocks[nNewBucket];
            pSystem->apLargeBlocks[nNewBucket] = pNewBlock;
            LeaveCriticalSection(&pSystem->tLock);
            return pNewBlock + 1;
        }
        pPrevious = pCurrent;
        pCurrent = (int*)*pCurrent;
    }
    LeaveCriticalSection(&pSystem->tLock);
    return 0;
}

// 0x00410700
void __cdecl sub_00410700_LogWrite00(const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 354);
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(&gszEmptyAssertText, 0, 0, szFormat, args);
}

// 0x00410740
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 371);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    sub_00410340_LogV(szPrefix, 0, 0, szFormat, args);
}

// 0x004107F0
unsigned __int64 __cdecl sub_004107F0_GetSaveDiskFreeSpace()
{
    char szPath[0x400];
    sub_00407050_GetSavePath(szPath, sizeof(szPath));
    void* hKernel = LoadLibraryA(gszKernel32_006CD6E4);
    if (hKernel)
    {
        D2GetDiskFreeSpaceExFn pfnGetDiskFreeSpaceEx = (D2GetDiskFreeSpaceExFn)GetProcAddress(hKernel, "GetDiskFreeSpaceExA");
        if (pfnGetDiskFreeSpaceEx)
        {
            unsigned __int64 nTotalFree = 0;
            unsigned __int64 nTotal = 0;
            unsigned __int64 nFreeToCaller = 0;
            pfnGetDiskFreeSpaceEx(szPath, &nFreeToCaller, &nTotal, &nTotalFree);
            FreeLibrary(hKernel);
            return nFreeToCaller;
        }
    }
    for (unsigned int i = 0; i < sizeof(szPath); i++)
    {
        if (szPath[i] == '\\')
        {
            szPath[i + 1] = 0;
            break;
        }
    }
    unsigned long nSectorsPerCluster = 0;
    unsigned long nBytesPerSector = 0;
    unsigned long nFreeClusters = 0;
    unsigned long nTotalClusters = 0;
    GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
    return nFreeClusters * nBytesPerSector * nSectorsPerCluster;
}

// 0x0041D160
void __cdecl sub_0041D160_DisplayAppFatal(const char* szFormat, ...)
{
    const char* szFile = 0;
    int nLine = 0;
    sub_0041C1A0_LockErrorState();
    if (gdwStormOwnerThread_007790C8 == GetCurrentThreadId())
    {
        szFile = (const char*)gpStormOwnerA_007790C0;
        nLine = (int)gpStormOwnerB_007790C4;
        SMemZero(&gpStormOwnerA_007790C0, 12);
    }
    sub_0041C1E0_UnlockErrorState();
    char szText[0x400];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    SErrDisplayError(0x85100084, szFile, nLine, szText, 0, 1);
    ExitProcess(1);
}

// 0x00420320
int __stdcall sub_00420320_RegisterHandlers(void* pContext)
{
    sub_004269C0_RegisterHandler(0x534D5348, pContext);
    sub_004269C0_RegisterHandler(0x534D5349, pContext);
    sub_004269C0_RegisterHandler(0x534D534A, pContext);
    sub_004269C0_RegisterHandler(0x534D5347, pContext);
    return 1;
}

// 0x00430600
static __forceinline int sub_00430600_CountNameMarks(const char* szText, int nLength)
{
    int nCount = 0;
    for (int i = 0; i < nLength; ++i)
    {
        if (szText[i] == '-' || szText[i] == '_')
        {
            ++nCount;
        }
    }
    return nCount;
}

// 0x004308A0
int __stdcall sub_004308A0_ExpansionNotice6(D2MenuCallbackArgStrc* pArg)
{
    if (!sub_00408F20_HasExpansionMpq())
    {
        return 0;
    }
    sub_004307A0(pArg->nArg, 6, 0x2772, 0x57F7);
    return 1;
}

// 0x004308E0
int __stdcall sub_004308E0_ExpansionNotice5(D2MenuCallbackArgStrc* pArg)
{
    if (!sub_00408F20_HasExpansionMpq())
    {
        return 0;
    }
    sub_004307A0(pArg->nArg, 5, 0x2771, 0x57F6);
    return 1;
}

int __stdcall sub_M121_Emit_00430600(const char* szText, int nLength) { return sub_00430600_CountNameMarks(szText, nLength); }

// 0x00430B80
int __fastcall sub_00430B80_GetSlotField04(int nSlot)
{
    D2SlotEntryStrc* pSlot = (D2SlotEntryStrc*)gppSlots_00779988[nSlot];
    D2_ASSERT(pSlot, 0x1162);
    return pSlot->nField04;
}

// 0x00431020
void __cdecl sub_00431020_ClearLists()
{
    D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
    D2Win_10045(gpList_00779960, &gszEmptyAssertText);
}

// 0x00431040
void __cdecl sub_00431040_ClearList() {
#ifdef MOVED_TEST
 D2Win_10045(gpList_00779964,&gszEmptyAssertText+4);
#else
 D2Win_10045(gpList_00779964,&gszEmptyAssertText);
#endif
}

D2WinControlStrc* gpControl_00779968; // 0x00779968

// 0x004312C0
int __stdcall sub_004312C0_CreateCreditsScreen(int nUnused)
{
    sub_0042F480_Reset();
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_0042F430_CreateControl(0x29);
    sub_0042F430_CreateControl(0x2A);
    if (!sub_00408F20_HasExpansionMpq())
    {
        gpList_0077995C = sub_0042F430_CreateControl(0x2B);
        gpList_00779960 = sub_0042F430_CreateControl(0x2C);
        gpList_00779964 = sub_0042F430_CreateControl(0x2D);
    }
    else
    {
        gpList_0077995C = sub_0042F430_CreateControl(0x2F);
        gpList_00779960 = sub_0042F430_CreateControl(0x30);
        gpList_00779964 = sub_0042F430_CreateControl(0x31);
    }
    gpControl_00779968 = sub_0042F430_CreateControl(0x2E);
    sub_004FD830(gpControl_00779968);
    sub_004FDA50(gpControl_00779968);
    sub_00431050_ShowCredits(0);
    D2Win_10053(gpList_00779964, 20);
    D2Win_10053(gpList_0077995C, 20);
    D2Win_10053(gpList_00779960, 20);
    return 1;
}

// 0x004313A0
static unsigned char sub_004313A0_GetFlagIndex(unsigned char nFlags)
{
    if (nFlags & 0x01)
        return 7;
    if (nFlags & 0x80)
        return 6;
    if (nFlags & 0x10)
        return 5;
    if (nFlags & 0x08)
        return 4;
    if (nFlags & 0x40)
        return 3;
    if (nFlags & 0x04)
        return 2;
    return 1;
}

// calling-convention shim (not game code)
int __fastcall sub_004313A0_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += sub_004313A0_GetFlagIndex(pFlags[i]);
    return nSum;
}

// 0x004317D0
void __cdecl sub_004317D0_FlushInput()
{
    D2WinMsgStrc tMsg;
    while (PeekMessageA(&tMsg, 0, 0, 0, 1))
    {
        switch (tMsg.uMessage)
        {
        case 0x12:
        case 0x102:
        case 0x201:
        case 0x202:
        case 0x204:
        case 0x205:
        case 0x207:
        case 0x208:
            break;
        default:
            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
            break;
        }
    }
}

int gnFlag_007798D0; // 0x007798D0

int gnFlag_007798D4; // 0x007798D4

void* gpfnArchiveLoader_007798D8; // 0x007798D8

int gbConnected_0077959C; // 0x0077959C

D2WinControlStrc* gpControl_00779344; // 0x00779344

D2WinControlStrc* gpAddressEdit_00779958; // 0x00779958

char gszAddress_007795F8[255]; // 0x007795F8

// 0x00431910
int __stdcall sub_00431910_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431920
int __stdcall sub_00431920_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431930
int __stdcall sub_00431930_RunAndSetFlag(int nArg)
{
    sub_00431600_ShowLevelScreen(nArg);
    gnFlag_007798D0 = 1;
    return 1;
}

// 0x00431950
int __stdcall sub_00431950_LoopCallback(int nArg)
{
    if (gnFlag_007798D0 || gnFlag_007798D4)
        sub_004F9190();
    return 1;
}

// 0x00431970
void __cdecl sub_00431970_CreateScreen()
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0x3A);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0x3B);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1432), 0, 0, 0);
}

// 0x00431A00
int __cdecl sub_00431A00_ShowArchiveMessage()
{
    sub_00431970_CreateScreen();
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader_007798D8 = (void*)ARCHIVE_LoadVideoArchives;
    gnLoaderFlag_007798E0 = 1;
    sub_004FA590_RunLoop(sub_00431950_LoopCallback);
    sub_0042F3F0_DestroyControls();
    return gnFlag_007798D4;
}

// 0x00431A40
int __stdcall sub_00431A40_SetMode2(int nArg)
{
    gnLaunchMode_007795EC = 2;
    sub_0042FFE0_CreateScreen();
    return 1;
}

// build: context sub_00436CF0
void __cdecl sub_00436CF0()
{
    const Unicode* pText1 = sub_004FDD90_GetEditText(gpEdit_007799CC);
    const Unicode* pText2 = sub_004FDD90_GetEditText(gpEdit_007799D0);
    sub_004F96F0_ControlClearState(gpControl_007799D4, (sub_00526800(pText1) > 0) | (sub_00526800(pText2) > 0));
}

int gnLastClickX_00779998; // 0x00779998

int gnLastClickY_0077999C; // 0x0077999C

int gnLastClickTick_007799A0; // 0x007799A0

// 0x00431A60
int __fastcall sub_00431A60_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg)
{
    int bResult = 1;
    if (pMsg->uMessage != 0x201)
        bResult = 0;
    int nTick = GetTickCount();
    if (nTick - gnLastClickTick_007799A0 > 300)
        bResult = 0;
    D2CoordPairStrc tPoint;
    GetCursorPos(&tPoint);
    if (abs(tPoint.nY - gnLastClickY_0077999C) + abs(tPoint.nX - gnLastClickX_00779998) > 4)
        bResult = 0;
    gnLastClickY_0077999C = tPoint.nY;
    gnLastClickTick_007799A0 = nTick;
    gnLastClickX_00779998 = tPoint.nX;
    return bResult;
}

// 0x00431C30
int __stdcall sub_00431C30_Leave(int nArg)
{
    gnLaunchState_007795E8 = 0;
    sub_00515F50(0xB4);
    sub_004F9190();
    return 1;
}

// 0x00431C60
void __fastcall sub_00431C60_HandleModeMessage(unsigned char* pMsg, int nSize)
{
    if (nSize != -1)
    {
        switch (*pMsg)
        {
        case 0xAF:
            gdwGlobal_00779990 = 1;
            break;
        case 0xB0:
            gdwGlobal_00779990 = 0;
            break;
        }
    }
}

// 0x00431D10
int __stdcall sub_00431D10_ClearLoop(int nArg)
{
    sub_004F9190();
    return 1;
}

// 0x00431D20
int __stdcall sub_00431D20_CreateTcpIpScreen(int nArg)
{
    sub_0042F2E0_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_004F95C0_ControlDestroy(&gpControl_00779344);
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0x10F);
    D2Win_10033(pControl, 0);
    sub_0042F3A0_CreateFromTemplate(0x10E);
    pControl = sub_0042F3A0_CreateFromTemplate(0x10C);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B1F));
    gpAddressEdit_00779958 = sub_0042F3A0_CreateFromTemplate(0x10D);
    if (!gszAddress_007795F8[0])
        SRegLoadString("Diablo II", "LastTcpIp", 0, gszAddress_007795F8, 0x100);
    sub_004FFE10_SetTextA(gpAddressEdit_00779958, gszAddress_007795F8);
    sub_004F91C0(gpAddressEdit_00779958);
    D2Win_10082(gpAddressEdit_00779958);
    sub_004FA450_SetActive(sub_0042F3A0_CreateFromTemplate(0x110));
    sub_0042F3A0_CreateFromTemplate(0x111);
    return 1;
}

// 0x00431E00
int __stdcall sub_00431E00_CreateControl10B(int nArg)
{
    sub_0042F3F0_DestroyControls();
    gpControl_00779344 = sub_0042F430_CreateControl(0x10B);
    sub_004FD830(gpControl_00779344);
    sub_004FDA50(gpControl_00779344);
    return 1;
}

// 0x00431E30
int __stdcall sub_00431E30_PollConnection(int nArg)
{
    const int nStatus = CLIENT_GetConnectionStatus();
    if (!nStatus)
    {
        gbConnected_0077959C = nStatus;
        sub_004F9190();
        return 1;
    }
    if (nStatus == 2)
    {
        gbConnected_0077959C = 1;
        sub_004F9190();
    }
    return 1;
}

// 0x00431E70
static void sub_00431E70_SetModeFlags(char nMode)
{
    gpLaunchRecord_007795D4->nMode = nMode;
    gpLaunchRecord_007795D4->nFlag085 = 0;
    gpLaunchRecord_007795D4->nFlag089 = 0;
    gpLaunchRecord_007795D4->nFlag088 = 0;
    gpLaunchRecord_007795D4->nFlag086 = 0;
    gpLaunchRecord_007795D4->nFlag087 = 0;
    gpLaunchRecord_007795D4->nFlag08A = 0;
    gpLaunchRecord_007795D4->nFlag08B = 0;

    if (nMode == 0)
    {
        gpLaunchRecord_007795D4->nFlag085 = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord_007795D4->nFlag089 = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord_007795D4->nFlag088 = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord_007795D4->nFlag086 = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord_007795D4->nFlag087 = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord_007795D4->nFlag08A = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord_007795D4->nFlag08B = 1;
    }
}

void __cdecl sub_I03_Emit_00431E70(char nMode)
{
    sub_00431E70_SetModeFlags(gnTextSentinel_0070CB80);
    sub_00431E70_SetModeFlags(nMode);
}

// 0x00431F50
int __stdcall sub_00432020_OnCancel(int nArg)
{
    sub_00515020_FadeOutWaves();
    sub_0042F480_Reset();
    sub_0043B080();
    return 1;
}

int __stdcall sub_00432040_OnCancel2(int nArg)
{
    sub_00515020_FadeOutWaves();
    sub_0042F480_Reset();
    sub_0043B080();
    return 1;
}

int __stdcall sub_00432300_OnLoginScreen(int nArg)
{
    sub_00432100_CreateLoginScreen();
    return 1;
}

D2WinControlStrc* gpEdit_00779340; // 0x00779340

D2WinControlStrc* gpPasswordEdit_007799BC; // 0x007799BC

D2WinControlStrc* gpPasswordEdit_007799C0; // 0x007799C0

D2WinControlStrc* gpPasswordEdit_007799C4; // 0x007799C4

D2WinControlStrc* gpPasswordEdit_007799C8; // 0x007799C8

D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

// 0x00432100
void __cdecl sub_00432100_CreateLoginScreen()
{
    sub_0043C4F0();
    sub_0042F430_CreateControl(0x15);
    sub_0042F430_CreateControl(0x16);
    sub_0042F430_CreateControl(0x18);
    sub_0042F430_CreateControl(0x19);
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x1A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = sub_0042F430_CreateControl(0x1B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2C));
    pControl = sub_0042F430_CreateControl(0x1D);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2D));
    pControl = sub_0042F430_CreateControl(0x1E);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2E));
    if (sub_00408F20_HasExpansionMpq())
        pControl = sub_0042F430_CreateControl(0x21);
    else
        pControl = sub_0042F430_CreateControl(0x1F);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B2B), 0x0, 0x0, 0x0);
    gpEdit_0077958C = sub_0042F430_CreateControl(0x59);
    sub_004FDAD0_SetKeyCallback(gpEdit_0077958C, sub_0042FE70_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_0077958C, 0x10);
    sub_004FFE10_SetTextA(gpEdit_0077958C, gpLaunchRecord_007795D4->szAccount);
    gpEdit_00779334 = sub_0042F430_CreateControl(0x5A);
    sub_004FDAD0_SetKeyCallback(gpEdit_00779334, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpEdit_00779334, 0xD);
    gpEdit_00779340 = sub_0042F430_CreateControl(0x5B);
    sub_004FDD50_SetMaxLength(gpEdit_00779340, 0xD);
    gpEdit_007795A8 = sub_0042F430_CreateControl(0x5C);
    sub_004FDD50_SetMaxLength(gpEdit_007795A8, 0xD);
    if (gpLaunchRecord_007795D4->szAccount[0] != 0x0)
        sub_004F91C0(gpEdit_00779334);
    else
        sub_004F91C0(gpEdit_0077958C);
    sub_004FDDD0_LinkTab(gpEdit_0077958C, gpEdit_00779334);
    sub_004FDDD0_LinkTab(gpEdit_00779334, gpEdit_00779340);
    sub_004FDDD0_LinkTab(gpEdit_00779340, gpEdit_007795A8);
    sub_004FDDD0_LinkTab(gpEdit_007795A8, gpEdit_0077958C);
    sub_0042F430_CreateControl(0x5D);
    sub_0042F430_CreateControl(0x5E);
}

// 0x00432340
int __stdcall sub_00432340_Callback(int nUnused)
{
    sub_004370C0();
    return 1;
}

// 0x00432350
static int sub_00432350_IsListedCode(int nCode)
{
    switch (nCode)
    {
    case 2:
    case 10:
    case 11:
    case 12:
    case 13:
    case 126:
    case 127:
        return 1;
    }
    return 0;
}

// 0x00432400
int __cdecl sub_00432400_PollStatus()
{
    if (gnWaitDone_00779994)
        return 1;
    if (!sub_00449AC0_GetHandle())
        return 2;
    switch (WaitForSingleObject(sub_00449AC0_GetHandle(), 0))
    {
    default:
        return 2;
    case 0x102:
        _ReadWriteBarrier();
        return 3;
    case 0:
        sub_00449C00();
        return sub_00432350_GetStatus() ? 2 : 0;
    }
}

static int gnWaitDone_00779994; // 0x00779994

// 0x00432480
int __fastcall sub_00432480(const char* szName, int bFlag)
{
    if (*szName && gpLaunchRecord_007795D4->szName22D[0] && !strcmp(szName, gpLaunchRecord_007795D4->szName22D) && sub_00449B30_QueryAddress())
    {
        return 0;
    }

    if (!bFlag)
    {
        sub_0042F6E0();
    }

    D2MCPClientCloseMCP();
    gnWaitDone_00779994 = 0;

    if (!*szName)
    {
        gpLaunchRecord_007795D4->szName22D[0] = 0;
        gpLaunchRecord_007795D4->szNameD5[0] = 0;
        if (!bFlag)
        {
            sub_0042F3F0_DestroyControls();
        }

        return 0;
    }

    D2LaunchPayloadStrc* pPayload;
    if (!gpFuncTable_0077ABF0)
        goto fail;
    pPayload = gpFuncTable_0077ABF0->pfn0x44(szName, "password");
    if (!pPayload)
        goto fail;
    if (pPayload->nSize == 8)
    {
fail:
        if (!bFlag)
            sub_0042F3F0_DestroyControls();
        return 2;
    }
    SStrCopy(gpLaunchRecord_007795D4->szName22D, szName, 0x100);
    SStrCopy(gpLaunchRecord_007795D4->szNameD5, szName, 0x100);
    sub_0044A130_StartThread(&pPayload->tRecord);
    int nResult = 3;
    if (!bFlag)
    {
        sub_004FA590_RunLoop(sub_00432450_OnWait);
        nResult = sub_00432400_GetStatus();
        sub_0042F3F0_DestroyControls();
    }
    return nResult;
}

int __cdecl sub_00432400_GetWaitStatus()
{
    if (gnWaitDone_00779994)
        return 1;

    if (sub_00449AC0())
    {
        switch (WaitForSingleObject((void*)sub_00449AC0(), 0))
        {
        case 0:
            return sub_00432350_IsListedCode(sub_00449C00()) ? 2 : 0;
        case 0x102:
            return 3;
        }
    }

    return 2;
}

// 0x00433020
int __stdcall sub_00433020_PollConnectA(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C50() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        sub_00449C60_SetValue(0);
        sub_004F9190();
    }
    return 1;
}

// 0x00433060
int __stdcall sub_00433060_PollConnectB(int nArg)
{
    sub_00449B70_Receive();
    if (sub_00449C70() || !sub_00449B30_QueryAddress() || gdwGlobal_00779974)
    {
        sub_00449C80_SetValue(0);
        sub_004F9190();
    }
    return 1;
}

// 0x00433440
void __fastcall sub_00433440_ShowMessageNoArg(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    sub_00433380_ShowMessage(pText, pfnDone, 0);
}

// 0x004334D0
int __stdcall sub_004334D0_DestroyControls(int nArg)
{
    sub_0042F3F0_DestroyControls();
    return 1;
}

// 0x00433BD0
int __stdcall sub_00433BD0_UpdateNameOk(int nArg)
{
    sub_00430620_UpdateNameOk();
    return 1;
}

// 0x00433BE0
int __stdcall sub_00433BE0_UpdateOk(int nArg)
{
    sub_004306C0_UpdateOk();
    return 1;
}

// 0x00436F30
void __cdecl sub_00436F30_CreateEmailScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return;
    }
    sub_0043C4F0();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x12B);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6A), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x12E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B5F), 0x0, 0x0, 0x0);
    sub_0042F430_CreateControl(0x12F);
    pControl = sub_0042F430_CreateControl(0x130);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpEdit_007799DC = sub_0042F430_CreateControl(0x131);
    sub_004FDD50_SetMaxLength(gpEdit_007799DC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpEdit_007799DC, sub_0042FEF0_FilterChar);
    sub_004FDB00_SetEnterCallback(gpEdit_007799DC, sub_00436F20_OnEditChange);
    sub_0042F430_CreateControl(0x132);
    pControl = sub_0042F430_CreateControl(0x133);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799E0 = sub_0042F430_CreateControl(0x134);
    sub_004FDB00_SetEnterCallback(gpEdit_007799E0, sub_00436F20_OnEditChange);
    sub_004FFE10_SetTextA(gpEdit_007799DC, gpLaunchRecord_007795D4->szAccount);
    sub_004F91C0(gpEdit_007799DC);
    sub_004FDDD0_LinkTab(gpEdit_007799DC, gpEdit_007799E0);
    sub_004FDDD0_LinkTab(gpEdit_007799E0, gpEdit_007799DC);
    gpButton_007799E4 = sub_0042F430_CreateControl(0x12C);
    sub_0042F430_CreateControl(0x12D);
    sub_00436EB0_UpdateOkButton();
}

// 0x004370C0
void __cdecl sub_004370C0_CreateInfoScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return;
    }
    sub_0043C4F0();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x135);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B65), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x136);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B66), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x137);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B67), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x138);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B68), 0x0, 0x0, 0x0);
    sub_0042F430_CreateControl(0x139);
    sub_0042F430_CreateControl(0x13A);
    sub_0042F430_CreateControl(0x13B);
    sub_0042F430_CreateControl(0x13C);
}

// 0x004372B0
void __cdecl sub_004372B0_CreatePasswordScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        sub_00433450_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return;
    }
    sub_0043C4F0();
    D2WinControlStrc* pControl = sub_0042F430_CreateControl(0x13D);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6C), 0x0, 0x0, 0x0);
    pControl = sub_0042F430_CreateControl(0x13E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B70), 0x0, 0x0, 0x0);
    sub_0042F430_CreateControl(0x13F);
    pControl = sub_0042F430_CreateControl(0x140);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpPasswordEdit_007799BC = sub_0042F430_CreateControl(0x141);
    sub_004FFE10_SetTextA(gpPasswordEdit_007799BC, gpLaunchRecord_007795D4->szAccount);
    sub_004FDD50_SetMaxLength(gpPasswordEdit_007799BC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit_007799BC, sub_0042FEF0_FilterChar);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799BC, sub_004372A0_OnEnter);
    sub_0042F430_CreateControl(0x142);
    pControl = sub_0042F430_CreateControl(0x143);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6D));
    gpPasswordEdit_007799C0 = sub_0042F430_CreateControl(0x144);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C0, sub_004372A0_OnEnter);
    sub_0042F430_CreateControl(0x145);
    pControl = sub_0042F430_CreateControl(0x146);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6E));
    gpPasswordEdit_007799C8 = sub_0042F430_CreateControl(0x147);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C8, sub_004372A0_OnEnter);
    sub_0042F430_CreateControl(0x148);
    pControl = sub_0042F430_CreateControl(0x149);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6F));
    gpPasswordEdit_007799C4 = sub_0042F430_CreateControl(0x14A);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit_007799C4, sub_004372A0_OnEnter);
    gpPasswordOk_007799A4 = sub_0042F430_CreateControl(0x14B);
    sub_0042F430_CreateControl(0x14C);
    sub_004F91C0(gpPasswordEdit_007799BC);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799BC, gpPasswordEdit_007799C0);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C0, gpPasswordEdit_007799C8);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C8, gpPasswordEdit_007799C4);
    sub_004FDDD0_LinkTab(gpPasswordEdit_007799C4, gpPasswordEdit_007799BC);
    sub_004371E0_UpdatePasswordOk();
}

// 0x00437550
void __cdecl sub_00437550_CreateStatusScreen()
{
    gdwStatusStart_007799B8 = GetTickCount();
    sub_0042F3F0_DestroyControls();
    sub_0042E6B0(0x1);
    D2WinControlStrc* pFrame = sub_0042F3A0_CreateFromTemplate(0xE2);
    D2Win_10033(pFrame, 0x0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 0x1);
    D2WinControlStrc* pOther = sub_0042F3A0_CreateFromTemplate(0xE3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 0x1);
    D2WinControlStrc* pText = sub_0042F3A0_CreateFromTemplate(0xE4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pText, 0x1);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x1433), 0x0, 0x0, 0x0);
    gpStatusText_007799A8 = sub_0042F3A0_CreateFromTemplate(0xE5);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpStatusText_007799A8, 0x1);
    gpCounterText_007799AC = sub_0042F3A0_CreateFromTemplate(0xE6);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpCounterText_007799AC, 0x1);
    gnStatusStringId_007799B0 = -1;
    gnStatusDots_007799B4 = 0x0;
    sub_0042E6A0(sub_0043B810_SetFlag);
    sub_00436AD0_UpdateStatus();
}

// 0x004F9050
int __cdecl sub_004F9050()
{
    gdwGlobal_007D55B8 = 0x0;
    return sub_004F5D60();
}
