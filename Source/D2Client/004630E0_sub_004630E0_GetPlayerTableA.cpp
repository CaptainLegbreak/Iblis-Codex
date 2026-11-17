extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2UnitStrc;

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __stdcall sub_0063E510_FillInventoryTables(D2UnitStrc* pUnit, unsigned char* pTableA, unsigned char* pTableB); // 0x0063E510

// 0x004630E0
int __fastcall sub_004630E0_GetPlayerTableA(unsigned char* pTable, unsigned int nSize)
{
    unsigned char aOther[16];
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (nSize < sizeof(aOther) || !pPlayer)
        return 0;
    memset(pTable, 0xFF, sizeof(aOther));
    sub_0063E510_FillInventoryTables(pPlayer, pTable, aOther);
    return 1;
}

// 0x00463130
int __fastcall sub_00463130_GetPlayerTableB(unsigned char* pTable, unsigned int nSize)
{
    unsigned char aOther[16];
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (nSize < sizeof(aOther) || !pPlayer)
        return 0;
    memset(pTable, 0xFF, sizeof(aOther));
    sub_0063E510_FillInventoryTables(pPlayer, aOther, pTable);
    return 1;
}
