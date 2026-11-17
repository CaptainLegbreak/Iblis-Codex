struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2RunesTxt;

struct D2UnitStrc
{
    char pad00[0x0C];
    int dwUnitId;
};

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char nAnimMode;
    unsigned char nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};

int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int dwVersion); // 0x0062AE20
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion); // 0x00558CB0
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit);                                                        // 0x00564CB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem);                             // 0x0062BED0
void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);      // 0x00563470

// 0x0056ACE0
int __fastcall PLRSAVE2_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc** ppItem, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion)
{
    unsigned char* pSection = *ppSection;
    *ppItem = 0;

    unsigned int nSize = pEnd - pSection;

    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstream(pSection, nSize, 1, &tItemSave, dwVersion);
    if (tItemSave.nClassId == -1)
    {
        return 0;
    }

    D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize, 1, &tItemSave, &nSize, dwVersion);
    if (!pItem)
    {
        return 0;
    }

    pSection += nSize;
    sub_00564CB0_Nop(pItem);

    const int nSockets = tItemSave.nItemFileIndex;
    D2UnitStrc* pParentItem = pItem;
    for (int i = 0; i < nSockets; ++i)
    {
        nSize = pEnd - pSection;
        ITEMS_GetCompactItemDataFromBitstream(pSection, nSize, 1, &tItemSave, dwVersion);

        pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize, 1, &tItemSave, &nSize, dwVersion);
        if (!pItem)
        {
            SUNIT_RemoveUnit(pGame, pParentItem);
            return 0;
        }

        pSection += nSize;
        sub_00564CB0_Nop(pItem);
        UNITS_ChangeAnimMode(pItem, 4);

        const int nSocketableGUID = pItem->dwUnitId;
        int bPlaced;
        if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pPlayer, nSocketableGUID, sub_00451F50_GetUnitGUID(pParentItem), &bPlaced, 0, 1, 0, 0))
        {
            SUNIT_RemoveUnit(pGame, pParentItem);
            return 0;
        }
    }

    if (ITEMS_GetItemFlags(pParentItem) & 0x4000000 && !ITEMS_GetRunesTxtRecordFromItem(pParentItem))
    {
        ITEMMODE_DetachItemFromOwner(pGame, pPlayer, pParentItem);
        pParentItem = 0;
    }

    *ppSection = pSection;
    *ppItem = pParentItem;
    return 1;
}
