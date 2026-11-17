struct D2CriticalSectionStrc { unsigned int opaque[6]; };
struct D2NetPacketStrc
{
    unsigned char data[0x5B4];
    int nSize;
    int unk_5B8;
    D2NetPacketStrc* pNext;
};
struct D2NetQueueStrc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc lock;
    unsigned char unk_86C[0x4];
    D2NetPacketStrc** ppHeads;
    D2NetPacketStrc** ppTails;
    D2NetPacketStrc* pFree;
    int nQueues;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

// 0x006BEAD0
int __stdcall sub_006BEAD0_ReceivePacket(D2NetQueueStrc* pQueue, int nIndex, void* pDst, unsigned int nMax)
{
    if (!pQueue)
    {
        return -1;
    }
    if (nIndex >= pQueue->nQueues)
    {
        return -1;
    }
    if (nMax > 0x5B4)
    {
        nMax = 0x5B4;
    }

    EnterCriticalSection(&pQueue->lock);
    D2NetPacketStrc* pPacket = pQueue->ppHeads[nIndex];
    if (!pPacket)
    {
        LeaveCriticalSection(&pQueue->lock);
        return -1;
    }
    pQueue->ppHeads[nIndex] = pPacket->pNext;
    if (pQueue->ppTails[nIndex] == pPacket)
    {
        pQueue->ppTails[nIndex] = 0;
    }
    LeaveCriticalSection(&pQueue->lock);

    const int nCopy = (pPacket->nSize + 4 > (int)nMax) ? nMax : pPacket->nSize + 4;
    memcpy(pDst, pPacket, nCopy);
    int nResult = pPacket->nSize;
    memset(pPacket, 0, sizeof(D2NetPacketStrc));

    EnterCriticalSection(&pQueue->lock);
    pPacket->pNext = pQueue->pFree;
    pQueue->pFree = pPacket;
    LeaveCriticalSection(&pQueue->lock);
    return nResult;
}
