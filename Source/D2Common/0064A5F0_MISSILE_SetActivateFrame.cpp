#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2MissileDataStrc
{
    int unk_00[2];
    short nActivateFrame;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId[4];
    D2MissileDataStrc* pMissileData;
};

// 0x0064A5F0
void __stdcall MISSILE_SetActivateFrame(D2UnitStrc* pMissile, int nActivateFrame)
{
    if (pMissile && pMissile->dwUnitType == 3 && pMissile->pMissileData)
    {
        nActivateFrame = D2_MIN(D2_MAX(nActivateFrame, -32768), 32767);
        pMissile->pMissileData->nActivateFrame = nActivateFrame;
    }
}
