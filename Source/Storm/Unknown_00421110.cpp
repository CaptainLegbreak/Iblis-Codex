#include "Storm.h"

#define TO_UNSIGNED sub_00421510_ToUnsigned

struct D2StormFixedArrayAStrc;
struct D2StormArrayAStrc;
struct D2StormFixedArrayBStrc;
struct D2StormFixedArrayCStrc;
struct D2StormArrayBStrc;
struct BigBuffer;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct D2StormFixedArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;

    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_00421110_ReallocData(unsigned int nAlloc);
    D2StormFixedArrayAStrc& sub_00421870_Assign(const D2StormFixedArrayAStrc& tSource);
};

struct D2StormArrayAStrc : D2StormFixedArrayAStrc
{
    unsigned int f_C;

    D2StormArrayAStrc& sub_00421BA0_Assign(const D2StormArrayAStrc& tSource);
};

struct D2StormFixedArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;

    void sub_00421680_ReallocData(unsigned int nAlloc);
};

struct D2StormFixedArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    char* f_8;

    void sub_004216B0_ReallocData(unsigned int nAlloc);
};

struct D2StormArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    void sub_00421980_SetCount(unsigned int nCount);
};

struct BigBuffer
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

    unsigned int At(unsigned int nIndex) const
    {
        return m_offset + nIndex < f_4 ? f_8[m_offset + nIndex] : 0;
    }
};

int __stdcall sub_004212F0_Compare(void* hLeft, void* hRight); // 0x004212F0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszTypeNewsTableItem_0072FF8C[];

static __declspec(noinline) void __cdecl sub_00421510_ToUnsigned(unsigned int* pnResult, BigBuffer* pBuf);

// 0x00421110
void D2StormFixedArrayAStrc::sub_00421110_ReallocData(unsigned int nAlloc)
{
    f_0 = nAlloc;
    if (f_8 || nAlloc)
        f_8 = (unsigned int*)SMemReAlloc(f_8, nAlloc * sizeof(unsigned int), gszTypeNameUInt_00708874, -2, 0);
}

// 0x00421680
void D2StormFixedArrayBStrc::sub_00421680_ReallocData(unsigned int nAlloc)
{
    f_0 = nAlloc;
    if (f_8 || nAlloc)
        f_8 = (unsigned char*)SMemReAlloc(f_8, nAlloc, gszTypeNameUChar_00708880, -2, 0);
}

// 0x004216B0
void D2StormFixedArrayCStrc::sub_004216B0_ReallocData(unsigned int nAlloc)
{
    f_0 = nAlloc;
    if (f_8 || nAlloc)
        f_8 = (char*)SMemReAlloc(f_8, nAlloc, gszTypeNameChar_0070888C, -2, 0);
}

// 0x00421870
D2StormFixedArrayAStrc& D2StormFixedArrayAStrc::sub_00421870_Assign(const D2StormFixedArrayAStrc& tSource)
{
    if (this != &tSource)
        sub_004215C0_Set(tSource.f_4, tSource.f_8);
    return *this;
}

// 0x00421980
void D2StormArrayBStrc::sub_00421980_SetCount(unsigned int nCount)
{
    if (nCount > f_4 && nCount > f_0)
    {
        unsigned int nChunk = f_C ? f_C : sub_00421160_CalcChunkSize(nCount);
        sub_004211C0_ReallocData(RoundUp(nCount, nChunk));
    }
    f_4 = nCount;
}

// 0x00421BA0
D2StormArrayAStrc& D2StormArrayAStrc::sub_00421BA0_Assign(const D2StormArrayAStrc& tSource)
{
    if (this != &tSource)
        sub_004215C0_Set(tSource.f_4, tSource.f_8);
    f_C = tSource.f_C;
    return *this;
}

// 0x00421510
static __declspec(noinline) void __cdecl sub_00421510_ToUnsigned(unsigned int* pnResult, BigBuffer* pBuf)
{
    *pnResult = 0;
    *pnResult = pBuf->At(0);
}

// 0x00421530
int __stdcall sub_00421530(void* hLeft, void* hRight)
{
    return sub_004212F0_Compare(hLeft, hRight);
}

// 0x00421550
void __stdcall SBigToUnsigned(void* hBig, unsigned int* pnResult)
{
    TO_UNSIGNED(pnResult, (BigBuffer*)hBig);
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
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D2C0_InitBase()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    return this;
}

void __cdecl sub_0051D2D0_Nop()
{
}

void __cdecl sub_0051D2E0_Nop()
{
}

void __fastcall sub_0051D350_CopyElement(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

void D2StormArray408Strc::sub_0051D570_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

void D2StormArray408Strc::sub_0051D670_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

// 0x00421860
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D6A0_Clear()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

D2StormArray408Strc* D2StormArray408Strc::sub_0051D720_Init()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
    f_C = 0;
    return this;
}

void D2StormArray408Strc::sub_0051D730_FreeData()
{
    if (f_8)
        SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
}

D2Storm408ElemStrc* D2StormArray408Strc::sub_0051D7A0_New()
{
    ReserveInline(1, 1);
    return &f_8[f_4++];
}
