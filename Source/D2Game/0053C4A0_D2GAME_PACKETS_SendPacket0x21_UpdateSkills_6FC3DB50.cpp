extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

struct D2UnitStrc;
struct D2GameStrc;

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
#pragma pack(pop)

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
};

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId);                        // 0x00644300

// build: context sub_GetUnitType
static __forceinline int sub_GetUnitType(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    return nUnitType;
}

// 0x0053C4A0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove)
{
    if (!pUnit)
    {
        return;
    }

    if (!pClient && pUnit->dwUnitType == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (!pOwner)
        {
            return;
        }

        pClient = SUNIT_GetClientFromPlayer(pOwner, ".\\GAME\\SCmd.cpp", 1298);
    }

    if (pClient)
    {
        D2GSPacketSrv21 packet21;
        packet21.nHeader = 0x21;
        packet21.nUnitType = sub_GetUnitType(pUnit);
        packet21.bRemove = bRemove;
        packet21.nUnitGUID = pUnit->dwUnitId;
        packet21.nSkillId = nSkillId;
        packet21.nSkillLevel = nSkillLevel;
        packet21.nBonusSkillLevel = (unsigned char)SKILLS_GetBonusSkillLevelFromSkillId(pUnit, nSkillId);
        D2GAME_PACKETS_SendPacket_6FC3C710(&packet21, sizeof(packet21), pClient);
    }
}
