#include "D2BNClient.h"

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand);

int __fastcall FOG_SOCKET_Send(FSafeSock* pSafeSock, const char* pBuffer, int nBufferLength); // 0x0040DCC0
extern long volatile gpSocket_00881BF0; // 0x00881BF0
extern const char gszLineEnd_006FFCB0[]; // 0x006FFCB0

// 0x0051C570
int __fastcall sub_0051C570_SendLine(const char* szLine)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gpSocket_00881BF0, 0, 0);
    FOG_SOCKET_Send(pSocket, szLine, strlen(szLine));
    FOG_SOCKET_Send(pSocket, gszLineEnd_006FFCB0, 1);
    return 1;
}
