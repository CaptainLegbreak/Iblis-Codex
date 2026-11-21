#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DrlgTiles.h"
#include "D2Drlg.h"
#include "D2DrlgPresets.h"

#define DRLGTYPE_OUTDOOR 3
#define DRLGTYPE_PRESET 2
#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))

struct D2DrlgStrc;
struct D2DrlgOrthStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2CoordStrc;
struct D2DrlgCoordStrc;
union D2SeedStrc;
struct D2DrlgLinkStrc;
struct D2DrlgLevelLinkDataStrc;
struct D2LevelDefBin;
struct D2UnkOutdoorStrc3;
struct D2PosStrc;
struct D2OffsetPosStrc;
struct D2UnkPathStrc;
struct D2UnkPathStrc2;
struct D2PathTestStrc;
struct D2PathRayStrc;






void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570
static __declspec(noinline) void __stdcall sub_00675EB0_PlaceCoord(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4);
static __declspec(noinline) void __stdcall sub_00675F80_PlaceCoordCentered(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4);





D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
extern D2DrlgLinkStrc gAct1MonasteryDrlgLink[]; // 0x006F0840
extern D2DrlgLinkStrc gAct2OutdoorDrlgLink[]; // 0x006F0930
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance); // 0x0066B860

struct D2UnkOutdoorStrc3
{
    int nLevelId;
    int nIgnoredLevel1;
    int nIgnoredLevel2;
    int nRand;
    int nNextRand;
    int nFlags;
};

extern D2DrlgLinkStrc gAct2CanyonDrlgLink[15]; // 0x006F0A20
extern D2DrlgLinkStrc gAct5UbersDrlgLink[15]; // 0x006F0B10
extern D2DrlgLinkStrc gAct4OutdoorDrlgLink[15]; // 0x006F0C00
extern D2DrlgLinkStrc gAct4ChaosSanctumDrlgLink[15]; // 0x006F0CF0
extern const D2UnkOutdoorStrc3 stru_6FDD06C0[15]; // 0x006F1258


D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset); // 0x0066B790

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

static __declspec(noinline) int sub_00677870_IsYGreater(const D2PosStrc* pPos1, const D2PosStrc* pPos2);

struct D2UnkPathStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

struct D2UnkPathStrc2
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned char unk0x02;
};

extern const D2UnkPathStrc stru_6FDD2158[25]; // 0x006F1518
extern const D2UnkPathStrc2 byte_6FDD2288[25]; // 0x006F1648


int __stdcall sub_00678C10(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678C10

struct D2PathTestStrc
{
    char unk0x00[0x08];
    D2ActiveRoomStrc* pRoom;
    char unk0x0C[0x18];
    int nUnitSize;
    char unk0x28[0x04];
    int nCollisionMask;
};

struct D2PathRayStrc
{
    unsigned short nStartX;
    unsigned short nStartY;
    unsigned short nTargetX;
    unsigned short nTargetY;
    char unk0x08[0x08];
    int nStepX;
    int nStepY;
    int bValid;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
void __fastcall sub_00678E30(D2PathRayStrc* pRay); // 0x00678E30

// 0x00675600
int __fastcall sub_00675600_LookupTable(int nA, int nB, int nC, int nD, int nE)
{
    if (nA < 0)
    {
        nA -= 2;
    }
    else if (nA > 0)
    {
        nA += 2;
    }

    if (nC < 0)
    {
        nC -= 2;
    }
    else if (nC > 0)
    {
        nC += 2;
    }

    const int nRow = gaLookupRow_006F1088[nA + 9 * (nC + nD) + nB];
    if (nRow == -1)
    {
        return 0;
    }

    if (nE >= 4)
    {
        return gaLookupLarge_006F06F0[nRow - 1][nE - 4];
    }

    return gaLookupSmall_006F0630[nRow - 1][nE];
}

// 0x00675670
void __fastcall DRLGOUTPLACE_SetBlankBorderGridCells(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const D2CoordStrc aOffsets[4][2] = {
        {{  0,  0 }, {  1,  1 }},
        {{  1,  0 }, { -1,  1 }},
        {{  0,  1 }, {  1, -1 }},
        {{  1,  1 }, { -1, -1 }}
    };

    for (int k = 0; k < 4; ++k)
    {
        int nX = aOffsets[k][0].nX;
        if (nX)
        {
            nX = pOutdoor->nGridWidth - 1;
        }

        int nY = aOffsets[k][0].nY;
        if (nY)
        {
            nY = pOutdoor->nGridHeight - 1;
        }

        int nDirX = aOffsets[k][1].nX;
        int nDirY = aOffsets[k][1].nY;

        int i = nX;
        int j = nY;
        while (!(DRLGGRID_GetGridEntry(&pOutdoor->pGrid[2], nX, j) & 1))
        {
            while (!(DRLGGRID_GetGridEntry(&pOutdoor->pGrid[2], i, j) & 1))
            {
                DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], i, j, 0x100, 0);
                i += nDirX;
            }
            j += nDirY;
            i = nX;
        }
    }
}

