#include "Storm.h"

struct D2StormArrayAStrc;
struct D2StormArrayBStrc;
struct D2StormArrayCStrc;
struct D2Storm408ElemStrc;
struct D2StormArray408Strc;
struct D2StormQueueStrc;
struct D2StormRecordStackStrc;
struct D2StormBigStrc;

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
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
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;
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
    // build: context D2StormArrayBStrc::Reserve
    void Reserve(unsigned int nCount)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : sub_00421160_CalcChunkSize(nCount);
            sub_004211C0_ReallocData(RoundUp(nCount, nChunk));
        }
    }
    // build: context D2StormArrayBStrc::Push
    void Push(unsigned char nByte)
    {
        Reserve(1);
        f_8[f_4] = nByte;
        f_4 += 1;
    }
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
};

struct D2StormArrayCStrc
{
    unsigned int f_0;
    unsigned int f_4;
    void* f_8;
    unsigned int f_C;

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

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszTypeNewsTableItem_0072FF8C[];

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;

    D2StormArray408Strc* sub_0051D2C0_InitBase();
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);
    void sub_0051D570_FreeData();
    void sub_0051D5D0_ReallocData(unsigned int nCount);
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;
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
    D2StormArrayBStrc tBuffer;
};

void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn); // 0x00421CB0

inline void* operator new(unsigned int, void* pPlace) throw();

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

// 0x004211C0
void D2StormArrayBStrc::sub_004211C0_ReallocData(unsigned int nAlloc)
{
    unsigned char* pOld = f_8;
    f_0 = nAlloc;
    f_8 = (unsigned char*)SMemReAlloc(pOld, nAlloc, gszTypeNameUChar_00708880, -2, 0x10);
    if (!f_8)
    {
        f_8 = (unsigned char*)SMemAlloc(nAlloc, gszTypeNameUChar_00708880, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
                new (&f_8[i]) unsigned char(pOld[i]);
            SMemFree(pOld, gszTypeNameUChar_00708880, -2, 0);
        }
    }
}

// 0x004216E0
void D2StormArrayAStrc::sub_004216E0_ReallocData(unsigned int nAlloc)
{
    unsigned int* pOld = f_8;
    f_0 = nAlloc;
    f_8 = (unsigned int*)SMemReAlloc(pOld, nAlloc * 4, gszTypeNameUInt_00708874, -2, 0x10);
    if (!f_8)
    {
        f_8 = (unsigned int*)SMemAlloc(nAlloc * 4, gszTypeNameUInt_00708874, -2, 0);
        if (pOld)
        {
            unsigned int nCount = nAlloc < f_4 ? nAlloc : f_4;
            for (unsigned int i = 0; i < nCount; i++)
                new (&f_8[i]) unsigned int(pOld[i]);
            SMemFree(pOld, gszTypeNameUInt_00708874, -2, 0);
        }
    }
}

#include "gen/data/Source/Storm/Unknown_004211C0.inc"

// 0x00421630
void D2StormArrayBStrc::sub_00421630_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_00421160_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_004211C0_ReallocData(nCount);
    }
}

// 0x00421AB0
void D2StormArrayAStrc::sub_00421AB0_Reserve(unsigned int nCount, int bRound)
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

// 0x00421B00
void D2StormArrayCStrc::sub_00421B00_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_00421240_CalcChunkSize(nCount);
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

// 0x004218A0
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

inline unsigned int D2StormArrayBStrc::sub_00421160_CalcChunkSize(unsigned int nCount)
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

// 0x004219D0
unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
}

static void sub_00421BD0_AppendLength(unsigned int nValue, D2StormArrayBStrc* pArray)
{
    while (nValue)
    {
        pArray->Push((unsigned char)(nValue % 255));
        nValue /= 255;
    }
    pArray->Push(0xFF);
}

// 0x004235F0
static __declspec(noinline) void sub_004235F0_ToBinary(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn)
{
    pOut->f_4 = 0;
    sub_00421CB0_AppendDigits(pOut, pIn);
}

static __declspec(noinline) void sub_00423770_ToStream(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn)
{
    sub_004235F0_ToBinary(pOut, pIn);
    sub_00421BD0_AppendLength(pOut->f_4, pOut);
    sub_00421CB0_AppendDigits(pOut, pIn);
}

// 0x00423AE0
void __stdcall SBigToBinaryArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    sub_004235F0_ToBinary(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
}

// 0x00423B30
void __stdcall sub_00423B30(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead)
{
    D2StormBigStrc* pBig = (D2StormBigStrc*)hBig;
    sub_004235F0_ToBinary(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.f_4 < nSize ? pBig->tBuffer.f_4 : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.f_8, nCopy);
    if (pRead)
        *pRead = nCopy;
}

// 0x00423B80
void __stdcall SBigToBinaryPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    sub_004235F0_ToBinary(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.f_8;
    if (pSize)
        *pSize = pBig->tBuffer.f_4;
}

// 0x00423C90
void __stdcall SBigToStreamArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    sub_00423770_ToStream(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
}

// 0x00423CE0
void __stdcall SBigToStreamBuffer(D2StormBigStrc* pBig, void* pBuffer, unsigned int nSize, unsigned int* pWritten)
{
    sub_00423770_ToStream(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.f_4 < nSize ? pBig->tBuffer.f_4 : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.f_8, nCopy);
    if (pWritten)
        *pWritten = nCopy;
}

// 0x00423D30
void __stdcall SBigToStreamPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    sub_00423770_ToStream(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.f_8;
    *pSize = pBig->tBuffer.f_4;
}
