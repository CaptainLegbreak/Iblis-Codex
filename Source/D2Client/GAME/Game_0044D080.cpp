#include "D2Client.h"
#include "D2StormTypes.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2LevelTxt.h"

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __cdecl sub_00466FE0(); // 0x00466FE0

int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90

unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0

void __cdecl sub_0044C060_Refresh(); // 0x0044C060

void __cdecl sub_00466FF0(); // 0x00466FF0

extern int gdwGlobal_007A0664; // 0x007A0664

extern int gdwGlobal_007A065C; // 0x007A065C

static int gdwGlobal_007A0654; // 0x007A0654

static int gdwGlobal_007A0670; // 0x007A0670

extern int gdwGlobal_007A0658; // 0x007A0658

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct _RTL_CRITICAL_SECTION;

struct D2BetaScreenStrc;

struct Unicode;

struct D2ClientConfigStrc;

#pragma pack(push, 1)

struct D2ConfigStrc
{
    char unk0x000[0x19];
    int dwGameType;
    unsigned short wJoinID;
    char szGameName[0x18];
    char szServerIP[0x18];
    char szBattleNetIP[0x18];
    char szMCPIP[0x18];
    char unk0x07F[6];
    char bAmazon;
    char bPaladin;
    char bSorceress;
    char bNecromancer;
    char bBarbarian;
    char bDruid;
    char bAssassin;
    unsigned char unk_8C[0x31];
    char szName[0x18];
    char szRealm[0x18];
    unsigned char unk_ED[0x112];
    int dwAct;
    char unk0x203[0x219 - 0x203];
    char bFlag219;
    char unk0x21A[0x229 - 0x21A];
    int dwValue229;
};

