struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x70];
    int nRightSkillId;
    int nLeftSkillId;
};

struct D2CharStatsTxt
{
    char unk0x00[0xAC];
    short wStartSkill;
    char unk0xAE[0x16];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC4];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

struct D2SaveHeaderStrc
{
    int dwHeaderMagic;
    unsigned int dwVersion;
    char unk0x08[0x21];
    unsigned char nStats;
    unsigned char nSkills;
    char unk0x2B[0x84];
    unsigned char MercSaveData[0x10];
};

#define UNIT_PLAYER 0
#define ACT_I 0
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define PLRSAVE2ERROR_UNKNOWN 1
#define PLRSAVE2ERROR_NEWBIE_SAVE 2
#define PLRSAVE2ERROR_NO_CLIENT 3
#define PLRSAVE2ERROR_COUNT 27

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const int dwErrorCodesRemap_006E1208[PLRSAVE2ERROR_COUNT];                                           // 0x006E1208

void __fastcall sub_6FC32220(D2ClientStrc* pClient);                                                        // 0x00537970
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient);                                                   // 0x005385F0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall sub_00569F20(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient);               // 0x00569F20
void __fastcall sub_005385D0(D2ClientStrc* pClient, int a2, int a3);                                        // 0x005385D0
void __fastcall sub_00571F90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct); // 0x005706D0
void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char nAct); // 0x00534F10
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);                 // 0x006439F0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0
void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3);                     // 0x00546270
int __fastcall PLRSAVE2_ReadSaveHeader(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char** ppSection, unsigned char* pEnd, D2UnitStrc** ppPlayer); // 0x0056A090
int __fastcall sub_0056A370_ReadQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A370
int __fastcall PLRSAVE2_ReadWaypointData(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A3E0
int __fastcall sub_0056A470_ReadPlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A470
int __fastcall PLRSAVE2_ReadStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nStats); // 0x0056A620
int __fastcall PLRSAVE2_ReadSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nSkills); // 0x0056A710
int __fastcall sub_0056A7E0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError); // 0x0056A7E0
int __fastcall PLRSAVE2_ReadCorpses(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int* a6); // 0x0056A830
D2UnitStrc* __fastcall PLRSAVE2_ReadMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData, unsigned int dwVersion); // 0x0056AA50
int __fastcall PLRSAVE2_ReadPetSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion, int* a6); // 0x0056AC10
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3);                   // 0x005726C0
int __fastcall PLRSAVE2_ReadIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion); // 0x0056AE50
void __fastcall PLRSAVE2_InitializeStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nHitpoints, int nMana); // 0x0056AF80
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit);                        // 0x005378E0

static __forceinline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

static int __stdcall sub_00569F80_CreateNewbiePlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer)
{
    sub_6FC32220(pClient);
    const int nClassId = CLIENTS_GetClassId(pClient);
    D2UnitStrc* pPlayer = SUNIT_AllocUnitData(UNIT_PLAYER, nClassId, 0, 0, pGame, 0, 0, 0, 0);
    sub_00569F20(pGame, pPlayer, pClient);
    sub_005385D0(pClient, 0, 1);
    sub_00571F90(pGame, pPlayer, pClient);

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    PLAYERSTATS_SetStatsForStartingAct(pGame, pPlayer, nAct);
    PLAYER_CreateStartItemsFromCharStatsTxt(pPlayer, pGame, nAct);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = 0;
    pPlayerData->nRightSkillId = 0;

    if (nAct == ACT_I && pPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
        if (pCharStatsTxtRecord && pCharStatsTxtRecord->wStartSkill && SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, pCharStatsTxtRecord->wStartSkill))
        {
            D2GAME_AssignSkill_6FD13800(pPlayer, 0, pCharStatsTxtRecord->wStartSkill, -1);
            pPlayerData->nRightSkillId = pCharStatsTxtRecord->wStartSkill;
        }
    }

    QUESTS_SequenceCycler(pGame, pPlayer, 1);
    *ppPlayer = pPlayer;
    return 0;
}

