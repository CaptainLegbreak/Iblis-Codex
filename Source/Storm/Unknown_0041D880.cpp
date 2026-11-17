#include "Storm.h"

struct Obj0041D880;
struct D2StormHandleStrc;
struct D2StormBitReaderStrc;
struct Obj0041D920;
struct Obj0041D940;
struct D2StormHuffInputStrc;
struct D2StormHuffOutputStrc;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct D2StormHuffItemStrc;
struct D2StormHuffTreeStrc;
struct D2AdpcmHeaderStrc;

struct Obj0041D880 { const unsigned int* pCur00; unsigned int dwBits04; int nBitCount08; };

void __stdcall SBigNew(void** phBig); // 0x00423950
void __stdcall SBigDel(void* hBig); // 0x00424E40

struct D2StormHandleStrc
{
    void* hHandle;

    D2StormHandleStrc();
    ~D2StormHandleStrc();
};

struct D2StormBitReaderStrc
{
    unsigned int* pData;
    unsigned int dwBits;
    int nBitsLeft;

    int sub_0041D8A0_ReadBit();
};

struct Obj0041D920 { unsigned int dwCur00; unsigned int dwValue04; unsigned int dwBase08; unsigned int dwValue0C; unsigned int dwValue10; };

struct Obj0041D940 { int nValue00; int nUnknown04; int nValue08; };

struct D2StormHuffInputStrc
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    D2StormHuffInputStrc(void* pInputBuffer);
};

struct D2StormHuffOutputStrc
{
    unsigned char* pOutputStart;
    unsigned int f_4;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;
    D2StormHuffOutputStrc(void* pOutputBuffer, unsigned int nOutputSize);
    void sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits);
};

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
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
    int bIsCmp0;
    unsigned int nUnk0x04;
    D2StormHuffItemStrc f_8[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    D2StormHuffItemStrc* pItemsByValue[0x102];

    void sub_0041D9E0_EncodeOne(D2StormHuffOutputStrc* pOutput, unsigned int nValue);
    void sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem);
};

struct D2AdpcmHeaderStrc
{
    unsigned char nZero;
    unsigned char f_1;
};

// 0x0041D880
extern "C" __declspec(dllexport) Obj0041D880* __fastcall sub_0041D880(Obj0041D880* pObj, int nUnusedEdx, const unsigned int* pBuffer) {
    pObj->pCur00 = pBuffer;
    pObj->dwBits04 = *pObj->pCur00++;
    pObj->nBitCount08 = 32;
    return pObj;
}

// 0x0041D320
D2StormHandleStrc::D2StormHandleStrc()
{
    SBigNew(&hHandle);
}

// 0x0041D330
D2StormHandleStrc::~D2StormHandleStrc()
{
    SBigDel(hHandle);
}

// 0x0041D8A0
int D2StormBitReaderStrc::sub_0041D8A0_ReadBit()
{
    int nBit = dwBits & 1;
    dwBits >>= 1;
    if (!--nBitsLeft)
    {
        dwBits = *pData++;
        nBitsLeft = 32;
    }
    return nBit;
}

// 0x0041D920
extern "C" __declspec(dllexport) Obj0041D920* __fastcall sub_0041D920(Obj0041D920* pObj, int nUnusedEdx, unsigned int dwFirst, unsigned int dwSecond) {
    pObj->dwBase08 = dwFirst;
    pObj->dwCur00 = dwFirst;
    pObj->dwValue04 = dwSecond;
    pObj->dwValue0C = 0;
    pObj->dwValue10 = 0;
    return pObj;
}

// 0x0041D940
extern "C" __declspec(dllexport) int __fastcall sub_0041D940(Obj0041D940* pObj) {
    return pObj->nValue08 - pObj->nValue00;
}

// 0x0041D950
void D2StormHuffOutputStrc::sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits)
{
    nBitBuffer |= nValue << nBitCount;
    nBitCount += nBits;
    while (nBitCount >= 8)
    {
        if (f_4)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            f_4--;
        }
        nBitBuffer >>= 8;
        nBitCount -= 8;
    }
}

// 0x0041D9E0
void D2StormHuffTreeStrc::sub_0041D9E0_EncodeOne(D2StormHuffOutputStrc* pOutput, unsigned int nValue)
{
    D2StormHuffItemStrc* pItem = pItemsByValue[nValue];
    unsigned int nCode = 0;
    unsigned int nBits = 0;
    for (D2StormHuffItemStrc* pParent = pItem->pParent; pParent; pParent = pParent->pParent)
    {
        nCode = (nCode << 1) | (pParent->pChild != pItem);
        nBits++;
        pItem = pParent;
    }
    pOutput->sub_0041D950_PutBits(nCode, nBits);
}

// 0x0041F350
void D2StormHuffTreeStrc::sub_0041F350_IncWeights(D2StormHuffItemStrc* pItem)
{
    for (; pItem; pItem = pItem->pParent)
    {
        pItem->nWeight++;
        D2StormHuffItemStrc* pCur = pItem;
        D2StormHuffItemStrc* pNext;
        for (;;)
        {
            pNext = (D2StormHuffItemStrc*)pCur->f_0.Next();
            if (!pNext || pNext->nWeight >= pItem->nWeight)
                break;
            pCur = pNext;
        }
        if (pCur == pItem)
            continue;
        tItemList.LinkNode((char*)pCur, 2, (char*)pItem);
        tItemList.LinkNode((char*)pItem, 2, (char*)pNext);
        D2StormHuffItemStrc* pCurParentChild = pCur->pParent->pChild;
        if (pItem->pParent->pChild == pItem)
            pItem->pParent->pChild = pCur;
        if (pCurParentChild == pCur)
            pCur->pParent->pChild = pItem;
        D2StormHuffItemStrc* pTemp = pItem->pParent;
        pItem->pParent = pCur->pParent;
        pCur->pParent = pTemp;
        nUnk0x04++;
    }
}

