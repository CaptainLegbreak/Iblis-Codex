struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int nFlags;
};

struct D2MapAIPathPositionStrc
{
    int nMapAIAction;
    int nX;
    int nY;
};

struct D2MapAIStrc
{
    int nPathNodes;
    D2MapAIPathPositionStrc* pPosition;
};

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    D2MapAIStrc* pMapAI;
    int nUnitType;
    int nYpos;
    int bSpawned;
};

struct D2DrlgFileStrc
{
    char unk0x00[0x14];
    int nWallLayers;
    int nFloorLayers;
};

struct D2LvlPrestTxt
{
    int dwDef;
    int unk0x04;
    int dwPopulate;
    char unk0x0C[0x1C];
    int nSizeX;
    int nSizeY;
    char unk0x30[0x14];
    char szFile[6][60];
};

struct D2DrlgVertexStrc;

struct D2DrlgMapStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
    D2DrlgFileStrc* pFile;
    char unk0x10[0x10];
    D2DrlgVertexStrc* pVertices;
    D2DrlgGridStrc pMapGrid;
    D2PresetUnitStrc* pPresetUnit;
    char unk0x3C[0x8];
    int* pPopsIndex;
    int* pPopsSubIndex;
    int* pPopsOrientation;
    int* pPopsLocation;
    D2DrlgMapStrc* pNext;
};

struct D2DrlgPresetRoomStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2DrlgMapStrc* pMap;
    unsigned int dwFlags;
    D2DrlgGridStrc pWallGrid[4];
    D2DrlgGridStrc pTileTypeGrid[4];
    D2DrlgGridStrc pFloorGrid[2];
    D2DrlgGridStrc pCellGrid;
    D2DrlgGridStrc* pMazeGrid;
    D2DrlgCoordStrc* pTombStoneTiles;
    int nTombStoneTiles;
};

struct D2DrlgPresetLevelStrc
{
    D2DrlgMapStrc* pDrlgMap;
};

struct D2DrlgStrc
{
    char unk0x000[0x478];
    void* pMempool;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x14];
    D2DrlgPresetLevelStrc* pPreset;
    char unk0x018[0x19C];
    D2DrlgStrc* pDrlg;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgPresetRoomStrc* pMaze;
    char unk0x24[0x4];
    unsigned int dwFlags;
    char unk0x2C[0x8];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x4];
    int nType;
    char unk0x4C[0x4];
    unsigned int dwDT1Mask;
    char unk0x54[0x4];
    D2DrlgLevelStrc* pLevel;
};

extern "C" const char gszDrlgPresetSourceFile;                                                                    // 0x006EE7C4
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId);                                                  // 0x0061F0B0
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);                            // 0x0066B3E0
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom);                          // 0x0066B970
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);                                     // 0x0067CD90
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertices);                              // 0x0067D1E0
void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile);                                                // 0x00668300
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                            // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x006829C0
#pragma intrinsic(memset, memcpy)

D2MapAIStrc* __fastcall DRLGPRESET_CreateCopyOfMapAI(void* pMemPool, D2MapAIStrc* pMapAI)
{
    D2MapAIStrc* pNewMapAI = (D2MapAIStrc*)sub_0040B430(pMemPool, sizeof(D2MapAIStrc), &gszDrlgPresetSourceFile, 1396, 0);
    memset(pNewMapAI, 0, sizeof(D2MapAIStrc));
    pNewMapAI->nPathNodes = pMapAI->nPathNodes;
    pNewMapAI->pPosition = (D2MapAIPathPositionStrc*)sub_0040B430(pMemPool, sizeof(D2MapAIPathPositionStrc) * pNewMapAI->nPathNodes, &gszDrlgPresetSourceFile, 1401, 0);
    memcpy(pNewMapAI->pPosition, pMapAI->pPosition, sizeof(D2MapAIPathPositionStrc) * pNewMapAI->nPathNodes);
    return pNewMapAI;
}

D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc** ppMapAI2)
{
    *ppMapAI2 = *ppMapAI1;
    *ppMapAI1 = 0;

    return *ppMapAI2;
}

void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAI)
{
    sub_0040B480(pMemPool, pMapAI->pPosition, &gszDrlgPresetSourceFile, 1431, 0);
    sub_0040B480(pMemPool, pMapAI, &gszDrlgPresetSourceFile, 1432, 0);
}

