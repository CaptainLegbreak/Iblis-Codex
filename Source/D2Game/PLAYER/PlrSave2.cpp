#include "D2Game.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define PLRSAVE2_WAYPOINT_HEADER 0x5357
#define PLRSAVE2ERROR_BAD_WAYPOINT 0x10
#define PLRSAVE2_SKILLS_MARKER 0x6669
#define NUMBER_OF_PLAYERCLASSES 7
#define PLRSAVE2ERROR_BAD_PLAYERINTRO 17
#define PLRSAVE2ERROR_BAD_PET 22
#define STAT_HITPOINTS 6
#define PLRSAVE2ERROR_BAD_STATS 0x12
#define PLRSAVE2ERROR_BAD_SKILLS 0x13
#define ITEMSTATCOSTFLAGINDEX_CSVSIGNED 13
#define UNITFLAG_SKSRVDOFUNC 0x00000040
#define UNITFLAG_HASEVENTSOUND 0x00000400
#define UNITFLAG_HASTXTMSG 0x00000100
#define UNITFLAG_DOUPDATE 0x00000001
#define UNITFLAGEX_HASINV 0x00000001
#define UNITFLAGEX_ITEMINIT 0x00000010
#define PLRMODE_NEUTRAL 1
#define PLRMODE_TOWNNEUTRAL 5
#define OBJMODE_OPERATING 1
#define OBJMODE_OPENED 2
#define OBJMODE_SPECIAL1 3
#define OBJMODE_SPECIAL2 4
#define LEVEL_HARROGATH 109
#define UNIT_PLAYER 0
#define STAT_MANA 8
#define STAT_STAMINA 10
#define STAT_LEVEL 12
#define STAT_GOLD 14
#define STAT_GOLDBANK 15
#define STAT_NEXTEXP 30
#define STAT_VELOCITYPERCENT 67
#define STAT_ATTACKRATE 68
#define STAT_OTHER_ANIMRATE 69
struct D2RunesTxt;
struct D2SaveSkillKeyStrc;
struct D2SaveHeaderStrc;
struct D2PlayerDataStrc;
struct D2WaypointSaveFlagStrc;
struct D2WaypointSaveDataStrc;
struct D2PlrIntroSaveStrc;
struct T0056A6F0;
struct D2Act5Quest3Strc;

struct D2GameStrc
{
    char unk0x00[0x6D];
    unsigned char nDifficulty;
    char unk0x6E[0x02];
    int bExpansion;
    int dwGameType;
    char unk0x78[0x04];
    unsigned int dwInitSeed;
    unsigned char unk_80[0x28];
    int dwGameFrame;
};

struct D2DataTablesStrc
{
    char unk0x00[0xBA8];
    int nHighestClassSkillCount;
    unsigned char unk_BAC[0x20];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0x04];
    int nItemStatCostTxtRecordCount;
};

struct D2SaveSkillKeyStrc
{
    unsigned short nSkill;
    unsigned short nKey;
};

#pragma pack(push, 1)
struct D2SaveHeaderStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    char unk0x08[0x08];
    unsigned int dwWeaponSwitch;
    char szName[16];
    unsigned int dwSaveFlags;
    unsigned char nClass;
    unsigned char nStats;
    unsigned char nSkills;
    unsigned char nLevel;
    unsigned int dwCreateTime;
    unsigned int dwLasTime;
    unsigned int dwPlayTime;
    D2SaveSkillKeyStrc SkillKeys[16];
    unsigned short nLeftSkillId;
    unsigned short nLeftSkillItemIndex;
    unsigned short nRightSkillId;
    unsigned short nRightSkillItemIndex;
    unsigned short nSwitchLeftSkillId;
    unsigned short nSwitchLeftSkillItemIndex;
    unsigned short nSwitchRightSkillId;
    unsigned short nSwitchRightSkillItemIndex;
    unsigned char nComponent[16];
    unsigned char nCompColor[16];
    unsigned char nTown[3];
    unsigned int dwMapSeed;
    char unk0xAF[0x20];
    unsigned char nGuildEmblemBgColor;
    char unk0xD0[0x7F];
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" long __cdecl _time32(long* pTime); // 0x006850E6
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc* pClient, unsigned char* pBackgroundColor, unsigned char* pForegroundColor, unsigned char* pEmblemType); // 0x00539190
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0
int __fastcall sub_005385C0_GetPlayTime(D2ClientStrc* pClient); // 0x005385C0
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient); // 0x005385F0
int __fastcall CLIENTS_GetFlags(D2ClientStrc* pClient); // 0x00538640
int __fastcall CLIENTS_GetCreateTime(D2ClientStrc* pClient); // 0x00538790
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
void __fastcall CLIENTS_GetSkillHotKey(D2ClientStrc* pClient, int nId, int* pSkillId, int* pHand, int* pItemGUID); // 0x005390D0
unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc* pClient); // 0x00539220

