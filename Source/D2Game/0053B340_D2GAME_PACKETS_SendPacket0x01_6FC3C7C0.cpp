#pragma pack(push, 1)
struct D2GSPacketSrv01 { unsigned char nHeader; unsigned char nDifficulty; unsigned int dwArenaFlags; unsigned char nExpansion; unsigned char nLadder; };
struct D2GSPacketSrv1A { unsigned char nHeader; unsigned char nExperience; };
struct D2GSPacketSrv1B { unsigned char nHeader; unsigned short nExperience; };
struct D2GSPacketSrv1C { unsigned char nHeader; unsigned int nExperience; };
struct D2GSPacketSrv1D { unsigned char nHeader; unsigned char nStat; unsigned char nValue; };
struct D2GSPacketSrv1E { unsigned char nHeader; unsigned char nStat; unsigned short nValue; };
struct D2GSPacketSrv1F { unsigned char nHeader; unsigned char nStat; unsigned int nValue; };
struct D2GSPacketSrv69 { unsigned char nHeader; unsigned int unk0x01; unsigned char unk0x05; unsigned short unk0x06; unsigned short unk0x08; unsigned char unk0x0A; unsigned char unk0x0B; };
struct D2GSPacketSrv6A { unsigned char nHeader; unsigned int nUnitGUID; unsigned char unk0x05; unsigned char nTargetUnitType; unsigned int nTargetUnitGuid; unsigned char nDirection; };
struct D2GSPacketSrv6B { unsigned char nHeader; unsigned int unk0x01; unsigned char unk0x05; unsigned short unk0x06; unsigned short unk0x08; unsigned char unk0x0A; unsigned char unk0x0B; unsigned short unk0x0C; unsigned short unk0x0E; };
struct D2GSPacketSrv6C { unsigned char nHeader; unsigned int unk0x01; unsigned char unk0x05; unsigned char unk0x06; unsigned int unk0x07; unsigned char unk0x0B; unsigned short unk0x0C; unsigned short unk0x0E; };
struct D2GSPacketSrv6D { unsigned char nHeader; unsigned int unk0x01; unsigned short unk0x05; unsigned short unk0x07; unsigned char unk0x09; };
struct D2GSPacketSrv67 { unsigned char nHeader; int nUnitGUID; unsigned char unk0x05; short nX; short nY; char unk0x0A; char unk0x0B; unsigned char nPathType; short nVelocity; char unk0x0F; };
struct D2GSPacketSrv68 { unsigned char nHeader; int nUnitGUID; unsigned char unk0x05; short nX; short nY; char unk0x0A; int unk0x0B; char unk0x0F; char unk0x10; unsigned char nPathType; short nVelocity; char unk0x14; };
struct D2GSPacketSrv9E { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned char nValue; };
struct D2GSPacketSrv9F { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned short nValue; };
struct D2GSPacketSrvA0 { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned int nValue; };
struct D2GSPacketSrvA1 { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned char nValue; };
struct D2GSPacketSrvA2 { unsigned char nHeader; unsigned char nStat; unsigned int dwGUID; unsigned short nValue; };
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

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[2];
    int bExpansion;
    int dwGameType;
};

struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
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
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame);                                                  // 0x0053FD40
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall sub_00648A40_GetTargetX(D2DynamicPathStrc* pPath);                                            // 0x00648A40
int __stdcall sub_00648A60_GetTargetY(D2DynamicPathStrc* pPath);                                            // 0x00648A60
int __stdcall sub_00648E30_GetPathValue(D2DynamicPathStrc* pPath);                                          // 0x00648E30
unsigned char __stdcall sub_00648EA0_GetPathByte(D2DynamicPathStrc* pPath);                                 // 0x00648EA0

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define UNIT_MONSTER 1
#define STAT_VELOCITYPERCENT 67

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline int SCMD_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

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

// 0x0053B340
void __fastcall D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame)
{
    D2GSPacketSrv01 packet01;

    packet01.nHeader = nHeader;
    packet01.dwArenaFlags = ARENA_GetFlags(pGame);
    packet01.nDifficulty = pGame->nDifficulty;
    packet01.nExpansion = pGame->bExpansion != 0;
    packet01.nLadder = pGame->dwGameType != 0;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet01, sizeof(packet01), pClient);
}

// 0x0053B5F0
void __fastcall D2GAME_PACKETS_SendPacket0x68_6FC3CA90(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, char a5, int a6, char a7)
{
    D2GSPacketSrv68 packet68 = {};

    packet68.nHeader = nHeader;
    packet68.nUnitGUID = nUnitGUID;
    packet68.unk0x05 = a4;
    packet68.unk0x0A = a5;
    packet68.unk0x0B = a6;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;

    packet68.nX = CLIENTS_GetUnitXInline(pMonster);
    packet68.nY = CLIENTS_GetUnitYInline(pMonster);
    packet68.unk0x0F = a7;
    packet68.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet68.nPathType >= 5)
    {
        if (packet68.nPathType > 6)
        {
            if (packet68.nPathType == 8)
            {
                packet68.nPathType = 11;
            }
        }
        else
        {
            packet68.nPathType = 2;
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet68.nVelocity = nVelocity;
    packet68.unk0x14 = sub_00648EA0_GetPathByte(pPath);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet68, sizeof(packet68), pClient);
}

