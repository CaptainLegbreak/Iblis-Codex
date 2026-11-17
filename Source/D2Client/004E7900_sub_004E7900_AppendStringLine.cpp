const wchar_t* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
wchar_t* __fastcall sub_00526700(wchar_t* pDest, const wchar_t* pSource);                                 // 0x00526700

// 0x004E7900
static __declspec(noinline) int sub_004E7900_AppendStringLine(wchar_t* wszOut, unsigned short wStr)
{
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

void __stdcall sub_M24_Emit_004E7900(wchar_t* wszOut, unsigned short wStr, int nOther)
{
    if (nOther)
        sub_004E7900_AppendStringLine(wszOut, wStr);
}
