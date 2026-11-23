#include <D2UnitData.h>
#include "D2ClientUi.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2StormTypes.h"
#include "D2ClientTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Win32Types.h"
#include "D2ItemTypes.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct D2CelFileStrc;
struct Unicode;
struct D2MonsterDataStrc;
struct D2ClientNotifyStrc;
struct D2ClientNodeStrc;
struct D2RosterSubStrc;
struct D2RosterEntryStrc;
struct D2RC4Strc;
struct D2ClientSlotObjStrc;
struct D2ClientSlotHolderStrc;
struct D2ClientRecordStrc;
struct D2ClientStringListStrc;
struct D2ItemStatCostTxt;
struct D2NpcButtonStrc;
struct D2StaticPathStrc;
struct D2InventoryGridInfoStrc;
struct D2PanelButtonStrc;
struct RangeNode;
struct LookupNode;
struct ColorView;
union PackedWord;
struct D2BodyLocRectStrc;
struct SMSGHANDLER_PARAMS;
struct D2UnitStrc;
struct D2ClientServiceStrc;
struct D2DataTablesStrc;
struct D2ItemsTxt;
struct D2AuxLevelEntryStrc;
struct D2GfxDataStrc;
struct D2HirelingIconRecordStrc;
struct D2PanelLabelStrc;

extern void* ghDbgHelp; // 0x0098A680
extern int gbRightClickConsumed; // 0x007A0670
extern int gbPopupDismissed; // 0x007A5254

static D2UnitStrc* gpHoverItem; // 0x007BCBF4


struct D2ClientNodeStrc
{
    char unk0x00[0x08];
    int nId;
    char unk0x0C[0x08];
    int nValueA;
    int nValueB;
    char unk0x1C[0x14];
    D2ClientNodeStrc* pNext;
};

struct D2RosterSubStrc
{
    int nUnk0x00;
    D2RosterSubStrc* pNext;
};

struct D2RosterEntryStrc
{
    char unk0x00[0x34];
    void* pResource;
    D2RosterSubStrc* pSubList;
    char unk0x3C[0x44];
    D2RosterEntryStrc* pNext;
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void ApplyKeystream(unsigned char* pData, unsigned int nSize);
};

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    int (__fastcall* pfnCall)(int nArg1, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

struct D2ClientSlotHolderStrc
{
    char unk0x00[0x0C];
    D2ClientSlotObjStrc* pObj;
};

struct D2ClientRecordStrc
{
    unsigned char nId;
    unsigned char nType;
    unsigned char nFlag;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_5;
    unsigned char nValue3;
    unsigned char nUnk0x07;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
};

struct D2ClientStringListStrc
{
    Unicode* pStrings[6];
    unsigned short nCount;
    unsigned char f_1A[4];
    unsigned char unk0x1E[8];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
D2ClientNotifyStrc* __cdecl GAME_GetClientNotify(); // 0x0044B7B0
void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __cdecl sub_00468F00(); // 0x00468F00
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __cdecl WARDENCLIENT_ActivatePendingModule(); // 0x00480230
void __cdecl sub_0048A050(); // 0x0048A050
void __cdecl sub_0048A730(); // 0x0048A730
void __cdecl sub_00494FC0(); // 0x00494FC0
void __fastcall sub_0049EB10_PostRecord(D2ClientRecordStrc* pRecord); // 0x0049EB10
void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg); // 0x004A1770
void __cdecl sub_004B8CB0(); // 0x004B8CB0
void __fastcall sub_004DC2B0(void* pResource); // 0x004DC2B0
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern int gnHoverTopX; // 0x00721E3C
extern int gnHoverTopY; // 0x00721E40
extern int gnHoverBottomX; // 0x00721E44
extern int gnHoverBottomY; // 0x00721E48
extern int gnHoverCellX; // 0x00721E4C
extern int gnHoverCellY; // 0x00721E50
extern int gbGameServerReady; // 0x007A0618
extern int gbPositionalSound; // 0x007A061C
extern int gbLeavingGame; // 0x007A0620
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern D2ClientNodeStrc* gpNodeList_007BB5BC; // 0x007BB5BC
extern D2RosterEntryStrc* gpRosterListA_007BB5C0; // 0x007BB5C0
extern int gdwGlobal_007BB5DC; // 0x007BB5DC
extern unsigned char gnGlobal_007BB5E0; // 0x007BB5E0
extern D2ClientSlotHolderStrc* gpSlotHolder; // 0x007BC990
static int gbHoverInGrid; // 0x007BCBE4
extern int gnRecipeScrollColor; // 0x007BCEA4
extern Unicode gwszRecipeScrollText[]; // 0x007BCEA8
extern unsigned char gbTextHoverSet; // 0x007BF23A
extern int gdwGlobal_007BF23F; // 0x007BF23F
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyOwners[16]; // 0x007C0768
extern int gaHotkeyLeft[16]; // 0x007C07B8
extern unsigned char gaTable_007C0EA4[]; // 0x007C0EA4
extern int gbQuestIntroFlagsReady; // 0x007C0ECC
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __stdcall sub_Z12_EmitUse(int nMin, int nMax, int bModified);
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

#pragma pack(push, 2)
struct D2NpcButtonStrc
{
    int nId;
    int bActive;
    unsigned short nTextId;
    int nMode;
    unsigned short nKey;
    int nArg;
};
#pragma pack(pop)

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl GAME_GetConnectionType(); // 0x0044DB30
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
int __cdecl sub_00468830(); // 0x00468830
void __fastcall MSG_SendHeaderOnly(char nValue); // 0x00478590
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
void __fastcall sub_00480930(int nType, int nUnitId); // 0x00480930
void __cdecl sub_004B90B0(); // 0x004B90B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004C21F0(D2UnitStrc* pItem); // 0x004C21F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
extern int gnStashObjectId; // 0x00721E54
extern int gnButtonCount; // 0x00722160
extern int gnInvMouseX; // 0x007BCA4C
extern int gnInvMouseY; // 0x007BCBD8
static int gbHoverInBodyLoc; // 0x007BCBE8
static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8
extern unsigned char gnSelectedTab; // 0x007BCC04
extern int gbWeaponSwitch_007BCC4C; // 0x007BCC4C
extern "C" int gbTradeFlag; // 0x007BCE28
extern int gbInvGoldButtonDown; // 0x007BCE30
extern void* gpCel_007BCE8C; // 0x007BCE8C
extern int gbPanelButtonClicked; // 0x007BCE9C

extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78
extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40
extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3); // 0x004786D0
int __cdecl INV_CheckTradeClickDelay(); // 0x00486D10
void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt); // 0x0049FF90
int __fastcall sub_004C1E20(D2UnitStrc* pItem); // 0x004C1E20
int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pItem); // 0x004C2240
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590
int __stdcall sub_00628C20(D2UnitStrc* pItem); // 0x00628C20
int __stdcall sub_00628C70(D2UnitStrc* pItem); // 0x00628C70
int __stdcall sub_0062A0A0(D2UnitStrc* pItem); // 0x0062A0A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall sub_0063BD10(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall sub_004B3870_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870
void __cdecl sub_K04_EmitUse(int nValue);

#pragma pack(push, 2)
struct D2PanelButtonStrc
{
    int bActive;
    int nValue;
    unsigned short nString;
    int nCel;
    unsigned short nFrame;
    int nType;
};

#pragma pack(pop)

extern D2PanelButtonStrc gaPanelButtons_007BC9E0[]; // 0x007BC9E0
int __cdecl MONSTER_IsGambleShop(); // 0x004B3500
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId); // 0x004B3230
extern unsigned char gnMaxTab; // 0x007BCC05

struct RangeNode
{
    char gap00[0x204];
    unsigned int start;
    unsigned int size;
    RangeNode* next;
};

struct LookupNode
{
    char gap00[0x8];
    unsigned int key;
    char gapAfterKey[0x10];
    unsigned int value;
    char gapAfterValue[0x10];
    LookupNode* next;
};

struct ColorView
{
    char gap00[0x10];
    unsigned int color;
};

union PackedWord
{
    unsigned int word;
    struct Bytes
    {
        unsigned char low;
        unsigned char high;
        unsigned char third;
        unsigned char fourth;
    } bytes;
};

typedef char packed_word_size[sizeof(PackedWord)==4?1:-1];

typedef char packed_high_lane[OFFSET(PackedWord::Bytes,high)==1?1:-1];

typedef char RangeNode_start[OFFSET(RangeNode,start)==0x204?1:-1];

typedef char RangeNode_size[OFFSET(RangeNode,size)==0x208?1:-1];

typedef char RangeNode_next[OFFSET(RangeNode,next)==0x20C?1:-1];

typedef char LookupNode_key[OFFSET(LookupNode,key)==0x8?1:-1];

typedef char LookupNode_value[OFFSET(LookupNode,value)==0x1C?1:-1];

typedef char LookupNode_next[OFFSET(LookupNode,next)==0x30?1:-1];

typedef char ColorView_color[OFFSET(ColorView,color)==0x10?1:-1];

extern "C" LookupNode* gLookupHead_007BB5BC;
extern "C" unsigned int gValue_007A065C;
extern "C" unsigned int gValue_007A0660;
extern "C" unsigned int gValue_007A0664;
extern "C" unsigned int gValue_007A6ABC;
extern "C" unsigned int gValue_007A6ADC;
extern "C" unsigned int gValue_007A6AE0;
extern "C" unsigned int gValue_007A6AF0;
extern "C" unsigned int gValue_00712F44;
extern "C" unsigned int gValue_00712F48;
extern "C" unsigned int gValue_007BB5D8;
extern "C" unsigned int gValue_007BB5E8;
extern "C" unsigned int gValue_007BCBF0; // 0x007BCBF0
extern "C" unsigned int gValue_007BCE2C; // 0x007BCE2C
extern "C" unsigned short gValue_007BB5E4;
extern "C" const unsigned char gColorTable_00971740[];
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

extern U8 gColor;
extern int gScreenHeight;
extern int gScreenWidth;
extern U32 gUiState; // 0x007BCBF0
extern void* gResourceA;
extern void* gResourceB;
void __cdecl InitializePalette();
void __fastcall sub_004F6300(int x, int y, int width, int height, int color, int mode);
int __stdcall ReleaseResource(void* resource);
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall sub_00479120_GetHirelingClassId(int nUnitId); // 0x00479120
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
void __stdcall sub_Z12_EmitUse2(int nValue1, int nValue2);

struct D2BodyLocRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x12[2];
};

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
extern D2BodyLocRectStrc gaBodyLocRects[11]; // 0x007BCD38
extern int gnAutomapWidth; // 0x007A5220
extern int gnAutomapHeight_007A521C; // 0x007A521C
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
void __stdcall sub_00467FA0(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
extern int gbBuySellPressed; // 0x007BCEA0
extern "C" int gnLightmapRenderMode; // 0x00712CCC
extern "C" int gbSkillPointsHighlight; // 0x007C0C3C
extern "C" unsigned char gbFlag_007BC9D4; // 0x007BC9D4
extern "C" unsigned char gbFlag_007BC9D8; // 0x007BC9D8
extern "C" int gnScreenHeight_00711470; // 0x00711470
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80
void __stdcall sub_00483E40(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40
void __fastcall INV_DrawMercEquipHighlights(D2UnitStrc* pUnit); // 0x0048B3F0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

typedef void (__fastcall *UnitCallback)(Unit*);

extern U32 gSelectionState; // 0x007BCC50
extern U8 gPaletteA;
extern U8 gPaletteB;
extern U8 gPaletteC;
extern U8 gPaletteD;
void __fastcall CUNIT_ForEachObject(UnitCallback callback); // 0x004649D0
void __fastcall sub_00489DA0(Unit* unit); // 0x00489DA0
U32 __stdcall PaletteColor(U32 red, U32 green, U32 blue);
void __fastcall sub_00478600(U8 command, U16 value, U32 word2, U32 word3); // 0x00478600
static void INV_DrawUnitEquippedItems(D2UnitStrc* pUnit); // 0x0048B540

struct D2AuxLevelEntryStrc
{
    int nType;
    const char* szFile;
    char bLocalized;
    char bFormat;
    char unk0x0A[2];
};

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C360
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern D2AuxLevelEntryStrc gaAuxLevelEntries[]; // 0x00721D98
static void __stdcall INV_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified);
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __fastcall sub_004521C0_SetTextColor(Unicode* pText, int nColor); // 0x004521C0
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem); // 0x006288A0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0062A1E0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0


void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
extern D2CelFileStrc* gpGoldButtonCel_007BCC34; // 0x007BCC34
extern int gbGoldButtonDown_007BCE30; // 0x007BCE30
extern int gbGoldButtonDown_007BCE34; // 0x007BCE34
extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC
static int __stdcall INV_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight); // 0x00486820

struct D2HirelingIconRecordStrc
{
    int unk0x00[5];
};

#pragma pack(push, 2)
struct D2PanelLabelStrc
{
    int nX;
    int nX2;
    int nY;
    unsigned short nString;
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" size_t __cdecl strlen(const char* szString);
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __cdecl sub_00525150(); // 0x00525150
void __fastcall PLAYER_SetPanelSlide(int nMode); // 0x0045AEA0
Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern); // 0x00526940
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
int __fastcall sub_004A7660_SplitAtNewLine(Unicode* wszText, Unicode** ppSecond); // 0x004A7660
unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0
const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB); // 0x0046A530
extern D2CelFileStrc* gpBankCel; // 0x007BCC2C
extern D2CelFileStrc* gpTradeStashCel; // 0x007BCC3C
extern D2CelFileStrc* gpSuperTransmogrifierCel; // 0x007BCC30
extern D2PanelLabelStrc gaPanelLabels[12]; // 0x006D9AE8
extern void* gpBtnCel; // 0x007BEF7C
extern void* gpCellFile_007BEF78; // 0x007BEF78
extern void* gpCellFile_007BEF10; // 0x007BEF10
extern void* gpCellFile_007BEF2C; // 0x007BEF2C
extern void* gpCellFile_007BEF20; // 0x007BEF20
extern D2HirelingIconRecordStrc* gpHirelingRecords_007BEEAC; // 0x007BEEAC

int gdwGlobal_007BC974; // 0x007BC974

int __cdecl sub_00402A80_IsDbgHelpLoaded(); // 0x00402A80

// 0x0044BFF0
int __cdecl INV_IsRightClickConsumed()
{
    return gbRightClickConsumed != 0;
}

void __cdecl sub_004972B0_InitializePalette(); // 0x004972B0

unsigned int gnQuestTimerValue; // 0x007BCC14

unsigned long gdwQuestTimerTicks; // 0x007BCC18