struct D2BetaScreenStrc
{
    unsigned long dwTick;
    D2CelFileStrc* pCelFile;
    unsigned char nAct;
    const char* szName;
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl strcmp(const char* s1, const char* s2);

extern int gnState_0070EF18; // 0x0070EF18

extern D2BetaScreenStrc gtBetaScreens_0070F238[]; // 0x0070F238

extern int gnBetaScreenCount_0070F024; // 0x0070F024

extern char gszServerIP_0070EF20[]; // 0x0070EF20

extern char gszAddress_0070F130[]; // 0x0070F130

extern unsigned char gbGlobal_007A0522; // 0x007A0522

void __fastcall sub_0044B440_PushValue(int nValue); // 0x0044B440

void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880

void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0

void __fastcall sub_00478A00(void* pCel); // 0x00478A00

int __fastcall D2Win_10177(unsigned char nAct); // 0x004FB480

void __cdecl sub_00475EF0_FreeLerpTables(); // 0x00475EF0

void __cdecl sub_00468170_ShutdownCursor(); // 0x00468170

void __cdecl sub_00451850_FreeMsgRecordChunks(); // 0x00451850

void __cdecl sub_004794B0_FreeRosterLists(); // 0x004794B0

void __cdecl sub_00478A50_FreeRosterPets(); // 0x00478A50

void __cdecl sub_00451F20_RegisterWindowHandlers(); // 0x00451F20

void __fastcall sub_00530F30_SetGlobal(int nValue); // 0x00530F30

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

void __stdcall GAME_SetGlobalAct(int nAct); // 0x0052DFA0

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

extern int gnGlobal_0071146C; // 0x0071146C

extern "C" unsigned int __cdecl strlen(const char* s);

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

struct D2ClientConfigStrc
{
    char unk0x000[0x1EF];
    unsigned char nFlags1EF;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC214

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

int __cdecl sub_00449B70_PollMcpConnection(); // 0x00449B70

void __cdecl sub_0044C000_StartClick(); // 0x0044C000

void __cdecl sub_0044C2C0(); // 0x0044C2C0

void __cdecl sub_0044C6E0_DrainPacketQueues(); // 0x0044C6E0

void __cdecl sub_0044C790_Update(); // 0x0044C790

int __fastcall sub_0044CCA0(unsigned int nFrames, unsigned int nRemainder, int nRate);

void __cdecl sub_0044CCE0_AverageCounters(); // 0x0044CCE0

void __cdecl sub_0044CE90_UpdateKeyState(); // 0x0044CE90

void __cdecl sub_0044EEC0_CheckConnectionTimeouts(); // 0x0044EEC0

void __cdecl sub_004519C0_ReplayRecords(); // 0x004519C0

int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90

int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __cdecl sub_00462920_ClearValue(); // 0x00462920

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0

void __cdecl sub_00467AC0_UpdateHoverUnit(); // 0x00467AC0

void __cdecl sub_00477DD0(); // 0x00477DD0

int __cdecl sub_0047BDF0_HandleBnetChatMessage(); // 0x0047BDF0

void __fastcall sub_00480320_CallHolderSlot3(int nDelta); // 0x00480320

void __fastcall sub_00481600_RunPendingAction(D2UnitStrc* pPlayer); // 0x00481600

void __cdecl sub_00482C20_Tick(); // 0x00482C20

int __cdecl sub_00514840_IsChannelStreaming(); // 0x00514840

void __cdecl sub_00514930_StopChannel(); // 0x00514930

void __fastcall sub_00515F50_FadeOutMaster(int nArg); // 0x00515F50

int __stdcall GAME_UpdateGamesProgress(int nArg); // 0x0052FC20

extern unsigned int gdwFrameTime_0070EF1C; // 0x0070EF1C

extern D2ClientConfigStrc* gpConfig_007A0438; // 0x007A0438

extern _RTL_CRITICAL_SECTION gCriticalSection_007A0468; // 0x007A0468

extern unsigned int gdwLastCheck_007A04A0; // 0x007A04A0

extern unsigned int gdwGlobal_007A04B8; // 0x007A04B8

extern unsigned int gdwGlobal_007A04BC; // 0x007A04BC

extern int gdwGlobal_007A061C; // 0x007A061C

int gdwGlobal_007A0620; // 0x007A0620

extern int gnGlobal_007A0648; // 0x007A0648

extern int gnGlobal_007A0650; // 0x007A0650

extern int gnGlobal_007A0654; // 0x007A0654

unsigned char gnBetaScreenIndex_007A060D; // 0x007A060D

char gszGameName_007A05DC[20]; // 0x007A05DC

unsigned short gwJoinID_007A0520; // 0x007A0520

int gdwGlobal_007A05C0; // 0x007A05C0

int gdwGlobal_007A04F4; // 0x007A04F4

char gszCharName_007A05C4[4]; // 0x007A05C4

D2ClientCallbackFn gpfnClientCallback_007A0484; // 0x007A0484

unsigned int gdwGlobal_007A048C; // 0x007A048C

unsigned int gdwLastFrame_007A0490; // 0x007A0490

int gnGlobal_007A0494; // 0x007A0494

unsigned int gdwNextCheck_007A049C; // 0x007A049C

int gdwGlobal_007A04A8; // 0x007A04A8

int gnGlobal_007A04AC; // 0x007A04AC

int gnGlobal_007A04B0; // 0x007A04B0

int gnGlobal_007A04B4; // 0x007A04B4

void* ghEvent_007A05BC; // 0x007A05BC

int gnGameType_007A0610; // 0x007A0610

int gnSkipped_007A0704; // 0x007A0704

struct D2ActInfoStrc;

struct D2RectStrc;

struct D2ClientCharRecordStrc;

struct D2PongDataStrc;

struct D2GSPacketSrv8F;

struct D2MsgHandlerEntryStrc;

struct D2ChatStormLinkStrc;

struct D2ChatStormLinkAStrc;

struct D2ChatStormLinkBStrc;

struct D2ChatStormNodeStrc;

struct D2ChatStormBaseArrayAStrc;

struct D2ChatStormBaseArrayBStrc;

struct D2ChatStormListAStrc;

struct D2ChatStormListBStrc;

struct D2ChatStormHashTableStrc;

struct D2ChatStormCtorLinkStrc;

struct D2ChatStormListCStrc;

struct D2ChatStormListDStrc;

struct D2ChatStormListEStrc;

struct D2CommonStormSlotLinkStrc;

struct D2CommonStormSlotListAStrc;

struct D2CommonStormSlotListBStrc;

struct D2CommonMappingEntryNodeBaseStrc;

struct D2CommonMappingEntryNodeStrc;

struct D2CommonStringEntryNodeStrc;

struct D2CommonStormHashTableAStrc;

struct D2LoadingTimerStrc;

extern int gnLastViewX_0070F55C; // 0x0070F55C

extern int gnLastViewY_0070F558; // 0x0070F558

extern int gnViewDeltaX_007A0678; // 0x007A0678

extern int gnViewDeltaY_007A067C; // 0x007A067C

extern void* gpGlobal_007A0634; // 0x007A0634

void __fastcall sub_004547B0(); // 0x004547B0

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

void __fastcall sub_00476D40_AdjustViewPos(int* pX, int* pY); // 0x00476D40

void __fastcall sub_004760A0_SetViewPos(D2ViewStrc* pView, int nX, int nY); // 0x004760A0

void __fastcall sub_00476140(D2ViewStrc* pView, int nArg); // 0x00476140

void __cdecl sub_00473F50_UpdateWeather(); // 0x00473F50

void __stdcall sub_0061C0B0(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0

void __stdcall D2GFX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x004F6430

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __cdecl sub_0045B440_UpdateAutomapOrigin(); // 0x0045B440

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall sub_00476BC0(D2ViewStrc* pView); // 0x00476BC0

void __fastcall sub_00456EE0_DrawUIPanels(D2ViewStrc* pView); // 0x00456EE0

void __stdcall sub_004F98E0(); // 0x004F98E0

void __fastcall sub_00468820(int nArg1, int nArg2); // 0x00468820

void __cdecl sub_004684C0(); // 0x004684C0

void __fastcall sub_00477980(); // 0x00477980

extern int gnGlobal_00711470; // 0x00711470

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

#pragma pack(push, 1)

struct D2ClientCharRecordStrc
{
    char unk0x00[0x1EF];
    unsigned char aFlags[2];
};

#pragma pack(pop)

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

extern unsigned short gawLoadingStrings_0070F384[]; // 0x0070F384

int gnLoadingIndex_007A05D4; // 0x007A05D4

extern D2ClientCharRecordStrc* gpCharRecord_007A0438; // 0x007A0438

extern int gnAutomapWidth_007A5220; // 0x007A5220


struct D2PongDataStrc
{
    unsigned long dwData0;
    unsigned long dwData1;
    unsigned long dwData2;
    unsigned long dwData3;
    unsigned long dwTick;
    unsigned long dwData5;
    unsigned long dwData6;
    unsigned long dwData7;
};

#pragma pack(push, 1)

struct D2GSPacketSrv8F
{
    unsigned char nHeader;
    D2PongDataStrc tData;
};

#pragma pack(pop)

extern D2PongDataStrc gtPongData_007A04D4; // 0x007A04D4

typedef char D2MsgHandlerEntrySize[(sizeof(D2MsgHandlerEntryStrc) == 12) ? 1 : -1];

extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F2C4[1]; // 0x0070F2C4

extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F348[2]; // 0x0070F348

extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F360[2]; // 0x0070F360

int __cdecl sub_004F59A0(); // 0x004F59A0

extern "C" void __fastcall sub_00451DB0_RegisterMsgHandlers(int hwnd, D2MsgHandlerEntryStrc* table, unsigned int count); // 0x00451DB0

extern "C" void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2LoadingTimerStrc
{
    unsigned long dwStart;
    unsigned long dwLength;
};

extern int gdwGlobal_007A0524; // 0x007A0524

extern int gdwGlobal_007A0618; // 0x007A0618

extern int gdwGlobal_007A062C; // 0x007A062C

extern D2LoadingTimerStrc gtLoadingTimer_007A0684; // 0x007A0684

void __cdecl sub_0044CB60_DrawLoadingText(); // 0x0044CB60

int __fastcall sub_0044E040_TimerRunning(D2LoadingTimerStrc* pTimer); // 0x0044E040

D2ViewStrc* gpView_007A0640; // 0x007A0640

static int gdwGlobal_007A0608; // 0x007A0608

static int gdwGlobal_007A0650; // 0x007A0650

static int gdwGlobal_007A066C; // 0x007A066C

static int gdwGlobal_007A0680; // 0x007A0680

unsigned long gdwLastTick_007A04A0; // 0x007A04A0

unsigned long gdwPing_007A04A4; // 0x007A04A4

unsigned long gdwPingSamples_007A04CC; // 0x007A04CC

unsigned long gdwPingAverage_007A04D0; // 0x007A04D0

int gdwGlobal_007A05F8; // 0x007A05F8

int gdwGlobal_007A0604; // 0x007A0604

int gnValue_007A0624; // 0x007A0624

// 0x0044C5E0
void __stdcall sub_0044C5E0_ActivateMsg(SMSGHANDLER_PARAMS* pMessage)
{
    gdwGlobal_0070F7E0 = pMessage->wParam;
    if (pMessage->wParam)
    {
        sub_00455F20(0xD, 1, 0);
        gdwGlobal_007A0664 = 0;
        sub_00466FE0();
        sub_004FB130_SetActiveState(0);
        pMessage->bReturn = 0;
        return;
    }

    if (sub_00469D90(0x22, 1) && (static_cast<unsigned short>(GetAsyncKeyState(sub_00469AA0(0x22, 1))) & 0x8000) == 0)
    {
        gdwGlobal_007A065C = 0;
    }

    if (gdwGlobal_0070F234 != 0x10)
    {
        sub_0044C060_Refresh();
    }

    if (gdwGlobal_0070F2BC != 0x10)
    {
        gdwGlobal_0070F2BC = 0x10;
        gdwGlobal_007A0654 = 0;
        gdwGlobal_007A0670 = 1;
        gdwGlobal_007A0658 = 0;
        sub_00466FF0();
        pMessage->bReturn = 0;
        return;
    }

    pMessage->bReturn = 0;
}

static int GetRoomBlankScreen(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    D2LevelsTxt* pTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pTxt, 1502);
    return pTxt->dwBlankScreen;
}

// 0x0044C990
void __fastcall sub_0044C990_DrawGameView(int bNoCursor)
{
    sub_004547B0();
    if (WINDOW_GetState())
        return;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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
    sub_00473F50_UpdateWeather();

    unsigned char nRed, nGreen, nBlue;
    sub_0061C0B0(gpGlobal_007A0634, &nRed, &nGreen, &nBlue);
    D2GFX_SetAmbientColor(nRed, nGreen, nBlue);

    if (!D2GFX_StartDraw(GetRoomBlankScreen(sub_004646A0_GetPlayerRoom()), 0, 0, 0))
        return;

    sub_004FB0D0();
    sub_0045B440_UpdateAutomapOrigin();
    if (sub_0045AE90() != 3)
        sub_00476BC0(gpView_007A0640);
    sub_00456EE0_DrawUIPanels(gpView_007A0640);
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

// 0x0044CB60
void __cdecl sub_0044CB60_DrawLoadingText()
{
    if (WINDOW_GetState())
    {
        return;
    }
    if (!D2GFX_StartDraw(1, 0, 0, 0))
    {
        return;
    }
    D2GFX_ClearScreen(0);
    sub_00502EF0(3);
    const Unicode* pText = D2LANG_GetStringFromTblIndex(gawLoadingStrings_0070F384[gnLoadingIndex_007A05D4]);
    if (gpCharRecord_007A0438->aFlags[0] & 0x20)
    {
        if (gnLoadingIndex_007A05D4 == 0x14)
        {
            pText = D2LANG_GetStringFromTblIndex(0x5522);
        }
        else if (gnLoadingIndex_007A05D4 == 0x15)
        {
            pText = D2LANG_GetStringFromTblIndex(0x5521);
        }
    }
    const int nWidth = sub_00501820(pText);
    if (nWidth < gnAutomapWidth_007A5220 - 0x28)
    {
        sub_00502320(pText, (gnAutomapWidth_007A5220 - nWidth) >> 1, 0xC8, 0, 0);
    }
    else
    {
        sub_00502EF0(2);
        int nLines;
        T0044CB60* pLines = sub_00502970_SplitText(pText, &nLines, 0x258);
        T0044CB60* pLine = pLines;
        for (unsigned int i = 0; i < nLines; ++i)
        {
            const int nX = (gnAutomapWidth_007A5220 - sub_00501820(pLine->pText)) >> 1;
            sub_00502320(pLine->pText, nX, 2 * (D2Win_10125() * i) + 0xC8, 0, 0);
            pLine = pLine->pNext;
        }
        sub_005028A0_FreeTextLines(pLines);
    }
    sub_004F98E0();
    D2GFX_EndScene();
}

// 0x0044CDB0
void __fastcall sub_0044CDB0_StorePong(const D2GSPacketSrv8F* pPacket)
{
    gtPongData_007A04D4.dwData0 = pPacket->tData.dwData0;
    gtPongData_007A04D4.dwData1 = pPacket->tData.dwData1;
    gtPongData_007A04D4.dwData2 = pPacket->tData.dwData2;
    gtPongData_007A04D4.dwData3 = pPacket->tData.dwData3;
    gtPongData_007A04D4.dwTick = pPacket->tData.dwTick;
    gtPongData_007A04D4.dwData5 = pPacket->tData.dwData5;
    gtPongData_007A04D4.dwData6 = pPacket->tData.dwData6;
    gtPongData_007A04D4.dwData7 = pPacket->tData.dwData7;
    gtPongData_007A04D4.dwTick = GetTickCount();
    unsigned long dwPing = GetTickCount() - gdwLastTick_007A04A0;
    gdwPing_007A04A4 = dwPing;
    if (gdwPingSamples_007A04CC < 10)
    {
        dwPing += gdwPingAverage_007A04D0 * gdwPingSamples_007A04CC;
        ++gdwPingSamples_007A04CC;
        gdwPingAverage_007A04D0 = dwPing / gdwPingSamples_007A04CC;
    }
}

// 0x0044D080
int __cdecl sub_0044D080_PushState()
{
    if (gnState_0070EF18 == 5)
        sub_0044B440_PushValue(gnState_0070EF18 - 3);
    return gnState_0070EF18;
}

// 0x0044D100
int __stdcall sub_0044D100_ShowBetaScreens(int nArg)
{
    char szPath[0x104];
    D2GfxDataStrc tData;
    if (!WINDOW_GetState())
    {
        if (!D2GFX_StartDraw(1, 0, 0, 0))
            return 0;
        if (gnBetaScreenIndex_007A060D < gnBetaScreenCount_0070F024)
        {
            if (!gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].pCelFile)
            {
                wsprintfA(szPath, "%s\\ui\\betascreens\\%s", szDataGlobal_006D4118, gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].szName);
                gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].pCelFile = sub_004788B0(szPath, 0);
                gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].dwTick = GetTickCount();
                D2Win_10177(gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].nAct);
            }
            memset(&tData, 0, sizeof(tData));
            tData.pCellFile = gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].pCelFile;
            tData.nDirection = 0;
            tData.nFrame = 0;
            TEXTURE_CelDraw(&tData, 0, 0x100, -1, 5, 0);
            tData.nFrame = 1;
            TEXTURE_CelDraw(&tData, 0x100, 0x100, -1, 5, 0);
            tData.nFrame = 2;
            TEXTURE_CelDraw(&tData, 0x200, 0x100, -1, 5, 0);
            tData.nFrame = 3;
            TEXTURE_CelDraw(&tData, 0, 0x1E0, -1, 5, 0);
            tData.nFrame = 4;
            TEXTURE_CelDraw(&tData, 0x100, 0x1E0, -1, 5, 0);
            tData.nFrame = 5;
            TEXTURE_CelDraw(&tData, 0x200, 0x1E0, -1, 5, 0);
        }
        D2GFX_EndScene();
    }
    if (gnBetaScreenIndex_007A060D >= gnBetaScreenCount_0070F024 || GetTickCount() > gtBetaScreens_0070F238[gnBetaScreenIndex_007A060D].dwTick + 10000)
    {
        gnBetaScreenIndex_007A060D += 1;
        if (gnBetaScreenIndex_007A060D >= gnBetaScreenCount_0070F024)
        {
            for (int i = 0; i < gnBetaScreenCount_0070F024; i += 1)
            {
                if (gtBetaScreens_0070F238[i].pCelFile)
                {
                    sub_00478A00(gtBetaScreens_0070F238[i].pCelFile);
                    gtBetaScreens_0070F238[i].pCelFile = 0;
                    gtBetaScreens_0070F238[i].dwTick = 0;
                }
            }
            sub_0044B880_SetValue(0);
            return 1;
        }
    }
    return 0;
}

