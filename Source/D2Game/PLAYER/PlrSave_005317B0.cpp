#include "D2Game.h"
#include "D2Structs.h"

#define WRITE_ITEM(pItem) { const int nSize = D2GAME_SAVE_SerializeItem_6FC89AD0(pGame, pUnit, pItem, pData, nBufferSize - (pData - pBuffer), a4, a5, a6); if (nSize < 0) return -1; pData += nSize; if (!nSize && nItems > 0) --nItems; }
#define PREPARE_ITEM(pItem) (ITEMS_SerializeItemToBitstream(pItem, tempBuffer, sizeof(tempBuffer), 1, 1, 0))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define SYSERROR_BAD_WAYPOINT 3
#define WAYPOINT_MAGIC 0x5357
#define UNITFLAG_TARGETABLE 0x02
#define UNITFLAG_CANBEATTACKED 0x04
#define UNITFLAG_ISVALIDTARGET 0x08
#define UNITFLAG_INITSEEDSET 0x10
#define PLRMODE_DEAD 0x11
#define STATE_PLAYERBODY 7
#define EVENTTYPE_FREEHOVER 3
#define EVENTTYPE_STATREGEN 4
#define EVENTTYPE_TRAP 6
#define COLLIDE_MASK_CORPSE 0x9C19
#define CLIENTFLAGEX_HAS_SAVE_CHECKSUM 0x08
#define LEVEL_ROGUEENCAMPMENT 1
#define LEVEL_LUTGHOLEIN 40
#define LEVEL_KURASTDOCKTOWN 75
#define LEVEL_HARROGATH 109
struct D2SaveHeaderStrc;
struct D2ServerCallbackFunctions;
struct D2SkillListStrc;
struct D2PlayerDataStrc;
struct D2WaypointSaveRecordStrc;
struct D2WaypointSaveSectionStrc;
struct D2CharItemStrc;
struct D2CharStatsTxt;
struct D2ItemsTxt;
struct D2UnitProxyArgStrc;
struct D2DrlgDeleteStrc;


D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
static __declspec(noinline) unsigned short sub_00531750_CountInventoryItems(D2InventoryStrc* pInventory); // 0x00531750
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble); // 0x006313E0

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4A];
    unsigned char nGameType;
    unsigned char unk_6B[0x51];
    D2DrlgActStrc* pAct[5];
};

int __fastcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int a4, int a5, int a6); // 0x005316D0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile);
extern "C" int __cdecl fclose(_iobuf* pFile);
int __fastcall sub_00407050_GetSavePath(char* szPath, int nSize); // 0x00407050
__declspec(noalias) int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7); // 0x00569AD0

struct D2ClientStrc
{
    int dwClientId;
    char unk0x04[0x174];
    int bUnlockCharacter;
    D2SaveHeaderStrc* pSaveHeader;
    int nSaveHeaderSize;
    char unk0x184[0x8];
    unsigned int nSaveChecksum;
    char unk0x190[0x18];
    D2GameStrc* pGame;
    char unk0x1AC[0x228];
    unsigned int dwFlags;
    char unk0x3D8[0xD4];
    D2ClientStrc* pNext;
};

int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient); // 0x00538590
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int a5, int a6, int a7); // 0x00538CE0
D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient); // 0x00538E00
void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* pClient); // 0x00538F10
void __fastcall D2GAME_SetSaveLoadComplete_6FC34300(D2ClientStrc* pClient); // 0x00538F80
extern "C" int __stdcall sub_00554100(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100
extern "C" void __fastcall sub_00539300(D2ClientStrc* pClient, unsigned int* pOut); // 0x00539300
extern "C" void __fastcall sub_00539310(D2ClientStrc* pClient, unsigned int* pOut); // 0x00539310
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer); // 0x005392F0
int __fastcall sub_00531EB0_WriteFileOnRealm(D2GameStrc* pGame, char* szAccountName, D2UnitStrc* pPlayer, const char* szName, int bInteractsWithPlayer, unsigned int nToken, unsigned int dwArg, unsigned int nClientInfo);
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230
extern "C" const char gszFileModeWb_006D69E0[]; // 0x006D69E0
extern "C" const char gszSaveOpenError_006E09C4[]; // 0x006E09C4
extern "C" const char szPlrSaveCppFile_006E09AC[];
static __declspec(noinline) void __stdcall sub_00532240_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName);

