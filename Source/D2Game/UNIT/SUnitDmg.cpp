#include "D2Game.h"

#define UNIT_MONSTER 1
#define MONSTATS2FLAGINDEX_DEADCOL_0057AF00 0x13
#define STAT_ITEM_DEMONDAMAGE_PERCENT 121
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_OBJECT 2
#define ITEMTYPE_GOLD 4
#define ITEMQUAL_NORMAL 2
#define STAT_STAMINA 10
#define OBJECT_FIRE_SMALL 160
#define OBJECT_FIRE_LARGE 162
#define OBJMODE_NEUTRAL 0
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define EVENTTYPE_ENDANIM 1
#define EVENTTYPE_QUESTFN 7
#define UNITFLAG_TARGETABLE 0x00000002
#define UNITFLAG_SKSRVDOFUNC 0x00000040
#define GOLD_PILE_COUNT 32
#define UNIT_PLAYER 0
#define STAT_HITPOINTS 6
#define DAMAGEHITFLAG_2 2
#define DAMAGERESULTFLAG_SUCCESSFULHIT 1
#define DAMAGERESULTFLAG_WILLDIE 0x02
#define UNIT_INVALID 6
#define STAT_LEVEL 12

struct D2CombatStrc;
struct D2ObjectControlStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;
struct D2UnkDamageRecordStrc;
struct D2StatReduceCtx;
struct D2StatReduceRec;
struct Context;
struct Record;
struct D2DrlgCoordsStrc;
struct D2CurseStrc;
struct D2ObjOperateFnStrc;
struct D2SeedStrc;
struct D2DamageStrc;
struct D2UnitStrc;
struct D2GameStrc;
struct D2DataTablesStrc;
struct Unit;
struct D2CoordStrc;
struct D2ObjectsTxt;
struct D2PetInfoStrc;
struct D2HirelingTxt;
struct D2PartyExpStrc;

struct D2DamageStrc
{
    unsigned int dwHitFlags;
    unsigned short wResultFlags;
    unsigned short wExtra;
    int dwPhysDamage;
    int dwEnDmgPct;
    int dwFireDamage;
    int dwBurnDamage;
    int dwBurnLen;
    int dwLtngDamage;
    int dwMagDamage;
    int dwColdDamage;
    int dwPoisDamage;
    int dwPoisLen;
    int dwColdLen;
    int dwFrzLen;
    int dwLifeLeech;
    int dwManaLeech;
    int dwStamLeech;
    int dwStunLen;
    int unk0x48[10];
};

struct D2CombatStrc
{
    D2GameStrc* pGame;
    int dwAttackerType;
    int dwAttackerId;
    int dwDefenderType;
    int dwDefenderId;
    D2DamageStrc tDamage;
    D2CombatStrc* pNext;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    unsigned int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0x8];
    D2SeedStrc pSeed;
    unsigned char unk_28[0x4];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x7C];
    D2CombatStrc* pCombat;
    char unk0xB0[0x8];
    unsigned int dwDropItemCode;
    char unk0xBC[0x8];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4A];
    unsigned char nGameType;
    char unk0x6B[0x02];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    int dwGameType;
    char unk0x78[0x30];
    unsigned int dwGameFrame;
};

struct D2MonStatsTxt
{
    char unk0x000[0x4F];
    unsigned char nAIdel[3];
    unsigned char unk_52[0x116];
    signed char nColdEffect[3];
    char unk0x16B[0x3D];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[0x04];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x1BC];
    int nMonTypeTxtRecordCount;
    unsigned int* pMonTypeNest;
    int nMonTypeIndex;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

struct D2UnkDamageRecordStrc
{
    int unk0x00[3];
    int nValue;
};

int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

struct D2StatReduceCtx
{
    int unk0x00;
    int unk0x04;
    D2UnitStrc* pUnit;
    int unk0x0C;
    int unk0x10;
    int bCapped;
};

struct D2StatReduceRec
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int nStatId;
};

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
static __declspec(noinline) int sub_0057BDD0_ReduceByStat(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue);

struct Unit
{
    int type;
};

struct Context
{
    Game* game;
    Difficulty* difficulty;
    Unit* attacker;
    Unit* defender;
    int attackerFlag;
    int defenderFlag;
    Damage* damage;
    int zeroReduction;
    int flatReduction1;
    int flatReduction2;
};

extern Record gVar_00732980_Records[12]; // 0x00732980
extern int __fastcall sub_00451F30_HasFlags(Unit*,unsigned int); // 0x00451F30

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2CurseStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nSkill;
    int nSkillLevel;
    int nDuration;
    int nStat;
    int nStatValue;
    int nState;
    StatListRemoveCallback pStateRemoveCallback;
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pPlayer;
    D2ObjectControlStrc* pObjectregion;
    int nObjectIdx;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
    char unk0xF8[0x75];
    unsigned char nMonsterOK;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170
