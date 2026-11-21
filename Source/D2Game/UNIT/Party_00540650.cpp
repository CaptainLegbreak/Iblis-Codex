#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


struct D2PartyStrc
{
    short nPartyId;
    short field_2;
    D2PartyNodeStrc* pPartyNodes;
    D2PartyStrc* pNext;
};

struct D2PartyControlStrc
{
    short field_0;
    short field_2;
    D2PartyStrc* pParties;
};


typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

#define UNIT_PLAYER 0
#define UNIT_INVALID 6
#define STAT_GOLD 14

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits);           // 0x005404F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit);                                     // 0x0053CDF0
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);               // 0x00540710
void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer);             // 0x0053DF00
int __fastcall sub_00540460_GetPartyMemberCount(D2GameStrc* pGame, short nPartyId);                         // 0x00540460
void __fastcall sub_00540220_RemoveParty(D2GameStrc* pGame, short nPartyId);                                // 0x00540220
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0

void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    const int nNewValue = STATLIST_UnitGetStatValue(pUnit, nStat, 0) + nValue;
    if (nNewValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nNewValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;

        case STAT_GOLDBANK:
            if (nNewValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
}

// 0x00540290
static D2PartyStrc* sub_00540290_FindParty(D2GameStrc* pGame, short nPartyId)
{
    D2_ASSERT(pGame->hParty, 210);
    for (D2PartyStrc* pParty = pGame->hParty->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            return pParty;
        }
    }
    return 0;
}

void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        pCallback(pGame, pUnit, pArgs);
        return;
    }
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId == D2PartyIdNone)
    {
        pCallback(pGame, pUnit, pArgs);
        return;
    }
    D2PartyStrc* pParty = sub_00540290_FindParty(pGame, nPartyId);
    if (!pParty)
    {
        return;
    }
    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
        if (pPartyMember)
        {
            D2ActiveRoomStrc* pPartyMemberRoom = UNITS_GetRoom(pPartyMember);
            if (pPartyMemberRoom && DUNGEON_GetLevelIdFromRoom(pPartyMemberRoom) == nLevelId)
            {
                pCallback(pGame, pPartyMember, pArgs);
            }
        }
    }
}

static inline int PARTY_GetLivingUnitsInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLivingUnits = 0;
    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, PARTY_CountLivingUnits, &nLivingUnits);
    return nLivingUnits;
}

// 0x00540650
static void __stdcall PARTY_CalculatePickAndDrop(int* pGoldToPick, int* pGoldToDrop, D2UnitStrc* pUnit, int nValue)
{
    const int nGoldLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    *pGoldToDrop = 0;
    *pGoldToPick = nValue;
    if (nGold + nValue > nGoldLimit)
    {
        *pGoldToPick = nGoldLimit - nGold;
        *pGoldToDrop = nValue - *pGoldToPick;
    }
}

void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\UNIT\\Party.cpp", 591);
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId == D2PartyIdNone)
    {
        return;
    }
    D2PartyStrc* pParty = sub_00540290_FindParty(pGame, nPartyId);
    if (!pParty)
    {
        return;
    }
    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
        if (pPartyMember && pPartyMember != pUnit)
        {
            sub_6FC3E200(pClient, pPartyMember);
        }
    }
}

void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2PartyNodeStrc* pPreviousPartyNode = 0;
    int nUnitGUID;
    const int nType = pUnit ? (nUnitGUID = pUnit->dwUnitId, pUnit->dwUnitType) : UNIT_INVALID;
    D2_ASSERT(nType == UNIT_PLAYER, 304);
    const unsigned short nPartyId = PARTY_GetPartyIdForUnitOwner(pGame, pUnit);
    if (nPartyId == D2PartyIdNone)
    {
        return;
    }
    D2PartyStrc* pParty = sub_00540290_FindParty(pGame, nPartyId);
    D2_ASSERT(pParty, 312);
    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        if (pPartyNode->nUnitGUID == nUnitGUID)
        {
            if (pPreviousPartyNode)
            {
                pPreviousPartyNode->pNext = pPartyNode->pNext;
            }
            else
            {
                pParty->pPartyNodes = pPartyNode->pNext;
            }
            sub_6FC7B450(pGame, pUnit);
            D2GAME_PACKETS_SendPacket0x8D_6FC3F960(pUnit, pUnit);
            FOG_FreeServerMemory(pGame->pMemoryPool, pPartyNode, ".\\UNIT\\Party.cpp", 328, 0);
            break;
        }
        pPreviousPartyNode = pPartyNode;
    }
    if (sub_00540460_GetPartyMemberCount(pGame, nPartyId) <= 1)
    {
        sub_00540220_RemoveParty(pGame, nPartyId);
    }
}

int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGoldValue)
{
    const int nLivingUnits = PARTY_GetLivingUnitsInSameLevel(pGame, pUnit);
    if (nLivingUnits <= 1)
    {
        int nGoldToPick;
        int nGoldToDrop;
        PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pUnit, nGoldValue);
        PLRTRADE_AddGold(pUnit, STAT_GOLD, nGoldToPick);
        return nGoldToDrop;
    }

    const int nPartyId = SUNIT_GetPartyId(pUnit);
    D2PartyStrc* pParty = sub_00540290_FindParty(pGame, nPartyId);
    if (!pParty)
    {
        int nGoldToPick;
        int nGoldToDrop;
        PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pUnit, nGoldValue);
        PLRTRADE_AddGold(pUnit, STAT_GOLD, nGoldToPick);
        return nGoldToDrop;
    }

    const int nDividedGold = nGoldValue / nLivingUnits;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
        if (pPartyMember && pPartyMember != pUnit)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPartyMember);
            if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == nLevelId && sub_00451F70_GetUnitMode(pUnit) != 0 && sub_00451F70_GetUnitMode(pUnit) != 17)
            {
                int nGoldToPick = 0;
                int nGoldToDrop = 0;
                PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pPartyMember, nDividedGold);
                PLRTRADE_AddGold(pPartyMember, STAT_GOLD, nGoldToPick);
                nGoldValue += nGoldToDrop - nDividedGold;
            }
        }
    }

    int nGoldToPick;
    int nGoldToDrop;
    PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pUnit, nGoldValue);
    PLRTRADE_AddGold(pUnit, STAT_GOLD, nGoldToPick);
    return nGoldToDrop;
}
