// 0x00504020
int* __fastcall sub_00504020_ClearTable(int* table)
{
    for (int i = 0; i < 128; ++i)
        table[i] = 0;
    return table;
}
