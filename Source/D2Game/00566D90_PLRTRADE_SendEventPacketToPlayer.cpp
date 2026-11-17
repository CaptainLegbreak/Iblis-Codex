struct D2ClientStrc;
struct D2UnitStrc;

#pragma pack(push, 1)
struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned int dwParam;
    unsigned char nParam;
    char szText[32];
};
#pragma pack(pop)

#define STRCOLOR_WHITE 0

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket);   // 0x0053C850
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0

// 0x00566D90
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource)
{
    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nType = nType;
    packet5A.nColor = STRCOLOR_WHITE;
    packet5A.dwParam = 0;

    if (szSource)
    {
        SStrCopy(packet5A.szText, szSource, 0x7FFFFFFF);
        packet5A.szText[15] = 0;
    }
    else
    {
        packet5A.szText[0] = 0;
    }

    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2254), &packet5A);
}
