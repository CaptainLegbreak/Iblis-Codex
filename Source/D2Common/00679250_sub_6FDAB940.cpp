enum D2C_PathConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
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
    char unk0x00[0x58];
    D2UnitStrc* pTargetUnit;
    char unk0x5C[0x0C];
    unsigned char dwSpeed;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

float __stdcall sub_0040B330_Cos(int nAngle);                                                               // 0x0040B330
float __stdcall sub_0040B350_Sin(int nAngle);                                                               // 0x0040B350
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00679250
void __fastcall sub_6FDAB940(D2PathPointStrc* pOutPathPoint, D2DynamicPathStrc* pPath)
{
    D2_ASSERT(pPath, 0x201);
    D2_ASSERT(pPath->pTargetUnit, 0x202);

    pOutPathPoint->X = UNITS_GetXPositionInline(pPath->pTargetUnit);
    pOutPathPoint->Y = UNITS_GetYPositionInline(pPath->pTargetUnit);

    if (pPath->dwSpeed)
    {
        int nDirection = 8 * PATH_GetDirection(pPath->pTargetUnit->pDynamicPath);
        nDirection = (nDirection - (pPath->dwSpeed << 8)) & 0x1FF;
        const float fSpeed = pPath->dwSpeed;
        pOutPathPoint->X += (short)(sub_0040B330_Cos(nDirection) * fSpeed);
        pOutPathPoint->Y += (short)(sub_0040B350_Sin(nDirection) * fSpeed);
    }
}
