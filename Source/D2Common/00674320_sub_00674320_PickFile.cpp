struct D2DrlgGridStrc
{
    int* pCellsFlags;
    int* pCellsRowOffsets;
    int nWidth;
    int nHeight;
    int field_10;
};
struct D2DrlgOutdoorInfoStrc
{
    int field_00;
    D2DrlgGridStrc tGrid04;
    char pad_after_grid[20];
    D2DrlgGridStrc tGridFlags;
};
struct D2SeedStrc
{
    unsigned int dwLow;
    unsigned int dwHigh;
};
struct D2OutdoorPresetFileStrc
{
    int f_0;
    int nFiles;
    int nPickedFile;
    D2OutdoorPresetFileStrc* pNext;
};
struct D2DrlgDrlgStrc
{
    char pad_00[1144];
    void* pMemPool;
};
struct D2DrlgLevelStrc
{
    char pad_00[20];
    D2DrlgOutdoorInfoStrc* pOutdoor;
    char pad_after_outdoor[412];
    D2DrlgDrlgStrc* pDrlg;
    char pad_after_drlg[12];
    D2SeedStrc tSeed;
    D2OutdoorPresetFileStrc* pPresetFiles;
};
struct D2LvlPrestRecordStrc
{
    int f_0;
    char pad_04[60];
    int nFiles;
};
extern D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0
extern void* __fastcall sub_0040B430(void* pPool, int nSize, const char* szFile, int nLine, int nZero); // 0x0040B430
extern int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc* pSeed, int nLimit); // 0x0045C3E0
extern int __fastcall sub_00666FD0_PresetWidth(int nPresetId); // 0x00666FD0
extern int __fastcall sub_00666FE0_PresetHeight(int nPresetId); // 0x00666FE0
extern void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

// 0x00674320
static __declspec(noinline) int __cdecl sub_00674320_PickFile(D2DrlgLevelStrc* pLevel, int nPresetId)
{
    void* pMemPool = pLevel->pDrlg->pMemPool;
    D2OutdoorPresetFileStrc* pFile = pLevel->pPresetFiles;
    while (pFile)
    {
        if (pFile->f_0 == nPresetId)
            break;
        pFile = pFile->pNext;
    }
    if (!pFile)
    {
        D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(nPresetId);
        pFile = (D2OutdoorPresetFileStrc*)sub_0040B430(pMemPool, sizeof(D2OutdoorPresetFileStrc), ".\\DRLG\\Outdoors.cpp", 249, 0);
        memset(pFile, 0, sizeof(D2OutdoorPresetFileStrc));
        pFile->f_0 = pRecord->f_0;
        pFile->nFiles = pRecord->nFiles;
        pFile->nPickedFile = sub_0045C3E0_RollLimited(&pLevel->tSeed, pRecord->nFiles);
        pFile->pNext = pLevel->pPresetFiles;
        pLevel->pPresetFiles = pFile;
    }
    pFile->nPickedFile = (pFile->nPickedFile + 1) % pFile->nFiles;
    return pFile->nPickedFile;
}

// 0x006743C0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoor;
    const int nWidth = sub_00666FD0_PresetWidth(nPresetId) / 8;
    const int nHeight = sub_00666FE0_PresetHeight(nPresetId) / 8;
    if (nPickedFile == -1)
        nPickedFile = sub_00674320_PickFile(pLevel, nPresetId);
    for (int y = nY; y < nY + nHeight; ++y)
    {
        for (int x = nX; x < nX + nWidth; ++x)
        {
            DRLGGRID_AlterGridFlag(&pOutdoor->tGridFlags, x, y, 983040, 5);
            DRLGGRID_AlterGridFlag(&pOutdoor->tGridFlags, x, y, (nPickedFile << 16) | 512, 0);
            if (bFlag && ((nPresetId >= 4 && nPresetId <= 15) || (unsigned int)(nPresetId - 364) <= 11))
                DRLGGRID_AlterGridFlag(&pOutdoor->tGridFlags, x, y, 1, 0);
            DRLGGRID_AlterGridFlag(&pOutdoor->tGrid04, x, y, 0, 3);
        }
    }
    DRLGGRID_AlterGridFlag(&pOutdoor->tGrid04, nX, nY, nPresetId, 3);
}