struct D2PlayerDataStrc
{
    char unk0x00[0x1C];
    D2WaypointDataStrc* pWaypointData[3];
    char unk0x28[0x24];
    int bBusy;
    char unk0x50[0x10];
    D2PlrIntroStrc* pPlayerIntro[3];
    unsigned int dwBoughtItemId;
};

struct D2WaypointSaveRecordStrc
{
    unsigned short nFlags;
    unsigned short unk0x02;
    int unk0x04[5];
};

struct D2WaypointSaveSectionStrc
{
    unsigned short nMagic;
    unsigned short unk0x02;
    int unk0x04;
    D2WaypointSaveRecordStrc pRecords[3];
};

struct D2CharItemStrc
{
    int dwItemCode;
    int unk0x04;
};

struct D2CharStatsTxt
{
    char unk0x00[0x5C];
    D2CharItemStrc pItems[10];
    char unk0xAC[0x18];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgDeleteStrc
{
    int nUnitType;
    int nUnitGUID;
    D2DrlgDeleteStrc* pNext;
};

struct D2CriticalSectionStrc
{
    void* pDebugInfo;
    long nLockCount;
    long nRecursionCount;
    void* hOwningThread;
    void* hLockSemaphore;
    unsigned long nSpinCount;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

typedef void (__fastcall* STATLIST_CallbackFn)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gbClientListInitialized_008846D8; // 0x008846D8
extern D2CriticalSectionStrc gClientListLock_008846A8; // 0x008846A8
extern D2ClientStrc* gpClientList_008842A8[256]; // 0x008842A8
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
unsigned int __fastcall D2GAME_SAVE_CalculateChecksum_6FC8A140(D2SaveHeaderStrc* pSaveHeader, int nSize); // 0x00531E30
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400
void __fastcall sub_00534800_CreatePlayerIntros(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00534800
void __fastcall PLAYER_CreateStartItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2CharStatsTxt* pCharStatsTxt, int nCount, D2CharItemStrc* pCharItem); // 0x00534D60
void __fastcall SUNITPROXY_CountPlayersInLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x00536820
D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536C50
void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bStale); // 0x00537230
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0
void __fastcall sub_0053BDA0_SendUnitRemoval(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0
void __fastcall D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D090
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053ED50
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70
void __fastcall ARENA_AllocArenaUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053F530
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30
void __fastcall QUESTS_UpdateNPCIntros(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct); // 0x00545100
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue); // 0x0055B800
void __fastcall sub_6FC92EF0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567330
int __fastcall sub_00567620(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* a3); // 0x00567620
void __fastcall sub_00568760_ResetPlayerInteract(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00568760
int __fastcall sub_6FC61F20(D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00573140
void __fastcall PLAYERPETS_AllocPetList(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575AF0
void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00579130
void __fastcall sub_6FC79B50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x005854D0
void __fastcall sub_0058D560_EndInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058D560
void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597310
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventory); // 0x00597890
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2DrlgDeleteStrc* __stdcall DUNGEON_GetDrlgDeleteFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A330
void* __stdcall sub_00619DA0_ActLookup(D2DrlgActStrc* pAct, int a2, int a3); // 0x00619DA0
void __stdcall UNITS_AllocPlayerData(D2UnitStrc* pUnit); // 0x00621F90
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall UNITS_SetSwitchLeftSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00623300
void __stdcall UNITS_SetSwitchRightSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00623350
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, STATLIST_CallbackFn pfCallback, D2GameStrc* pGame); // 0x00626D40
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool); // 0x006438B0
void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit); // 0x00647EE0
void __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0
void __stdcall D2Common_10231(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650C20
void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDest, const D2WaypointSaveRecordStrc* pSource); // 0x00661030

static __declspec(noinline) unsigned short sub_00531750_CountInventoryItems(D2InventoryStrc* pInventory)
{
    int nCount = 0;
    if (!pInventory)
        return 0;
    if (INVENTORY_GetCursorItem(pInventory))
        nCount = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pIsItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pIsItem)
            ++nCount;
    }
    return (unsigned short)nCount;
}

