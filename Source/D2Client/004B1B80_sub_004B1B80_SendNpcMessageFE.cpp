struct D2UnitStrc;
struct D2ClientDialogStrc;

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext);                   // 0x0049E7E0
void __fastcall sub_004A10E0(D2UnitStrc* pUnit, unsigned short nMessage, int nArg);                         // 0x004A10E0
int __fastcall sub_004B18C0(void* pContext, int nArg, int nValue);                                          // 0x004B18C0
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020

extern char gbGlobal_007C0C69;                                                                              // 0x007C0C69
extern int gnGlobal_007C0D25;                                                                               // 0x007C0D25
extern int gnGlobal_007C0D29;                                                                               // 0x007C0D29
extern D2ClientDialogStrc* gpDialog_007C0D6F;                                                               // 0x007C0D6F

// 0x004B1B80
int __cdecl sub_004B1B80_SendNpcMessageFE()
{
    if (gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
    {
        D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
        sub_004A10E0(pNpc, 0xFE, 0);
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
        sub_004B8020(gpDialog_007C0D6F);
        gpDialog_007C0D6F = 0;
    }
    return 1;
}

// 0x004B1C00
int __cdecl sub_004B1C00_SendNpcMessage152()
{
    if (gnGlobal_007C0D29 && sub_00463990(gnGlobal_007C0D25, 1))
    {
        D2UnitStrc* pNpc = gnGlobal_007C0D29 ? sub_00463990(gnGlobal_007C0D25, 1) : 0;
        sub_004A10E0(pNpc, 0x152, 0);
        gbGlobal_007C0C69 = 1;
        sub_0049E7E0_SetTextCallback(sub_004B18C0, 0);
        sub_004B8020(gpDialog_007C0D6F);
        gpDialog_007C0D6F = 0;
    }
    return 1;
}
