struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    int unk0x08;
    int dwUnitId;
    int unk0x10[4];
    D2SeedStrc tSeed;
    int unk0x28;
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0xE8 - 0x30];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2MissilesTxt
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned int dwMissileFlags;
    unsigned short wCltDoFunc;
    unsigned short wCltHitFunc;
    unsigned short wSrvDoFunc;
    unsigned short wSrvHitFunc;
    unsigned short wSrvDmgFunc;
    unsigned short wTravelSound;
    unsigned short wHitSound;
    unsigned short wExplosionMissile;
    short wSubMissile[3];
    short wCltSubMissile[3];
    short wHitSubMissile[4];
    short wCltHitSubMissile[4];
    short wProgSound;
    unsigned short wProgOverlay;
    int dwParam[5];
    int dwHitPar[3];
    int dwCltParam[5];
    int dwCltHitPar[3];
    char unk0x78[0x96 - 0x78];
    short wRange;
    char unk0x98[0x1A4 - 0x98];
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
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDB40
D2UnitStrc* __fastcall sub_004CE320(D2UnitStrc* pMissile, int nArg1, int nArg2, int nMissile);              // 0x004CE320
void __fastcall sub_004CE4B0_InitMotion(D2UnitStrc* pMissile);                                              // 0x004CE4B0
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D4BB0
void __fastcall sub_004D4BB0_CltDoObjectSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }

    int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    const int nParam = pMissilesTxtRecord->dwCltParam[0];
    const int nEnd = nParam + 0x7D;
    if (nFrames < pMissilesTxtRecord->wRange - nParam && nFrames > nParam && pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        D2UnitStrc* pNew = sub_004CE320(pMissile, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->wCltSubMissile[0]);
        if (pNew)
        {
            sub_004CE4B0_InitMotion(pNew);
        }
    }

    if (nFrames < nEnd && nFrames > nParam)
    {
        D2UnitStrc* pUnit = UNITS_GetRoom(pMissile)->pUnitFirst;
        do
        {
            if (!pUnit)
                break;
            if (pUnit->dwUnitType == 2 && pUnit->dwClassId >= 0x11 && pUnit->dwClassId < 0x16)
            {
                if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
                {
                    const int nLevel = MISSILE_GetLevel(pMissile);
                    D2UnitStrc* pNew = (D2UnitStrc*)sub_004CDB40_SubmitRequest(pOwner, pMissilesTxtRecord->wCltSubMissile[0], UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), MISSILE_GetSkill(pMissile), nLevel);
                    if (pNew)
                    {
                        sub_004CE4B0_InitMotion(pNew);
                    }
                }

                if (pMissilesTxtRecord->wCltSubMissile[1] > 0 && !(nFrames % 8))
                {
                    int nTargetId = MISSILE_GetTargetX(pMissile);
                    D2UnitStrc* pTarget = nTargetId ? sub_00463990(nTargetId, 2) : 0;
                    if (!pTarget)
                    {
                        MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                    }
                    else
                    {
                        D2MissileStrc tMissile;
                        memset(&tMissile, 0, sizeof(tMissile));
                        tMissile.dwFlags = 0x421;
                        tMissile.pOwner = pOwner;
                        tMissile.nX = UNITS_GetXPosition(pUnit);
                        tMissile.nY = CLIENTS_GetUnitY(pUnit);
                        tMissile.nSkill = MISSILE_GetSkill(pMissile);
                        tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);
                        tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                        tMissile.nTargetX = UNITS_GetXPosition(pTarget);
                        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
                        sub_004CD540_CreateMissile(&tMissile);
                        if (!SEED_RollLimitedRandomNumber(&pTarget->tSeed, 4))
                        {
                            MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                        }
                    }
                }
            }
            pUnit = pUnit->pRoomNext;
        } while (pUnit);
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
