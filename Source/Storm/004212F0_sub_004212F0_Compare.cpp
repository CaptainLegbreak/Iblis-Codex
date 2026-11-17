inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern char gszTypeNameChar_0070888C[];                                                                   // 0x0070888C

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
    unsigned int* sub_00420FE0_Top();                                                                       // 0x00420FE0
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct D2StormArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;
    unsigned int f_C;

    void sub_00421770_ReallocData(unsigned int nAlloc);
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int Count() const
    {
        return m_array.f_4 - m_start;
    }
    int IsUsed(unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.f_4;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.f_8[m_start + nIndex] : 0;
    }
    void sub_00422140_Trim();
};

// 0x004212F0
int __stdcall sub_004212F0_Compare(D2StormQueueStrc* pLeft, D2StormQueueStrc* pRight)
{
    int nResult = 0;
    for (unsigned int i = 0; pLeft->IsUsed(i) || pRight->IsUsed(i); ++i)
    {
        if ((*pLeft)[i] != (*pRight)[i])
            nResult = (*pLeft)[i] > (*pRight)[i] ? 1 : -1;
    }
    return nResult;
}

// 0x00421770
void D2StormArrayCStrc::sub_00421770_ReallocData(unsigned int nAlloc)
{
    char* pOld = f_8;
    f_0 = nAlloc;
    f_8 = (char*)SMemReAlloc(pOld, nAlloc, gszTypeNameChar_0070888C, -2, 0x10);
    if (!f_8)
    {
        f_8 = (char*)SMemAlloc(nAlloc, gszTypeNameChar_0070888C, -2, 0);
        if (pOld)
        {
            if (nAlloc >= f_4)
                nAlloc = f_4;
            for (unsigned int i = 0; i < nAlloc; ++i)
                new (&f_8[i]) char(pOld[i]);
            SMemFree(pOld, gszTypeNameChar_0070888C, -2, 0);
        }
    }
}

// 0x00422140
void D2StormQueueStrc::sub_00422140_Trim()
{
    while (Count())
    {
        if (*m_array.sub_00420FE0_Top())
            break;
        m_array.SetCount(m_array.f_4 - 1);
    }
}

#include "gen/data/Source/Storm/004212F0_sub_004212F0_Compare.inc"
