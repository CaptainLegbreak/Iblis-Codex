#include "gen/data/Source/D2Game/GAME/Game_0052C170.inc"
#include "D2GameTypes.h"

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* lpCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* lpCriticalSection); // 0x006CC214

typedef void* HGAMEDATA;

extern unsigned short gwGameId;                                                                    // 0x00731000
extern char gGameListLock[];                                                                    // 0x00882D18
extern HGAMEDATA hGameArray_6FD447F8[1024];                                                                 // 0x00882D38

// 0x0052C170
unsigned short __fastcall sub_0052C170_ReserveGameId()
{
    EnterCriticalSection((_RTL_CRITICAL_SECTION*)gGameListLock);

    const unsigned short nBaseId = gwGameId;
    int nGameId = gwGameId++;
    if (gwGameId > 1024u)
    {
        gwGameId = 1;
    }

    if (hGameArray_6FD447F8[(unsigned short)nGameId - 1])
    {
        while (1)
        {
            nGameId = gwGameId++;
            if (gwGameId > 1024u)
            {
                gwGameId = 1;
            }

            if ((unsigned short)nGameId == (unsigned short)nBaseId)
            {
                LeaveCriticalSection((_RTL_CRITICAL_SECTION*)gGameListLock);
                return 0;
            }

            if (!hGameArray_6FD447F8[(unsigned short)nGameId - 1])
            {
                break;
            }
        }
    }

    hGameArray_6FD447F8[(unsigned short)nGameId - 1] = (HGAMEDATA)-1;
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)gGameListLock);
    return nGameId;
}


struct D2GameDataTableStrc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void __fastcall CLIENTS_Release();                                                                          // 0x00537730

void __fastcall SUNITPROXY_ClearGlobalItemCache();                                                          // 0x00537120

extern D2GameDataTableStrc* gpGameDataTbl;                                                         // 0x00883D38

extern int gnAct;                                                                                  // 0x00883D44

// 0x0052C030
int __stdcall GAME_Shutdown()
{
    CLIENTS_Release();
    DeleteCriticalSection((D2CriticalSectionStrc *)(&gGameListLock));
    SUNITPROXY_ClearGlobalItemCache();
    gwGameId = 1;
    gpGameDataTbl = 0;
    gnAct = 0;
    return 1;
}
