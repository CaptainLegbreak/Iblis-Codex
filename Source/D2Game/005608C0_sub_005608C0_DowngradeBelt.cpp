typedef unsigned char U8;
typedef unsigned int U32;

struct Point
{
    int x;
    int y;
};
struct StaticPath
{
    U8 pad00[12];
    int x;
    int y;
};
struct Unit
{
    int type;
    int classId;
    U8 pad08[4];
    int id;
    int mode;
    U8 pad14[24];
    StaticPath* path;
    U8 pad30[48];
    void* inventory;
    U8 pad64[96];
    U32 flags;
};
struct Game
{
    U8 pad00[112];
    int expansion;
};
struct ItemRecord
{
    U8 pad00[128];
    U32 code;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_0053D010_Notify(void*, Unit*, Unit*, U32); // 0x0053D010
Unit* __fastcall sub_00552F60_Find(Game*, int, int); // 0x00552F60
void* __fastcall sub_005531C0_Client(Unit*, const char*, int); // 0x005531C0
void* __fastcall sub_00555DA0_FreeSpot(void*, Point*, Point*, int, U8); // 0x00555DA0
void __fastcall sub_00558AA0_Drop(Game*, Unit*, Unit*, void*, int, int); // 0x00558AA0
void __fastcall sub_0055BF50_Check(Unit*, const char*, int); // 0x0055BF50
void __fastcall sub_0055C270_Update(Unit*, Unit*); // 0x0055C270
void __fastcall sub_0055C2C0_Apply(Game*, Unit*, Unit*, int); // 0x0055C2C0
void __fastcall sub_0055DBC0_Refresh(Game*, Unit*, int); // 0x0055DBC0
int __fastcall sub_0055F590_CheckItem(Unit*, const char*, int); // 0x0055F590
void __fastcall sub_00568770_Special(Game*, Unit*, Unit*); // 0x00568770
extern "C" void __stdcall sub_00620870_Position(Unit*, Point*); // 0x00620870
extern "C" void* __stdcall sub_00620BB0_Room(Unit*); // 0x00620BB0
extern "C" void __stdcall sub_00621000_SetFlag(Unit*, int); // 0x00621000
extern "C" int __stdcall sub_00621050_Grid(Unit*, U8, int); // 0x00621050
extern "C" void __stdcall sub_00624690_Mode(Unit*, int); // 0x00624690
extern "C" int __stdcall sub_006280A0_TestFlag(Unit*, U32, int, const char*); // 0x006280A0
extern "C" void __stdcall sub_006280D0_SetFlag(Unit*, U32, int); // 0x006280D0
extern "C" void __stdcall sub_00628170_CommandFlag(Unit*, U32, int); // 0x00628170
extern "C" U8 __stdcall sub_00628250_Page(Unit*); // 0x00628250
extern "C" void __stdcall sub_00628280_SetPage(Unit*, U8); // 0x00628280
extern "C" void __stdcall sub_00628320_SavePage(Unit*, U8); // 0x00628320
extern "C" void __stdcall sub_006287B0_Flags(U32*, U32, int); // 0x006287B0
extern "C" int __stdcall sub_0062FF70_Check(Unit*, Unit*); // 0x0062FF70
extern "C" ItemRecord* __stdcall sub_006335F0_Record(int); // 0x006335F0
extern "C" Unit* __stdcall sub_0063AD90_Remove(void*, Unit*); // 0x0063AD90
extern "C" int __stdcall sub_0063B210_Add(void*, Unit*, int); // 0x0063B210
extern "C" Unit* __stdcall sub_0063B2C0_First(void*); // 0x0063B2C0
extern "C" int __stdcall sub_0063B950_Place(void*, Unit*, int, int, U8, const char*, int); // 0x0063B950
extern "C" void __stdcall sub_0063BCF0_Trace(const char*, int, void*, int, int, int, int, U8); // 0x0063BCF0
extern "C" void __stdcall sub_0063C180_Cursor(void*, Unit*); // 0x0063C180
extern "C" void __stdcall sub_0063CC70_Refresh(void*, Unit*); // 0x0063CC70
extern "C" Unit* __stdcall sub_0063DFA0_Next(Unit*); // 0x0063DFA0
extern "C" Unit* __stdcall sub_0063DFD0_Item(Unit*); // 0x0063DFD0
extern "C" int __stdcall sub_006488C0_X(StaticPath*); // 0x006488C0
extern "C" int __stdcall sub_00648900_Y(StaticPath*); // 0x00648900

struct BeltRect { int left, right, top, bottom; };
struct BeltRecord { char unknown00[4]; U8 nBoxes; U8 reserved5; unsigned short reserved6; BeltRect boxes[16]; };
extern "C" void __stdcall sub_00660CB0_Record(int, int, BeltRecord*); // 0x00660CB0
extern "C" int __stdcall UNITS_GetBeltType(Unit*); // 0x00621ED0
extern "C" Unit* __stdcall sub_0063C7F0_Belt(void*, int); // 0x0063C7F0
extern "C" void __stdcall sub_0063C550_Return(void*, int); // 0x0063C550
void __fastcall sub_0053EED0_RemoveBelt(void*, Unit*, Unit*, U32); // 0x0053EED0
void __fastcall sub_0055C6E0_OnItemToCursor(Unit*, Unit*); // 0x0055C6E0
void __fastcall sub_0055C730_UpdateProperties(Game*, Unit*, Unit*, int, int); // 0x0055C730

static __forceinline int PlaceIntoInventory(Game* game, Unit* player, int itemId, int line)
{
        if (!game) return 0;
        {
            sub_0055BF50_Check(player, ".\\ITEMS\\ItemMode.cpp", 0x87B);
            Unit* placed = sub_00552F60_Find(game, 4, itemId);
            if (!placed || placed->type != 4 || placed->mode != 4) return 0;
            {
                U8 targetPage = sub_00628250_Page(placed);
                void* targetInventory = player->inventory;
                if (!targetInventory) return 0;
                int special = 0;
                int clearCursor = 1;
                int targetGrid = sub_00621050_Grid(player, targetPage, game->expansion);
                if (player->type == 0) {
                    switch (targetPage) {
                    case 1: clearCursor = 0; break;
                    case 2: special = 1; break;
                    }
                }
                if (!sub_0063B950_Place(targetInventory, placed, targetGrid, 0, targetPage, ".\\ITEMS\\ItemMode.cpp", line)) return 0;
                if (!sub_0063B210_Add(targetInventory, placed, 1)) return 0;
                if (sub_00628250_Page(placed) != 4) sub_0055C270_Update(player, placed);
                placed->flags &= -3;
                if (sub_0062FF70_Check(placed, player)) sub_0055C2C0_Apply(game, placed, player, 0);
                if (clearCursor) sub_0063C180_Cursor(targetInventory, 0);
                sub_00624690_Mode(placed, 0);
                sub_00628170_CommandFlag(placed, 2, 1);
                if (sub_0055F590_CheckItem(placed, ".\\ITEMS\\ItemMode.cpp", 0x8EA)) sub_006280D0_SetFlag(placed, 1, 1);
                if (sub_006280A0_TestFlag(placed, 0x4000, 0x8EE, ".\\ITEMS\\ItemMode.cpp")) sub_006280D0_SetFlag(placed, 0x4000, 0);
                sub_00621000_SetFlag(player, 1);
                sub_0063CC70_Refresh(targetInventory, placed);
                if (special == 1) sub_00568770_Special(game, player, placed);
                if (sub_0062FF70_Check(placed, player)) {
                    sub_0055DBC0_Refresh(game, player, 0);
                    sub_00621000_SetFlag(player, 1);
                }
                return 1;
            }
        }
}

// 0x005608C0
void __fastcall sub_005608C0_DowngradeBelt(Game* game, Unit* player, Unit* belt)
{
    void* inventory = player->inventory;
    D2_ASSERT(inventory, 0xC0C);
    BeltRecord record;
    if (belt) sub_00660CB0_Record(UNITS_GetBeltType(belt), 0, &record);
    else sub_00660CB0_Record(2, 0, &record);
    for (int index = 0; index < 16; ++index) {
        Unit* item = sub_0063C7F0_Belt(inventory, index);
        if (index < record.nBoxes || !item) continue;
        U32 flags = 0;
        sub_006287B0_Flags(&flags, 32, 1);
        sub_0053EED0_RemoveBelt(sub_005531C0_Client(player, ".\\ITEMS\\ItemMode.cpp", 0xC1F), player, item, flags);
        Unit* removed = sub_0063AD90_Remove(inventory, item);
        D2_ASSERT(removed, 0xC22);
        D2_ASSERT(item == removed, 0xC23);
        int x;
        switch (item->type) {
        case 2: case 4: case 5: x = item->path->x; break;
        default: x = item->path ? sub_006488C0_X(item->path) : 0; break;
        }
        sub_0063C550_Return(inventory, x);
        sub_00624690_Mode(removed, 4);
        sub_0055C6E0_OnItemToCursor(player, item);
        sub_00628280_SetPage(item, 0);
        if (PlaceIntoInventory(game, player, item->id, 0xC29)) continue;
        {
            Point playerPosition;
            Point dropPosition;
            sub_00620870_Position(player, &playerPosition);
            void* room = sub_00555DA0_FreeSpot(sub_00620BB0_Room(player), &playerPosition, &dropPosition, 1, 1);
            if (room) {
                sub_0055C730_UpdateProperties(game, item, player, 0, 1);
                sub_00558AA0_Drop(game, player, item, room, dropPosition.x, dropPosition.y);
            }
        }
    }
}
