// build: base-profile

struct D2UnitStrc;

struct D2GameStrc
{
    int sub_005490E0_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID);                                    // 0x005490E0
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pItemStatus); // 0x005606B0

// build: context PLRMSG_IsBodyLocValid
inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
}

#define D2_MAYBE_UNUSED(x) (void)(x)

// 0x0054AD90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem_6FC85280(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
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
    if (ITEMMODE_EquipCursorItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &a6) || !a6)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    char szName[32];
    D2_MAYBE_UNUSED(szName);
    return 3;
}
