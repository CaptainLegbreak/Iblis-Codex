#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Drlg.h"

#include "D2UnitData.h"
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MonsterDataStrc;
struct D2GSPacketSrvB1;

void __fastcall MONSTER_RemoveAll(D2GameStrc* pGame); // 0x00573640
void __fastcall OBJECTS_RemoveAll(D2GameStrc* pGame); // 0x00552A40
void __fastcall PLAYER_RemoveAllPlayers(D2GameStrc* pGame); // 0x00534A50
void __fastcall ITEMS_RemoveAll(D2GameStrc* pGame); // 0x00557F10
void __fastcall MISSILES_RemoveAll(D2GameStrc* pGame); // 0x0059F840
void __fastcall sub_00555770_RemoveAllTiles(D2GameStrc* pGame); // 0x00555770
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize); // 0x0052B330

#pragma pack(push, 1)
struct D2GSPacketSrvB1
{
    unsigned char nHeader;
    char szGameName[48];
    unsigned short nClientCount;
    unsigned short nGameId;
};

#pragma pack(pop)

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

// 0x0053B1B0
int __fastcall sub_6FC3C640(int nClientId, short nGameId, short nClientCount, const char* szGameName)
{
    D2GSPacketSrvB1 packetB1;

    packetB1.nHeader = 0xB2;
    packetB1.nGameId = nGameId;
    packetB1.nClientCount = nClientCount;

    SStrCopy(packetB1.szGameName, szGameName, 0x10);

    return sub_0052B330(0, nClientId, &packetB1, sizeof(packetB1));
}
