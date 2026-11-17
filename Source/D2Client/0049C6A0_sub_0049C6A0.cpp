struct D2WaypointDataStrc;

D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool);                                  // 0x00660F30
extern D2WaypointDataStrc* gpWaypointData_007BF081;                                                         // 0x007BF081
extern char gbGlobal_007BF085;                                                                              // 0x007BF085

// 0x0049C6A0
void __cdecl sub_0049C6A0()
{
    gpWaypointData_007BF081 = WAYPOINTS_AllocWaypointData(0);
    gbGlobal_007BF085 = 0;
}