// 0x00675EB0
static void __stdcall sub_00675EB0_PlaceCoord(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nWidth - pCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += 16;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += 16;
        }
        else if (a4 == 2)
        {
            pCoord->nPosY -= 8;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= 16;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= 16;
        }
        else if (a4 == 2)
        {
            pCoord->nPosY += 8;
        }
        else if (a4 == 3)
        {
            pCoord->nPosY -= 8;
        }
        break;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_00675EB0_Shim(D2DrlgCoordStrc* pCoords, int nCount)
{
    for (int i = 1; i < nCount; ++i)
    {
        sub_00675EB0_PlaceCoord(&pCoords[i - 1], &pCoords[i], i & 3, i & 1);
    }
}

// 0x00675F80
static void __stdcall sub_00675F80_PlaceCoordCentered(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX -= pCoord->nWidth / 2 + 8;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += pCoord->nWidth / 2 + 8;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= pCoord->nHeight / 2 + 8;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += pCoord->nHeight / 2 + 8;
        }
        break;
    case 4:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= pCoord->nWidth / 2 + 8;
        }
        break;
    case 5:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX += pCoord->nWidth / 2 + 8;
        }
        break;
    case 6:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= pCoord->nHeight / 2 + 8;
        }
        break;
    case 7:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += pCoord->nHeight / 2 + 8;
        }
        break;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_00675F80_Shim(D2DrlgCoordStrc* pCoords, int nCount)
{
    for (int i = 1; i < nCount; ++i)
    {
        sub_00675F80_PlaceCoordCentered(&pCoords[i - 1], &pCoords[i], i & 7, i & 1);
    }
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static void __fastcall sub_6FD815E0(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
    switch (a3)
    {
    case 0:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 1:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 2:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 3:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY += pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 4:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 5:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 6:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 7:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY += pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    default:
        return;
    }
}

// 0x006760F0
int __fastcall sub_6FD81330(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }

    D2LevelDefBin* pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(pLevelLinkData->nCurrentLevel);
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosX = pLevelDefBinRecord->dwOffsetX;
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosY = pLevelDefBinRecord->dwOffsetY;

    return 1;
}

// 0x00676AE0
int __fastcall sub_6FD81BF0(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = 0;

    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 7;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        nRand = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 8;

        if (nRand == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    }

    sub_6FD815E0(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 0);

    return 1;
}

static __forceinline void DRLGOUTPLACE_PlaceCoord(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
    switch (a3)
    {
    case 0:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= 16;
        }
        break;

    case 1:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= 16;
        }
        else if (a4 == 2)
        {
            pDrlgCoord2->nPosY += 8;
        }
        break;

    case 2:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += 16;
        }
        break;

    case 3:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight - pDrlgCoord2->nHeight;

        switch (a4)
        {
        case 1:
            pDrlgCoord2->nPosY += 16;
            break;

        case 2:
            pDrlgCoord2->nPosY -= 8;
            break;

        case 3:
            pDrlgCoord2->nPosY += 8;
            break;

        default:
            break;
        }
        break;

    default:
        return;
    }
}

// 0x00676150
int __fastcall sub_00676150_LinkStepDirection(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 3;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int nNext = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 4;
        if (nNext == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nNext;
    }

    DRLGOUTPLACE_PlaceCoord(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 1);

    return 1;
}

// 0x00676280
int __fastcall sub_00676280_PlaceLevelLinkSide(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = 0;

    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 7;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        nRand = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 8;

        if (nRand == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    }

    sub_6FD815E0(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 1);

    return 1;
}

static int gnDrlgLinkFlags_0096D66C; // 0x0096D66C

