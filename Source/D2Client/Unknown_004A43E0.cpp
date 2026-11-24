#include "D2Client.h"

#include "D2Structs.h"

#include "D2ClientTypes.h"

#include "D2Unicode.h"

#include "D2StormTypes.h"

#include "D2MonsterIds.h"

#include "D2Primitives.h"

#include "D2Path.h"

#include "D2ClientUi.h"

#include "D2CelContext.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2GameTypes.h"

#include "D2LevelTxt.h"

#include "D2StatIds.h"

#include "D2MsgRecord.h"

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

#pragma pack(push, 2)

#pragma pack(pop)

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall AUTOMAP_UnregisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

#pragma pack(push, 2)

#pragma pack(pop)

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

extern int gnScreenWidth; // 0x0071146C

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

#pragma pack(push, 1)

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#pragma pack(push, 2)

#pragma pack(pop)

#pragma pack(push, 2)

#pragma pack(pop)

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

#pragma pack(push, 2)

#pragma pack(pop)

#define UNIT_PLAYER 0

#define STAT_LEVEL 12

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

#pragma pack(pop)

extern D2SliderButtonStrc gaKeyConfigButtons[3]; // 0x007246D8

int gaPressed[7]; // 0x007C0288

#pragma pack(push, 1)

#pragma pack(pop)

static int gnKeyConfigEntryCount; // 0x007C0274

int gnKeyConfigThumbScale; // 0x007C0278

static int gnKeyConfigFirstVisible; // 0x007C02AC

extern int gnAutomapHeight; // 0x007A521C

// build: symbol ??__EgnKeyConfigThumbY@@YAXXZ 0x006CACE0
int gnKeyConfigThumbY = (gnAutomapHeight - 420) / 2 + 47; // 0x007C02CC

#pragma pack(push, 2)

struct D2ClientListEntryStrc
{
    int nId;
    unsigned short nString;
    unsigned char unk0x06[4];
};

#pragma pack(pop)

int __cdecl GAME_IsExitPending(); // 0x0044DA30

extern "C" void __cdecl GAME_UnregisterMouseHandlers(); // 0x0044DCE0

extern "C" void __cdecl GAME_RegisterMouseHandlers(); // 0x0044DD20

void __cdecl sub_00466FE0(); // 0x00466FE0

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

void __cdecl CMDTBL_SaveHotkeys(); // 0x00469D20

extern int gbRedraw; // 0x007C0280

extern int gnKeyConfigSelected; // 0x007C02B0

extern int gbKeyCaptureActive; // 0x007C02B8

int gbKeyConfigPressRepeat; // 0x007C0284

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

void __fastcall CMDTBL_ResetKeyConfig(int nArg); // 0x00469A60

struct D2HotkeyActionStrc
{
    char unk0x00[0x0A];
    short nValue0A;
    char unk0x0C[0x0C];
    int nState18;
    int nState1C;
};

extern "C" int __stdcall sub_00420290_HandleMsg(void* pMessage); // 0x00420290

extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[]; // 0x0072472C

extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[]; // 0x00724738

extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[]; // 0x00724780

extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[]; // 0x0072478C

#pragma pack(push, 2)

#pragma pack(pop)

int __stdcall TEXT_IsAbovePanelLine(int nX); // 0x004A4780

int gnThumbRange; // 0x007C027C

int gnDragThumbY; // 0x007C02A4

int gnDragMouseY; // 0x007C02A8

unsigned long gdwKeyConfigRepeatTick; // 0x007C02C0

#define STAT_STATPTS 4

#define STAT_NEWSKILLS 5

#pragma pack(push, 2)

#pragma pack(pop)

void __cdecl CMDTBL_SaveAndBindHotkeys(); // 0x00469D40

void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200

void __fastcall WARDENCLIENT_ToggleEscMenuUIState(int bSaveState, int nMenu); // 0x0047E090

extern int global_00724728; // 0x00724728

enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

extern void* gpKeyConfigSliderCel; // 0x007C02BC

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#pragma pack(push, 2)

#pragma pack(pop)

static int TEXT_IsOnKeyConfigButton(int nX, int nY);

static int TEXT_IsOnPressedButton(int nX, int nY);

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

#pragma pack(push, 2)

#pragma pack(pop)

#pragma pack(push, 2)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 2)

#pragma pack(pop)

#define gbUpPressed_007C028C (gaPressed[1])

#define gbDownPressed_007C0290 (gaPressed[2])

