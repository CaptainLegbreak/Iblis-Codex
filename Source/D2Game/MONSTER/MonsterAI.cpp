#include "D2Game.h"

#define PETTYPE_HIREABLE 7
#define STAT_STRENGTH 0
#define STAT_DEXTERITY 2
#define STAT_HITPOINTS 6
#define STAT_MAXHP 7
#define STAT_LEVEL 12
#define STAT_EXPERIENCE 13
#define STAT_NEXTEXP 30
#define STAT_ARMORCLASS 31
#define STAT_MINDAMAGE 21
#define STAT_MAXDAMAGE 22
#define STAT_SECONDARY_MINDAMAGE 23
#define STAT_SECONDARY_MAXDAMAGE 24
#define STAT_FIRERESIST 39
#define STAT_LIGHTRESIST 41
#define STAT_COLDRESIST 43
#define STAT_POISONRESIST 45
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define MONSTATSFLAGINDEX_SWITCHAI 16
struct D2InteractInfoStrc;
struct D2PetInfoStrc;
struct D2SkillsTxt;
struct Node00572DA0;
struct List00572DA0;
struct Node00572DC0;
struct List00572DC0;
struct Node00572DE0;
struct List00572DE0;
struct D2MonsterDataStrc;
struct D2PackedGuidStrc;
struct D2MessageStrc;
struct D2MessageListStrc;
struct D2GSPacketSrv27;
struct D2MonStatsTxt;

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    unsigned char unk_20[0x4D];
    unsigned char nDifficulty;
    unsigned char unk_6E[0x2];
    int bExpansion;
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
};

void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc* pUnit, unsigned short nStatId, int nValue); // 0x005718C0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

struct D2PetInfoStrc
{
    char unk0x00[0x08];
    int nHirelingId;
};

struct D2SkillsTxt
{
    char unk0x000[0x174];
    short wReqLevel;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
    unsigned char unk_A84[0x11C];
    int nSkillsTxtRecordCount;
};

struct D2HirelingTxt
{
    char unk0x00[0x1C];
    int nHirelingLevel;
    int dwExpPerLvl;
    int dwHitpoints;
    int dwHitpointsPerLvl;
    int dwDefense;
    int dwDefensePerLvl;
    int nStr;
    int nStrPerLvl;
    int nDex;
    int nDexPerLvl;
    int dwAttackRate;
    int dwAttackRatePerLvl;
    int dwShare;
    int nDmgMin;
    int nDmgMax;
    int nDmgPerLvl;
    int dwResist;
    int dwResistPerLvl;
    char unk0x64[0x14];
    int dwSkill[6];
    char unk0x90[0x30];
    signed char nMode[6];
    signed char nLevel[6];
    signed char nSLvlPerLvl[6];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall AITACTICS_AddMessage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScrollTarget, unsigned short wMessage, int bScrollMessage); // 0x005DE330
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00574BD0
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

struct D2InteractInfoStrc
{
    D2UnitStrc* pUnit;
    int nInteract;
    D2InteractInfoStrc* pNext;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

struct Node00572DA0 {
    unsigned int dwValue00;
    unsigned int dwUnknown04;
    Node00572DA0* pNext;
};

struct List00572DA0 {
    Node00572DA0* pHead;
};

struct Node00572DC0 {
    unsigned int dwValue00;
    unsigned int dwUnknown04;
    Node00572DC0* pNext;
};

struct List00572DC0 {
    Node00572DC0* pHead;
};

struct Node00572DE0 { int nId; unsigned int dwUnknown04; Node00572DE0* pNext; };

struct List00572DE0 { Node00572DE0* pHead; };

struct D2MonsterDataStrc
{
    D2MonStatsTxt* pMonstatsTxt;
    char unk0x04[0x2C];
    D2MonsterInteractStrc* pMonInteract;
    union
    {
        int nAiValue;
        int unk0x34;
    };
    union
    {
        int nAiState;
        int unk0x38;
    };
};

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
void __fastcall sub_6FC3F340(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5); // 0x0053D6D0
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
void __fastcall D2GAME_NPC_Heal_6FCCB220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00578E70
void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00543D50
int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID); // 0x00554100
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00537190

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
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0
void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0
void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl); // 0x00543D10
void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00544520
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bNoInteractInfo); // 0x00576770
int __fastcall ACT1Q4_IsCainInTristramDeactivated(D2GameStrc* pGame); // 0x00594610
void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMsgList); // 0x00661480

