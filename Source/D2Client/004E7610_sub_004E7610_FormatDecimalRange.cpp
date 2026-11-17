extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
void __fastcall sub_00526320_ToUnicode(wchar_t* pDest, const char* szSource, int nLength);                  // 0x00526320

// 0x004E7610
static void __stdcall sub_004E7610_FormatDecimalRange(wchar_t* wszText, int bPrefixSign, int nMin, int nMinFrac, int nMax, int nMaxFrac)
{
    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, "+%d.%d-%d.%d", nMin, nMinFrac, nMax, nMaxFrac);
    else
        wsprintfA(szText, "%d.%d-%d.%d", nMin, nMinFrac, nMax, nMaxFrac);
    sub_00526320_ToUnicode(wszText, szText, 32);
}

extern "C" void __stdcall sub_K07_EmitB(wchar_t* p, int b, int a1, int a2, int a3, int a4)
{
    sub_004E7610_FormatDecimalRange(p, b, a1, a2, a3, a4);
}
