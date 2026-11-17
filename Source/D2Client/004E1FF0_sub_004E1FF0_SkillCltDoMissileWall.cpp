struct D2DynamicPathStrc;
struct D2StaticPathStrc;
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2InventoryStrc;
struct D2GfxLightStrc;
struct D2StatListStrc;
struct D2SkillDescTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    void* f_14;
    char unk0x18[0x10];
    int dwInitSeed;
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x18];
    int dwFrameCountPrecise;
    char unk0x4C[0x14];
    D2InventoryStrc* pInventory;
    D2GfxLightStrc* pLight;
    char unk0x68[0x5C];
    unsigned int dwFlags;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char unk0x00C[0x0A];
    unsigned char nSeqInput;
    char unk0x017[0x4D];
    int dwAuraRangeCalc;
    char unk0x068[0x82];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    short wCltMissileD;
    char unk0x0F2[0x1A];
    short wPrgOverlay;
    short wPrgSound;
    char unk0x110[0x04];
    int dwCltCalc[3];
    char unk0x120[0x18];
    int dwCalc[4];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2MissilesTxt
{
    char unk0x000[0x18];
    short wSubMissile[3];
    char unk0x01E[0x186];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x1C];
    int nOverlayTxtRecordCount;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);
typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

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
    int unk0x38;
    int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int nInitArg;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004E1FF0
int __fastcall sub_004E1FF0_SkillCltDoMissileWall(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!sub_004C52E0_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nDX = nTargetX - nX;
    int nDY = nTargetY - nY;
    if (!nDX && !nDY)
    {
        return 0;
    }

    int nStepX = 0;
    int nStepY = 0;

    if (nDX < 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = -2;
    }
    else if (nDX == 0 && nDY < 0)
    {
        nStepX = 2;
    }
    else if (nDX > 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = 2;
    }
    else if (nDX > 0 && nDY == 0)
    {
        nStepY = 2;
    }
    else if (nDX > 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = 2;
    }
    else if (nDX == 0 && nDY > 0)
    {
        nStepX = -2;
    }
    else if (nDX < 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = -2;
    }
    else if (nDX < 0 && nDY == 0)
    {
        nStepY = -2;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    nDX -= nCount / 2 * nStepX;
    nDY -= nCount / 2 * nStepY;

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    for (int i = 0; i < nCount; ++i)
    {
        tMissile.pOwner = pUnit;
        tMissile.nX = nX + nDX / 6;
        tMissile.nTargetX = nDX;
        tMissile.nTargetY = nDY;
        tMissile.nY = nY + nDY / 6;
        tMissile.nSkillLevel = nSkillLevel;
        tMissile.nMissile = nMissile;
        sub_004CD540_CreateMissile(&tMissile);
        nDX += nStepX;
        nDY += nStepY;
    }

    return 1;
}
