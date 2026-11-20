#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Path.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define ITEMQUAL_SET 5
#define ITEMQUAL_UNIQUE 7

struct D2ActInfoStrc;
struct D2TileStrc;
struct D2GemsTxt;
struct D2UnitTargetStrc;
struct D2StaticPathStrc;
struct D2ObjectDataStrc;
struct D2GSPacketSrv60;
struct D2GSPacketSrv9C;
struct D2SkillsTxt;
struct D2MotionVectorStrc;
struct D2UnitEventArgsStrc;
struct D2HotspotStrc;
struct D2PanelGfxStrc;
struct D2HintCursorStrc;
struct D2TimedHintStrc;
struct D2FloorTileViewStrc;
struct D2CellNodeStrc;
struct D2CellGridViewStrc;
struct D2AddressInfoStrc;
struct D2AddressQueryStrc;
struct D2SlotObjectStrc;
struct D2SlotStrc;
struct D2SkillStateStrc;
struct D2GSPacketSrv7DStrc;
struct D2UniqueItemsTxt;
struct D2SetItemsTxt;
struct D2PacketRecord8Strc;
struct D2PacketRecord13Strc;
struct D2GSPacketSrv42Strc;
struct D2PacketRecord11Strc;
struct D2CoordStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2GfxMotionStrc;
struct D2CellPosStrc;
struct D2GridCellStrc;
struct D2ItemsTxt;
struct D2ItemSaveStrc;
struct D2GSPacketSrv9D;



struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char InteractType;
    unsigned char nPortalFlags;
};


struct D2GSPacketSrv60
{
    unsigned char nHeader;
    unsigned char nFlags;
    unsigned char nLevel;
    char dwUnitGUID[4];
};

struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};


struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0x74];
    D2SetItemsTxt* pSetItemsTxt;
    int nSetItemsTxtRecordCount;
    char unk0xC20[0x04];
    D2UniqueItemsTxt* pUniqueItemsTxt;
    int nUniqueItemsTxtRecordCount;
};

struct D2GfxMotionStrc
{
    int unk0x00;
    D2MotionVectorStrc tA;
    D2MotionVectorStrc tB;
    char unk0x1C[0xC];
    D2MotionVectorStrc tC;
    int unk0x34;
    int nUnk0x38;
    int nUnk0x3C;
};

struct D2UnitEventArgsStrc
{
    int nX;
    int nY;
    int nArg2;
    int nArg3;
    int nArg4;
    int nArg5;
    int nArg6;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __fastcall sub_00465EE0_RemoveClientSideUnit(int nUnitId, int nUnitType); // 0x00465EE0
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
int __fastcall sub_00480C10_DispatchUnitEvent(int nEvent, D2UnitStrc* pUnit, D2UnitEventArgsStrc* pArgs, int nArg); // 0x00480C10
void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* pItem); // 0x004C2180
void __fastcall sub_004C5420_UseBow(D2UnitStrc* pUnit, int nValue, int nArg2, int nArg3); // 0x004C5420
void __fastcall sub_004C7BE0_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue); // 0x004C7BE0
void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x004E4050
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit); // 0x006222C0
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag); // 0x00622300
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110
int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask); // 0x006287A0
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall sub_00645F00_GetBowValue(D2UnitStrc* pUnit, int* pValue); // 0x00645F00
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

struct D2HotspotStrc
{
    char unk0x00[0x10];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    char unk0x20[0x04];
    char bFlag0x24;
    char bFlag0x25;
    char unk0x26[0x02];
};

struct D2PanelGfxStrc
{
    int unk0x00[15];
    int f_3C;
    int unk0x40[2];
};

struct D2HintCursorStrc
{
    char unk0x00[0x50];
    int aValues[1];
};

struct D2TimedHintStrc
{
    int bActive;
    void* pOwner;
    int nEndTickA;
    int bActive2;
    int nArgE;
    int nEndTickF;
    int nArgG;
    int nEndTickC;
};

struct D2FloorTileViewStrc
{
    char unk0x00[0x3C];
    int nOffsetX;
    int nOffsetY;
    void __thiscall sub_004DE410_DrawFloorTile(D2TileStrc* pTile, int nArg, int nScreenX, int nScreenY, int nX, int nY);
    void __thiscall sub_004DE630_DrawTileAt(int nX, int nY);
    void __thiscall sub_004DE6C0_DrawTileTriple(int nX, int nY, int nStepX, int nStepY);
};

struct D2GridCellStrc
{
    int unk0x00[4];
    D2CellNodeStrc* pNodes;
    int f_14;
    int unk0x18[3];
};

struct D2CellGridViewStrc
{
    int unk0x00;
    int nOffsetX;
    int nOffsetY;
    int unk0x0C[6];
    int nScrollX;
    int nScrollY;
    char unk0x2C[0xEA7C];
    D2GridCellStrc* pCells;
    char unk0xEAAC[0x04];
    int nSize;
    void __thiscall sub_004DF510_DrawCellNodes();
};

struct D2AddressInfoStrc
{
    short nUnk0x00;
    short f_2;
    int nMagic;
    int nUnk0x08;
    short f_C;
    short nVersion;
    int f_10;
};

struct D2AddressQueryStrc
{
    char unk0x00[0x50];
    char bFamilyMatch;
    char unk0x51[0x1B];
    int nSocket;
    int nParam;
    int nResult;
    int nParamOut;
    char unk0x7C[0x05];
    char f_81;
    char unk0x82[0x04];
    char nState[4];
};

struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int f_4;
    char unk0x08[0x2C];
    unsigned int nKey;
};

