struct D2GameStrc;
struct D2DrlgStrc;
struct D2DrlgEnvironmentStrc;
struct D2DrlgActStrc;
typedef void (__stdcall* AUTOMAPFN)(void* pRoom);
typedef void (__stdcall* TOWNAUTOMAPFN)(int nLevelId, int nPickedFile, int nX, int nY);

struct D2DrlgActStrc
{
    int unk0x00;
    D2DrlgEnvironmentStrc* pEnvironment;
    int nTownId;
    unsigned int dwInitSeed;
    int unk0x10;
    unsigned char nAct;
    char pad0x15[3];
    void* pTileData[12];
    D2DrlgStrc* pDrlg;
    int unk0x4C;
    int bClient;
    int unk0x54[2];
    void* pMemPool;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2DrlgStrc* __fastcall DRLG_AllocDrlg(D2DrlgActStrc* pAct, unsigned char nActNo, void* hArchive, unsigned int nInitSeed, int nTownLevelId, unsigned int nFlags, D2GameStrc* pGame, unsigned char nDifficulty, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x00642DA0
D2DrlgEnvironmentStrc* __fastcall ENVIRONMENT_AllocDrlgEnvironment(void* pMemPool);                        // 0x0061BE40
void __fastcall DRLGANIM_InitCache(D2DrlgStrc* pDrlg, void** ppTileData);                                   // 0x00642A30

// 0x006194A0
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap)
{
    D2DrlgActStrc* pAct = (D2DrlgActStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgActStrc), ".\\DUNGEON\\Dungeon.cpp", 0x19, 0);
    memset(pAct, 0, sizeof(D2DrlgActStrc));

    pAct->dwInitSeed = nInitSeed;
    pAct->bClient = bClient;
    pAct->nAct = nAct;
    pAct->pMemPool = pMemPool;

    if (bClient)
    {
        pAct->pDrlg = DRLG_AllocDrlg(pAct, nAct, 0, nInitSeed, 0, 1, pGame, nDifficulty, pfAutoMap, pfTownAutoMap);
    }
    else
    {
        pAct->nTownId = nTownLevelId;
        pAct->pDrlg = DRLG_AllocDrlg(pAct, nAct, 0, nInitSeed, nTownLevelId, 0, pGame, nDifficulty, pfAutoMap, pfTownAutoMap);
    }

    pAct->pEnvironment = ENVIRONMENT_AllocDrlgEnvironment(pMemPool);
    DRLGANIM_InitCache(pAct->pDrlg, pAct->pTileData);
    return pAct;
}
