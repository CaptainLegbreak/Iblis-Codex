struct Unicode
{
    unsigned short wChar;

    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);                      // 0x00526F20
};

int __fastcall sub_0043E630_ShowChannelText(Unicode* pText);                                                // 0x0043E630

// 0x00446B30
int __fastcall sub_00446B30_ShowText(int nArg, const char* szText)
{
    Unicode wszText[0x240];
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    Unicode::win2Unicode(wszText, szText, 0x240);
    sub_0043E630_ShowChannelText(wszText);
    return 1;
}