struct D2SlotStrc
{
    int f_0;
    int unk0x04;
    D2SlotObjectStrc* pObject;
    char unk0x0C[0x14];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszGfxUtilSourceFile[]; // 0x006DB974
extern D2HotspotStrc gaHotspots_00727902[]; // 0x00727902
extern int gnGlobal_007C5474; // 0x007C5474
extern int gnGlobal_007C5480; // 0x007C5480
extern void* gpfnEventTable_00727DB4[2]; // 0x00727DB4
extern int gnGlobal_007C89D8; // 0x007C89D8
extern int gnGlobal_007C89E0; // 0x007C89E0
extern D2TimedHintStrc gTimedHint_007C89E4; // 0x007C89E4
extern void* gpGlobal_007A0634; // 0x007A0634
extern int gdwGlobal_007C8C78; // 0x007C8C78
extern D2SlotStrc gaSlots_007C8A78[16]; // 0x007C8A78
int __cdecl sub_0044DB00(); // 0x0044DB00
int __cdecl sub_0045AE90(); // 0x0045AE90
int __cdecl sub_00463DF0(); // 0x00463DF0
void __fastcall sub_0046EE80(D2UnitStrc* pUnit, int nX, int nY); // 0x0046EE80
void __fastcall sub_00475AA0(int nA, int nB, unsigned char* pByte0, unsigned char* pByte1, unsigned char* pByte2, unsigned char* pByte3); // 0x00475AA0
int __cdecl sub_004817F0(); // 0x004817F0
int __cdecl sub_00481810(); // 0x00481810
int __cdecl sub_00481820(); // 0x00481820
D2HintCursorStrc* __fastcall sub_00481860(int nId); // 0x00481860
int __fastcall sub_004B9590(void* pEntry); // 0x004B9590
void* __fastcall sub_004B9610(int nId); // 0x004B9610
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __cdecl sub_004BFDD0(); // 0x004BFDD0
int __fastcall sub_004DBB50(D2PanelGfxStrc* pGfx, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5, int* pOut, int nArg7, int nArg8); // 0x004DBB50
void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0
int __fastcall sub_004DC110(void* pArg1, int nArg2, int nArg3, int nArg4, void* pfnCallback, int nArg6, int nArg7); // 0x004DC110
void __stdcall sub_004DEF80(D2GridCellStrc* pCell, int nArg, D2CellGridViewStrc* pView); // 0x004DEF80
int __cdecl sub_004F51D0(); // 0x004F51D0
int __fastcall sub_00515710(int nHandle); // 0x00515710
int __fastcall sub_00516760(int nSocket, int* pParam, D2AddressInfoStrc* pInfo); // 0x00516760
int __stdcall sub_006001F0(D2PanelGfxStrc* pGfx, int nArg2, int nArg3); // 0x006001F0
D2TileStrc* __stdcall sub_00619720(void* pAct); // 0x00619720
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall sub_006275B0(D2UnitStrc* pUnit); // 0x006275B0
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x006277F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit, D2SkillStrc* skill); // 0x004D9FC0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0


#pragma pack(push, 1)
struct D2GSPacketSrv7DStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
    int dwItemId;
    int dwAction;
    int bSet;
};

#pragma pack(pop)

void __fastcall sub_0046F280(D2UnitStrc* pUnit, int nComponent); // 0x0046F280
void __fastcall sub_0046F950(D2UnitStrc* pUnit); // 0x0046F950
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60
int __fastcall sub_004C10E0_CanUseItem(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x004C10E0
int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004D9FC0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
unsigned char __stdcall sub_00623D60_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00623D60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __stdcall sub_00629A40(D2UnitStrc* pItem); // 0x00629A40
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
void __stdcall sub_0063D1D0_InventoryItemCall(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D1D0
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2GemsTxt* pGemsTxt, int nArg2, int nArg5); // 0x0065FEC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0

struct D2UniqueItemsTxt
{
    char unk0x00[0x84];
    short wDropSound;
    short wUseSound;
    char unk0x88[0x14C - 0x88];
};

struct D2SetItemsTxt
{
    char unk0x00[0x82];
    short wDropSound;
    short wUseSound;
    char unk0x86[0x1B8 - 0x86];
};

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

#pragma pack(push, 1)
struct D2PacketRecord8Strc
{
    unsigned char nHeader;
    unsigned char nCursor;
    unsigned int dwItemId;
    unsigned short nSkill;
};

struct D2PacketRecord13Strc
{
    unsigned char nHeader;
    unsigned int nItemGUID;
    unsigned int dwFlag;
    unsigned int bSet;
};

struct D2GSPacketSrv42Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

#pragma pack(pop)

extern short gwGlobal_007C78A8; // 0x007C78A8
extern short gwGlobal_007C78AC; // 0x007C78AC
extern int gaCursorKind_00727A40[]; // 0x00727A40
extern unsigned int gnCursorKindCount_00727A48; // 0x00727A48
void __fastcall sub_004B29E0(int nUnitId); // 0x004B29E0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
void __fastcall sub_00468010(D2UnitStrc* pItem, int nCursor); // 0x00468010
extern "C" int gnTable_00727A28[5]; // 0x00727A28
extern "C" unsigned int gnTableCount_00727A3C; // 0x00727A3C
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0
void __stdcall sub_0063BE30_Return(int nUnused1, int nUnused2);
int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C110
int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory); // 0x0063E0B0
extern "C" const char szItemCppFile[];

#pragma pack(push, 1)
struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02[1];
    unsigned int dwUnitId;
    unsigned char unk0x07[4];
};

#pragma pack(pop)

static void sub_004C1350_RefreshEquippedItems(D2UnitStrc* pUnit);

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char bMode;
    unsigned char nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};

#pragma pack(push, 1)
struct D2GSPacketSrv9D
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char pBitstream[244];
};

#pragma pack(pop)

int __cdecl sub_0044DCC0(); // 0x0044DCC0
void __cdecl sub_00453B00_SendMouseMove(); // 0x00453B00
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __cdecl sub_00487990_ResetHover(); // 0x00487990
void __fastcall sub_004B2A00(int nUnitId); // 0x004B2A00
void __fastcall sub_004B2A40(int nUnitId); // 0x004B2A40
void __fastcall sub_004C1910_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bArg); // 0x004C1910
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
int __stdcall sub_0062E410(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410
void __stdcall sub_004C35F0_ItemToBody9D(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave); // 0x004C35F0
void __fastcall sub_004B2640(D2UnitStrc* pUnit); // 0x004B2640
void __fastcall sub_004B2A80_ResetHoverForItem(int nUnitId); // 0x004B2A80
int __cdecl sub_004B2E20_IsQuestActive(); // 0x004B2E20
int __fastcall sub_004B3230_GetTickPair(int* pLow); // 0x004B3230
void __fastcall sub_00498D50(int nX, int nArg); // 0x00498D50
void __cdecl sub_00498D60(); // 0x00498D60
void __fastcall sub_004B2A60(int nUnitId); // 0x004B2A60

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004BDF30
void __fastcall sub_004BDF30_SetPortalStateFromPacket60(D2GSPacketSrv60* pPacket)
{
    D2_ASSERT(pPacket, 0x556);

    D2UnitStrc* pUnit = sub_00463990(*(int*)pPacket->dwUnitGUID, UNIT_OBJECT);
    if (pUnit)
    {
        D2_ASSERT(pUnit->dwClassId == 0x3B || pUnit->dwClassId == 0x3C, 0x560);
        D2_ASSERT(pPacket->nLevel <= 0xFF, 0x562);

        pUnit->pObjectData->InteractType = pPacket->nLevel;

        unsigned char nPortalFlags = UNITS_GetObjectPortalFlags(pUnit);
        if (pPacket->nFlags & 2)
        {
            nPortalFlags |= 2;
        }
        if (pPacket->nFlags & 1)
        {
            nPortalFlags |= 1;
        }
        UNITS_SetObjectPortalFlags(pUnit, nPortalFlags);
    }
}

// 0x004BFBC0
void __fastcall sub_004BFBC0_HitTestHotspots(int nX, int nY)
{
    for (int i = 0; i < gnGlobal_007278FC; i++)
    {
        gaHotspots_00727902[i].bFlag0x25 = 0;
        gaHotspots_00727902[i].bFlag0x24 = 0;
    }

    for (int i = 0; i < gnGlobal_007278FC; i++)
    {
        if (nX >= gaHotspots_00727902[i].nLeft && nX <= gaHotspots_00727902[i].nRight && nY >= gaHotspots_00727902[i].nTop && nY <= gaHotspots_00727902[i].nBottom)
        {
            sub_004B9A00(1, 0, 0, 0, 0);
            gaHotspots_00727902[i].bFlag0x25 = 1;
            gaHotspots_00727902[i].bFlag0x24 = 1;
        }
    }
}

// 0x004C01E0
void __cdecl sub_004C01E0_DrawPanelUnit()
{
    if (gnGlobal_007C5474)
    {
        if (sub_00463DF0())
        {
            sub_004C0090();
            return;
        }

        sub_004BFDD0();
        if (gnGlobal_007C5474 == 2)
        {
            D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C5480, 4);
            if (pUnit)
            {
                D2PanelGfxStrc tGfx;
                int nOut;
                memset(&tGfx, 0, sizeof(tGfx));
                if (sub_004DBB50(&tGfx, pUnit, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tGfx, 0, 1) && tGfx.f_3C)
                {
                    unsigned int nWidth;
                    unsigned int nHeight;
                    sub_004DBEA0(pUnit, 0, 0, &nWidth, &nHeight);
                    UNITS_ChangeAnimMode(pUnit, 0);
                    int nOffsetY = 0;
                    if (nHeight < 0x70)
                    {
                        nOffsetY = (0x72 - nHeight) >> 1;
                    }
                    sub_0046EE80(pUnit, 0xA7 - (nWidth >> 1), nOffsetY + 0x6A);
                    UNITS_ChangeAnimMode(pUnit, 4);
                }
            }
        }
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x31D);
        exit(-1);
    }
}