void __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall sub_0055A090_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID); // 0x00629ED0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553990
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
void __fastcall sub_6FD12FD0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FAF0
void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest); // 0x005540A0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __fastcall sub_0056E970(D2CurseStrc* pCurse); // 0x0056E970
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
D2UnitStrc* __fastcall D2GAME_DropArmor_6FC4F830(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x005594C0
D2UnitStrc* __fastcall D2GAME_DropWeapon_6FC4FA50(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x00559630
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660
int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0

typedef char chkCombatNext_M125[(int)&((D2CombatStrc*)0)->pNext == 0x84 ? 1 : -1];

typedef char chkUnitCombat_M125[(int)&((D2UnitStrc*)0)->pCombat == 0xAC ? 1 : -1];

struct D2PetInfoStrc
{
    unsigned int nSeed;
    unsigned short wName;
    short unk0x06;
    int nHirelingId;
};

struct D2HirelingTxt
{
    char unk0x00[0x20];
    int dwExpPerLvl;
};

struct D2PartyExpStrc
{
    D2UnitStrc* pDefenderUnit;
    D2UnitStrc* pMembers[8];
    int nMemberLevels[8];
    int nMembers;
    int nLevelSum;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00574BD0
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel); // 0x00611800
int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int nExperience); // 0x00611860
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00570880
int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, void* pDamage); // 0x005C0C30

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc*, D2UnitStrc*, void*);

void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs); // 0x005405A0
void __fastcall SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x0057E5A0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, int nLevel); // 0x00572840
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3); // 0x005726C0
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0057A830
int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2)
{
    if (nMonType1 > 0 && nMonType1 < sgptDataTables->nMonTypeTxtRecordCount
        && nMonType2 > 0 && nMonType2 < sgptDataTables->nMonTypeTxtRecordCount)
    {
        return sgptDataTables->pMonTypeNest[(nMonType1 >> 5) + nMonType2 * sgptDataTables->nMonTypeIndex] & gdwBitMasks[nMonType1 & 31];
    }

    return 0;
}

// 0x0057AD80
void __fastcall SUNITDMG_RemoveShatterState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (SUNIT_IsDead(pUnit) && STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        return;
    }

    STATES_ToggleState(pUnit, nState, 0);
    if (!SUNIT_IsDead(pUnit))
    {
        STATES_ToggleState(pUnit, 107, 0);
    }

    UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\SUnitDmg.cpp", 338);
}

// 0x0057AF00
static __declspec(noinline) int sub_0057AF00_IsMonsterWithoutDeadCol(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    const int nClassId = pUnit->dwClassId;
    return !sub_004638A0_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_DEADCOL_0057AF00);
}

// 0x0057AF30
int __fastcall SUNITDMG_GetColdEffect(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return -50;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return -50;
    }

    return pMonStatsTxtRecord->nColdEffect[pGame->nDifficulty];
}

int __fastcall sub_M424_Emit_0057AF00(D2UnitStrc* pUnit, int nBias)
{
    return sub_0057AF00_IsMonsterWithoutDeadCol(pUnit) + nBias;
}

// 0x0057B170
void __fastcall SUNITDMG_RemoveFreezeState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (SUNIT_IsDead(pUnit) && STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        return;
    }

    STATES_ToggleState(pUnit, nState, 0);
    SUNIT_SetCombatMode(SUNIT_GetGameFromUnit(pUnit), pUnit, 1);

    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = pUnit->pMonsterData->pMonstatsTxt;
        if (pMonStatsTxtRecord)
        {
            int nAiDelay;
            if (!pGame->nGameType && !pGame->dwGameType)
            {
                nAiDelay = pMonStatsTxtRecord->nAIdel[0];
            }
            else
            {
                nAiDelay = pMonStatsTxtRecord->nAIdel[pGame->nDifficulty];
            }

            if (nAiDelay <= 0)
            {
                nAiDelay = 15;
            }

            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            EVENT_SetEvent(pGame, pUnit, 2, nAiDelay + pGame->dwGameFrame, 0, 0);
        }
    }
}

// 0x0057B630
static void __stdcall sub_0057B630_AddDemonDamage(D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2UnkDamageRecordStrc* pRecord)
{
    if (MONSTERS_IsDemon(pTarget))
    {
        const int nBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
        if (nBonus > 0)
        {
            pRecord->nValue += nBonus;
        }
    }
}

void __fastcall sub_K11_Emit0057B630(D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2UnkDamageRecordStrc* pRecord)
{
    sub_0057B630_AddDemonDamage(pAttacker, pTarget, pRecord);
}

// 0x0057BDD0
static int sub_0057BDD0_ReduceByStat(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue)
{
    int nStatId = pRec->nStatId;
    if (nStatId == -1)
    {
        return nValue;
    }

    if (nValue >= 100 && pCtx->bCapped)
    {
        return nValue;
    }

    int nStat = STATLIST_UnitGetStatValue(pCtx->pUnit, nStatId, 0);
    if (!nStat)
    {
        return nValue;
    }

    return nValue - nStat;
}

int __fastcall sub_Emit_0057BDD0(D2StatReduceCtx* pCtx, D2StatReduceRec* pRec, int nValue)
{
    int n = sub_0057BDD0_ReduceByStat(pCtx, pRec, nValue);
    return n + sub_0057BDD0_ReduceByStat(pCtx, pRec + 1, n);
}

