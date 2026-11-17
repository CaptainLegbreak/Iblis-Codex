struct D2UnitStrc;
extern int gnGlobal_007C0E7C;                                                                               // 0x007C0E7C
extern unsigned long gdwGlobal_007C0E68;                                                                    // 0x007C0E68
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
void __fastcall sub_004B8940(int nArg);                                                                     // 0x004B8940
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

// 0x004B9110
void __fastcall sub_004B9110_SendGoldRequest(unsigned long nGold)
{
    if (gnGlobal_007C0E7C == 4 || gnGlobal_007C0E7C == 5 || gnGlobal_007C0E7C == 6)
    {
        sub_00478600_SendShorts(0x4F, 7, 0, 0);
        gnGlobal_007C0E7C = 3;
        return;
    }

    const unsigned long nMaxGold = STATLIST_UnitGetStatValue(sub_00463DD0(), 0x0E, 0);
    if (nGold >= nMaxGold)
    {
        gdwGlobal_007C0E68 = nMaxGold;
        sub_00478600_SendShorts(0x4F, 8, nMaxGold >> 0x10, nMaxGold);
    }
    else
    {
        gdwGlobal_007C0E68 = nGold;
        sub_00478600_SendShorts(0x4F, 8, nGold >> 0x10, nGold);
    }
}

// 0x004B91F0
void __cdecl sub_004B91F0()
{
    sub_004B8940(0);
}
