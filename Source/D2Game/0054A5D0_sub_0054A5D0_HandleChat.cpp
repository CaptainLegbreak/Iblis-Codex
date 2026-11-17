struct D2GameStrc;
struct D2ClientStrc;
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMem; int dwUnitId; };
#pragma pack(push, 1)
struct D2GSPacketClt15 { unsigned char nHeader; unsigned char nType; unsigned char nColor; char szMessage[256]; char szName[16]; };
struct D2GSPacketSrv26 { unsigned char nHeader; unsigned char nType; unsigned char nColor; unsigned char nUnitType; int nUnitId; unsigned char nUnk; unsigned char nLevel; char szName[16]; char szMessage[256]; };
struct D2GSPacketSrv5A { unsigned char nHeader; unsigned char nType; unsigned char nColor; int nUnitId; unsigned char nUnk; char szName[16]; char szOther[16]; };
#pragma pack(pop)
struct D2GSPacketSrv26Args { D2GSPacketSrv26* pPacket26; D2GSPacketClt15* pPacket15; int nUnitId; };
typedef void (__fastcall* D2ClientCallback)(D2ClientStrc*, void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern const char gszPlrMsgSourceFile[]; // 0x006E1050
extern int gbWhispTextNotListening_6FD4DC24; // 0x008846E0
extern int gbWhispTextInGame_6FD4DC20; // 0x008846E4
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
void __fastcall GAME_ForEachIngameClient(D2GameStrc*, D2ClientCallback, void*); // 0x0052DED0
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc*, D2GSPacketSrv26*); // 0x0053C750
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc*, D2GSPacketSrv5A*); // 0x0053C850
void __fastcall D2GAME_PACKETS_HandlePlayerMessage_6FC847B0(D2ClientStrc*, void*); // 0x0054A470
void __fastcall D2GAME_PACKETS_HandleWhisper_6FC848A0(D2ClientStrc*, void*); // 0x0054A510
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc*, const char*, int); // 0x005531C0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
// 0x0054A5D0
int __fastcall sub_0054A5D0_HandleChat(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nSize)
{
    D2GSPacketClt15 packet15;
    memset(&packet15, 0, sizeof(packet15));
    packet15.nHeader = pBuffer[0];
    packet15.nType = pBuffer[1];
    packet15.nColor = pBuffer[2];
    const char* pText = (const char*)pBuffer + 3;
    SStrCopy(packet15.szMessage, pText, 256);
    const int nLength = SStrLen(pText);
    if (nLength >= 256 || nLength + 4 >= nSize) return 2;
    pText += nLength + 1;
    SStrCopy(packet15.szName, pText, 16);
    SStrLen(pText);
    D2GSPacketSrv26 packet26;
    const char* pName = CLIENTS_GetName(SUNIT_GetClientFromPlayer(pUnit, gszPlrMsgSourceFile, 0x9E7));
    if (SStrLen(pName) > 0) SStrCopy(packet26.szName, pName, 0x7FFFFFFF);
    else packet26.szName[0] = 0;
    const int nReceiverLength = SStrLen(packet15.szName);
    const int bWhisper = nReceiverLength > 0 && nReceiverLength <= 15;
    packet26.nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    packet15.szName[15] = 0;
    if (packet15.szMessage[255]) goto MalformedChat;
    if (SStrChr(packet15.szMessage, -1)) {
MalformedChat:
        return 0;
    }
    memcpy(packet26.szMessage, packet15.szMessage, 256);
    packet26.nColor = packet15.nColor;
    packet26.nUnk = 0;
    packet26.nHeader = 0x26;
    packet26.nUnitId = 0;
    packet26.nUnitType = 2;
    D2ClientCallback pCallback;
    if (bWhisper) { packet26.nType = 2; pCallback = D2GAME_PACKETS_HandleWhisper_6FC848A0; }
    else { packet26.nType = 1; pCallback = D2GAME_PACKETS_HandlePlayerMessage_6FC847B0; }
    gbWhispTextInGame_6FD4DC20 = 0;
    gbWhispTextNotListening_6FD4DC24 = 0;
    D2GSPacketSrv26Args args;
    args.pPacket26 = &packet26;
    args.pPacket15 = &packet15;
    args.nUnitId = pUnit && pUnit->dwUnitType == 0 ? pUnit->dwUnitId : -1;
    GAME_ForEachIngameClient(pGame, pCallback, &args);
    if (packet26.nType == 2)
    {
        if (gbWhispTextNotListening_6FD4DC24)
        {
            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nColor = 0;
            packet5A.nUnitId = 0;
            SStrCopy(packet5A.szName, packet15.szName, 0x7FFFFFFF);
            packet5A.nType = 13;
            packet5A.szName[15] = 0;
            D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(SUNIT_GetClientFromPlayer(pUnit, gszPlrMsgSourceFile, 0xA2C), &packet5A);
        }
        else if (!gbWhispTextInGame_6FD4DC20)
        {
            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nColor = 0;
            packet5A.nUnitId = 0;
            SStrCopy(packet5A.szName, packet15.szName, 0x7FFFFFFF);
            packet5A.nType = 4;
            packet5A.szName[15] = 0;
            D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(SUNIT_GetClientFromPlayer(pUnit, gszPlrMsgSourceFile, 0xA38), &packet5A);
        }
        else
        {
        D2GSPacketSrv26 reply;
        reply.nHeader = 0x26;
        reply.nType = 6;
        reply.nUnitId = 0;
        reply.nUnitType = 2;
        reply.nUnk = 0;
        SStrCopy(reply.szName, packet15.szName, 0x7FFFFFFF);
        reply.szName[15] = 0;
        reply.nColor = 0;
        memcpy(reply.szMessage, packet15.szMessage, 256);
        D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(SUNIT_GetClientFromPlayer(pUnit, gszPlrMsgSourceFile, 0xA46), &reply);
        }
    }
    return 0;
}
