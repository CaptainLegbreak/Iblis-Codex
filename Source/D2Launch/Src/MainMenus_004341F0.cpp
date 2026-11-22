#include "D2Launch.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
class BNGatewayAccess;

int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl); // 0x004FB950
void __cdecl sub_00433640_PlayIntroVideo(); // 0x00433640
void __cdecl sub_0042FB20(); // 0x0042FB20
void __cdecl sub_0042F3F0_DestroyControls(); // 0x0042F3F0
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
int __stdcall sub_00431950_LoopCallback(int nArg); // 0x00431950
void __fastcall sub_00431570_CreateControls(int bFlag); // 0x00431570
extern D2WinControlStrc* gpList_00779964; // 0x00779964
extern D2ConfigStrc* gpConfig_007795D4; // 0x007795D4
extern int gnFlag_007798D0; // 0x007798D0
extern int gnFlag_007798D4; // 0x007798D4

class BNGatewayAccess
{
public:
    const char* __stdcall Name(int nGateway);

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
};

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
int __fastcall D2Win_10055(D2WinControlStrc* pTextBox); // 0x004FBAB0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0
void __cdecl sub_00431AF0(); // 0x00431AF0
extern D2FuncTable_0077ABF0Strc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl sub_004317D0_FlushInput(); // 0x004317D0
int __cdecl sub_0042FA40_InitAuxBattleNet(); // 0x0042FA40
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq); // 0x0041BA60
int __stdcall SFileCloseArchive(void* hMpq); // 0x00419A80
int __cdecl sub_0042FAB0_GetAuxFlag(); // 0x0042FAB0
void __cdecl sub_004334E0_PlayIntro(); // 0x004334E0
void __fastcall sub_0042F540_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
int __fastcall sub_004F9190(); // 0x004F9190
int __fastcall sub_0043C180_Connect(D2LaunchRecordStrc* pRecord, int bFlag, int nMode); // 0x0043C180
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
void __cdecl sub_00435330_ShowLoginScreen(); // 0x00435330
void __cdecl sub_00436CF0(); // 0x00436CF0
void __cdecl sub_00436EB0_UpdateOkButton(); // 0x00436EB0
void __fastcall AUTOMAP_InitCharSaveHeader(char* szName, char nClass, char* pData, int nFlags); // 0x0043C540
int __fastcall sub_0043C6B0_WriteSaveHeader(const char* szName); // 0x0043C6B0
void __cdecl sub_00435E10(); // 0x00435E10
extern int gnLaunchMode_007795EC; // 0x007795EC
void __cdecl sub_0042F6C0_SetDone(); // 0x0042F6C0
extern int gbGatewayFlag_00779954; // 0x00779954
extern void (__cdecl* gpfnGatewayDone_007795BC)(); // 0x007795BC
extern D2WinControlStrc* gpStatusText_007799A8; // 0x007799A8
extern D2WinControlStrc* gpCounterText_007799AC; // 0x007799AC

int gnListPos_0077996C; // 0x0077996C

void* gpfnArchiveLoader2_007798DC; // 0x007798DC

int gnLoaderFlag_007798E0; // 0x007798E0

// 0x004341F0
int __stdcall sub_004341F0_CheckListEnd(int nArg)
{
    if (gnListPos_0077996C <= sub_004FB950_GetFirstVisible(gpList_00779964) + 10)
        sub_004336C0();
    return 1;
}

// 0x00434220
int __cdecl sub_00434220_PlayDisc()
{
    sub_0042F3F0_DestroyControls();
    D2WinControlStrc* pControl = sub_0042F3A0_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = sub_0042F3A0_CreateFromTemplate(0x3C);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    pControl = sub_0042F3A0_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1431), 0, 0, 0);
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader2_007798DC = (void*)ARCHIVE_LoadExpansionArchives;
    gnLoaderFlag_007798E0 = 0;
    sub_004FA590_RunLoop(sub_00431950_LoopCallback);
    sub_0042F3F0_DestroyControls();
    return gnFlag_007798D4;
}

// 0x004342E0
int __cdecl sub_004342E0_ExpansionDisc()
{
    sub_00431570_CreateControls(1);
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader2_007798DC = (void*)ARCHIVE_LoadExpansionArchives;
    gnLoaderFlag_007798E0 = 0;
    sub_004FA590_RunLoop(sub_00431950_LoopCallback);
    sub_0042F3F0_DestroyControls();
    return gnFlag_007798D4;
}