struct D2ActiveRoomStrc;

// 0x0044D390
int __fastcall sub_0044D390_GetTextX(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - sub_00501820(wszText) / 2;
}

// 0x0044D3E0
void __cdecl sub_0044D3E0_DrawOverlayA()
{
    int nX = sub_0044D390_GetTextX(0x13EA, gnGlobal_0071146C / 2);
    int nY = 0x3E;
    if (gdwGlobal_007A04F4)
        nY = 0x64;
    sub_00502320(D2LANG_GetStringFromTblIndex(0x13EA), nX, nY, 4, 0);
    if (!gdwGlobal_007A04F4)
    {
        nX = sub_0044D390_GetTextX(0x13EB, gnGlobal_0071146C / 2);
        sub_00502320(D2LANG_GetStringFromTblIndex(0x13EB), nX, 0x6B, 4, 0);
    }
    nY = 0xE8;
    if (gdwGlobal_007A04F4)
        nY = 0x110;
    sub_00502320(D2LANG_GetStringFromTblIndex(0x13EC), sub_0044D390_GetTextX(0x13EC, gnGlobal_0071146C / 2), nY, 4, 0);
}

// 0x0044D550
int __cdecl sub_0044D550_Shutdown()
{
    sub_00475EF0_FreeLerpTables();
    sub_00468170_ShutdownCursor();
    sub_00451850_FreeMsgRecordChunks();
    sub_004794B0_FreeRosterLists();
    sub_00478A50_FreeRosterPets();
    sub_00451F20_RegisterWindowHandlers();
    return 1;
}