// 0x004C0EC0
void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp)
{
    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwUnitType == 0)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp") || bForce)
    {
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    }

    if (bClamp)
    {
        sub_006275B0(pUnit);
    }
}

#include "gen/data/Source/D2Client/UNIT/Item.inc"

// 0x004C10C0
int __fastcall sub_004C10C0_IsSkillStateUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (sub_004D9FC0(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }
    return 1;
}

// 0x004C10E0
int __fastcall sub_0055DB00_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bResult = ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0);
    if (bResult && ITEMS_GetQuiverType(pItem))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pOtherArmItem == pItem)
        {
            pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        }

        if (!pOtherArmItem || !ITEMSIsA(pOtherArmItem, ITEMS_GetQuiverType(pItem)))
        {
            bResult = 0;
        }
    }

    return bResult;
}

static void __stdcall sub_004C0D20_ApplyItemStats(D2UnitStrc* pUnit, D2UnitStrc* pItem, int bForce)
{
    D2ItemsTxt* pItemsTxtRecord;
    D2GemsTxt* pGemsTxtRecord;

    if (!pUnit)
    {
        return;
    }

    if (ITEMSIsA(pItem, 0x14))
    {
        D2_ASSERT(pUnit->dwUnitType == 4, 0x30);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        sub_0065FEC0_ItemApplyProps(2, NULL, pItem, pGemsTxtRecord, sub_00629A40(pUnit), 0);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        D2_ASSERT(pUnit->dwUnitType == 4, 0x3A);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        sub_0065FEC0_ItemApplyProps(5, pUnit, pItem, pGemsTxtRecord, sub_00629A40(pUnit), 0);
    }
    else
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x48, ".\\UNIT\\Item.cpp"))
    {
        return;
    }

    if (pUnit->dwUnitType == 0)
    {
        D2UnitStrc* pLeftHand = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        if (UNITS_CanDualWield(pUnit))
        {
            int bType = 1;
            if (pLeftHand && pItem != pLeftHand && ITEMSIsA(pItem, 0x2D))
            {
                bType = 0;
            }

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0x64, ".\\UNIT\\Item.cpp") && !bForce)
            {
                return;
            }

            STATLIST_MergeStatLists(pUnit, pItem, bType);
            return;
        }
    }

    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x70, ".\\UNIT\\Item.cpp") && !bForce)
    {
        return;
    }

    STATLIST_MergeStatLists(pUnit, pItem, 1);
}

static void sub_004C1160_SaveSkillState(D2SkillStateStrc* pState, D2UnitStrc* pUnit)
{
    pState->nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    pState->nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
    pState->nStamina = STATLIST_UnitGetStatValue(pUnit, 0x0A, 0);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pState->nLeftOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\UNIT\\Item.cpp", 0x155);
    }
    else
    {
        pState->nLeftOwnerGUID = -1;
        pState->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pState->nRightOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\UNIT\\Item.cpp", 0x161);
    }
    else
    {
        pState->nRightOwnerGUID = -1;
        pState->nRightSkillId = 0;
    }
}

static void sub_004C1200_RestoreSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState)
{
    if (pState->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit))
        {
            switch (sub_004D9FC0_GetSkillUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetLeftActiveSkill(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
                break;
            }
        }
    }

    if (pState->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit))
        {
            switch (sub_004D9FC0_GetSkillUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetRightActiveSkill(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
                break;
            }
        }
    }
}

static __declspec(noinline) void __stdcall sub_004C1290_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem || !pUnit->pInventory)
        return;

    INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
    if (pUnit->dwUnitType == 0)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
    sub_0046F280(pUnit, nComponent);
}

// 0x004C12F0
static __declspec(noinline) void __stdcall sub_004C12F0_ReattachItem(int nMode, int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem)
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0x0B || nBodyLoc == 0x0C)
        return;

    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    sub_0046F280(pUnit, nComponent);
    if (nMode == 1 && !STATLIST_GetOwner(pItem, NULL))
        sub_004C0D20_ApplyItemStats(pUnit, pItem, 1);

    sub_0063D1D0_InventoryItemCall(pInventory, pItem);
}

// 0x004C16C0
static void sub_004C16C0_RefreshUnitItems(D2UnitStrc* pUnit)
{
    sub_004C1350_RefreshEquippedItems(pUnit);
}

