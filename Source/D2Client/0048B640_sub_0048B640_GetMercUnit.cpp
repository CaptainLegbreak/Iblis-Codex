struct D2UnitStrc;

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                   // 0x00478F20

// 0x0048B640
D2UnitStrc* __cdecl sub_0048B640_GetMercUnit()
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pMerc = sub_00463990(nPetId, 1);
        if (pMerc)
        {
            return pMerc;
        }
    }
    sub_00455F20(0x24, 2, 0);
    return 0;
}
