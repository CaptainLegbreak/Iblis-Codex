#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define STAT_LEVEL 12

struct D2SliderButtonStrc;
struct D2Record42Strc;
struct Unicode;
struct UnicodeChar;
struct D2QuestTextLineStrc;
struct D2QuestTextBufferStrc;
struct D2QuestPanelEntryStrc;
struct D2QuestSlotRectStrc;
struct D2AiControlStrc;
struct D2AiTickParamStrc;
struct D2HotkeyActionStrc;
struct D2MsgHandlerEntryStrc;
struct D2CharStatsTxt;
struct D2MonStatsTxt;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __cdecl sub_00463DF0();
unsigned char __cdecl sub_00483350_IsCinematicBusy();
void __cdecl sub_004A2300_UpdateQuestPage();
void __cdecl sub_004A23D0_LoadPanelCels();
int __stdcall sub_004A26B0_OpenPanel(int nArg);
int __cdecl sub_004A1760_Forward();
void __stdcall sub_004A3220(int nPage, int nArg);
void __fastcall sub_00478590(char nValue);

#pragma pack(push, 2)
struct D2SliderButtonStrc
{
    unsigned short nStringId;
    void (__cdecl* pfnClick)();
    int unk0x06;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2Record42Strc
{
    int aData[10];
    unsigned short wLast;
};

#pragma pack(pop)
extern unsigned char gbFlag_007BF2B0; // 0x007BF2B0
extern D2Record42Strc gtRecord_007BF355; // 0x007BF355
extern int gnPage_007C0255; // 0x007C0255
extern D2SliderButtonStrc gaSliderButtons_007246D8[3]; // 0x007246D8
extern int gaPressed_007C0288[7]; // 0x007C0288

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

struct D2QuestTextLineStrc
{
    unsigned short wLead[9];
    UnicodeChar wszText[300];
};

struct D2QuestTextBufferStrc
{
    unsigned char pHead[0x106];
    D2QuestTextLineStrc pLines[6];

