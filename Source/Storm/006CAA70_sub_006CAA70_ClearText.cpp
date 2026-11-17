extern unsigned short gwszHoverName_007A2F38[256]; // 0x007A2F38

// 0x006CAA70
void __cdecl sub_006CAA70_ClearText()
{
    for (int i = 0; i < 256; ++i)
    {
        gwszHoverName_007A2F38[i] = 0;
    }
}
