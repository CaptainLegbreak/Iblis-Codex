struct D2ClientDialogStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC0];
    unsigned int dwFlags;
};

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_004B3C20(int nValue);                                                                   // 0x004B3C20
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020

extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern char gbGlobal_007C0C69;                                                                              // 0x007C0C69
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern D2ClientDialogStrc* gpDialog_007C0D73;                                                               // 0x007C0D73

// 0x004B3D10
void __fastcall sub_004B3D10_CancelAndFlag(int nUnitId)
{
    sub_004B3C20(nUnitId);
    D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
    }
}

// 0x004B3DE0
void __cdecl sub_004B3DE0_CloseNpc()
{
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}

// 0x004B3ED0
void __cdecl sub_004B3ED0()
{
    sub_00455F20(12, 1, 0);
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}

// 0x004B3FE0
void __cdecl sub_004B3FE0()
{
    gnGlobal_007C0C6B = 0;
    sub_00487990_ResetHover();
    sub_004B3C20(gnGlobal_007C0D25);
    sub_00455F20(8, 1, 0);
}

// 0x004B4070
int __cdecl sub_004B4070_ClosePanel73()
{
    if (gbGlobal_007C0C69)
    {
        return 0;
    }

    if (gpDialog_007C0D73)
    {
        sub_004B8020(gpDialog_007C0D73);
        gpDialog_007C0D73 = 0;
        gnGlobal_007C0C6B = 0;
        sub_00487990_ResetHover();
        sub_004B3C20(gnGlobal_007C0D25);
        sub_00455F20(8, 1, 0);
    }

    return 1;
}
