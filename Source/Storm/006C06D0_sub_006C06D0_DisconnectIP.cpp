struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};
struct D2ConnectionNodeStrc
{
    int nClient;
    char unk_04[0x14];
    unsigned int nIP;
    D2ConnectionNodeStrc* pNext;
};
struct D2ConnectionTableStrc
{
    char unk_00[0xC];
    unsigned int nMask;
    char unk_10[0x10];
    D2ConnectionNodeStrc** ppBuckets;
    int unk_24;
    D2CriticalSectionStrc tLock;
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);
void __fastcall sub_006C0420_DisconnectClient(D2ConnectionTableStrc* pTable, int nClient, const char* pFile, int nLine); // 0x006C0420
const char* __stdcall sub_006B013E_FormatIP(unsigned int nIP); // 0x006B013E
void __cdecl sub_00410660_Log(const char* pCategory, const char* pFormat, ...); // 0x00410660
extern const char gszCategory_006FC4A8[]; // 0x006FC4A8

// 0x006C06D0
void __stdcall sub_006C06D0_DisconnectIP(D2ConnectionTableStrc* pTable, unsigned int nIP, const char* pFile, int nLine)
{
    unsigned int nBucket = pTable->nMask & nIP;
    EnterCriticalSection(&pTable->tLock);
    D2ConnectionNodeStrc* pNode = pTable->ppBuckets[nBucket];
    while (pNode)
    {
        if (pNode->nIP == nIP)
            break;
        pNode = pNode->pNext;
    }
    LeaveCriticalSection(&pTable->tLock);
    if (pNode)
        sub_006C0420_DisconnectClient(pTable, pNode->nClient, pFile, nLine);
    else
        sub_00410660_Log(gszCategory_006FC4A8, "[HACKLIST]  Client %s is already closed", sub_006B013E_FormatIP(nIP));
    sub_00410660_Log(gszCategory_006FC4A8, "[HACKLIST]  IP:%s  QSDisconnectIP() from FILE:%s  LINE:%d", sub_006B013E_FormatIP(nIP), pFile, nLine);
}
