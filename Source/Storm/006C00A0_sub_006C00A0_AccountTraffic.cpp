struct D2CriticalSectionStrc { void* debug; long lockCount, recursionCount; void* owner; void* semaphore; unsigned long spinCount; };

struct D2ClientTableStrc
{
    char unk_000[0xBD0];
    int __thiscall sub_006BF660_CheckAddress(unsigned int nAddress); // 0x006BF660
};

struct D2ServerClientStrc
{
    char unk0x00[0x18];
    unsigned int f_18;
    char unk0x1C[0x08];
    unsigned long f_24;
    unsigned int nPending;
    D2CriticalSectionStrc lock;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

static __declspec(noinline) int __stdcall sub_006C00A0_AccountTraffic(D2ClientTableStrc* pTable, unsigned int nBytes, D2ServerClientStrc* pClient);

// 0x006C00A0
static int __stdcall sub_006C00A0_AccountTraffic(D2ClientTableStrc* pTable, unsigned int nBytes, D2ServerClientStrc* pClient)
{
    const unsigned long dwTick = GetTickCount();
    D2CriticalSectionStrc* pLock = &pClient->lock;
    EnterCriticalSection(pLock);
    pClient->nPending += nBytes;
    LeaveCriticalSection(pLock);
    if (pClient->nPending > 1000)
    {
        return pTable->sub_006BF660_CheckAddress(pClient->f_18) != 0;
    }

    if (dwTick - pClient->f_24 > 1000)
    {
        EnterCriticalSection(pLock);
        pClient->f_24 = dwTick;
        if (pClient->nPending >= 200)
        {
            pClient->nPending -= 200;
        }
        else
        {
            pClient->nPending = 0;
        }

        LeaveCriticalSection(pLock);
    }

    return 1;
}

unsigned int __stdcall sub_E4F1_Emit_006C00A0(D2ClientTableStrc* pTable, D2ServerClientStrc* pClient, unsigned int nBytes)
{
    if (sub_006C00A0_AccountTraffic(pTable, nBytes, pClient))
    {
        return 0;
    }

    return pClient->f_18;
}
