#include "D2Client.h"

struct D2AutomapRecordStrc;
struct D2PoolSystemStrc;

struct Unicode
{
    unsigned short wChar;
};

#pragma pack(push, 1)
struct D2ClientInfoStrc
{
    char unk0x00[0x1EF];
    unsigned short wFlags;
};
#pragma pack(pop)

struct D2LoadingTimerStrc
{
    unsigned long dwStart;
    unsigned long dwLength;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x04];
    int dwUnitId;
};

struct D2MonStatsTxt
{
    char unk0x00[0x1A8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
};

struct D2WinMsgStrc
{
    unsigned int dwTick;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
};

struct D2MsgRecordChunkStrc
{
    D2WinMsgStrc tRecords[500];
    int nCount;
    int nUnk0x1F44;
    D2MsgRecordChunkStrc* pNext;
};

typedef void (__fastcall* D2InitHandlerFn)(void* pArg);
typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);
typedef int (__stdcall* D2LoadStringFn)(int nId, char* szBuffer, unsigned int nSize);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryExA(const char* szFileName, void* hFile, unsigned long dwFlags); // 0x006CC348
extern "C" __declspec(dllimport) void* __stdcall LoadAcceleratorsA(void* hInstance, const char* szTableName); // 0x006CC4A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80
void __cdecl sub_00409DD0_InitPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize);   // 0x00409DD0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0);                        // 0x0040B3C0
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __stdcall sub_0041C2F0_RegisterMsgSource(unsigned short wFacility, void* hModule, void* pReserved);     // 0x0041C2F0
int __cdecl sub_0044BBA0();                                                                                 // 0x0044BBA0
void __stdcall sub_0044C850(int nArg1, int nArg2, int nArg3);                                               // 0x0044C850
void __fastcall sub_0044C990(void* pArg);                                                                   // 0x0044C990
void __cdecl sub_0044DBE0_ReadColorFlag();                                                                  // 0x0044DBE0
int __stdcall sub_004512C0_LoadString(int nId, char* szBuffer, unsigned int nSize);                         // 0x004512C0
void __stdcall sub_00451920_RecordHandler(int nArg1, int nArg2, int nArg3);                                 // 0x00451920
void __cdecl sub_00456550_LoadLoadingScreen();                                                              // 0x00456550
void __cdecl sub_00456D80();                                                                                // 0x00456D80
void __fastcall sub_00457300_InitGfxCaches(void* pMemPool, int bCelPool);                                   // 0x00457300
void __fastcall sub_00457420(int nArg);                                                                     // 0x00457420
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode);                                                      // 0x0045AEA0
void __cdecl sub_00463C70();                                                                                // 0x00463C70
void __fastcall sub_00463D90(int nArg);                                                                     // 0x00463D90
void __cdecl sub_004659C0();                                                                                // 0x004659C0
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90
void __cdecl sub_0046BF90();                                                                                // 0x0046BF90
void __cdecl sub_0046D750();                                                                                // 0x0046D750
void __cdecl sub_00472320();                                                                                // 0x00472320
void __cdecl sub_004723C0();                                                                                // 0x004723C0
void __cdecl sub_00472BD0();                                                                                // 0x00472BD0
void __cdecl sub_00473CE0();                                                                                // 0x00473CE0
void __cdecl sub_00473CF0();                                                                                // 0x00473CF0
void __cdecl sub_00474790();                                                                                // 0x00474790
void __cdecl sub_004758D0();                                                                                // 0x004758D0
void __fastcall sub_00475FD0(D2ViewStrc* pView);                                                            // 0x00475FD0
void __fastcall sub_004760A0_SetViewPos(D2ViewStrc* pView, int nX, int nY);                                 // 0x004760A0
D2ViewStrc* __cdecl sub_00476B10();                                                                         // 0x00476B10
void __cdecl sub_00476EA0_LoadPalShift();                                                                   // 0x00476EA0
void __cdecl sub_00476FB0();                                                                                // 0x00476FB0
void __cdecl sub_00477DD0();                                                                                // 0x00477DD0
void __fastcall sub_004781D0(int bAnimate);                                                    // 0x004781D0
void __cdecl sub_0047BD30();                                                                                // 0x0047BD30
void __cdecl sub_0047F1D0_LoadResolution();                                                                 // 0x0047F1D0
void __cdecl sub_00483960();                                                                                // 0x00483960
void __cdecl sub_00499E30();                                                                                // 0x00499E30
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);         // 0x00502320
D2RecordHandlerFn __fastcall sub_005173D3_SetRecordHandler(D2RecordHandlerFn pfnHandler);                  // 0x005173D3
int __fastcall sub_0051740B_ErrorBox(const char* szText);                                                   // 0x0051740B
void __fastcall sub_005177B2_SetLoadStringFn(D2LoadStringFn pfnLoadString);                                 // 0x005177B2
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
void __cdecl sub_005FE070();                                                                                // 0x005FE070
void __cdecl sub_005FF3A0();                                                                                // 0x005FF3A0
void __cdecl sub_00600B80();                                                                                // 0x00600B80

