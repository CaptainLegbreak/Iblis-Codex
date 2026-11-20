#include "D2Client.h"
#include "D2Structs.h"

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType);                 // 0x004639B0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                              // 0x00463990
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

extern D2R01LightStrc* gpLights_007B5668;                                                                   // 0x007B5668

__forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00475930
void __fastcall sub_00475930_ActCallback(D2ActiveRoomStrc* pRoom)
{
    for (D2R01LightStrc* pLight = gpLights_007B5668; pLight; pLight = pLight->pNext)
    {
        if (pLight->nMode == 2)
        {
            D2UnitStrc* pUnit = 0;
            if (pLight->nUnitType != 6)
            {
                unsigned int const tNUnitId = pLight->nUnitId;
                pUnit = pLight->f_8 ? sub_004639B0_FindServerSideUnit(tNUnitId, pLight->nUnitType)
                                    : sub_00463990(tNUnitId, pLight->nUnitType);
            }
            D2_ASSERT(pUnit, 1425);

            D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
            if (pUnitRoom != pRoom)
            {
                const unsigned int nX = CLIENTS_GetUnitXInline(pUnit);
                const unsigned int nY = CLIENTS_GetUnitYInline(pUnit);
                const int nRadius = pLight->nRadius >> 3;
                if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX + nRadius, nY) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
                else if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX - nRadius, nY) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
                else if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX, nY + nRadius) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
                else if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX, nY - nRadius) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
            }
        }
    }
}