// 0x004521C0
Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit)
{
    if (pText->wChar)
    {
        unsigned short wszBufferBuf[0x400];
        Unicode* wszBuffer = (Unicode*)wszBufferBuf;
        wszBuffer[0].wChar = 0;
        for (int i = 1; i < 0x400; i++)
        {
            wszBuffer[i].wChar = 0;
        }
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        unsigned short wszDigitBuf[3];
        Unicode* wszDigit = (Unicode*)wszDigitBuf;
        wszDigit[0].wChar = 0;
        wszDigit[1].wChar = 0;
        wszDigit[2].wChar = 0;
        char szDigit[4];
        wsprintfA(szDigit, "%c", (char)(nDigit + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_00526700(wszBuffer, pText);
        sub_005267E0(pText, wszBuffer);
    }
    return pText;
}

// 0x00454970
extern "C" int __cdecl INV_GetScreenHeightMinusPanel()
{
    return gnScreenHeight_00711470 - 49;
}

// 0x0045FDD0
int __cdecl INV_IsPopupDismissed()
{
    return gbPopupDismissed != 0;
}

extern "C" { int gbTradeFlag; } // 0x007BCE28

extern "C" { int gnFlag_007C02EC; } // 0x007C02EC

// 0x004776F0
extern "C" void __cdecl INV_SetRenderModeGlide()
{
    gnLightmapRenderMode = 4;
}

// 0x00477700
extern "C" void __cdecl INV_SetRenderModeOpenGL()
{
    gnLightmapRenderMode = 5;
}

// 0x00477710
extern "C" void __cdecl INV_SetRenderModeDirect3D()
{
    gnLightmapRenderMode = 6;
}

// 0x00477720
extern "C" void __cdecl INV_SetRenderModeRave()
{
    gnLightmapRenderMode = 7;
}

int gnSentBytes; // 0x007A6AF8

int gnSentPackets; // 0x007A6B00


int gnChatDrawCount; // 0x007BB5EC

D2ClientServiceStrc* gpService; // 0x007BC998

int gdwGlobal_007BEEFC; // 0x007BEEFC

// 0x00477EE0
void __cdecl INV_SendLeaveGame()
{
    unsigned char nHeader = 0x69;
// build: symbol ?CLIENT_Send@* 0x0052AE50
    CLIENT_Send(1, 0, &nHeader);
    gnSentBytes += 1;
    gnSentPackets += 1;
    if (gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1 && gdwGlobal_007A0610 != 6 && gdwGlobal_007A0610 != 7
        && gdwGlobal_007A0610 != 8 && gdwGlobal_007A0610 != 9)
    {
        gbLeavingGame = 1;
        gbPositionalSound = 0;
        gbGameServerReady = 0;
    }
    if (gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 7)
    {
        D2ClientNotifyStrc* pNotify = GAME_GetClientNotify();
        if (pNotify)
            pNotify->pfnNotify();
    }
}

struct D2ClientInterfaceStrc
{
    char unk0x00[0x5C];
    int (__cdecl* pfnGetVersion)();
};

struct D2GameLogonPacketStrc
{
    unsigned char nHeader;
    unsigned char nServerHash[4];
    unsigned char f_5[2];
    unsigned char nClass;
    unsigned char nVersion[4];
    unsigned char nKey1[4];
    unsigned char nKey2[4];
    unsigned char f_14;
    char szName[16];
};

D2ClientInterfaceStrc* __cdecl sub_0044D540_GetClientInterface();                                           // 0x0044D540

int __cdecl CHAT_HasClassOverride();                                                                // 0x0047AA30

extern char gszClientCharName[];                                                                         // 0x007A05C4

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

// 0x00477F70
void __fastcall sub_00477F70_SendGameLogon(int nServerToken, int nServerHash)
{
    D2GameLogonPacketStrc tPacket;
    tPacket.nHeader = 0x68;
    *(int*)tPacket.nServerHash = nServerHash;
    *(short*)tPacket.f_5 = (short)nServerToken;
    *(int*)tPacket.nVersion = sub_0044D540_GetClientInterface()->pfnGetVersion();
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    *(unsigned int*)tPacket.nKey1 = FOG_IsExpansion() ? 0xED5DCC50 : 0x2185EDD6;
    *(unsigned int*)tPacket.nKey2 = 0x91A519B6;
    tPacket.f_14 = STRTABLE_GetLanguage();
    tPacket.nClass = CHAT_HasClassOverride() ? sub_0047AA20_GetClassOverride() : gnCharClass_007A0522;
    SStrCopy(tPacket.szName, gszClientCharName, 0x7FFFFFFF);
// build: symbol ?CLIENT_Send@* 0x0052AE50
    CLIENT_Send(sizeof(D2GameLogonPacketStrc), 0, &tPacket);
    gnSentBytes += sizeof(D2GameLogonPacketStrc);
    gnSentPackets += 1;
}

// 0x00478010
void __cdecl sub_00478010()
{
    unsigned char nHeader = 0x6A;
    CLIENT_Send(1, 0, &nHeader);
    gnSentBytes += 1;
    gnSentPackets += 1;
}

// 0x004790B0
void __fastcall INV_FindNodeValues(int nId, int* pValueA, int* pValueB)
{
    for (D2ClientNodeStrc* pNode = gpNodeList_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
        {
            *pValueA = pNode->nValueA;
            *pValueB = pNode->nValueB;
            return;
        }
    }
    *pValueA = 0;
    *pValueB = 0;
}

// 0x0047AD10
void __stdcall INV_ResetImeCompositionMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gwGlobal_007BC850 = 0;
    gwGlobal_007BB5F8 = 0;
    gnChatDrawCount = -2;
    if (gdwGlobal_007BB5DC == 6)
        gnGlobal_007BB5E0 = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047B070
void __stdcall INV_SetMsgHandled(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x0047BC70
void __stdcall INV_CloseChatOnPanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nYpos > gnScreenHeight - 0x31)
        UI_SetUIVar(5, 1, 0);
}

// 0x0047EC40
int __cdecl sub_0047EC40_IsSet()
{
    return gdwGlobal_007BC974 != 0;
}

// 0x0047F8C0
void D2RC4Strc::ApplyKeystream(unsigned char* pData, unsigned int nSize)
{
    for (unsigned int n = 0; n < nSize; ++n)
    {
        ++i;
        j += S[i];
        unsigned char* pA = &S[i];
        unsigned char* pB = &S[j];
        unsigned char t = *pA;
        *pA = *pB;
        *pB = t;
        pData[n] ^= S[(unsigned char)(S[j] + S[i])];
    }
}

// 0x0047FFB0
int __stdcall INV_CallServiceWithTime(int nArg1, int nArg2, int nArg3)
{
    if (!gpService)
        return 0;
    _FILETIME tTime;
    GetSystemTimeAsFileTime(&tTime);
    return gpService->pfnCall(nArg1, nArg2, nArg3, &tTime, -1, -1);
}

// 0x004802E0
void __fastcall INV_ProcessWardenRequest(int nArg1, int nArg2)
{
    if (gpSlotHolder)
    {
        int nOut = 0;
        gpSlotHolder->pObj->Slot2(nArg1, nArg2, &nOut);
        WARDENCLIENT_ActivatePendingModule();
    }
}

// 0x00482CA0
void __fastcall INV_UpdateAuxBattleNetAddress(int nIndex)
{
    const int nType = gaAuxLevelEntries[nIndex].nType;
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d = 0x22;
    unsigned char nLevel;
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        sscanf(szAddress, "%d.%d.%d.%d", &a, &b, &c, &d);
        const unsigned char nLow = d;
        if (nLow & 1)
            nLevel = 7;
        else if (nLow & 0x80)
            nLevel = 6;
        else if (nLow & 0x10)
            nLevel = 5;
        else if (nLow & 0x08)
            nLevel = 4;
        else if (nLow & 0x40)
            nLevel = 3;
        else
            nLevel = (nLow & 4) ? 2 : 1;
    }
    else
    {
        nLevel = 0x22;
    }

    unsigned char nNeeded;
    switch (nType)
    {
    case 2:
        nNeeded = 2;
        break;
    case 3:
        nNeeded = 3;
        break;
    case 4:
        nNeeded = 4;
        break;
    case 5:
    case 6:
        nNeeded = 5;
        break;
    case 7:
        nNeeded = 7;
        break;
    default:
        nNeeded = 1;
        break;
    }

    if (nNeeded > nLevel)
    {
        int nValue;
        switch (nNeeded)
        {
        case 7:
            nValue = 0x23;
            break;
        case 5:
            nValue = 0xB2;
            break;
        case 4:
            nValue = 0x2A;
            break;
        case 3:
            nValue = 0x62;
            break;
        case 2:
            nValue = 0x26;
            break;
        default:
            nValue = 0x22;
            break;
        }
        d = nValue;
        sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, d);
        SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    }
}

// 0x00483300
extern "C" void __cdecl INV_StopCinematic()
{
    gbFlag_007BC9D4 = 1;
}

// 0x00483340
extern "C" void __cdecl INV_ChainCinematic()
{
    gbFlag_007BC9D8 = 1;
}

// 0x00484A70
static const Unicode* INV_GetClassNameText(unsigned int nClass)
{
    if (nClass < 7)
    {
        switch (nClass)
        {
        case 0:
            return D2LANG_GetStringFromTblIndex(0xFAB);
        case 1:
            return D2LANG_GetStringFromTblIndex(0xFAA);
        case 2:
            return D2LANG_GetStringFromTblIndex(0xFA9);
        case 3:
            return D2LANG_GetStringFromTblIndex(0xFA8);
        case 4:
            return D2LANG_GetStringFromTblIndex(0xFA7);
        case 5:
            return D2LANG_GetStringFromTblIndex(0x2771);
        case 6:
            return D2LANG_GetStringFromTblIndex(0x2772);
        }

        return 0;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x69C);
    exit(-1);
}

const Unicode* __fastcall sub_A15_Emit_00484A70(const unsigned char* pClass)
{
    return INV_GetClassNameText(*pClass);
}

// 0x00485240
static void __stdcall INV_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified)
{
    *pnMin = 1;
    *pnMax = 2;
    if (!pUnit || !pItem)
        return;
    int nStatNotDynamic = 0;
    D2UnitStrc* pOwner = STATLIST_GetOwner(gpOwnerSource_007BCBF4, &nStatNotDynamic);
    const int bOwner = pOwner != 0;
    if (pOwner && pOwner != pUnit)
        pUnit = pOwner;
    STATLIST_MergeStatLists(pUnit, pItem, 1);
    const int nMin = STATLIST_UnitGetStatValue(pItem, nStatMin, 0);
    int nMax = STATLIST_UnitGetStatValue(pItem, nStatMax, 0);
    if (!bOwner)
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    else
        STATLIST_MergeStatLists(pUnit, pItem, nStatNotDynamic);
    const int nBaseMin = STATLIST_GetUnitBaseStat(pItem, nStatMin, 0);
    const int nBaseMax = STATLIST_GetUnitBaseStat(pItem, nStatMax, 0);
    if (nBaseMin < nMin || nBaseMax < nMax)
        *pbModified = 1;
    if (nMax <= nMin)
        nMax = nMin;
    const int nByTimeMax = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_MAXDAMAGE_BYTIME, 0);
    if (nByTimeMax && sgptDataTables->nItemStatCostTxtRecordCount > 0x110 && &sgptDataTables->pItemStatCostTxt[0x110] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nAdd = ITEMMODS_GetByTimeAdjustment(nByTimeMax, nPeriod, nBaseTime, 0, 0, 0);
        nMax += nAdd;
        if (nAdd)
            *pbModified = 1;
    }
    const int nByTimePct = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_MAXDAMAGE_PERCENT_BYTIME, 0);
    if (nByTimePct && sgptDataTables->nItemStatCostTxtRecordCount > 0x111 && &sgptDataTables->pItemStatCostTxt[0x111] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nPct = ITEMMODS_GetByTimeAdjustment(nByTimePct, nPeriod, nBaseTime, 0, 0, 0);
        nMax += DATATBLS_ApplyRatio(nMax, nPct, 100);
        if (nPct)
            *pbModified = 1;
    }
    *pnMin = nMin;
    *pnMax = nMax;
}

// 0x00485410
void __stdcall INV_BuildItemDamageText(D2UnitStrc* pItem, Unicode* pBuffer)
{
    unsigned short wszValueBuf[256];
    Unicode* wszValue = (Unicode*)wszValueBuf;
    char szValue[256];
    int bModified;
    int nMax;
    int nMin;

    for (int i = 0; i < sizeof(wszValueBuf) / sizeof(wszValue[0]); ++i)
        wszValue[i].wChar = 0;
    const Unicode* wszSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* wszNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
    D2UnitStrc* pPlayer = sub_00463DD0();

    if (ITEMSIsA(pItem, 0x26))
    {
        int nElemMin;
        nMin = ITEMS_GetMissileType(pItem);
        unsigned short wszTextBuf[256];
        Unicode* wszText = (Unicode*)wszTextBuf;
        for (int i = 0; i < sizeof(wszTextBuf) / sizeof(wszText[0]); ++i)
            wszText[i].wChar = 0;
        int nColor = 0;
        nElemMin = MISSILE_GetMinElemDamage(0, pPlayer, nMin, 1);
        nMax = MISSILE_GetMaxElemDamage(0, pPlayer, nMin, 1);
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);

        switch (MISSILE_GetElemTypeFromMissileId(nMin))
        {
        case 5:
        {
            nColor = 2;
            int nLength = sub_0064B2A0(0, pPlayer, nMin, 1) / 25;
            if (nLength <= 0)
                nLength = 1;
            nElemMin /= nLength;
            nMax /= nLength;
            break;
        }
        case 4:
            nColor = 3;
            break;
        case 1:
            nColor = 1;
            break;
        case 2:
            nColor = 4;
            break;
        }

        nElemMin += MISSILE_GetMinDamage(0, pPlayer, nMin, 1);
        int nElemMax = nMax + MISSILE_GetMaxDamage(0, pPlayer, nMin, 1);
        nElemMin >>= 8;
        nElemMax >>= 8;
        if (nElemMax <= nElemMin)
            nElemMax = nElemMin;

        SStrPrintf(szValue, sizeof(szValue), "%i", nElemMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        if (nElemMin != nElemMax)
        {
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
            SStrPrintf(szValue, sizeof(szValue), "%i", nElemMax);
            sub_00526F20(wszValue, szValue, 9);
            sub_004521C0_SetTextColor(wszValue, nColor);
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, wszValue);
        }
        sub_00526700(wszText, wszNewLine);
        sub_005267E0(pBuffer, wszText);
        return;
    }

    bModified = 0;
    if (ITEMS_Is1Or2Handed(pPlayer, pItem))
    {
        unsigned short wszTwoHandBuf[128];
        Unicode* wszTwoHand = (Unicode*)wszTwoHandBuf;
        unsigned short wszOneHandBuf[128];
        Unicode* wszOneHand = (Unicode*)wszOneHandBuf;

        INV_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszTwoHandBuf) / sizeof(wszTwoHand[0]); ++i)
            wszTwoHand[i].wChar = 0;
        sub_005267E0(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD8A));
        sub_00526700(wszTwoHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszNewLine);

        INV_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszOneHandBuf) / sizeof(wszOneHand[0]); ++i)
            wszOneHand[i].wChar = 0;
        sub_005267E0(wszOneHand, D2LANG_GetStringFromTblIndex(0xD89));
        sub_00526700(wszOneHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszNewLine);

        sub_004521C0_SetTextColor(wszTwoHand, 0);
        sub_004521C0_SetTextColor(wszOneHand, 0);
        sub_005267E0(pBuffer, wszTwoHand);
        sub_00526700(pBuffer, wszOneHand);
    }
    else
    {
        unsigned short nString;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            INV_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
            nString = 0xD8A;
        }
        else
        {
            INV_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
            nString = 0xD89;
        }
        if (nMax <= nMin + 1)
            nMax = nMin + 1;

        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(nString));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszNewLine);
    }

    bModified = 0;
    if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MINDAMAGE_PERCENT, 0) || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MAXDAMAGE_PERCENT, 0)
        || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MINDAMAGE, 0) || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0))
        bModified = 1;

    if (ITEMS_CheckIfThrowable(pItem))
    {
        unsigned short wszTextBuf[256];
        Unicode* wszText = (Unicode*)wszTextBuf;
        for (int i = 0; i < sizeof(wszTextBuf) / sizeof(wszText[0]); ++i)
            wszText[i].wChar = 0;
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);
        INV_GetItemDamageRange(pItem, pPlayer, 0x9F, 0xA0, &nMin, &nMax, &bModified);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        const int nColor = bModified ? 3 : 0;
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszNewLine);
        sub_00526700(pBuffer, wszText);
    }
}

