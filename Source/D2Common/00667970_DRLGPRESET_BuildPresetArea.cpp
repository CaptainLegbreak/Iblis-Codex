struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

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

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    char unk0x10[0x04];
    int nUnitType;
    int nYpos;
};

struct D2DrlgFileStrc
{
    char unk0x00[0x0C];
    int nWidth;
    int nHeight;
    int nWallLayers;
    char unk0x18[0x04];
    void* pTileTypeLayer[4];
    void* pWallLayer[4];
    char unk0x3C[0x18];
    D2PresetUnitStrc* pPresetUnit;
};

struct D2LvlPrestTxt
{
    int dwDef;
    char unk0x04[0x04];
    int dwPopulate;
    char unk0x0C[0x04];
    int dwOutdoors;
    char unk0x14[0x20];
    int dwScan;
    int dwPops;
    char unk0x3C[0x08];
    char szFile[6][60];
    unsigned int dwDt1Mask;
};

struct D2ObjectsTxt
{
    char unk0x00[0x167];
    unsigned char nSubClass;
};

struct D2DrlgVertexStrc;

struct D2DrlgMapStrc
{
    int nLevelPrest;
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
    D2DrlgFileStrc* pFile;
    D2DrlgCoordStrc pDrlgCoord;
    D2DrlgVertexStrc* pVertices;
    D2DrlgGridStrc pMapGrid;
    char unk0x38[0x08];
    int nPops;
    int* pPopsIndex;
    int* pPopsSubIndex;
    int* pPopsOrientation;
    D2DrlgCoordStrc* pPopsLocation;
};

struct D2DrlgPresetRoomStrc
{
    int nLevelPrest;
    char unk0x04[0x04];
    D2DrlgMapStrc* pMap;
    unsigned int dwFlags;
    char unk0x10[0xDC];
    D2DrlgGridStrc* pMazeGrid;
};

struct D2DrlgStrc
{
    char unk0x00[0x464];
    void* hArchive;
    char unk0x468[0x10];
    void* pMempool;
};

struct D2DrlgTileInfoStrc
{
    int nPosX;
    int nPosY;
    int nTileIndex;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x2C];
    D2DrlgTileInfoStrc pTileInfo[32];
    char unk0x1AC[0x08];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int nLevelId;
    char unk0x1D4[0x04];
    int nTileInfo;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x20];
    D2DrlgPresetRoomStrc* pMaze;
    char unk0x24[0x04];
    unsigned int dwFlags;
    char unk0x2C[0x08];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x0C];
    unsigned int dwDT1Mask;
};

extern "C" const char gszEmptyAssertText;    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();    // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);    // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszDrlgPresetSourceFile;    // 0x006EE7C4
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);    // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);    // 0x00640E90
void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc** ppDrlgFile, void* hArchive, const char* szFile);    // 0x00665F40
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed);    // 0x00667620
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, char nIndex);    // 0x0066AF30
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);    // 0x0066B3E0
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom);    // 0x0066B970
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);    // 0x0066C040
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlags, int nOperation);    // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);    // 0x0067C570
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation);    // 0x0067C590
void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags);    // 0x0067CBF0
void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth, int* pBuffer);    // 0x0067CD30
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);    // 0x0067CDC0

