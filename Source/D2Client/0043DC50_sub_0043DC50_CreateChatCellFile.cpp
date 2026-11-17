struct D2CellFileStrc;
struct D2WinControlStrc;

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2WinControlInitStrc
{
    int nType;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int field_14;
    int nStringId;
    D2CellFileStrc** ppCellFile;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

struct D2LaunchFuncsStrc
{
    char unk0x00[0x10];
    void (__fastcall* pfn0x10)();
    char unk0x14[0x40];
    void (__fastcall* pfn0x54)(char* szName, char* szTitle, int nA, char* szRealm, int nFlags);
    void (__fastcall* pfn0x58)();
    char unk0x5C[0x0C];
    int (__fastcall* pfn0x68)();
    char unk0x6C[0x3C];
    void (__fastcall* pfn0xA8)(void (__fastcall* pfnA)(void* pA, void* pB), void (__cdecl* pfnB)());
    void (__fastcall* pfn0xAC)();
};

#pragma pack(push, 1)
struct D2LaunchCharInfoStrc
{
    char unk0x00[0xBD];
    char szName0xBD[0x131];
    unsigned char nValue0x1EE;
    char wFlags[2];
    char unk0x1F1[0x34];
    D2LaunchFuncsStrc* f_225;
    char unk0x229[0x04];
    char szRealm0x22D[0x131];
    char nType0x35E;
    char unk0x35F[0x02];
    char szText0x361[0x40];
    char szText0x3A1[0x10];
    char szText0x3B1[0x1A];
    char wFlags0x3CB[2];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __cdecl sub_00410610_WriteLogLine(const char* szFormat, ...);                                                           // 0x00410610
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void* __stdcall sub_004FAC80(int nArg);                                                                     // 0x004FAC80
int __fastcall sub_005259C0(void* pArg, int nArg);                                                          // 0x005259C0
void __cdecl sub_00524E40();                                                                                // 0x00524E40
void __cdecl sub_0043CC30();                                                                                // 0x0043CC30
void __stdcall sub_004F9160_SetLoopValue(int nValue);                                                       // 0x004F9160
int __stdcall BACKGROUND_SetCellFile(D2CellFileStrc* pCellFile);                                            // 0x004F9140
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit);                             // 0x004F93C0
void __cdecl sub_0043DDD0();                                                                                // 0x0043DDD0
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength);                         // 0x004FDD50
void __cdecl sub_004477A0_Refresh();                                                                        // 0x004477A0
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet);                  // 0x004FA420
D2WinControlStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CellFileStrc* pCellFile, int a6, int a7, int a8, int a9, int a10, int a11); // 0x00501290
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet);                        // 0x004F9740
void __fastcall sub_00500B20_SetValue(D2WinControlStrc* pControl, int nValue);                              // 0x00500B20
void __cdecl sub_0043F4D0();                                                                                // 0x0043F4D0
void __cdecl sub_0043F8C0_ResetLaunchState();                                                               // 0x0043F8C0
void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0
void __fastcall sub_0044B220_SetCallback(void (__fastcall* pfnCallback)(void* pArg));                       // 0x0044B220
void __cdecl sub_0044AA50();                                                                                // 0x0044AA50
void __cdecl sub_0043F730();                                                                                // 0x0043F730
void __fastcall sub_004F96F0_ControlClearState(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl);                                          // 0x004FA450
void __cdecl sub_00514DB0();                                                                                // 0x00514DB0
void __fastcall sub_00514E10(const char* szFile);                                                           // 0x00514E10
int __cdecl sub_00514D80();                                                                                 // 0x00514D80
void __fastcall D2SOUND_10034(int nArg);                                                                    // 0x005148F0
int __cdecl sub_00441A90();                                                                                 // 0x00441A90
void __stdcall sub_00449E50(int nValue);                                                                    // 0x00449E50
typedef int (__stdcall* D2LaunchCallback)(int nArg);
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590
int __cdecl sub_00449E40();                                                                                 // 0x00449E40
void __cdecl sub_0044AA80();                                                                                // 0x0044AA80
void __cdecl D2MCPClientCloseMCP();                                                                         // 0x00449AD0
void __cdecl sub_00515070();                                                                                // 0x00515070
void __cdecl sub_004495A0();                                                                                // 0x004495A0
void __cdecl sub_00505100();                                                                                // 0x00505100
void __cdecl sub_0043F800();                                                                                // 0x0043F800
int __stdcall sub_004F95C0_ControlDestroy(D2WinControlStrc** ppControl);                                   // 0x004F95C0
void __cdecl sub_0043D510();                                                                                // 0x0043D510
void* __stdcall sub_005066C0(int nA, int nMode, char* szA, char* szB);                                     // 0x005066C0
void __stdcall sub_005052B0(void* pObject, int nValue);                                                    // 0x005052B0
void __stdcall sub_005052F0(void* pObject, int nValue);                                                    // 0x005052F0
void __stdcall sub_005051A0(void* pObject, int nValue);                                                    // 0x005051A0
void __stdcall sub_00505260(void* pObject, int nValue);                                                    // 0x00505260
int __stdcall sub_0043F9B0_EditKey(D2WinControlStrc* pControl, int nPos, const char* pKey);                 // 0x0043F9B0
int __stdcall sub_0043DB90(int nArg);                                                                       // 0x0043DB90
int __stdcall sub_00448C70_ButtonCallback(void* pMsg);                                                      // 0x00448C70
void __fastcall sub_00440D10(void* pArg);                                                                   // 0x00440D10
void __fastcall sub_0043E4C0(void* pA, void* pB);                                                           // 0x0043E4C0
void __cdecl sub_0043E570();                                                                                // 0x0043E570
int __stdcall sub_00441500(int nUnused);                                                               // 0x00441500

