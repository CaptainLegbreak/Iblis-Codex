#include "Storm.h"

struct D2StormArrayAStrc;
struct D2StormArrayBStrc;
struct D2StormArrayCStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct BigBuffer;
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct D2StormArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;
    void sub_004216E0_ReallocData(unsigned int nAlloc);
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_00421AB0_Reserve(unsigned int nCount, int bRound);
};

struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;
    void sub_004211C0_ReallocData(unsigned int nAlloc);
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_00421630_Reserve(unsigned int nCount, int bRound);
    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);                         // 0x004218B0
    void sub_004219F0_Set(unsigned int nCount, const unsigned char* pData);                                 // 0x004219F0
    void Reserve(unsigned int nCount)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_00421160_CalcChunkSize(nCount);
            sub_004211C0_ReallocData(RoundUp(nCount, nChunk));
        }
    }
    void Push(unsigned char nByte)
    {
        Reserve(1);
        m_data[m_count] = nByte;
        m_count += 1;
    }
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
};

struct D2StormArrayCStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    void* m_data;
    unsigned int m_chunk;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00421240_CalcChunkSize(unsigned int nCount);                                           // 0x00421240
    void sub_00421770_ReallocData(unsigned int nAlloc);                                                     // 0x00421770
    void sub_00421B00_Reserve(unsigned int nCount, int bRound);
};
extern "C" const char gszTypeNewsTableItem_0072FF8C[];

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;
};

void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, BigBuffer* pIn); // 0x00421CB0

inline void* operator new(unsigned int, void* pPlace) throw();

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

// 0x004211C0
void D2StormArrayBStrc::sub_004211C0_ReallocData(unsigned int nAlloc)
{
    unsigned char* pOld = m_data;
    m_alloc = nAlloc;
    m_data = (unsigned char*)SMemReAlloc(pOld, nAlloc, gszTypeNameUChar_00708880, -2, 0x10);
    if (!m_data)
    {
        m_data = (unsigned char*)SMemAlloc(nAlloc, gszTypeNameUChar_00708880, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < m_count ? nAlloc : m_count;
            for (unsigned int i = 0; i < nCount; i++)
                new (&m_data[i]) unsigned char(pOld[i]);
            SMemFree(pOld, gszTypeNameUChar_00708880, -2, 0);
        }
    }
}

// 0x004216E0
void D2StormArrayAStrc::sub_004216E0_ReallocData(unsigned int nAlloc)
{
    unsigned int* pOld = m_data;
    m_alloc = nAlloc;
    m_data = (unsigned int*)SMemReAlloc(pOld, nAlloc * 4, gszTypeNameUInt_00708874, -2, 0x10);
    if (!m_data)
    {
        m_data = (unsigned int*)SMemAlloc(nAlloc * 4, gszTypeNameUInt_00708874, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < m_count ? nAlloc : m_count;
            for (unsigned int i = 0; i < nCount; i++)
                new (&m_data[i]) unsigned int(pOld[i]);
            SMemFree(pOld, gszTypeNameUInt_00708874, -2, 0);
        }
    }
}

#include "gen/data/Source/Storm/Unknown_004211C0.inc"

// 0x00421630
void D2StormArrayBStrc::sub_00421630_Reserve(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_00421160_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_004211C0_ReallocData(nCount);
    }
}

// 0x00421AB0
void D2StormArrayAStrc::sub_00421AB0_Reserve(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_004210A0_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_004216E0_ReallocData(nCount);
    }
}

// 0x00421B00
void D2StormArrayCStrc::sub_00421B00_Reserve(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_00421240_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_00421770_ReallocData(nCount);
    }
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    return this;
}

// build: symbol ?BNNEWS_CopyNewsItem@* 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x004218A0
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (m_data)
        SMemFree(m_data, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &m_data[m_count++];
}

inline unsigned int D2StormArrayBStrc::sub_00421160_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x100)
    {
        unsigned int nResult = nCount;
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 0x100;
    return 0x100;
}

// 0x004219D0
unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
}
