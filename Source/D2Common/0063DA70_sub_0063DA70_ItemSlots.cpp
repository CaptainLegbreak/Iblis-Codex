typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct Unit;
struct Inventory;
struct ItemRecord;
struct AppearanceRecord;
struct ItemData;
struct ItemLink;

#define FIELD(T, p, off) (*(T*)((u8*)(p) + (off)))

struct AppearanceSix
{
    u8 f_0;
    u8 f_1;
    u8 field2;
    u8 field3;
    u8 f_4;
    u8 field5;
};

struct CodeEntry
{
    u32 code;
    s32 type;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern CodeEntry gTable_0096CC68[]; // 0x0096CC68
void __cdecl sub_0063D710_InitCodes(); // 0x0063D710
s32 __fastcall sub_00451F60_ClassId(Unit*); // 0x00451F60
u8 __stdcall sub_00627D40_Page(Unit*); // 0x00627D40
u8 __stdcall sub_00628660_BodySlot(Unit*); // 0x00628660
s32 __stdcall sub_00629B50_IsType(s32, s32); // 0x00629B50
s32 __stdcall sub_0062C100_Transform(Unit*, Unit*, u8*, s32); // 0x0062C100
ItemRecord* __stdcall sub_006335F0_ItemRecord(s32); // 0x006335F0
ItemRecord* __stdcall sub_00633640_RecordByCode(u32, s32*); // 0x00633640
Unit* __stdcall sub_0063C050_BodyItem(Inventory*, s32); // 0x0063C050
u32 __stdcall sub_0064F380_WeaponCode(Unit*, Inventory*, s32*, s32, s32); // 0x0064F380
s32 __stdcall sub_0064F420_UsesAppearance(s32); // 0x0064F420
s32 __stdcall sub_0064F500_AppearanceIndex(s32, AppearanceSix*); // 0x0064F500
AppearanceRecord* __stdcall sub_0065B620_AppearanceRecord(s32); // 0x0065B620

// 0x0063D690
static __declspec(noinline) void __cdecl sub_0063D690_CopySix(AppearanceSix* output, Unit* item)
{
    if (item)
    {
        ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, item, 4));
        D2_ASSERT(record, 0x121E);
        output->f_0 = FIELD(u8, record, 0x116);
        output->f_1 = FIELD(u8, record, 0x117);
        output->field2 = FIELD(u8, record, 0x118);
        output->field3 = FIELD(u8, record, 0x119);
        output->f_4 = FIELD(u8, record, 0x11A);
        output->field5 = FIELD(u8, record, 0x11B);
    }
    else
    {
        memset(output, 0, sizeof(AppearanceSix));
    }
}

// 0x0063D900
static __declspec(noinline) s32 __cdecl sub_0063D900_FindCode(u32 second, u32 first)
{
    sub_0063D710_InitCodes();
    for (u32 index = 1; index < 0xFF; ++index)
    {
        const u32 code = gTable_0096CC68[index].code;
        if (code == first || code == second)
        {
            return index;
        }
    }
    return 0;
}

static __declspec(noinline) void __stdcall sub_0063D930_WeaponSlots(u8* firstOutput, u8* secondOutput, Unit* item, Unit* unit)
{
    D2_ASSERT(unit, 0x13B3);
    D2_ASSERT(item, 0x13B4);
    const u8 page = sub_00627D40_Page(item);
    if (page == 4 || page == 5)
    {
        Inventory* inventory = FIELD(Inventory*, unit, 0x60);
        s32 mode;
        const u32 weapon = sub_0064F380_WeaponCode(unit, inventory, &mode, -1, 1);
        const u8 slot = sub_00628660_BodySlot(item);
        if (weapon == 0x20776278)
        {
            if (slot == 5 || slot == 6)
            {
                if (inventory)
                {
                    Unit* equipped = sub_0063C050_BodyItem(inventory, 5);
                    if (equipped)
                    {
                        ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, equipped, 4));
                        D2_ASSERT(record, 0x13CF);
                        const s32 code = sub_0063D900_FindCode(FIELD(u32, record, 0x80), FIELD(u32, record, 0x90));
                        if (code <= 0)
                        {
                            firstOutput[6] = 0xFF;
                            secondOutput[6] = 0xFF;
                        }
                        else
                        {
                            firstOutput[6] = (u8)code;
                        }
                    }
                }
            }
        }
        else if (weapon == 0x20776F62)
        {
            if (slot == 6)
            {
                s32 recordIndex;
                ItemRecord* record = sub_00633640_RecordByCode(0x2074696C, &recordIndex);
                if (record)
                {
                    const s32 code = sub_0063D900_FindCode(FIELD(u32, record, 0x80), FIELD(u32, record, 0x90));
                    if (!code)
                    {
                        firstOutput[5] = 0xFF;
                        secondOutput[5] = 0xFF;
                    }
                    else
                    {
                        firstOutput[5] = (u8)code;
                    }
                }
            }
        }
    }
}

