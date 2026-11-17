struct D2ActiveRoomStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2DynamicPathStrc
{
    unsigned short wOffsetX;
    unsigned short wPosX;
    unsigned short wOffsetY;
    unsigned short wPosY;
    char unk0x08[0x14];
    D2ActiveRoomStrc* pRoom;
    char unk0x20[0x4];
    int dwCurrentPointIdx;
    int dwPathPoints;
    char unk0x2C[0x4];
    D2UnitStrc* pUnit;
    char unk0x34[0x8];
    unsigned int dwPathType;
    char unk0x40[0x8];
    unsigned int dwCollisionPattern;
    char unk0x4C[0x4];
    unsigned int nMoveTestCollisionMask;
    char unk0x54[0x4];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x20];
    int dwVelocity;
    char unk0x80[0x10];
    unsigned char nDist;
    char unk0x91[0x7];
    int nDirOffset;
    D2PathPointStrc PathPoints[78];
};

struct D2CollisionTestStrc
{
    D2ActiveRoomStrc* pRoom;
    unsigned int nCollisionPattern;
    unsigned int nCollisionMask;
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
    char unk0x1C[0xC];
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo);                                                     // 0x00679B30
int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo);                                             // 0x00679C80

// 0x00679E50
int __fastcall sub_6FDAB0B0(D2PathInfoStrc* pPathInfo)
{
    pPathInfo->pDynamicPath->dwCurrentPointIdx = 0;
    return PATH_Toward_6FDAA9F0(pPathInfo);
}

// 0x00679E60
int __fastcall PATH_BackupTurn_Compute(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->nDirOffset = -4;

    const int nResult = sub_6FDAA720(pPathInfo);
    if (!nResult)
    {
        return 0;
    }

    pDynamicPath->dwPathPoints = nResult;
    pDynamicPath->nDirOffset = -2;

    int nExtra = sub_6FDAA720(pPathInfo) - nResult;
    if (!nExtra)
    {
        pDynamicPath->nDirOffset = 2;
        nExtra = sub_6FDAA720(pPathInfo) - nResult;
    }

    pDynamicPath->nDirOffset = -4;
    return nResult + nExtra;
}
