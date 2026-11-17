struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2ClientNodeStrc
{
    int nClient;
    D2ClientNodeStrc* pNext;
    char f_8[0x10];
    unsigned int f_18;
};
struct D2ClientTableStrc
{
    char unk_00[0xC];
    unsigned int nMask;
    int unk_10;
    D2ClientNodeStrc** ppBuckets;
    int unk_18;
    D2CriticalSectionStrc* pLocks;
    char unk_20[0xBD0 - 0x20];
    int bEnabled;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
void __fastcall sub_006C0420_CloseClient(D2ClientTableStrc*, int, const char*, int); // 0x006C0420
const char* __stdcall sub_006B013E_FormatAddress(unsigned int); // 0x006B013E
void __cdecl sub_00410660_LogWritePrefixed(const char*, const char*, ...); // 0x00410660
void __fastcall sub_006BFEA0_RecordAddress(D2ClientTableStrc*, const char*, unsigned int, int); // 0x006BFEA0
extern const char gszLogTag_006FC4A8[]; // 0x006FC4A8

// 0x006C0530
void __stdcall sub_006C0530_RecordClient(D2ClientTableStrc* pTable, int nClient, const char* szFile, int nLine)
{
    if (!pTable->bEnabled) return;
    unsigned int nBucket = pTable->nMask & nClient;
    EnterCriticalSection(&pTable->pLocks[nBucket]);
    D2ClientNodeStrc* pNode = pTable->ppBuckets[nBucket];
    while (pNode && pNode->nClient != nClient)
        pNode = pNode->pNext;
    LeaveCriticalSection(&pTable->pLocks[nBucket]);
    if (!pNode)
    {
        sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  Couldn't hacklist client %d (closed) from FILE:%s  LINE:%d", nClient, szFile, nLine);
        return;
    }
    unsigned int nAddress = pNode->f_18;
    sub_00410660_LogWritePrefixed(gszLogTag_006FC4A8, "[HACKLIST]  IP:%s  QSHackList() from FILE:%s  LINE:%d", sub_006B013E_FormatAddress(nAddress), szFile, nLine);
    sub_006C0420_CloseClient(pTable, nClient, szFile, nLine);
    sub_006BFEA0_RecordAddress(pTable, szFile, nAddress, nLine);
}
