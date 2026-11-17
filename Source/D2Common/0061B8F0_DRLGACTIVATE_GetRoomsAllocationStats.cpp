static int gStatsClientFreedRooms;                                                                          // 0x0096C8BC
static int gStatsClientAllocatedRooms;                                                                      // 0x0096C8B8
static int gStatsFreedRooms;                                                                                // 0x0096C8C0
static int gStatsAllocatedRooms;                                                                            // 0x0096C8C4

// 0x0061B8F0
void __fastcall DRLGACTIVATE_GetRoomsAllocationStats(int* pOutStatsClientAllocatedRooms, int* pOutStatsClientFreedRooms, int* pOutStatsAllocatedRooms, int* pOutStatsFreedRooms)
{
    *pOutStatsClientAllocatedRooms = gStatsClientAllocatedRooms;
    *pOutStatsClientFreedRooms = gStatsClientFreedRooms;
    *pOutStatsAllocatedRooms = gStatsAllocatedRooms;
    *pOutStatsFreedRooms = gStatsFreedRooms;
}
