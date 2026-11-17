struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0xB4];
    D2UnitStrc* pListNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00553490
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath);                                  // 0x00648BF0
void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0057C980
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00552DB0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 222);

    return pUnit->pListNext;
}

// 0x00553540
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    sub_6FCBC7E0(pGame, pUnit);
    D2UnitStrc* pTargetUnit = PATH_GetTargetUnit(pUnit->pDynamicPath);
    if (pTargetUnit != pUnit)
    {
        return pTargetUnit;
    }

    return 0;
}

// 0x00553570
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode)
{
    SUNITDMG_FreeAttackerCombatList(pGame, pUnit);
    UNITS_ChangeAnimMode(pUnit, nMode);
}
