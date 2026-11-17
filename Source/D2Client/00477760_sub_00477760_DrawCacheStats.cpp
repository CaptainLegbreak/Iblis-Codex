struct D2CacheStatsStrc
{
    unsigned int nFloorSize;
    int unk0x04;
    int nFloorMisses;
    unsigned int nSubtileSize;
    int unk0x10;
    int nSubtileMisses;
    unsigned int nSprite1Size;
    unsigned int nSprite2Size;
    unsigned int nSprite3Size;
    int unk0x24[3];
    int nSprite1Misses;
    int nSprite2Misses;
    int nSprite3Misses;
    int unk0x3C[3];
    int nSprite1Accesses;
    int nSprite2Accesses;
    int nSprite3Accesses;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
void __stdcall sub_005FE010_GetTileCacheStats(unsigned int* pSize, int* pMisses, int* pTotal, int* pUtilized); // 0x005FE010
D2CacheStatsStrc* __cdecl sub_004F5290_GetCacheStats();                                                     // 0x004F5290
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...);                           // 0x004F6890

// 0x00477760
void __cdecl sub_00477760_DrawCacheStats()
{
    char szText[0x400];
    int nTotal;
    int nMisses;
    int nUtilized;
    unsigned int nSize;
    sub_005FE010_GetTileCacheStats(&nSize, &nMisses, &nTotal, &nUtilized);
    if (nTotal > 0)
    {
        const float fPercent = (float)(nMisses * 100.0 / nTotal);
        sprintf(szText, "Tile Cache: (%.2fK) %3.2f%%, Misses: %d, %d percent utilized\n", (float)nSize * 0.0009765625, fPercent, nMisses, nUtilized);
        D2GFX_OutputString(10, 0x30, szText);
    }
    D2CacheStatsStrc* pStats = sub_004F5290_GetCacheStats();
    if (!pStats)
        return;
    if (pStats->nFloorSize)
    {
        sprintf(szText, "Floor Cache: (%.2fK) Misses: %d\n", (float)pStats->nFloorSize * 0.0009765625, pStats->nFloorMisses);
        D2GFX_OutputString(10, 0x3C, szText);
    }
    if (pStats->nSubtileSize)
    {
        sprintf(szText, "Subtile Cache: (%.2fK) Misses: %d\n", (float)pStats->nSubtileSize * 0.0009765625, pStats->nSubtileMisses);
        D2GFX_OutputString(10, 0x48, szText);
    }
    if (pStats->nSprite1Size)
    {
        sprintf(szText, "Sprite Cache 1: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSprite1Size * 0.0009765625, pStats->nSprite1Misses, pStats->nSprite1Accesses);
        D2GFX_OutputString(10, 0x54, szText);
    }
    if (pStats->nSprite2Size)
    {
        sprintf(szText, "Sprite Cache 2: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSprite2Size * 0.0009765625, pStats->nSprite2Misses, pStats->nSprite2Accesses);
        D2GFX_OutputString(10, 0x60, szText);
    }
    if (pStats->nSprite3Size)
    {
        sprintf(szText, "Sprite Cache 3: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSprite3Size * 0.0009765625, pStats->nSprite3Misses, pStats->nSprite3Accesses);
        D2GFX_OutputString(10, 0x6C, szText);
    }
}
