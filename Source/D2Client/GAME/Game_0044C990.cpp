#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ActInfoStrc;
struct D2RectStrc;
struct Unicode;
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

struct D2LevelsTxt
{
    char unk0x000[0x218];
    unsigned int dwBlankScreen;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnLastViewX_0070F55C; // 0x0070F55C
extern int gnLastViewY_0070F558; // 0x0070F558
extern int gnViewDeltaX_007A0678; // 0x007A0678
extern int gnViewDeltaY_007A067C; // 0x007A067C
extern void* gpGlobal_007A0634; // 0x007A0634
void __fastcall sub_004547B0(); // 0x004547B0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
void __fastcall sub_00476D40_AdjustViewPos(int* pX, int* pY); // 0x00476D40
void __fastcall sub_004760A0_SetViewPos(D2ViewStrc* pView, int nX, int nY); // 0x004760A0
void __fastcall sub_00476140(D2ViewStrc* pView, int nArg); // 0x00476140
void __fastcall sub_00473F50(); // 0x00473F50
void __stdcall sub_0061C0B0(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0
void __stdcall D2GFX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x004F6430
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __fastcall sub_0045B440(); // 0x0045B440
int __cdecl sub_0045AE90(); // 0x0045AE90
void __fastcall sub_00476BC0(D2ViewStrc* pView); // 0x00476BC0
void __fastcall sub_00456EE0_DrawUIPanels(D2ViewStrc* pView); // 0x00456EE0
void __stdcall sub_004F98E0(); // 0x004F98E0
void __fastcall sub_00468820(int nArg1, int nArg2); // 0x00468820
void __fastcall sub_004684C0(); // 0x004684C0
void __fastcall sub_00477980(); // 0x00477980

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

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

struct Unicode
{
    unsigned short wChar;
};

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
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern unsigned short gawLoadingStrings_0070F384[]; // 0x0070F384
extern int gnLoadingIndex_007A05D4; // 0x007A05D4
extern D2ClientCharRecordStrc* gpCharRecord_007A0438; // 0x007A0438
extern int gnAutomapWidth_007A5220; // 0x007A5220
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

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

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

typedef char D2MsgHandlerEntrySize[(sizeof(D2MsgHandlerEntryStrc) == 12) ? 1 : -1];

extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F2C4[1]; // 0x0070F2C4
extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F348[2]; // 0x0070F348
extern "C" D2MsgHandlerEntryStrc gtHandlers_0070F360[2]; // 0x0070F360
extern "C" int __cdecl sub_004F59A0_GetHwnd(); // 0x004F59A0
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
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gdwGlobal_007A062C; // 0x007A062C
extern D2LoadingTimerStrc gtLoadingTimer_007A0684; // 0x007A0684
void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880
void __cdecl sub_0044CB60_DrawLoadingText(); // 0x0044CB60
int __fastcall sub_0044E040_TimerRunning(D2LoadingTimerStrc* pTimer); // 0x0044E040
void __fastcall sub_00456300(int nArg1, int nArg2); // 0x00456300

D2ViewStrc* gpView_007A0640; // 0x007A0640

static int GetRoomBlankScreen(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    D2LevelsTxt* pTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pTxt, 1502);
    return pTxt->dwBlankScreen;
}

static int gdwGlobal_007A0608; // 0x007A0608

static int gdwGlobal_007A0650; // 0x007A0650

static int gdwGlobal_007A0654; // 0x007A0654

static int gdwGlobal_007A066C; // 0x007A066C

static int gdwGlobal_007A0670; // 0x007A0670

static int gdwGlobal_007A0680; // 0x007A0680

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
    sub_00473F50();

    unsigned char nRed, nGreen, nBlue;
    sub_0061C0B0(gpGlobal_007A0634, &nRed, &nGreen, &nBlue);
    D2GFX_SetAmbientColor(nRed, nGreen, nBlue);

    if (!D2GFX_StartDraw(GetRoomBlankScreen(sub_004646A0_GetPlayerRoom()), 0, 0, 0))
        return;

    sub_004FB0D0();
    sub_0045B440();
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

#include "gen/data/Source/D2Client/GAME/Game_0044C990.inc"

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

unsigned long gdwLastTick_007A04A0; // 0x007A04A0

unsigned long gdwPing_007A04A4; // 0x007A04A4

unsigned long gdwPingSamples_007A04CC; // 0x007A04CC

unsigned long gdwPingAverage_007A04D0; // 0x007A04D0

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

// 0x0044DCE0
extern "C" void __cdecl sub_0044DCE0_MouseExtTables_451E10()
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0_GetHwnd(), gtHandlers_0070F2C4, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0_GetHwnd(), gtHandlers_0070F348, 2);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0_GetHwnd(), gtHandlers_0070F360, 2);
}

// 0x0044DD20
extern "C" void __cdecl sub_0044DD20_MouseExtTables_451DB0()
{
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0_GetHwnd(), gtHandlers_0070F2C4, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0_GetHwnd(), gtHandlers_0070F348, 2);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0_GetHwnd(), gtHandlers_0070F360, 2);
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

int gnLoadingIndex_007A05D4; // 0x007A05D4

int gdwGlobal_007A05F8; // 0x007A05F8

int gdwGlobal_007A0604; // 0x007A0604

int gdwGlobal_007A0620; // 0x007A0620

int gnValue_007A0624; // 0x007A0624

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

    sub_00456300(1, 0);
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
