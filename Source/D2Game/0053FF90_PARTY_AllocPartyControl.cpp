extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define D2PartyIdNone 0xFFFF

struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
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
    short nNextPartyId;
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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory);                                            // 0x0063D450

static D2PartyStrc* PARTY_FindParty_Inlined(D2GameStrc* pGame, short nPartyId)
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

// 0x0053FF90
void __fastcall PARTY_AllocPartyControl(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x18);
    D2_ASSERT(!pGame->pPartyControl, 0x19);

    D2PartyControlStrc* pPartyControl = (D2PartyControlStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PartyControlStrc), ".\\UNIT\\Party.cpp", 0x1A, 0);
    D2_ASSERT(pPartyControl, 0x1B);

    memset(pPartyControl, 0, sizeof(D2PartyControlStrc));
    pPartyControl->nNextPartyId = 3;

    pGame->pPartyControl = pPartyControl;
}

// 0x00540460
int __fastcall sub_00540460_GetPartyMemberCount(D2GameStrc* pGame, short nPartyId)
{
    D2PartyStrc* pParty = PARTY_FindParty_Inlined(pGame, nPartyId);
    int nCount = 0;
    if (!pParty)
    {
        return -1;
    }

    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        ++nCount;
    }

    return nCount;
}

// 0x00540710
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    if (pUnit->pInventory)
    {
        nUnitGUID = INVENTORY_GetOwnerId(pUnit->pInventory);
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x27B);
    D2_ASSERT(pGame, 0x27C);

    if (!pGame->pPartyControl)
    {
        return D2PartyIdNone;
    }

    for (D2PartyStrc* pParty = pGame->pPartyControl->pParties; pParty; pParty = pParty->pNext)
    {
        for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
        {
            if (pPartyNode->nUnitGUID == nUnitGUID)
            {
                return pParty->nPartyId;
            }
        }
    }

    return D2PartyIdNone;
}
