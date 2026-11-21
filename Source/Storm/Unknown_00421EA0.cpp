#include "D2StormAutoLink.h"
#define DECODE_LENGTH sub_00420F80_DecodeLength
#define FROM_BINARY sub_00423380_FromBinary
#define FROM_LENGTH_PREFIXED sub_004234F0_FromLengthPrefixed

struct D2GameStrc;
struct D2StormArrayAStrc;
struct D2StormArray2Strc;
struct D2StormQueueStrc;
struct D2StormBigStrc;
struct D2StormRecordStackStrc;
struct D2StormArrayBStrc;
struct D2StormBreakCmdStrc;
struct D2GameLinkStrc;
struct D2StormListAStrc;
struct D2StormGameArrayStrc;
struct D2StormHashObjectChunkStrc;
struct D2StormListArrayStrc;
struct D2StormBigBufferStrc;
struct T0041D340;
struct D2StormTSListStrc;

void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
    void sub_00421EA0_GrowToFit(unsigned int nIndex, int bZero);
    void sub_00421F10_SetCount(unsigned int nCount);
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    // build: context D2StormArrayAStrc::Reserve
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
    // build: context D2StormArrayAStrc::SetCount
    void SetCount(unsigned int nCount)
    {
        if (nCount > f_4)
            Reserve(nCount - f_4, 1);
        f_4 = nCount;
    }
};

struct D2StormArray2Strc
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
    unsigned int sub_00450810_CalcChunkSize(unsigned int nCount);                                           // 0x00450810
    void sub_00450D90_ReallocData(unsigned int nAlloc);                                                     // 0x00450D90
    void sub_00450E70_Reserve(unsigned int nCount, int bRound);
    void sub_00450F50_ReserveExact(unsigned int nCount);
};

struct D2StormQueueStrc
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;
    void sub_00421FE0_GrowToFit(int nIndex);                                                                // 0x00421FE0
    unsigned int* sub_00422050_At(unsigned int nIndex);
    void sub_00422120_SetStart(unsigned int nStart);
    D2StormQueueStrc& operator=(const D2StormQueueStrc& tSource);
    void sub_00422080_TrimToStart();
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
    void sub_00422140_Trim();                                                                               // 0x00422140
};

struct D2StormRecordStackStrc
{
    D2StormQueueStrc pRecords[16];
    unsigned int nUsed;
};

struct D2StormArrayBStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);                         // 0x004218B0
    void sub_004219F0_Set(unsigned int nCount, const unsigned char* pData);                                 // 0x004219F0

    void Reserve(unsigned int nCount)
    {
        nCount += f_4;
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C ? f_C : sub_00421160_CalcChunkSize(nCount);
            unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nCount += nChunk - nRemainder;
            sub_004211C0_ReallocData(nCount);
        }
    }
    unsigned char* New()
    {
        Reserve(1);
        unsigned char* pSlot = f_8 + f_4;
        f_4 += 1;
        return pSlot;
    }
    void Push(const unsigned char& nByte)
    {
        Reserve(1);
        f_8[f_4] = nByte;
        f_4 += 1;
    }
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
};

struct D2StormBigStrc
{
    D2StormQueueStrc tQueue;
    D2StormRecordStackStrc tStack;
    D2StormArrayBStrc tBuffer;
    ~D2StormBigStrc();                                                                                      // 0x00421D80
    static void operator delete(void* pMemory);
};

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn); // 0x00421CB0
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormBreakCmdStrc
{
    D2StormLinkStrc f_0;
    int nData;

    static void operator delete(void* pMemory);
};

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink;
    D2GameStrc* pNext;
};

struct D2GameStrc
{
    unsigned int dwHashValue;
    D2GameLinkStrc tLinkToSlot;
    D2GameLinkStrc tLinkToFull;
    char unk0x14[0x1DE0];

    ~D2GameStrc();                                                                                          // 0x0044F820
    static void operator delete(void* pMemory);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc();
    void UnlinkAll();                                                                                       // 0x0044F8E0
    static void operator delete(void* pMemory);
};

