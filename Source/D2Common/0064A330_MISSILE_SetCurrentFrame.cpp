#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2MissileDataStrc
{
    int unk_00[4];
    short nCurrentFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId[4];
    D2MissileDataStrc* pMissileData;
};

// 0x0064A330
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        nCurrentFrame = D2_MIN(D2_MAX(nCurrentFrame, -32768), 32767);
        pMissile->pMissileData->nCurrentFrame = nCurrentFrame;
    }
}
