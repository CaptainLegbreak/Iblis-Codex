unsigned char gaScaleTable_00971740[256][256];        // 0x00971740

// 0x006B96C0
void __cdecl sub_006B96C0_BuildScaleTable()
{
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            gaScaleTable_00971740[i][j] = (unsigned char)((i * j) / 255);
        }
    }
}
