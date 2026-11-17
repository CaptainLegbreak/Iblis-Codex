struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2DrlgStrc
{
    char unk0x000[0x450];
    unsigned char nDifficulty;
};

struct D2LevelDefBin
{
    char unk0x00[0x0C];
    int dwSizeX[3];
    int dwSizeY[3];
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1B4];
    D2DrlgStrc* pDrlg;
    int nJungleDefs;
    int* pJungleDefs;
    char unk0x1C0[0x04];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int nLevelId;
};

#define LEVEL_SPIDERFOREST 76
#define LEVEL_GREATMARSH 77
#define LEVEL_FLAYERJUNGLE 78
#define LVLPREST_ACT3_JUNGLE_HEAD 573
#define LVLPREST_ACT3_JUNGLE_TAIL 574

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0

extern const int gnJungleDefOffsets_006F2370[3];                                                            // 0x006F2370
extern const int gnJungleFiles_006F2328[18];                                                                // 0x006F2328

// 0x0067E910
void __fastcall DRLGOUTJUNG_BuildJungle(D2DrlgLevelStrc* pLevel)
{
    switch (pLevel->nLevelId)
    {
    case LEVEL_SPIDERFOREST:
    case LEVEL_GREATMARSH:
    case LEVEL_FLAYERJUNGLE:
    {
        D2LevelDefBin* pLevelDefBin = DATATBLS_GetLevelDefRecord(LEVEL_SPIDERFOREST);
        const int nSizeX = pLevelDefBin->dwSizeX[pLevel->pDrlg->nDifficulty] / 32;
        const int nSizeY = pLevelDefBin->dwSizeY[pLevel->pDrlg->nDifficulty] / 32;
        int nDefId = 0;

        const int nRand = SEED_RollLimitedRandomNumber(&pLevel->pSeed, 4 * (pLevel->nJungleDefs == 3) + 2);
        int nFileIndex = 0;

        D2_ASSERT(pLevel->pJungleDefs, 0x27);

        for (int i = 0; i < nSizeY; ++i)
        {
            if (pLevel->nLevelId == LEVEL_SPIDERFOREST && i == nSizeY - 1)
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 4 * i, LVLPREST_ACT3_JUNGLE_HEAD, pLevel->pJungleDefs[nSizeX * nSizeY - 1] == 0, 0);
                nDefId += 2;
            }
            else if (pLevel->nLevelId == LEVEL_FLAYERJUNGLE && i == 0)
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, LVLPREST_ACT3_JUNGLE_TAIL, pLevel->pJungleDefs[1] == 0, 0);
                nDefId += 2;
            }
            else
            {
                for (int j = 0; j < nSizeX; ++j)
                {
                    int nJungleDef = pLevel->pJungleDefs[nDefId++];
                    int nPickedFile = -1;
                    if (nJungleDef > LVLPREST_ACT3_JUNGLE_TAIL)
                    {
                        D2_ASSERT(nFileIndex < 3, 0x47);

                        nJungleDef += gnJungleDefOffsets_006F2370[pLevel->nLevelId - LEVEL_SPIDERFOREST];
                        nPickedFile = gnJungleFiles_006F2328[nFileIndex + 3 * nRand];
                        ++nFileIndex;
                    }

                    if (nJungleDef)
                    {
                        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 4 * j, 4 * i, nJungleDef, nPickedFile, 0);
                    }
                }
            }
        }
        break;
    }
    }
}

#include "gen/data/Source/D2Common/0067E910_DRLGOUTJUNG_BuildJungle.inc"
