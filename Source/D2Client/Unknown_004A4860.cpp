#include "D2Client.h"

#define STAT_STATPTS 4
#define STAT_NEWSKILLS 5
struct Unicode;
struct D2SliderButtonStrc;

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

struct D2ClientListEntryStrc
{
    int nId;
    unsigned char unk0x04[6];
};

#pragma pack(pop)

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
int __cdecl sub_004A44C0_GetMaxFirstEntry(); // 0x004A44C0
int __stdcall sub_004A4780_IsAbovePanelLine(int nX); // 0x004A4780
extern int gnGlobal_0071146C; // 0x0071146C
extern D2SliderButtonStrc gaSliderButtons_007246D8[3]; // 0x007246D8
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnEntryCount_007C0274; // 0x007C0274
extern int gnThumbScale_007C0278; // 0x007C0278
extern int gnThumbRange_007C027C; // 0x007C027C
extern int gnGlobal_007C0280; // 0x007C0280
extern int gnGlobal_007C0284; // 0x007C0284
extern int gaPressed_007C0288[7]; // 0x007C0288
extern int gnFirstVisible_007C02AC; // 0x007C02AC
extern int gnGlobal_007C02B0; // 0x007C02B0
extern int gnDragThumbY_007C02A4;
extern int gnDragMouseY_007C02A8;
extern unsigned long gdwLastTick_007C02C0;
extern int gnThumbY_007C02CC; // 0x007C02CC
void __cdecl sub_00469D40_SaveAndBindHotkeys(); // 0x00469D40
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200
void __fastcall sub_0047E090(int bSaveState, int nMenu); // 0x0047E090

struct Message { char pad[0x0C]; unsigned int lParam; char pad10[8]; int handled; int result; };

extern int global_00724728; // 0x00724728
int __cdecl sub_0044DA30(); // 0x0044DA30
int __fastcall sub_004B9A00(int, void*, int, int, int); // 0x004B9A00
int __stdcall sub_00420290(Message*); // 0x00420290

enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };

struct Unicode
{
    unsigned short wChar;
};

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
extern int gnGlobal_00711470; // 0x00711470
extern "C" int gnFlag_007C02EC; // 0x007C02EC

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        int wParam;
        struct
        {
            unsigned short wParamLow;
            unsigned short wParamHigh;
        };
    };
    union
    {
        int lParam;
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
    };
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_0045AE90(); // 0x0045AE90
void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
int __fastcall sub_004A6580_IsInPanelButton(int nMode, int nX, int nY); // 0x004A6580
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall sub_004A6630_IsInRightPanelButton(int nMode, int nX, int nY); // 0x004A6630
int __cdecl sub_004A6690_IsMouseOnRightButton(); // 0x004A6690

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
bool __stdcall sub_004A6A00_CheckUiVars(int nArg); // 0x004A6A00
bool __stdcall sub_004A6D50_CheckUiVars(int nArg); // 0x004A6D50
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
extern void* gpGlobal_007C02DC; // 0x007C02DC
extern void* gpGlobal_007C02E0; // 0x007C02E0
extern int gnGlobal_007C02E4; // 0x007C02E4
extern int gnGlobal_007C02E8; // 0x007C02E8

int gnDragThumbY_007C02A4; // 0x007C02A4

int gnDragMouseY_007C02A8; // 0x007C02A8

unsigned long gdwLastTick_007C02C0; // 0x007C02C0

int gnThumbY_007C02CC; // 0x007C02CC

static __forceinline int sub_F08_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_F08_PanelLeft()
{
    return (gnGlobal_0071146C - 0x26C) / 2;
}

static __forceinline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnGlobal_0071146C - sub_F08_PanelLeft() * 2);
}

static __forceinline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static __forceinline int sub_F08_TrackBottom()
{
    return sub_F08_ListTop() + 0x125;
}

