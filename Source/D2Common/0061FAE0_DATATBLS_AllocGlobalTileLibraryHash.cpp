struct D2TileLibraryHeaderStrc;

struct D2LvlTypesTxt
{
    char szFile[32][60];
    unsigned char nAct;
    unsigned char pad0x781[3];
    unsigned int dwExpansion;
};

static D2LvlTypesTxt* gpLvlTypesTxt_0096C9F0;                                                               // 0x0096C9F0
static int gnLvlTypesTxtRecordCount_0096C9FC;                                                               // 0x0096C9FC
static D2TileLibraryHeaderStrc** gppTileLibraryHash_0096CA1C;                                               // 0x0096CA1C

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" int __cdecl strcmp(const char* s1, const char* s2);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
void __stdcall DT1_ListAdd(D2TileLibraryHeaderStrc** ppList, const char* szFilePath);                      // 0x00604A40

// 0x0061FAE0
void __fastcall DATATBLS_AllocGlobalTileLibraryHash()
{
    D2_ASSERT(gpLvlTypesTxt_0096C9F0, 1040);

    const int nSize = sizeof(D2TileLibraryHeaderStrc*[1024]) * gnLvlTypesTxtRecordCount_0096C9FC;
    gppTileLibraryHash_0096CA1C = (D2TileLibraryHeaderStrc**)FOG_AllocPool(0, nSize, ".\\DATATBLS\\LvlTbls.cpp", 1043, 0);
    memset(gppTileLibraryHash_0096CA1C, 0, nSize);

    D2TileLibraryHeaderStrc** ppTileLibraryHash = gppTileLibraryHash_0096CA1C;
    const int bExpansion = sub_00408F20_HasExpansionMpq();
    for (int i = 0; i < gnLvlTypesTxtRecordCount_0096C9FC; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            if (!strcmp(gpLvlTypesTxt_0096C9F0[i].szFile[j], "0"))
            {
                break;
            }

            if (bExpansion || !gpLvlTypesTxt_0096C9F0[i].dwExpansion)
            {
                DT1_ListAdd(ppTileLibraryHash, gpLvlTypesTxt_0096C9F0[i].szFile[j]);
            }
        }
        ppTileLibraryHash += 1024;
    }
}

void sub_W12_EmitLvlTypesTxtWrites(D2LvlTypesTxt* pLvlTypesTxt, int nRecordCount)
{
    gpLvlTypesTxt_0096C9F0 = pLvlTypesTxt;
    gnLvlTypesTxtRecordCount_0096C9FC = nRecordCount;
}