void __stdcall sub_Z12_EmitDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    int nMin, nMax, bModified;
    INV_GetItemDamageRange(pItem, pUnit, 0x1F, 0x20, &nMin, &nMax, &bModified);
    sub_Z12_EmitUse(nMin, nMax, bModified);
}

unsigned char gbFlag_007BCC06; // 0x007BCC06

// 0x00486640
static inline void INV_AppendStringLine(Unicode* pText)
{
    const Unicode* pFirst = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pSecond = D2LANG_GetStringFromTblIndex(0x4FD6);
    sub_00526700(pText, pSecond);
    sub_00526700(pText, pFirst);
}

// 0x00486820
static int __stdcall INV_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

D2NpcButtonStrc gaNpcButtons[4]; // 0x007BC9E0

int gdwTradeCheckTick; // 0x007BCA48

D2CelFileStrc* gpTradePanelCel; // 0x007BCB04

int gnInvPanelMode; // 0x007BCBF0

int gbQuestTimerActive; // 0x007BCC10

D2CelFileStrc* gpHoradricCel; // 0x007BCC1C

void* gpGoldButtonCel; // 0x007BCC34

int gnSelectedShopButton; // 0x007BCC40

int gbCubeItemClicked; // 0x007BCC50

int gbCubeClosed; // 0x007BCC54

void* gpCelInvArmor; // 0x007BCE68

void* gpCelInvBelt; // 0x007BCE6C

void* gpCelInvBoots; // 0x007BCE70

void* gpCelInvHelmGlove; // 0x007BCE74

void* gpCelInvRingAmulet; // 0x007BCE78

void* gpCelInvWeapons; // 0x007BCE7C

void* gpCelTradeBtn; // 0x007BCE80

void* gpCelInvChar6Tab; // 0x007BCE84

void* gpCelNpcInv; // 0x007BCE88

static int gbPanelButtonDown; // 0x007BCE90

// 0x004868B0
void __cdecl INV_LoadInvPanelCels()
{
    gpCelInvArmor = sub_004520C0_LoadUiCelFile("Panel\\inv_armor");
    gpCelInvBelt = sub_004520C0_LoadUiCelFile("Panel\\inv_belt");
    gpCelInvBoots = sub_004520C0_LoadUiCelFile("Panel\\inv_boots");
    gpCelInvHelmGlove = sub_004520C0_LoadUiCelFile("Panel\\inv_helm_glove");
    gpCelInvRingAmulet = sub_004520C0_LoadUiCelFile("Panel\\inv_ring_amulet");
    gpCelInvWeapons = sub_004520C0_LoadUiCelFile("Panel\\inv_weapons");
    gpCelTradeBtn = sub_004520C0_LoadUiCelFile("Panel\\tradebtn");
    gpGoldButtonCel = sub_004520C0_LoadUiCelFile("Panel\\goldcoinbtn");
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        gpCelInvChar6Tab = sub_004520C0_LoadUiCelFile("Panel\\invchar6Tab");
        gbWeaponSwitch_007BCC4C = 0;
        gpCelNpcInv = sub_004520C0_LoadUiCelFile("Panel\\NPCInv");
    }
    else
    {
        gpCelInvChar6Tab = 0;
        gbWeaponSwitch_007BCC4C = 0;
        gpCelNpcInv = 0;
    }
}

// 0x00486980
void __cdecl INV_FreeInvPanelCels()
{
    if (gpHoradricCel)
    {
        ARCHIVE_FreeClientCellFile(gpHoradricCel);
        gpHoradricCel = 0;
    }
    if (gpCelInvArmor)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvArmor);
        gpCelInvArmor = 0;
    }
    if (gpCelInvBelt)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvBelt);
        gpCelInvBelt = 0;
    }
    if (gpCelInvBoots)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvBoots);
        gpCelInvBoots = 0;
    }
    if (gpCelInvHelmGlove)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvHelmGlove);
        gpCelInvHelmGlove = 0;
    }
    if (gpCelInvRingAmulet)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvRingAmulet);
        gpCelInvRingAmulet = 0;
    }
    if (gpCelInvWeapons)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvWeapons);
        gpCelInvWeapons = 0;
    }
    if (gpCelTradeBtn)
    {
        ARCHIVE_FreeClientCellFile(gpCelTradeBtn);
        gpCelTradeBtn = 0;
    }
    if (gpGoldButtonCel)
    {
        ARCHIVE_FreeClientCellFile(gpGoldButtonCel);
        gpGoldButtonCel = 0;
    }
    if (FOG_IsExpansion() && GAME_IsExpansion() && gpCelInvChar6Tab)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvChar6Tab);
        gpCelInvChar6Tab = 0;
    }
    if (gpCelNpcInv)
    {
        ARCHIVE_FreeClientCellFile(gpCelNpcInv);
        gpCelNpcInv = 0;
    }
    if (gpCel_007BCE8C)
    {
        ARCHIVE_FreeClientCellFile(gpCel_007BCE8C);
        gpCel_007BCE8C = 0;
    }
    gpCelInvArmor = 0;
    gpCelInvBelt = 0;
    gpCelInvBoots = 0;
    gpCelInvHelmGlove = 0;
    gpCelInvRingAmulet = 0;
    gpCelInvWeapons = 0;
    gpCelTradeBtn = 0;
    gpGoldButtonCel = 0;
}

void __fastcall sub_M112_Emit_00486640(Unicode* pText)
{
    INV_AppendStringLine(pText);
}

// 0x00486AD0
void __cdecl sub_00486AD0_ToggleFlag()
{
    gbFlag_007BCC06 = gbFlag_007BCC06 == 0;
}

// 0x00486AE0
int __cdecl INV_GetPanelX()
{
    if (!GAME_IsExpansion())
    {
        return gnPanelOffsetX + 0x113;
    }
    return gnPanelOffsetX + 0x110;
}

// 0x00486B00
int __cdecl INV_GetPanelY()
{
    if (!GAME_IsExpansion())
    {
        return gnScreenHeight + gnPanelOffsetY - 0x41;
    }
    return gnScreenHeight + gnPanelOffsetY - 0x40;
}

// 0x00486B30
int __cdecl INV_IsTradeStateInteractive()
{
    switch (gnInvPanelMode)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
        return 0;
    }
    return 0;
}

// 0x00486B80
int __cdecl sub_00486B80_IsNpcStateB()
{
    switch (gnInvPanelMode)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
    case 0x11:
        return 0;
    }
    return 0;
}

// 0x00486D10
int __cdecl INV_CheckTradeClickDelay()
{
    if (!GAME_GetConnectionType() || GAME_GetConnectionType() == 1)
    {
        return 1;
    }
    if (sub_004B9180())
    {
        sub_004B90B0();
        return 0;
    }
    if (GetTickCount() - gdwTradeCheckTick > 0xFA)
    {
        gdwTradeCheckTick = GetTickCount();
        return 1;
    }
    return 0;
}

// 0x00486D70
int __cdecl sub_00486D70_IsNotState11()
{
    return gnInvPanelMode != 0xB;
}

// 0x00486D80
int __cdecl sub_00486D80_IsState1Or2()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2)
    {
        return 1;
    }
    return 0;
}

// 0x00486E10
int __fastcall INV_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnScreenWidth - gnPanelOffsetX - 0x12E || nX > gnScreenWidth - gnPanelOffsetX - 0x10E)
    {
        return 0;
    }
    if (nY < gnScreenHeight + gnPanelOffsetY - 0x60 || nY > gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 0;
    }
    return 1;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00487740
static int __stdcall INV_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
{
    int nOutX;
    int nOutY;
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
    unsigned int nGridX;
    unsigned int nGridY;
    if (!nPage)
    {
        nGridX = (nX - gtPlayerInvGrid.nGridLeft) / gtPlayerInvGrid.nGridBoxWidth;
        nGridY = (nY - gtPlayerInvGrid.nGridTop) / gtPlayerInvGrid.nGridBoxHeight;
    }
    else if (GAME_IsExpansion())
    {
        nGridX = (nX - gtBigBankGrid.nGridLeft) / gtBigBankGrid.nGridBoxWidth;
        nGridY = (nY - gtBigBankGrid.nGridTop) / gtBigBankGrid.nGridBoxHeight;
    }
    else
    {
        nGridX = (nX - gtBankGrid.nGridLeft) / gtBankGrid.nGridBoxWidth;
        nGridY = (nY - gtBankGrid.nGridTop) / gtBankGrid.nGridBoxHeight;
    }

    D2UnitStrc* pItem = sub_0063BD10(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && sub_0062A0A0(pItem))
        {
            if (!ITEM_IsItemActionBlocked(pItem))
            {
                sub_00478680_SendPacket5(0x4C, pItem->dwUnitId);
                sub_004C21F0(pItem);
                return 1;
            }
        }
        else if (sub_00628C20(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
            {
                if (GAME_GetUIVarState(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gbCubeItemClicked = 1;
                }

                sub_004786D0_SendPacket(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                sub_004C21F0(pItem);
                sub_004B9A00(sub_004C1E20(pItem), 0, 0, 0, 0);
                gbHoverInGrid = 0;
                return 1;
            }
        }
        else if (sub_00628C70(pItem))
        {
            D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            const int nCode = pTxt->dwCode;
            if (nCode == 0x20737274 || nCode == 0x20736B62 || nCode == 0x20646B62)
            {
                TEXT_OpenTextData(pItem, pTxt);
            }
            return 1;
        }
    }

    return 0;
}

// 0x00487990
void __cdecl INV_ResetHover()
{
    gnHoverTopX = -1;
    gnHoverTopY = -1;
    gnHoverBottomX = -1;
    gnHoverBottomY = -1;
    gnHoverCellX = -1;
    gnHoverCellY = -1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

// 0x00487B30
void __cdecl INV_ResetNpcState()
{
    gnInvPanelMode = 0;
    gnSelectedTab = 0;
    gbInvGoldButtonDown = 0;
    gnInvMouseX = 0;
    gnInvMouseY = 0;
    if (gpTradePanelCel)
    {
        ARCHIVE_FreeClientCellFile(gpTradePanelCel);
        gpTradePanelCel = 0;
    }
    gdwTradeCheckTick = 0;
}

extern "C" { int gRequest; } // 0x007BCC0C

// 0x00487B70
void __cdecl INV_SetRequest()
{
    gRequest = 1;
}

// 0x00487B80
void __cdecl INV_SetNpcStateTrade()
{
    gnSelectedTab = 0;
    gnInvPanelMode = 0x13;
}

int __stdcall sub_H19_Emit_00487740(D2UnitStrc* pPlayer, int nX, int nY)
{
    return INV_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
}

// 0x00487BA0
static void __stdcall INV_ForwardTradeClick(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!sub_004B3870_HandleTradeClick((D2UnitStrc*)nArg1, (D2UnitStrc*)nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gnInvPanelMode = 5;
    sub_00468070_SetCursorItemState(0);
}

// 0x00487BE0
int __cdecl INV_ResetNpcButtons()
{
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    return 1;
}

// 0x00487C20
void __cdecl INV_ResetNpcButtonsFromPending()
{
    if (gnInvPanelMode == 5)
    {
        gaNpcButtons[0].bActive = 0;
        gaNpcButtons[1].bActive = 0;
        gaNpcButtons[2].bActive = 0;
        gaNpcButtons[3].bActive = 0;
        gnInvPanelMode = 1;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    }
}

// 0x00487C60
void __cdecl INV_AdvancePendingNpcState()
{
    D2_ASSERT(gnInvPanelMode == 5, 0x1EA1);
    gnInvPanelMode = 6;
}

// 0x00487CC0
void __cdecl INV_SelectFirstButton()
{
    gnSelectedShopButton = -1;
    for (int i = 0; i < gnButtonCount; ++i)
    {
        if (gaNpcButtons[i].bActive)
        {
            gnSelectedShopButton = i;
            break;
        }
    }
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
}

// 0x00487D30
void __cdecl INV_SetNpcStateMenuReturn()
{
    gnInvPanelMode = 7;
}

// 0x00487D40
void __cdecl INV_ResetButtonsFromMenuReturn()
{
    D2_ASSERT(gnInvPanelMode == 7, 0x1ED3);
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
}

void __cdecl sub_K04_EmitForward(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    INV_ForwardTradeClick(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7);
    sub_K04_EmitUse(nArg7);
}

// 0x00487DA0
static void INV_SetRepairAllButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0x276F;
    gaPanelButtons_007BC9E0[nButton].nCel = 1;
    gaPanelButtons_007BC9E0[nButton].nType = 8;
    gaPanelButtons_007BC9E0[nButton].nFrame = 0x12;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

// 0x00487DE0
static void INV_SetRepairButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD0A;
    gaPanelButtons_007BC9E0[nButton].nCel = 4;
    gaPanelButtons_007BC9E0[nButton].nType = 1;
    gaPanelButtons_007BC9E0[nButton].nFrame = 6;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

void __cdecl sub_M214_Emit_00487ED0()
{
    INV_SetRepairButton(2);
    INV_SetRepairAllButton(3);
}

// 0x00487E20
static void INV_SetBuyButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD07;
    gaPanelButtons_007BC9E0[nButton].nCel = 2;
    gaPanelButtons_007BC9E0[nButton].nType = 3;
    gaPanelButtons_007BC9E0[nButton].nFrame = 2;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

// 0x00487E60
static void INV_SetSellButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD08;
    gaPanelButtons_007BC9E0[nButton].nCel = 3;
    gaPanelButtons_007BC9E0[nButton].nType = 4;
    gaPanelButtons_007BC9E0[nButton].nFrame = 4;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

// 0x00487EA0
static void INV_ClearButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0;
    gaPanelButtons_007BC9E0[nButton].nCel = 1;
    gaPanelButtons_007BC9E0[nButton].nType = 1;
    gaPanelButtons_007BC9E0[nButton].nFrame = 0;
    gaPanelButtons_007BC9E0[nButton].bActive = 0;
}

void __cdecl INV_SetupPanelButtons()
{
    const int bValue = MONSTER_IsGambleShop();
    int nUnitId;
    if (!sub_004B3230_GetSelectedUnitId(&nUnitId))
        return;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pUnit)
        return;

    if (!bValue)
    {
        gnMaxTab = 1;
        INV_SetBuyButton(0);
        INV_SetSellButton(1);
        gaPanelButtons_007BC9E0[2].nString = 0;
        gaPanelButtons_007BC9E0[2].nCel = 1;
        gaPanelButtons_007BC9E0[2].nType = 1;
        gaPanelButtons_007BC9E0[2].nFrame = 0;
        gaPanelButtons_007BC9E0[2].bActive = 0;
    }
    else
    {
        switch (pUnit->dwClassId)
        {
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
            gnMaxTab = 3;
            INV_SetBuyButton(0);
            INV_SetSellButton(1);
            INV_ClearButton(2);
            break;

        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            gnMaxTab = 3;
            INV_SetBuyButton(0);
            INV_SetSellButton(1);
            gaPanelButtons_007BC9E0[2].nString = 0xD0A;
            gaPanelButtons_007BC9E0[2].nCel = 4;
            gaPanelButtons_007BC9E0[2].nType = 1;
            gaPanelButtons_007BC9E0[2].nFrame = 6;
            gaPanelButtons_007BC9E0[2].bActive = 1;
            gaPanelButtons_007BC9E0[3].nString = 0x276F;
            gaPanelButtons_007BC9E0[3].nCel = 1;
            gaPanelButtons_007BC9E0[3].nType = 8;
            gaPanelButtons_007BC9E0[3].nFrame = 0x12;
            gnButtonCount = 4;
            gaPanelButtons_007BC9E0[3].bActive = 1;
// build: symbol ?gnButtonRow@* 0x0072215C
            gnButtonRow = 3;
            gaPanelButtons_007BC9E0[0].nValue = 0;
            gaPanelButtons_007BC9E0[1].nValue = 0;
            gaPanelButtons_007BC9E0[2].nValue = 0;
            gaPanelButtons_007BC9E0[3].nValue = 0;
            return;

        default:
            gnButtonCount = 0;
            return;
        }
    }

    gaPanelButtons_007BC9E0[3].nString = 0x1030;
    gaPanelButtons_007BC9E0[3].nCel = 9;
    gaPanelButtons_007BC9E0[3].nFrame = 0xA;
    gnButtonCount = 4;
    gaPanelButtons_007BC9E0[3].bActive = 1;
    gnButtonRow = 3;
    gaPanelButtons_007BC9E0[0].nValue = 0;
    gaPanelButtons_007BC9E0[1].nValue = 0;
    gaPanelButtons_007BC9E0[2].nValue = 0;
    gaPanelButtons_007BC9E0[3].nValue = 0;
}

// 0x004880F0
void __cdecl INV_ClearClickPos()
{
    gnInvMouseX = 0;
    gnInvMouseY = 0;
}

// 0x00488100
void __fastcall INV_DrawGold(int nType)
{
    int nOldFont = D2Win_10127_SetFont(1);
    D2GfxDataStrc tData = {};
    tData.nDirection = 0;

    int nGold;
    int nTextX;
    int nTextY;
    int nIconX;
    int nIconY;
    int nFrame;
    switch (nType)
    {
    case 0:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLDBANK, 0);
        nTextX = gnPanelOffsetX + 0xA5;
        if (GAME_IsExpansion())
        {
            nTextY = gnScreenHeight + gnPanelOffsetY - 0x1B8;
            nIconY = gnScreenHeight + gnPanelOffsetY - 0x1B6;
        }
        else
        {
            nTextY = gnScreenHeight + gnPanelOffsetY - 0xF4;
            nIconY = gnScreenHeight + gnPanelOffsetY - 0xF2;
        }
        nIconX = gnPanelOffsetX + 0x49;
        nFrame = gbGoldButtonDown_007BCE34 != 0;
        if (GAME_IsExpansion())
        {
            if (INV_IsMouseInBox(gnPanelOffsetX + 0x49, gnScreenHeight + gnPanelOffsetY - 0x1B6, 0x14, 0x12))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x101C), gnPanelOffsetX + 0x35, gnScreenHeight + gnPanelOffsetY - 0x1CA, 0, 0);
            }
        }
        else
        {
            if (INV_IsMouseInBox(gnPanelOffsetX + 0x49, gnScreenHeight + gnPanelOffsetY - 0xF2, 0x14, 0x12))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x101C), gnPanelOffsetX + 0x35, gnScreenHeight + gnPanelOffsetY - 0x106, 0, 0);
            }
        }
        break;

    case 1:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLD, 0);
        nTextX = gnScreenWidth - gnPanelOffsetX - 0xD4;
        nTextY = gnScreenHeight + gnPanelOffsetY - 0x48;
        nIconY = gnScreenHeight + gnPanelOffsetY - 0x45;
        nIconX = gnScreenWidth - gnPanelOffsetX - 0xED;
        nFrame = gbGoldButtonDown_007BCE30 != 0;
        break;

    default:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLDBANK, 0);
        nTextX = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xCF3)) + gnPanelOffsetX + 0x15;
        nTextY = gnScreenHeight + gnPanelOffsetY - 0x6A;
        nIconX = 0;
        nIconY = 0;
        nFrame = 0;
        break;
    }

    if (nType != 3)
    {
        Unicode wszGold[20] = {};
        char szGold[20];
        SStrPrintf(szGold, 20, szFmtD_006D57BC, nGold);
        sub_00526F20(wszGold, szGold, 19);
        if (nType == 2)
        {
            nTextX = gnPanelOffsetX - D2Win_10121_GetTextWidth(wszGold) + 0xC6;
        }
        D2Win_10117_DrawText(wszGold, nTextX, nTextY, 0, 0);
    }

    switch (nType)
    {
    case 0:
        if (gbGoldButtonDown_007BCE34)
        {
            ++nIconY;
        }
        nIconX += 2;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    case 1:
        if (gbGoldButtonDown_007BCE30)
        {
            ++nIconY;
        }
        nIconX += 1;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    default:
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xCF3), gnPanelOffsetX + 0x15, nTextY, 0, 0);
        break;
    }

    D2Win_10127_SetFont(nOldFont);
}