// 0x00676C00
int __fastcall sub_00676C00_PlaceLevelNextTo(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = 3;
    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];

    const int nLinkedLevel = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    D2DrlgCoordStrc* pDst = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    if (SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1)
    {
        D2DrlgCoordStrc* pSrc = &pLevelLinkData->pLevelCoord[nLinkedLevel];
        switch (pLevelLinkData->nRand[0][pLevelLinkData->nIteration])
        {
        case 0:
            pDst->nPosX = pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight + pSrc->nPosY;
            break;
        case 1:
            pDst->nPosX = pSrc->nPosX - pDst->nWidth;
            pDst->nPosY = pSrc->nPosY;
            break;
        case 2:
            pDst->nPosX = pSrc->nWidth - pDst->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - pDst->nHeight;
            break;
        case 3:
            pDst->nPosX = pSrc->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight - pDst->nHeight + pSrc->nPosY + 8;
            break;
        }
        gnDrlgLinkFlags_0096D66C = 0x800000;
    }
    else
    {
        D2DrlgCoordStrc* pSrc = &pLevelLinkData->pLevelCoord[nLinkedLevel];
        switch (pLevelLinkData->nRand[0][pLevelLinkData->nIteration])
        {
        case 0:
            pDst->nPosX = pSrc->nWidth - pDst->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight + pSrc->nPosY;
            break;
        case 1:
            pDst->nPosX = pSrc->nPosX - pDst->nWidth;
            pDst->nPosY = pSrc->nHeight - pDst->nHeight + pSrc->nPosY;
            break;
        case 2:
            pDst->nPosX = pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - pDst->nHeight;
            break;
        case 3:
            pDst->nPosX = pSrc->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - 8;
            break;
        }
        gnDrlgLinkFlags_0096D66C = 0x400000;
    }

    return 1;
}

int __fastcall sub_Emit_0096D66C()
{
    return gnDrlgLinkFlags_0096D66C;
}

// 0x00676EB0
int __fastcall sub_6FD82130(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    const int nLevelLink = gAct1MonasteryDrlgLink[nIteration].nLevelLink;
    int nCounter = 0;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    int bResult = 1;
    if (nIteration)
    {
        pLevelLinkData->pLevelCoord[0].nHeight += 200;
        pLevelLinkData->pLevelCoord[0].nPosY -= 200;

        bResult = DRLG_CheckNotOverlappingUsingManhattanDistance(pLevelLinkData->pLevelCoord, &pLevelLinkData->pLevelCoord[nCounter], 0);

        pLevelLinkData->pLevelCoord[0].nHeight -= 200;
        pLevelLinkData->pLevelCoord[0].nPosY += 200;
    }

    return bResult;
}

// 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nCounter = 0;
    const int nLevelLink = gAct2OutdoorDrlgLink[nIteration].nLevelLink;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    return 1;
}

// 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct2CanyonDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct5UbersDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct4OutdoorDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677110
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct4ChaosSanctumDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677180
void __fastcall sub_00677180_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand)
{
    if (pLevel->nDrlgType == DRLGTYPE_OUTDOOR)
    {
        D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
        for (int i = 0; i < 15; ++i)
        {
            if (pLevel->eLevelId == stru_6FDD06C0[i].nLevelId || !stru_6FDD06C0[i].nLevelId)
            {
                if (pLevel->eLevelId != stru_6FDD06C0[i].nIgnoredLevel1 && pLevel->eLevelId != stru_6FDD06C0[i].nIgnoredLevel2 && pRand[nIteration] == stru_6FDD06C0[i].nRand)
                {
                    if (pRand[nIteration + 1] == stru_6FDD06C0[i].nNextRand)
                    {
                        pOutdoors->dwFlags |= stru_6FDD06C0[i].nFlags;
                    }
                }
            }
        }
    }
}

#include "gen/data/Source/D2Common/Unknown_00675600.inc"
struct D2ActiveRoomStrc;

// 0x00677640
static __forceinline void sub_00677640_AddOrthToLevel(D2DrlgLevelStrc* pLevel, int nLevelId)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgLevelStrc* pWarpLevel = DRLG_GetLevel(pLevel->pDrlg, nLevelId);
    const int nDirection = DRLG_GetDirectionFromCoordinates(&pLevel->pLevelCoords, &pWarpLevel->pLevelCoords);
    DRLGROOM_AddOrth(&pOutdoors->pRoomData, pWarpLevel, nDirection, pWarpLevel->nDrlgType == DRLGTYPE_PRESET);
}

void __fastcall sub_M293_Emit_00677640(D2DrlgLevelStrc* pLevel, int nLevelId)
{
    sub_00677640_AddOrthToLevel(pLevel, nLevelId);
}

// 0x006777D0
static __declspec(noinline) void __stdcall sub_006777D0_OffsetByDirection(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut)
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

void __stdcall sub_W04_Emit_006777D0(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut)
{
    sub_006777D0_OffsetByDirection(pBase, nDir, nA, nB, pOut);
}

// 0x00677870
static int sub_00677870_IsYGreater(const D2PosStrc* pPos1, const D2PosStrc* pPos2)
{
    return pPos1->nY > pPos2->nY;
}

