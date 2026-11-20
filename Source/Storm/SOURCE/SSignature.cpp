#include "Storm.h"

struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct D2StormHandlerNodeStrc;
struct D2StormWndRecNodeStrc;
struct D2StormHashCtxStrc;
struct D2StormHashBufferStrc;
struct D2StormRsaKeyStrc;
struct D2StormHuffInputStrc;
struct D2StormHuffItemStrc;
struct D2StormHuffLinkSlotStrc;
struct D2StormHuffTreeStrc;
struct D2StormArrayAStrc;
struct D2StormArrayBStrc;
struct D2StormArrayCStrc;
struct D2StormQueueStrc;
struct D2StormRecord14Strc;
struct D2StormRecordStackStrc;
struct D2StormBigStrc;
struct D2StormEventHandlerStrc;
struct D2StormHandlerTableStrc;
struct T0041D340;

extern "C" void* __cdecl _alloca(unsigned int nSize);
extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x006CC488
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0
int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize); // 0x0041D200
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
void __stdcall sub_0041D010_ReportHandleLeak(const char* szName, const char* szDetail); // 0x0041D010
void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00
int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubtype); // 0x00426370
extern unsigned int gaCrc32Table_00708448[256]; // 0x00708448

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc() : m_prevlink(0), m_next(0)
    {
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExisting);
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            {
                D2StormLinkStrc* pPrev = pExistingLink->m_prevlink;
                pLink->m_prevlink = pPrev;
                pLink->m_next = pPrev->m_next;
                pPrev->m_next = pNode;
                pExistingLink->m_prevlink = pLink;
            }
            break;
        }
    }
};

struct D2StormHandlerNodeStrc
{
    D2StormLinkStrc f_0;
    int nValue;
};

struct D2StormWndRecNodeStrc
{
    D2StormLinkStrc f_0;
    int nValue;
};

extern D2StormNodeListStrc gHandlerList_00708420; // 0x00708420
extern D2StormNodeListStrc gWndRecList_00708860; // 0x00708860

struct D2StormHashCtxStrc
{
    unsigned int nBitCountLo;
    unsigned int nBitCountHi;
    unsigned int nState[5];
    unsigned char pBlock[64];

    void sub_00425D90_Init();                                                                               // 0x00425D90
    void sub_00425F00_Final(unsigned char* pDigest);                                                        // 0x00425F00
};

struct D2StormHashBufferStrc
{
    unsigned int nSignSize;
    int nModulusSize;
    unsigned int nUsed;
    unsigned int nWindow;
    char* pBuffer;
    int unk0x14;
    D2StormHashCtxStrc tHash;
    int f_74;

    static void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, gszNew, -1, 0);
    }
    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormRsaKeyStrc
{
    void* f_0;
    void* f_4;

    D2StormRsaKeyStrc();                                                                                    // 0x0041D4D0
    ~D2StormRsaKeyStrc();                                                                                   // 0x0041D530
    void sub_00426070_SetKey(const void* pExponent, unsigned int nExponentSize, const void* pModulus, int nModulusSize); // 0x00426070
    void sub_004260A0_Process(unsigned char* pData, unsigned int nSize);                                    // 0x004260A0
};

struct D2StormHuffInputStrc
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    D2StormHuffInputStrc(void* pInputBuffer);                                                               // 0x0041D880
};

struct D2StormHuffItemStrc
{
    D2StormLinkStrc f_0;
    unsigned int nValue;
    unsigned int nWeight;
    D2StormHuffItemStrc* pParent;
    D2StormHuffItemStrc* pChild;
};