struct D2StormGameArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2GameStrc* f_8;
    unsigned int f_C;

    ~D2StormGameArrayStrc();                                                                                // 0x0044FD80
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameArrayStrc m_array;
    D2StormLinkStrc f_10;

    static void operator delete(void* pMemory);
};

struct D2StormListArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormListAStrc* f_8;
    unsigned int f_C;

    ~D2StormListArrayStrc();                                                                                // 0x0044FF60
    static void operator delete(void* pMemory);
};

struct D2StormBigBufferStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
    unsigned int m_offset;

    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
    void sub_00421FE0_GrowToFit(int nIndex);                                                                // 0x00421FE0
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void InlineSetCount(unsigned int nCount)
    {
        if (nCount > f_4 && nCount > f_0)
        {
            unsigned int nChunk = f_C;
            if (!nChunk)
                nChunk = sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            sub_004216E0_ReallocData(nAlloc);
        }
        f_4 = nCount;
    }
    void InlineGrowToFit(int nIndex)
    {
        unsigned int nPosition = m_offset + nIndex;
        if (nPosition >= f_4)
        {
            unsigned int nNewCount = nPosition + 1;
            if (nNewCount > f_0)
            {
                unsigned int nChunk = f_C ? f_C : sub_004210A0_CalcChunkSize(nNewCount);
                sub_004216E0_ReallocData(RoundUp(nNewCount, nChunk));
            }
            SMemZero(&f_8[f_4], (nPosition - f_4 + 1) * sizeof(unsigned int));
            f_4 = nNewCount;
        }
    }
    unsigned int& Get(unsigned int nIndex)
    {
        sub_00421FE0_GrowToFit(nIndex);
        return f_8[m_offset + nIndex];
    }
    unsigned int& At(unsigned int nIndex)
    {
        InlineGrowToFit(nIndex);
        return f_8[m_offset + nIndex];
    }
};

extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);
void __fastcall sub_00425850_Sha1Transform(unsigned int* pState, const unsigned char* pBlock); // 0x00425850

struct T0041D340
{
    unsigned __int64 nBitCount;
    unsigned int aState[5];
    unsigned char f_1C[64];
    unsigned char unk_5C[0x4];
    void Append(const unsigned char* pData, unsigned int nLen);
    void sub_00425F00_Final(unsigned char* pDigest);
};

extern "C" const unsigned char gaSha1Padding_00708890[]; // 0x00708890

struct D2StormTSListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormTSListStrc();
    void sub_00426CF0_UnlinkAll();                                                                          // 0x00426CF0
};

static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength);
static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, D2StormBigBufferStrc* pBuf);
static __declspec(noinline) void __stdcall sub_004234F0_FromLengthPrefixed(D2StormBigBufferStrc* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData);

// build: symbol ??4D2StormQueueStrc@@QAEAAU0@ABU0@@Z 0x004221B0
// 0x00421EA0
void D2StormArrayAStrc::sub_00421EA0_GrowToFit(unsigned int nIndex, int bZero)
{
    if (nIndex >= f_4)
    {
        unsigned int nCount = nIndex + 1;
        if (nCount > f_0)
        {
            unsigned int nChunk = f_C;
            if (!nChunk)
                nChunk = sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            sub_004216E0_ReallocData(nAlloc);
        }
        if (bZero)
            SMemZero(&f_8[f_4], (nIndex - f_4 + 1) * sizeof(unsigned int));
        f_4 = nCount;
    }
}

// 0x00421F10
void D2StormArrayAStrc::sub_00421F10_SetCount(unsigned int nCount)
{
    if (nCount > f_4 && nCount > f_0)
    {
        unsigned int nChunk = f_C;
        if (!nChunk)
            nChunk = sub_004210A0_CalcChunkSize(nCount);
        unsigned int nAlloc = nCount;
        const unsigned int nRemainder = nCount % nChunk;
        if (nRemainder)
            nAlloc = nCount + nChunk - nRemainder;
        sub_004216E0_ReallocData(nAlloc);
    }
    f_4 = nCount;
}

// 0x00422050
unsigned int* D2StormQueueStrc::sub_00422050_At(unsigned int nIndex)
{
    sub_00421FE0_GrowToFit(nIndex);
    return &m_array.f_8[m_start + nIndex];
}