struct D2UnitStrc
{
    int dwUnitType;
    union
    {
        char unk0x04[0x08];
        int dwClassId;
    };
    unsigned int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x4C];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
unsigned short __fastcall PLRSAVE2_GetItemIndex(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGUID); // 0x00568DC0
void __fastcall PLRSAVE2_WriteMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SaveHeaderStrc* pSaveHeader); // 0x00568E60
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
void __stdcall UNITS_GetSwitchLeftSkillData(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags); // 0x00623220
void __stdcall UNITS_GetSwitchRightSkillData(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags); // 0x00623290
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
void __stdcall INVENTORY_GetItemSaveGfxInfo(D2UnitStrc* pUnit, unsigned char* pComponents, unsigned char* pColors); // 0x0063E510
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

struct D2WaypointDataStrc
{
    unsigned short nFlag0;
    unsigned short unk0x02;
    int unk0x04[3];
};

struct D2PlayerDataStrc
{
    char unk0x00[0x1C];
    D2WaypointDataStrc* pWaypointData[3];
    unsigned char unk_28[0x38];
    D2PlrIntroStrc* pPlayerIntro[3];
    unsigned char unk_6C[0x4];
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillFlags;
    int nLeftSkillFlags;
    int nSwitchRightSkillId;
    int nSwitchLeftSkillId;
    int nSwitchRightSkillFlags;
    int nSwitchLeftSkillFlags;
};

#pragma pack(push, 1)
struct D2WaypointSaveFlagStrc
{
    D2WaypointDataStrc flags;
    unsigned int unk0x10;
    unsigned int unk0x14;
};

struct D2WaypointSaveDataStrc
{
    unsigned short nHeader;
    int unk0x02;
    unsigned short nRecordSize;
    D2WaypointSaveFlagStrc waypoints[3];
};

#pragma pack(pop)

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDest, const D2WaypointDataStrc* pSource); // 0x00661030
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0
int __fastcall sub_00531BB0_WriteItemList(void* pArg1, void* pArg2, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
unsigned int __stdcall FOG_ComputeChecksum(const unsigned char* pData, unsigned int nSize); // 0x00411130
int __fastcall PLRSAVE2_WriteSaveHeader(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00568F20
int __fastcall sub_00569320_WriteQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569320
int __fastcall PLRSAVE2_WriteWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x005693E0
int __fastcall PLRSAVE2_WritePlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569490
int __fastcall PLRSAVE2_WritePlayerStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569540
int __fastcall sub_005696F0_WriteSkillSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x005696F0
int __fastcall sub_005697B0_WriteItemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a6, int a7, int bSizing); // 0x005697B0
int __fastcall PLRSAVE2_WriteCorpsesSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing); // 0x005697F0
int __fastcall sub_005699A0_WriteMercSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing); // 0x005699A0
int __fastcall PLRSAVE2_WriteIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing); // 0x00569A00

struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char unk0x04[3][8];
    unsigned char unk0x1C[3][8];
};
int __fastcall sub_0056A7E0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError); // 0x0056A7E0
void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055F4F0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2ItemStatCostTxt
{
    char unk0x00[0x04];
    unsigned char nItemStatFlags[4];
    char unk0x08[0x02];
    unsigned char nCsvBits;
    unsigned char nCsvParam;
    char unk0x0C[0x144 - 0x0C];
};

