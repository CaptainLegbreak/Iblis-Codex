struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x4];
    unsigned int dwFlags;
    char unk0x008[0x1AC];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0xC];
    D2SeedStrc pSeed;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x4];
    unsigned int dwInitSeed;
    char unk0x08[0xC];
    D2SeedStrc pSeed;
    char unk0x1C[0xC];
    unsigned int dwFlags;
    char unk0x2C[0x18];
    unsigned char fRoomStatus;
    char unk0x45[0x3];
    int nType;
    char unk0x4C[0x4];
    unsigned int dwDT1Mask;
    char unk0x54[0x4];
    D2DrlgLevelStrc* pLevel;
    char unk0x5C[0x90];
};

struct D2LvlSubTxt
{
    int dwType;
    char unk0x004[0x44];
    unsigned int dwDt1Mask;
    char unk0x04C[0xD0];
    int nProb[5];
    char unk0x130[0x2C];
};

enum D2C_J11DrlgConstants
{
    DRLGTYPE_MAZE = 1,
    DRLGTYPE_PRESET = 2,
    DRLGLEVELFLAG_AUTOMAP_REVEAL = 0x10,
    DRLGROOMFLAG_AUTOMAP_REVEAL = 0x40000,
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId);                                               // 0x0061FA90
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom);                                  // 0x00666630
void __fastcall sub_0067D6D0(D2DrlgRoomStrc* pRoom);                                        // 0x0067D6D0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0066B3E0
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType)
{
    D2DrlgRoomStrc* pDrlgRoom = (D2DrlgRoomStrc*)sub_0040B430(pLevel->pDrlg->pMempool, sizeof(D2DrlgRoomStrc), ".\\DRLG\\DrlgRoom.cpp", 32, 0);
    memset(pDrlgRoom, 0, sizeof(D2DrlgRoomStrc));
    pDrlgRoom->nType = nType;
    pDrlgRoom->pLevel = pLevel;
    pDrlgRoom->fRoomStatus = 4;
    SEED_InitLowSeed(&pDrlgRoom->pSeed, (unsigned int)SEED_RollRandomNumber(&pLevel->pSeed));
    pDrlgRoom->dwInitSeed = (unsigned int)SEED_RollRandomNumber(&pDrlgRoom->pSeed);
    if (pLevel->dwFlags & DRLGLEVELFLAG_AUTOMAP_REVEAL)
    {
        pDrlgRoom->dwFlags |= DRLGROOMFLAG_AUTOMAP_REVEAL;
    }
    switch (nType)
    {
    case DRLGTYPE_MAZE:
        sub_0067D6D0(pDrlgRoom);
        break;
    case DRLGTYPE_PRESET:
        DRLGPRESET_AllocPresetRoomData(pDrlgRoom);
        break;
    }
    return pDrlgRoom;
}

// 0x006706A0
int __fastcall DRLGTILESUB_PickSubThemes(D2DrlgRoomStrc* pDrlgRoom, int nSubType, int nSubTheme)
{
    if (nSubType != -1 && nSubTheme != -1)
    {
        D2LvlSubTxt* pLvlSubTxtRecord = DATATBLS_GetLvlSubTxtRecord(nSubType);
        int nMask = 0;
        int nCounter = 0;
        while (pLvlSubTxtRecord->dwType == nSubType)
        {
            if ((int)((unsigned int)SEED_RollRandomNumber(&pDrlgRoom->pSeed) % 100) < pLvlSubTxtRecord->nProb[nSubTheme])
            {
                nMask |= 1 << nCounter;
                pDrlgRoom->dwDT1Mask |= pLvlSubTxtRecord->dwDt1Mask;
            }
            ++pLvlSubTxtRecord;
            ++nCounter;
        }
        return nMask;
    }
    return 0;
}
