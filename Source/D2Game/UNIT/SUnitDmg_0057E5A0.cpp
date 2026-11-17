#include "D2Game.h"

struct D2StaticPathStrc { unsigned char pad[0xC]; int nX, nY; };
struct D2UnitStrc {
    int dwUnitType; unsigned char pad04[0x28];
    union { D2PathRecordStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; } path;
};
struct T0057E5A0 {
    D2UnitStrc* pReference;
    D2UnitStrc* players[8];
    int levels[8];
    int count, totalLevel;
};
extern const char gszEmptyAssertText; // 0x006CC837
int __fastcall SUNIT_IsDead(D2UnitStrc* unit); // 0x005541B0
int __stdcall PATH_GetX(D2PathRecordStrc* path); // 0x006488C0
int __stdcall PATH_GetY(D2PathRecordStrc* path); // 0x00648900
int __fastcall UNITS_GetXPosition(D2UnitStrc* unit); // 0x0045ADF0
int __fastcall UNITS_GetYPosition(D2UnitStrc* unit); // 0x0045AE20
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* unit, int stat, int layer); // 0x00625480
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char* text, const char* file, int line); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int code); // 0x00681E09

static __forceinline int GetReferenceX(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return unit->path.pStaticPath->nX;
    }
    return unit->path.pDynamicPath ? PATH_GetX(unit->path.pDynamicPath) : 0;
}
static __forceinline int GetReferenceY(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return unit->path.pStaticPath->nY;
    }
    return unit->path.pDynamicPath ? PATH_GetY(unit->path.pDynamicPath) : 0;
}

// 0x0057E5A0
void __fastcall SUNITDMG_PartyCallback_ComputePartyExperience(D2GameStrc* game, D2UnitStrc* unit, T0057E5A0* data)
{
    if (SUNIT_IsDead(unit))
        return;
    D2UnitStrc* reference = data->pReference;
    if (reference)
    {
        int x = GetReferenceX(reference);
        int y = GetReferenceY(reference);
        if (!x)
            return;
        int unitX = UNITS_GetXPosition(unit);
        int unitY = UNITS_GetYPosition(unit);
        if (!unitX)
            return;
        int dx = x - unitX;
        int dy = y - unitY;
        unsigned int distance = dx * dx + dy * dy;
        if (distance > 6400)
            return;
    }
    if (data->count >= 8)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 3877);
        exit(-1);
    }
    data->players[data->count] = unit;
    data->levels[data->count] = STATLIST_UnitGetStatValue(unit, 12, 0);
    data->totalLevel += data->levels[data->count];
    ++data->count;
}
