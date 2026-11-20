#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"

struct D2SkillListStrc;



struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    char unk0x04[0x10];
    int dwAiParam[3];
};

struct D2MonStatsTxt
{
    char unk0x00[0x56];
    short wAiParam[8][3];
    char unk0x86[0x1A];
    unsigned char nDrain[3];
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl;
    unsigned int unk0x04;
    D2UnitStrc* pTarget;
    unsigned int unk0x0C[2];
    int nTargetDistance;
    int bCombat;
    D2MonStatsTxt* pMonstatsTxt;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x22];
    short wSrvDoFunc;
    char unk0x030[0x16];
    short wSrvMissile;
    short wSrvMissileA;
    char unk0x04A[0x0A];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    short wAuraTargetState;
    char unk0x084[0xF0];
    short wReqLevel;
    char unk0x176[0x66];
    unsigned char nEType;
    char unk0x1DD[0x53];
    unsigned char nAiType;
    char unk0x231;
    short wAiBonus;
    char unk0x234[0x08];
};

struct D2MissilesTxt
{
    char unk0x00[0x96];
    short wRange;
};

struct D2DataTablesStrc
{
    char unk0x000[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

struct D2ShadowMasterAiCallbackArgStrc
{
    D2UnitStrc* unk0x00;
    D2UnitStrc* unk0x04;
    int unk0x08;
    int unk0x0C;
    D2UnitStrc* unk0x10;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    D2UnitStrc* unk0x24;
};

struct D2ShadowMasterSkillStrc
{
    D2UnitStrc* pTarget;
    int nSkillId;
    int nChance;
    int nX;
    int nY;
};

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268
extern "C" const char szAiThink4File[];                                                                     // 0x006E3500

int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId);                                    // 0x0046ACE0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nSkillId); // 0x00540E60
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00553540
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0
int __fastcall sub_6FCBD900(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                     // 0x00554200
D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit);                           // 0x0055B7E0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                         // 0x005B0BD0
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED00
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);   // 0x005DED20
int __fastcall sub_6FCD06D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DF140
int __fastcall sub_6FCE34E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0
int __fastcall AITHINK_IsTargetKillableByShadowMaster(D2UnitStrc* pUnit, D2UnitStrc* pTarget);             // 0x005EB650
D2UnitStrc* __fastcall AITHINK_TargetCallback_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EB6D0
int __fastcall sub_005EB7F0_IsStateGroupActive(D2UnitStrc* pUnit, int nState);                              // 0x005EB7F0
int __fastcall sub_005EB8B0_ShadowMasterUseSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int bCombat, D2UnitStrc* pTarget, int nX, int nY, D2AiTickParamStrc* pAiTickParam); // 0x005EB8B0
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                           // 0x00621F20
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_CheckStateMaskPgsvOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A2B0
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643910
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill);                                                     // 0x00644360
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460

enum D2C_ShadowMasterConstants
{
    EVENTTYPE_AITHINK = 2,
    COLLIDE_MISSILE_BARRIER = 4,
    SKILLSFLAGINDEX_AURA = 2,

    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_FREEZE = 12,

    STAT_DAMAGERESIST = 36,
    STAT_MAGICRESIST = 37,
    STAT_FIRERESIST = 39,
    STAT_LIGHTRESIST = 41,
    STAT_COLDRESIST = 43,
    STAT_POISONRESIST = 45,
};

// 0x0045C370
static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0)
    {
        return 0;
    }

    return DATATBLS_GetMissilesTxtRecord(nMissileId);
}

static __forceinline D2StatListStrc* GetAuraStateStatList(D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord)
{
    if (pSkillsTxtRecord->nAuraState > 0 && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    }

    return 0;
}

static __forceinline int AI_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return SKILLS_GetSkillLevel(pUnit, pSkill, 1);
}

static __forceinline int AI_ClampChance(int nChance)
{
    if (nChance > 5 && nChance < 100)
    {
        return nChance;
    }

    if (nChance <= 5)
    {
        return 5;
    }

    return 100;
}

