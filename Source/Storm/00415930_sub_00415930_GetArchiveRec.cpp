struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

struct D2StormArchiveRecStrc
{
    char pad00[0x110];
    int nKind;
    int pad114;
    int nInfo;
    char pad11C[0x13C];
    int nRefs;
};

struct D2StormQuadStrc
{
    int n00;
    int n04;
    int n08;
    int n0C;
};

struct D2StormFileSubStrc
{
    int pad00;
    int nSizeLow;
    char pad08[0x10];
    int nValue;
    D2StormQuadStrc tQuad;
};

struct D2StormFileRecStrc
{
    char pad00[0x110];
    int nKind;
    int nValue;
    D2StormFileSubStrc* f_118;
};

struct D2StormSoundBuffer
{
    virtual long __stdcall QueryInterface() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCaps() = 0;
    virtual long __stdcall GetCurrentPosition() = 0;
    virtual long __stdcall GetFormat() = 0;
    virtual long __stdcall GetVolume(int* pnVolume) = 0;
    virtual long __stdcall GetPan(int* pnPan) = 0;
    virtual long __stdcall GetFrequency() = 0;
    virtual long __stdcall GetStatus() = 0;
    virtual long __stdcall Initialize() = 0;
    virtual long __stdcall Lock() = 0;
    virtual long __stdcall Play() = 0;
    virtual long __stdcall SetCurrentPosition() = 0;
    virtual long __stdcall SetFormat() = 0;
    virtual long __stdcall SetVolume(int nVolume) = 0;
    virtual long __stdcall SetPan(int nPan) = 0;
};

struct D2StormDdaNodeStrc;

struct D2StormDdaLinkStrc
{
    D2StormDdaLinkStrc* m_prevlink;
    D2StormDdaNodeStrc* m_next;

    D2StormDdaNodeStrc* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};

struct D2StormDdaNodeStrc
{
    D2StormDdaLinkStrc f_0;
    D2StormFileRecStrc* pFile;
    char pad0C[0x28];
    int f_34;
    int f_38;
    D2StormSoundBuffer* pBuffer;
};

struct D2StormDdaListStrc
{
    int m_linkoffset;
    D2StormDdaLinkStrc m_terminator;

    D2StormDdaNodeStrc* Head()
    {
        return m_terminator.Next();
    }
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340

D2CriticalSectionStrc gBasePathLock_00779068;                                                               // 0x00779068
extern D2StormDdaListStrc gDdaList_00708384;                                                                // 0x00708384

// 0x00415930
static __declspec(noinline) int sub_00415930_GetArchiveRec(void* hArchive, D2StormArchiveRecStrc** ppRec)
{
    *ppRec = (D2StormArchiveRecStrc*)hArchive;
    return 1;
}

// 0x00415950
static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// 0x00415F10
int __stdcall sub_00415F10_AdjustArchiveRefs(void* hArchive, int bRelease)
{
    D2StormArchiveRecStrc* pRec;
    EnterCriticalSection(&gBasePathLock_00779068);
    if (!sub_00415930_GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    pRec->nRefs += bRelease ? -1 : 1;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00415FA0
int __stdcall sub_00415FA0_GetArchiveInfo(void* hArchive, int* pnInfo, int* pbKind3)
{
    if (pnInfo)
        *pnInfo = 0;
    if (pbKind3)
        *pbKind3 = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormArchiveRecStrc* pRec;
    if (!sub_00415930_GetArchiveRec(hArchive, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pnInfo)
        *pnInfo = pRec->nInfo;
    if (pbKind3)
        *pbKind3 = pRec->nKind == 3;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416160
int __stdcall sub_00416160_GetFileSubValue(void* hFile)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    const int nValue = pRec->f_118->nValue;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nValue;
}

// 0x004161C0
int __stdcall sub_004161C0_GetFileSubQuad(void* hFile, D2StormQuadStrc* pQuad)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pRec->nKind != -1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    *pQuad = pRec->f_118->tQuad;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x00416320
int __stdcall sub_00416320_GetFileSize(void* hFile, int* pnSizeHigh)
{
    int nResult = 0;
    if (pnSizeHigh)
        *pnSizeHigh = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (sub_00415950_GetFileRec(hFile, &pRec) && pRec->nKind == -1)
        nResult = pRec->f_118->nSizeLow;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nResult;
}

// 0x004181F0
int __stdcall sub_004181F0_DdaGetVolume(void* hFile, int* pnVolume, int* pnPan)
{
    if (pnVolume)
        *pnVolume = 0;
    if (pnPan)
        *pnPan = 0;
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    D2StormDdaNodeStrc* pNode;
    for (pNode = gDdaList_00708384.Head(); pNode; pNode = pNode->f_0.Next())
    {
        if (pNode->pFile == pRec)
            break;
    }
    if (!pNode)
    {
        sub_0041C340_SetLastError(0x85100072);
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    if (pNode->f_34 == 0x7FFFFFFF)
        pNode->pBuffer->GetVolume(&pNode->f_34);
    if (pNode->f_38 == 0x7FFFFFFF)
        pNode->pBuffer->GetPan(&pNode->f_38);
    if (pnVolume)
        *pnVolume = pNode->f_34;
    if (pnPan)
        *pnPan = pNode->f_38;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}

// 0x004182D0
int __stdcall sub_004182D0_DdaSetVolume(void* hFile, int nVolume, int nPan)
{
    EnterCriticalSection(&gBasePathLock_00779068);
    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return 0;
    }
    D2StormDdaNodeStrc* pNode;
    for (pNode = gDdaList_00708384.Head(); pNode; pNode = pNode->f_0.Next())
    {
        if (pNode->pFile == pRec)
            break;
    }
    if (!pNode)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        sub_0041C340_SetLastError(0x85100072);
        return 0;
    }
    if (nVolume != 0x7FFFFFFF && nVolume != pNode->f_34)
    {
        pNode->f_34 = nVolume;
        pNode->pBuffer->SetVolume(nVolume);
    }
    if (nPan != 0x7FFFFFFF && nPan != pNode->f_38)
    {
        pNode->f_38 = nPan;
        pNode->pBuffer->SetPan(nPan);
    }
    LeaveCriticalSection(&gBasePathLock_00779068);
    return 1;
}
