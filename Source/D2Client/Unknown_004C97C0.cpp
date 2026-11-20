#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"



struct D2SkillsTxt
{
    char unk0x000[0x64];
    unsigned int dwParamCalc;
    char unk0x068[0x23C - 0x68];
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

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                 // 0x00681EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390
int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId);                              // 0x004F21B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, int nDirection);                          // 0x006488A0

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C97C0
int __fastcall sub_004C97C0_SpawnScatterMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = sub_004F21B0_GetCltMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nRadius = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwParamCalc, nSkillId, nSkillLevel);
    if (nRadius <= 0)
    {
        return 0;
    }

    const int nSpacing = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwParamCalc, nSkillId, 1);
    if (nSpacing <= 0)
    {
        return 0;
    }

    const int nRadiusSq = nRadius * nRadius;
    const int nRange = 2 * nRadius + 1;
    const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 18);
    const int nCount = nRadiusSq / (nSpacing * nSpacing) / (nRoll + 1);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x2001;
    tParams.pOwner = pUnit;
    tParams.nMissile = nMissileId;
    tParams.nSkill = nSkillId;
    tParams.nSkillLevel = nSkillLevel;

    for (int i = 0; i < nCount; ++i)
    {
        const int nOffsetX = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRadius;
        const int nOffsetY = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRadius;
        if (nOffsetY * nOffsetY + nOffsetX * nOffsetX < nRadiusSq)
        {
            tParams.nX = nOffsetX + nX + 2;
            tParams.nY = nOffsetY + nY + 2;
            D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tParams);
            if (pMissile)
            {
                PATH_SetDirection(pMissile->pDynamicPath, SEED_RollLimitedRandomNumber(&pUnit->pSeed, 0x40));
            }
        }
    }

    return 1;
}