static void __stdcall DRLGPRESET_FreeDrlgGrids(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze && pMaze->pMap)
    {
        D2DrlgFileStrc* pDrlgFile = pMaze->pMap->pFile;
        if (pDrlgFile)
        {
            const int nWallLayers = pDrlgFile->nWallLayers;
            for (int i = 0; i < nWallLayers; ++i)
            {
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pTileTypeGrid[i]);
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pWallGrid[i]);
            }

            const int nFloorLayers = pDrlgFile->nFloorLayers;
            for (int i = 0; i < nFloorLayers; ++i)
            {
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pFloorGrid[i]);
            }

            DRLGGRID_FreeGrid(pMemPool, &pMaze->pCellGrid);
        }
    }
}

void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->pLevel->pDrlg->pMempool;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze)
    {
        DRLGPRESET_FreeDrlgGrids(pMemPool, pDrlgRoom);

        if (pMaze->pTombStoneTiles)
        {
            sub_0040B480(pMemPool, pMaze->pTombStoneTiles, &gszDrlgPresetSourceFile, 1783, 0);
        }

        sub_0040B480(pMemPool, pMaze, &gszDrlgPresetSourceFile, 1786, 0);
        pDrlgRoom->pMaze = 0;
    }
}

void __fastcall DRLGPRESET_FreeDrlgGridsFromPresetRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->pMaze)
    {
        DRLGPRESET_FreeDrlgGrids(pDrlgRoom->pLevel->pDrlg->pMempool, pDrlgRoom);
    }
}

void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = (D2DrlgPresetRoomStrc*)sub_0040B430(pDrlgRoom->pLevel->pDrlg->pMempool, sizeof(D2DrlgPresetRoomStrc), &gszDrlgPresetSourceFile, 1807, 0);
    memset(pMaze, 0, sizeof(D2DrlgPresetRoomStrc));
    pDrlgRoom->pMaze = pMaze;
}

D2DrlgRoomStrc* __fastcall DRLGPRESET_InitPresetRoomData(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, D2DrlgCoordStrc* pDrlgCoord, unsigned int dwDT1Mask, int dwRoomFlags, int dwPresetFlags, D2DrlgGridStrc* pMazeGrid)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
    pDrlgRoom->dwDT1Mask = dwDT1Mask;
    pDrlgRoom->dwFlags |= dwRoomFlags;
    pDrlgRoom->pDrlgCoord.nPosX = pDrlgCoord->nPosX;
    pDrlgRoom->pDrlgCoord.nPosY = pDrlgCoord->nPosY;
    pDrlgRoom->pDrlgCoord.nWidth = pDrlgCoord->nWidth;
    pDrlgRoom->pDrlgCoord.nHeight = pDrlgCoord->nHeight;

    D2DrlgPresetRoomStrc* pDrlgPresetRoom = pDrlgRoom->pMaze;
    pDrlgPresetRoom->pMap = pDrlgMap;
    pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
    pDrlgPresetRoom->dwFlags = dwPresetFlags;
    pDrlgPresetRoom->pMazeGrid = pMazeGrid;

    if (pMazeGrid)
    {
        pMazeGrid->nHeight |= 1;
    }

    if (!pDrlgPresetRoom->pMap->pLvlPrestTxtRecord->dwPopulate)
    {
        pDrlgRoom->dwFlags |= 0x800000;
    }

    DRLGROOM_AddRoomExToLevel(pLevel, pDrlgRoom);
    return pDrlgRoom;
}

void __fastcall DRLGPRESET_GetTombStoneTileCoords(D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordStrc** ppTombStoneTiles, int* pnTombStoneTiles)
{
    if (pDrlgRoom->nType != 2)
    {
        *ppTombStoneTiles = 0;
        *pnTombStoneTiles = 0;
    }
    else
    {
        D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
        *ppTombStoneTiles = pMaze->pTombStoneTiles;
        *pnTombStoneTiles = pMaze->nTombStoneTiles;
    }
}

int __fastcall DRLGPRESET_SetPickedFileInDrlgMap(D2DrlgMapStrc* pDrlgMap, int nPickedFile)
{
    return pDrlgMap->nPickedFile = nPickedFile;
}

int __fastcall DRLGPRESET_GetSizeX(int nLvlPrestId)
{
    return DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId)->nSizeX;
}

