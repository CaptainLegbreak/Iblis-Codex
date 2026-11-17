#pragma pack(push, 1)
struct D2GSPacketSrv0C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessage;
    unsigned char nHitClass;
    unsigned char nLife;
};

struct D2GSPacketSrv0D
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nHitClass;
    unsigned short nX;
    unsigned short nY;
    unsigned char nHitType;
    unsigned char nUnitLifePct;
};

struct D2GSPacketSrv15
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char bReassign;
};

struct D2GSPacketSrv07
{
    unsigned char nHeader;
    unsigned short nX;
    unsigned short nY;
    unsigned char nLevelId;
};

struct D2GSPacketSrv21
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char bRemove;
    unsigned int nUnitGUID;
    unsigned short nSkillId;
    unsigned char nSkillLevel;
    unsigned char nBonusSkillLevel;
    unsigned char unk0x0B;
};

struct D2GSPacketSrv23
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nPosition;
    unsigned short nSkill;
    unsigned int nOwnerGUID;
};

struct D2GSPacketSrv3F
{
    unsigned char nHeader;
    unsigned char nCursor;
    unsigned int dwItemId;
    unsigned short nSkill;
};

struct D2GSPacketSrv57
{
    unsigned char nHeader;
    unsigned int dwUnitGUID;
    unsigned char nUnitType;
    unsigned short nNameSeed;
    unsigned short nUMods01;
    unsigned short nUMods23;
    unsigned short bChampion;
};

struct D2GSPacketSrv99
{
    unsigned char nHeader;
    unsigned char nSourceUnitType;
    unsigned int nSourceUnitGUID;
    unsigned short nSkillId;
    unsigned char nSkillLevel;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned short nItemEffect;
};

struct D2GSPacketSrv9A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int nUnitGUID;
    unsigned int nSkillId;
    unsigned char nSkillLevel;
    unsigned short nX;
    unsigned short nY;
    unsigned short nItemEffect;
};
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
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    D2DynamicPathStrc* pDynamicPath;
};

#define UNIT_MONSTER 1

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId);                        // 0x00644300

// build: symbol ?D2GAME_PACKETS_SendPacket_6FC3C710@@YGXPBXHPAUD2ClientStrc@@@Z 0x0053B280
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

// 0x0053B430
void __fastcall D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char nHitClass, unsigned char nLifePct)
{
    D2GSPacketSrv0C packet0C;

    packet0C.nHeader = nHeader;
    packet0C.nUnitType = nUnitType;
    packet0C.dwUnitGUID = nUnitGUID;
    packet0C.nMessage = a5;
    packet0C.nHitClass = nHitClass;
    packet0C.nLife = nLifePct;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet0C, sizeof(packet0C), pClient);
}

// 0x0053B4B0
void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife)
{
    D2GSPacketSrv0D packet0D;

    packet0D.nHeader = nPacketId;
    packet0D.nUnitType = nUnitType;
    packet0D.dwUnitGUID = nUnitId;
    packet0D.nHitClass = nHitClass;
    packet0D.nX = nX;
    packet0D.nY = nY;
    packet0D.nHitType = nHitType;
    packet0D.nUnitLifePct = nLife;

    D2_ASSERT(nUnitType < 6, 0x136);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet0D, sizeof(packet0D), pClient);
}

// 0x0053BC10
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7)
{
    D2GSPacketSrv15 packet15;

    packet15.nHeader = nHeader;
    packet15.nUnitType = nUnitType;
    packet15.dwUnitGUID = nUnitGUID;
    packet15.nPosX = nPosX;
    packet15.nPosY = nPosY;
    packet15.bReassign = a7;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet15, sizeof(packet15), pClient);
}

// 0x0053BC50
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, unsigned char nAreaId, unsigned short nTileX, unsigned short nTileY)
{
    D2GSPacketSrv07 packet07;

    packet07.nHeader = 0x07;
    packet07.nX = nTileX;
    packet07.nY = nTileY;
    packet07.nLevelId = nAreaId;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet07, sizeof(packet07), pClient);
}

// 0x0053D880
void __fastcall sub_6FC3F4D0(D2ClientStrc* pClient, int a2, unsigned char a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7)
{
    D2GSPacketSrv57 packet57;

    packet57.nHeader = 0x57;
    packet57.dwUnitGUID = a2;
    packet57.nUnitType = a3;
    packet57.nNameSeed = a4;
    packet57.nUMods01 = a5;
    packet57.nUMods23 = a6;
    packet57.bChampion = a7;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet57, sizeof(packet57), pClient);
}