struct D2StormHuffTreeStrc
{
    int unk0x00[2];
    D2StormHuffItemStrc f_8[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    D2StormHuffItemStrc* pItemsByValue[0x102];
    D2StormHuffLinkSlotStrc f_3474[0x80];

    D2StormHuffTreeStrc();                                                                                  // 0x0041F950
    ~D2StormHuffTreeStrc();                                                                                 // 0x0041F6A0
    void sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem);                                               // 0x0041F350
    unsigned int sub_0041F740_Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput); // 0x0041F740
    void sub_0041F510_InsertBranch(unsigned int nValue);
};

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            if (bRound)
            {
                unsigned int nChunk = f_C ? f_C : sub_004210A0_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004216E0_ReallocData(nCount);
        }
    }
    // build: context D2StormArrayAStrc::SetCount
    void SetCount(unsigned int nCount)
    {
        if (nCount > f_4)
            Reserve(nCount - f_4, 1);
        f_4 = nCount;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct D2StormArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    void ReallocAndClear(unsigned int nCount)
    {
        f_0 = nCount;
        if (f_8 || nCount)
            f_8 = (unsigned char*)SMemReAlloc(f_8, nCount, gszTypeNameUChar_00708880, -2, 0);
    }
    void sub_004219F0_Set(unsigned int nCount, const unsigned char* pData);
};

struct D2StormArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            if (bRound)
            {
                unsigned int nChunk = f_C ? f_C : sub_00421240_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_00421770_ReallocData(nCount);
        }
    }
    void ReallocAndClear(unsigned int nCount)
    {
        f_0 = nCount;
        if (f_8 || nCount)
            f_8 = (char*)SMemReAlloc(f_8, nCount, gszTypeNameChar_0070888C, -2, 0);
    }
    unsigned int sub_00421240_CalcChunkSize(unsigned int nCount);                                           // 0x00421240
    void sub_00421770_ReallocData(unsigned int nAlloc);                                                     // 0x00421770
    void sub_00421A50_Set(unsigned int nCount, const char* pData);
    unsigned int sub_00421F60_Add(unsigned int nCount, const char* pData);
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int sub_004212D0_Get(unsigned int nIndex);                                                              // 0x004212D0
    void sub_004220D0_SetCount(unsigned int nCount);
};

struct D2StormRecord14Strc
{
    int nData[5];
};

struct D2StormRecordStackStrc
{
    D2StormRecord14Strc pRecords[16];
    unsigned int nUsed;
};

struct D2StormBigStrc
{
    int unk0x00[5];
    D2StormRecordStackStrc tStack;
    int unk0x158[4];

    ~D2StormBigStrc();                                                                                      // 0x00421D80
    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
};

int __stdcall sub_004242C0_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, D2StormRecordStackStrc* pStack); // 0x004242C0
int __stdcall sub_00424700_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, D2StormRecordStackStrc* pStack); // 0x00424700
int __stdcall sub_00424B00_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormRecordStackStrc* pStack); // 0x00424B00

struct D2StormEventHandlerStrc
{
    int nData[3];
    D2StormEventHandlerStrc* pNext;
};

struct D2StormHandlerTableStrc
{
    D2StormEventHandlerStrc** ppTable;
    unsigned int nSize;
    int nUsed;
};

struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];

    void sub_00425D90_Init();                                                                               // 0x00425D90
    void sub_00425DD0_Update(const unsigned char* pData, unsigned int nLen);                                // 0x00425DD0
    void sub_00425F00_Final(unsigned char* pDigest);                                                        // 0x00425F00
};

inline void* operator new(unsigned int, void* pPlace) throw();

// build: context D2StormArrayAStrc::Reserve
// build: context D2StormArrayCStrc::Reserve
inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

// 0x0041C900
void __stdcall sub_0041C900_AddHandler(int nValue)
{
    sub_0041C1A0_LockErrorState();
    D2StormHandlerNodeStrc* pNode = new (SMemAlloc(sizeof(D2StormHandlerNodeStrc), gszTypeNameHandler_00708434, -2, 0x8000008)) D2StormHandlerNodeStrc;
    gHandlerList_00708420.LinkNode((char*)pNode, 1, 0);
    pNode->nValue = nValue;
    sub_0041C1E0_UnlockErrorState();
}