static __declspec(noinline) int __cdecl sub_0057BE00_Resistance(Context* c,Record* r)
{
    int resistance=0;
    if(r->resistanceStat!=-1)
        resistance=sub_00625480_Stat(c->defender,r->resistanceStat,0);
    if(r->pierceStat!=-1 && (resistance<100 || !c->defenderFlag))
    {
        int pierce=sub_00625480_Stat(c->attacker,r->pierceStat,0);
        if(pierce) resistance-=pierce;
    }
    if(!c->defenderFlag && r->resistanceStat!=36 && r->resistanceStat!=37)
    {
        if(FIELD(c->game,112)) resistance+=FIELD(c->difficulty,0);
        else
        {
            switch(BYTEFIELD(c->game,109))
            {
            case 1: resistance-=20; break;
            case 2: resistance-=50; break;
            }
        }
    }
    if(resistance<=0)
    {
        if(resistance<=-100) resistance=-100;
    }
    else
    {
        if(!c->defenderFlag)
        {
            int maximum=75;
            if(r->maximumStat!=-1)
            {
                maximum=sub_00625480_Stat(c->defender,r->maximumStat,0)+75;
                if(maximum>=95) maximum=95;
            }
            else if(r->resistanceStat==36) maximum=50;
            resistance=(resistance>-100 ? resistance : -100)<maximum ? (resistance>-100 ? resistance : -100) : maximum;
        }
        if(r->resistanceStat==36 && sub_00639DF0_State(c->attacker,47) && sub_0063E990_ClassB(c->defender)) resistance=0;
    }
    return resistance;
}

static __declspec(noinline) int __cdecl sub_0057BF10_Absorb(Record* r,Context* c,int amount)
{
    if(r->absorbPercentStat!=-1)
    {
        int percent=sub_00625480_Stat(c->defender,r->absorbPercentStat,0);
        if(percent>=40) percent=40;
        if(percent>0)
        {
            int absorbed=sub_00483360_Ratio(amount,percent,100);
            FIELD(c->damage,72)+=absorbed;
            amount-=absorbed;
        }
        int absorbed=sub_00625480_Stat(c->defender,r->absorbFlatStat,0)<<8;
        if(absorbed>0)
        {
            if(absorbed>=amount) absorbed=amount;
            FIELD(c->damage,72)+=absorbed;
            amount-=absorbed;
        }
    }
    return amount;
}

// 0x0057BF80
static __declspec(noinline) int __stdcall sub_0057BF80_Apply(int ignore,Context* c,Record* r)
{
    int* field=&FIELD(c->damage,r->damageOffset);
    int amount=*field;
    int originalAmount=amount;
    if(amount<=0) { *field=0; return 0; }
    int resistance=sub_0057BE00_Resistance(c,r);
    if(ignore)
    {
        if(resistance>0) resistance=0;
    }
    else amount-=FIELD(c,28+4*r->reductionIndex);
    if(amount>0 && resistance)
    {
        if(resistance>=100) resistance=100;
        amount=sub_00483360_Ratio(amount,100-resistance,100);
    }
    sub_005347D0_Report(c->game,c->attacker,c->defender,originalAmount,resistance,FIELD(c,28+4*r->reductionIndex),amount,r->name,r->flags);
    originalAmount=amount;
    if(!ignore)
    {
        amount=sub_0057BF10_Absorb(r,c,amount);
        sub_005347E0_ReportAbsorb(c->game,c->attacker,c->defender,originalAmount-amount,r->name);
    }
    *field=amount;
    return amount;
}

// 0x0057C060
static __declspec(noinline) int __cdecl sub_0057C060_Scale(Context* c)
{
    if(c->attacker && c->defender && c->attacker!=c->defender)
    {
        if(c->defender->type==0)
        {
            if(c->attacker->type==0 || sub_0063EE90_ClassE(c->attacker)) return 17;
            Unit* attacker=c->attacker;
            if(sub_00451F30_HasFlags(attacker,0x80000000u) || sub_0063EE90_ClassE(attacker)) return 17;
        }
        else
        {
            if(sub_0063EE90_ClassE(c->defender) && sub_0063EE90_ClassE(c->attacker)) return 25;
            if(sub_0063EE90_ClassE(c->attacker) && sub_0063E9F0_ClassC(0,c->defender))
            {
                Difficulty* difficulty=c->difficulty;
                if(difficulty) return FIELD(difficulty,56);
                return 100;
            }
            if(sub_0063EDC0_ClassD(c->attacker))
            {
                Unit* defender=c->defender;
                if(sub_00451F30_HasFlags(defender,0x80000000u)) return sub_0063EE90_ClassE(defender) ? 200 : 400;
            }
        }
    }
    return 100;
}

// 0x0057C140
static __declspec(noinline) void __cdecl sub_0057C140_Durations(Context* c)
{
    if(FIELD(c->damage,48)>0 || FIELD(c->damage,52)>0)
    {
        if(sub_00625500_BaseStat(c->defender,153,0))
        {
            FIELD(c->damage,48)=0;
            FIELD(c->damage,52)=0;
        }
        else if(sub_00625500_BaseStat(c->defender,118,0))
        {
            FIELD(c->damage,48)/=2;
            FIELD(c->damage,52)/=2;
        }
    }
    if(FIELD(c->damage,44)>0 && sub_00639DF0_State(c->defender,133)) FIELD(c->damage,44)=0;
    if(FIELD(c->damage,24)>0 && sub_00639DF0_State(c->defender,131)) FIELD(c->damage,24)=0;
}

