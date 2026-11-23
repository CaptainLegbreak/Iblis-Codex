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

extern D2UnitStrc* gpHoverItem; // 0x007BCBF4


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
void __cdecl sub_0044DA70(); // 0x0044DA70
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
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
extern int gbHoverInGrid; // 0x007BCBE4
extern int gnInvPanelMode; // 0x007BCBF0
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
void __fastcall sub_00478590(char nValue); // 0x00478590
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
void __fastcall sub_00480930(int nType, int nUnitId); // 0x00480930
void __cdecl sub_004B90B0(); // 0x004B90B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004C21F0(D2UnitStrc* pItem); // 0x004C21F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
extern int gnStashObjectId; // 0x00721E54
extern int gnButtonCount; // 0x00722160
extern int gnInvMouseX; // 0x007BCA4C
extern int gnGlobal_007BCAF0; // 0x007BCAF0
extern int gnInvMouseY; // 0x007BCBD8
extern int gbHoverInBodyLoc; // 0x007BCBE8
extern D2UnitStrc* gpLastHoverItem; // 0x007BCBF8
extern unsigned char gnSelectedTab; // 0x007BCC04
extern unsigned int gnQuestTimerValue; // 0x007BCC14
extern unsigned long gdwQuestTimerTicks; // 0x007BCC18
extern D2CelFileStrc* gpBuySellTabsCel; // 0x007BCC24
extern D2CelFileStrc* gpMiniConvertCel; // 0x007BCC28
extern D2CelFileStrc* gpShopInvChar6TabCel; // 0x007BCC38
extern int gbWeaponSwitch_007BCC4C; // 0x007BCC4C
extern int gbTradeAcceptedSelf; // 0x007BCD34
extern int gbTradeAcceptedOther; // 0x007BCE14
extern "C" int gbTradeFlag; // 0x007BCE28
extern int gbInvGoldButtonDown; // 0x007BCE30
extern void* gpCel_007BCE8C; // 0x007BCE8C
extern int gbPanelButtonClicked; // 0x007BCE9C

extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78
extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40
extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88
extern int gbCubeItemClicked; // 0x007BCC50
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3); // 0x004786D0
int __cdecl sub_00486D10_CheckTick(); // 0x00486D10
void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt); // 0x0049FF90
int __fastcall sub_004C1E20(D2UnitStrc* pItem); // 0x004C1E20
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
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
int __cdecl sub_004B3500(); // 0x004B3500
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
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
extern D2BodyLocRectStrc gaBodyLocRects[11]; // 0x007BCD38
extern int gnAutomapWidth; // 0x007A5220
extern int gnAutomapHeight_007A521C; // 0x007A521C
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
extern unsigned char gabInvHighlightColors; // 0x007BCAD8
extern unsigned char gbGlobal_007BCAD9; // 0x007BCAD9
void __stdcall sub_00467FA0(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
extern int gbBuySellPressed; // 0x007BCEA0
extern "C" int gnLightmapRenderMode; // 0x00712CCC
extern "C" int gbSkillPointsHighlight; // 0x007C0C3C
extern "C" unsigned char gbFlag_007BC9D4; // 0x007BC9D4
extern "C" unsigned char gbFlag_007BC9D8; // 0x007BC9D8
extern "C" int gnScreenHeight_00711470; // 0x00711470
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
extern int gbCubeClosed; // 0x007BCC54
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
static void sub_0048B540_DrawEquippedItems(D2UnitStrc* pUnit);

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
extern int gbQuestTimerActive; // 0x007BCC10
extern D2CelFileStrc* gpHoradricCel; // 0x007BCC1C
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
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
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
extern int gdwTradeCheckTick; // 0x007BCA48
extern D2CelFileStrc* gpBankCel; // 0x007BCC2C
extern D2CelFileStrc* gpTradeStashCel; // 0x007BCC3C
extern D2CelFileStrc* gpSuperTransmogrifierCel; // 0x007BCC30
extern D2CelFileStrc* gpTradePanelCel; // 0x007BCB04
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
int __cdecl sub_0044BFF0_IsSet()
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

int gbHoverInBodyLoc; // 0x007BCBE8

D2UnitStrc* gpLastHoverItem; // 0x007BCBF8

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
        sub_00455F20(5, 1, 0);
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
int __cdecl sub_00486B00_GetPanelY()
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
int __cdecl sub_00486D10_CheckTick()
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
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY)
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
static int __stdcall sub_00487740_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
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
            if (!sub_004C2240(pItem))
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
            if (!sub_004C2240(pItem) && sub_00486D10_CheckTick())
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
void __cdecl sub_00487B70()
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
    return sub_00487740_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
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
    const int bValue = sub_004B3500();
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
    int nOldFont = sub_00502EF0(1);
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

    sub_00502EF0(nOldFont);
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
int __cdecl sub_004888C0_CanUseCursor()
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
    if (sub_00486E10_IsInNpcPanelRect(nX, nY))
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
    sub_00455F20(0x19, 1, 0);
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
            sub_00455F20(0x19, 1, 0);
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
    sub_0048B540_DrawEquippedItems(pUnit);
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
    if (sub_00455F20(25, 0, 0))
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
        sub_00455F20(25, 1, 0);
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
        sub_00455F20(25, 1, 0);
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
    sub_00455F20(0x1A, 1, 0);
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
    if (sub_00455F20(0x1A, 0, 0))
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
    sub_00478590(0x60);
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
    const int nOldFont = sub_00502EF0(6);
    Unicode::strncpy(wszName, CUNIT_GetUnitName(pUnit), 32);
    wszName[31].wChar = 0;
    Unicode* pEnd = &wszName[31];
    while (D2Win_10121_GetTextWidth(wszName) > 0xA0)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    D2Win_10117_DrawText(wszName, gnPanelOffsetX + 0xF, 0xD6 - gnPanelOffsetY, 0, 0);
    sub_00502EF0(nOldFont);
}

// 0x0048A890
void __cdecl INV_DrawPanelLabels()
{
    const int nOldFont = sub_00502EF0(6);
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
    sub_00502EF0(nOldFont);
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
        sub_0046EFD0_DrawFramedBox(nX, nY, pRect->nWidth, pRect->nHeight, nColor, 0);
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
                sub_00455F20(0x21, 2, 0);
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
                sub_00455F20(0x21, 2, 0);
                sub_00494FC0();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
    }
    gdwGlobal_007BEEFC = 0;
    sub_0044DA70();
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
extern "C" void __cdecl sub_004AA8F0_ClearValue7C0C3C()
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
    const int nOldFont = sub_00502EF0(6);
    D2Win_10117_DrawText(wszText, nX + 8, 0x37, 0, 0);
    sub_00502EF0(nOldFont);
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
static void sub_0048B540_DrawEquippedItems(D2UnitStrc* pUnit)
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
    sub_00455F20(0x24, 2, 0);
    return 0;
}

// 0x0048B7C0
void __stdcall INV_MercInvClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
    if (nPetId == -1)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
    if (!pPet)
    {
        sub_00455F20(0x24, 2, 0);
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
        sub_00455F20(0x24, 2, 0);
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
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
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

    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0048BBE0
void __fastcall INV_OpenRecipeScroll(const Unicode* wszName, int nUnused, int nArg)
{
    sub_005267E0(gwszRecipeScrollText, wszName);
    gnRecipeScrollColor = nArg;
    sub_00455F20(0x25, 0, 0);
}

#include "gen/data/Source/D2Client/UI/inv.inc"
