struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc pSeed;
    char unk0x28[0x1C];
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
};

struct D2GSPacketSrv73
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char nMissileId[2];
    unsigned char nX[4];
    unsigned char nY[4];
    unsigned char nFirstX[4];
    unsigned char nFirstY[4];
    unsigned char nCurrentFrame[2];
    unsigned char nUnitType;
    unsigned char nUnitGUID[4];
    unsigned char nLevel;
    unsigned char nPierce;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit();                                                           // 0x00463DE0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId);                // 0x00621CC0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

// 0x0045E6D0
void __fastcall sub_0045E6D0_Packet73(const D2GSPacketSrv73* pPacket)
{
    const int nX = *(const int*)pPacket->nX;
    const int nY = *(const int*)pPacket->nY;
    const int nFirstX = *(const int*)pPacket->nFirstX;
    const int nFirstY = *(const int*)pPacket->nFirstY;
    const unsigned short nCurrentFrame = *(const unsigned short*)pPacket->nCurrentFrame;
    const unsigned short nMissileId = *(const unsigned short*)pPacket->nMissileId;
    const int nUnitGUID = *(const int*)pPacket->nUnitGUID;

    D2UnitStrc* pOwner = sub_00463DE0_GetStoredUnit();
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pOwner;
    tMissileParams.dwFlags = 0x40000001;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkillLevel = pPacket->nLevel;
    tMissileParams.nMissile = nMissileId;
    if (nFirstX && nFirstY)
    {
        tMissileParams.dwFlags = 0x40000021;
        tMissileParams.nTargetX = nFirstX;
        tMissileParams.nTargetY = nFirstY;
    }

    D2UnitStrc* pMissile = sub_004CD540_CreateMissile(&tMissileParams);
    if (pMissile)
    {
        UNITS_StoreOwnerTypeAndGUID(pMissile, pPacket->nUnitType, nUnitGUID);
        if (pPacket->nPierce)
            STATLIST_SetUnitStat(pMissile, 0x148, pPacket->nPierce, 0);

        MISSILE_SetCurrentFrame(pMissile, nCurrentFrame);
        pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissile->dwFrameCountPrecise >> 8) << 8;
    }
}
