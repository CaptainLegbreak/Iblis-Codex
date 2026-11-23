#include "D2Common.h"

#include "D2PathFind.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2DrlgPresets.h"

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

static int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo);

struct D2PathFoWallContextStrc
{
    D2PathFoWallNodeStrc* aPendingCache[128];
    D2PathFoWallNodeStrc* aVisitedCache[128];
};

extern const int gaIdaStar_PointCacheHashMaskX[]; // 0x006F1998

extern const int gaIdaStar_PointCacheHashMaskY[]; // 0x006F1B98

// 0x0067ADC0
int __stdcall PATH_AStar_Heuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDiffX = tPoint1.X - tPoint2.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = tPoint1.Y - tPoint2.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    if (nDiffX >= nDiffY)
    {
        return nDiffY + 2 * nDiffX;
    }
    return nDiffX + 2 * nDiffY;
}

// 0x0067AE00
D2PathFoWallNodeStrc* __stdcall PATH_AStar_GetNodeFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[tPathPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[tPathPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pNode = pContext->aPendingCache[nHash]; pNode != 0; pNode = pNode->pNextCachePoint)
    {
        if (tPathPoint.X == pNode->tPoint.X && tPathPoint.Y == pNode->tPoint.Y)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x0067AE50
D2PathFoWallNodeStrc* __stdcall PATH_AStar_FindPointInVisitedCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[tPathPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[tPathPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pNode = pContext->aVisitedCache[nHash]; pNode != 0; pNode = pNode->pNextCachePoint)
    {
        if (tPathPoint.X == pNode->tPoint.X && tPathPoint.Y == pNode->tPoint.Y)
        {
            return pNode;
        }
    }

    return 0;
}

typedef unsigned int size_t;
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
struct D2DrlgTableEntryStrc
{
    char unk0x00[0x38];
};
struct D2DrlgEntryTableStrc
{
    char unk0x0000[0x404];
    D2DrlgTableEntryStrc pEntries[200];
    int nEntries;
};

// 0x0067B1C0
D2DrlgTableEntryStrc* __fastcall PATH_AStar_AllocNewNode(D2DrlgEntryTableStrc* pTable)
{
    if (pTable->nEntries == 200)
    {
        return 0;
    }

    D2DrlgTableEntryStrc* pEntry = &pTable->pEntries[pTable->nEntries++];
    memset(pEntry, 0, sizeof(D2DrlgTableEntryStrc));
    return pEntry;
}

// 0x0067B740
static int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo)
{
    if (!pPathInfo->pDynamicPath->hTarget)
    {
        return 1;
    }
    D2ActiveRoomStrc* pStartRoom = pPathInfo->pStartRoom;
    const int nTargetX = pPathInfo->tTargetCoord.X;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nTargetY = pPathInfo->tTargetCoord.Y;
    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY + 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY + 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY + 0, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 0, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY + 0, nCollisionPattern, nCollisionMask))
    {
    ReturnOne:
        return 1;
    }

    return !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 0, nTargetY + 2, nCollisionPattern, nCollisionMask);
}

int __stdcall sub_Emit_0067B740(D2PathInfoStrc* pPathInfo)
{
    return PATH_AStar_TargetLocationHasEnoughRoom(pPathInfo);
}
