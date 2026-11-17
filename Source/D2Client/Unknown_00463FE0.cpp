#include "D2Client.h"

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x000[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x008[0x24];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2ObjectsTxt
{
    char unk0x000[0x13A];
    unsigned char nIsDoor;
    char unk0x13B[0x65];
    int dwLeft;
    int dwTop;
    int dwWidth;
    int dwHeight;
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall sub_00643260(int* pX, int* pY);                                                   // 0x00643260
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5

inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00463FE0
static int __stdcall sub_00463FE0_IsInObjectSelectBox(int nY, D2ObjectsTxt* pObjectsTxtRecord, int nX, D2UnitStrc* pUnit)
{
    int nUnitX = UNITS_InlineGetXPosition(pUnit);
    int nUnitY = UNITS_InlineGetYPosition(pUnit);
    sub_00643260(&nUnitX, &nUnitY);

    const int nLeft = pObjectsTxtRecord->dwLeft + nUnitX;
    const int nTop = pObjectsTxtRecord->dwTop + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= pObjectsTxtRecord->dwWidth + nLeft && nY <= pObjectsTxtRecord->dwHeight + nTop)
    {
        return 1;
    }

    return 0;
}

int __fastcall sub_Q03_Emit_ObjectSelectBox(D2UnitStrc* pUnit, int nX, int nY)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
    if (pObjectsTxtRecord->nIsDoor)
    {
        return sub_00463FE0_IsInObjectSelectBox(nY, pObjectsTxtRecord, nX, pUnit);
    }

    return 0;
}

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[11];
    unsigned int nFrameCount;
    void* pCellFile;
    int unk0x38;
    D2CelStrc* f_3C;
    int unk0x40;
    int unk0x44;
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __fastcall sub_004DAE60_UnitSupportsMode(D2UnitStrc* pUnit, int nMode);                                 // 0x004DAE60
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, int nArg7, int nArg8); // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit);                                          // 0x004DA0D0
int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit);                                          // 0x004DA0F0

static int __stdcall sub_004640A0_GetUnitSelectRect(unsigned int nFrame, D2RectStrc* pRect, D2UnitStrc* pUnit, int nMode)
{
    if (sub_004DAE60_UnitSupportsMode(pUnit, nMode))
    {
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));

        int nOut;
        if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, nMode, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2CelStrc* pCell = tContext.f_3C;
            if (pCell)
            {
                D2_ASSERT(nFrame <= tContext.nFrameCount, 0x5DF);

                const int nOffsetX = sub_00601920(pCell) - 12;
                pRect->nLeft = nOffsetX + UNITS_GetClientCoordX(pUnit);
                pRect->nRight = sub_006018C0(pCell) + pRect->nLeft + 24;
                const int nTop = sub_00601950(pCell) + UNITS_GetClientCoordY(pUnit) + 12;
                pRect->nTop = nTop;
                pRect->nBottom = nTop - sub_006018F0(pCell) - 24;

                const int nWidth = pRect->nRight - pRect->nLeft;
                if (nWidth < 32)
                {
                    const int nPad = (32 - nWidth) >> 1;
                    pRect->nRight += nPad;
                    pRect->nLeft -= nPad;
                }

                const int nHeight = nTop - pRect->nBottom;
                if (nHeight < 32)
                {
                    const int nPad = (32 - nHeight) >> 1;
                    pRect->nBottom -= nPad;
                    pRect->nTop += nPad;
                }

                const int nGfxOffsetX = sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
                const int nGfxOffsetY = sub_004DA0D0_GetGfxMotionField38(pUnit) + sub_004DA0F0_GetGfxMotionField3C(pUnit);
                pRect->nLeft += nGfxOffsetX;
                pRect->nRight += nGfxOffsetX;
                pRect->nTop += nGfxOffsetY;
                pRect->nBottom += nGfxOffsetY;
                return 1;
            }
        }
    }

    return 0;
}

int __fastcall sub_Q03_Emit_UnitSelectRect(D2UnitStrc* pUnit, int nX)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);

    D2RectStrc tRect;
    for (int nMode = 0; nMode < 16; ++nMode)
    {
        if (sub_004640A0_GetUnitSelectRect(nFrameNo, &tRect, pUnit, nMode) && nX >= tRect.nLeft && nX <= tRect.nRight)
        {
            return 1;
        }
    }

    return 0;
}
