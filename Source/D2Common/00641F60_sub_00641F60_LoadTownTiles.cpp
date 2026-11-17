struct D2TileLibraryHeaderStrc;

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x1C];
    D2DrlgCoordStrc pLevelCoords;
    char unk0x2C[0x180];
    D2DrlgLevelStrc* pNextLevel;
    char unk0x1B0[0x20];
    int nLevelId;
};

struct D2DrlgStrc
{
    char unk0x00[0x0C];
    D2TileLibraryHeaderStrc* pTiles[32];
    char unk0x8C[0x3F0];
    D2DrlgLevelStrc* pLevel;
    unsigned char nAct;
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDst, const char* szFormat, ...);           // 0x006CC468
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118

void __stdcall DT1_ListAdd(D2TileLibraryHeaderStrc** ppList, const char* szFilePath);                      // 0x00604A40
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoord, int nX, int nY);                    // 0x0066B980

#define ACT_I 0
#define ACT_II 1
#define ACT_III 2
#define MAX_PATH 260

// 0x00641F60
void __fastcall sub_00641F60_LoadTownTiles(D2DrlgStrc* pDrlg)
{
    char szPath[MAX_PATH] = { 0 };
    switch (pDrlg->nAct)
    {
    case ACT_I:
        wsprintfA(szPath, "%s\\Tiles\\Act1\\Town\\Floor.dt1", szDataGlobal_006D4118);
        break;

    case ACT_II:
        wsprintfA(szPath, "%s\\Tiles\\Act2\\Town\\Ground.dt1", szDataGlobal_006D4118);
        break;

    case ACT_III:
        wsprintfA(szPath, "%s\\Tiles\\ACT3\\Kurast\\sets.dt1", szDataGlobal_006D4118);
        break;

    default:
        return;
    }

    DT1_ListAdd(pDrlg->pTiles, szPath);
}

// 0x006427A0
int __fastcall sub_006427A0_GetLevelIdFromCoordinates(D2DrlgStrc* pDrlg, int nX, int nY)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pLevel->pLevelCoords, nX, nY))
        {
            return pLevel->nLevelId;
        }
    }

    return 0;
}
