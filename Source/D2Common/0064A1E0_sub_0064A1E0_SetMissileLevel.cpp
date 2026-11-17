typedef unsigned char U8;
typedef unsigned short U16;
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct B24Roster
{
    U8 pad0[0x4];
    int value;
    unsigned int key;
    U8 padAfterKey[0x24];
    B24Roster* next;
};
typedef char B24RosterValue[(OFFSET(B24Roster,value)==0x4)?1:-1];
typedef char B24RosterKey[(OFFSET(B24Roster,key)==0x8)?1:-1];
typedef char B24RosterNext[(OFFSET(B24Roster,next)==0x30)?1:-1];
struct B24MissileData
{
    U8 pad0[0xC];
    short nLevel;
};
struct B24Unit
{
    unsigned int type;
    U8 pad4[0x10];
    B24MissileData* missileData;
};
typedef char B24MissileLevel[(OFFSET(B24MissileData,nLevel)==0xC)?1:-1];
typedef char B24UnitData[(OFFSET(B24Unit,missileData)==0x14)?1:-1];
extern "C" U8 gB24Selection;
extern "C" U8* gB24PackedState;
extern "C" int gB24Dirty;
extern "C" B24Roster* gB24Roster;
extern "C" int gB24MinX;
extern "C" int gB24MaxX;
extern "C" int gB24MinY;
extern "C" int gB24MaxY;
extern "C" int gB24RowCount;
extern "C" unsigned int gB24SelectedKey;
extern "C" U8 gB24Rows[];

extern "C" int __fastcall sub_00479180_FindRosterValue(unsigned int key)
{
    B24Roster* node = gB24Roster;
    while (node)
    {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return 0;
}

extern "C" int __cdecl sub_004B1D70_FindSelectedRow()
{
    int count = gB24RowCount;
    int index = 0;
    int found = 0;
    if (count > 0)
    {
        unsigned int key = gB24SelectedKey;
        const U8* row = gB24Rows;
        do
        {
            if (found)
                break;
            if (*(const unsigned int*)row == key)
                found = 1;
            else
            {
                index += 1;
                row += 0x16;
            }
        } while (index < count);
        if (found == 1)
            return index;
    }
    return 0;
}

// 0x0064A1E0
extern "C" void __stdcall sub_0064A1E0_SetMissileLevel(B24Unit* unit, int level)
{
    if (unit && unit->type == 3 && unit->missileData)
        unit->missileData->nLevel = (short)level;
}
