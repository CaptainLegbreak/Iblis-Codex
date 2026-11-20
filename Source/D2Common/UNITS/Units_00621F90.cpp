#include "D2Structs.h"
#include "D2UnitData.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
#pragma function(memset)

struct D2BitBufferStrc;
struct D2WaypointDataStrc;
struct D2RosterInfoStrc;



void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2RosterInfoStrc* __fastcall sub_004DC0B0_GetNextRosterInfo(D2RosterInfoStrc* pRosterInfo);
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30
D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool);                                         // 0x0065C430
D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool);                                  // 0x00660F30
void __stdcall sub_0066A250(int nUnused);

// 0x00621F90
void __stdcall UNITS_AllocPlayerData(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3919);
    D2_ASSERT(!ptUnit->pPlayerData, 3921);

    ptUnit->pPlayerData = (D2PlayerDataStrc*)FOG_AllocPool(ptUnit->pMemoryPool, sizeof(D2PlayerDataStrc), ".\\UNITS\\Units.cpp", 3922, 0);
    memset(ptUnit->pPlayerData, 0x00, sizeof(D2PlayerDataStrc));
    ptUnit->pPlayerData->szName[0] = 0;

    for (int i = 0; i < 3; ++i)
    {
        D2BitBufferStrc* const pQuestRecord = QUESTRECORD_AllocRecord(sub_004DC0B0_GetNextRosterInfo((D2RosterInfoStrc*)ptUnit));
        (*(D2PlayerDataStrc* volatile*)&ptUnit->pPlayerData)->pQuestData[i] = pQuestRecord;
        ptUnit->pPlayerData->pWaypointData[i] = WAYPOINTS_AllocWaypointData(sub_004DC0B0_GetNextRosterInfo((D2RosterInfoStrc*)ptUnit));
    }

    ptUnit->pPlayerData->nPortalFlags = DUNGEON_GetPortalFlagFromLevelId(1);
    ptUnit->pPlayerData->bBusy = 0;
    sub_0066A250((int)ptUnit);
}
