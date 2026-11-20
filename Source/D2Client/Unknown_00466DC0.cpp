#include "D2Client.h"

struct D2SelectionRectStrc;

struct D2SelectionRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};
extern int gnSelectedUnitId_007A6A78; // 0x007A6A78
extern int gnSelectedUnitType_007A6A8C; // 0x007A6A8C
extern int gdwGlobal_007A6A94; // 0x007A6A94
extern int gdwGlobal_007A6A98; // 0x007A6A98


D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
int __stdcall ITEMS_IsMetalItem(int nItemId); // 0x00629CC0

int gnSelectionLeft_007A6A7C; // 0x007A6A7C

int gnSelectionTop_007A6A80; // 0x007A6A80

int gnSelectionRight_007A6A84; // 0x007A6A84

int gnSelectionBottom_007A6A88; // 0x007A6A88

int gbSelectionRectValid_007A6A9C; // 0x007A6A9C

// 0x00466DC0
int __cdecl sub_00466DC0()
{
    return gdwGlobal_00711F90;
}

// 0x00466FE0
void __cdecl sub_00466FE0()
{
    gdwGlobal_007A6A98 = 0;
    gdwGlobal_007A6A94 = 0;
}

// 0x00466FF0
void __cdecl sub_00466FF0()
{
    gdwGlobal_007A6A98 = 0;
}

// 0x00467430
void __fastcall sub_00467430_SetSelectionRect(const D2SelectionRectStrc* pRect)
{
    if (pRect)
    {
        gnSelectionLeft_007A6A7C = pRect->nLeft;
        gnSelectionTop_007A6A80 = pRect->nTop;
        gnSelectionRight_007A6A84 = pRect->nRight;
        gnSelectionBottom_007A6A88 = pRect->nBottom;
        gbSelectionRectValid_007A6A9C = 1;
    }
    else
    {
        gbSelectionRectValid_007A6A9C = 0;
    }
}

// 0x00467A00
void __cdecl sub_00467A00()
{
    gdwGlobal_00711F90 = 0x13;
    gdwGlobal_00711F94 = 0x13;
}

// build: context sub_00467A10
D2UnitStrc* __cdecl sub_00467A10()
{
    if (gdwGlobal_007A6A94)
    {
        D2UnitStrc* pUnit = sub_00463990(gnSelectedUnitId_007A6A78, gnSelectedUnitType_007A6A8C);
        if (pUnit && sub_00466870(pUnit, 0, 0, 0))
        {
            return pUnit;
        }
        gdwGlobal_007A6A98 = 0;
        gdwGlobal_007A6A94 = 0;
    }
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_00466DC0.inc"
#include "D2Structs.h"

static __forceinline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
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
    if (pUnit && pUnit->dwUnitType == 4
        && ITEMS_IsMetalItem(UNITS_GetClassIdInline(pUnit)))
    {
        return 1;
    }
    return 0;
}