#define KEYCFG_X ((gnScreenWidth_0071146C - 620) / 2)

#define KEYCFG_Y ((gnAutomapHeight - 420) / 2)

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 2)

struct D2KeyConfigButtonStrc
{
    unsigned short nString;
    unsigned char unk0x02[4];
    int nColor;
    int nX;
    unsigned char unk0x0E[0x0C];
};

#pragma pack(pop)

void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

extern D2KeyConfigButtonStrc gaButtons_007246D8[3]; // 0x007246D8

extern unsigned int gdwMessageTick_007C02C8; // 0x007C02C8

int gnKeyConfigPressedButton; // 0x007C02B4

int gnMessage; // 0x007C02C4

unsigned int gnBlink; // 0x007C02D0

int gnLastMouseY; // 0x007C02D4

int gnLastMouseX; // 0x007C02D8

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 2)

#pragma pack(pop)

extern D2ClientListEntryStrc gaKeyConfigEntries[]; // 0x00724268

extern D2ClientListEntryStrc gaKeyConfigEntriesExp[]; // 0x00724468

#pragma pack(push, 2)

#pragma pack(pop)

#pragma pack(push, 2)

#pragma pack(pop)

static inline int sub_F08_ListTop()
{
    return (gnAutomapHeight - 0x1A4) / 2;
}

static inline int sub_KEYCFG_Rows()
{
    return ((sub_F08_ListTop() + 0x16C) - (sub_F08_ListTop() + 0x28)) / 0x12;
}

static inline int sub_KEYCFG_TrackCels()
{
    return ((KEYCFG_Y + 0x131) - (KEYCFG_Y + 0x2F)) / 0x0C;
}

static inline int sub_KEYCFG_RowTrackCels()
{
    return (sub_KEYCFG_Rows() * 0x12 - 0x4E) / 0x0C + 1;
}

static inline int sub_KEYCFG_VisibleLines()
{
    return ((KEYCFG_Y + 0x136) - (KEYCFG_Y + 0x28)) / 0x12;
}

static inline int sub_F08_VisibleLines()
{
    return sub_KEYCFG_Rows() - 3;
}

static inline int sub_I18_ListTop()
{
    return (gnAutomapHeight - 0x1A4) / 2;
}

static inline int sub_I18_TrackTop()
{
    return sub_I18_ListTop() + 0x2F;
}

static inline int sub_I18_TrackBottom()
{
    return sub_I18_ListTop() + 0x125;
}

static inline int sub_I18_ThumbHeight()
{
    return gnKeyConfigThumbScale * 12;
}

static inline int sub_I18_TrackSpan()
{
    return sub_I18_TrackBottom() - sub_I18_TrackTop() - sub_I18_ThumbHeight();
}

static inline int sub_F08_PanelLeft()
{
    return (gnScreenWidth - 0x26C) / 2;
}

static inline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnScreenWidth - sub_F08_PanelLeft() * 2);
}

static inline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static inline int sub_F08_ThumbHeight()
{
    return gnKeyConfigThumbScale * 12;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_KEYCFG_Rows() * 0x12 - sub_F08_ThumbHeight() - 0x4E;
}

static inline int sub_F08_NoOtherPressed(int nIndex)
{
    for (int i = 0; i < 7; ++i)
    {
        if (gaPressed[i] && i != nIndex)
            return 0;
    }
    return 1;
}

static inline int sub_KEYCFG_ListTop()
{
    return (gnAutomapHeight - 0x1A4) / 2;
}

static inline int sub_KEYCFG_PanelRight()
{
    return KEYCFG_X + (gnScreenWidth_0071146C - KEYCFG_X * 2);
}

static inline int sub_KEYCFG_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

static inline int sub_KEYCFG_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

// 0x004A43E0
void __cdecl TEXT_InitKeyConfigEntries()
{
    if (GAME_IsExpansion())
    {
// build: symbol ?gpListEntries@* 0x00724264
        gpListEntries = gaKeyConfigEntriesExp;
        gnKeyConfigEntryCount = 62;
        gnKeyConfigThumbScale = sub_KEYCFG_RowTrackCels() * sub_F08_VisibleLines() / gnKeyConfigEntryCount;
        gnThumbRange = gnKeyConfigEntryCount - sub_F08_VisibleLines();
    }
    else
    {
        gpListEntries = gaKeyConfigEntries;
        gnKeyConfigEntryCount = 51;
        gnKeyConfigThumbScale = sub_KEYCFG_RowTrackCels() * sub_F08_VisibleLines() / gnKeyConfigEntryCount;
        gnThumbRange = gnKeyConfigEntryCount - sub_F08_VisibleLines();
    }
}

