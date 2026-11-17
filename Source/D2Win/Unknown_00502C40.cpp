// 0x00502C40
int* __fastcall sub_00502C40_ClearTable(int* pTable)
{
    for (int i = 0; i < 0x200; ++i)
    {
        pTable[i] = 0;
    }
    return pTable;
}
