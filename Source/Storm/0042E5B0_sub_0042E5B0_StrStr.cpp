struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue);
};

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __stdcall sub_0043A460(const Unicode* pTitle, Unicode* pText, int nArg3, int nArg4);                   // 0x0043A460
extern int gdwGlobal_00779DC4;                                                                              // 0x00779DC4
extern int gdwGlobal_0070CC08;                                                                              // 0x0070CC08

// 0x0042E5B0
char* __cdecl sub_0042E5B0_StrStr(char* szString, const char* szSubString)
{
    return strstr(szString, szSubString);
}

// build: symbol ??0Unicode@@QAE@G@Z 0x0042E600
Unicode::Unicode(unsigned short wValue)
{
    wChar = wValue;
}

// 0x004303E0
bool __stdcall sub_004303E0_IsLineBreak(Unicode wc)
{
    if (wc.wChar == 13 || wc.wChar == 10)
        return true;
    return false;
}

// 0x0043A610
void __cdecl sub_0043A610_ShowString()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x2B3B);
    Unicode wEmpty;
    wEmpty.wChar = 0;
    gdwGlobal_0070CC08 = gdwGlobal_00779DC4;
    sub_0043A460(pTitle, &wEmpty, 2, 0x12);
}
