struct D2ClientStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2BitBufferStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    D2CoordStrc tGameCoords;
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
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    char unk0x64[0x4C];
    unsigned int dwLastHitClass;
};

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;

    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x005490E0
    int sub_00549150_CheckStoredItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x00549150
};

struct D2PlayerDataStrc
{
    char szName[0x10];
    D2BitBufferStrc* pQuestData[3];
    char unk0x1C[0x50];
    int dwBoughtItemId;
};

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc*, D2UnitStrc*, D2ClientStrc*, int);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc field_0;
    int field_4;
    int field_8;
};

extern D2UnkPlrMsgStrc stru_6FD30708[20];                                                                   // 0x007319E8

void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10); // 0x0053B570
int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);                     // 0x00535610
void __fastcall sub_00549A60_SendCantDoThat(D2UnitStrc* pUnit);                                             // 0x00549A60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall sub_6FC48940(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6); // 0x0055E9B0
int __fastcall sub_6FC446B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4, int a5, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int a8); // 0x00560420
int __fastcall sub_6FC45550(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* a6); // 0x00563D20
void __fastcall D2GAME_NPC_IdentifyBoughtItem_6FCCA990(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00578640
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);          // 0x0065C360

#define UNIT_ITEM 4
#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_TILE 5
#define MAX_QUEST_STATUS 42
#define QFLAG_UPDATEQUESTLOG 12

inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
}

// 0x005482A0
void __fastcall sub_6FC81F60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const char nHitClass = pUnit->dwLastHitClass;
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    const int nUnitId = pUnit->dwUnitId;
    D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(pClient, 0x0F, 0, nUnitId, (unsigned char)stru_6FD30708[nAnimMode].field_4, D2COMMON_10175_PathGetFirstPointX(pPath), D2COMMON_10176_PathGetFirstPointY(pPath), nHitClass, nX, nY);
}

// 0x0054ACD0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x19_RemoveItemFromBuffer_6FC850C0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    int a6;
    const int nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        sub_00549A60_SendCantDoThat(pUnit);
        return 2;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 2;
    }

    if (ITEMS_GetInvPage(pItem) == 1)
    {
        return 3;
    }

    if (sub_6FC7C3A0(pGame, pUnit, pItem))
    {
        a6 = 0;
        if (!sub_6FC446B0(pGame, pUnit, nItemGUID, &a6, 1, 0, 0, 0) && a6)
        {
            return 3;
        }
    }

    return 0;
}

// 0x0054AE30
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1B_Swap2HandedItem_6FC853C0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int a6 = 0;
    if (sub_6FC45550(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a6) || !a6)
    {
        return 0;
    }

    return 3;
}

// 0x0054B3E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x23_ItemToBelt_6FC85E70(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const int nBeltSlot = *(int*)((char*)pPacket + 5);
    const int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int a6 = 0;
    if (sub_6FC48940(pGame, pUnit, nItemGUID, nBeltSlot, 0, &a6) || !a6)
    {
        return 0;
    }

    return 3;
}

// 0x0054BC30
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x37_IdentifyFromGamble_6FC86C30(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    if (!SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID))
    {
        return 2;
    }

    const int nBoughtItemId = UNITS_GetPlayerData(pUnit)->dwBoughtItemId;
    if (nBoughtItemId != nItemGUID)
    {
        return 3;
    }

    D2GAME_NPC_IdentifyBoughtItem_6FCCA990(pGame, pUnit, nItemGUID);
    return 0;
}

// 0x0054C9C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x58_QuestCompleted_6FC883B0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const int nQuestId = *(unsigned short*)((char*)pPacket + 1);
    if (nQuestId < MAX_QUEST_STATUS)
    {
        D2BitBufferStrc* pQuestData = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestData, nQuestId, QFLAG_UPDATEQUESTLOG);
        return 0;
    }

    return 2;
}