int __fastcall DRLGPRESET_GetSizeY(int nLvlPrestId)
{
    return DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId)->nSizeY;
}

char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    return pMaze->pMap->pLvlPrestTxtRecord->szFile[pMaze->pMap->nPickedFile];
}

void __fastcall DRLGPRESET_ResetDrlgMap(D2DrlgLevelStrc* pLevel, int bKeepPreset)
{
    pLevel->pPreset->pDrlgMap = 0;

    if (!bKeepPreset)
    {
        sub_0040B480(pLevel->pDrlg->pMempool, pLevel->pPreset, &gszDrlgPresetSourceFile, 2906, 0);
        pLevel->pPreset = 0;
    }
}

D2PresetUnitStrc* __fastcall DRLGPRESET_CopyPresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit, int nX, int nY)
{
    D2PresetUnitStrc* pNewPresetUnit = (D2PresetUnitStrc*)sub_0040B430(pMemPool, sizeof(D2PresetUnitStrc), &gszDrlgPresetSourceFile, 1354, 0);
    memset(pNewPresetUnit, 0, sizeof(D2PresetUnitStrc));
    pNewPresetUnit->nUnitType = pPresetUnit->nUnitType;
    pNewPresetUnit->nIndex = pPresetUnit->nIndex;
    pNewPresetUnit->nMode = pPresetUnit->nMode;
    pNewPresetUnit->nXpos = nX + pPresetUnit->nXpos;
    pNewPresetUnit->nYpos = nY + pPresetUnit->nYpos;
    pNewPresetUnit->bSpawned = pPresetUnit->bSpawned;

    if (pPresetUnit->pMapAI)
    {
        pNewPresetUnit->pMapAI = DRLGPRESET_CreateCopyOfMapAI(pMemPool, pPresetUnit->pMapAI);

        for (unsigned int i = 0; i < (unsigned int)pNewPresetUnit->pMapAI->nPathNodes; ++i)
        {
            pNewPresetUnit->pMapAI->pPosition[i].nX += nX;
            pNewPresetUnit->pMapAI->pPosition[i].nY += nY;
        }
    }

    return pNewPresetUnit;
}

void __fastcall DRLGPRESET_FreePresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit)
{
    if (pPresetUnit->pMapAI)
    {
        DRLGPRESET_FreeMapAI(pMemPool, pPresetUnit->pMapAI);
    }

    sub_0040B480(pMemPool, pPresetUnit, &gszDrlgPresetSourceFile, 1387, 0);
}

// 0x006683D0
void __fastcall DRLGPRESET_FreeDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap)
{
    D2DrlgMapStrc* pMap = pDrlgMap;
    while (pMap)
    {
        D2DrlgMapStrc* pNextMap = pMap->pNext;

        DRLGGRID_FreeGrid(pMemPool, &pMap->pMapGrid);
        DRLGVER_FreeVertices(pMemPool, &pMap->pVertices);
        DRLGPRESET_FreeDrlgFile(&pMap->pFile);

        D2PresetUnitStrc* pPresetUnit = pMap->pPresetUnit;
        while (pPresetUnit)
        {
            D2PresetUnitStrc* pFreePresetUnit = pPresetUnit;
            pPresetUnit = pPresetUnit->pNext;
            DRLGPRESET_FreePresetUnit(pMemPool, pFreePresetUnit);
        }

        if (pMap->pPopsIndex)
        {
            sub_0040B480(pMemPool, pMap->pPopsIndex, &gszDrlgPresetSourceFile, 2554, 0);
        }

        if (pMap->pPopsSubIndex)
        {
            sub_0040B480(pMemPool, pMap->pPopsSubIndex, &gszDrlgPresetSourceFile, 2555, 0);
        }

        if (pMap->pPopsOrientation)
        {
            sub_0040B480(pMemPool, pMap->pPopsOrientation, &gszDrlgPresetSourceFile, 2556, 0);
        }

        if (pMap->pPopsLocation)
        {
            sub_0040B480(pMemPool, pMap->pPopsLocation, &gszDrlgPresetSourceFile, 2557, 0);
        }

        sub_0040B480(pMemPool, pMap, &gszDrlgPresetSourceFile, 2559, 0);
        pMap = pNextMap;
    }
}
