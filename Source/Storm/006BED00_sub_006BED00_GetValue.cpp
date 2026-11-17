typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BED00_Entry
{
    char unk_000[0x8C];
    int nValue;
};

sub_006BED00_Entry* __fastcall sub_006BEC00_FindLocked(int nKey1, int nKey2, CRITICAL_SECTION** ppLock); // 0x006BEC00

// 0x006BED00
int __stdcall sub_006BED00_GetValue(int nKey1, int nKey2)
{
    CRITICAL_SECTION* pLock = 0;
    sub_006BED00_Entry* pEntry = sub_006BEC00_FindLocked(nKey1, nKey2, &pLock);
    int nValue = 0;
    if (pEntry)
        nValue = pEntry->nValue;
    if (pLock)
        LeaveCriticalSection(pLock);
    return nValue;
}