// 0x0057C1E0
void __fastcall sub_0057C1E0_Total(Game* game,Unit* attacker,Unit* defender,Damage* damage)
{
    Context c;
    c.game=game;
    c.difficulty=sub_00611D30_Difficulty(BYTEFIELD(game,109));
    c.attacker=attacker;
    c.defender=defender;
    c.damage=damage;
    c.attackerFlag=attacker && attacker->type==1 && !sub_0063EE90_ClassE(attacker);
    c.defenderFlag=defender && defender->type==1 && !sub_0063EE90_ClassE(defender);
    c.zeroReduction=0;
    int reduction=sub_00625480_Stat(defender,34,0)<<8;
    if(reduction>0 && FIELD(damage,84)>0) reduction=sub_00483360_Ratio(reduction,FIELD(damage,84),1024);
    c.flatReduction1=reduction;
    reduction=sub_00625480_Stat(defender,35,0)<<8;
    if(reduction>0 && FIELD(damage,84)>0) reduction=sub_00483360_Ratio(reduction,FIELD(damage,84),1024);
    c.flatReduction2=reduction;
    int scale=sub_0057C060_Scale(&c);
    if(scale!=100)
    {
        Record* r=gVar_00732980_Records;
        int remaining=12;
        do
        {
            if(r->scales)
            {
                int* field=&FIELD(damage,r->damageOffset);
                if(*field>0) *field=sub_00483360_Ratio(*field,scale,100);
            }
            ++r;
        } while(--remaining);
    }
    sub_005C0C30_Event(game,11,defender,attacker,damage);
    sub_0057C140_Durations(&c);
    int ignore=0;
    if(defender && defender->type==1)
    {
        int classB=sub_0063E990_ClassB(defender);
        int classA=sub_0063E940_ClassA(defender);
        if(classB && (FIELD(damage,0)&256)) ignore=1;
        if(classA && (FIELD(damage,0)&512)) ignore=1;
        if(!classB && !classA && (FIELD(damage,0)&1024)) ignore=1;
    }
    else if(FIELD(damage,0)&1024) ignore=1;
    Record* r=gVar_00732980_Records;
    for(int i=0;i<12;++i,++r)
    {
        if(r->requiresAttackerFlag && !c.attackerFlag) break;
        sub_0057BF80_Apply(ignore,&c,r);
    }
    FIELD(damage,76)=FIELD(damage,8)+(FIELD(damage,40)+FIELD(damage,36)+FIELD(damage,32)+FIELD(damage,28)+FIELD(damage,16));
    if(c.attackerFlag) FIELD(damage,76)+=FIELD(damage,56);
}

// 0x0057C980
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (pCombat)
    {
        D2CombatStrc* pPrevious = 0;
        do
        {
            D2CombatStrc* pNext = pCombat->pNext;

            if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId)
            {
                if (!pPrevious)
                {
                    pAttacker->pCombat = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pCombat, ".\\UNIT\\SUnitDmg.cpp", 1897, 0);
            }
            else
            {
                pPrevious = pCombat;
            }

            pCombat = pNext;
        }
        while (pCombat);
    }
}

// 0x0057C9F0
void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (pCombat)
    {
        D2CombatStrc* pPrevious = 0;
        do
        {
            D2CombatStrc* pNext = pCombat->pNext;

            if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId && pCombat->dwDefenderType == pDefender->dwUnitType && pCombat->dwDefenderId == pDefender->dwUnitId)
            {
                if (!pPrevious)
                {
                    pAttacker->pCombat = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }

                FOG_FreeServerMemory(pGame->pMemoryPool, pCombat, ".\\UNIT\\SUnitDmg.cpp", 1951, 0);
            }
            else
            {
                pPrevious = pCombat;
            }

            pCombat = pNext;
        }
        while (pCombat);
    }
}

// 0x0057CA80
static void __stdcall sub_0057CA80_AddCombatRecord(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (pDefender && pDefender->dwUnitType == UNIT_OBJECT && (pDefender->dwClassId == 7 || pDefender->dwClassId == 11))
    {
        return;
    }

    if (pDefender->dwUnitType != UNIT_MONSTER && pDefender->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2CombatStrc* pCombat = (D2CombatStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2CombatStrc), ".\\UNIT\\SUnitDmg.cpp", 1995, 0);
    pCombat->pGame = pGame;
    pCombat->dwAttackerType = pAttacker->dwUnitType;
    pCombat->dwAttackerId = pAttacker->dwUnitId;
    pCombat->dwDefenderType = pDefender->dwUnitType;
    pCombat->dwDefenderId = pDefender->dwUnitId;
    memcpy(&pCombat->tDamage, pDamage, sizeof(pCombat->tDamage));
    pCombat->pNext = pAttacker->pCombat;
    pAttacker->pCombat = pCombat;
}

// 0x0057D690
D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pAttacker || !pDefender)
    {
        return 0;
    }

    for (D2CombatStrc* pCombat = pAttacker->pCombat; pCombat; pCombat = pCombat->pNext)
    {
        if (pCombat->dwAttackerType == sub_0044BE50_GetUnitTypeOrInvalid(pAttacker) && pCombat->dwAttackerId == sub_00451F50_GetUnitGUID(pAttacker)
            && pCombat->dwDefenderType == sub_0044BE50_GetUnitTypeOrInvalid(pDefender) && pCombat->dwDefenderId == sub_00451F50_GetUnitGUID(pDefender))
        {
            return &pCombat->tDamage;
        }
    }

    return 0;
}

