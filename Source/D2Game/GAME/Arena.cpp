#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define NUM_ARENA_SCORES 7

struct D2ArenaStrc;
struct D2ArenaUnitStrc;
struct D2PlayerDataStrc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2ArenaTxt;
struct D2ClientStrc;

struct D2ArenaStrc
{
    int nAlternateStartTown;
    int nType;
    unsigned int fFlags;
    int nTemplate;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2PlayerDataStrc
{
    char unk0x00[0x34];
    D2ArenaUnitStrc* pArenaUnit;
};


struct D2ArenaTxt
{
    int dwScores[7];
};

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    char unk0x008[0x4A0];
    D2ClientStrc* pNext;
};

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
unsigned int __fastcall sub_6FC33C10(D2ClientStrc* pClient); // 0x005388C0
void __fastcall D2GAME_PACKETS_SendPacket0x65_6FC3F5E0(D2ClientStrc* pClient, unsigned int dwPlayerId, unsigned short nCount); // 0x0053D9C0

// 0x0053F5D0
int __fastcall ARENA_GetAlternateStartTown(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 99);

    return pArena->nAlternateStartTown;
}

static D2ArenaStrc* ARENA_GetArenaCtrl_Inlined(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x6C);
    return pArena;
}

// 0x0053F630
static void __stdcall ARENA_UpdateScore(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int eScore)
{
    const int bAttackerIsPlayer = pAttacker && pAttacker->dwUnitType == UNIT_PLAYER;
    D2_ASSERT(bAttackerIsPlayer, 0x73);
    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pAttacker)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 0x77);
    D2ArenaTxt* pArenaTxtRecord = DATATBLS_GetArenaTxtRecord(ARENA_GetArenaCtrl_Inlined(pGame)->nType);
    D2_ASSERT(eScore < NUM_ARENA_SCORES, 0x7D);
    switch (eScore)
    {
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
        pArenaUnit->nScore += pArenaTxtRecord->dwScores[eScore];
        break;
    case 2:
    case 5:
    {
        D2ArenaUnitStrc* pSrcArenaUnit = UNITS_GetPlayerData(pDefender)->pArenaUnit;
        D2_ASSERT(pSrcArenaUnit, 0x8C);
        pArenaUnit->nScore += pSrcArenaUnit->nScore * pArenaTxtRecord->dwScores[eScore] / 100;
        break;
    }
    default:
        break;
    }
    pArenaUnit->bUpdateScore = 1;
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x94);
    pArena->fFlags |= GAMEFLAG_ARENA_UPDATE;
    UNITROOM_RefreshUnit(pDefender);
}

static __forceinline void ARENA_MarkUpdated(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x94);
    pArena->fFlags |= GAMEFLAG_ARENA_UPDATE;
}

static int UnitType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

// 0x0053F720
void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender)
{
 if(!pGame->pArenaCtrl) return;
 switch(UnitType(pAttacker))
 {
 case 0:
  D2_ASSERT(UNITS_GetPlayerData(pAttacker)->pArenaUnit,0xAC);
  if(pAttacker==pDefender)
  {
   ARENA_UpdateScore(pGame,pAttacker,pAttacker,0);
  }
  else if(pDefender)
  {
   if(pDefender->dwUnitType==0)
   {
    ARENA_UpdateScore(pGame,pAttacker,pDefender,1);
    ARENA_UpdateScore(pGame,pAttacker,pDefender,2);
    ARENA_UpdateScore(pGame,pDefender,pAttacker,4);
    ARENA_UpdateScore(pGame,pDefender,pAttacker,5);
   }
   else if(pDefender->dwUnitType==1)
   {
    ARENA_UpdateScore(pGame,pAttacker,pDefender,3);
   }
  }
  break;
 case 1:
  if(pDefender && UnitType(pDefender)==0)
   ARENA_UpdateScore(pGame,pDefender,pAttacker,6);
  break;
 }
}

void __fastcall sub_K10_EmitArenaUpdateScore(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    ARENA_UpdateScore(pGame, pAttacker, pDefender, 5);
}

// 0x0053FB00
static int sub_0053FB00_GetArenaUpdateScore(D2UnitStrc* pPlayer)
{
    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pPlayer)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 219);
    return pArenaUnit->bUpdateScore;
}

// 0x0053FB30
static void __stdcall sub_0053FB30_SendArenaScore(D2ClientStrc* pClient, D2UnitStrc* pPlayer)
{
    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pPlayer)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 229);
    D2GAME_PACKETS_SendPacket0x65_6FC3F5E0(pClient, !pPlayer ? -1 : pPlayer->dwUnitId, pArenaUnit->nScore);
}

// 0x0053FB90
static void __stdcall sub_0053FB90_SendArenaScores(D2GameStrc* pGame, int bAll, D2ClientStrc* pClient)
{
    D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    for (D2ClientStrc* i = pGame->pClientList; i; i = i->pNext)
    {
        D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (i->dwClientState == CLIENTSTATE_INGAME && pOtherPlayer)
        {
            if (bAll || (pOtherPlayer != pLocalPlayer && sub_0053FB00_GetArenaUpdateScore(pOtherPlayer)))
            {
                sub_0053FB30_SendArenaScore(pClient, pOtherPlayer);
            }
        }
    }
}

// 0x0053FC20
void __fastcall ARENA_SynchronizeWithClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    if (!pArena || !(pArena->fFlags & GAMEFLAG_ARENA_UPDATE))
    {
        return;
    }
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer && sub_0053FB00_GetArenaUpdateScore(pPlayer))
    {
        sub_0053FB30_SendArenaScore(pClient, pPlayer);
    }
    if (sub_6FC33C10(pClient))
    {
        sub_0053FB90_SendArenaScores(pGame, 0, pClient);
    }
}

// 0x0053FC70
void __fastcall ARENA_SendScoresToClient(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    sub_0053FB90_SendArenaScores(pGame, 1, pClient);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 1);
    if (pClient->dwClientState != CLIENTSTATE_INGAME && pPlayer)
    {
        sub_0053FB30_SendArenaScore(pClient, pPlayer);
    }
}

// 0x0053FD40
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 313);

    return pArena->fFlags;
}

// 0x0053FD70
unsigned int __fastcall sub_0053FD70(D2GameStrc* pGame, unsigned int nMask)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 323);

    return pArena->fFlags & nMask;
}

// 0x0053FDA0
void __fastcall sub_0053FDA0(D2GameStrc* pGame, unsigned int nFlags, int bSet)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 333);

    if (bSet)
    {
        pArena->fFlags |= nFlags;
    }
    else
    {
        pArena->fFlags &= ~nFlags;
    }
}