// 0x005317B0
int __fastcall sub_005317B0_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pData, int nBufferSize, int a4, int a5, int a6)
{
    unsigned char tempBuffer[8192];
    unsigned char* pBuffer = pData;
    if (nBufferSize < 2) return 0;
    *(unsigned short*)pData = 0x4D4A;
    pData += 2;
    unsigned short nItems = sub_00531750_CountInventoryItems(pInventory);
    if (nBufferSize < pData - pBuffer + 2) return pData - pBuffer;
    unsigned short* pItemCount = (unsigned short*)pData;
    *pItemCount = nItems;
    pData += 2;
    if (pInventory)
    {
        D2UnitStrc* pLeft = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        D2UnitStrc* pCursor = INVENTORY_GetCursorItem(pInventory);
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                if (PREPARE_ITEM(pRight) < 0) return -1;
                if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
            }
            else
            {
                if (PREPARE_ITEM(pOther) < 0) return -1;
                if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            }
        }
        else
        {
            if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
        }
        if (pCursor && pCursor->dwUnitType == 4 && PREPARE_ITEM(pCursor) < 0) return -1;
        D2UnitStrc* pListItem = INVENTORY_GetFirstItem(pInventory);
        while (pListItem)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pListItem);
            unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (INVENTORY_GetItemNodePage(pListItem) != 3 || (nBodyLoc != 4 && nBodyLoc != 5))
            {
                WRITE_ITEM(pItem);
            }
            pListItem = INVENTORY_GetNextItem(pListItem);
        }
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                WRITE_ITEM(pRight);
                if (pOther) { WRITE_ITEM(pOther); }
            }
            else
            {
                WRITE_ITEM(pOther);
                if (pRight) { WRITE_ITEM(pRight); }
            }
        }
        else
        {
            if (pRight) { WRITE_ITEM(pRight); }
            if (pOther) { WRITE_ITEM(pOther); }
        }
        if (pCursor && pCursor->dwUnitType == 4) { WRITE_ITEM(pCursor); }
        *pItemCount = nItems;
    }
    return pData - pBuffer;
}

// 0x00532240
static void __stdcall sub_00532240_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
{
    if (!gnGlobal_007310CC)
    {
        return;
    }

    char szPath[0x400];
    char szFile[0x1F4];
    unsigned char pData[0x2000];
    unsigned int nSize;

    sub_00407050_GetSavePath(szPath, sizeof(szPath));
    sprintf(szFile, gszSaveFormat_006D4230, szPath, szName);
    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, dwArg);
    if ((int)nSize <= 0)
    {
        return;
    }

    _iobuf* pFile = fopen(szFile, gszFileModeWb_006D69E0);
    if (pFile)
    {
        fwrite(pData, nSize, 1, pFile);
        fclose(pFile);
    }
    else
    {
        sub_00410610_WriteLogLine(gszSaveOpenError_006E09C4, szFile);
    }
}

// 0x00532340
static __declspec(noinline) void __stdcall sub_00532340_SaveToClient(int bInteractsWithPlayer, D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pPlayer)
{
    unsigned char pData[0x2000];
    unsigned int nSize;

    if (CLIENTS_GetSaveHeader(pClient))
    {
        CLIENTS_FreeSaveHeader(pClient);
    }

    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, 0);
    const int nFileSize = nSize;
    D2_ASSERT(nFileSize > 0, 2866);
    const int nClientId = CLIENTS_GetClientId(pClient);
    CLIENTS_AttachSaveFile(nClientId, pData, nFileSize, nFileSize, 0, 0, 0);
    D2GAME_SetSaveLoadComplete_6FC34300(pClient);
}