    D2QuestTextBufferStrc();
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#pragma pack(push, 1)
struct D2QuestPanelEntryStrc
{
    int nQuestId;
    char unk0x004[0x25E - 0x004];
    unsigned short wTextId;
    unsigned char nSlot;
    char unk0x261[0x263 - 0x261];
    unsigned char bEnabled;
    char unk0x264[0x265 - 0x264];
    int bDone;
    char unk0x269[0x26A - 0x269];
};

#pragma pack(pop)

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
void __fastcall sub_004A3FE0(int nMode);
void __cdecl sub_0044DA70(); // 0x0044DA70
void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0
int __fastcall sub_004A27B0_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2QuestSlotRectStrc gaQuestSlots_00723EB0[]; // 0x00723EB0
extern int gnQuestCount_007BF2A0; // 0x007BF2A0
extern char gbGlobal_007BF2B0; // 0x007BF2B0
extern char gbGlobal_007BF2B3; // 0x007BF2B3
extern D2QuestPanelEntryStrc gaQuestEntries_007BF3AA[]; // 0x007BF3AA
extern char gbGlobal_007C025D; // 0x007C025D
extern char gbGlobal_007C025E; // 0x007C025E
extern char gbGlobal_007C025F; // 0x007C025F
extern char gbGlobal_007C0260; // 0x007C0260
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnEntryCount_007C0274; // 0x007C0274
int __cdecl sub_004A44C0_GetMaxFirstEntry(); // 0x004A44C0
extern int gnThumbScale_007C0278; // 0x007C0278
extern int gnFirstVisible_007C02AC; // 0x007C02AC
extern int gnThumbY_007C02CC; // 0x007C02CC

#pragma pack(push, 2)
struct D2ClientListEntryStrc
{
    int nId;
    unsigned char unk0x04[6];
};

#pragma pack(pop)

int __cdecl sub_0044DA30(); // 0x0044DA30
extern "C" void __cdecl sub_0044DCE0_MouseExtTables_451E10(); // 0x0044DCE0
extern "C" void __cdecl sub_0044DD20_MouseExtTables_451DB0(); // 0x0044DD20
void __cdecl sub_00466FE0(); // 0x00466FE0
void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70
void __cdecl sub_00469D20_SaveHotkeys(); // 0x00469D20
void __cdecl sub_004A43E0(); // 0x004A43E0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern int gnGlobal_007C0280; // 0x007C0280
extern int gnGlobal_007C02B0; // 0x007C02B0
extern int gnGlobal_007C02B8; // 0x007C02B8
extern int gnGlobal_007C0284;
int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90
int __stdcall sub_B05_Sink(int nA, int nB);

int __fastcall sub_0040C720_ReleaseReferences(int nArg); // 0x0040C720
void __fastcall sub_00469A60_ResetKeyConfig(int nArg); // 0x00469A60
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
extern "C" void __cdecl sub_00517ABB(void* pMemory); // 0x00517ABB

struct D2HotkeyActionStrc
{
    char unk0x00[0x0A];
    short nValue0A;
    char unk0x0C[0x0C];
    int nState18;
    int nState1C;
};

int __cdecl sub_0044DA30(); // 0x0044DA30
extern "C" void __fastcall sub_004A4500_SetActionValue(int nValue); // 0x004A4500
extern "C" int __stdcall sub_00420290_HandleMsg(void* pMessage); // 0x00420290

struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10
int __cdecl sub_004F59A0(); // 0x004F59A0
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072472C[]; // 0x0072472C
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724738[]; // 0x00724738
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724780[]; // 0x00724780
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072478C[]; // 0x0072478C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
int __cdecl sub_00466DC0(); // 0x00466DC0
int __cdecl sub_0044DCA0_GetGameType(); // 0x0044DCA0
int __cdecl sub_0044DCC0(); // 0x0044DCC0

static __declspec(noinline) int sub_004A47C0_GetButtonAt(int nX, int nY);

int gnGlobal_007BF298; // 0x007BF298

// 0x004A3FE0
void __fastcall sub_004A3FE0(int nMode)
{
    if (gnGlobal_007BF298 == 0)
    {
        if (GetTickCount() - gnGlobal_007C0259 < 250)
            return;
        if (sub_00463DF0())
            return;
        if (sub_00483350_IsCinematicBusy())
            return;
        if (sub_00455F20(15, 0, nMode) != 1)
            return;
        sub_004A23D0_LoadPanelCels();
        gnGlobal_007BF298 = 2;
        sub_004A2300_UpdateQuestPage();
        sub_004A3220(gnGlobal_007C0255, 0);
        sub_00478590(0x40);
        return;
    }

    if (gnGlobal_007BF298 == 1)
    {
        gnGlobal_007BF298 = 0;
        if (sub_00483350_IsCinematicBusy())
            return;
        if (sub_00455F20(15, 0, nMode) != 1)
            return;
        sub_004A23D0_LoadPanelCels();
        gnGlobal_007BF298 = 2;
        sub_004A2300_UpdateQuestPage();
        sub_004A3220(gnGlobal_007C0255, 0);
        sub_00478590(0x40);
        return;
    }

    sub_004A26B0_OpenPanel(nMode);
    gnGlobal_007C0259 = GetTickCount();
    sub_004A1760_Forward();
}

// 0x004A40D0
void __fastcall sub_004A40D0_SetRecord(const D2Record42Strc* pRecord)
{
    gtRecord_007BF355 = *pRecord;
    gbFlag_007BF2B0 = 0;
    if (!sub_00483350())
    {
        if (gnState_007BF298 == 2)
        {
            sub_004A23D0_LoadPanelCels();
        }
        sub_004A3220(gnPage_007C0255, 1);
    }
}

// 0x004A4A00
static __forceinline int sub_004A4A00_IsOnButton(int nX, int nY)
{
    return sub_004A47C0_GetButtonAt(nX, nY) != 3;
}

// 0x004A4A80
static __forceinline int sub_004A4A80_IsOnPressedButton(int nX, int nY)
{
    const int nButton = gnPressedButton_007C02B4;
    if (nButton != 3 && sub_004A47C0_GetButtonAt(nX, nY) == nButton)
    {
        return 1;
    }
    return 0;
}

// 0x004A4AA0
int __fastcall sub_004A4AA0_IsOnlyPressed(int nIndex)
{
    for (int i = 0; i < 7; i++)
    {
        if (gaPressed_007C0288[i] && i != nIndex)
        {
            return 0;
        }
    }
    return 1;
}

int __stdcall sub_M119_Emit_004A4A00(int nX, int nY)
{
    if (sub_004A4A00_IsOnButton(nX, nY))
    {
        return sub_004A4A80_IsOnPressedButton(nX + 1, nY);
    }
    return 2;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A4260
D2QuestTextBufferStrc::D2QuestTextBufferStrc()
{
}

char gbGlobal_007BF2B2; // 0x007BF2B2

char gbGlobal_007BF2B4; // 0x007BF2B4

static unsigned char sub_004A2610_HitTestButtonA(int nX, int nY)
{
    if (nX >= 0xE6 && nX <= 0xE6 + 0x1D && nY >= 0x187 && nY <= 0x187 + 0x20)
    {
        return 1;
    }
    return 0;
}

static int sub_004A2630_GetSlotAtPoint(int nX, int nY)
{
    int nCount = gnQuestCount_007BF2A0;
    D2_ASSERT((unsigned int)nCount <= 6, 0x738);
    for (int i = 0; i < nCount; ++i)
    {
        if (nX >= gaQuestSlots_00723EB0[i].nX && nX < gaQuestSlots_00723EB0[i].nX + 0x38 && nY >= gaQuestSlots_00723EB0[i].nY && nY < gaQuestSlots_00723EB0[i].nY + 0x34)
        {
            return i;
        }
    }
    return -1;
}

static unsigned char sub_004A2690_HitTestButtonB(int nX, int nY)
{
    if (nX >= 0x116 && nX <= 0x116 + 0x23 && nY >= 0x188 && nY <= 0x188 + 0x21)
    {
        return 1;
    }
    return 0;
}

static void sub_004A27D0_OpenQuestDescription(int nSlot)
{
    int nIndex = -1;
    for (int i = 0; i < gnQuestCount_007BF2A0; ++i)
    {
        if (gaQuestEntries_007BF3AA[i].nSlot == nSlot)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex == -1)
    {
        return;
    }
    unsigned short wTextId = gaQuestEntries_007BF3AA[nIndex].wTextId;
    if (wTextId == 0xE8C || wTextId == 0xE8D)
    {
        return;
    }
    sub_004A1320_OpenTextPanel(wTextId, 1, 0);
    sub_0049E7E0_SetTextCallback(sub_004A27B0_CloseQuestText, 0);
    gbGlobal_007BF2B3 = 1;
}

// 0x004A42A0
void __stdcall sub_004A42A0_OnLeftButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnGlobal_007A2858;
    int nY = D2_HIWORD(pMsg->lParam) + gnGlobal_007A285C;
    if (gbGlobal_007BF2B2)
    {
        if (sub_004A2690_HitTestButtonB(nX, nY)) sub_004A3FE0(0);
    }
    else if (!gbGlobal_007BF2B3)
    {
        if (gnIndex_007BF2B5 != -1)
        {
            int nSlot = sub_004A2630_GetSlotAtPoint(nX, nY);
            if (nSlot == gnIndex_007BF2B5)
            {
                ganPageSelection_007BF2BD[gnGlobal_007C0255] = nSlot;
                gnIndex_007BF2B9 = nSlot;
            }
        }
        else if (gbGlobal_007BF2B4 == 1)
        {
            if (sub_004A2610_HitTestButtonA(nX, nY) && gnIndex_007BF2B9 != -1)
            {
                sub_004A27D0_OpenQuestDescription(gnIndex_007BF2B9);
            }
        }
    }
    D2_RESET_QUEST_SELECTION();
    if (D2_LOWORD(pMsg->lParam) > gnGlobal_0071146C / 2) return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x2F) return;
    }
    else
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x31) return;
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

