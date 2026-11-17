#pragma pack(push, 1)
struct D2GSPacketSrv98 { unsigned char nHeader; unsigned int unk0x01; unsigned short unk0x05; };
struct D2GSPacketSrv9B { unsigned char nHeader; unsigned short unk0x01; int unk0x03; };
struct D2GSPacketSrv97 { unsigned char nHeader; };
struct D2GSPacketSrvA4 { unsigned char nHeader; short unk0x01; };
struct D2GSPacketSrvA7 { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nState; };
struct D2GSPacketSrvA9 { unsigned char nHeader; unsigned char nUnitType; int nUnitId; unsigned char nState; };
struct D2GSPacketSrv59 { unsigned char nHeader; unsigned int dwGUID; unsigned char nClass; char szName[16]; short nPosX; short nPosY; };
struct D2GSPacketSrv19 { unsigned char nHeader; unsigned char nGold; };
struct D2GSPacketSrv1D { unsigned char nHeader; unsigned char nStat; unsigned char nValue; };
struct D2GSPacketSrv1E { unsigned char nHeader; unsigned char nStat; unsigned short nValue; };
struct D2GSPacketSrv1F { unsigned char nHeader; unsigned char nStat; unsigned int nValue; };
struct D2GSPacketSrv9C { unsigned char nHeader; unsigned char nAction; unsigned char nPacketSize; unsigned char nComponent; int nItemId; unsigned char pBitstream[244]; };
#pragma pack(pop)

struct D2PacketDataStrc
{
    int nPacketSize;
    unsigned char packetData[0x200];
    D2PacketDataStrc* pNext;
};

struct D2ClientStrc
{
    char unk0x000[0x1B8];
    D2PacketDataStrc* pPacketDataHead;
    D2PacketDataStrc* pPacketDataTail;
    D2PacketDataStrc* pPacketDataPool;
};

struct D2GameStrc;
struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);               // 0x0053DA90
unsigned char __stdcall sub_00623D60_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem);                // 0x00623D60
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
int __fastcall sub_0053EA50_SendSocketedItems(D2ClientStrc* pClient, D2UnitStrc* pItem, int nFlags);       // 0x0053EA50

#define STAT_GOLD 14
#define UNIT_PLAYER 0

// 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void* pPacket, int nPacketSize, D2ClientStrc* pClient)
{
    int nSize = 0;
    if (!pClient)
    {
        return;
    }

    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetTail(pClient);
    if (pPacketData)
    {
        nSize = pPacketData->nPacketSize;
    }

    if (nPacketSize + nSize > 0x200 || !pPacketData)
    {
        pPacketData = pClient->pPacketDataPool;
        nSize = 0;
        if (pPacketData)
        {
            pClient->pPacketDataPool = pPacketData->pNext;
        }
        else
        {
            pPacketData = (D2PacketDataStrc*)sub_0040B430(0, sizeof(D2PacketDataStrc), ".\\GAME\\SCmd.cpp", 0xA0, 0);
        }

        memset(pPacketData, 0, sizeof(D2PacketDataStrc));
        CLIENTS_PacketDataList_Append(pClient, pPacketData);
    }

    memcpy(&pPacketData->packetData[nSize], pPacket, nPacketSize);
    pPacketData->nPacketSize += nPacketSize;
}

// 0x0053E0A0
void __fastcall sub_6FC3FAF0(D2ClientStrc* pClient, unsigned int a2, unsigned short a3)
{
    D2GSPacketSrv98 packet98 = {};

    packet98.nHeader = 0x98;
    packet98.unk0x01 = a2;
    packet98.unk0x05 = a3;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet98, sizeof(packet98), pClient);
}

// 0x0053E0E0
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3)
{
    D2GSPacketSrv9B packet9B;

    packet9B.nHeader = 0x9B;
    packet9B.unk0x01 = nUnitGUID;
    packet9B.unk0x03 = a3;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet9B, sizeof(packet9B), pClient);
}

// 0x0053E110
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc* pClient)
{
    D2GSPacketSrv97 packet97 = {};

    packet97.nHeader = 0x97;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet97, sizeof(packet97), pClient);
}

// 0x0053E1A0
void __fastcall D2GAME_PACKETS_SendPacket0xA4_6FC3FC00(D2ClientStrc* pClient, short a2)
{
    D2GSPacketSrvA4 packetA4;

    packetA4.nHeader = 0xA4;
    packetA4.unk0x01 = a2;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA4, sizeof(packetA4), pClient);
}