extern const unsigned int gdwBitMasks[32]; // 0x006CE268
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00411020
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits); // 0x00411030
int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0
void __fastcall sub_0053C5D0(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053C5D0

struct T0056A6F0 { unsigned char value; };

void __fastcall sub_0056DEB0(Unit*,int,int,int); // 0x0056DEB0

enum { REMOVE_SKILL = 1 };

struct D2QuestDataStrc
{
    int nQuestNo;
    D2GameStrc* pGame;
    char unk0x08[0x10];
    void* pQuestDataEx;
};

struct D2Act5Quest3Strc
{
    char unk0x00[0xAD];
    unsigned char bChangeToSpecialObjectModeOutsideTown;
    unsigned char bChangeToSpecialObjectModeInTown;
    char unk0xAF[0x2D];
    int nObjectUpdateInvocations;
};

int __fastcall sub_005337F0_ReadItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize); // 0x005337F0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553990
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
void __fastcall sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553490
int __fastcall sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x00554CA0
void __fastcall sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FC50
void __fastcall sub_6FC752A0(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00581A20
void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740
void __fastcall sub_00571620(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int a4); // 0x00597890
void __fastcall sub_6FCC6540(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char nAnimMode;
    unsigned char nPad09;
    unsigned short nPad0A;
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned short nPad12;
    int nItemFileIndex;
};
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion); // 0x00558CB0
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit); // 0x00564CB0
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0
void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00563470
int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, int nSkillId, int nHand, int nItemGUID); // 0x005390A0
int __fastcall sub_0056AF20_GetItemGUIDFromIndex(D2GameStrc* pGame, D2UnitStrc* pUnit, int nIndex); // 0x0056AF20
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall DATATBLS_GetLevelThreshold(int nClass, int nLevel); // 0x00611800
void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc* pClient); // 0x0053E110

int __fastcall sub_00568D80_FindTerminator(const char* szText, int nSize)
{
    const char* pStart = szText;
    const char* pEnd = szText + nSize;
    while (szText < pEnd && *szText)
    {
        ++szText;
    }

    if (szText >= pEnd)
    {
        return -1;
    }

    return szText - pStart;
}

// 0x00568F20
int __fastcall PLRSAVE2_WriteSaveHeader(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    D2ClientStrc* pClient;
    unsigned char* pSection = *ppSection;
    pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x1B4);
    if (!pClient)
    {
        return 2;
    }

    const char* szName = CLIENTS_GetName(pClient);
    if (!szName)
    {
        return 2;
    }

    if (sub_00568D80_FindTerminator(szName, 16) < 1)
    {
        return 2;
    }

    if (pSection + sizeof(D2SaveHeaderStrc) > pEnd)
    {
        return 1;
    }

    D2SaveHeaderStrc saveHeader;
    memset(&saveHeader, 0, sizeof(D2SaveHeaderStrc));
    saveHeader.dwHeaderMagic = 0xAA55AA55;
    saveHeader.dwVersion = 0x60;
    SStrCopy(saveHeader.szName, szName, 0x7FFFFFFF);
    saveHeader.dwSaveFlags = CLIENTS_GetFlags(pClient);
    if (pGame->bExpansion)
    {
        saveHeader.dwSaveFlags |= 0x20;
    }

    if (pGame->dwGameType)
    {
        saveHeader.dwSaveFlags |= 0x40;
    }

    saveHeader.nClass = CLIENTS_GetClassId(pClient);
    saveHeader.nLevel = STATLIST_UnitGetStatValue(pPlayer, 0xC, 0);
    saveHeader.dwCreateTime = CLIENTS_GetCreateTime(pClient);
    saveHeader.dwLasTime = _time32(0);
    saveHeader.dwPlayTime = sub_005385C0_GetPlayTime(pClient);
    saveHeader.dwMapSeed = pGame->dwInitSeed;
    saveHeader.nStats = 16;
    saveHeader.nSkills = (unsigned char)sgptDataTables->nHighestClassSkillCount;
    if (CLIENTS_GetWeaponSwitch(SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x1DD)))
    {
        saveHeader.dwWeaponSwitch |= 1;
    }

    int nGUID;
    int nSkill;
    for (int i = 0; i < 16; ++i)
    {
        int nParam;
        CLIENTS_GetSkillHotKey(pClient, i, &nSkill, &nParam, &nGUID);
        D2_ASSERT(nSkill < 0x8000, 0x1EB);
        saveHeader.SkillKeys[i].nSkill = (unsigned short)nSkill | (nParam != 0 ? 0x8000 : 0);
        saveHeader.SkillKeys[i].nKey = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);
    }

    D2SkillStrc* pSkill = UNITS_GetLeftSkill(pPlayer);
    if (pSkill)
    {
        saveHeader.nLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrSave2.cpp", 0x1F5);
        saveHeader.nLeftSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, SKILLS_GetOwnerGUIDFromSkill(pSkill));
    }

    pSkill = UNITS_GetRightSkill(pPlayer);
    saveHeader.nRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrSave2.cpp", 0x1FC);
    saveHeader.nRightSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, SKILLS_GetOwnerGUIDFromSkill(pSkill));

    int nSkillId;
    UNITS_GetSwitchLeftSkillData(pPlayer, &nSkillId, &nGUID);
    saveHeader.nSwitchLeftSkillId = nSkillId;
    saveHeader.nSwitchLeftSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);

    UNITS_GetSwitchRightSkillData(pPlayer, &nSkillId, &nGUID);
    saveHeader.nSwitchRightSkillId = nSkillId;
    saveHeader.nSwitchRightSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);

    saveHeader.nTown[pGame->nDifficulty] = CLIENTS_GetActNo(pClient) | 0x80;

    memset(saveHeader.nComponent, 0xFF, 16);
    memset(saveHeader.nCompColor, 0xFF, 16);
    INVENTORY_GetItemSaveGfxInfo(pPlayer, saveHeader.nComponent, saveHeader.nCompColor);
    PLRSAVE2_WriteMercData(pGame, pPlayer, &saveHeader);

    unsigned char nSaveField;
    unsigned char nUnused1;
    unsigned char nUnused2;
    CLIENTS_GetGuildEmblem(pClient, &nSaveField, &nUnused1, &nUnused2);
    saveHeader.nGuildEmblemBgColor = nSaveField;

    memcpy(pSection, &saveHeader, sizeof(D2SaveHeaderStrc));
    *ppSection = pSection + sizeof(D2SaveHeaderStrc);
    return 0;
}

