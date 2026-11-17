extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_MISSILE = 3,
    UNIT_INVALID = 6,
};

enum
{
    INVPAGE_EQUIP = 1,
    INVPAGE_TRADE = 2,
    INVPAGE_CUBE = 3,
    INVPAGE_STASH = 4,
};

enum
{
    INVENTORYRECORD_MONSTER = 5,
    INVENTORYRECORD_TRADE_PAGE_1 = 6,
    INVENTORYRECORD_TRADE_PAGE_2 = 7,
    INVENTORYRECORD_BANK_PAGE_1 = 8,
    INVENTORYRECORD_TRANSMOGRIFY_BOX_PAGE_1 = 9,
    INVENTORYRECORD_GUILD_VAULT_PAGE_1 = 10,
    INVENTORYRECORD_TROPHY_CASE_PAGE_1 = 11,
    INVENTORYRECORD_BIG_BANK_PAGE_1 = 12,
};

enum
{
    OBJECT_GUILD_VAULT = 338,
    OBJECT_TROPHY_CASE = 339,
};

enum
{
    PLRMODE_WALK = 2,
    PLRMODE_RUN = 3,
    PLRMODE_TOWNWALK = 6,
};

enum
{
    MONMODE_WALK = 2,
    MONMODE_SKILL1 = 8,
    MONMODE_SKILL2 = 9,
    MONMODE_RUN = 15,
};

enum
{
    MONSTER_VULTURE1 = 110,
    MONSTER_DIABLO = 243,
    MONSTER_DOOMKNIGHT1 = 310,
    MONSTER_DIABLOCLONE = 333,
    MONSTER_ACT3HIRE = 359,
};

enum
{
    MONSTER_TENTACLE1 = 258,
    MONSTER_TENTACLEHEAD1 = 261,
};

enum
{
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};

enum
{
    COMPOSIT_RIGHTHAND = 7,
};

enum
{
    ITEMTYPE_SHIELD = 2,
};

struct D2MonsterDataStrc
{
    int unk0x00;
    unsigned char nComponent[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

struct D2ItemsTxt
{
    char unk0x000[0x11E];
    unsigned short wType[2];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA80];
    int nMonStatsTxtRecordCount;
};

struct D2InventoryRecordMapStrc
{
    int nClassId;
    int nRecord;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2InventoryRecordMapStrc gInventoryRecordMap_00744544[];                                             // 0x00744544
extern unsigned int gnInventoryRecordMapCount_0074457C;                                                     // 0x0074457C
extern unsigned int gdwNoBlockItemCodes_00744580[];                                                         // 0x00744580
extern unsigned int gnNoBlockItemCodeCount_00744584;                                                        // 0x00744584

unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent);  // 0x00664860
D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640
unsigned int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                           // 0x00621190
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
int __fastcall MONSTERS_GetBaseIdFromMonsterId(int nMonsterId);                                             // 0x00463900
int __stdcall D2Common_10399(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x00641530
int __stdcall UNITS_GetMeleeRange(D2UnitStrc* pUnit);                                                       // 0x00622870
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0

// 0x00621050
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD)
{
    D2_ASSERT(pUnit, 2607);

    int nRet = -1;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        switch ((unsigned char)nInvPage)
        {
        case INVPAGE_EQUIP:
            return INVENTORYRECORD_TRADE_PAGE_1;

        case INVPAGE_TRADE:
            return INVENTORYRECORD_TRADE_PAGE_2;

        case INVPAGE_STASH:
            return bLoD != 0 ? INVENTORYRECORD_BIG_BANK_PAGE_1 : INVENTORYRECORD_BANK_PAGE_1;

        case INVPAGE_CUBE:
            return INVENTORYRECORD_TRANSMOGRIFY_BOX_PAGE_1;

        default:
        {
            const int nClassId = pUnit->dwClassId;
            for (unsigned int i = 0; i < gnInventoryRecordMapCount_0074457C; ++i)
            {
                if (nClassId == gInventoryRecordMap_00744544[i].nClassId)
                {
                    nRet = gInventoryRecordMap_00744544[i].nRecord;
                    break;
                }
            }
            break;
        }
        }
        break;

    case UNIT_MONSTER:
        return INVENTORYRECORD_MONSTER;

    case UNIT_OBJECT:
        switch (pUnit->dwClassId)
        {
        case OBJECT_GUILD_VAULT:
            return INVENTORYRECORD_GUILD_VAULT_PAGE_1;

        case OBJECT_TROPHY_CASE:
            return INVENTORYRECORD_TROPHY_CASE_PAGE_1;

        default:
            return -1;
        }
    }