static __forceinline int sub_H18_UnitFlag9(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

static void sub_004C1350_RefreshEquippedItems(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (pUnit->dwUnitType && !sub_H18_UnitFlag9(pUnit))
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    D2SkillStateStrc tState;
    int bChanged = 0;
    sub_004C1160_SaveSkillState(&tState, pUnit);

    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (pItem && INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit)
            && !STATLIST_GetOwner(pItem, NULL) && sub_004C10E0_CanUseItem(pUnit, pItem))
        {
            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
        }
    }

    for (int i = 0; i < 0x0B; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (!pItem)
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x203, ".\\UNIT\\Item.cpp") && !STATLIST_GetOwner(pItem, NULL))
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x208, ".\\UNIT\\Item.cpp") && !STATLIST_GetOwner(pItem, NULL))
            continue;

        if (sub_004C10E0_CanUseItem(pUnit, pItem))
            continue;

        ITEMS_SetItemFlag(pItem, 0x4000, 1);
        sub_004C1290_AttachItem(sub_00623D60_GetItemComponent(pUnit, pItem), pUnit, pItem);
        bChanged = 1;
    }

    int nTries = 100;
    int bMore;
    do
    {
        bMore = 0;
        for (int i = 0; i < 0x0B; ++i)
        {
            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
            if (!pItem)
                continue;

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0x226, ".\\UNIT\\Item.cpp"))
                continue;

            if (!ITEMS_CheckItemFlag(pItem, 0x4000, 0x22A, ".\\UNIT\\Item.cpp") && STATLIST_GetOwner(pItem, NULL))
                continue;

            if (!sub_004C10E0_CanUseItem(pUnit, pItem))
                continue;

            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            const int nComponent = sub_00623D60_GetItemComponent(pUnit, pItem);
            const int nMode = pItem->dwAnimMode;
            D2InventoryStrc* pBodyInventory = pUnit->pInventory;
            if (pBodyInventory)
            {
                const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
                if (nBodyLoc != 0x0B && nBodyLoc != 0x0C)
                {
                    INVENTORY_UpdateWeaponGUIDOnRemoval(pBodyInventory, pItem);
                    sub_0046F280(pUnit, nComponent);
                    if (nMode == 1 && !STATLIST_GetOwner(pItem, NULL))
                        sub_004C0D20_ApplyItemStats(pUnit, pItem, 1);

                    sub_0063D1D0_InventoryItemCall(pBodyInventory, pItem);
                }
            }
            bMore = 1;
            bChanged = 1;
        }
    }
    while (bMore && nTries--);

    for (int i = 0; i < 0x0B; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem && ITEMS_GetItemQuality(pItem) == 5 && !ITEMS_CheckItemFlag(pItem, 0x100, 0x247, ".\\UNIT\\Item.cpp")
            && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x248, ".\\UNIT\\Item.cpp"))
        {
            if (pUnit->dwUnitType == 0)
                INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

            ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
        }
    }

    sub_004C1200_RestoreSkillState(pUnit, &tState);
    if (bChanged)
    {
        if (pUnit->dwUnitType == 0)
        {
            sub_0046F950(pUnit);
            sub_00470610_Refresh(pUnit, 0);
        }
        else
        {
            sub_004AFF60_MonsterCommand(7, pUnit, NULL);
        }
    }
}

// 0x004C17F0
static int sub_004C17F0_GetItemUseSound(D2UnitStrc* pItem)
{
    int nSound = 0;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxtRecord && pItemsTxtRecord->wDropSound > 0)
        nSound = pItemsTxtRecord->wUseSound;

    if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE)
    {
        const int nIndex = ITEMS_GetFileIndex(pItem);
        D2UniqueItemsTxt* pRecord = (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount) ? &sgptDataTables->pUniqueItemsTxt[nIndex] : 0;
        if (pRecord && pRecord->wDropSound > 0)
            nSound = pRecord->wUseSound;
    }
    else if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        const int nIndex = ITEMS_GetFileIndex(pItem);
        D2SetItemsTxt* pRecord = (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nIndex] : 0;
        if (pRecord && pRecord->wDropSound > 0)
            nSound = pRecord->wUseSound;
    }

    return nSound;
}

// 0x004C1B80
void __fastcall sub_004C1B80_ItemCommand(int nEvent, D2UnitStrc* pUnit, int bSet, int nMode)
{
    switch (nEvent)
    {
    case 2:
        UNITS_ChangeAnimMode(pUnit, nMode);
        if (pUnit)
        {
            if (bSet)
            {
                pUnit->dwFlags |= 2;
            }
            else
            {
                pUnit->dwFlags &= ~2;
            }
        }
        break;
    }
}

// 0x004C1BC0
void __fastcall sub_004C1BC0(D2PacketRecord11Strc* pPacket, int nArg)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
        sub_004C16C0_RefreshUnitItems(pUnit);
}

// 0x004C1C50
int __fastcall sub_004C1C50_PlaceBodyItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc)
{
    if (!pItem)
    {
        return 0;
    }

    if (INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc))
    {
        sub_0063BE30(pInventory, nBodyLoc);
    }

    return sub_0063BDB0(pInventory, pItem, nBodyLoc) != 0;
}

static __forceinline D2UniqueItemsTxt* ITEMS_GetUniqueItemsTxtRecordInline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nUniqueItemsTxtRecordCount)
        return &sgptDataTables->pUniqueItemsTxt[nId];
    return 0;
}

static __forceinline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordInline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSetItemsTxtRecordCount)
        return &sgptDataTables->pSetItemsTxt[nId];
    return 0;
}

// 0x004C1D60
int __fastcall sub_004C1D60(D2UnitStrc* pItem)
{
    int nSound = 0;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxt && pItemsTxt->wDropSound > 0)
        nSound = pItemsTxt->wDropSound;

    if (ITEMS_GetItemQuality(pItem) == 7)
    {
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxt = ITEMS_GetUniqueItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxt && pUniqueItemsTxt->wDropSound > 0)
                nSound = pUniqueItemsTxt->wDropSound;
        }
    }
    else if (ITEMS_GetItemQuality(pItem) == 5)
    {
        D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxt && pSetItemsTxt->wDropSound > 0)
            nSound = pSetItemsTxt->wDropSound;
    }
    return nSound;
}

// 0x004C1E20
int __fastcall sub_004C1E20_GetItemUseSound(D2UnitStrc* pItem)
{
    return sub_004C17F0_GetItemUseSound(pItem);
}

// 0x004C1E30
void __cdecl sub_004C1E30()
{
    gwGlobal_007C78A8 = 0;
    gwGlobal_007C78AC = 0;
}

// 0x004C2020
void __fastcall sub_004C2020(D2PacketRecord13Strc* pPacket)
{
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemGUID, 4);
    if (pItem)
        ITEMS_SetItemFlag(pItem, pPacket->dwFlag, pPacket->bSet);
}

// 0x004C2050
void __fastcall sub_004C2050(D2GSPacketSrv42Strc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitGUID, pPacket->nUnitType);
    if (!pUnit)
        return;
    if (pUnit != sub_00463DD0())
        return;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (!pItem)
        return;
    int nItemId = pItem->dwUnitId;
    INVENTORY_SetCursorItem(pInventory, 0);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_00465EE0_RemoveClientSideUnit(nItemId, pItem->dwUnitType);
    sub_004B29E0(nItemId);
}

// 0x004C2150
int __fastcall sub_004C2150_FindInTable(int nValue)
{
    for (unsigned int i = 0; i < gnTableCount_00727A3C; ++i)
    {
        if (nValue == gnTable_00727A28[i])
            return 4;
    }
    return 3;
}

// 0x004C2180
void __fastcall sub_004C2180_UpdateCursorItem(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0xCC2);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(hItem, 0x36);
    if (pStatList)
    {
        STATES_ToggleState(hItem, 0x36, 0);
        D2Common_10474(hItem, pStatList);
        STATLIST_FreeStatList(pStatList);
        UnitUpdateAnimRateAndVel(hItem, ".\\UNIT\\Item.cpp", 0xCCA);
    }
}