static __forceinline int sub_F08_ThumbHeight()
{
    return gnThumbScale_007C0278 * 12;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_F08_TrackBottom() - sub_F08_TrackTop() - sub_F08_ThumbHeight();
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

static __forceinline int sub_F08_NoOtherPressed(int nIndex)
{
    for (int i = 0; i < 7; ++i)
    {
        if (gaPressed_007C0288[i] && i != nIndex)
            return 0;
    }
    return 1;
}

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
        const int nNew = nFirst <= 0 ? nFirst : nFirst - 1;
        if (nNew >= 0)
        {
            nFirst = nNew;
            gnFirstVisible_007C02AC = nFirst;
        }
    }
    else if (nStep > 0)
    {
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
        {
            nFirst = nNew;
            gnFirstVisible_007C02AC = nFirst;
        }
    }
    gnThumbY_007C02CC = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
}

void __fastcall sub_004A45C0_MoveSelection(int nStep)
{
    if (!nStep)
        return;
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            sub_004A45C0_MoveSelection(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            sub_004A45C0_MoveSelection(1);
        return;
    }

    const int nCount = gnEntryCount_007C0274;
    if (nStep < 0)
    {
        const int nOld = gnGlobal_007C02B0;
        const int nNew = nOld <= 0 ? nOld : nOld - 1;
        if (nNew >= 0)
            gnGlobal_007C02B0 = nNew;
    }
    else if (nStep > 0 && gnGlobal_007C02B0 < nCount)
    {
        const int nNew = gnGlobal_007C02B0 + 1;
        if (nNew < nCount)
            gnGlobal_007C02B0 = nNew;
    }

    const int nSelected = gnGlobal_007C02B0;
    int nFirst = gnFirstVisible_007C02AC;
    if (nSelected < nFirst)
    {
        const int nTrackTop = sub_F08_TrackTop();
        gnFirstVisible_007C02AC = nSelected;
        gnThumbY_007C02CC = nSelected * sub_F08_TrackSpan() / sub_004A44C0_GetMaxFirstEntry() + nTrackTop;
        return;
    }

    for (;;)
    {
        int nLast = nFirst;
        for (int nLine = 0; nLast < nCount && nLine < 0x0F; ++nLine)
            ++nLast;
        if (gnGlobal_007C02B0 < nLast)
            break;

        const int nMax = sub_004A44C0_GetMaxFirstEntry();
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
            nFirst = nNew;
        gnThumbY_007C02CC = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
    }
    gnFirstVisible_007C02AC = nFirst;
}

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

// 0x004A4860
static __declspec(noinline) int sub_004A4860_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

// 0x004A48B0
static __declspec(noinline) int sub_004A48B0_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

// 0x004A4900
static __declspec(noinline) int sub_004A4900_IsAboveThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY > sub_F08_ListTop() + 0x2F && nY < gnThumbY_007C02CC)
            return 1;
    }
    return 0;
}

// 0x004A4950
static __declspec(noinline) int sub_004A4950_IsOnThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY >= gnThumbY_007C02CC && nY <= gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A49A0
static __declspec(noinline) int sub_004A49A0_IsBelowThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY < sub_F08_ListTop() + 0x125 && nY > gnThumbY_007C02CC + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