// 0x0057D700
unsigned short __fastcall sub_0057D700_GetCombatResultFlags(D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    if (!pDefender || !pAttacker)
    {
        return 0;
    }

    D2CombatStrc* pCombat = pAttacker->pCombat;
    if (!pCombat)
    {
        return 0;
    }

    for (; pCombat; pCombat = pCombat->pNext)
    {
        if (pCombat->dwAttackerType == pAttacker->dwUnitType && pCombat->dwAttackerId == pAttacker->dwUnitId
            && pCombat->dwDefenderType == pDefender->dwUnitType && pCombat->dwDefenderId == pDefender->dwUnitId)
        {
            return (unsigned char)pCombat->tDamage.wResultFlags;
        }
    }

    return 0;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0057D760
int __stdcall SUNITDMG_RollAndCompareValues(D2UnitStrc* pUnit, int* pFirstValue, int* pSecondValue)
{
    *pFirstValue = SEED_RollLimitedRandomNumber(&pUnit->pSeed, *pFirstValue);
    *pSecondValue = SEED_RollLimitedRandomNumber(&pUnit->pSeed, *pSecondValue);

    return *pFirstValue >= *pSecondValue;
}

// 0x0057DBF0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam)
{
    if (!pAttacker || !pDefender)
    {
        return;
    }

    const unsigned int nAttackerType = pAttacker->dwUnitType;
    if (!(pDamage->wResultFlags & 0x8380) && pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        if (!(pDamage->dwHitFlags & DAMAGEHITFLAG_2))
        {
            SUNITDMG_FillDamageValues(pGame, pAttacker, pDefender, pDamage, 0, nSrcDam);
        }

        SUNITDMG_CalculateTotalDamage(pGame, pAttacker, pDefender, pDamage);

        int nTotalDamage = pDamage->dwPhysDamage + pDamage->dwFireDamage + pDamage->dwLtngDamage + pDamage->dwMagDamage + pDamage->dwColdDamage + pDamage->dwPoisDamage;
        if (nAttackerType == UNIT_MONSTER)
        {
            nTotalDamage += pDamage->dwLifeLeech;
        }

        const int nHitpoints = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0);
        if ((nTotalDamage & ~0xFF) > (nHitpoints & ~0xFF))
        {
            pDamage->wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
        }
    }

    sub_0057CA80_AddCombatRecord(pGame, pAttacker, pDefender, pDamage);
}

// 0x0057E240
void __fastcall SUNITDMG_RollDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage)
{
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, pDamage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
}

// 0x0057E2F0
static int sub_0057E2F0_ApplyLevelDifferenceFactor(int nAttackerLevel, int nExperience, int nDefenderLevel)
{
    if (nDefenderLevel <= nAttackerLevel)
    {
        int nIndex = nAttackerLevel - nDefenderLevel;
        if (nIndex >= 11)
        {
            nIndex = 10;
        }

        const int nFactor = gnExpFactorLowerLevel_006E1668[nIndex];
        if (nFactor != 256)
        {
            return DATATBLS_ApplyRatio(nExperience, nFactor, 256);
        }
    }
    else
    {
        if (nAttackerLevel >= 25 && nDefenderLevel > 0)
        {
            return DATATBLS_ApplyRatio(nExperience, nAttackerLevel, nDefenderLevel);
        }

        int nIndex = nDefenderLevel - nAttackerLevel;
        if (nIndex >= 11)
        {
            nIndex = 10;
        }

        const int nFactor = gnExpFactorHigherLevel_006E1694[nIndex];
        if (nFactor != 256)
        {
            return DATATBLS_ApplyRatio(nExperience, nFactor, 256);
        }
    }

    return nExperience;
}

// 0x0057E350
int __fastcall sub_0057E350_ApplyExpRatio(int nValue, int nRatio, int nShift)
{
    if (nShift > 0 && nShift < 32)
    {
        if (nValue > (0x7FFFFFFF >> (nShift + (nRatio >> nShift))))
        {
            return (nValue >> nShift) * nRatio;
        }

        return nValue * nRatio >> nShift;
    }

    return nValue;
}

// 0x0057E390
static int __stdcall sub_0057E390_ApplyExpRatio(int nLevel, int nResult)
{
    if (nResult <= 0)
    {
        return nResult;
    }

    const int nRatio1 = DATATBLS_GetExpRatio(nLevel);
    const int nRatio2 = DATATBLS_GetExpRatio(0);
    if (nRatio2 > 0 && nRatio2 < 32)
    {
        if (nResult > (0x7FFFFFFF >> (nRatio2 + (nRatio1 >> nRatio2))))
        {
            nResult = nRatio1 * (nResult >> nRatio2);
        }
        else
        {
            nResult = nResult * nRatio1 >> nRatio2;
        }
    }

    return nResult;
}

