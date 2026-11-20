#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_INVALID 6
#define STATE_NOMANAREGEN 85
#define STAT_MODIFIERLIST_SKILL 350
#define STAT_MODIFIERLIST_LEVEL 351
#define SKILLSFLAGINDEX_AURA 5
#define SKILLSFLAGINDEX_IMMEDIATE 15
struct D2CurseStrc;
struct D2StatesTxt;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2SkillsTxt;



typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

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

struct D2StatesTxt { char unk_00[0x10]; unsigned char nFlags[4]; char unk_14[0x28]; };

struct D2MonStatsTxt { char unk_00[0xC]; unsigned char nFlags[4]; char unk_10[0x198]; };

struct D2MonStats2Txt { char unk_00[4]; unsigned char nFlags[4]; };

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x74];
    short nAuraState;
    unsigned char unk_82[0xC6];
    int dwParamBase;
    int dwParamPerLevel1;
    int dwParamPerLevel2;
    char unk0x154[0xE8];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
void __fastcall sub_6FD10E50(D2UnitStrc*, int, D2StatListStrc*); // 0x0056E900
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc*, int); // 0x00625310
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc*, int); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc*, int); // 0x00625760
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*, StatListRemoveCallback); // 0x00625CE0
void __stdcall STATLIST_SetSkillId(D2StatListStrc*, int); // 0x006260D0
D2SkillStrc* __stdcall sub_006260E0(D2StatListStrc*); // 0x006260E0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc*, int); // 0x006260F0
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc*); // 0x00626100
void __stdcall STATLIST_FreeStatList(D2StatListStrc*); // 0x00626CD0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStat(D2StatListStrc*, int, int, int); // 0x00627150
void __stdcall D2Common_10474(D2UnitStrc*, D2StatListStrc*); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn);
extern "C" const char gszSkillsSourceFile; // 0x006DAB88
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0
int __fastcall sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x0056CDA0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* pSkill, int* pOwnerGUID, int a3, int a4, int a5); // 0x00643B00
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x23_6FC3DC60(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char a4, unsigned short a5, int a6); // 0x0053C590
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
        return &sgptDataTables->pStatesTxt[nState];
    return 0;
}

// 0x0056E970
D2StatListStrc* __fastcall sub_0056E970(D2CurseStrc* pCurse)
{
    D2UnitStrc* pTarget = pCurse->pTarget;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pTarget);
    const int nState = pCurse->nState;
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
    if (!pStatesTxtRecord)
        return 0;
    if (pTarget && pTarget->dwUnitType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pTarget->dwClassId >= 0 && pTarget->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pTarget->dwClassId];
        }
        if (!pMonStatsTxtRecord || (pMonStatsTxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[0]))
            return 0;
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (!pMonStats2TxtRecord || !(pMonStats2TxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[1]))
            return 0;
    }
    const int bCurse = STATES_CheckStateMaskCurseByStateId(nState);
    if (bCurse)
    {
        const int nResistance = STATLIST_UnitGetStatValue(pTarget, 109, 0);
        if (nResistance >= 100)
            return 0;
        if (nResistance)
        {
            const int nDuration = pCurse->nDuration;
            pCurse->nDuration = nDuration - DATATBLS_ApplyRatio(nDuration, nResistance, 100);
        }
        if (STATES_CheckState(pTarget, 57))
            return 0;
    }
    unsigned int nFlags = 0;
    D2StatListStrc* pStatList;
    if (bCurse)
    {
        nFlags = 0x20;
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20);
    }
    else
        pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, nState);
    if (pStatList)
    {
        if (STATLIST_GetState(pStatList) == pCurse->nState && pCurse->nSkill == (int)sub_006260E0(pStatList))
        {
            const int nSkillLevel = STATLIST_GetSkillLevel(pStatList);
            if (pCurse->nSkillLevel == nSkillLevel)
            {
                if (pCurse->nDuration)
                {
                    const int nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
                    STATLIST_SetExpireFrame(pStatList, nExpireFrame);
                    EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
                }
                return pStatList;
            }
            if (pCurse->nSkillLevel < nSkillLevel)
                return 0;
        }
        D2Common_10474(pTarget, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    UNITROOM_RefreshUnit(pTarget);
    STATES_ToggleState(pTarget, nState, 1);
    int nExpireFrame = 0;
    if (pCurse->nDuration)
    {
        nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
        nFlags |= 2;
        EVENT_SetEvent(pGame, pCurse->pTarget, 12, nExpireFrame, 0, 0);
    }
    if (STATES_CheckStateMaskExpByStateId(nState))
        nFlags |= 0x800;
    if (pStatesTxtRecord->nFlags[0] & (unsigned char)gdwBitMasks[1])
        nFlags |= 8;
    pStatList = STATLIST_AllocStatList(!pTarget ? 0 : pTarget->pMemoryPool, nFlags, nExpireFrame, !pCurse->pUnit ? 6 : pCurse->pUnit->dwUnitType, !pCurse->pUnit ? -1 : pCurse->pUnit->dwUnitId);
    STATLIST_SetState(pStatList, nState);
    STATLIST_SetSkillId(pStatList, pCurse->nSkill);
    STATLIST_SetSkillLevel(pStatList, pCurse->nSkillLevel);
    if (pCurse->nStat != -1)
        STATLIST_SetStat(pStatList, pCurse->nStat, pCurse->nStatValue, 0);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    if (!pCurse->pStateRemoveCallback)
    {
        STATLIST_SetStatRemoveCallback(pStatList, sub_6FD10E50);
        return pStatList;
    }
    STATLIST_SetStatRemoveCallback(pStatList, pCurse->pStateRemoveCallback);
    return pStatList;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x0056EBE0
void __fastcall sub_0056EBE0_DoSkillArea(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nStatId, int nState, StatListRemoveCallback pfRemoveStatCallback)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    D2CurseStrc tCurse = {};
    tCurse.pUnit = pUnit;
    tCurse.nDuration = pSkillsTxtRecord->dwParamPerLevel1 * nSkillLevel;
    tCurse.nSkillLevel = nSkillLevel;
    tCurse.pTarget = pTarget;
    tCurse.nStatValue = (nSkillLevel - 1) * pSkillsTxtRecord->dwParamPerLevel2 + pSkillsTxtRecord->dwParamBase;
    tCurse.nSkill = nSkillId;
    tCurse.nStat = nStatId;
    tCurse.nState = nState;
    tCurse.pStateRemoveCallback = pfRemoveStatCallback;
    D2_ASSERT(!pfRemoveStatCallback || !IsBadCodePtr((void*)pfRemoveStatCallback), 0x52B);
    sub_0056E970(&tCurse);
}

static void __stdcall sub_0056FF10_StartAssignedAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
        {
            D2SkillStrc* pHighestLevelSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
            if (pHighestLevelSkill)
            {
                const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pHighestLevelSkill, 1);
                if (nSkillLevel > 0)
                {
                    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_IMMEDIATE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_IMMEDIATE & 7])
                    {
                        sub_0056F7F0(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
                    }
                    else
                    {
                        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);

                        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
                        if (!pStatList)
                        {
                            pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
                        }

                        if (pStatList)
                        {
                            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
                            STATLIST_SetSkillId(pStatList, nSkillId);
                            STATLIST_SetSkillLevel(pStatList, nSkillLevel);
                            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
                        }
                    }

                    sub_6FD13260(pGame, pUnit, nSkillId, nSkillLevel, 1);
                }
            }
        }
    }
}