// 0x0044D580
void __fastcall sub_0044D580_ApplyConfig219(D2ConfigStrc* pConfig)
{
    if (pConfig->bFlag219)
        sub_00530F30_SetGlobal(0);
}

// 0x0044D5A0
void __fastcall sub_0044D5A0_ApplyConfigAct(D2ConfigStrc* pConfig)
{
    if (pConfig->dwAct)
    {
        D2_ASSERT(pConfig->dwAct < 6, 3366);
        D2_ASSERT(pConfig->dwAct > 0, 3367);
        GAME_SetGlobalAct(pConfig->dwAct - 1);
    }
}

// 0x0044D5F0
void __fastcall sub_0044D5F0_ApplyConfigGame(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szServerIP, "0"))
        SStrCopy(gszServerIP_0070EF20, pConfig->szServerIP, 0x7FFFFFFF);
    SStrCopy(gszGameName_007A05DC, pConfig->szGameName, 0x7FFFFFFF);
    gdwGlobal_007A0610 = pConfig->dwGameType;
    gwJoinID_007A0520 = pConfig->wJoinID;
    gdwGlobal_007A05C0 = pConfig->dwValue229;
}

// 0x0044D650
void __fastcall sub_0044D650_ApplyConfigAddr4F(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szBattleNetIP, "0"))
        SStrCopy(gszAddress_0070F028, pConfig->szServerIP, 0x7FFFFFFF);
}

