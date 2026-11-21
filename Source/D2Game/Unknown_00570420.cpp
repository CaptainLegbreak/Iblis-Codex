#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2MonModes.h"

#define MONTYPEFLAG_UNIQUE 8
#define EVENTTYPE_REMOVESTATE 0x0C

#define UNITFLAG_DOUPDATE 1
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
struct D2ModeChangeStrc;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2ServerCallbacks;
struct D2StatesTxt;
struct D2GSPacketSrvAA;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall sub_6FD10E50(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall sub_00570850_Forward(void* pUnused, D2UnitStrc* pUnit, int nArg); // 0x00570850

typedef void (__fastcall* LevelCallback)(unsigned int, int);

struct D2ServerCallbacks { char unk_00[44]; LevelCallback levelUp; };

extern D2ServerCallbacks* gpServerCallbacks; // 0x00883D50
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience); // 0x00611860
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall sub_00625D60(D2UnitStrc*); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc*); // 0x00625DB0
void __fastcall sub_00536850_UpdateLevel(D2GameStrc*,D2UnitStrc*,int); // 0x00536850
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
void __fastcall sub_0055F500_RefreshItemStatLists(D2GameStrc*,D2UnitStrc*); // 0x0055F500
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc*,D2UnitStrc*,int); // 0x0055FDE0
int __stdcall sub_00622150_GetLevelInfo(D2UnitStrc*,int,int); // 0x00622150
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
static void sub_00570A50_SpendStatPointsOnStrength(D2UnitStrc* pUnit, int nValue);
static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue);

struct D2BitBufferStrc { unsigned char* pBuffer; int nBits; int nPos; int nPosBits; int bFull; };

struct D2StatesTxt { char unk_00[0x10]; unsigned char nStateFlags[8]; char unk_18[0x24]; };

#pragma pack(push, 1)
struct D2GSPacketSrvAA { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nSize; unsigned char pStream[244]; };

#pragma pack(pop)

extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern const unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc*); // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int); // 0x004111A0
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc*); // 0x0063A100
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc*, D2StatStrc*, int); // 0x00625C90
void __fastcall sub_0053E8D0_SendPacket(D2ClientStrc*, const void*, int); // 0x0053E8D0

// 0x00570420
void __fastcall sub_6FD14F70(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nDelay)
{
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && !MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE) && !MONSTERS_IsBoss(0, pUnit))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nDelay);
        int nFrame = pGame->dwGameFrame;
        if (!pStatList)
        {
            const int nUnitGUID = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            nFrame += 100;
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nFrame, nUnitType, nUnitGUID);
            if (pStatList)
            {
                EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
                STATLIST_SetState(pStatList, STATE_STUNNED);
                STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                STATES_ToggleState(pUnit, STATE_STUNNED, 1);
            }
        }
        else
        {
            nFrame += nDelay;
            D2COMMON_10476(pStatList, nFrame);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
        }

        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_NEUTRAL, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
        pUnit->dwFlags &= ~UNITFLAG_DOUPDATE;
    }
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x00570590
D2StatListStrc* __fastcall sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nState, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    const int nAuraLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const unsigned int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nAuraLength + pGame->dwGameFrame, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }
    STATLIST_SetState(pStatList, nState);
    STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    STATES_ToggleState(pTarget, nState, 1);
    EVENT_SetEvent(pGame, pTarget, 0xC, nAuraLength + pGame->dwGameFrame, 0, 0);
    sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    return pStatList;
}

// 0x005706A0
static void __stdcall sub_005706A0_UseActEntry(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }
    if (nAct >= gnActCount_007326B4)
    {
        nAct = 0;
    }
    sub_0057EB10(pGame, pUnit, gnActEntries_006E1520[nAct]);
}

void __fastcall sub_K11_Emit005706A0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    sub_005706A0_UseActEntry(pGame, pUnit, nAct);
}

#include "gen/data/Source/D2Game/Unknown_00570420.inc"
struct D2MonStatsTxt;

// 0x00570870
static __forceinline void sub_00570870_ForwardToLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_IterateLivingPlayers(pGame, (SUNIT_IterateFn)sub_00570850_Forward, pUnit);
}