// 0x004345C0
int __stdcall sub_004345C0_ReloadAndLeave(int nArg)
{
    sub_004FAD70();
    ARCHIVE_LoadExpansionArchives(sub_00434220_PlayDisc, sub_004342E0_ExpansionDisc, 0, gpConfig_007795D4);
    if (sub_00514D80())
        D2SOUND_10034(1);
    sub_004336C0();
    return 1;
}

// 0x00434760
int __stdcall sub_00434760_ResetAndLeave(int nArg)
{
    sub_0042F480_Reset();
    if (sub_00514D80())
        D2SOUND_10034(1);
    sub_004336C0();
    return 1;
}

// 0x00434D90
int __stdcall sub_00434D90_PlayIntroAndLeave(int nArg)
{
    if (sub_004F9050())
        sub_00433640_PlayIntroVideo();
    D2Win_10004(1);
    sub_0042FB20();
    return 1;
}

// 0x00434DC0
int __stdcall sub_00434DC0_Leave(int nArg)
{
    sub_004336C0();
    return 1;
}

// 0x00434DD0
int __stdcall sub_00434DD0_ClearAndLeave(int nArg)
{
    sub_0043B9A0();
    sub_004336C0();
    return 1;
}

// 0x00434DF0
int __stdcall sub_00434DF0_Leave(int nArg)
{
    sub_004336C0();
    return 1;
}

D2WinControlStrc* gpControl_00779590; // 0x00779590

// build: symbol ?Name@BNGatewayAccess@@QAGPBDH@Z 0x005180A0
// 0x00434600
int __stdcall sub_00434600_CreateGatewayScreen(int nUnused)
{
    sub_0043C4F0();
    sub_0042F430_CreateControl(0x47);
    D2Win_10044(sub_0042F430_CreateControl(0x48), D2LANG_GetStringFromTblIndex(0x2B2F));
    D2Win_10044(sub_0042F430_CreateControl(0x49), D2LANG_GetStringFromTblIndex(0x2B30));
    gpControl_00779590 = sub_0042F430_CreateControl(0x4A);
    sub_0042F430_CreateControl(0x4B);
    sub_0042F430_CreateControl(0x4C);
    BNGatewayAccess* pGateways = (BNGatewayAccess*)gpFuncTable_0077ABF0->pfnGetRecord();
    int nCur = pGateways->m_nCurGateway;
    for (int i = 1; i <= pGateways->m_nNumGateways; ++i)
    {
        sub_004FCF80_SetTextA(gpControl_00779590, pGateways->Name(i));
    }
    int nFirst = sub_004FB950_GetFirstVisible(gpControl_00779590);
    int nVisible = D2Win_10055(gpControl_00779590);
    int nLine = nCur - 1;
    if (nLine < nFirst || nLine - nFirst > nVisible)
    {
        D2Win_10053(gpControl_00779590, nLine);
        nLine = 0;
    }
    sub_004FB9D0_Select(gpControl_00779590, nLine);
    sub_00431AF0();
    return 1;
}

// 0x00435020
int __stdcall sub_00435020_Callback(int nUnused)
{
    sub_004336C0();
    return 1;
}

// 0x00435230
void __cdecl sub_00435230_PlayIntroVideos()
{
    D2_ASSERT(!gpLaunchRecord_007795D4->bIntroPlayed, 0x8D4);
    D2Win_10029(0);
    sub_0042F480_Reset();
    sub_004317D0_FlushInput();
    if (sub_004F9050())
    {
        if (!sub_0040EB10())
        {
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\New_BLIZ640x480.bik", 0, 0);
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\BlizNorth640x480.bik", 0, 0);
        }
        else
        {
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\New_BLIZ640x240.bik", 2, 0);
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\BlizNorth640x240.bik", 2, 0);
        }
        if (!sub_0042FA40_InitAuxBattleNet())
        {
            void* hMpq = 0;
            SFileOpenArchive("d2video.mpq", 0x64, 0, &hMpq);
            if (hMpq)
            {
                sub_00433640_PlayIntroVideo();
                SFileCloseArchive(hMpq);
            }
        }
        else
        {
            if (sub_00408F20_HasExpansionMpq() && sub_0042FAB0_GetAuxFlag())
                sub_004334E0_PlayIntro();
        }
    }
    D2Win_10004(1);
    sub_0042FB20();
}

int gnLaunchState_007795E8; // 0x007795E8

int gdwGlobal_007795F4; // 0x007795F4

int gdwGlobal_007799D8; // 0x007799D8