extern "C" const char gszLngFileName_006D5EE0[];                                                            // 0x006D5EE0
extern int gdwGlobal_0070F414;                                                                              // 0x0070F414
extern D2InitHandlerFn gpfnInitHandlers_0070F488[52];                                                       // 0x0070F488
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern unsigned short gwToUpperTable_00730578[0x100];                                                       // 0x00730578
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern char gaClientState_007A0480[0x80];                                                                   // 0x007A0480
extern D2ClientCallbackFn gpfnClientCallback_007A0484;                                                      // 0x007A0484
D2PoolSystemStrc* gpMemPool_007A0488;                                                                       // 0x007A0488
extern int gdwGlobal_007A048C;                                                                              // 0x007A048C
extern int gdwGlobal_007A0498;                                                                              // 0x007A0498
extern unsigned long gdwNextTick_007A049C;                                                                  // 0x007A049C
extern unsigned long gdwLastTick_007A04A0;                                                                  // 0x007A04A0
extern int gdwGlobal_007A04A8;                                                                              // 0x007A04A8
int gdwGlobal_007A04B8;                                                                                     // 0x007A04B8
extern unsigned long gdwDelayEnd_007A04BC;                                                                  // 0x007A04BC
extern int gdwGlobal_007A04C8;                                                                              // 0x007A04C8
extern int gdwGlobal_007A04F4;                                                                              // 0x007A04F4
int gdwGlobal_007A04F8;                                                                                     // 0x007A04F8
int gdwGlobal_007A04FC;                                                                                     // 0x007A04FC
extern int gdwGlobal_007A0524;                                                                              // 0x007A0524
extern int gdwGlobal_007A05F8;                                                                              // 0x007A05F8
extern int gdwGlobal_007A0608;                                                                              // 0x007A0608
unsigned char gnDifficulty_007A060C;                                                                        // 0x007A060C
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
extern int gdwGlobal_007A0620;                                                                              // 0x007A0620
extern int gnValue_007A0624;                                                                                // 0x007A0624
int gdwGlobal_007A0628;                                                                                     // 0x007A0628
int gdwGlobal_007A062C;                                                                                     // 0x007A062C
extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634
extern D2AutomapRecordStrc* gpAutomapRecord_007A0638;                                                       // 0x007A0638
extern D2ViewStrc* gpView_007A0640;                                                                         // 0x007A0640
extern int gdwGlobal_007A0650;                                                                              // 0x007A0650
extern int gdwGlobal_007A0654;                                                                              // 0x007A0654
extern int gdwGlobal_007A0664;                                                                              // 0x007A0664
extern int gdwGlobal_007A066C;                                                                              // 0x007A066C
int gdwGlobal_007A0670;                                                                                     // 0x007A0670
extern int gdwGlobal_007A0674;                                                                              // 0x007A0674
int gdwGlobal_007A0684;                                                                                     // 0x007A0684
int gdwGlobal_007A0688;                                                                                     // 0x007A0688
extern void* gxGlobal_007A0708;                                                                             // 0x007A0708
void* ghLngModule_007A070C;                                                                                 // 0x007A070C
char gszLngPath_007A0710[0x104];                                                                            // 0x007A0710
extern D2RecordHandlerFn gpfnPrevHandler_007A2764;                                                          // 0x007A2764
extern int gdwGlobal_007A2780;                                                                              // 0x007A2780
extern int gdwGlobal_007A2788;                                                                              // 0x007A2788
extern int gaUIVarStates_007A27C0[];                                                                        // 0x007A27C0
Unicode gxGlobal_007A2C80[80];                                                                              // 0x007A2C80
extern int gdwGlobal_007A2D20;                                                                              // 0x007A2D20
extern int gdwGlobal_007A2D24;                                                                              // 0x007A2D24
extern Unicode gwszHoverLine_007A2D30[];                                                                    // 0x007A2D30
extern int gnHoverTextColor_007A2F30;                                                                       // 0x007A2F30

