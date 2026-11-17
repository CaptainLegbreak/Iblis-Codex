extern unsigned short gwszName_007BCEA8[4096]; // 0x007BCEA8

// 0x006CABF0
void __cdecl sub_006CABF0_ClearText()
{
    for (int i = 0; i < 4096; ++i)
    {
        gwszName_007BCEA8[i] = 0;
    }
}
