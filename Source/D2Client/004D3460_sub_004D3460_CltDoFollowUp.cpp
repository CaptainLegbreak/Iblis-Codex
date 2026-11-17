struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[6];
    D2SeedStrc tSeed;
    int unk0x28;
    D2DynamicPathStrc* pDynamicPath;
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
    char unk0x78[0x08];
    unsigned int dwSrvCalc;
    unsigned int dwCltCalc;
    char unk0x88[0x11C];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
};

typedef char cc_M338_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];
typedef char cc_M338_D2UnitStrc_path[sizeof(D2UnitStrc) == 0x30 ? 1 : -1];

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
void __fastcall sub_004CE050_SpawnFollowUp(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);             // 0x004CE050
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile);                                             // 0x0064A210
int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath);                                         // 0x006505C0

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D3460
void __fastcall sub_004D3460_CltDoFollowUp(D2UnitStrc* pMissile)
{
    if (sub_006505C0_TestPathFlag8(pMissile->pDynamicPath))
    {
        const int nMissileId = pMissile->dwClassId;
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
        {
            sub_004CE050_SpawnFollowUp(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, MISSILE_EvaluateMissileFormula(pMissile, sub_004639D0_GetOwnerUnit(pMissile), pMissilesTxtRecord->dwCltCalc, nMissileId, sub_0064A210(pMissile)));
        }
    }

    sub_004D30C0_CltDoCommon(pMissile);
}
