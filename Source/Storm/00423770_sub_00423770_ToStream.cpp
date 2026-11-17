void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2A0

struct D2StormArrayAStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;
};

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

struct D2StormBigStrc
{
    D2StormQueueStrc tQueue;
    D2StormRecordStackStrc tStack;
    D2StormArrayBStrc tBuffer;
};

void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn);                // 0x00421CB0

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
static __declspec(noinline) void sub_00423770_ToStream(D2StormArrayBStrc* pOut, D2StormQueueStrc* pIn)
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

void __stdcall sub_00423B30(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead)
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
