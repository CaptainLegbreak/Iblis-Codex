struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2MissilesTxt
{
    char unk0x000[0x2C];
    short wCltHitSubMissile[4];
    short wProgSound;
    short wProgOverlay;
    int dwParam[5];
    int dwHitPar[3];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0x12C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
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
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __fastcall sub_00464EC0_CheckSkillOwner(D2UnitStrc* unit, D2UnitStrc* target);                          // 0x00464EC0
int __fastcall sub_00464F70_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                        // 0x00464F70
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster);                                                       // 0x0063E940
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster);                                                      // 0x0063E990
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x004CF3C0
int __fastcall sub_004CF3C0_CltHitUnit(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pMissilesTxtRecord->dwCltHitPar[0] && pOwner && (sub_00464EC0_CheckSkillOwner(pOwner, pUnit) || sub_00464F70_IsTargetBlocked(pOwner, pUnit)))
    {
        if (pMissilesTxtRecord->wProgOverlay > 0)
        {
            sub_00470390(pUnit, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
            return 1;
        }

        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case 0:
        if (pMissilesTxtRecord->dwCltHitPar[1])
        {
            return 0;
        }
        break;

    case 1:
        switch (pMissilesTxtRecord->dwCltHitPar[1])
        {
        case 2:
            if (!MONSTERS_IsDemon(pUnit))
            {
                return 0;
            }
            break;

        default:
            if (!MONSTERS_IsUndead(pUnit))
            {
                return 0;
            }
            break;
        }
        break;

    default:
        return 0;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2MissileStrc tMissile;
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.pOwner = pOwner;
        tMissile.pOrigin = pMissile;
        tMissile.nSkill = MISSILE_GetSkill(pMissile);
        tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);
        tMissile.nMissile = 0xCC;
        sub_004CD540_CreateMissile(&tMissile);
    }

    return 1;
}
