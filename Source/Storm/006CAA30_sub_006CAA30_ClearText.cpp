extern unsigned short gwszText_007A2D30[256]; // 0x007A2D30

// 0x006CAA30
void __cdecl sub_006CAA30_ClearText()
{
    for (int i = 0; i < 256; ++i)
    {
        gwszText_007A2D30[i] = 0;
    }
}
