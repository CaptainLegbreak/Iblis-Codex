struct D2TileLibraryEntryStrc
{
    char unk0x00[0x50];
    void* pUnk0x50;
    void* pUnk0x54;
    char unk0x58[0x08];
};

struct D2TileLibraryHeaderStrc
{
    int dwVersion;
    int dwFlags;
    char szLibraryName[260];
    int nTiles;
    D2TileLibraryEntryStrc* pFirst;
};

extern "C" const char gszEmptyAssertText;                                                    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                       // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);          // 0x006829C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                // 0x0040B380
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0060A910
void __stdcall sub_0060A910_CopyTileLibrary(D2TileLibraryHeaderStrc* pSource, D2TileLibraryHeaderStrc** ppCopy, int* pnSize)
{
    D2_ASSERT(pSource, 1171);

    int nSize = sizeof(D2TileLibraryHeaderStrc) + pSource->nTiles * sizeof(D2TileLibraryEntryStrc);
    D2TileLibraryHeaderStrc* pCopy = (D2TileLibraryHeaderStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 1178, 0);
    D2_ASSERT(pCopy, 1179);

    memset(pCopy, 0, nSize);
    memcpy(pCopy, pSource, nSize);
    D2TileLibraryEntryStrc* pEntries = (D2TileLibraryEntryStrc*)(pCopy + 1);
    pCopy->pFirst = pEntries;
    for (int i = 0; i < pCopy->nTiles; ++i)
    {
        pEntries[i].pUnk0x54 = 0;
        pEntries[i].pUnk0x50 = 0;
    }
    pCopy->dwFlags &= 4;

    *ppCopy = pCopy;
    *pnSize = nSize;
}