static __forceinline int sub_F08_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_F08_LinesTop()
{
    return sub_F08_ListTop() + 0x28;
}

static __forceinline int sub_F08_LinesBottom()
{
    return sub_F08_ListTop() + 0x136;
}

static __forceinline int sub_F08_VisibleLines()
{
    return (sub_F08_LinesBottom() - sub_F08_LinesTop()) / 0x12;
}

// 0x004A44C0
int __cdecl sub_004A44C0_GetMaxFirstEntry()
{
    int nCount = gnEntryCount_007C0274;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

static __forceinline int sub_I18_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_I18_TrackTop()
{
    return sub_I18_ListTop() + 0x2F;
}

static __forceinline int sub_I18_TrackBottom()
{
    return sub_I18_ListTop() + 0x125;
}

static __forceinline int sub_I18_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static __forceinline int sub_I18_TrackSpan()
{
    return sub_I18_TrackBottom() - sub_I18_TrackTop() - sub_I18_ThumbHeight();
}

// 0x004A4500
void __fastcall sub_004A4500_ScrollList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            sub_004A4500_ScrollList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            sub_004A4500_ScrollList(1);
        return;
    }

    const int nMax = sub_004A44C0_GetMaxFirstEntry();
    int nFirst = gnFirstVisible_007C02AC;
    if (nStep < 0)
    {
        const int nPrev = nFirst <= 0 ? nFirst : nFirst - 1;
        if (nPrev < 0)
            goto done;
        nFirst = nPrev;
    }
    else if (nStep > 0)
    {
        const int nNext = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNext > nMax)
            goto done;
        nFirst = nNext;
    }
    else
        goto done;
    gnFirstVisible_007C02AC = nFirst;