// 0x0044C880
void __cdecl sub_0044C880()
{
    sub_00472BD0();
}

// 0x0044C890
void __cdecl sub_0044C890_ReleaseGameState()
{
    sub_00472BD0();
    sub_00476FB0();
    sub_004659C0();
    if (gpAct_007A0634)
        DUNGEON_FreeAct(gpAct_007A0634);
    gpAct_007A0634 = 0;
    sub_005FF3A0();
    sub_005FE070();
    sub_00457420(0);
    sub_00475FD0(gpView_007A0640);
    gpView_007A0640 = 0;
    sub_00456D80();
    sub_00473CF0();
    sub_004758D0();
    sub_004723C0();
    FOG_DestroyMemoryPoolSystem(gpMemPool_007A0488);
    memset(gaClientState_007A0480, 0, sizeof(gaClientState_007A0480));
    sub_0040B3C0(gpAutomapRecord_007A0638, ".\\GAME\\Game.cpp", 0x599, 0);
}

// 0x0044CCE0
void __cdecl sub_0044CCE0_AverageCounters()
{
    const int nNow = gdwGlobal_007A048C;
    if ((unsigned int)(nNow - gdwGlobal_007A04B8) > 3000)
    {
        gdwGlobal_007A04A8 = gdwGlobal_007A04AC / 3;
        gdwGlobal_007A04B0 = gdwGlobal_007A04B4 / 3;
        gdwGlobal_007A04B8 = nNow;
        gdwGlobal_007A04AC = 0;
        gdwGlobal_007A04B4 = 0;
    }
}

// 0x0044CD70
void __cdecl sub_0044CD70_TickTimer()
{
    const unsigned long dwNow = GetTickCount();
    if (gdwNextTick_007A049C < dwNow)
    {
        sub_00477DD0();
        gdwLastTick_007A04A0 = dwNow;
        if (gpClientInfo_007A0438->wFlags & 4)
            gdwNextTick_007A049C = dwNow + 5000;
        else
            gdwNextTick_007A049C = dwNow + 5000;
    }
}

// 0x0044CE40
void __fastcall sub_0044CE40(int nValue)
{
    gdwGlobal_007A04FC = nValue;
}

// 0x0044CE90
void __cdecl sub_0044CE90_UpdateKeyState()
{
    if (sub_00469D90(0x24, 1))
    {
        const unsigned short wKey = sub_00469AA0(0x24, 1);
        if (wKey != 0xFFFF && (GetAsyncKeyState(wKey) & 0x8000))
        {
            gdwGlobal_007A0664 = 1;
            return;
        }
    }
    if (sub_00469D90(0x24, 0))
    {
        const unsigned short wKey = sub_00469AA0(0x24, 0);
        if (wKey != 0xFFFF && (GetAsyncKeyState(wKey) & 0x8000))
        {
            gdwGlobal_007A0664 = 1;
            return;
        }
    }
    gdwGlobal_007A0664 = 0;
}

// 0x0044D510
void __cdecl sub_0044D510()
{
    gdwGlobal_007A062C = 1;
}

// 0x0044D520
void __cdecl sub_0044D520()
{
    gdwGlobal_007A0620 = 1;
}

// 0x0044D530
void __fastcall sub_0044D530(int nValue)
{
    gdwGlobal_007A0628 = nValue;
}

// 0x0044D9F0
int __fastcall sub_0044D9F0_RunInitHandlers(void* pArg)
{
    gdwGlobal_0070F414 = 1;
    for (unsigned int i = 0; i < 52; i++)
    {
        if (gpfnInitHandlers_0070F488[i])
            gpfnInitHandlers_0070F488[i](pArg);
    }
    return gdwGlobal_0070F414;
}

// 0x0044DA40
void __cdecl sub_0044DA40()
{
    gdwGlobal_0070F2BC = 0x10;
    gdwGlobal_0070F234 = 0x10;
    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0670 = 0;
    sub_00466FE0();
}

// 0x0044DA70
void __cdecl sub_0044DA70()
{
    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0670 = 0;
}

// 0x0044DAD0
void __fastcall sub_0044DAD0(int nValue)
{
    gdwGlobal_007A04C8 = nValue;
}

// 0x0044DB40
void __fastcall sub_0044DB40(int nDelay)
{
    const unsigned long dwEnd = GetTickCount() + nDelay;
    if (dwEnd > gdwDelayEnd_007A04BC)
        gdwDelayEnd_007A04BC = dwEnd;
}

