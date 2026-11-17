struct D2ActiveRoomStrc;
struct D2SeedStrc { unsigned int nLowSeed; unsigned int nHighSeed; };
struct D2UnitStrc { int dwUnitType; int dwClassId; char unk0x08[0x18]; D2SeedStrc pSeed; };
struct D2DrlgCoordsStrc { int nX; int nY; int nWidth; int nHeight; int nTileX; int nTileY; int nTileW; int nTileH; };
struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int unk0x1C[4];
    int nSkill;
    int nSkillLevel;
    char unk0x34[0x28];
};

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }
    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0046AF70
void __stdcall sub_0046AF70(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (pPlayer)
    {
        D2MissileStrc tMissile;
        D2DrlgCoordsStrc tCoords;
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2003;
        tMissile.pOwner = pPlayer;
        tMissile.nSkill = 0;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = 0x11F;
        DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
        int nCount = 0;
        int i = 0;
        for (; nCount < 3; ++i)
        {
            if (i >= 25) break;
            int nX = tCoords.nX + SEED_RollLimitedRandomNumber(&pPlayer->pSeed, tCoords.nWidth);
            int nY = tCoords.nY + SEED_RollLimitedRandomNumber(&pPlayer->pSeed, tCoords.nHeight);
            tMissile.nX = nX;
            if (!COLLISION_CheckMask(pRoom, nX, tMissile.nY = nY, 5)) { sub_004CD540_CreateMissile(&tMissile); } else { --nCount; }
            ++nCount;
        }
    }
}
