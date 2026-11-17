#include "Fog.h"
struct D2CriticalSectionStrc { unsigned int fields[6]; };
struct T006BFAD0
{
    int f_0;
    unsigned char pad04[0xC];
    unsigned int socket;
    unsigned char pad14[0x18];
    D2CriticalSectionStrc f_2C;
    unsigned char pad44[0x18];
    unsigned char overlapped5C[0x14];
    unsigned int f_70;
    T006C23B0* f_74;
    unsigned char pad78[0x28];
    unsigned int f_A0;
};
void* __fastcall FOG_Alloc(unsigned int size, const char* file, int line, int unused); // 0x0040B380
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int count);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) int __stdcall send(unsigned int socket, const char* bytes, int size, int flags);
extern "C" __declspec(dllimport) int __stdcall WSAGetLastError();
unsigned int __cdecl sub_00410A80_GetTimeSeconds(); // 0x00410A80

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nBytes, unsigned long* pnWritten, void* pOverlapped);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
long __fastcall sub_006BE640_AddReference(T006BE350* pServer, T006BFAD0* pClient);                         // 0x006BE640

static __declspec(noinline) int sub_006C2760_BeginWrite(T006BE350* pServer, T006BFAD0* pClient);

// 0x006C2760
static int sub_006C2760_BeginWrite(T006BE350* pServer, T006BFAD0* pClient)
{
    if (!pClient->f_74)
    {
        return 1;
    }

    sub_006BE640_AddReference(pServer, pClient);
    T006C23B0* pPacket = pClient->f_74;
    D2_ASSERT(pClient->socket != -1, 0x518);

    unsigned long nWritten;
    const int bWritten = WriteFile((void*)pClient->socket, pPacket + 1, pPacket->nPacketSize, &nWritten, pClient->overlapped5C);
    const unsigned long nError = GetLastError();
    if (!bWritten && nError != 0x3E5)
    {
        sub_006C0360_RemoveClient(pServer, pClient);
        sub_006C0420_CloseRemote(pServer, pClient->f_0, gszQServerNT_006FC8A0, 0x527);
        return 0;
    }

    if (nError == 0x3E5)
    {
        pClient->f_70 |= 4;
    }
    return 1;
}

__declspec(noinline) static T006C23B0* __stdcall sub_006C23B0_AppendPacket(T006BFAD0* client, unsigned int size, const char* bytes);

static T006C23B0* __stdcall sub_006C23B0_AppendPacket(T006BFAD0* client, unsigned int size, const char* bytes)
{
    T006C23B0* packet = (T006C23B0*)FOG_Alloc(size + 8, gszQServerNT_006FC8A0, 0x440, 0);
    memcpy(packet + 1, bytes, size);
    packet->nPacketSize = size;
    packet->f_4 = 0;
    T006C23B0* tail = client->f_74;
    if (!tail)
    {
        client->f_74 = packet;
        return 0;
    }
    while (tail->f_4)
        tail = tail->f_4;
    tail->f_4 = packet;
    return tail;
}

int __fastcall sub_006C2C70_SendLocal(T006BE350 * pQServer, T006BFAD0 * pQServerClient, char * pBytes, int nSize) {
    int nWsaError;
    D2CriticalSectionStrc* lpCriticalSection = &pQServerClient->f_2C;
      EnterCriticalSection(lpCriticalSection);
    unsigned int nHighResTime = sub_00410A80_GetTimeSeconds();
    pQServerClient->f_A0 = nHighResTime;
    if (pQServerClient->f_74) {
      sub_006C23B0_AppendPacket(pQServerClient, nSize, pBytes);
    } else {
      unsigned int nBytesSent;
      if (pQServerClient->socket == -1) {
        nWsaError = pQServerClient->f_0;
          LeaveCriticalSection(lpCriticalSection);
        sub_006C0420_CloseRemote(pQServer, nWsaError, gszQServerNT_006FC8A0, 0x220);
        sub_006C0360_RemoveClient(pQServer, pQServerClient);
        return 0;
      }

              nBytesSent = send(pQServerClient->socket, pBytes, nSize, 0);
      if (nBytesSent == -1) {
        nWsaError = WSAGetLastError();
        if (nWsaError != 0x2733) {
          nWsaError = pQServerClient->f_0;
            LeaveCriticalSection(lpCriticalSection);
          sub_006C0420_CloseRemote(pQServer, nWsaError, gszQServerNT_006FC8A0, 0x234);
          return 0;
        }

        nBytesSent = 0;
      }
      if (nBytesSent < (unsigned int)nSize) {
        sub_006C23B0_AppendPacket(pQServerClient, nSize - nBytesSent, pBytes + nBytesSent);
        sub_006C2760_BeginWrite(pQServer, pQServerClient);
      }
    }

      LeaveCriticalSection(lpCriticalSection);
    return 1;
}
