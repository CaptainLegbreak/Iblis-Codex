struct D2CriticalSectionStrc { void* debug; long lockCount, recursionCount; void* owner; void* semaphore; unsigned long spinCount; };

struct D2SrvClientStrc
{
    int unk0x00;
    D2SrvClientStrc* pNext;
    int unk0x08;
    int bClosed;
};

struct D2QueueServerStrc
{
    int bAltSend;
    int unk0x04;
    unsigned int nBuckets;
    int unk0x0C[2];
    D2SrvClientStrc** ppBuckets;
    int unk0x18;
    D2CriticalSectionStrc* pLocks;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);

int __fastcall sub_006C2C70(D2QueueServerStrc* pServer, D2SrvClientStrc* pClient, char* pData, int nSize); // 0x006C2C70
int __fastcall sub_006C3410_Send(D2QueueServerStrc* pServer, D2SrvClientStrc* pClient, char* pData, int nSize); // 0x006C3410

// 0x006BFAD0
int __stdcall sub_006BFAD0_BroadcastToAllClients(D2QueueServerStrc* pServer, char* pData, int nSize)
{
    for (unsigned int i = 0; i < pServer->nBuckets; ++i)
    {
        EnterCriticalSection(&pServer->pLocks[i]);
        D2SrvClientStrc* pClient = pServer->ppBuckets[i];
        do
        {
            if (!pClient)
            {
                break;
            }

            if (!pClient->bClosed)
            {
                if (pServer->bAltSend)
                {
                    sub_006C2C70(pServer, pClient, pData, nSize);
                }
                else
                {
                    sub_006C3410_Send(pServer, pClient, pData, nSize);
                }
            }

            pClient = pClient->pNext;
        }
        while (pClient);
        LeaveCriticalSection(&pServer->pLocks[i]);
    }

    return 1;
}
