struct D2UnitStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2DynamicPathStrc
{
    char unk0x00[0x10];
    D2PathPointStrc tTargetCoord;
    char unk0x14[0x28];
    unsigned int dwPathType;
    char unk0x40[0x18];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x8];
    unsigned char nDirection;
    char unk0x65[0x17];
    int dwVelocity;
};

// 0x006486C0
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwVelocity;
}

// 0x006487F0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->nDirection;
}

// 0x00648A00
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.X;
}

// 0x00648A10
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.Y;
}

// 0x00648BF0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->pTargetUnit;
}

// 0x00648E30
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwPathType;
}
