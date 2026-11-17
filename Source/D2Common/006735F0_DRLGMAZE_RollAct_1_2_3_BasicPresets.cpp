struct D2SeedStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};

struct D2RoomPresetStrc
{
    int nLevelPrest;
    int nPickedFile;
    char unk0x08[0x4];
    unsigned int dwFlags;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2RoomPresetStrc* pMaze;
    D2DrlgRoomStrc* pDrlgRoomNext;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x8];
    int nRooms;
    char unk0x0C[0x4];
    D2DrlgRoomStrc* pFirstRoomEx;
    char unk0x14[0x1AC];
    int nLevelType;
    D2SeedStrc pSeed;
    void* pBuild;
    int nLevelId;
};

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->dwHigh + (unsigned __int64)pSeed->dwLow * 0x6AC690C5;
    pSeed->dwHigh = (unsigned int)(lSeed >> 32);
    pSeed->dwLow = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

// 0x006735F0
void __fastcall DRLGMAZE_RollAct_1_2_3_BasicPresets(D2DrlgLevelStrc* pLevel)
{
    int nLevelPrestId;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLevelPrestId = 52;
        break;

    case 4:
        nLevelPrestId = 108;
        break;

    case 7:
        nLevelPrestId = 167;
        break;

    case 8:
        nLevelPrestId = 205;
        break;

    case 10:
        nLevelPrestId = 257;
        break;

    case 13:
        nLevelPrestId = 301;
        break;

    case 17:
        nLevelPrestId = 413;
        break;

    case 22:
        nLevelPrestId = 753;
        break;

    case 24:
        nLevelPrestId = 664;
        break;

    case 25:
        nLevelPrestId = 704;
        break;

    default:
        return;
    }

    if (pLevel->nLevelId == 8)
    {
        return;
    }

    int aSlots[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int nIndex = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
    int nRemaining = D2_MAX(pLevel->nRooms / 5 + 1, 2);
    int nTries = 2 * pLevel->nRooms;

    for (int i = 0; i < 15; ++i)
    {
        const int nFirst = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
        const int nSecond = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
        const int nSlot = aSlots[nFirst];
        aSlots[nFirst] = aSlots[nSecond];
        aSlots[nSecond] = nSlot;
    }

    while (nRemaining && nTries)
    {
        const int nPreset = nLevelPrestId + aSlots[nIndex];
        const int nNewPreset = nLevelPrestId + aSlots[nIndex] + 15;
        for (D2DrlgRoomStrc* pRoom = pLevel->pFirstRoomEx; pRoom; pRoom = pRoom->pDrlgRoomNext)
        {
            if ((~(pRoom->pMaze->dwFlags >> 1) & 1) && pRoom->pMaze->nLevelPrest == nPreset)
            {
                D2RoomPresetStrc* pMaze = pRoom->pMaze;
                pMaze->dwFlags |= 2;
                --nRemaining;
                pMaze->nLevelPrest = nNewPreset;
                pMaze->nPickedFile = -1;
                break;
            }
        }

        --nTries;
        ++nIndex;
        nIndex -= nIndex / 15 * 15;
    }
}
