#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define STAT_ITEM_MAGICARROW 157
#define DAMAGERESULTFLAG_SUCCESSFULHIT 1
#define SKILLSRVDOFN_COUNT 191
#define EVENTFN_COUNT 50
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define STATE_UNINTERRUPTABLE 54
#define EVENTTYPE_AITHINK 2
#define UNITFLAG_NOTC 0x00020000
#define UNITFLAG_ISREVIVE 0x80000000
struct D2UnitFindArgStrc;
struct D2SeedStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2PetTypeTxt;
struct D2AuraCallbackStrc;
struct D2_6FD106F0_Strc;
struct D2_6FD10880_Strc;
struct D2PortalFlagsStrc;
struct D2MonsterDataStrc;
struct D2SummonArgStrc;
struct D2ModeChangeStrc;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x58];
    unsigned short wItemFormat;
    unsigned char unk_7A[0x2E];
    int dwGameFrame;
};


struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    int eEarLvl;
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};



struct D2SkillsTxt
{
    char unk0x000[0xBE];
    signed char nPetType;
    char unk0x0BF[0x01];
    unsigned int dwPetMax;
    char unk0x0C4[0x6A];
    unsigned short wResultFlags;
    char unk0x130[0x40];
    unsigned int dwSkPoints;
    char unk0x174[0xC8];
};

struct D2PetTypeTxt
{
    char unk0x00[0xBC];
    int nSkillCount;
    short wSkillIds[15];
    unsigned short unk0xDE;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x4C];
    int nPetTypeTxtRecordCount;
};

struct D2DamageStrc
{
    char unk0x00[0x04];
    unsigned short wResultFlags;
};

struct D2AuraCallbackStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pOwner;
    int nCounter;
    void* pArgs;
};

struct D2_6FD106F0_Strc
{
    D2UnitStrc* pUnit;
    int nDistance;
    int nX;
    int nY;
    int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*);
};

struct D2_6FD10880_Strc
{
    D2UnitStrc* unk0x00;
    int unk0x04;
    D2UnitStrc* unk0x08;
    int unk0x0C;
    int unk0x10;
    int unk0x14;
};

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    unsigned int unk0x38;
    unsigned int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    void* pInitFunc;
    int pInitArgs;
};

struct D2UnitFindArgStrc
{
    int nFlags;
    int unk0x04;
    D2UnitStrc* pUnit;
    int nX;
    int nY;
    int nSize;
    int nMaxArrayEntries;
    int nIndex;
    void* pField;
    void* pfnUnitTest;
    int unk0x28;
    int unk0x2C;
    int unk0x30;
    int unk0x34;
};

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    void* pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nFlags;
    int nIndex;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

typedef int (__fastcall* SkillDoFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int a6, int a7);

typedef int (__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit, D2UnitFindArgStrc* pUnitFindArg);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const SkillDoFunc gpSkillSrvDoFnTable_007322B0[SKILLSRVDOFN_COUNT]; // 0x007322B0
extern const D2UnitEventCallbackFunction gpEventCallbackTable_007325B0[EVENTFN_COUNT]; // 0x007325B0
void __fastcall sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
int __fastcall sub_6FCF5DE0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BA90
int __fastcall sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BB20
int __fastcall sub_6FD107E0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BC70
int __fastcall sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BCD0
int __fastcall sub_6FD15320(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg); // 0x0056E370
int __fastcall sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x0056CDA0
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0
void __fastcall D2GAME_STATES_SendUnitStates_6FCC58E0(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00570E30
void __fastcall D2GAME_STATES_SendUnitStateUpdates_6FCC5BE0(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005711D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int nPetType); // 0x00478A20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall sub_6FC7D150(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax); // 0x00575850
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
void __fastcall sub_6FC51310(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558580
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, int a3, int nStatId, int nValue, int a6); // 0x0053D130
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __fastcall sub_6FC80A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310
D2UnitStrc* __fastcall sub_6FC7C7B0(D2UnitStrc* pUnit); // 0x00535BC0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem); // 0x0062A310
int __stdcall D2GAME_Transmogrify_6FC4A660(D2UnitStrc* pItem); // 0x00563FE0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8); // 0x005C0AD0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110
void __fastcall sub_6FC7DF40(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575900
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x0053C4A0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00646D60
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, D2CoordStrc* pReturnCoords, int a4, int a5); // 0x00555DA0
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel); // 0x0056CF40
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

struct D2PortalFlagsStrc
{
    unsigned char nFlags;
};

void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, D2PortalFlagsStrc portalFlags); // 0x00622300
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighboringRooms); // 0x0064E810

