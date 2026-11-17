struct D2UnitStrc
{
    char unk0x00[0xC4];
    unsigned int dwFlags;
};

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2); // 0x00456300
void __cdecl sub_004B3DE0_CloseNpc(); // 0x004B3DE0
void __cdecl sub_004C0440_Thunk(); // 0x004C0440
void __cdecl sub_004B3ED0(); // 0x004B3ED0
void __cdecl sub_0048A6A0_ResetNpcCursor(); // 0x0048A6A0
void __cdecl sub_004B2110_FreeResources(); // 0x004B2110
extern int gnGlobal_007C0C6B; // 0x007C0C6B
extern char gbGlobal_007C0C69; // 0x007C0C69

// 0x004B5320
void __fastcall sub_004B5320_OnUnitRemoved(unsigned char nUnitType, int nUnitId)
{
    D2UnitStrc* pUnit = 0;
    if (nUnitType < 6)
    {
        pUnit = sub_00463990(nUnitId, nUnitType);
    }

    switch (nUnitType)
    {
    case 1:
        if (pUnit)
        {
            pUnit->dwFlags |= 2;
        }

        if (gnGlobal_007C0C6B == 1)
        {
            gbGlobal_007C0C69 = 0;
            sub_004B3DE0_CloseNpc();
        }
        else if (gnGlobal_007C0C6B >= 3 && gnGlobal_007C0C6B <= 6)
        {
            sub_004B3ED0();
            sub_0048A6A0_ResetNpcCursor();
        }
        else if (gnGlobal_007C0C6B == 7)
        {
            sub_004C0440_Thunk();
        }
        else if (gbGlobal_007C0C69)
        {
            gbGlobal_007C0C69 = 0;
            sub_004B3DE0_CloseNpc();
        }

        sub_004B2110_FreeResources();
        gnGlobal_007C0C6B = 0;
        break;

    case 2:
    case 4:
    case 6:
        sub_00456300_CloseUIVars(1, 0);
        break;
    }
}