// 0x0044D680
void __fastcall sub_0044D680_ApplyConfigAddr67(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szMCPIP, "0"))
        SStrCopy(gszAddress_0070F130, pConfig->szMCPIP, 0x7FFFFFFF);
}

// 0x0044D6B0
void __fastcall sub_0044D6B0_ApplyConfigClass(D2ConfigStrc* pConfig)
{
    if (pConfig->bAmazon) gbGlobal_007A0522 = 0;
    if (pConfig->bPaladin) gbGlobal_007A0522 = 3;
    if (pConfig->bSorceress) gbGlobal_007A0522 = 1;
    if (pConfig->bNecromancer) gbGlobal_007A0522 = 2;
    if (pConfig->bBarbarian) gbGlobal_007A0522 = 4;
    if (pConfig->bDruid) gbGlobal_007A0522 = 5;
    if (pConfig->bAssassin) gbGlobal_007A0522 = 6;
}

// 0x0044D890
void __fastcall sub_0044D890_ApplyConfigName(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szName, "0"))
    {
        int nLength = strlen(pConfig->szName);
        memset(gszCharName_007A05C4, 0, 0x10);
        ++nLength;
        if (nLength > 0x10)
        {
            nLength = 0x10;
        }
        strncpy(gszCharName_007A05C4, pConfig->szName, nLength);
    }
}

