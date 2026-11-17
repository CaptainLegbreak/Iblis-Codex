enum NumericGroups
{
    N_m90 = -90,
    N_m48 = -48,
    N_m44 = -44,
    N_m40 = -40,
    N_m36 = -36,
    N_m32 = -32,
    N_m28 = -28,
    N_m24 = -24,
    N_m20 = -20,
    N_m16 = -16,
    N_m12 = -12,
    N_m8 = -8,
    N_m4 = -4,
    N_m1 = -1,
    N_0 = 0,
    N_1 = 1,
    N_2 = 2,
    N_3 = 3,
    N_4 = 4,
    N_5 = 5,
    N_6 = 6,
    N_7 = 7,
    N_8 = 8,
    N_9 = 9,
    N_10 = 10,
    N_11 = 11,
    N_12 = 12,
    N_16 = 16,
    N_17 = 17,
    N_18 = 18,
    N_20 = 20,
    N_21 = 21,
    N_22 = 22,
    N_23 = 23,
    N_24 = 24,
    N_25 = 25,
    N_28 = 28,
    N_31 = 31,
    N_32 = 32,
    N_36 = 36,
    N_40 = 40,
    N_44 = 44,
    N_48 = 48,
    N_49 = 49,
    N_50 = 50,
    N_51 = 51,
    N_52 = 52,
    N_53 = 53,
    N_54 = 54,
    N_55 = 55,
    N_56 = 56,
    N_57 = 57,
    N_58 = 58,
    N_59 = 59,
    N_60 = 60,
    N_62 = 62,
    N_64 = 64,
    N_68 = 68,
    N_72 = 72,
    N_76 = 76,
    N_80 = 80,
    N_84 = 84,
    N_88 = 88,
    N_92 = 92,
    N_96 = 96,
    N_100 = 100,
    N_101 = 101,
    N_103 = 103,
    N_104 = 104,
    N_106 = 106,
    N_108 = 108,
    N_112 = 112,
    N_116 = 116,
    N_120 = 120,
    N_121 = 121,
    N_122 = 122,
    N_124 = 124,
    N_127 = 127,
    N_128 = 128,
    N_141 = 141,
    N_159 = 159,
    N_160 = 160,
    N_228 = 228,
    N_255 = 255,
    N_256 = 256,
    N_301 = 301,
    N_302 = 302,
    N_303 = 303,
    N_315 = 315,
    N_316 = 316,
    N_317 = 317,
    N_326 = 326,
    N_329 = 329,
    N_330 = 330,
    N_331 = 331,
    N_332 = 332,
    N_337 = 337,
    N_404 = 404,
    N_420 = 420,
    N_421 = 421,
    N_476 = 476,
    N_512 = 512,
    N_1024 = 1024,
    N_2916 = 2916,
    N_2924 = 2924,
    N_1374389535 = 1374389535,
    N_1791398085 = 1791398085,
};

struct Unit
{
    int type;
    int classId;
    char padding_seedLow[N_32 - N_4 - sizeof(int)];
    unsigned int f_20;
    unsigned int f_24;
    char padding_inventory[N_96 - N_36 - sizeof(unsigned int)];
    void* inventory;
};

struct MissileRecord
{
    char padding_flags[N_5];
    unsigned char flags;
    char padding_element[N_228 - N_5 - sizeof(unsigned char)];
    unsigned char element;
    char padding_sourceDamage[N_301 - N_228 - sizeof(unsigned char)];
    unsigned char sourceDamage;
    unsigned char originDamage;
    unsigned char hitFlags;
    char padding_skill[N_404 - N_303 - sizeof(unsigned char)];
    short skill;
    char padding_tail[N_420 - N_404 - sizeof(short)];
};

struct SkillRecord
{
    char padding_sourceDamage[N_421];
    unsigned char sourceDamage;
    char padding_element[N_476 - N_421 - sizeof(unsigned char)];
    unsigned char element;
};

struct DataTables
{
    char padding_missiles[N_2916];
    MissileRecord* missiles;
    char padding_missileCount[N_2924 - N_2916 - sizeof(MissileRecord*)];
    int missileCount;
};

