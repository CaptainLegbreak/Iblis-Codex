#include "D2LevelIds.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgTiles.h"
#include "D2DrlgPresets.h"

typedef int (__fastcall* DRLGLINKFN)(D2DrlgLevelLinkDataStrc* pLevelLinkData);
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void __cdecl exit(int nCode);                                                                    // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszOutPlaceFile[];                                                                    // 0x006F1500

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
extern "C" void* __cdecl sub_00681EF0_Memset(void* pDst, int nValue, unsigned int nSize);                   // 0x00681EF0


struct D2PosStrc
{
    int nX;
    int nY;
};

struct D2OffsetPosStrc
{
    int nX;
    int nY;
    int nA;
    int nB;
    int nDir;
};

struct D2JungleStrc
{
    D2OffsetPosStrc tCoord;
    int nBranch;
    D2JungleStrc* pBasedOn;
    D2JungleStrc* pBranches[3];
    int nPresetsBlocksX;
    int nPresetsBlocksY;
    int* pJungleDefs;
    int nJungleDefs;
};


struct D2DrlgOrthStrc;



D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                  // 0x00642BB0
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2OffsetPosStrc* pCoord1, D2OffsetPosStrc* pCoord2, int nDistance); // 0x0066B860

extern const int gnSpiderForestPresets[];                                                          // 0x006F13BC
extern const int gnJunglePresets[][4];                                                             // 0x006F13F0

static void __stdcall sub_006777D0_OffsetByDirection(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut); // 0x006777D0

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % (unsigned int)nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

#define SEED_ROLL_LIMITED(pSeed, nMax, nResult) \
    if ((nMax) <= 0) \
    { \
        nResult = 0; \
    } \
    else if (((nMax) - 1) & (nMax)) \
    { \
        nResult = SEED_RollRandomNumber(pSeed) % (unsigned int)(nMax); \
    } \
    else \
    { \
        nResult = SEED_RollRandomNumber(pSeed) & ((nMax) - 1); \
    }

static inline int JUNGLE_ABS(int n)
{
    return n < 0 ? -n : n;
}

static void __stdcall sub_006777D0_OffsetByDirection(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut)
{
    int nDx = 0;
    int nDy = 0;
    switch (nDir)
    {
    case 0:
        nDx = 0;
        nDy = -nB;
        break;

    case 1:
        nDx = -nA;
        nDy = nB / -3;
        break;

    case 2:
        nDx = nA;
        nDy = nB / -3;
        break;

    case 3:
        nDx = -nA;
        nDy = -nB * 2 / 3;
        break;

    case 4:
        nDx = nA;
        nDy = -nB * 2 / 3;
        break;
    }

    pOut->nX = pBase->nX + nDx;
    pOut->nY = pBase->nY + nDy;
    pOut->nA = nA;
    pOut->nB = nB;
    pOut->nDir = nDir;
}

static D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel);

static D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel); // 0x00677880

