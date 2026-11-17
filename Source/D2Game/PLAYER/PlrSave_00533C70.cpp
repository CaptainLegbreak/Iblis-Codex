// build: base-profile

struct D2ClientStrc;
struct D2ActiveRoomStrc;
struct D2SaveHeaderStrc;
struct D2ServerCallbackFunctions;
struct _iobuf;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char pad10[0x50];
    void* pInventory;
    char pad64[0x60];
    unsigned int dwFlags;
};

struct D2GameStrc
{
    char unk0x00[0x6A];
    unsigned char nGameType;
    char unk0x6B[2];
    unsigned char nDifficulty;
    char unk0x6E[2];
    int bExpansion;
    char unk0x74[8];
    int nMapSeed;
    int unk80;
    int unk84;
    char unk88[0x48];
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
    char unk0x000[0xBA0];
    int nSkillsTxtRecordCount;
    char unk0xBA4[0x20];
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

// build: context PLRSAVE_GetCharStatsTxtRecordInline
static __forceinline D2CharStatsTxt* PLRSAVE_GetCharStatsTxtRecordInline(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00532520
static void __stdcall sub_00532520_AttachPlayerToClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
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
    sub_00532520_AttachPlayerToClient(pGame, pPlayer, pClient);
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

struct D2HirelingTxt
{
    char pad00[8];
    int dwClass;
    char pad0C[0x14];
    int dwExpPerLvl;
    char pad24[0xF0];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};
struct D2PetInfoStrc
{
    unsigned int nSeed;
    int nName;
    int nHirelingId;
};
#pragma pack(push, 1)
struct D2LegacyMercSaveStrc
{
    unsigned short wMagic;
    unsigned int dwFlags;
    unsigned int dwSeed;
    unsigned short wName;
    unsigned short wHirelingId;
    unsigned int dwExperience;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void __cdecl sub_00410610_WriteLogLine(const char*, ...); // 0x00410610
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int, int, int); // 0x006562F0
D2UnitStrc* __fastcall D2GAME_MERCS_Create_6FCC8630(D2GameStrc*, D2UnitStrc*, unsigned short, int, unsigned short, int, int); // 0x005774F0
unsigned int __fastcall PLRSAVE_ConvertLegacyHirelingExperience(D2GameStrc*, unsigned short, unsigned int); // 0x00533BF0
void __fastcall PLAYERPETS_UpdatePetInfo(D2UnitStrc*, int, int, D2PetInfoStrc*); // 0x005749B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, unsigned short); // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, unsigned short); // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, unsigned short); // 0x00627260
int __stdcall DATATBLS_GetMaxLevel(int); // 0x00611830
void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc*, unsigned short, int); // 0x005718C0
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int, int); // 0x00663790
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x00572840
void* __stdcall INVENTORY_AllocInventory(void*, D2UnitStrc*); // 0x0063ABD0
void __fastcall PLAYERPETS_HandlePetDeath(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x005751A0
void __fastcall SUNIT_SetCombatMode(D2GameStrc*, D2UnitStrc*, int); // 0x00553570
void __fastcall sub_005738D0(D2GameStrc*, D2UnitStrc*); // 0x005738D0
int __fastcall sub_005337F0_ReadItems(D2GameStrc*, D2UnitStrc*, unsigned char*, int, int, int, int*); // 0x005337F0
void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc*, D2UnitStrc*, int, int); // 0x0055DF00
void __fastcall sub_0055F4F0(D2GameStrc*, D2UnitStrc*, int); // 0x0055F4F0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
void __fastcall MONSTERAI_SendMercStats(D2GameStrc*, D2UnitStrc*, int); // 0x005726C0
int __fastcall sub_00532BE0_ReadQuestData(D2UnitStrc*, unsigned char*, int, int*); // 0x00532BE0
int __fastcall D2GAME_SAVE_ReadWaypointData_6FC8AD50(D2UnitStrc*, unsigned char*, int, int*); // 0x00532C70
int __fastcall sub_00532D00_ReadPlayerIntro(D2UnitStrc*, unsigned char*, int, int*); // 0x00532D00
int __fastcall PLRSAVE_ReadLegacyStats(D2GameStrc*, D2UnitStrc*, unsigned char*, int, int, int*); // 0x00532DA0
int __fastcall PLRSAVE_ReadLegacySkills(D2GameStrc*, D2ClientStrc*, D2UnitStrc*, unsigned char*, int, int, int*); // 0x00532E90
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc*); // 0x00622E70
int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc*); // 0x00623460
void __fastcall sub_00568DB0(D2GameStrc*, D2UnitStrc*); // 0x00568DB0
int __fastcall PLRSAVE_ReadCorpseSection(D2GameStrc*, D2UnitStrc*, unsigned char*, int, int, int*); // 0x005339A0
int __stdcall sub_00533F70_ReadHotkeySection(D2UnitStrc*, unsigned char*, unsigned int, int*); // 0x00533F70
int __stdcall DATATBLS_GetLevelThreshold(int, int); // 0x00611800
unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc*); // 0x00539220
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc*); // 0x0053E110

