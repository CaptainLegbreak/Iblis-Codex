#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct UiControl;
class SpinnerImplementation;
struct Unicode;
struct D2RectStrc;
struct D2DialogLineStrc;
struct Obj004B8580;
struct D2SoundNodeStrc;
struct D2SoundUnitNodeStrc;
struct D2SoundVecStrc;
struct D2SoundStream4B9BB0Strc;
struct D2GSPacketText5EStrc;
struct D2GSPacketSrv5E;
struct D2UiPacketStrc_004B9210;
struct D2CinematicPacketStrc;
struct D2UnkFieldsStrc;
struct D2UnkSortItemStrc;
class UIWidget;
class ButtonImplementation;
class SpinnerWrapper;
struct D2HintRecordStrc;
struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;
struct D2HintCursorStrc;
struct D2ValueNodeStrc;
struct D2ValueLinkStrc;
struct D2Packed004B9BC0Strc;
struct D2Entry004B9CD0Strc;
struct D2EntryNode004B9CD0Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

struct Obj004B8580 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    int nValue44;
};

extern char gbGlobal_007C0E80; // 0x007C0E80
int __cdecl sub_004549C0_IsPanelAllocated(); // 0x004549C0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00463DF0(); // 0x00463DF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __cdecl sub_00487B30_ResetNpcState(); // 0x00487B30
void __cdecl sub_0048A6F0_Clear(); // 0x0048A6F0
void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog);
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId); // 0x0061AAF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2ClientDialogStrc* gpDialog_007C0E64; // 0x007C0E64
extern D2ClientDialogStrc* gpDialog_007C0E6C; // 0x007C0E6C
extern int gnGlobal_007C0E7C; // 0x007C0E7C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall sub_004B8020(void* pRes); // 0x004B8020
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_00489360_SetTradePanelOpen(int bOpen); // 0x00489360
void __fastcall sub_004897E0_UpdateSound(int nArg1, int nArg2); // 0x004897E0
void __cdecl sub_00489E00_OpenUi(); // 0x00489E00
void __cdecl sub_00489F50_CloseUiArchives(); // 0x00489F50
void __cdecl sub_0048A460_CloseCubePanel(); // 0x0048A460
void __cdecl sub_0048A6E0_SetFlag7BCE28(); // 0x0048A6E0
int __cdecl sub_004B85E0(); // 0x004B85E0
void __fastcall sub_004B8940_CloseWait(int bReopen); // 0x004B8940
int __cdecl sub_004B8AD0_OpenWait(); // 0x004B8AD0
void __cdecl sub_004B8BF0_OpenWait2(); // 0x004B8BF0
void __cdecl sub_004B8CB0(); // 0x004B8CB0
void __fastcall sub_004CB9C0_Request(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
extern int gnGlobal_007C0E60; // 0x007C0E60
extern unsigned long gdwGlobal_007C0E68; // 0x007C0E68
extern unsigned long gdwTick_007C0E70; // 0x007C0E70
extern unsigned long gdwGlobal_007C0E78; // 0x007C0E78

extern "C" void __fastcall sub_00478600_SendPacket(U8 command, U16 value, U16 first, U16 second);
extern "C" int __fastcall sub_004FC9B0_AppendText(UiControl* control, const U16* text, int style, U8 metadata, int mode);
extern "C" int __fastcall sub_00455F20_SetUiState(int id, int state, int flag);
extern "C" int __cdecl sub_0044DCC0_Mode();
extern "C" int gPacketState; // 0x007C0E7C
extern "C" UiControl* gTextControl;
extern "C" int gPendingClear;
extern "C" int gCoordinateBase;
extern "C" int gCoordinateOffset;
extern "C" int gOpenFlag;
extern "C" int gUiPhase;
extern "C" U32 gRangeMode;
extern "C" int gRangeValue;

struct D2SoundUnitNodeStrc
{
    D2UnitStrc* pUnit;
    D2SoundUnitNodeStrc* pNext;
};

struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int f_8;
    D2SoundVecStrc vPos;
    float fDistance;
    char unk0x1C[0x0C];
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
};

#pragma pack(push, 1)
struct D2SoundStream4B9BB0Strc
{
    char unk0x00[0x45];
    int nValue;
};

#pragma pack(pop)
struct D2GSPacketText5EStrc
{
    unsigned char aText[37];
};

struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    D2GSPacketText5EStrc tText;
};

