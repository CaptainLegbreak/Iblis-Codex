#include "D2NetTypes.h"
struct D2Server006C3360Strc;
struct D2CriticalSectionStrc;
struct D2Worker006C33D0Strc;
struct D2Connection006C3410Strc;

struct D2Server006C3360Strc
{
    unsigned char unk_000[0x884];
    int bStarted884;
};

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132
int __fastcall sub_006C3120_Start(D2Server006C3360Strc* pServer, int nValue); // 0x006C3120

#include "D2SysTypes.h"

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct D2Worker006C33D0Strc
{
    unsigned char unk_000[0x854];
    D2CriticalSectionStrc tLock854;
    unsigned char unk_86C[0xBD8 - 0x86C];
    void* hThreadBD8;
    unsigned char unk_BDC[0xBF8 - 0xBDC];
    int bStopBF8;
};

struct D2Connection006C3410Strc
{
    unsigned char unk_00[0x10];
    int nSocket10;
};

int __stdcall sub_006B017A_Send(int nSocket, const void* pBuffer, int nLength, int nFlags); // 0x006B017A
int __stdcall sub_006B0168_GetLastError(); // 0x006B0168

// 0x006C3360
int __fastcall sub_006C3360_Startup(D2Server006C3360Strc* pServer, int nValue)
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
void __fastcall sub_006C33D0_Stop(D2Worker006C33D0Strc* pWorker)
{
    EnterCriticalSection(&pWorker->tLock854);
    pWorker->bStopBF8 = 1;
    LeaveCriticalSection(&pWorker->tLock854);
    WaitForSingleObject(pWorker->hThreadBD8, 2000);
}

// 0x006C3410
int __fastcall sub_006C3410_Send(int nUnused, D2Connection006C3410Strc* pConnection, const void* pBuffer, int nLength)
{
    if (sub_006B017A_Send(pConnection->nSocket10, pBuffer, nLength, 0) == -1)
    {
        sub_006B0168_GetLastError();
        return 0;
    }
    return 1;
}
