#include "D2Game.h"

struct D2InteractInfoStrc;
struct D2PackedGuidStrc;
struct D2MessageStrc;
struct D2MessageListStrc;
struct D2GSPacketSrv27;
struct D2InteractionStrc;
struct D2InteractionListStrc;
struct D2MonsterDataStrc;
struct D2MercDataStrc;
struct D2HirelingInitStrc;
struct D2PetInfoStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    char unk0x18[0xAC];
    unsigned int dwFlags;
    char unk0xC8[0x08];
    int dwNodeIndex;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
};

struct D2InteractInfoStrc
{
    D2UnitStrc* pUnit;
    int nInteract;
    D2InteractInfoStrc* pNext;
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

struct D2PackedGuidStrc
{
    unsigned short f_0;
    unsigned short f_2;
};

struct D2MessageStrc
{
    unsigned char nMenu;
    unsigned char pad0x01;
    unsigned short nStringId;
};

struct D2MessageListStrc
{
    unsigned char nCount;
    unsigned char pad0x01;
    D2MessageStrc pMessages[8];
};

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    D2MessageListStrc messageList;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x00681CE0
extern "C" const char gszMonsterAISourceFile[]; // 0x006E1560
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl); // 0x00543D10
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00544520
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bNoInteractInfo); // 0x00576770
int __fastcall ACT1Q4_IsCainInTristramDeactivated(D2GameStrc* pGame); // 0x00594610
void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMsgList); // 0x00661480
static __declspec(noinline) int __stdcall sub_00572C10_StartNpcInteraction(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract, char nQuestFlags, D2UnitStrc* pTarget, D2UnitStrc* pUnit);

struct D2InteractionStrc
{
    D2UnitStrc* pUnit;
    int nState;
    D2InteractionStrc* pNext;
};

struct D2InteractionListStrc
{
    D2InteractionStrc* pFirst;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x04];
    unsigned char nComponent[16];
    unsigned char unk_14[0x1C];
    D2InteractionListStrc* pInteractions;
};

struct D2MercDataStrc
{
    unsigned short nMercName;
    unsigned short wPad;
    unsigned int dwSeed;
};

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int unk0x34[2];
};

struct D2PetInfoStrc
{
    unsigned int nSeed;
    int wName;
    int nHirelingId;
};

void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short a2, int a3); // 0x0053E0E0
void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignment, int a3); // 0x005543B0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int a3); // 0x005726C0
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMerc, int nLevel); // 0x00572840
D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitGUID, int a4); // 0x005750E0
void __fastcall PLAYERPETS_AddPetWithInfo(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, D2PetInfoStrc* pPetInfo); // 0x00575E90
void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bGuard, int a6); // 0x0058F030
void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int a4); // 0x005A4850
void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nVersion, unsigned short nMercName); // 0x00663750
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pPlayer, unsigned int nSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0

// 0x00572C10
static int __stdcall sub_00572C10_StartNpcInteraction(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract, char nQuestFlags, D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;

    if (SUNIT_GetInteractUnit(pGame, pUnit))
    {
        return 0;
    }

    if (!pTarget || !pTarget->dwAnimMode || pTarget->dwAnimMode == 0xC || PLAYER_IsBusy(pUnit) == 1)
    {
        return 0;
    }

    if (!sub_00457490_CheckMonStatsFlag(pTarget->dwClassId, 9))
    {
        return 1;
    }

    if (pTarget->dwClassId == 0x92 && ACT1Q4_IsCainInTristramDeactivated(pGame))
    {
        return 0;
    }

    for (; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pUnit)
        {
            return 1;
        }
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, gszMonsterAISourceFile, 0x1C4);
    D2InteractInfoStrc* pNewInteractInfo = (D2InteractInfoStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2InteractInfoStrc), gszMonsterAISourceFile, 0x1C7, 0);
    pNewInteractInfo->pUnit = pUnit;

    D2InteractInfoStrc* pFirstInteractInfo = pMonInteract->pInteractInfo;
    int bNoInteractInfo;
    if (!pFirstInteractInfo)
    {
        bNoInteractInfo = 1;
        pNewInteractInfo->pNext = pFirstInteractInfo;
    }
    else
    {
        bNoInteractInfo = 0;
        pNewInteractInfo->pNext = pFirstInteractInfo;
    }

    pMonInteract->pInteractInfo = pNewInteractInfo;

    D2GAME_NPC_BuildHirelingList_6FCC6FF0(CLIENTS_GetGame(pClient), pClient, pTarget, bNoInteractInfo);
    SUNIT_SetInteractInfo(pUnit, 1, !pTarget ? -1 : pTarget->dwUnitId);
    pNewInteractInfo->nInteract = 0;

    const D2GameStrc* pGame_v157 = pGame;
    D2TextHeaderStrc* pTextHeader = TEXT_AllocTextHeader(pGame_v157->pMemoryPool);
    QUESTS_NPCActivate(pClient, pUnit, pTarget, pTextHeader);

    D2GSPacketSrv27 packet27;
    memcpy(&packet27.dwUnitGUID, &pTarget->dwUnitId, sizeof(pTarget->dwUnitId));
    packet27.nHeader = 0x27;
    int nValue;
    if (!pTarget)
        nValue = 6;
    else
        nValue = pTarget->dwUnitType;
    packet27.nUnitType = nValue;
    TEXT_CreateMessageListFromTextHeader(pTextHeader, &packet27.messageList);
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
    TEXT_FreeTextHeader(pTextHeader);

    QUESTS_SendCurrentFlags(pGame, pClient);
    const int nTargetGUID = !pTarget ? -1 : pTarget->dwUnitId;
    D2GAME_SendPacket0x28_6FC3F2F0(pClient, 0x28, 1, nTargetGUID, sub_00543520(pGame, pUnit), nQuestFlags);
    return 0;
}

