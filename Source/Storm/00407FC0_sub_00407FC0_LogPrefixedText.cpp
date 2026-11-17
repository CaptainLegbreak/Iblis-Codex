void __cdecl sub_004106B0_LogWritePrefixed0(const char* szPrefix, const char* szFormat, ...);               // 0x004106B0
void __cdecl sub_00410740_LogWritePrefixed00(const char* szPrefix, const char* szFormat, ...);              // 0x00410740
extern "C" const char gszPercentS_006FFC58[];                                                               // 0x006FFC58

// 0x00407FC0
static void __stdcall sub_00407FC0_LogPrefixedText(const char* szPrefix, const char* szText, int bFlag)
{
    if (bFlag)
    {
        sub_004106B0_LogWritePrefixed0(szPrefix, gszPercentS_006FFC58, szText);
    }
    else
    {
        sub_00410740_LogWritePrefixed00(szPrefix, gszPercentS_006FFC58, szText);
    }
}

void __stdcall sub_K01_Emit_00407FC0(const char* szPrefix, const char* szText, int bFlag)
{
    sub_00407FC0_LogPrefixedText(szPrefix, szText, bFlag);
}