extern D2SoundNodeStrc* gpSoundList_007C5458; // 0x007C5458
void __fastcall sub_0046B630_FireLevelEvent(int nIndex); // 0x0046B630
void __fastcall sub_004CA8D0_NotifyUnitHint(D2UnitStrc* pUnit, int nHandle); // 0x004CA8D0
void __fastcall sub_00516A10_FreeList(D2SoundUnitNodeStrc** ppList); // 0x00516A10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __fastcall sub_0044B880_SetValue(int nValue); // 0x0044B880
void __fastcall sub_0044C860_SetValue(int nValue); // 0x0044C860
void __cdecl sub_0044D520(); // 0x0044D520

#pragma pack(push, 1)
struct D2UiPacketStrc_004B9210
{
    unsigned char nHeader;
    unsigned short nType;
    unsigned short nArg;
};

#pragma pack(pop)

void __fastcall sub_004A28A0_OnUiPacket1(D2UiPacketStrc_004B9210* pPacket); // 0x004A28A0
void __fastcall sub_004B3340_OnUiPacket2(unsigned short nArg); // 0x004B3340
void __fastcall sub_004B25C0_OnUiPacket3(D2UiPacketStrc_004B9210* pPacket); // 0x004B25C0
void __fastcall sub_0049FF60_OnUiPacket4(D2UiPacketStrc_004B9210* pPacket); // 0x0049FF60
extern "C" void __fastcall sub_004A3100_SetPacketValue(unsigned int value); // 0x004A3100
void __fastcall sub_00478A00(void* pCel); // 0x00478A00

struct D2CinematicPacketStrc
{
    unsigned char nHeader;
    unsigned char nCinematic;
};

void __fastcall sub_00482EF0_PlayCinematic(int nIndex); // 0x00482EF0


struct D2UnkFieldsStrc
{
    char unk0x00[0x1C];
    int nUnk0x1C;
    char unk0x20[0x25];
    unsigned char nUnk0x45[4];
    unsigned char nUnk0x49[4];
    unsigned char nUnk0x4D[4];
    unsigned char nUnk0x51[4];
    unsigned char nUnk0x55[4];
};

struct D2UnkSortItemStrc
{
    char unk0x00[0x18];
    float fUnk0x18;
    char unk0x1C[0x18];
    unsigned int nUnk0x34;
    char unk0x38[4];
    unsigned char nUnk0x3C;
};

class UIWidget
{
public:
    virtual ~UIWidget();
    virtual void Slot01() = 0;
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int Slot11() = 0;

    int unk0x04;
};

class ButtonImplementation : public UIWidget
{
public:
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
    virtual void sub_004BAC60_SetUnk24(int nValue);

    char unk0x08[0x1C];
    int unk0x24;
    int (__cdecl* pfnCallback)();
};

class SpinnerWrapper : public UIWidget
{
public:
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);

    SpinnerImplementation* pImpl;
};

class SpinnerImplementation : public UIWidget
{
public:
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
};

struct D2HintRecordStrc
{
    int unk0x00;
    int nValue;
};

struct D2TimedHintEntryStrc
{
    int bUsed;
    int nHintId;
    int nKey;
    char unk0x0C[0x10];
    int nValue1C;
    char unk0x20[0x08];
    union
    {
        D2HintRecordStrc* pRecord;
        void* pKeyList;
    };
    void* f_2C;
    int nState;
    unsigned int dwTick;
};

D2HintCursorStrc* __fastcall sub_00481860(int nId); // 0x00481860
int __fastcall sub_005169D0_ListHasKey(void* pKeyList, int nKey); // 0x005169D0
extern D2TimedHintNodeStrc* gpTimedHintList_007C5458; // 0x007C5458

struct D2ValueNodeStrc
{
    char unk0x00[8];
    int nKey;
    char unk0x0C[0x10];
    int nValue;
};

struct D2ValueLinkStrc
{
    D2ValueNodeStrc* pValue;
    D2ValueLinkStrc* pNext;
};

extern D2ValueLinkStrc* gpValueList_007C5458; // 0x007C5458

#pragma pack(push, 1)
struct D2Packed004B9BC0Strc
{
    char unk0x00[0x45];
    int nOn;
    char unk0x49[0x04];
    int nHeld;
};

#pragma pack(pop)
struct D2Entry004B9CD0Strc
{
    char unk0x00[0x08];
    int nId;
    char unk0x0C[0x30];
    unsigned char nValue;
};

struct D2EntryNode004B9CD0Strc
{
    D2Entry004B9CD0Strc* f_0;
    D2EntryNode004B9CD0Strc* pNext;
};

