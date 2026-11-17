struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2WaypointDataStrc;

D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
void __stdcall WAYPOINTS_FreeWaypointData(void* pMemPool, D2WaypointDataStrc* pData);                       // 0x00660FD0
void __cdecl sub_0049C650_FreeWaypointCels();                                                               // 0x0049C650

extern int gnGlobal_007BF07D;                                                                               // 0x007BF07D
extern D2WaypointDataStrc* gpWaypointData_007BF081;                                                         // 0x007BF081
char gbGlobal_007BF085;                                                                                     // 0x007BF085

// 0x0049C6C0
void __cdecl sub_0049C6C0_SendWaypointClose()
{
    if (!gbGlobal_007BF085 && sub_00463DD0() && UNITS_GetRoom(sub_00463DD0()))
    {
        sub_004786A0_SendIntInt(0x49, gnGlobal_007BF07D, 0);
        gbGlobal_007BF085 = 1;
    }
}

// 0x0049C700
void __cdecl sub_0049C700_CloseWaypointPanel()
{
    sub_0049C6C0_SendWaypointClose();
    if (gpWaypointData_007BF081)
        WAYPOINTS_FreeWaypointData(0, gpWaypointData_007BF081);
    gpWaypointData_007BF081 = 0;
    sub_0049C650_FreeWaypointCels();
}

// 0x0049CF50
void __cdecl sub_0049CF50_SendWaypointClose()
{
    if (!gbGlobal_007BF085 && sub_00463DD0() && UNITS_GetRoom(sub_00463DD0()))
    {
        sub_004786A0_SendIntInt(0x49, gnGlobal_007BF07D, 0);
        gbGlobal_007BF085 = 1;
    }
}
