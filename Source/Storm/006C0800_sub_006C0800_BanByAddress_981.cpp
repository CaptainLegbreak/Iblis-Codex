struct D2CriticalSectionStrc { void* debug; long lockCount, recursionCount; void* owner; void* semaphore; unsigned long spinCount; };
struct D2ClientNodeStrc
{
    int nClient;
    int f_4[5];
    unsigned int f_18;
    D2ClientNodeStrc* pNext;
};
struct D2ServerStrc
{
    int unk_00[3];
    unsigned int nMask;
    int unk_10[4];
    D2ClientNodeStrc** ppBuckets;
    int unk_24;
    D2CriticalSectionStrc lock;
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress); // 0x006BF660
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
const char* __stdcall sub_006B013E_FormatAddress(unsigned int nAddress); // 0x006B013E
void __cdecl sub_00410660_Log(const char* szCategory, const char* szFormat, ...); // 0x00410660
void __stdcall sub_006C0770_BanClient(int nClient, const char* szFile, int nLine); // 0x006C0770
extern const char gszServerFile_006FC460[]; // 0x006FC460
extern const char gszHack_006FC4A8[]; // 0x006FC4A8

// 0x006C0800
int __fastcall sub_006C0800_BanByAddress(D2ServerStrc* pServer, unsigned int* pAddress, const char* szFile, int nLine)
{
    unsigned int nAddress = *pAddress;
    unsigned int nBucket = pServer->nMask & nAddress;
    EnterCriticalSection(&pServer->lock);
    D2ClientNodeStrc* pNode = pServer->ppBuckets[nBucket];
    while (pNode && pNode->f_18 != nAddress)
        pNode = pNode->pNext;
    LeaveCriticalSection(&pServer->lock);
    if (pNode && !pServer->sub_006BF660_CheckAddress(pNode->f_18))
    {
        sub_00410660_Log(gszHack_006FC4A8, "[HACKLIST]  Client %d at %s banned via QSBanByAddr()", pNode->nClient, sub_006B013E_FormatAddress(*pAddress));
        sub_006C0770_BanClient(pNode->nClient, gszServerFile_006FC460, 0x584);
    }
    return 1;
}