// build: context D2GAME_SAVE_WriteFile_6FC8A500
int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg)
{
    if (!pPlayer)
    {
        return 0;
    }

    pPlayer->dwFlagEx &= ~2;

    int bInteractsWithPlayer = 0;
    int nUnitType = 6;
    int nUnitGUID;
    if (sub_00554100(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 0)
    {
        bInteractsWithPlayer = 1;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, szPlrSaveCppFile_006E09AC, 2919);
    char szAccountName[50];
    CLIENTS_CopyAccountNameToBuffer(pClient, szAccountName);
    unsigned int nToken;
    sub_00539300(pClient, &nToken);
    unsigned int nClientInfo;
    sub_00539310(pClient, &nClientInfo);

    int nResult = 1;
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        sub_00532340_SaveToClient(bInteractsWithPlayer, pGame, pClient, pPlayer);
    }
    else if (gpD2EventCallbackTable_6FD45830)
    {
        nResult = sub_00531EB0_WriteFileOnRealm(pGame, szAccountName, pPlayer, szName, bInteractsWithPlayer, nToken, dwArg, nClientInfo);
    }
    else
    {
        sub_00532240_SaveToLocalFile(bInteractsWithPlayer, dwArg, pGame, pPlayer, szName);
    }

    return nResult;
}

#include "gen/data/Source/D2Game/PLAYER/PlrSave_005317B0.inc"

// 0x00532C70
int __fastcall D2GAME_SAVE_ReadWaypointData_6FC8AD50(D2UnitStrc* pUnit, const unsigned char* pSection, int nUnused, int* pSize)
{
    *pSize = 0;

    D2WaypointSaveSectionStrc tSection = *(const D2WaypointSaveSectionStrc*)pSection;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    if (tSection.nMagic != WAYPOINT_MAGIC)
    {
        return SYSERROR_BAD_WAYPOINT;
    }

    int i = 0;
    D2WaypointDataStrc** ppWaypointData = pPlayerData->pWaypointData;
    const D2WaypointSaveRecordStrc* pRecord = tSection.pRecords;
    for (; i < 3; ++i, ++ppWaypointData, ++pRecord)
    {
        if (pRecord->nFlags != 0x102 && pRecord->nFlags != 0x101 && pRecord->nFlags != 0)
        {
            return SYSERROR_BAD_WAYPOINT;
        }

        WAYPOINTS_CopyAndValidateWaypointData(*ppWaypointData, pRecord);
    }

    *pSize = sizeof(D2WaypointSaveSectionStrc);
    return 0;
}

// 0x00533F70
int __stdcall sub_00533F70_ReadHotkeySection(D2UnitStrc* pPlayer, const unsigned char* pSection, unsigned int nSize, int* pSize)
{
    *pSize = 0;

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave.cpp", 5793);
    if (!pClient)
    {
        return 0;
    }

    *pSize = 0x30;
    if (nSize <= 0x48)
    {
        return 0;
    }

    const unsigned char* pKey = pSection;
    for (int i = 8; i < 16; ++i)
    {
        int nSkillId = pKey[0];
        if (nSkillId >= 156 && nSkillId <= 216)
        {
            nSkillId += 65;
        }
        else if (nSkillId == 255)
        {
            nSkillId = -1;
        }

        CLIENTS_SetSkillHotKey(pClient, i, nSkillId, pKey[1], -1);
        pKey += 6;
    }

    if (nSize > 0x51)
    {
        const int* pSwitch = (const int*)(pSection + *pSize);
        const int nRightSkillId = pSwitch[1];
        UNITS_SetSwitchLeftSkill(pPlayer, pSwitch[0], -1);
        UNITS_SetSwitchRightSkill(pPlayer, nRightSkillId, -1);
        *pSize += 8;
    }

    return 0;
}

// 0x00534630
int __stdcall D2GAME_10029_SAVE_WriteFileInterface(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
{
    return D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, szName, 0);
}

// 0x00534650
D2UnitStrc* __stdcall sub_00534650_GetServerUnitFromFirstGame(int nUnitType, int nUnitGUID)
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();
    if (!pGame)
    {
        return 0;
    }

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    sub_0052DF40_UnlockFirstGame();
    return pUnit;
}

// 0x00534680
D2DrlgActStrc* __stdcall sub_00534680_GetActFromFirstGame(int nAct)
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();
    D2_ASSERT(pGame, 105);

    D2DrlgActStrc* pAct = pGame->pAct[nAct];
    sub_0052DF40_UnlockFirstGame();
    return pAct;
}

// 0x00534730
void* __stdcall sub_00534730_ActLookupInFirstGame(unsigned char nAct, int a2, int a3)
{
    D2GameStrc* pGame = sub_0052F6E0_LockFirstGame();
    D2_ASSERT(nAct < 5, 141);

    void* pResult = sub_00619DA0_ActLookup(pGame->pAct[nAct], a2, a3);
    sub_0052DF40_UnlockFirstGame();
    return pResult;
}

