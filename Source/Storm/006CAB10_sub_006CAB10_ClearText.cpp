extern unsigned short gwChatHistory_007BB840[2056]; // 0x007BB840

// 0x006CAB10
void __cdecl sub_006CAB10_ClearText()
{
    for (int i = 0; i < 2056; ++i)
    {
        gwChatHistory_007BB840[i] = 0;
    }
}
