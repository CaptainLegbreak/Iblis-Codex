struct Unicode
{
    unsigned short wChar;
};

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
extern "C" const char szEndCharsS_006E03A8[];                                                      // 0x006E03A8

// 0x005271A0
static bool sub_005271A0_EndsWithCharOf(const char* szChars, const Unicode* pText)
{
    Unicode wszChars[20] = {};
    int i;
    for (i = 0; i < 20 && szChars[i] != '\0'; ++i)
    {
        wszChars[i].wChar = (unsigned char)szChars[i];
    }
    if (szChars[i] != '\0')
    {
        wszChars[i - 1].wChar = 0;
    }
    else
    {
        wszChars[i].wChar = 0;
    }
    const int nLength = sub_00526800(wszChars);
    const int nTextLength = sub_00526800(pText);
    for (int j = 0; j < nLength; ++j)
    {
        if (pText[nTextLength - 1].wChar == wszChars[j].wChar)
        {
            return true;
        }
    }
    return false;
}

void __fastcall sub_I11_Emit_005271A0(Unicode* pDst, const Unicode* pText)
{
    sub_005267E0(pDst, pText);
    if (sub_005271A0_EndsWithCharOf(szEndCharsS_006E03A8, pText))
    {
        sub_005267E0(pDst, pText);
    }
}