// 0x005348C0
void __fastcall PLAYER_Create(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPlayerGUID)
{
    D2_ASSERT(pPlayer, 71);

    pPlayer->dwFlags |= UNITFLAG_ISVALIDTARGET | UNITFLAG_CANBEATTACKED | UNITFLAG_TARGETABLE;
    pPlayer->dwUnitId = nPlayerGUID;

    INVENTORY_AllocInventory(0, pPlayer);

    pPlayer->pSkills = SKILLS_AllocSkillList(pGame->pMemoryPool);
    SKILLS_InitSkillList(pPlayer);

    STATLIST_AllocStatListEx(pPlayer, 0, D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910, pGame);
    UNITS_AllocPlayerData(pPlayer);
    sub_00534800_CreatePlayerIntros(pGame, pPlayer);

    SUNIT_InitClientInPlayerData(pPlayer, 0);
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pPlayer);
    ARENA_AllocArenaUnit(pGame, pPlayer);
    PLAYERPETS_AllocPetList(pGame, pPlayer);
    sub_6FCBDD30(pPlayer, 2, 1);
}

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00534F10
void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, void* pUnused)
{
    if (!pPlayer)
    {
        return;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        PLAYER_CreateStartItem(pGame, pPlayer, pCharStatsTxtRecord, i, &pCharStatsTxtRecord->pItems[i]);
    }
}

// 0x00534F80
void __fastcall PLAYER_SynchronizeItemsToClient(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(pUnit->pInventory, 391);

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(pClient, pUnit, pCheckedItem, 0);
        }
        else if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0) && INVENTORY_GetItemNodePage(pItem) == 1)
        {
            D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(pClient, pUnit, pCheckedItem, 0);
        }
        else if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0) && INVENTORY_GetItemNodePage(pItem) == 2)
        {
            D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(pClient, pUnit, pCheckedItem, 0);
        }
    }
}

// 0x005350F0
void __fastcall sub_6FC7BEC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (pInteractUnit)
        {
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                D2GAME_NPC_ResetInteract_6FCCB4D0(pGame, pUnit, pInteractUnit);
                break;

            case UNIT_OBJECT:
                sub_6FC79B50(pGame, pUnit, pInteractUnit);
                break;

            case UNIT_PLAYER:
                sub_00568760_ResetPlayerInteract(pGame, pUnit);
                break;

            case UNIT_ITEM:
                if (DATATBLS_GetItemsTxtRecord(pInteractUnit->dwClassId)->dwCode == ' xob')
                {
                    sub_6FC92EF0(pGame, pUnit);
                }
                break;
            }
        }
    }

    sub_0058D560_EndInteraction(pGame, pUnit);
}

// 0x005352C0
void __fastcall sub_6FC7BFC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nPlayerGUID, D2CoordStrc* pCoord)
{
    D2_ASSERT(pRoom, 543);

    COLLISION_GetFreeCoordinatesEx(pRoom, pCoord, 2, COLLIDE_MASK_CORPSE, 4);

    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nPlayerGUID);
    if (!pPlayer)
    {
        return;
    }

    D2Common_10231(pPlayer->pDynamicPath, pPlayer, pRoom, pCoord->nX, pCoord->nY);
    pPlayer->dwFlags |= UNITFLAG_TARGETABLE;

    UNITS_ChangeAnimMode(pPlayer, PLRMODE_DEAD);
    pPlayer->dwFlags &= ~UNITFLAG_ISVALIDTARGET;

    STATES_ToggleState(pPlayer, STATE_PLAYERBODY, 1);
    pPlayer->dwFlags |= UNITFLAG_INITSEEDSET;

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_FREEHOVER, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_STATREGEN, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, EVENTTYPE_TRAP, 0);

    const int nOwnerGUID = INVENTORY_GetOwnerId(pPlayer->pInventory);
    if (nOwnerGUID != -1)
    {
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, nOwnerGUID, nPlayerGUID, 1);
    }
}