int __fastcall sub_00677870_Emit(const D2PosStrc* pPos1, const D2PosStrc* pPos2)
{
    return sub_00677870_IsYGreater(pPos1, pPos2);
}

// 0x00678910
D2DrlgLevelStrc* __stdcall sub_00678910(D2DrlgLevelStrc* pLevel)
{
    D2LevelDefBin* pLevelDef;
    D2DrlgLevelStrc* pAdjacentLevel;
    int nSizeX;
    int nSizeY;
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    int nHalfWidth = pLevel->nWidth / 2;
    int nPosY = 0;

    for (int i = 0; i < 5; ++i)
    {
        pLevelDef = DATATBLS_GetLevelDefRecord(79 + i);
        nSizeX = pLevelDef->dwSizeX[pDrlg->nDifficulty];
        nSizeY = pLevelDef->dwSizeY[pDrlg->nDifficulty];
        nPosY -= nSizeY;
        pAdjacentLevel = DRLG_GetLevel(pDrlg, 79 + i);
        const int nOffsetX = nHalfWidth - nSizeX / 2;
        pAdjacentLevel->nPosX = nOffsetX + pLevel->nPosX;
        pAdjacentLevel->nPosY = pLevel->nPosY + nPosY;
        pAdjacentLevel->nWidth = nSizeX;
        pAdjacentLevel->nHeight = nSizeY;
    }

    return pAdjacentLevel;
}

// 0x00678B10
int __fastcall sub_00678B10_GetDistanceEstimate(int nX1, int nY1, int nX2, int nY2)
{
    int nDiffX = nX1 - nX2;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = nY1 - nY2;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    const int nMin = nDiffX < nDiffY ? nDiffX : nDiffY;
    const int nMax = nDiffX > nDiffY ? nDiffX : nDiffY;
    return nMin + 2 * nMax;
}

// 0x00678B80
static int __fastcall sub_6FDAB610(int nX1, int nY1, int nX2, int nY2)
{
    int nAbsDiffX = nX2 - nX1;
    int nAbsDiffY = nY2 - nY1;
    int nDiffX = nAbsDiffX;
    int nDiffY = nAbsDiffY;

    if (nAbsDiffX < 0)
        nAbsDiffX = -nAbsDiffX;
    if (nAbsDiffY < 0)
        nAbsDiffY = -nAbsDiffY;

    if (nAbsDiffX >= 2 * nAbsDiffY)
    {
        if (nDiffY < 0)
            nDiffY = -1;
        else
            nDiffY &= 1;
    }
    else if (nAbsDiffY >= 2 * nAbsDiffX)
    {
        if (nDiffX < 0)
            nDiffX = -1;
        else
            nDiffX &= 1;
    }

    if (nDiffX < -1)
        nDiffX = -2;
    else if (nDiffX > 1)
        nDiffX = 2;

    if (nDiffY < -1)
        nDiffY = -2;
    else if (nDiffY > 1)
        nDiffY = 2;

    return nDiffY + 5 * nDiffX + 12;
}

// 0x00678CB0
int __fastcall sub_00678CB0_GetFirstDirectionXY(int nX1, int nY1, int nX2, int nY2)
{
    return byte_6FDD2288[sub_6FDAB610(nX1, nY1, nX2, nY2)].unk0x00;
}

// 0x00678CF0
int __fastcall sub_6FDAB750(int nX1, int nY1, int nX2, int nY2)
{
    return stru_6FDD2158[sub_6FDAB610(nX1, nY1, nX2, nY2)].unk0x00;
}

// 0x00678D30
void __fastcall sub_00678D30_GetDirectionsXY(int nX1, int nY1, int nX2, int nY2, int* pTestDir)
{
    int nIndex = sub_6FDAB610(nX1, nY1, nX2, nY2);

    pTestDir[0] = stru_6FDD2158[nIndex].unk0x00;
    pTestDir[1] = stru_6FDD2158[nIndex].unk0x04;
    pTestDir[2] = stru_6FDD2158[nIndex].unk0x08;
}

// 0x00678DB0
void __fastcall sub_00678DB0_GetDirectionTripletXY(int nX1, int nY1, int nX2, int nY2, int* pTestDir)
{
    int nIndex = sub_6FDAB610(nX1, nY1, nX2, nY2);

    pTestDir[0] = byte_6FDD2288[nIndex].unk0x00;
    pTestDir[1] = byte_6FDD2288[nIndex].unk0x01;
    pTestDir[2] = byte_6FDD2288[nIndex].unk0x02;
}

