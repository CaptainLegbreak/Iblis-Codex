#include "D2StormTypes.h"
struct D2StormArrayAStrc;
struct D2StormQueueStrc;
struct D2StormRecordStackStrc;
struct D2StormBigStrc;

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    D2StormQueueStrc& operator=(const D2StormQueueStrc& tSource)
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

struct D2StormRecordStackStrc
{
    D2StormQueueStrc pRecords[16];
    unsigned int nUsed;
};

struct D2StormBigStrc
{
    D2StormQueueStrc tQueue;
    D2StormRecordStackStrc tStack;
    int unk0x158[4];
};

int __stdcall sub_004242C0_BigOp(D2StormQueueStrc* pResult, D2StormQueueStrc* pA, D2StormQueueStrc* pB, D2StormRecordStackStrc* pStack);

// 0x00424640
static void __stdcall sub_00424640_BigPow(D2StormQueueStrc* pResult, D2StormQueueStrc* pBase, unsigned int nExp, D2StormRecordStackStrc* pStack)
{
    unsigned int nBit = nExp;
    while (nBit & (nBit - 1))
    {
        nBit &= nBit - 1;
    }
    D2StormQueueStrc* pWork = (pResult == pBase) ? &pStack->pRecords[pStack->nUsed++] : pResult;
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
    sub_00424640_BigPow(&pResult->tQueue, &pBase->tQueue, nExp, &pResult->tStack);
}