// 0x00488890
int __cdecl INV_IsNpcShopState()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3 || gnInvPanelMode == 4
        || gnInvPanelMode == 9)
    {
        return 1;
    }

    return 0;
}

// 0x004888C0
int __cdecl INV_CanUseCursor()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 4 || gnInvPanelMode == 3)
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
        {
            return 0;
        }
        const int nMode = sub_00468830();
        if (nMode == 7 || nMode == 1 || nMode == 4)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00488DF0
void __stdcall INV_ConsumeMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00488EC0
void __stdcall INV_ShopKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if ((gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3 || gnInvPanelMode == 4
        || gnInvPanelMode == 9) && !(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 1;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00489190
int __fastcall INV_ClickNpcPanel(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (INV_IsInNpcPanelRect(nX, nY))
    {
        gbPanelButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

int gnGlobal_007BCAF0; // 0x007BCAF0

int gbTradeAcceptedSelf; // 0x007BCD34

int gbTradeAcceptedOther; // 0x007BCE14

int gbTradeAccepted; // 0x007BCE18

int gbTradeCancelClicked; // 0x007BCE1C

int gbTradeAcceptButtonDown; // 0x007BCE20

int gbTradeCancelButtonDown; // 0x007BCE24

D2CelFileStrc* gpBuySellTabsCel; // 0x007BCC24

D2CelFileStrc* gpMiniConvertCel; // 0x007BCC28

D2CelFileStrc* gpShopInvChar6TabCel; // 0x007BCC38

void* gapHirelingIcons[7]; // 0x007BEEB0

// 0x00489220
void __cdecl INV_LoadShopPanelCels()
{
    char szPath[0x104];
    if (!gpBuySellTabsCel)
    {
// build: symbol ?gszDataGlobal@* 0x006D4118
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\buyselltabs", gszDataGlobal);
        gpBuySellTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpMiniConvertCel)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\miniconvert", gszDataGlobal);
        gpMiniConvertCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpShopInvChar6TabCel && FOG_IsExpansion() && GAME_IsExpansion())
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\invchar6tab", gszDataGlobal);
        gpShopInvChar6TabCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

// 0x004892F0
void __cdecl INV_FreeNpcCels()
{
    if (gpTradePanelCel)
    {
        ARCHIVE_FreeClientCellFile(gpTradePanelCel);
        gpTradePanelCel = 0;
    }
    if (gpBuySellTabsCel)
    {
        ARCHIVE_FreeClientCellFile(gpBuySellTabsCel);
        gpBuySellTabsCel = 0;
    }
    if (gpMiniConvertCel)
    {
        ARCHIVE_FreeClientCellFile(gpMiniConvertCel);
        gpMiniConvertCel = 0;
    }
    if (GAME_IsExpansion() && gpShopInvChar6TabCel)
    {
        ARCHIVE_FreeClientCellFile(gpShopInvChar6TabCel);
        gpShopInvChar6TabCel = 0;
    }
}

// 0x00489360
void __fastcall INV_SetTradePanelOpen(int bOpen)
{
    char szPath[0x104];
    if (gbTradeAcceptedSelf || gbTradeAcceptedOther)
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    gbTradeAcceptedSelf = 0;
    gbTradeAcceptedOther = 0;
    gbInvGoldButtonDown = 0;
    if (bOpen)
    {
        gdwTradeCheckTick = 0;
        gnInvPanelMode = 0xB;
        PLAYER_SetPanelSlide(3);
        if (!gpTradePanelCel)
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\trade", gszDataGlobal);
            gpTradePanelCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }
    else
    {
        gnInvPanelMode = 0xA;
        PLAYER_SetPanelSlide(0);
    }
    gbPanelButtonClicked = 0;
    gbTradeAccepted = 0;
    gbTradeCancelClicked = 0;
    gbTradeAcceptButtonDown = 0;
    gbTradeCancelButtonDown = 0;
}

// 0x00489770
void __stdcall INV_TradeBlockMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x004897A0
void __stdcall INV_TradeCancelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!UI_GetUIVarUnchecked(5))
            sub_004B8CB0();
    }
}

// 0x004897E0
void __fastcall INV_UpdateTradeAcceptSound(int bFirst, int bSecond)
{
    if ((gbTradeAcceptedSelf || gbTradeAcceptedOther) && (!bFirst || !bSecond))
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    else if ((!gbTradeAcceptedSelf && bFirst) || (bSecond && !gbTradeAcceptedOther))
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    gbTradeAcceptedSelf = bFirst;
    gbTradeAcceptedOther = bSecond;
}

// 0x00489860
int __cdecl INV_IsSellMode()
{
    return gnInvPanelMode == 4;
}

extern "C" RangeNode* __fastcall sub_0040BCB0_FindRange(unsigned int address, RangeNode* node)
{
    while (node)
    {
        unsigned int start = node->start;
        if (address >= start && address < start + node->size)
            return node;
        node = node->next;
    }
    return 0;
}

extern "C" void __fastcall sub_00468040_SetMode(unsigned int value, unsigned int alternate)
{
    unsigned int result = alternate != 0;
    gValue_007A6ABC = 0;
    gValue_007A6ADC = 0x6;
    gValue_007A6AE0 = value;
    gValue_007A6AF0 = result + 0x7;
}

extern "C" unsigned int __fastcall sub_00479080_FindListValue(unsigned int key)
{
    LookupNode* node = gLookupHead_007BB5BC;
    while (node)
    {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return 0;
}

extern "C" void __cdecl sub_0047BD30_ResetGlobals()
{
    gValue_00712F44 = 0x7;
    gValue_00712F48 = 0x7;
    gValue_007BB5D8 = 0;
    gValue_007BB5E4 = 0;
    gValue_007BB5E8 = 0;
}

// 0x00489880
extern "C" void __cdecl INV_ReturnToStashState()
{
    bool transition = gValue_007BCBF0 == 0xD;
    gValue_007BCE2C = 0;
    if (transition)
        gValue_007BCBF0 = 0xC;
}

// 0x00489A10
void __cdecl INV_CloseStashAndNotify()
{
    UI_SetUIVar(0x19, 1, 0);
    sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
}

// 0x00489CE0
void __stdcall INV_StashCloseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xC)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!UI_GetUIVarUnchecked(5))
        {
            UI_SetUIVar(0x19, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
            gnHoverTopX = -1;
            gnHoverTopY = -1;
            gnHoverBottomX = -1;
            gnHoverBottomY = -1;
            gnHoverCellX = -1;
            gnHoverCellY = -1;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
    }
}

// 0x00489D70
void __stdcall INV_KeyNoRepeatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00489DA0
void __fastcall INV_RecordStashUnitId(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwClassId : -1) != 267)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(sub_00463DD0());
    if (!pPlayerRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pPlayerRoom)) == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
    {
        gnStashObjectId = pUnit->dwUnitId;
    }
}

void __cdecl sub_J08_Emit_0048B540(D2UnitStrc* pUnit)
{
    sub_0048B0A0(pUnit);
    INV_DrawUnitEquippedItems(pUnit);
    INV_DrawMercEquipHighlights(pUnit);
}

U32 gButtonA; // 0x007BCE30

U32 gButtonB; // 0x007BCE34

U32 gPressedFrame; // 0x007BCE38

U32 gButtonLatch; // 0x007BCE3C

void* gArchiveA; // 0x007BCC2C

void* gArchiveB; // 0x007BCC3C

// 0x00489E00
void __cdecl INV_OpenStashPanel()
{
    if (UI_SetUIVar(25, 0, 0))
    {
        gSelectionState = 0;
        CUNIT_ForEachObject(sub_00489DA0);
        gUiState = 12;
        GAME_ResetMouseState();
        gButtonA = 0;
        gButtonB = 0;
        gPressedFrame = 0;
        gButtonLatch = 0;
    }
}

// 0x00489E50
void __cdecl INV_LoadStashPanelCels()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpBankCel)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\bank", gszDataGlobal);
        gpBankCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        if (FOG_IsExpansion())
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\TradeStash", gszDataGlobal);
            gpTradeStashCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }
}

// 0x00489EE0
void __cdecl INV_CloseStashPanel()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        UI_SetUIVar(25, 1, 0);
        sub_00478600(79, 18, 0, 0);
    }
    if (gArchiveA)
    {
        ARCHIVE_FreeClientCellFile(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        ARCHIVE_FreeClientCellFile(gArchiveB);
        gArchiveB = 0;
    }
}

// 0x00489F50
void __cdecl INV_ResetStashPanel()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        UI_SetUIVar(25, 1, 0);
    }
    if (gArchiveA)
    {
        ARCHIVE_FreeClientCellFile(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        ARCHIVE_FreeClientCellFile(gArchiveB);
        gArchiveB = 0;
    }
}

// 0x0048A050
void __cdecl INV_CloseCubePanel()
{
    gbQuestTimerActive = 0;
    UI_SetUIVar(0x1A, 1, 0);
    if (!gbCubeClosed)
    {
        sub_00478600_SendShorts(0x4F, 0x17, 0, 0);
        gbCubeClosed = 1;
    }
    if (gbCubeItemClicked)
    {
        if (CUNIT_FindClientUnit(gnStashObjectId, 2))
        {
            sub_00480930(2, gnStashObjectId);
        }
        gbCubeItemClicked = 0;
    }
}

int gbCubeButtonDown; // 0x007BCE40

int gbCubeButtonClicked; // 0x007BCE44

int gbCubeCloseButtonDown; // 0x007BCE48

int gbCubeCloseClicked; // 0x007BCE4C

// 0x0048A0D0
void __cdecl INV_SendTransmute()
{
    sub_00478600_SendShorts(0x4F, 0x18, 0, 0);
}

// 0x0048A3B0
void __stdcall INV_CubeBlockMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0048A3E0
void __stdcall INV_CubeCloseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!GAME_GetUIVarState(1))
        {
            gnHoverTopX = -1;
            gnHoverTopY = -1;
            gnHoverBottomX = -1;
            gnHoverBottomY = -1;
            gnHoverCellX = -1;
            gnHoverCellY = -1;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        if (!UI_GetUIVarUnchecked(5))
            sub_0048A050();
    }
}

// 0x0048A460
void __cdecl INV_OpenCubePanel()
{
    if (UI_SetUIVar(0x1A, 0, 0))
    {
        gbCubeClosed = 0;
        gnInvPanelMode = 0xE;
        GAME_ResetMouseState();
        gbInvGoldButtonDown = 0;
        gbCubeButtonDown = 0;
        gbCubeButtonClicked = 0;
        gbCubeCloseButtonDown = 0;
        gbCubeCloseClicked = 0;
    }
}

