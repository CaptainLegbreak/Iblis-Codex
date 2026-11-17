extern unsigned char* gpMulTable_00880B5C; // 0x00880B5C

// 0x0050DB70
void __cdecl sub_0050DB70_BuildMulTable()
{
    for (int y = 0; y < 256; ++y)
    {
        for (int x = 0; x < 256; ++x)
        {
            gpMulTable_00880B5C[y * 256 + x] = (unsigned char)(x * y / 255);
        }
    }
}