// 0x005701B0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags)
{
    if (nSkillId == SKILL_LEFTHANDSWING)
    {
        return;
    }

    if (!a2 && STATES_CheckState(pUnit, STATE_NOMANAREGEN))
    {
        STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
    }

    D2SkillStrc* pSkill = sub_006439B0_SkillFindByOwner(pUnit, nSkillId, nFlags);
    if (!pSkill)
    {
        return;
    }

    D2SkillStrc* pRightSkill = 0;
    if (a2)
    {
        SKILLS_SetLeftActiveSkill(pUnit, nSkillId, nFlags);
    }
    else
    {
        pRightSkill = UNITS_GetRightSkill(pUnit);
        SKILLS_SetRightActiveSkill(pUnit, nSkillId, nFlags);
    }

    nFlags = -1;
    SKILLS_GetSkillInfo(pSkill, &nFlags, 0, 0, 0);
    if ((!pUnit ? UNIT_INVALID : pUnit->dwUnitType) == UNIT_PLAYER)
    {
        D2GAME_PACKETS_SendPacket0x23_6FC3DC60(UnitGetClient(pUnit, &gszSkillsSourceFile, 3499), (!pUnit ? UNIT_INVALID : pUnit->dwUnitType), !pUnit ? -1 : pUnit->dwUnitId, a2, nSkillId, nFlags);
    }

    if (!a2)
    {
        if (pRightSkill)
        {
            D2SkillsTxt* pRightSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, &gszSkillsSourceFile, 3507));
            if (pRightSkillsTxtRecord && pRightSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
            {
                if (pRightSkillsTxtRecord->nAuraState >= 0 || pRightSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pRightSkillsTxtRecord->nAuraState);
                    if (pStatList)
                    {
                        D2Common_10474(pUnit, pStatList);
                        STATLIST_FreeStatList(pStatList);
                    }

                    STATES_ToggleState(pUnit, pRightSkillsTxtRecord->nAuraState, 0);
                }

                D2GAME_EVENTS_Delete_6FC34840(SUNIT_GetGameFromUnit(pUnit), pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            }
        }

        if (SKILLS_GetSkillsTxtRecord(nSkillId)->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        {
            sub_0056FF10_StartAssignedAura(SUNIT_GetGameFromUnit(pUnit), pUnit, nSkillId);
        }
    }
}
