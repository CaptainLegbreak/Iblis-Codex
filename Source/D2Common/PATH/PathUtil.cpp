#include "D2Common.h"
#include "D2Structs.h"

struct PathOwner;
struct D2DynamicPathStrc;
struct D2PathPointStrc;
struct D2StaticPathStrc;
struct D2UnitStrc;

struct PathOwner { char pad0[0x2c]; D2DynamicPathStrc* pPath; };

struct D2DynamicPathStrc
{
    char pad0[0x10];
    unsigned short x;
    unsigned short y;
    char pad14[0x44];
    union
    {
        PathOwner* field58;
        D2UnitStrc* pTargetUnit;
    };
    char pad5C[0x0C];
    unsigned char field68;
    unsigned char unk_69[0x3];
};

extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath); // 0x006487F0

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

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

// 0x00679190
void __fastcall sub_00679190(D2DynamicPathStrc* ptPath)
{
    if (ptPath == 0)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1ea);
        exit(-1);
    }
    if (ptPath->field58 == 0)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1eb);
        exit(-1);
    }

    unsigned char dir = PATH_GetDirection(ptPath->field58->pPath);
    int dir8 = (int)dir * 8;
    int offset = (int)ptPath->field68 * 256;
    int angle = (dir8 - offset) & 0x1FF;
    float f = (float)ptPath->field68;

    ptPath->x += (unsigned short)(int)(sub_0040B330_Cos(angle) * f);
    ptPath->y += (unsigned short)(int)(sub_0040B350_Sin(angle) * f);
}

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
void __fastcall sub_6FDAB940(D2PathPointStrc* pOutPathPoint, D2DynamicPathStrc* ptPath)
{
    D2_ASSERT(ptPath, 0x201);
    D2_ASSERT(ptPath->pTargetUnit, 0x202);

    pOutPathPoint->X = UNITS_GetXPositionInline(ptPath->pTargetUnit);
    pOutPathPoint->Y = UNITS_GetYPositionInline(ptPath->pTargetUnit);

    if (ptPath->field68)
    {
        int nDirection = 8 * PATH_GetDirection(ptPath->pTargetUnit->pDynamicPath);
        nDirection = (nDirection - (ptPath->field68 << 8)) & 0x1FF;
        const float fSpeed = ptPath->field68;
        pOutPathPoint->X += (short)(sub_0040B330_Cos(nDirection) * fSpeed);
        pOutPathPoint->Y += (short)(sub_0040B350_Sin(nDirection) * fSpeed);
    }
}
