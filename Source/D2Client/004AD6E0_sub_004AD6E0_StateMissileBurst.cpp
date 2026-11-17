struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    int nXPos;
    int nYPos;
};

struct D2MonsterDataStrc
{
    char pad0x00[0x16];
    unsigned short nTypeFlag;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x14];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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
    void(__fastcall* pInitFunc)(D2UnitStrc* pMissile);
    int pInitArgs;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile);                                          // 0x004E2ED0
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);            // 0x00621810
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

static int GetUnitPathX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int GetUnitPathY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x004AD6E0
static void __stdcall sub_004AD6E0_StateMissileBurst(int nSkillLevel, D2UnitStrc* pUnit, int nMissile)
{
    if (!nSkillLevel)
        nSkillLevel = 1;
    if (nMissile == 0xC3)
    {
        if (!pUnit || pUnit->dwUnitType != 1 || !pUnit->pMonsterData || !(pUnit->pMonsterData->nTypeFlag & 0x100))
            return;
    }
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = GetUnitPathX(pUnit);
    tMissile.nY = GetUnitPathY(pUnit);
    tMissile.nSkill = 0;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    if (nMissile != 0x141)
        tMissile.pInitFunc = sub_004E2ED0_VolleyCallback;
    int anDX[4] = { 0, 1, 0, -1 };
    int anDY[4] = { -1, 0, 1, 0 };
    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = GetUnitPathX(pUnit);
        const int nUnitY = GetUnitPathY(pUnit);
        const int nX = anDX[i] + nUnitX;
        const int nY = anDY[i] + nUnitY;
        for (int j = 0; j < 2; ++j)
        {
            tMissile.pInitArgs = j;
            tMissile.nTargetX = nX;
            tMissile.nTargetY = nY;
            sub_004CD540_CreateMissile(&tMissile);
        }
    }
}

// 0x004AD890
void __fastcall sub_004AD890_StateBurstOnFrame(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bSet, &nFrameCount);
    if (!pUnit || pUnit->dwAnimMode != 3 || bSet != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, 0xC3);
}

// 0x004AD8E0
void __fastcall sub_004AD8E0_StateBurst(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    if (pUnit && pUnit->dwAnimMode == 3)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, 0xC3);
}

// build: context sub_004AD920_StateBurstNeutral
void __fastcall sub_004AD920_StateBurstNeutral(D2UnitStrc* pUnit, int nState, int bSet)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode != 3 && (pUnit->dwAnimMode || nFrameNo != 2))
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0);
    sub_004AD6E0_StateMissileBurst(nLevel, pUnit, 0xE1);
}
