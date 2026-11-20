#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2SliderButtonStrc;
struct Unicode;
struct D2MonStatsTxt;

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
int __cdecl sub_004A44C0_GetMaxFirstEntry();
int __stdcall sub_004A4780_IsAbovePanelLine(int nX); // 0x004A4780
extern int gnGlobal_0071146C; // 0x0071146C
extern D2SliderButtonStrc gaSliderButtons_007246D8[3]; // 0x007246D8
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnThumbScale_007C0278; // 0x007C0278
extern int gnThumbRange_007C027C; // 0x007C027C
extern int gnGlobal_007C0280; // 0x007C0280
extern int gnGlobal_007C0284; // 0x007C0284
extern int gaPressed_007C0288[7]; // 0x007C0288
extern int gnDragThumbY_007C02A4; // 0x007C02A4
extern int gnDragMouseY_007C02A8; // 0x007C02A8
extern unsigned long gdwLastTick_007C02C0; // 0x007C02C0

struct SMSGHANDLER_PARAMS { char unknown0[12]; unsigned short x, y; char unknown10[8]; int handled, result; };

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall sub_004538D0(unsigned int); // 0x004538D0
int __cdecl sub_0045AE90(); // 0x0045AE90
int __fastcall sub_004A6580_IsInPanelButton(int, int, int); // 0x004A6580
int __cdecl sub_004A65E0_IsMouseOnLeftButton(); // 0x004A65E0
void __fastcall sub_004B9A00_ChangeUiState(int, int, int, int, int); // 0x004B9A00
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS*); // 0x00467F20
int __cdecl sub_004B3470_IsNpcQuestActive(); // 0x004B3470
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS*); // 0x00420290
extern int gnPressed_007C02E4; // 0x007C02E4
int __fastcall sub_004A6630_IsInRightPanelButton(int, int, int); // 0x004A6630
int __cdecl sub_004A6690_IsMouseOnRightButton(); // 0x004A6690


int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
extern int gnPressed_007C02E8; // 0x007C02E8

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern int gnGlobal_00711470; // 0x00711470
int __cdecl sub_0044DCC0(); // 0x0044DCC0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __cdecl sub_00466DD0(); // 0x00466DD0
void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int nArg); // 0x00622720
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380

static int gnEntryCount_007C0274; // 0x007C0274

static int gnFirstVisible_007C02AC; // 0x007C02AC

static int gnGlobal_007C02B0; // 0x007C02B0

static int gnThumbY_007C02CC; // 0x007C02CC

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

// 0x004A45C0
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

// 0x004A66E0
void __stdcall sub_004A66E0_HandleLeftButton(SMSGHANDLER_PARAMS* message)
{
    int x = message->x;
    int y = message->y;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && sub_004538D0(nResolution + 7))
    {
        return;
    }
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (sub_004A6580_IsInPanelButton(border, x, y))
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (sub_004A65E0_IsMouseOnLeftButton())
        {
            gnPressed_007C02E4 = 1;
            sub_004B9A00_ChangeUiState(4, 0, 0, 0, 0);
            sub_00467F20_MsgHandler(message);
            if (border == 2 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->handled = 0;
}

static __forceinline void MarkRightButtonPressed()
{
    gnPressed_007C02E8 = 1;
    const int nClickSound = 4;
    sub_004B9A00(nClickSound, 0, 0, 0, 0);
}

// 0x004A6790
void __stdcall sub_004A6790_HandleRightButton(SMSGHANDLER_PARAMS* message)
{
    int x = message->x;
    int y = message->y;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && sub_004538D0(nResolution + 7))
        return;
    int border = sub_0045AE90();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (sub_004A6630_IsInRightPanelButton(border, x, y))
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (sub_004A6690_IsMouseOnRightButton())
        {
            MarkRightButtonPressed();
            sub_00467F20_MsgHandler(message);
            if (border == 1 && sub_004B3470_IsNpcQuestActive()) return;
            message->handled = 1;
            message->result = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->handled = 0;
}

unsigned char gnTextColor_007C02F8; // 0x007C02F8

static int sub_004A70C0_GetWieldedTypeStatMax(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightItem = 0;
    D2UnitStrc* pLeftItem = 0;
    if (pInventory)
    {
        pRightItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        pLeftItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    }

    D2StatStrc aStats[0x20];
    int i = 0;
    const int nCount = STATLIST_CopyStats(pUnit, 0x15C, aStats, 0x20);
    int nBest = 0;
    for (; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0 || ((pLeftItem && ITEMSIsA(pLeftItem, nItemType)) || (pRightItem && ITEMSIsA(pRightItem, nItemType))) && nValue > nBest)
        {
            nBest = nValue;
        }
    }

    return nBest;
}

// 0x004A7180
static void sub_004A7180_DrawHoverLevelText(int nX, int nY, int nValue)
{
    if (nValue < 5)
    {
        nValue = 5;
    }
    else if (nValue > 0x5F)
    {
        nValue = 0x5F;
    }

    Unicode wszText[0x80];
    if (nX < gnGlobal_007A2858 + 0xAD || nX > gnGlobal_007A2858 + 0x137
        || nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x11E || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x10B)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    int nLevel = UNITS_GetBlockRate(pPlayer, sub_0044DCC0());
    if (nLevel <= 0)
    {
        nLevel = sub_004A70C0_GetWieldedTypeStatMax(pPlayer);
        if (nLevel > 0)
        {
            int nWeaponClass;
            COMPOSIT_GetWeaponClassId(pPlayer, pPlayer->pInventory, &nWeaponClass, -1, 1);
            if (nWeaponClass != 0x0D)
            {
                nLevel = 0;
            }
        }
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(sub_00466DD0());
    D2_ASSERT(pMonStatsTxtRecord, 0x15C);

    if (nLevel)
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2779), nLevel, nValue, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }
    else
    {
        sub_005269D0(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2778), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }

    D2Win_10132(wszText, gnGlobal_007A2858 + 0x8B, gnGlobal_00711470 + gnGlobal_007A285C - 0x13B, gnTextColor_007C02F8, 2, 0);
}

void __stdcall sub_I10_Emit_004A7180(int nX, int nY, int nValue)
{
    sub_004A7180_DrawHoverLevelText(nX, nY, nValue);
}