// 0x004A44C0
int __cdecl TEXT_GetMaxFirstEntry()
{
    int nCount = gnKeyConfigEntryCount;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

// 0x004A4500
void __fastcall TEXT_ScrollKeyConfigList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_ScrollKeyConfigList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_ScrollKeyConfigList(1);
        return;
    }

    const int nMax = TEXT_GetMaxFirstEntry();
    if (nStep < 0)
    {
        const int nPrev = gnKeyConfigFirstVisible <= 0 ? gnKeyConfigFirstVisible : gnKeyConfigFirstVisible - 1;
        if (nPrev >= 0)
            gnKeyConfigFirstVisible = nPrev;
    }
    else if (nStep > 0)
    {
        const int nNext = gnKeyConfigFirstVisible >= nMax ? gnKeyConfigFirstVisible : gnKeyConfigFirstVisible + 1;
        if (nNext <= nMax)
            gnKeyConfigFirstVisible = nNext;
    }
    gnKeyConfigThumbY = sub_I18_TrackSpan() * gnKeyConfigFirstVisible / nMax + sub_I18_TrackTop();
}

// 0x004A45C0
void __fastcall TEXT_MoveKeyConfigSelection(int nStep)
{
    if (!nStep)
        return;
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_MoveKeyConfigSelection(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_MoveKeyConfigSelection(1);
        return;
    }

    const int nCount = gnKeyConfigEntryCount;
    if (nStep < 0)
    {
        const int nOld = gnKeyConfigSelected;
        const int nNew = nOld <= 0 ? nOld : nOld - 1;
        if (nNew >= 0)
            gnKeyConfigSelected = nNew;
    }
    else if (nStep > 0 && gnKeyConfigSelected < nCount)
    {
        const int nNew = gnKeyConfigSelected + 1;
        if (nNew < nCount)
            gnKeyConfigSelected = nNew;
    }

    const int nSelected = gnKeyConfigSelected;
    int nFirst = gnKeyConfigFirstVisible;
    if (nSelected < nFirst)
    {
        const int nTrackTop = sub_F08_TrackTop();
        gnKeyConfigFirstVisible = nSelected;
        gnKeyConfigThumbY = nSelected * sub_F08_TrackSpan() / TEXT_GetMaxFirstEntry() + nTrackTop;
        return;
    }

    for (;;)
    {
        int nLast = nFirst;
        for (int nLine = 0; nLast < nCount && nLine < 0x0F; ++nLine)
            ++nLast;
        if (gnKeyConfigSelected < nLast)
            break;

        const int nMax = TEXT_GetMaxFirstEntry();
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
            nFirst = nNew;
        gnKeyConfigThumbY = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
    }
    gnKeyConfigFirstVisible = nFirst;
}

// 0x004A4720
static int TEXT_GetKeyConfigLineAt(int nY)
{
    int nIndex = gnKeyConfigFirstVisible;
    const int nCount = gnKeyConfigEntryCount;
    int nLine = 0;
    if (nIndex < nCount)
    {
        int nLineY = (gnAutomapHeight - 0x1A4) / 2 + 0x3A;
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

int __stdcall sub_M119_Emit_004A4A00(int nX, int nY)
{
    if (TEXT_IsOnKeyConfigButton(nX, nY))
    {
        return TEXT_IsOnPressedButton(nX + 1, nY);
    }
    return 2;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A47C0
static int TEXT_GetKeyConfigButtonAt(int nX, int nY)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        if (nX >= gaKeyConfigButtons[i].nLeft && nX <= gaKeyConfigButtons[i].nRight
            && nY >= gaKeyConfigButtons[i].nTop && nY <= gaKeyConfigButtons[i].nBottom)
            break;
    }
    return i;
}

static int __stdcall sub_E10_IsAbovePanelLineCopy(int nY)
{
    int nHalf = (gnScreenWidth - 620) / 2;
    return nY < nHalf + (gnScreenWidth - nHalf * 2 - 49) / 3 * 2 + 18;
}

// 0x004A47F0
static int TEXT_IsInKeyConfigList(int nX, int nY)
{
    const int nHalf = (gnScreenWidth - 0x26C) / 2;
    const int nLeft = nHalf + 0x12;
    const int nRight = nHalf + (gnScreenWidth - nHalf * 2 - 0x31) / 3 * 3 + 0x12;
    if (nX >= nLeft && nX <= nRight)
    {
        const int nTop = (gnAutomapHeight - 0x1A4) / 2;
        if (nY >= nTop + 0x28 && nY <= nTop + 0x136)
            return 1;
    }
    return 0;
}

// 0x004A4860
static int TEXT_IsOnUpArrow(int nX, int nY)
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
static int TEXT_IsOnDownArrow(int nX, int nY)
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
static int TEXT_IsAboveThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY > sub_F08_ListTop() + 0x2F && nY < gnKeyConfigThumbY)
            return 1;
    }
    return 0;
}