    return nRet;
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

inline unsigned char MONSTERS_GetComponentInline(D2UnitStrc* pUnit, int nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[nComponent];
    }
    return 0;
}

// 0x006225F0
int __fastcall sub_006225F0_MonsterCanBlock(D2UnitStrc* pUnit)
{
    switch (MONSTERS_ValidateMonsterIdInline(UNITS_GetClassIdInline(pUnit)))
    {
    case MONSTER_DIABLO:
    case MONSTER_DOOMKNIGHT1:
    case MONSTER_DIABLOCLONE:
        return 1;

    case MONSTER_ACT3HIRE:
        return 0;

    default:
        break;
    }

    const unsigned int dwCode = D2Common_11069(pUnit, COMPOSIT_RIGHTHAND, MONSTERS_GetComponentInline(pUnit, COMPOSIT_RIGHTHAND));
    if (!dwCode)
    {
        return 0;
    }

    for (unsigned int i = 0; i < gnNoBlockItemCodeCount_00744584; ++i)
    {
        if (dwCode == gdwNoBlockItemCodes_00744580[i])
        {
            return 0;
        }
    }

    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    if (pItemsTxtRecord && pItemsTxtRecord->wType[0] == ITEMTYPE_SHIELD)
    {
        return 1;
    }

    return 0;
}

// 0x00622C40
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus)
{
    if (pUnit2 && pUnit1)
    {
        const int nType = pUnit2 ? pUnit2->dwUnitType : UNIT_INVALID;
        if (nType == UNIT_MONSTER)
        {
            switch (MONSTERS_ValidateMonsterIdInline(sub_00463860(pUnit2)))
            {
            case MONSTER_TENTACLE1:
            case MONSTER_TENTACLEHEAD1:
            {
                const int nDistance = D2Common_10399(pUnit1, pUnit2);
                if (UNITS_GetMeleeRange(pUnit1) + 8 > nDistance)
                {
                    return 1;
                }
                break;
            }
            }
        }

        const int nRange = UNITS_GetMeleeRange(pUnit1) + nRangeBonus + 1;
        const int nDistance = D2Common_10399(pUnit1, pUnit2);
        if (nDistance > 0 && nRange < nDistance)
        {
            return 0;
        }

        if (nDistance <= 0)
        {
            return 1;
        }

        return UNITS_TestCollisionWithUnit(pUnit1, pUnit2, COLLIDE_MASK_PLAYER_FLYING) == 0;
    }

    return 0;
}

inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

// 0x00622D00
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        switch (UNITS_GetAnimOrSeqMode(pUnit))
        {
        case PLRMODE_WALK:
        case PLRMODE_RUN:
        case PLRMODE_TOWNWALK:
            return 1;

        default:
            return 0;
        }

    case UNIT_MONSTER:
        switch (UNITS_GetAnimModeInline(pUnit))
        {
        case MONMODE_WALK:
        case MONMODE_RUN:
            return 1;

        case MONMODE_SKILL1:
        case MONMODE_SKILL2:
            return MONSTERS_GetBaseIdFromMonsterId(sub_00463860(pUnit)) == MONSTER_VULTURE1;

        default:
            return 0;
        }

    case UNIT_MISSILE:
        D2_ASSERT(pUnit->dwUnitType != UNIT_MISSILE, 4901);
        return 0;

    default:
        return 0;
    }
}

#include "gen/data/Source/D2Common/00621050_UNITS_GetInventoryRecordId.inc"
