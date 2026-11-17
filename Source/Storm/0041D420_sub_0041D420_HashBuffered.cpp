struct SMSGHANDLER_PARAMS;

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2A0
void __stdcall SMemMove(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2E0
int __stdcall sub_00426E80_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00426E80

extern int gdwGlobal_007792F4;                                                                              // 0x007792F4

struct D2StormHashCtxStrc
{
    unsigned int nBitCountLo;
    unsigned int nBitCountHi;
    unsigned int nState[5];
    unsigned char pBlock[64];

    void sub_00425DD0_Update(const void* pData, unsigned int nSize);                                        // 0x00425DD0
};

struct D2StormHashBufferStrc
{
    int unk0x00[2];
    unsigned int nUsed;
    int nWindow;
    char* pBuffer;
    int unk0x14;
    D2StormHashCtxStrc tHash;
};

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

struct D2StormBitReaderStrc
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
    D2StormLinkStrc* sub_0041E900_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_004203F0_NextLink(int nLinkOffset);
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
    void sub_0041ED90_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);
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

struct D2StormRecord14Strc
{
    int nData[5];
};

struct D2StormRecordStackStrc
{
    D2StormRecord14Strc pRecords[16];
    unsigned int nUsed;

    D2StormRecord14Strc* sub_00420DD0_Push(int* pCounter);
    void sub_00420E00_Drop(unsigned int nCount);
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

struct D2StormQueueStrc
{
    D2StormPtrArrayStrc m_array;
    unsigned int m_start;

    int InRange(unsigned int nIndex)
    {
        return m_start + nIndex < m_array.f_4;
    }
    int sub_00420DB0_InRange(unsigned int nIndex);
    int sub_004212D0_Get(unsigned int nIndex);
};

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);
};

struct D2StormArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);
};

struct D2StormArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

    unsigned int sub_00421240_CalcChunkSize(unsigned int nCount);
};

// 0x0041D420
void __fastcall sub_0041D420_HashBuffered(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize)
{
    int nExtra = nSize - pBuffer->nWindow;
    if (nExtra >= 0)
    {
        if (pBuffer->nUsed > 0)
            pBuffer->tHash.sub_00425DD0_Update(pBuffer->pBuffer, pBuffer->nUsed);
        if (nExtra > 0)
            pBuffer->tHash.sub_00425DD0_Update(pData, nExtra);
        SMemCopy(pBuffer->pBuffer, pData + nExtra, pBuffer->nWindow);
        pBuffer->nUsed = pBuffer->nWindow;
    }
    else
    {
        int nOver = pBuffer->nUsed - pBuffer->nWindow + nSize;
        if (nOver > 0)
        {
            pBuffer->tHash.sub_00425DD0_Update(pBuffer->pBuffer, nOver);
            pBuffer->nUsed -= nOver;
            SMemMove(pBuffer->pBuffer, pBuffer->pBuffer + nOver, pBuffer->nUsed);
        }
        SMemCopy(pBuffer->pBuffer + pBuffer->nUsed, pData, nSize);
        pBuffer->nUsed += nSize;
    }
}

// 0x0041D8D0
unsigned int D2StormBitReaderStrc::sub_0041D8D0_Peek(unsigned int nBits, unsigned int nMask)
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
void D2StormBitReaderStrc::sub_0041D900_Skip(unsigned int nBits)
{
    nBitBuffer >>= nBits;
    nBitCount -= nBits;
}

// 0x0041DEC0
unsigned int __cdecl sub_0041DEC0_ReadMemory(char* pBuffer, unsigned int* pSize, D2StormMemSourceStrc* pSource)
{
    unsigned int nAvail = pSource->nSize - pSource->nPos;
    unsigned int nSize = *pSize < nAvail ? *pSize : nAvail;
    SMemCopy(pBuffer, pSource->pBuffer + pSource->nPos, nSize);
    pSource->nPos += nSize;
    return nSize;
}

// 0x0041DF00
void __cdecl sub_0041DF00_WriteMemory(char* pBuffer, unsigned int* pSize, D2StormMemSinkStrc* pSink)
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
unsigned int D2StormBitReaderStrc::sub_0041E9E0_Get(unsigned int nBits, unsigned int nMask)
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

// 0x0041ED90
void D2StormNodeListAStrc::sub_0041ED90_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
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

// 0x00420290
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg)
{
    return sub_00426E80_BreakHandlerChain(pMsg);
}

// 0x004203A0
int __stdcall SMsgSetDefaultWindow(int hWnd)
{
    gdwGlobal_007792F4 = hWnd;
    return 1;
}

// 0x004203F0
D2StormLinkStrc* D2StormLinkStrc::sub_004203F0_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00420520
D2StormLinkStrc* D2StormNodeListBStrc::sub_00420520_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
}

// 0x00420540
void D2StormNodeListBStrc::sub_00420540_LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
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

// 0x004205F0
char* D2StormNodeListBStrc::sub_004205F0_Next(char* pNode)
{
    return Link(pNode)->Next();
}

// 0x00420650
void D2StormNodeListBStrc::sub_00420650_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x004206E0
char* D2StormNodeListBStrc::sub_004206E0_RawNext(char* pNode)
{
    return pNode ? ((D2StormLinkStrc*)pNode)->m_next : m_terminator.m_next;
}

// 0x00420DB0
int D2StormQueueStrc::sub_00420DB0_InRange(unsigned int nIndex)
{
    return m_start + nIndex < m_array.f_4;
}

// 0x00420DD0
D2StormRecord14Strc* D2StormRecordStackStrc::sub_00420DD0_Push(int* pCounter)
{
    if (pCounter)
        ++*pCounter;
    return &pRecords[nUsed++];
}

// 0x00420E00
void D2StormRecordStackStrc::sub_00420E00_Drop(unsigned int nCount)
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
int D2StormQueueStrc::sub_004212D0_Get(unsigned int nIndex)
{
    return InRange(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
}