// 0x005EB970
void __fastcall AITHINK_Fn106_143_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int bCombat = pAiTickParam->bCombat;
    int nTargetDistance = pAiTickParam->nTargetDistance;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SkillListStrc* pSkillList = pUnit->pSkills;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!pSkillList)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 100);
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    if (pOwner)
    {
        const int nOwnerDistance = AITHINK_GetSquaredDistance(pUnit, pOwner);
        if (nOwnerDistance > pMonStatsTxt->wAiParam[1][2] * pMonStatsTxt->wAiParam[1][2]
            && sub_6FCE34E0(pGame, pUnit, 0, pOwner, bCombat, pAiTickParam, 0, 6))
        {
            return;
        }
    }

    if (pAiControl->dwAiParam[0] > 0)
    {
        D2UnitStrc* pCurrentTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pCurrentTarget)
        {
            pTarget = pCurrentTarget;
        }

        if (!pTarget)
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
        }
        else
        {
            --pAiControl->dwAiParam[0];
            if (sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, pAiControl->dwAiParam[1], bCombat, pTarget, 0, 0, pAiTickParam))
            {
                return;
            }
        }
    }

    if (nTargetDistance > pMonStatsTxt->wAiParam[1][1])
    {
        pTarget = 0;
    }

    if (!pTarget)
    {
        for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pSkillList); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szAiThink4File, 3443);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                switch (pSkillsTxtRecord->nAiType)
                {
                case 1:
                    if (pSkillsTxtRecord->nAiType == 1 && pSkillsTxtRecord->nAuraState > 0 && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (!sub_005EB7F0_IsStateGroupActive(pUnit, pSkillsTxtRecord->nAuraState) || (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 4)
                        {
                            if ((int)(SEED_RollRandomNumber(&pUnit->pSeed) % 100) < 60)
                            {
                                D2SkillStrc* pUseSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                                if (pUseSkill)
                                {
                                    int nResult;
                                    if (D2Common_11016(pUnit, pUseSkill) == 1)
                                    {
                                        if (!bCombat)
                                        {
                                            nResult = AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, 0, 4);
                                        }
                                        else
                                        {
                                            nResult = AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pUseSkill), nSkillId, 0, 0, 0);
                                        }
                                    }
                                    else
                                    {
                                        nResult = AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pUseSkill), nSkillId, 0, 0, 0);
                                    }

                                    if (nResult)
                                    {
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    break;

                case 6:
                    if (!UNITS_GetLeftSkill(pUnit) && (int)(SEED_RollRandomNumber(&pUnit->pSeed) % 100) < 20)
                    {
                        SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                    }
                    break;
                }
            }
        }
    }

    D2UnitStrc* pOwnerTarget = 0;
    if (pOwner)
    {
        pOwnerTarget = SUNIT_GetTargetUnit(pGame, pOwner);
        if (pOwnerTarget)
        {
            if (!SUNIT_IsDead(pOwnerTarget) && sub_6FCBD900(pGame, pUnit, pOwnerTarget))
            {
                pTarget = pOwnerTarget;
            }
            else
            {
                pOwnerTarget = 0;
            }
        }

        if (AITHINK_GetSquaredDistance(pUnit, pOwner) <= 144 && sub_6FCE34E0(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
        {
            return;
        }
    }

    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int nParam = pAiTickParam->pAiControl->dwAiParam[2];
    if (nParam <= 1)
    {
        nParam = 1;
    }

    int nChance = pMonStatsTxt->wAiParam[2][pGame->nDifficulty] - 2 * nParam;
    nChance = AI_ClampChance(nChance);

    if (!bCombat || (int)SEED_RollLimitedRandomNumber(pSeed, 100) >= nChance
        || !sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, 0, bCombat, pTarget, 0, 0, pAiTickParam))
    {

        D2ShadowMasterAiCallbackArgStrc arg = {};
        arg.unk0x00 = pOwner;
        arg.unk0x08 = 0x7FFFFFFF;
        arg.unk0x14 = 0x7FFFFFFF;
        sub_6FCF1E80(pGame, pUnit, &arg, AITHINK_TargetCallback_ShadowMaster, 1);

        if (!bCombat)
        {
            if (pOwnerTarget)
            {
                pTarget = pOwnerTarget;
            }
            else if (arg.unk0x10)
            {
                pTarget = arg.unk0x10;
            }
            else if (arg.unk0x24)
            {
                D2UnitStrc* pArg24 = arg.unk0x24;
                if (AITHINK_GetSquaredDistance(pUnit, pArg24) < 1024)
                {
                    pTarget = pArg24;
                }
            }

            if (!AITHINK_IsTargetKillableByShadowMaster(pUnit, pTarget))
            {
                D2UnitStrc* pTargetOwner = AIGENERAL_GetMinionOwner(pTarget);
                if (pTargetOwner && !SUNIT_IsDead(pTargetOwner) && AITHINK_GetSquaredDistance(pUnit, pTargetOwner) < 1024)
                {
                    pTarget = pTargetOwner;
                }
            }
        }

        const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
        const int nDistanceToTarget = AITHINK_GetSquaredDistance(pUnit, pTarget);

        int bProgressiveState;
        if (pMonStatsTxt->wAiParam[0][2] > 0 && STATES_CheckStateMaskPgsvOnUnit(pUnit))
        {
            bProgressiveState = 1;
        }
        else
        {
            bProgressiveState = 0;
        }

        const int bNotColliding = UNITS_TestCollisionWithUnit(pUnit, pTarget, COLLIDE_MISSILE_BARRIER) == 0;

        D2UnitStrc* pArg10 = arg.unk0x10;
        const int nArg20 = arg.unk0x20;
        const int nArg1C = arg.unk0x1C;

        const int nArg0C = *(volatile int*)&arg.unk0x0C;
        const int nArg08 = arg.unk0x08;
        const int nArg18 = arg.unk0x18;

        if (nArg0C > 3)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 32) < 2 * nArg0C)
            {
                if (pOwner && AITHINK_GetSquaredDistance(pUnit, pOwner) > 36)
                {
                    AITACTICS_RunToTargetUnit(pGame, pUnit, pOwner);
                    return;
                }

                if (sub_6FCD06D0(pGame, pUnit, pTarget, 8, 1))
                {
                    return;
                }
            }
        }

        int nAuraStatBonus = 0;

        D2ShadowMasterSkillStrc shadowMasterSkills[48];
        shadowMasterSkills[0].nSkillId = 0;
        shadowMasterSkills[0].nChance = 0;
        shadowMasterSkills[0].pTarget = pTarget;
        shadowMasterSkills[0].nX = 0;
        shadowMasterSkills[0].nY = 0;

        int nCounter = 1;
        const int nRandomPick = pMonStatsTxt->wAiParam[1][0];

        for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pSkillList); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szAiThink4File, 3645);
            int nResistance = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                D2UnitStrc* pSkillTarget = pTarget;
                int nCurrentValue = 0;
                int nTemp = pSkillsTxtRecord->wAiBonus;
                nTemp += pSkillsTxtRecord->wReqLevel / 4 + nResistance;
                nResistance = 0;

                switch (pSkillsTxtRecord->nEType)
                {
                case ELEMTYPE_NONE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_DAMAGERESIST, 0);
                    break;

                case ELEMTYPE_FIRE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_FIRERESIST, 0);
                    break;

                case ELEMTYPE_LTNG:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTRESIST, 0);
                    break;

                case ELEMTYPE_COLD:
                case ELEMTYPE_FREEZE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_COLDRESIST, 0);
                    break;

                case ELEMTYPE_POIS:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_POISONRESIST, 0);
                    break;

                case ELEMTYPE_MAGIC:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICRESIST, 0);
                    break;
                }

                nTemp += nResistance / -10;

                switch (pSkillsTxtRecord->nAiType)
                {
                case 1:
                    if (pSkillsTxtRecord->nAuraState <= 0 || STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (nArg08 <= 25)
                        {
                            nTemp -= 6;
                        }

                        if (sub_005EB7F0_IsStateGroupActive(pUnit, pSkillsTxtRecord->nAuraState))
                        {
                            nTemp -= 10;
                        }
                        else
                        {
                            nTemp += 10;
                        }

                        nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                        pSkillTarget = pUnit;
                    }
                    break;

                case 2:
                    if (pSkillsTxtRecord->nAuraState <= 0 || !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (pSkillsTxtRecord->wAuraTargetState <= 0 || !STATES_CheckState(pTarget, pSkillsTxtRecord->wAuraTargetState))
                        {
                            if (nArg08 <= 25)
                            {
                                nTemp -= 10;
                            }

                            nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                        }
                    }
                    break;

                case 3:
                    if (nArg20 > 5)
                    {
                        nTemp += -2 * nArg20;
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 7;
                    }

                    if (nArg1C < 3)
                    {
                        nTemp -= 10;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick) + 3 * (nArg1C - 3);
                    break;

                case 4:
                    if (nDistanceToTarget > pMonStatsTxt->wAiParam[0][0] * pMonStatsTxt->wAiParam[0][0])
                    {
                        nTemp -= 10;
                    }

                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (bCombat || nDistanceToTarget <= 25)
                    {
                        nTemp += 10;
                    }

                    if (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_AURA])
                    {
                        if (D2StatListStrc* pStatList = GetAuraStateStatList(pUnit, pSkillsTxtRecord))
                        {
                            const int nAuraStatValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                            nAuraStatBonus += nAuraStatValue;
                            if (nAuraStatValue >= 3)
                            {
                                break;
                            }
                        }

                        nTemp += pMonStatsTxt->wAiParam[0][2];
                    }
                    else if (pMonStatsTxt->wAiParam[0][2] > 0 && !bProgressiveState)
                    {
                        nTemp -= 10;
                    }
                    else
                    {
                        nTemp += 4 * nAuraStatBonus + 3;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;

                case 5:
                    if (!bNotColliding)
                    {
                        break;
                    }

                    if (pSkillsTxtRecord->wSrvMissile < 0)
                    {
                        if (D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pSkillsTxtRecord->wSrvMissileA))
                        {
                            if (nDistanceToTarget >= (pMissilesTxtRecord->wRange - 1) * (pMissilesTxtRecord->wRange - 1))
                            {
                                break;
                            }
                        }
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (nDistanceToTarget <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (bProgressiveState)
                    {
                        nTemp -= 5;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;

                case 6:
                    if (!UNITS_GetLeftSkill(pUnit))
                    {
                        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 20)
                        {
                            SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                        }
                    }
                    else
                    {
                        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 6)
                        {
                            SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                        }
                    }
                    break;

                case 7:
                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage > 66)
                    {
                        nCurrentValue = 0;
                        break;
                    }

                    pSkillTarget = 0;
                    if (!pOwner)
                    {
                        SEED_RollLimitedRandomNumber(pSeed, 40);
                        CLIENTS_GetUnitX(pUnit);
                        SEED_RollLimitedRandomNumber(pSeed, 40);
                        CLIENTS_GetUnitX(pUnit);
                    }
                    else
                    {
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitX(pTarget);
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitX(pTarget);
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitY(pOwner);
                    }

                    nCurrentValue += 10;
                    if (nLifePercentage < 45)
                    {
                        nCurrentValue += 10;
                    }
                    break;

                case 8:
                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage > 66)
                    {
                        nCurrentValue = 0;
                        break;
                    }

                    pSkillTarget = pUnit;
                    nCurrentValue *= 2;
                    if (nLifePercentage < 45)
                    {
                        nCurrentValue *= 2;
                    }
                    break;

                case 11:
                    if (!bNotColliding)
                    {
                        break;
                    }

                    if (pSkillsTxtRecord->wSrvMissile < 0)
                    {
                        if (D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pSkillsTxtRecord->wSrvMissileA))
                        {
                            if (nDistanceToTarget >= (pMissilesTxtRecord->wRange - 1) * (pMissilesTxtRecord->wRange - 1))
                            {
                                break;
                            }
                        }
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (nDistanceToTarget <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (bProgressiveState)
                    {
                        nTemp -= 5;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick) + 3 * nArg1C;
                    break;

                case 12:
                    if (sub_0044BE50_GetUnitTypeOrInvalid(pTarget) == UNIT_MONSTER)
                    {
                        D2MonStatsTxt* pTargetMonStatsTxt = sub_0055B7E0_GetMonStatsTxtFromUnit(pTarget);
                        if (!pTargetMonStatsTxt || pTargetMonStatsTxt->nDrain[pGame->nDifficulty] < 25)
                        {
                            break;
                        }
                    }

                    if (nDistanceToTarget > pMonStatsTxt->wAiParam[0][0] * pMonStatsTxt->wAiParam[0][0])
                    {
                        nTemp -= 10;
                    }

                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (bCombat || nDistanceToTarget <= 25)
                    {
                        nTemp += 10;
                    }

                    if (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_AURA])
                    {
                        if (D2StatListStrc* pStatList = GetAuraStateStatList(pUnit, pSkillsTxtRecord))
                        {
                            const int nAuraStatValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                            nAuraStatBonus += nAuraStatValue;
                            if (nAuraStatValue >= 3)
                            {
                                break;
                            }
                        }
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage < 75)
                    {
                        nCurrentValue += 8;
                    }

                    if (nLifePercentage < 50)
                    {
                        nCurrentValue += 12;
                    }
                    break;

                case 13:
                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (pMonStatsTxt->wAiParam[0][2] > 0 && !bProgressiveState)
                    {
                        nTemp -= 5;
                    }
                    else
                    {
                        nTemp += nAuraStatBonus;
                    }

                    if ((nLifePercentage < 50 || nArg0C > 3) && pArg10 && nArg18 < 4 && AITHINK_GetSquaredDistance(pUnit, pArg10) > 25)
                    {
                        nTemp += 20;
                        pSkillTarget = pArg10;
                    }
                    else
                    {
                        if (nDistanceToTarget < 25)
                        {
                            break;
                        }

                        if (nDistanceToTarget > 324)
                        {
                            nTemp += 10;
                        }
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;
                }

                if (nCurrentValue > shadowMasterSkills[nCounter - 1].nChance)
                {
                    shadowMasterSkills[nCounter].nSkillId = nSkillId;
                    shadowMasterSkills[nCounter].pTarget = pSkillTarget;
                    shadowMasterSkills[nCounter].nChance = nCurrentValue;
                    shadowMasterSkills[nCounter].nX = 0;
                    shadowMasterSkills[nCounter].nY = 0;
                    ++nCounter;
                }
            }
        }

        while (nCounter)
        {
            --nCounter;

            if (SEED_RollRandomNumber(&pUnit->pSeed) & 3)
            {
                D2UnitStrc* pPickTarget = shadowMasterSkills[nCounter].pTarget;
                const int nPickSkillId = shadowMasterSkills[nCounter].nSkillId;
                const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pPickTarget, 0);
                if (sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, nPickSkillId, bInMeleeRange, pPickTarget, shadowMasterSkills[nCounter].nX, shadowMasterSkills[nCounter].nY, pAiTickParam))
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nPickSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->wSrvDoFunc == 19)
                    {
                        pAiControl->dwAiParam[1] = nPickSkillId;
                        pAiControl->dwAiParam[0] = 25;
                    }
                    return;
                }
            }
        }

        if (pTarget)
        {
            const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
            if (sub_005EB8B0_ShadowMasterUseSkill(pGame, pOwner, pUnit, 0, bInMeleeRange, pTarget, 0, 0, pAiTickParam))
            {
                return;
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}

// build: context ?SKILLS_GetSkillsTxtRecord@@YAPAUD2SkillsTxt@@H@Z
// build: context ?SKILLS_GetMissilesTxtRecord@@YAPAUD2MissilesTxt@@H@Z
// build: context ?GetAuraStateStatList@@YAPAUD2StatListStrc@@PAUD2UnitStrc@@PAUD2SkillsTxt@@@Z
// build: context ?AI_ClampChance@@YAHH@Z
