#include "D2GameTypes.h"

struct D2GameDataTableStrc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
void __fastcall CLIENTS_Release();                                                                          // 0x00537730
void __fastcall SUNITPROXY_ClearGlobalItemCache();                                                          // 0x00537120
extern D2CriticalSectionStrc gGameListLock;                                                     // 0x00882D18
extern unsigned short gwGameId;                                                                    // 0x00731000
extern D2GameDataTableStrc* gpGameDataTbl;                                                         // 0x00883D38
extern int gnAct;                                                                                  // 0x00883D44

// 0x0052C030
int __stdcall GAME_Shutdown()
{
    CLIENTS_Release();
    DeleteCriticalSection(&gGameListLock);
    SUNITPROXY_ClearGlobalItemCache();
    gwGameId = 1;
    gpGameDataTbl = 0;
    gnAct = 0;
    return 1;
}

#include "gen/data/Source/D2Game/Unknown_0052C030.inc"