// 0x004C21E0
void __fastcall sub_004C21E0_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

// 0x004C2240
int __fastcall sub_004C2240(D2UnitStrc* pUnit)
{
    if (STATLIST_GetStatListFromUnitAndFlag(pUnit, 2))
        return 1;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer && STATES_CheckState(pPlayer, 0x36))
        return 1;
    return 0;
}

// 0x004C2270
void __fastcall sub_004C2270(D2GSPacketSrv7DStrc* pPacket)
{
    D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
    if (!pItem)
        return;

    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    const int nComponent = sub_00623D60_GetItemComponent(pUnit, pItem);
    const int nMode = pItem->dwAnimMode;
    if (pPacket->dwAction == 0x100)
    {
        ITEMS_SetItemFlag(pItem, 0x100, pPacket->bSet);
        sub_0046F950(pUnit);
        sub_004C1290_AttachItem(nComponent, pUnit, pItem);
        sub_00470610_Refresh(pUnit, 0);
        ITEMS_UpdateSets(pUnit, pItem, 1, 1);
        sub_004C1350_RefreshEquippedItems(pUnit);
    }
    else if (pPacket->dwAction == 0x200)
    {
        ITEMS_SetItemFlag(pItem, 0x100, 0);
        sub_004C12F0_ReattachItem(nMode, nComponent, pUnit, pItem);
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
        sub_004C1350_RefreshEquippedItems(pUnit);
    }
}

// 0x004C23E0
void __fastcall sub_004C23E0_RemoveEquippedItems(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    D2UnitStrc* pNext;
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = pNext)
    {
        pNext = INVENTORY_GetNextItem(pNode);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        D2_ASSERT(pItem, 0xD4F);

        if (INVENTORY_GetItemNodePage(pNode) == 3 || (INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit)))
        {
            sub_0046F950(pUnit);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved, 0xD5A);
            D2_ASSERT(pRemoved == pItem, 0xD5B);

            if (INVENTORY_GetItemNodePage(pNode) == 3)
                sub_0063BE30_Return((int)pInventory, INVENTORY_GetBodyLocFromEquippedItem(pInventory, pItem));

            ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
            if (pUnit->dwUnitType == 0)
                INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

            if (!sub_006280A0(pRemoved, 0x100, 0x96, (unsigned int)".\\UNIT\\Item.cpp"))
                STATLIST_ExpireUnitStatlist(pUnit, pRemoved);

            sub_004C1350_RefreshEquippedItems(pUnit);
        }
    }

    INVENTORY_RemoveAllItems(pInventory);
}

static __forceinline int ITEMPKT_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int ITEMPKT_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline unsigned int ITEMPKT_GetItemCode(D2UnitStrc* pItem)
{
    return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->dwCode;
}

static D2UnitStrc* __stdcall sub_004C0F20_CreateItem9C(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    int bFail;

    const int nSize = pPacket->nPacketSize - 0x08;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_CreateClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        return NULL;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xD8, ".\\UNIT\\Item.cpp"))
        {
            sub_00478680_SendPacket5(0x37, pPacket->nItemId);
        }
    }

    return pItem;
}

static D2UnitStrc* __stdcall sub_004C0FF0_CreateItem9D(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    int bFail;

    const int nSize = pPacket->nPacketSize - 0x0D;
    if (!pItemSave)
    {
        sub_0062E410(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = sub_004661C0_CreateClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        return NULL;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xFE, ".\\UNIT\\Item.cpp"))
        {
            sub_00478680_SendPacket5(0x37, pPacket->nItemId);
        }
    }

    return pItem;
}

void __fastcall sub_004C20B0_ItemToCursor9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0xB0C);

    if (sub_00463990(pPacket->nItemId, 4))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
    }

    D2UnitStrc* pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0xB13);

    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

void __fastcall sub_004C2340_ItemToCursor9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
    D2UnitStrc* pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0xD35);

    STATLIST_SetUnitStat(pItem, 0x46, 1, 0);
    D2InventoryStrc* pInventory = pUnit->pInventory;
    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

// 0x004C2540
static void __stdcall sub_004C2540_PlaceItem(D2UnitStrc* pItem, unsigned short nX, unsigned short nY, int nMode, int bFindRoom, unsigned char nPage)
{
    D2_ASSERT(pItem, 0xAC);

    D2ActiveRoomStrc* pRoom = NULL;
    if (bFindRoom && (nX || nY))
    {
        pRoom = sub_00465420_FindRoomAt(nX, nY);
    }

    sub_004C1910_SetItemMode(pItem, pRoom, nX, nY, nMode, 0);
    ITEMS_SetInvPage(pItem, nPage);
}

void __fastcall sub_004C2650_ItemOnCursor9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    if (tItemSave.bMode == 4)
    {
        D2_ASSERT(!sub_00463990(pPacket->nItemId, 4), 0x3A0);

        D2UnitStrc* pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(pItem, 0x3A2);

        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
}

void __fastcall sub_004C26F0_ItemDropped9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        D2InventoryStrc* pInventory = pPlayer->pInventory;
        D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
        if (pCursorItem && pCursorItem == pItem)
        {
            INVENTORY_SetCursorItem(pInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }

        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0F20_CreateItem9C(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
        }
    }
    else
    {
        pItem = sub_004C0F20_CreateItem9C(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    }

    D2_ASSERT(pItem, 0x3CF);
    sub_004C2180_UpdateCursorItem(pItem);
    sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, 5, 1, tItemSave.nStorePage);
}

static void __stdcall sub_004C2970_PlaceItemAt(unsigned short nY, unsigned char nPage, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned short nX)
{
    UNITS_SetXForStaticUnit(pItem, nX);
    UNITS_SetYForStaticUnit(pItem, nY);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x413);

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        return;
    }

    if (!sub_0063BCC0_PlaceItem(pInventory, pItem, ITEMPKT_GetUnitX(pItem), ITEMPKT_GetUnitY(pItem), UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0()), 1, nPage))
    {
        return;
    }

    if (pUnit == sub_00463DD0())
    {
        if (nPage == 1)
        {
            sub_004B9A00(sub_004C1D60(pItem), NULL, 0, 0, 0);
        }
        else
        {
            INVENTORY_SetCursorItem(pInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }
    }

    if (pUnit == sub_00463DD0() && nPage == 3)
    {
        const int nClassId = pItem->dwClassId;
        const unsigned int dwCode = DATATBLS_GetItemsTxtRecord(nClassId)->dwCode;
        if (dwCode == 0x20747368 || dwCode == 0x20326671)
        {
            sub_0048A540();
        }
    }
}

