#include "D2Drlg.h"
#include "D2DrlgMaps.h"



extern "C" const char gszEmptyAssertText;      // 0x006CC837

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430
extern "C" const char* __cdecl sub_00408090();                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

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

// 0x0067CE20
void __stdcall sub_0067CE20(void* pMemPool, D2DrlgVertexStrc* pCurrentVertex, D2DrlgCoordStrc* pDrlgCoord, unsigned char nDirection, D2DrlgOrthStrc* pCurrentRoomData)
{
    int nSign = 0;
    D2DrlgVertexStrc* pNextVertex = pCurrentVertex->pNext;
    D2DrlgVertexStrc* pLastVertex = pCurrentVertex->pNext->pNext;
    D2DrlgVertexStrc* pPreviousVertex = pCurrentVertex->pNext->pNext->pNext;

    while (pCurrentRoomData)
    {
        D2DrlgCoordStrc* pCurrentCoords;
        if (pCurrentRoomData->pBox)
            pCurrentCoords = pCurrentRoomData->pBox;
        else
            pCurrentCoords = pDrlgCoord;

        D2DrlgVertexStrc* pVertex;
        D2DrlgVertexStrc* pEndVertex;
        bool bDirection;
        int nFirst;
        int nSecond;
        int nStart;
        int nEnd;

        switch (pCurrentRoomData->nDirection)
        {
        case 0:
            pVertex = pCurrentVertex;
            bDirection = true;
            nSign = -1;
            pEndVertex = pNextVertex;
            nFirst = pCurrentCoords->nPosY + pCurrentCoords->nHeight;
            nSecond = pCurrentCoords->nPosY;
            break;

        case 1:
            pVertex = pNextVertex;
            bDirection = false;
            nSign = 1;
            pEndVertex = pLastVertex;
            nFirst = pCurrentCoords->nPosX;
            nSecond = pCurrentCoords->nPosX + pCurrentCoords->nWidth;
            break;

        case 2:
            pVertex = pLastVertex;
            bDirection = true;
            nSign = 1;
            pEndVertex = pPreviousVertex;
            nFirst = pCurrentCoords->nPosY;
            nSecond = pCurrentCoords->nPosY + pCurrentCoords->nHeight;
            break;

        case 3:
            pVertex = pPreviousVertex;
            bDirection = false;
            nSign = -1;
            pEndVertex = pCurrentVertex;
            nFirst = pCurrentCoords->nPosX + pCurrentCoords->nWidth;
            nSecond = pCurrentCoords->nPosX;
            break;

        default:
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 109);
            exit(-1);
        }

        if (bDirection)
        {
            nStart = pVertex->nPosY;
            nEnd = pEndVertex->nPosY;
        }
        else
        {
            nStart = pVertex->nPosX;
            nEnd = pEndVertex->nPosX;
        }

        if (nFirst * nSign <= nStart * nSign)
        {
            if (nSecond * nSign < nStart * nSign)
            {
                goto next;
            }
        }
        else
        {
            if (nFirst * nSign > nEnd * nSign)
            {
                goto next;
            }

            D2DrlgVertexStrc* pNewVertex = DRLGVER_AllocVertex(pMemPool, nDirection);
            if (bDirection)
            {
                pNewVertex->nPosX = pVertex->nPosX;
                pNewVertex->nPosY = nFirst;
            }
            else
            {
                pNewVertex->nPosY = pVertex->nPosY;
                pNewVertex->nPosX = nFirst;
            }
            pNewVertex->pNext = pVertex->pNext;
            pVertex->pNext = pNewVertex;
            pVertex = pNewVertex;
        }

        sub_0067CE00_MarkVertex(pVertex, pCurrentRoomData->bPreset);

        if (nSecond * nSign < nEnd * nSign)
        {
            D2DrlgVertexStrc* pNewVertex = DRLGVER_AllocVertex(pMemPool, nDirection);
            if (bDirection)
            {
                pNewVertex->nPosX = pVertex->nPosX;
                pNewVertex->nPosY = nSecond;
            }
            else
            {
                pNewVertex->nPosY = pVertex->nPosY;
                pNewVertex->nPosX = nSecond;
            }
            pNewVertex->pNext = pVertex->pNext;
            pVertex->pNext = pNewVertex;
        }

next:
        pCurrentRoomData = pCurrentRoomData->pNext;
    }
}
