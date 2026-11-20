#include "D2Game.h"
#include "D2Structs.h"
struct D2GameStrc;

struct D2PartyScreenCallbackStrc;
struct Client;
struct PartyArgs;
struct D2UnitStrc;
struct D2ClientStrc;
struct Unit;


struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);                           // 0x005A5690
};

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag); // 0x00538670
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B140
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags, int bSet); // 0x0055B260
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0053DA90

struct D2PartyScreenCallbackStrc
{
    D2UnitStrc* pPlayer1;
    D2UnitStrc* pPlayer2;
    unsigned short nPartyId;
};

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
void __fastcall sub_6FCBA980(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3); // 0x0055B3A0
void __fastcall sub_6FC3F8F0(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0053DEC0

struct Unit { int type, classId; void* pool; int id; };

struct Client { void sub_005A5690(int unitId, unsigned char type); };

struct PartyArgs { Unit* target; Unit* player; unsigned short f_8; };

unsigned short __fastcall sub_00554630(Unit*); // 0x00554630
void __fastcall sub_0055B140(Game*,Unit*,Unit*); // 0x0055B140
short __fastcall sub_0055B3F0(Unit*,Unit*); // 0x0055B3F0
void __fastcall sub_0055B440(Unit*,Unit*); // 0x0055B440
short __fastcall sub_00540100(Game*); // 0x00540100
int __fastcall sub_00540320(Game*,short,Unit*); // 0x00540320
void __fastcall sub_0055B650(Game*,Unit*); // 0x0055B650
Client* __fastcall sub_005531C0(Unit*,const char*,int); // 0x005531C0
void __fastcall sub_005A5970(Game*,Unit*,void*); // 0x005A5970

typedef void (__fastcall *Iterator)(Game*,Unit*,void*);

void __fastcall sub_005538D0(Game*,Iterator,void*); // 0x005538D0

enum { JOIN_RELATION = 2 };

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005407A0
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg); // 0x005A5C70

// 0x005A5750
static void __stdcall sub_005A5750_SetPlayerListFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned short nFlag, int nParam)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);
    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, nFlag) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, nFlag, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

static bool IsFemaleClass(D2UnitStrc* pUnit)
{
    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0:
    case 1:
    case 6:
        return true;
    }
    return false;
}

// 0x005A57B0
void __fastcall PARTYSCREEN_ToggleLootability(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    if (!CLIENTS_CheckFlag(UnitGetClient(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 74), 4))
    {
        return;
    }

    sub_005A5750_SetPlayerListFlag(pGame, pPlayer1, pPlayer2, 1, nParam);

    int nType;
    if (pPlayer1 && IsFemaleClass(pPlayer1))
    {
        nType = nParam != 0 ? 2 : 11;
    }
    else
    {
        nType = nParam != 0 ? 1 : 10;
    }

    UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 101)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, nType);
}

// 0x005A5900
static void sub_005A5900_PARTYSCREEN_UpdateRelation(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer)
{
    const int nLocalGUID = !pLocalPlayer ? -1 : pLocalPlayer->dwUnitId;
    const int nOtherGUID = !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId;

    if (nLocalGUID == nOtherGUID)
    {
        return;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pLocalPlayer);
    if (nPartyId == 0xFFFF)
    {
        if (sub_6FCBA9D0(pOtherPlayer, pLocalPlayer) == 4)
        {
            sub_6FCBA980(pLocalPlayer, pOtherPlayer, 2);
        }
        else
        {
            sub_6FCBA980(pOtherPlayer, pLocalPlayer, 0);
            sub_6FCBA980(pLocalPlayer, pOtherPlayer, 1);
        }
    }
    else
    {
        sub_6FCBA980(pOtherPlayer, pLocalPlayer, 1);
        sub_6FCBA980(pLocalPlayer, pOtherPlayer, 1);
    }
}

// 0x005A5970
void __fastcall sub_6FC7AED0(D2GameStrc* pGame, D2UnitStrc* pLocalPlayer, void* a3)
{
    D2PartyScreenCallbackStrc* pArg = (D2PartyScreenCallbackStrc*)a3;

    const unsigned short nPartyId = SUNIT_GetPartyId(pLocalPlayer);
    PLAYERLIST_AllocPlayerList(pGame, pLocalPlayer, pArg->pPlayer1);
    PLAYERLIST_AllocPlayerList(pGame, pArg->pPlayer1, pLocalPlayer);
    PLAYERLIST_AllocPlayerList(pGame, pLocalPlayer, pArg->pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pArg->pPlayer2, pLocalPlayer);

    sub_005A5900_PARTYSCREEN_UpdateRelation(pLocalPlayer, pArg->pPlayer1);
    sub_005A5900_PARTYSCREEN_UpdateRelation(pLocalPlayer, pArg->pPlayer2);

    if (nPartyId == pArg->nPartyId && nPartyId != 0xFFFF && pLocalPlayer != pArg->pPlayer2)
    {
        UnitGetClient(pLocalPlayer, ".\\PLAYER\\PartyScreen.cpp", 183)->PARTYSCREEN_SendEventUpdateToClient(!pArg->pPlayer2 ? -1 : pArg->pPlayer2->dwUnitId, 7);
    }

    sub_6FCBAA20(pLocalPlayer, pArg->pPlayer1);
    sub_6FCBAA20(pLocalPlayer, pArg->pPlayer2);
    sub_6FC3F8F0(pGame, pLocalPlayer);
}

// 0x005A5A30
void __fastcall sub_005A5A30(Game* game,Unit* player,Unit* target,int param,int* failure)
{
    unsigned short partyId=sub_00554630(target);
    sub_0055B140(game,player,target);
    sub_0055B140(game,target,player);
    if(sub_0055B3F0(player,target)!=JOIN_RELATION) {
        sub_0055B440(target,player);
        sub_0055B440(player,target);
        return;
    }
    if(partyId==0xFFFF) {
        partyId=sub_00540100(game);
        sub_00540320(game,partyId,target);
        sub_00540320(game,partyId,player);
        sub_0055B650(game,target);
    } else {
        sub_00540320(game,partyId,player);
    }
    sub_0055B650(game,player);
    sub_005531C0(player,".\\PLAYER\\PartyScreen.cpp",233)->sub_005A5690(!target ? -1 : target->id,8);
    PartyArgs args=PartyArgs();
    args.target=target;
    args.player=player;
    args.f_8=partyId;
    sub_005538D0(game,sub_005A5970,&args);
}

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

        UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 274)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 6);
    }

    sub_6FCBAA20(pPlayer1, pPlayer2);
    sub_6FCBAA20(pPlayer2, pPlayer1);
}

// 0x005A5BE0
void __fastcall PARTYSCREEN_ReceivedInvitation(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (sub_6FCBA9D0(pPlayer1, pPlayer2))
    {
        sub_6FCBAA20(pPlayer1, pPlayer2);
        sub_6FCBAA20(pPlayer2, pPlayer1);
        return;
    }

    sub_6FCBA980(pPlayer1, pPlayer2, 4);
    sub_6FCBA980(pPlayer2, pPlayer1, 2);

    UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 306)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 5);

    sub_6FCBAA20(pPlayer1, pPlayer2);
    sub_6FCBAA20(pPlayer2, pPlayer1);
}

// 0x005A5C70
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg)
{
    D2UnitStrc* pPlayer2 = (D2UnitStrc*)pArg;
    if (pPlayer1 != pPlayer2)
    {
        UnitGetClient(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 323)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer2 ? -1 : pPlayer2->dwUnitId, 9);
    }
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