// 0x0041D1E0
void __stdcall sub_0041D1E0_ReportHandleLeak(const char* szName)
{
    sub_0041D010_ReportHandleLeak(szName, 0);
}

// 0x0041D3B0
void __fastcall sub_0041D3B0_NewHashBuffer(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize)
{
    *ppBuffer = new D2StormHashBufferStrc;
    (*ppBuffer)->nSignSize = nSignSize;
    (*ppBuffer)->nModulusSize = nModulusSize;
    (*ppBuffer)->nUsed = 0;
    (*ppBuffer)->nWindow = nSignSize + 4;
    (*ppBuffer)->pBuffer = (char*)SMemAlloc((*ppBuffer)->nWindow, ".\\SOURCE\\SSignature.cpp", 0x57, 8);
    (*ppBuffer)->tHash.sub_00425D90_Init();
}

// 0x0041D6D0
int __fastcall sub_0041D6D0_VerifyHashBuffer(D2StormHashBufferStrc* pBuffer, const void* pExponent, const void* pModulus)
{
    int bResult = 0;
    if (pBuffer->nUsed == pBuffer->nWindow && *(int*)pBuffer->pBuffer == 0x5349474E)
    {
        unsigned int nSize = pBuffer->nSignSize;
        unsigned char* pDigest = (unsigned char*)_alloca(nSize);
        SMemFill(pDigest, nSize, 0xBB);
        pDigest[pBuffer->nSignSize - 1] = 0x0B;
        pBuffer->tHash.sub_00425F00_Final(pDigest);
        unsigned char* pSign = (unsigned char*)_alloca(pBuffer->nSignSize);
        SMemCopy(pSign, pBuffer->pBuffer + 4, pBuffer->nSignSize);
        D2StormRsaKeyStrc tKey;
        tKey.sub_00426070_SetKey(pExponent, pBuffer->nSignSize, pModulus, pBuffer->nModulusSize);
        tKey.sub_004260A0_Process(pSign, pBuffer->nSignSize);
        bResult = !SMemCmp(pSign, pDigest, pBuffer->nSignSize);
    }
    SMemFree(pBuffer->pBuffer, ".\\SOURCE\\SSignature.cpp", 0xD0, 0);
    delete pBuffer;
    return bResult;
}

// 0x0041D810
void __fastcall sub_0041D810_Crc32(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags)
{
    unsigned int nCrc = 0;
    if (pCrc)
        nCrc = *pCrc;
    if (nFlags & 1)
        nCrc = 0xFFFFFFFF;
    if (nFlags & 2)
    {
        while (nSize)
        {
            nCrc = (nCrc >> 8) ^ gaCrc32Table_00708448[(*pData ^ nCrc) & 0xFF];
            nSize--;
            pData++;
        }
    }
    if (nFlags & 4)
        nCrc = ~nCrc;
    if (pCrc)
        *pCrc = nCrc;
}

