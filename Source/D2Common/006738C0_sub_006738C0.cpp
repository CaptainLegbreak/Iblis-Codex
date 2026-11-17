struct D2DrlgRoomStrc;
struct D2DrlgLevelStrc;
struct D2DrlgOrthStrc;
struct D2DrlgBuildStrc;
struct D2LvlMazeTxt;

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgOrthStrc
{
    D2DrlgRoomStrc* pRoom;
    int nDirection;
    int bPreset;
    int bInit;
    D2DrlgCoordStrc* pBox;
    D2DrlgOrthStrc* pNext;
};

struct D2RoomPresetStrc
{
    int nLevelPrest;
    int nPickedFile;
    char unk0x08[0x4];
    unsigned int dwFlags;
};

struct D2LvlPrestTxt
{
    int dwDef;
    char unk0x04[0x3C];
    int dwFiles;
};

struct D2DrlgMapStrc
{
    char unk0x00[0x4];
    int nPickedFile;
    D2LvlPrestTxt* pLvlPrestTxtRecord;
};

struct D2DrlgBuildStrc
{
    int nPreset;
    int nDivisor;
    int nRand;
    D2DrlgBuildStrc* pNext;
};

struct D2DrlgPresetInfoStrc
{
    char unk0x00[0x4];
    int nDirection;
};

struct D2DrlgStrc
{
    char unk0x00[0x94];
    int nStaffTombLevel;
    char unk0x98[0x3B8];
    unsigned char nDifficulty;
    char unk0x451[0x27];
    void* pMemPool;
    char unk0x47C[0x4];
    unsigned char nAct;
    char unk0x481[0x3];
    int nBossTombLevel;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x8];
    int nRooms;
    char unk0x0C[0x4];
    D2DrlgRoomStrc* pFirstRoomEx;
    union
    {
        D2LvlMazeTxt* pMaze;
        D2DrlgPresetInfoStrc* pPreset;
    };
    char unk0x18[0x4];
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
    char unk0x2C[0x188];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x8];
    int nLevelType;
    D2SeedStrc pSeed;
    D2DrlgBuildStrc* pBuild;
    int nLevelId;
};

struct D2DrlgRoomStrc
{
    D2DrlgOrthStrc* pDrlgOrth;
    char unk0x04[0x10];
    D2SeedStrc pSeed;
    char unk0x1C[0x4];
    D2RoomPresetStrc* pMaze;
    D2DrlgRoomStrc* pDrlgRoomNext;
    char unk0x28[0xC];
    D2DrlgCoordStrc pDrlgCoord;
    char unk0x44[0x14];
    D2DrlgLevelStrc* pLevel;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                        // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);         // 0x0045C3E0
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed); // 0x00666ED0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom); // 0x00667ED0

// 0x006738C0
static void __stdcall sub_006738C0(D2DrlgMapStrc* pDrlgMap, int nPickedFile, D2DrlgLevelStrc* pLevel);

static void __declspec(noinline) __stdcall sub_006738C0(D2DrlgMapStrc* pDrlgMap, int nPickedFile, D2DrlgLevelStrc* pLevel)
{
    void* pMemPool = pLevel->pDrlg->pMemPool;
    if (nPickedFile != -1)
    {
        pDrlgMap->nPickedFile = nPickedFile;
        return;
    }

    const int nLevelDef = pDrlgMap->pLvlPrestTxtRecord->dwDef;
    const int nFiles = pDrlgMap->pLvlPrestTxtRecord->dwFiles;
    int nLvlPrestId = 0;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLvlPrestId = 52;
        break;

    case 4:
        nLvlPrestId = 108;
        break;

    case 7:
        nLvlPrestId = 167;
        break;

    case 8:
        nLvlPrestId = 205;
        break;

    case 10:
        nLvlPrestId = 257;
        break;

    case 13:
        nLvlPrestId = 301;
        break;

    case 17:
        nLvlPrestId = 413;
        break;

    case 18:
        nLvlPrestId = 481;
        break;

    case 22:
        nLvlPrestId = 753;
        break;

    case 24:
        nLvlPrestId = 664;
        break;

    case 25:
        nLvlPrestId = 704;
        break;

    case 28:
        nLvlPrestId = 836;
        break;

    case 33:
        nLvlPrestId = 1002;
        break;

    case 34:
        nLvlPrestId = 1058;
        break;

    case 35:
        nLvlPrestId = 1052;
        break;

    default:
        nLvlPrestId = nLevelDef;
        break;
    }

    if (nLevelDef > nLvlPrestId && nLevelDef < nLvlPrestId + 16)
    {
        D2DrlgBuildStrc* pDrlgBuild = pLevel->pBuild;
        while (pDrlgBuild)
        {
            if (pDrlgBuild->nPreset == nLevelDef)
            {
                break;
            }
            pDrlgBuild = pDrlgBuild->pNext;
        }

        if (!pDrlgBuild)
        {
            pDrlgBuild = (D2DrlgBuildStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgBuildStrc), ".\\DRLG\\Maze.cpp", 1920, 0);
            memset(pDrlgBuild, 0, sizeof(D2DrlgBuildStrc));
            pDrlgBuild->nPreset = nLevelDef;
            pDrlgBuild->nDivisor = nFiles;
            pDrlgBuild->nRand = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, nFiles);
            pDrlgBuild->pNext = pLevel->pBuild;
            pLevel->pBuild = pDrlgBuild;
        }

        pDrlgBuild->nRand = (pDrlgBuild->nRand + 1) % pDrlgBuild->nDivisor;
        pDrlgMap->nPickedFile = pDrlgBuild->nRand;
    }
}

void __stdcall sub_Emit_00673A60_BuildMazeRoom(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel)
{
    D2RoomPresetStrc* pPreset = pDrlgRoom->pMaze;
    D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;
    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, pPreset->nLevelPrest, pDrlgCoord, &pLevel->pSeed);
    sub_006738C0(pDrlgMap, pPreset->nPickedFile, pLevel);
    DRLGPRESET_BuildArea(pLevel, pDrlgMap, 0, pDrlgCoord->nWidth <= 12 && pDrlgCoord->nHeight <= 12);
}