// 0x0044DCE0
extern "C" void __cdecl sub_0044DCE0_MouseExtTables_451E10()
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHandlers_0070F2C4, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHandlers_0070F348, 2);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gtHandlers_0070F360, 2);
}

// 0x0044DD20
extern "C" void __cdecl sub_0044DD20_MouseExtTables_451DB0()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHandlers_0070F2C4, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHandlers_0070F348, 2);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gtHandlers_0070F360, 2);
}

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0044DEF0
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

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

// 0x0044E380
void __fastcall sub_0044E380_ShowLoadingMessage(int nIndex)
{
    if (sub_0044E040_TimerRunning(&gtLoadingTimer_007A0684))
    {
        return;
    }

    if (gdwGlobal_007A0604)
    {
        return;
    }

    if (gdwGlobal_007A062C)
    {
        return;
    }

    gnLoadingIndex_007A05D4 = nIndex;
    if (nIndex >= 29)
    {
        gnLoadingIndex_007A05D4 = 9;
    }

    sub_00456300_CloseUIVars(1, 0);
    gtLoadingTimer_007A0684.dwStart = GetTickCount();
    gtLoadingTimer_007A0684.dwLength = 2500;
    gdwGlobal_007A0620 = 1;
    gdwGlobal_007A061C = 0;
    gdwGlobal_007A0618 = 0;
    sub_0044B880_SetValue(0);
}

// 0x0044E400
int __stdcall sub_0044E400_LoadingTimerCallback(void* pArg)
{
    int bResult = 0;
    if (sub_0044DFF0_TimerExpired(&gtLoadingTimer_007A0684))
    {
        sub_004547B0();
        bResult = 1;
    }
    else
    {
        sub_0044CB60_DrawLoadingText();
    }
    return bResult;
}

