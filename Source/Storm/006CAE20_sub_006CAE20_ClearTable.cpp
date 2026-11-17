extern unsigned int gaTable_00841EC8[0x200]; // 0x00841EC8

// 0x006CAE20
void __cdecl sub_006CAE20_ClearTable()
{
    for (int i = 0; i < 0x200; ++i)
    {
        gaTable_00841EC8[i] = 0;
    }
}
