struct D2GameStrc;
struct D2UnitStrc;

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit);         // 0x006505E0

// 0x005D2B20
int __fastcall sub_005D2B20(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (pOwner)
    {
        D2Common_10235_PATH_UpdateRiderPath(pUnit, pOwner);
    }
    return 1;
}
