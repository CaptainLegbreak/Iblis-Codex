struct D2UnitStrc
{
    int unk_00[3];
    int nUnitId;
};
extern unsigned int gnDialogAmount_007A2A68; // 0x007A2A68
unsigned short gwDialogAmountHigh_007A2A6A;        // 0x007A2A6A
int gnDialogMode_007A279C;        // 0x007A279C
void __cdecl sub_00453EE0_ClosePanel(); // 0x00453EE0
void __fastcall sub_004B9110_TransferGold(unsigned int nAmount); // 0x004B9110
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2); // 0x004786A0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

static __forceinline int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->nUnitId;
}

// 0x00454080
int __cdecl sub_00454080_ConfirmGoldDialog()
{
    sub_00453EE0_ClosePanel();
    if (!gnDialogAmount_007A2A68)
    {
        if (gnDialogMode_007A279C == 2)
            sub_004B9110_TransferGold(gnDialogAmount_007A2A68);
        return 1;
    }
    switch (gnDialogMode_007A279C)
    {
    case 0:
    case 1:
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        int nId = GetUnitId(pPlayer);
        sub_004786A0_SendIntInt(0x50, nId, gnDialogAmount_007A2A68);
        return 1;
    }
    case 2:
        sub_004B9110_TransferGold(gnDialogAmount_007A2A68);
        break;
    case 4:
        sub_00478600_SendShorts(0x4F, 0x13, gwDialogAmountHigh_007A2A6A, gnDialogAmount_007A2A68);
        break;
    case 3:
        sub_00478600_SendShorts(0x4F, 0x14, gwDialogAmountHigh_007A2A6A, gnDialogAmount_007A2A68);
        break;
    default:
        return 1;
    }
    sub_004B9A00(0xDD, 0, 0, 0, 0);
    return 1;
}
