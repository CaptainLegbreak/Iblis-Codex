struct T00508FE0
{
    float x;
    float y;
    unsigned int dwColor;
    float oow;
    float sow;
    float tow;
    float unk0x18;
};

struct D2GlideSmackStrc
{
    void* f_0;
    unsigned char nType;
};

struct D2TileLibraryEntryStrc
{
    char unk0x00[0x42];
    short nCacheIndex;
};

struct D2GlideFloorCacheEntryStrc
{
    int unk0x00;
    int f_4;
    D2TileLibraryEntryStrc* pTile;
    D2GlideFloorCacheEntryStrc* pNext;
    D2GlideFloorCacheEntryStrc* pPrev;
};

struct D2GlideFloorCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideFloorCacheEntryStrc* pHead;
    D2GlideFloorCacheEntryStrc* pTail;
    D2GlideFloorCacheEntryStrc* f_14;
    D2GlideFloorCacheEntryStrc* f_18;
    D2GlideFloorCacheEntryStrc* pEntries;
};

struct D2GrTexInfoStrc
{
    int nSmallLodLog2;
    int nLargeLodLog2;
    int nAspectRatioLog2;
    int nFormat;
    unsigned char* pData;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack);                                   // 0x006CC608
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
D2GlideFloorCacheEntryStrc* __fastcall sub_0050F570_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F570

extern D2GrTexInfoStrc gGlideTileTexInfo_0072F6A8;                                                          // 0x0072F6A8
extern D2GrTexInfoStrc gGlideFloorTexInfo_0072F6BC;                                                         // 0x0072F6BC
extern unsigned char* gpGlideSmackBufferB_00880B70;                                                          // 0x00880B70
extern unsigned char* gpGlideSmackBufferC_00880B74;                                                          // 0x00880B74
extern T00508FE0 gaGlideSmackVertices_00880B78[4];                                                  // 0x00880B78
extern unsigned char* gpGlideSmackBuffer_00880BF0;                                                           // 0x00880BF0
extern unsigned char* gpGlideTileDecodeBuffer_00880BFC;                                                     // 0x00880BFC
extern unsigned char* gpGlideFloorDecodeBuffer_00880C00;                                                    // 0x00880C00

// 0x0050DF10
void __cdecl sub_0050DF10_GlideSmackInit()
{
    gaGlideSmackVertices_00880B78[0].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices_00880B78[1].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices_00880B78[2].dwColor = 0xFFFFFFFF;
    gaGlideSmackVertices_00880B78[3].dwColor = 0xFFFFFFFF;
    gpGlideSmackBufferB_00880B70 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x47, 0);
    gpGlideSmackBufferC_00880B74 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x48, 0);
    gpGlideSmackBuffer_00880BF0 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glSmack.cpp", 0x49, 0);
}

// 0x0050E040
void __fastcall sub_0050E040_GlideCloseSmacker(D2GlideSmackStrc* pRecord)
{
    if (pRecord->nType == 's' && pRecord->f_0)
    {
        SmackClose(pRecord->f_0);
        pRecord->f_0 = 0;
    }
    pRecord->nType = 0;
}

// 0x0050F750
void __fastcall sub_0050F750_FloorCacheRemove(D2GlideFloorCacheStrc* pCache, int nIndex)
{
    if (!pCache->nUsed)
        return;
    D2GlideFloorCacheEntryStrc* pEntry = sub_0050F570_FloorCacheUnlink(pCache, nIndex);
    if (pEntry)
    {
        D2TileLibraryEntryStrc* pTile = pEntry->pTile;
        D2_ASSERT(pTile, 0xF1);
        pTile->nCacheIndex = 0;
        pEntry->pTile = 0;
        if (!pCache->f_14)
        {
            pCache->f_14 = pEntry;
            pCache->f_18 = pEntry;
        }
        else
        {
            pCache->f_18->pNext = pEntry;
            pEntry->pPrev = pCache->f_18;
            pCache->f_18 = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F870
void __cdecl sub_0050F870_GlideBlocksInit()
{
    gpGlideTileDecodeBuffer_00880BFC = (unsigned char*)FOG_Alloc(0x400, ".\\Src\\glBlocks.cpp", 0x33, 0);
    gpGlideFloorDecodeBuffer_00880C00 = (unsigned char*)FOG_Alloc(0x8000, ".\\Src\\glBlocks.cpp", 0x34, 0);
    gGlideTileTexInfo_0072F6A8.pData = gpGlideTileDecodeBuffer_00880BFC;
    gGlideFloorTexInfo_0072F6BC.pData = gpGlideFloorDecodeBuffer_00880C00;
}
