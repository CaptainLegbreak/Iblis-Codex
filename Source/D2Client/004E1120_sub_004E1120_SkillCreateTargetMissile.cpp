struct D2DynamicPathStrc;

struct D2UnitStrc
{
    char unk0x00[0x2C];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x94];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0xEA];
    short wCltMissile;
    char unk0x0EC[0x23C - 0xEC];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB6C];
    int nMissilesTxtRecordCount;
    char unk0xB70[0xB98 - 0xB70];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

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
extern const unsigned char gaDirection64To4_006DBA60[64];                                                  // 0x006DBA60
extern const unsigned char gaDirection4_006DBA58[4];                                                       // 0x006DBA58
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection);                         // 0x006488A0

// build: context CLT_Abs
static int CLT_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

#define SKILLS_GetSkillsTxtRecord_E1120(nSkillId) \
    ((nSkillId) >= 0 && (nSkillId) < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0)

// 0x004E1120
int __fastcall sub_004E1120_SkillCreateTargetMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord_E1120(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissile;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nEndX = nTargetX;
    int nEndY = nTargetY;
    int nSteps = 4;
    if (CLT_Abs(nTargetX - nX) < CLT_Abs(nTargetY - nY))
    {
        nEndX = nX;
        do
        {
            if (nEndX > nTargetX)
            {
                --nEndX;
            }
            else if (nEndX < nTargetX)
            {
                ++nEndX;
            }
        }
        while (--nSteps > 0);
    }
    else
    {
        nEndY = nY;
        do
        {
            if (nEndY > nTargetY)
            {
                --nEndY;
            }
            else if (nEndY < nTargetY)
            {
                ++nEndY;
            }
        }
        while (--nSteps > 0);
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    tMissile.pOwner = pUnit;
    tMissile.nTargetX = nEndX - nX;
    tMissile.nTargetY = nEndY - nY;
    tMissile.nX = nX + tMissile.nTargetX / 6 - 1;
    tMissile.nY = nY + tMissile.nTargetY / 6 - 1;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    sub_006488A0_SetDirection(pUnit->pDynamicPath, gaDirection4_006DBA58[gaDirection64To4_006DBA60[UNITS_GetDirectionToCoords(pUnit, nEndX, nEndY) & 0x3F] & 3]);
    sub_004CD540_CreateMissile(&tMissile);
    return 1;
}

#include "gen/data/Source/D2Client/004E1120_sub_004E1120_SkillCreateTargetMissile.inc"