unsigned int __cdecl sub_00481820(); // 0x00481820
extern "C" int __fastcall sub_004E4100_RandomInRange(int nMin, int nMax); // 0x004E4100
extern D2EntryNode004B9CD0Strc* gpEntryNodes_007C5458; // 0x007C5458

// 0x004B82F0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex)
{
    D2_ASSERT(pDialog, 0x4E7);
    D2_ASSERT(nIndex < pDialog->nLines, 0x4ED);
    if (nIndex == -1)
    {
        pDialog->nHover = nIndex;
        return;
    }

    for (int i = 0; i < pDialog->nLines; ++i)
    {
        const int* pbEnabled = &pDialog->pLines[i].bEnabled;
        if (nIndex == i)
        {
            if (*pbEnabled)
            {
                pDialog->nHover = nIndex;
                return;
            }

            D2_ASSERT(0, 0x50F);
        }
    }

    D2_ASSERT(0, 0x513);
}

// 0x004B83A0
static void sub_004B83A0_PlaceLine(D2ClientDialogStrc* pDialog, int nIndex)
{
    int nOldFont = sub_00502EF0(1);
    sub_00502EF0(pDialog->pLines[nIndex].nFont);
    int nWidth = sub_00501820(pDialog->pLines[nIndex].wszText);
    if (nWidth >= pDialog->nWidth)
        pDialog->pLines[nIndex].nX = 0;
    else
        pDialog->pLines[nIndex].nX = (pDialog->nWidth - nWidth + 1) / 2 + 1;
    pDialog->pLines[nIndex].nWidth = nWidth;
    sub_00502EF0(nOldFont);
}

void __fastcall sub_004B8410_LayoutDialog(D2ClientDialogStrc* pDialog)
{
    int nMaxWidth = 0;
    int nHeight = 0;
    D2_ASSERT(pDialog->bAutoSize, 0x59F);
    int nOldFont = sub_00502EF0(1);
    int nDisabled = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        int nWidth = sub_00501820(pDialog->pLines[i].wszText);
        if (nWidth > nMaxWidth)
            nMaxWidth = nWidth;
        if (!pDialog->pLines[i].bEnabled)
            ++nDisabled;
        nHeight += pDialog->pLines[i].nHeight;
    }
    nMaxWidth += 0x14;
    nHeight += 0xF;
    sub_00502EF0(nOldFont);
    pDialog->nX = pDialog->nCenterX - nMaxWidth / 2;
    if (pDialog->bCountEnabled)
        pDialog->nY = pDialog->nCenterY - nDisabled * 0x15;
    else
        pDialog->nY = pDialog->nCenterY - nHeight / 3;
    D2_ASSERT(nMaxWidth <= gnGlobal_0071146C - 0x50, 0x5D2);
    D2_ASSERT(nHeight <= gnGlobal_00711470 - 0x62, 0x5D7);
    if (pDialog->nX + nMaxWidth > gnGlobal_0071146C - 0xA)
        pDialog->nX = gnGlobal_0071146C - nMaxWidth;
    if (pDialog->nY + nHeight > gnGlobal_00711470 - 0x3A)
        pDialog->nY = gnGlobal_00711470 - nHeight - 0x30;
    if (pDialog->nX <= 0xA)
        pDialog->nX = 0xA;
    if (pDialog->nY <= 0xA)
        pDialog->nY = 0xA;
    pDialog->nWidth = nMaxWidth;
    pDialog->nHeight = nHeight;
    for (int j = 0; j < pDialog->nLines; ++j)
        sub_004B83A0_PlaceLine(pDialog, j);
}

// 0x004B8580
extern "C" __declspec(dllexport) int __fastcall sub_004B8580(Obj004B8580* pObj) {
    if (pObj) {
        return pObj->nValue44;
    }
    return -1;
}

// 0x004B8590
D2DialogLineStrc* __fastcall sub_004B8590_GetLine(D2ClientDialogStrc* pDialog, int nIndex)
{
    if (pDialog && nIndex >= 0 && nIndex < pDialog->nLines)
        return &pDialog->pLines[nIndex];
    return 0;
}

// 0x004B85B0
void __fastcall sub_004B85B0_GetRect(D2ClientDialogStrc* pDialog, D2RectStrc* pRect)
{
    if (pDialog && pRect)
    {
        pRect->nTop = pDialog->nY;
        pRect->nLeft = pDialog->nX;
        pRect->nBottom = pDialog->nHeight + pDialog->nY;
        pRect->nRight = pDialog->nWidth + pDialog->nX;
    }
}

