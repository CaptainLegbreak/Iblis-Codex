#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2ClientSound.h"
struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct UiControl;
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
struct D2HintRecordStrc;
struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;
struct D2ValueNodeStrc;
struct D2ValueLinkStrc;
struct D2Packed004B9BC0Strc;
struct D2Entry004B9CD0Strc;
struct D2EntryNode004B9CD0Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern int gnScreenWidth; // 0x0071146C
void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
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

extern char gbTradeActive; // 0x007C0E80
int __cdecl UI_IsGoldPanelOpen(); // 0x004549C0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __cdecl INV_ResetNpcState(); // 0x00487B30
void __cdecl INV_ClearTradeFlag(); // 0x0048A6F0
void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog);
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId); // 0x0061AAF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern D2ClientDialogStrc* gpTradeRequestDialog; // 0x007C0E64
extern D2ClientDialogStrc* gpTradeWaitDialog; // 0x007C0E6C
extern int gnTradeState; // 0x007C0E7C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall INV_SetTradePanelOpen(int bOpen); // 0x00489360
void __fastcall INV_UpdateTradeAcceptSound(int nArg1, int nArg2); // 0x004897E0
void __cdecl INV_OpenStashPanel(); // 0x00489E00
void __cdecl INV_ResetStashPanel(); // 0x00489F50
void __cdecl INV_OpenCubePanel(); // 0x0048A460
void __cdecl INV_SetTradeFlag(); // 0x0048A6E0
int __cdecl sub_004B85E0(); // 0x004B85E0
void __fastcall sub_004B8940_CloseWait(int bReopen); // 0x004B8940
int __cdecl sub_004B8AD0_OpenWait(); // 0x004B8AD0
void __cdecl sub_004B8BF0_OpenWait2(); // 0x004B8BF0
void __cdecl sub_004B8CB0(); // 0x004B8CB0
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
extern int gnTradePartnerUnitId; // 0x007C0E60
extern unsigned long gdwPrimaryTradeGold; // 0x007C0E68
extern unsigned long gdwTradeTimeoutTick; // 0x007C0E70
extern unsigned long gdwSecondaryTradeGold; // 0x007C0E78

extern "C" void __fastcall sub_00478600_SendPacket(U8 command, U16 value, U16 first, U16 second);
extern "C" int __fastcall sub_004FC9B0_AppendText(UiControl* control, const U16* text, int style, U8 metadata, int mode);
extern "C" int __fastcall UI_SetUIVar(int id, int state, int flag); // 0x00455F20
extern "C" int __cdecl GAME_IsExpansion(); // 0x0044DCC0
extern "C" int gPacketState; // 0x007C0E7C
extern "C" UiControl* gTextControl;
extern "C" int gPendingClear;
extern "C" int gCoordinateBase;
extern "C" int gCoordinateOffset;
extern "C" int gOpenFlag;
extern "C" int gUiPhase;
extern "C" U32 gRangeMode;
extern "C" int gRangeValue;


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
void __fastcall UNITSND_RemoveUnitHint(D2UnitStrc* pUnit, int nHandle); // 0x004CA8D0
void __fastcall D2SOUNDUTIL_ListFree(D2SoundUnitNodeStrc** ppList); // 0x00516A10
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880
void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860
void __cdecl GAME_RequestExit(); // 0x0044D520

#pragma pack(push, 1)
struct D2UiPacketStrc_004B9210
{
    unsigned char nHeader;
    unsigned short nType;
    unsigned short nArg;
};

#pragma pack(pop)

void __fastcall QUESTLOG_AcceptShortPacket(D2UiPacketStrc_004B9210* pPacket); // 0x004A28A0
void __fastcall NPCMENU_ReloadHirelingPopup(unsigned short nArg); // 0x004B3340
void __fastcall NPCMENU_OnNpcPacketStoreSubId(D2UiPacketStrc_004B9210* pPacket); // 0x004B25C0
void __fastcall TEXT_AcceptWordPacket(D2UiPacketStrc_004B9210* pPacket); // 0x0049FF60
extern "C" void __fastcall QUESTLOG_SetQuestPacketValue(unsigned int value); // 0x004A3100
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

struct D2CinematicPacketStrc
{
    unsigned char nHeader;
    unsigned char nCinematic;
};

void __fastcall INV_PlayCinematic(int nIndex); // 0x00482EF0

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

D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860
int __fastcall D2SOUNDUTIL_ListContains(void* pKeyList, int nKey); // 0x005169D0
extern D2TimedHintNodeStrc* gpClientSoundList; // 0x007C5458

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

