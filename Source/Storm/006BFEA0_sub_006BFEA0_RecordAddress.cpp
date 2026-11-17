struct D2CriticalSectionStrc { void* debug; long lockCount, recursionCount; void* owner; void* semaphore; unsigned long spinCount; };
struct D2AddressRecordStrc
{
    unsigned int f_0;
    int f_4;
    int nRefresh;
    D2AddressRecordStrc* pNext;
};
typedef void (__fastcall* D2AddressCallback)(unsigned int, const char*, int);
struct D2ClientTableStrc
{
    char unk_000[0x88C];
    D2AddressRecordStrc* pFree;
    int nCount;
    D2CriticalSectionStrc lock;
    D2AddressRecordStrc** ppBuckets;
    unsigned int f_8B0;
    char unk_8B4[0x304];
    D2AddressCallback pfnCallback;
    char unk_BBC[0x14];
    int enabled;
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress); // 0x006BF660
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void __stdcall sub_006BE6C0_LogHackListSize(int nSize); // 0x006BE6C0
extern const char gszServerFile_006FC460[]; // 0x006FC460
// 0x006BFEA0
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc* pTable, const char* szFile, unsigned int nAddress, int nLine)
{
    if (!pTable->enabled)
        return;
    if (pTable->sub_006BF660_CheckAddress(nAddress))
        return;
    if (pTable->pfnCallback)
        pTable->pfnCallback(nAddress, szFile, nLine);
    D2CriticalSectionStrc* pLock = &pTable->lock;
    EnterCriticalSection(pLock);
    unsigned int nBucket = nAddress % pTable->f_8B0;
    D2AddressRecordStrc* pRecord = pTable->ppBuckets[nBucket];
    while (pRecord && pRecord->f_0 != nAddress)
        pRecord = pRecord->pNext;
    if (pRecord)
    {
        pRecord->nRefresh = 120;
        LeaveCriticalSection(pLock);
        return;
    }
    pRecord = pTable->pFree;
    if (pRecord)
        pTable->pFree = pRecord->pNext;
    else
        pRecord = (D2AddressRecordStrc*)FOG_Alloc(sizeof(D2AddressRecordStrc), gszServerFile_006FC460, 0x4AA, 0);
    pRecord->f_0 = nAddress;
    pRecord->f_4 = 120;
    pRecord->nRefresh = 0;
    pRecord->pNext = pTable->ppBuckets[nBucket];
    pTable->ppBuckets[nBucket] = pRecord;
    ++pTable->nCount;
    LeaveCriticalSection(pLock);
    sub_006BE6C0_LogHackListSize(pTable->nCount);
}
