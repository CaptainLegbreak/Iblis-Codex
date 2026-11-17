struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x08];
    int dwUnitId;
    char unk0x10[0xD4];
    D2UnitStrc* pListNext;
};

struct D2GameStrc
{
    char unk0x00[0x1120];
    D2UnitStrc* pUnitList[5][128];
    D2UnitStrc* pTileList;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_TILE 5
#define UNIT_LIST_MASK 0x7F

extern const int s_anUnitListOffset_006E10E0[6]; // 0x006E10E0

// 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID)
{
    D2_ASSERT(pGame, 722);

    D2UnitStrc** ppUnitList;
    if (nUnitType == UNIT_TILE)
    {
        ppUnitList = &pGame->pTileList;
    }
    else if (nUnitType >= 0 && nUnitType <= 4)
    {
        ppUnitList = (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }
    else
    {
        ppUnitList = 0;
    }

    for (D2UnitStrc* pUnit = *ppUnitList; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitGUID)
        {
            return pUnit;
        }
    }

    return 0;
}

#include "gen/data/Source/D2Game/00552F60_SUNIT_GetServerUnit.inc"
