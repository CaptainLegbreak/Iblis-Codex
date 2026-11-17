extern unsigned short gwszText_007A2C80[80]; // 0x007A2C80

// 0x006CAA10
void __cdecl sub_006CAA10_ClearText()
{
    for (int i = 0; i < 80; ++i)
    {
        gwszText_007A2C80[i] = 0;
    }
}