// build: context DRLG_GenerateJungles
static D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel)
{
    D2LevelDefBin* pLevelDef = DATATBLS_GetLevelDefRecord(LEVEL_SPIDERFOREST);
    int nIdx = 1;
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int nSizeX = pLevelDef->dwSizeX[pDrlg->nDifficulty];
    int nSizeY = pLevelDef->dwSizeY[pDrlg->nDifficulty];
    int nBlocksX = nSizeX / 32;
    int nBlocksY = nSizeY / 32;
    int nMinX = pLevel->nPosX;
    int nMaxY = pLevel->nPosY;
    int nMaxX = nMinX + nSizeX;
    int nMinY = nMaxY - nSizeY;

    D2JungleStrc tJungles[3];
    sub_00681EF0_Memset(tJungles, 0, sizeof(tJungles));

    sub_006777D0_OffsetByDirection((const D2PosStrc*)&pLevel->nPosX, 0, nSizeX, nSizeY, &tJungles[0].tCoord);

    int nJ;
    while (nIdx < 3)
    {
        unsigned int nBaseOn;
        SEED_ROLL_LIMITED(&pDrlg->pSeed, nIdx, nBaseOn);
        sub_006777D0_OffsetByDirection((const D2PosStrc*)&tJungles[nBaseOn].tCoord, SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 5), nSizeX, nSizeY, &tJungles[nIdx].tCoord);

        for (nJ = 0; nJ < nIdx; nJ++)
        {
            if (!DRLG_CheckNotOverlappingUsingManhattanDistance(&tJungles[nJ].tCoord, &tJungles[nIdx].tCoord, 0))
            {
                break;
            }
        }

        if (nJ < nIdx)
        {
            continue;
        }

        tJungles[nBaseOn].pBranches[tJungles[nBaseOn].nBranch] = &tJungles[nIdx];
        tJungles[nIdx].pBasedOn = &tJungles[nBaseOn];
        ++tJungles[nBaseOn].nBranch;
        D2_ASSERT(tJungles[nBaseOn].nBranch <= 3, 0x63E);

        if (nMinX > tJungles[nIdx].tCoord.nX)
        {
            nMinX = tJungles[nIdx].tCoord.nX;
        }
        if (nMinY > tJungles[nIdx].tCoord.nY)
        {
            nMinY = tJungles[nIdx].tCoord.nY;
        }
        if (nMaxX < tJungles[nIdx].tCoord.nX + tJungles[nIdx].tCoord.nA)
        {
            nMaxX = tJungles[nIdx].tCoord.nX + tJungles[nIdx].tCoord.nA;
        }

        ++nIdx;
    }

    D2_ASSERT((nMaxX - nMinX) % 32 == 0, 0x64D);
    D2_ASSERT((nMaxY - nMinY) % 32 == 0, 0x64E);

    int x;
    int y;
    int nColumnSize;
    int nW = (nMaxX - nMinX) / 32 + 2;
    int nH = (nMaxY - nMinY) / 32 + 2;
    int nSize = nH * nW * sizeof(int);

    int* pPreset0 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x658, 0);
    int* pPreset1 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x659, 0);
    int* pPreset2 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x65A, 0);
    int* pLevelPresetId = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x65B, 0);

