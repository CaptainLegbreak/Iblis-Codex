#include "D2StormTypes.h"
struct D2StormArrayAStrc;
struct BigBuffer;
struct BigStack;
struct D2StormBigStrc;

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    BigBuffer& operator=(const BigBuffer& tSource)
    {
        if (this != &tSource)
        {
            m_array.sub_004215C0_Set(tSource.m_array.f_4, tSource.m_array.f_8);
        }
        m_array.f_C = tSource.m_array.f_C;
        m_start = tSource.m_start;
        return *this;
    }
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;
};

struct D2StormBigStrc
{
    BigBuffer tQueue;
    BigStack tStack;
    int unk0x158[4];
};

int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack);

// 0x00424640
static void __stdcall Pow(BigBuffer* pResult, BigBuffer* pBase, unsigned int nExp, BigStack* pStack)
{
    unsigned int nBit = nExp;
    while (nBit & (nBit - 1))
    {
        nBit &= nBit - 1;
    }
    BigBuffer* pWork = (pResult == pBase) ? &pStack->pRecords[pStack->nUsed++] : pResult;
    if (pWork != pBase)
    {
        D2StormArrayViewStrc tView;
        tView.pData = pBase->m_array.f_8;
        tView.nCount = pBase->m_array.f_4;
        pWork->m_array.sub_004215C0_Set(tView.nCount, tView.pData);
    }
    pWork->m_array.f_C = pBase->m_array.f_C;
    pWork->m_start = pBase->m_start;
    while (nBit > 1)
    {
        sub_004242C0_BigOp(pWork, pWork, pWork, pStack);
        nBit >>= 1;
        if (nExp & nBit)
        {
            sub_004242C0_BigOp(pWork, pWork, pBase, pStack);
        }
    }
    if (pResult != pWork)
    {
        *pResult = *pWork;
        pStack->nUsed--;
    }
}

// 0x00424F50
void __stdcall SBigPow(D2StormBigStrc* pResult, D2StormBigStrc* pBase, unsigned int nExp)
{
    Pow(&pResult->tQueue, &pBase->tQueue, nExp, &pResult->tStack);
}