void __stdcall sub_M113_Emit_00570870(D2GameStrc* pGame, D2UnitStrc* pFirst, D2UnitStrc* pSecond)
{
    sub_00570870_ForwardToLivingPlayers(pGame, pFirst);
    sub_00570870_ForwardToLivingPlayers(pGame, pSecond);
}

// 0x00570E10
int __cdecl sub_00570E10_GetStateMaskCount()
{
    return (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
}

// 0x00570880
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* game,D2UnitStrc* unit)
{
 int classId;
 if(!unit) classId=-1; else classId=unit->dwClassId;
 int previousLevel=STATLIST_GetUnitBaseStat(unit,STAT_LEVEL,0);
 int level=DATATBLS_GetCurrentLevelFromExp(classId,STATLIST_UnitGetStatValue(unit,STAT_EXPERIENCE,0));
 STATLIST_SetUnitStat(unit,STAT_LEVEL,level,0);
 STATLIST_SetUnitStat(unit,STAT_NEXTEXP,DATATBLS_GetLevelThreshold(classId,level),0);
 int gained=level-previousLevel;
 if(gained>0) {
  D2CharStatsTxt* record=(classId>=0 && classId<sgptDataTables->nCharStatsTxtRecordCount)?&sgptDataTables->pCharStatsTxt[classId]:0;
  int life=STATLIST_GetUnitBaseStat(unit,STAT_MAXHP,0)+((record->lifePerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXHP,life,0);
  int maxLife=STATLIST_GetMaxLifeFromUnit(unit);
  if(STATLIST_UnitGetStatValue(unit,STAT_HITPOINTS,0)>0) STATLIST_SetUnitStat(unit,STAT_HITPOINTS,maxLife,0);
  int mana=STATLIST_GetUnitBaseStat(unit,STAT_MAXMANA,0)+((record->manaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXMANA,mana,0);
  int maxMana=sub_00625D60(unit);
  STATLIST_SetUnitStat(unit,STAT_MANA,maxMana,0);
  int stamina=STATLIST_GetUnitBaseStat(unit,STAT_MAXSTAMINA,0)+((record->staminaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXSTAMINA,stamina,0);
  int maxStamina=STATLIST_GetMaxStaminaFromUnit(unit);
  STATLIST_SetUnitStat(unit,STAT_STAMINA,maxStamina,0);
  STATLIST_AddUnitStat(unit,STAT_STATPTS,record->statPerLevel*gained,0);
  STATLIST_AddUnitStat(unit,STAT_SKILLPTS,gained,0);
  sub_00536850_UpdateLevel(game,unit,level);
  SUNIT_AttachSound(unit,2,unit);
  SUNIT_IterateLivingPlayers(game,(SUNIT_IterateFn)sub_00570850_Forward,unit);
  sub_0055F500_RefreshItemStatLists(game,unit);
  D2GAME_UpdatePlayerItems_6FC4BB90(game,unit,1);
  if(gpServerCallbacks && gpServerCallbacks->levelUp) gpServerCallbacks->levelUp(game->nGameId,sub_00622150_GetLevelInfo(unit,classId,level));
 }
}

// 0x00570A50
static void sub_00570A50_SpendStatPointsOnStrength(D2UnitStrc* pUnit, int nValue)
{
    if (nValue)
    {
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nValue, 0);
        STATLIST_AddUnitStat(pUnit, STAT_STRENGTH, nValue, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
}

void __fastcall sub_C899_Emit_00570A50(D2UnitStrc* pUnit, int nValue)
{
    sub_00570A50_SpendStatPointsOnStrength(pUnit, nValue);
    sub_00570A50_SpendStatPointsOnStrength(pUnit, nValue + 1);
}

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00570A80
static void sub_00570A80_AddEnergyPoints(D2UnitStrc* pUnit, int nPoints)
{
    if (nPoints && pUnit)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nPoints, 0);
            STATLIST_AddUnitStat(pUnit, STAT_ENERGY, nPoints, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, STAT_MANA, pCharStatsTxtRecord->nManaPerMagic * nPoints << 6, 0);
            }
            STATLIST_AddUnitStat(pUnit, STAT_MAXMANA, pCharStatsTxtRecord->nManaPerMagic * nPoints << 6, 0);
            const int nMaxMana = STATLIST_UnitGetStatValue(pUnit, STAT_MAXMANA, 0);
            if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) > nMaxMana)
            {
                STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
            }
        }
    }
}

