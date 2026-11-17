extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PartyNodeStrc;

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

#define PARTY_FIRST_ID 3

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

// 0x005400B0
static short sub_005400B0_GetFreePartyId(D2GameStrc* pGame)
{
    D2PartyControlStrc* pPartyControl = pGame->pPartyControl;
    short nPartyId = pPartyControl->nNextPartyId;
    if ((unsigned short)nPartyId < PARTY_FIRST_ID)
    {
        nPartyId = PARTY_FIRST_ID;
    }

    for (;;)
    {
        D2PartyStrc* pCurrent = pPartyControl->pParties;
        while (pCurrent && pCurrent->nPartyId != nPartyId)
        {
            pCurrent = pCurrent->pNext;
        }

        if (!pCurrent)
        {
            break;
        }

        ++nPartyId;
        if ((unsigned short)nPartyId < PARTY_FIRST_ID)
        {
            nPartyId = PARTY_FIRST_ID;
        }
    }

    pPartyControl->nNextPartyId = nPartyId + 1;
    return nPartyId;
}

// 0x00540100
short __fastcall PARTY_CreateParty(D2GameStrc* pGame)
{
    D2PartyControlStrc* pPartyControl = pGame->pPartyControl;
    D2_ASSERT(pPartyControl, 0x7F);
    D2PartyStrc* pParty = (D2PartyStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2PartyStrc), ".\\UNIT\\Party.cpp", 0x80, 0);
    D2_ASSERT(pParty, 0x81);
    *pParty = D2PartyStrc();
    pParty->nPartyId = sub_005400B0_GetFreePartyId(pGame);
    pParty->pNext = pPartyControl->pParties;
    pPartyControl->pParties = pParty;
    return pParty->nPartyId;
}
