extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385

// 0x0051DCD0
static void __stdcall sub_0051DCD0_EncodeChar(char* pChar, unsigned int* pBits, int nFlag)
{
    const char ch = (char)toupper(*pChar);
    *pChar = ch;
    if (ch <= 0x37)
    {
        *pChar = (char)((*pBits & 7) ^ ch);
        *pBits >>= 3;
    }
    else if (ch < 0x41)
    {
        *pChar = (char)((nFlag & 1) ^ ch);
    }
}

extern "C" void __stdcall sub_K08_EmitEncodeChar(char* pText, unsigned int* pBits, int nFlag)
{
    sub_0051DCD0_EncodeChar(pText, pBits, nFlag);
    sub_0051DCD0_EncodeChar(pText + 1, pBits, nFlag);
}