void __stdcall sub_004A4AD0_Press(int nX, int nY)
{
    gnPressedButton_007C02B4 = 3;
    if (gnGlobal_007C0284)
        return;

    const int bInList = sub_004A47F0_IsInList(nX, nY);
    const int bUp = sub_004A4860_IsOnUpArrow(nX, nY);
    const int bDown = sub_004A48B0_IsOnDownArrow(nX, nY);
    const int bPageUp = sub_004A4900_IsAboveThumb(nX, nY);
    const int bThumb = sub_004A4950_IsOnThumb(nX, nY);
    const int bPageDown = sub_004A49A0_IsBelowThumb(nX, nY);
    const int bButton = sub_004A47C0_GetButtonAt(nX, nY) != 3;

    if (sub_F08_NoOtherPressed(7) && !bInList && !bUp && !bDown && !bPageUp && !bThumb && !bPageDown && !bButton)
    {
        gnGlobal_007C0284 = gnGlobal_007C0280;
        return;
    }

    if (sub_F08_NoOtherPressed(0) && (bInList || gaPressed_007C0288[0]))
    {
        gaPressed_007C0288[0] = gnGlobal_007C0280;
        if (gnGlobal_007C0280)
        {
            const int nTop = sub_F08_ListTop();
            if (nY < nTop + 0x28)
                sub_004A45C0_MoveSelection(-1);
            if (nY > nTop + 0x136)
                sub_004A45C0_MoveSelection(1);

            const int nOldD4 = gnGlobal_007246D4;
            const int nOldSelected = gnGlobal_007C02B0;
            const int nLine = sub_004A4720_GetLineAt(nY);
            gnGlobal_007C02B0 = nLine;
            gnGlobal_007246D4 = sub_004A4780_IsAbovePanelLine(nX);
            if (gpListEntries_00724264[nLine].nId == 0x39)
            {
                gnGlobal_007246D4 = nOldD4;
                gnGlobal_007C02B0 = nOldSelected;
            }
        }
    }

    if (sub_F08_NoOtherPressed(1) && bUp)
    {
        gaPressed_007C0288[1] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(-1);
        }
    }

    if (sub_F08_NoOtherPressed(2) && bDown)
    {
        gaPressed_007C0288[2] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(1);
        }
    }

    if (sub_F08_NoOtherPressed(3) && bPageUp)
    {
        gaPressed_007C0288[3] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(1 - sub_F08_VisibleLines());
        }
    }

    if (sub_F08_NoOtherPressed(4) && (bThumb || gaPressed_007C0288[4]))
    {
        if (bThumb && !gaPressed_007C0288[4] && gnGlobal_007C0280)
        {
            gnDragThumbY_007C02A4 = gnThumbY_007C02CC;
            gnDragMouseY_007C02A8 = nY;
        }
        gaPressed_007C0288[4] = gnGlobal_007C0280;
        if (gnGlobal_007C0280)
        {
            const int nTop = sub_F08_ListTop();
            sub_004A4500_ScrollList((gnDragThumbY_007C02A4 - nTop - gnDragMouseY_007C02A8 + nY - 0x2F)
                * (gnThumbRange_007C027C + 1) / sub_F08_TrackSpan() - gnFirstVisible_007C02AC);
        }
    }

    if (sub_F08_NoOtherPressed(5) && bPageDown)
    {
        gaPressed_007C0288[5] = gnGlobal_007C0280;
        if (gnGlobal_007C0280 && GetTickCount() > gdwLastTick_007C02C0 + 0x32)
        {
            gdwLastTick_007C02C0 = GetTickCount();
            sub_004A4500_ScrollList(sub_F08_VisibleLines() - 1);
        }
    }

    if (sub_F08_NoOtherPressed(6) && bButton)
    {
        gaPressed_007C0288[6] = gnGlobal_007C0280;
        gnPressedButton_007C02B4 = sub_004A47C0_GetButtonAt(nX, nY);
    }
}

// 0x004A5020
void __cdecl sub_004A5020_AcceptKeyConfig()
{
    sub_00469D40_SaveAndBindHotkeys();
    sub_00455F20(11, 1, 0);
    sub_0047E200_CloseMenus(1);
}

// 0x004A5040
void __cdecl sub_004A5040_CancelKeyConfig()
{
    sub_00469D50();
    sub_00455F20(11, 1, 0);
    sub_0047E090(0, 1);
}

// 0x004A5C70
void __stdcall sub_004A5C70(Message* message)
{
    if (sub_0044DA30()) { message->handled = 0; return; }
    if (global_00724728) {
        if (!(message->lParam & REPEAT_MASK)) {
            sub_00469D50();
            sub_00455F20(UI_VARIABLE, 1, 0);
            sub_0047E090(0, 1);
            sub_004B9A00(1, 0, 0, 0, 0);
        }
    } else global_00724728 = 1;
    message->handled = 1;
    message->result = 0;
    sub_00420290(message);
}

