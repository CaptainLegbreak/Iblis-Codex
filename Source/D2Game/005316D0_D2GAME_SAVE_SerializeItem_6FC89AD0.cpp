struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2InventoryStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    D2CoordStrc tGameCoords;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x4C];
    int bBusy;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2StaticPathStrc* pStaticPath;
        D2DynamicPathStrc* pDynamicPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
    char unk0xCC[0x18];
    D2UnitStrc* pListNext;
};

struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    unsigned char nClassId;
    char unk0x009[0x16B];
    D2UnitStrc* pPlayer;
};

struct D2GameStrc
{
    char unk0x00[0x1120];
    D2UnitStrc* pUnitList[5][128];
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
void __fastcall sub_00538410_RemoveUnitIfNotAdjacent2(D2ClientStrc* pClient, D2UnitStrc* pUnit);            // 0x00538410
void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x005394A0
void __fastcall sub_00539760(D2ClientStrc* pClient, D2GameStrc* pGame, int a3, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00539760
void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                     // 0x00554100
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
int __fastcall D2GAME_Return1_6FC41900(D2UnitStrc* pItem);                                                  // 0x00564CA0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* pUnit);                                                // 0x00620F50
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

extern const int dword_6FD307F8[];                                                                          // 0x00731AD8

#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define STATE_PLAYERBODY 7

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005316D0
int __stdcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nBitstreamSize, int a4, int a5, int a6)
{
    if (pItem)
    {
        const int bFlag = (pItem->dwFlagEx >> 15) & 1;
        if (!bFlag && (a4 != bFlag || a5 == bFlag || a6 != bFlag || D2GAME_Return1_6FC41900(pItem)))
        {
            const int nBits = ITEMS_SerializeItemToBitstream(pItem, pBitstream, nBitstreamSize, 1, 1, 0);
            D2_ASSERT(nBits, 1884);
            return nBits;
        }
    }
    return 0;
}

// 0x00535060
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        return 1;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
    {
        return 1;
    }

    return UNITS_GetPlayerData(pUnit)->bBusy;
}

// 0x0053A420
void __fastcall sub_0053A420_RebuildPlayerWithClass(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char nClassId)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    pClient->nClassId = nClassId;
    const int nX = CLIENTS_GetUnitXInline(pPlayer);
    const int nY = CLIENTS_GetUnitYInline(pPlayer);
    const int nUnitId = pPlayer->dwUnitId;
    const int nUnitType = pPlayer->dwUnitType;
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPlayer), nUnitType, nUnitId);
    SUNIT_RemoveUnit(pGame, pPlayer);
    sub_00539760(pClient, pGame, 0, pRoom, nX, nY);
    D2UnitStrc* pClientPlayer = pClient->pPlayer;
    sub_005394A0(pClient, pClientPlayer, pGame, pRoom, nX, nY);
}

// 0x005489F0
void __fastcall sub_6FC82830(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer != pUnit)
    {
        for (int i = 0; dword_6FD307F8[i] != -1; ++i)
        {
            const int nStatId = dword_6FD307F8[i];
            const int nValue = STATLIST_GetUnitBaseStat(pUnit, nStatId, 0);
            D2GAME_UpdateAttribute_6FC822D0(pUnit, nStatId, nValue, pPlayer);
        }
    }
}

// 0x005531E0
void __fastcall sub_005531E0_FixRoomIfInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (UNITS_IsCurrentRoomInvalid(pUnit))
    {
        int bFlag = 0;
        if (pUnit)
        {
            bFlag = (pUnit->dwFlags >> 4) & 1;
        }

        if (!bFlag)
        {
            sub_00538410_RemoveUnitIfNotAdjacent2(pClient, pUnit);
        }
    }
}

// 0x005538D0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg)
{
    D2UnitStrc** ppSlot = pGame->pUnitList[0];
    SUNIT_IterateFn pfCallback = pfIterate;
    D2_ASSERT(pGame && pfCallback, 2022);

    for (int i = 0; i < 128; ++i, ++ppSlot)
    {
        for (D2UnitStrc* pUnit = *ppSlot; pUnit; pUnit = pUnit->pListNext)
        {
            if (!STATES_CheckState(pUnit, STATE_PLAYERBODY))
            {
                pfCallback(pGame, pUnit, pArg);
            }

            D2_ASSERT(pUnit, 222);
        }
    }
}

#include "gen/data/Source/D2Game/005316D0_D2GAME_SAVE_SerializeItem_6FC89AD0.inc"