unsigned int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820
extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100
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
    int nOldFont = D2Win_10127_SetFont(1);
    D2Win_10127_SetFont(pDialog->pLines[nIndex].nFont);
    int nWidth = D2Win_10121_GetTextWidth(pDialog->pLines[nIndex].wszText);
    if (nWidth >= pDialog->nWidth)
        pDialog->pLines[nIndex].nX = 0;
    else
        pDialog->pLines[nIndex].nX = (pDialog->nWidth - nWidth + 1) / 2 + 1;
    pDialog->pLines[nIndex].nWidth = nWidth;
    D2Win_10127_SetFont(nOldFont);
}

void __fastcall sub_004B8410_LayoutDialog(D2ClientDialogStrc* pDialog)
{
    int nMaxWidth = 0;
    int nHeight = 0;
    D2_ASSERT(pDialog->bAutoSize, 0x59F);
    int nOldFont = D2Win_10127_SetFont(1);
    int nDisabled = 0;
    for (int i = 0; i < pDialog->nLines; ++i)
    {
        int nWidth = D2Win_10121_GetTextWidth(pDialog->pLines[i].wszText);
        if (nWidth > nMaxWidth)
            nMaxWidth = nWidth;
        if (!pDialog->pLines[i].bEnabled)
            ++nDisabled;
        nHeight += pDialog->pLines[i].nHeight;
    }
    nMaxWidth += 0x14;
    nHeight += 0xF;
    D2Win_10127_SetFont(nOldFont);
    pDialog->nX = pDialog->nCenterX - nMaxWidth / 2;
    if (pDialog->bCountEnabled)
        pDialog->nY = pDialog->nCenterY - nDisabled * 0x15;
    else
        pDialog->nY = pDialog->nCenterY - nHeight / 3;
    D2_ASSERT(nMaxWidth <= gnScreenWidth - 0x50, 0x5D2);
    D2_ASSERT(nHeight <= gnScreenHeight - 0x62, 0x5D7);
    if (pDialog->nX + nMaxWidth > gnScreenWidth - 0xA)
        pDialog->nX = gnScreenWidth - nMaxWidth;
    if (pDialog->nY + nHeight > gnScreenHeight - 0x3A)
        pDialog->nY = gnScreenHeight - nHeight - 0x30;
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
    return gbTradeActive == 0;
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
    if (gnTradeState > 2 && !UI_IsGoldPanelOpen())
    {
        if (nX >= gnPanelOffsetX + 0x111 && nX <= gnPanelOffsetX + 0x133 && nY >= 0xA8 - gnPanelOffsetY && nY <= 0xCA - gnPanelOffsetY)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnPanelOffsetX + 0xEF, 0xA7 - gnPanelOffsetY, 0, 0);
        if (nX >= gnPanelOffsetX + 0xDD && nX <= gnPanelOffsetX + 0xFF && nY >= 0x17F - gnPanelOffsetY && nY <= 0x1A1 - gnPanelOffsetY)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnPanelOffsetX + 0xBB, 0x17E - gnPanelOffsetY, 0, 0);
        if (nX >= gnPanelOffsetX + 0x111 && nX <= gnPanelOffsetX + 0x133 && nY >= 0x17F - gnPanelOffsetY && nY <= 0x1A1 - gnPanelOffsetY)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1022), gnPanelOffsetX + 0x107, 0x17E - gnPanelOffsetY, 0, 0);
    }

    if (sub_00463DD0_GetPlayerUnit())
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
        if (CUNIT_IsPlayerDeadOrMissing() || (pRoom && !DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))))
        {
            if (GAME_GetUIVarState(0x17))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                UI_SetUIVar(0x17, 1, 0);
                INV_ClearTradeFlag();
                INV_ResetNpcState();
                gnTradeState = 0;
            }
            return;
        }
    }

    if (gnTradeState >= 3 && gnTradeState <= 6)
        return;
    if (!gnTradeState)
        return;
    if (gnTradeState == 1)
    {
        if (gpTradeWaitDialog)
            sub_004B8100_DrawDialog(gpTradeWaitDialog);
    }
    else if (gnTradeState == 2)
    {
        if (gpTradeRequestDialog)
            sub_004B8100_DrawDialog(gpTradeRequestDialog);
    }
}

unsigned long gdwTradeTimeoutTick; // 0x007C0E70

// 0x004B8A30
int __cdecl sub_004B8A30_OnCancel()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    DIALOG_DestroyDialog(gpTradeRequestDialog);
    gpTradeRequestDialog = 0;
    gnTradeState = 3;
    sub_00478600_SendShorts(0x4F, 3, 0, 0);
    return 1;
}

// 0x004B8A80
int __cdecl sub_004B8A80_OnClose()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    DIALOG_DestroyDialog(gpTradeRequestDialog);
    gpTradeRequestDialog = 0;
    gnTradeState = 7;
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    gdwTradeTimeoutTick = GetTickCount();
    return 1;
}