RESTART:
    sub_00681EF0_Memset(pPreset0, 0, nSize);
    sub_00681EF0_Memset(pPreset1, 0, nSize);
    sub_00681EF0_Memset(pPreset2, 0, nSize);
    sub_00681EF0_Memset(pLevelPresetId, 0, nSize);

    for (nJ = 0; nJ < 3; nJ++)
    {
        int nBY;
        int nBX = (tJungles[nJ].tCoord.nX - nMinX) / 32 + 1;
        nBY = (tJungles[nJ].tCoord.nY - nMinY) / 32 + 1;
        tJungles[nJ].nPresetsBlocksX = nBX;
        tJungles[nJ].nPresetsBlocksY = nBY;
        tJungles[nJ].pJungleDefs = (int*)FOG_AllocPool(pMemPool, nBlocksY * nBlocksX * sizeof(int), gszOutPlaceFile, 0x66F, 0);

        int bOffset;
        if (nJ == 0)
        {
            bOffset = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 2);
        }
        else
        {
            bOffset = (tJungles[nJ].tCoord.nDir % 2) == 1;
        }

        int nAttach;
        do
        {
            for (int y = 0; y < nBlocksY; y++)
            {
                for (int x = 0; x < nBlocksX; x++)
                {
                    pPreset0[(nBY + y) * nW + nBX + x] = nJ + 1;
                    pPreset1[(nBY + y) * nW + nBX + x] = 0;
                    pPreset2[(nBY + y) * nW + nBX + x] = 0;
                    pLevelPresetId[(nBY + y) * nW + nBX + x] = 0;
                }
            }

            x = bOffset + nBX;
            y = nBY + nBlocksY - 1;
            if (nJ != 0)
            {
                pPreset2[nW * y + x] = 1;
                pPreset2[nW * y + x + (bOffset ? -1 : 1)] = 2;
            }

            for (int i = 0; i < tJungles[nJ].nBranch; i++)
            {
                switch (tJungles[nJ].pBranches[i]->tCoord.nDir)
                {
                case 0:
                    pPreset2[nBY * nW + nBX] = 1;
                    break;
                case 1:
                    pPreset2[(nBY + 3) * nW + nBX] = 1;
                    break;
                case 2:
                    pPreset2[(nBY + 3) * nW + nBX + 1] = 1;
                    break;
                case 3:
                    pPreset2[(nBY + 1) * nW + nBX] = 1;
                    break;
                case 4:
                    pPreset2[(nBY + 1) * nW + nBX + 1] = 1;
                    break;
                }
            }

            nAttach = nJ != 0;
            int nStep = 0;
            nColumnSize = 0;
            while (y >= nBY)
            {
                const int nRow = nW * y;
                pPreset1[x + nRow] = (nJ + 1) * 100 + nStep;
                ++nStep;

                if (nColumnSize == 0 || y == nBY || SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 3))
                {
                    ++nColumnSize;
                    if (nColumnSize >= 2 && y > 1)
                    {
                        if (pPreset2[nRow + x + (bOffset ? -1 : 1)] == 0)
                        {
                            ++nAttach;
                            pPreset2[nRow + x + (bOffset ? -1 : 1)] = 2;
                        }
                    }
                    --y;
                }
                else
                {
                    nColumnSize = 0;
                    if (bOffset)
                    {
                        --x;
                        bOffset = 0;
                    }
                    else
                    {
                        ++x;
                        bOffset = 1;
                    }
                }
            }
        }
        while (nAttach < 2);

        int nCount = nAttach;
        while (nCount > 3)
        {
            unsigned int nRemove;
            SEED_ROLL_LIMITED(&pDrlg->pSeed, nCount, nRemove);
            int bFinished = 0;
            nColumnSize = 0;
            for (int y = 0; y < nBlocksY && !bFinished; y++)
            {
                for (int x = 0; x < nBlocksX && !bFinished; x++)
                {
                    if (pPreset2[(nBY + y) * nW + nBX + x] == 2)
                    {
                        if (nRemove == nColumnSize)
                        {
                            pPreset2[(nBY + y) * nW + nBX + x] = 0;
                            bFinished = 1;
                            --nCount;
                        }
                        ++nColumnSize;
                    }
                }
            }
        }
    }

    for (y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {

            const int nP0 = pPreset0[y * nW + x];
            int nLast = 0x7FFFFFFF;
            int nFlags = 0;
            if (pPreset2[y * nW + x] == 1)
            {
                if (pPreset1[(y - 1) * nW + x] && pPreset1[(y - 1) * nW + x] < nLast && pPreset0[(y - 1) * nW + x] == nP0)
                {
                    nFlags = 8;
                    nLast = pPreset1[(y - 1) * nW + x];
                }
                if (pPreset1[(y + 1) * nW + x] && pPreset1[(y + 1) * nW + x] < nLast && pPreset0[(y + 1) * nW + x] == nP0)
                {
                    nFlags = 4;
                    nLast = pPreset1[(y + 1) * nW + x];
                }
                if (pPreset1[y * nW + x + 1] && pPreset1[y * nW + x + 1] < nLast && pPreset0[y * nW + x + 1] == nP0)
                {
                    nFlags = 2;
                    nLast = pPreset1[y * nW + x + 1];
                }
                if (pPreset1[y * nW + x - 1] && pPreset1[y * nW + x - 1] < nLast && pPreset0[y * nW + x - 1] == nP0)
                {
                    nFlags = 1;
                    nLast = pPreset1[y * nW + x - 1];
                }

                if (nFlags & 8)
                {
                    pLevelPresetId[(y - 1) * nW + x] |= 4;
                }
                if (nFlags & 4)
                {
                    pLevelPresetId[(y + 1) * nW + x] |= 8;
                }
                if (nFlags & 2)
                {
                    pLevelPresetId[y * nW + x + 1] |= 1;
                }
                if (nFlags & 1)
                {
                    pLevelPresetId[y * nW + x - 1] |= 2;
                }

                if (pPreset2[(y - 1) * nW + x] == 1 && pPreset0[(y - 1) * nW + x] != nP0)
                {
                    nFlags |= 8;
                }
                if (pPreset2[(y + 1) * nW + x] == 1 && pPreset0[(y + 1) * nW + x] != nP0)
                {
                    nFlags |= 4;
                }
                if (pPreset2[y * nW + x + 1] == 1 && pPreset0[y * nW + x + 1] != nP0)
                {
                    nFlags |= 2;
                }
                if (pPreset2[y * nW + x - 1] == 1 && pPreset0[y * nW + x - 1] != nP0)
                {
                    nFlags |= 1;
                }
            }

            const int nP1 = pPreset1[y * nW + x];
            if (nP1)
            {
                if (JUNGLE_ABS(nP1 - pPreset1[(y - 1) * nW + x]) == 1)
                {
                    nFlags |= 8;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[(y + 1) * nW + x]) == 1)
                {
                    nFlags |= 4;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[y * nW + x + 1]) == 1)
                {
                    nFlags |= 2;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[y * nW + x - 1]) == 1)
                {
                    nFlags |= 1;
                }
            }

            pLevelPresetId[y * nW + x] |= nFlags;
        }
    }

    for (y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {

            const int nP0 = pPreset0[y * nW + x];
            int nLevelPreset = pLevelPresetId[y * nW + x];
            nColumnSize = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 4);
            const int bHadNoPreset = nLevelPreset == 0;
            if (pPreset2[y * nW + x] == 2)
            {
                nJ = 0;
                int bLook = 1;
                for (; nJ < 4 && bLook; nJ++)
                {
                    switch ((nColumnSize + nJ) % 4)
                    {
                    case 0:
                        if (pPreset0[(y - 1) * nW + x] == nP0 && pLevelPresetId[(y - 1) * nW + x] && pLevelPresetId[(y - 1) * nW + x] < 15)
                        {
                            nLevelPreset |= 0x80;
                            bLook = 0;
                        }
                        break;
                    case 1:
                        if (pPreset0[(y + 1) * nW + x] == nP0 && pLevelPresetId[(y + 1) * nW + x] && pLevelPresetId[(y + 1) * nW + x] < 15)
                        {
                            nLevelPreset |= 0x40;
                            bLook = 0;
                        }
                        break;
                    case 2:
                        if (pPreset0[y * nW + x + 1] == nP0 && pLevelPresetId[y * nW + x + 1] && pLevelPresetId[y * nW + x + 1] < 15)
                        {
                            nLevelPreset |= 0x20;
                            bLook = 0;
                        }
                        break;
                    case 3:
                        if (pPreset0[y * nW + x - 1] == nP0 && pLevelPresetId[y * nW + x - 1] && pLevelPresetId[y * nW + x - 1] < 15)
                        {
                            nLevelPreset |= 0x10;
                            bLook = 0;
                        }
                        break;
                    }
                }

                if (!nLevelPreset)
                {
                    goto RESTART;
                }

                if (bHadNoPreset)
                {
                    nJ = 0;
                    bLook = 1;
                    for (; nJ < 4 && bLook; nJ++)
                    {
                        switch ((nColumnSize + nJ) % 4)
                        {
                        case 0:
                            if (pPreset0[(y - 1) * nW + x] != nP0 && pPreset2[(y - 1) * nW + x] == 2)
                            {
                                nLevelPreset |= 0x80;
                                bLook = 0;
                            }
                            break;
                        case 1:
                            if (pPreset0[(y + 1) * nW + x] != nP0 && pPreset2[(y + 1) * nW + x] == 2)
                            {
                                nLevelPreset |= 0x40;
                                bLook = 0;
                            }
                            break;
                        case 2:
                            if (pPreset0[y * nW + x + 1] != nP0 && pPreset2[y * nW + x + 1] == 2)
                            {
                                nLevelPreset |= 0x20;
                                bLook = 0;
                            }
                            break;
                        case 3:
                            if (pPreset0[y * nW + x - 1] != nP0 && pPreset2[y * nW + x - 1] == 2)
                            {
                                nLevelPreset |= 0x10;
                                bLook = 0;
                            }
                            break;
                        }
                    }

                    bLook = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 2) != 0 && bLook;
                    nColumnSize = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 4);

                    for (nJ = 0; nJ < 4 && bLook; nJ++)
                    {
                        switch ((nColumnSize + nJ) % 4)
                        {
                        case 0:
                            if (pLevelPresetId[(y - 1) * nW + x] && pLevelPresetId[(y - 1) * nW + x] < 15 && !(nLevelPreset & 0x80))
                            {
                                nLevelPreset |= 0x80;
                                bLook = 0;
                            }
                            break;
                        case 1:
                            if (pLevelPresetId[(y + 1) * nW + x] && pLevelPresetId[(y + 1) * nW + x] < 15 && !(nLevelPreset & 0x40))
                            {
                                nLevelPreset |= 0x40;
                                bLook = 0;
                            }
                            break;
                        case 2:
                            if (pLevelPresetId[y * nW + x + 1] && pLevelPresetId[y * nW + x + 1] < 15 && !(nLevelPreset & 0x20))
                            {
                                nLevelPreset |= 0x20;
                                bLook = 0;
                            }
                            break;
                        case 3:
                            if (pLevelPresetId[y * nW + x - 1] && pLevelPresetId[y * nW + x - 1] < 15 && !(nLevelPreset & 0x10))
                            {
                                nLevelPreset |= 0x10;
                                bLook = 0;
                            }
                            break;
                        }
                    }
                }

                if (nLevelPreset & 0x80)
                {
                    pLevelPresetId[(y - 1) * nW + x] |= 0x40;
                }
                if (nLevelPreset & 0x40)
                {
                    pLevelPresetId[(y + 1) * nW + x] |= 0x80;
                }
                if (nLevelPreset & 0x20)
                {
                    pLevelPresetId[y * nW + x + 1] |= 0x10;
                }
                if (nLevelPreset & 0x10)
                {
                    pLevelPresetId[y * nW + x - 1] |= 0x20;
                }

                pPreset2[y * nW + x] = 0;
            }

            pLevelPresetId[y * nW + x] |= nLevelPreset;
        }
    }

    for (y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {
            const int nId = pLevelPresetId[y * nW + x];
            int nPDef = nId % 16;
            if (nPDef != 0)
            {
                if (nId >= 16)
                {
                    if (nId & 0x10)
                    {
                        nPDef = gnJunglePresets[nPDef][0];
                    }
                    if (nId & 0x20)
                    {
                        nPDef = gnJunglePresets[nPDef][1];
                    }
                    if (nId & 0x40)
                    {
                        nPDef = gnJunglePresets[nPDef][2];
                    }
                    if (nId & 0x80)
                    {
                        nPDef = gnJunglePresets[nPDef][3];
                    }
                    D2_ASSERT(nPDef != 0, 0x78C);
                }
                else
                {
                    nPDef += 0x211;
                }
            }
            else if (nId >= 16)
            {
                nPDef = gnSpiderForestPresets[nId >> 4];
                D2_ASSERT(nPDef != 0, 0x799);
            }

            pLevelPresetId[y * nW + x] = nPDef;
        }
    }

    for (nJ = 0; nJ < 3; nJ++)
    {
        int nDef = 0;
        for (int by = 0; by < nBlocksY; by++)
        {
            for (int bx = 0; bx < nBlocksX; bx++)
            {
                tJungles[nJ].pJungleDefs[nDef] = pLevelPresetId[(tJungles[nJ].nPresetsBlocksY + by) * nW + bx + tJungles[nJ].nPresetsBlocksX];
                if (tJungles[nJ].pJungleDefs[nDef] > 0x23E)
                {
                    ++tJungles[nJ].nJungleDefs;
                }
                ++nDef;
            }
        }
    }

    int bSwapped;
    do
    {
        bSwapped = 0;
        for (nJ = 0; nJ < 2; nJ++)
        {
            if (tJungles[nJ + 1].tCoord.nY > tJungles[nJ].tCoord.nY)
            {
                D2JungleStrc tTemp = tJungles[nJ + 1];
                tJungles[nJ + 1] = tJungles[nJ];
                tJungles[nJ] = tTemp;
                bSwapped = 1;
            }
        }
    }
    while (bSwapped);

    D2DrlgLevelStrc* pJungleLevel = 0;
    for (nJ = 0; nJ < 3; nJ++)
    {
        pJungleLevel = DRLG_GetLevel(pDrlg, nJ + 76);
        pJungleLevel->pnJungleDefs = tJungles[nJ].pJungleDefs;
        pJungleLevel->nJungleDefs = tJungles[nJ].nJungleDefs;
        pJungleLevel->nPosX = tJungles[nJ].tCoord.nX;
        pJungleLevel->nPosY = tJungles[nJ].tCoord.nY;
        pJungleLevel->nWidth = tJungles[nJ].tCoord.nA;
        pJungleLevel->nHeight = tJungles[nJ].tCoord.nB;
    }

    FOG_FreePool(pMemPool, pPreset0, gszOutPlaceFile, 0x7D2, 0);
    FOG_FreePool(pMemPool, pPreset1, gszOutPlaceFile, 0x7D3, 0);
    FOG_FreePool(pMemPool, pPreset2, gszOutPlaceFile, 0x7D4, 0);
    FOG_FreePool(pMemPool, pLevelPresetId, gszOutPlaceFile, 0x7D5, 0);

    return pJungleLevel;
}