// 0x0048A4B0
void __cdecl INV_LoadCubePanelCel()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpSuperTransmogrifierCel)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\supertransmogrifier", gszDataGlobal);
        gpSuperTransmogrifierCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

void* gUiArchive; // 0x007BCC30

void __cdecl sub_00494EB0_DrawUiRectangle()
{
    InitializePalette();
    sub_004F6300(0, 0, gScreenWidth, gScreenHeight - 49, gColor, 1);
}

// 0x0048A500
void __cdecl INV_ShutdownCubePanel()
{
    if (gUiState == 14)
    {
        gUiState = 0;
        sub_0048A050();
    }
    if (gUiArchive)
    {
        ARCHIVE_FreeClientCellFile(gUiArchive);
        gUiArchive = 0;
    }
}

// 0x0048A540
void __fastcall INV_QuestCodeUpdate(int nCode)
{
    char szPath[0x104];
    D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
    if (nCode == 0x20747368)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 10, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 10, 11);
    }
    else if (nCode == 0x20326671)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 18, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 18, 11);
    }
    gbQuestTimerActive = 1;
    gnQuestTimerValue = 0;
    gdwQuestTimerTicks = GetTickCount();
    if (!gpHoradricCel)
    {
        SStrPrintf(szPath, 0x104, "%s\\ui\\menu\\horadric", gszDataGlobal);
        gpHoradricCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

// 0x0048A600
void __cdecl INV_FreeHoradricCel()
{
    if (gpHoradricCel)
    {
        ARCHIVE_FreeClientCellFile(gpHoradricCel);
        gpHoradricCel = 0;
    }
    gbQuestTimerActive = 0;
    gnQuestTimerValue = 0;
    gdwQuestTimerTicks = 0;
}

// 0x0048A630
void __cdecl INV_EnterNpcMenuState()
{
    gnInvPanelMode = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    D2ClientRecordStrc tRecord;
    tRecord.nId = 0x5A;
    tRecord.nFlag = 1;
    *(int*)&tRecord.nValue0 = 0;
    tRecord.nType = 0x0E;
    sub_0049EB10_PostRecord(&tRecord);
}

// 0x0048A680
void __cdecl INV_ClearPanelPage()
{
    gnGlobal_007BCAF0 = 0;
}

// 0x0048A690
int __cdecl INV_HasHoverItem()
{
    return gpHoverItem != 0;
}

// 0x0048A6A0
void __cdecl INV_ResetNpcCursor()
{
    gbPanelButtonClicked = 0;
    gnInvPanelMode = 0;
    gnInvMouseX = 0;
    gnInvMouseY = 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || !INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        sub_00468070_SetCursorItemState(0);
    }
}

// 0x0048A6E0
extern "C" void __cdecl INV_SetTradeFlag()
{
    gbTradeFlag = 1;
}

// 0x0048A6F0
void __cdecl INV_ClearTradeFlag()
{
    gbTradeFlag = 0;
}

void __cdecl sub_005239C0_ReleaseResources()
{
    if (gResourceA)
    {
        ReleaseResource(gResourceA);
        gResourceA = 0;
    }
    if (gResourceB)
    {
        ReleaseResource(gResourceB);
        gResourceB = 0;
    }
}

// 0x0048A700
void __cdecl INV_ToggleWeaponSwitch()
{
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        gbWeaponSwitch_007BCC4C = !gbWeaponSwitch_007BCC4C;
    }
}

// 0x0048A730
void __cdecl INV_ResetEquipSounds()
{
    if (!FOG_IsExpansion() || !GAME_IsExpansion())
    {
        return;
    }
    sub_004B9A00(1, 0, 0, 0, 0);
    MSG_SendHeaderOnly(0x60);
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pItem)
    {
        sub_004C21F0(pItem);
    }
    pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pItem)
    {
        sub_004C21F0(pItem);
    }
}

// 0x0048A790
int __stdcall INV_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

// 0x0048A7D0
void __stdcall INV_DrawUnitName(D2UnitStrc* pUnit)
{
    unsigned short wszNameBuf[32];
    Unicode* wszName = (Unicode*)wszNameBuf;
    for (int i = 0; i < 32; ++i)
    {
        wszName[i].wChar = 0;
    }
    const int nOldFont = D2Win_10127_SetFont(6);
    Unicode::strncpy(wszName, CUNIT_GetUnitName(pUnit), 32);
    wszName[31].wChar = 0;
    Unicode* pEnd = &wszName[31];
    while (D2Win_10121_GetTextWidth(wszName) > 0xA0)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    D2Win_10117_DrawText(wszName, gnPanelOffsetX + 0xF, 0xD6 - gnPanelOffsetY, 0, 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x0048A890
void __cdecl INV_DrawPanelLabels()
{
    const int nOldFont = D2Win_10127_SetFont(6);
    for (int i = 0; i < sizeof(gaPanelLabels) / sizeof(gaPanelLabels[0]); ++i)
    {
        unsigned short wszTextBuf[100];
        Unicode* wszText = (Unicode*)wszTextBuf;
        for (int j = 0; j < 100; ++j)
        {
            wszText[j].wChar = 0;
        }
        Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(gaPanelLabels[i].nString), 99);
        wszText[99].wChar = 0;
        const int nLeft = gaPanelLabels[i].nX + gnPanelOffsetX;
        const int nRight = gaPanelLabels[i].nX2 + gnPanelOffsetX;
        const int nY = gaPanelLabels[i].nY - gnPanelOffsetY;
        Unicode* pSecond;
        if (sub_004A7660_SplitAtNewLine(wszText, &pSecond))
        {
            TEXT_DrawCenteredText(nLeft, nY - 4, nRight, wszText, 0);
            TEXT_DrawCenteredText(nLeft, nY + 4, nRight, pSecond, 0);
        }
        else if (nRight)
        {
            TEXT_DrawCenteredText(nLeft, nY, nRight, wszText, 0);
        }
        else
        {
            D2Win_10117_DrawText(wszText, nLeft, nY, 0, 0);
        }
    }
    D2Win_10127_SetFont(nOldFont);
}

// 0x0048B290
static int __stdcall INV_CanMercEquipItem(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pbSlotMatch)
{
    *pbSlotMatch = 0;
    if (!GAME_IsExpansion())
        return 0;
    int bResult = 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x302C, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x302F, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMSIsA(pItem, 3) || ITEMSIsA(pItem, 0x25))
    {
        bResult = 1;
        *pbSlotMatch = bResult;
    }
    switch (sub_00479120_GetHirelingClassId(!pUnit ? -1 : pUnit->dwUnitId))
    {
    case 0x10F:
        if (ITEMSIsA(pItem, 0x1B))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x152:
        if (ITEMSIsA(pItem, 0x21) || ITEMSIsA(pItem, 0x22))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x167:
        if (ITEMSIsA(pItem, 2))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x230:
        if (ITEMSIsA(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x231:
        if (ITEMSIsA(pItem, 0x1E))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    }
    if (bResult && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
        bResult = 0;
    return bResult;
}

void __fastcall sub_Z12_EmitCanHirelingEquipItem(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bMatch;
    const int bCan = INV_CanMercEquipItem(pUnit, pItem, &bMatch);
    sub_Z12_EmitUse2(bCan, bMatch);
}

unsigned char gabInvHighlightColors; // 0x007BCAD8

unsigned char gbGlobal_007BCAD9; // 0x007BCAD9

static __forceinline int IsCursorInRectInline(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

static __forceinline void DrawBodyLocRectInline(D2BodyLocRectStrc* pRect, int nColor)
{
    const int nX = pRect->nLeft;
    const int nY = pRect->nTop;
    if (nX >= 0 && nX < gnAutomapWidth && nY >= 0 && nY < gnAutomapHeight_007A521C)
        AUTOMAP_DrawFramedBox(nX, nY, pRect->nWidth, pRect->nHeight, nColor, 0);
}

struct D2InventoryStrc;

struct D2LowQualityItemsTxt
{
    char szName[0x20];
    unsigned short wTblId;
};

struct D2RareAffixTxt
{
    char unk0x00[0x0C];
    unsigned short wStringId;
    char unk0x0E[0x18];
    char szName[0x20];
};

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

#pragma intrinsic(memset, strcpy, strcat, strlen)

#pragma pack(push, 1)

struct D2LevelTextStrc
{
    char c00;
    int n01;
    int n05;
    int n09;
    int n0D;
    char c11;
};

#pragma pack(pop)

#define WSZ(a) ((Unicode*)(a))

#define SZ(a) ((char*)(a))

void __stdcall sub_00403040_ConstructVector(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnCtor)(void*)); // 0x00403040

void __fastcall sub_0042F530_ClearUnicode(void* pChar);                                                     // 0x0042F530

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nSize, const char* szFormat, ...);             // 0x00413A40

unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170

D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440

D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470

const Unicode* __fastcall INV_SkipBracketTag(const Unicode* pString); // 0x004834A0

void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...);                          // 0x0048BE80

int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150

void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefix);                                 // 0x00627EC0

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffix);                                 // 0x00627F80

unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem);                                          // 0x00627FE0

unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem);                                          // 0x00628040

char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem);                                                        // 0x00628340

unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400

D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex);                                     // 0x00633EE0

D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId);                                          // 0x00634260

D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nId);                              // 0x006375C0

int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);                                          // 0x0063CD60

static int INV_FormatEarName(D2UnitStrc* pItem, Unicode* pText);                                   // 0x00484C90

static int __stdcall INV_FormatEarNameTo(D2UnitStrc* pItem, Unicode* pOut, const Unicode* pFormat); // 0x00484D30

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

extern int gbHoverPlayerItem; // 0x00721E38

struct D2BitBufferStrc;

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey);

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

D2UnitStrc* __cdecl CURSOR_GetCursorItem(); // 0x004680A0

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall sub_00478700_SendCommand(char nCommand, int nArg0, int nArg1, int nArg2, int nArg3); // 0x00478700

void __cdecl sub_004A9DF0_UpdateSkillIcons(); // 0x004A9DF0

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230

void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pItem); // 0x004C21F0

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130

unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850

int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0

int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0

int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

static int gbNpcTradeClicked; // 0x007BCBEC

static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0

static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage);

extern D2InvRectStrc gtPlayerInvRect; // 0x007BCAA0

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

D2InventoryGridInfoStrc gtTradePage2Grid;        // 0x007BCA30

D2InventoryGridInfoStrc gtCubeGrid;        // 0x007BCB70

int __cdecl GAME_IsExitPending(); // 0x0044DA30

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __cdecl INV_LoadUiRecords(); // 0x004835B0

int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0

int __cdecl sub_0045AE90(); // 0x0045AE90

void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS*); // 0x00498DC0

void __cdecl sub_0048A730_SwapWeapons(); // 0x0048A730

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

typedef int (__fastcall *D2BodyClickFn)(D2UnitStrc*,D2InventoryStrc*,int);

extern D2BodyClickFn gaBodyClick[]; // 0x00721E58

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY);

static int INV_IsOverWeaponSwapTab(int nX, int nY); // 0x00486860

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0

static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX); // 0x00486E60

static int INV_FormatEarName(D2UnitStrc* pItem, Unicode* pText)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x6EA, ".\\UI\\inv.cpp"))
    {
        const int nQuality = ITEMS_GetItemQuality(pItem);
        if (nQuality >= 5 && nQuality <= 9)
        {
            return 0;
        }

        int aName[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aName[i] = 0;
        }
        int aFormatted[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aFormatted[i] = 0;
        }
        sub_00526F20(WSZ(aName), ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(WSZ(aFormatted), WSZ(aName), pText, 0x200, STRTABLE_GetLanguage());
        sub_005267E0(pText, WSZ(aFormatted));
        return 1;
    }

    return 0;
}

static int __stdcall INV_FormatEarNameTo(D2UnitStrc* pItem, Unicode* pOut, const Unicode* pFormat)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x70B, ".\\UI\\inv.cpp"))
    {
        int aName[0x100];
        for (int i = 0; i < 0x100; ++i)
        {
            aName[i] = 0;
        }
        sub_00526F20(WSZ(aName), ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(pOut, WSZ(aName), pFormat, 0x200, STRTABLE_GetLanguage());
        return 1;
    }

    return 0;
}