static __declspec(noinline) void __stdcall sub_0063DA70_ItemSlots(Unit* unit, u8* firstOutput, u8* secondOutput, Unit* item);

// 0x0063DA70
static void __stdcall sub_0063DA70_ItemSlots(Unit* unit, u8* firstOutput, u8* secondOutput, Unit* item)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (inventory)
    {
        Unit* firstHand = sub_0063C050_BodyItem(inventory, 5);
        Unit* secondHand = sub_0063C050_BodyItem(inventory, 6);
        ItemRecord* record = sub_006335F0_ItemRecord(!item ? -1 : FIELD(s32, item, 4));
        D2_ASSERT(record, 0x140C);
        u8 slot = sub_00628660_BodySlot(item);
        const u32 code1 = FIELD(u32, record, 0x80);
        const u32 code2 = FIELD(u32, record, 0x90);
        const s32 code = sub_0063D900_FindCode(code1, code2);
        if (!code)
        {
            if (slot < 0x10)
            {
                firstOutput[slot] = 0xFF;
                secondOutput[slot] = 0xFF;
            }
        }
        else
        {
            if (item == firstHand)
            {
                slot = 5;
            }
            else if (item == secondHand)
            {
                slot = 6;
            }
            else if (slot >= 0x10)
            {
                return;
            }
            firstOutput[slot] = (u8)code;
            sub_0063D930_WeaponSlots(firstOutput, secondOutput, item, unit);
            if (!sub_0062C100_Transform(unit, item, &secondOutput[slot], 0))
            {
                secondOutput[slot] = 0xFF;
            }
            else
            {
                ++secondOutput[slot];
            }
        }
    }
}

void __stdcall sub_0063E510_InventoryAppearance(Unit* unit, u8* firstOutput, u8* secondOutput)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (inventory && FIELD(u32, inventory, 0) == 0x01020304)
    {
        Unit* item = FIELD(Unit*, inventory, 0x0C);
        while (item)
        {
            if (FIELD(u32, item, 0) == 4 && FIELD(s32, item, 0x10) == 1)
            {
                ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, item, 4));
                D2_ASSERT(record, 0x1446);
                const u8 page = sub_00627D40_Page(item);
                if (page != 1 && page != 4 && page != 5)
                {
                    if (page == 3)
                    {
                        AppearanceSix appearance;
                        sub_0063D690_CopySix(&appearance, item);
                        for (u32 slot = 0; slot < 0x10; ++slot)
                        {
                            if (sub_0064F420_UsesAppearance(slot))
                            {
                                AppearanceRecord* appearanceRecord = sub_0065B620_AppearanceRecord(sub_0064F500_AppearanceIndex(slot, &appearance));
                                if (sub_00451F60_ClassId(item) > 0)
                                {
                                    const u32 appearanceCode = FIELD(u32, appearanceRecord, 0x20);
                                    const s32 code = sub_0063D900_FindCode(appearanceCode, appearanceCode);
                                    if (code)
                                    {
                                        if (slot < 0x10)
                                        {
                                            firstOutput[slot] = (u8)code;
                                            if (!sub_0062C100_Transform(unit, item, &secondOutput[slot], 0))
                                            {
                                                secondOutput[slot] = 0xFF;
                                            }
                                            else
                                            {
                                                ++secondOutput[slot];
                                            }
                                        }
                                        continue;
                                    }
                                }
                                if (slot < 0x10)
                                {
                                    firstOutput[slot] = 0xFF;
                                    secondOutput[slot] = 0xFF;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (!sub_00629B50_IsType(FIELD(short, record, 0x11E), 0x4B))
                    {
                        sub_0063DA70_ItemSlots(unit, firstOutput, secondOutput, item);
                    }
                }
            }
            if (FIELD(u32, item, 0) != 4)
            {
                break;
            }
            ItemData* data = FIELD(ItemData*, item, 0x14);
            if (!data)
            {
                break;
            }
            ItemLink* link = (ItemLink*)((u8*)data + 0x5C);
            if (!link)
            {
                break;
            }
            item = FIELD(Unit*, link, 8);
        }
    }
}