struct D2DrlgLevelLinkDataStrc;



struct D2DrlgWarpStrc;

typedef int (__fastcall* LINKFN)(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);
typedef void (__fastcall* FLAGFN)(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand);

#define DRLGTYPE_PRESET 2
#define DRLGTYPE_OUTDOOR 3
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                    // 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nShift);      // 0x00642920
int __fastcall DRLG_CheckOverlappingWithOrthogonalMargin(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMargin); // 0x0066B880
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                        // 0x0066AEC0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset);

int __fastcall sub_00676DD0_LinkAct1Wilderness(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);    // 0x00676DD0
int __fastcall sub_6FD82130(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);                       // 0x00676EB0
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);      // 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);        // 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);         // 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);      // 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);  // 0x00677110
void __fastcall sub_00677180_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand);      // 0x00677180

extern D2DrlgLinkStrc gAct1WildernessDrlgLink[15];                                                          // 0x006F0750
extern D2DrlgLinkStrc gAct1MonasteryDrlgLink[15];                                                           // 0x006F0840
extern D2DrlgLinkStrc gAct2OutdoorDrlgLink[15];                                                             // 0x006F0930
extern D2DrlgLinkStrc gAct2CanyonDrlgLink[15];                                                              // 0x006F0A20
extern D2DrlgLinkStrc gAct5UbersDrlgLink[15];                                                               // 0x006F0B10
extern D2DrlgLinkStrc gAct4OutdoorDrlgLink[15];                                                             // 0x006F0C00
extern D2DrlgLinkStrc gAct4ChaosSanctumDrlgLink[15];                                                        // 0x006F0CF0
extern D2DrlgLinkStrc gAct5OutdoorDrlgLink[15];
extern D2DrlgLinkStrc gAct5TundraDrlgLink[15];
// build: symbol ?gnDrlgLinkFlags@* 0x0096D66C
extern int gnDrlgLinkFlags;