extern int gnLaunchMode_0077BBE4;                                                                           // 0x0077BBE4
static int gbDone_0077BDA0;                                                                                 // 0x0077BDA0
static int gdwGlobal_0077BBF8;                                                                              // 0x0077BBF8
D2LaunchFuncsStrc* gpLaunchFuncs_0077B09C;                                                                  // 0x0077B09C
static int gnLoopValueOut_0077BC14;                                                                         // 0x0077BC14
extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8;                                                           // 0x0077BBD8
extern D2WinControlStrc* gpChatTextBox_0077BD8C;                                                            // 0x0077BD8C
extern D2CellFileStrc* gpChatBackground_0077BC04;                                                           // 0x0077BC04
extern D2CellFileStrc* gpCellFile_0077BC08;                                                                 // 0x0077BC08
extern D2WinControlStrc* gpChatControl_0077B058[17];                                                        // 0x0077B058
extern D2WinControlInitStrc gatChatControlInits_0070CE50[17];                                               // 0x0070CE50
extern D2WinControlInitStrc gtControlInit_0070D2A0;                                                         // 0x0070D2A0
D2WinControlStrc* gpControl_0077BD98;                                                                       // 0x0077BD98
extern D2WinControlInitStrc gtControlInit_0070D240;                                                         // 0x0070D240
extern D2WinControlInitStrc gtControlInit_0070D270;                                                         // 0x0070D270
D2WinControlStrc* gpChatEdit_0077BD94;                                                                      // 0x0077BD94
extern D2WinControlStrc* gpChatControl_0077B084;                                                            // 0x0077B084
extern D2WinControlStrc* gpChatControl_0077B088;                                                            // 0x0077B088
extern D2WinControlStrc* gpChatControl_0077B08C;                                                            // 0x0077B08C
extern D2WinControlStrc* gpChatControl_0077B090;                                                            // 0x0077B090
D2WinControlStrc* gapChatButtons_0077AD78[11];                                                              // 0x0077AD78
extern D2WinControlInitStrc gtControlInit_0070D210;                                                         // 0x0070D210
D2WinControlStrc* gpChatControl_0077BC44;                                                                   // 0x0077BC44
extern D2WinControlInitStrc gtControlInit_0070D390;                                                         // 0x0070D390
static int gbToggle_0077BBEC;                                                                               // 0x0077BBEC
D2WinControlStrc* gpChatControl_0077BC48;                                                                   // 0x0077BC48
extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070
extern D2WinControlStrc* gpChatControl_0077B074;                                                            // 0x0077B074
extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078
extern D2WinControlStrc* gpControlC_0077B07C;                                                               // 0x0077B07C
extern D2WinControlInitStrc gtControlInit_0070D2D0;                                                         // 0x0070D2D0
extern D2WinControlInitStrc gtControlInit_0070D300;                                                         // 0x0070D300
D2WinControlStrc* gpNamesButton_0077BD08;                                                                   // 0x0077BD08
extern D2WinControlInitStrc gtControlInit_0070D330;                                                         // 0x0070D330
extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C
extern D2WinControlInitStrc gtControlInit_0070D360;                                                         // 0x0070D360
extern D2WinControlStrc* gpControl_0077B080;                                                                // 0x0077B080
char gszText_0077B1D0[8];                                                                                   // 0x0077B1D0
char gszText_0077B0B4[28];                                                                                  // 0x0077B0B4
extern int gbCheck_0077BD58;                                                                                // 0x0077BD58
static D2CriticalSectionStrc gtChatLock_0077AE28;                                                           // 0x0077AE28
D2WinControlStrc* gapControls_0077B050[2];                                                                  // 0x0077B050
D2WinControlStrc* gpControl_0077BC40;                                                                       // 0x0077BC40
D2CellFileStrc* gpChatCellFile_0077BBFC;                                                                    // 0x0077BBFC

