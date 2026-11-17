extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef void (__stdcall* D2CmpColorCallback)(unsigned int nColor);

struct D2CmpTileSubStrc
{
    int unk0x00;
    int unk0x04;
    short unk0x08;
    unsigned short nSize;
    int unk0x0C;
    unsigned char* pData;
};

struct D2CmpTileBlockStrc
{
    char unk0x00[0x48];
    int f_48;
    int nSubBytes;
    int nSubs;
    D2CmpTileSubStrc* pSubs;
    char* pName;
    void* pExtra;
};

struct D2CmpTileLibraryStrc
{
    int nVersion;
    unsigned int dwFlags;
    char szName[0x104];
    int nBlocks;
    D2CmpTileBlockStrc* pBlocks;
};

// 0x0060A520
static void sub_0060A520_ForEachDataColor(D2CmpColorCallback pfnColor, const unsigned char* pData, int nSize)
{
    for (int i = 0; i < nSize; i += 3)
    {
        pfnColor((((pData[2] << 8) + pData[1]) << 8) + pData[0]);
        pData += 3;
    }
}

// 0x0060A570
void __stdcall sub_0060A570_ForEachLibraryColor(D2CmpTileLibraryStrc* pLibrary, D2CmpColorCallback pfnColor)
{
    D2_ASSERT(pLibrary, 0x3EA);
    D2_ASSERT(pLibrary->dwFlags & 1, 0x3EB);
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        for (int j = 0; j < pBlock->nSubs; j++)
        {
            D2CmpTileSubStrc* pSub = &pBlock->pSubs[j];
            sub_0060A520_ForEachDataColor(pfnColor, pSub->pData, pSub->nSize);
        }
    }
}