// 0x004A4950
static int TEXT_IsOnThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY >= gnKeyConfigThumbY && nY <= gnKeyConfigThumbY + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A49A0
static int TEXT_IsBelowThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY < sub_F08_ListTop() + 0x125 && nY > gnKeyConfigThumbY + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A4A00
static inline int TEXT_IsOnKeyConfigButton(int nX, int nY)
{
    return TEXT_GetKeyConfigButtonAt(nX, nY) != 3;
}

// 0x004A4A10
static int TEXT_IsOnSelectedLine(int nX, int nY)
{
    if (TEXT_IsInKeyConfigList(nX, nY) && TEXT_GetKeyConfigLineAt(nY) == gnKeyConfigSelected
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
        && sub_E10_IsAbovePanelLineCopy(nX) == gnKeyConfigColumn)
        return 1;
    return 0;
}

// 0x004A4A80
static inline int TEXT_IsOnPressedButton(int nX, int nY)
{
    const int nButton = gnKeyConfigPressedButton;
    if (nButton != 3 && TEXT_GetKeyConfigButtonAt(nX, nY) == nButton)
    {
        return 1;
    }
    return 0;
}

// 0x004A4AA0
int __fastcall TEXT_IsOnlyPressed(int nIndex)
{
    for (int i = 0; i < 7; i++)
    {
        if (gaPressed[i] && i != nIndex)
        {
            return 0;
        }
    }
    return 1;
}

void __stdcall sub_004A4AD0_Press(int nX, int nY)
{
    gnKeyConfigPressedButton = 3;
    if (gbKeyConfigPressRepeat)
        return;

    const int bInList = TEXT_IsInKeyConfigList(nX, nY);
    const int bUp = TEXT_IsOnUpArrow(nX, nY);
    const int bDown = TEXT_IsOnDownArrow(nX, nY);
    const int bPageUp = TEXT_IsAboveThumb(nX, nY);
    const int bThumb = TEXT_IsOnThumb(nX, nY);
    const int bPageDown = TEXT_IsBelowThumb(nX, nY);
    const int bButton = TEXT_IsOnKeyConfigButton(nX, nY);

    if (TEXT_IsOnlyPressed(7) && !bInList && !bUp && !bDown && !bPageUp && !bThumb && !bPageDown && !bButton)
    {
        gbKeyConfigPressRepeat = gbRedraw;
        return;
    }

    if (TEXT_IsOnlyPressed(0) && (bInList || gaPressed[0]))
    {
        gaPressed[0] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            if (nY < nTop + 0x28)
                TEXT_MoveKeyConfigSelection(-1);
            if (nY > nTop + 0x136)
                TEXT_MoveKeyConfigSelection(1);

            const int nOldD4 = gnKeyConfigColumn;
            const int nOldSelected = gnKeyConfigSelected;
            const int nLine = TEXT_GetKeyConfigLineAt(nY);
            gnKeyConfigSelected = nLine;
            gnKeyConfigColumn = TEXT_IsAbovePanelLine(nX);
            if (gpListEntries[nLine].nId == 0x39)
            {
                gnKeyConfigColumn = nOldD4;
                gnKeyConfigSelected = nOldSelected;
            }
        }
    }

    if (TEXT_IsOnlyPressed(1) && bUp)
    {
        gaPressed[1] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(-1);
        }
    }

    if (TEXT_IsOnlyPressed(2) && bDown)
    {
        gaPressed[2] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1);
        }
    }

    if (TEXT_IsOnlyPressed(3) && bPageUp)
    {
        gaPressed[3] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1 - sub_F08_VisibleLines());
        }
    }

    if (TEXT_IsOnlyPressed(4) && (bThumb || gaPressed[4]))
    {
        if (bThumb && !gaPressed[4] && gbRedraw)
        {
            gnDragThumbY = gnKeyConfigThumbY;
            gnDragMouseY = nY;
        }
        gaPressed[4] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            TEXT_ScrollKeyConfigList((gnDragThumbY - nTop - gnDragMouseY + nY - 0x2F)
                * (gnThumbRange + 1) / sub_F08_TrackSpan() - gnKeyConfigFirstVisible);
        }
    }

    if (TEXT_IsOnlyPressed(5) && bPageDown)
    {
        gaPressed[5] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(sub_F08_VisibleLines() - 1);
        }
    }

    if (TEXT_IsOnlyPressed(6) && bButton)
    {
        gaPressed[6] = gbRedraw;
        gnKeyConfigPressedButton = TEXT_GetKeyConfigButtonAt(nX, nY);
    }
}