// 0x0044E460
void __stdcall sub_0044E460_ButtonMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nBottom = gnGlobal_00711470 - 0x50;
    int nLeft = gnGlobal_0071146C / 2 - 0x30;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gdwGlobal_007A0680 = 1;
        gdwGlobal_007A0650 = 0;
        gdwGlobal_007A0654 = 0;
        gdwGlobal_007A066C = 0;
        gdwGlobal_007A0670 = 0;
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

// 0x0044ED10
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

// 0x0044EE70
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0044EEC0
void __cdecl sub_0044EEC0_CheckConnectionTimeouts()
{
    if (!gdwGlobal_007A0610 || gdwGlobal_007A0610 == 1)
    {
        return;
    }

    unsigned long dwNow = GetTickCount();
    if (!sub_0052A640_IsConnected() && !gdwGlobal_007A0620 && gdwGlobal_007A061C)
    {
        sub_0044E380_ShowLoadingMessage(7);
    }

    if (gnValue_007A0624 && dwNow - gdwGlobal_007A0524 > 300000)
    {
        sub_0044E380_ShowLoadingMessage(7);
    }

    if (dwNow - gdwGlobal_007A05F8 > 30000 && !gdwGlobal_007A061C && !gdwGlobal_007A0620 && !gnValue_007A0624)
    {
        sub_0044E380_ShowLoadingMessage(6);
    }

    if (!gdwGlobal_007A0618 && !gdwGlobal_007A061C && !gdwGlobal_007A0620 && !gnValue_007A0624
        && (gdwGlobal_007A0610 == 9 || gdwGlobal_007A0610 == 7))
    {
        sub_0044E380_ShowLoadingMessage(6);
    }
}

int __fastcall sub_0044CCA0(unsigned int nValue, unsigned int nUnused, int nLimit)
{
    int nCount = 0;
    if (nLimit < 7)
        nCount = 1;
    if ((int)nValue > 1)
        nCount++;
    if ((int)nValue > 9)
        nCount++;
    if ((int)nValue > 0x13)
        nCount++;
    if ((int)nValue > 0x1D)
        nCount++;
    return nCount;
}