struct Damage
{
    int flags;
    int physicalMin;
    int physicalMax;
    int fireMin;
    int fireMax;
    int fireLength;
    int lightMin;
    int lightMax;
    int magicMin;
    int magicMax;
    int coldMin;
    int coldMax;
    int coldLength;
    int poisonMin;
    int poisonMax;
    int poisonLength;
    int poisonCount;
    int lifeMin;
    int lifeMax;
    int manaMin;
    int manaMax;
    int staminaMin;
    int staminaMax;
    int stunLength;
    int burnMin;
    int burnMax;
    int burnLength;
    int demonBonus;
    int undeadBonus;
    int armorReduction;
    int percent;
};

extern "C" int __stdcall sub_00625480_GetStat(Unit*, int, int); // 0x00625480
extern "C" int __stdcall sub_00625500_GetBaseStat(Unit*, int, int); // 0x00625500
extern "C" int __stdcall sub_00645830_GetItemBonus(Unit*, Unit*, int, int); // 0x00645830
extern "C" int __fastcall sub_00483360_Ratio(int, int, int); // 0x00483360
extern "C" SkillRecord* __fastcall sub_0045C4B0_GetSkillRecord(int); // 0x0045C4B0
extern "C" Unit* __stdcall sub_00622830_GetWeapon(Unit*); // 0x00622830
extern "C" void __stdcall sub_00622E90_EndWeapon(Unit*, int); // 0x00622E90
extern "C" Unit* __stdcall sub_00623990_GetWeaponSlot(Unit*, int); // 0x00623990
extern "C" void __stdcall sub_00623C80_BeginWeapon(Unit*, int); // 0x00623C80
extern "C" int __stdcall sub_006289C0_IsWeapon(Unit*); // 0x006289C0
extern "C" short __stdcall sub_00629860_GetStrengthFactor(Unit*); // 0x00629860
extern "C" short __stdcall sub_006298A0_GetDexterityFactor(Unit*); // 0x006298A0
extern "C" int __stdcall sub_00629BB0_IsItemType(Unit*, int); // 0x00629BB0
extern "C" int __stdcall sub_0062BA80_UsesThrowDamage(Unit*); // 0x0062BA80
extern "C" int __stdcall sub_0063D340_GetWeaponMode(Unit*, void*); // 0x0063D340
extern "C" int __stdcall sub_0063EE90_UsesDexterity(Unit*); // 0x0063EE90
extern "C" int __stdcall sub_00644D50_GetSkillElementMin(Unit*, int, int, int); // 0x00644D50
extern "C" int __stdcall sub_00644E40_GetSkillElementMax(Unit*, int, int, int); // 0x00644E40
extern "C" int __stdcall sub_00644F20_GetSkillElementLength(Unit*, int, int, int); // 0x00644F20
extern "C" int __stdcall sub_00647BC0_GetSkillPhysicalMin(Unit*, int, int, int); // 0x00647BC0
extern "C" int __stdcall sub_00647D00_GetSkillPhysicalMax(Unit*, int, int, int); // 0x00647D00
extern "C" int __stdcall sub_0064A280_GetMissileSkill(Unit*); // 0x0064A280
extern "C" int __stdcall sub_0064AF20_GetMissilePhysicalMin(Unit*, Unit*, int, int); // 0x0064AF20
extern "C" int __stdcall sub_0064AFF0_GetMissilePhysicalMax(Unit*, Unit*, int, int); // 0x0064AFF0
extern "C" int __stdcall sub_0064B100_GetMissileElementMin(Unit*, Unit*, int, int); // 0x0064B100
extern "C" int __stdcall sub_0064B1D0_GetMissileElementMax(Unit*, Unit*, int, int); // 0x0064B1D0
extern "C" int __stdcall sub_0064B2A0_GetMissileElementLength(Unit*, Unit*, int, int); // 0x0064B2A0
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" DataTables* gVar_00744304; // 0x00744304
extern "C" unsigned char gVar_006CE284; // 0x006CE284
extern "C" unsigned char gVar_006CE268; // 0x006CE268
extern "C" unsigned char gVar_006CE280; // 0x006CE280

static __forceinline unsigned int RollPercent(Unit* unit)
{
    unsigned __int64 next = (unsigned __int64)unit->f_24
        + (unsigned __int64)unit->f_20 * 1791398085u;
    unit->f_24 = (unsigned int)(next >> 32);
    unit->f_20 = (unsigned int)next;
    return (unsigned int)next % 100u;
}