struct D2MonsterDataStrc
{
    char unk0x00[0x28];
    D2AiControlStrc* pAiControl;
};

struct D2SummonArgStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    int nHcIdx;
    int nAiSpecialState;
    int nMonMode;
    D2CoordStrc pPosition;
    int nPetType;
    int nPetMax;
};

int __fastcall sub_00554070(D2UnitStrc* pUnit); // 0x00554070
void __fastcall sub_00554040(D2UnitStrc* pUnit, int nUnitGUID); // 0x00554040
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    unsigned char unk0x14;
    unsigned char nEventFlag;
    unsigned short unk0x16;
    int unk0x18;
    int unk0x1C;
};

enum
{
    PLRMODE_ATTACK1 = 7,
    MONMODE_ATTACK1 = 4,
};

void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
void __fastcall D2GAME_PLAYERMODE_Change_6FC81A00(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0056BAD0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter)
{
    if (!nAuraFilter)
    {
        nAuraFilter = 0x8583;
    }

    if (pUnit)
    {
        sub_6FD0FE80(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter, sub_6FCF5DE0, pDamage, 0, ".\\SKILLS\\Skills.cpp", 539);
    }

    return 1;
}

// 0x0056BBC0
D2UnitStrc* __fastcall SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAuraRange, int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*))
{
    D2_6FD106F0_Strc arg;
    arg.pUnit = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.nX = CLIENTS_GetUnitXInline(pUnit);
    arg.nY = CLIENTS_GetUnitYInline(pUnit);
    arg.pCallback = pCallback;

    sub_6FD0FE80(pGame, pUnit, 0, 0, nAuraRange, 0x8783, sub_6FD106F0, &arg, 0, ".\\SKILLS\\Skills.cpp", 696);

    return arg.pUnit;
}

// 0x0056BC80
int __fastcall sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter)
{
    int nSkillId = 0;

    sub_6FD0FE80(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter | 0xA783, sub_6FD107E0, &nSkillId, 0, ".\\SKILLS\\Skills.cpp", 736);

    return nSkillId;
}

// 0x0056BD10
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8)
{
    D2_6FD10880_Strc args;
    args.unk0x0C = a7;
    args.unk0x10 = a7;
    args.unk0x00 = 0;
    args.unk0x04 = -1;
    args.unk0x08 = 0;
    args.unk0x14 = 0;
    sub_6FD0FE80(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter | 0xA783, sub_6FD10880, &args, 0, ".\\SKILLS\\Skills.cpp", 803);

    D2UnitStrc* pResult = args.unk0x00;
    if (!pResult)
    {
        pResult = args.unk0x08;
    }

    if (a8)
    {
        *a8 = args.unk0x14;
    }

    return pResult;
}

// 0x0056BD90
void __fastcall sub_0056BD90_RefreshPetMaxForSkill(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if (pSkillsTxtRecord->nPetType <= 0 || pSkillsTxtRecord->nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    D2PetTypeTxt* pPetTypeTxtRecord = sub_00478A20_GetPetTypeTxtRecord(pSkillsTxtRecord->nPetType);
    if (!pPetTypeTxtRecord)
    {
        return;
    }

    int nMax = 0;
    for (int i = 0; i < pPetTypeTxtRecord->nSkillCount; ++i)
    {
        const int nPetSkillId = pPetTypeTxtRecord->wSkillIds[i];
        D2SkillsTxt* pPetSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nPetSkillId);
        if (pPetSkillsTxtRecord)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, nPetSkillId);
            if (pSkill)
            {
                const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
                int nPetMax = 0;
                if (nLevel > 0)
                {
                    nPetMax = SKILLS_EvaluateSkillFormula(pPlayer, pPetSkillsTxtRecord->dwPetMax, nPetSkillId, nLevel);
                    if (nPetMax < 1)
                    {
                        nPetMax = 1;
                    }
                }

                if (nPetMax > nMax)
                {
                    nMax = nPetMax;
                }
            }
        }
    }

    sub_6FC7D150(pGame, pPlayer, pSkillsTxtRecord->nPetType, nMax);
}

// 0x0056C310
int __fastcall sub_6FD11340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pItem)
    {
        int bNoQuantity = 0;
        int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) - 1;
        if (nQuantity < 0)
        {
            bNoQuantity = 1;
            nQuantity = 0;
        }

        STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nQuantity, 0);
        sub_6FC51310(pGame, pItem);

        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\Skills.cpp", 1350), pItem, 1, STAT_QUANTITY, nQuantity, 0);

        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) != nMaxDurability)
        {
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\Skills.cpp", 1356), pItem, 1, STAT_DURABILITY, nMaxDurability, 0);
        }

        sub_6FC80A30(pGame, pUnit);

        if (!bNoQuantity)
        {
            return nQuantity + 1;
        }
    }

    return 0;
}

