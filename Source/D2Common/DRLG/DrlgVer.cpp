#include "D2Drlg.h"
struct D2DrlgCoordStrc;
struct D2DrlgCoordsStrc;
struct D2DrlgVertexStrc;
struct D2DrlgOrthStrc;


struct D2DrlgVertexStrc
{
    int nPosX;
    int nPosY;
    unsigned char nDirection;
    unsigned int dwFlags;
    D2DrlgVertexStrc* pNext;
};

struct D2DrlgOrthStrc
{
    void* pRoom;
    int nDirection;
    int bInit;
    int unk0x0C;
    D2DrlgCoordsStrc* pCoords;
    D2DrlgOrthStrc* pNext;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void __stdcall sub_0067CE20(void* pMemPool, D2DrlgVertexStrc* pCurrentVertex, D2DrlgCoordStrc* pDrlgCoord, unsigned char nDirection, D2DrlgOrthStrc* pCurrentRoomData); // 0x0067CE20
D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection);
static void __stdcall sub_0067CE00_MarkVertex(D2DrlgVertexStrc* pVertex, int bInit);
static void __fastcall sub_0067D030(D2DrlgCoordsStrc* pCoords, D2DrlgVertexStrc* pFirst);
void __fastcall sub_0067D050(void* pMemPool, D2DrlgVertexStrc** ppVertex, D2DrlgCoordsStrc* pCoords, unsigned char nDirection, D2DrlgOrthStrc* pOrth);
void __fastcall sub_0067D250(D2DrlgVertexStrc** ppVertex);
void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY);

// build: symbol ?DRLGVER_AllocVertex@@YIPAUD2DrlgVertexStrc@@PAXE@Z 0x0067CDD0
D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection)
{
    D2DrlgVertexStrc* pVertex = (D2DrlgVertexStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgVertexStrc), ".\\DRLG\\DrlgVer.cpp", 19, 0);
    memset(pVertex, 0, sizeof(D2DrlgVertexStrc));
    pVertex->nDirection = nDirection;
    return pVertex;
}

// 0x0067CE00
static void __stdcall sub_0067CE00_MarkVertex(D2DrlgVertexStrc* pVertex, int bInit)
{
    pVertex->dwFlags |= 1;
    if (bInit)
    {
        pVertex->dwFlags |= 2;
    }
}

// build: context sub_0067CE20
void __stdcall sub_0067CE20(void* pMemPool, D2DrlgVertexStrc* pVertex, D2DrlgCoordsStrc* pDefaultCoords, unsigned char nDirection, D2DrlgOrthStrc* pOrth)
{
    D2DrlgVertexStrc* pVertex1 = pVertex->pNext;
    D2DrlgVertexStrc* pVertex2 = pVertex1->pNext;
    D2DrlgVertexStrc* pVertex3 = pVertex2->pNext;

    for (; pOrth; pOrth = pOrth->pNext)
    {
        D2DrlgCoordsStrc* pCoords = pOrth->pCoords;
        if (!pCoords)
        {
            pCoords = pDefaultCoords;
        }

        D2DrlgVertexStrc* pStart;
        int nStart;
        int nEnd;
        int nFirst;
        int nSecond;
        int nStep;
        int bVertical;

        switch (pOrth->nDirection)
        {
        case 0:
            pStart = pVertex;
            nStart = pVertex->nPosY;
            nEnd = pVertex1->nPosY;
            nFirst = pCoords->nSubtileY + pCoords->nSubtileHeight;
            nSecond = pCoords->nSubtileY;
            nStep = -1;
            bVertical = 1;
            break;

        case 1:
            pStart = pVertex1;
            nStart = pVertex1->nPosX;
            nEnd = pVertex2->nPosX;
            nFirst = pCoords->nSubtileX;
            nSecond = pCoords->nSubtileX + pCoords->nSubtileWidth;
            nStep = 1;
            bVertical = 0;
            break;

        case 2:
            pStart = pVertex2;
            nStart = pVertex2->nPosY;
            nEnd = pVertex3->nPosY;
            nFirst = pCoords->nSubtileY;
            nSecond = pCoords->nSubtileY + pCoords->nSubtileHeight;
            nStep = 1;
            bVertical = 1;
            break;

        case 3:
            pStart = pVertex3;
            nStart = pVertex3->nPosX;
            nEnd = pVertex->nPosX;
            nFirst = pCoords->nSubtileX + pCoords->nSubtileWidth;
            nSecond = pCoords->nSubtileX;
            nStep = -1;
            bVertical = 0;
            break;

        default:
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 109);
            exit(-1);
        }

        if (nFirst * nStep > nStart * nStep)
        {
            if (nFirst * nStep > nEnd * nStep)
            {
                continue;
            }

            D2DrlgVertexStrc* pNew = DRLGVER_AllocVertex(pMemPool, nDirection);
            if (bVertical)
            {
                pNew->nPosX = pStart->nPosX;
                pNew->nPosY = nFirst;
            }
            else
            {
                pNew->nPosY = pStart->nPosY;
                pNew->nPosX = nFirst;
            }
            pNew->pNext = pStart->pNext;
            pStart->pNext = pNew;
            pStart = pNew;
        }
        else if (nSecond * nStep < nStart * nStep)
        {
            continue;
        }

        sub_0067CE00_MarkVertex(pStart, pOrth->bInit);

        if (nSecond * nStep < nEnd * nStep)
        {
            D2DrlgVertexStrc* pNew = DRLGVER_AllocVertex(pMemPool, nDirection);
            if (bVertical)
            {
                pNew->nPosX = pStart->nPosX;
                pNew->nPosY = nSecond;
            }
            else
            {
                pNew->nPosY = pStart->nPosY;
                pNew->nPosX = nSecond;
            }
            pNew->pNext = pStart->pNext;
            pStart->pNext = pNew;
        }
    }
}

