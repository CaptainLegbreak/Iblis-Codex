#include "D2Game.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ArenaUnitStrc
{
    int nScore;
    int bUpdateScore;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x34];
    D2ArenaUnitStrc* pArenaUnit;
};

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2ArenaStrc
{
    int nAlternateStartTown;
    int nType;
    unsigned int fFlags;
};

struct D2GameStrc
{
    char unk0x0000[0x1D28];
    D2ArenaStrc* pArenaCtrl;
};

struct D2ArenaTxt
{
    int dwScores[7];
};

#define UNIT_PLAYER 0
#define NUM_ARENA_SCORES 7
#define GAMEFLAG_ARENA_UPDATE 0x400

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

static D2ArenaStrc* ARENA_GetArenaCtrl_Inlined(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x6C);
    return pArena;
}

static __forceinline void ARENA_MarkUpdated(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x94);
    pArena->fFlags |= GAMEFLAG_ARENA_UPDATE;
}

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
    ARENA_MarkUpdated(pGame);
    UNITROOM_RefreshUnit(pDefender);
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