static inline unsigned int SEED_RollRandomNumber_Links(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

void __stdcall sub_006772C0_InitLevelLinks(D2DrlgLinkStrc* pDrlgLink, LINKFN pfLink, FLAGFN pfFlag, D2DrlgStrc* pDrlg); // 0x006772C0

static void __stdcall sub_006775C0_SetOverlapWarps(int nStartId, int nEndId, D2DrlgStrc* pDrlg); // 0x006775C0
// 0x006772C0
static void __stdcall sub_006772C0_InitLevelLinks(D2DrlgLinkStrc* pDrlgLink, LINKFN pfLink, FLAGFN pfFlag, D2DrlgStrc* pDrlg)
{
    D2DrlgLevelLinkDataStrc pLevelLinkData = {};
    D2LevelDefBin* pLevelDefBinRecord = 0;
    D2DrlgPresetInfoStrc* pPresetInfo = 0;
    D2DrlgLevelStrc* pLevel = 0;
    D2DrlgLinkStrc* pLink;
    int nLevelId = 0;
    int nCounter = 0;
    int nVisEx = 0;
    int nVis = 0;

    for (int i = 0; i < 15; ++i)
    {
        pLevelLinkData.nRand[2][i] = -1;
        pLevelLinkData.nRand[3][i] = -1;
        pLevelLinkData.nRand[0][i] = -1;
        pLevelLinkData.nRand[1][i] = -1;
    }

    pLevelLinkData.pLink = pDrlgLink;
    pLevelLinkData.pSeed = pDrlg->pSeed;

    for (int i = 0; pDrlgLink[i].nLevel; ++i)
    {
        pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(pDrlgLink[i].nLevel);

        pLevelLinkData.pLevelCoord[i].nWidth = pLevelDefBinRecord->dwSizeX[pDrlg->nDifficulty];
        pLevelLinkData.pLevelCoord[i].nHeight = pLevelDefBinRecord->dwSizeY[pDrlg->nDifficulty];
    }

    nCounter = 0;
    pLink = pDrlgLink;
    while (pLink->nLevel)
    {
        pLevelLinkData.nIteration = nCounter;
        pLevelLinkData.nCurrentLevel = pLink->nLevel;

        if (!((DRLGLINKFN)pLink->pfLinker)(&pLevelLinkData))
        {
            pLevelLinkData.nRand[2][nCounter] = -1;
            pLevelLinkData.nRand[3][nCounter] = -1;
            pLevelLinkData.nRand[0][nCounter] = -1;
            pLevelLinkData.nRand[1][nCounter] = -1;

            --nCounter;
        }
        else if (!pfLink || pfLink(&pLevelLinkData, nCounter))
        {
            ++nCounter;
        }

        pLink = &pDrlgLink[nCounter];
    }

    nCounter = 0;
    pLink = pDrlgLink;
    while (pLink->nLevel)
    {
        nLevelId = pLink->nLevel;

        if (pLink->nLevelLink == -1)
        {
            nVis = 0;
        }
        else
        {
            nVis = pDrlgLink[pLink->nLevelLink].nLevel;
        }

        if (pLink->nLevelLinkEx == -1)
        {
            nVisEx = 0;
        }
        else
        {
            nVisEx = pDrlgLink[pLink->nLevelLinkEx].nLevel;
        }

        pLevel = DRLG_GetLevel(pDrlg, nLevelId);

        pLevel->pLevelCoords = pLevelLinkData.pLevelCoord[nCounter];

        if (pLevel->nDrlgType == DRLGTYPE_PRESET)
        {
            pPresetInfo = pLevel->pPreset;
            switch (pLevel->eLevelId)
            {
            case 1:
                pPresetInfo->nDirection = pLevelLinkData.nRand[0][nCounter];
                break;
            case 0x28:
                pPresetInfo->nDirection = pLevelLinkData.nRand[0][nCounter + 1];
                break;
            }
        }

        if (pLevel->eLevelId == LEVEL_BLACKMARSH)
        {
            D2DrlgLevelStrc* pOuterLevel = DRLG_GetLevel(pDrlg, LEVEL_OUTERCLOISTER);
            pPresetInfo = pOuterLevel->pPreset;
            switch (pLevelLinkData.nRand[0][nCounter])
            {
            case 1:
                pPresetInfo->nDirection = ((unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1) ? 1 : 2;
                break;
            case 3:
                pPresetInfo->nDirection = ~(unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1;
                break;
            }
        }

        if (pfFlag)
        {
            pfFlag(pLevel, nCounter, pLevelLinkData.nRand[0]);
        }

        if (pDrlg->nAct != 4)
        {
            if (nVis)
            {
                D2DrlgWarpStrc* pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                D2DrlgWarpStrc* pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVis);
                DRLG_SetWarpId(pDrlgWarp1, nVis, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }

            if (nVisEx)
            {
                D2DrlgWarpStrc* pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                D2DrlgWarpStrc* pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVisEx);
                DRLG_SetWarpId(pDrlgWarp1, nVisEx, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }
        }

        ++nCounter;
        pLink = &pDrlgLink[nCounter];
    }
}

// 0x006775C0
static void __stdcall sub_006775C0_SetOverlapWarps(int nStartId, int nEndId, D2DrlgStrc* pDrlg)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);
        D2DrlgWarpStrc* pDrlgWarp = DRLG_GetDrlgWarpFromLevelId(pDrlg, i);

        for (int j = nStartId; j <= nEndId; ++j)
        {
            if (i != j)
            {
                D2DrlgLevelStrc* pOtherLevel = DRLG_GetLevel(pDrlg, j);
                if (DRLG_CheckOverlappingWithOrthogonalMargin(&pLevel->pLevelCoords, &pOtherLevel->pLevelCoords, -1))
                {
                    DRLG_SetWarpId(pDrlgWarp, j, -1, -1);
                }
            }
        }
    }
}

