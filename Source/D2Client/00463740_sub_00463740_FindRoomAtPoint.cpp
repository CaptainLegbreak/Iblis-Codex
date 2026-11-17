struct D2ActiveRoomStrc { char unknown0[76]; int x, y, width, height; };
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*, D2ActiveRoomStrc***, int*); // 0x00619790
// 0x00463740
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* room, int x, int y)
{
    if (!room) return 0;
    if (x >= room->x && x < room->x + room->width && y >= room->y && y < room->y + room->height) return room;
    D2ActiveRoomStrc** adjacent = 0;
    int count = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(room, &adjacent, &count);
    for (unsigned int i = 0; i < (unsigned int)count; ++i) {
        if (adjacent[i] && x >= adjacent[i]->x && x < adjacent[i]->x + adjacent[i]->width
            && y >= adjacent[i]->y && y < adjacent[i]->y + adjacent[i]->height)
            return adjacent[i];
    }
    return 0;
}
