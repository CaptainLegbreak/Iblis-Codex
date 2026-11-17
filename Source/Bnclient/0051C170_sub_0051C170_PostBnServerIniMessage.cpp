int __fastcall sub_0051E3D0_PostMessage(const char* szText, int nCode);                                     // 0x0051E3D0
int __fastcall sub_005202F0_QueueText(int nId, const char* szText);                                         // 0x005202F0

// 0x0051C170
int __cdecl sub_0051C170_PostBnServerIniMessage()
{
    return sub_0051E3D0_PostMessage("bnserver-D2DV.ini", 0x80000004);
}

// 0x0051C6B0
int __fastcall sub_0051C6B0_QueueTextLine(const char* szText)
{
    return sub_005202F0_QueueText(1, szText);
}

// 0x0051CA20
char __cdecl sub_0051CA20_GetGatewayLetter()
{
    return 'G';
}
