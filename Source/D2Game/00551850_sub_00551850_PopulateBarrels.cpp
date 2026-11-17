struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;
struct D2ItemDropStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD0];
    unsigned int dwSizeX;
    unsigned int dwSizeY;
    char unk_D8[0x162 - 0xD8];
    unsigned char nXSpacing;
    unsigned char nYSpacing;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
D2UnitStrc* __fastcall ITEMS_DropRandomItemAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDrop); // 0x00559130
extern int gnArmorStandOrRackIds_00731EA0[];                                                                // 0x00731EA0
extern int gnArmorStandOrRackCount_00731EB0;                                                                // 0x00731EB0

static inline unsigned __int64 OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*, D2DrlgCoordsStrc*); // 0x00619730
extern int gnBarrelXOffsets_00731B7C[8]; // 0x00731B7C
extern int gnBarrelYOffsets_00731B9C[8]; // 0x00731B9C

static __declspec(noinline) int __stdcall sub_005502F0_CanPlace(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY);

// 0x005502F0
static int __stdcall sub_005502F0_CanPlace(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY)
{
    if (pDrlgCoords->nSubtileWidth < 2 || pDrlgCoords->nSubtileHeight < 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 2
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 2
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileWidth + pDrlgCoords->nSubtileX - nSizeX
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileHeight + pDrlgCoords->nSubtileY - nSizeY
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 2, nSizeY + 2, 0x3F11))
    {
        return 1;
    }
    return 0;
}

static __forceinline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0) return 0;
    if ((nMax - 1) & nMax) return (unsigned int)OBJECTS_RollSeed_Inline(pSeed) % nMax;
    return (unsigned int)OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}
// 0x00551850
D2UnitStrc* __fastcall sub_00551850_PopulateBarrels(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(7);
    D2_ASSERT(nDensity <= 128, 0x955);
    int nCount = 0;
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    D2SeedStrc* pSeed = &pControl->pSeed;
    if ((unsigned int)OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability) return 0;
    D2DrlgCoordsStrc bounds;
    DUNGEON_GetRoomCoordinates(pRoom, &bounds);
    int nClusters = ((bounds.nSubtileWidth * bounds.nSubtileHeight >> 7) * nDensity) >> 8;
    int nTries = 2 * nClusters;
    D2UnitStrc* pObject = 0;
    while (nClusters > 0 && nTries > 0)
    {
        int nClassId;
        if (OBJECTS_RollLimited_Inline(pSeed, 3))
            nClassId = 7;
        else
            nClassId = 11;
        D2CoordStrc base;
        base.nX = bounds.nSubtileX + OBJECTS_RollLimited_Inline(pSeed, bounds.nSubtileWidth);
        base.nY = bounds.nSubtileY + OBJECTS_RollLimited_Inline(pSeed, bounds.nSubtileHeight);
        D2CoordStrc coord;
        coord.nX = base.nX;
        coord.nY = base.nY;
        if (sub_005502F0_CanPlace(&bounds, &coord, pRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY) == 1)
        {
            D2_ASSERT(pRoom, 0x98D);
            pObject = SUNIT_AllocUnitData(2, nClassId, base.nX, base.nY, pGame, pRoom, 1, 0, 0);
            int nClusterSize = 1;
            ++nCount;
            if (nCount >= 8) return pObject;
            int bCanPlace = 1;
            pObject = 0;
            while (!OBJECTS_RollLimited_Inline(pSeed, nClusterSize >> 1) && bCanPlace)
            {
                int i = 0;
                bCanPlace = 0;
                while (!bCanPlace)
                {
                    if (i >= 15) break;
                    const unsigned int nDirection = (unsigned int)OBJECTS_RollSeed_Inline(pSeed) & 7;
                    base.nX += pObjectsTxt->nXSpacing * gnBarrelXOffsets_00731B7C[nDirection];
                    base.nY += pObjectsTxt->nYSpacing * gnBarrelYOffsets_00731B9C[nDirection];
                    coord.nX = base.nX;
                    coord.nY = base.nY;
                    bCanPlace = sub_005502F0_CanPlace(&bounds, &coord, pRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY);
                    ++i;
                }
                if (!bCanPlace) continue;
                int nNextClass;
                if ((unsigned int)OBJECTS_RollSeed_Inline(pSeed) & 3)
                    nNextClass = 7;
                else
                    nNextClass = 11;
                pObject = SUNIT_AllocUnitData(2, nNextClass, base.nX, base.nY, pGame, pRoom, 1, 0, 0);
                ++nClusterSize;
                ++nCount;
                if (nCount >= 8) return pObject;
            }
            --nClusters;
        }
        --nTries;
    }
    return pObject;
}
