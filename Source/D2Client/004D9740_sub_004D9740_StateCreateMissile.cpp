struct D2UnitStrc;

struct D2StatesTxt
{
    char unk0x00[0x38];
    short wSkill;
    short wMissile;
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    void* pStatesLinker;
    int nStatesTxtRecordCount;
    char unk0x0C8[0xB6C - 0xC8];
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
void __fastcall sub_004AF890(D2UnitStrc* pUnit, int nArg1, int nArg2);                                      // 0x004AF890
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540

static D2StatesTxt* STATES_GetStatesTxtRecord_J03(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

// 0x004D9740
void __fastcall sub_004D9740_StateCreateMissile(D2UnitStrc* pUnit, int nState)
{
    sub_004AF890(pUnit, 5, 0);

    D2StatesTxt* pStatesTxt = STATES_GetStatesTxtRecord_J03(nState);
    if (!pStatesTxt)
    {
        return;
    }

    if (pStatesTxt->wMissile < 0 || pStatesTxt->wMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nMissile = pStatesTxt->wMissile;
    tMissile.nSkill = pStatesTxt->wSkill >= 0 ? pStatesTxt->wSkill : 0;
    tMissile.nSkillLevel = 1;
    sub_004CD540_CreateMissile(&tMissile);
}