// 0x0057E3F0
static unsigned int __stdcall sub_0057E3F0_CapHirelingExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, int nAttackerLevel, unsigned int nResult)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER)
    {
        return nResult;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, !pAttacker ? -1 : pAttacker->dwUnitId);
    if (!pPetInfo)
    {
        return 0;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nAttackerLevel);
    if (!pHirelingTxtRecord)
    {
        return 0;
    }

    const int nCurrentLevelExp = MONSTERS_GetHirelingExpForNextLevel(nAttackerLevel, pHirelingTxtRecord->dwExpPerLvl);
    const int nNextLevelExp = MONSTERS_GetHirelingExpForNextLevel(nAttackerLevel + 1, pHirelingTxtRecord->dwExpPerLvl);
    const unsigned int nMaxExp = (unsigned int)(nNextLevelExp - nCurrentLevelExp) >> 6;
    if (nResult > nMaxExp)
    {
        nResult = nMaxExp;
    }

    return nResult;
}

// 0x0057E480
static int __stdcall SUNITDMG_ComputeExperienceGain(D2GameStrc* pGame, int nAttackerLevel, D2UnitStrc* pAttacker, int nDefenderLevel, int nDefenderExperience)
{
    if (nDefenderExperience > 0x7FFFFF)
    {
        nDefenderExperience = 0x7FFFFF;
    }

    if (nDefenderExperience <= 0)
    {
        return 1;
    }

    const int nClassId = (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER) ? pAttacker->dwClassId : 0;
    if (nAttackerLevel >= DATATBLS_GetMaxLevel(nClassId))
    {
        return 0;
    }

    int nResult = sub_0057E2F0_ApplyLevelDifferenceFactor(nAttackerLevel, nDefenderExperience, nDefenderLevel);
    nResult = sub_0057E390_ApplyExpRatio(nAttackerLevel, nResult);

    const int nAddExpPct = STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_ADDEXPERIENCE, 0);
    if (nAddExpPct)
    {
        nResult += DATATBLS_ApplyRatio(nResult, nAddExpPct, 100);
    }

    return sub_0057E3F0_CapHirelingExperience(pGame, pAttacker, nAttackerLevel, nResult);
}

// 0x0057E510
static void __stdcall SUNITDMG_AddExperienceForPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOldLevel, unsigned int nExperienceGained)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    const int nClassId = pUnit->dwClassId;
    unsigned int nNewExperience = nExperienceGained + nExperience;
    const unsigned int nMaxExperience = DATATBLS_GetLevelThreshold(nClassId, DATATBLS_GetMaxLevel(nClassId) - 1);
    if (nNewExperience > nMaxExperience)
    {
        nNewExperience = nMaxExperience;
    }

    STATLIST_SetUnitStat(pUnit, STAT_LASTEXP, nNewExperience - nExperience, 0);
    STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nNewExperience, 0);

    if (nOldLevel != DATATBLS_GetCurrentLevelFromExp(nClassId, nNewExperience))
    {
        PLAYERSTATS_LevelUp(pGame, pUnit);
        SUNITEVENT_Trigger(pGame, UNITEVENT_LEVELUP, pUnit, 0, 0);
    }
}

// 0x0057E6C0
static void __stdcall sub_0057E6C0_DistributePartyExperience(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDefender, int nPlayerLevel, int nDefenderLevel, int nDefenderExperience)
{
    D2PartyExpStrc partyExp;
    memset(&partyExp, 0, sizeof(partyExp));
    partyExp.pDefenderUnit = pDefender;
    PARTY_IteratePartyMembersInSameLevel(pGame, pPlayer, SUNITDMG_PartyCallback_ComputePartyExperience, &partyExp);

    if (partyExp.nMembers <= 0 || partyExp.nLevelSum <= 0)
    {
        return;
    }

    if (partyExp.nMembers == 1)
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pPlayer, nPlayerLevel, SUNITDMG_ComputeExperienceGain(pGame, nPlayerLevel, pPlayer, nDefenderLevel, nDefenderExperience));
        return;
    }

    const int nExperience = nDefenderExperience + 89 * nDefenderExperience * (partyExp.nMembers - 1) / 256;
    const float multiplier = (float)nExperience / (float)partyExp.nLevelSum;
    for (int i = 0; i < partyExp.nMembers; ++i)
    {
        const int nMemberLevel = partyExp.nMemberLevels[i];
        D2UnitStrc* pMember = partyExp.pMembers[i];
        const int nExperienceGained = SUNITDMG_ComputeExperienceGain(pGame, nMemberLevel, pMember, nDefenderLevel, (int)((float)nMemberLevel * multiplier));
        SUNITDMG_AddExperienceForPlayer(pGame, pMember, nMemberLevel, nExperienceGained);
    }
}

// 0x0057E7B0
static D2UnitStrc* __stdcall sub_0057E7B0_GetExperienceOwner(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    int nType = UNIT_INVALID;
    if (pAttacker)
    {
        nType = pAttacker->dwUnitType;
    }

    switch (nType)
    {
    case UNIT_MONSTER:
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        D2StatListStrc* pStatList = 0;
        if (STATES_CheckStateMaskExpOnUnit(pAttacker))
        {
            pStatList = STATLIST_GetStatListFromUnitAndFlag(pAttacker, STATLIST_FLAG_EXP);
        }

        if (pDefender && STATES_CheckStateMaskExpOnUnit(pDefender))
        {
            pStatList = STATLIST_GetStatListFromUnitAndFlag(pDefender, STATLIST_FLAG_EXP);
        }

        if (pStatList)
        {
            const int nOwnerType = STATLIST_GetOwnerType(pStatList);
            const int nOwnerGUID = STATLIST_GetOwnerGUID(pStatList);
            pOwner = SUNIT_GetServerUnit(pGame, nOwnerType, nOwnerGUID);
        }

        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            return pOwner;
        }

        return 0;
    }
    case UNIT_PLAYER:
        return pAttacker;
    }

    return 0;
}