// 0x00535610
int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* a3)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (!pInteractUnit)
        {
            SUNIT_ResetInteractInfo(pPlayer);
            return 0;
        }

        switch (nUnitType)
        {
        case UNIT_PLAYER:
            return sub_00567620(pGame, pPlayer, a3);

        case UNIT_MONSTER:
            return sub_6FC61F20(pInteractUnit, pPlayer);
        }
    }
    else
    {
        if (UNITS_GetPlayerData(pPlayer)->bBusy)
        {
            return 0;
        }
    }

    return sub_00567620(pGame, pPlayer, a3);
}

// 0x00537340
void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId)
{
    D2UnitProxyArgStrc unitProxyArg;
    unitProxyArg.nLevelId = nCurrentLevelId;
    unitProxyArg.nCounter = 0;

    switch (nCurrentLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 0, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_LUTGHOLEIN:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 1, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_KURASTDOCKTOWN:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 2, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_THEPANDEMONIUMFORTRESS:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 3, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_HARROGATH:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 4, unitProxyArg.nCounter == 0);
        break;

    default:
        break;
    }

    switch (nDestLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 0);
        break;

    case LEVEL_LUTGHOLEIN:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 1);
        ACT1Q4_UpdateQuestStateOnActChange(pGame, pUnit);
        break;

    case LEVEL_KURASTDOCKTOWN:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 2);
        break;

    case LEVEL_HARROGATH:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 4);
        break;

    default:
        return;
    }
}

// 0x00537680
void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    D2GAME_INVMODE_First_6FC40FB0(pGame, pNpc, pClient, 0);

    D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNpc);
    if (pGambleInventory)
    {
        D2GAME_INVMODE_First_6FC40FB0(pGame, pNpc, pClient, pGambleInventory);
    }
}

// 0x00538CE0
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int a6, int a7)
{
    int nResult = 0;

    if (!gbClientListInitialized_008846D8)
    {
        return 0;
    }

    EnterCriticalSection(&gClientListLock_008846A8);

    D2ClientStrc* pClient = gpClientList_008842A8[nClientId & 0xFF];
    while (pClient)
    {
        if (pClient->dwClientId == nClientId)
        {
            break;
        }

        pClient = pClient->pNext;
    }

    if (pClient)
    {
        void* pDestination = 0;
        if (!pClient->nSaveHeaderSize)
        {
            pClient->pSaveHeader = (D2SaveHeaderStrc*)sub_0040B430(pClient->pGame->pMemoryPool, nTotalSize, ".\\GAME\\Clients.cpp", 2858, 0);
            pDestination = pClient->pSaveHeader;
        }
        else
        {
            pDestination = (char*)pClient->pSaveHeader + pClient->nSaveHeaderSize;
        }

        D2_ASSERT(pClient->nSaveHeaderSize + nSize <= nTotalSize, 2863);

        memcpy(pDestination, pSaveData, nSize);

        pClient->nSaveHeaderSize += nSize;
        pClient->bUnlockCharacter = bUnlockCharacter;

        if (pClient->nSaveHeaderSize == nTotalSize)
        {
            pClient->dwFlags |= CLIENTFLAGEX_HAS_SAVE_CHECKSUM;
            pClient->nSaveChecksum = D2GAME_SAVE_CalculateChecksum_6FC8A140(pClient->pSaveHeader, pClient->nSaveHeaderSize);
            nResult = 1;
        }
    }

    LeaveCriticalSection(&gClientListLock_008846A8);
    return nResult;
}

// 0x0053A770
void __fastcall LEVEL_RemoveUnitsExceptClientPlayer(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 132);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    D2UnitStrc* pUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2_ASSERT(pUnit, 136);

    const int nUnitType = pUnit->dwUnitType;
    const int nUnitGUID = pUnit->dwUnitId;
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2DrlgDeleteStrc* pDrlgDelete = DUNGEON_GetDrlgDeleteFromRoom(ppRoomList[i]); pDrlgDelete; pDrlgDelete = pDrlgDelete->pNext)
        {
            if (pDrlgDelete->nUnitType != nUnitType || pDrlgDelete->nUnitGUID != nUnitGUID)
            {
                sub_0053BDA0_SendUnitRemoval(pClient, 0x0A, pDrlgDelete->nUnitType, pDrlgDelete->nUnitGUID);
            }
        }
    }
}
