#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn);                                    // 0x006CC34C

struct D2UnitFindArgStrc;





D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);               // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0

// 0x0065A6B0
static __declspec(noinline) int sub_0065A6B0_IsAreaNearRoomEdge(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize)
{
    D2DrlgCoordsStrc pCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &pCoords);

    if (nX - nSize <= pCoords.nSubtileX || nY - nSize <= pCoords.nSubtileY
        || nSize + nX >= pCoords.nSubtileX + pCoords.nSubtileWidth || nSize + nY >= pCoords.nSubtileY + pCoords.nSubtileHeight)
    {
        return 1;
    }

    return 0;
}

static __declspec(noinline) int sub_0065A710_IsAreaInRoomRange(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize)
{
    D2DrlgCoordsStrc pCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &pCoords);

    if (nX + nSize >= pCoords.nSubtileX)
    {
        if (nY + nSize >= pCoords.nSubtileY || nY - nSize <= pCoords.nSubtileY + pCoords.nSubtileHeight)
        {
            return 1;
        }
        return 0;
    }

    if (nX - nSize > pCoords.nSubtileX + pCoords.nSubtileWidth)
    {
        return 0;
    }

    if (nY + nSize >= pCoords.nSubtileY || nY - nSize <= pCoords.nSubtileY + pCoords.nSubtileHeight)
    {
        return 1;
    }
    return 0;
}

// 0x0065A800
D2UnitStrc* __stdcall UNITFINDS_GetNearestTestedUnit(D2UnitStrc* pUnit, int nX, int nY, int nSize, int (__fastcall* pfnUnitTest)(D2UnitStrc*, D2UnitStrc*))
{
    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;

    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(hRoom, 144);

    DUNGEON_GetAdjacentRoomsListFromRoom(hRoom, &ppRoomList, &nNumRooms);

    D2UnitStrc* pResult = 0;
    int nSmallestDistance = 65535;
    if (!nSize)
    {
        nSize = 65536;
    }

    D2_ASSERT(!IsBadCodePtr((void*)pfnUnitTest), 159);

    for (int i = 0; i < nNumRooms; ++i)
    {
        if (sub_0065A710_IsAreaInRoomRange(ppRoomList[i], nX, nY, nSize))
        {
            for (D2UnitStrc* j = ppRoomList[i]->pUnitFirst; j; j = j->ptRoomNext)
            {
                const int nDistance = sub_006417F0_GetDistanceToXY(j, nX, nY);
                if (nDistance < nSize && nDistance < nSmallestDistance && pfnUnitTest(j, pUnit))
                {
                    pResult = j;
                    nSmallestDistance = nDistance;
                }
            }
        }
    }

    return pResult;
}

// 0x0065A900
static __declspec(noinline) void sub_0065A900_GrowUnitsArray(D2UnitFindDataStrc* pUnitFindData)
{
    D2_ASSERT(pUnitFindData, 192);

    const int nMax = pUnitFindData->nMaxArrayEntries + 15;
    D2UnitStrc** pArray = (D2UnitStrc**)FOG_ReallocPool(pUnitFindData->pMemPool, pUnitFindData->pUnitsArray, sizeof(D2UnitStrc*) * nMax, ".\\UNITS\\UnitFinds.cpp", 197, 0);
    pUnitFindData->nMaxArrayEntries = nMax;
    pUnitFindData->pUnitsArray = pArray;
}

void __stdcall sub_M404_Emit_0065AC70(D2UnitFindDataStrc* pUnitFindData)
{
    if (sub_0065A6B0_IsAreaNearRoomEdge(pUnitFindData->pRoom, pUnitFindData->nX, pUnitFindData->nY, pUnitFindData->nSize))
    {
        sub_0065A900_GrowUnitsArray(pUnitFindData);
    }
}