// 0x00533C70
static int __stdcall sub_00533C70_ReadLegacyMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int nVersion, unsigned int nSize, int* pSize)
{
    *pSize = 0;
    if (nVersion == 71)
    {
        if (*(unsigned short*)pSection != 0x4D4A)
            return 14;
        const unsigned int nSeed = *(unsigned int*)(pSection + 2);
        if (nSeed)
        {
            const unsigned short nName = *(unsigned short*)(pSection + 6);
            if (nName)
                D2GAME_MERCS_Create_6FCC8630(pGame, pPlayer, nName, nSeed, 0xFFFF, 0, 0);
        }
        *pSize = 8;
        goto Done;
    }
    if (nSize < 1)
    {
        sub_00410610_WriteLogLine("Premature end of save data.");
        return 14;
    }
    if (!*pSection)
    {
        *pSize = 1;
        return 0;
    }
    {
        unsigned char* pStart = pSection;
        *pSize = 0;
        if (nSize < sizeof(D2LegacyMercSaveStrc))
        {
            sub_00410610_WriteLogLine("Premature end of save data.");
            return 14;
        }
        D2LegacyMercSaveStrc* pMercSave = (D2LegacyMercSaveStrc*)pSection;
        pSection += sizeof(D2LegacyMercSaveStrc);
        int bDead = pMercSave->dwFlags & 0x10000;
        D2HirelingTxt* pHirelingTxt = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pMercSave->wHirelingId, 1);
        if (!pHirelingTxt)
        {
            sub_00410610_WriteLogLine("Unable to load merc.");
            return 14;
        }
        if (nVersion <= 89)
            pMercSave->dwExperience = PLRSAVE_ConvertLegacyHirelingExperience(pGame, pMercSave->wHirelingId, pMercSave->dwExperience);
        pMercSave->wName += pHirelingTxt->wNameFirst;
        if (pMercSave->wName > pHirelingTxt->wNameLast)
            pMercSave->wName = pHirelingTxt->wNameFirst;
        D2UnitStrc* pMerc = D2GAME_MERCS_Create_6FCC8630(pGame, pPlayer, pMercSave->wName, pMercSave->dwSeed, pMercSave->wHirelingId, pHirelingTxt->dwClass, bDead);
        int nRead;
        D2PetInfoStrc petInfo;
        if (!pMerc)
        {
            *pSize = pSection - pStart;
            goto Done;
        }
        else
        {
            petInfo.nSeed = pMercSave->dwSeed;
            petInfo.nName = pMercSave->wName;
            petInfo.nHirelingId = pMercSave->wHirelingId;
            PLAYERPETS_UpdatePetInfo(pPlayer, 7, !pMerc ? -1 : pMerc->dwUnitId, &petInfo);
            STATLIST_UnitGetStatValue(pPlayer, 12, 0);
            const int nMaxLevel = DATATBLS_GetMaxLevel(0);
            int nLevel = 1;
            const unsigned int nExperience = pMercSave->dwExperience;
            if ((unsigned int)STATLIST_UnitGetStatValue(pMerc, 13, 0) < nExperience)
                STATLIST_SetUnitStat(pMerc, 13, nExperience, 0);
            D2GAME_MERCS_SendStat_6FCC61D0(pMerc, 13, nExperience);
            for (;;)
            {
                D2HirelingTxt* pMercStats = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pMercSave->wHirelingId, nLevel);
                if (!pMercStats)
                {
                    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1660);
                    exit(-1);
                }
                const int nNextLevel = nLevel + 1;
                if (nNextLevel > nMaxLevel)
                    break;
                if (nExperience < MONSTERS_GetHirelingExpForNextLevel(nNextLevel, pMercStats->dwExpPerLvl))
                    break;
                nLevel = nNextLevel;
            }
            MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pMerc, nLevel);
            if (!pMerc->pInventory)
                INVENTORY_AllocInventory(0, pMerc);
            if (bDead)
            {
                PLAYERPETS_HandlePetDeath(pGame, pPlayer, pMerc);
                pMerc->dwFlags |= 0x10000;
                SUNIT_SetCombatMode(pGame, pMerc, 12);
                sub_005738D0(pGame, pMerc);
            }
            unsigned char* pItems = pSection;
            {
            int nItemsRead;
            int nResult = sub_005337F0_ReadItems(pGame, pMerc, pItems, nVersion, pStart + nSize - pItems, 0, &nItemsRead);
            if (nResult)
                return nResult;
            sub_0055DF00_RecalcItemStates(pGame, pMerc, 0, 0);
            sub_0055F4F0(pGame, pMerc, 0);
            STATLIST_SetUnitStat(pMerc, 6, STATLIST_GetMaxLifeFromUnit(pMerc), 0);
            MONSTERAI_SendMercStats(pGame, pPlayer, 1);
            nRead = pItems + nItemsRead - pStart;
            }
        }
    *pSize = nRead;
    }
