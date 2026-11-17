struct D2GameStrc;
struct D2DynamicPathStrc;
struct D2UnitStrc { unsigned int dwUnitType; char dwClassId[0x28]; D2DynamicPathStrc* pDynamicPath; char unk_30[0x94]; unsigned int dwFlags; };
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pPath, int nMask); // 0x00648C30

// 0x005D1BF0
int __fastcall sub_005D1BF0_ResurrectMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkill, int nLevel)
{
    const unsigned int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
        return 0;
    SKILLS_ResurrectUnit(pGame, pUnit);
    pUnit->dwFlags &= ~14;
    PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 256);
    return 1;
}
