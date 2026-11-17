extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2DynamicPathStrc
{
    char unk0x00[0x08];
    int dwClientCoordX;
    int dwClientCoordY;
    char unk0x10[0x20];
    D2UnitStrc* pUnit;
    unsigned int dwFlags;
    unsigned int unk0x38;
    unsigned int dwPathType;
    unsigned int dwPrevPathType;
    char unk0x44[0x20];
    unsigned char nDirection;
    unsigned char nNewDirection;
    unsigned char nDiffDirection;
    char unk0x67[0x15];
    int dwVelocity;
    unsigned int nPreviousVelocity;
    char unk0x84[0x0D];
    unsigned char nDistMax;
    char unk0x92[6];
    int nDirOffset;
};

extern int gnDirectionDiffTable_006EB548[];                                                                 // 0x006EB548
extern int gaOffsetForPathType_006EB648[];                                                                  // 0x006EB648
extern int gaPathTypeFlags_006EB690[];                                                                      // 0x006EB690

// 0x006485F0
void __fastcall sub_6FDA9720(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection)
{
    nDirection &= 63;
    int nUnitType;
    if (!pDynamicPath->pUnit)
    {
        nUnitType = 6;
    }
    else
    {
        nUnitType = pDynamicPath->pUnit->dwUnitType;
    }

    switch (nUnitType)
    {
    case 2:
    case 4:
        pDynamicPath->nDirection = nDirection;
        break;
    case 3:
        if (!(pDynamicPath->dwFlags & 0x40))
        {
            pDynamicPath->nDirection = nDirection;
        }
        break;
    default:
        if (nDirection != pDynamicPath->nNewDirection)
        {
            pDynamicPath->nNewDirection = nDirection;
            const unsigned char nDiff = nDirection - pDynamicPath->nDirection;
            pDynamicPath->nDiffDirection = gnDirectionDiffTable_006EB548[nDiff & 63];
        }
        break;
    }
}

// 0x006489E0
void __fastcall PATH_SetClientCoordX(D2DynamicPathStrc* pPath, int nX)
{
    pPath->dwClientCoordX = nX;
}

// 0x006489F0
void __fastcall PATH_SetClientCoordY(D2DynamicPathStrc* pPath, int nY)
{
    pPath->dwClientCoordY = nY;
}

// 0x00648CF0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType)
{
    D2_ASSERT(!(pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 0 && nPathType == 2), 0x861);

    int nFlag = gaPathTypeFlags_006EB690[nPathType];
    if ((nFlag & 0x2000) && !(pDynamicPath->dwFlags & 0x4000))
    {
        pDynamicPath->dwPrevPathType = pDynamicPath->dwPathType;
    }

    if ((nFlag & 0x8000) && !(pDynamicPath->dwFlags & 0x10000))
    {
        pDynamicPath->nPreviousVelocity = pDynamicPath->dwVelocity;
    }

    pDynamicPath->dwPathType = nPathType;
    pDynamicPath->dwFlags = nFlag | pDynamicPath->dwFlags & 0xFFF800FF;
    pDynamicPath->nDirOffset = gaOffsetForPathType_006EB648[nPathType];

    D2_ASSERT(pDynamicPath->dwPrevPathType != 0xB, 0x871);
    D2_ASSERT(pDynamicPath->dwPrevPathType != 8, 0x872);
    D2_ASSERT((nPathType != 4) || (pDynamicPath->nDistMax < 78), 0x873);
}

// 0x006505C0
int __stdcall sub_006505C0_TestPathFlag8(D2DynamicPathStrc* pPath)
{
    if (!pPath)
    {
        return 0;
    }

    return pPath->dwFlags & 8;
}

#include "gen/data/Source/D2Common/006485F0_sub_6FDA9720.inc"