void sub_00677640_AddOrthToLevel(D2DrlgLevelStrc* pLevel, int nLevelId); // 0x00677640

static void __stdcall sub_00677680_AddLevelOrths(D2DrlgStrc* pDrlg, int nEndId, int nStartId); // 0x00677680

// build: context sub_00677680_AddLevelOrths
static void __stdcall sub_00677680_AddLevelOrths(D2DrlgStrc* pDrlg, int nEndId, int nStartId)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);

        if (pLevel->nDrlgType == DRLGTYPE_OUTDOOR)
        {
            int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, i);
            int* pWarpIdArray = DRLGWARP_GetWarpIdArrayFromLevelId(pDrlg, i);

            for (int j = 0; j < 8; ++j)
            {
                if (pVisArray[j] && pWarpIdArray[j] == -1)
                {
                    sub_00677640_AddOrthToLevel(pLevel, pVisArray[j]);
                }
            }
        }
    }
}

static void sub_00677750_CreateAct1LevelConnections(D2DrlgStrc* pDrlg);
static void sub_00677750_CreateAct1LevelConnections(D2DrlgStrc* pDrlg); // 0x00677750
// 0x00677750
static void sub_00677750_CreateAct1LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct1WildernessDrlgLink, sub_00676DD0_LinkAct1Wilderness, sub_00677180_SetAct1OutdoorFlags, pDrlg);
    sub_006772C0_InitLevelLinks(gAct1MonasteryDrlgLink, sub_6FD82130, sub_00677180_SetAct1OutdoorFlags, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 0x11, 1);
}

