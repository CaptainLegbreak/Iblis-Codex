struct D2InventoryStrc;
struct D2ItemDataStrc
{
    int quality;
    unsigned char pad04[0x32];
    unsigned short autoAffix;
    unsigned short prefix[3];
    unsigned short suffix[3];
};
struct D2UnitStrc
{
    unsigned int type;
    int classId;
    unsigned char pad08[12];
    D2ItemDataStrc* itemData;
    unsigned char pad18[0x48];
    D2InventoryStrc* inventory;
};
struct D2MagicAffixTxt
{
    unsigned char pad00[0x65];
    unsigned char levelReq;
    unsigned char pad66;
    unsigned char characterClass;
    unsigned char classLevelReq;
};
struct D2UniqueItemsTxt { unsigned char pad00[0x36]; short levelReq; };
struct D2SetItemsTxt { unsigned char pad00[0x32]; short levelReq; };
struct D2ItemsTxt { unsigned char pad00[0x13F]; unsigned char levelReq; };
struct D2StatStrc { unsigned short layer; unsigned short stat; int value; };
struct D2SkillsTxt
{
    unsigned char pad00[12];
    signed char characterClass;
    unsigned char pad0D[0x167];
    short requiredLevel;
    unsigned char pad176[0xC6];
};
struct D2DataTablesStrc
{
    unsigned char pad00[0xB98];
    D2SkillsTxt* skills;
    int unknownB9C;
    int skillCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc*, int); // 0x00627EC0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc*, int); // 0x00627F80
unsigned short __stdcall sub_00627F20_GetAutoAffix(D2UnitStrc*); // 0x00627F20
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int); // 0x00633EE0
int __stdcall DATATBLS_GetMaxLevel(int); // 0x00611830
int __stdcall ITEMS_GetFileIndex(D2UnitStrc*); // 0x00629DA0
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int); // 0x00483470
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc*, unsigned int); // 0x00463720
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int); // 0x00483440
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc*); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc*); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc*); // 0x0063DFA0
int __stdcall STATLIST_CopyStats(D2UnitStrc*, int, D2StatStrc*, int); // 0x006261D0
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc*); // 0x00451F60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
// build: context sub_00623C60
static __forceinline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->classId;
    }
    return -1;
}

static __declspec(noinline) int __fastcall sub_00628830_ApplyClassMinimum(D2MagicAffixTxt*, D2UnitStrc*, int);

// 0x00628830
static int __fastcall sub_00628830_ApplyClassMinimum(D2MagicAffixTxt* record, D2UnitStrc* player, int required)
{
    if (!record)
        return required;
    if (record->characterClass != 255 && player && record->characterClass == sub_00623C60(player))
    {
        if (required <= record->classLevelReq)
            required = record->classLevelReq;
    }
    else
    {
        if (required <= record->levelReq)
            required = record->levelReq;
    }
    return required;
}

// build: context sub_00628830_Shim

// calling-convention shim (not game code)
int __fastcall sub_00628830_Shim(D2UnitStrc* item, D2UnitStrc* player)
{
    D2MagicAffixTxt* prefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(item, 0));
    D2MagicAffixTxt* suffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(item, 0));
    D2MagicAffixTxt* automatic = DATATBLS_GetMagicAffixTxtRecord(sub_00627F20_GetAutoAffix(item));
    int required = sub_00628830_ApplyClassMinimum(prefix, player, 0);
    required = sub_00628830_ApplyClassMinimum(suffix, player, required);
    required = sub_00628830_ApplyClassMinimum(automatic, player, required);
    return required;
}
