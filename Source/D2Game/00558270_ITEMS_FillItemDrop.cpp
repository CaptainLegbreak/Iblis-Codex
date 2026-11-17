struct D2DynamicPathStrc;
struct D2DrlgActStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};

struct D2ItemDataStrc
{
    char unk0x00[0x24];
    int dwActionStamp;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2ItemDataStrc* pItemData;
    char unk0x18[0x08];
    D2SeedStrc pSeed;
    unsigned int dwInitSeed;
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x94];
    unsigned int dwFlags;
    char unk0xC8[0x20];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
    char unk0x78[0x04];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
    char unk0xAC[0x10];
    D2DrlgActStrc* pAct[5];
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit;
    D2SeedStrc* pSeed;
    D2GameStrc* pGame;
    int nItemLvl;
    unsigned int unk0x10;
    int nId;
    int nSpawnType;
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom;
    unsigned short wUnitInitFlags;
    unsigned short wItemFormat;
    int bForce;
    int nQuality;
    int nQuantity;
    int nMinDur;
    int nMaxDur;
    int nItemIndex;
    unsigned int dwFlags1;
    unsigned int dwSeed;
    unsigned int dwItemSeed;
    unsigned char eEarLvl;
    char unk0x51[3];
    int nQtyOverride;
    char szName[16];
    int nPrefix[3];
    int nSuffix[3];
    unsigned int dwFlags2;
};

typedef void(__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);   // 0x00557FA0
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                    // 0x0061A180
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned int __stdcall ITEMS_GetItemStartSeed(D2UnitStrc* pItem);                                           // 0x00627DF0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem);                                                        // 0x006281E0
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem);                                                        // 0x00628340
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem);                                           // 0x006289F0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

#define UNIT_ITEM 4
#define ITEMTYPE_GOLD 4
#define ITEMTYPE_PLAYER_BODY_PART 7
#define STAT_GOLD 14
#define STAT_QUANTITY 70
#define STAT_DURABILITY 72
#define STAT_MAXDURABILITY 73
#define IFLAG_PERSONALIZED 0x1000000
#define UNITFLAG_TARGETABLE 2

__forceinline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00558270
void __fastcall ITEMS_FillItemDrop(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    memset(pItemDrop, 0, sizeof(D2ItemDropStrc));

    pItemDrop->pGame = pGame;
    pItemDrop->wItemFormat = ITEMS_GetItemFormat(pItem);
    pItemDrop->nItemLvl = ITEMS_GetItemLevel(pItem);
    if (pItemDrop->nItemLvl <= 0)
    {
        pItemDrop->nItemLvl = 1;
    }

    pItemDrop->nId = !pItem ? -1 : pItem->dwClassId;
    pItemDrop->nSpawnType = !pItem ? 0 : pItem->dwAnimMode;
    pItemDrop->nQuality = ITEMS_GetItemQuality(pItem);
    pItemDrop->nX = CLIENTS_GetUnitX(pItem);
    pItemDrop->nY = CLIENTS_GetUnitY(pItem);

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        pItemDrop->nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
    }
    else if (ITEMS_CheckIfStackable(pItem))
    {
        const int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);

        D2_ASSERT(nQuantity >= 0, 3241);

        pItemDrop->nQuantity = nQuantity;
    }

    pItemDrop->pSeed = &pItem->pSeed;
    pItemDrop->wUnitInitFlags = 1;
    pItemDrop->dwSeed = pItem->dwInitSeed;
    pItemDrop->dwItemSeed = ITEMS_GetItemStartSeed(pItem);
    pItemDrop->nItemIndex = ITEMS_GetFileIndex(pItem);
    pItemDrop->dwFlags1 = ITEMS_GetItemFlags(pItem);
    pItemDrop->nMinDur = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
    pItemDrop->nMaxDur = STATLIST_GetUnitBaseStat(pItem, STAT_MAXDURABILITY, 0);
    pItemDrop->nItemIndex = ITEMS_GetFileIndex(pItem);
    pItemDrop->bForce = 0;

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_PLAYER_BODY_PART)
    {
        strcpy(pItemDrop->szName, ITEMS_GetEarName(pItem));
        pItemDrop->eEarLvl = ITEMS_GetEarLevel(pItem);
    }
    else if (ITEMS_CheckItemFlag(pItem, IFLAG_PERSONALIZED, 3265, ".\\ITEMS\\Items.cpp"))
    {
        strcpy(pItemDrop->szName, ITEMS_GetEarName(pItem));
    }
}

// 0x00558B90
void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct)
{
    if (!pGame->pAct[nAct])
    {
        return;
    }

    const int nGameFrame = pGame->dwGameFrame;
    for (D2ActiveRoomStrc* i = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]); i; i = i->pRoomNext)
    {
        D2UnitStrc* pNext = i->pUnitFirst;
        while (pNext)
        {
            D2UnitStrc* pItem = pNext;
            pNext = pItem->pRoomNext;
            if (pItem->dwUnitType == UNIT_ITEM)
            {
                const int nDeletionFrame = pItem->pItemData->dwActionStamp;
                if (nDeletionFrame && nDeletionFrame <= nGameFrame)
                {
                    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                    if (pRoom)
                    {
                        DUNGEON_AllocDrlgDelete(pRoom, pItem->dwUnitType, pItem->dwUnitId);
                        UNITS_FreeCollisionPath(pItem);
                        UNITROOM_RemoveUnitFromRoom(pItem);
                    }

                    pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
                    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
                    SUNIT_RemoveUnit(pGame, pItem);
                }
            }
        }
    }
}