// 0x005693E0
int __fastcall PLRSAVE2_WriteWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pNext = pSection + sizeof(D2WaypointSaveDataStrc);
    if (pNext > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2WaypointSaveDataStrc waypointSaveData = {};
    waypointSaveData.nHeader = PLRSAVE2_WAYPOINT_HEADER;
    waypointSaveData.unk0x02 = 1;
    waypointSaveData.nRecordSize = sizeof(D2WaypointSaveDataStrc);

    for (int i = 0; i < 3; ++i)
    {
        WAYPOINTS_ValidateAndCopyWaypointData(pPlayerData->pWaypointData[i], &waypointSaveData.waypoints[i].flags);
    }

    memcpy(pSection, &waypointSaveData, sizeof(D2WaypointSaveDataStrc));
    *ppSection = pNext;
    return 0;
}

// 0x005699A0
int __fastcall sub_005699A0_WriteMercSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing)
{
    unsigned char* pData = *ppSection;
    if (pGame->bExpansion)
    {
        *(unsigned short*)pData = 0x666A;
        pData += 2;

        D2UnitStrc* pPet = sub_6FC7E8B0(pGame, pPlayer, 7, 1);
        if (pPet)
        {
            const int nLength = sub_00531BB0_WriteItemList(pGame, pPet, pData, pEnd - pData, 0, a7, bSizing);
            if (nLength >= 0)
            {
                pData += nLength;
            }
            else
            {
                return 5;
            }
        }

        *ppSection = pData;
    }

    return 0;
}