// 0x0044DC70
void __fastcall sub_0044DC70_SetDifficulty(unsigned char nDifficulty)
{
    gnDifficulty_007A060C = nDifficulty;
}

// 0x0044DC80
void __fastcall sub_0044DC80(unsigned char nValue)
{
    gdwGlobal_007A04F4 = nValue;
}

// 0x0044DC90
void __fastcall sub_0044DC90(int nValue)
{
    gdwGlobal_007A04F8 = nValue;
}

// 0x0044DCA0
int __cdecl sub_0044DCA0_GetGameType()
{
    return (gdwGlobal_007A0610 >= 2 && gdwGlobal_007A0610 <= 3) ? gdwGlobal_007A04F8 : 1;
}

// 0x0044DCD0
unsigned char __cdecl sub_0044DCD0_GetDifficulty()
{
    return gnDifficulty_007A060C;
}

// 0x0044DFF0
int __fastcall sub_0044DFF0_TimerExpired(D2LoadingTimerStrc* pTimer)
{
    if (pTimer->dwLength)
    {
        unsigned long dwNow = GetTickCount();
        unsigned long dwLeft;
        if (dwNow >= pTimer->dwStart + pTimer->dwLength)
        {
            pTimer->dwStart = 0;
            pTimer->dwLength = 0;
            dwLeft = 0;
        }
        else
        {
            dwLeft = pTimer->dwLength - (dwNow - pTimer->dwStart);
        }
        return dwLeft == 0;
    }
    return 1;
}

// 0x0044E040
int __fastcall sub_0044E040_TimerRunning(D2LoadingTimerStrc* pTimer)
{
    return !sub_0044DFF0_TimerExpired(pTimer);
}

// 0x0044E200
void __cdecl sub_0044E200_InitGameState()
{
    gdwGlobal_007A0684 = 0;
    gdwGlobal_007A0688 = 0;
    gdwGlobal_007A062C = 0;
    gdwGlobal_007A0628 = 0;
    gdwGlobal_007A0608 = 0;
    gnValue_007A0624 = 0;
    gdwGlobal_007A0664 = 0;
    memset(gaClientState_007A0480, 0, sizeof(gaClientState_007A0480));
    sub_00409DD0_InitPoolSystem(&gpMemPool_007A0488, "Client Pool System", 0x40000, 0x1000);
    sub_00463D90(0);
    sub_0044DBE0_ReadColorFlag();
    if (!gpView_007A0640)
        gpView_007A0640 = sub_00476B10();
    sub_0047F1D0_LoadResolution();
    sub_00456550_LoadLoadingScreen();
    sub_004565E0_Redraw(1);
    if (gdwGlobal_007A0610 == 7 || gdwGlobal_007A0610 == 9 || gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 8)
        sub_004781D0(1);
    sub_005173D3_SetRecordHandler(sub_0044C850);
    sub_00476EA0_LoadPalShift();
    sub_00600B80();
    sub_00457300_InitGfxCaches(gpMemPool_007A0488, 1);
    gdwGlobal_007A0620 = sub_0044BBA0() != 0;
    gdwGlobal_007A0524 = GetTickCount();
    gdwGlobal_007A05F8 = GetTickCount();
    gpfnClientCallback_007A0484 = sub_0044C990;
    gdwGlobal_007A0498 = 0;
    gdwGlobal_007A0494 = 0;
    sub_004760A0_SetViewPos(gpView_007A0640, 0, 0);
    sub_0045AEA0_SetPanelSlide(0);
    gdwGlobal_007A04FC = 0;
    sub_0046D750();
    sub_00473CE0();
    sub_0046BF90();
    gpAutomapRecord_007A0638 = (D2AutomapRecordStrc*)FOG_Alloc(8, ".\\GAME\\Game.cpp", 0x546, 0);
    sub_00463C70();
    sub_00474790();
    sub_00472320();
    sub_0047BD30();
    gdwGlobal_007A0674 = 0;
    gdwGlobal_007A061C = 0;
}

// build: context sub_00451290
void __cdecl sub_00451290()
{
    if (ghLngModule_007A070C)
        FreeLibrary(ghLngModule_007A070C);
    gxGlobal_007A0708 = 0;
    ghLngModule_007A070C = 0;
}