struct D2MonStatsTxt
{
    char unk0x00[0x0C];
    unsigned char nMonStatsFlags[4];
    unsigned char unk_10[0x90];
    unsigned char nDrain[3];
    unsigned char unk_A3[0x105];
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

// 0x005726C0
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3)
{
    D2UnitStrc* pMerc = sub_6FC7E8B0(pGame, pPlayer, PETTYPE_HIREABLE, 0);
    if (!pMerc)
    {
        return;
    }

    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_LEVEL, STATLIST_UnitGetStatValue(pMerc, STAT_LEVEL, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_STRENGTH, STATLIST_GetUnitBaseStat(pMerc, STAT_STRENGTH, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_DEXTERITY, STATLIST_GetUnitBaseStat(pMerc, STAT_DEXTERITY, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MAXHP, STATLIST_GetUnitBaseStat(pMerc, STAT_MAXHP, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_HITPOINTS, STATLIST_UnitGetStatValue(pMerc, STAT_HITPOINTS, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_ARMORCLASS, STATLIST_GetUnitBaseStat(pMerc, STAT_ARMORCLASS, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_EXPERIENCE, STATLIST_UnitGetStatValue(pMerc, STAT_EXPERIENCE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_NEXTEXP, STATLIST_UnitGetStatValue(pMerc, STAT_NEXTEXP, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MINDAMAGE, STATLIST_GetUnitBaseStat(pMerc, STAT_SECONDARY_MINDAMAGE, 0) + STATLIST_GetUnitBaseStat(pMerc, STAT_MINDAMAGE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MAXDAMAGE, STATLIST_GetUnitBaseStat(pMerc, STAT_SECONDARY_MAXDAMAGE, 0) + STATLIST_GetUnitBaseStat(pMerc, STAT_MAXDAMAGE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_FIRERESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_FIRERESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_LIGHTRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_LIGHTRESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_COLDRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_COLDRESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_POISONRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_POISONRESIST, 0));
}

// 0x00572BA0
D2MonsterInteractStrc* __fastcall MONSTERAI_AllocMonsterInteract(D2GameStrc* pGame)
{
    D2MonsterInteractStrc* pMonInteract = (D2MonsterInteractStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2MonsterInteractStrc), ".\\MONSTER\\MonsterAI.cpp", 379, 0);
    pMonInteract->pInteractInfo = 0;
    return pMonInteract;
}

// 0x00572840
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, int nLevel)
{
    D2_ASSERT(pGame, 0xE0);
    D2_ASSERT(pPlayer, 0xE1);
    D2_ASSERT(pPlayer->dwUnitType == 0, 0xE2);

    D2UnitStrc* pHireling = pMerc;
    if (!pHireling)
    {
        pHireling = sub_6FC7E8B0(pGame, pPlayer, 7, 0);
        if (!pHireling)
        {
            return;
        }
    }

    STATLIST_UnitGetStatValue(pPlayer, 0xC, 0);
    const int nHirelingLevel = STATLIST_UnitGetStatValue(pHireling, 0xC, 0);
    if (!nLevel)
    {
        nLevel = nHirelingLevel + 1;
    }

    AITACTICS_AddMessage(pGame, pHireling, pPlayer, 0xD7C, 1);
    STATLIST_SetUnitStat(pHireling, 0xC, nLevel, 0);

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, pHireling->dwUnitId);
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    const int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;

    const int nNextExp = nLevel >= DATATBLS_GetMaxLevel(0) - 1 ? 0 : MONSTERS_GetHirelingExpForNextLevel(nLevel + 1, pHirelingTxtRecord->dwExpPerLvl);
    STATLIST_SetUnitStat(pHireling, 0x1E, nNextExp, 0);

    const int nExperience = MONSTERS_GetHirelingExpForNextLevel(nLevel, pHirelingTxtRecord->dwExpPerLvl);
    if (STATLIST_UnitGetStatValue(pHireling, 0xD, 0) < nExperience)
    {
        STATLIST_SetUnitStat(pHireling, 0xD, nExperience, 0);
    }

    int nStrength = pHirelingTxtRecord->nStr + nLevelUps * pHirelingTxtRecord->nStrPerLvl / 8;
    nStrength = nStrength < 10 ? 10 : nStrength;
    STATLIST_SetUnitStat(pHireling, 0, nStrength, 0);

    int nDexterity = pHirelingTxtRecord->nDex + nLevelUps * pHirelingTxtRecord->nDexPerLvl / 8;
    nDexterity = nDexterity < 10 ? 10 : nDexterity;
    STATLIST_SetUnitStat(pHireling, 2, nDexterity, 0);

    int nHitpoints = (pHirelingTxtRecord->dwHitpoints << 8) + nLevelUps * (pHirelingTxtRecord->dwHitpointsPerLvl << 8);
    nHitpoints = nHitpoints < 0x2800 ? 0x2800 : nHitpoints;
    STATLIST_SetUnitStat(pHireling, 7, nHitpoints, 0);
    STATLIST_SetUnitStat(pHireling, 6, nHitpoints, 0);

    int nDefense = pHirelingTxtRecord->dwDefense + nLevelUps * pHirelingTxtRecord->dwDefensePerLvl;
    nDefense = nDefense < 0 ? 0 : nDefense;
    STATLIST_SetUnitStat(pHireling, 0x1F, nDefense, 0);

    int nMinDamage = pHirelingTxtRecord->nDmgMin + nLevelUps * pHirelingTxtRecord->nDmgPerLvl / 8;
    nMinDamage = nMinDamage < 0 ? 0 : nMinDamage;
    STATLIST_SetUnitStat(pHireling, 0x17, nMinDamage, 0);

    int nMaxDamage = pHirelingTxtRecord->nDmgMax + nLevelUps * pHirelingTxtRecord->nDmgPerLvl / 8;
    nMaxDamage = nMaxDamage < 1 ? 1 : nMaxDamage;
    STATLIST_SetUnitStat(pHireling, 0x18, nMaxDamage, 0);

    int nAttackRate = pHirelingTxtRecord->dwAttackRate + nLevelUps * pHirelingTxtRecord->dwAttackRatePerLvl;
    nAttackRate = nAttackRate < 0 ? 0 : nAttackRate;
    STATLIST_SetUnitStat(pHireling, 0x13, nAttackRate, 0);

    int nResist = pHirelingTxtRecord->dwResist + nLevelUps * pHirelingTxtRecord->dwResistPerLvl / 4;
    nResist = nResist < 0 ? 0 : nResist;
    STATLIST_SetUnitStat(pHireling, 0x27, nResist, 0);
    STATLIST_SetUnitStat(pHireling, 0x29, nResist, 0);
    STATLIST_SetUnitStat(pHireling, 0x2B, nResist, 0);
    STATLIST_SetUnitStat(pHireling, 0x2D, nResist, 0);

    int nHpRegen = STATLIST_GetUnitBaseStat(pHireling, 7, 0) / 2000;
    nHpRegen = nHpRegen < 0 ? 0 : nHpRegen;
    STATLIST_SetUnitStat(pHireling, 0x4A, nHpRegen, 0);

    for (int i = 0; i < 6; ++i)
    {
        if (pHirelingTxtRecord->dwSkill[i] <= 0 || pHirelingTxtRecord->dwSkill[i] >= sgptDataTables->nSkillsTxtRecordCount || pHirelingTxtRecord->nMode[i] >= 16)
        {
            return;
        }

        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(pHirelingTxtRecord->dwSkill[i]);
        if (pSkillsTxtRecord && nLevel >= pSkillsTxtRecord->wReqLevel)
        {
            int nSkillLevel = pHirelingTxtRecord->nLevel[i] + (nLevelUps * pHirelingTxtRecord->nSLvlPerLvl[i] >> 5);
            nSkillLevel = nSkillLevel > 0 ? nSkillLevel : 0;
            nSkillLevel = nSkillLevel < 32 ? nSkillLevel : 32;
            if (nSkillLevel > 0)
            {
                D2GAME_SetSkills_6FD14C60(pHireling, pHirelingTxtRecord->dwSkill[i], nSkillLevel, 0);
            }
        }
    }
}

// 0x00572BC0
void __fastcall MONSTERAI_FreeMonsterInteract(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract)
{
    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;
    while (pInteractInfo)
    {
        D2InteractInfoStrc* pNext = pInteractInfo->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 392, 0);
        pInteractInfo = pNext;
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pMonInteract, ".\\MONSTER\\MonsterAI.cpp", 395, 0);
}

// 0x00572DA0
extern "C" __declspec(dllexport) int __fastcall sub_00572DA0(List00572DA0* pList) {
    int nCount = 0;
    for (Node00572DA0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->dwValue00) {
            nCount++;
        }
    }
    return nCount;
}

// 0x00572DC0
extern "C" __declspec(dllexport) int __fastcall sub_00572DC0(List00572DC0* pList) {
    for (Node00572DC0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->dwValue00) {
            return 1;
        }
    }
    return 0;
}

// 0x00572DE0
extern "C" __declspec(dllexport) int __fastcall sub_00572DE0(List00572DE0* pList, int nId) {
    for (Node00572DE0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->nId == nId) {
            return 1;
        }
    }
    return 0;
}

// 0x00572E60
void __fastcall sub_6FC61AB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract)
{
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pUnit)
        {
            if (!pInteractInfo->nInteract)
            {
                pInteractInfo->nInteract = 1;
                D2GAME_NPC_Heal_6FCCB220(pGame, pUnit, pNpc);
            }
            return;
        }
    }
}

