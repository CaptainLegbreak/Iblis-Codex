#pragma once
// Path finding: the search nodes of the IDA* and wall-following path finders.

#include "D2Check.h"
#include "D2Path.h"

struct D2PathIDAStarNodeStrc
{
    unsigned short nFScore; // 0x00
    unsigned short nHeuristicDistanceToTarget; // 0x02
    unsigned short nBestDistanceFromStart; // 0x04
    short nEvaluationsCount; // 0x06
    D2PathPointStrc tCoord; // 0x08
    const int* pNeighborsSequence; // 0x0C
    int nNextNeighborIndex; // 0x10
    D2PathIDAStarNodeStrc* pParent; // 0x14
    D2PathIDAStarNodeStrc* pBestChild; // 0x18
};

struct D2PathFoWallNodeStrc
{
    D2PathPointStrc tPoint; // 0x00
    short nFScore; // 0x04
    short nHeuristicDistanceToTarget; // 0x06
    short nBestDistanceFromStart; // 0x08
    unsigned short wPad; // 0x0A
    D2PathFoWallNodeStrc* pBestParent; // 0x0C
    D2PathFoWallNodeStrc* pChildren[8]; // 0x10
    D2PathFoWallNodeStrc* pNextCachePoint; // 0x30
    D2PathFoWallNodeStrc* pNextSortedByFScore; // 0x34
};

D2_CHECK_SIZE(D2PathIDAStarNodeStrc, 0x1C);
D2_CHECK_SIZE(D2PathFoWallNodeStrc, 0x38);