// 0x0056A3E0
int __fastcall PLRSAVE2_ReadWaypointData(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pNext = pSection + sizeof(D2WaypointSaveDataStrc);
    if (pNext > pEnd)
    {
        return PLRSAVE2ERROR_BAD_WAYPOINT;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2WaypointSaveDataStrc* pWaypointSaveData = (D2WaypointSaveDataStrc*)pSection;
    if (pWaypointSaveData->nHeader != PLRSAVE2_WAYPOINT_HEADER)
    {
        return PLRSAVE2ERROR_BAD_WAYPOINT;
    }

    for (int i = 0; i < 3; ++i)
    {
        D2WaypointDataStrc* pSavedData = &pWaypointSaveData->waypoints[i].flags;
        if (pSavedData->nFlag0 != 0x102 && pSavedData->nFlag0 != 0x101 && pSavedData->nFlag0)
        {
            return PLRSAVE2ERROR_BAD_WAYPOINT;
        }

        WAYPOINTS_CopyAndValidateWaypointData(pPlayerData->pWaypointData[i], pSavedData);
    }

    *ppSection = pNext;
    return 0;
}

// 0x005696F0
int __fastcall sub_005696F0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd)
{
    unsigned char* pData = *ppSection;
    if (pData + sgptDataTables->nHighestClassSkillCount + 2 > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pData = PLRSAVE2_SKILLS_MARKER;
    pData += 2;

    const int nClassId = CLIENTS_GetClassId(SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrSave2.cpp", 775));
    if (nClassId >= NUMBER_OF_PLAYERCLASSES)
    {
        return 2;
    }

    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        *pData = SKILLS_GetSkillLevel(pUnit, SKILLS_GetSkillById(pUnit, nSkillId, -1), 0);
        ++pData;
    }

    *ppSection = pData;
    return 0;
}

// 0x00569AD0
int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int a6, int a7)
{
    unsigned char aBuffer[0x8000];
    const unsigned char* pEnd = &pData[nMaxSize];
    unsigned char* pSection = pData;
    unsigned char* pBuffer = aBuffer;
    *pSize = 0;

    int nResult;
    if (!pPlayer || pPlayer->dwUnitType != 0)
    {
        nResult = 2;
        goto LABEL_FAIL;
    }

    nResult = PLRSAVE2_WriteSaveHeader(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = sub_00569320_WriteQuestSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = PLRSAVE2_WriteWaypointData(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = PLRSAVE2_WritePlrIntroSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = PLRSAVE2_WritePlayerStats(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;
    nResult = sub_005696F0_WriteSkillSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto LABEL_FAIL;

    {
        const int nRemaining = pEnd - pSection;
        nResult = sub_005697B0_WriteItemSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a6, a7, 1);
        if (nResult) goto LABEL_FAIL;
        const int nItemsSize = pBuffer - aBuffer;
        nResult = PLRSAVE2_WriteCorpsesSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a7, 1);
        if (nResult) goto LABEL_FAIL;
        if (pGame->bExpansion)
        {
            nResult = sub_005699A0_WriteMercSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a7, 1);
            if (nResult) goto LABEL_FAIL;
            nResult = PLRSAVE2_WriteIronGolemSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], a7, 1);
            if (nResult) goto LABEL_FAIL;
        }

        const int nBufferSize = pBuffer - aBuffer;
        const unsigned char* pItemsEnd = nBufferSize <= nRemaining ? pEnd : pSection + (nItemsSize - nBufferSize + nRemaining);
        nResult = sub_005697B0_WriteItemSection(pGame, pPlayer, &pSection, pItemsEnd, a6, a7, 0);
        if (nResult) goto LABEL_FAIL;
        nResult = PLRSAVE2_WriteCorpsesSection(pGame, pPlayer, &pSection, pEnd, a7, 0);
        if (nResult) goto LABEL_FAIL;
        if (pGame->bExpansion)
        {
            nResult = sub_005699A0_WriteMercSection(pGame, pPlayer, &pSection, pEnd, a7, 0);
            if (nResult) goto LABEL_FAIL;
            nResult = PLRSAVE2_WriteIronGolemSection(pGame, pPlayer, &pSection, pEnd, a7, 0);
            if (nResult) goto LABEL_FAIL;
        }
    }

    {
        const unsigned int nSize = pSection - pData;
        *pSize = nSize;
        *(unsigned int*)(pData + 8) = nSize;
        *(unsigned int*)(pData + 0xC) = FOG_ComputeChecksum(pData, nSize);
    }
    return 0;

LABEL_FAIL:
    *pSize = 0;
    return nResult;
}

// 0x0056A470
int __fastcall sub_0056A470(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    D2PlrIntroSaveStrc* pPlrIntro = (D2PlrIntroSaveStrc*)*ppSection;
    unsigned char* pSectionEnd = *ppSection + sizeof(D2PlrIntroSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    if (pPlrIntro->nHeader != 0x7701)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        PLRINTRO_CopyBufferToQuestIntroFlags(pPlayerData->pPlayerIntro[i], pPlrIntro->unk0x04[i]);
        PLRINTRO_CopyBufferToNpcIntroFlags(pPlayerData->pPlayerIntro[i], pPlrIntro->unk0x1C[i]);
    }

    *ppSection = pSectionEnd;
    return 0;
}

