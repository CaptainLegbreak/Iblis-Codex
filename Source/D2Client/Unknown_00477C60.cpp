void __cdecl VIEW_ToggleCacheStats();                                                               // 0x00477C00

extern int gbCacheStats;                                                                           // 0x007BB3A4
int gbCacheStatsChecked;                                                                                      // 0x007BB3AC

// 0x00477C60
void __cdecl sub_00477C60_CheckCacheStats()
{
    if (gbCacheStatsChecked || !gbCacheStats)
        VIEW_ToggleCacheStats();
    gbCacheStatsChecked = 1;
}
