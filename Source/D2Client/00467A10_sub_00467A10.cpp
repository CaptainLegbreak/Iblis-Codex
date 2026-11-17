struct D2UnitStrc;

int gnSelectedUnitId_007A6A78;        // 0x007A6A78
int gnSelectedUnitType_007A6A8C;        // 0x007A6A8C
extern int gdwGlobal_007A6A94; // 0x007A6A94
extern int gdwGlobal_007A6A98; // 0x007A6A98

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
int __fastcall sub_00466870(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x00466870

// 0x00467A10
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
        return 0;
    }

    return 0;
}