// 0x00436270
int __stdcall sub_00436270_OnShowLogin(int nArg)
{
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436280
int __stdcall sub_00436280_ConnectOk(int nArg)
{
    gdwGlobal_007795F4 = 0;
    if (!sub_0043C180_Connect(gpLaunchRecord_007795D4, 1, 0))
    {
        if (gdwGlobal_007795F4)
        {
            sub_00435330_ShowLoginScreen();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord_007795D4->szAccount);
        if (sub_00430BC0_HasSaveFiles())
        {
            sub_00515020();
            sub_0042F480_Reset();
            sub_0043B080();
            return 1;
        }
        sub_00435580();
    }
    return 1;
}

// 0x00436300
int __stdcall sub_00436300_BackToLogin(int nArg)
{
    sub_0042F3F0_DestroyControls();
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436360
int __stdcall sub_00436360_SubmitCharacter(int nArg)
{
    if (gpLaunchRecord_007795D4->nClass == 6 || gpLaunchRecord_007795D4->nClass == 5)
        *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF |= 0x20;
    if (gnLaunchMode_007795EC == 3)
    {
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0_WriteSaveHeader(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 4;
        gnLaunchState_007795E8 = 3;
        *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        gpLaunchRecord_007795D4->nByte22D = 0;
        gpLaunchRecord_007795D4->nByteD5 = 0;
        sub_004F9190();
        return 1;
    }
    if (gnLaunchMode_007795EC == 0)
    {
        AUTOMAP_InitCharSaveHeader(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0_WriteSaveHeader(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 1;
        *(int*)gpLaunchRecord_007795D4->aState19 = 0;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        gnLaunchState_007795E8 = 1;
        sub_004F9190();
        return 1;
    }
    if (gnLaunchMode_007795EC == 2)
    {
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader(gpLaunchRecord_007795D4->szCharName, gpLaunchRecord_007795D4->nClass, gpLaunchRecord_007795D4->aDataED, *(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF);
        sub_0043C6B0_WriteSaveHeader(gpLaunchRecord_007795D4->szCharName);
        gpLaunchRecord_007795D4->nByte35E = 3;
        gnLaunchState_007795E8 = 1;
        *(int*)gpLaunchRecord_007795D4->aState209 = 4;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 4)
            *(int*)gpLaunchRecord_007795D4->aState209 = 0x804;
        if (*(unsigned short*)gpLaunchRecord_007795D4->aFlags1EF & 0x20)
            *(int*)gpLaunchRecord_007795D4->aState209 |= 0x100000;
        sub_004F9190();
        return 1;
    }
    if (gnLaunchMode_007795EC == 1)
        sub_00435E10();
    return 1;
}

// 0x00436590
int __stdcall sub_00436590_Back(int nArg)
{
    sub_0042F3F0_DestroyControls();
    sub_00435580();
    return 1;
}

// 0x00436C70
int __stdcall sub_00436C70_SendEmptyText(int nArg)
{
    gpFuncTable_0077ABF0->pfnSlotB8((char*)&gszEmptyAssertText);
    sub_004F9190();
    return 1;
}

// 0x00436C90
int __stdcall sub_00436C90_AskConfirm(int nArg)
{
    sub_0042F540_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B5E), 0x2B61, 0x13EF, sub_00436C70_SendEmptyText, sub_004334D0_CloseBox, 0, 1);
    return 1;
}

// 0x00436CD0
int __stdcall sub_00436CD0_SetFlagAndExit(int nArg)
{
    gdwGlobal_007799D8 = 1;
    sub_004F9190();
    return 1;
}

// 0x00436D40
int __stdcall sub_00436D40_Callback(int nArg)
{
    sub_00436CF0();
    return 1;
}

// 0x00436F20
int __stdcall sub_00436F20_OnEditChange(int nArg)
{
    sub_00436EB0_UpdateOkButton();
    return 1;
}

// 0x00436320
int __stdcall sub_00436320_GatewayOk(int nUnused)
{
    gbGatewayFlag_00779954 = 1;
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436340
int __stdcall sub_00436340_GatewayBack(int nUnused)
{
    gpfnGatewayDone_007795BC = sub_0042F6C0_SetDone;
    sub_0042F3F0_DestroyControls();
    sub_00435330_ShowLoginScreen();
    return 1;
}

// 0x00436AC0
void __cdecl sub_00436AC0_ClearStatusTexts()
{
    gpStatusText_007799A8 = 0;
    gpCounterText_007799AC = 0;
}