// 0x00573180
void __fastcall sub_00573180(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide)
{
    if (!pMonster)
    {
        return;
    }

    const int nType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    if (!pMonster->pMonsterData)
    {
        return;
    }

    D2MonsterInteractStrc* pMonInteract = pMonster->pMonsterData->pMonInteract;
    if (!pMonInteract)
    {
        return;
    }

    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;
    while (pInteractInfo)
    {
        D2InteractInfoStrc* pNext = pInteractInfo->pNext;
        sub_6FC3F340(SUNIT_GetClientFromPlayer(pInteractInfo->pUnit, ".\\MONSTER\\MonsterAI.cpp", 860), 0x62, UNIT_MONSTER, sub_00451F50_GetUnitGUID(pMonster), 0);

        int nInteractType;
        int nInteractGUID;
        if (!bClientSide || (SUNIT_GetInteractInfo(pInteractInfo->pUnit, &nInteractType, &nInteractGUID) && nInteractType == UNIT_MONSTER && nInteractGUID == sub_00451F50_GetUnitGUID(pMonster)))
        {
            SUNIT_ResetInteractInfo(pInteractInfo->pUnit);
        }

        if (pCallback)
        {
            pCallback(pInteractInfo->pUnit);
        }

        FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 875, 0);
        pInteractInfo = pNext;
    }

    pMonInteract->pInteractInfo = 0;
}

