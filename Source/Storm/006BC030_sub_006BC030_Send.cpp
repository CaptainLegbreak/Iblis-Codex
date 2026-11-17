struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
int __stdcall sub_006B017A_Send(int nSocket, const void* pBuffer, int nLength, int nFlags); // 0x006B017A
int __stdcall sub_006B0168_GetLastError(); // 0x006B0168
struct D2Socket006BC030Strc
{
    unsigned char unk_00[8];
    int nSocket;
    D2CriticalSectionStrc tLock;
    unsigned char unk_24[8];
    int bClosed;
    int nState;
    int nLastError;
};

// 0x006BC030
int __fastcall sub_006BC030_Send(D2Socket006BC030Strc* pSocket, const void* pBuffer, int nLength)
{
    if (!pSocket || pSocket->bClosed)
    {
        return -1;
    }
    EnterCriticalSection(&pSocket->tLock);
    int nResult;
    const int nSent = sub_006B017A_Send(pSocket->nSocket, pBuffer, nLength, 0);
    if (nSent == -1)
    {
        const int nError = sub_006B0168_GetLastError();
        pSocket->nLastError = nError;
        if (nError == 0x2733)
        {
            nResult = 0;
        }
        else
        {
            pSocket->nState = 4;
            return -1;
        }
    }
    else
    {
        nResult = nSent;
    }
    LeaveCriticalSection(&pSocket->tLock);
    return nResult;
}
