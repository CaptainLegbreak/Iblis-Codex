#include "D2Common.h"
#include "D2Structs.h"
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2DrlgCoordsStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    unsigned char unk_04[0x8];
    D2CoordStrc tGameCoords;
};


struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x4C];
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    char unk0x5C[0x74 - 0x5C];
    D2UnitStrc* pUnitFirst;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall sub_00619EE0(D2ActiveRoomStrc* pRoom); // 0x00619EE0
D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom); // 0x00619F60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate); // 0x00619F90
int __stdcall D2Common_10084(D2ActiveRoomStrc* pRoom); // 0x0061AB60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
void __stdcall sub_0064FC20_ResetDynamicPathRoom(D2DynamicPathStrc* pDynamicPath); // 0x0064FC20
void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619F20
void __stdcall UNITS_ResetRoom(D2UnitStrc* pUnit); // 0x00620B50
void __stdcall UNITROOM_RemoveUnitFromUpdateQueue(D2UnitStrc* pUnit); // 0x0064C1B0

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
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
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x0064BF60
static int __stdcall sub_0064BF60_CanAddUnitToRoom(int bAssertIfPresent, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc tRoomCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);

    const int nX = UNITS_GetXPositionInline(pUnit);
    const int nY = UNITS_GetYPositionInline(pUnit);
    D2_ASSERT(pRoom && nX >= pRoom->nSubtileX && nX < pRoom->nSubtileX + pRoom->nSubtileWidth
        && nY >= pRoom->nSubtileY && nY < pRoom->nSubtileY + pRoom->nSubtileHeight, 46);

    for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->pRoomNext)
    {
        if (pUnit == i)
        {
            if (!bAssertIfPresent)
            {
                return FALSE;
            }
            D2_ASSERT(pUnit != i, 60);
        }
    }
    return TRUE;
}

// 0x0064C2C0
int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused)
{
    D2_ASSERT(pUnit, 72);
    D2_ASSERT(pRoom, 73);
    D2_ASSERT(sub_0064BF60_CanAddUnitToRoom(TRUE, pUnit, pRoom), 82);

    D2UnitStrc** ppUnitFirst = DUNGEON_GetUnitListFromRoom(pRoom);
    D2_ASSERT(ppUnitFirst, 87);
    pUnit->pRoomNext = *ppUnitFirst;
    *ppUnitFirst = pUnit;

    UNITROOM_RefreshUnit(pUnit);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        sub_00619EE0(pRoom);
        break;
    case UNIT_MONSTER:
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
        {
            sub_00619EE0(pRoom);
        }
        break;
    }
    return TRUE;
}

// 0x0064C040
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 123);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && !D2Common_10084(pRoom) && !(pUnit->dwFlags & 0x2000))
    {
        pUnit->dwFlags |= 0x2000;

        D2UnitStrc** ppUnitFirst = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 1);
        D2_ASSERT(ppUnitFirst, 142);

        pUnit->pChangeNextUnit = *ppUnitFirst;
        *ppUnitFirst = pUnit;
    }
}

// 0x0064C0C0
void __stdcall UNITROOM_SortUnitListByTargetY(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc** ppUnitFirst = 0;
    D2UnitStrc** ppUnit = 0;
    D2UnitStrc* pNextUnit = 0;
    D2UnitStrc* pUnit = 0;
    int bContinue = 0;

    ppUnit = DUNGEON_GetUnitListFromRoom(pRoom);
    pUnit = *ppUnit;
    ppUnitFirst = ppUnit;
    D2UnitStrc* pPreviousUnit = 0;

    if (pUnit)
    {
        pNextUnit = pUnit->pRoomNext;
        do
        {
            bContinue = 0;

            while (pNextUnit)
            {
                int nY = UNITS_GetClientCoordY(pUnit);
                if (nY > UNITS_GetClientCoordY(pNextUnit))
                {
                    if (pPreviousUnit)
                    {
                        pPreviousUnit->pRoomNext = pNextUnit;
                    }
                    else
                    {
                        *ppUnitFirst = pNextUnit;
                    }

                    pUnit->pRoomNext = pNextUnit->pRoomNext;
                    pNextUnit->pRoomNext = pUnit;
                    pPreviousUnit = pNextUnit;
                    pNextUnit = pUnit->pRoomNext;
                    bContinue = 1;
                }
                else
                {
                    pPreviousUnit = pUnit;
                    pUnit = pNextUnit;
                    pNextUnit = pNextUnit->pRoomNext;
                }
            }
        }
        while (bContinue);
    }
}