// 0x00572F20
void __fastcall sub_6FC61B70(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract)
{
    QUESTS_NPCDeactivate(pGame, pPlayer, pNpc);

    D2InteractInfoStrc* pPrevious = 0;
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pPlayer)
        {
            if (pInteractInfo->nInteract >= 1)
            {
                if (!pPrevious)
                {
                    pMonInteract->pInteractInfo = pInteractInfo->pNext;
                }
                else
                {
                    pPrevious->pNext = pInteractInfo->pNext;
                }

                int nUnitType;
                int nUnitGUID;
                if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 1)
                {
                    SUNIT_ResetInteractInfo(pPlayer);
                }

                FOG_FreePool(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 651, 0);
                if (!pMonInteract->pInteractInfo)
                {
                    SUNITPROXY_FreeNpcGamble(pGame, pNpc, pPlayer);
                }
                return;
            }

            if (pInteractInfo->nInteract == 0)
            {
                if (!pPrevious)
                {
                    pMonInteract->pInteractInfo = pInteractInfo->pNext;
                }
                else
                {
                    pPrevious->pNext = pInteractInfo->pNext;
                }

                int nUnitType;
                int nUnitGUID;
                if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 1)
                {
                    SUNIT_ResetInteractInfo(pPlayer);
                }

                FOG_FreePool(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 686, 0);
                return;
            }
        }

        pPrevious = pInteractInfo;
    }
}

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

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\MONSTER\\MonsterAI.cpp", 0x1C4);
    D2InteractInfoStrc* pNewInteractInfo = (D2InteractInfoStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2InteractInfoStrc), ".\\MONSTER\\MonsterAI.cpp", 0x1C7, 0);
    pNewInteractInfo->pUnit = pUnit;

    int bNoInteractInfo;
    if (!pMonInteract->pInteractInfo)
    {
        bNoInteractInfo = 1;
    }
    else
    {
        bNoInteractInfo = 0;
    }

    pNewInteractInfo->pNext = pMonInteract->pInteractInfo;
    pMonInteract->pInteractInfo = pNewInteractInfo;

    D2GAME_NPC_BuildHirelingList_6FCC6FF0(CLIENTS_GetGame(pClient), pClient, pTarget, bNoInteractInfo);
    SUNIT_SetInteractInfo(pUnit, 1, pTarget->dwUnitId);
    pNewInteractInfo->nInteract = 0;

    D2TextHeaderStrc* pTextHeader = TEXT_AllocTextHeader(pGame->pMemoryPool);
    QUESTS_NPCActivate(pClient, pUnit, pTarget, pTextHeader);

    D2GSPacketSrv27 packet27;
    memcpy(&packet27.dwUnitGUID, &pTarget->dwUnitId, sizeof(pTarget->dwUnitId));
    packet27.nHeader = 0x27;
    packet27.nUnitType = pTarget->dwUnitType;
    TEXT_CreateMessageListFromTextHeader(pTextHeader, &packet27.messageList);
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
    TEXT_FreeTextHeader(pTextHeader);

    QUESTS_SendCurrentFlags(pGame, pClient);
    const int nTargetGUID = pTarget->dwUnitId;
    D2GAME_SendPacket0x28_6FC3F2F0(pClient, 0x28, 1, nTargetGUID, sub_00543520(pGame, pUnit), nQuestFlags);
    return 0;
}

