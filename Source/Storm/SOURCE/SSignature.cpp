#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2StormTypes.h"
#include "D2StormSha1.h"


struct D2StormNodeListStrc;

struct HANDLER;

struct WNDREC;


struct D2StormHashBufferStrc;

struct D2StormRsaKeyStrc;

struct D2StormHuffInputStrc;

struct HUFFNODE;

struct D2StormHuffLinkSlotStrc;

struct CHuffman;


struct D2StormArrayBStrc;

struct D2StormArrayCStrc;

struct BigBuffer;

struct BigStack;

struct D2StormBigStrc;


extern "C" void* __cdecl _alloca(unsigned int nSize);

extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x006CC488

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize); // 0x0041D200

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0

void __stdcall SErrReportNamedResourceLeak(const char* szName, const char* szDetail); // 0x0041D010

void __cdecl sub_0041C1A0_LockErrorState(); // 0x0041C1A0

void __cdecl sub_0041C1E0_UnlockErrorState(); // 0x0041C1E0

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult); // 0x00420B00

int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubtype); // 0x00426370

extern unsigned int gaCrc32Table_00708448[256]; // 0x00708448

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

struct HANDLER
{
    D2StormLinkStrc f_0;
    int nValue;
};

struct WNDREC
{
    D2StormLinkStrc f_0;
    int nValue;
};

extern D2StormNodeListStrc gHandlerList_00708420; // 0x00708420

extern D2StormNodeListStrc gWndRecList_00708860; // 0x00708860


struct D2StormHashBufferStrc
{
    unsigned int nSignSize;
    int nModulusSize;
    unsigned int nUsed;
    unsigned int nWindow;
    char* pBuffer;
    int unk0x14;
    Sha1 tHash;

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

struct HUFFNODE
{
    D2StormLinkStrc f_0;
    unsigned int nValue;
    unsigned int nWeight;
    HUFFNODE* pParent;
    HUFFNODE* pChild;
};

struct CHuffman
{
    int unk0x00[2];
    HUFFNODE f_8[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    HUFFNODE* pItemsByValue[0x102];
    D2StormHuffLinkSlotStrc f_3474[0x80];

    CHuffman();                                                                                  // 0x0041F950
    ~CHuffman();                                                                                 // 0x0041F6A0
    void sub_0041F350_IncWeights(HUFFNODE* pItem);                                               // 0x0041F350
    unsigned int Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput); // 0x0041F740
    void AddSymbol(unsigned int nValue);
};

#include "D2StormArrayA.h"

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
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);
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

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int sub_004212D0_Get(unsigned int nIndex);                                                              // 0x004212D0
    void sub_004220D0_SetCount(unsigned int nCount);
    int InRange(unsigned int nIndex)
    {
        return m_start + nIndex < m_array.f_4;
    }
    int sub_00420DB0_InRange(unsigned int nIndex);
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;

    BigBuffer* sub_00420DD0_Push(int* pCounter);
    void sub_00420E00_Drop(unsigned int nCount);
};

struct D2StormBigStrc
{
    int unk0x00[5];
    BigStack tStack;
    int unk0x158[4];

    ~D2StormBigStrc();                                                                                      // 0x00421D80
    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
};

int __stdcall sub_004242C0_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, BigStack* pStack); // 0x004242C0

int __stdcall sub_00424700_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, BigStack* pStack); // 0x00424700

int __stdcall sub_00424B00_BigOp(D2StormBigStrc* pResult, D2StormBigStrc* pA, BigStack* pStack); // 0x00424B00


inline void* operator new(unsigned int, void* pPlace) throw();

struct SMSGHANDLER_PARAMS;

void __stdcall SMemMove(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2E0

int __stdcall SEvtBreakHandlerChain(void* pData); // 0x00426E80

extern int gdwGlobal_007792F4;                                                                              // 0x007792F4

struct D2StormMemSourceStrc
{
    int unk0x00[3];
    char* pBuffer;
    unsigned int nPos;
    unsigned int nSize;
};

struct D2StormMemSinkStrc
{
    char* pBuffer;
    unsigned int nPos;
    unsigned int nSize;
};

struct CBitInput
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    unsigned int Peek(unsigned int nBits, unsigned int nMask)
    {
        if (nBitCount <= nBits)
        {
            nBitBuffer |= *(unsigned short*)pInput << nBitCount;
            nBitCount += 16;
            pInput += 2;
        }
        return nBitBuffer & nMask;
    }
    void Skip(unsigned int nBits)
    {
        nBitBuffer >>= nBits;
        nBitCount -= nBits;
    }
    unsigned int sub_0041D8D0_Peek(unsigned int nBits, unsigned int nMask);
    void sub_0041D900_Skip(unsigned int nBits);
    unsigned int sub_0041E9E0_Get(unsigned int nBits, unsigned int nMask);
};