// 0x0064A850
static __declspec(noinline) int __stdcall sub_0064A850_CheckCritical(Unit* item, Unit* unit)
{
    int chance = sub_00625480_GetStat(unit, 337, 0);
    if ((int)RollPercent(unit) < chance)
        return 1;
    chance = sub_00625500_GetBaseStat(unit, 141, 0);
    if (chance)
    {
        if ((int)RollPercent(unit) < chance)
            return 1;
    }
    if (item)
    {
        chance = sub_00645830_GetItemBonus(unit, item, 0, 2);
        if (chance)
        {
            if ((int)RollPercent(unit) < chance)
                return 1;
        }
    }
    return 0;
}

// 0x0064A930
static __declspec(noinline) void sub_0064A930_AddElements(int shift, Unit* unit, Damage* damage)
{
    damage->fireMin += sub_00625480_GetStat(unit, 48, 0) << shift;
    damage->fireMax += sub_00625480_GetStat(unit, 49, 0) << shift;
    damage->lightMin += sub_00625480_GetStat(unit, 50, 0) << shift;
    damage->lightMax += sub_00625480_GetStat(unit, 51, 0) << shift;
    damage->magicMin += sub_00625480_GetStat(unit, 52, 0) << shift;
    damage->magicMax += sub_00625480_GetStat(unit, 53, 0) << shift;
    damage->coldMin += sub_00625480_GetStat(unit, 54, 0) << shift;
    damage->coldMax += sub_00625480_GetStat(unit, 55, 0) << shift;
    damage->coldLength += sub_00625480_GetStat(unit, 56, 0);
    damage->poisonMin += sub_00625480_GetStat(unit, 57, 0);
    damage->poisonMax += sub_00625480_GetStat(unit, 58, 0);
    int length = sub_00625480_GetStat(unit, 101, 0);
    if (length > 0)
        damage->poisonLength += length;
    else
    {
        damage->poisonLength += sub_00625480_GetStat(unit, 59, 0);
        damage->poisonCount += sub_00625480_GetStat(unit, 326, 0);
    }
    damage->lifeMin += sub_00625480_GetStat(unit, 60, 0);
    damage->manaMin += sub_00625480_GetStat(unit, 62, 0);
    damage->burnMin += sub_00625480_GetStat(unit, 316, 0);
    damage->burnMax += sub_00625480_GetStat(unit, 317, 0);
    damage->burnLength += sub_00625480_GetStat(unit, 315, 0);
}

// 0x0064AA60
static __declspec(noinline) void sub_0064AA60_ScaleElements(int factor, Damage* damage)
{
    if (factor != 128)
    {
        damage->fireMin = damage->fireMin * factor / 128;
        damage->fireMax = damage->fireMax * factor / 128;
        damage->lightMin = damage->lightMin * factor / 128;
        damage->lightMax = damage->lightMax * factor / 128;
        damage->magicMin = damage->magicMin * factor / 128;
        damage->magicMax = damage->magicMax * factor / 128;
        damage->coldMin = damage->coldMin * factor / 128;
        damage->coldMax = damage->coldMax * factor / 128;
        damage->coldLength = damage->coldLength * factor / 128;
        damage->poisonMin = damage->poisonMin * factor / 128;
        damage->poisonMax = damage->poisonMax * factor / 128;
        damage->poisonCount = damage->poisonCount * factor / 128;
        damage->lifeMin = damage->lifeMin * factor / 128;
        damage->manaMin = damage->manaMin * factor / 128;
        damage->burnMin = damage->burnMin * factor / 128;
        damage->burnMax = damage->burnMax * factor / 128;
        damage->burnLength = damage->burnLength * factor / 128;
    }
}

