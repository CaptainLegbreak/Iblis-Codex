struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

struct D2GameDataTableStrc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
void __fastcall CLIENTS_Release();                                                                          // 0x00537730
void __fastcall SUNITPROXY_ClearGlobalItemCache();                                                          // 0x00537120
extern D2CriticalSectionStrc gCriticalSection_6FD45800;                                                     // 0x00882D18
extern unsigned short gwGameId_6FD2CA04;                                                                    // 0x00731000
extern D2GameDataTableStrc* gpGameDataTbl_6FD45818;                                                         // 0x00883D38
extern int gnAct_6FD45824;                                                                                  // 0x00883D44

// 0x0052C030
int __stdcall GAME_Shutdown()
{
    CLIENTS_Release();
    DeleteCriticalSection(&gCriticalSection_6FD45800);
    SUNITPROXY_ClearGlobalItemCache();
    gwGameId_6FD2CA04 = 1;
    gpGameDataTbl_6FD45818 = 0;
    gnAct_6FD45824 = 0;
    return 1;
}

#include "gen/data/Source/D2Game/Unknown_0052C030.inc"