// 0x0053B710
void __fastcall D2GAME_PACKETS_SendPacket0x67_6FC3CBC0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, short nX, short nY, char a7)
{
    D2GSPacketSrv67 packet67 = {};

    packet67.nHeader = nHeader;
    packet67.nUnitGUID = nUnitGUID;
    packet67.unk0x05 = a4;
    packet67.nX = nX;
    packet67.nY = nY;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet67.unk0x0A = a7;
    packet67.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet67.nPathType >= 5)
    {
        if (packet67.nPathType > 6)
        {
            if (packet67.nPathType == 8)
            {
                packet67.nPathType = 11;
            }
        }
        else
        {
            packet67.nPathType = 1;
            packet67.nX = sub_00648A40_GetTargetX(pPath);
            packet67.nY = sub_00648A60_GetTargetY(pPath);
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet67.nVelocity = nVelocity;
    packet67.unk0x0F = sub_00648EA0_GetPathByte(pPath);
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet67, sizeof(packet67), pClient);
}

// 0x0053B7F0
void __fastcall D2GAME_PACKETS_SendPacket0x68_6FC3CCB0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, char a5, int a6, char a7, char a8, char a9)
{
    D2GSPacketSrv68 packet68 = {};

    packet68.nHeader = nHeader;
    packet68.nUnitGUID = nUnitGUID;
    packet68.unk0x05 = a4;
    packet68.unk0x0A = a5;
    packet68.unk0x0B = a6;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet68.nX = CLIENTS_GetUnitXInline(pMonster);
    packet68.nY = CLIENTS_GetUnitYInline(pMonster);
    packet68.unk0x0F = a7;
    packet68.unk0x10 = a9;
    packet68.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet68.nPathType == 8)
    {
        packet68.nPathType = 11;
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet68.nVelocity = nVelocity;
    packet68.unk0x14 = a8;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet68, sizeof(packet68), pClient);
}

// 0x0053B910
void __fastcall D2GAME_PACKETS_SendPacket0x67_6FC3CDE0(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char a4, short nX, short nY, char a7, char a8, char a9)
{
    D2GSPacketSrv67 packet67 = {};

    packet67.nHeader = nHeader;
    packet67.nUnitGUID = nUnitGUID;
    packet67.unk0x05 = a4;
    packet67.nX = nX;
    packet67.nY = nY;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet67.unk0x0A = a7;
    packet67.unk0x0B = a9;
    packet67.nPathType = sub_00648E30_GetPathValue(pPath);
    if (packet67.nPathType >= 5)
    {
        if (packet67.nPathType > 6)
        {
            if (packet67.nPathType == 8)
            {
                packet67.nPathType = 11;
            }
        }
        else
        {
            packet67.nPathType = 1;
            packet67.nX = sub_00648A40_GetTargetX(pPath);
            packet67.nY = sub_00648A60_GetTargetY(pPath);
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet67.nVelocity = nVelocity;
    packet67.unk0x0F = a8;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet67, sizeof(packet67), pClient);
}

// 0x0053B9F0
void __fastcall D2GAME_PACKETS_SendPacket0x6A_6FC3CEE0(D2ClientStrc* pClient, char a2, int nUnitGUID, char a4, char a5, int a6, char nDirection)
{
    D2GSPacketSrv6A packet6A = {};

    packet6A.nHeader = a2;
    packet6A.nUnitGUID = nUnitGUID;
    packet6A.unk0x05 = a4;
    packet6A.nTargetUnitType = a5;
    packet6A.nTargetUnitGuid = a6;
    packet6A.nDirection = nDirection;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6A, sizeof(packet6A), pClient);
}

// 0x0053BA40
void __fastcall D2GAME_PACKETS_SendPacket0x69_6FC3CF30(D2ClientStrc* pClient, char a2, int a3, char a4, short a5, short a6, char a7, char a8)
{
    D2GSPacketSrv69 packet69 = {};

    packet69.nHeader = a2;
    packet69.unk0x01 = a3;
    packet69.unk0x05 = a4;
    packet69.unk0x06 = a5;
    packet69.unk0x08 = a6;
    packet69.unk0x0A = a7;
    packet69.unk0x0B = a8;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet69, sizeof(packet69), pClient);
}

