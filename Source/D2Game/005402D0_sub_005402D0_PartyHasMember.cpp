extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
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

#define UNIT_PLAYER 0
#define UNIT_INVALID 6

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
void __fastcall sub_6FC3F8F0(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x0053DEC0
void __fastcall FRIENDLY_RemoveHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);    // 0x005A6080

// 0x005402D0
static int sub_005402D0_PartyHasMember(D2PartyStrc* pParty, int nUnitGUID)
{
    D2_ASSERT(pParty, 229);
    for (D2PartyNodeStrc* pNode = pParty->pPartyNodes; pNode; pNode = pNode->pNext)
    {
        if (pNode->nUnitGUID == nUnitGUID)
        {
            return 1;
        }
    }
    return 0;
}

static D2PartyStrc* sub_M08_FindPartyById(D2PartyControlStrc* pPartyControl, short nPartyId)
{
    for (D2PartyStrc* pParty = pPartyControl->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            return pParty;
        }
    }
    return 0;
}

int __fastcall sub_00540320(D2GameStrc* pGame, short nPartyId, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pGame->pPartyControl, 210);
    D2PartyStrc* pParty = sub_M08_FindPartyById(pGame->pPartyControl, nPartyId);
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2_ASSERT(pParty, 254);
    const int nType = pPlayer ? pPlayer->dwUnitType : UNIT_INVALID;
    D2_ASSERT(pPlayer && nType == UNIT_PLAYER, 255);
    if (sub_005402D0_PartyHasMember(pParty, nUnitGUID))
    {
        return 1;
    }
    D2PartyNodeStrc* pPartyNode = (D2PartyNodeStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2PartyNodeStrc), ".\\UNIT\\Party.cpp", 264, 0);
    D2_ASSERT(pPartyNode, 265);
    pPartyNode->nUnitGUID = 0;
    pPartyNode->pNext = 0;
    pPartyNode->nUnitGUID = nUnitGUID;
    pPartyNode->pNext = pParty->pPartyNodes;
    pParty->pPartyNodes = pPartyNode;
    sub_6FC3F8F0(pGame, pPlayer);
    for (D2PartyNodeStrc* i = pPartyNode->pNext; i; i = i->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, i->nUnitGUID);
        if (pPartyMember)
        {
            FRIENDLY_RemoveHostility(pGame, pPlayer, pPartyMember);
            FRIENDLY_RemoveHostility(pGame, pPartyMember, pPlayer);
        }
    }
    return 1;
}