// 0x0053E260
void __fastcall D2GAME_PACKETS_SendPacket0xA7_StateOn_6FC3FC20(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA7 packetA7;

    packetA7.nHeader = 0xA7;
    packetA7.nUnitType = nUnitType;
    packetA7.nUnitId = dwUnitId;
    packetA7.nState = nState;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA7, sizeof(packetA7), pClient);
}

// 0x0053E290
void __fastcall D2GAME_PACKETS_SendPacket0xA9_StateOff_6FC3FC50(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA9 packetA9;

    packetA9.nHeader = 0xA9;
    packetA9.nUnitType = nUnitType;
    packetA9.nUnitId = dwUnitId;
    packetA9.nState = nState;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packetA9, sizeof(packetA9), pClient);
}

// 0x0053E8D0
void __fastcall sub_0053E8D0_SendPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, nPacketSize, pClient);
}

// 0x0053E8F0
void __fastcall sub_6FC3D1F0(D2ClientStrc* pClient, int nUnitGUID, unsigned char nClassId, const char* szName, short nX, short nY)
{
    D2GSPacketSrv59 packet59 = {};

    packet59.nHeader = 0x59;
    packet59.dwGUID = nUnitGUID;
    packet59.nClass = nClassId;
    memset(packet59.szName, 0, sizeof(packet59.szName));
    SStrCopy(packet59.szName, szName, 0x7FFFFFFF);
    packet59.nPosX = nX;
    packet59.nPosY = nY;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet59, sizeof(packet59), pClient);

    D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_PLAYER, nUnitGUID);
    if (pOtherPlayer)
    {
        SCMD_Send0x75_PartyRosterUpdate(pLocalPlayer, pOtherPlayer);
    }
}

static __forceinline void __fastcall SCMD_SendGoldStat(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue)
{
    const unsigned char nPacketStatId = (unsigned char)nStatId;
    if (nValue < 0xFF)
    {
        D2GSPacketSrv1D packet1D;
        packet1D.nHeader = 0x1D;
        packet1D.nStat = nPacketStatId;
        packet1D.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1D, sizeof(packet1D), pClient);
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = nPacketStatId;
        packet1E.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1E, sizeof(packet1E), pClient);
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = nPacketStatId;
        packet1F.nValue = nValue;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1F, sizeof(packet1F), pClient);
    }
}

static __forceinline int SCMD_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x0053E9B0
void __fastcall D2GAME_PACKETS_SendPacket0x19_6FC3D3D0(D2ClientStrc* pClient, int nValue, int a3)
{
    const int nDiff = nValue - a3;
    if (nDiff <= 0 || nDiff >= 0xFF)
    {
        SCMD_SendGoldStat(pClient, STAT_GOLD, nValue);
    }
    else
    {
        D2GSPacketSrv19 packet19;
        packet19.nHeader = 0x19;
        packet19.nGold = nDiff;

        D2GAME_PACKETS_SendPacket_6FC3C710(&packet19, sizeof(packet19), pClient);
    }
}

// 0x0053EAE0
void __fastcall D2GAME_SendPacket0x9C_6FC3E570(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);

    D2_ASSERT(pPlayer, 1915);

    D2GSPacketSrv9C packet9C;

    packet9C.nHeader = 0x9C;
    packet9C.nAction = nAction;
    packet9C.nItemId = SCMD_GetUnitGUID(pItem);
    packet9C.nComponent = sub_00623D60_GetItemComponent(pPlayer, pItem);

    const unsigned int nOldItemFlags = ITEMS_GetItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwFlag, 1);

    memset(packet9C.pBitstream, 0, sizeof(packet9C.pBitstream));

    const unsigned int nLength = ITEMS_SerializeItemToBitstream(pItem, packet9C.pBitstream, sizeof(packet9C.pBitstream), 0, 0, bGamble) + 8;

    D2_ASSERT(nLength <= 0xFC, 1932);

    packet9C.nPacketSize = nLength;
    ITEMS_SetItemFlag(pItem, 0xFFFFFFFF, 0);
    ITEMS_SetItemFlag(pItem, nOldItemFlags, 1);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet9C, packet9C.nPacketSize, pClient);

    sub_0053EA50_SendSocketedItems(pClient, pItem, dwFlag);
}
