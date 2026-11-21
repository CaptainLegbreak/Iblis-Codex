#include "D2NetTypes.h"

extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E
extern "C" int __stdcall getsockname(unsigned int nSocket, void* pAddress, int* pnLength);                 // 0x006B0144
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0

extern int gClientSocket;                                                                                   // 0x00730AE0

// 0x0052AFE0
void __stdcall CLIENT_GetLocalIpAddressString(char* szBuffer)
{
    D2SockAddrInStrc tAddress = {};
    int nLength = sizeof(tAddress);
    getsockname(gClientSocket, &tAddress, &nLength);
    const char* szLocalIpAddress = inet_ntoa(*(D2InAddrStrc*)&tAddress.sin_addr.s_addr);
    SStrCopy(szBuffer, szLocalIpAddress, 0x7FFFFFFF);
}
