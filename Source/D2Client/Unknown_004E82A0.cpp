typedef wchar_t Unicode;
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

__declspec(noinline) static int __stdcall sub_004E82A0_AppendSecondsTwentieths(unsigned short wStr, Unicode* wszOut, int nValue);

// 0x004E82A0
static int __stdcall sub_004E82A0_AppendSecondsTwentieths(unsigned short wStr, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    const int nTenths = nValue * 20 / 3;
    const int nFraction = nTenths % 10;
    int nWhole = nTenths / 10;
    if (nWhole < 1)
        nWhole = 1;
    if (nWhole || nFraction)
    {
        int szText_[8]; char* const szText = (char*)szText_;
        if (nFraction)
            wsprintfA(szText, "%d.%d", nWhole, nFraction);
        else
            wsprintfA(szText, gszFormatD_006D57BC, nWhole);
        sub_00526320_ToUnicode(wszText, szText, 32);
    }
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    if (nWhole == 1)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10C0));
    else
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10B6));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

int __fastcall sub_Emit_004E82A0(Unicode* wszOut, int nValue, int nStr)
{
    if (!wszOut)
        return 0;
    return sub_004E82A0_AppendSecondsTwentieths((unsigned short)nStr, wszOut, nValue);
}
