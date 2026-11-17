#include "Fog.h"

#define S_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), line); exit(-1); }

struct D2SNameEntryStrc;
struct D2SNameListStrc;
struct D2SNameNodeStrc;
struct D2TxtLinkNodeStrc;

extern "C" const char gszEmptyAssertText_006CC837; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2SNameEntryStrc
{
    const char* szName;
    int nType;
    unsigned int nCount;
    int unk0x0C;
    int unk0x10;
};

struct D2SNameListStrc
{
    const char* pStrings;
    int unk0x04;
    int unk0x08;
    unsigned int nCount;
};

struct D2SNameNodeStrc
{
    D2SNameNodeStrc* pNext;
    unsigned int nHash;
    D2SNameEntryStrc* pEntry;
};

__declspec(noinline) static int __stdcall sub_006BCE20_MapNames(unsigned short* pOut, D2SNameListStrc* pList, D2SNameEntryStrc* pEntries);

struct D2TxtLinkNodeStrc
{
    char szText[32];
    int nLinkIndex;
    D2TxtLinkNodeStrc* pPrevious;
    D2TxtLinkNodeStrc* pNext;
};

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
static __declspec(noinline) void __cdecl sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppLink, D2TxtLinkNodeStrc* pNode);

// 0x006BCE20
static int __stdcall sub_006BCE20_MapNames(unsigned short* pOut, D2SNameListStrc* pList, D2SNameEntryStrc* pEntries)
{
    D2SNameNodeStrc* aBuckets[256];
    D2SNameNodeStrc aNodes[0x118];
    unsigned int nNodes = 0;
    int nOut = 0;

    D2SNameEntryStrc* pCheck = pEntries;
    if (pCheck->nType)
    {
        do
        {
            if (pCheck->nType == 5)
            {
                for (unsigned int i = 1; i < pCheck->nCount; ++i)
                {
                    ++pCheck;
                    S_ASSERT(pCheck->nType == 5, 0xC4);
                }
            }
            ++pCheck;
        } while (pCheck->nType);
    }

    SMemZero(aBuckets, sizeof(aBuckets));

    D2SNameEntryStrc* pEntry = pEntries;
    if (pEntry->nType)
    {
        D2SNameNodeStrc* pCursor = aNodes;
        do
        {
        S_ASSERT(nNodes < 0x118, 0xCC);
        ++nNodes;
        D2SNameNodeStrc* pNode = pCursor++;
        const char* szName = pEntry->szName;
        unsigned int nHash = SStrHash(szName, 0, 0);
        unsigned int nBucket = ((((nHash >> 8) ^ nHash) >> 16) ^ (nHash >> 8) ^ nHash) & 0xFF;
        pNode->nHash = nHash;
        pNode->pEntry = pEntry;
        pNode->pNext = aBuckets[nBucket];
        aBuckets[nBucket] = pNode;
            ++pEntry;
        } while (pEntry->nType);
    }

    const char* szString = pList->pStrings;
    for (unsigned int i = 0; i < pList->nCount; ++i)
    {
        unsigned int nHash = SStrHash(szString, 0, 0);
        unsigned int nBucket = ((((((nHash >> 8) ^ nHash) >> 8) ^ nHash) >> 8) ^ nHash) & 0xFF;
        for (D2SNameNodeStrc* pNode = aBuckets[nBucket]; pNode; pNode = pNode->pNext)
        {
            if (pNode->nHash == nHash && !SStrCmpI(szString, pNode->pEntry->szName, 0x7FFFFFFF))
            {
                pNode->nHash = 0;
                pOut[nOut++] = (unsigned short)(pNode->pEntry - pEntries);
                goto next;
            }
        }
        pOut[nOut++] = 0x7FFF;
next:
        while (*szString)
        {
            ++szString;
        }
        ++szString;
    }

    for (unsigned int j = 0; j < nNodes; ++j)
    {
        if (aNodes[j].nHash)
        {
            pOut[nOut] = (unsigned short)(aNodes[j].pEntry - pEntries);
            ++nOut;
        }
    }

    return nOut;
}

// build: context sub_006BCE20_Shim
// calling-convention shim (not game code)
int __stdcall sub_006BCE20_Shim(unsigned short* pOut, D2SNameListStrc* pList, D2SNameEntryStrc* pEntries)
{
    return sub_006BCE20_MapNames(pOut, pList, pEntries);
}

// 0x006BD490
static void __cdecl sub_006BD490_InsertNode(D2TxtLinkNodeStrc** ppLink, D2TxtLinkNodeStrc* pNode)
{
    while (*ppLink)
    {
        D2TxtLinkNodeStrc* pCurrent = *ppLink;
        const int nCompare = strcmp(pNode->szText, pCurrent->szText);
        if (nCompare < 0)
        {
            ppLink = &pCurrent->pPrevious;
        }
        else if (nCompare > 0)
        {
            ppLink = &pCurrent->pNext;
        }
        else
        {
            FOG_FreePool(0, pNode, ".\\Src\\Excel\\Excel.cpp", 1191, 0);
            return;
        }
    }

    *ppLink = pNode;
}

// build: context sub_006BD490_Shim
// calling-convention shim (not game code)
void __cdecl sub_006BD490_Shim(D2TxtLinkNodeStrc** ppRoot, D2TxtLinkNodeStrc* pNode)
{
    sub_006BD490_InsertNode(ppRoot, pNode);
}
