static __declspec(noinline) void sub_006BCD50_MakeCode(const char* szText, char* szCode);

// 0x006BCD50
static void sub_006BCD50_MakeCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

// calling-convention shim (not game code)
unsigned int __stdcall sub_006BCD50_Shim(const char* szText)
{
    unsigned int dwCode;
    sub_006BCD50_MakeCode(szText, (char*)&dwCode);
    return dwCode;
}
