#include "D2Common.h"
#include "D2DrlgTiles.h"
#include "D2Drlg.h"

struct D2DrlgOrthStrc
{
    void* pTarget;
    int nDirection;
    int bPreset;
    int bInit;
    D2DrlgCoordStrc* pBox;
    D2DrlgOrthStrc* pNext;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
static __declspec(noinline) int sub_0066B6A0(D2DrlgOrthStrc*, D2DrlgOrthStrc*); // 0x0066B6A0
static __declspec(noinline) void __stdcall sub_0066B720(D2DrlgOrthStrc**, D2DrlgOrthStrc*); // 0x0066B720
// 0x0066B6A0
static int sub_0066B6A0(D2DrlgOrthStrc* pDrlgOrth1, D2DrlgOrthStrc* pDrlgOrth2)
{
    if (pDrlgOrth1->nDirection > pDrlgOrth2->nDirection)
    {
        return 1;
    }

    if (pDrlgOrth1->nDirection == pDrlgOrth2->nDirection)
    {
        switch (pDrlgOrth2->nDirection)
        {
        case 0:
            if (pDrlgOrth1->pBox->nPosY > pDrlgOrth2->pBox->nPosY)
            {
                return 1;
            }
            break;

        case 1:
            if (pDrlgOrth1->pBox->nPosX < pDrlgOrth2->pBox->nPosX)
            {
                return 1;
            }
            break;

        case 2:
            if (pDrlgOrth1->pBox->nPosY < pDrlgOrth2->pBox->nPosY)
            {
                return 1;
            }
            break;

        case 3:
            if (pDrlgOrth1->pBox->nPosX > pDrlgOrth2->pBox->nPosX)
            {
                return 1;
            }
            break;
        }
    }

    return 0;
}

// 0x0066B720
static void __stdcall sub_0066B720(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgOrthStrc* pNew)
{
    if (!*ppDrlgOrth)
    {
        *ppDrlgOrth = pNew;
        return;
    }

    D2DrlgOrthStrc* pNext = (*ppDrlgOrth)->pNext;
    D2DrlgOrthStrc* pPrevious = *ppDrlgOrth;
    if (!pNext)
    {
        if (sub_0066B6A0(pPrevious, pNew))
        {
            pNew->pNext = *ppDrlgOrth;
            *ppDrlgOrth = pNew;
            return;
        }
    }
    else
    {
        do
        {
            if (sub_0066B6A0(pNext, pNew))
            {
                break;
            }

            pPrevious = pNext;
            pNext = pNext->pNext;
        }
        while (pNext);
    }

    pNew->pNext = pNext;
    pPrevious->pNext = pNew;
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

// 0x0066B790
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset)
{
    D2DrlgOrthStrc* pNew = (D2DrlgOrthStrc*)sub_0040B430(pLevel->pDrlg->pMempool, sizeof(D2DrlgOrthStrc), ".\\DRLG\\DrlgRoom.cpp", 351, 0);
    memset(pNew, 0, sizeof(D2DrlgOrthStrc));
    pNew->pTarget = pLevel;
    pNew->nDirection = nDirection;
    pNew->bPreset = bIsPreset;
    pNew->bInit = 0;
    pNew->pBox = &pLevel->pLevelCoords;
    sub_0066B720(ppDrlgOrth, pNew);
}
