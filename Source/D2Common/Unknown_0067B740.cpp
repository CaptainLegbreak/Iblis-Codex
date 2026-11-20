#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DrlgPresets.h"




int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

static __declspec(noinline) int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo);

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