void* gpGlobal_007C02DC; // 0x007C02DC

void* gpGlobal_007C02E0; // 0x007C02E0

// 0x004A6460
void __cdecl sub_004A6460_LoadLevelCels()
{
    gpGlobal_007C02DC = sub_004520C0_LoadUiCelFile("Panel\\Level");
    gpGlobal_007C02E0 = sub_004520C0_LoadUiCelFile("Panel\\Levelsocket");
}

// 0x004A6480
void __cdecl sub_004A6480_FreeLevelCels()
{
    if (gpGlobal_007C02DC)
    {
        sub_00478A00(gpGlobal_007C02DC);
        gpGlobal_007C02DC = 0;
    }
    if (gpGlobal_007C02E0)
    {
        sub_00478A00(gpGlobal_007C02E0);
        gpGlobal_007C02E0 = 0;
    }
}

// 0x004A64C0
void __cdecl sub_004A64C0_UpdateStatButtons()
{
    if (sub_004538D0(0xB))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (sub_004538D0(6))
    {
        if (!STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
            sub_00455F20(6, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0) && !sub_004538D0(2))
            sub_00455F20(6, 0, 0);
    }
    if (sub_004538D0(7))
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) <= 0)
            sub_00455F20(7, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) > 0 && !sub_004538D0(4))
            sub_00455F20(7, 0, 0);
    }
}

// 0x004A65E0
int __cdecl sub_004A65E0_IsMouseOnLeftButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnGlobal_0071146C / 2 - 0xC2 && nX < gnGlobal_0071146C / 2 - 0xA0 && nY > gnGlobal_00711470 - 0x2A && nY < gnGlobal_00711470 - 8)
        return 1;
    return 0;
}

// 0x004A6690
int __cdecl sub_004A6690_IsMouseOnRightButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnGlobal_0071146C / 2 + 0xA3 && nX < gnGlobal_0071146C / 2 + 0xC5 && nY > gnGlobal_00711470 - 0x2A && nY < gnGlobal_00711470 - 8)
        return 1;
    return 0;
}

// 0x004A7660
int __fastcall sub_004A7660_SplitAtNewline(Unicode* wszText, Unicode** ppNext)
{
    Unicode* pChar = wszText;
    *ppNext = 0;
    int nLen = sub_00526800(wszText);
    int i = 0;
    while (pChar->wChar)
    {
        if (pChar->wChar == '\n')
        {
            wszText[i].wChar = 0;
            if (i >= nLen)
                return 0;
            *ppNext = pChar + 1;
            return 1;
        }
        ++pChar;
        ++i;
    }
    return 0;
}

// 0x004A7A90
void __cdecl sub_004A7A90_SetFlag()
{
    gnFlag_007C02EC = 1;
}

// 0x004A7AD0
void __cdecl sub_004A7AD0()
{
}

int gnGlobal_007C02E4; // 0x007C02E4

static int __fastcall CLIENT_HitPanelButton(int nMode, int nX, int nY)
{
    return sub_004A6580_IsInPanelButton(nMode, nX, nY);
}

// 0x004A6840
void __stdcall sub_004A6840_LeftButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && sub_004538D0(9))
    {
        return;
    }

    sub_00467FA0_MsgHandler(pMsg);
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E4 && CLIENT_HitPanelButton(sub_0045AE90(), nX, nY))
        {
            gnGlobal_007C02E4 = 0;
            sub_00455F20(6, 1, 0);
            sub_00455F20(2, 0, 0);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (gnGlobal_007C02E4 && sub_004A65E0_IsInLeftButton())
        {
            gnGlobal_007C02E4 = 0;
            sub_00455F20(2, 0, 0);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }

    gnGlobal_007C02E4 = 0;
    pMsg->bUseResult = 0;
}

int gnGlobal_007C02E8; // 0x007C02E8

static int __fastcall CLIENT_HitRightPanelButton(int nMode, int nX, int nY)
{
    return sub_004A6630_IsInRightPanelButton(nMode, nX, nY);
}

