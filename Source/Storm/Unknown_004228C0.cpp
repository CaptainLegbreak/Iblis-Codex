#include "Storm.h"
#include "D2StormLink.h"

struct D2StormArrayAStrc;
struct D2StormQueueStrc;
struct D2StormBigStrc;
struct D2StormBigStackStrc;
struct D2StormHandleRefStrc;
struct D2StormHandleStrc;
struct D2StormHandlePairStrc;
struct D2StormLinkStrc;
struct D2StormListAStrc;

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

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
    void SetCount(unsigned int nCount)
    {
        if (nCount > f_4)
            Reserve(nCount - f_4, 1);
        f_4 = nCount;
    }
    void GrowToFit(unsigned int nIndex, int bZero)
    {
        if (nIndex < f_4)
            return;
        Reserve(nIndex - f_4 + 1, 1);
        if (bZero)
            SMemZero(&f_8[f_4], (nIndex - f_4 + 1) * sizeof(unsigned int));
        f_4 = nIndex + 1;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int IsUsed(unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.f_4;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
    }
    __forceinline unsigned int& operator[](unsigned int nIndex)
    {
        m_array.GrowToFit(m_start + nIndex, 1);
        return m_array.f_8[m_start + nIndex];
    }
    void SetCount(unsigned int nCount)
    {
        m_array.SetCount(m_start + nCount);
    }
};

struct D2StormBigStrc
{
    D2StormQueueStrc tPrimary;
    char unk0x14[0x154];
};

struct D2StormBigStackStrc
{
    D2StormQueueStrc f_0[16];
    unsigned int nUsed;
};

static void __stdcall sub_00422300_Add(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c);
int __stdcall sub_00425330(void* hHandle, int nArg1, int nArg2, int nArg3); // 0x00425330
void __stdcall SBigToBinaryBuffer(void* hHandle, void* pBuffer, unsigned int nSize, unsigned int* pRead); // 0x00423B30
int __stdcall sub_00423850(void* hHandle, int nArg1, int nArg2); // 0x00423850

struct D2StormHandleRefStrc
{
    void* hHandle;

    D2StormHandleRefStrc& sub_00425FE0_Apply(const int& nArg1, const int& nArg2, const int& nArg3);
};

struct D2StormHandleStrc
{
    void* hHandle;

    void* sub_00426010_ReadFill(void* pBuffer, unsigned int nSize);
    int sub_00426050_Call(int nArg1, int nArg2);
};

struct D2StormHandlePairStrc
{
    void* hFirst;
    void* hSecond;

    void sub_00426070_CallBoth(int nArg1, int nArg2, int nArg3, int nArg4);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(D2StormLinkStrc* pNode)
    {
        return pNode ? pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_00426AE0_Link(D2StormLinkStrc* pNode);
    void sub_00426B00_LinkNode(D2StormLinkStrc* pNode, int nLinkType, D2StormLinkStrc* pExisting);
    char* sub_00426BB0_Next(D2StormLinkStrc* pNode);
    void sub_00426C10_UnlinkNode(D2StormLinkStrc* pNode);
    char* sub_00426C80_RawNext(D2StormLinkStrc* pNode);
};

// 0x004228C0
static void __stdcall sub_004228C0_Not(D2StormQueueStrc& a, const D2StormQueueStrc& b)
{
    unsigned int i = 0;
    for (; b.IsUsed(i); i++)
    {
        a[i] = ~b[i];
    }
    a.SetCount(i);
}

// 0x004239E0
void __stdcall sub_004239E0_BigNot(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    sub_004228C0_Not(pResult->tPrimary, pA->tPrimary);
}

inline unsigned int ExtractLowPart(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    return nLow;
}

static void __stdcall sub_00422300_Add(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c)
{
    unsigned __int64 nCarry = 0;
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        nCarry += (unsigned __int64)b[i] + c[i];
        a[i] = ExtractLowPart(nCarry);
    }
    if (nCarry)
    {
        a[i] = (unsigned int)nCarry;
        i++;
    }
    a.SetCount(i);
}

// 0x00423790
void __stdcall SBigAdd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00422300_Add(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

static void __stdcall sub_00422440_And(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] & c[i];
    }
    a.SetCount(i);
}

// 0x004237B0
void __stdcall sub_004237B0_BigAnd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00422440_And(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

static void __stdcall sub_004229D0_Or(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] | c[i];
    }
    a.SetCount(i);
}

// 0x00423A00
void __stdcall sub_00423A00_BigOr(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_004229D0_Or(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

static void __stdcall sub_00423250_Xor(D2StormQueueStrc& a, const D2StormQueueStrc& b, const D2StormQueueStrc& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] ^ c[i];
    }
    a.SetCount(i);
}

// 0x00423D60
void __stdcall sub_00423D60_BigXor(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00423250_Xor(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00425FE0
D2StormHandleRefStrc& D2StormHandleRefStrc::sub_00425FE0_Apply(const int& nArg1, const int& nArg2, const int& nArg3)
{
    sub_00425330(hHandle, nArg1, nArg2, nArg3);
    return *this;
}

// 0x00426010
void* D2StormHandleStrc::sub_00426010_ReadFill(void* pBuffer, unsigned int nSize)
{
    unsigned int nRead;
    SBigToBinaryBuffer(hHandle, pBuffer, nSize, &nRead);
    if (nRead < nSize)
        sub_0041D300_ZeroMemory((char*)pBuffer + nRead, nSize - nRead);
    return pBuffer;
}

// 0x00426050
int D2StormHandleStrc::sub_00426050_Call(int nArg1, int nArg2)
{
    return sub_00423850(hHandle, nArg1, nArg2);
}

// 0x00426070
void D2StormHandlePairStrc::sub_00426070_CallBoth(int nArg1, int nArg2, int nArg3, int nArg4)
{
    sub_00423850(hFirst, nArg1, nArg2);
    sub_00423850(hSecond, nArg3, nArg4);
}

// 0x00426930
D2StormLinkStrc* D2StormLinkStrc::sub_00426930_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x00426AE0
D2StormLinkStrc* D2StormListAStrc::sub_00426AE0_Link(D2StormLinkStrc* pNode)
{
    return Link(pNode);
}

// 0x00426B00
void D2StormListAStrc::sub_00426B00_LinkNode(D2StormLinkStrc* pNode, int nLinkType, D2StormLinkStrc* pExisting)
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
        pExistingLink->m_next = (char*)pNode;
        break;
    default:
        {
            D2StormLinkStrc* pPrev = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrev;
            pLink->m_next = pPrev->m_next;
            pPrev->m_next = (char*)pNode;
            pExistingLink->m_prevlink = pLink;
        }
        break;
    }
}

// 0x00426BB0
char* D2StormListAStrc::sub_00426BB0_Next(D2StormLinkStrc* pNode)
{
    return Link(pNode)->Next();
}

// 0x00426C10
void D2StormListAStrc::sub_00426C10_UnlinkNode(D2StormLinkStrc* pNode)
{
    Link(pNode)->Unlink();
}

// 0x00426C80
char* D2StormListAStrc::sub_00426C80_RawNext(D2StormLinkStrc* pNode)
{
    return pNode ? pNode->m_next : m_terminator.m_next;
}