static void sub_00677790_CreateAct2LevelConnections(D2DrlgStrc* pDrlg);
static void sub_00677790_CreateAct2LevelConnections(D2DrlgStrc* pDrlg); // 0x00677790
// 0x00677790
static void sub_00677790_CreateAct2LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct2OutdoorDrlgLink, DRLGOUTPLACE_LinkAct2Outdoors, 0, pDrlg);
    sub_006772C0_InitLevelLinks(gAct2CanyonDrlgLink, DRLGOUTPLACE_LinkAct2Canyon, 0, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 0x2E, 0x28);
}

static void sub_00678A20_CreateAct4LevelConnections(D2DrlgStrc* pDrlg);
static void sub_00678A20_CreateAct4LevelConnections(D2DrlgStrc* pDrlg); // 0x00678A20

// build: context sub_00678A20_CreateAct4LevelConnections
static void sub_00678A20_CreateAct4LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct4OutdoorDrlgLink, DRLGOUTPLACE_LinkAct4Outdoors, 0, pDrlg);
    sub_006772C0_InitLevelLinks(gAct4ChaosSanctumDrlgLink, DRLGOUTPLACE_LinkAct4ChaosSanctum, 0, pDrlg);

    DRLG_GetLevel(pDrlg, LEVEL_OUTERSTEPPES)->pOutdoors->dwFlags |= gnDrlgLinkFlags;

    sub_00677680_AddLevelOrths(pDrlg, 0x6A, 0x67);
}

