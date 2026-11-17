struct D2ActiveRoomStrc;
struct tagRECT { long left; long top; long right; long bottom; };
struct D2DrlgCoordsStrc { int nSubtileX; int nSubtileY; int nSubtileWidth; int nSubtileHeight; int nTileXPos; int nTileYPos; int nTileWidth; int nTileHeight; };
struct D2SpawnAreaStrc { char unk0x00[0x10]; tagRECT tRect; char unk0x20[0x08]; int nIndex; };
extern "C" __declspec(dllimport) int __stdcall CopyRect(tagRECT* lprcDst, const tagRECT* lprcSrc);              // 0x006CC458
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall DUNGEON_GameTileToSubtileCoords(long* pX, long* pY);                                        // 0x00643560

static void __stdcall sub_0054DAC0_GetSpawnBounds(D2ActiveRoomStrc* pRoom, int* pWidth, D2SpawnAreaStrc* pArea, int* pX, int* pY, int* pHeight)
{
    if (!pArea)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom, &coords);
        *pX = coords.nSubtileX + 1;
        *pY = coords.nSubtileY + 1;
        *pWidth = coords.nSubtileWidth - 1;
        *pHeight = coords.nSubtileHeight - 1;
    }
    else
    {
        tagRECT rect;
        CopyRect(&rect, &pArea->tRect);
        DUNGEON_GameTileToSubtileCoords(&rect.left, &rect.top);
        DUNGEON_GameTileToSubtileCoords(&rect.right, &rect.bottom);
        *pX = rect.left + 1;
        *pY = rect.top + 1;
        *pWidth = rect.right - *pX;
        *pHeight = rect.bottom - *pY;
    }
}

void __stdcall sub_M96_UseBounds_0054DAC0(int nX, int nY, int nWidth, int nHeight);
void __fastcall sub_M96_Emit_0054DAC0(void* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea)
{
    int nX, nY, nWidth, nHeight;
    int nPosX, nPosY;
    sub_0054DAC0_GetSpawnBounds(pRoom, &nWidth, pArea, &nX, &nY, &nHeight);
    sub_M96_UseBounds_0054DAC0(nX, nY, nWidth, nHeight);
}

struct D2GameStrc;
struct D2UnitStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomViewStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

struct D2FormationOffsetStrc
{
    int nX;
    int nY;
    int unk0x08;
};

struct D2UnkMonCreateStrc2
{
    int nCount;
    int unk0x04[2];
    D2FormationOffsetStrc pOffsets[1];
};

int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY);                                       // 0x0061B130
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int a7, int a8); // 0x005B2F20
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pCoordList, int nX, int nY, int nMonsterId, int nMode, int a8, int a9); // 0x005B3040

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
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

// 0x0054DDC0
int __stdcall sub_0054DDC0_FindPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea, int nClassId, int* pFormation, int* pX, int* pY)
{
    int nX, nY, nWidth, nHeight;
    sub_0054DAC0_GetSpawnBounds(pRoom, &nWidth, pArea, &nX, &nY, &nHeight);

    int bHasArea = 0;
    int nAreaIndex = 0;
    if (pArea)
    {
        nAreaIndex = pArea->nIndex;
        bHasArea = 1;
    }

    D2SeedStrc* pSeed = pRoom ? &((D2ActiveRoomViewStrc*)pRoom)->pSeed : 0;
    const int nCount = pFormation[0];
    pFormation += 3;
    for (int nTry = 0; nTry < 20; ++nTry)
    {
        const int nPosX = SEED_RollLimitedRandomNumber(pSeed, nWidth) + nX;
        const int nPosY = SEED_RollLimitedRandomNumber(pSeed, nHeight) + nY;

        D2FormationOffsetStrc* pOffset = (D2FormationOffsetStrc*)pFormation;
        int bPlaced = 1;
        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pMonster;
            if (bHasArea)
            {
                if (D2Common_10095(pRoom, pOffset->nX + nPosX, pOffset->nY) != nAreaIndex)
                {
                    bPlaced = 0;
                    break;
                }

                pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pArea, pOffset->nX + nPosX, pOffset->nY + nPosY, nClassId, 1, -1, 1);
            }
            else
            {
                pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pOffset->nX + nPosX, pOffset->nY + nPosY, nClassId, 1, -1, 1);
            }

            if (!pMonster)
            {
                bPlaced = 0;
                break;
            }

            ++pOffset;
        }

        if (bPlaced)
        {
            *pX = nPosX;
            *pY = nPosY;
            return 1;
        }
    }

    return 0;
}
