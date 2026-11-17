struct D2GlideTexCacheEntryStrc;
struct D2GlideTileCacheStrc;
struct D2GlideFloorCacheStrc;

struct D2GlideTexCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTexCacheEntryStrc* pHead;
    D2GlideTexCacheEntryStrc* pTail;
    D2GlideTexCacheEntryStrc* f_14;
    D2GlideTexCacheEntryStrc* f_18;
    D2GlideTexCacheEntryStrc* pEntries;
};

int __cdecl sub_00508970_GlideLoadLibrary();                                                                // 0x00508970
void __fastcall sub_0050ECB0_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush);                      // 0x0050ECB0
void __fastcall sub_0050F210_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush);                    // 0x0050F210
void __fastcall sub_0050F7C0_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush);                  // 0x0050F7C0

extern int (__stdcall* gpfGlideGet_0087EB1C)(int nName, int nSize, int* pParams);                          // 0x0087EB1C
int gnGlideNumBoards_0087EFC4;                                                                              // 0x0087EFC4
extern D2GlideTileCacheStrc gGlideTileCache_0087EB48;                                                       // 0x0087EB48
extern D2GlideFloorCacheStrc gGlideFloorCache_0087EB68;                                                     // 0x0087EB68
extern D2GlideTexCacheStrc gaGlideTexCaches_0087F048[4];                                                    // 0x0087F048

// 0x00508F60
int __cdecl sub_00508F60_GlideCheckBoards()
{
    if (!sub_00508970_GlideLoadLibrary())
    {
        return 0;
    }

    gpfGlideGet_0087EB1C(0xF, 4, &gnGlideNumBoards_0087EFC4);
    return gnGlideNumBoards_0087EFC4 > 0;
}

// 0x00508F90
void __cdecl sub_00508F90_GlideDestroyTexCaches()
{
    sub_0050F7C0_FloorCacheDestroy(&gGlideFloorCache_0087EB68, 0);
    sub_0050F210_TileCacheDestroy(&gGlideTileCache_0087EB48, 0);
    sub_0050ECB0_TexCacheDestroy(&gaGlideTexCaches_0087F048[1], 0);
    sub_0050ECB0_TexCacheDestroy(&gaGlideTexCaches_0087F048[2], 0);
    sub_0050ECB0_TexCacheDestroy(&gaGlideTexCaches_0087F048[3], 0);
}
