#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgPresets.h"
typedef unsigned __int64 uint64_t;

static inline uint64_t SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    uint64_t lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static inline void sub_6FD81430(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
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

static inline void sub_6FD81850(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
	switch (a3)
	{
	case 0:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth - pDrlgCoord2->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosX += 16;
		}
		break;

	case 1:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight - pDrlgCoord2->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosY += 16;
		}
		else if (a4 == 2)
		{
			pDrlgCoord2->nPosY -= 8;
		}
		break;

	case 2:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosX -= 16;
		}
		break;

	case 3:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;

		switch (a4)
		{
		case 1:
			pDrlgCoord2->nPosY -= 16;
			break;

		case 2:
			pDrlgCoord2->nPosY += 8;
			break;

		case 3:
			pDrlgCoord2->nPosY -= 8;
			break;
		default:
			break;
		}
		break;

	default:
		return;
	}
}

// 0x006769A0
int __fastcall sub_6FD81B30(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = 0;

    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = (SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1) + 1;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        nRand = pLevelLinkData->nRand[0][pLevelLinkData->nIteration] != 1 ? 1 : 2;

        if (nRand == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    }

    D2DrlgCoordStrc* pDrlgCoord1 = &pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink];
    D2DrlgCoordStrc* pDrlgCoord2 = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    const int nDirection = pLevelLinkData->nRand[0][pLevelLinkData->nIteration];
    if (nDirection == 1)
    {
        sub_6FD81430(pDrlgCoord1, pDrlgCoord2, 1, 0);
    }
    else
    {
        sub_6FD81850(pDrlgCoord1, pDrlgCoord2, nDirection, 0);
    }

    return 1;
}
