struct D2UnitStrc { char pad[0x10]; int dwAnimMode; };
struct D2GameStrc { char pad[0x1DC4]; unsigned int dwLastPacketTime; };
struct D2SkillStrc;
typedef int (__fastcall* PacketCallback)(D2GameStrc*,D2UnitStrc*,unsigned char*,int);
struct D2PacketTableStrc { PacketCallback pfCallback; int nSize; };
extern D2PacketTableStrc gPacketTable_006E0D18[]; // 0x006E0D18
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*); // 0x006CC34C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
unsigned int __cdecl sub_00410A80_GetTime(); // 0x00410A80
int __fastcall sub_0057EEC0(D2GameStrc*,D2UnitStrc*,int,int,D2SkillStrc*); // 0x0057EEC0
// 0x0054D750
int __fastcall D2GAME_PACKET_Handler_6FC89320(D2GameStrc* pGame,D2UnitStrc* pUnit,unsigned char* pPacket,int nSize)
{
    unsigned char nHeader = *pPacket;
    if (!nHeader || nHeader >= 103) return 3;
    if (!gPacketTable_006E0D18[nHeader].pfCallback) return 3;
    int bIgnore;
    switch (nHeader)
    {
    case 20: case 21: case 60: case 67: case 102:
        bIgnore = 0;
        break;
    case 32: case 38:
        bIgnore = !sub_0057EEC0(pGame,pUnit,1,0,0);
        break;
    case 65:
        bIgnore = 1;
        if (pUnit && pUnit->dwAnimMode == 17) bIgnore = 0;
        break;
    default:
        bIgnore = !sub_0057EEC0(pGame,pUnit,1,0,0);
        break;
    }
    if (!bIgnore)
    {
        if (pGame->dwLastPacketTime > 1) pGame->dwLastPacketTime = sub_00410A80_GetTime();
        if (IsBadCodePtr((void*)gPacketTable_006E0D18[nHeader].pfCallback))
        {
            sub_00408A60(&gszEmptyAssertText,sub_00408090(),6564);
            exit(-1);
        }
        return gPacketTable_006E0D18[nHeader].pfCallback(pGame,pUnit,pPacket,nSize);
    }
    return 0;
}

#include "gen/data/Source/D2Game/0054D750_D2GAME_PACKET_Handler_6FC89320.inc"
