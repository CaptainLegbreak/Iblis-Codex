#include "D2Game.h"

struct D2StaticPathStrc;

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int nTargetX;
    int nTargetY;
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x1C];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x80];
    unsigned char dwLastHitClass;
    char unk0xB1[0x13];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

void __fastcall D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char nHitClass, unsigned char nLifePct); // 0x0053B430
void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10
void __fastcall sub_6FC3F4D0(D2ClientStrc* pClient, int a2, unsigned char a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7); // 0x0053D880
void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ClientStrc* pClient); // 0x00537680
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
void __fastcall sub_00554670_UpdateClientsOnRoomChange(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670
void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer); // 0x00571580
void __fastcall sub_6FCC5F20(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005715A0
void __fastcall sub_00571620(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740
void __fastcall sub_6FCC6540(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0
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

static void __stdcall sub_00597CF0_SendLifeUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient);

static __forceinline int sub_F05_MsgGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_F05_MsgGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_F05_UnitFlagBit(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> nBit) & 1;
}

static __forceinline int sub_F05_UnitFlagExBit(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> nBit) & 1;
}

static __forceinline int sub_F05_MsgGetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x00597C70
static void __stdcall sub_00597C70_SendSummonerInfo(D2ClientStrc* pClient, D2UnitStrc* pUnit)
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
    sub_6FC3F4D0(pClient, sub_F05_MsgGetUnitId(pUnit), 1, nNameSeed, nUMods, nUMod2, nChampion);
}

void __fastcall MONSTERMSG_SendMonsterUpdates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int bUnitInitialized)
{
    if (pUnit)
    {
        if (sub_F05_UnitFlagExBit(pUnit, 16))
        {
            D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, pUnit->dwUnitType, pUnit->dwUnitId, sub_F05_MsgGetUnitX(pUnit), sub_F05_MsgGetUnitY(pUnit), 1);
            sub_00554670_UpdateClientsOnRoomChange(pGame, pUnit, 0);
        }

        if (sub_F05_UnitFlagBit(pUnit, 0))
        {
            MONSTERMSG_SendMonsterModeUpdate(pGame, pUnit, pClient);
        }

        pUnit->dwFlags &= ~0x80000;
    }

    sub_6FCC6540(pUnit, pClient);

    if (pUnit)
    {
        if (sub_F05_UnitFlagBit(pUnit, 8))
        {
            sub_00571620(pUnit, pClient);
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
            sub_00597CF0_SendLifeUpdate(pUnit, pClient);
        }
    }

    if (!bUnitInitialized && STATES_IsAnyGfxStateFlagSet(pUnit))
    {
        D2GAME_STATES_SendStates_6FCC5F00(pUnit, pClient, 0);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pUnit))
    {
        sub_6FCC5F20(pUnit, pClient);
    }

    if (pUnit && sub_F05_UnitFlagBit(pUnit, 11))
    {
        sub_00597C70_SendSummonerInfo(pClient, pUnit);
    }
}

// 0x00597CF0
static void __stdcall sub_00597CF0_SendLifeUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const unsigned char nHitClass = pUnit->dwLastHitClass;
    unsigned char nHpPct = MONSTERMODE_GetHpPercent128(pUnit);
    STATLIST_SetUnitStat(pUnit, 0x160, nHpPct, 0);
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