done:
    gnThumbY_007C02CC = sub_I18_TrackSpan() * nFirst / nMax + sub_I18_TrackTop();
}

int gnGlobal_007C0284; // 0x007C0284

int gaPressed_007C0288[7]; // 0x007C0288

int gnFirstVisible_007C02AC; // 0x007C02AC

// 0x004A4720
static int sub_004A4720_GetLineAt(int nY)
{
    int nIndex = gnFirstVisible_007C02AC;
    const int nCount = gnEntryCount_007C0274;
    int nLine = 0;
    if (nIndex < nCount)
    {
        int nLineY = (gnAutomapHeight_007A521C - 0x1A4) / 2 + 0x3A;
        do
        {
            if (nLine >= 0x0F)
                break;
            if (nY <= nLineY)
                return nIndex;
            ++nIndex;
            ++nLine;
            nLineY += 0x12;
        }
        while (nIndex < nCount);
        if (nIndex < nCount)
            return nIndex;
    }
    return nCount < 0 ? nCount : nCount - 1;
}

static int __stdcall sub_E10_IsAbovePanelLineCopy(int nY)
{
    int nHalf = (gnGlobal_0071146C - 620) / 2;
    return nY < nHalf + (gnGlobal_0071146C - nHalf * 2 - 49) / 3 * 2 + 18;
}

// 0x004A47C0
static __declspec(noinline) int sub_004A47C0_GetButtonAt(int nX, int nY)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        if (nX >= gaSliderButtons_007246D8[i].nLeft && nX <= gaSliderButtons_007246D8[i].nRight
            && nY >= gaSliderButtons_007246D8[i].nTop && nY <= gaSliderButtons_007246D8[i].nBottom)
            break;
    }
    return i;
}

// 0x004A47F0
static int sub_004A47F0_IsInList(int nX, int nY)
{
    const int nHalf = (gnGlobal_0071146C - 0x26C) / 2;
    const int nLeft = nHalf + 0x12;
    const int nRight = nHalf + (gnGlobal_0071146C - nHalf * 2 - 0x31) / 3 * 3 + 0x12;
    if (nX >= nLeft && nX <= nRight)
    {
        const int nTop = (gnAutomapHeight_007A521C - 0x1A4) / 2;
        if (nY >= nTop + 0x28 && nY <= nTop + 0x136)
            return 1;
    }
    return 0;
}

// 0x004A4A10
static int sub_004A4A10_IsOnSelectedLine(int nX, int nY)
{
    if (sub_004A47F0_IsInList(nX, nY) && sub_004A4720_GetLineAt(nY) == gnGlobal_007C02B0
        && sub_E10_IsAbovePanelLineCopy(nX) == gnGlobal_007246D4)
        return 1;
    return 0;
}

// 0x004A5200
void __fastcall sub_004A5200(int nArg)
{
    sub_004A43E0();
    if (nArg)
    {
        if (gnGlobal_007C02B8 == 0)
        {
            sub_00469D20_SaveHotkeys();
            sub_0046AA20(0, 0);
            sub_0044DCE0_MouseExtTables_451E10();
            sub_00467A70_RefreshHoverUnit(0);
        }
        gnFirstVisible_007C02AC = 0;
        gnGlobal_007C02B0 = 0;
    }
    else if (gnGlobal_007C02B8 == 0)
    {
        sub_0046AA20(1, 0);
        sub_0044DD20_MouseExtTables_451DB0();
        sub_00466FE0();
    }
    sub_004A5060();
}

