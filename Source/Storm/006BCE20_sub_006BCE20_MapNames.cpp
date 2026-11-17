extern "C" const char gszEmptyAssertText_006CC837;                                                       // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                   // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                            // 0x00681E09
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                // 0x0041D300
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                     // 0x00413590
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);          // 0x00413CE0

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

#define S_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText_006CC837, sub_00408090(), line); exit(-1); }

__declspec(noinline) static int __stdcall sub_006BCE20_MapNames(unsigned short* pOut, D2SNameListStrc* pList, D2SNameEntryStrc* pEntries);

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
