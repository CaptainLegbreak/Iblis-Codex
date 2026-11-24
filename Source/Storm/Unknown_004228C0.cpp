#include "Storm.h"
#include "D2StormLink.h"

struct D2StormBigStrc;
struct BigStack;
struct D2StormHandleRefStrc;
struct BigNum;
namespace Crypt { struct RSA; }
struct D2StormLinkStrc;
struct D2StormListAStrc;

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

#include "D2StormBigBuffer.h"


struct D2StormBigStrc
{
    BigBuffer tPrimary;
    char unk0x14[0x154];
};

int __stdcall SBigPowMod(void* hHandle, int nArg1, int nArg2, int nArg3); // 0x00425330
void __stdcall SBigToBinaryBuffer(void* hHandle, void* pBuffer, unsigned int nSize, unsigned int* pRead); // 0x00423B30
int __stdcall sub_00423850(void* hHandle, int nArg1, int nArg2); // 0x00423850

struct D2StormHandleRefStrc
{
    void* hHandle;

    D2StormHandleRefStrc& sub_00425FE0_Apply(const int& nArg1, const int& nArg2, const int& nArg3);
};

struct BigNum
{
    void* hHandle;

    void* sub_00426010_ReadFill(void* pBuffer, unsigned int nSize);
    int sub_00426050_Call(int nArg1, int nArg2);
};

namespace Crypt
{

struct RSA
{
    void* hFirst;
    void* hSecond;

    void Prepare(int nArg1, int nArg2, int nArg3, int nArg4);
};

}

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

inline unsigned int ExtractLowPart(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    return nLow;
}

// build: symbol ?BigAnd@* 0x00422440
static void __stdcall BigAnd(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] & c[i];
    }
    a.SetCount(i);
}

// build: symbol ?BigOr@* 0x004229D0
static void __stdcall BigOr(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] | c[i];
    }
    a.SetCount(i);
}

// build: symbol ?BigXor@* 0x00423250
static void __stdcall BigXor(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] ^ c[i];
    }
    a.SetCount(i);
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
