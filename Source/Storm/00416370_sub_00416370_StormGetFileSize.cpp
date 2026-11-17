struct D2CriticalSectionStrc { char data[24]; };

struct D2StormArchiveFileStrc
{
    int unk0x00[2];
    int nFileSize;
};

struct D2StormFileRecStrc
{
    char unk0x000[0x110];
    void* hFile;
    int unk0x114;
    D2StormArchiveFileStrc* pArchiveFile;
};

extern D2CriticalSectionStrc gBasePathLock_00779068; // 0x00779068
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pdwFileSizeHigh); // 0x006CC2F0

static __declspec(noinline) int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec);

// 0x00415950
static int sub_00415950_GetFileRec(void* hFile, D2StormFileRecStrc** ppRec)
{
    *ppRec = (D2StormFileRecStrc*)hFile;
    return 1;
}

// 0x00416370
int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pdwFileSizeHigh)
{
    if (pdwFileSizeHigh)
    {
        *pdwFileSizeHigh = 0;
    }

    EnterCriticalSection(&gBasePathLock_00779068);

    D2StormFileRecStrc* pRec;
    if (!sub_00415950_GetFileRec(hFile, &pRec))
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return -1;
    }

    if (pRec->hFile != (void*)-1)
    {
        LeaveCriticalSection(&gBasePathLock_00779068);
        return GetFileSize(pRec->hFile, (unsigned long*)pdwFileSizeHigh);
    }

    const int nFileSize = pRec->pArchiveFile->nFileSize;
    LeaveCriticalSection(&gBasePathLock_00779068);
    return nFileSize;
}
