#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameClient.h"
#include "D2GameRecords.h"


extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient);                         // 0x005392D0
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);        // 0x00539240

static void __stdcall D2GAME_PACKETS_SendPacket_6FC3C710(const void*, int, D2ClientStrc*); // 0x0053B280
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
struct D2SkillListStrc;
#pragma pack(push, 1)
struct D2SkillPacketEntryStrc { unsigned short nSkill; unsigned char nLevel; };
struct D2GSPacketSrv94 { unsigned char nHeader; unsigned char nCount; int nGUID; };
#pragma pack(pop)
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc*); // 0x005387C0
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc*); // 0x006438F0
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc*); // 0x00643910
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc*, const char*, int); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
void __fastcall FOG_FreePool(void*, void*, const char*, int, int); // 0x0040B480
// 0x0053C5D0
void __fastcall sub_0053C5D0(D2ClientStrc* pClient, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 0x55A);
    D2SkillListStrc* hSkillInfo = hUnit->pSkills;
    D2_ASSERT(hSkillInfo, 0x55D);
    D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(hSkillInfo);
    int nCount = 0;
    while (pSkill)
    {
        pSkill = SKILLS_GetNextSkill(pSkill);
        ++nCount;
    }
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    int nSize = 6 + 3 * nCount;
    D2GSPacketSrv94* pPacket = (D2GSPacketSrv94*)sub_0040B430(pGame->pMemoryPool, nSize, ".\\GAME\\SCmd.cpp", 0x568, 0);
    D2SkillPacketEntryStrc* pEntry = (D2SkillPacketEntryStrc*)(pPacket + 1);
    pPacket->nHeader = 0x94;
    D2_ASSERT(nCount < 256, 0x56E);
    pPacket->nCount = nCount;
    pPacket->nGUID = !hUnit ? -1 : hUnit->dwUnitId;
    for (pSkill = SKILLS_GetFirstSkillFromSkillList(hSkillInfo); pSkill;)
    {
        pEntry->nLevel = SKILLS_GetSkillLevel(hUnit, pSkill, 0);
        pEntry->nSkill = SKILLS_GetSkillIdFromSkill(pSkill, ".\\GAME\\SCmd.cpp", 0x576);
        pSkill = SKILLS_GetNextSkill(pSkill);
        ++pEntry;
    }
    D2GAME_PACKETS_SendPacket_6FC3C710(pPacket, nSize, pClient);
    FOG_FreePool(pGame->pMemoryPool, pPacket, ".\\GAME\\SCmd.cpp", 0x57E, 0);
}
