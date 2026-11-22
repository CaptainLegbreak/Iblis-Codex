#pragma once
// Storm big-number buffer: a growable array of 32-bit limbs plus a start offset.

#include "D2StormArrayA.h"

struct BigBuffer
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
    __forceinline unsigned int& operator[](unsigned int nIndex)
    {
        m_array.GrowToFit(m_start + nIndex, 1);
        return m_array.f_8[m_start + nIndex];
    }
    void SetCount(unsigned int nCount)
    {
        m_array.SetCount(m_start + nCount);
    }
    void CopyFrom(const BigBuffer& tSource)
    {
        if (this != &tSource)
            m_array.sub_004215C0_Set(tSource.m_array.f_4, tSource.m_array.f_8);
        m_array.f_C = tSource.m_array.f_C;
        m_start = tSource.m_start;
    }
    unsigned int& Ref(int nIndex)
    {
        GrowToFit(nIndex);
        return m_array.f_8[m_start + nIndex];
    }
    inline unsigned int& At(unsigned int nIndex)
    {
        m_array.GrowToFitInline(m_start + nIndex);
        return m_array.f_8[m_start + nIndex];
    }
    void SetStart(unsigned int nStart)
    {
        m_start = nStart;
        if (nStart)
            GrowToFit(-1);
    }
    void GrowToFit(int nIndex);                                                                // 0x00421FE0
    void sub_004220D0_SetCount(unsigned int nCount);                                                        // 0x004220D0
    void sub_00422140_Trim();                                                                               // 0x00422140
};

struct BigStack
{
    union
    {
        BigBuffer f_0[16];
        BigBuffer pRecords[16];
    };
    unsigned int nUsed;
};