// 0x00422120
void D2StormQueueStrc::sub_00422120_SetStart(unsigned int nStart)
{
    m_start = nStart;
    if (nStart)
        sub_00421FE0_GrowToFit(-1);
}

// 0x004221B0
D2StormQueueStrc& D2StormQueueStrc::operator=(const D2StormQueueStrc& tSource)
{
    if (this != &tSource)
        m_array.sub_004215C0_Set(tSource.m_array.f_4, tSource.m_array.f_8);
    m_array.f_C = tSource.m_array.f_C;
    m_start = tSource.m_start;
    return *this;
}

// 0x00450E70
void D2StormArray2Strc::sub_00450E70_Reserve(unsigned int nCount, int bRound)
{
    nCount += f_4;
    if (nCount > f_0)
    {
        if (bRound)
        {
            unsigned int nChunk = f_C ? f_C : sub_00450810_CalcChunkSize(nCount);
            nCount = RoundUp(nCount, nChunk);
        }
        sub_00450D90_ReallocData(nCount);
    }
}

// 0x00450F50
void D2StormArray2Strc::sub_00450F50_ReserveExact(unsigned int nCount)
{
    const unsigned int nNewCount = f_4 + nCount;
    if (nNewCount > f_0)
        sub_00450D90_ReallocData(nNewCount);
}

// 0x00422080
void D2StormQueueStrc::sub_00422080_TrimToStart()
{
    m_array.SetCount(m_start);
}

// 0x00422710
static __declspec(noinline) int IsOdd(D2StormQueueStrc* pQueue)
{
    pQueue->sub_00422140_Trim();
    if (pQueue->Count() >= 1 && ((*pQueue)[0] & 1))
    {
        return 1;
    }
    return 0;
}

// 0x004238F0
int __stdcall SBigIsOdd(D2StormBigStrc* pBig)
{
    return IsOdd(&pBig->tQueue);
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

unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
}

static void sub_00421BD0_AppendLength(D2StormArrayBStrc* pArray, unsigned int nValue)
{
    while (nValue)
    {
        unsigned char* pSlot = pArray->New();
        *pSlot = (unsigned char)(nValue % 255);
        nValue /= 255;
    }
    pArray->Push(0xFF);
}

static __declspec(noinline) void sub_004235F0_ToBinary(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn)
{
    pOut->f_4 = 0;
    sub_00421CB0_AppendDigits(pOut, pIn);
}

// 0x00423770
static void sub_00423770_ToStream(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn)
{
    sub_004235F0_ToBinary(pOut, pIn);
    sub_00421BD0_AppendLength(pOut, pOut->f_4);
    sub_00421CB0_AppendDigits(pOut, pIn);
}

void __stdcall SBigToBinaryArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    sub_004235F0_ToBinary(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
}

void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead)
{
    D2StormBigStrc* pBig = (D2StormBigStrc*)hBig;
    sub_004235F0_ToBinary(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.f_4 < nSize ? pBig->tBuffer.f_4 : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.f_8, nCopy);
    if (pRead)
        *pRead = nCopy;
}

void __stdcall SBigToBinaryPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    sub_004235F0_ToBinary(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.f_8;
    if (pSize)
        *pSize = pBig->tBuffer.f_4;
}

void __stdcall SBigToStreamArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    sub_00423770_ToStream(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.f_4, pBig->tBuffer.f_8);
}

void __stdcall SBigToStreamBuffer(D2StormBigStrc* pBig, void* pBuffer, unsigned int nSize, unsigned int* pWritten)
{
    sub_00423770_ToStream(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.f_4 < nSize ? pBig->tBuffer.f_4 : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.f_8, nCopy);
    if (pWritten)
        *pWritten = nCopy;
}

void __stdcall SBigToStreamPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    sub_00423770_ToStream(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.f_8;
    *pSize = pBig->tBuffer.f_4;
}