static __declspec(noinline) int sub_0064ABA0_ElementBonus(int amount, int kind, Unit* unit)
{
    int bonus;
    switch (kind)
    {
    case 1:
        bonus = sub_00625480_GetStat(unit, 329, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    case 2:
        bonus = sub_00625480_GetStat(unit, 330, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    case 4:
    case 12:
        bonus = sub_00625480_GetStat(unit, 331, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    case 5:
        bonus = sub_00625480_GetStat(unit, 332, 0);
        if (bonus) return sub_00483360_Ratio(amount, bonus, 100);
        break;
    }
    return 0;
}

extern "C" void __stdcall sub_0064B860_BuildDamage(Damage* damage, Unit* owner, Unit* origin, Unit* missile, int level)
{
    memset(damage, 0, 124);
    if (!owner) return;
    if (!missile) return;
    if (missile->type != 3) return;
    int missileId = missile->classId;
    if (missileId < 0) return;
    if (missileId >= gVar_00744304->missileCount) return;
    MissileRecord* record = &gVar_00744304->missiles[missileId];
    if (!record) return;

    int sourceDamage, originDamage, element;
    int physicalMin, physicalMax, elementMin, elementMax, elementLength;
    if (record->skill > 0 || (record->flags & gVar_006CE284))
    {
        int skill = record->skill;
        if (record->flags & gVar_006CE284)
        {
            int missileSkill = sub_0064A280_GetMissileSkill(missile);
            if (missileSkill > 0) skill = missileSkill;
        }
        SkillRecord* skillRecord = sub_0045C4B0_GetSkillRecord(skill);
        if (!skillRecord) return;
        sourceDamage = skillRecord->sourceDamage;
        originDamage = 0;
        if (record->sourceDamage == 255) sourceDamage = 0;
        physicalMin = sub_00647BC0_GetSkillPhysicalMin(owner, skill, level, 0);
        physicalMax = sub_00647D00_GetSkillPhysicalMax(owner, skill, level, 0);
        element = skillRecord->element;
        elementMin = sub_00644D50_GetSkillElementMin(owner, skill, level, 1);
        elementMax = sub_00644E40_GetSkillElementMax(owner, skill, level, 1);
        elementLength = sub_00644F20_GetSkillElementLength(owner, skill, level, 1);
    }
    else
    {
        sourceDamage = record->sourceDamage;
        originDamage = record->originDamage;
        physicalMin = sub_0064AF20_GetMissilePhysicalMin(missile, owner, missileId, level);
        physicalMax = sub_0064AFF0_GetMissilePhysicalMax(missile, owner, missileId, level);
        element = record->element;
        elementMin = sub_0064B100_GetMissileElementMin(missile, owner, missileId, level);
        elementMax = sub_0064B1D0_GetMissileElementMax(missile, owner, missileId, level);
        elementLength = sub_0064B2A0_GetMissileElementLength(missile, owner, missileId, level);
        if (record->flags & gVar_006CE268)
        {
            elementMin += sub_0064ABA0_ElementBonus(elementMin, element, owner);
            elementMax += sub_0064ABA0_ElementBonus(elementMax, element, owner);
        }
    }
    if (record->hitFlags & 1) damage->flags |= 256;
    if (record->hitFlags & 2) damage->flags |= 512;
    if (record->hitFlags & 4) damage->flags |= 1024;

    int sourceMin = 0, sourceMax = 0, percent = 0;
    int itemBonus = 0, maximumPercent = 0;
    Unit* item = 0;
    if (sourceDamage)
    {
        damage->flags |= 1;
        if (owner->type == 0)
            item = sub_00623990_GetWeaponSlot(owner, 1);
        else if (owner->type == 1 && owner->inventory)
            item = sub_00622830_GetWeapon(owner);
        if (sub_0064A850_CheckCritical(item, owner)) damage->flags |= 2;
        itemBonus = 0;
        if (item && item->type == 4)
        {
            if ((record->flags & gVar_006CE280) && sub_006289C0_IsWeapon(item))
                sourceDamage /= 2;
            itemBonus = sub_00645830_GetItemBonus(owner, item, 0, 1);
            int strengthFactor = sub_00629860_GetStrengthFactor(item);
            if (strengthFactor)
                itemBonus += sub_00625480_GetStat(owner, 0, 0) * strengthFactor / 100;
            int dexterityFactor = sub_006298A0_GetDexterityFactor(item);
            if (dexterityFactor)
                itemBonus += sub_00625480_GetStat(owner, 2, 0) * dexterityFactor / 100;
            if (sub_0062BA80_UsesThrowDamage(item))
            {
                sourceMin = sub_00625480_GetStat(owner, 159, 0) << 8;
                sourceMax = sub_00625480_GetStat(owner, 160, 0) << 8;
            }
            else if (owner->inventory && sub_0063D340_GetWeaponMode(owner, owner->inventory) == 2)
            {
                sourceMin = sub_00625480_GetStat(owner, 23, 0) << 8;
                sourceMax = sub_00625480_GetStat(owner, 24, 0) << 8;
            }
            else
            {
                sourceMin = sub_00625480_GetStat(owner, 21, 0) << 8;
                sourceMax = sub_00625480_GetStat(owner, 22, 0) << 8;
            }
            if (sub_00629BB0_IsItemType(item, 57)) damage->undeadBonus += 50;
        }
        else
        {
            if (owner->type == 1 && sub_0063EE90_UsesDexterity(owner))
                percent = sub_00625480_GetStat(owner, 2, 0);
            sourceMin = sub_00625480_GetStat(owner, 21, 0) << 8;
            sourceMax = sub_00625480_GetStat(owner, 22, 0) << 8;
        }
        sourceMin = sourceMin * sourceDamage / 128;
        sourceMax = sourceMax * sourceDamage / 128;
        percent += sub_00625480_GetStat(owner, 25, 0) + itemBonus;
        itemBonus = sub_00625480_GetStat(owner, 18, 0);
        maximumPercent = sub_00625480_GetStat(owner, 17, 0);
        damage->demonBonus += sub_00625480_GetStat(owner, 121, 0);
        damage->undeadBonus += sub_00625480_GetStat(owner, 122, 0);
        damage->armorReduction += sub_00625480_GetStat(owner, 120, 0);
        if (sub_00625480_GetStat(owner, 103, 0)) damage->flags |= 256;
        if (sub_00625480_GetStat(owner, 104, 0)) damage->flags |= 512;
        if (sub_00625480_GetStat(owner, 106, 0)) damage->flags |= 1024;
    }
    else if (originDamage && origin)
    {
        if (sub_0064A850_CheckCritical(0, origin)) damage->flags |= 2;
        sourceMin = sub_00625480_GetStat(origin, 21, 0) * originDamage / 128;
        sourceMax = sub_00625480_GetStat(origin, 22, 0) * originDamage / 128;
        percent = sub_00625480_GetStat(origin, 25, 0);
        itemBonus = sub_00625480_GetStat(origin, 18, 0);
        maximumPercent = sub_00625480_GetStat(origin, 17, 0);
        damage->demonBonus += sub_00625480_GetStat(origin, 121, 0);
        damage->undeadBonus += sub_00625480_GetStat(origin, 122, 0);
        damage->armorReduction += sub_00625480_GetStat(origin, 120, 0);
    }
    percent += sub_00625480_GetStat(missile, 25, 0);
    if (itemBonus > maximumPercent) percent += itemBonus;
    else percent += maximumPercent;
    if (percent <= -90) percent = -90;
    damage->percent = percent;
    damage->physicalMin = sourceMin + physicalMin;
    damage->physicalMax = sourceMax + physicalMax;
    if (element)
    {
        switch (element)
        {
        case 1: damage->fireMin = elementMin; damage->fireMax = elementMax; damage->fireLength = elementLength; break;
        case 2: damage->lightMin = elementMin; damage->lightMax = elementMax; break;
        case 3: damage->magicMin = elementMin; damage->magicMax = elementMax; break;
        case 4: case 12: damage->coldMin = elementMin; damage->coldMax = elementMax; damage->coldLength = elementLength; break;
        case 5: damage->poisonMin = elementMin; damage->poisonMax = elementMax; damage->poisonLength = elementLength; break;
        case 6: damage->lifeMin = elementMin; damage->lifeMax = elementMax; break;
        case 7: damage->manaMin = elementMin; damage->manaMax = elementMax; break;
        case 8: damage->staminaMin = elementMin; damage->staminaMax = elementMax; break;
        case 9: damage->stunLength = elementLength; break;
        case 11: damage->burnMin = elementMin; damage->burnMax = elementMax; damage->burnLength = elementLength; break;
        }
    }
    if (sourceDamage)
    {
        sub_00623C80_BeginWeapon(owner, 1);
        sub_0064A930_AddElements(8, owner, damage);
        sub_0064AA60_ScaleElements(sourceDamage, damage);
        sub_00622E90_EndWeapon(owner, 1);
    }
    else if (originDamage && origin)
    {
        sub_0064A930_AddElements(0, origin, damage);
        sub_0064AA60_ScaleElements(originDamage, damage);
    }
}
