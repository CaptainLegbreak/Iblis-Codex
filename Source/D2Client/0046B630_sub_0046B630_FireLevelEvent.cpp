struct D2UnitStrc;
struct D2ActiveRoomStrc;

typedef void (__cdecl* LEVELEVENT_Fn)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl sub_00410A80_GetTime();                                                                         // 0x00410A80
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620
void __stdcall sub_004DA000(D2UnitStrc* pUnit);                                                             // 0x004DA000
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom);                                     // 0x0046BF30

extern LEVELEVENT_Fn gpfnLevelEvents_007129D8[];                                                            // 0x007129D8
unsigned int gdwLevelEventBits_007A7458;                                                                    // 0x007A7458
int gnTimerEnd_007A7464;                                                                                    // 0x007A7464

// 0x0046B630
void __fastcall sub_0046B630_FireLevelEvent(int nIndex)
{
    D2_ASSERT(nIndex < 0x20, 0x1D9);
    D2_ASSERT(nIndex < 0x14, 0x1DA);
    gdwLevelEventBits_007A7458 |= 1 << nIndex;
    if (gpfnLevelEvents_007129D8[nIndex])
    {
        gpfnLevelEvents_007129D8[nIndex]();
    }
}

// 0x0046BFD0
void __fastcall sub_0046BFD0_StartTimer(int nDelay)
{
    if (nDelay > 0 && gnTimerEnd_007A7464 == 0)
    {
        gnTimerEnd_007A7464 = sub_00410A80_GetTime() + nDelay;
    }
}

// 0x0046BFF0
void __fastcall sub_0046BFF0_UnitEventMissile271(D2UnitStrc* pUnit)
{
    D2UnitStrc* pMissile = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pUnit), 3, 0x271);
    if (!pMissile)
    {
        return;
    }

    sub_004DA000(pUnit);
    sub_004DA1D0_SetMotionVectorA(pUnit, 0, 0, 0x12C);
    sub_004DA200_SetMotionVectorB(pUnit, 0, 0, -2, 1);
    sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 5, 0);
    sub_004DA6E0_SetMotionFlag20(pUnit, 0);
    MISSILE_SetTargetY(pMissile, 1);
    sub_0046BF30_CheckThroneLevel(sub_004646A0_GetPlayerRoom());
}

#include "gen/data/Source/D2Client/0046B630_sub_0046B630_FireLevelEvent.inc"