// 0x004B8BA0
int __cdecl sub_004B8BA0_OnClose2()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    DIALOG_DestroyDialog(gpTradeWaitDialog);
    gpTradeWaitDialog = 0;
    gnTradeState = 7;
    gdwTradeTimeoutTick = GetTickCount();
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    return 1;
}

// 0x004B8CF0
void __fastcall sub_004B8CF0_HandleTradePacket(const unsigned char* pPacket)
{
    switch (pPacket[1])
    {
    case 21:
        INV_OpenCubePanel();
        return;

    case 16:
        INV_OpenStashPanel();
        return;

    case 17:
        INV_ResetStashPanel();
        return;

    case 12:
        gnTradeState = 0;
        sub_004B8940_CloseWait(0);
        return;

    case 13:
        gnTradeState = 0;
        sub_004B8940_CloseWait(1);
        return;

    case 0:
        if (!gnTradeState)
        {
            if (!GAME_GetUIVarState(0x17))
            {
                if (!UI_SetUIVar(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                INV_ClearTradeFlag();
                gdwTradeTimeoutTick = 0xFFFFFFFF;
            }

            gnTradeState = 1;
            sub_004B8BF0_OpenWait2();
            INV_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 9:
        UNITSND_PlayPlayerSpeech(sub_00463DD0_GetPlayerUnit(), 0x17);
        return;

    case 10:
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnTradePartnerUnitId, 0);
        if (pUnit)
        {
            UNITSND_PlayPlayerSpeech(pUnit, 0x17);
        }
        return;
    }

    case 1:
        if (!gnTradeState)
        {
            D2InventoryStrc* const pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
            if (INVENTORY_GetCursorItem(pInventory))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (sub_004B85E0() || !sub_004B8AD0_OpenWait() || GAME_GetUIVarState(5))
            {
                sub_00478600_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (!GAME_GetUIVarState(0x17))
            {
                if (!UI_SetUIVar(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                gdwTradeTimeoutTick = 0xFFFFFFFF;
            }

            gnTradeState = 2;
            INV_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 2:
        INV_UpdateTradeAcceptSound(0, 0);
        sub_004B8940_CloseWait(0);
        return;

    case 5:
        if (!UI_GetUIVarUnchecked(0x17))
        {
            return;
        }

        gdwTradeTimeoutTick = 0xFFFFFFFF;
        INV_SetTradePanelOpen(1);
        switch (gnTradeState)
        {
        case 3:
            gnTradeState = 5;
        case 5:
            INV_UpdateTradeAcceptSound(0, 1);
            return;

        case 4:
            gnTradeState = 6;
            INV_UpdateTradeAcceptSound(1, 1);
            return;

        case 6:
        case 7:
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 6:
        if (!UI_GetUIVarUnchecked(0x17))
        {
            return;
        }

        sub_00478600_SendShorts(0x4F, 8, (unsigned short)(gdwPrimaryTradeGold >> 16), (unsigned short)gdwPrimaryTradeGold);
        gdwTradeTimeoutTick = 0xFFFFFFFF;
        INV_SetTradePanelOpen(1);
        switch (gnTradeState)
        {
        case 7:
            gnTradeState = 3;
        case 3:
            INV_UpdateTradeAcceptSound(0, 0);
            return;

        case 4:
        case 5:
        case 6:
            INV_UpdateTradeAcceptSound(0, 0);
            gnTradeState = 3;
            return;

        case 1:
            gdwSecondaryTradeGold = 0;
            INV_UpdateTradeAcceptSound(0, 0);
            gnTradeState = 3;
            if (gpTradeWaitDialog)
            {
                DIALOG_DestroyDialog(gpTradeWaitDialog);
                gpTradeWaitDialog = 0;
            }
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 14:
        INV_SetTradeFlag();
        return;

    case 15:
        INV_ClearTradeFlag();
        return;
    }
}

// 0x004B90B0
extern "C" void __cdecl sub_004B90B0_SendState()
{
    sub_00478600_SendPacket(0x4F, 7, 0, 0);
    gPacketState = 3;
}

// build: symbol @CHATDLG_PrintMessage@* 0x0043E5F0
extern "C" int __fastcall CHATDLG_PrintMessage(const U16* text, int style)
{
    if (gTextControl)
        sub_004FC9B0_AppendText(gTextControl, text, style, 0, 1);
    return 1;
}

// build: symbol @CHATDLG_PrintText@* 0x0043E610
extern "C" int __fastcall CHATDLG_PrintText(const U16* text, int style)
{
    if (gTextControl)
        sub_004FC9B0_AppendText(gTextControl, text, style, 0, 1);
    return 1;
}

extern "C" void __cdecl sub_00494FC0_ClearUi()
{
    if (gPendingClear != 0)
    {
        UI_SetUIVar(21, 1, 0);
        gPendingClear = 0;
    }
}

extern "C" void __cdecl sub_004898A0_OpenUi()
{
    gOpenFlag = 1;
    if (gUiPhase == 13)
        gUiPhase = 12;
    UI_SetUIVar(5, 1, 0);
}

unsigned long gdwSecondaryTradeGold; // 0x007C0E78

D2GSPacketText5EStrc gaQuestIntroFlags; // 0x007C0EA4

int gbQuestIntroFlagsReady; // 0x007C0ECC

// 0x004B90D0
void __fastcall sub_004B90D0_SetValue(unsigned long nValue, bool bFirst)
{
    if (bFirst)
    {
        gdwPrimaryTradeGold = nValue;
    }
    else
    {
        gdwSecondaryTradeGold = nValue;
    }
}

// 0x004B9200
void __cdecl sub_004B9200_ResetTable()
{
    gbQuestIntroFlagsReady = 0;
}

// 0x004B92B0
void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket)
{
    gaQuestIntroFlags = pPacket->tText;
    gbQuestIntroFlagsReady = 1;
}

// 0x004B92D0
int __stdcall sub_004B92D0_IsTableReady(int nUnused)
{
    return gbQuestIntroFlagsReady;
}

// 0x004B9330
void __fastcall sub_004B9330_ForwardByte(const unsigned char* pPacket)
{
    sub_0046B630_FireLevelEvent(pPacket[1]);
}

D2ClientSoundStrc* __fastcall SOUNDINST_FindSoundByHandle(int nHandle); // 0x004B9440

// 0x004B9110
void __fastcall sub_004B9110_SendGoldRequest(unsigned long nGold)
{
    if (gnTradeState == 4 || gnTradeState == 5 || gnTradeState == 6)
    {
        sub_00478600_SendShorts(0x4F, 7, 0, 0);
        gnTradeState = 3;
        return;
    }

    const unsigned long nMaxGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
    if (nGold >= nMaxGold)
    {
        gdwPrimaryTradeGold = nMaxGold;
        sub_00478600_SendShorts(0x4F, 8, nMaxGold >> 0x10, nMaxGold);
    }
    else
    {
        gdwPrimaryTradeGold = nGold;
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
    if (gnTradeState == 7)
    {
        if (gdwTradeTimeoutTick != 0xFFFFFFFF && GetTickCount() > gdwTradeTimeoutTick + 30000)
        {
            sub_0048A6A0_ClearHover();
            gnTradeState = 0;
            sub_004B8940_CloseWait(0);
            sub_00477EE0();
            WINMAIN_SetExitApplication(0);
            GAME_SetCinematicExit(1);
            GAME_RequestExit();
        }

        return 1;
    }

    return 0;
}

int gbRandomSoundTest; // 0x007C5468

void* gpListBoxSliderCel; // 0x007C546C

// 0x004B9210
void __fastcall sub_004B9210_DispatchUiPacket(D2UiPacketStrc_004B9210* pPacket)
{
    switch (pPacket->nType)
    {
    case 36:
        QUESTLOG_SetQuestPacketValue(pPacket->nArg);
        return;

    case 2:
        NPCMENU_ReloadHirelingPopup(pPacket->nArg);
        return;

    case 1:
        QUESTLOG_AcceptShortPacket(pPacket);
        return;

    case 3:
    case 6:
        NPCMENU_OnNpcPacketStoreSubId(pPacket);
        return;

    case 4:
    case 13:
        TEXT_AcceptWordPacket(pPacket);
        return;

    case 23:
        sub_00477EE0();
        WINMAIN_SetExitApplication(0);
        GAME_SetCinematicExit(1);
        GAME_RequestExit();
        return;
    }
}

// 0x004BABC0
void __cdecl sub_004BABC0_ToggleHints()
{
    gbRandomSoundTest = !gbRandomSoundTest;
    if (!gbRandomSoundTest)
    {
// build: symbol ?SOUNDINST_LockSpeechSounds@* 0x004BAA50
        SOUNDINST_LockSpeechSounds();
    }
}

// 0x004BE060
void __cdecl sub_004BE060()
{
    if (gpListBoxSliderCel)
    {
        ARCHIVE_FreeClientCellFile(gpListBoxSliderCel);
        gpListBoxSliderCel = 0;
    }
}

// 0x004B9320
void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket)
{
    INV_PlayCinematic(pPacket->nCinematic);
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

D2TimedHintNodeStrc* gpClientSoundList; // 0x007C5458

