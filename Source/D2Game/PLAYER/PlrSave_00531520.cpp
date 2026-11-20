#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2UnitData.h"

struct D2StaticPathStrc;
struct D2PlayerDataStrc;
struct D2QuestSaveSectionStrc;



struct D2GameStrc
{
    char unk0x00[0xD0];
    int nGameSeed[2];
};

void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543D80
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280
int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210
int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc); // 0x0063BDB0
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
static int __stdcall sub_00531520_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent); // 0x00531520
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pItem); // 0x00564CB0


#pragma pack(push, 1)
struct D2QuestSaveSectionStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned short nSize;
    unsigned char pQuestRecord[3][96];
};

#pragma pack(pop)

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc*); // 0x00625DB0
unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc*); // 0x0053FCE0
extern "C" const char gszPlrSaveFile_006E09AC[]; // 0x006E09AC
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, int* pSeed); // 0x00552DF0
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName); // 0x006220F0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwnerId); // 0x0063D430
int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x00533350
int __fastcall sub_005335E0(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize); // 0x005335E0
static __declspec(noinline) int __stdcall sub_00533850_ReadCorpse(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize);

__declspec(noinline)
// 0x00531520
static int __stdcall sub_00531520_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent)
{
    switch (!pItem ? 0 : pItem->dwAnimMode)
    {
    case 6:
        if (pParent)
        {
            UNITS_ChangeAnimMode(pItem, 4);
            const int nParentGUID = pParent->dwUnitId;
            const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
            int bPlaced;
            if (D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pPlayer, nItemGUID, nParentGUID, &bPlaced, 0, 1, 0, 0))
                break;
        }
    default:
        return 13;
    case 1:
        {
            D2InventoryStrc* pInventory = pPlayer->pInventory;
            const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (!nBodyLoc || !INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
                return 13;
            int nPage = 3;
            if (nBodyLoc == 11 || nBodyLoc == 12)
                nPage = 4;
            if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
                return 13;
            ITEMS_SetBodyLocation(pItem, nBodyLoc);
            if (pItem)
                pItem->dwFlags &= ~2u;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 255);
            sub_00628170_SetItemCommandFlag(pItem, 8, 1);
            if (pItem)
                pItem->dwFlags &= ~0x02000000u;
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pPlayer, 1);
            QUESTS_ItemPickedUp(pGame, pPlayer, pItem);
            break;
        }
    case 0:
        {
            UNITS_ChangeAnimMode(pItem, 4);
            int nY;
            switch (pItem->dwUnitType)
            {
            case 2:
            case 4:
            case 5:
                nY = pItem->pStaticPath->nYPos;
                break;
            default:
                nY = pItem->pDynamicPath ? PATH_GetYPosition(pItem->pDynamicPath) : 0;
                break;
            }
            int nX;
            switch (pItem->dwUnitType)
            {
            case 2:
            case 4:
            case 5:
                nX = pItem->pStaticPath->nXPos;
                break;
            default:
                nX = pItem->pDynamicPath ? PATH_GetXPosition(pItem->pDynamicPath) : 0;
                break;
            }
            const int nItemGUID = pItem->dwUnitId;
            if (D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrSave.cpp", 536, pGame, pPlayer, nItemGUID, nX, nY, 0, 0, 0))
                break;
            return 13;
        }
    }
    return 0;
}

int __fastcall sub_Emit_PlaceSavedItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent)
{
    sub_00564CB0_Nop(pItem);
    return sub_00531520_PlaceSavedItem(pGame, pPlayer, pItem, pParent);
}

// 0x00532BE0
int __fastcall sub_00532BE0_ReadQuestData(D2UnitStrc* pPlayer, const D2QuestSaveSectionStrc* pSection, int nUnused, int* pSize)
{
    *pSize = 0;

    D2QuestSaveSectionStrc tSection = *pSection;
    D2QuestSaveSectionStrc* pQuestSection = &tSection;
    if (pQuestSection->dwHeaderMagic != '!ooW')
    {
        return 2;
    }

    if (pQuestSection->dwVersion != 6)
    {
        return 2;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyBufferToRecord(pPlayerData->pQuestData[i], pQuestSection->pQuestRecord[i], 96, 1);
    }

    *pSize = sizeof(D2QuestSaveSectionStrc);
    return 0;
}