// build: symbol ?sub_00666E00@@YGXPAUD2DrlgMapStrc@@H@Z 0x00666E00
static void __stdcall sub_00666E00(D2DrlgMapStrc* pDrlgMap, int nPops)
{
    pDrlgMap->nPops = nPops;

    for (int i = 0; i < nPops; ++i)
    {
        D2DrlgCoordStrc* pPopsLocation = &pDrlgMap->pPopsLocation[i];
        const int nX1 = pPopsLocation->nPosX < pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY1 = pPopsLocation->nPosY < pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;
        const int nX2 = pPopsLocation->nPosX > pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY2 = pPopsLocation->nPosY > pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;

        pPopsLocation->nPosX = nX1 + pDrlgMap->pDrlgCoord.nPosX;
        pPopsLocation->nPosY = nY1 + pDrlgMap->pDrlgCoord.nPosY;
        pPopsLocation->nWidth = nX2 - nX1 + 1;
        pPopsLocation->nHeight = nY2 - nY1 + 1;
        pDrlgMap->pPopsIndex[i] = pDrlgMap->pPopsIndex[i] / 4 - 1;
    }
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

// 0x00667970
static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, int bSingleRoom, D2DrlgMapStrc* pDrlgMap)
{
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, pLevel->nLevelId);
    int nWarpFlag = 0x10;
    for (int i = 0; i < 8; ++i)
    {
        if (pVisArray[i] && DRLGWARP_GetWarpDestinationFromArray(pLevel, i) == -1)
        {
            nFlags |= nWarpFlag;
        }

        nWarpFlag <<= 1;
    }

    DRLGGRID_AlterAllGridFlags(pDrlgGrid, nFlags, 0);

    const int bScan = pDrlgMap->pLvlPrestTxtRecord->dwScan;
    const int nPops = pDrlgMap->pLvlPrestTxtRecord->dwPops;
    int nProcessedPops = 0;

    if (!bScan && !nPops)
    {
        return;
    }

    DRLGPRESET_LoadDrlgFile(&pDrlgMap->pFile, pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
    DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pLevel->pSeed);

    D2_ASSERT(pDrlgMap->pFile->nWidth == pDrlgMap->pDrlgCoord.nWidth, 0x8B9);
    D2_ASSERT(pDrlgMap->pFile->nHeight == pDrlgMap->pDrlgCoord.nHeight, 0x8BA);

    if (nPops)
    {
        pDrlgMap->pPopsIndex = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8BF, 0);
        pDrlgMap->pPopsSubIndex = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C0, 0);
        pDrlgMap->pPopsOrientation = (int*)sub_0040B430(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C1, 0);
        pDrlgMap->pPopsLocation = (D2DrlgCoordStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgCoordStrc) * nPops, &gszDrlgPresetSourceFile, 0x8C2, 0);
    }

    memset(pDrlgMap->pPopsIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsSubIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsOrientation, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsLocation, 0, sizeof(D2DrlgCoordStrc) * nPops);

    D2DrlgFileStrc* pFile = pDrlgMap->pFile;
    D2DrlgCoordStrc tDrlgCoord = { 0 };
    D2DrlgGridStrc tTileTypeGrid = { 0 };
    D2DrlgGridStrc tWallGrid = { 0 };
    int nTileTypeCellFlags[0x100];
    int nWallCellFlags[0x100];

    tDrlgCoord.nWidth = pFile->nWidth + 1;
    tDrlgCoord.nHeight = pFile->nHeight + 1;

    for (int i = 0; i < pFile->nWallLayers; ++i)
    {
        DRLGGRID_AssignCellsOffsetsAndFlags(&tTileTypeGrid, (int*)pFile->pTileTypeLayer[i], &tDrlgCoord, pFile->nWidth + 1, nTileTypeCellFlags);
        DRLGGRID_AssignCellsOffsetsAndFlags(&tWallGrid, (int*)pFile->pWallLayer[i], &tDrlgCoord, pFile->nWidth + 1, nWallCellFlags);

        for (int nY = 0; nY < pFile->nHeight; ++nY)
        {
            for (int nX = 0; nX < pFile->nWidth; ++nX)
            {
                const int nTileType = DRLGGRID_GetGridEntry(&tTileTypeGrid, nX, nY);
                const int nWallFlags = DRLGGRID_GetGridEntry(&tWallGrid, nX, nY);
                const unsigned int nIndex = ((unsigned int)nWallFlags >> 0x14) & 0x3F;
                const int nSubIndex = (nWallFlags >> 8) & 0xFF;
                const int nUpperBit = nWallFlags & 0x80000000;

                if (nTileType == 0xB || nTileType == 0xA)
                {
                    if (bScan && nIndex <= 7 && (nSubIndex == 0 || nSubIndex == 4 || nUpperBit))
                    {
                        int nGridX;
                        int nGridY;
                        if (bSingleRoom)
                        {
                            nGridX = 0;
                            nGridY = 0;
                        }
                        else
                        {
                            nGridX = nX / 8;
                            nGridY = nY / 8;
                        }

                        DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 1 << (nIndex + 4), 0);
                    }

                    if (nPops && nIndex >= 8 && nIndex <= 0x1D)
                    {
                        int nCounter = 0;
                        while (nCounter < nProcessedPops)
                        {
                            if (pDrlgMap->pPopsIndex[nCounter] == nIndex)
                            {
                                pDrlgMap->pPopsLocation[nCounter].nWidth = nX;
                                pDrlgMap->pPopsLocation[nCounter].nHeight = nY;
                                break;
                            }

                            ++nCounter;
                        }

                        if (nCounter == nProcessedPops)
                        {
                            pDrlgMap->pPopsIndex[nProcessedPops] = nIndex;
                            pDrlgMap->pPopsSubIndex[nProcessedPops] = nSubIndex;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosX = nX;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosY = nY;
                            ++nProcessedPops;
                        }
                    }

                    if (bScan && nIndex >= 0x1E && nIndex <= 0x21)
                    {
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosX = nX + pDrlgMap->pDrlgCoord.nPosX;
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosY = nY + pDrlgMap->pDrlgCoord.nPosY;

                        switch (nIndex)
                        {
                        case 0x1E:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex;
                            break;

                        case 0x1F:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex + 5;
                            break;

                        case 0x20:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xA;
                            break;

                        case 0x21:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xB;
                            break;

                        case 0x22:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xC;
                            break;
                        }

                        ++pLevel->nTileInfo;
                    }
                }
            }
        }

        DRLGGRID_ResetGrid(&tWallGrid);
        DRLGGRID_ResetGrid(&tTileTypeGrid);
    }

    if (nPops)
    {
        sub_00666E00(pDrlgMap, nProcessedPops);
    }

    if (bScan)
    {
        for (D2PresetUnitStrc* pPresetUnit = pFile->pPresetUnit; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
        {
            if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 0x23D && DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40)
            {
                int nGridX;
                int nGridY;
                if (bSingleRoom)
                {
                    nGridX = 0;
                    nGridY = 0;
                }
                else
                {
                    nGridX = pPresetUnit->nXpos / 5 / 8;
                    nGridY = pPresetUnit->nYpos / 5 / 8;
                }

                DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 0x30000, 0);
            }
        }
    }
}

