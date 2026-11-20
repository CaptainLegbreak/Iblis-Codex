#include "D2CMP.h"
#include "D2CmpTypes.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
unsigned char __fastcall sub_0060CD70_WrapIndex(int a, int b, int c);                                       // 0x0060CD70


struct D2FindTileNodeStrc
{
    D2CmpTileBlockStrc* pTile;
    D2FindTileNodeStrc* pNext;
};

struct D2FindTileEntryStrc
{
    int nKey2;
    int nKey3;
    int nKey1;
    D2FindTileNodeStrc* pTileList;
    D2FindTileEntryStrc* pNext;
};

// 0x0060CEA0
static void sub_0060CEA0_AddTileToEntry(D2FindTileEntryStrc* pEntry, D2CmpTileBlockStrc* pTile)
{
    for (D2FindTileNodeStrc* pNode = pEntry->pTileList; pNode; pNode = pNode->pNext)
    {
        if (pNode->pTile == pTile)
        {
            return;
        }
    }
    D2FindTileNodeStrc* pNode = (D2FindTileNodeStrc*)FOG_Alloc(sizeof(D2FindTileNodeStrc), ".\\SRC\\FindTiles.cpp", 0x6E, 0);
    D2_ASSERT(pNode, 0x6F);
    memset(pNode, 0, sizeof(D2FindTileNodeStrc));
    pNode->pTile = pTile;
    pNode->pNext = pEntry->pTileList;
    pEntry->pTileList = pNode;
}

// 0x0060CF00
static void sub_0060CF00_AddEntry(D2FindTileEntryStrc** ppBucket, D2CmpTileBlockStrc* pTile)
{
    D2FindTileEntryStrc* pEntry = (D2FindTileEntryStrc*)FOG_Alloc(sizeof(D2FindTileEntryStrc), ".\\SRC\\FindTiles.cpp", 0x82, 0);
    D2_ASSERT(pEntry, 0x83);
    memset(pEntry, 0, sizeof(D2FindTileEntryStrc));
    pEntry->nKey3 = pTile->nValue2C;
    pEntry->nKey2 = pTile->nValue28;
    pEntry->nKey1 = pTile->nValue24;
    pEntry->pNext = *ppBucket;
    *ppBucket = pEntry;
    D2FindTileNodeStrc* pNode = (D2FindTileNodeStrc*)FOG_Alloc(sizeof(D2FindTileNodeStrc), ".\\SRC\\FindTiles.cpp", 0x8E, 0);
    D2_ASSERT(pNode, 0x8F);
    memset(pNode, 0, sizeof(D2FindTileNodeStrc));
    pNode->pTile = pTile;
    pEntry->pTileList = pNode;
}

// 0x0060CFA0
void __fastcall sub_0060CFA0_AddTileToTable(D2FindTileEntryStrc** ppTable, D2CmpTileBlockStrc* pTile)
{
    int bNew = 1;
    D2_ASSERT(ppTable, 0xA5);
    D2_ASSERT(pTile, 0xA6);
    D2FindTileEntryStrc** ppBucket = &ppTable[sub_0060CD70_WrapIndex(pTile->nValue2C, pTile->nValue28, pTile->nValue24)];
    D2FindTileEntryStrc* pEntry = *ppBucket;
    while (pEntry && bNew)
    {
        if (pEntry->nKey3 == pTile->nValue2C && pEntry->nKey2 == pTile->nValue28 && pEntry->nKey1 == pTile->nValue24)
        {
            bNew = 0;
        }
        else
        {
            pEntry = pEntry->pNext;
        }
    }
    if (bNew)
    {
        sub_0060CF00_AddEntry(ppBucket, pTile);
    }
    else
    {
        sub_0060CEA0_AddTileToEntry(pEntry, pTile);
    }
}
