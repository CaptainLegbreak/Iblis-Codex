#include "D2Net.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall CLIENT_ReadPacketFromBuffer(void* pBuffer, int nBufferSize);                                // 0x0052AEB0

void __fastcall FOG_10222(const unsigned char* pData, unsigned int nSize);                                  // 0x0040B130

int __fastcall FOG_CompressPacket(unsigned char* pOut, int nCapacity, const unsigned char* pIn, int nSize);       // 0x0040B1B0

int __stdcall FOG_10157(void* pServer, unsigned int nKey, const void* pData, unsigned int nSize); // 0x006C03A0

extern void* gpServer_00882D08;                                                                             // 0x00882D08

#define GAME_PORT 4000

struct D2PacketBufferStrc;

typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);

typedef int (__fastcall* D2NET_PacketCallback)(int, int, int, int);

typedef int (__fastcall* D2NET_ReadPacketCallback)(QServer*, D2PacketBufferStrc*, int);

int gnLocalClientGameGuid;                                                                         // 0x00882D0C

QServer* __stdcall QSInit(int a1, int a2, int a3, int a4, D2NET_PacketCallback a5, D2NET_PacketCallback a6, D2NET_PacketCallback a7, D2NET_ReadPacketCallback a8); // 0x006BF760

int __stdcall FOG_10165(QServer* pServer, int nClientId, const char* szFile, int nLine);                   // 0x006C06B0

int __stdcall FOG_10170(QServer* pServer, int a2);                                                          // 0x006BF040

int __stdcall FOG_10171(QServer* pServer, D2NET_Unk_Callback pfCallback);                                   // 0x006BF080

int __stdcall FOG_10172(QServer* pServer, int nClientId, int dwGameGuid);                                   // 0x006BF0A0

int __stdcall FOG_10173(void* pContainer, int nKey); // 0x006BF0C0

int __stdcall FOG_10177(QServer* pServer, int dwMilliseconds);                                              // 0x006BEBC0

void __stdcall FOG_10183_Return(QServer* pServer, int nUnused);                                             // 0x006BF600

int __fastcall SERVER_SendToLocalClientCallback(QServer* nUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize); // 0x0052B0E0

int __fastcall SERVER_ValidateClientPacket(int a1, int a2, int a3, int a4);                                 // 0x0052B100

int __fastcall SERVER_OnClientConnectedCallback(int a1, int a2, int a3, int a4);                                                // 0x0052B720

// 0x0052B330
unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize)
{
    const unsigned char* pPacket = (const unsigned char*)pPacketArg;

    D2_ASSERT(nPacketSize <= 516, 344);

    if (NET_IsLocalConnection())
    {
        CLIENT_ReadPacketFromBuffer((void*)pPacket, nPacketSize);
        return nPacketSize;
    }

    if (nSendMode != 0 || *pPacket != 0xAF)
    {
        FOG_10222(pPacket, nPacketSize);
        if (nSendMode != 2)
        {
            unsigned char frame[1036];
            unsigned int nFrameSize = FOG_CompressPacket(&frame[2], 1032, pPacket, nPacketSize);
            D2_ASSERT(nFrameSize, 376);

            if (++nFrameSize < 0xF0)
            {
                frame[1] = (unsigned char)nFrameSize;
                return FOG_10157(gpServer_00882D08, (unsigned int)pClientId, &frame[1], nFrameSize) != 0 ? nFrameSize : 0;
            }

            ++nFrameSize;
            frame[0] = (unsigned char)((nFrameSize >> 8) | 0xF0);
            frame[1] = (unsigned char)nFrameSize;
            return FOG_10157(gpServer_00882D08, (unsigned int)pClientId, frame, nFrameSize) != 0 ? nFrameSize : 0;
        }
    }

    return FOG_10157(gpServer_00882D08, (unsigned int)pClientId, pPacket, nPacketSize) != 0 ? nPacketSize : 0;
}

// 0x0052B750
int __fastcall SERVER_OnClientDisconnectedCallback(int a1, int a2, int a3, int a4)
{
    const unsigned char data[1] = { 0x70 };

    FOG_10175(gpServer, data, sizeof(data), a2);
    return 1;
}

// 0x0052B7A0
void __stdcall SERVER_Initialize(int a1, int a2)
{
    gpServer = QSInit(a1, 3, GAME_PORT, a2, SERVER_ValidateClientPacket, SERVER_OnClientConnectedCallback, SERVER_OnClientDisconnectedCallback, SERVER_SendToLocalClientCallback);
}

// 0x0052B570
void __stdcall D2NET_10016(int nClientId)
{
    FOG_10165(gpServer, nClientId, ".\\SRC\\Server.cpp", 468);
}

// 0x0052B5A0
void __stdcall D2NET_10018(int a1)
{
    if (!gpServer)
    {
        return;
    }

    FOG_10170(gpServer, a1);
}

// 0x0052B5C0
int __stdcall SERVER_SetRemoveClientCallback(D2NET_Unk_Callback pfCallback)
{
    return FOG_10171(gpServer, pfCallback);
}

// 0x0052B5E0
int __stdcall SERVER_SetClientGameGUID(int nClientId, int dwGameGuid)
{
    if (nClientId)
    {
        return FOG_10172(gpServer, nClientId, dwGameGuid);
    }

    gnLocalClientGameGuid = dwGameGuid;

    return dwGameGuid;
}

// 0x0052B610
int __stdcall SERVER_GetClientGameGUID(int nClientId)
{
    if (nClientId)
    {
        return FOG_10173(gpServer, nClientId);
    }

    return gnLocalClientGameGuid;
}

// 0x0052B640
int __fastcall SERVER_EnqueueClientPacket(const unsigned char* pBuffer, unsigned short nBufferSize, int a3)
{
    D2_ASSERT(nBufferSize <= MAX_MSG_SIZE, 521);

    return FOG_10175(gpServer, pBuffer, nBufferSize, a3);
}

// 0x0052B6D0
int __stdcall D2NET_10022(int dwMilliseconds)
{
    return FOG_10177(gpServer, dwMilliseconds);
}

// 0x0052B700
void __stdcall D2NET_10029_Return(int nUnused)
{
    FOG_10183_Return(gpServer, nUnused);
}
