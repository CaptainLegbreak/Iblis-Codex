typedef unsigned short Unicode;
struct D2ClientDialogStrc;
struct D2UnitStrc { int unk_00[3]; int nUnitId; };
int __fastcall sub_004B9A00(int, D2UnitStrc*, int, int, int); // 0x004B9A00
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int, int, int (__cdecl*)(), int (__cdecl*)(), int, int, int, int, int, int, int); // 0x004B7EB0
void __fastcall sub_004B8370_SetField5C(D2ClientDialogStrc*, int); // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc*, const Unicode*, int, int, int, int, int (__cdecl*)(), int); // 0x004B85F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __fastcall sub_00478700_SendCommand(char, int, int, int, int); // 0x00478700
void __fastcall sub_004B2370_ConfirmLocal(int); // 0x004B2370
int __cdecl sub_004BF9B0_OnClose(); // 0x004BF9B0
extern int gnLocalMode_007C5470; // 0x007C5470
extern int gnDialogState_007C5474; // 0x007C5474
extern int gnArg_007C547C; // 0x007C547C
extern int gnArg_007C5480; // 0x007C5480
extern D2ClientDialogStrc* gpDialog_007C5484; // 0x007C5484

static __forceinline int GetUnitId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->nUnitId; }

// 0x004BFAF0
int __cdecl sub_004BFAF0_ShowConfirmation()
{
    if (gnDialogState_007C5474 == 2)
    {
    sub_004B9A00(2, 0, 0, 0, 0);
    gpDialog_007C5484 = sub_004B7EB0_CreateDialog(0x96, 0x82, sub_004BF9B0_OnClose, 0, 1, 0, 1, 0, 0, 0, 1);
    sub_004B8370_SetField5C(gpDialog_007C5484, 0);
    sub_004B85F0_AddTextLine(gpDialog_007C5484, D2LANG_GetStringFromTblIndex(0xD19), 15, 0, 0, 1, 0, 0);
    gnDialogState_007C5474 = 3;
    if (!gnLocalMode_007C5470)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        int nUnitId = !pPlayer ? -1 : pPlayer->nUnitId;
        sub_00478700_SendCommand(0x44, nUnitId, gnArg_007C547C, gnArg_007C5480, 3);
    }
    else
    {
        sub_004B2370_ConfirmLocal(gnArg_007C5480);
    }
    return 1;
    }
    return 0;
}