// 0x0064C160
void __stdcall UNITROOM_ClearUpdateQueue(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc** ppChangeUnit = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 0);
    D2UnitStrc* pChangeUnit = *ppChangeUnit;
    while (pChangeUnit)
    {
        D2UnitStrc* pNextChangeUnit = pChangeUnit->pChangeNextUnit;
        pChangeUnit->dwFlags &= ~0x2000;
        pChangeUnit->pChangeNextUnit = 0;
        pChangeUnit = pNextChangeUnit;
    }

    *ppChangeUnit = 0;
}

// 0x0064C260
int __stdcall UNITROOM_IsUnitInRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 340);

    if (!pRoom)
    {
        return 0;
    }

    D2UnitStrc* pRoomUnit = *DUNGEON_GetUnitListFromRoom(pRoom);
    while (pRoomUnit != pUnit)
    {
        pRoomUnit = pRoomUnit->pRoomNext;
        if (!pRoomUnit)
        {
            return 0;
        }
    }

    return 1;
}

// 0x0064C450
void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 210);

    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
    {
        D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
        if (pStaticPath->pRoom)
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
        pStaticPath->pRoom = 0;
        break;
    }

    default:
        sub_0064FC20_ResetDynamicPathRoom(pUnit->pDynamicPath);
        break;
    }
}

// 0x0064C1B0
void __stdcall UNITROOM_RemoveUnitFromUpdateQueue(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 301);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        D2_ASSERT(!pUnit->pChangeNextUnit, 312);
        return;
    }

    D2UnitStrc** ppChangeUnit = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 0);
    D2UnitStrc* pChangeUnit = *ppChangeUnit;
    D2UnitStrc* pPreviousChangeUnit = 0;
    for (; pChangeUnit; pChangeUnit = pChangeUnit->pChangeNextUnit)
    {
        if (pChangeUnit == pUnit)
        {
            break;
        }

        pPreviousChangeUnit = pChangeUnit;
    }

    if (pChangeUnit)
    {
        if (!pPreviousChangeUnit)
        {
            *ppChangeUnit = pChangeUnit->pChangeNextUnit;
            pChangeUnit->pChangeNextUnit = 0;
        }
        else
        {
            pPreviousChangeUnit->pChangeNextUnit = pChangeUnit->pChangeNextUnit;
            pChangeUnit->pChangeNextUnit = 0;
        }
    }
}

// 0x0064C370
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit)
{
    int bReset = 0;

    D2_ASSERT(pUnit, 245);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        D2_ASSERT(!pUnit->pRoomNext, 253);
        return;
    }

    D2UnitStrc** ppRoomUnit = DUNGEON_GetUnitListFromRoom(pRoom);
    D2UnitStrc* pRoomUnit = *ppRoomUnit;
    D2UnitStrc* pPreviousUnit = 0;
    for (; pRoomUnit; pRoomUnit = pRoomUnit->pRoomNext)
    {
        if (pRoomUnit == pUnit)
        {
            break;
        }

        pPreviousUnit = pRoomUnit;
    }

    if (pRoomUnit)
    {
        bReset = 1;
        if (!pPreviousUnit)
        {
            *ppRoomUnit = pRoomUnit->pRoomNext;
        }
        else
        {
            pPreviousUnit->pRoomNext = pRoomUnit->pRoomNext;
        }

        pRoomUnit->pRoomNext = 0;

        switch (pUnit->dwUnitType)
        {
        case 0:
            DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
            break;

        case 1:
            if (STATLIST_GetUnitAlignment(pUnit) == 2)
            {
                DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
            }
            break;
        }
    }

    UNITROOM_RemoveUnitFromUpdateQueue(pUnit);
    pUnit->dwFlags &= ~0x2000;
    if (bReset)
    {
        UNITS_ResetRoom(pUnit);
    }
}
