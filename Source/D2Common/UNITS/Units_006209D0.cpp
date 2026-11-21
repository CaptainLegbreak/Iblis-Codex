#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameObjs.h"
#include "D2UnitData.h"
#include "D2Path.h"

#define COLLIDE_WALL 0x1

#define COLLIDE_MISSILE_BARRIER 0x4

#define COLLIDE_ITEM 0x200

#define COLLIDE_OBJECT 0x400

#define COLLIDE_MASK_DOOR_BLOCK_VIS 0x806

#define OBJSUBCLASS_TOWNPORTAL 0x4

#define STAT_TOHIT 0x13

#define STAT_DEXTERITY 0x2

#define STAT_HITPOINTS 0x6

#define STAT_MANA 0x8

#define STAT_LEVEL 0xC

#define DEX_BASE 7

#define DEX_MUL 5

struct D2MonStats2Txt;

struct D2ObjectsTxt;

struct D2ObjectDataStrc;

struct D2CharStatsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pPath); // 0x00648C10

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

unsigned int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

#pragma function(memset)

struct D2BitBufferStrc;

struct D2WaypointDataStrc;

struct D2RosterInfoStrc;

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

D2RosterInfoStrc* __fastcall sub_004DC0B0_GetNextRosterInfo(D2RosterInfoStrc* pRosterInfo);

int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30

D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool);                                         // 0x0065C430

D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool);                                  // 0x00660F30

void __stdcall sub_0066A250(int nUnused);

struct D2SkillStrc;

struct D2TimerArgStrc;

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0

int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit);                                                      // 0x00622D00

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0

#pragma intrinsic(memset)

#define STRCOPY_MAX 0x7FFFFFFF

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770

#define MONMODE_DEAD 12

#define MONSTATS2FLAGINDEX_CORPSESEL 7

#define MONSTATS2FLAGINDEX_DEADCOL 19

// 0x006209D0
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 2062);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
        if (ptUnit->pObjectData->pObjectTxt->nIsDoor)
        {
            if (ptUnit->pObjectData->pObjectTxt->nBlocksVis)
            {
                return COLLIDE_MASK_DOOR_BLOCK_VIS;
            }
            else if (ptUnit->pObjectData->pObjectTxt->nBlockMissile)
            {
                return COLLIDE_DOOR | COLLIDE_MISSILE_BARRIER;
            }
            else
            {
                return COLLIDE_OBJECT;
            }
        }
        else
        {
            if (ptUnit->pObjectData->pObjectTxt->nSubClass & OBJSUBCLASS_TOWNPORTAL)
            {
                return COLLIDE_CORPSE;
            }
            else if (ptUnit->pObjectData->pObjectTxt->nBlockMissile)
            {
                return COLLIDE_OBJECT | COLLIDE_MISSILE_BARRIER;
            }
            else
            {
                return COLLIDE_OBJECT;
            }
        }

    case UNIT_ITEM:
        return COLLIDE_ITEM;

    case UNIT_TILE:
        return COLLIDE_WALL;

    default:
        return PATH_GetFootprintCollisionMask(ptUnit->pDynamicPath);
    }
}

// 0x006217C0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3457);

    if (ptUnit->pAnimSeq)
    {
        return ptUnit->dwFrameCountPrecise <= 0;
    }
    else
    {
        return ptUnit->nSeqCurrentFramePrecise + ptUnit->wAnimSpeed >= ptUnit->dwFrameCountPrecise;
    }
}

// 0x00621F90
void __stdcall UNITS_AllocPlayerData(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3919);
    D2_ASSERT(!ptUnit->pPlayerData, 3921);

    ptUnit->pPlayerData = (D2PlayerDataStrc*)FOG_AllocPool(ptUnit->pMemoryPool, sizeof(D2PlayerDataStrc), ".\\UNITS\\Units.cpp", 3922, 0);
    memset(ptUnit->pPlayerData, 0x00, sizeof(D2PlayerDataStrc));
    ptUnit->pPlayerData->szName[0] = 0;

    for (int i = 0; i < 3; ++i)
    {
        D2BitBufferStrc* const pQuestRecord = QUESTRECORD_AllocRecord(sub_004DC0B0_GetNextRosterInfo((D2RosterInfoStrc*)ptUnit));
        (*(D2PlayerDataStrc* volatile*)&ptUnit->pPlayerData)->pQuestData[i] = pQuestRecord;
        ptUnit->pPlayerData->pWaypointData[i] = WAYPOINTS_AllocWaypointData(sub_004DC0B0_GetNextRosterInfo((D2RosterInfoStrc*)ptUnit));
    }

    ptUnit->pPlayerData->nPortalFlags = DUNGEON_GetPortalFlagFromLevelId(1);
    ptUnit->pPlayerData->bBusy = 0;
    sub_0066A250((int)ptUnit);
}

// 0x00622150
char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4005);
    D2_ASSERT(pUnit->pPlayerData, 4007);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4008);

    return pUnit->pPlayerData->szName;
}

