struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC4];
    unsigned int dwFlagEx;
};

#define UNIT_PLAYER 0
#define UNIT_TYPES_COUNT 6
#define UNITFLAGEX_TELEPORTED 0x10000

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
int __stdcall UNITFINDS_AreUnitsInNeighboredRooms(D2UnitStrc* pDestUnit, D2UnitStrc* pSrcUnit);             // 0x0065A590

// 0x0054C6D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4B_RequestEntityUpdate_6FC880F0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    if (nUnitType >= UNIT_TYPES_COUNT)
    {
        return 2;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (nUnitType == UNIT_PLAYER && pTarget != pUnit)
    {
        return 3;
    }

    if (!pTarget)
    {
        return 1;
    }

    if (!UNITFINDS_AreUnitsInNeighboredRooms(pUnit, pTarget))
    {
        return 1;
    }

    UNITROOM_RefreshUnit(pTarget);
    pTarget->dwFlagEx |= UNITFLAGEX_TELEPORTED;
    return 0;
}
