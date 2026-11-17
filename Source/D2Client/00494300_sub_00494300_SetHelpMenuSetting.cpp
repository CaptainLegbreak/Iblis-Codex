int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
extern unsigned long gdwHelpMenu_00722310;                                                                  // 0x00722310

// 0x00494300
static __forceinline void sub_00494300_SetHelpMenuSetting(unsigned long dwValue)
{
    gdwHelpMenu_00722310 = dwValue;
    SRegSaveValue("Diablo II", "Help Menu", 1, dwValue);
}

void __fastcall sub_M115_Emit_00494300(unsigned long dwValue)
{
    sub_00494300_SetHelpMenuSetting(dwValue);
}