Done:
    return 0;
}
#pragma pack(push,1)
struct D2LegacySaveHeaderStrc
{
 unsigned int dwMagic;
 unsigned int dwVersion;
 char szName[16];
 unsigned int dwFlags;
 unsigned short nSkills;
 unsigned short nStats;
 unsigned short nHeaderSize;
 unsigned short nClass;
 char unk24[0x22];
 unsigned char hotkeys[8][2];
 unsigned char nLeftSkill;
 unsigned char nRightSkill;
 unsigned char nLocation;
 unsigned char guildFlags[2];
 char guildTag[4];
 char guildName[28];
 unsigned char guildColors[3];
 unsigned int nMapSeed;
};
#pragma pack(pop)
typedef char LegacyHeaderSizeCheck[sizeof(D2LegacySaveHeaderStrc)==130?1:-1];
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
extern "C" int __cdecl _stricmp(const char*,const char*); // 0x006841E9
void __fastcall sub_00538630(D2ClientStrc*,unsigned short); // 0x00538630
void __fastcall CLIENTS_SetClassId(D2ClientStrc*,int); // 0x00538620
void __fastcall CLIENTS_SetActNo(D2ClientStrc*,unsigned char); // 0x005382E0
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc*); // 0x005387C0
unsigned int __fastcall ARENA_GetFlags(D2GameStrc*); // 0x0053FD40
void __fastcall sub_00539120_SetGuildFlags(D2ClientStrc*,int); // 0x00539120
void __fastcall sub_00539140_SetGuildTag(D2ClientStrc*,char*); // 0x00539140
void __fastcall sub_00539170_SetGuildName(D2ClientStrc*,char*); // 0x00539170
void __fastcall sub_005391C0_SetGuildColors(D2ClientStrc*,unsigned char,int,int); // 0x005391C0
void __fastcall sub_00539230_SetFlag(D2ClientStrc*,unsigned char); // 0x00539230
void __fastcall sub_005390A0(D2ClientStrc*,int,int,int,int); // 0x005390A0
static __forceinline int PLRSAVE_ConvertLegacySkill(unsigned char nSkill)
{
 int nId=nSkill;
 if(nId>=156 && nId<=216) nId+=65;
 else if(nId==255) nId=-1;
 return nId;
}
// 0x00532690
int __fastcall PLRSAVE_ReadLegacyHeader(D2GameStrc* pGame,D2ClientStrc* pClient,D2LegacySaveHeaderStrc* pSave,D2UnitStrc** ppPlayer,int* pNewPlayer,unsigned int* pVersion,int* pStats,int* pSkills,int* pLeft,int* pRight,int* pHeaderSize)
{
 char szGuildTag[4];
 *pHeaderSize=0;
 D2LegacySaveHeaderStrc header=*pSave;
 sub_00538630(pClient,0);
 if(header.dwMagic!=0xAA55AA55) {
  if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 0; }
  return 1;
 }
 if(header.nHeaderSize!=130) {
  if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 0; }
  return 14;
 }
 const unsigned int nVersion=header.dwVersion;
 *pVersion=nVersion;
 if(nVersion<71 || nVersion>96) goto invalidVersion;
 {
 header.szName[15]=0;
 char* szName=CLIENTS_GetName(pClient);
 szName[15]=0;
 if(_stricmp(szName,header.szName)) { *pNewPlayer=0;return 1; }
 const unsigned short nSaveFlags=(unsigned short)header.dwFlags;
 unsigned short bExpansion=(unsigned short)header.dwFlags;
 bExpansion &= 0x20;
 if(bExpansion) { if(!pGame->bExpansion) return 24; }
 else if(pGame->bExpansion) return 23;
 if(header.dwFlags & 4) {
  if(header.dwFlags & 8) return 21;
  if(!(ARENA_GetFlags(pGame)&0x800)) return 20;
 } else if(ARENA_GetFlags(pGame)&0x800) return 19;
 const int nProgress=(nSaveFlags>>8)&31;
 if(nProgress<8 && pGame->nDifficulty>1) return 18;
 if((nSaveFlags & 0x20) && nProgress<5 && pGame->nDifficulty>0) return 17;
 if(nProgress<4 && pGame->nDifficulty>0) return 17;
 sub_00539120_SetGuildFlags(pClient,*(int*)header.guildFlags);
 char szGuildName[28];
 memcpy(szGuildTag,header.guildTag,4);
 memcpy(szGuildName,header.guildName,28);
 szGuildTag[3]=0;szGuildName[27]=0;
 sub_00539140_SetGuildTag(pClient,szGuildTag);
 sub_00539170_SetGuildName(pClient,szGuildName);
 sub_005391C0_SetGuildColors(pClient,header.guildColors[0],*(int*)&header.guildColors[1],*(int*)&header.guildColors[2]);
 if(header.dwFlags & 1) {
  *pNewPlayer=1;header.dwFlags &= ~1;
  sub_00538630(pClient,header.dwFlags);
  return 0;
 }
 sub_00539230_SetFlag(pClient,(header.dwFlags>>13)&1);
 const int nClass=header.nClass;
 *pNewPlayer=0;
 CLIENTS_SetClassId(pClient,nClass);
 sub_00538630(pClient,nSaveFlags);
 unsigned char nAct=header.nLocation & 15;
 const unsigned char nDifficulty=header.nLocation>>4;
 if(nAct>=5 || nDifficulty>=3) return 9;
 if(pGame->nGameType==3 && !pGame->unk84 && pGame->nDifficulty==nDifficulty) pGame->nMapSeed=header.nMapSeed;
 if(pGame->nDifficulty!=nDifficulty) nAct=0;
 CLIENTS_SetActNo(pClient,nAct);
 *ppPlayer=SUNIT_AllocUnitData(0,nClass,0,0,pGame,0,0,0,0);
 sub_00532520_AttachPlayerToClient(pGame,*ppPlayer,pClient);
 sub_00571F90(CLIENTS_GetGame(pClient),*ppPlayer,pClient);
 *pStats=16;
 *pSkills=sgptDataTables->nSkillsTxtRecordCount;
 if(header.nStats>16 || header.nSkills>sgptDataTables->nSkillsTxtRecordCount) {
  if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 0; }
  return 1;
 }
 if(header.nStats!=16) *pStats=header.nStats;
 if(header.nSkills!=sgptDataTables->nSkillsTxtRecordCount) *pSkills=header.nSkills;
 unsigned char* pHotkey;
 int i;
 for(i=0,pHotkey=&header.hotkeys[0][1];i<8;++i,pHotkey+=2) sub_005390A0(pClient,i,PLRSAVE_ConvertLegacySkill(pHotkey[-1]),*pHotkey,-1);
 *pLeft=PLRSAVE_ConvertLegacySkill(header.nLeftSkill);
 *pRight=PLRSAVE_ConvertLegacySkill(header.nRightSkill);
 *pHeaderSize=header.nHeaderSize;
 return 0;
 }