// 0x0056B180
int __fastcall PLRSAVE2_ProcessSaveFile(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    D2SaveHeaderStrc* pSaveHeader = (D2SaveHeaderStrc*)pSaveFile;
    unsigned char* pSection = pSaveFile;
    unsigned char* pSaveFileEnd = &pSaveFile[nSize];
    D2UnitStrc* pPlayer = 0;
    int nHitpoints;
    int nMana;
    int nErrorCode;
    int bLoaded = 0;

    *ppPlayer = 0;

    if (!pClient)
    {
        nErrorCode = PLRSAVE2ERROR_NO_CLIENT;
    }
    else
    {
        nErrorCode = PLRSAVE2_ReadSaveHeader(pGame, pClient, &pSection, pSaveFileEnd, ppPlayer);
        if (nErrorCode)
        {
            if (nErrorCode == PLRSAVE2ERROR_NEWBIE_SAVE && pSection == pSaveFileEnd)
            {
                return sub_00569F80_CreateNewbiePlayer(pGame, pClient, ppPlayer);
            }
        }
        else
        {
            pPlayer = *ppPlayer;
            const unsigned int nVersion = pSaveHeader->dwVersion;
            nErrorCode = sub_0056A370_ReadQuestSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
            if (!nErrorCode)
            {
                nErrorCode = PLRSAVE2_ReadWaypointData(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                if (!nErrorCode)
                {
                    nErrorCode = sub_0056A470_ReadPlrIntroSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                    if (!nErrorCode)
                    {
                        nErrorCode = PLRSAVE2_ReadStats(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, pSaveHeader->nStats);
                        if (!nErrorCode)
                        {
                            nHitpoints = STATLIST_UnitGetStatValue(pPlayer, STAT_HITPOINTS, 0);
                            nMana = STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0);

                            nErrorCode = PLRSAVE2_ReadSkills(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, pSaveHeader->nSkills);
                            if (!nErrorCode)
                            {
                                int nItemSize;
                                nErrorCode = sub_0056A7E0(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, 0, &nItemSize);
                                if (!nErrorCode)
                                {
                                    nErrorCode = PLRSAVE2_ReadCorpses(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, &nItemSize);
                                    if (!nErrorCode)
                                    {
                                        D2UnitStrc* pMerc = PLRSAVE2_ReadMercData(pGame, pPlayer, pSaveHeader->MercSaveData, nVersion);
                                        nErrorCode = PLRSAVE2_ReadPetSection(pGame, pPlayer, pMerc, &pSection, pSaveFileEnd, nVersion, &nItemSize);
                                        if (!nErrorCode)
                                        {
                                            if (pMerc)
                                            {
                                                MONSTERAI_SendMercStats(pGame, pPlayer, 1);
                                            }

                                            nErrorCode = PLRSAVE2_ReadIronGolemSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                                            if (!nErrorCode)
                                            {
                                                bLoaded = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!bLoaded)
    {
        if (nErrorCode < 0 || nErrorCode >= PLRSAVE2ERROR_COUNT)
        {
            nErrorCode = PLRSAVE2ERROR_UNKNOWN;
        }

        if (pPlayer)
        {
            if (UNITS_GetRoom(pPlayer))
            {
                const int nUnitGUID = pPlayer->dwUnitId;
                const int nUnitType = pPlayer->dwUnitType;
                DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPlayer), nUnitType, nUnitGUID);
            }

            SUNIT_RemoveUnit(pGame, pPlayer);
        }

        CLIENTS_SetPlayerInClient(pClient, 0);
        return dwErrorCodesRemap_006E1208[nErrorCode];
    }

    PLRSAVE2_InitializeStats(pGame, pPlayer, nHitpoints, nMana);
    return 0;
}

#include "gen/data/Source/D2Game/0056B180_PLRSAVE2_ProcessSaveFile.inc"
