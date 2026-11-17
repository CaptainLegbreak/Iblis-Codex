struct D2GameStrc;
struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x7C];
    D2GameStrc* pGame;
};
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540710
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00650D70
static __forceinline int UNIT_TypeOrInvalid(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }
static __forceinline unsigned short SUNIT_GetPartyId_Inline(D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->pGame && pPlayer->dwUnitType == 0)
        return PARTY_GetPartyIdForUnitOwner(pPlayer->pGame, pPlayer);
    return 0xFFFF;
}

// 0x00554DE0
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    if (pUnit1 && pUnit1->dwUnitType == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit1);
        if (pOwner)
        {
            pUnit1 = pOwner;
        }
    }
    if (pUnit2 && (!pUnit2 ? 6 : pUnit2->dwUnitType) == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit2);
        if (pOwner)
        {
            pUnit2 = pOwner;
        }
    }
    if (pUnit1 == pUnit2)
    {
        return 1;
    }
    if (UNIT_TypeOrInvalid(pUnit1) == 0 && UNIT_TypeOrInvalid(pUnit2) == 0)
    {
        const unsigned int nPartyId1 = SUNIT_GetPartyId_Inline(pUnit1);
        const unsigned int nPartyId2 = SUNIT_GetPartyId_Inline(pUnit2);
        return nPartyId1 == nPartyId2 && nPartyId2 != 0xFFFF;
    }
    return STATLIST_AreUnitsAligned(pUnit1, pUnit2);
}