// 0x004B8A00
int __cdecl sub_004B8A00_IsGlobalClear()
{
    return gbGlobal_007C0E80 == 0;
}

// 0x004B85F0
void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nHeight, int nArg4,
    int nType, int nFont, int (__cdecl* pfnCallback)(), int bEnabled)
{
    int nIndex = pDialog->nLines;
    D2_ASSERT(nIndex < 10, 0x552);
    pDialog->nLines = nIndex + 1;
    pDialog->pLines[nIndex].nHeight = nHeight;
    pDialog->pLines[nIndex].nX = 0;
    pDialog->pLines[nIndex].nArg4 = nArg4;
    pDialog->pLines[nIndex].nFont = nFont;
    if (nType == 3)
    {
        D2_ASSERT(pDialog->nMode != 1, 0x55E);
    }
    pDialog->pLines[nIndex].nType = nType;
    pDialog->pLines[nIndex].pfnCallback = pfnCallback;
    pDialog->pLines[nIndex].bEnabled = bEnabled;
    int nLen = sub_00526800(wszText) + 1;
    if (nLen > 0x77)
        nLen = 0x77;
    sub_00526790(pDialog->pLines[nIndex].wszText, wszText, nLen);
    pDialog->pLines[nIndex].wszText[nLen].wChar = 0;
    if (bEnabled)
        pDialog->nEnabled += 1;
    if (pDialog->bAutoSize)
        sub_004B8410_LayoutDialog(pDialog);
    else
        sub_004B83A0_PlaceLine(pDialog, nIndex);
    D2RectStrc tRect;
    tRect.nTop = pDialog->nY;
    tRect.nLeft = pDialog->nX;
    tRect.nBottom = pDialog->nY + pDialog->nHeight;
    tRect.nRight = pDialog->nX + pDialog->nWidth;
    sub_00467430(&tRect);
    if (pDialog->nHover == -1 && bEnabled)
        sub_004B82F0_Select(pDialog, nIndex);
}

// 0x004B8730
void __cdecl sub_004B8730_DrawDialogHover()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (gnGlobal_007C0E7C > 2 && !sub_004549C0_IsPanelAllocated())
    {
        if (nX >= gnGlobal_007A2858 + 0x111 && nX <= gnGlobal_007A2858 + 0x133 && nY >= 0xA8 - gnGlobal_007A285C && nY <= 0xCA - gnGlobal_007A285C)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnGlobal_007A2858 + 0xEF, 0xA7 - gnGlobal_007A285C, 0, 0);
        if (nX >= gnGlobal_007A2858 + 0xDD && nX <= gnGlobal_007A2858 + 0xFF && nY >= 0x17F - gnGlobal_007A285C && nY <= 0x1A1 - gnGlobal_007A285C)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnGlobal_007A2858 + 0xBB, 0x17E - gnGlobal_007A285C, 0, 0);
        if (nX >= gnGlobal_007A2858 + 0x111 && nX <= gnGlobal_007A2858 + 0x133 && nY >= 0x17F - gnGlobal_007A285C && nY <= 0x1A1 - gnGlobal_007A285C)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1022), gnGlobal_007A2858 + 0x107, 0x17E - gnGlobal_007A285C, 0, 0);
    }

    if (sub_00463DD0_GetPlayerUnit())
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
        if (sub_00463DF0() || (pRoom && !DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))))
        {
            if (sub_004538D0(0x17))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                sub_00455F20(0x17, 1, 0);
                sub_0048A6F0_Clear();
                sub_00487B30_ResetNpcState();
                gnGlobal_007C0E7C = 0;
            }
            return;
        }
    }

    if (gnGlobal_007C0E7C >= 3 && gnGlobal_007C0E7C <= 6)
        return;
    if (!gnGlobal_007C0E7C)
        return;
    if (gnGlobal_007C0E7C == 1)
    {
        if (gpDialog_007C0E6C)
            sub_004B8100_DrawDialog(gpDialog_007C0E6C);
    }
    else if (gnGlobal_007C0E7C == 2)
    {
        if (gpDialog_007C0E64)
            sub_004B8100_DrawDialog(gpDialog_007C0E64);
    }
}

unsigned long gdwTick_007C0E70; // 0x007C0E70

