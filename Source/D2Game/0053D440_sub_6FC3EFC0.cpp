extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

struct D2GameStrc;
struct D2BitBufferStrc;

struct D2ObjectDataStrc
{
    void* pObjectTxt;
    unsigned char InteractType;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ObjectDataStrc* pObjectData;
};

struct D2PlayerDataStrc
{
    char szName[0x10];
};

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

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit);                                            // 0x00552B10
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned short __fastcall PLAYERLIST_GetFlags(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                  // 0x0055B350
short __fastcall sub_6FCBA9D0(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                                  // 0x0055B3F0
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit);                                      // 0x006222C0
void __stdcall QUESTRECORD_CopyRecordToBuffer(D2BitBufferStrc* pQuestFlags, unsigned char* pBuffer, int nBufferSize, int nUnused); // 0x0065C560

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

#pragma pack(push, 1)
struct D2GSPacketSrv7D
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID1;
    int nUnitGUID2;
    int unk0x0A;
    int unk0x0E;
};

struct D2GSPacketSrv28
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int unk0x02;
    unsigned char unk0x06;
    unsigned char pData[96];
};

struct D2GSPacketSrv29
{
    unsigned char nHeader;
    unsigned char pData[96];
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader;
    unsigned char nQuestId;
    unsigned char nFlags;
    unsigned char nState;
    unsigned short field_4;
};

struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short nSoundEvent;
};

struct D2GSPacketSrv4E
{
    unsigned char nHeader;
    unsigned short nMercName;
    int nSeed;
};

struct D2GSPacketSrv50
{
    unsigned char nHeader;
    unsigned short nQuestId;
    unsigned short nMonstersToBeKilled;
    unsigned short nStaffTombLevelOffset;
    unsigned short nBarbsToBeRescued;
    unsigned char unk0x09[6];
};

struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    unsigned char unk0x001[37];
};

struct D2GSPacketSrv52
{
    unsigned char nHeader;
    unsigned char pQuestList[41];
};

struct D2GSPacketSrv11
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short unk0x06;
};

struct D2GSPacketSrv58
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char unk0x05;
    unsigned char unk0x06;
};

struct D2GSPacketSrv60
{
    unsigned char nHeader;
    unsigned char nFlags;
    unsigned char nLevel;
    int dwUnitGUID;
};

struct D2GSPacketSrv61
{
    unsigned char nHeader;
    unsigned char unk0x01;
};

struct D2GSPacketSrv73
{
    unsigned char nHeader;
    int unk0x01;
    unsigned short nMissileId;
    int nX;
    int nY;
    int nFirstX;
    int nFirstY;
    unsigned short nCurrentFrame;
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned char nLevel;
    unsigned char nPierce;
};

struct D2GSPacketSrv75
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned short nPartyId;
    unsigned short nLevel;
    unsigned short nFlags;
    unsigned short unk0x0B;
};

struct D2GSPacketSrv7B
{
    unsigned char nHeader;
    unsigned char nSlot;
    unsigned short nSkill;
    int nItemGUID;
};

struct D2GSPacketSrv7E
{
    unsigned char nHeader;
    unsigned int unk0x01;
};

struct D2GSPacketSrv82
{
    unsigned char nHeader;
    int dwOwnerGUID;
    char szOwnerName[16];
    int dwPortalGUID0;
    int dwPortalGUID1;
};

struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    int dwPlayerGUID;
    int dwCorpseGUID;
};

struct D2GSPacketSrv89
{
    unsigned char nHeader;
    unsigned char nEvent;
};

struct D2GSPacketSrv8A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
};
#pragma pack(pop)

// 0x0053D440
void __fastcall sub_6FC3EFC0(D2ClientStrc* pClient, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int a4, int a5)
{
    D2GSPacketSrv7D packet7D = {};

    packet7D.nHeader = 0x7D;
    int nUnitType;
    if (!pUnit1)
        nUnitType = 6;
    else
        nUnitType = pUnit1->dwUnitType;
    packet7D.nUnitType = nUnitType;
    const int nUnitGUID1 = !pUnit1 ? -1 : pUnit1->dwUnitId;
    packet7D.nUnitGUID1 = nUnitGUID1;
    const int nUnitGUID2 = !pUnit2 ? -1 : pUnit2->dwUnitId;
    packet7D.nUnitGUID2 = nUnitGUID2;
    packet7D.unk0x0A = a4;
    packet7D.unk0x0E = a5;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7D, sizeof(packet7D), pClient);
}

// 0x0053D670
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6)
{
    D2GSPacketSrv28 packet28;

    packet28.nHeader = nHeader;
    packet28.unk0x01 = a3;
    packet28.unk0x02 = a4;
    packet28.unk0x06 = a6;

    QUESTRECORD_CopyRecordToBuffer(a5, packet28.pData, 0x60, 0);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet28, sizeof(packet28), pClient);
}

// 0x0053D700
void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053D710
void __fastcall sub_6FC3F380(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket)
{
    D2GSPacketSrv5D packet5D = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet5D, sizeof(packet5D), pClient);
}

// 0x0053D780
void __fastcall SCMD_SendPacket0x2C(D2ClientStrc* pClient, D2GSPacketSrv2C* pPacket)
{
    D2GSPacketSrv2C packet2C = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet2C, sizeof(packet2C), pClient);
}

// 0x0053D7B0
void __fastcall D2GAME_SendPacket0x4E_6FC3F410(D2ClientStrc* pClient, D2GSPacketSrv4E* pPacket)
{
    D2GSPacketSrv4E packet4E = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet4E, sizeof(packet4E), pClient);
}

