#include "D2Game.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);                           // 0x005A5690
};

void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0053DA90
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B140
void __fastcall sub_6FCBA980(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3); // 0x0055B3A0

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005407A0
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg); // 0x005A5C70

// 0x005A5B30
void __fastcall PARTYSCREEN_InvitationCancelled(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (sub_6FCBA9D0(pPlayer1, pPlayer2) == 4)
    {
        if (SUNIT_GetPartyId(pPlayer2) == -1)
        {
            sub_6FCBA980(pPlayer1, pPlayer2, 0);
        }
        else
        {
            sub_6FCBA980(pPlayer1, pPlayer2, 1);
        }

        if (SUNIT_GetPartyId(pPlayer1) == -1)
        {
            sub_6FCBA980(pPlayer2, pPlayer1, 0);
        }
        else
        {
            sub_6FCBA980(pPlayer2, pPlayer1, 1);
        }

        SUNIT_GetClientFromPlayer(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 274)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 6);
    }

    sub_6FCBAA20(pPlayer1, pPlayer2);
    sub_6FCBAA20(pPlayer2, pPlayer1);
}

// 0x005A5CB0
void __fastcall sub_6FC7B460(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg)
{
    D2UnitStrc* pPlayer2 = (D2UnitStrc*)pArg;
    if (pPlayer1 == pPlayer2)
    {
        sub_6FCBA980(pPlayer1, pPlayer1, 1);
        SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer1);
    }
    else
    {
        sub_6FCBA980(pPlayer1, pPlayer2, 0);
        if (SUNIT_GetPartyId(pPlayer1) == -1)
        {
            sub_6FCBA980(pPlayer2, pPlayer1, 0);
        }
        else
        {
            sub_6FCBA980(pPlayer2, pPlayer1, 1);
        }

        SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
        SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
    }
}

// 0x005A5D20
void __fastcall PARTYSCREEN_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer1);
    PARTY_IteratePartyMembers(pGame, nPartyId, PARTYSCREEN_PartyIterate_PlayerLeftParty, pPlayer1);
    PARTY_LeaveParty(pGame, pPlayer1);
}