// 0x0044EFA0
int __stdcall sub_0044EFA0_GameFrame(int nUnused)
{
    int bFrame = 0;
    int bDrawn = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (gnGameType_007A0610 == 0 || gnGameType_007A0610 == 1)
    {
        if (WINDOW_GetState())
        {
            gdwLastFrame_007A0490 = GetTickCount();
            return 0;
        }

        if ((sub_00453A90_GetUIVarUnchecked(9) || sub_00453A90_GetUIVarUnchecked(11)) && pPlayer && sub_004646A0_GetPlayerRoom())
        {
            gdwLastFrame_007A0490 = GetTickCount();
            gpfnClientCallback_007A0484(0);
            sub_00482C20_Tick();
            return 0;
        }
    }

    sub_004519C0_ReplayRecords();
    if (gnGlobal_007A0650)
    {
        sub_0044C000_StartClick();
    }

    if (gnGlobal_007A0654)
    {
        sub_0044C2C0();
    }

    sub_0044CE90_UpdateKeyState();

    unsigned int dwNow = GetTickCount();
    if (gdwNextCheck_007A049C < dwNow)
    {
        sub_00477DD0();
        gdwLastCheck_007A04A0 = dwNow;
        if (gpConfig_007A0438->nFlags1EF & 4)
        {
            gdwNextCheck_007A049C = dwNow + 5000;
        }
        else
        {
            gdwNextCheck_007A049C = dwNow + 5000;
        }
    }

    gdwGlobal_007A048C = GetTickCount();
    if (!gdwLastFrame_007A0490)
    {
        gdwLastFrame_007A0490 = gdwGlobal_007A048C - gdwFrameTime_0070EF1C;
    }

    sub_00480320_CallHolderSlot3(gdwLastFrame_007A0490 - gdwGlobal_007A048C);
    sub_0044CCE0_AverageCounters();

    unsigned int nElapsed = gdwGlobal_007A048C - gdwLastFrame_007A0490;
    if (nElapsed >= gdwFrameTime_0070EF1C)
    {
        gdwLastFrame_007A0490 = gdwGlobal_007A048C;
        bFrame = 1;
        if (gdwGlobal_007A048C < gdwGlobal_007A04BC)
        {
            nElapsed -= gdwFrameTime_0070EF1C;
            unsigned int nLate = gdwFrameTime_0070EF1C - 1;
            if (nElapsed < nLate)
            {
                nLate = nElapsed;
            }

            gdwLastFrame_007A0490 = gdwGlobal_007A048C - nLate;
            gnSkipped_007A0704 = 0;
            nElapsed = gdwFrameTime_0070EF1C;
            gdwGlobal_007A04B8 = gdwGlobal_007A048C;
            gdwGlobal_007A04A8 = 25;
            gnGlobal_007A04B0 = 0;
            gnGlobal_007A04AC = 0;
            gnGlobal_007A04B4 = 0;
        }

        if (gdwGlobal_007A061C)
        {
            sub_00481600_RunPendingAction(pPlayer);
        }
    }

    int bReady = 0;
    if (gnGameType_007A0610 == 0)
    {
        sub_0052CFE0();
        bReady = GAME_UpdateGamesProgress(1);
        if (bReady)
        {
            sub_0052FD90(1, 0);
        }
    }
    else if (gnGameType_007A0610 == 1)
    {
        sub_0052CFE0();
        bReady = GAME_UpdateGamesProgress(1);
        sub_0052FD90(0, 0);
    }

    sub_0044C6E0_DrainPacketQueues();
    sub_0047BDF0_HandleBnetChatMessage();
    sub_00449B70_PollMcpConnection();
    sub_0044EEC0_CheckConnectionTimeouts();

    if (gdwGlobal_007A061C)
    {
        if (gnGameType_007A0610 != 0 && gnGameType_007A0610 != 1)
        {
            if (bFrame)
            {
                sub_0044C790_Update();
                gdwLastFrame_007A0490 += gdwFrameTime_0070EF1C - nElapsed;
                bDrawn = 1;
                const int nRate = gdwGlobal_007A04A8;
                const unsigned int nFrames = nElapsed / gdwFrameTime_0070EF1C;
                const unsigned int nRest = nElapsed % gdwFrameTime_0070EF1C;
                int nLimit = sub_0044CCA0(nFrames, nRest, nRate);
                if (nRate > 28)
                {
                    nLimit = 0;
                }

                if (gnSkipped_007A0704 > nLimit)
                {
                    gnSkipped_007A0704 = 0;
                }
            }
            else if (gdwGlobal_007A04A8 > 22)
            {
                gnSkipped_007A0704 = 0;
            }
        }
        else if (bReady)
        {
            sub_0044C790_Update();
            bDrawn = 1;
            if (nElapsed <= gdwFrameTime_0070EF1C)
            {
                gnSkipped_007A0704 = 0;
            }
            else if (nElapsed < 2 * gdwFrameTime_0070EF1C)
            {
                gdwLastFrame_007A0490 += gdwFrameTime_0070EF1C - nElapsed;
                gnSkipped_007A0704 = 0;
            }
            else
            {
                gnSkipped_007A0704 = gnSkipped_007A0704 <= 1;
                gdwLastFrame_007A0490 += 1 - gdwFrameTime_0070EF1C;
            }
        }
    }

    if (gdwGlobal_007A061C)
    {
        sub_00462920_ClearValue();
        sub_00467AC0_UpdateHoverUnit();
        if (sub_00514840_IsChannelStreaming())
        {
            sub_00515F50_FadeOutMaster(0xB4);
            sub_00514930_StopChannel();
            sub_00515CE0_SetMasterVolume(0xFF);
        }

        if (!gnSkipped_007A0704)
        {
            if (sub_004646A0_GetPlayerRoom())
            {
                gpfnClientCallback_007A0484(0);
                ++gnGlobal_007A0494;
                ++gnGlobal_007A04AC;
            }
        }
        else if (bFrame)
        {
            ++gnGlobal_007A04B4;
        }

        if (bDrawn)
        {
            sub_00482C20_Tick();
        }

        ++gnSkipped_007A0704;
    }
    else
    {
        WINDOW_GetState();
    }

    if (!gdwGlobal_007A0620)
    {
        return 0;
    }

    sub_00480340();
    sub_004FB480_SetActA(0);
    sub_00456300_CloseUIVars(1, 0);
    if (gnGameType_007A0610 == 0 || gnGameType_007A0610 == 1)
    {
        sub_0052E9C0();
    }

    if (gnGameType_007A0610 == 6 || gnGameType_007A0610 == 8)
    {
        EnterCriticalSection(&gCriticalSection_007A0468);
        gnGlobal_007A0648 = 1;
        LeaveCriticalSection(&gCriticalSection_007A0468);
        WaitForSingleObject(ghEvent_007A05BC, 10000);
        ghEvent_007A05BC = 0;
    }

    return 1;
}

#include "gen/data/Source/D2Client/GAME/Game_0044D080.inc"
