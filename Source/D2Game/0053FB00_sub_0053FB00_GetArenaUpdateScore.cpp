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
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2ClientStrc
{
    unsigned int dwClientId;
    int dwClientState;
    char unk0x008[0x4A0];
    D2ClientStrc* pNext;
};

struct D2ArenaStrc
{
    int nAlternateStartTown;
    int nType;
    unsigned int fFlags;
};

struct D2GameStrc
{
    char unk0x0000[0x88];
    D2ClientStrc* pClientList;
    char unk0x008C[0x1C9C];
    D2ArenaStrc* pArenaCtrl;
};

#define CLIENTSTATE_INGAME 4
#define GAMEFLAG_ARENA_UPDATE 0x400

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
unsigned int __fastcall sub_6FC33C10(D2ClientStrc* pClient);                                                // 0x005388C0
void __fastcall D2GAME_PACKETS_SendPacket0x65_6FC3F5E0(D2ClientStrc* pClient, unsigned int dwPlayerId, unsigned short nCount); // 0x0053D9C0

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