// 0x0043DC50
static void __cdecl sub_0043DC50_CreateChatCellFile(D2LaunchCharInfoStrc* pInfo)
{
    int nMode = 5;
    const unsigned short wFlags = *(unsigned short*)pInfo->wFlags0x3CB;
    if ((wFlags & 4) && !(wFlags & 8) && (sub_00408F20_HasExpansionMpq() || pInfo->nValue0x1EE < 5))
        nMode = 1;
    gpChatCellFile_0077BBFC = (D2CellFileStrc*)sub_005066C0(pInfo->nValue0x1EE, nMode, pInfo->szText0x3A1, pInfo->szText0x3B1);
    if (gpChatCellFile_0077BBFC)
    {
        sub_005052B0(gpChatCellFile_0077BBFC, 0x42);
        sub_005052F0(gpChatCellFile_0077BBFC, 0x23B);
        sub_005051A0(gpChatCellFile_0077BBFC, 0);
        sub_00505260(gpChatCellFile_0077BBFC, 0);
    }
}
#define CREATE_CELL_FILE sub_0043DC50_CreateChatCellFile

// 0x00441B70
int __fastcall sub_00441B70_RunChat(D2LaunchCharInfoStrc* pInfo)
{
    char szTitle[256];
    D2WinControlStrc* pControl8;
    D2WinControlStrc* pControl4;

    GetTickCount();
    if (!sub_005259C0(sub_004FAC80(sub_00408F20_HasExpansionMpq()), 0))
        return 1;

    gnLaunchMode_0077BBE4 = 0;
    gbDone_0077BDA0 = 0;
    gdwGlobal_0077BBF8 = 1;
    gpLaunchFuncs_0077B09C = pInfo->f_225;
    D2_ASSERT(gpLaunchFuncs_0077B09C, 3303);
    if (!gpLaunchFuncs_0077B09C->pfn0x68())
        gbDone_0077BDA0 = 4;
    else
    {
    sub_0043CC30();
    sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);
    gpChatTextBox_0077BD8C = 0;
    if (gpCharInfo_0077BBD8->szText0x361[0])
        BACKGROUND_SetCellFile(gpChatBackground_0077BC04);
    else
        BACKGROUND_SetCellFile(gpCellFile_0077BC08);
    if (gpCharInfo_0077BBD8->szText0x361[0])
    {
        for (int i = 0; i < 17; i++)
            gpChatControl_0077B058[i] = CONTROL_Create(&gatChatControlInits_0070CE50[i]);
        gpControl_0077BD98 = CONTROL_Create(&gtControlInit_0070D2A0);
    }
    else
    {
        sub_0043DDD0();
        CREATE_CELL_FILE(pInfo);
    }
    gpChatTextBox_0077BD8C = CONTROL_Create(&gtControlInit_0070D240);
    if (gpCharInfo_0077BBD8->szText0x361[0])
    {
        gpChatEdit_0077BD94 = CONTROL_Create(&gtControlInit_0070D270);
        sub_004FDAD0_SetKeyCallback(gpChatEdit_0077BD94, sub_0043F9B0_EditKey);
        sub_004FDB00_SetEnterCallback(gpChatEdit_0077BD94, sub_0043DB90);
        sub_004F91C0(gpChatEdit_0077BD94);
        sub_004FDD50_SetMaxLength(gpChatEdit_0077BD94, 200);
        sub_004477A0_Refresh();
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B084, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B088, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B08C, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gpChatControl_0077B090, 1);
        D2WinControlStrc** ppButton = gapChatButtons_0077AD78;
        for (int nX = 40; nX < 700; nX += 60, ppButton++)
            *ppButton = BUTTON_Create(nX, 591, 60, 100, 0, (int)sub_00448C70_ButtonCallback, 0, 0, 4, 0, 0);
        gpChatControl_0077BC44 = CONTROL_Create(&gtControlInit_0070D210);
        sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
        gpChatControl_0077BC48 = CONTROL_Create(&gtControlInit_0070D390);
        if (gbToggle_0077BBEC)
            sub_00500B20_SetValue(gpChatControl_0077BC48, 2);
    }
    sub_0043F4D0();
    sub_0043F8C0_ResetLaunchState();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    gnLaunchMode_0077BBE4 = 0;
    pControl8 = CONTROL_Create(&gtControlInit_0070D2D0);
    gpNamesButton_0077BD08 = CONTROL_Create(&gtControlInit_0070D300);
    gpControlMain_0077BC4C = CONTROL_Create(&gtControlInit_0070D330);
    sub_0044B220_SetCallback(sub_00440D10);
    sub_0044AA50();
    sub_0043F730();
    pControl4 = CONTROL_Create(&gtControlInit_0070D360);
    const unsigned short wFlags = *(unsigned short*)gpCharInfo_0077BBD8->wFlags;
    if ((wFlags & 8) && (wFlags & 4))
    {
        sub_004F96F0_ControlClearState(gpControlA_0077B070, 0);
        sub_004F96F0_ControlClearState(gpControlB_0077B078, 0);
    }
    sub_004FA450_SetActive(gpControl_0077B080);
    gszText_0077B1D0[0] = 0;
    gszText_0077B0B4[0] = 0;
    sub_00514DB0();
    sub_00514E10("data\\global\\sfx\\cursor\\button.wav");
    if (sub_00514D80())
        D2SOUND_10034(1);
    gbCheck_0077BD58 = gpCharInfo_0077BBD8->nType0x35E == 4;
    sub_004F96F0_ControlClearState(gpControlC_0077B07C, gbCheck_0077BD58 == 0);
    if (sub_00441A90())
    {
        sprintf(szTitle, "%s,%s", pInfo->szRealm0x22D, pInfo->szName0xBD);
        int nFlags = 0;
        if (*(unsigned short*)pInfo->wFlags & 0x20)
            nFlags = 1;
        if (gpCharInfo_0077BBD8->szText0x361[0])
            nFlags |= 2;
        gpLaunchFuncs_0077B09C->pfn0x54(pInfo->szName0xBD, szTitle, 0x25, pInfo->szText0x361, nFlags);
    }
    else
    {
        sub_00410610_WriteLogLine("[D2MULTI]  Could not restore MCP connection.");
        gpLaunchFuncs_0077B09C->pfn0x10();
    }
    if (gpLaunchFuncs_0077B09C->pfn0x68())
    {
        sub_00449E50(0);
        InitializeCriticalSection(&gtChatLock_0077AE28);
        if (!gpCharInfo_0077BBD8->szText0x361[0])
            gpLaunchFuncs_0077B09C->pfn0xA8(sub_0043E4C0, sub_0043E570);
        sub_004FA590_RunLoop(sub_00441500);
        if (sub_00449E40())
        {
            sub_0044AA80();
            sub_00449E50(0);
        }
        if (!gpCharInfo_0077BBD8->szText0x361[0])
            gpLaunchFuncs_0077B09C->pfn0xAC();
        DeleteCriticalSection(&gtChatLock_0077AE28);
        gpLaunchFuncs_0077B09C->pfn0x58();
        if (gbDone_0077BDA0 != 4)
            D2MCPClientCloseMCP();
    }
    else
        gbDone_0077BDA0 = 4;

    GetTickCount();
    sub_00515070();
    sub_004495A0();
    sub_00505100();
    sub_0043F8C0_ResetLaunchState();
    sub_0043F800();
    sub_004F95C0_ControlDestroy(&gpChatTextBox_0077BD8C);
    if (gpControl_0077BD98)
        sub_004F95C0_ControlDestroy(&gpControl_0077BD98);
    sub_004F95C0_ControlDestroy(&pControl8);
    sub_004F95C0_ControlDestroy(&pControl4);
    sub_004F95C0_ControlDestroy(&gpNamesButton_0077BD08);
    sub_004F95C0_ControlDestroy(&gpControlMain_0077BC4C);
    if (gpChatControl_0077BC48)
        sub_004F95C0_ControlDestroy(&gpChatControl_0077BC48);
    if (gpChatEdit_0077BD94)
        sub_004F95C0_ControlDestroy(&gpChatEdit_0077BD94);
    for (int j = 0; j < 11; j++)
    {
        if (gapChatButtons_0077AD78[j])
            sub_004F95C0_ControlDestroy(&gapChatButtons_0077AD78[j]);
        gapChatButtons_0077AD78[j] = 0;
    }
    sub_004F95C0_ControlDestroy(&gpChatControl_0077BC44);
    for (int k = 0; k < 17; k++)
    {
        if (gpChatControl_0077B058[k])
            sub_004F95C0_ControlDestroy(&gpChatControl_0077B058[k]);
        gpChatControl_0077B058[k] = 0;
    }
    if (!gpCharInfo_0077BBD8->szText0x361[0])
    {
        for (int m = 0; m <= 1; m++)
        {
            if (gapControls_0077B050[m])
            {
                sub_004F95C0_ControlDestroy(&gapControls_0077B050[m]);
                gapControls_0077B050[m] = 0;
            }
        }
        if (gpControl_0077BC40)
        {
            sub_004F95C0_ControlDestroy(&gpControl_0077BC40);
            gpControl_0077BC40 = 0;
        }
    }
    BACKGROUND_SetCellFile(0);
    sub_004F9160_SetLoopValue(0);
    sub_0043D510();
    }
    sub_00524E40();
    return 1;
}

#include "gen/data/Source/D2Client/0043DC50_sub_0043DC50_CreateChatCellFile.inc"