void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags)
{
    sub_00572C10_StartNpcInteraction(pGame, pMonInteract, nQuestFlags, pTarget, pUnit);
}

static __forceinline int GetUnitType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

inline D2InteractionListStrc* GetInteractions(D2UnitStrc* pUnit)
{
    if (GetUnitType(pUnit) == 1)
    {
        D2MonsterDataStrc* pData = pUnit->pMonsterData;
        return !pData ? 0 : pData->pInteractions;
    }
    return 0;
}

// 0x00572EA0
void __fastcall sub_00572EA0_AdvanceInteraction(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2InteractionListStrc* pList = GetInteractions(pUnit);
    D2InteractionStrc* pEntry = pList->pFirst;
    while (pEntry)
    {
        if (pEntry->pUnit == pTarget)
        {
            if (pEntry->nState == 1)
                pEntry->nState = 2;
            return;
        }
        pEntry = pEntry->pNext;
    }
}

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static __forceinline void MONSTER_SetComponent(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    if (sub_0044BE50(pUnit) == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nComponent[nComponent] = nValue;
        }
    }
}

// 0x00573270
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nSaveVersion, D2MercDataStrc* pMercData, int bDead)
{
    if (!pPlayer || !pUnit || !pMercData || pPlayer->dwUnitType != 0)
    {
        return;
    }

    pUnit->dwFlags |= 0x4020200;

    SUNIT_SetAlignment(pUnit, 2, 0);

    if (!bDead)
    {
        D2GAME_UpdateSummonAI_6FC401F0(pGame, pUnit, 0, pPlayer->dwNodeIndex);
    }

    D2UnitStrc* pPet = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 1);
    if (pPet)
    {
        D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(SUNIT_GetClientFromPlayer(pPlayer, gszMonsterAISourceFile, 0x52), 0xFFFF, 0);

        AIGENERAL_SetOwnerData(pGame, pPet, -1, 1, 0, 0);
        PLAYERPETS_RemovePet(pGame, pPlayer, UNITS_GetUnitId(pPet), 0);
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPet), 1, UNITS_GetUnitId(pPet));
        SUNIT_RemoveUnit(pGame, pPet);
    }

    D2HirelingInitStrc hirelingInit;
    D2PetInfoStrc petInfo;
    petInfo.nSeed = pMercData->dwSeed;
    petInfo.wName = pMercData->nMercName;
    const int nAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, pMercData->nMercName);
    const int nDifficulty = pGame->nDifficulty;
    if (!MONSTERS_HirelingInit(pGame->bExpansion, pPlayer, pMercData->dwSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    petInfo.nHirelingId = hirelingInit.nId;
    PLAYERPETS_AddPetWithInfo(pGame, pPlayer, pUnit, 7, &petInfo);

    pUnit->dwFlags |= 0x80000000;
    AIGENERAL_SetOwnerData(pGame, pUnit, pPlayer->dwUnitId, sub_0044BE50(pPlayer), 0, 0);

    if (nSaveVersion == 0xFFFF)
    {
        const int nLevel = hirelingInit.nLevel;
        const int nHirelingId = (unsigned short)hirelingInit.nId;
        if (!DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, hirelingInit.nLevel))
        {
            return;
        }

        STATLIST_SetUnitStat(pUnit, 13, hirelingInit.nExperience, 0);
        MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pUnit, nLevel);
        MONSTERAI_SendMercStats(pGame, pPlayer, 1);
    }

    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x13, 0);

    MONSTER_SetComponent(pUnit, 0, 0);
    MONSTER_SetComponent(pUnit, 5, 0);
    MONSTER_SetComponent(pUnit, 6, 0);
    MONSTER_SetComponent(pUnit, 7, 0);
    MONSTER_SetComponent(pUnit, 1, 0);
}
