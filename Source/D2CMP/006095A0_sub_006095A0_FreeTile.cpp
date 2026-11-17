extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

struct D2CmpTileNodeStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    void* pData;
    D2CmpTileNodeStrc* pNext;
};

struct D2CmpTileStrc
{
    char unk0x00[0x58];
    D2CmpTileNodeStrc* pNodes;
    D2CmpTileStrc* pNext;
};

struct D2CmpTileListStrc
{
    int unk0x00;
    int nId;
    int nCount;
    D2CmpTileStrc* pFirst;
};

// 0x006095A0
static void sub_006095A0_FreeTile(D2CmpTileStrc* pTile)
{
    D2_ASSERT(pTile, 0x54);
    D2CmpTileNodeStrc* pNode = pTile->pNodes;
    while (pNode)
    {
        D2CmpTileNodeStrc* pNext = pNode->pNext;
        if (pNode->pData)
        {
            FOG_Free(pNode->pData, ".\\SRC\\Tilecmp.cpp", 0x35, 0);
        }
        FOG_Free(pNode, ".\\SRC\\Tilecmp.cpp", 0x38, 0);
        pNode = pNext;
    }
    FOG_Free(pTile, ".\\SRC\\Tilecmp.cpp", 0x60, 0);
}

// 0x00609670
void __stdcall sub_00609670_FreeTileList(D2CmpTileListStrc* pList)
{
    D2_ASSERT(pList, 0x80);
    D2CmpTileStrc* pTile = pList->pFirst;
    while (pTile)
    {
        D2CmpTileStrc* pNext = pTile->pNext;
        sub_006095A0_FreeTile(pTile);
        pTile = pNext;
    }
    FOG_Free(pList, ".\\SRC\\Tilecmp.cpp", 0x8C, 0);
}
