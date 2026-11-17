struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2SaveHeaderStrc;
struct D2ServerCallbackFunctions;
struct _iobuf;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2GameStrc
{
    char unk0x00[0x6A];
    unsigned char nGameType;
    char unk0x6B[0x65];
    int pGameSeed;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x50];
    int dwTradeState;
    int unk0x54;
    int dwAcceptTradeTick;
    void* pTrade;
    char unk0x60[0x10];
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

#define UNIT_PLAYER 0
#define ACT_I 0
#define PLRMODE_NEUTRAL 1
#define GAMETYPE_1 1
#define GAMETYPE_2 2
#define SYSERROR_UNK_14 14

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                          // 0x00883D50
extern "C" const char gszSaveFormat_006D4230[];                                                             // 0x006D4230
extern "C" const char gszModeRb_006CDC90[];                                                                 // 0x006CDC90

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A
extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684782
extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC

void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit);                        // 0x005378E0
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient);                     // 0x00553180
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient);                                                    // 0x00538830
void __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* pUnit, char* szName);                                  // 0x006220F0
void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, int* pSeed);                                              // 0x00552DF0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __fastcall sub_6FC32220(D2ClientStrc* pClient);                                                        // 0x00537970
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient);                                                   // 0x005385F0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall sub_00571F90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0
void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct); // 0x005706D0
void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char nAct); // 0x00534F10
void* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);                 // 0x006439F0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0
void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3);                     // 0x00546270
void __fastcall sub_00407050_GetSavePath(char* szPath, int nSize);                                          // 0x00407050
int __fastcall sub_00534330(D2GameStrc* pGame, D2ClientStrc* pClient, D2SaveHeaderStrc* pSave, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00534330
D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient);                                  // 0x00538E00
int __fastcall CLIENTS_GetSaveHeaderSize(D2ClientStrc* pClient);                                            // 0x00538E30
void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* pClient);                                              // 0x00538F10
void __fastcall sub_6FD14C30(D2UnitStrc* pUnit);                                                            // 0x0056DE40

static __forceinline D2CharStatsTxt* PLRSAVE_GetCharStatsTxtRecordInline(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00532520
static void __stdcall sub_00532520_AttachPlayerToClient(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pPlayer)
{
    CLIENTS_SetPlayerInClient(pClient, pPlayer);
    SUNIT_InitClientInPlayerData(pPlayer, pClient);
    UNITS_SetNameInPlayerData(pPlayer, CLIENTS_GetName(pClient));
    SUNIT_InitSeed(pPlayer, &pGame->pGameSeed);
    UNITS_ChangeAnimMode(pPlayer, PLRMODE_NEUTRAL);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->pTrade = 0;
    pPlayerData->dwTradeState = 0;
    pPlayerData->dwAcceptTradeTick = 0;
    pPlayerData->unk0x54 = 0;
}

// 0x00532590
static int __stdcall PLRSAVE_CreateNewPlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer)
{
    sub_6FC32220(pClient);
    const int nClassId = CLIENTS_GetClassId(pClient);
    D2UnitStrc* pPlayer = SUNIT_AllocUnitData(UNIT_PLAYER, nClassId, 0, 0, pGame, 0, 0, 0, 0);
    sub_00532520_AttachPlayerToClient(pGame, pClient, pPlayer);
    sub_00571F90(pGame, pPlayer, pClient);

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    PLAYERSTATS_SetStatsForStartingAct(pGame, pPlayer, nAct);
    PLAYER_CreateStartItemsFromCharStatsTxt(pPlayer, pGame, nAct);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = 0;
    pPlayerData->nRightSkillId = 0;

    if (nAct == ACT_I && pPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE_GetCharStatsTxtRecordInline(pPlayer->dwClassId);
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

// 0x005343A0
static int __stdcall D2GAME_SAVE_ReadFile_6FC8C9D0(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    char szPath[1024];
    char szFileName[500];
    unsigned char saveFile[0x2000];
    D2UnitStrc* pPlayer = 0;
    int nResult = 0;

    *ppPlayer = 0;
    sub_00407050_GetSavePath(szPath, sizeof(szPath));
    sprintf(szFileName, gszSaveFormat_006D4230, szPath, szName);

    _iobuf* pSaveFile = fopen(szFileName, gszModeRb_006CDC90);
    if (pSaveFile)
    {
        const unsigned int nFileSize = fread(saveFile, 1, sizeof(saveFile), pSaveFile);
        fclose(pSaveFile);
        if (nFileSize)
        {
            nResult = sub_00534330(pGame, pClient, (D2SaveHeaderStrc*)saveFile, nFileSize, &pPlayer, pRoomArg, nXArg, nYArg);
            if (nResult)
            {
                return nResult;
            }
        }
    }

    *ppPlayer = pPlayer;
    if (!pPlayer)
    {
        nResult = SYSERROR_UNK_14;
    }

    return nResult;
}

// 0x005344B0
static int __stdcall sub_005344B0_ReadSaveFromDisk(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    int nErrorCode = SYSERROR_UNK_14;
    D2UnitStrc* pPlayer = 0;
    if (!gpD2EventCallbackTable_6FD45830)
    {
        nErrorCode = D2GAME_SAVE_ReadFile_6FC8C9D0(pGame, pClient, szName, &pPlayer, pRoomArg, nXArg, nYArg);
        if (pPlayer)
        {
            QUESTS_SequenceCycler(pGame, pPlayer, 0);
        }
    }

    *ppPlayer = pPlayer;
    return nErrorCode;
}

// 0x00534520
static int __stdcall sub_00534520_ReadSaveFromClient(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    *ppPlayer = 0;
    D2SaveHeaderStrc* pSaveHeader = CLIENTS_GetSaveHeader(pClient);
    const int nSaveHeaderSize = CLIENTS_GetSaveHeaderSize(pClient);
    if (!nSaveHeaderSize)
    {
        return SYSERROR_UNK_14;
    }

    const int nErrorCode = sub_00534330(pGame, pClient, pSaveHeader, nSaveHeaderSize, ppPlayer, pRoomArg, nXArg, nYArg);
    if (nErrorCode)
    {
        *ppPlayer = 0;
        return nErrorCode;
    }

    if (*ppPlayer)
    {
        if (pGame->nGameType == GAMETYPE_1 || pGame->nGameType == GAMETYPE_2)
        {
            CLIENTS_FreeSaveHeader(pClient);
        }

        QUESTS_SequenceCycler(pGame, *ppPlayer, 0);
    }

    return 0;
}

// 0x005345A0
int __fastcall D2GAME_SAVE_GetUnitDataFromFile_6FC8CB40(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, int bLoadSave, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    int nErrorCode;
    if (pGame->nGameType != GAMETYPE_1 && pGame->nGameType != GAMETYPE_2 && !gpD2EventCallbackTable_6FD45830)
    {
        if (bLoadSave)
        {
            nErrorCode = sub_005344B0_ReadSaveFromDisk(pGame, pClient, szName, ppPlayer, pRoomArg, nXArg, nYArg);
        }
        else
        {
            nErrorCode = PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
        }
    }
    else
    {
        if (bLoadSave)
        {
            nErrorCode = sub_00534520_ReadSaveFromClient(pGame, pClient, ppPlayer, pRoomArg, nXArg, nYArg);
        }
        else
        {
            nErrorCode = PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
        }
    }

    if (nErrorCode)
    {
        return nErrorCode;
    }

    if (!*ppPlayer)
    {
        return SYSERROR_UNK_14;
    }

    sub_6FD14C30(*ppPlayer);
    return 0;
}
