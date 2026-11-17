extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;

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

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);               // 0x00552F60
void __fastcall sub_6FC7B450(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x005A5FF0
void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer);             // 0x0053DF00

// 0x00540180
static void __stdcall sub_00540180_FreeParty(D2PartyStrc* pParty, D2GameStrc* pGame)
{
    D2_ASSERT(pParty, 149);
    D2PartyNodeStrc* pNode = pParty->pPartyNodes;
    while (pNode)
    {
        D2UnitStrc* pMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pNode->nUnitGUID);
        D2_ASSERT(pMember, 154);
        sub_6FC7B450(pGame, pMember);
        D2GAME_PACKETS_SendPacket0x8D_6FC3F960(pMember, pMember);
        D2PartyNodeStrc* pNext = pNode->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pNode, ".\\UNIT\\Party.cpp", 162, 0);
        pNode = pNext;
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pParty, ".\\UNIT\\Party.cpp", 165, 0);
}

// 0x00540220
void __fastcall sub_00540220_RemoveParty(D2GameStrc* pGame, short nPartyId)
{
    D2PartyControlStrc* pPartyControl = pGame->pPartyControl;
    D2PartyStrc* pPrevious = 0;
    D2_ASSERT(pPartyControl, 180);
    for (D2PartyStrc* pParty = pPartyControl->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pParty->pNext;
            }
            else
            {
                pPartyControl->pParties = pParty->pNext;
            }
            sub_00540180_FreeParty(pParty, pGame);
            return;
        }
        pPrevious = pParty;
    }
}