// 0x00570B60
static void sub_00570B60_AddVitalityPoints(D2UnitStrc* pUnit, int nPoints)
{
    if (nPoints && pUnit)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nPoints, 0);
            STATLIST_AddUnitStat(pUnit, STAT_VITALITY, nPoints, 0);
            STATLIST_AddUnitStat(pUnit, STAT_MAXHP, pCharStatsTxtRecord->nLifePerVitality * nPoints << 6, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, STAT_HITPOINTS, pCharStatsTxtRecord->nLifePerVitality * nPoints << 6, 0);
            }
            const int nMaxHp = STATLIST_UnitGetStatValue(pUnit, STAT_MAXHP, 0);
            if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) > nMaxHp)
            {
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
            }
            STATLIST_AddUnitStat(pUnit, STAT_MAXSTAMINA, pCharStatsTxtRecord->nStaminaPerVitality * nPoints << 6, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, STAT_STAMINA, pCharStatsTxtRecord->nStaminaPerVitality * nPoints << 6, 0);
            }
            const int nMaxStamina = STATLIST_UnitGetStatValue(pUnit, STAT_MAXSTAMINA, 0);
            if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) > nMaxStamina)
            {
                STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
            }
        }
    }
}

// 0x00570C80
void __fastcall sub_00570C80_PLAYERSTATS_ResetToBaseStats(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }
    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }
    int nDiff = pCharStatsTxtRecord->nStr - STATLIST_GetUnitBaseStat(pUnit, STAT_STRENGTH, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nDiff, 0);
        STATLIST_AddUnitStat(pUnit, STAT_STRENGTH, nDiff, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
    sub_00570A80_AddEnergyPoints(pUnit, pCharStatsTxtRecord->nInt - STATLIST_GetUnitBaseStat(pUnit, STAT_ENERGY, 0));
    nDiff = pCharStatsTxtRecord->nDex - STATLIST_GetUnitBaseStat(pUnit, STAT_DEXTERITY, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nDiff, 0);
        STATLIST_AddUnitStat(pUnit, STAT_DEXTERITY, nDiff, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
    sub_00570B60_AddVitalityPoints(pUnit, pCharStatsTxtRecord->nVit - STATLIST_GetUnitBaseStat(pUnit, STAT_VITALITY, 0));
}

// 0x00570D60
int __fastcall PLAYERSTATS_SpendStatPoint(D2UnitStrc* pUnit, int nStatId)
{
    if (!STATLIST_UnitGetStatValue(pUnit, STAT_STATPTS, 0))
    {
        return 0;
    }
    switch (nStatId)
    {
    case 0:
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -1, 0);
        STATLIST_AddUnitStat(pUnit, STAT_STRENGTH, 1, 0);
        UNITROOM_RefreshUnit(pUnit);
        return 1;
    case 1:
        sub_00570A80_AddEnergyPoints(pUnit, 1);
        return 1;
    case 2:
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -1, 0);
        STATLIST_AddUnitStat(pUnit, STAT_DEXTERITY, 1, 0);
        UNITROOM_RefreshUnit(pUnit);
        return 1;
    case 3:
        sub_00570B60_AddVitalityPoints(pUnit, 1);
        return 1;
    }
    return 0;
}

// 0x00570B30
static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue)
{
    if (nValue)
    {
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nValue, 0);
        STATLIST_AddUnitStat(pUnit, STAT_DEXTERITY, nValue, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
}

void __fastcall sub_C899_Emit_00570B30(D2UnitStrc* pUnit, int nValue)
{
    sub_00570B30_SpendStatPointsOnDexterity(pUnit, nValue);
    sub_00570B30_SpendStatPointsOnDexterity(pUnit, nValue + 1);
}

static __forceinline D2StatesTxt* SKILLS_GetStatesTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nStatesTxtRecordCount) return 0; return &sgptDataTables->pStatesTxt[id]; }