// 0x0041F510
void D2StormHuffTreeStrc::sub_0041F510_InsertBranch(unsigned int nValue)
{
    D2StormHuffItemStrc* pFirst = (D2StormHuffItemStrc*)tItemList.Head();
    D2StormHuffItemStrc* pItem = (D2StormHuffItemStrc*)tFreeList.Head();
    if (!pItem)
        pItem = &f_8[nItemsUsed++];
    tItemList.LinkNode((char*)pItem, 1, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    pItem->nValue = pFirst->nValue;
    pItem->nWeight = pFirst->nWeight;
    pItem->pParent = pFirst;
    pItemsByValue[pItem->nValue] = pItem;
    pItem = (D2StormHuffItemStrc*)tFreeList.Head();
    if (!pItem)
        pItem = &f_8[nItemsUsed++];
    tItemList.LinkNode((char*)pItem, 1, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    pItem->nValue = nValue;
    pItem->nWeight = 0;
    pItem->pParent = pFirst;
    pItemsByValue[nValue] = pItem;
    pFirst->pChild = pItem;
    sub_0041F350_IncWeights(pItem);
}

// 0x0041F9E0
void __fastcall sub_0041F9E0_DecompressHuffman(void* pOutput, unsigned int* pOutputSize, void* pInput, unsigned int nInputSize, int nUnused)
{
    D2StormHuffInputStrc tInput(pInput);
    D2StormHuffTreeStrc tTree;
    *pOutputSize = tTree.sub_0041F740_Decompress(pOutput, *pOutputSize, &tInput);
}

// 0x00420360
int __stdcall SMsgPushRegisterState(int nType)
{
    SEvtPushState('SMSH', nType);
    SEvtPushState('SMSI', nType);
    SEvtPushState('SMSJ', nType);
    SEvtPushState('SMSG', nType);
    return 1;
}

// 0x004208E0
void __stdcall sub_004208E0_AddWndRec(int nValue)
{
    D2StormWndRecNodeStrc* pNode = new (SMemAlloc(sizeof(D2StormWndRecNodeStrc), gszTypeNameWndRec_00708850, -2, 8)) D2StormWndRecNodeStrc;
    gWndRecList_00708860.LinkNode((char*)pNode, 2, 0);
    pNode->nValue = nValue;
}

// 0x00420CF0
int __stdcall sub_00420CF0_WindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam)
{
    int bUseResult = 0;
    int lResult = 0;
    if (SMsgDispatchMessage(hWnd, uMsg, wParam, lParam, &bUseResult, &lResult) && bUseResult)
        return lResult;
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// 0x004213B0
unsigned int __stdcall sub_004213B0_FindLastSetBit(D2StormQueueStrc* pQueue)
{
    unsigned int nCount = pQueue->m_array.f_4;
    unsigned int nStart = pQueue->m_start;
    unsigned int nWords = nCount - nStart;
    for (unsigned int i = nWords; i != 0; )
    {
        i--;
        if (nStart + i < nCount && pQueue->m_array.f_8[nStart + i])
        {
            unsigned int nMask = 0x80000000;
            for (unsigned int nBit = 32; nBit != 0; )
            {
                nBit--;
                if (pQueue->sub_004212D0_Get(i) & nMask)
                    return i * 32 + nBit;
                nMask >>= 1;
            }
        }
    }
    return 0;
}

// 0x004219F0
void D2StormArrayBStrc::sub_004219F0_Set(unsigned int nCount, const unsigned char* pData)
{
    ReallocAndClear(nCount);
    for (unsigned int i = 0; i < nCount; i++, pData++)
        new (&f_8[i]) unsigned char(*pData);
    f_4 = nCount;
}

// 0x00421A50
void D2StormArrayCStrc::sub_00421A50_Set(unsigned int nCount, const char* pData)
{
    ReallocAndClear(nCount);
    for (unsigned int i = 0; i < nCount; i++, pData++)
        new (&f_8[i]) char(*pData);
    f_4 = nCount;
}

// 0x00421F60
unsigned int D2StormArrayCStrc::sub_00421F60_Add(unsigned int nCount, const char* pData)
{
    Reserve(nCount, 1);
    for (unsigned int i = 0; i < nCount; i++, pData++)
        new (&f_8[f_4 + i]) char(*pData);
    f_4 += nCount;
    return f_4 - nCount;
}

// 0x004220D0
void D2StormQueueStrc::sub_004220D0_SetCount(unsigned int nCount)
{
    m_array.SetCount(m_start + nCount);
}

// 0x004237D0
void __stdcall sub_004237D0_CopyQueue(D2StormQueueStrc* pDest, D2StormQueueStrc* pSource)
{
    if (pDest != pSource)
        pDest->m_array.sub_004215C0_Set(pSource->m_array.f_4, pSource->m_array.f_8);
    pDest->m_array.f_C = pSource->m_array.f_C;
    pDest->m_start = pSource->m_start;
}

// 0x00424E40
void __stdcall SBigDel(D2StormBigStrc* pBig)
{
    delete pBig;
}

// 0x00424F10
int __stdcall SBigMul(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return sub_004242C0_BigOp(pResult, pA, pB, &pResult->tStack);
}

// 0x00424F70
int __stdcall sub_00424F70_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return sub_00424700_BigOp(pResult, pA, pB, &pResult->tStack);
}

// 0x00424F90
int __stdcall sub_00424F90_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    return sub_00424B00_BigOp(pResult, pA, &pResult->tStack);
}