// 0x004C2AD0
void __fastcall sub_004C2AD0_ItemToStorage9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            if (INVENTORY_RemoveItemFromInventory(pPlayer->pInventory, pItem))
            {
                const unsigned char nPage = ITEMS_GetInvPage(pItem);
                const int nRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
                INVENTORY_Return(".\\UNIT\\Item.cpp", 0x456, pPlayer->pInventory, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), nRecordId, 1, nPage);
                sub_00487990_ResetHover();
                if (pPlayer->dwUnitType == 0)
                {
                    INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                }

                if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
                {
                    STATLIST_ExpireUnitStatlist(pPlayer, pItem);
                }
            }

            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
            if (!pItem)
            {
                return;
            }
        }
        else
        {
            sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, tItemSave.bMode, 0, tItemSave.nStorePage);
            ITEMS_SetItemFlag(pItem, -1, 0);
            ITEMS_SetItemFlag(pItem, tItemSave.dwFlags, 1);
        }
    }
    else
    {
        pItem = sub_004C0F20_CreateItem9C(0, 0, 1, pPacket, &tItemSave);
    }

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    sub_004C2970_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pPlayer, pItem, tItemSave.nX);
    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
    sub_004B2A40(!pItem ? -1 : pItem->dwUnitId);
}

// build: context sub_004C2C80_ItemFromStorage9D
void __fastcall sub_004C2C80_ItemFromStorage9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        if (tItemSave.nStorePage == 1)
        {
            sub_00463DD0();
        }
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x4B7);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        if (tItemSave.nStorePage == 2)
        {
            sub_00463DD0();
        }
        return;
    }

    D2_ASSERT(pRemoved == pItem, 0x4CB);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0());
    INVENTORY_Return(".\\UNIT\\Item.cpp", 0x4CF, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, nPage);
    sub_00487990_ResetHover();
    if (pUnit->dwUnitType == 0)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(pItem, 0x4DD);
        }
        else
        {
            sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nX, tItemSave.bMode, 0, tItemSave.nStorePage);
        }

        ITEMS_SetInvPage(pItem, 0xFF);
        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
    else
    {
        sub_00465EE0_RemoveClientSideUnit(pItem->dwUnitId, 4);
        if (pUnit == sub_00463DD0())
        {
            if (tItemSave.nStorePage == 1)
            {
                sub_004B9A00(1, NULL, 0, 0, 0);
            }
            else
            {
                sub_00468070_SetCursorItemState(NULL);
            }
        }
    }

    if (pUnit == sub_00463DD0())
    {
        sub_004B2A00(pItem->dwUnitId);
    }
}

// 0x004C3760
static void __stdcall sub_004C3760_ItemFromBody9D(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2_ASSERT(pUnit->dwUnitType == 0, 0x6ED);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x6EF);

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, pItemSave->nBodyloc);
    sub_0046F950(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    sub_0046F280(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, pItemSave->nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x6F7);
    D2_ASSERT(pRemoved == pItem, 0x6F8);

    if (pUnit->dwUnitType == 0)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    sub_0063BE30(pInventory, pItemSave->nBodyloc);

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        if (pUnit == sub_00463DD0())
        {
            pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, pItemSave);
            D2_ASSERT(pItem, 0x703);
        }
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    if (pUnit == sub_00463DD0())
    {
        sub_00487990_ResetHover();
        ITEMS_SetBodyLocation(pItem, 0);
        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
}

// 0x004C3920
void __fastcall sub_004C3920_BodyPacket9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);
    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x40))
    {
        sub_004C35F0_ItemToBody9D(pPacket, &tItemSave);
        return;
    }

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x80))
    {
        sub_004C3760_ItemFromBody9D(pPacket, &tItemSave);
    }
}

// 0x004C3B30
void __fastcall sub_004C3B30_UpdateItemFromPacket9C(D2GSPacketSrv9C* pPacket)
{
    int bFail;
    const int nSize = pPacket->nPacketSize - 8;
    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, UNIT_ITEM);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, UNIT_ITEM);
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x7B3);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x7B6);

    if (!sub_006287A0_TestFlags(ITEMS_GetItemFlags(pItem), 8))
    {
        INVENTORY_SetCursorItem(pInventory, 0);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem)
    {
        sub_004C2180_UpdateCursorItem(pCursorItem);
    }
}

// 0x004C3C00
void __fastcall sub_004C3C00_ItemToMerc9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    int nUnitId;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    if (!sub_004B3230_GetTickPair(&nUnitId))
    {
        return;
    }

    D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pPacket->nAction == 0x0C)
    {
        if (!pItem)
        {
            return;
        }

        if (sub_004B2E20_IsQuestActive())
        {
            sub_00487990_ResetHover();
        }

        if (!INVENTORY_RemoveItemFromInventory(pInventory, pItem))
        {
            return;
        }

        const unsigned char nPage = ITEMS_GetInvPage(pItem);
        if (nPage == 0xFF)
        {
            return;
        }

        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, sub_0044DCC0());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0x81B, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, nPage);
        sub_00453B00_SendMouseMove();
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        sub_004B2A80_ResetHoverForItem(pPacket->nItemId);
        return;
    }

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    if (!pItem)
    {
        pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
        ITEMS_SetInvPage(pItem, tItemSave.nStorePage);
    }
    else
    {
        INVENTORY_CompareWithItemsParentInventory(pInventory, pItem);
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, &tItemSave);
            if (!pItem)
            {
                return;
            }

            if (tItemSave.nStorePage != ITEMS_GetInvPage(pItem))
            {
                return;
            }
        }
        else
        {
            sub_004C2540_PlaceItem(pItem, 0, 0, 0, 0, tItemSave.nStorePage);
        }
    }

    ITEMS_SetInvPage(pItem, tItemSave.nStorePage);

    int nX;
    int nY;
    if (!sub_0063B9D0_PlaceItemAt(pInventory, pItem, tItemSave.nX, tItemSave.nY, UNITS_GetInventoryRecordId(pUnit, tItemSave.nStorePage, sub_0044DCC0()), &nX, &nY, tItemSave.nStorePage))
    {
        return;
    }

    sub_004C2970_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pUnit, pItem, tItemSave.nX);
    sub_004B2640(pUnit);
    sub_004C2180_UpdateCursorItem(pItem);
}

void __fastcall sub_004C4130_ItemToBelt9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x8EF);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }
    else
    {
        pItem = sub_004C0F20_CreateItem9C(0, 0, 1, pPacket, &tItemSave);
    }

    UNITS_SetXForStaticUnit(pItem, tItemSave.nX);
    UNITS_SetYForStaticUnit(pItem, tItemSave.nY);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x8FF);

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
    {
        INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, CLIENTS_GetUnitX(pItem));
    }

    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    if (tItemSave.dwFlags & 0x400)
    {
        ITEMS_SetItemFlag(pItem, 0x400, 1);
    }

    INVENTORY_SetCursorItem(pInventory, NULL);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_00498D50(ITEMPKT_GetUnitX(pItem), 1);
    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
    sub_004B2A60(pItem->dwUnitId);
}

