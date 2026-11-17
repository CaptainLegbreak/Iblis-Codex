struct Room;
struct Tile;
struct Cell;
struct Context;

struct RoomCoordinates
{
    int x;
    int y;
    int width;
    int height;
    int tileX;
    int tileY;
    int tileWidth;
    int tileHeight;
};

struct Node
{
    int type;
    int x;
    int y;
    void* object;
    Node* next;
};

#define FIELD(T, p, off) (*(T*)((unsigned char*)(p) + (off)))

void __stdcall DUNGEON_GetRoomCoordinates(Room* pRoom, RoomCoordinates* pCoords);                           // 0x00619730
extern const unsigned int gVar_006CE274_Flags;                                                              // 0x006CE274

static __declspec(noinline) void __stdcall sub_004DD550_AddFloor(Cell* cell, Room* room, Context* context, Tile* tile);

// 0x004DD550
static void __stdcall sub_004DD550_AddFloor(Cell* cell, Room* room, Context* context, Tile* tile)
{
    unsigned int index = FIELD(unsigned int, context, 0xEA64)++;
    if (index >= 3000)
    {
        return;
    }
    Node* node = &FIELD(Node, context, 4) + index;
    node->type = 1;
    node->object = tile;
    node->next = 0;
    {
        RoomCoordinates coordinates;
        DUNGEON_GetRoomCoordinates(room, &coordinates);
        node->x = 8 * (coordinates.x + 5 * FIELD(int, tile, 8));
        node->y = 8 * (coordinates.y + 5 * FIELD(int, tile, 12));
    }
    FIELD(unsigned int, context, 0) |= gVar_006CE274_Flags;
    Node* last = FIELD(Node*, cell, 16);
    if (!last)
    {
        FIELD(Node*, cell, 16) = node;
        return;
    }
    while (last->next)
    {
        last = last->next;
    }
    last->next = node;
}

void __stdcall sub_004DD550_Emit(Room* room, Context* context, Tile* tile, unsigned int count, Cell* cells)
{
    for (unsigned int i = 0; i < count; ++i, tile = (Tile*)((unsigned char*)tile + 48))
    {
        sub_004DD550_AddFloor((Cell*)((unsigned char*)cells + 36 * i), room, context, tile);
    }
}