// 0x004A4FA0
static int TEXT_GetKeyConfigEntryState(int nIndex, int nFlag)
{
    if (nIndex == gnKeyConfigSelected && (gbKeyCaptureActive || nFlag == gnKeyConfigColumn))
    {
        return 3;
    }

// build: symbol ?gpListEntries@* 0x00724264
    if (!CUNIT_HasHotkeyBinding(gpListEntries[nIndex].nId, 1) && !CUNIT_HasHotkeyBinding(gpListEntries[nIndex].nId, 0))
    {
        return 1;
    }

    return CUNIT_HasHotkeyBinding(gpListEntries[nIndex].nId, nFlag) ? 4 : 5;
}

// 0x004A5010
void __cdecl TEXT_ResetKeyConfigDefaults()
{
    CMDTBL_ResetKeyConfig(0);
}

// 0x004A5020
void __cdecl TEXT_AcceptKeyConfig()
{
    CMDTBL_SaveAndBindHotkeys();
    UI_SetUIVar(11, 1, 0);
    sub_0047E200_CloseMenus(1);
}

// 0x004A5040
void __cdecl TEXT_CancelKeyConfig()
{
    sub_00469D50();
    UI_SetUIVar(11, 1, 0);
    WARDENCLIENT_ToggleEscMenuUIState(0, 1);
}

// 0x004A5060
void __cdecl TEXT_LayoutSlider()
{
    const int nOldFont = sub_00502EF0_SetFont(13);
    for (unsigned int i = 0; i < 3; ++i)
    {
        const int nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(gaKeyConfigButtons[i].nStringId));
        const int nThird = (sub_F08_PanelRight() - sub_F08_PanelLeft()) / (sizeof(gaKeyConfigButtons) / sizeof(gaKeyConfigButtons[0]));
        gaKeyConfigButtons[i].nLeft = nThird * i + sub_F08_PanelLeft() + nThird / 2 - nWidth / 2 - 10;
        gaKeyConfigButtons[i].nRight = nThird * i + sub_F08_PanelLeft() + nThird / 2 + nWidth / 2 + 10;
        gaKeyConfigButtons[i].nTop = sub_F08_ListTop() + 0x149;
        gaKeyConfigButtons[i].nBottom = sub_F08_ListTop() + 0x16F;
    }
    sub_00502EF0_SetFont(nOldFont);

    gnKeyConfigThumbY = sub_F08_TrackSpan() * gnKeyConfigFirstVisible / TEXT_GetMaxFirstEntry() + sub_F08_TrackTop();
}

// 0x004A5190
void __cdecl TEXT_InitTextSlider()
{
    char szPath[0x104];
    TEXT_InitKeyConfigEntries();
    sprintf(szPath, "%s\\UI\\Menu\\TextSlid", gszDataGlobal);
    gpKeyConfigSliderCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    sub_004A5060();
    gnKeyConfigFirstVisible = 0;
    gnKeyConfigSelected = 0;
}

// 0x004A51E0
void __cdecl TEXT_FreeTextSliderCel()
{
    if (gpKeyConfigSliderCel)
    {
        ARCHIVE_FreeClientCellFile(gpKeyConfigSliderCel);
        gpKeyConfigSliderCel = 0;
    }
}