static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    return pUnit->dwClassId;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048C060
void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pOut, int nMaxLen)
{
    if (pItem)
    {
        D2ItemsTxt* pItemsTxt;
        const Unicode* pStrF9B;
        const Unicode* pNewLine;
        int nItemType;
        int nLen;

        Unicode aPrefix[0x200];
        Unicode aSuffix[0x200];
        Unicode aLine[0x200];

        pStrF9B = D2LANG_GetStringFromTblIndex(0xF9B);
        pNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
        nLen = 0;
        pItemsTxt = DATATBLS_GetItemsTxtRecord(sub_00623C60(pItem));
        D2_ASSERT(pItemsTxt, 0x732);

        nItemType = ITEMS_GetItemType(pItem);
        if (ITEMS_CheckItemFlag(pItem, 0x4000000, 0x735, ".\\UI\\inv.cpp"))
        {
            Unicode aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(WSZ(aPrefix), INV_SkipBracketTag(WSZ(aName)));
            sub_00526700(WSZ(aPrefix), pNewLine);
            const Unicode* pRuneName = D2LANG_GetStringFromTblIndex(ITEMS_GetPrefixId(pItem, 0));
            if (pRuneName)
            {
                sub_005267E0(WSZ(aSuffix), pRuneName);
            }
            else
            {
                sub_005267E0(WSZ(aSuffix), pStrF9B);
            }
            sub_00526700(WSZ(aLine), WSZ(aSuffix));
            INV_PrefixColorCode(WSZ(aLine), 4);
            sub_00526700(pOut, WSZ(aPrefix));
            sub_00526700(pOut, WSZ(aLine));
        }
        else if (ITEMS_CheckItemFlag(pItem, 0x10, 0x748, ".\\UI\\inv.cpp"))
        {
            switch (ITEMS_GetItemQuality(pItem))
            {
            case ITEMQUAL_INFERIOR:
            {
                D2LowQualityItemsTxt* pLowQuality = DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pLowQuality)
                {
                    INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B0), D2LANG_GetStringFromTblIndex(pLowQuality->wTblId), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                }
                break;
            }
            case ITEMQUAL_NORMAL:
            {
                if (!ITEMSIsA(pItem, 0x16) && !ITEMSIsA(pItem, 0x12))
                {
                    if (ITEMSIsA(pItem, 7))
                    {
                        char szLevel[18] = { 0 };
                        Unicode aEarName[0x100];
                        Unicode aLevelText[3];
                        SStrPrintf(szLevel, 3, "%d", ITEMS_GetEarLevel(pItem));
                        sub_00526F20(WSZ(aLevelText), szLevel, 3);
                        Unicode aUnused[0x100];
                        char aName[20];
                        strcpy(SZ(aName), ITEMS_GetEarName(pItem));
                        sub_00526F20(WSZ(aEarName), SZ(aName), 0x100);
                        if (ITEMS_CheckItemFlag(pItem, 0x8000, 0x775, ".\\UI\\inv.cpp"))
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x1406));
                            sub_00526700(pOut, pNewLine);
                            sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        else
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        sub_00526700(pOut, WSZ(aLevelText));
                        sub_00526700(pOut, pNewLine);
                        sub_00526700(pOut, INV_GetClassNameText(ITEMS_GetFileIndex(pItem)));
                        sub_00526700(pOut, pNewLine);
                        Unicode aText[100] = { 0 };
                        Unicode aFormat[0x200];
                        sub_005267E0(WSZ(aFormat), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                        sub_005272B0_FormatText(WSZ(aText), WSZ(aEarName), WSZ(aFormat), 100, STRTABLE_GetLanguage());
                        sub_00526700(pOut, WSZ(aText));
                    }
                    else if (ITEMSIsA(pItem, 0x28))
                    {
                        D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(ITEMS_GetFileIndex(pItem));
                        INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B4), D2LANG_GetStringFromTblIndex(pMonStatsTxt->wNameStr), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                    }
                    else
                    {
                        D2InventoryStrc* pInventory = pItem->pInventory;
                        if (ITEMS_CheckItemFlag(pItem, 0x800, 0x799, ".\\UI\\inv.cpp") && pInventory && INVENTORY_GetItemCount(pInventory))
                        {
                            INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B3), D2LANG_GetStringFromTblIndex(0x6C0), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                        }
                        else
                        {
                            Unicode aName[0x200];
                            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                            sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                        }
                    }
                }
                else
                {
                    switch (ITEMS_GetSuffixId(pItem, 0))
                    {
                    case 0:
                    {
                        int nString = 0x897;
                        if (nItemType != ITEMTYPE_BOOK)
                        {
                            nString = 0x898;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    case 1:
                    {
                        int nString = 0x899;
                        if (nItemType != ITEMTYPE_BOOK)
                        {
                            nString = 0x89A;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    }
                }
                break;
            }
            case ITEMQUAL_SUPERIOR:
                INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6AF), D2LANG_GetStringFromTblIndex(0x6BF), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                break;
            case ITEMQUAL_RARE:
            case ITEMQUAL_CRAFT:
            case ITEMQUAL_TEMPERED:
            {
                D2RareAffixTxt* pRarePrefix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRarePrefixId(pItem));
                D2RareAffixTxt* pRareSuffix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRareSuffixId(pItem));
                if (pRarePrefix)
                {
                    if (pRarePrefix->wStringId)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRarePrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pRareSuffix)
                {
                    if (pRareSuffix->wStringId)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                    }
                    else
                    {
                        Unicode aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRareSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        nLen += sub_00526800(WSZ(aTemp));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), WSZ(aTemp));
                        }
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x822);
                D2_ASSERT(nLen < nMaxLen, 0x822);

                Unicode aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                sub_005267E0(WSZ(aLine), INV_SkipBracketTag(WSZ(aName)));
                sub_00526700(WSZ(aLine), pNewLine);
                Unicode aFormat[200] = { 0 };
                INV_FormatArgs(WSZ(aFormat), D2LANG_GetStringFromTblIndex(0x6B6), WSZ(aPrefix), WSZ(aSuffix), 0);
                Unicode aEar[0x200];
                if (INV_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aFormat)))
                {
                    sub_00526700(WSZ(aLine), WSZ(aEar));
                }
                else
                {
                    sub_00526700(WSZ(aLine), WSZ(aFormat));
                }
                sub_00526700(pOut, WSZ(aLine));
                break;
            }
            case ITEMQUAL_UNIQUE:
            {
                Unicode aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                if (ITEMS_GetFileIndex(pItem) < 0)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    break;
                }
                D2UniqueItemsTxt* pUniqueItemsTxt = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (!pUniqueItemsTxt)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    break;
                }
                if (!pItemsTxt->nSkipName)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                }
                Unicode aEar[0x200];
                if (INV_FormatEarNameTo(pItem, WSZ(aEar), INV_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex))))
                {
                    sub_00526700(pOut, WSZ(aEar));
                }
                else
                {
                    sub_00526700(pOut, INV_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex)));
                }
                break;
            }
            case ITEMQUAL_SET:
            {
                D2SetItemsTxt* pSetItemsTxt = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pSetItemsTxt)
                {
                    Unicode aName[0x200];
                    sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                    if (pSetItemsTxt->wTblIndex)
                    {
                        Unicode aEar[0x200];
                        Unicode aSetName[0x200];
                        sub_005267E0(WSZ(aSetName), D2LANG_GetStringFromTblIndex(pSetItemsTxt->wTblIndex));
                        if (INV_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aSetName)))
                        {
                            sub_00526700(pOut, WSZ(aEar));
                        }
                        else
                        {
                            Unicode aText[100] = { 0 };
                            INV_FormatArgs(WSZ(aText), D2LANG_GetStringFromTblIndex(0x2769), WSZ(aSetName), 0);
                            sub_00526700(pOut, WSZ(aText));
                        }
                    }
                }
                break;
            }
            case ITEMQUAL_MAGIC:
            {
                D2MagicAffixTxt* pPrefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, 0));
                D2MagicAffixTxt* pSuffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, 0));
                if (pPrefix)
                {
                    if (pPrefix->wTblIndex)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pPrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pSuffix)
                {
                    if (pSuffix->wTblIndex)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                        sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                    }
                    else
                    {
                        Unicode aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen += strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B2), WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), WSZ(aSuffix), 0);
                break;
            }
            default:
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x8CE);
                exit(-1);
            }
        }
        else
        {
            Unicode aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
        }

        INV_FormatEarName(pItem, pOut);
        sub_00452170(pOut);
        if (pItemsTxt->nQuest)
        {
            if (pItemsTxt->nQuestDiffCheck && STATLIST_UnitGetStatValue(pItem, STAT_QUESTITEMDIFFICULTY, 0) < GAME_GetDifficulty())
            {
                INV_PrefixColorCode(pOut, 1);
            }
            else if (pItemsTxt->dwCode != 0x2067656C)
            {
                INV_PrefixColorCode(pOut, 4);
            }
        }
    }
}

// build: symbol ?INV_AppendStackQuantity@* 0x00486100
static void __stdcall INV_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
// build: symbol ?gszFormatLd@* 0x006D9BE8
        SStrPrintf(szNumber, 10, gszFormatLd, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x0048CEA0
static void __stdcall INV_AppendShopPriceText(const Unicode* pSource, Unicode* pText)
{
    Unicode wszName[0x40] = { 0 };
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, pSource);
    if (gnInvPanelMode == 4 && ITEMS_CheckItemFlag(gpHoverItem, 0x400000, 0xCCC, ".\\UI\\inv.cpp"))
    {
        Unicode wszLabel[0x80];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0x58DA));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(wszLabel, 1));
    }

    int nSetIndex;
    if (NPCMENU_GetTradeCostText(gpHoverItem, gbHoverPlayerItem, &nSetIndex, wszName, 0x40))
    {
        if (wszName[0].wChar)
        {
            sub_00526700(pText, pColorEnd);
        }
        sub_00526700(pText, wszName);
        return;
    }

    if (gnInvPanelMode != 4)
    {
        Unicode wszLabel[0x40];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0xD05));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(wszLabel, 1));
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048CFF0
void __cdecl INV_DrawBookTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(gpHoverItem && ITEMS_GetItemType(gpHoverItem) == ITEMTYPE_BOOK, 0xCF1);
    D2_ASSERT(DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId), 0xCF5);

    INV_AppendStackQuantity(gpHoverItem, wszText);
    if (gnInvPanelMode == 0)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89B));
        sub_00526700(wszText, pColorEnd);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89E));
        sub_00526700(wszText, pColorEnd);
    }

    Unicode wszLine[0x80];
    INV_BuildItemName(gpHoverItem, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400];
    if (gnInvPanelMode >= 1 && gnInvPanelMode <= 9)
    {
        INV_AppendShopPriceText(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnHoverTopY - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverTopX, gnHoverTopY, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverBottomX, gnHoverBottomY + nHeight, 0, 0);
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048DB80
void __cdecl INV_DrawTransmogrifyTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (!ITEMS_GetTransmogrify(gpHoverItem))
    {
        return;
    }

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0xE61);
    int nItemId = 0;
    D2ItemsTxt* pBaseTxt = DATATBLS_GetItemRecordFromItemCode(pItemsTxt->dwTransmogrifyType, &nItemId);
    D2_ASSERT(pBaseTxt, 0xE64);

    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(pBaseTxt->wNameStr));
    sub_00526700(wszText, pColorEnd);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_00526700(wszText, pColorEnd);

    Unicode wszLine[0x80];
    INV_BuildItemName(gpHoverItem, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400] = { 0 };
    if ((unsigned int)(gnInvPanelMode - 1) <= 8)
    {
        INV_AppendShopPriceText(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnHoverTopY - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverTopX, gnHoverTopY, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverBottomX, gnHoverBottomY + nHeight, 0, 0);
    }
}