// 0x00532DA0
int __fastcall sub_00532DA0_ReadPlayerStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pData, int nStatCount, int nUnused, int* pSize)
{
    *pSize = 0;
    if (*(unsigned short*)pData != 0x6667) return 4;
    pData += 2;
    struct { int i; int nPresent; } tLoop;
    tLoop.nPresent = 0;
    tLoop.i = 0;
    if (nStatCount > 0) do
    {
        if (pData[(unsigned int)tLoop.i >> 3] & (1 << (tLoop.i & 7)))
        {
            const int nValue = *(int*)&pData[4 * tLoop.nPresent + 3];
            ++tLoop.nPresent;
            STATLIST_SetUnitStat(pUnit, tLoop.i, nValue, 0);
        }
        else
        {
            STATLIST_SetUnitStat(pUnit, tLoop.i, 0, 0);
        }
        ++tLoop.i;
    } while (tLoop.i < nStatCount);
    const int nSize = tLoop.nPresent * 4 + 5;
    if (ARENA_IsInArenaMode(pGame))
    {
        const int nLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, 6, nLife, 0);
        const int nMana = STATLIST_GetMaxManaFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, 8, nMana, 0);
    }
    const int nStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, 10, nStamina, 0);
    *pSize = nSize;
    return 0;
}

// 0x005337F0
int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize)
{
    int nResult;
    if (nVersion == 0x47)
        nResult = PLRSAVE_ReadLegacyItems(pGame, pUnit, pSection, 0x47, nSize, nUnused, pReadSize);
    else if (nVersion < 0x48 || nVersion > 0x60)
        return 1;
    else
        nResult = sub_005335E0(pGame, pUnit, pSection, nVersion, nSize, nUnused, pReadSize);
    return nResult;
}

// 0x00533850
static int __stdcall sub_00533850_ReadCorpse(D2UnitStrc* pUnit, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize)
{
    *pReadSize = 0;
    pData += 12;
    nSize -= 12;

    D2UnitStrc* pPlayer = pUnit;
    pUnit = SUNIT_AllocUnitData(0, !pPlayer ? -1 : pPlayer->dwClassId, 0, 0, pGame, 0, 1, 0x11, 0);
    if (!pUnit)
    {
        return 8;
    }

    pUnit->dwFlags &= ~4;
    {
        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszPlrSaveFile_006E09AC, 0x1511);
        SUNIT_InitClientInPlayerData(pUnit, pClient);
        char* const szName = CLIENTS_GetName(pClient);
        UNITS_SetNameInPlayerData(pUnit, szName);
    }
    SUNIT_InitSeed(pUnit, pGame->nGameSeed);
    STATES_ToggleState(pUnit, 7, 1);
    pUnit->dwFlags &= ~0x10;
    INVENTORY_SetOwnerId(pUnit->pInventory, !pPlayer ? -1 : pPlayer->dwUnitId);

    {
        int nRead = 0;
        const int nResult = sub_005337F0_ReadItems(pGame, pUnit, pData, nVersion, nSize, 1, &nRead);
        if (nResult)
        {
            return nResult;
        }

        nSize = nRead + 12;
        INVENTORY_CreateCorpseForPlayer(pPlayer->pInventory, !pUnit ? -1 : pUnit->dwUnitId, 0, 1);
        const int nCorpseId = !pUnit ? -1 : pUnit->dwUnitId;
        const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, nPlayerId, nCorpseId, 1);
        *pReadSize = nSize;
        return 0;
    }
}

// build: context sub_00533850_EmitCaller
int __fastcall sub_00533850_EmitCaller(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize)
{
    return sub_00533850_ReadCorpse(pPlayer, pGame, pData, nVersion, nSize, pReadSize);
}
