#include "D2Client.h"
#include "D2Structs.h"

struct D2SelectionRectStrc;

struct D2SelectionRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};
extern int gnSelectedUnitId; // 0x007A6A78
extern int gnSelectedUnitType; // 0x007A6A8C
extern int gbHasSelectedUnit; // 0x007A6A94
extern int gbHoverLocked; // 0x007A6A98


D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
int __stdcall ITEMS_IsMetalItem(int nItemId); // 0x00629CC0

int gnSelectionLeft; // 0x007A6A7C

int gnSelectionTop; // 0x007A6A80

int gnSelectionRight; // 0x007A6A84

int gnSelectionBottom; // 0x007A6A88

int gbSelectionRectValid; // 0x007A6A9C

// 0x00466DC0
int __cdecl sub_00466DC0()
{
// build: symbol ?gnHoverMonClassId@* 0x00711F90
    return gnHoverMonClassId;
}

// 0x00466FE0
void __cdecl sub_00466FE0()
{
    gbHoverLocked = 0;
    gbHasSelectedUnit = 0;
}

// 0x00466FF0
void __cdecl sub_00466FF0()
{
    gbHoverLocked = 0;
}

// 0x00467430
void __fastcall sub_00467430_SetSelectionRect(const D2SelectionRectStrc* pRect)
{
    if (pRect)
    {
        gnSelectionLeft = pRect->nLeft;
        gnSelectionTop = pRect->nTop;
        gnSelectionRight = pRect->nRight;
        gnSelectionBottom = pRect->nBottom;
        gbSelectionRectValid = 1;
    }
    else
    {
        gbSelectionRectValid = 0;
    }
}

// 0x00467A00
void __cdecl sub_00467A00()
{
    gnHoverMonClassId = 0x13;
// build: symbol ?gnHoverClassId@* 0x00711F94
    gnHoverClassId = 0x13;
}

D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10

#include "gen/data/Source/D2Client/Unknown_00466DC0.inc"

static inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x00467470
int __fastcall sub_00467470_UnitFindTest(D2UnitStrc* pUnit, void* pArg)
{
    if (pUnit && pUnit->dwUnitType == UNIT_ITEM
        && ITEMS_IsMetalItem(UNITS_GetClassIdInline(pUnit)))
    {
        return 1;
    }
    return 0;
}
