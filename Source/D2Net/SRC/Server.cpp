#include "D2Net.h"

#define GAME_PORT 4000
struct D2PacketBufferStrc;

typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);
typedef int (__fastcall* D2NET_PacketCallback)(int, int, int, int);
typedef int (__fastcall* D2NET_ReadPacketCallback)(QServer*, D2PacketBufferStrc*, int);
int gnLocalClientGameGuid_6FC0B26C;                                                                         // 0x00882D0C

QServer* __stdcall QSInit(int a1, int a2, int a3, int a4, D2NET_PacketCallback a5, D2NET_PacketCallback a6, D2NET_PacketCallback a7, D2NET_ReadPacketCallback a8); // 0x006BF760
int __stdcall FOG_10165(QServer* pServer, int nClientId, const char* szFile, int nLine);                   // 0x006C06B0
int __stdcall FOG_10170(QServer* pServer, int a2);                                                          // 0x006BF040
int __stdcall FOG_10171(QServer* pServer, D2NET_Unk_Callback pfCallback);                                   // 0x006BF080
int __stdcall FOG_10172(QServer* pServer, int nClientId, int dwGameGuid);                                   // 0x006BF0A0
int __stdcall FOG_10173(QServer* pServer, int nClientId);                                                   // 0x006BF0C0
int __stdcall FOG_10177(QServer* pServer, int dwMilliseconds);                                              // 0x006BEBC0
void __stdcall FOG_10183_Return(QServer* pServer, int nUnused);                                             // 0x006BF600
int __fastcall sub_0052B0E0(QServer* nUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize); // 0x0052B0E0
int __fastcall SERVER_ValidateClientPacket(int a1, int a2, int a3, int a4);                                 // 0x0052B100
int __fastcall sub_6FC020B0(int a1, int a2, int a3, int a4);                                                // 0x0052B720

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
int __stdcall sub_0052B5C0_SetServerHandler(D2NET_Unk_Callback pfCallback)
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

    gnLocalClientGameGuid_6FC0B26C = dwGameGuid;

    return dwGameGuid;
}

// 0x0052B610
int __stdcall SERVER_GetClientGameGUID(int nClientId)
{
    if (nClientId)
    {
        return FOG_10173(gpServer, nClientId);
    }

    return gnLocalClientGameGuid_6FC0B26C;
}

// 0x0052B640
int __fastcall sub_0052B640(const unsigned char* pBuffer, unsigned short nBufferSize, int a3)
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

// 0x0052B750
int __fastcall sub_6FC020E0(int a1, int a2, int a3, int a4)
{
    const unsigned char data[1] = { 0x70 };

    FOG_10175(gpServer, data, sizeof(data), a2);
    return 1;
}

// 0x0052B7A0
void __stdcall SERVER_Initialize(int a1, int a2)
{
    gpServer = QSInit(a1, 3, GAME_PORT, a2, SERVER_ValidateClientPacket, sub_6FC020B0, sub_6FC020E0, sub_0052B0E0);
}