// 0x004A6920
void __stdcall sub_004A6920_RightButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && sub_004538D0(9))
    {
        return;
    }

    sub_00467FA0_MsgHandler(pMsg);
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E8 && CLIENT_HitRightPanelButton(sub_0045AE90(), nX, nY))
        {
            gnGlobal_007C02E8 = 0;
            sub_00455F20(7, 1, 0);
            sub_00455F20(4, 0, 0);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (gnGlobal_007C02E8 && sub_004A6690_IsMouseOnRightButton())
        {
            gnGlobal_007C02E8 = 0;
            sub_00455F20(4, 0, 0);
            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }

    gnGlobal_007C02E8 = 0;
    pMsg->bUseResult = 0;
}

// 0x004A6A00
bool __stdcall sub_004A6A00_CheckUiVars(int nArg)
{
    if (nArg == 3)
        return true;
    if (sub_004538D0(2))
        return true;
    if (sub_004538D0(0x16) && sub_004538D0(1))
        return true;
    if (sub_004538D0(0x16) && sub_004538D0(4))
        return true;
    return (bool)sub_004538D0(0xC);
}

// 0x004A6D50
bool __stdcall sub_004A6D50_CheckUiVars(int nArg)
{
    if (nArg == 3)
        return true;
    if (sub_004538D0(4))
        return true;
    if (sub_004538D0(0xC))
        return true;
    if (sub_004538D0(0x16) && sub_004538D0(1))
        return true;
    return false;
}

// 0x004A6B30
void __cdecl sub_004A6B30_DrawLeftPanelButtons()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && sub_004A6A00_CheckUiVars(nBorder))
    {
        gnGlobal_007C02E4 = 0;
        return;
    }

    int nX;
    if (nBorder == 2)
        nX = gnGlobal_0071146C / 2 + 0x28;
    else
        nX = 0x28;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02E0;
    tContext.nFrame = 0;
    const int nCelWidth = sub_006018C0(CelGetHandle(&tContext));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xF92), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
        sub_004F6480(&tContext, nX, gnGlobal_00711470 - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E4 && sub_004A6580_IsInPanelButton(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gnGlobal_007C02E4 && sub_004A65E0_IsInLeftButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    sub_006018C0(CelGetHandle(&tContext));
    sub_00501820(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A65E0_IsInLeftButton() && !sub_004538D0(9))
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF92), gnGlobal_0071146C / 2 - 0xB3, gnGlobal_00711470 - 0x32, 0, 1);
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xC2, gnGlobal_00711470 - 8, -1, 5, 0);
}

// 0x004A6E60
void __cdecl sub_004A6E60_DrawRightPanelButtons()
{
    const int nBorder = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2 && sub_004A6D50_CheckUiVars(nBorder))
    {
        gnGlobal_007C02E8 = 0;
        return;
    }

    int nX;
    if (nBorder == 1)
        nX = gnGlobal_0071146C - gnGlobal_0071146C / 2 - 0x49;
    else
        nX = gnGlobal_0071146C - 0x49;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02E0;
    tContext.nFrame = 0;
    const int nCelWidth = sub_006018C0(CelGetHandle(&tContext));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_00502320(D2LANG_GetStringFromTblIndex(0xF93), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnGlobal_00711470 - 0x8E, 0, 0);
        sub_004F6480(&tContext, nX, gnGlobal_00711470 - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gnGlobal_007C02E8 && sub_004A6630_IsInPanelButton2(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gnGlobal_007C02E8 && sub_004A6690_IsInRightButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    sub_006018C0(CelGetHandle(&tContext));
    sub_00501820(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        sub_004F6480(&tContext, nX + 3, gnGlobal_00711470 - 0x6D, -1, 5, 0);
        return;
    }

    if (sub_004A6690_IsInRightButton() && !sub_004538D0(9))
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF93), gnGlobal_0071146C / 2 + 0xB2, gnGlobal_00711470 - 0x32, 0, 1);
    sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0xA3, gnGlobal_00711470 - 8, -1, 5, 0);
}