// 0x0053D7E0
void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket)
{
    D2GSPacketSrv50 packet50 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet50, sizeof(packet50), pClient);
}

// 0x0053D830
void __fastcall sub_0053D830_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053D840
void __fastcall sub_0053D840(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053D850
void __fastcall D2GAME_PACKETS_SendPacket0x11_6FC3F4A0(D2ClientStrc* pClient, int nUnitType, int nUnitGUID, int nOverlay)
{
    D2GSPacketSrv11 packet11;

    packet11.nHeader = 0x11;
    packet11.nUnitType = nUnitType;
    packet11.dwUnitGUID = nUnitGUID;
    packet11.unk0x06 = nOverlay;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet11, sizeof(packet11), pClient);
}

// 0x0053D8D0
void __fastcall sub_0053D8D0_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket)
{
    D2GSPacketSrv58 packet58 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet58, sizeof(packet58), pClient);
}

// 0x0053D900
void __fastcall sub_6FC3F550(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv60 packet60;

    packet60.nHeader = 0x60;
    packet60.nFlags = UNITS_GetObjectPortalFlags(pUnit);
    packet60.nLevel = pUnit->pObjectData->InteractType;
    packet60.dwUnitGUID = pUnit->dwUnitId;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet60, sizeof(packet60), pClient);
}

// 0x0053D940
void __fastcall sub_0053D940_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue)
{
    D2GSPacketSrv61 packet61;

    packet61.nHeader = 0x61;
    packet61.unk0x01 = nValue;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet61, sizeof(packet61), pClient);
}

// 0x0053DA10
void __fastcall sub_6FC3F610(D2ClientStrc* pClient, D2GSPacketSrv73* pPacket)
{
    D2GSPacketSrv73 packet73 = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet73, sizeof(packet73), pClient);
}

// 0x0053DA90
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pLocalPlayer, ".\\GAME\\SCmd.cpp", 0xAFA);

    D2GSPacketSrv75 packet75 = {};

    packet75.nHeader = 0x75u;
    const int nUnitGUID = !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId;
    packet75.nUnitGUID = nUnitGUID;
    packet75.nLevel = STATLIST_UnitGetStatValue(pOtherPlayer, 0xC, 0);
    packet75.nPartyId = SUNIT_GetPartyId(pOtherPlayer);
    packet75.nFlags = PLAYERLIST_GetFlags(pLocalPlayer, pOtherPlayer);
    packet75.unk0x0B = sub_6FCBA9D0(pLocalPlayer, pOtherPlayer);

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet75, sizeof(packet75), pClient);
}

// 0x0053DB20
void __fastcall D2GAME_PACKETS_SendPacket0x7B_6FC3F720(D2ClientStrc* pClient, unsigned char nIndex, int nSkill, int nHand, int nItemGUID)
{
    D2GSPacketSrv7B packet7B;

    packet7B.nHeader = 0x7Bu;
    packet7B.nSlot = nIndex;
    packet7B.nSkill = nSkill & 0xFFF;
    packet7B.nItemGUID = nItemGUID;
    if (nHand)
        packet7B.nSkill |= 0x8000;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7B, sizeof(packet7B), pClient);
}

// 0x0053DB70
void __fastcall D2GAME_PACKETS_SendPacket0x7E_6FC3F770(D2ClientStrc* pClient)
{
    D2GSPacketSrv7E packet7E;

    packet7E.nHeader = 0x7E;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet7E, sizeof(packet7E), pClient);
}

// 0x0053DB90
void __fastcall D2GAME_PACKETS_SendPacket0x82_6FC3F790(D2GameStrc* pGame, D2ClientStrc* pClient, int nPortalGUID, int nPortalOwnerGUID)
{
    D2GSPacketSrv82 packet82;

    packet82.nHeader = 0x82u;
    D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, nPortalGUID);
    packet82.szOwnerName[0] = 0;
    if (pPortal)
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, OBJECTS_GetUnitIdFromTimerArg(pPortal));
        if (pPlayer)
        {
            SStrCopy(packet82.szOwnerName, UNITS_GetPlayerData(pPlayer)->szName, sizeof(packet82.szOwnerName));

            packet82.dwOwnerGUID = pPlayer->dwUnitId;
            packet82.dwPortalGUID0 = nPortalGUID;
            packet82.dwPortalGUID1 = nPortalOwnerGUID;

            D2GAME_PACKETS_SendPacket_6FC3C710(&packet82, sizeof(packet82), pClient);
        }
    }
}

// 0x0053DFB0
void __fastcall D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(D2ClientStrc* pClient, int nUnitId, int nCorpseId, unsigned char bAssign)
{
    D2GSPacketSrv8E packet8E;

    packet8E.nHeader = 0x8E;
    packet8E.dwPlayerGUID = nUnitId;
    packet8E.dwCorpseGUID = nCorpseId;
    packet8E.nType = bAssign;

    D2GAME_PACKETS_SendPacket_6FC3C710(&packet8E, sizeof(packet8E), pClient);
}

// 0x0053DFE0
void __fastcall sub_0053DFE0_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket)
{
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, sizeof(*pPacket), pClient);
}

// 0x0053DFF0
void __fastcall D2GAME_SendPacket0x8A_6FC3FA60(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket)
{
    D2GSPacketSrv8A packet8A = *pPacket;
    D2GAME_PACKETS_SendPacket_6FC3C710(&packet8A, sizeof(packet8A), pClient);
}
