struct D2ActiveRoomStrc;
struct D2StatListStrc;

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x3A];
    unsigned int dwGameFrame;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent);                       // 0x005415A0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, int nPrefix, int nIndex);                              // 0x00627EF0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0

extern int gdwHealthPotionCodes_00731F4C[4];                                                                // 0x00731F4C
extern unsigned int gnHealthPotionCodes_00731F5C;                                                           // 0x00731F5C
extern int gdwManaPotionCodes_00731F60[4];                                                                  // 0x00731F60
extern unsigned int gnManaPotionCodes_00731F70;                                                             // 0x00731F70

#define DIFFMODE_NORMAL 0
#define UNIT_ITEM 4
#define EVENTTYPE_STATREGEN 3
#define STAT_ITEM_REPLENISH_DURABILITY 252
#define STAT_ITEM_REPLENISH_QUANTITY 253
#define IFLAG_RUNEWORD 0x4000000
#define STATE_RUNEWORD 171

// 0x00558450
int __fastcall ITEMS_GetHealthPotionDropCode(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 0xD5E);

    unsigned char nIndex = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (pGame && pGame->nDifficulty > DIFFMODE_NORMAL)
    {
        nIndex += 2;
    }

    if (nIndex >= gnHealthPotionCodes_00731F5C)
    {
        return gdwHealthPotionCodes_00731F4C[3];
    }

    return gdwHealthPotionCodes_00731F4C[nIndex];
}

// 0x005584C0
int __fastcall ITEMS_GetManaPotionDropCode(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 0xD7D);

    unsigned char nIndex = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (pGame && pGame->nDifficulty > DIFFMODE_NORMAL)
    {
        nIndex += 2;
    }

    if (nIndex >= gnManaPotionCodes_00731F70)
    {
        return gdwManaPotionCodes_00731F60[3];
    }

    return gdwManaPotionCodes_00731F60[nIndex];
}

// 0x00558530
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nReplenishDurability = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_REPLENISH_DURABILITY, 0);
    if (nReplenishDurability && !EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_STATREGEN))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, 2500 / nReplenishDurability + pGame->dwGameFrame + 1, 0, 0);
    }
}

// 0x00558580
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nReplenishQuantity = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_REPLENISH_QUANTITY, 0);
    if (nReplenishQuantity && !EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_STATREGEN))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, 2500 / nReplenishQuantity + pGame->dwGameFrame + 1, 0, 0);
    }
}

// 0x00558C50
void __fastcall ITEMS_DestroyRunewordStatList(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM || !(ITEMS_GetItemFlags(pItem) & IFLAG_RUNEWORD))
    {
        return;
    }

    ITEMS_SetItemFlag(pItem, IFLAG_RUNEWORD, 0);
    ITEMS_AssignPrefix(pItem, 0, 0);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, STATE_RUNEWORD, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
}

#include "gen/data/Source/D2Game/00558450_ITEMS_GetHealthPotionDropCode.inc"