// 0x004A5200
void __fastcall TEXT_ToggleKeyConfigPanel(int nArg)
{
    TEXT_InitKeyConfigEntries();
    if (nArg)
    {
        if (gbKeyCaptureActive == 0)
        {
            CMDTBL_SaveHotkeys();
            sub_0046AA20(0, 0);
            GAME_UnregisterMouseHandlers();
            sub_00467A70_RefreshHoverUnit(0);
        }
        gnKeyConfigFirstVisible = 0;
        gnKeyConfigSelected = 0;
    }
    else if (gbKeyCaptureActive == 0)
    {
        sub_0046AA20(1, 0);
        GAME_RegisterMouseHandlers();
        sub_00466FE0();
    }
    sub_004A5060();
}

// 0x004A5270
void __cdecl TEXT_DrawKeyConfigPanel()
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    TEXT_InitKeyConfigEntries();
    if (gnLastMouseX != nMouseX || gnLastMouseY != nMouseY || gbRedraw)
    {
        gnLastMouseX = nMouseX;
        gnLastMouseY = nMouseY;
        sub_004A4AD0_Press(nMouseX, nMouseY);
    }

    const int nOldFont = sub_00502EF0_SetFont(13);
    AUTOMAP_DrawFramedBox(KEYCFG_X, KEYCFG_Y, gnScreenWidth_0071146C - 2 * KEYCFG_X, (KEYCFG_Y + 0x171) - KEYCFG_Y, 0, 1);

    D2RectStrc tRect;
    tRect.nLeft = KEYCFG_X;
    tRect.nTop = KEYCFG_Y + 3;
    tRect.nRight = gnScreenWidth_0071146C - KEYCFG_X - 3;
    tRect.nBottom = KEYCFG_Y + 0x170;
    UI_DrawRectangleBorder(&tRect);
    tRect.nTop = KEYCFG_Y + 0x143;
    UI_DrawRectangleBorder(&tRect);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF51), KEYCFG_X + 0x12, KEYCFG_Y + 0x1E, 4, 0);
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF52), KEYCFG_X + 0x12 + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, KEYCFG_Y + 0x1E, 4, 0);
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF53), KEYCFG_X + 0x12 + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), KEYCFG_Y + 0x1E, 4, 0);

    int i = 0;
    while (i < sub_KEYCFG_VisibleLines() && i < gnKeyConfigEntryCount)
    {
        int nY = i * 0x12 + KEYCFG_Y + 0x22;
        int nIndex = gnKeyConfigFirstVisible + i;
        int bVisible;
        if (gbKeyCaptureActive && nIndex == gnKeyConfigSelected && (gnBlink & 0xF) <= 4)
            bVisible = 0;
        else
            bVisible = 1;

        ++i;

        if (gpListEntries[nIndex].nId == 0x39)
            continue;

        if (nIndex == gnKeyConfigSelected)
        {
            AUTOMAP_DrawFramedBox(KEYCFG_X + 0x12, nY + 1, 3 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), 0x12, 0, 1);
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gpListEntries[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, gbKeyCaptureActive ? 3 : 0, 0);
        }
        else
        {
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gpListEntries[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, 0, 0);
        }

        if (bVisible || !gnKeyConfigColumn)
        {
            D2Win_10117_DrawText(CMDTBL_GetKeyText(gpListEntries[nIndex].nId, 1), KEYCFG_X + 0x1E + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, nY + 0x12, TEXT_GetKeyConfigEntryState(nIndex, 1), 0);
        }

        if (bVisible || gnKeyConfigColumn)
        {
            D2Win_10117_DrawText(CMDTBL_GetKeyText(gpListEntries[nIndex].nId, 0), KEYCFG_X + 0x1E + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), nY + 0x12, TEXT_GetKeyConfigEntryState(nIndex, 0), 0);
        }
    }

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = gpKeyConfigSliderCel;
    tCel.nFrame = 13;
    for (int j = 0; j < sub_KEYCFG_TrackCels(); ++j)
        TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x3B + j * 0x0C, -1, 5, 0);

    tCel.nFrame = 14;
    for (int k = 0; k < gnKeyConfigThumbScale; ++k)
        TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x20, gnKeyConfigThumbY + 0x0C + k * 0x0C, -1, 5, 0);

    if (gbUpPressed_007C028C && sub_KEYCFG_IsOnUpArrow(nMouseX, nMouseY))
        tCel.nFrame = 9;
    else
        tCel.nFrame = 11;
    TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x2F, -1, 5, 0);

    if (gbDownPressed_007C0290 && sub_KEYCFG_IsOnDownArrow(nMouseX, nMouseY))
        tCel.nFrame = 8;
    else
        tCel.nFrame = 10;
    TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x40, -1, 5, 0);

    for (unsigned int m = 0; m < 3; ++m)
    {
        int nColor;
        if (m == gnKeyConfigPressedButton)
            nColor = gaButtons_007246D8[m].nColor;
        else
            nColor = 4;
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gaButtons_007246D8[m].nString), gaButtons_007246D8[m].nX + 10, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x12, nColor, 0);
    }

    if (GetTickCount() < gdwMessageTick_007C02C8 + 2000)
    {
        const int nCenterX = gnScreenWidth_0071146C / 2;
        const int nTextY = KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) + 0x1E;
        const int nTextX = nCenterX - D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(gnMessage)) / 2;
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gnMessage), nTextX, nTextY, 1, 1);
    }

    sub_00502EF0_SetFont(nOldFont);
    ++gnBlink;
}