// 0x0057E860
static void __stdcall SUNITDMG_AddExperienceForHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pHireling, int nLevel, int nExperienceBonus)
{
    if (nExperienceBonus <= 0)
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, !pHireling ? -1 : pHireling->dwUnitId);
    if (!pPetInfo)
    {
        return;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord || nLevel >= STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0))
    {
        return;
    }

    const unsigned int nCurrentExp = STATLIST_GetUnitBaseStat(pHireling, STAT_EXPERIENCE, 0);
    const unsigned int nNewExp = nCurrentExp + 2 * nExperienceBonus;
    const int nMaxLevel = DATATBLS_GetMaxLevel(0) - 1;
    if (nLevel >= nMaxLevel)
    {
        return;
    }

    STATLIST_SetUnitStat(pHireling, STAT_EXPERIENCE, nNewExp, 0);
    D2GAME_PACKETS_SendPacket0xA0_A1_A2_6FC3D610(SUNIT_GetClientFromPlayer(pPlayer, ".\\UNIT\\SUnitDmg.cpp", 4029), pHireling, STAT_EXPERIENCE, nCurrentExp, nNewExp);

    int nNewLevel = nLevel;
    do
    {
        if ((unsigned int)MONSTERS_GetHirelingExpForNextLevel(nNewLevel + 1, pHirelingTxtRecord->dwExpPerLvl) > nNewExp)
        {
            break;
        }

        nNewLevel += 1;
    }
    while (nNewLevel < nMaxLevel);

    if (nNewLevel > nLevel)
    {
        MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pHireling, nNewLevel);
        MONSTERAI_SendMercStats(pGame, pPlayer, 0);
        SUNIT_AttachSound(pHireling, 0x5B, pPlayer);
        SUNITEVENT_Trigger(pGame, UNITEVENT_LEVELUP, pHireling, 0, 0);
    }
}

// build: context SUNITDMG_DistributeExperience
void __fastcall SUNITDMG_DistributeExperience(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    int nPlayerLevel;
    if (!pAttacker || !pDefender || pAttacker->dwUnitType != UNIT_PLAYER && pAttacker->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    const int nDefenderExperience = STATLIST_GetUnitBaseStat(pDefender, STAT_EXPERIENCE, 0);
    if (nDefenderExperience <= 0)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_0057E7B0_GetExperienceOwner(pGame, pAttacker, pDefender);
    if (!pPlayer)
    {
        return;
    }

    const int nDefenderLevel = STATLIST_GetUnitBaseStat(pDefender, STAT_LEVEL, 0);
    D2UnitStrc* pPet = sub_6FC7E8B0(pGame, pPlayer, PETTYPE_HIREABLE, 0);
    if (pPet)
    {
        const int nPetLevel = STATLIST_GetUnitBaseStat(pPet, STAT_LEVEL, 0);
        int nExperienceBonus = SUNITDMG_ComputeExperienceGain(pGame, nPetLevel, pPet, nDefenderLevel, nDefenderExperience);
        if (pAttacker != pPet)
        {
            nExperienceBonus = 86 * nExperienceBonus / 256;
        }

        SUNITDMG_AddExperienceForHireling(pGame, pPlayer, pPet, nPetLevel, nExperienceBonus);
    }

    nPlayerLevel = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0);
    if (SUNIT_GetPartyId(pPlayer) != -1)
    {
        sub_0057E6C0_DistributePartyExperience(pGame, pPlayer, pDefender, nPlayerLevel, nDefenderLevel, nDefenderExperience);
    }
    else
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pPlayer, nPlayerLevel, SUNITDMG_ComputeExperienceGain(pGame, nPlayerLevel, pPlayer, nDefenderLevel, nDefenderExperience));
    }
}

// 0x0057EAB0
void __fastcall SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pUnit, int nExperienceBonus)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }

    const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        SUNITDMG_AddExperienceForPlayer(pGame, pUnit, nLevel, nExperienceBonus);
    }
    else
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            SUNITDMG_AddExperienceForHireling(pGame, pOwner, pUnit, nLevel, nExperienceBonus);
        }
    }
}

// 0x0057F390
void __fastcall sub_0057F390_DropCorpseGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody, int nGold, int nUnused)
{
    if (nGold > 0)
    {
        D2UnitStrc* pGoldPiles[GOLD_PILE_COUNT];
        int nCount = 0;
        sub_0055A090_DropGoldPiles(pGame, pDeadBody, nGold, pGoldPiles, &nCount, GOLD_PILE_COUNT);

        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pGold = pGoldPiles[i];
            D2_ASSERT(ITEMS_GetItemType(pGold) == ITEMTYPE_GOLD, 588);
            ITEMS_SetOwnerId(pGold, sub_00451F50_GetUnitGUID(pPlayer));
        }
    }
}