static __forceinline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nItemStatCostTxtRecordCount) return 0; return &sgptDataTables->pItemStatCostTxt[id]; }

// build: context sub_GetUnitTypeOrInvalid
static __forceinline int sub_GetUnitTypeOrInvalid(D2UnitStrc* pUnit) { if (!pUnit) return UNIT_INVALID; return pUnit->dwUnitType; }

// 0x00570E30
void __fastcall D2GAME_STATES_SendUnitStates_6FCC58E0(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2BitBufferStrc bitBuffer;
    unsigned int nFlags[8];
    D2StatStrc stats[16];
    if (!pUnit || !pClient) return;
    unsigned int* pFlags = D2COMMON_10494_STATES_GetStatFlags(pUnit);
    const int nTotalStatFlagCount = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
    memcpy(nFlags, pFlags, sizeof(unsigned int) * nTotalStatFlagCount);
    D2GSPacketSrvAA packetAA;
    packetAA.nHeader = 0xAA;
    packetAA.nUnitType = sub_GetUnitTypeOrInvalid(pUnit);
    packetAA.nUnitId = pUnit->dwUnitId;
    BITMANIP_Initialize(&bitBuffer, packetAA.pStream, 244);
    int i = 0;
    int nStateOffset = 0;
    for (; i < nTotalStatFlagCount; ++i, nStateOffset += 32)
    {
        int nBit = sub_004111A0_GetLowestSetBit(nFlags[i]);
        while (nBit >= 0)
        {
            nFlags[i + (nBit >> 5)] &= gdwInvBitMasks[nBit & 31];
            const int nStateId = nBit + nStateOffset;
            D2StatesTxt* pStatesTxtRecord = SKILLS_GetStatesTxtRecord(nStateId);
            if (!pStatesTxtRecord) { nBit = sub_004111A0_GetLowestSetBit(nFlags[i]); continue; }
            if (pStatesTxtRecord->nStateFlags[0] & gdwBitMasks[0]) { nBit = sub_004111A0_GetLowestSetBit(nFlags[i]); continue; }
            {
                if (BITMANIP_GetSize(&bitBuffer) + 7 >= 219) break;
                BITMANIP_Write(&bitBuffer, nStateId, 8);
                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nStateId);
                if (pStatList)
                {
                    const int nStatCount = STATLIST_GetBaseStatsData(pStatList, stats, 16);
                    if (nStatCount > 0)
                    {
                        BITMANIP_Write(&bitBuffer, 1, 1);
                        for (int j = 0; j < nStatCount; ++j)
                        {
                            const int nStatId = (unsigned int)stats[j].nPackedValue >> 16;
                            const unsigned short nLayer = stats[j].nLayer;
                            int nValue = stats[j].nValue;
                            D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
                            if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nSendBits > 0)
                            {
                                if (pItemStatCostTxtRecord->nSendBits < 32)
                                {
                                    if (pItemStatCostTxtRecord->nItemStatFlags[0] & gdwBitMasks[1])
                                    {
                                        const int nMin = -1 << (pItemStatCostTxtRecord->nSendBits - 1);
                                        nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pItemStatCostTxtRecord->nSendBits - 1)) - 1);
                                    }
                                    else
                                    {
                                        nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pItemStatCostTxtRecord->nSendBits) - 1);
                                    }
                                }
                                BITMANIP_Write(&bitBuffer, nStatId, 9);
                                if (pItemStatCostTxtRecord->nSendParamBits)
                                    BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nSendParamBits);
                                BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nSendBits);
                            }
                        }
                        BITMANIP_Write(&bitBuffer, 0x1FF, 9);
                    }
                    else BITMANIP_Write(&bitBuffer, 0, 1);
                }
                else BITMANIP_Write(&bitBuffer, 0, 1);
            }
            nBit = sub_004111A0_GetLowestSetBit(nFlags[i]);
        }
    }
    BITMANIP_Write(&bitBuffer, 0xFF, 8);
    const int nSize = BITMANIP_GetSize(&bitBuffer) + 7;
    packetAA.nSize = nSize;
    sub_0053E8D0_SendPacket(pClient, &packetAA, nSize);
}