struct D2StormNodeListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_0041EB40_Link(char* pNode);
    void sub_0041EB60_UnlinkNode(char* pNode);
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);
};

struct D2StormNodeListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_00420520_Link(char* pNode);
    void sub_00420540_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);
    char* sub_004205F0_Next(char* pNode);
    void sub_00420650_UnlinkNode(char* pNode);
    char* sub_004206E0_RawNext(char* pNode);
};

struct D2StormPtrArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    int* f_8;
    unsigned int f_C;

    int* sub_00420FD0_At(unsigned int nIndex);
};

struct D2StormByteArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;
    unsigned int f_C;

    char* sub_00421000_At(unsigned int nIndex);
};

// build: context D2StormArrayAStrc::Reserve
// build: context D2StormArrayCStrc::Reserve
inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}



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
    Sha1 tHash;
    tHash.Initialize();
    tHash.Append(pData, nLen);
    tHash.sub_00425F00_Final(pDigest);
}

// 0x0041D3B0
void __fastcall SSignatureVerifyStream_Begin(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize)
{
    *ppBuffer = new D2StormHashBufferStrc;
    (*ppBuffer)->nSignSize = nSignSize;
    (*ppBuffer)->nModulusSize = nModulusSize;
    (*ppBuffer)->nUsed = 0;
    (*ppBuffer)->nWindow = nSignSize + 4;
    (*ppBuffer)->pBuffer = (char*)SMemAlloc((*ppBuffer)->nWindow, ".\\SOURCE\\SSignature.cpp", 0x57, 8);
    (*ppBuffer)->tHash.Initialize();
}

// 0x0041D420
void __fastcall sub_0041D420_HashBuffered(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize)
{
    int nExtra = nSize - pBuffer->nWindow;
    if (nExtra >= 0)
    {
        if (pBuffer->nUsed > 0)
            pBuffer->tHash.Append((const unsigned char*)pBuffer->pBuffer, pBuffer->nUsed);
        if (nExtra > 0)
            pBuffer->tHash.Append((const unsigned char*)pData, nExtra);
        SMemCopy(pBuffer->pBuffer, pData + nExtra, pBuffer->nWindow);
        pBuffer->nUsed = pBuffer->nWindow;
    }
    else
    {
        int nOver = pBuffer->nUsed - pBuffer->nWindow + nSize;
        if (nOver > 0)
        {
            pBuffer->tHash.Append((const unsigned char*)pBuffer->pBuffer, nOver);
            pBuffer->nUsed -= nOver;
            SMemMove(pBuffer->pBuffer, pBuffer->pBuffer + nOver, pBuffer->nUsed);
        }
        SMemCopy(pBuffer->pBuffer + pBuffer->nUsed, pData, nSize);
        pBuffer->nUsed += nSize;
    }
}

// 0x0041D590
int __fastcall SSignatureGenerate(char* pData, unsigned int* pnSize, const void* pExponent, unsigned int nSignSize, const void* pModulus1, int nModulusSize1, const void* pModulus2, int nModulusSize2)
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

// 0x0041D6D0
int __fastcall SSignatureVerifyStream_Finish(D2StormHashBufferStrc* pBuffer, const void* pExponent, const void* pModulus)
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
void __fastcall CrcBuffer(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags)
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

// 0x0041D8D0
unsigned int CBitInput::sub_0041D8D0_Peek(unsigned int nBits, unsigned int nMask)
{
    if (nBitCount <= nBits)
    {
        nBitBuffer |= *(unsigned short*)pInput << nBitCount;
        nBitCount += 16;
        pInput += 2;
    }
    return nBitBuffer & nMask;
}

// 0x0041D900
void CBitInput::sub_0041D900_Skip(unsigned int nBits)
{
    nBitBuffer >>= nBits;
    nBitCount -= nBits;
}

// 0x0041DEC0
unsigned int __cdecl PkwareBufferRead(char* pBuffer, unsigned int* pSize, D2StormMemSourceStrc* pSource)
{
    unsigned int nAvail = pSource->nSize - pSource->nPos;
    unsigned int nSize = *pSize < nAvail ? *pSize : nAvail;
    SMemCopy(pBuffer, pSource->pBuffer + pSource->nPos, nSize);
    pSource->nPos += nSize;
    return nSize;
}