// 0x004A59D0
int __stdcall TEXT_KeyConfigWheelMsg(D2HotkeyActionStrc* pAction)
{
    if (GAME_IsExitPending())
    {
        pAction->nState18 = 0;
        return (int)pAction;
    }

    int nDuration = pAction->nValue0A / 120;
    if (nDuration)
    {
        TEXT_ScrollKeyConfigList(-nDuration * 2);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pAction->nState18 = 1;
    pAction->nState1C = 0;
    return sub_00420290_HandleMsg(pAction);
}

// 0x004A5C70
void __stdcall TEXT_CancelKeyConfigMsg(SMSGHANDLER_PARAMS* message)
{
    if (GAME_IsExitPending()) { message->bReturn = 0; return; }
    if (global_00724728) {
        if (!(message->lParam & REPEAT_MASK)) {
            sub_00469D50();
            UI_SetUIVar(UI_VARIABLE, 1, 0);
            WARDENCLIENT_ToggleEscMenuUIState(0, 1);
            sub_004B9A00(1, 0, 0, 0, 0);
        }
    } else global_00724728 = 1;
    message->bReturn = 1;
    message->lResult = 0;
    sub_00420290_BreakHandlerChain(message);
}

// 0x004A5D00
void __cdecl TEXT_RegisterKeyCaptureHandlers()
{
    gbKeyCaptureActive = 1;
    sub_00455AE0_CloseUIVar(0xB);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
    COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
}

// 0x004A5DE0
void __cdecl TEXT_CloseKeyCaptureHandlers()
{
    if (gbKeyCaptureActive)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
        sub_00469D50();
        sub_0046AA20(1, 0);
        GAME_RegisterMouseHandlers();
        sub_00466FE0();
        gbKeyCaptureActive = 0;
    }
}