static void sub_00678A70_CreateAct5LevelConnections(D2DrlgStrc* pDrlg);
static void sub_00678A70_CreateAct5LevelConnections(D2DrlgStrc* pDrlg); // 0x00678A70

// build: context sub_00678A70_CreateAct5LevelConnections
static void sub_00678A70_CreateAct5LevelConnections(D2DrlgStrc* pDrlg)
{
    sub_006772C0_InitLevelLinks(gAct5OutdoorDrlgLink, 0, 0, pDrlg);
    sub_006772C0_InitLevelLinks(gAct5TundraDrlgLink, 0, 0, pDrlg);

    sub_006775C0_SetOverlapWarps(0x6F, 0x70, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 0x70, 0x6F);

    sub_006775C0_SetOverlapWarps(0x6E, 0x6F, pDrlg);
    sub_006775C0_SetOverlapWarps(0x6D, 0x6E, pDrlg);

    sub_006772C0_InitLevelLinks(gAct5UbersDrlgLink, DRLGOUTPLACE_LinkAct5Ubers, 0, pDrlg);
}

D2DrlgLevelStrc* __stdcall sub_00678910_PlaceKurastLevels(D2DrlgLevelStrc* pLevel); // 0x00678910
D2DrlgLevelStrc* __stdcall sub_00678910_PlaceKurastLevels(D2DrlgLevelStrc* pLevel); // 0x00678910


static void sub_006789B0_CreateAct3LevelConnections(D2DrlgStrc* pDrlg);
// 0x006789B0
static void sub_006789B0_CreateAct3LevelConnections(D2DrlgStrc* pDrlg)
{
    D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, LEVEL_KURASTDOCKTOWN);
    D2LevelDefBin* pDef = DATATBLS_GetLevelDefRecord(LEVEL_KURASTDOCKTOWN);
    pLevel->nPosX = pDef->dwOffsetX;
    pLevel->nPosY = pDef->dwOffsetY;
    pLevel->nWidth = pDef->dwSizeX[pDrlg->nDifficulty];
    pLevel->nHeight = pDef->dwSizeY[pDrlg->nDifficulty];
    pLevel = DRLG_GenerateJungles(pLevel);
    sub_00678910_PlaceKurastLevels(pLevel);
    sub_006775C0_SetOverlapWarps(75, 83, pDrlg);
    sub_00677680_AddLevelOrths(pDrlg, 83, 75);
}

// 0x00678AD0
void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg, unsigned char nAct)
{
    switch (nAct)
    {
    case 0: sub_00677750_CreateAct1LevelConnections(pDrlg); break;
    case 1: sub_00677790_CreateAct2LevelConnections(pDrlg); break;
    case 2: sub_006789B0_CreateAct3LevelConnections(pDrlg); break;
    case 3: sub_00678A20_CreateAct4LevelConnections(pDrlg); break;
    case 4: sub_00678A70_CreateAct5LevelConnections(pDrlg); break;
    }
}
