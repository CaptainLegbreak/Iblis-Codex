struct D2ActiveRoomStrc;
struct D2GameStrc { char unk_00[0xA8]; int dwGameFrame; };
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; };
struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX, nY;
    unsigned char nAnimMode, nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage, nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
int __fastcall EVENT_GetEventFrame(D2GameStrc*, D2UnitStrc*, int); // 0x005415A0
void __fastcall EVENT_SetEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int); // 0x005417D0
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc*, D2ActiveRoomStrc*, unsigned char*, unsigned int, int, D2ItemSaveStrc*, unsigned int*, unsigned int); // 0x00558CB0
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc*, D2UnitStrc*, int, int, int*, int, int, int, int); // 0x00562660
void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc*, D2UnitStrc*); // 0x005979B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, unsigned short); // 0x00625480
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*, unsigned int, int); // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc*, int, int); // 0x00628170
int __stdcall sub_0062E410(unsigned char*, unsigned int, int, D2ItemSaveStrc*); // 0x0062E410
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc*, unsigned char*, int, int, int, int); // 0x006313E0

// 0x0055A2A0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame)
{
    unsigned char aBuffer[1024];
    D2ItemSaveStrc itemSave;
    unsigned int nRead;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    unsigned int nSize = ITEMS_SerializeItemToBitstream(pItem, aBuffer, 1024, 1, 1, 0);
    sub_0062E410(aBuffer, nSize, 1, &itemSave);
    D2UnitStrc* pNewItem = ITEMS_CreateItemFromBitstream(pGame, pRoom, aBuffer, nSize, 1, &itemSave, &nRead, 96);
    if (!pNewItem)
        return 0;
    unsigned char* pBitstream = aBuffer + nRead;
    nSize -= nRead;
    ITEMS_SetItemFlag(pNewItem, 0x80000, 1);
    ITEMS_SetItemFlag(pNewItem, 0x2000, 0);
    if (bAddToGame && itemSave.nItemFileIndex)
    {
        const int nSocketCount = itemSave.nItemFileIndex;
        for (int i = 0; i < nSocketCount; ++i)
        {
            sub_0062E410(pBitstream, nSize, 1, &itemSave);

            D2UnitStrc* __restrict pFiller = ITEMS_CreateItemFromBitstream(pGame, 0, pBitstream, nSize, 1, &itemSave, &nRead, 96);
            if (!pFiller)
                return 0;
            pBitstream += nRead;
            nSize -= nRead;
            UNITS_ChangeAnimMode(pFiller, 4);
            int bPlaced;
            if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pNewItem, !pFiller ? -1 : pFiller->dwUnitId, sub_00451F50_GetUnitGUID(pNewItem), &bPlaced, 0, 1, 0, 0))
            {
                sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xDD4);
                exit(-1);
            }
            ITEMS_SetItemFlag(pFiller, 0x80000, 1);
            ITEMS_SetItemFlag(pFiller, 0x2000, 0);
            ITEMS_SetItemCMDFlag(pFiller, 1, 0);
        }
    }
    ITEMS_SetItemFlag(pItem, 0x8000000, 1);
    const int nReplenishDurability = STATLIST_UnitGetStatValue(pNewItem, 252, 0);
    if (nReplenishDurability && !EVENT_GetEventFrame(pGame, pNewItem, 3))
        EVENT_SetEvent(pGame, pNewItem, 3, pGame->dwGameFrame + 2500 / nReplenishDurability + 1, 0, 0);
    const int nReplenishQuantity = STATLIST_UnitGetStatValue(pNewItem, 253, 0);
    if (nReplenishQuantity && !EVENT_GetEventFrame(pGame, pNewItem, 3))
        EVENT_SetEvent(pGame, pNewItem, 3, pGame->dwGameFrame + 2500 / nReplenishQuantity + 1, 0, 0);
    D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pNewItem);
    ITEMS_SetItemCMDFlag(pNewItem, 1, 0);
    return pNewItem;
}