// 0x0056C4E0
int __fastcall sub_6FD119C0(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    D2UnitStrc* pWeapon = sub_6FC7C7B0(pUnit);
    if (!pWeapon)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int bNoAmmoItem = 1;
    if (ITEMS_GetAmmoType(pWeapon))
    {
        bNoAmmoItem = 0;
        if (!SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 1600) && STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_MAGICARROW, 0))
        {
            return 1;
        }
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    if (pRightArmItem && (!bNoAmmoItem || pRightArmItem == pWeapon) && (ITEMS_CheckIfStackable(pRightArmItem) || ITEMS_CheckIfThrowable(pRightArmItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pRightArmItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pRightArmItem);
    }

    D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
    if (pLeftArmItem && (!bNoAmmoItem || pLeftArmItem == pWeapon) && (ITEMS_CheckIfStackable(pLeftArmItem) || ITEMS_CheckIfThrowable(pLeftArmItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pLeftArmItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pLeftArmItem);
    }

    return 0;
}

// 0x0056C6A0
void __fastcall sub_6FD11AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit)
    {
        pUnit->dwFlagEx &= 0xFFFFFFBF;
    }

    if (pItem && D2GAME_Transmogrify_6FC4A660(pItem))
    {
        SUNIT_AttachSound(pUnit, 4, pUnit);
    }

    D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\Skills.cpp", 1711), 0, 0xFF, 1, 0, 0xFFFF);
}

// 0x0056D400
void __fastcall sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* a3, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity)
{
    static const int xOffsets[64] = // 0x006E1288
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24,
        -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5,
        8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] = // 0x006E1388
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11,
        8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27,
        -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = CLIENTS_GetUnitXInline(a3);
    missileParams.nY = CLIENTS_GetUnitYInline(a3);
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pOwner;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;

    if (nVelocity)
    {
        missileParams.nVelocity = nVelocity;
        missileParams.dwFlags |= 4;
    }

    for (int i = 0; i < 64; ++i)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
}

// 0x0056D810
void __fastcall sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel)
{
    if (nDoFunc >= 0 && nDoFunc < SKILLSRVDOFN_COUNT && gpSkillSrvDoFnTable_007322B0[nDoFunc])
    {
        gpSkillSrvDoFnTable_007322B0[nDoFunc](pGame, pUnit, nSkillId, nSkillLevel);
    }
}

// 0x0056DAB0
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality)
{
    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    if (nItemId != -1)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pUnit, &pCoord);

        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop = {};
            itemDrop.pUnit = pUnit;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pGame;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = nItemId;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.nQuality = nItemQuality;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        }
    }

    return 0;
}

// 0x0056E390
D2UnitStrc* __fastcall sub_6FD15210(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    if (pUnit && nSkillLevel > 0 && pTarget)
    {
        const int nX = UNITS_GetXPosition(pTarget);
        const int nY = CLIENTS_GetUnitY(pTarget);

        D2UnitFindArgStrc unitFindArg = {};
        unitFindArg.nFlags = 0x1002;
        unitFindArg.nX = nX;
        unitFindArg.nY = nY;
        unitFindArg.nSize = 10;

        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);

        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, UNITS_GetRoom(pTarget), nX, nY, 10, sub_6FD15320, &unitFindArg);
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        D2UnitStrc* pResult = 0;
        if (unitFindData.nIndex)
        {
            pResult = *unitFindData.pUnitsArray;
        }

        UNITFINDS_FreeUnitFindData(&unitFindData);
        return pResult;
    }

    return 0;
}

// 0x0056E680
unsigned short __fastcall sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8)
{
    if (!(pSkillsTxtRecord->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT))
    {
        pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), a8);
        if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            pDamage->wResultFlags |= pSkillsTxtRecord->wResultFlags;
        }
    }
    else
    {
        pDamage->wResultFlags = pSkillsTxtRecord->wResultFlags;
    }

    return pDamage->wResultFlags;
}

// 0x0056E6F0
unsigned short __fastcall sub_6FD15650(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned short wResultFlags, int a5, D2DamageStrc* pDamage, int a7)
{
    if (!(wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT))
    {
        pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pOwner, pUnit, a5, a7);
        if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            pDamage->wResultFlags |= wResultFlags;
        }
    }
    else
    {
        pDamage->wResultFlags = wResultFlags;
    }

    return pDamage->wResultFlags;
}

