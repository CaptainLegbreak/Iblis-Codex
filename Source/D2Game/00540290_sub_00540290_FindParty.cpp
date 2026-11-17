extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc;
struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2PartyNodeStrc
{
    int nUnitGUID;
    D2PartyNodeStrc* pNext;
};

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

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x1D0C];
    D2PartyControlStrc* pPartyControl;
};

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

#define UNIT_PLAYER 0
#define D2PartyIdNone 0xFFFF

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                            // 0x00554630
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit);                                     // 0x0053CDF0
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);               // 0x00540710
void __fastcall sub_6FC7B450(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005A5FF0
void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer);             // 0x0053DF00
int __fastcall sub_00540460_GetPartyMemberCount(D2GameStrc* pGame, short nPartyId);                         // 0x00540460
void __fastcall sub_00540220_RemoveParty(D2GameStrc* pGame, short nPartyId);                                // 0x00540220

// 0x00540290
static D2PartyStrc* sub_00540290_FindParty(D2GameStrc* pGame, short nPartyId)
{
    D2_ASSERT(pGame->pPartyControl, 210);
    for (D2PartyStrc* pParty = pGame->pPartyControl->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            return pParty;
        }
    }
    return 0;
}

// 0x005405A0
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

// 0x005406A0
void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\UNIT\\Party.cpp", 591);
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
    D2_ASSERT(pUnit, 304);
    const int nUnitGUID = pUnit->dwUnitId;
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 304);
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