// 0x004B8A30
int __cdecl sub_004B8A30_OnCancel()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0E64);
    gpDialog_007C0E64 = 0;
    gnGlobal_007C0E7C = 3;
    sub_00478600_SendShorts(0x4F, 3, 0, 0);
    return 1;
}

// 0x004B8A80
int __cdecl sub_004B8A80_OnClose()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0E64);
    gpDialog_007C0E64 = 0;
    gnGlobal_007C0E7C = 7;
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    gdwTick_007C0E70 = GetTickCount();
    return 1;
}

// 0x004B8BA0
int __cdecl sub_004B8BA0_OnClose2()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    sub_004B8020(gpDialog_007C0E6C);
    gpDialog_007C0E6C = 0;
    gnGlobal_007C0E7C = 7;
    gdwTick_007C0E70 = GetTickCount();
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    return 1;
}

// 0x004B8CF0
void __fastcall sub_004B8CF0_HandleTradePacket(const unsigned char* pPacket)
{
    switch (pPacket[1])
    {
    case 21:
        sub_0048A460_CloseCubePanel();
        return;

    case 16:
        sub_00489E00_OpenUi();
        return;

    case 17:
        sub_00489F50_CloseUiArchives();
        return;

    case 12:
        gnGlobal_007C0E7C = 0;
        sub_004B8940_CloseWait(0);
        return;

    case 13:
        gnGlobal_007C0E7C = 0;
        sub_004B8940_CloseWait(1);
        return;

    case 0:
        if (!gnGlobal_007C0E7C)
        {
            if (!sub_004538D0(0x17))
            {
                if (!sub_00455F20(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                sub_0048A6F0_Clear();
                gdwTick_007C0E70 = 0xFFFFFFFF;
            }

            gnGlobal_007C0E7C = 1;
            sub_004B8BF0_OpenWait2();
            sub_00489360_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 9:
        sub_004CB9C0_Request(sub_00463DD0_GetPlayerUnit(), 0x17);
        return;

    case 10:
    {
        D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C0E60, 0);
        if (pUnit)
        {
            sub_004CB9C0_Request(pUnit, 0x17);
        }
        return;
    }

    case 1:
        if (!gnGlobal_007C0E7C)
        {
            D2InventoryStrc* const pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
            if (INVENTORY_GetCursorItem(pInventory))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (sub_004B85E0() || !sub_004B8AD0_OpenWait() || sub_004538D0(5))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (!sub_004538D0(0x17))
            {
                if (!sub_00455F20(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                gdwTick_007C0E70 = 0xFFFFFFFF;
            }

            gnGlobal_007C0E7C = 2;
            sub_00489360_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 2:
        sub_004897E0_UpdateSound(0, 0);
        sub_004B8940_CloseWait(0);
        return;

    case 5:
        if (!sub_00453A90_GetUIVarUnchecked(0x17))
        {
            return;
        }

        gdwTick_007C0E70 = 0xFFFFFFFF;
        sub_00489360_SetTradePanelOpen(1);
        switch (gnGlobal_007C0E7C)
        {
        case 3:
            gnGlobal_007C0E7C = 5;
        case 5:
            sub_004897E0_UpdateSound(0, 1);
            return;

        case 4:
            gnGlobal_007C0E7C = 6;
            sub_004897E0_UpdateSound(1, 1);
            return;

        case 6:
        case 7:
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 6:
        if (!sub_00453A90_GetUIVarUnchecked(0x17))
        {
            return;
        }

        sub_00478600_SendShorts(0x4F, 8, (unsigned short)(gdwGlobal_007C0E68 >> 16), (unsigned short)gdwGlobal_007C0E68);
        gdwTick_007C0E70 = 0xFFFFFFFF;
        sub_00489360_SetTradePanelOpen(1);
        switch (gnGlobal_007C0E7C)
        {
        case 7:
            gnGlobal_007C0E7C = 3;
        case 3:
            sub_004897E0_UpdateSound(0, 0);
            return;

        case 4:
        case 5:
        case 6:
            sub_004897E0_UpdateSound(0, 0);
            gnGlobal_007C0E7C = 3;
            return;

        case 1:
            gdwGlobal_007C0E78 = 0;
            sub_004897E0_UpdateSound(0, 0);
            gnGlobal_007C0E7C = 3;
            if (gpDialog_007C0E6C)
            {
                sub_004B8020(gpDialog_007C0E6C);
                gpDialog_007C0E6C = 0;
            }
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 14:
        sub_0048A6E0_SetFlag7BCE28();
        return;

    case 15:
        sub_0048A6F0_Clear();
        return;
    }
}

// 0x004B90B0
extern "C" void __cdecl sub_004B90B0_SendState()
{
    sub_00478600_SendPacket(0x4F, 7, 0, 0);
    gPacketState = 3;
}

extern "C" int __fastcall sub_0043E5F0_AppendText(const U16* text, int style)
{
    if (gTextControl)
        sub_004FC9B0_AppendText(gTextControl, text, style, 0, 1);
    return 1;
}

extern "C" int __fastcall sub_0043E610_AppendText(const U16* text, int style)
{
    if (gTextControl)
        sub_004FC9B0_AppendText(gTextControl, text, style, 0, 1);
    return 1;
}

extern "C" void __cdecl sub_00494FC0_ClearUi()
{
    if (gPendingClear != 0)
    {
        sub_00455F20_SetUiState(21, 1, 0);
        gPendingClear = 0;
    }
}

extern "C" void __cdecl sub_004898A0_OpenUi()
{
    gOpenFlag = 1;
    if (gUiPhase == 13)
        gUiPhase = 12;
    sub_00455F20_SetUiState(5, 1, 0);
}

unsigned long gdwGlobal_007C0E78; // 0x007C0E78

D2GSPacketText5EStrc gtTable_007C0EA4; // 0x007C0EA4

int gdwTableInit_007C0ECC; // 0x007C0ECC

// 0x004B90D0
void __fastcall sub_004B90D0_SetValue(unsigned long nValue, bool bFirst)
{
    if (bFirst)
    {
        gdwGlobal_007C0E68 = nValue;
    }
    else
    {
        gdwGlobal_007C0E78 = nValue;
    }
}

// 0x004B9200
void __cdecl sub_004B9200_ResetTable()
{
    gdwTableInit_007C0ECC = 0;
}

// 0x004B92B0
void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket)
{
    gtTable_007C0EA4 = pPacket->tText;
    gdwTableInit_007C0ECC = 1;
}

// 0x004B92D0
int __stdcall sub_004B92D0_IsTableReady(int nUnused)
{
    return gdwTableInit_007C0ECC;
}

// 0x004B9330
void __fastcall sub_004B9330_ForwardByte(const unsigned char* pPacket)
{
    sub_0046B630_FireLevelEvent(pPacket[1]);
}

// 0x004B9440
D2ClientSoundStrc* __fastcall sub_004B9440_FindSoundByHandle(int nHandle)
{
    if (nHandle)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pSound = pNode->pSound;
            if (pSound->f_8 == nHandle)
            {
                return pSound;
            }
        }
    }
    return 0;
}

// 0x004B9470
static inline void sub_004B9470_ReleaseUnits(D2ClientSoundStrc* pSound)
{
    for (D2SoundUnitNodeStrc* pNode = pSound->pUnitList; pNode; pNode = pNode->pNext)
    {
        sub_004CA8D0_NotifyUnitHint(pNode->pUnit, pSound->f_8);
    }
    sub_00516A10_FreeList(&pSound->pUnitList);
}

// 0x004B94A0
static inline void sub_004B94A0_StopStream(D2ClientSoundStrc* pSound)
{
    if (pSound->nType == 1)
    {
        sub_004DF7B0(pSound->pStream);
    }
    D2_ASSERT(!pSound->pStream, 0x93);
}

void __fastcall sub_M112_Emit_004B9470(D2ClientSoundStrc* pSound)
{
    sub_004B9470_ReleaseUnits(pSound);
}

void __fastcall sub_M112_Emit_004B94A0(D2ClientSoundStrc* pSound)
{
    sub_004B94A0_StopStream(pSound);
}

// 0x004B9560
int __fastcall sub_004B9560_HasSoundHandle(int nHandle)
{
    return sub_004B9440_FindSoundByHandle(nHandle) != 0;
}

// 0x004B9BB0
static inline int sub_004B9BB0_GetStreamValue(D2SoundStream4B9BB0Strc* pStream)
{
    return pStream->nValue;
}

int __fastcall sub_M112_Emit_004B9BB0(D2SoundStream4B9BB0Strc* pStream)
{
    return sub_004B9BB0_GetStreamValue(pStream);
}

// 0x004B9110
void __fastcall sub_004B9110_SendGoldRequest(unsigned long nGold)
{
    if (gnGlobal_007C0E7C == 4 || gnGlobal_007C0E7C == 5 || gnGlobal_007C0E7C == 6)
    {
        sub_00478600_SendShorts(0x4F, 7, 0, 0);
        gnGlobal_007C0E7C = 3;
        return;
    }

    const unsigned long nMaxGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
    if (nGold >= nMaxGold)
    {
        gdwGlobal_007C0E68 = nMaxGold;
        sub_00478600_SendShorts(0x4F, 8, nMaxGold >> 0x10, nMaxGold);
    }
    else
    {
        gdwGlobal_007C0E68 = nGold;
        sub_00478600_SendShorts(0x4F, 8, nGold >> 0x10, nGold);
    }
}

// 0x004B91F0
void __cdecl sub_004B91F0()
{
    sub_004B8940_CloseWait(0);
}

// 0x004B9180
int __cdecl sub_004B9180_PollWait()
{
    if (gnGlobal_007C0E7C == 7)
    {
        if (gdwTick_007C0E70 != 0xFFFFFFFF && GetTickCount() > gdwTick_007C0E70 + 30000)
        {
            sub_0048A6A0_ClearHover();
            gnGlobal_007C0E7C = 0;
            sub_004B8940_CloseWait(0);
            sub_00477EE0();
            sub_0044B880_SetValue(0);
            sub_0044C860_SetValue(1);
            sub_0044D520();
        }

        return 1;
    }

    return 0;
}

int gbHintsOff_007C5468; // 0x007C5468

void* gpCelFile_007C546C; // 0x007C546C

// 0x004B9210
void __fastcall sub_004B9210_DispatchUiPacket(D2UiPacketStrc_004B9210* pPacket)
{
    switch (pPacket->nType)
    {
    case 36:
        sub_004A3100_SetPacketValue(pPacket->nArg);
        return;

    case 2:
        sub_004B3340_OnUiPacket2(pPacket->nArg);
        return;

    case 1:
        sub_004A28A0_OnUiPacket1(pPacket);
        return;

    case 3:
    case 6:
        sub_004B25C0_OnUiPacket3(pPacket);
        return;

    case 4:
    case 13:
        sub_0049FF60_OnUiPacket4(pPacket);
        return;

    case 23:
        sub_00477EE0();
        sub_0044B880_SetValue(0);
        sub_0044C860_SetValue(1);
        sub_0044D520();
        return;
    }
}

// 0x004BABC0
void __cdecl sub_004BABC0_ToggleHints()
{
    gbHintsOff_007C5468 = !gbHintsOff_007C5468;
    if (!gbHintsOff_007C5468)
    {
        sub_004BAA50_RefreshHintRange();
    }
}

// 0x004BE060
void __cdecl sub_004BE060()
{
    if (gpCelFile_007C546C)
    {
        sub_00478A00(gpCelFile_007C546C);
        gpCelFile_007C546C = 0;
    }
}

// 0x004B9320
void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket)
{
    sub_00482EF0_PlayCinematic(pPacket->nCinematic);
}

// 0x004B9340
float __fastcall sub_004B9340_MaxFloat(float fA, float fB)
{
    return fA > fB ? fA : fB;
}

// 0x004B9370
float __fastcall sub_004B9370_MinFloat(float fA, float fB)
{
    return fA < fB ? fA : fB;
}

// 0x004B93A0
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax)
{
    return sub_004B9370_MinFloat(sub_004B9340_MaxFloat(fValue, fMin), fMax);
}

// 0x004B9B80
void __fastcall sub_004B9B80_SetFields(D2UnkFieldsStrc* pRecord, int nValue, int nBase, int nOffset)
{
    *(int*)pRecord->nUnk0x49 = pRecord->nUnk0x1C;
    *(int*)pRecord->nUnk0x4D = nValue;
    *(int*)pRecord->nUnk0x51 = nBase;
    *(int*)pRecord->nUnk0x55 = nBase + nOffset;
    *(int*)pRecord->nUnk0x45 = 1;
}

// 0x004B9DA0
int __fastcall sub_004B9DA0_CompareItems(D2UnkSortItemStrc* pA, D2UnkSortItemStrc* pB, int bCompareFloat,
                                         int bCompareValue)
{
    if (pA->nUnk0x3C > pB->nUnk0x3C)
    {
        return 1;
    }

    if (pA->nUnk0x3C < pB->nUnk0x3C)
    {
        return 0;
    }

    if (bCompareFloat)
    {
        if (pA->fUnk0x18 < pB->fUnk0x18)
        {
            return 1;
        }

        if (pA->fUnk0x18 > pB->fUnk0x18)
        {
            return 0;
        }
    }

    if (bCompareValue)
    {
        if (pA->nUnk0x34 > pB->nUnk0x34)
        {
            return 1;
        }

        if (pA->nUnk0x34 < pB->nUnk0x34)
        {
            return 0;
        }
    }

    return pA > pB;
}

// 0x004BAC60
void ButtonImplementation::sub_004BAC60_SetUnk24(int nValue)
{
    unk0x24 = nValue;
}

// 0x004BAD40
int ButtonImplementation::MsgSlot06(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x24 && !(pMsg->lParam & 0x40000000) && pMsg->wParam == 0x0D)
    {
        return pfnCallback();
    }

    return 0;
}

// 0x004BC280
int SpinnerWrapper::MsgSlot02(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot02(pMsg);
}

D2TimedHintNodeStrc* gpTimedHintList_007C5458; // 0x007C5458

// 0x004B9590
int __fastcall sub_004B9590(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nState == 1;
            }
        }
    }
    return 0;
}