// build: symbol ??_GD2GameStrc@@QAEPAXI@Z 0x0044FBB0
// build: symbol ??_GD2StormBigStrc@@QAEPAXI@Z 0x00423820
// build: symbol ??_GD2StormBreakCmdStrc@@QAEPAXI@Z 0x00426E20
// build: symbol ??_GD2StormHashObjectChunkStrc@@QAEPAXI@Z 0x004500A0
// build: symbol ??_GD2StormListArrayStrc@@QAEPAXI@Z 0x004504D0
// 0x00423820
inline void D2StormBigStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x00426E20
inline void D2StormBreakCmdStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0044FBB0
inline void D2GameStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// build: symbol ??_GD2StormListAStrc@@QAEPAXI@Z 0x0044FCF0
inline D2StormListAStrc::~D2StormListAStrc()
{
    UnlinkAll();
}

inline void D2StormListAStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004500A0
inline void D2StormHashObjectChunkStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x004504D0
inline void D2StormListArrayStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void sub_Emit_D2StormBigStrc(D2StormBigStrc* p)
{
    delete p;
}

// build: context sub_Emit_D2StormBreakCmdStrc
void sub_Emit_D2StormBreakCmdStrc(D2StormBreakCmdStrc* p)
{
    delete p;
}

void sub_Emit_D2GameStrc(D2GameStrc* p)
{
    delete p;
}

// build: context sub_Emit_D2StormListAStrc
void sub_Emit_D2StormListAStrc(D2StormListAStrc* p)
{
    delete p;
}

// build: context sub_Emit_D2StormHashObjectChunkStrc
void sub_Emit_D2StormHashObjectChunkStrc(D2StormHashObjectChunkStrc* p)
{
    delete p;
}

void sub_Emit_D2StormListArrayStrc(D2StormListArrayStrc* p)
{
    delete p;
}

static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength)
{
    *pnLength = 0;
    *pnOffset = 0;
    while (*pnOffset < nSize)
    {
        unsigned int nByte = pData[(*pnOffset)++];
        if (nByte == 0xFF)
            break;
        *pnLength = *pnLength * 0xFF + nByte;
    }
    *pnLength = *pnLength < nSize - *pnOffset ? *pnLength : nSize - *pnOffset;
}

static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, D2StormBigBufferStrc* pBuf)
{
    pBuf->InlineSetCount(pBuf->m_offset);
    for (unsigned int i = 0; i < nCount; i++)
    {
        unsigned int nByte = pData[i];
        unsigned int nWord = i >> 2;
        unsigned int nShift = i & 3;
        pBuf->At(nWord) = (nByte << (nShift * 8)) + (nShift ? pBuf->Get(nWord) : 0);
    }
}

static __declspec(noinline) void __stdcall sub_004234F0_FromLengthPrefixed(D2StormBigBufferStrc* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData)
{
    unsigned int nOffset;
    unsigned int nLength;
    DECODE_LENGTH(pData, nSize, &nOffset, &nLength);
    FROM_BINARY(pData + nOffset, nLength, pBuf);
    if (pnUsed)
        *pnUsed = nOffset + nLength;
}

void __stdcall sub_00423850(void* hBig, const void* pData, unsigned int nSize)
{
    FROM_BINARY((const unsigned char*)pData, nSize, (D2StormBigBufferStrc*)hBig);
}

// 0x00423890
void __stdcall SBigFromStream(void* hBig, const void* pData, unsigned int nSize, unsigned int* pnUsed)
{
    FROM_LENGTH_PREFIXED((D2StormBigBufferStrc*)hBig, pnUsed, nSize, (const unsigned char*)pData);
}

// 0x00425720
unsigned int __fastcall sub_00425720_Rotl(unsigned int nValue, int nShift)
{
    return _rotl(nValue, nShift);
}

// 0x00425830
void __fastcall sub_00425830_LoadBE32(unsigned int* pOut, const unsigned char* pIn)
{
    *pOut = ((((pIn[0] << 8) | pIn[1]) << 8 | pIn[2]) << 8) | pIn[3];
}

