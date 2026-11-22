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