void __fastcall sub_004C42A0_ItemFromBelt9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x92C);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x931);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        return;
    }

    D2_ASSERT(pRemoved == pItem, 0x93A);

    sub_0063C550_Return(pInventory, tItemSave.nX);
    sub_00498D60();
    sub_00498D50(tItemSave.nX, 0);
    if (pPlayer->dwUnitType == 0)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
        INVENTORY_SetCursorItem(pInventory, pItem);
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        sub_004C2180_UpdateCursorItem(pItem);
    }
    else
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        sub_00468070_SetCursorItemState(NULL);
    }
}

void __fastcall sub_004C4990_ItemToSocket9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (pItem)
    {
        sub_004C2540_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, tItemSave.bMode, 0, tItemSave.nStorePage);
    }
    else
    {
        pItem = sub_004C0FF0_CreateItem9D(0, 0, 0, pPacket, &tItemSave);
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0xB34);

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 8))
        {
            D2InventoryStrc* pPlayerInventory = sub_00463DD0()->pInventory;
            D2_ASSERT(pPlayerInventory, 0xB3A);
            INVENTORY_SetCursorItem(pPlayerInventory, NULL);
            sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pPlayerInventory));
        }

        sub_004C0D20_ApplyItemStats(pUnit, pItem, 0);
    }

    sub_004C2180_UpdateCursorItem(pItem);
}

static void sub_004C3E00_CursorItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x86C);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x874);
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x87C);

    UNITS_SetXForStaticUnit(pItem, pItemSave->nX);
    UNITS_SetYForStaticUnit(pItem, pItemSave->nY);
    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        return;
    }

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    if (pItemSave->nStorePage == 0xFF)
    {
        return;
    }

    D2_ASSERT(sub_0063BCC0_PlaceItem(pInventory, pItem, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0()), 1, nPage), 0x892);

    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
}

static void __stdcall sub_004C3F60_BeltItemToCursor(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x8A6);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x8AB);

    if (pPlayer->dwUnitType == 0)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x8B0);
    D2_ASSERT(pRemoved == pItem, 0x8B1);

    const int nRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
    INVENTORY_Return(".\\UNIT\\Item.cpp", 0x8B4, pInventory, pItemSave->nX, pItemSave->nY, nRecordId, 1, nPage);
    sub_00487990_ResetHover();
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        sub_00465EE0_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = sub_004C0F20_CreateItem9C(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x8BB);
    }
    else
    {
        sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_004C2180_UpdateCursorItem(pItem);
}

// 0x004C40D0
void __fastcall sub_004C40D0_BeltPacket2_9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    const int nMode = pItem->dwAnimMode;
    if (nMode == 0)
    {
        sub_004C3F60_BeltItemToCursor(pPacket, &tItemSave);
    }
    else if (nMode == 4)
    {
        sub_004C3E00_CursorItemToBelt(pPacket, &tItemSave);
    }
}

static void __stdcall sub_004C43E0_ItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x957);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x963);

    UNITS_SetXForStaticUnit(pItem, pItemSave->nX);
    UNITS_SetYForStaticUnit(pItem, pItemSave->nY);
    if (ITEMSIsA(pItem, 0x0D))
    {
        sub_004C0D20_ApplyItemStats(pPlayer, pItem, 0);
    }

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
    {
        D2_ASSERT(INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, CLIENTS_GetUnitX(pItem)), 0x970);
    }

    sub_00453B00_SendMouseMove();
    sub_004C2180_UpdateCursorItem(pItem);
}

void __stdcall sub_004C44D0_ItemFromBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
    {
        return;
    }

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x98D);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x98F);
    D2_ASSERT(pRemoved == pItem, 0x990);

    if (pPlayer->dwUnitType == 0)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    sub_0063C550_Return(pInventory, pItemSave->nX);
    sub_004C2540_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    INVENTORY_SetCursorItem(pInventory, pItem);
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    sub_004C2180_UpdateCursorItem(pItem);
}

// 0x004C45C0
void __fastcall sub_004C45C0_BeltPacket9C(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    sub_0062E410(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = sub_00463990(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    const int nMode = pItem->dwAnimMode;
    if (nMode == 2)
    {
        sub_004C44D0_ItemFromBelt(pPacket, &tItemSave);
    }
    else if (nMode == 4)
    {
        sub_004C43E0_ItemToBelt(pPacket, &tItemSave);
    }
}

// 0x004C4620
void __fastcall sub_004C4620(D2PacketRecord8Strc* pPacket)
{
    if (pPacket->nSkill != 0xFFFF)
    {
        for (unsigned int i = 0; i < gnCursorKindCount_00727A48; ++i)
        {
            if (pPacket->nCursor == gaCursorKind_00727A40[i] && !sub_00453A90_GetUIVarUnchecked(1))
            {
                sub_00455F20(1, 0, 0);
                break;
            }
        }
        D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
        if (pItem)
            sub_00468010(pItem, pPacket->nCursor);
        return;
    }

    if (pPacket->nCursor == 0xFF)
    {
        D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, 4, 0);
            sub_004C2180_UpdateCursorItem(pItem);
        }
        sub_00468070_SetCursorItemState(0);
        return;
    }

    for (unsigned int i = 0; i < gnCursorKindCount_00727A48; ++i)
    {
        if (pPacket->nCursor == gaCursorKind_00727A40[i] && !sub_00453A90_GetUIVarUnchecked(1))
            sub_00455F20(1, 0, 0);
    }
    D2UnitStrc* pItem = sub_00463990(pPacket->dwItemId, 4);
    if (pItem)
    {
        ITEMS_SetItemFlag(pItem, 4, 1);
        sub_00468010(pItem, pPacket->nCursor);
    }
}

// 0x004C51E0
void __fastcall sub_004C51E0_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    const int nDirection = UNITS_GetDirection(pUnit) >> 3;
    int aOffsetX[8] = { 0, -1, -2, -1, 0, 1, 2, 1 };
    int aOffsetY[8] = { 2, 1, 0, -1, -2, -1, 0, 1 };

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    *pX = aOffsetX[nDirection] + nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    *pY = aOffsetY[nDirection] + nY;
}

// 0x004C52E0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    int nY;
    D2UnitStrc* pTarget = sub_004648F0_GetTargetUnit(pUnit);
    if (pTarget)
    {
        int nX;
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pTarget->pStaticPath->tGameCoords.nX;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nX = PATH_GetXPosition(pTarget->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        *pX = nX;

        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pTarget->pStaticPath->tGameCoords.nY;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nY = PATH_GetYPosition(pTarget->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
    }
    else
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    *pY = nY;

    if (!*pX || !nY)
    {
        sub_004C51E0_GetAdjacentPosition(pUnit, pX, pY);
    }
    return 1;
}

// 0x004C6030
int __fastcall sub_004C6030_UseBowOrCallTarget(D2UnitStrc* pUnit, int nArg2, int nArg3)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        const int nValue = sub_00645F00_GetBowValue(pUnit, &nArg3);
        if (nValue != -1)
        {
            sub_004C5420_UseBow(pUnit, nValue, nArg2, nArg3);
        }
    }
    else
    {
        sub_004E4050_Nothing(pUnit, sub_004648F0_GetTargetUnit(pUnit));
    }

    return 1;
}

