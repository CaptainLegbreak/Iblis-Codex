void __cdecl sub_00477C00_ToggleCacheStats();                                                               // 0x00477C00

extern int gbCacheStats_007BB3A4;                                                                           // 0x007BB3A4
int gnGlobal_007BB3AC;                                                                                      // 0x007BB3AC

// 0x00477C60
void __cdecl sub_00477C60_CheckCacheStats()
{
    if (gnGlobal_007BB3AC || !gbCacheStats_007BB3A4)
        sub_00477C00_ToggleCacheStats();
    gnGlobal_007BB3AC = 1;
}
