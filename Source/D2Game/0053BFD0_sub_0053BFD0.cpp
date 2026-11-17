#pragma pack(push, 1)
struct D2PacketHeaderOnlyStrc
{
    unsigned char nHeader;
};

struct D2PacketSize06Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};

struct D2PacketSize05Strc
{
    unsigned char nHeader;
    int nValue;
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

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

// @ref 0x0053B280
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

struct D2UnitStrc {char unitPrefix[0x0C];int dwUnitId;};
static __forceinline int SCMD_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}
#pragma pack(push,1)
struct PacketA1 {unsigned char header,stat;int guid;unsigned char value;};
struct PacketA2 {unsigned char header,stat;int guid;unsigned short value;};
struct PacketA0 {unsigned char header,stat;int guid;unsigned int value;};
#pragma pack(pop)
extern const char text_006CC837[];  // 0x006CC837
const char* __cdecl sub_00408090();  // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int);  // 0x00408A60
__declspec(noreturn) void __cdecl sub_00681E09(int);  // 0x00681E09
// 0x0053BFD0
void __fastcall sub_0053BFD0(D2ClientStrc* client,D2UnitStrc* unit,unsigned short stat,unsigned int base,unsigned int full) {
 if(stat>=0xFF) {sub_00408A60(text_006CC837,sub_00408090(),1069);sub_00681E09(-1);}
 full-=base;
 const int fitsWord=full<0xFFFF;
 if(full<0xFF) {
  PacketA1 packet;packet.header=0xA1;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket_6FC3C710(&packet,sizeof(packet),client);
 } else if(fitsWord) {
  PacketA2 packet;packet.header=0xA2;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket_6FC3C710(&packet,sizeof(packet),client);
 } else {
  PacketA0 packet;packet.header=0xA0;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=base;
  D2GAME_PACKETS_SendPacket_6FC3C710(&packet,sizeof(packet),client);
 }
}
