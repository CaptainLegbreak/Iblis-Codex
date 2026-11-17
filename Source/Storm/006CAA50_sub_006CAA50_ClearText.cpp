extern unsigned short gwszText_007A2A78[256]; // 0x007A2A78

// 0x006CAA50
void __cdecl sub_006CAA50_ClearText()
{
    for (int i = 0; i < 256; ++i)
    {
        gwszText_007A2A78[i] = 0;
    }
}
