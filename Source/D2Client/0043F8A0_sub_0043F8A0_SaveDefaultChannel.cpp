int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

// 0x0043F8A0
static __forceinline void sub_0043F8A0_SaveDefaultChannel(const char* szChannel)
{
    SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
}

void __stdcall sub_M113_Emit_0043F8A0(const char* szFirst, const char* szSecond)
{
    sub_0043F8A0_SaveDefaultChannel(szFirst);
    sub_0043F8A0_SaveDefaultChannel(szSecond);
}
