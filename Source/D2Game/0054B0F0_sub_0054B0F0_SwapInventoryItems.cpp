// build: base-profile

#define D2_MAYBE_UNUSED(x) (void)(x)
struct D2UnitStrc;
struct D2GameStrc
{
    int sub_005490E0_CheckCursorItem(D2UnitStrc*, int); // 0x005490E0
    int sub_00549150_CheckStoredItem(D2UnitStrc*, int); // 0x00549150
};
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc*); // 0x00628250
int __fastcall sub_6FC7C3A0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00535610
int __fastcall sub_6FC46D40(D2GameStrc*, D2UnitStrc*, int, int, int, int, int*); // 0x00561B00

#pragma pack(push, 1)
struct D2GSPacketClt1F
{
    unsigned char nHeader;
    int nCursorItemGUID;
    int nInventoryItemGUID;
    int nPosX;
    int nPosY;
};
#pragma pack(pop)

// 0x0054B0F0
int __fastcall sub_0054B0F0_SwapInventoryItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    D2GSPacketClt1F* pPacket1F = (D2GSPacketClt1F*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    const int nCursorItemGUID = pPacket1F->nCursorItemGUID;
    const int nInventoryItemGUID = pPacket1F->nInventoryItemGUID;
    const int nX = pPacket1F->nPosX;
    const int nY = pPacket1F->nPosY;
    D2UnitStrc* pInventoryItem;
    int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nCursorItemGUID);
    if (!nResult)
    {
        nResult = pGame->sub_00549150_CheckStoredItem(pUnit, nInventoryItemGUID);
        if (!nResult)
        {
            pInventoryItem = SUNIT_GetServerUnit(pGame, 4, nInventoryItemGUID);
        }
    }
    if (nResult)
    {
        return nResult;
    }

    if (!pInventoryItem)
    {
        return 2;
    }

    if (ITEMS_GetInvPage(pInventoryItem) == 1)
    {
        return 3;
    }
    if (ITEMS_GetInvPage(pInventoryItem) == 2)
    {
        return 3;
    }

    int bPlaced;
    if (sub_6FC7C3A0(pGame, pUnit, pInventoryItem) && !sub_6FC46D40(pGame, pUnit, nCursorItemGUID, nInventoryItemGUID, nX, nY, &bPlaced) && bPlaced)
    {

        SUNIT_GetServerUnit(pGame, 4, nCursorItemGUID);
        char szName[32];
        char szCursorItemName[32];
        D2_MAYBE_UNUSED(szName);
        D2_MAYBE_UNUSED(szCursorItemName);
        return 3;
    }

    return 0;
}