// 0x00451330
int __cdecl sub_00451330()
{
    if (gszLngPath_007A0710[0])
    {
        ghLngModule_007A070C = LoadLibraryExA(gszLngPath_007A0710, 0, 2);
        SRegSaveString("Diablo II", "LNG File", 0, gszLngPath_007A0710);
    }
    if (!ghLngModule_007A070C)
    {
        if (SRegLoadString("Diablo II", "LNG File", 0, gszLngPath_007A0710, sizeof(gszLngPath_007A0710)))
            ghLngModule_007A070C = LoadLibraryExA(gszLngPath_007A0710, 0, 2);
        if (!ghLngModule_007A070C)
        {
            ghLngModule_007A070C = LoadLibraryExA(gszLngFileName_006D5EE0, 0, 2);
            if (!ghLngModule_007A070C)
            {
                sub_0051740B_ErrorBox("Unable to start LNG manager.");
                return 0;
            }
        }
    }
    gxGlobal_007A0708 = LoadAcceleratorsA(ghLngModule_007A070C, (const char*)0x64);
    sub_0041C2F0_RegisterMsgSource(0xFFF, ghLngModule_007A070C, 0);
    sub_005177B2_SetLoadStringFn(sub_004512C0_LoadString);
    return 1;
}

// 0x00451400
void __cdecl sub_00451400_AddRecordChunk()
{
    D2MsgRecordChunkStrc* pChunk = (D2MsgRecordChunkStrc*)FOG_Alloc(sizeof(D2MsgRecordChunkStrc), ".\\GAME\\Record.cpp", 0x35, 0);
    D2MsgRecordChunkStrc* pOld = gpMsgRecordChunk_0070F7A0;
    pChunk->nCount = 0;
    pChunk->nUnk0x1F44 = 0;
    pOld->pNext = pChunk;
    pChunk->pNext = 0;
    gpMsgRecordChunk_0070F7A0 = pChunk;
}

// 0x00451940
void __cdecl sub_00451940_InstallRecordHandler()
{
    gdwGlobal_007A2780 = 1;
    gpfnPrevHandler_007A2764 = sub_005173D3_SetRecordHandler(sub_00451920_RecordHandler);
}

// 0x00451970
void __cdecl sub_00451970()
{
    gdwGlobal_007A2788 = 1;
}

// 0x00451F10
int __cdecl sub_00451F10_PushRegisterState()
{
    return SMsgPushRegisterState(sub_004F59A0());
}

// 0x00451F50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// 0x00451F60
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// 0x00451F80
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x00452130
void __cdecl sub_00452130_InitColors()
{
    sub_00483960();
    sub_00499E10();
    sub_00499E30();
    sub_004AB2F0();
    sub_00497250();
    sub_00497270();
    sub_004972B0();
    sub_00497290();
}

// 0x00452170
Unicode* __fastcall sub_00452170(Unicode* pText)
{
    return pText;
}

// 0x00452180
void __fastcall sub_00452180_StrToUpper(Unicode* pText)
{
    if (!pText)
        return;
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength; i++)
    {
        const unsigned short wChar = pText[i].wChar;
        pText[i].wChar = wChar >= 0x100 ? wChar : gwToUpperTable_00730578[wChar];
    }
}

// 0x00452520
void __fastcall sub_00452520_SetHoverLine(const Unicode* pText, int nColor)
{
    if (!pText)
    {
        gwszHoverLine_007A2D30[0].wChar = 0;
        return;
    }
    sub_005267E0(gwszHoverLine_007A2D30, pText);
    gnHoverTextColor_007A2F30 = nColor;
}

// 0x00453060
void __cdecl sub_00453060()
{
    if (!sub_00526800(gxGlobal_007A2C80))
        return;
    const int nWidth = sub_00501820(gxGlobal_007A2C80) + 8;
    const int nHeight = D2Win_10125() + 7;
    int nX = gdwGlobal_007A2D20 - (nWidth >> 1);
    int nY = gdwGlobal_007A2D24 + 2;
    if (nX < 0)
        nX = 0;
    if (nX + nWidth > gnGlobal_0071146C)
        nX = gnGlobal_0071146C - nWidth;
    if (nY - nHeight < 0)
        nY = nHeight;
    if (nY > gnGlobal_00711470 - 0x1F)
        nY = gnGlobal_00711470 - 0x1F;
    sub_00502320(gxGlobal_007A2C80, nX, nY - 2, 0, 1);
    memset(gxGlobal_007A2C80, 0, sizeof(gxGlobal_007A2C80));
}

// 0x004538D0
int __fastcall sub_004538D0(unsigned int nUIVar)
{
    D2_ASSERT(nUIVar < 0x26, 0xC34);
    return gaUIVarStates_007A27C0[nUIVar];
}

#include "gen/data/Source/D2Client/GAME/Game_0044C880.inc"
