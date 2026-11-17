struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x5C];
    D2InventoryStrc* pInventory;
};

struct D2GameStrc
{
    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x005490E0
};

int __fastcall sub_6FC7C3A0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);                     // 0x00535610
int __fastcall sub_00561220_SwapDualWieldedItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int* pFailure); // 0x00561220
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0

#define BODYLOC_RARM 4
#define BODYLOC_LARM 5

inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
}

// 0x0054B030
int __fastcall sub_0054B030_SwapDualWieldedItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = *(int*)((char*)pPacket + 1);
    const unsigned char nBodyLoc = *((unsigned char*)pPacket + 5);
    int nResult = pGame->sub_005490E0_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    const int nLoc = nBodyLoc;
    if (!PLRMSG_IsBodyLocValid(nLoc))
    {
        return 2;
    }

    if (nLoc != BODYLOC_RARM && nLoc != BODYLOC_LARM)
    {
        return 3;
    }

    nResult = (INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nLoc) ? -1 : 0) + 1;
    if (nResult)
    {
        return nResult;
    }

    if (!sub_6FC7C3A0(pGame, pUnit, INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nLoc)))
    {
        return 0;
    }

    int nFailure;
    if (sub_00561220_SwapDualWieldedItem(pGame, pUnit, nItemGUID, nBodyLoc, &nFailure) || !nFailure)
    {
        return 0;
    }

    return 3;
}
