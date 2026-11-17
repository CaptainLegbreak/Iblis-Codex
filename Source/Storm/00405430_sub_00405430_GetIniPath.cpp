int __fastcall sub_00406B60_GetModuleDirectory(char* szPath, int nSize);                                    // 0x00406B60
unsigned int __stdcall sub_00413800(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800

// 0x00405430
static __forceinline void sub_00405430_GetIniPath(char* szPath)
{
    sub_00406B60_GetModuleDirectory(szPath, 0x104);
    sub_00413800(szPath, "D2.ini", 0x104);
}

void __stdcall sub_M114_Emit_00405430(char* szPath)
{
    sub_00405430_GetIniPath(szPath);
}
