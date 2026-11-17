struct Unicode;
struct D2ClientDialogStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
void __cdecl sub_00487B30();                                                                                // 0x00487B30
void __cdecl sub_0048A6F0_ClearValue();                                                                     // 0x0048A6F0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370(void* pPanel, int nValue);                                                     // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8);                                                                   // 0x004B85F0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex);                               // 0x004B82F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __cdecl sub_004B8A30_OnCancel();                                                                        // 0x004B8A30
int __cdecl sub_004B8A80_OnClose();                                                                         // 0x004B8A80

D2ClientDialogStrc* gpDialog_007C0E64;                                                                      // 0x007C0E64
unsigned long gdwGlobal_007C0E68;                                                                           // 0x007C0E68
extern D2ClientDialogStrc* gpDialog_007C0E6C;                                                               // 0x007C0E6C
extern unsigned long gdwTick_007C0E70;                                                                      // 0x007C0E70
char gbGlobal_007C0E74;                                                                                     // 0x007C0E74
extern unsigned long gdwGlobal_007C0E78;                                                                    // 0x007C0E78
int gnGlobal_007C0E7C;                                                                                      // 0x007C0E7C
char gbGlobal_007C0E80;                                                                                     // 0x007C0E80

// 0x004B8720
void __cdecl sub_004B8720()
{
    gnGlobal_007C0E7C = 0;
    gbGlobal_007C0E74 = 0;
}

// 0x004B8920
void __cdecl sub_004B8920()
{
    gdwGlobal_007C0E78 = 0;
    gdwGlobal_007C0E68 = 0;
    gbGlobal_007C0E80 = 1;
}

// 0x004B8940
void __fastcall sub_004B8940_CloseWait(int bReopen)
{
    gbGlobal_007C0E80 = 0;
    if (gpDialog_007C0E6C)
    {
        sub_004B8020(gpDialog_007C0E6C);
        gpDialog_007C0E6C = 0;
    }

    if (gpDialog_007C0E64)
    {
        sub_004B8020(gpDialog_007C0E64);
        gpDialog_007C0E64 = 0;
    }

    if (gnGlobal_007C0E7C == 7)
    {
        return;
    }

    if (sub_004538D0(0x17))
    {
        sub_00455F20(0x17, 1, 0);
        sub_0048A6F0_ClearValue();
        sub_00487B30();
        if (!sub_00463DF0() && bReopen)
        {
            sub_00455F20(1, 2, 0);
        }

        if (sub_004538D0(5))
        {
            sub_00455F20(5, 1, 0);
        }
    }

    if (gnGlobal_007C0E7C)
    {
        sub_00478600_SendShorts(0x4F, 2, 0, 0);
        gnGlobal_007C0E7C = 0;
    }
}

// 0x004B8AD0
int __cdecl sub_004B8AD0_OpenWait()
{
    if (gpDialog_007C0E64)
    {
        return 0;
    }

    gpDialog_007C0E64 = sub_004B7EB0_CreateDialog(0x140, 0x64, sub_004B8A80_OnClose, sub_004B8A80_OnClose, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370(gpDialog_007C0E64, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0E64, D2LANG_GetStringFromTblIndex(0xFCA), 0xF, 0, 0, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C0E64, D2LANG_GetStringFromTblIndex(0xD49), 0xF, 0, 0, 1, sub_004B8A30_OnCancel, 1);
    sub_004B85F0_AddTextLine(gpDialog_007C0E64, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B8A80_OnClose, 1);
    sub_004B82F0_Select(gpDialog_007C0E64, -1);
    return 1;
}

// 0x004B8CB0
void __cdecl sub_004B8CB0()
{
    sub_00478600_SendShorts(0x4F, 2, 0, 0);
    if (gnGlobal_007C0E7C != 7)
    {
        gbGlobal_007C0E74 = 1;
        gdwTick_007C0E70 = GetTickCount();
        gnGlobal_007C0E7C = 7;
    }
}

// 0x004B9070
void __cdecl sub_004B9070_SendPosition()
{
    gnGlobal_007C0E7C = 7;
    sub_00478600_SendShorts(0x4F, 4, (unsigned short)(gdwGlobal_007C0E68 >> 16), (unsigned short)gdwGlobal_007C0E68);
    gdwTick_007C0E70 = 0xFFFFFFFF;
}