// 0x004C7C40
int __fastcall sub_004C7C40_RegisterTableEvent(void* pArg1, int nArg2, int nArg3, int nArg4, unsigned int nIndex, int nArg6, int nArg7)
{
    if (nIndex <= 1)
    {
        void* pfnCallback = gpfnEventTable_00727DB4[nIndex];
        if (pfnCallback)
        {
            return sub_004DC110(pArg1, nArg2, nArg3, nArg4, pfnCallback, nArg6, nArg7);
        }
    }

    return 0;
}

// 0x004C7CF0
int __fastcall sub_004C7CF0_EvaluateClientSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    sub_004C7BE0_ApplyClientSkillCalc(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    return 1;
}

// 0x004D93B0
void __fastcall sub_004D93B0_SendPositionEvent(D2UnitStrc* pUnit)
{
    D2UnitEventArgsStrc tArgs = {};

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    tArgs.nX = nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    tArgs.nY = nY;

    sub_00480C10_DispatchUnitEvent(0x19, pUnit, &tArgs, 0);
    D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0);
}

// 0x004DA080
void __stdcall sub_004DA080_FreeGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        FOG_Free(pMotion, ".\\ENGINE\\Particle.cpp", 100, 0);
        sub_0046F070_SetGfxMotion(pUnit, 0);
    }
}

// 0x004DA0D0
int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nUnk0x38;
    }
    return 0;
}

// 0x004DA0F0
int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nUnk0x3C;
    }
    return 0;
}

// 0x004DCD40
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG)
{
    if (gnGlobal_007C89D8)
    {
        D2HintCursorStrc* pCursor = sub_00481860(gnGlobal_007C89D8);
        void* pEntry = sub_004B9610(gnGlobal_007C89D8);
        if (pEntry && sub_004B9590(pEntry))
        {
            const int nValue = nIndex > 0 ? pCursor->aValues[nIndex] : 0;
            const int nOffset = 4 * (gnGlobal_007C89D8 - sub_004817F0());
            *(int*)(sub_00481810() + nOffset) = nValue;
            gnGlobal_007C89E0 = sub_00481820();
        }
    }

    sub_004BA8F0();
    gTimedHint_007C89E4.bActive = 1;
    gTimedHint_007C89E4.pOwner = pOwner;
    gTimedHint_007C89E4.nEndTickA = sub_0044DB00() + nDelayA;
    gTimedHint_007C89E4.bActive2 = 1;
    gTimedHint_007C89E4.nArgE = nArgE;
    gTimedHint_007C89E4.nEndTickF = sub_0044DB00() + nDelayF;
    gTimedHint_007C89E4.nArgG = nArgG;
    gTimedHint_007C89E4.nEndTickC = sub_0044DB00() + nDelayC;
}

// 0x004DE630
void __thiscall D2FloorTileViewStrc::sub_004DE630_DrawTileAt(int nX, int nY)
{
    int nScreenX = nX;
    int nScreenY = nY + 5;
    sub_00643260(&nScreenX, &nScreenY);
    nScreenY += 0x28;
    D2_ASSERT(gpGlobal_007A0634, 0xDF);
    nScreenX += nOffsetX;
    nScreenY += nOffsetY;
    D2TileStrc* pTile = sub_00619720(gpGlobal_007A0634);
    if (pTile)
    {
        sub_004DE410_DrawFloorTile(pTile, 1, nScreenX, nScreenY, nX, nY);
    }
}

// 0x004DE6C0
void __thiscall D2FloorTileViewStrc::sub_004DE6C0_DrawTileTriple(int nX, int nY, int nStepX, int nStepY)
{
    const int nBaseX = nX / 5 * 5;
    const int nBaseY = nY / 5 * 5;
    sub_004DE630_DrawTileAt(nBaseX, nBaseY);
    sub_004DE630_DrawTileAt(nBaseX + nStepX, nBaseY + nStepY);
    sub_004DE630_DrawTileAt(nBaseX + 2 * nStepX, nBaseY + 2 * nStepY);
}

// 0x004DF510
void __thiscall D2CellGridViewStrc::sub_004DF510_DrawCellNodes()
{
    const int nCells = nSize;
    int nCount = nCells * nCells;
    D2GridCellStrc* pCell = pCells;
    const int nArg = sub_0045AE90();
    while (nCount--)
    {
        for (D2CellNodeStrc* pNode = pCell->pNodes; pNode; pNode = pNode->pNext)
        {
            if (!(pNode->dwFlags & 3))
            {
                unsigned char nByte0;
                unsigned char nByte1;
                unsigned char nByte2;
                unsigned char nByte3;
                sub_00475AA0(pNode->nA, pNode->nB, &nByte0, &nByte1, &nByte2, &nByte3);
                sub_004DC7B0(pNode->pPos, (((nByte3 << 8 | nByte2) << 8 | nByte1) << 8) | nByte0, 0);
            }
            else
            {
                const int bMode = sub_004F51D0();
                if (pNode->dwFlags & 1)
                {
                    if (bMode)
                    {
                        sub_004F6980(pNode->pPos->f_18, pNode->nA, pNode->nB, 4, nArg);
                    }
                    else
                    {
                        sub_004F6980(pNode->pPos->f_18, nOffsetX - nScrollX + pNode->pPos->nX, pNode->pPos->nY - nScrollY + nOffsetY, 4, nArg);
                    }
                }
                else if (pNode->dwFlags & 2)
                {
                    sub_00471620(pNode->pPos);
                }
            }
        }

        if (pCell->f_14)
        {
            sub_004DEF80(pCell, 1, this);
        }
        ++pCell;
    }
}

// 0x004DF630
int __fastcall sub_004DF630_QueryAddress(D2AddressQueryStrc* pQuery)
{
    D2_ASSERT(*(int*)pQuery->nState == 2, 0x5D);

    D2AddressInfoStrc tInfo;
    int nParam = pQuery->nParam;
    int nResult = sub_00516760(pQuery->nSocket, &nParam, &tInfo);
    if (nResult && tInfo.nVersion == 0x10 && tInfo.nMagic == 0x5622)
    {
        pQuery->nResult = nResult;
        pQuery->nParamOut = nParam;
        pQuery->bFamilyMatch = tInfo.f_2 == 2;
        return 1;
    }

    pQuery->f_81 = 1;
    return 0;
}

// 0x004DF9D0
D2SlotStrc* __fastcall SoundChannelFind(int nOwner)
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }

    D2SlotStrc* pBest = 0;
    for (int i = 0; i < 16; i++)
    {
        D2SlotStrc* pSlot = &gaSlots_007C8A78[i];
        if (sub_00515710(pSlot->f_0) && pSlot->pObject && pSlot->pObject->f_4 == nOwner)
        {
            if (!pBest || pSlot->pObject->nKey < pBest->pObject->nKey)
            {
                pBest = pSlot;
            }
        }
    }

    return pBest;
}