// 0x0056AC10
int __fastcall PLRSAVE2_ReadPetSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion, int* a6)
{
    unsigned char* pSection = *ppSection;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    if (pSection + 2 > pEnd)
    {
        return 0;
    }

    if (*(unsigned short*)pSection != 0x666A)
    {
        if (a6)
        {
            *a6 = 101;
        }

        return PLRSAVE2ERROR_BAD_PET;
    }

    unsigned char* pData = pSection + 2;
    if (pMerc)
    {
        int nError = 0;
        if (sub_0056A7E0(pGame, pMerc, &pData, pEnd, dwVersion, 0, &nError))
        {
            if (a6)
            {
                *a6 = nError;
            }

            return PLRSAVE2ERROR_BAD_PET;
        }

        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pMerc, 0, 0);
        sub_0055F4F0(pGame, pMerc, 0);
        if (!SUNIT_IsDead(pMerc))
        {
            STATLIST_SetUnitStat(pMerc, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pMerc), 0);
        }
    }

    *ppSection = pData;
    return 0;
}

// 0x0056AF20
int __fastcall sub_0056AF20_GetItemGUIDFromIndex(D2GameStrc* pGame, D2UnitStrc* pUnit, int nIndex)
{
    if (!pUnit->pInventory)
    {
        return -1;
    }

    int nCounter = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (nCounter == nIndex)
        {
            if (pCheckedItem)
            {
                return pCheckedItem->dwUnitId;
            }

            break;
        }

        ++nCounter;
    }

    return -1;
}

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0056A4F0
int __fastcall PLRSAVE2_ReadStatsEx(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pData = *ppSection;
    if (&pData[2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6667)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    D2BitBufferStrc bitBuffer;
    BITMANIP_Initialize(&bitBuffer, pData, pEnd - pData);

    for (int nStatId = sub_00411020_ReadBits(&bitBuffer, 9); nStatId < 511; nStatId = sub_00411020_ReadBits(&bitBuffer, 9))
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
        if (!pItemStatCostTxtRecord || pItemStatCostTxtRecord->nCsvBits <= 0)
        {
            return PLRSAVE2ERROR_BAD_STATS;
        }

        int nLayer = 0;
        if (pItemStatCostTxtRecord->nCsvParam > 0)
        {
            nLayer = (unsigned short)BITMANIP_ReadSigned(&bitBuffer, pItemStatCostTxtRecord->nCsvParam);
        }

        int nValue = 0;
        if (pItemStatCostTxtRecord->nCsvBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_CSVSIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_CSVSIGNED & 7])
        {
            nValue = BITMANIP_ReadSigned(&bitBuffer, pItemStatCostTxtRecord->nCsvBits);
        }
        else
        {
            nValue = sub_00411020_ReadBits(&bitBuffer, pItemStatCostTxtRecord->nCsvBits);
        }

        STATLIST_SetUnitStat(pUnit, nStatId, nValue, nLayer);
    }

    *ppSection = &pData[BITMANIP_GetSize(&bitBuffer)];
    return 0;
}

// 0x0056A710
int __fastcall PLRSAVE2_ReadSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nSkills)
{
    unsigned char* pData = *ppSection;
    if (&pData[2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6669)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 1773);
    if (!pClient)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    const int nClassId = CLIENTS_GetClassId(pClient);
    for (int i = 0; i < nSkills; ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        if (i > SKILLS_GetPlayerSkillCount(nClassId))
        {
            break;
        }

        if (pData[i])
        {
            D2GAME_SetSkills_6FD14C60(pPlayer, nSkillId, pData[i], 1);
        }
    }

    sub_0053C5D0(pClient, pPlayer);
    sub_6FD14C30(pPlayer);

    *ppSection = &pData[nSkills];
    return 0;
}

// 0x0056A6F0
void __fastcall sub_0056A6F0(Game* unused,Unit* unit,int skill,T0056A6F0 level)
{
    if(level.value) sub_0056DEB0(unit,skill,level.value,REMOVE_SKILL);
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x0056A7E0
int __fastcall sub_0056A7E0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError)
{
    unsigned char* pSection = *ppSection;
    int nSize = 0;
    const int nError = sub_005337F0_ReadItems(pGame, pUnit, pSection, nVersion, pEnd - pSection, 0, &nSize);
    if (nError)
    {
        if (pError)
        {
            *pError = nError;
        }
        return 0x14;
    }

    *ppSection = pSection + nSize;
    return 0;
}

