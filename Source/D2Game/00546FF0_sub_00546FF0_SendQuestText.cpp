extern "C" char* __cdecl strcpy(char* pDestination, const char* pSource);

struct D2ClientStrc;
struct D2GameStrc
{
    void sub_00546FF0_SendQuestText(const char* szText); // 0x00546FF0
};

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);
extern void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0
extern void __fastcall sub_00546FE0_SendQuestTextToClient(D2ClientStrc* pClient, void* pContext); // 0x00546FE0

// 0x00546FF0
void D2GameStrc::sub_00546FF0_SendQuestText(const char* szText)
{
    D2GSPacketSrv26 packet;
    packet.szName[0] = 0;
    packet.nNameColor = 0;
    strcpy(packet.szMessage, szText);
    packet.nMessageColor = 0;
    packet.nHeader = 0x26;
    packet.dwUnitGUID = 0;
    packet.nUnitType = 2;
    packet.nMessageType = 1;
    D2GSPacketSrv26* pPacket = &packet;
    GAME_ForEachIngameClient(this, sub_00546FE0_SendQuestTextToClient, &pPacket);
}