// 0x0041DF00
void __cdecl PkwareBufferWrite(char* pBuffer, unsigned int* pSize, D2StormMemSinkStrc* pSink)
{
    unsigned int nAvail = pSink->nSize - pSink->nPos;
    unsigned int nSize = *pSize < nAvail ? *pSize : nAvail;
    SMemCopy(pSink->pBuffer + pSink->nPos, pBuffer, nSize);
    pSink->nPos += nSize;
}

// 0x0041E900
D2StormLinkStrc* D2StormLinkStrc::sub_0041E900_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0041E9E0
unsigned int CBitInput::sub_0041E9E0_Get(unsigned int nBits, unsigned int nMask)
{
    unsigned int nValue = Peek(nBits, nMask);
    Skip(nBits);
    return nValue;
}

// 0x0041EB40
D2StormLinkStrc* D2StormNodeListAStrc::sub_0041EB40_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
}

// 0x0041EB60
void D2StormNodeListAStrc::sub_0041EB60_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// build: symbol ?LinkNode@D2StormNodeListAStrc@@QAEXPADI0@Z 0x0041ED90
void D2StormNodeListAStrc::LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
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

// 0x0041F510
void CHuffman::AddSymbol(unsigned int nValue)
{
    HUFFNODE* pFirst = (HUFFNODE*)tItemList.Head();
    HUFFNODE* pItem = (HUFFNODE*)tFreeList.Head();
    if (!pItem)
        pItem = &f_8[nItemsUsed++];
    tItemList.LinkNode((char*)pItem, 1, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    pItem->nValue = pFirst->nValue;
    pItem->nWeight = pFirst->nWeight;
    pItem->pParent = pFirst;
    pItemsByValue[pItem->nValue] = pItem;
    pItem = (HUFFNODE*)tFreeList.Head();
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
void __fastcall HuffmanDecompress(void* pOutput, unsigned int* pOutputSize, void* pInput, unsigned int nInputSize, int nUnused)
{
    D2StormHuffInputStrc tInput(pInput);
    CHuffman tTree;
    *pOutputSize = tTree.Decompress(pOutput, *pOutputSize, &tInput);
}

// 0x00420DB0
int BigBuffer::sub_00420DB0_InRange(unsigned int nIndex)
{
    return m_start + nIndex < m_array.f_4;
}

// 0x00420DD0
BigBuffer* BigStack::sub_00420DD0_Push(int* pCounter)
{
    if (pCounter)
        ++*pCounter;
    return &pRecords[nUsed++];
}

// 0x00420E00
void BigStack::sub_00420E00_Drop(unsigned int nCount)
{
    nUsed -= nCount;
}

// 0x00420FD0
int* D2StormPtrArrayStrc::sub_00420FD0_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x00421000
char* D2StormByteArrayStrc::sub_00421000_At(unsigned int nIndex)
{
    return &f_8[nIndex];
}

// 0x004210A0
unsigned int D2StormArrayAStrc::sub_004210A0_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x40)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x40;
    return 0x40;
}

// 0x004210E0
unsigned int __stdcall sub_004210E0_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x00421160
unsigned int D2StormArrayBStrc::sub_00421160_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x100)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x100;
    return 0x100;
}

// 0x004211A0
unsigned int __stdcall sub_004211A0_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x00421240
unsigned int D2StormArrayCStrc::sub_00421240_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x100)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    f_C = 0x100;
    return 0x100;
}

// 0x00421280
unsigned int __stdcall sub_00421280_RoundUp(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x004212D0
int BigBuffer::sub_004212D0_Get(unsigned int nIndex)
{
    return InRange(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
}

// 0x004213B0
unsigned int __stdcall sub_004213B0_FindLastSetBit(BigBuffer* pQueue)
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
void BigBuffer::sub_004220D0_SetCount(unsigned int nCount)
{
    m_array.SetCount(m_start + nCount);
}

// 0x004237D0
void __stdcall SBigCopy(BigBuffer* pDest, BigBuffer* pSource)
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
int __stdcall SBigRand(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return sub_00424700_BigOp(pResult, pA, pB, &pResult->tStack);
}

// 0x00424F90
int __stdcall SBigSquare(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    return sub_00424B00_BigOp(pResult, pA, &pResult->tStack);
}


#include "gen/data/Source/Storm/SOURCE/SSignature.inc"