// 0x0041DA30
static __declspec(noinline) void sub_0041DA30_GetCompressionLevel(unsigned int nCmpLevel, unsigned char* pnLevel, int* pCmpType)
{
    switch (nCmpLevel)
    {
    case 1:
    case 2:
        *pnLevel = 4;
        *pCmpType = 6;
        break;
    case 3:
        *pnLevel = 6;
        *pCmpType = 8;
        break;
    default:
        *pnLevel = 5;
        *pCmpType = 7;
        break;
    }
}

static int __stdcall sub_0041DA60_CompressADPCM(int nOutSize, const short* pIn, int nInSize, unsigned int nChannels, unsigned char nLevel, unsigned char* pOut)
{
    unsigned char* pOutStart = pOut;
    if ((unsigned int)nOutSize < 2)
    {
        return 2;
    }
    D2AdpcmHeaderStrc tHeader;
    tHeader.f_1 = nLevel - 1;
    tHeader.nZero = 0;
    *(D2AdpcmHeaderStrc*)pOut = tHeader;
    pOut += 2;
    const int nHeader = nChannels * 2 + (pOut - pOutStart);
    if (nHeader > nOutSize)
    {
        return nHeader;
    }
    int aPredicted[2];
    int aStepIndex[2];
    aStepIndex[0] = 0x2C;
    aStepIndex[1] = 0x2C;
    for (unsigned int i = 0; i < nChannels; i++)
    {
        const short nSample = *pIn++;
        aPredicted[i] = nSample;
        *(short*)pOut = nSample;
        pOut += 2;
    }
    int nGrowLeft = nInSize / 2 - (pOut - pOutStart);
    if (nGrowLeft < 0)
    {
        nGrowLeft = 0;
    }
    unsigned int nIndex = nChannels;
    const unsigned int nWords = (unsigned int)nInSize >> 1;
    int nChannel = nChannels - 1;
    if (nIndex >= nWords)
    {
        return pOut - pOutStart;
    }
    do
    {
        if ((pOut - pOutStart) + 2 > nOutSize)
        {
            return (pOut - pOutStart) + 2;
        }
        if (nChannels == 2)
        {
            nChannel = nChannel == 0;
        }
        const int nSample = *pIn++;
        int nDifference = nSample - aPredicted[nChannel];
        const unsigned int nAbs = nDifference < 0 ? -nDifference : nDifference;
        const unsigned char nSignBit = nSample >= aPredicted[nChannel] ? 0 : 0x40;
        unsigned int nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
        if (nAbs < (nStepSize >> nLevel))
        {
            if (aStepIndex[nChannel])
            {
                aStepIndex[nChannel]--;
            }
            *pOut++ = 0x80;
        }
        else
        {
            while (nAbs > nStepSize * 2 && aStepIndex[nChannel] < 0x58 && nGrowLeft)
            {
                aStepIndex[nChannel] += 8;
                if (aStepIndex[nChannel] > 0x58)
                {
                    aStepIndex[nChannel] = 0x58;
                }
                nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
                nGrowLeft--;
                *pOut++ = 0x81;
            }
            const unsigned int nStepRest = nStepSize >> tHeader.f_1;
            const unsigned int nMaxBit = 1 << (nLevel - 2);
            unsigned int nTotal = 0;
            unsigned int nMask = 0;
            unsigned int nLimit = 0x20;
            unsigned int nBit = 1;
            if (nMaxBit <= 0x20)
            {
                nLimit = nMaxBit;
            }
            for (;;)
            {
                if (nTotal + nStepSize <= nAbs)
                {
                    nTotal += nStepSize;
                    nMask |= nBit;
                }
                if (nBit == nLimit)
                {
                    break;
                }
                nStepSize >>= 1;
                nBit <<= 1;
            }
            const int nDelta = nTotal + nStepRest;
            int nPredicted = aPredicted[nChannel];
            if (nSignBit)
            {
                nPredicted -= nDelta;
                if (nPredicted < -0x8000)
                {
                    nPredicted = -0x8000;
                }
            }
            else
            {
                nPredicted += nDelta;
                if (nPredicted > 0x7FFF)
                {
                    nPredicted = 0x7FFF;
                }
            }
            *pOut++ = nSignBit | (unsigned char)nMask;
            aStepIndex[nChannel] += gaADPCMIndexTable_006CFCB8[nMask & 0x1F];
            aPredicted[nChannel] = nPredicted;
            if (aStepIndex[nChannel] < 0)
            {
                aStepIndex[nChannel] = 0;
            }
            else if (aStepIndex[nChannel] > 0x58)
            {
                aStepIndex[nChannel] = 0x58;
            }
        }
        nIndex++;
    } while (nIndex < nWords);
    return pOut - pOutStart;
}

void __fastcall sub_0041E360_SCompADPCMCompressMono(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = sub_0041DA60_CompressADPCM(*pcbOutBuffer, pvInBuffer, cbInBuffer, 1, nLevel, pvOutBuffer);
}

void __fastcall sub_0041E3C0_SCompADPCMCompressStereo(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = sub_0041DA60_CompressADPCM(*pcbOutBuffer, pvInBuffer, cbInBuffer, 2, nLevel, pvOutBuffer);
}