// 0x004A5E60
static void sub_004A5E60_Release(int nX, int nY)
{
    if (gaPressed_007C0288[0])
    {
        if (sub_004A4A10_IsOnSelectedLine(nX, nY) && gpListEntries_00724264[gnGlobal_007C02B0].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    if (gaPressed_007C0288[6])
    {
        const int nButton = gnPressedButton_007C02B4;
        if (nButton != 3 && sub_004A47C0_GetButtonAt(nX, nY) == nButton)
        {
            gaSliderButtons_007246D8[nButton].pfnClick();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    gnGlobal_007C0284 = 0;
    gaPressed_007C0288[0] = 0;
    gaPressed_007C0288[1] = 0;
    gaPressed_007C0288[2] = 0;
    gaPressed_007C0288[3] = 0;
    gaPressed_007C0288[4] = 0;
    gaPressed_007C0288[5] = 0;
    gaPressed_007C0288[6] = 0;
}

// 0x004A5F10
void __stdcall sub_004A5F10_ButtonUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    sub_004A5E60_Release(nX, nY);
    gnGlobal_007C0280 = 0;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A4FA0
static int sub_004A4FA0_GetEntryState(int nIndex, int nFlag)
{
    if (nIndex == gnGlobal_007C02B0 && (gnGlobal_007C02B8 || nFlag == gnGlobal_007246D4))
    {
        return 3;
    }

    if (!sub_00469D90(gpListEntries_00724264[nIndex].nId, 1) && !sub_00469D90(gpListEntries_00724264[nIndex].nId, 0))
    {
        return 1;
    }

    return sub_00469D90(gpListEntries_00724264[nIndex].nId, nFlag) ? 4 : 5;
}

int sub_B05_Emit_004A4FA0(int* pIndex)
{
    int nA = sub_004A4FA0_GetEntryState(*pIndex, 1);
    int nB = sub_004A4FA0_GetEntryState(*pIndex, 0);
    return sub_B05_Sink(nA, nB);
}

void* gpCelFile_007C02BC; // 0x007C02BC

// 0x0040D530
int __cdecl sub_0040D530_Call0040C720()
{
    return sub_0040C720_ReleaseReferences(1);
}

// 0x004A5010
void __cdecl sub_004A5010_Call00469A60()
{
    sub_00469A60_ResetKeyConfig(0);
}

// 0x004A51E0
void __cdecl sub_004A51E0_FreeCelFile()
{
    if (gpCelFile_007C02BC)
    {
        sub_00478A00(gpCelFile_007C02BC);
        gpCelFile_007C02BC = 0;
    }
}

// 0x005EF1E0
int __fastcall sub_005EF1E0_BaalThroneGetAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}

// build: context sub_00600C60_CallFree
void __fastcall sub_00600C60_CallFree(void* pMemory)
{
    sub_00517ABB(pMemory);
}

// 0x004A59D0
int __stdcall sub_004A59D0_HandleHotkeyAction(D2HotkeyActionStrc* pAction)
{
    if (sub_0044DA30())
    {
        pAction->nState18 = 0;
        return (int)pAction;
    }

    int nDuration = pAction->nValue0A / 120;
    if (nDuration)
    {
        sub_004A4500_SetActionValue(-nDuration * 2);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pAction->nState18 = 1;
    pAction->nState1C = 0;
    return sub_00420290_HandleMsg(pAction);
}

int gnGlobal_007C02B8; // 0x007C02B8

// 0x004A5D00
void __cdecl sub_004A5D00_OpenSliderHandlers()
{
    gnGlobal_007C02B8 = 1;
    sub_00455AE0_CloseUIVar(0xB);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00724738, 6);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_00724780, 1);
    sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
}

// 0x004A5DE0
void __cdecl sub_004A5DE0_CloseSliderHandlers()
{
    if (gnGlobal_007C02B8)
    {
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724738, 6);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724780, 1);
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
        sub_00469D50();
        sub_0046AA20(1, 0);
        sub_0044DD20_MouseExtTables_451DB0();
        sub_00466FE0();
        gnGlobal_007C02B8 = 0;
    }
}

#include "gen/data/Source/D2Client/Unknown_004A3FE0.inc"
struct D2UnitStrc;

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x004A7300
static __declspec(noinline) int sub_004A7300_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord_Inl(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            nAttackRate += pCharStatsTxtRecord->dwToHitFactor;
        }
    }

    return nAttackRate;
}

int __stdcall sub_004A7340_GetPercentA(int nAttackRate)
{
    if (!nAttackRate)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nPercent = 100;
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 398);

    const int nMonsterId = sub_00466DC0();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    D2_ASSERT(pMonStatsTxtRecord, 403);

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 2, &monStatsInit);
    int nDefense = monStatsInit.nAC;
    if (pMonStatsTxtRecord->nAlign != 1 && !sub_0044DCC0() && sub_0044DCD0_GetDifficulty())
    {
        nDefense = nDefense * 10 / 12;
    }

    int nToHit = sub_004A7300_AddToHitFactor(pPlayer, nAttackRate);
    if (nDefense < 0)
    {
        nToHit -= nDefense;
        nDefense = 0;
    }

    if (nToHit < 0)
    {
        nDefense -= nToHit;
        nToHit = 0;
    }

    if (nToHit || nDefense)
    {
        nDefense += nToHit;
        nPercent = nToHit * 100 / nDefense;
    }

    const int nPlayerLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nChance = 2 * nPlayerLevel * nPercent / (pMonStatsTxtRecord->nLevel[nDifficulty] + nPlayerLevel);
    if (nChance < 5)
    {
        return 5;
    }
    if (nChance > 95)
    {
        return 95;
    }
    return nChance;
}