// 0x004B9610
void* __fastcall sub_004B9610(int nHintId)
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nHintId == nHintId)
        {
            return (void*)pEntry->nKey;
        }
    }
    return 0;
}

// 0x004B9B20
int __fastcall sub_004B9B20(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nValue1C;
            }
        }
    }
    return 0;
}

// 0x004B9BE0
int __fastcall sub_004B9BE0_HasActiveHint(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                D2HintRecordStrc* pRecord = pEntry->pRecord;
                if (pRecord && pRecord->nValue)
                {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

// 0x004B9C20
int __cdecl sub_004B9C20_IsSpeechPlaying()
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nState != 2 && pEntry->nHintId >= 0xB76 && pEntry->nHintId <= 0x1230)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B9C60
int __cdecl sub_004B9C60_IsSongPlaying()
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nState != 2 && pEntry->nHintId >= 0x1231 && pEntry->nHintId <= 0x125A)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B9CA0
int __fastcall sub_004B9CA0_GetHintIdByKey(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                return pEntry->nHintId;
            }
        }
    }
    return 0;
}

// 0x004B9690
D2TimedHintEntryStrc* __stdcall sub_004B9690_FindOldestEntry(int nGroup, int nKey, D2TimedHintEntryStrc* pExclude)
{
    D2TimedHintEntryStrc* pOldest = 0;
    D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458;
    if (gpTimedHintList_007C5458)
    {
        for (; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (sub_00481860(pEntry->nHintId)->nOwnerId == nGroup && pEntry != pExclude && pEntry->nState == 1
                && (!nKey || sub_005169D0_ListHasKey(pEntry->pKeyList, nKey)) && (!pOldest || pEntry->dwTick < pOldest->dwTick))
            {
                pOldest = pEntry;
            }
        }
    }

    return pOldest;
}