// 0x00426180
void __stdcall sub_00426180_CopyHandlerTable(D2StormHandlerTableStrc* pDest, D2StormHandlerTableStrc* pSource)
{
    pDest->nSize = pSource->nSize;
    pDest->nUsed = pSource->nUsed;
    pDest->ppTable = (D2StormEventHandlerStrc**)SMemAlloc(pDest->nSize * sizeof(D2StormEventHandlerStrc*), gszSEvtCpp, 0x3E, 0);
    for (unsigned int i = 0; i < pSource->nSize; i++)
    {
        D2StormEventHandlerStrc** ppNext = &pDest->ppTable[i];
        for (D2StormEventHandlerStrc* pHandler = pSource->ppTable[i]; pHandler; pHandler = pHandler->pNext)
        {
            *ppNext = (D2StormEventHandlerStrc*)SMemAlloc(sizeof(D2StormEventHandlerStrc), gszSEvtCpp, 0x45, 0);
            SMemCopy(*ppNext, pHandler, sizeof(D2StormEventHandlerStrc));
            ppNext = &(*ppNext)->pNext;
        }
        *ppNext = 0;
    }
}

#include "gen/data/Source/Storm/SOURCE/SSignature.inc"

// 0x0041D340
static __declspec(noinline) int __stdcall sub_0041D340_FindSignatureTag(const char* pData, unsigned int nSize, unsigned int nSignSize, unsigned int* pOffset)
{
    *pOffset = nSize - nSignSize - 4;
    if (nSize >= nSignSize + 4 && *(const int*)(pData + *pOffset) == 0x5349474E)
        return 1;
    return 0;
}

// 0x0041D370
static __declspec(noinline) void __stdcall sub_0041D370_HashData(unsigned int nLen, const unsigned char* pData, unsigned char* pDigest)
{
    T0041D340 tHash;
    tHash.sub_00425D90_Init();
    tHash.sub_00425DD0_Update(pData, nLen);
    tHash.sub_00425F00_Final(pDigest);
}

// 0x0041D590
int __fastcall sub_0041D590_SignBuffer(char* pData, unsigned int* pnSize, const void* pExponent, unsigned int nSignSize, const void* pModulus1, int nModulusSize1, const void* pModulus2, int nModulusSize2)
{
    unsigned int nOffset;
    if (!sub_0041D340_FindSignatureTag(pData, *pnSize, nSignSize, &nOffset))
        nOffset = *pnSize;
    unsigned char* pDigest = (unsigned char*)_alloca(nSignSize);
    SMemFill(pDigest, nSignSize, 0xBB);
    pDigest[nSignSize - 1] = 0x0B;
    sub_0041D370_HashData(nOffset, (const unsigned char*)pData, pDigest);
    unsigned char* pSign = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pSign, pDigest, nSignSize);
    D2StormRsaKeyStrc tKey1;
    tKey1.sub_00426070_SetKey(pExponent, nSignSize, pModulus1, nModulusSize1);
    tKey1.sub_004260A0_Process(pSign, nSignSize);
    unsigned char* pCheck = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pCheck, pSign, nSignSize);
    D2StormRsaKeyStrc tKey2;
    tKey2.sub_00426070_SetKey(pExponent, nSignSize, pModulus2, nModulusSize2);
    tKey2.sub_004260A0_Process(pCheck, nSignSize);
    if (SMemCmp(pCheck, pDigest, nSignSize))
        return 0;
    *(int*)(pData + nOffset) = 0x5349474E;
    SMemCopy(pData + nOffset + 4, pSign, nSignSize);
    *pnSize = nOffset + nSignSize + 4;
    return 1;
}