// 0x00577670
D2UnitStrc* __fastcall sub_00577670_FindInventoryItemByClassId(D2UnitStrc* pUnit, int nClassId)
{
    if (pUnit->pInventory)
    {
        D2UnitStrc* pNext;
        for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = pNext)
        {
            D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pItem);
            pNext = INVENTORY_GetNextItem(pItem);
            if ((!pCheck ? -1 : pCheck->dwClassId) == nClassId && !UNIT_HasFlagEx(pCheck, UNITFLAGEX_ITEMINIT))
            {
                return pCheck;
            }
        }
    }

    return 0;
}

// 0x0057F020
void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        nMode = DUNGEON_IsRoomInTown(pRoom) != 0 ? PLRMODE_TOWNNEUTRAL : PLRMODE_NEUTRAL;
    }

    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    UNITS_SetUsedSkill(pPlayer, 0);
}

// 0x00580460
int __fastcall sub_6FC80EE0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (!pSkill)
    {
        return 2;
    }

    UNITS_SetAnimationFrame(pPlayer, nSkillLevel);

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 1 && (sub_6FCBC7E0(pGame, pPlayer), sub_6FCBC930(pGame, pPlayer) == 2))
    {
        SKILLS_SetFlags(pSkill, nSkillFlags | 2);
    }
    else
    {
        if (pPlayer && UNIT_HasFlag(pPlayer, UNITFLAG_SKSRVDOFUNC) || nSkillId != 1 && nSkillId != 2)
        {
            return (SUNIT_IsDead(pPlayer) != 0) + 1;
        }
    }

    sub_6FD13410(pGame, pPlayer);
    return (SUNIT_IsDead(pPlayer) != 0) + 1;
}

// 0x00581AD0
void __fastcall sub_6FC75350(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (pUnit)
    {
        if (UNIT_HasFlag(pUnit, UNITFLAG_DOUPDATE))
        {
            sub_6FC752A0(pUnit, pClient);
        }

        if (UNIT_HasFlag(pUnit, UNITFLAG_HASEVENTSOUND))
        {
            D2GAME_UpdateUnit_6FCC6080(pUnit, pClient);
        }

        if (UNIT_HasFlag(pUnit, UNITFLAG_HASTXTMSG))
        {
            sub_00571620(pUnit, pClient);
        }

        if (UNIT_HasFlagEx(pUnit, UNITFLAGEX_HASINV))
        {
            D2GAME_INVMODE_First_6FC40FB0(pGame, pUnit, pClient, 0);
        }
    }

    sub_6FCC6540(pUnit, pClient);
}

// 0x0058A730
void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;

    switch (nAnimMode)
    {
    case OBJMODE_OPERATING:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_OPENED);
        break;

    case OBJMODE_OPENED:
    {
        D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
        if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_HARROGATH)
        {
            if (++pQuestDataEx->nObjectUpdateInvocations > 5)
            {
                pQuestDataEx->bChangeToSpecialObjectModeInTown = 1;
            }

            if (pQuestDataEx->bChangeToSpecialObjectModeInTown)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        else
        {
            if (pQuestDataEx->bChangeToSpecialObjectModeOutsideTown)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        break;
    }

    case OBJMODE_SPECIAL1:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL2);
        break;
    }

    EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
}

