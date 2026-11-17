extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#pragma pack(push, 1)
struct D2GSPacketSrv01
{
    unsigned char nHeader;
    unsigned char nDifficulty;
    unsigned int dwArenaFlags;
    unsigned char nExpansion;
    unsigned char nLadder;
};

struct D2GSPacketSrv03
{
    unsigned char nHeader;
    unsigned char nAct;
    unsigned int dwGameSeed;
    unsigned short nTownLevelId;
    unsigned int nObjectSeed;
};
#pragma pack(pop)

struct D2ActiveRoomStrc;
struct D2PlayerDataStrc
{
    char pad0x00[0x150];
    unsigned int unk0x150;
    unsigned int unk0x154;
    unsigned int unk0x158;
    unsigned int unk0x15C;
};

struct D2UnitStrc
{
    int dwUnitType;
    char pad0x04[0x10];
    D2PlayerDataStrc* pPlayerData;
};

void __fastcall sub_0044DC70_SetDifficulty(unsigned char nDifficulty);                                      // 0x0044DC70
void __fastcall sub_0044DC80(unsigned char nValue);                                                         // 0x0044DC80
void __fastcall sub_0044DC90(int nValue);                                                                   // 0x0044DC90
void __fastcall sub_0047A9A0_SetClientFlags(int nFlags);                                                    // 0x0047A9A0
void __cdecl sub_00456970_InitUI();                                                                         // 0x00456970
void __fastcall sub_0044E100_LoadAct(unsigned char nAct, unsigned int dwGameSeed, unsigned int dwObjectSeed, int nTownLevelId); // 0x0044E100
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
extern int gnValue_007A0624;                                                                                // 0x007A0624
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
void __fastcall sub_00470B10_PreloadForceAct(int nAct);                                                     // 0x00470B10

// 0x0045C8B0
void __fastcall sub_0045C8B0_GamePacket01_GameFlags(D2GSPacketSrv01* pPacket)
{
    const unsigned int dwArenaFlags = pPacket->dwArenaFlags;
    sub_0044DC70_SetDifficulty(pPacket->nDifficulty);
    sub_0044DC80(pPacket->nExpansion);
    sub_0044DC90(pPacket->nLadder);
    sub_0047A9A0_SetClientFlags(dwArenaFlags);
    sub_00456970_InitUI();
}

// 0x0045C8E0
void __fastcall sub_0045C8E0_GamePacket03_LoadAct(D2GSPacketSrv03* pPacket)
{
    sub_0044E100_LoadAct(pPacket->nAct, pPacket->dwGameSeed, pPacket->nObjectSeed, pPacket->nTownLevelId);
}

// 0x0045C9A0
void __fastcall sub_0045C9A0_GamePacket04_LoadDone(void* pPacket)
{
    gdwGlobal_007A061C = 1;
    gnValue_007A0624 = 0;
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        sub_00470B10_PreloadForceAct(DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)));
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer && pPlayer->dwUnitType == 0 && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->unk0x150 = 0;
            pPlayer->pPlayerData->unk0x154 = 0;
            pPlayer->pPlayerData->unk0x158 = 0;
            pPlayer->pPlayerData->unk0x15C = 0;
        }
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x527);
        exit(-1);
    }
}
