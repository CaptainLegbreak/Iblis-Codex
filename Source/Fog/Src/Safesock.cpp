#include "Fog.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"

struct FSafeSock
{
    int bConnected;
    int bConnecting;
    unsigned int nSocket;
    D2CriticalSectionStrc tCriticalSection;
    void* hThread;
    unsigned long nThreadId;
    int bStopping;
    unsigned long nFogErrorCode;
    unsigned long nWSALastError;
    char szName[64];
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId);
extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData);                // 0x006B0132
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E
extern "C" unsigned short __stdcall htons(unsigned short nValue);                                           // 0x006B0156
extern "C" int __stdcall ioctlsocket(unsigned int nSocket, long nCommand, unsigned long* pArgument);       // 0x006B015C
extern "C" int __stdcall setsockopt(unsigned int nSocket, int nLevel, int nOption, const char* pValue, int nLength); // 0x006B0162
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
extern "C" unsigned int __stdcall socket(int nFamily, int nType, int nProtocol);                            // 0x006B016E
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
extern "C" const char gszUnknownUpper_006CCED8[];                                                           // 0x006CCED8
char gszResolvedHostIP_0075D040[256];                                                                       // 0x0075D040

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern "C" int __stdcall closesocket(unsigned int nSocket); // 0x006B012C

// 0x0040D8E0
FSafeSock* __fastcall FOG_SOCKET_ConnectEx(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName, int bNonBlocking)
{
    FSafeSock* pSafeSock = (FSafeSock*)FOG_Alloc(sizeof(FSafeSock), ".\\Src\\Safesock.cpp", 204, 0);
    memset(pSafeSock, 0, sizeof(FSafeSock));
    if (szName)
    {
        SStrCopy(pSafeSock->szName, szName, sizeof(pSafeSock->szName));
    }
    else
    {
        SStrCopy(pSafeSock->szName, gszUnknownUpper_006CCED8, sizeof(pSafeSock->szName));
    }
    InitializeCriticalSection(&pSafeSock->tCriticalSection);

    D2WSADataStrc tWSAData;
    const int nStartupError = WSAStartup(0x101, &tWSAData);
    if (nStartupError)
    {
        pSafeSock->nWSALastError = nStartupError;
        pSafeSock->nFogErrorCode = 1;
        DeleteCriticalSection(&pSafeSock->tCriticalSection);
        FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 223, 0);
        return 0;
    }

    const unsigned int nSocket = socket(2, 1, 0);
    pSafeSock->nSocket = nSocket;
    if (nSocket == -1)
    {
        pSafeSock->nWSALastError = WSAGetLastError();
        pSafeSock->nFogErrorCode = 2;
        DeleteCriticalSection(&pSafeSock->tCriticalSection);
        FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 243, 0);
        return 0;
    }

    int bNoDelay = 1;
    setsockopt(nSocket, 6, 1, (const char*)&bNoDelay, 4);
    int bKeepAlive = 1;
    setsockopt(nSocket, 0xFFFF, 8, (const char*)&bKeepAlive, 4);
    int nSendTimeout = 3000;
    setsockopt(nSocket, 0xFFFF, 0x1005, (const char*)&nSendTimeout, 4);

    if (bNonBlocking & 1)
    {
        unsigned long nArgument = 1;
        ioctlsocket(nSocket, 0x8004667E, &nArgument);
    }

    pSafeSock->bConnecting = 1;
    D2SockAddrInStrc tAddress;
    memset(&tAddress, 0, sizeof(tAddress));
    tAddress.sin_family = 2;
    tAddress.sin_port = htons(nPortNumber);
    tAddress.sin_addr.s_addr = inet_addr(szHostAddress);
    if (connect(nSocket, &tAddress, sizeof(tAddress)) == -1)
    {
        const int nError = WSAGetLastError();
        if (!(bNonBlocking & 1) || (nError != 0x2733 && nError != 0x2734))
        {
            pSafeSock->nWSALastError = nError;
            pSafeSock->nFogErrorCode = 3;
            DeleteCriticalSection(&pSafeSock->tCriticalSection);
            FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 291, 0);
            return 0;
        }
    }

    if (!(bNonBlocking & 1))
    {
        pSafeSock->bConnected = 1;
        pSafeSock->bConnecting = 0;
    }

    if (!gszResolvedHostIP_0075D040[0] || !inet_addr(gszResolvedHostIP_0075D040))
    {
        D2SockAddrInStrc tLocal;
        int nLength = sizeof(tLocal);
        if (getsockname(nSocket, &tLocal, &nLength) != -1)
        {
            strcpy(gszResolvedHostIP_0075D040, inet_ntoa(tLocal.sin_addr));
        }
    }

    if (pThreadProc)
    {
        pSafeSock->hThread = CreateThread(0, 0, pThreadProc, lpParameter, 0, &pSafeSock->nThreadId);
    }
    return pSafeSock;
}

// 0x0040DBD0
void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock)
{
    EnterCriticalSection(&pSafeSock->tCriticalSection);
    pSafeSock->bStopping = 1;
    LeaveCriticalSection(&pSafeSock->tCriticalSection);
    if (pSafeSock->hThread)
    {
        WaitForSingleObject(pSafeSock->hThread, 5000);
    }
    if (pSafeSock->hThread)
    {
        CloseHandle(pSafeSock->hThread);
        pSafeSock->hThread = 0;
    }
    if (pSafeSock->nSocket != (unsigned int)-1)
    {
        const unsigned int nSocket = pSafeSock->nSocket;
        pSafeSock->nSocket = (unsigned int)-1;
        pSafeSock->bConnected = 0;
        if (closesocket(nSocket) == -1)
        {
            pSafeSock->nWSALastError = WSAGetLastError();
            pSafeSock->nFogErrorCode = 5;
        }
    }
    DeleteCriticalSection(&pSafeSock->tCriticalSection);
    FOG_Free(pSafeSock, ".\\Src\\Safesock.cpp", 387, 0);
}