// 0x0056ACE0
int __fastcall PLRSAVE2_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc** ppItem, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion)
{
    unsigned char* pSection = *ppSection;
    *ppItem = 0;

    unsigned int nSize = pEnd - pSection;

    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstream(pSection, nSize, 1, &tItemSave, dwVersion);
    if (tItemSave.nClassId == -1)
    {
        return 0;
    }

    D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize, 1, &tItemSave, &nSize, dwVersion);
    if (!pItem)
    {
        return 0;
    }

    pSection += nSize;
    sub_00564CB0_Nop(pItem);

    const int nSockets = tItemSave.nItemFileIndex;
    D2UnitStrc* pParentItem = pItem;
    for (int i = 0; i < nSockets; ++i)
    {
        nSize = pEnd - pSection;
        ITEMS_GetCompactItemDataFromBitstream(pSection, nSize, 1, &tItemSave, dwVersion);

        pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize, 1, &tItemSave, &nSize, dwVersion);
        if (!pItem)
        {
            SUNIT_RemoveUnit(pGame, pParentItem);
            return 0;
        }

        pSection += nSize;
        sub_00564CB0_Nop(pItem);
        UNITS_ChangeAnimMode(pItem, 4);

        const int nSocketableGUID = pItem->dwUnitId;
        int bPlaced;
        if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pPlayer, nSocketableGUID, sub_00451F50_GetUnitGUID(pParentItem), &bPlaced, 0, 1, 0, 0))
        {
            SUNIT_RemoveUnit(pGame, pParentItem);
            return 0;
        }
    }

    if (ITEMS_GetItemFlags(pParentItem) & 0x4000000 && !ITEMS_GetRunesTxtRecordFromItem(pParentItem))
    {
        ITEMMODE_DetachItemFromOwner(pGame, pPlayer, pParentItem);
        pParentItem = 0;
    }

    *ppSection = pSection;
    *ppItem = pParentItem;
    return 1;
}

inline void UNITS_SetInventoryGold(D2UnitStrc* pUnit, unsigned int nGold)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const unsigned int nLimit = UNITS_GetInventoryGoldLimit(pUnit);
            if (nGold > nLimit)
            {
                nGold = nLimit;
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_GOLD, nGold, 0);
    }
}

inline void UNITS_SetStashGold(D2UnitStrc* pUnit, unsigned int nGold)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const unsigned int nLimit = UNITS_GetStashGoldLimit(pUnit);
            if (nGold > nLimit)
            {
                nGold = nLimit;
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, nGold, 0);
    }
}

// 0x0056AF80
void __fastcall PLRSAVE2_InitializeStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nHitpoints, int nMana)
{
    D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\PLAYER\\PlrSave2.cpp", 2222);
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);

    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    if (nGold < 0 || nGold > UNITS_GetInventoryGoldLimit(pUnit))
    {
        UNITS_SetInventoryGold(pUnit, 0);
    }

    const int nGoldBank = STATLIST_UnitGetStatValue(pUnit, STAT_GOLDBANK, 0);
    if (nGoldBank < 0 || nGoldBank > UNITS_GetStashGoldLimit(pUnit))
    {
        UNITS_SetStashGold(pUnit, 0);
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);

    for (int i = 0; i < 16; ++i)
    {
        int nSkillId;
        int nHand;
        int nItemIndex;
        CLIENTS_GetSkillHotKey(pClient, i, &nSkillId, &nHand, &nItemIndex);
        if (nItemIndex)
        {
            nItemIndex = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, nItemIndex);
            CLIENTS_SetSkillHotKey(pClient, i, nSkillId, nHand, nItemIndex);
        }
    }

    if (pPlayerData->nLeftSkillFlags)
    {
        pPlayerData->nLeftSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nLeftSkillFlags);
    }

    if (pPlayerData->nRightSkillFlags)
    {
        pPlayerData->nRightSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nRightSkillFlags);
    }

    if (pPlayerData->nSwitchLeftSkillFlags)
    {
        pPlayerData->nSwitchLeftSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nSwitchLeftSkillFlags);
    }

    if (pPlayerData->nSwitchRightSkillFlags)
    {
        pPlayerData->nSwitchRightSkillFlags = sub_0056AF20_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nSwitchRightSkillFlags);
    }

    if (pPlayerData->nLeftSkillId)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 1, pPlayerData->nLeftSkillId, pPlayerData->nLeftSkillFlags);
    }

    if (pPlayerData->nRightSkillId)
    {
        D2GAME_AssignSkill_6FD13800(pUnit, 0, pPlayerData->nRightSkillId, pPlayerData->nRightSkillFlags);
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMana, 0);
    STATLIST_SetUnitStat(pUnit, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_OTHER_ANIMRATE, 100, 0);
    const int nNextExp = DATATBLS_GetLevelThreshold(!pUnit ? -1 : pUnit->dwClassId, STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0));
    STATLIST_SetUnitStat(pUnit, STAT_NEXTEXP, nNextExp, 0);

    if (CLIENTS_GetWeaponSwitch(pClient))
    {
        D2GAME_PACKETS_SendPacket0x97_6FC3FB60(pClient);
    }
}
