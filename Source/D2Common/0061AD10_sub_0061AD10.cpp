struct RoomEx; struct Coord;

struct Room { char pad[0x10]; RoomEx* roomEx[2]; };
void __fastcall sub_00666A80(RoomEx*,Coord**,int*);  // 0x00666A80
enum { ROOM_SLOT = 0 };
// 0x0061AD10
void __stdcall sub_0061AD10(Room* room,Coord** tiles,int* count)
{
    sub_00666A80(room->roomEx[ROOM_SLOT],tiles,count);
}