// 0x004B9B50
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue)
{
    if (!nKey)
        return;
    D2ValueLinkStrc* pLink = gpValueList_007C5458;
    if (!pLink)
        return;
    do
    {
        D2ValueNodeStrc* pValue = pLink->pValue;
        if (pValue->nKey == nKey)
        {
            pValue->nValue = nValue;
            return;
        }
        pLink = pLink->pNext;
    } while (pLink);
}

// 0x004B9BC0
static inline int sub_004B9BC0_IsOnAndNotHeld(D2Packed004B9BC0Strc* pRecord)
{
    return pRecord->nOn && !pRecord->nHeld;
}

// 0x004B9CD0
void __fastcall sub_004B9CD0_SetEntryByte(int nId, unsigned char nValue)
{
    if (!nId)
    {
        return;
    }
    for (D2EntryNode004B9CD0Strc* pNode = gpEntryNodes_007C5458; pNode; pNode = pNode->pNext)
    {
        D2Entry004B9CD0Strc* pEntry = pNode->f_0;
        if (pEntry->nId == nId)
        {
            pEntry->nValue = nValue;
            return;
        }
    }
}

// 0x004B9EB0
void __cdecl sub_004B9EB0_PlayRandomSound()
{
    if (sub_00481820() % 3 == 0)
    {
        const int nSound = sub_004E4100_RandomInRange(0xB76, 0x1230);
        sub_004B9A00(nSound, 0, 0, 0, 0);
    }
}

int __fastcall sub_M119_Emit_004B9BC0(D2Packed004B9BC0Strc* pRecord)
{
    return sub_004B9BC0_IsOnAndNotHeld(pRecord);
}