// 0x006221E0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags)
{
    D2_ASSERT(pUnit, 4031);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4032);

    pUnit->pPlayerData->nPortalFlags = nPortalFlags;
}

// 0x00622230
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4041);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4042);

    return pUnit->pPlayerData->nPortalFlags;
}

// 0x00622270
unsigned int __stdcall UNITS_GetNameOffsetFromObject(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 4051);

    if (ptUnit->dwUnitType == UNIT_OBJECT)
    {
        return ptUnit->pObjectData->pObjectTxt->dwNameOffset;
    }

    return 0;
}

// 0x006222C0
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4068);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4069);
    return pUnit->pObjectData->nPortalFlags;
}

// 0x00622300
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag)
{
    D2_ASSERT(pUnit, 4079);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4080);
    pUnit->pObjectData->nPortalFlags = nPortalFlag;
}

// 0x00622350
int __stdcall UNITS_CheckObjectPortalFlag(D2UnitStrc* pUnit, unsigned char nFlag)
{
    D2_ASSERT(pUnit, 4090);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4091);

    return (nFlag & pUnit->pObjectData->nPortalFlags) != 0;
}

// 0x006223A0
int __stdcall UNITS_GetOverlayHeight(D2UnitStrc* pUnit)
{
    switch (!pUnit ? UNIT_INVALID : pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return 1;

    case UNIT_MONSTER:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return 0;
        }

        return pMonStats2TxtRecord->nOverlayHeight - 1;
    }
    }

    return 0;
}

// 0x00622DC0
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit)
{
    return UNITS_IsInMovingMode(pUnit) != 0;
}

// 0x00622DE0
unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit)
{
    const unsigned int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const unsigned int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const unsigned int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);

    unsigned int nShiftedLifeDifference = 0;
    unsigned int nShiftedManaDifference = 0;

    if (nMaxLife > nLife)
    {
        nShiftedLifeDifference = (nMaxLife - nLife) >> 8;
    }

    if (nMaxMana > nMana)
    {
        nShiftedManaDifference = (nMaxMana - nMana) >> 8;
    }

    if (nShiftedLifeDifference || nShiftedManaDifference)
    {
        return (nShiftedLifeDifference + nShiftedManaDifference) * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) >> 2;
    }

    return 0;
}

// 0x00622E90
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int a2)
{
}

inline D2PlayerDataStrc* UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x00623300
void __stdcall UNITS_SetSwitchLeftSkill(D2UnitStrc* pUnit, int nSwitchLeftSkillId, int nSwitchLeftSkillFlags)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 5288);

        pPlayerData->nSwitchLeftSkillId = nSwitchLeftSkillId;
        pPlayerData->nSwitchLeftSkillFlags = nSwitchLeftSkillFlags;
    }
}

// 0x00623350
void __stdcall UNITS_SetSwitchRightSkill(D2UnitStrc* pUnit, int nSwitchRightSkillId, int nSwitchRightSkillFlags)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 5303);

        pPlayerData->nSwitchRightSkillId = nSwitchRightSkillId;
        pPlayerData->nSwitchRightSkillFlags = nSwitchRightSkillFlags;
    }
}

// 0x006233A0
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* hWeapon)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 5317);

        if (hWeapon)
        {
            D2_ASSERT(hWeapon->dwUnitType == UNIT_ITEM, 5321);

            pPlayerData->nWeaponGUID = hWeapon->dwUnitId;
        }
        else
        {
            pPlayerData->nWeaponGUID = 0;
        }
    }
}

// 0x006234C0
void __fastcall UNITS_SetTimerArg(D2UnitStrc* pUnit, D2TimerArgStrc* pTimerArg)
{
    D2_ASSERT(pUnit, 5387);

    pUnit->pTimerArg = pTimerArg;
}

// 0x006234F0
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 5395);

    return pUnit->pTimerArg;
}

// 0x00623520
void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit)
{
    if (!pUnit->pStaticPath)
    {
        pUnit->pStaticPath = (D2StaticPathStrc*)sub_0040B430(pUnit->pMemoryPool, sizeof(D2StaticPathStrc), ".\\UNITS\\Units.cpp", 5406, 0);
        memset(pUnit->pStaticPath, 0x00, sizeof(D2StaticPathStrc));
    }
}

// 0x00623570
void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit)
{
    if (pUnit->pStaticPath)
    {
        FOG_FreeServerMemory(pUnit->pMemoryPool, pUnit->pStaticPath, ".\\UNITS\\Units.cpp", 5419, 0);
    }
}

// 0x00623600
int __stdcall UNITS_IsCorpseUseable(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    if (pUnit->dwAnimMode != MONMODE_DEAD)
        return 0;

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2TxtRecord)
        return 0;

    if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_DEADCOL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_DEADCOL & 7])
        return 0;

    if (!(pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_CORPSESEL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_CORPSESEL & 7]))
        return 0;

    return STATES_CheckStateMaskUdeadOnUnit(pUnit) == 0;
}
