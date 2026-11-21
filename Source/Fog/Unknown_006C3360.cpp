#include "D2QServer.h"

struct QServer
{
    unsigned char unk_000[0x884];
    int bStarted884;
};

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132
int __fastcall sub_006C3120_Start(QServer* pServer, int nValue); // 0x006C3120

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

int __stdcall sub_006B017A_Send(int nSocket, const void* pBuffer, int nLength, int nFlags); // 0x006B017A
int __stdcall sub_006B0168_GetLastError(); // 0x006B0168

// 0x006C3360
int __fastcall sub_006C3360_Startup(QServer* pServer, int nValue)
{
    D2WSADataStrc tWsaData;
    pServer->bStarted884 = 1;
    if (WSAStartup(0x101, &tWsaData))
    {
        return 0;
    }
    return sub_006C3120_Start(pServer, nValue);
}

// 0x006C33D0
void __fastcall sub_006C33D0_Stop(D2QueueServerStrc* pServer)
{
    EnterCriticalSection(&pServer->tLock);
    pServer->bStop = 1;
    LeaveCriticalSection(&pServer->tLock);
    WaitForSingleObject(pServer->hAcceptThreads[0], 2000);
}

// 0x006C3410
int __fastcall sub_006C3410_Send(D2QueueServerStrc* pServer, D2QClientStrc* pClient, char* pData, int nSize)
{
    if (sub_006B017A_Send(pClient->iSocket, pData, nSize, 0) == -1)
    {
        sub_006B0168_GetLastError();
        return 0;
    }
    return 1;
}