// 0x0056E740
D2UnitEventStrc* __fastcall sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int a4, int a5, int nEventFunc, int a7, int a8)
{
    if (nEventFunc >= 0 && nEventFunc < EVENTFN_COUNT && gpEventCallbackTable_007325B0[nEventFunc])
    {
        return SUNITEVENT_Register(pGame, pUnit, nUnitEventType, a4, a5, gpEventCallbackTable_007325B0[nEventFunc], a7, a8);
    }

    return 0;
}

// 0x0056FC50
void __fastcall sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 3235);
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
        sub_6FD13260(pGame, pUnit, nSkillId, nSkillLevel, 0);
    }
}

// 0x00570080
int __fastcall sub_6FD136E0(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        int nRequiredSkillPoints = 1;
        if (pSkillsTxtRecord->dwSkPoints != -1)
        {
            int nSkillLevel = 0;

            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pSkill)
            {
                nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            }

            nRequiredSkillPoints = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwSkPoints, nSkillId, nSkillLevel);
        }

        if (STATLIST_GetUnitBaseStat(pUnit, STAT_SKILLPTS, 0) >= nRequiredSkillPoints)
        {
            STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, -nRequiredSkillPoints, 0);

            D2SkillStrc* pSkill = SKILLS_AddSkill(pUnit, nSkillId);
            SKILLS_RefreshPassiveSkills(pUnit);

            if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
            {
                sub_6FC7DF40(SUNIT_GetGameFromUnit(pUnit), pUnit);
            }

            if (!pSkill)
            {
                STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nRequiredSkillPoints, 0);
            }
            else
            {
                const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 0);
                D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(SUNIT_GetClientFromPlayer(pUnit, ".\\SKILLS\\Skills.cpp", 3443), pUnit, nSkillId, nLevel, 0);

                const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
                if (nPassiveState)
                {
                    STATES_ToggleState(pUnit, nPassiveState, 1);
                }

                SKILLS_RefreshSkill(pUnit, nSkillId);
                return 1;
            }
        }
    }

    return 0;
}

// 0x00571580
void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer)
{
    if (bPlayer)
    {
        D2GAME_STATES_SendUnitStates_6FCC58E0(pUnit, pClient);
    }
    else
    {
        D2GAME_STATES_SendUnitStateUpdates_6FCC5BE0(pUnit, pClient);
    }
}

#include "gen/data/Source/D2Game/SKILLS/Skills_0056BAD0.inc"

// 0x0056D130
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm)
{
    D2_ASSERT(pRoom, 0xE42);

    if (ppSourceUnit)
    {
        *ppSourceUnit = 0;
    }

    if (pUnit && DUNGEON_IsRoomInTown(pRoom))
    {
        if ((nDestLevel != 0x27 && nDestLevel != 0x88 && nDestLevel != 0x85 && nDestLevel != 0x86 && nDestLevel != 0x87) || nObjectId != 0x3C)
        {
            SUNIT_AttachSound(pUnit, 0x18, pUnit);
            return 0;
        }
    }

    const unsigned char nAct = DRLG_GetActNoFromLevelId(nDestLevel);
    const int nSourceLevel = DUNGEON_GetLevelIdFromRoom(pRoom);

    D2_ASSERT(nAct == DRLG_GetActNoFromLevelId(nSourceLevel), 0xE5C);

    D2CoordStrc coords;
    coords.nX = nX;
    coords.nY = nY;

    if (!bPerm)
    {
        if (!COLLISION_GetFreeCoordinatesWithField(pRoom, &coords, &coords, 3, 0x3E01, 0xC01, 0))
        {
            return 0;
        }
    }

    const int nTargetX = coords.nX;
    const int nTargetY = coords.nY;

    D2ActiveRoomStrc* pTargetRoom = D2GAME_GetRoom_6FC52070(pRoom, nTargetX, nTargetY);
    if (!pTargetRoom)
    {
        return 0;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(2, nObjectId, nTargetX, nTargetY, pGame, pTargetRoom, 1, 1, 0);
    if (ppSourceUnit)
    {
        *ppSourceUnit = pPortal;
    }

    UNITS_ChangeAnimMode(pPortal, 1);

    D2UnitStrc* pLinkPortal = D2GAME_CreateLinkPortal_6FD13B20(pGame, pUnit, pPortal, nDestLevel, nSourceLevel);
    if (!pLinkPortal)
    {
        return 0;
    }

    D2PortalFlagsStrc portalFlags;
    portalFlags.nFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, portalFlags);
    DUNGEON_ToggleHasPortalFlag(pTargetRoom, 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pLinkPortal), 0);
    return 1;
}