// 0x004A5E60
static void TEXT_ReleaseKeyConfigPress(int nX, int nY)
{
    if (gaPressed[0])
    {
        if (TEXT_IsOnSelectedLine(nX, nY) && gpListEntries[gnKeyConfigSelected].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    if (gaPressed[6])
    {
        const int nButton = gnKeyConfigPressedButton;
        if (nButton != 3 && TEXT_GetKeyConfigButtonAt(nX, nY) == nButton)
        {
            gaKeyConfigButtons[nButton].pfnClick();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    gbKeyConfigPressRepeat = 0;
    gaPressed[0] = 0;
    gaPressed[1] = 0;
    gaPressed[2] = 0;
    gaPressed[3] = 0;
    gaPressed[4] = 0;
    gaPressed[5] = 0;
    gaPressed[6] = 0;
}

// 0x004A5F10
void __stdcall TEXT_KeyConfigButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    TEXT_ReleaseKeyConfigPress(nX, nY);
    gbRedraw = 0;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey);               // 0x00469C20

void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset);                                                // 0x004A5D70

extern unsigned long gdwMessageTick; // 0x007C02C8

// 0x004A60B0
void __stdcall sub_004A60B0_KeyDownMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    unsigned short wKey = 0;
    if (!(pMsg->lParam & 0x40000000))
    {
        if (pMsg->wParam == 0x1B)
        {
            TEXT_UnregisterKeyConfigHandlers(1);
            sub_004B9A00(1, 0, 0, 0, 0);
// build: symbol ?gbKeyConfigReady@* 0x00724728
            gbKeyConfigReady = 0;
        }
        else
        {
// build: symbol ?gpListEntries@* 0x00724264
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
            if (CMDTBL_QueryKey(gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (unsigned short)pMsg->wParam, &wKey))
            {
                TEXT_UnregisterKeyConfigHandlers(1);
                sub_004B9A00(2, 0, 0, 0, 0);
                if (pMsg->wParam == 0x0D || pMsg->wParam == 0x2E || pMsg->wParam == 0x08 || pMsg->wParam == 0x20)
                {
                    gbKeyConfigReady = 0;
                    goto store_key;
                }
            }
            gbKeyConfigReady = 1;
        }
store_key:
        if (wKey)
        {
            gwGlobal_007C02C4 = wKey;
            gdwMessageTick = GetTickCount();
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A61A0
void __stdcall sub_004A61A0_KeyUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    unsigned short wKey = 0;
    if (gbKeyConfigReady)
    {
        if (CMDTBL_QueryKey(gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (unsigned short)pMsg->wParam, &wKey))
        {
            TEXT_UnregisterKeyConfigHandlers(1);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    else
    {
        gbKeyConfigReady = 1;
    }

    if (wKey)
    {
        gwGlobal_007C02C4 = wKey;
        gdwMessageTick = GetTickCount();
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}


#define STAT_ARMORCLASS_VS_HTH 33

#pragma pack(push, 2)

#pragma pack(pop)

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl UI_RegisterKeyConfigHandlers(); // 0x00454980

void __fastcall CUNIT_ClearHotkeyBinding(int nId, int nB); // 0x00469D70

#define SOUND_ID 4

#define FIELD_OFFSET(T, F) ((unsigned long)&(((T*)0)->F))

#pragma pack(push, 2)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

// 0x004A4780
int __stdcall TEXT_IsAbovePanelLine(int nY)
{
    int nHalf = (gnScreenWidth - 620) / 2;
    return nY < nHalf + (gnScreenWidth - nHalf * 2 - 49) / 3 * 2 + 18;
}

// 0x004A5A40
void __stdcall TEXT_PrevEntryMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

// build: symbol ?gpListEntries@* 0x00724264
    D2ClientListEntryStrc* pEntries = gpListEntries;
    int nOldIndex = gnKeyConfigSelected;
    do
    {
        TEXT_MoveKeyConfigSelection(-1);
    }
    while (pEntries[gnKeyConfigSelected].nId == 0x39);

    if (nOldIndex != gnKeyConfigSelected)
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5AB0
void __stdcall TEXT_NextEntryMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    D2ClientListEntryStrc* pEntries = gpListEntries;
    int nOldIndex = gnKeyConfigSelected;
    do
    {
        TEXT_MoveKeyConfigSelection(1);
    }
    while (pEntries[gnKeyConfigSelected].nId == 0x39);

    if (nOldIndex != gnKeyConfigSelected)
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5B30
void __stdcall TEXT_SelectSecondaryColumnMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

// build: symbol ?gnKeyConfigColumn@* 0x007246D4
    if (gnKeyConfigColumn == 0)
    {
        gnKeyConfigColumn = 1;
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5B90
void __stdcall TEXT_SelectPrimaryColumnMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    if (gnKeyConfigColumn == 1)
    {
        gnKeyConfigColumn = 0;
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5BF0
void __stdcall TEXT_ClearEntryKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

// build: symbol ?gbKeyConfigReady@* 0x00724728
    if (gbKeyConfigReady)
    {
        if (!(pMsg->lParam & 0x40000000))
        {
            CUNIT_ClearHotkeyBinding(gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    else
    {
        gbKeyConfigReady = 1;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5D70
void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset)
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
    if (bReset)
    {
        UI_RegisterKeyConfigHandlers();
        gbKeyCaptureActive = 0;
    }
}

// 0x004A5F70
void __stdcall TEXT_ApplyEntryMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    if (gbKeyConfigReady)
    {
        if (!(pMsg->lParam & 0x40000000) && gpListEntries[gnKeyConfigSelected].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
            gbKeyConfigReady = 0;
        }
    }
    else
    {
        gbKeyConfigReady = 1;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// build: symbol ?$S1@?4??sub_004A8DF0_DrawKeyLabel@@YIXHHHH@Z@4IA 0x007C0830
// 0x004A6000
void __stdcall sub_004A6000_RegisterPressMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
    UI_RegisterKeyConfigHandlers();
    gbKeyCaptureActive = 0;
    gbRedraw = 1;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __stdcall TEXT_WheelCaptureMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004A6310

void __stdcall TEXT_ButtonCaptureMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004A6350

void __stdcall sub_004A63B0_WheelMsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x004A63B0

#include "gen/data/Source/D2Client/Unknown_004A43E0.inc"