static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gnInvPanelMode == 0xA || gnInvPanelMode == 0xB)
    {
        return 0;
    }
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }
    if (ITEMS_GetMaxSockets(pItem) <= 0)
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    return INVENTORY_GetItemCount(pInventory) < ITEMS_GetSockets(pItem);
}

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid)
{
    D2_ASSERT(pItem, 0x14E8);
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned int nPixelWidth;
    unsigned int nPixelHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    sub_004DBEA0(pItem, 0, 0, &nPixelWidth, &nPixelHeight);
    if (nWidth % 2 == 0)
    {
        nCellX = ((nPixelWidth >> 2) - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
    }
    if (nWidth == pGrid->nGridX)
    {
        nCellX = pGrid->nGridX / 2;
    }
    if (nHeight % 2 == 0)
    {
        nCellY = ((nPixelHeight >> 2) - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
    }
    if (nHeight == pGrid->nGridY)
    {
        nCellY = pGrid->nGridY / 2;
    }
    *pOutX = nCellX;
    *pOutY = nCellY;
    if (nWidth > 1)
    {
        const int n = *pOutX - nWidth / 2;
        *pOutX = n < 0 ? 0 : n;
    }
    if (nHeight > 1)
    {
        const int n = *pOutY - nHeight / 2;
        *pOutY = n < 0 ? 0 : n;
    }
}

// 0x0048FFE0
static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage)
{
    int nResult = 0;
    if (nPage == 0xFF)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion());
    int nGridX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nGridY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    int nOutX;
    int nOutY;

    if (sub_00468830() == 6)
    {
        D2UnitStrc* pCursor = CURSOR_GetCursorItem();
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pCursor && pHit)
        {
            nResult = 1;
            if (!ITEM_IsItemActionBlocked(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && INV_CheckTradeClickDelay())
                {
                    MSG_SendTwoDwords(0x27, !pHit ? -1 : pHit->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
                    ITEM_SetUninterruptableState(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (sub_00468830() == 8)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            nResult = 1;
            if (!ITEM_IsItemActionBlocked(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && INV_CheckTradeClickDelay())
                {
                    sub_00478680_SendPacket5(0x4C, pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (!pCursorItem)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            const int bIsPlayer = pUnit == sub_00463DD0_GetPlayerUnit();
            if (INV_IsTradeStateInteractive() && bIsPlayer == 1)
            {
                if (!ITEM_IsItemActionBlocked(pHit) && INV_CheckTradeClickDelay())
                {
                    if (GetAsyncKeyState(0x11) & 0x8000)
                    {
                        int nNpcId;
                        if (NPCMENU_GetInteractNpcId(&nNpcId))
                        {
                            D2UnitStrc* pNpc = CUNIT_FindClientUnit(nNpcId, 1);
                            if (pNpc)
                            {
                                if (ITEMS_IsNotQuestItem(pHit))
                                {
                                    const int nCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pHit, GAME_GetDifficulty(), MONSTER_GetQuestFlags(), !pNpc ? -1 : pNpc->dwClassId, 1);
                                    sub_00478700_SendCommand(0x33, !pNpc ? -1 : pNpc->dwUnitId, !pHit ? -1 : pHit->dwUnitId, !pHit ? -1 : pHit->dwAnimMode, nCost);
                                }
                                else
                                {
                                    UNITSND_PlayPlayerSpeech(pUnit, 0x13);
                                }
                            }
                        }
                    }
                    else if ((nFlags & 4) && ITEMS_CheckIfBeltable(pHit) && !ITEMS_GetInvPage(pHit))
                    {
                        sub_00478680_SendPacket5(0x63, pHit->dwUnitId);
                        sub_004B9A00(0xEB, 0, 0, 0, 0);
                    }
                    else
                    {
                        sub_00478680_SendPacket5(0x19, pHit->dwUnitId);
                        gbNpcTradeClicked = 1;
                    }
                    nResult = 1;
                    ITEM_SetUninterruptableState(pHit);
                }
            }
            else if (gnInvPanelMode < 0x13)
            {
                INV_ForwardTradeClick((int)pUnit, (int)pHit, bIsPlayer, nX, nY, 0, 0);
            }
        }
    }
    else
    {
        D2UnitStrc* pHit;
        unsigned int nCount;
        INVENTORY_CanItemBePlaced(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pHit, &nCount, nPage);
        D2UnitStrc* pOther = 0;
        int bPlace = 1;
        if (nCount > 1)
        {
            D2UnitStrc* pBox = 0;
            INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pBox, nPage, 1);
            if (pBox && DATATBLS_GetItemsTxtRecord((!pBox ? -1 : pBox->dwClassId))->dwCode == 0x20786F62)
            {
                pHit = pBox;
                goto LBL_CUBE;
            }
        }

        if (pHit && nCount == 1)
        {
            if (ITEMS_AreStackablesEqual(pCursorItem, pHit))
            {
                if (!ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != 0xB && nPage != 2)
                {
                    MSG_SendTwoDwords(0x21, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
            }
            else if (gnHoverCellX >= 0 && gnHoverCellY >= 0)
            {
                if (INV_CanSocketInto(pHit, pCursorItem) && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
                {
                    MSG_SendTwoDwords(0x28, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (ITEMSIsA(pCursorItem, 0x16) && ITEMSIsA(pHit, 0x12)
                    && ITEMS_GetSuffixId(pCursorItem, 0) == ITEMS_GetSuffixId(pHit, 0)
                    && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != 0xB)
                {
                    sub_004A9DF0_UpdateSkillIcons();
                    MSG_SendTwoDwords(0x29, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (DATATBLS_GetItemsTxtRecord(!pHit ? -1 : pHit->dwClassId)->dwCode == 0x20786F62)
                {
LBL_CUBE:
                    if (!ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
                    {
                        int nFreeX;
                        int nFreeY;
                        const int nCubeRecord = UNITS_GetInventoryRecordId(pUnit, 3, GAME_IsExpansion());
                        if (INVENTORY_GetFreePosition(pInventory, pCursorItem, nCubeRecord, &nFreeX, &nFreeY, 3))
                        {
                            MSG_SendTwoDwords(0x2A, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                            ITEM_SetUninterruptableState(pCursorItem);
                            sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                            nResult = 1;
                        }
                        else
                        {
                            UNITSND_PlayPlayerSpeech(pUnit, 0x13);
                        }
                        goto LBL_DONE;
                    }
                }

                if (bPlace && INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 0)
                    && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && nPage != 2)
                {
                    sub_00478700_SendCommand(0x1F, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pOther ? -1 : pOther->dwUnitId, gnHoverCellX, gnHoverCellY);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
LBL_DONE:
                ;
            }
        }
        else
        {
            if (nPage == 3)
            {
                D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord((!pCursorItem ? -1 : pCursorItem->dwClassId));
                D2_ASSERT(pTxt, 0x163A);
                if (pTxt->dwCode == 0x20786F62)
                {
                    return 1;
                }
            }

            int nCellX;
            int nCellY;
            sub_00486BD0_GetItemCell(nX, nY, &nCellX, &nCellY, pCursorItem, pGrid);
            D2UnitStrc* pExchange;
            unsigned int nExchangeCount;
            if (INVENTORY_CanItemBePlaced(pInventory, pCursorItem, nCellX, nCellY, nRecord, &pExchange, &nExchangeCount, nPage)
                && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
            {
                sub_00478700_SendCommand(0x18, (!pCursorItem ? -1 : pCursorItem->dwUnitId), nCellX, nCellY, nPage);
                ITEM_SetUninterruptableState(pCursorItem);
                sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                nResult = 1;
            }
        }
    }
    return nResult;
}

int __stdcall sub_19F4_Emit_0048FFE0(D2UnitStrc* pUnit, unsigned int nX, unsigned int nY, int nFlags)
{
    return INV_ClickInvGrid(pUnit, pUnit->pInventory, nX, nY, nFlags, &gtPlayerInvGrid, gnSelectedTab);
}

int __fastcall sub_00483AB0_IsInInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverWeaponSwapTab(int nX, int nY)
{
    if (nX >= gaCompGrids[5].rect.nLeft && nX <= gaCompGrids[5].rect.nRight && nY >= gaCompGrids[5].rect.nTop - 0x18 && nY < gaCompGrids[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids[4].rect.nLeft && nX <= gaCompGrids[4].rect.nRight && nY >= gaCompGrids[4].rect.nTop - 0x18 && nY < gaCompGrids[4].rect.nTop)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return 0;
    }
    if (nY >= gnScreenHeight + gnPanelOffsetY - 0x57 && nY <= gnScreenHeight + gnPanelOffsetY - 0x45
        && nX >= gnScreenWidth - gnPanelOffsetX - 0xED && nX <= gnScreenWidth - gnPanelOffsetX - 0xD9)
    {
        return 1;
    }
    return 0;
}

static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        return;
    }
    if (nY > gnScreenHeight - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
    }
    if (sub_0045AE90() == 3 && gnInvPanelMode == 0 && nX < gnScreenWidth / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

#define MV(x) (x)

#define PACKET(x) (x)

int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck);  // 0x0063DE60

int __stdcall sub_0062C0B0_GetItemTypeClass(D2UnitStrc* pItem);

// 0x00490780
int __fastcall sub_00490780(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int nBodyLoc)
{
    int nResult = 0;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, MV(5));
    D2UnitStrc* pSelected = INVENTORY_GetItemFromBodyLoc(pInventory, MV(4));
    if (sub_00468830() == MV(6))
    {
        D2UnitStrc* pCursor = CURSOR_GetCursorItem();
        if (pCursor && pSelected && !ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x27), !pSelected ? -1 : pSelected->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
            sub_004C21F0(pSelected);
            nResult = 1;
        }
    }
    else if (sub_00468830() == MV(8))
    {
        if (pSelected && !ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
        {
            sub_00478680_SendPacket5(PACKET(0x4C), !pSelected ? -1 : pSelected->dwUnitId);
            sub_004C21F0(pSelected);
            nResult = 1;
        }
    }
    switch (D2Common_10299(pPlayer, nBodyLoc, pItem, 0))
    {
    case 0:
        if (pItem)
        {
            if (D2Common_10299(pPlayer, nBodyLoc, pItem, 1))
            {
                const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
                if (nClass == MV(7) || nClass == (!pPlayer ? -1 : pPlayer->dwClassId))
                {
                    UNITSND_PlayPlayerSpeech(pPlayer, MV(0x14));
                    return 1;
                }
            }
            UNITSND_PlayPlayerSpeech(pPlayer, MV(0x13));
        }
        return 1;
    case 1:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1A), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 2:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pOther) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1B), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pOther);
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 3:
        if (sub_00486B80_IsNpcStateB())
        {
            if (!ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
            {
                sub_004785B0_SendPacket3(PACKET(0x1C), MV(4));
                sub_004C21F0(pSelected);
                gbNpcTradeClicked = 1;
                nResult = 1;
            }
        }
        else if (gnInvPanelMode < MV(0x13))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pSelected, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        break;
    case 4:
        if (gnInvPanelMode == MV(4))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pOther, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        else if (!ITEM_IsItemActionBlocked(pOther) && INV_CheckTradeClickDelay())
        {
            sub_004785B0_SendPacket3(PACKET(0x1C), MV(5));
            sub_004C21F0(pOther);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 5:
        if (!ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1D), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 7:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pSelected) && !ITEM_IsItemActionBlocked(pOther) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1E), !pItem ? -1 : pItem->dwUnitId, MV(4));
            sub_004C21F0(pItem);
            sub_004C21F0(pSelected);
            sub_004C21F0(pOther);
            nResult = 1;
        }
        break;
    case 6:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != MV(0xB))
        {
            MSG_SendTwoDwords(PACKET(0x21), !pItem ? -1 : pItem->dwUnitId, !pSelected ? -1 : pSelected->dwUnitId);
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    }
    return nResult;
}

// 0x00490BA0
int __fastcall sub_00490BA0(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int nBodyLoc)
{
    int nResult = 0;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, MV(5));
    D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, MV(4));
    if (sub_00468830() == MV(6))
    {
        D2UnitStrc* pCursor = CURSOR_GetCursorItem();
        if (pCursor && pLeft && !ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x27), !pLeft ? -1 : pLeft->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
            sub_004C21F0(pLeft);
            nResult = 1;
        }
    }
    else if (sub_00468830() == MV(8))
    {
        if (pLeft && !ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            sub_00478680_SendPacket5(PACKET(0x4C), !pLeft ? -1 : pLeft->dwUnitId);
            sub_004C21F0(pLeft);
            nResult = 1;
        }
    }
    switch (D2Common_10299(pPlayer, nBodyLoc, pItem, 0))
    {
    case 0:
        if (pItem)
        {
            if (D2Common_10299(pPlayer, nBodyLoc, pItem, 1))
            {
                const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
                if (nClass == MV(7) || nClass == (!pPlayer ? -1 : pPlayer->dwClassId))
                {
                    UNITSND_PlayPlayerSpeech(pPlayer, MV(0x14));
                    return 1;
                }
            }
            UNITSND_PlayPlayerSpeech(pPlayer, MV(0x13));
        }
        return 1;
    case 1:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1A), !pItem ? -1 : pItem->dwUnitId, MV(5));
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 2:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pRight) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1B), !pItem ? -1 : pItem->dwUnitId, MV(5));
            sub_004C21F0(pRight);
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 3:
        if (sub_00486B80_IsNpcStateB())
        {
            if (!ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
            {
                sub_004785B0_SendPacket3(PACKET(0x1C), MV(5));
                sub_004C21F0(pLeft);
                gbNpcTradeClicked = 1;
                nResult = 1;
            }
        }
        else if (gnInvPanelMode < MV(0x13))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pLeft, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        break;
    case 4:
        if (gnInvPanelMode == MV(4))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pRight, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        else if (!ITEM_IsItemActionBlocked(pRight) && INV_CheckTradeClickDelay())
        {
            sub_004785B0_SendPacket3(PACKET(0x1C), MV(4));
            sub_004C21F0(pRight);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 5:
        if (!ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1D), !pItem ? -1 : pItem->dwUnitId, MV(5));
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 7:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pRight) && !ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1E), !pItem ? -1 : pItem->dwUnitId, MV(5));
            sub_004C21F0(pItem);
            sub_004C21F0(pRight);
            sub_004C21F0(pLeft);
            nResult = 1;
        }
        break;
    case 6:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != MV(0xB))
        {
            MSG_SendTwoDwords(PACKET(0x21), !pItem ? -1 : pItem->dwUnitId, !pLeft ? -1 : pLeft->dwUnitId);
            sub_004C21F0(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    }
    return nResult;
}

// 0x00490FC0
int __fastcall sub_00490FC0(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int nBodyLoc)
{
    int nResult = 0;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (sub_00468830() == MV(6))
    {
        pPlayer = CURSOR_GetCursorItem();
        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        if (pPlayer && pItem && !ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(MV(0x27), pItem->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId);
            sub_004C21F0(pItem);
            nResult = 1;
        }
    }
    else if (sub_00468830() == MV(8))
    {
        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        if (pItem && !ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            sub_00478680_SendPacket5(MV(0x4C), pItem->dwUnitId);
            sub_004C21F0(pItem);
            nResult = 1;
        }
    }
    else
    {
        switch (D2Common_10299(pPlayer, nBodyLoc, pItem, 0))
        {
        case 0:
            if (pItem)
            {
                if (D2Common_10299(pPlayer, nBodyLoc, pItem, 1))
                {
                    const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
                    if (nClass == MV(7) || nClass == (!pPlayer ? -1 : pPlayer->dwClassId))
                    {
                        UNITSND_PlayPlayerSpeech(pPlayer, MV(0x14));
                        return 1;
                    }
                }
                UNITSND_PlayPlayerSpeech(pPlayer, MV(0x13));
            }
            return 1;
        case 1:
            if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
            {
                MSG_SendTwoDwords(MV(0x1A), !pItem ? -1 : pItem->dwUnitId, (unsigned short)nBodyLoc);
                sub_004C21F0(pItem);
                sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
                gbNpcTradeClicked = 1;
                nResult = 1;
            }
            break;
        case 3:
            if (sub_00486B80_IsNpcStateB())
            {
                if (INV_CheckTradeClickDelay())
                {
                    sub_004785B0_SendPacket3(MV(0x1C), nBodyLoc);
                    gbNpcTradeClicked = 1;
                    nResult = 1;
                }
            }
            else if (gnInvPanelMode < MV(0x13))
            {
                pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
                INV_ForwardTradeClick((int)pPlayer, (int)pItem, 1, gnInvMouseX, gnInvMouseY, 0, 0);
            }
            break;
        case 5:
            if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
            {
                MSG_SendTwoDwords(MV(0x1D), !pItem ? -1 : pItem->dwUnitId, (unsigned short)nBodyLoc);
                sub_004C21F0(pItem);
                sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
                nResult = 1;
            }
            break;
        }
    }
    return nResult;
}

// 0x004912A0
void __stdcall INV_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if(GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing()) {
        pMsg->bReturn=0;
        return;
    }
    const int y=pMsg->nYpos;
    const int x=pMsg->nXpos;
    if(x>gnScreenWidth) {
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* inventory=player->pInventory;
    int handled=0;
    if(!HIREABLES_AreBeltRowsShown()) {
        if(INV_IsOverGoldButton(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==11 || gnInvPanelMode==12 || gnInvPanelMode==15)) {
            gbInvGoldButtonDown=1;
            sub_004B9A00(4,0,0,0,0);
        }
        if(INV_IsInNpcPanelRect(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==19)) {
            gbPanelButtonDown=1;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    if(!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && sub_00483AB0_IsInInvRect(x,y)) {
        if(INV_IsInNpcPanelRect(x,y)) {
            gbPanelButtonDown=1;
            UI_SetUIVar(1,1,0);
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        pMsg->bReturn=1;
        pMsg->lResult=0;
        int result=0;
        if(x>=gtPlayerInvGrid.nGridLeft && x<=gtPlayerInvGrid.nGridRight && y>=gtPlayerInvGrid.nGridTop && y<=gtPlayerInvGrid.nGridBottom) {
            result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtPlayerInvGrid,0);
            handled=1;
        }
        else {
            int bodyloc=0;
            for(;bodyloc<11;++bodyloc) {
                if(x>=gaCompGrids[bodyloc].rect.nLeft && x<=gaCompGrids[bodyloc].rect.nRight && y>=gaCompGrids[bodyloc].rect.nTop && y<=gaCompGrids[bodyloc].rect.nBottom) goto BODY_FOUND;
            }
            goto AFTER_BODY;
BODY_FOUND:
            {
                D2UnitStrc* cursor=INVENTORY_GetCursorItem(inventory);
                if(sub_00468830()==6 || sub_00468830()==8) {
USE_BODY_ACTION:
                    result=gaBodyClick[bodyloc](player,inventory,bodyloc);
                    handled=1;
                }
                else {
                    D2UnitStrc* bodyItem=INVENTORY_GetItemFromBodyLoc(inventory,bodyloc);
                    if(!INV_CanSocketInto(bodyItem,cursor)) goto USE_BODY_ACTION;
                    if(!ITEM_IsItemActionBlocked(cursor) && INV_CheckTradeClickDelay()) {
                        MSG_SendTwoDwords(0x28,!cursor?-1:cursor->dwUnitId,!bodyItem?-1:bodyItem->dwUnitId);
                        ITEM_SetUninterruptableState(cursor);
                        sub_004B9A00(ITEM_GetDropSound(bodyItem),0,0,0,0);
                        handled=1;
                    }
                    result=0;
                }
            }
AFTER_BODY:
            if(!handled && GAME_IsExpansion() && INV_IsOverWeaponSwapTab(x,y)) {
                pMsg->bReturn=1;
                sub_0048A730_SwapWeapons();
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        pMsg->lResult=0;
        pMsg->bReturn=1;
        if(!result) {
            if(sub_00468830()==6) UI_CancelCursorItemUse();
            else if(sub_00468830()==8) sub_00478680_SendPacket5(0x4C,-1);
        }
        sub_00420290_BreakHandlerChain(pMsg);
        gbHoverInGrid=0;
        gbHoverInBodyLoc=0;
        gpHoverItem=0;
        gpLastHoverItem=0;
        if(!handled) INV_ClickOutsidePanel(y,pMsg,x);
        return;
    }
    switch(gnInvPanelMode) {
    case 14:
        if(x>=gtCubeGrid.nGridLeft && x<=gtCubeGrid.nGridRight && y>=gtCubeGrid.nGridTop && y<=gtCubeGrid.nGridBottom) {
            INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtCubeGrid,3);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        break;
    case 12:
        {
            int left,right,top,bottom;
            if(GAME_IsExpansion()) {
                left=gtBigBankGrid.nGridLeft;right=gtBigBankGrid.nGridRight;top=gtBigBankGrid.nGridTop;bottom=gtBigBankGrid.nGridBottom;
            }
            else {
                left=gtBankGrid.nGridLeft;right=gtBankGrid.nGridRight;top=gtBankGrid.nGridTop;bottom=gtBankGrid.nGridBottom;
            }
            if(x>=left && x<=right && y>=top && y<=bottom) {
                if(GAME_IsExpansion()) INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBigBankGrid,4);
                else INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBankGrid,4);
                pMsg->lResult=0;
                pMsg->bReturn=1;
                gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        break;
    case 11:
        if(x>=gtTradePage2Grid.nGridLeft && x<=gtTradePage2Grid.nGridRight && y>=gtTradePage2Grid.nGridTop && y<=gtTradePage2Grid.nGridBottom) {
            int result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtTradePage2Grid,2);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            if(result) sub_004B90B0_SendState();
            return;
        }
        break;
    }
    pMsg->bReturn=0;
    INV_ClickOutsidePanel(y,pMsg,x);
}

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0

static int __fastcall GetCenteredXInline(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    nWidth /= 2;
    return nX - nWidth;
}

// 0x00495DC0
void __cdecl sub_00495DC0_DrawHelpText()
{
    unsigned short wszLine1Buf[100];
    Unicode* wszLine1 = (Unicode*)wszLine1Buf;
    unsigned short wszLine2Buf[100];
    Unicode* wszLine2 = (Unicode*)wszLine2Buf;
    unsigned short wszLine3Buf[100];
    Unicode* wszLine3 = (Unicode*)wszLine3Buf;
    unsigned short wszLine4Buf[100];
    Unicode* wszLine4 = (Unicode*)wszLine4Buf;
    unsigned short wszLine5Buf[100];
    Unicode* wszLine5 = (Unicode*)wszLine5Buf;

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1066), GetCenteredXInline(0x1066, 0x131), 0x11, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1030), GetCenteredXInline(0x1030, 0x21D), 0x49, 0, 0);

    const int nOldFont = D2Win_10127_SetFont(5);

    for (int i = 0; i < 100; ++i)
    {
        wszLine1[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine1Buf) / sizeof(wszLine1[0]), wszLine1, D2LANG_GetStringFromTblIndex(0x1067), CMDTBL_GetKeyText(0x22, 1));
    D2Win_10117_DrawText(wszLine1, 0x75, 0x4E, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine2[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine2Buf) / sizeof(wszLine2[0]), wszLine2, D2LANG_GetStringFromTblIndex(0x1068), CMDTBL_GetKeyText(0x25, 1));
    D2Win_10117_DrawText(wszLine2, 0x75, 0x62, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine3[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine3Buf) / sizeof(wszLine3[0]), wszLine3, D2LANG_GetStringFromTblIndex(0x1069), CMDTBL_GetKeyText(0x24, 1));
    D2Win_10117_DrawText(wszLine3, 0x75, 0x76, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine4[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine4Buf) / sizeof(wszLine4[0]), wszLine4, D2LANG_GetStringFromTblIndex(0x106A), CMDTBL_GetKeyText(0x7, 1));
    D2Win_10117_DrawText(wszLine4, 0x75, 0x8A, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106B), 0x75, 0x9E, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106C), 0x75, 0xB2, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106D), 0x75, 0xC6, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine5[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine5Buf) / sizeof(wszLine5[0]), wszLine5, D2LANG_GetStringFromTblIndex(0x106E), CMDTBL_GetKeyText(0x6, 1));
    D2Win_10117_DrawText(wszLine5, 0x75, 0xDA, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106F), GetCenteredXInline(0x106F, 0x37), 0x168, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1070), GetCenteredXInline(0x1070, 0x83), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredXInline(0x1071, 0x83), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredXInline(0x1072, 0x83), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1074), GetCenteredXInline(0x1074, 0xB6), 0x181, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1075), GetCenteredXInline(0x1075, 0xB6), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1076), GetCenteredXInline(0x1076, 0xE7), 0x168, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1077), GetCenteredXInline(0x1077, 0x120), 0x181, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1078), GetCenteredXInline(0x1078, 0x120), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1079), GetCenteredXInline(0x1079, 0x162), 0x113, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107A), GetCenteredXInline(0x107A, 0x162), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107B), GetCenteredXInline(0x107B, 0x162), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107C), GetCenteredXInline(0x107C, 0x162), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107D), GetCenteredXInline(0x107D, 0x1C1), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1073), GetCenteredXInline(0x1073, 0x1FB), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredXInline(0x1071, 0x1FB), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredXInline(0x1072, 0x1FB), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107E), GetCenteredXInline(0x107E, 0x24A), 0x168, 0, 0);

    D2Win_10127_SetFont(nOldFont);
}