// 0x00425730
void __fastcall sub_00425730_Sha1Round0(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + ((*b & c) | (~*b & d)) + *w + 0x5A827999;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x00425770
void __fastcall sub_00425770_Sha1Round1(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + (*b ^ c ^ d) + *w + 0x6ED9EBA1;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x004257B0
void __fastcall sub_004257B0_Sha1Round2(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + (((c | d) & *b) | (c & d)) + *w + 0x8F1BBCDC;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x004257F0
void __fastcall sub_004257F0_Sha1Round3(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += _rotl(a, 5) + (*b ^ c ^ d) + *w + 0xCA62C1D6;
    *b = _rotl(*b, 30);
    *w = 0;
}

// 0x00425DD0
void T0041D340::Append(const unsigned char* pData, unsigned int nLen)
{
    unsigned int nUsed = (unsigned int)nBitCount >> 3 & 0x3F;
    nBitCount += (unsigned __int64)nLen * 8;
    if (nUsed)
    {
        nLen += nUsed;
        pData -= nUsed;
        if (nLen >= 64)
        {
            for (; nUsed < 64; nUsed++)
                f_1C[nUsed] = pData[nUsed];
            sub_00425850_Sha1Transform(aState, f_1C);
            nLen -= 64;
            pData += 64;
            nUsed = 0;
        }
    }
    while (nLen >= 64)
    {
        sub_00425850_Sha1Transform(aState, pData);
        nLen -= 64;
        pData += 64;
    }
    for (; nUsed < nLen; nUsed++)
        f_1C[nUsed] = pData[nUsed];
}

// 0x00425E80
void __fastcall sub_00425E80_PutBE64(unsigned char* pOut, unsigned __int64 nValue)
{
    pOut[7] = (unsigned char)nValue; nValue >>= 8;
    pOut[6] = (unsigned char)nValue; nValue >>= 8;
    pOut[5] = (unsigned char)nValue; nValue >>= 8;
    pOut[4] = (unsigned char)nValue; nValue >>= 8;
    pOut[3] = (unsigned char)nValue; nValue >>= 8;
    pOut[2] = (unsigned char)nValue; nValue >>= 8;
    pOut[1] = (unsigned char)nValue; nValue >>= 8;
    pOut[0] = (unsigned char)nValue;
}

// 0x00425EE0
void __fastcall sub_00425EE0_PutBE32(unsigned int nValue, unsigned char* pOut)
{
    pOut[3] = (unsigned char)nValue; nValue >>= 8;
    pOut[2] = (unsigned char)nValue; nValue >>= 8;
    pOut[1] = (unsigned char)nValue; nValue >>= 8;
    pOut[0] = (unsigned char)nValue;
}

static inline void sub_PutBE64(unsigned char* p, unsigned __int64 v)
{
    p[7] = (unsigned char)v; v >>= 8;
    p[6] = (unsigned char)v; v >>= 8;
    p[5] = (unsigned char)v; v >>= 8;
    p[4] = (unsigned char)v; v >>= 8;
    p[3] = (unsigned char)v; v >>= 8;
    p[2] = (unsigned char)v; v >>= 8;
    p[1] = (unsigned char)v; v >>= 8;
    p[0] = (unsigned char)v;
}

// 0x00425F00
void T0041D340::sub_00425F00_Final(unsigned char* pDigest)
{
    unsigned char aCount[8];
    sub_PutBE64(aCount, nBitCount);
    Append(gaSha1Padding_00708890, ((0xFFFFFFF7 - ((unsigned int)nBitCount >> 3)) & 0x3F) + 1);
    Append(aCount, 8);
    for (int i = 0; i < 5; i++)
    {
        unsigned int v = aState[i];
        for (int j = 3; j >= 0; j--)
        {
            pDigest[i * 4 + j] = (unsigned char)v;
            v >>= 8;
        }
    }
}

#include "gen/data/Source/Storm/Unknown_00421EA0.inc"

// 0x00426160
unsigned int __fastcall sub_00426160_GetTableSize(unsigned int nCount)
{
    unsigned int nSize = 1;
    const unsigned int nLimit = 2 * nCount + 2;
    while (nSize <= nLimit)
        nSize += nSize;
    return nSize;
}

// 0x00426D30
D2StormTSListStrc::~D2StormTSListStrc()
{
    sub_00426CF0_UnlinkAll();
}
