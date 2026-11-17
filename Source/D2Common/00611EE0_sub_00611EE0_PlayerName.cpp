typedef unsigned short Unicode;
struct PlayerRecord
{
    char pad0[32];
    char name[164];
};
struct MonsterRecord
{
    char pad0[6];
    unsigned short nameIndex;
    char padTail[416];
};
struct ItemRecord
{
    char pad0[244];
    unsigned short nameIndex;
};
struct ObjectRecord
{
    char name[1];
};
struct DataTables
{
    char pad0[2680];
    MonsterRecord* monsters;
    char padMonsterCount[4];
    int monsterCount;
    char padPlayers[320];
    PlayerRecord* players;
    int playerCount;
};
struct UnitHeader
{
    unsigned int type;
    int classId;
};

extern DataTables* gVar_00744304; // 0x00744304
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int); // 0x00687330
extern "C" int __cdecl _snprintf(char*, unsigned int, const char*, ...); // 0x006831DB
extern "C" char* __cdecl sub_006883F8_Copy(char*, const char*); // 0x006883F8
const Unicode* __fastcall sub_00524A30_String(unsigned short); // 0x00524A30
char* __fastcall sub_00526F70_Narrow(char*, const Unicode*, int); // 0x00526F70
ObjectRecord* __stdcall sub_00640E90_Object(int); // 0x00640E90
ItemRecord* __stdcall sub_006335F0_Item(int); // 0x006335F0

// 0x00611EE0
static __declspec(noinline) void sub_00611EE0_PlayerName(char* buffer, int length, int id)
{
    if (length <= 0) return;
    if (id >= 0 && id < gVar_00744304->playerCount)
    {
        PlayerRecord* record = &gVar_00744304->players[id];
        if (record && record->name[0])
        {
            strncpy(buffer, record->name, length);
            buffer[length - 1] = 0;
            return;
        }
    }
    _snprintf(buffer, length, "player %d", id);
    buffer[length - 1] = 0;
}

// 0x00611F40
static __declspec(noinline) void sub_00611F40_MonsterName(char* buffer, int length, int id)
{
    if (length <= 0) return;
    if (id >= 0 && id < gVar_00744304->monsterCount)
    {
        MonsterRecord* record = &gVar_00744304->monsters[id];
        if (record && record->nameIndex != 0x1506)
        {
            const Unicode* name = sub_00524A30_String(record->nameIndex);
            sub_00526F70_Narrow(buffer, name, length);
            return;
        }
    }
    _snprintf(buffer, length, "monster %d", id);
    buffer[length - 1] = 0;
}

// 0x00611FA0
static __declspec(noinline) void sub_00611FA0_CopyObjectLabel(char* buffer, int length, int id)
{
    if (length <= 0) return;
    ObjectRecord* record = sub_00640E90_Object(id);
    if (record && record->name[0])
    {
        strncpy(buffer, record->name, length);
        buffer[length - 1] = 0;
        return;
    }
    _snprintf(buffer, length, "object %d", id);
    buffer[length - 1] = 0;
}

// 0x00611FE0
static __declspec(noinline) void sub_00611FE0_ItemName(char* buffer, int length, int id)
{
    ItemRecord* record = sub_006335F0_Item(id);
    if (record && record->nameIndex != 0x1506)
    {
        const Unicode* name = sub_00524A30_String(record->nameIndex);
            sub_00526F70_Narrow(buffer, name, length);
        return;
    }
    if (length > 0)
    {
        _snprintf(buffer, length, "item %d", id);
        buffer[length - 1] = 0;
    }
}

// 0x00612030
static __declspec(noinline) void sub_00612030_MissileName(char* buffer, int length, int id)
{
    if (length > 0)
    {
        _snprintf(buffer, length, "missile %d", id);
        buffer[length - 1] = 0;
    }
}

// 0x00612050
char* __stdcall sub_00612050_UnitName(UnitHeader* unit, char* buffer, int length)
{
    buffer[0] = 0;
    if (!unit)
    {
        sub_006883F8_Copy(buffer, "NULL Unit");
        return buffer;
    }
    switch (unit->type)
    {
    case 0: sub_00611EE0_PlayerName(buffer, length, unit->classId); break;
    case 1: sub_00611F40_MonsterName(buffer, length, unit->classId); break;
    case 2: sub_00611FA0_CopyObjectLabel(buffer, length, unit->classId); break;
    case 3: sub_00612030_MissileName(buffer, length, unit->classId); break;
    case 4: sub_00611FE0_ItemName(buffer, length, unit->classId); break;
    default: sub_006883F8_Copy(buffer, "Invalid Unit"); break;
    }
    return buffer;
}

// 0x00612120
char* __stdcall sub_00612120_TypedName(unsigned int type, short id, char* buffer, int length)
{
    buffer[0] = 0;
    switch (type)
    {
    case 0: sub_00611EE0_PlayerName(buffer, length, id); break;
    case 1: sub_00611F40_MonsterName(buffer, length, id); break;
    case 2: sub_00611FA0_CopyObjectLabel(buffer, length, id); break;
    case 3:
        if (length > 0)
        {
            _snprintf(buffer, length, "missile %d", id);
            buffer[length - 1] = 0;
        }
        break;
    case 4: sub_00611FE0_ItemName(buffer, length, id); break;
    default: sub_006883F8_Copy(buffer, "Invalid Unit Type"); break;
    }
    return buffer;
}