// 0x00678C10
int __stdcall sub_00678C10(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nAbsDiffX = pPoint2.X - pPoint1.X;
    int nAbsDiffY = pPoint2.Y - pPoint1.Y;
    int nDiffX = nAbsDiffX;
    int nDiffY = nAbsDiffY;

    if (nAbsDiffX < 0)
    {
        nAbsDiffX = -nAbsDiffX;
    }

    if (nAbsDiffY < 0)
    {
        nAbsDiffY = -nAbsDiffY;
    }

    if (nAbsDiffX >= 2 * nAbsDiffY)
    {
        if (nDiffY < 0)
        {
            nDiffY = -1;
        }
        else
        {
            nDiffY &= 1;
        }
    }
    else if (nAbsDiffY >= 2 * nAbsDiffX)
    {
        if (nDiffX < 0)
        {
            nDiffX = -1;
        }
        else
        {
            nDiffX &= 1;
        }
    }

    if (nDiffX < -1)
    {
        nDiffX = -2;
    }
    else if (nDiffX > 1)
    {
        nDiffX = 2;
    }

    if (nDiffY < -1)
    {
        nDiffY = -2;
    }
    else if (nDiffY > 1)
    {
        nDiffY = 2;
    }

    return nDiffY + 5 * nDiffX + 12;
}

// 0x00678CD0
int __stdcall sub_00678CD0_GetFirstDirection(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    return byte_6FDD2288[sub_00678C10(pPoint1, pPoint2)].unk0x00;
}

// 0x00678D70
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nIndex = sub_00678C10(pPoint1, pPoint2);

    pTestDir[0] = stru_6FDD2158[nIndex].unk0x00;
    pTestDir[1] = stru_6FDD2158[nIndex].unk0x04;
    pTestDir[2] = stru_6FDD2158[nIndex].unk0x08;
}

// 0x00678DF0
void __fastcall sub_00678DF0(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nIndex = sub_00678C10(pPoint1, pPoint2);

    pTestDir[0] = byte_6FDD2288[nIndex].unk0x00;
    pTestDir[1] = byte_6FDD2288[nIndex].unk0x01;
    pTestDir[2] = byte_6FDD2288[nIndex].unk0x02;
}

// 0x00678D10
int __stdcall sub_6FDAB770(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    return stru_6FDD2158[sub_00678C10(tPoint1, tPoint2)].unk0x00;
}

// 0x00678F00
void __fastcall sub_6FDAB810(int* a1, int* a2)
{
    if (*a1 >= 0)
    {
        while (*a1 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a1 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }

    if (*a2 >= 0)
    {
        while (*a2 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a2 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
}

// 0x00678F70
int __fastcall sub_00678F70_TestRay(D2PathTestStrc* pPath, D2PathRayStrc* pRay)
{
    if (!pRay->bValid)
        return 0;

    sub_00678E30(pRay);
    if (!pRay->bValid)
        return 0;

    int nStepX = pRay->nStepX;
    int nStepY = pRay->nStepY;
    if (!nStepX && !nStepY)
        return 0;

    int nX = (pRay->nStartX << 16) + 0x8000;
    int nY = (pRay->nStartY << 16) + 0x8000;
    const int nTargetX = (pRay->nTargetX << 16) + 0x8000;
    const int nTargetY = (pRay->nTargetY << 16) + 0x8000;
    sub_6FDAB810(&nStepX, &nStepY);

    int nStep;
    if (D2_ABS(nStepX) > D2_ABS(nStepY))
        nStep = D2_ABS(nStepX);
    else
        nStep = D2_ABS(nStepY);

    D2ActiveRoomStrc* pRoom = pPath->pRoom;
    const int nUnitSize = pPath->nUnitSize;
    const int nCollisionMask = pPath->nCollisionMask;
    while (1)
    {
        const int nDeltaX = nTargetX - nX;
        if (D2_ABS(nDeltaX) < nStep)
        {
            const int nDeltaY = nTargetY - nY;
            if (D2_ABS(nDeltaY) < nStep)
                break;
        }

        const int nNewX = nX + nStepX;
        const int nNewY = nY + nStepY;
        if ((short)(nX >> 16) != (short)(nNewX >> 16) || (short)(nY >> 16) != (short)(nNewY >> 16))
        {
            if (COLLISION_CheckMaskWithSize(pRoom, (unsigned short)(nNewX >> 16), (unsigned short)(nNewY >> 16), nUnitSize, nCollisionMask))
                return 0;
        }

        nX = nNewX;
        nY = nNewY;
    }

    D2_ASSERT(nX != 0x80008000, 0x1DF);
    D2_ASSERT(nY != 0x80008000, 0x1E0);
    return 1;
}
