struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x18];
    int nSpawnCount;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    char unk0x28[0x26];
    unsigned char nActionFrame;
};

#define UNIT_MONSTER 1
#define MONMODE_DEATH 0
#define MONMODE_DEAD 12

void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810
void __fastcall sub_0046F170_RemoveOverlays(D2UnitStrc* pUnit);                                             // 0x0046F170
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount);               // 0x0046C320

static __forceinline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x004AD5F0
void __fastcall sub_004AD5F0_StateOverlayOrSpawn(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
        return;

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
        return;

    if (pUnit->dwAnimMode == MONMODE_DEATH)
    {
        int nFrame;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
        if (nFrame == 13)
        {
            sub_0046F170_RemoveOverlays(pUnit);
            sub_00470390(pUnit, 0x34, 5, 0, 0, 0, 0, 0);
            sub_00470390(pUnit, 0x9C, 5, 0, 0, 0, 0, 0);
            pUnit->nActionFrame = 0;
        }
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD)
    {
        if ((unsigned int)SEED_RollRandomNumberForceInline(&pUnit->pSeed) % 100 == 0 && pMonsterData->nSpawnCount < 100)
        {
            UNITS_GetXPosition(pUnit);
            CLIENTS_GetUnitY(pUnit);
            sub_0046C320_SpawnAroundUnit(pUnit, 0xE3, 4);
            pMonsterData->nSpawnCount += 4;
        }
    }
}