// 0x0057FDC0
void __fastcall PLRMODE_StartXY_Block(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(pPlayer, 1095);

    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    sub_6FCBC4D0(pPlayer);
    UNITS_SetUsedSkill(pPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
}

// 0x0057FE30
void __fastcall PLRMODE_StartXY_GetHit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(pPlayer, 1136);

    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    sub_6FCBC4D0(pPlayer);
    UNITS_SetUsedSkill(pPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
}

// 0x0057FE90
void __fastcall PLRMODE_StartXY_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
    pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    sub_6FD12FD0(pGame, pPlayer);
}

// 0x0057FEF0
void __fastcall PLRMODE_StartID_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* pTarget)
{
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);

    D2_ASSERT(pTarget, 1215);

    UNITS_SetTargetUnitForDynamicUnit(pPlayer, pTarget);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);

    if (pPlayer)
    {
        pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    }

    sub_6FD12FD0(pGame, pPlayer);
}

// 0x00582380
void __fastcall D2GAME_OBJECTS_TrapHandler5_7_6FC75BC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2UnitStrc* pFireLarge = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_LARGE, pCoord.nX, pCoord.nY, pGame, pRoom, 1, 1, 0);
    if (pFireLarge)
    {
        D2GAME_SetSparkChest_6FCBD7C0(pFireLarge, 2);
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    const int nX = pCoord.nX + 1;
    if (nX >= drlgCoords.nSubtileX && nX < drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        D2UnitStrc* pFireSmall = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_SMALL, nX, pCoord.nY, pGame, UNITS_GetRoom(pUnit), 1, 1, 0);
        D2GAME_SetSparkChest_6FCBD7C0(pFireSmall, 2);
    }
}

// 0x00582800
void __fastcall sub_00582800_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback)
{
    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 0;
    curse.pTarget = pTarget;
    curse.nDuration = nDuration;
    curse.nStat = nStat;
    curse.nStatValue = nStatValue;
    curse.nState = nState;
    curse.pStateRemoveCallback = pStateRemoveCallback;
    sub_0056E970(&curse);
}

// 0x00582A30
void __fastcall D2GAME_SHRINES_Portal_6FC76880(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->pPlayer);

    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->pPlayer, &pCoord);

    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    const int nTownId = DUNGEON_GetTownLevelIdFromActNo(nAct);

    if (COLLISION_GetFreeCoordinates(UNITS_GetRoom(pOp->pPlayer), &pCoord, 3, 0x1C09, 0))
    {
        D2GAME_CreatePortalObject_6FD13DF0(pOp->pGame, pOp->pPlayer, pRoom, pCoord.nX + 5, pCoord.nY + 5, nTownId, 0, OBJECT_TOWN_PORTAL, 0);
    }
}

// 0x00583A40
void __fastcall sub_6FC77AB0(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FD10E50(pUnit, nState, pStatList);
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
}

// 0x00583BD0
void __fastcall sub_6FC77C10(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    sub_6FD10E50(pUnit, nState, pStatList);
    sub_6FD14C30(pUnit);
}

// 0x00583E70
int __fastcall OBJECTS_OperateFunction33_WirtsBody(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        pOp->pObject->dwDropItemCode = ' gel';

        int nItemLevel;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->pObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);

            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + 10, 0, 0);
        }
    }

    return 1;
}

// 0x00584160
int __fastcall OBJECTS_OperateFunction19_ArmorStand(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->pObject, &pCoord);
        D2GAME_DropArmor_6FC4F830(pOp->pGame, UNITS_GetRoom(pOp->pObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x005841D0
int __fastcall OBJECTS_OperateFunction20_WeaponRack(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->pObject, &pCoord);
        D2GAME_DropWeapon_6FC4FA50(pOp->pGame, UNITS_GetRoom(pOp->pObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->pObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x00584540
int __fastcall sub_6FC78B20(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nObjectType, int nObjectGUID)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, nObjectType, nObjectGUID);
    if (!pObject)
    {
        return 0;
    }

    const int nClassId = pObject->dwClassId;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && !DATATBLS_GetObjectsTxtRecord(nClassId)->nMonsterOK)
        {
            return 1;
        }

        if (!UNITS_IsObjectInInteractRange(pUnit, pObject))
        {
            return 1;
        }
    }

    int nResult = 1;
    OBJECTS_OperateHandler(pGame, pUnit, nObjectType, nObjectGUID, &nResult);
    return nResult;
}

// build: context SUNITDMG_SetExperienceForTargetLevel
void __fastcall SUNITDMG_SetExperienceForTargetLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel)
{
    int nClassId;
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }

    const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
    if (nTargetLevel <= nLevel)
    {
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nClassId = pUnit->dwClassId;
        const unsigned int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        const unsigned int nThreshold = DATATBLS_GetLevelThreshold(nClassId, nTargetLevel);
        if (nThreshold > nExperience)
        {
            SUNITDMG_AddExperienceForPlayer(pGame, pUnit, nLevel, nThreshold - nExperience);
        }
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER || nLevel >= DATATBLS_GetMaxLevel(0))
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, pUnit->dwUnitId);
    if (!pPetInfo)
    {
        return;
    }

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    const int nExperience = STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
    SUNITDMG_AddExperienceForHireling(pGame, pOwner, pUnit, nLevel, MONSTERS_GetHirelingExpForNextLevel(nTargetLevel, pHirelingTxtRecord->dwExpPerLvl) - nExperience);
}

#include "gen/data/Source/D2Game/UNIT/SUnitDmg.inc"