static __forceinline int UNITS_HasBeenDeletedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx >> 8) & 1;
}

static __forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

// 0x0056D840
static void sub_6FD146D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4008);

    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, sub_00554070(pUnit));
    if (pPet)
    {
        if (UNITS_HasBeenDeletedInline(pPet))
        {
            SUNIT_RemoveUnit(pGame, pPet);
            sub_00554040(pUnit, -1);
            return;
        }

        pPet->dwFlags |= 0x4000000u;

        SUNITDMG_KillMonster(pGame, pPet, pUnit, 1);
    }

    sub_00554040(pUnit, -1);
}

// 0x0056D8D0
static void __stdcall sub_0056D8D0_SetPetFlagsAndCount(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg, D2UnitStrc* pPet)
{
    if (!(pSummonArg->dwFlags & 8) && pPet)
    {
        pPet->dwFlags |= UNITFLAG_ISREVIVE;
    }

    if (pSummonArg->dwFlags & 2)
    {
        sub_6FD146D0(pGame, pSummonArg->pOwner);
        sub_00554040(pSummonArg->pOwner, !pPet ? -1 : pPet->dwUnitId);
    }

    int nPetMax = pSummonArg->nPetMax;
    if (nPetMax < 1)
    {
        nPetMax = 1;
    }
    sub_6FC7D7A0(pGame, pSummonArg->pOwner, pPet, pSummonArg->nPetType, nPetMax);
}

inline int I12_SummonGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int I12_SummonGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = I12_SummonGetUnitX(pTarget);
        *pY = I12_SummonGetUnitY(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056D940
D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg)
{
    int nX;
    int nY;
    if (pSummonArg->dwFlags & 1)
    {
        nX = pSummonArg->pPosition.nX;
        nY = pSummonArg->pPosition.nY;
    }
    else
    {
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pSummonArg->pOwner, &nX, &nY);
    }

    D2ActiveRoomStrc* pOwnerRoom = UNITS_GetRoom(pSummonArg->pOwner);
    D2ActiveRoomStrc* pRoom = D2GAME_GetRoom_6FC52070(pOwnerRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    D2UnitStrc* pPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, -1, 66);
    if (!pPet)
    {
        if (pSummonArg->dwFlags & 4)
        {
            return 0;
        }

        pPet = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, 4, 66);
        if (!pPet)
        {
            return 0;
        }
    }

    sub_0056D8D0_SetPetFlagsAndCount(pGame, pSummonArg, pPet);

    if (pPet)
    {
        pPet->dwFlags |= UNITFLAG_NOTC;
    }

    D2UnitStrc* pOwner = pSummonArg->pOwner;
    int nOwnerType = UNIT_INVALID;
    if (pOwner)
    {
        nOwnerType = pOwner->dwUnitType;
    }
    AIGENERAL_SetOwnerData(pGame, pPet, !pOwner ? -1 : pOwner->dwUnitId, nOwnerType, 0, 0);

    D2_ASSERT(!STATES_CheckState(pPet, STATE_UNINTERRUPTABLE), 4108);

    AITHINK_ExecuteAiFn(pGame, pPet, AIGENERAL_GetAiControlFromUnit(pPet), pSummonArg->nAiSpecialState);
    MONSTER_UpdateAiCallbackEvent(pGame, pPet);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pPet, EVENTTYPE_AITHINK, pGame->dwGameFrame + 25, 0, 0);

    return pPet;
}

// 0x0056E230
int __fastcall sub_6FD150A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2_ASSERT(pUnit, 4625);
    D2_ASSERT(pTarget, 4626);
    D2_ASSERT(pGame, 4627);

    SUNIT_SetCombatMode(pGame, pUnit, 1);
    UNITS_SetUsedSkill(pUnit, 0);

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, 0, -1);
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        D2GAME_PLAYERMODE_Change_6FC81A00(pGame, pUnit, pSkill, PLRMODE_ATTACK1, !pTarget ? UNIT_INVALID : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId, 1);
        break;

    case UNIT_MONSTER:
    {
        D2ModeChangeStrc tModeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_ATTACK1, &tModeChange);
        tModeChange.pTargetUnit = pTarget;
        D2GAME_ModeChange_6FC65220(pGame, &tModeChange, 1);
        break;
    }
    }

    return 1;
}