invalidVersion:
 if(gpD2EventCallbackTable_6FD45830) { *pNewPlayer=1;return 9; }
 return 1;
}

// 0x00534020
int __fastcall D2GAME_SAVE_ProcessSaveFile_6FC8C0C0(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    D2UnitStrc* pLoadedPlayer = 0;
    *ppPlayer = 0;
    if (nSize < 130)
        return 9;
    int bCreateNew, nVersion, nStatCount, nSkillCount, nLeftSkillId, nRightSkillId, nRead;
    int nResult = PLRSAVE_ReadLegacyHeader(pGame, pClient, (D2LegacySaveHeaderStrc*)pSaveFile, &pLoadedPlayer, &bCreateNew, (unsigned int*)&nVersion, &nStatCount, &nSkillCount, &nLeftSkillId, &nRightSkillId, &nRead);
    if (nResult)
        return nResult;
    if (bCreateNew)
        return PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
    D2UnitStrc* pPlayer = pLoadedPlayer;
    *ppPlayer = pPlayer;
    unsigned char* pSection = pSaveFile + nRead;
    nSize -= nRead;
    nResult = sub_00532BE0_ReadQuestData(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = D2GAME_SAVE_ReadWaypointData_6FC8AD50(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = sub_00532D00_ReadPlayerIntro(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = PLRSAVE_ReadLegacyStats(pGame, pPlayer, pSection, 16, nVersion, &nRead);
    if (nResult)
        return nResult;
    int nHitpoints = STATLIST_UnitGetStatValue(pPlayer, 6, 0);
    int nMana = STATLIST_UnitGetStatValue(pPlayer, 8, 0);
    int nGold = STATLIST_UnitGetStatValue(pPlayer, 14, 0);
    if (nGold < 0 || nGold > UNITS_GetInventoryGoldLimit(pPlayer))
    {
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == 0)
                UNITS_GetInventoryGoldLimit(pPlayer);
            STATLIST_SetUnitStat(pPlayer, 14, 0, 0);
        }
    }
    nGold = STATLIST_UnitGetStatValue(pPlayer, 15, 0);
    if (nGold < 0 || nGold > UNITS_GetStashGoldLimit(pPlayer))
    {
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == 0)
                UNITS_GetStashGoldLimit(pPlayer);
            STATLIST_SetUnitStat(pPlayer, 15, 0, 0);
        }
    }
    pSection += nRead;
    nSize -= nRead;
    nResult = PLRSAVE_ReadLegacySkills(pGame, pClient, pPlayer, pSection, nSkillCount, nVersion, &nRead);
    if (nResult)
        return nResult;
    sub_00568DB0(pGame, pPlayer);
    if (nLeftSkillId)
        D2GAME_AssignSkill_6FD13800(pPlayer, 1, nLeftSkillId, -1);
    if (nRightSkillId)
        D2GAME_AssignSkill_6FD13800(pPlayer, 0, nRightSkillId, -1);
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = nLeftSkillId;
    pPlayerData->nRightSkillId = nRightSkillId;
    nSize -= nRead;
    pSection += nRead;
    nResult = sub_005337F0_ReadItems(pGame, pPlayer, pSection, nVersion, nSize, 0, &nRead);
    if (!nResult)
    {
        nSize -= nRead;
        pSection += nRead;
        nResult = PLRSAVE_ReadCorpseSection(pGame, pPlayer, pSection, nVersion, nSize, &nRead);
        if (!nResult)
        {
            nSize -= nRead;
            pSection += nRead;
            nResult = sub_00533C70_ReadLegacyMerc(pGame, pPlayer, pSection, nVersion, nSize, &nRead);
            if (!nResult)
            {
                pSection += nRead;
                nRead = 0;
                sub_00533F70_ReadHotkeySection(pPlayer, pSection, nVersion, &nRead);
            }
        }
    }
    STATLIST_SetUnitStat(pPlayer, 6, nHitpoints, 0);
    STATLIST_SetUnitStat(pPlayer, 8, nMana, 0);
    STATLIST_SetUnitStat(pPlayer, 0x44, 100, 0);
    STATLIST_SetUnitStat(pPlayer, 0x43, 100, 0);
    STATLIST_SetUnitStat(pPlayer, 0x45, 100, 0);
    int nClass;
    if (!pPlayer)
        nClass = -1;
    else
        nClass = pPlayer->dwClassId;
    const int nLevel = STATLIST_GetUnitBaseStat(pPlayer, 12, 0);
    const int nNextExperience = DATATBLS_GetLevelThreshold(nClass, nLevel);
    STATLIST_SetUnitStat(pPlayer, 0x1E, nNextExperience, 0);
    if (CLIENTS_GetWeaponSwitch(pClient))
        D2GAME_PACKETS_SendPacket0x97_6FC3FB60(pClient);
    return 0;
}