D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom)
{
    int nCellPos[0x400];
    int nCellFlags[0x100];
    D2DrlgGridStrc tDrlgGrid;

    const int nGridWidth = pDrlgMap->pDrlgCoord.nWidth / 8 + 1;
    const int nGridHeight = pDrlgMap->pDrlgCoord.nHeight / 8 + 1;
    if (pDrlgMap->pLvlPrestTxtRecord->dwOutdoors)
    {
        nFlags |= 0x80000;
    }

    DRLGGRID_FillGrid(&tDrlgGrid, nGridWidth, nGridHeight, nCellPos, nCellFlags);
    DRLGPRESET_BuildPresetArea(pLevel, &tDrlgGrid, nFlags, bSingleRoom, pDrlgMap);

    const unsigned int dwDT1Mask = pDrlgMap->pLvlPrestTxtRecord->dwDt1Mask;
    D2DrlgRoomStrc* pDrlgRoom = 0;
    if (bSingleRoom)
    {
        const int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, 0, 0);
        D2DrlgRoomStrc* pRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
        pRoom->dwDT1Mask = dwDT1Mask;
        pRoom->dwFlags |= nGridFlags;
        pRoom->pDrlgCoord.nPosX = pDrlgMap->pDrlgCoord.nPosX;
        pRoom->pDrlgCoord.nPosY = pDrlgMap->pDrlgCoord.nPosY;
        pRoom->pDrlgCoord.nWidth = pDrlgMap->pDrlgCoord.nWidth;
        pRoom->pDrlgCoord.nHeight = pDrlgMap->pDrlgCoord.nHeight;

        D2DrlgPresetRoomStrc* pDrlgPresetRoom = pRoom->pMaze;
        pDrlgPresetRoom->pMap = pDrlgMap;
        pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
        pDrlgPresetRoom->dwFlags = 1;
        pDrlgPresetRoom->pMazeGrid = 0;

        if (!pDrlgMap->pLvlPrestTxtRecord->dwPopulate)
        {
            pRoom->dwFlags |= 0x800000;
        }

        DRLGROOM_AddRoomExToLevel(pLevel, pRoom);
        pDrlgRoom = pRoom;
    }
    else
    {
        const int nXEnd = pDrlgMap->pDrlgCoord.nPosX + pDrlgMap->pDrlgCoord.nWidth;
        const int nYEnd = pDrlgMap->pDrlgCoord.nPosY + pDrlgMap->pDrlgCoord.nHeight;
        D2DrlgCoordStrc tDrlgCoord = { 0, 0, 0, 0 };
        int nGridY = 0;

        for (int nY = pDrlgMap->pDrlgCoord.nPosY; nY < nYEnd; nY += 8)
        {
            const int nDeltaToEndY = nYEnd - nY;
            tDrlgCoord.nPosY = nY;
            int nGridX = 0;
            for (int nX = pDrlgMap->pDrlgCoord.nPosX; nX < nXEnd; nX += 8)
            {
                const int nDeltaToEndX = nXEnd - nX;
                tDrlgCoord.nPosX = nX;

                tDrlgCoord.nWidth = nDeltaToEndX;
                if (nDeltaToEndX >= 8)
                {
                    tDrlgCoord.nWidth = 8;
                }

                tDrlgCoord.nHeight = nDeltaToEndY;
                if (nDeltaToEndY >= 8)
                {
                    tDrlgCoord.nHeight = 8;
                }

                int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, nGridX, nGridY);
                int nMapFlags = pDrlgMap->pVertices ? DRLGGRID_GetGridEntry(&pDrlgMap->pMapGrid, nGridX, nGridY) : 0;
                if (tDrlgCoord.nWidth && tDrlgCoord.nHeight)
                {
                    pDrlgRoom = DRLGPRESET_InitPresetRoomData(pLevel, pDrlgMap, &tDrlgCoord, dwDT1Mask, nGridFlags, 0, (D2DrlgGridStrc*)nMapFlags);
                }

                ++nGridX;
            }

            ++nGridY;
        }
    }

    DRLGGRID_ResetGrid(&tDrlgGrid);
    return pDrlgRoom;
}
