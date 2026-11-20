#include "D2Structs.h"
// build: base-profile

struct D2GameStrc;


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const int s_anUnitListOffset_006E10E0[6]; // 0x006E10E0

#define UNIT_TILE 5

#define D2_MAYBE_UNUSED(x) (void)(x)

static __forceinline D2UnitStrc** SUNIT_GetUnitList(D2GameStrc* pGame, int nUnitType, unsigned int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
        return (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & 0x7F);
    return 0;
}

// 0x00553060
void __fastcall sub_00553060_AddToUnitList(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    D2UnitStrc** ppUnitList;
    if (pUnit->dwUnitType == UNIT_TILE)
        ppUnitList = (D2UnitStrc**)((char*)pGame + 0x1B20);
    else
        ppUnitList = SUNIT_GetUnitList(pGame, pUnit->dwUnitType, pUnit->dwUnitId);

    D2UnitStrc* i = *ppUnitList;
    D2UnitStrc* pPrevious = 0;
    while (i)
    {
        if (i->dwUnitId <= pUnit->dwUnitId)
        {
            if (i->dwUnitId == pUnit->dwUnitId)
            {
                char szMessage[256];
                D2_MAYBE_UNUSED(szMessage);
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x355);
                exit(-1);
            }
            break;
        }
        pPrevious = i;
        i = i->pListNext;
    }

    pUnit->pListNext = i;
    if (pPrevious)
        pPrevious->pListNext = pUnit;
    else
        *ppUnitList = pUnit;
}
