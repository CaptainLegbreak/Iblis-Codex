struct D2InventoryStrc;
struct D2UnitStrc { int type, classId; char unknown8[88]; D2InventoryStrc* inventory; };
struct D2MonStats2Txt { char unknown0[14]; unsigned char meleeRange; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc*, D2UnitStrc**, int*, int*); // 0x0063C9B0
unsigned char __stdcall ITEMS_GetMeleeRange(D2UnitStrc*); // 0x006288D0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380
// 0x00622870
int __stdcall sub_00622870_GetMeleeRange(D2UnitStrc* unit)
{
    if (!unit) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x11be); exit(-1); }
    int range;
    switch (unit->type) {
    case 1: {
        D2MonStats2Txt* record = UNITS_GetMonStats2TxtRecordFromMonsterId(unit->classId);
        if (!record) goto fail;
        range = record->meleeRange;
        if (range == 255) {
            int weaponClass;
            COMPOSIT_GetWeaponClassId(unit, unit->inventory, &weaponClass, -1, 1);
            return weaponClass == 6 ? 2 : 0;
        }
        break;
    }
    case 0: {
        D2UnitStrc* weapon;
        int type, flags;
        if (!INVENTORY_GetEquippedWeapon(unit->inventory, &weapon, &type, &flags)) {
fail:
            return 0;
        }
        range = ITEMS_GetMeleeRange(weapon);
        break;
    }
    default:
        goto fail;
    }
    return range;
}
