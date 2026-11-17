#include "D2Game.h"

enum D2C_J07SkillsConstants
{
    UNIT_MONSTER = 1,
    UNIT_INVALID = 6,
    MONMODE_SEQUENCE = 14,
    UNITFLAG_SKSRVDOFUNC = 0x40,
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x3C];
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    char unk0x4C[0x78];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x00[0x11];
    unsigned char nMonAnim;
    char unk0x12[0x36];
    short wSrvMissileA;
    char unk0x4A[0xEE];
    unsigned int dwCalc[1];
    char unk0x13C[0x100];
};

struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short wMonStatsEx;
    char unk0x1A[0x18E];
};

struct D2MonStats2Txt
{
    char unk0x00[0x109];
    unsigned char nInfernoAnim;
    char unk0x10A[0x2A];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x0C];
    D2MonStats2Txt* pMonStats2Txt;
    void* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
    char unk0xA9C[0xD0];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc*, int);

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
    MissileInitFunc pInitFunc;
    int pInitArgs;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30
void __fastcall SKILLS_MissileInit_DiabWall(D2UnitStrc* pMissile, int nInitSeed);                           // 0x005CD110

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005CC440
void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            if (pSkillsTxtRecord->nMonAnim == MONMODE_SEQUENCE)
            {
                UNITS_SetAnimationFrame(pUnit, pMonStats2TxtRecord->nInfernoAnim - 1);
                pUnit->dwFrameCountPrecise = (pMonStats2TxtRecord->nInfernoAnim + 1) << 8;
            }
            else
            {
                pUnit->nSeqCurrentFramePrecise = pMonStats2TxtRecord->nInfernoAnim << 8;
            }
        }
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, 8);
        pUnit->dwFrameCountPrecise = 0x500;
    }
}

// 0x005CD1C0
int __fastcall SKILLS_SrvDo102_DiabWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nSubMissiles = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = UNITS_GetXPosition(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nMissile = nMissileId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.pInitFunc = SKILLS_MissileInit_DiabWall;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.pInitArgs = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}
