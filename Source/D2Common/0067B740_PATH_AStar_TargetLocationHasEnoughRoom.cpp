struct D2ActiveRoomStrc;
struct D2UnitStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    char unk_00[0x58];
    D2UnitStrc* pTargetUnit;
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    D2ActiveRoomStrc* pTargetRoom;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned short field_16;
    int nDistMax;
    unsigned char nMinimumFScoreToEvaluate;
    unsigned char field_1D;
    unsigned short field_1E;
    int nPathType;
    int nUnitSize;
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064D910

static __declspec(noinline) int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo);

// 0x0067B740
static int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo)
{
    if (!pPathInfo->pDynamicPath->pTargetUnit)
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
