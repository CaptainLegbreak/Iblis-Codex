#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2StormTypes.h"
#include "D2StormSha1.h"

struct D2StormNodeListStrc;

struct D2StormHashBufferStrc;

namespace Crypt { struct RSA; }

struct CBitInput;

struct HUFFNODE;

struct D2StormHuffLinkSlotStrc;

struct CHuffman;



struct BigBuffer;

struct BigStack;


extern "C" void* __cdecl _alloca(unsigned int nSize);

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize); // 0x0041D200

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0

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

namespace Crypt
{

struct RSA
{
    void* hExponent;
    void* hModulus;

    RSA();                                                                                                  // 0x0041D4D0
    ~RSA();                                                                                                 // 0x0041D530
    void Prepare(const void* pExponent, unsigned int nExponentSize, const void* pModulus, int nModulusSize); // 0x00426070
    void Process(unsigned char* pData, unsigned int nSize);                                    // 0x004260A0
};

}

struct HUFFNODE
{
    D2StormLinkStrc tLink;
    unsigned int nValue;
    unsigned int nWeight;
    HUFFNODE* pParent;
    HUFFNODE* pChild;
};

struct CHuffman
{
    int unk0x00[2];
    HUFFNODE aItems[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    HUFFNODE* pItemsByValue[0x102];
    D2StormHuffLinkSlotStrc aQuickLinks[0x80];

    CHuffman();                                                                                  // 0x0041F950
    ~CHuffman();                                                                                 // 0x0041F6A0
    void sub_0041F350_IncWeights(HUFFNODE* pItem);                                               // 0x0041F350
    unsigned int Decompress(void* pOutput, unsigned int nOutputSize, CBitInput* pInput); // 0x0041F740
    void AddSymbol(unsigned int nValue);
};

#include "D2StormArrayA.h"

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int sub_004212D0_Get(unsigned int nIndex);                                                              // 0x004212D0
    void sub_004220D0_SetCount(unsigned int nCount);
    int InRange(unsigned int nIndex)
    {
        return m_start + nIndex < m_array.m_count;
    }
    int sub_00420DB0_InRange(unsigned int nIndex);
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;

    BigBuffer* Push(int* pCounter); // 0x00420DD0
    void Drop(unsigned int nCount); // 0x00420E00
};

inline void* operator new(unsigned int, void* pPlace) throw();

void __stdcall SMemMove(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2E0

struct CBitInput
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    CBitInput(void* pInputBuffer);                                                                          // 0x0041D880
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
};

struct D2StormNodeListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);
};

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

struct D2StormBigStrc;
void __stdcall SBigNew(D2StormBigStrc** ppBig);                                                             // 0x00423950
void __stdcall SBigDel(D2StormBigStrc* pBig);                                                               // 0x00424E40

// A big number handle that owns its SBig.
struct BigNum
{
    D2StormBigStrc* hHandle;

    BigNum();
    ~BigNum();
};

// 0x0041D320
BigNum::BigNum()
{
    SBigNew(&hHandle);
}

// 0x0041D330
BigNum::~BigNum()
{
    SBigDel(hHandle);
}

// 0x0041D340
static int __stdcall FindSignatureTag(const char* pData, unsigned int nSize, unsigned int nSignSize, unsigned int* pOffset)
{
    *pOffset = nSize - nSignSize - 4;
    if (nSize >= nSignSize + 4 && *(const int*)(pData + *pOffset) == 0x5349474E)
        return 1;
    return 0;
}

// 0x0041D370
static void __stdcall HashSignatureData(unsigned int nLen, const unsigned char* pData, unsigned char* pDigest)
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

// 0x0041D410
unsigned int __fastcall GetHashWindowSize(D2StormHashBufferStrc* pBuffer)
{
    return pBuffer->nWindow;
}

// 0x0041D420
void __fastcall HashBufferedData(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize)
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
    if (!FindSignatureTag(pData, *pnSize, nSignSize, &nOffset))
        nOffset = *pnSize;
    unsigned char* pDigest = (unsigned char*)_alloca(nSignSize);
    SMemFill(pDigest, nSignSize, 0xBB);
    pDigest[nSignSize - 1] = 0x0B;
    HashSignatureData(nOffset, (const unsigned char*)pData, pDigest);
    unsigned char* pSign = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pSign, pDigest, nSignSize);
    Crypt::RSA tKey1;
    tKey1.Prepare(pExponent, nSignSize, pModulus1, nModulusSize1);
    tKey1.Process(pSign, nSignSize);
    unsigned char* pCheck = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pCheck, pSign, nSignSize);
    Crypt::RSA tKey2;
    tKey2.Prepare(pExponent, nSignSize, pModulus2, nModulusSize2);
    tKey2.Process(pCheck, nSignSize);
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
        Crypt::RSA tKey;
        tKey.Prepare(pExponent, pBuffer->nSignSize, pModulus, pBuffer->nModulusSize);
        tKey.Process(pSign, pBuffer->nSignSize);
        bResult = !SMemCmp(pSign, pDigest, pBuffer->nSignSize);
    }
    SMemFree(pBuffer->pBuffer, ".\\SOURCE\\SSignature.cpp", 0xD0, 0);
    delete pBuffer;
    return bResult;
}

// 0x0041D7D0
int __fastcall SSignatureVerify(const void* pData, int nSize, const void* pExponent, unsigned int nSignSize, const void* pModulus, int nModulusSize)
{
    D2StormHashBufferStrc* pBuffer;
    SSignatureVerifyStream_Begin(&pBuffer, nSignSize, nModulusSize);
    HashBufferedData(pBuffer, (const char*)pData, nSize);
    return SSignatureVerifyStream_Finish(pBuffer, pExponent, pModulus);
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

// build: symbol ?LinkNode@D2StormNodeListAStrc@@QAEXPADI0@Z 0x0041ED90

// 0x0041F9E0
void __fastcall HuffmanDecompress(void* pOutput, unsigned int* pOutputSize, void* pInput, unsigned int nInputSize, int nUnused)
{
    CBitInput tInput(pInput);
    CHuffman tTree;
    *pOutputSize = tTree.Decompress(pOutput, *pOutputSize, &tInput);
}

// 0x00420DB0
int BigBuffer::sub_00420DB0_InRange(unsigned int nIndex)
{
    return m_start + nIndex < m_array.m_count;
}

// 0x00420DD0
BigBuffer* BigStack::Push(int* pCounter)
{
    if (pCounter)
        ++*pCounter;
    return &pRecords[nUsed++];
}

// 0x00420E00
void BigStack::Drop(unsigned int nCount)
{
    nUsed -= nCount;
}

// 0x004212D0
int BigBuffer::sub_004212D0_Get(unsigned int nIndex)
{
    return InRange(nIndex) ? m_array.m_data[m_start + nIndex] : 0;
}

// 0x004213B0
unsigned int __stdcall BigHighBitIndex(BigBuffer* pQueue)
{
    unsigned int nCount = pQueue->m_array.m_count;
    unsigned int nStart = pQueue->m_start;
    unsigned int nWords = nCount - nStart;
    for (unsigned int i = nWords; i != 0; )
    {
        i--;
        if (nStart + i < nCount && pQueue->m_array.m_data[nStart + i])
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

// 0x004220D0
void BigBuffer::sub_004220D0_SetCount(unsigned int nCount)
{
    m_array.SetCount(m_start + nCount);
}

#include "gen/data/Source/Storm/SOURCE/SSignature.inc"
