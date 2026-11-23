#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"

struct D2StaticPathStrc;


void __fastcall D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char nHitClass, unsigned char nLifePct); // 0x0053B430
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10
void __fastcall SCMD_SendUniqueMonsterInfo(D2ClientStrc* pClient, int a2, unsigned char a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7); // 0x0053D880
void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ClientStrc* pClient); // 0x00537680
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall SUNIT_SynchronizeRoomClients(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670
void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer); // 0x00571580
void __fastcall SUNITMSG_SendOverlay(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005715A0
void __fastcall SUNITMSG_SendHoverText(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740
void __fastcall SUNITMSG_SendQueuedMessages(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg); // 0x00597890
void __fastcall MONSTERMSG_SendMonsterModeUpdate(D2GameStrc* pGame, D2UnitStrc* pMonster, D2ClientStrc* pClient); // 0x00597E20
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

static inline int sub_F05_MsgGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_MsgGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_UnitFlagBit(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> nBit) & 1;
}

static inline int sub_F05_UnitFlagExBit(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> nBit) & 1;
}

static inline int sub_F05_MsgGetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// build: symbol ?MONSTERMSG_SendSummonerInfo@* 0x00597C70
static void __stdcall MONSTERMSG_SendSummonerInfo(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, 1))
    {
        return;
    }

    const unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const unsigned short nNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    const unsigned short nUMods = pUMods[0] | (pUMods[1] << 8);
    const unsigned short nUMod2 = pUMods[2];
    const unsigned short nChampion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 4);
    SCMD_SendUniqueMonsterInfo(pClient, sub_F05_MsgGetUnitId(pUnit), 1, nNameSeed, nUMods, nUMod2, nChampion);
}

// build: symbol ?MONSTERMSG_SendLifeUpdate@* 0x00597CF0
static void __stdcall MONSTERMSG_SendLifeUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const unsigned char nHitClass = pUnit->dwLastHitClass;
    unsigned char nHpPct = MONSTERMODE_GetHpPercent128(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_LAST_SENT_HP_PCT, nHpPct, 0);
    if (nHpPct > 1)
    {
        --nHpPct;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x100))
    {
        nHpPct |= 0x80;
    }

    const int nUnitGUID = (pUnit ? pUnit->dwUnitId : -1);
    D2ClientStrc* const pTarget = pClient;
    D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(pTarget, 0xC, 1, nUnitGUID, 19, nHitClass, nHpPct);
}

// 0x00598220
void __fastcall MONSTERMSG_SendMonsterUpdates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int bUnitInitialized)
{
    if (pUnit)
    {
        if (sub_F05_UnitFlagExBit(pUnit, 16))
        {
            const int nY = sub_F05_MsgGetUnitY(pUnit);
            const int nX = sub_F05_MsgGetUnitX(pUnit);
            const int nUnitGUID = (pUnit ? pUnit->dwUnitId : -1);
            const int nUnitType = (pUnit ? pUnit->dwUnitType : UNIT_INVALID);
            D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, 1);
            SUNIT_SynchronizeRoomClients(pGame, pUnit, 0);
        }

        if (sub_F05_UnitFlagBit(pUnit, 0))
        {
            MONSTERMSG_SendMonsterModeUpdate(pGame, pUnit, pClient);
        }

        pUnit->dwFlags &= ~0x80000;
    }

    SUNITMSG_SendQueuedMessages(pUnit, pClient);

    if (pUnit)
    {
        if (sub_F05_UnitFlagBit(pUnit, 8))
        {
            SUNITMSG_SendHoverText(pUnit, pClient);
        }

        if (sub_F05_UnitFlagExBit(pUnit, 0))
        {
            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pPlayer && MONSTERAI_IsTrading(pUnit, pPlayer))
            {
                SUNITPROXY_UpdateGambleInventory(pGame, pUnit, pPlayer, pClient);
            }
            else if (MONSTERS_GetHirelingTypeId(pUnit) && AIGENERAL_GetMinionOwner(pUnit) == pPlayer)
            {
                D2GAME_INVMODE_First_6FC40FB0(pGame, pUnit, pClient, 0);
            }
        }

        if (sub_F05_UnitFlagBit(pUnit, 10))
        {
            D2GAME_UpdateUnit_6FCC6080(pUnit, pClient);
        }

        if (sub_F05_UnitFlagBit(pUnit, 15))
        {
            MONSTERMSG_SendLifeUpdate(pUnit, pClient);
        }
    }

    if (!bUnitInitialized && STATES_IsAnyGfxStateFlagSet(pUnit))
    {
        D2GAME_STATES_SendStates_6FCC5F00(pUnit, pClient, 0);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pUnit))
    {
        SUNITMSG_SendOverlay(pUnit, pClient);
    }

    if (pUnit && sub_F05_UnitFlagBit(pUnit, 11))
    {
        MONSTERMSG_SendSummonerInfo(pClient, pUnit);
    }
}

// 0x005985C0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    return false;
}

void __cdecl sub_005BDB10_Return()
{
}