// 0x0053BAA0
void __fastcall D2GAME_PACKETS_SendPacket0x6C_6FC3CF90(D2ClientStrc* pClient, char a2, int a3, char a4, char a5, int a6, char a7, short a8, short a9)
{
    D2GSPacketSrv6C packet6C = {};

    packet6C.nHeader = a2;
    packet6C.unk0x01 = a3;
    packet6C.unk0x05 = a4;
    packet6C.unk0x06 = a5;
    packet6C.unk0x07 = a6;
    packet6C.unk0x0B = a7;
    packet6C.unk0x0C = a8;
    packet6C.unk0x0E = a9;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6C, sizeof(packet6C), pClient);
}

// 0x0053BB00
void __fastcall D2GAME_PACKETS_SendPacket0x6B_6FC3D000(D2ClientStrc* pClient, char a2, int a3, char a4, short a5, short a6, char a7, char a8, short a9, short a10)
{
    D2GSPacketSrv6B packet6B = {};

    packet6B.nHeader = a2;
    packet6B.unk0x01 = a3;
    packet6B.unk0x05 = a4;
    packet6B.unk0x06 = a5;
    packet6B.unk0x08 = a6;
    packet6B.unk0x0A = a7;
    packet6B.unk0x0B = a8;
    packet6B.unk0x0C = a9;
    packet6B.unk0x0E = a10;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6B, sizeof(packet6B), pClient);
}

// 0x0053BB70
void __fastcall D2GAME_PACKETS_SendPacket0x6D_6FC3D080(D2ClientStrc* pClient, unsigned int dwUnitId, unsigned short nX, unsigned short nY, unsigned char nUnitLife)
{
    D2GSPacketSrv6D packet6D = {};

    packet6D.nHeader = 0x6D;
    packet6D.unk0x01 = dwUnitId;
    packet6D.unk0x05 = nX;
    packet6D.unk0x07 = nY;
    packet6D.unk0x09 = nUnitLife;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet6D, sizeof(packet6D), pClient);
}

// 0x0053BDD0
void __fastcall D2GAME_PACKETS_SendPacket0x1A_B_C_6FC3D410(D2ClientStrc* pClient, int nExperience, int a3)
{
    const int nDiff = nExperience - a3;

    if (nDiff >= 0 && nDiff < 0xFFFF)
    {
        if (nDiff < 0xFF)
        {
            D2GSPacketSrv1A packet1A;
            packet1A.nHeader = 0x1A;
            packet1A.nExperience = nDiff;
            D2GAME_PACKETS_SendPacket_6FC3C710(&packet1A, sizeof(packet1A), pClient);
        }
        else
        {
            D2GSPacketSrv1B packet1B;
            packet1B.nHeader = 0x1B;
            packet1B.nExperience = nDiff;
            D2GAME_PACKETS_SendPacket_6FC3C710(&packet1B, sizeof(packet1B), pClient);
        }
    }
    else
    {
        D2GSPacketSrv1C packet1C;
        packet1C.nHeader = 0x1C;
        packet1C.nExperience = nExperience;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1C, sizeof(packet1C), pClient);
    }
}

// 0x0053BE40
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue)
{
    D2_ASSERT(nStatId < 0xFF, 971);

    if (nValue < 0xFF)
    {
        D2GSPacketSrv1D packet1D;
        packet1D.nHeader = 0x1D;
        packet1D.nStat = (unsigned char)nStatId;
        packet1D.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1D, sizeof(packet1D), pClient);
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = (unsigned char)nStatId;
        packet1E.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1E, sizeof(packet1E), pClient);
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = (unsigned char)nStatId;
        packet1F.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet1F, sizeof(packet1F), pClient);
    }
}

// 0x0053BEE0
void __fastcall D2GAME_PACKETS_SendPacket0x9E_9F_A0_6FC3D520(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nStatId, unsigned int nValue)
{
    D2_ASSERT(nStatId < 0xFF, 1013);

    const int bFitsWord = nValue < 0xFFFF;
    if (nValue < 0xFF)
    {
        D2GSPacketSrv9E packet9E;
        packet9E.nHeader = 0x9E;
        packet9E.nStat = (unsigned char)nStatId;
        packet9E.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9E.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet9E, sizeof(packet9E), pClient);
    }
    else if (bFitsWord)
    {
        D2GSPacketSrv9F packet9F;
        packet9F.nHeader = 0x9F;
        packet9F.nStat = (unsigned char)nStatId;
        packet9F.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9F.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet9F, sizeof(packet9F), pClient);
    }
    else
    {
        D2GSPacketSrvA0 packetA0;
        packetA0.nHeader = 0xA0;
        packetA0.nStat = (unsigned char)nStatId;
        packetA0.dwGUID = SCMD_GetUnitGUID(pUnit);
        packetA0.nValue = nValue;
        D2GAME_PACKETS_SendPacket_6FC3C710(&packetA0, sizeof(packetA0), pClient);
    }
}