// 0x00573020
void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags)
{
    sub_00572C10_StartNpcInteraction(pGame, pMonInteract, nQuestFlags, pTarget, pUnit);
}

static __forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline unsigned int MONSTERS_CheckMonStatsFlag(D2MonStatsTxt* pMonStatsTxtRecord, int nFlag)
{
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static __forceinline D2MonsterDataStrc* MONSTERS_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x00573040
static int sub_00573040_AiSwitchAllowed(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        if (MONSTERS_CheckMonStatsFlag(DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId), MONSTATSFLAGINDEX_SWITCHAI))
        {
            return 1;
        }
    }
    return 0;
}

int __fastcall sub_00573090_ApplyAiMode(D2UnitStrc* pUnit, int nState, int nValue)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && nState < 5 && sub_00573040_AiSwitchAllowed(pUnit))
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterData(pUnit);
        if (pMonsterData)
        {
            pMonsterData->nAiState = nState;
            pMonsterData->nAiValue = nValue;
            return 1;
        }
    }
    return 0;
}

static __forceinline D2MonsterDataStrc* MONSTERS_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005730E0
int __fastcall MONSTERAI_GetTargetOverrideType(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            return pMonsterData->unk0x38;
        }
    }

    return 0;
}

// 0x00573100
int __fastcall MONSTERAI_GetTargetOverrideGUID(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            return pMonsterData->unk0x34;
        }
    }

    return 0;
}

// 0x00573120
void __fastcall sub_00573120_ClearMonsterPair(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            pMonsterData->unk0x38 = 0;
            pMonsterData->unk0x34 = 0;
        }
    }
}

static __forceinline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecordFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonstatsTxt;
    }

    return 0;
}

// 0x00573140
int __fastcall sub_6FC61F20(D2UnitStrc* pNpc, D2UnitStrc* pPlayer)
{
    if (!pNpc)
    {
        return 0;
    }

    const int nUnitType = pNpc ? pNpc->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pNpc);
    if (!pMonsterData)
    {
        return 0;
    }

    if (!pMonsterData->pMonInteract)
    {
        return 0;
    }

    for (D2InteractInfoStrc* pInteractInfo = pMonsterData->pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pPlayer)
        {
            return pInteractInfo->nInteract >= 1;
        }
    }

    return 1;
}

// 0x0057C3E0
int __fastcall sub_0057C3E0_GetMonsterDrain(D2UnitStrc* pUnit, int nUnused, D2GameStrc* pGame)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 100;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERS_GetMonStatsTxtRecordFromUnitInline(pUnit);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
}