// 0x00496720
void __stdcall INV_HelpCloseButtonMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (gdwGlobal_007BEEFC)
    {
        if (D2GFX_GetResolutionMode() == 2)
        {
            if (nX >= 0x2AD && nX <= 0x2CD && nY >= 0x18 && nY <= 0x38)
            {
                UI_SetUIVar(0x21, 2, 0);
                sub_00494FC0();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
        else
        {
            if (nX >= 0x20D && nX <= 0x22D && nY >= 0x18 && nY <= 0x38)
            {
                UI_SetUIVar(0x21, 2, 0);
                sub_00494FC0();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
    }
    gdwGlobal_007BEEFC = 0;
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

D2InventoryGridInfoStrc gtHirelingInvGrid; // 0x007BCBC0

// 0x004967F0
void __cdecl INV_LoadPanelCels()
{
    char szPath[0x104];
    gpBtnCel = sub_004520C0_LoadUiCelFile("Panel\\btn");
    const int nLanguage = sub_00525150();
    int bExpansion = 0;
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        bExpansion = 1;
    }
    if (nLanguage >= 6 && nLanguage <= 9)
    {
        if (bExpansion)
        {
            sprintf(szPath, "%s\\UI\\InvChar6", szDataLocal_006D41A8);
        }
        else
        {
            sprintf(szPath, "%s\\UI\\InvChar", szDataLocal_006D41A8);
        }
        gpCellFile_007BEF64 = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    else
    {
        gpCellFile_007BEF64 = sub_004520C0_LoadUiCelFile(bExpansion ? "Panel\\InvChar6" : "Panel\\InvChar");
    }
    gpCellFile_007BEF78 = sub_004520C0_LoadUiCelFile("Panel\\Arrow");
    gpCellFile_007BEF24 = sub_004520C0_LoadUiCelFile("Panel\\Invwarn");
    gpCellFile_007BEF60 = sub_004520C0_LoadUiCelFile("Panel\\DuroIcon");
    gpCellFile_007BEF14 = sub_004520C0_LoadUiCelFile("Panel\\GemSocket");
    gpCellFile_007BEF10 = sub_004520C0_LoadUiCelFile("Panel\\ctrlpnl_popbelt");
    gpCellFile_007BEF68 = sub_004520C0_LoadUiCelFile("Panel\\Hlthmana");
    gpCellFile_007BEF80 = sub_004520C0_LoadUiCelFile("Panel\\overlap");
    gpStateButtonCel_007BEF70 = sub_004520C0_LoadUiCelFile("Panel\\menubutton");
    gpCellFile_007BEF2C = sub_004520C0_LoadUiCelFile("Panel\\menupanel");
    gpCellFile_007BEF20 = sub_004520C0_LoadUiCelFile("Panel\\skillpoints");
    gpGlobal_007BEF0C = sub_004520C0_LoadUiCelFile("Panel\\runbutton");
    gpCellFile_007BEF28 = sub_004520C0_LoadUiCelFile("Panel\\hostilepic");
    memset(gabGlobal_007BEF30, 0, sizeof(gabGlobal_007BEF30));
    SRegLoadValue("Diablo II", "Show HP Text", 0, &gdwShowHpText_007BEFDC);
    SRegLoadValue("Diablo II", "Show MP Text", 0, &gdwShowMpText_007BEFE0);
}

// 0x00497300
void __cdecl INV_DrawKeyBindingPopup()
{
    unsigned short wszTextBuf[200];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 200; ++i)
    {
        wszText[i].wChar = 0;
    }
    unsigned short wszKeyBuf[30];
    Unicode* wszKey = (Unicode*)wszKeyBuf;
    for (int i = 0; i < 30; ++i)
    {
        wszKey[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x1053));
    if (CUNIT_GetHotkeyBinding(0x23, 1) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKeyBuf));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(0x23, 1));
        sub_00526700(wszText, wszKey);
    }
    if (CUNIT_GetHotkeyBinding(0x23, 0) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKeyBuf));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(0x23, 0));
        sub_00526700(wszText, wszKey);
    }
    sub_00502280_SetPopUpText(wszText, gnScreenWidth / 2 - 0x91, gnScreenHeight - 0x17, 0, 1);
}

static inline int INV_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x004A17D0
void __stdcall sub_004A17D0(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007BF23F = 1;
    if (sub_00467A10())
    {
// build: symbol ?gnTextNpcId@* 0x007BF202
// build: symbol ?gbTextFromObject@* 0x007BF20A
        if (gbTextFromObject && CUNIT_FindClientUnit(gnTextNpcId, 1) == sub_00467A10())
            return;
    }
    else if (!sub_00467A10() && gbTextHoverSet)
    {
// build: symbol ?gnTextHoverUnitId@* 0x007BF23B
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnTextHoverUnitId, 1);
        if (pUnit && pUnit == CUNIT_FindClientUnit(gnTextNpcId, 1))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
        }
        return;
    }
    sub_004A1770(pMsg);
}

// 0x004A7A80
extern "C" void __cdecl INV_ClearGoldDialogFlag()
{
    gnFlag_007C02EC = 0;
}

// 0x004AA0C0
void __fastcall INV_SetHotkeySkillSlot(int nSlot, int nValueA, int nValueB, int nValueC)
{
    gaHotkeySkills[nSlot] = nValueA;
    gaHotkeyLeft[nSlot] = nValueB;
    gaHotkeyOwners[nSlot] = nValueC;
}

// 0x004AA8F0
extern "C" void __cdecl INV_ClearSkillPointsHighlight()
{
    gbSkillPointsHighlight = 0;
}

// 0x004B1050
int __fastcall INV_GetMonsterOwnerGuid(D2UnitStrc* pUnit, char* pNotFound, int* pValue)
{
    *pNotFound = 1;
    *pValue = -1;
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nOwnerGUID != -1)
    {
        *pValue = pUnit->pMonsterData->nOwnerGUID;
        *pNotFound = 0;
        return 1;
    }
    return 0;
}

// 0x004B92E0
int __stdcall INV_GetTableByte(int nUnused, int nIndex)
{
    D2_ASSERT(gbQuestIntroFlagsReady, 0x60);
    D2_ASSERT(nIndex < 0x25, 0x65);
    return gaTable_007C0EA4[nIndex];
}

// 0x0048BE00
void __fastcall INV_CutBracketToken(Unicode* pString, const Unicode* pToken)
{
    Unicode wszOpen[2] = { '[', 0 };
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    Unicode* pFound = sub_00526940_UnicodeStrStr(pString, pToken);
    if (pFound)
    {
        pFound += 4;
        const int nLength = sub_00526800(pFound);
        Unicode::strncpy(wszText, pFound, nLength - sub_00526800(sub_00526940_UnicodeStrStr(pFound, wszOpen)));
        sub_005267E0(pString, wszText);
    }
}

// 0x00492770
void __stdcall INV_WeaponSwapKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExpansion())
    {
        if (!(pMsg->lParam & 0x40000000) && !UI_GetUIVarUnchecked(5))
            sub_0048A730();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x00493100
void __stdcall INV_DrawIconNumber(int nValue, int nX)
{
    unsigned short wszConvertedBuf[32];
    Unicode* wszConverted = (Unicode*)wszConvertedBuf;
    for (int i = 0; i < 32; ++i)
    {
        wszConverted[i].wChar = 0;
    }
    unsigned short wszTextBuf[32];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 32; ++i)
    {
        wszText[i].wChar = 0;
    }
    char szNumber[0x20];
    sprintf(szNumber, szIntFormat_006D57BC, nValue);
    memset(wszText, 0, sizeof(wszTextBuf));
    sub_00526320_ToUnicode(wszConverted, szNumber, 32);
    Unicode::strncpy(wszText, wszConverted, 32);
    wszText[31].wChar = 0;
    Unicode* pEnd = &wszText[sub_00526800(wszText)];
    while (D2Win_10121_GetTextWidth(wszText) > 0x2E)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    const int nOldFont = D2Win_10127_SetFont(6);
    D2Win_10117_DrawText(wszText, nX + 8, 0x37, 0, 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x004953C0
int __fastcall INV_GetCenteredX(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    return nX - D2Win_10121_GetTextWidth(wszText) / 2;
}

// 0x0048B3F0
void __fastcall INV_DrawMercEquipHighlights(D2UnitStrc* pUnit)
{
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0()->pInventory);
    if (!pCursorItem)
        return;
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects[i].nLeft > 0 && IsCursorInRectInline(gaBodyLocRects[i].nLeft, gaBodyLocRects[i].nTop, gaBodyLocRects[i].nRight, gaBodyLocRects[i].nBottom))
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            int bMatch;
            if (ITEMS_CheckBodyLocation(pCursorItem, i) && INV_CanMercEquipItem(pUnit, pCursorItem, &bMatch) && ITEMS_CheckRequirements(pCursorItem, pUnit, 0, 0, 0, 0))
                DrawBodyLocRectInline(&gaBodyLocRects[i], gbGlobal_007BCAD9);
            else
                DrawBodyLocRectInline(&gaBodyLocRects[i], gabInvHighlightColors);
        }
    }
}

// 0x0048B540
static void INV_DrawUnitEquippedItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    for (int i = 0; i < 11; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem)
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            const int nX = gaBodyLocRects[i].nLeft
                + (gaBodyLocRects[i].nWidth - nWidth * gtHirelingInvGrid.nGridBoxWidth) / 2;
            const int nY = gaBodyLocRects[i].nTop
                + (gaBodyLocRects[i].nHeight - nHeight * gtHirelingInvGrid.nGridBoxWidth) / 2;
            sub_0046EE80_DrawCursorItem(pItem, nX, nY);
            if (gpHoverItem == pItem && ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0
                && ITEMS_CheckItemFlag(pItem, 0x800, 0x30C8, ".\\UI\\inv.cpp"))
            {
                sub_00483E40(pItem, &gtHirelingInvGrid, nX, nY);
            }
        }
    }
}

// 0x0048B640
D2UnitStrc* __cdecl INV_GetMercUnit()
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pMerc = CUNIT_FindClientUnit(nPetId, 1);
        if (pMerc)
        {
            return pMerc;
        }
    }
    UI_SetUIVar(0x24, 2, 0);
    return 0;
}

// 0x0048B7C0
void __stdcall INV_MercInvClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
    if (nPetId == -1)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
    if (!pPet)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    pMsg->bReturn = 0;
    sub_00467FA0(pMsg);
    gbBuySellPressed = 0;
    if (!IsCursorInRectInline(0, 0, gnScreenWidth / 2, gnScreenHeight - 0x31))
    {
        return;
    }

    if (IsCursorInRectInline(gnPanelOffsetX + 0x110, gnPanelOffsetY + gnScreenHeight - 0x5F, gnPanelOffsetX + 0x130, gnPanelOffsetY + gnScreenHeight - 0x3F))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0()->pInventory);
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects[i].nLeft > 0 && IsCursorInRectInline(gaBodyLocRects[i].nLeft, gaBodyLocRects[i].nTop, gaBodyLocRects[i].nRight, gaBodyLocRects[i].nBottom))
        {
            if (pCursorItem)
            {
                int bSlotMatch = 0;
                if (ITEMS_CheckBodyLocation(pCursorItem, i) && ITEMS_CheckRequirements(pCursorItem, pPet, 0, 0, 0, 0) && INV_CanMercEquipItem(pPet, pCursorItem, &bSlotMatch))
                {
                    sub_004C21F0(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    sub_004785B0_SendPacket3(0x61, 0);
                }
                else if (ITEMS_CheckBodyLocation(pCursorItem, i) && INV_CanMercEquipItem(pPet, pCursorItem, &bSlotMatch) && bSlotMatch)
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x56);
                }
                else
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x55);
                }

                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }

            if (pPet->pInventory)
            {
                D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPet->pInventory, i);
                if (pItem)
                {
                    sub_004C21F0(pItem);
                    sub_004785B0_SendPacket3(0x61, i);
                    gbHoverInGrid = 0;
                    gbHoverInBodyLoc = 0;
                    gpHoverItem = 0;
                }
            }
        }
    }

    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0048BBE0
void __fastcall INV_OpenRecipeScroll(const Unicode* wszName, int nUnused, int nArg)
{
    sub_005267E0(gwszRecipeScrollText, wszName);
    gnRecipeScrollColor = nArg;
    UI_SetUIVar(0x25, 0, 0);
}

#include "gen/data/Source/D2Client/UI/inv.inc"
