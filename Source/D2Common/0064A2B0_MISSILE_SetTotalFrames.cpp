#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2MissileDataStrc
{
    int unk_00[3];
    short nLevel;
    short nTotalFrames;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId[4];
    D2MissileDataStrc* pMissileData;
};

// 0x0064A2B0
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        nTotalFrames = D2_MIN(D2_MAX(nTotalFrames, -32768), 32767);
        pMissile->pMissileData->nTotalFrames = nTotalFrames;
    }
}