// 0x0067D030
static void __fastcall sub_0067D030(D2DrlgCoordsStrc* pCoords, D2DrlgVertexStrc* pFirst)
{
    D2DrlgVertexStrc* pVertex = pFirst;
    do
    {
        pVertex->nPosX -= pCoords->nSubtileX;
        pVertex->nPosY -= pCoords->nSubtileY;
        pVertex = pVertex->pNext;
    }
    while (pVertex != pFirst);
}

// 0x0067D050
void __fastcall DRLGVER_CreateVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex, D2DrlgCoordsStrc* pCoords, unsigned char nDirection, D2DrlgOrthStrc* pOrth)
{
    --pCoords->nSubtileWidth;
    --pCoords->nSubtileHeight;
    for (D2DrlgOrthStrc* pShrink = pOrth; pShrink; pShrink = pShrink->pNext)
    {
        --pShrink->pCoords->nSubtileWidth;
        --pShrink->pCoords->nSubtileHeight;
    }

    D2DrlgVertexStrc* pVertex0 = DRLGVER_AllocVertex(pMemPool, nDirection);
    *ppVertex = pVertex0;
    pVertex0->nPosX = pCoords->nSubtileX;
    pVertex0->nPosY = pCoords->nSubtileY + pCoords->nSubtileHeight;

    D2DrlgVertexStrc* pVertex1 = DRLGVER_AllocVertex(pMemPool, nDirection);
    pVertex0->pNext = pVertex1;
    pVertex1->nPosX = pCoords->nSubtileX;
    pVertex1->nPosY = pCoords->nSubtileY;

    D2DrlgVertexStrc* pVertex2 = DRLGVER_AllocVertex(pMemPool, nDirection);
    pVertex1->pNext = pVertex2;
    pVertex2->nPosX = pCoords->nSubtileX + pCoords->nSubtileWidth;
    pVertex2->nPosY = pCoords->nSubtileY;

    D2DrlgVertexStrc* pVertex3 = DRLGVER_AllocVertex(pMemPool, nDirection);
    pVertex2->pNext = pVertex3;
    pVertex3->nPosX = pCoords->nSubtileX + pCoords->nSubtileWidth;
    pVertex3->nPosY = pCoords->nSubtileY + pCoords->nSubtileHeight;
    pVertex3->pNext = *ppVertex;

    sub_0067CE20(pMemPool, *ppVertex, pCoords, nDirection, pOrth);
    sub_0067D030(pCoords, *ppVertex);

    ++pCoords->nSubtileWidth;
    ++pCoords->nSubtileHeight;
    for (D2DrlgOrthStrc* pGrow = pOrth; pGrow; pGrow = pGrow->pNext)
    {
        ++pGrow->pCoords->nSubtileWidth;
        ++pGrow->pCoords->nSubtileHeight;
    }
}

// 0x0067D250
void __fastcall sub_0067D250(D2DrlgVertexStrc** ppVertex)
{
    D2DrlgVertexStrc* pPrevious = 0;
    D2DrlgVertexStrc* pVertex = *ppVertex;
    while (pVertex)
    {
        D2DrlgVertexStrc* pNext = pVertex->pNext;
        pVertex->pNext = pPrevious;
        pPrevious = pVertex;
        pVertex = pNext;
    }

    *ppVertex = pPrevious;
}

// 0x0067D280
void __fastcall sub_0067D280(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY)
{
    *pDirectionX = pVertex->pNext->nPosX - pVertex->nPosX;
    *pDirectionY = pVertex->pNext->nPosY - pVertex->nPosY;

    if (*pDirectionX < 0)
    {
        *pDirectionX = -1;
    }
    else if (*pDirectionX > 0)
    {
        *pDirectionX = 1;
    }

    if (*pDirectionY < 0)
    {
        *pDirectionY = -1;
    }
    else if (*pDirectionY > 0)
    {
        *pDirectionY = 1;
    }
}

// 0x0067D1E0
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    if (*ppVertex)
    {
        D2DrlgVertexStrc* pVertex = (*ppVertex)->pNext;
        while (pVertex)
        {
            D2DrlgVertexStrc* pFree = pVertex;
            pVertex = pVertex->pNext;
            sub_0040B480(pMemPool, pFree, ".\\DRLG\\DrlgVer.cpp", 276, 0);

            if (pVertex == *ppVertex)
            {
                sub_0040B480(pMemPool, pVertex, ".\\DRLG\\DrlgVer.cpp", 279, 0);
                break;
            }
        }

        if (!pVertex)
        {
            sub_0040B480(pMemPool, *ppVertex, ".\\DRLG\\DrlgVer.cpp", 287, 0);
        }

        *ppVertex = 0;
    }
}
