#include "D2Structs.h"
#include "D2Path.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
#pragma intrinsic(memset)


struct D2PathIDAStarNodeStrc
{
    unsigned short nFScore;
    unsigned short nHeuristicDistanceToTarget;
    unsigned short nBestDistanceFromStart;
    short nEvaluationsCount;
    D2PathPointStrc tCoord;
    const int* pNeighborsSequence;
    int nNextNeighborIndex;
    D2PathIDAStarNodeStrc* pParent;
    D2PathIDAStarNodeStrc* pBestChild;
};

struct D2PathIDAStarContextStrc
{
    D2PathIDAStarNodeStrc* pCurrentNode;
    D2PathIDAStarNodeStrc aNodesStorage[900];
    int nNodesCount;
};

typedef char chkIdaCount_M125[(int)&((D2PathIDAStarContextStrc*)0)->nNodesCount == 0x6274 ? 1 : -1];

// 0x0067A590
static D2PathIDAStarNodeStrc* PATH_IDAStar_GetNewNode(D2PathIDAStarContextStrc* pContext)
{
    if (pContext->nNodesCount == 900)
    {
        return 0;
    }
    D2PathIDAStarNodeStrc* pNewNode = &pContext->aNodesStorage[pContext->nNodesCount++];
    memset(pNewNode, 0, sizeof(*pNewNode));
    return pNewNode;
}

D2PathIDAStarNodeStrc* __stdcall sub_M125_Emit_0067A590(int nUnused1, int nUnused2, int nUnused3, D2PathIDAStarContextStrc* pContext)
{
    return PATH_IDAStar_GetNewNode(pContext);
}
