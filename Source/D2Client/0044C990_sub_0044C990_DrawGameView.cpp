struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2ViewStrc;
struct D2ActInfoStrc;

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2LevelsTxt
{
    char unk0x000[0x218];
    unsigned int dwBlankScreen;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ViewStrc* gpView_007A0640;                                                                                // 0x007A0640
extern int gnLastViewX_0070F55C;                                                                            // 0x0070F55C
extern int gnLastViewY_0070F558;                                                                            // 0x0070F558
extern int gnViewDeltaX_007A0678;                                                                           // 0x007A0678
extern int gnViewDeltaY_007A067C;                                                                           // 0x007A067C
extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
extern int gnClearScreenCount_0070F2C0;                                                                     // 0x0070F2C0
void __fastcall sub_004547B0();                                                                             // 0x004547B0
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
void __fastcall sub_00476D40_AdjustViewPos(int* pX, int* pY);                                               // 0x00476D40
void __fastcall sub_004760A0_SetViewPos(D2ViewStrc* pView, int nX, int nY);                                 // 0x004760A0
void __fastcall sub_00476140(D2ViewStrc* pView, int nArg);                                                  // 0x00476140
void __fastcall sub_00473F50();                                                                             // 0x00473F50
void __stdcall sub_0061C0B0(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue);  // 0x0061C0B0
void __stdcall sub_004F6430_SetAmbientColor(int nRed, int nGreen, int nBlue);                               // 0x004F6430
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);    // 0x004F60F0
void __fastcall sub_004FB0D0();                                                                             // 0x004FB0D0
void __fastcall sub_0045B440();                                                                             // 0x0045B440
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
void __fastcall sub_00476BC0(D2ViewStrc* pView);                                                            // 0x00476BC0
void __fastcall sub_00456EE0(D2ViewStrc* pView);                                                            // 0x00456EE0
void __stdcall sub_004F98E0();                                                                               // 0x004F98E0
void __fastcall sub_00468820(int nArg1, int nArg2);                                                         // 0x00468820
void __fastcall sub_004684C0();                                                                  // 0x004684C0
void __fastcall sub_00477980();                                                                             // 0x00477980
void __stdcall D2GFX_ClearScreen(int bPartial);                                                             // 0x004F63B0
int __stdcall D2GFX_EndScene();                                                                             // 0x004F6190

static int GetRoomBlankScreen(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    D2LevelsTxt* pTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pTxt, 1502);
    return pTxt->dwBlankScreen;
}

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

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
static int gdwGlobal_007A0608;                                                                              // 0x007A0608
static int gdwGlobal_007A0650;                                                                              // 0x007A0650
static int gdwGlobal_007A0654;                                                                              // 0x007A0654
static int gdwGlobal_007A066C;                                                                              // 0x007A066C
static int gdwGlobal_007A0670;                                                                              // 0x007A0670
static int gdwGlobal_007A0680;                                                                              // 0x007A0680
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290

// 0x0044C990
void __fastcall sub_0044C990_DrawGameView(int bNoCursor)
{
    sub_004547B0();
    if (WINDOW_GetState())
        return;

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2RectStrc tRect;
    sub_00476070_GetViewRect(gpView_007A0640, &tRect.nLeft, &tRect.nTop, &tRect.nRight, &tRect.nBottom);
    int nY;
    int nX;
    nX = UNITS_GetClientCoordX(pPlayer) - (tRect.nRight - tRect.nLeft) / 2;
    nY = UNITS_GetClientCoordY(pPlayer) - (tRect.nBottom - tRect.nTop) / 2;
    sub_00476D40_AdjustViewPos(&nX, &nY);
    if (gnLastViewX_0070F55C != -1 || gnLastViewY_0070F558 != -1)
    {
        gnViewDeltaX_007A0678 = nX - gnLastViewX_0070F55C;
        gnViewDeltaY_007A067C = nY - gnLastViewY_0070F558;
    }
    gnLastViewX_0070F55C = nX;
    gnLastViewY_0070F558 = nY;
    sub_004760A0_SetViewPos(gpView_007A0640, nX, nY);
    sub_00476140(gpView_007A0640, 0);
    sub_00473F50();

    unsigned char nRed, nGreen, nBlue;
    sub_0061C0B0(gpGlobal_007A0634, &nRed, &nGreen, &nBlue);
    sub_004F6430_SetAmbientColor(nRed, nGreen, nBlue);

    if (!D2GFX_StartDraw(GetRoomBlankScreen(sub_004646A0_GetPlayerRoom()), 0, 0, 0))
        return;

    sub_004FB0D0();
    sub_0045B440();
    if (sub_0045AE90() != 3)
        sub_00476BC0(gpView_007A0640);
    sub_00456EE0(gpView_007A0640);
    sub_004F98E0();
    sub_00468820(10, 10);
    if (!bNoCursor)
        sub_004684C0();
    sub_00477980();
    if (gnClearScreenCount_0070F2C0)
    {
        D2GFX_ClearScreen(0);
        if (--gnClearScreenCount_0070F2C0 < 0)
            gnClearScreenCount_0070F2C0 = 0;
    }
    D2GFX_EndScene();
}

// 0x0044E4F0
void __stdcall sub_0044E4F0_MouseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007A0680 = 0;
    const int nBottom = gnGlobal_00711470 - 0x50;
    int nLeft = gnGlobal_0071146C / 2 - 0x30;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gdwGlobal_007A0608 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0670 = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

#include "gen/data/Source/D2Client/0044C990_sub_0044C990_DrawGameView.inc"
