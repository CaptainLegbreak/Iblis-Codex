#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2PlayerModes.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2Unicode.h"
#include "D2GameStrc.h"
#include "D2StormLink.h"
#include "D2Primitives.h"
#include "D2DrlgRooms.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2InactiveUnits.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
#include "D2QuestData.h"

#pragma intrinsic(_ReadWriteBarrier)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAX_MSG_SIZE 516

#define PCLASS_AMAZON 0

#define PCLASS_SORCERESS 1

#define PCLASS_NECROMANCER 2

#define PCLASS_BARBARIAN 4

#define PCLASS_DRUID 5

#define PCLASS_ASSASSIN 6

struct D2MonsterRegionStrc;

struct D2CorpseStrc;

struct D2SGameDataStrc;

struct D2ServerCallbackFunctions;

struct D2GSPacketClt6B;

struct D2NetPacketRecStrc;

struct D2NetLockStrc;

struct D2Net52BE10Strc;

struct D2UnitDescriptionListStrc;

struct Unicode;

struct D2MonStatsTxt;

struct D2ItemsTxt;

struct D2StormLinkStrc;

struct D2StormListAStrc;

struct D2StormChunkListStrc;

struct D2StormListArrayStrc;

struct D2StormHashTableStrc;

struct D2StormListStrc;

struct D2Storm4167B0Strc;

struct D2Storm4168F0Strc;

struct D2Storm416A90Strc;

struct D2HashKeyNoneStrc;

struct D2GameDataTableStrc;

union D2LargeIntegerUnion;

struct D2CriticalSectionStrc;

struct D2ActiveRoomStrc;

struct D2ClientStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2GSPacketSrv5A;

struct D2ObjectsTxt;

struct D2DataTablesStrc;

struct D2StormHashNodeStrc;

struct D2StormHashTable0052E650Strc;

struct D2FileTimeStrc;

struct D2StormSlotLink00530600Strc;

struct D2StormSlotList00530600Strc;

struct D2StormSlotArray00530600Strc;

struct D2StormHashTable00530600Strc;

extern char gData_00882028[]; // 0x00882028

extern int gdwGlobal_00882528; // 0x00882528

extern int gdwGlobal_0072FFA8; // 0x0072FFA8

extern char gData_00882428[]; // 0x00882428

extern int gdwGlobal_008822A4; // 0x008822A4

extern int gdwGlobal_008822A0; // 0x008822A0

extern int gdwGlobal_00882538; // 0x00882538

extern int gdwGlobal_00730190; // 0x00730190

extern int gdwGlobal_00882750; // 0x00882750

int __stdcall sub_00424E40(void* pArg); // 0x00424E40

extern char gData_006E0498[]; // 0x006E0498

extern char gData_006E0550[]; // 0x006E0550

extern char gData_006E0568[]; // 0x006E0568

extern int gdwGlobal_00731010; // 0x00731010

extern int gdwGlobal_00731008; // 0x00731008

void __stdcall GAME_SendGameList(void* pArg); // 0x0052E8E0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem); // 0x00409C80

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0

void __fastcall GAME_SendUnitRemovalToClient(D2ClientStrc* pClient, void* pUnit); // 0x0052DFB0

void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame); // 0x00536640

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

void __fastcall CLIENTS_FreeClientsFromGame(D2GameStrc* pGame); // 0x00537AC0

void __fastcall LEVEL_RemoveAllUnits(D2GameStrc* pGame); // 0x0053AFD0

void __fastcall D2GAME_PACKETS_SendPacket0x5C_6FC3E090(D2ClientStrc* pClient, int nUnitGUID); // 0x0053CA90

void __fastcall ARENA_FreeArena(D2GameStrc* pGame); // 0x0053F500

void __fastcall PARTY_FreePartyControl(D2GameStrc* pGame); // 0x00540000

void __fastcall EVENT_FreeEventQueue(D2GameStrc* pGame); // 0x00541400

void __fastcall SUNITINACTIVE_FreeInactiveUnitLists(D2GameStrc* pGame); // 0x00543080

void __fastcall QUESTS_QuestFree(D2GameStrc* pGame); // 0x00543800

void __fastcall OBJRGN_FreeObjectControl(D2GameStrc* pGame); // 0x00546E90

void __fastcall MONSTERREGION_FreeAll(void* pMemPool, D2MonsterRegionStrc** ppMonsterRegion); // 0x00547B50

void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0054F060

void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00552610

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x005559A0

void __stdcall DUNGEON_FreeAct(D2DrlgActStrc* pAct); // 0x0061AFD0

D2CriticalSectionStrc gCriticalSection_6FD45800; // 0x00882D18

D2GameStrc* gpGame_6FD457FC; // 0x00882D34

int gnGamesGUIDs_6FD447F8[1024];                                                                            // 0x00882D38

void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc*, D2UnitStrc*, D2ClientStrc*); // 0x0053C940

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc*); // 0x0063D570

D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc*); // 0x0063D610

int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc*); // 0x0063D630

void __fastcall D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(D2ClientStrc*, int, int, unsigned char); // 0x0053DFB0

void __fastcall ARENA_SendScoresToClient(D2GameStrc*, D2ClientStrc*); // 0x0053FC70

int __fastcall CLIENTS_CheckState(int nClientId, int nState); // 0x00538930

int __fastcall CLIENTS_GetNameById(int nClientId, char* szName); // 0x00538B70

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId); // 0x0052C060

int __fastcall CLIENTS_GetCanonicalName(const char* szName, char* szGameName); // 0x00538C60

int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize); // 0x0053EFC0

D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                                 // 0x00883D50

void __fastcall D2GAME_PACKETS_SendGameLeft(int nClientId); // 0x0053B220

struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    unsigned char abParam[4];
    unsigned char nParam;
    char szText[32];
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame); // 0x0052DA90

D2GameStrc* __fastcall GAME_LockGame(int nGameGUID); // 0x0052E860

int __fastcall GAME_IsGameNameUnused(const char* szGameName); // 0x0052F8B0

D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId); // 0x00537810

int __fastcall CLIENTS_IsInGame(D2GameStrc* pGame, int nClientId); // 0x005381C0

int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient); // 0x00538590

int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient); // 0x005385F0

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830

void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer); // 0x005392F0

void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave); // 0x00539DA0

void __fastcall sub_0053B1B0_SendGameInfo(void* pClientId, unsigned short nGameId, int nClients, const char* szGameName); // 0x0053B1B0

void __fastcall SCMD_SendSkillList(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053C5D0

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

unsigned int __fastcall CLIENT_IsGameOwner(D2ClientStrc* pClient); // 0x00539030

#pragma pack(push, 1)

struct D2GSPacketClt6B
{
    unsigned char nHeader;
    unsigned char nSize;
    unsigned int dwTotalSize;
    unsigned char saveData[8192];
};

#pragma pack(pop)

typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __stdcall SERVER_SetRemoveClientCallback(D2NET_Unk_Callback pfCallback); // 0x0052B5C0

int __stdcall GAME_AbortClientById(int nClientId, int a2, int a3); // 0x005300F0

void __fastcall SUNITPROXY_FillGlobalItemCache(); // 0x00536F80

void __fastcall CLIENTS_Initialize(); // 0x005376C0

int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int a6, int a7); // 0x00538CE0

struct D2NetPacketRecStrc
{
    unsigned char data[MAX_MSG_SIZE];
    int nPacketSize;
    unsigned long dwTickCount;
    D2NetPacketRecStrc* pNext;
};

struct D2NetLockStrc
{
    D2CriticalSectionStrc tLock;

    void Lock(int nUnused);
    void Unlock(int nUnused);
};

struct D2Net52BE10Strc
{
    char unk0x00[0xD0];
    char aData[4];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);

extern "C" const char szD2NetCpp_006E0488[];

extern int gnConnectionMode_00882D10;

int gbD2ServerCallbackFunctionsInitialized_6FD45834;                                                        // 0x00883D54

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

typedef void(__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

extern UnitDescriptionFunction gpfGetDescription_6FD2CA64[5]; // 0x0073107C

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

struct D2StormOwnedLinkStrc : D2StormLinkStrc
{
    D2StormOwnedLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormOwnedLinkStrc()
    {
        Unlink();
    }
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormOwnedLinkStrc m_terminator;

    D2StormListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        D2StormLinkStrc* pPrevLink;
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    void LinkToTail(char* pNode)
    {
        LinkNode(pNode, 2, 0);
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00450580_DeleteAll();                                                                          // 0x00450580
};

struct D2StormListArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;

    void sub_00450110_SetCount(unsigned int nCount);                                                        // 0x00450110
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableStrc();
    virtual void Destroy();
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    unsigned int sub_0052E0E0_Mask(unsigned int value);
    void sub_0044FA00_InternalClear(int bWarn);                                                             // 0x0044FA00
    void sub_0052FF20_GrowListArray();
};

extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

struct D2GameListStrc;

struct D2GameHashLinkStrc
{
    D2GameHashLinkStrc* m_prevlink;
    D2GameStrc* m_next;

    D2GameHashLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
        {
            return (D2GameHashLinkStrc*)~(int)m_next;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (char*)this - (char*)m_prevlink->m_next;
        }
        return (D2GameHashLinkStrc*)((char*)m_next + nLinkOffset);
    }

    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2GameHashListStrc
{
    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
};

struct D2GameDataTableStrc
{
    virtual void InternalDelete(D2GameStrc* pGame);
    virtual D2GameStrc* sub_NewNode(D2GameHashListStrc* pList, int nExtraBytes, int nFlags);
    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
    unsigned int m_fullnessIndicator;
    unsigned int f_14;
    unsigned int f_18;
    D2GameHashListStrc* m_slotlistarray;
    unsigned int f_20;
    unsigned int m_hashmask;
    char unk0x28[0x1C];
    D2HashKeyNoneStrc f_44;
    char unk0x45[0x3];
    unsigned int nSequence;
    int bWrapped;
    D2CriticalSectionStrc f_50;

    void SyncEnterLock(int* pLockHandle, int bForWriting);
    void SyncLeaveLock(int nLockHandle);
    void Unlock(int nLockHandle);
    void Unlink(D2GameStrc* pGame);                                                                         // 0x0052E490
    void sub_0052E590(D2GameStrc* pGame);
    void sub_0052E5B0(D2GameStrc* pGame);
    void DeleteUnlock(D2GameStrc* pGame, int nLockHandle);                                                  // 0x0052E5D0
    D2GameStrc* Ptr(unsigned int nHashValue, const D2HashKeyNoneStrc* pKey);                                // 0x0052E650
    D2GameStrc* sub_0052E6B0(unsigned int nHashValue);
    unsigned int sub_0052E6D0_GenerateHandle();
    int sub_00530600(unsigned int nSlot);                                                                   // 0x00530600
    D2GameStrc* sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags);
    D2GameStrc* sub_005308C0_NewHandle(unsigned int* pHandle);
    D2GameStrc* sub_005308F0_NewLock(unsigned int* pHandle, int* pLockedHandle);
    D2GameStrc* Lock(unsigned int nHashValue, int* pLockHandle, int bForWriting);

    D2GameStrc* LockInline(unsigned int nHashValue, int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&f_50);
        *pLockHandle = bForWriting ? 1 : -1;
        D2GameStrc* pGame = Ptr(nHashValue, &f_44);
        if (!pGame)
        {
            if (*pLockHandle)
            {
                LeaveCriticalSection(&f_50);
            }
            *pLockHandle = 0;
        }
        return pGame;
    }
};

void __fastcall SrvFreeGame(int nGameGUID, D2GameStrc* pGame); // 0x0052C7F0

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerUnion* pCount); // 0x006CC25C

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void); // 0x006CC544

extern int dword_6FD2CA10; // 0x0073100C

void __fastcall GAME_UpdateProgress(D2GameStrc* pGame); // 0x0052D870

void __fastcall GAME_FindGameOwnerCallback(D2ClientStrc* client, void* context); // 0x0052CBB0

void __fastcall GAME_FindFirstClientCallback(D2ClientStrc* client, void* context); // 0x0052CBD0

void __fastcall SrvEndGame(int clientId, int flag); // 0x005303D0

extern "C" void _ReadWriteBarrier(void);

struct D2StormHashNodeStrc
{
    unsigned int m_hashval;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc f_C;
};

struct D2StormHashTable0052E650Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* sub_0052E650_Ptr(unsigned int nHashVal, int nKey);
};

int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400

int __fastcall CLIENTS_GetFlags(D2ClientStrc*); // 0x00538640

void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc*, unsigned char*, unsigned char*, unsigned char*); // 0x00539190

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0

struct D2StormSlotLink00530600Strc
{
    D2StormSlotLink00530600Strc* m_prevlink;
    char* m_next;

    inline char* Next()
    {
        char* const pNext = (int)m_next <= 0 ? 0 : m_next;
        return pNext;
    }
};

struct D2StormSlotList00530600Strc
{
    int m_linkoffset;
    D2StormSlotLink00530600Strc m_terminator;

};

struct D2StormSlotArray00530600Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormSlotList00530600Strc* m_data;
    unsigned int m_chunk;

};

struct D2StormHashTable00530600Strc
{
    void* m_vtable;
    D2StormSlotList00530600Strc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArray00530600Strc m_slotlistarray;
    unsigned int m_slotmask;

    void sub_0052FF20_GrowListArray();  // 0x0052FF20
    int sub_00530600(unsigned int nSlot);
};

int gdwGlobal_00882D14; // 0x00882D14

struct D2GameInfoStrc
{
    int nGameId;
    unsigned int nInitSeed;
    int nClients;
    int nPlayers;
    int nMonsters;
    int nObjects;
    int nItems;
    int nMissiles;
    int nUniqueItems;
    int nNPCs;
    unsigned int dwLastUsedUnitGUID[6];
    int nPathTowardPct;
    int nPathClockPct;
    int nPathCounterPct;
    int nPathAStarPct;
    int nPathFoWallPct;
    int nPathTotalCalls;
    int nFrames;
    int nTime;
    int nFrameRate;
    char szGameName[16];
    char szGamePassword[16];
    char szGameDescription[32];
    unsigned char nArenaTemplate;
    unsigned char nMaxLevelDifference;
    unsigned char nMaxPlayers;
    unsigned char padding0xA7;
    unsigned int nArenaFlags;
    void* pMemoryPool;
};

#define PATHTYPE_ASTAR 1

#define PATHTYPE_TOWARD 2

#define PATHTYPE_MON_CIRCLE_CW 5

#define PATHTYPE_MON_CIRCLE_CCW 6

unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame);                                                  // 0x0053FD40

static int GAME_CountUnitsInLists(D2UnitStrc** pUnitLists);

unsigned long gdwPlayerPos_00883D4C; // 0x00883D4C

D2GameDataTableStrc* gpGameDataTbl_6FD45818; // 0x00883D38

int dword_6FD45844; // 0x00883D58

int gnTargetMsPerFrame_6FD457F8; // 0x00883D60

int __stdcall GAME_GetPlayerUnitsCount(unsigned short nGameId);

#define BUCKETS 128

#define INFO_DESCRIPTION_SIZE 16

#define GAME_ID_BIAS 1

#define UNLOCK_LINE 4196

struct D2UnitInfoStrc
{
    int nUnitType;
    int nClassId;
    int nUnitGUID;
    int nAnimMode;
    int nX;
    int nY;
    int nOwnerType;
    int nOwnerGUID;
    int unk0x20;
    char szDescription[INFO_DESCRIPTION_SIZE];
};

void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pUnitInfo);                           // 0x00553F30

struct D2GameNodeStrc
{
    ~D2GameNodeStrc();                                                                                      // 0x0044F820
};

static inline D2GameStrc* GAMELINK_Next(D2GameLinkStrc* pLink)
{
    return (int)pLink->pNext <= 0 ? 0 : pLink->pNext;
}

struct D2GameListStrc
{
    int nLinkOffset;
    D2GameLinkStrc tTerminator;

    D2GameLinkStrc* InlineLink(D2GameStrc* pGame)
    {
        return pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    }

    D2GameStrc* InlineNext(D2GameStrc* pGame)
    {
        return GAMELINK_Next(InlineLink(pGame));
    }

    D2GameStrc* RawNext(D2GameStrc* pGame);
    D2GameStrc* Next(D2GameStrc* pGame);
    D2GameStrc* DeleteNode(D2GameStrc* pGame);
};

struct D2MessageThreadArgsStrc
{
    int nParam1;
    int nParam2;
    char szMessage[0x100];
};

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* lpThreadAttributes, unsigned long dwStackSize, unsigned long (__stdcall* lpStartAddress)(D2MessageThreadArgsStrc*), D2MessageThreadArgsStrc* lpParameter, unsigned long dwCreationFlags, unsigned long* lpThreadId); // 0x006CC250

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430

int __stdcall SERVER_HackListClient(int nClientId, int a2, int a3);                                                  // 0x0052B4F0

void __stdcall GAME_SendMessageToAllClients(int a1, int nPacketParam, const char* szMessage);               // 0x0052F4C0

void __fastcall SrvDisconnectClientById(int nClientId, int nEventType);                                   // 0x00530270

void __fastcall CLIENTS_UpdatePing(int nClientId, int a2, int a3, int a4);                                  // 0x005389A0

int __fastcall CLIENTS_GetClientIdByName(const char* szClientName);                                         // 0x00538BF0

void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005433F0

int __stdcall DUNGEON_TestRoomCanUnTile(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom);                      // 0x0061A3F0

int __stdcall D2Common_10081_GetTileCountFromRoom(D2ActiveRoomStrc* pRoom);                                 // 0x0061A790

void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom);                     // 0x0061A910

extern int nInitSeed_6FDC2CA08;                                                                             // 0x00731004

int dword_6FD4581C;                                                                                         // 0x00883D3C

int dword_6FD45820;                                                                                         // 0x00883D40

int gnPeakMemoryUsageInLast10s_6FD45828;                                                                    // 0x00883D48

extern int gnTargetFrameRate_6FD2CA60;                                                                      // 0x00731014

int gnAct_6FD45824;                                                                                         // 0x00883D44

struct D2ClientInfoStrc;

void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20

void __fastcall CLIENTS_EnableCharacterUnlock(D2ClientStrc* pClient);                                                        // 0x00538320

void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState);                            // 0x005386D0

D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int a8, int a9); // 0x00539A30

void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);          // 0x0053B320

void __fastcall D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame); // 0x0053B340

struct D2GSPacketClt66
{
    unsigned char nHeader;
    char szGameName[16];
    unsigned char nGameType;
    unsigned char nPlayerClass;
    unsigned char nTemplate;
    unsigned char nDifficulty;
    char szClientName[16];
    unsigned char abArena[2];
    unsigned char abGameFlags[4];
    unsigned char unk0x2B;
    unsigned char unk0x2C;
    unsigned char nLocale;
};

extern int gbCheckHeartbeat_00730FFC;                                                                       // 0x00730FFC

int __stdcall SERVER_ReadGamePacket(unsigned char* pBuffer, int nSize);                              // 0x0052B2D0

int __stdcall SERVER_ReadSystemPacket(unsigned char* pBuffer, int nSize);                              // 0x0052B2F0

int __stdcall SERVER_ReadAdminPacket(unsigned char* pBuffer, int nSize);                              // 0x0052B310

void __fastcall GAME_ProcessAdminMessage(void* pData, int nSize);                                                       // 0x0052CC20

void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType);            // 0x0052CAF0

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag);                              // 0x00538670

void __fastcall CCMD_ProcessClientSystemMessage(void* pData, int nSize);                                    // 0x0053F100

void __fastcall ProcessClientMessage(void* pData, int nPacketSize);                                    // 0x0053F3D0

void __fastcall PLRMSG_BroadcastSystemMessage(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A9B0

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __fastcall GAME_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient);                      // 0x0052C210

void __fastcall sub_005394A0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY);

int __fastcall sub_00539760(D2ClientStrc* pClient, D2GameStrc* pGame, int a3, D2ActiveRoomStrc* pRoom, int nX, int nY);

void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nReason);           // 0x0053B260

#define INPUT_PREFIX 0

#define REPLY_FA 0xFA

#define REPLY_FB 0xFB

#define REPLY_FC 0xFC

#pragma pack(push,1)

struct Request {
#if INPUT_PREFIX
 char movedPrefix[INPUT_PREFIX];
#endif
 int client; unsigned char unused,command;
};

struct ShortResponse
{
    unsigned char command;
    char payload[15];
};

struct Array8
{
    unsigned int values[8];
};

struct ServerInfo {
 unsigned int a,b,c,d,e,f,g,h,i,j;
 char description[128];
 unsigned int a8,ac,b0,b4,b8,bc,c0,c4,c8,cc,d0;
 unsigned short d4;
 unsigned int d6,da,de,e2,e6;
 unsigned short unusedEA;
 unsigned int ec;
 Array8 f0;
 unsigned int f110;
};

struct Reply {
 unsigned char command;
 unsigned int a,b,c,d,e,f,g,h,i,j;
 char description[128];
 unsigned int a9,ad,b1,b5,b9,bd;
 Array8 c1;
 unsigned int e1,e5,e9,ed,f1;
 unsigned short f5;
 unsigned int f7,fb,ff,f103,f107,f10b,f10f,f113,f117;
 char reserved[0x4A];
};

#pragma pack(pop)

long gnCounter_00883D64;         // 0x00883D64

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);  // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);  // 0x006CC204

int __stdcall sub_0052B490_ObjectCall_6BED90(int,int,int);

int __stdcall sub_0052B330(unsigned char,int,void*,int);  // 0x0052B330

void __stdcall D2NET_10016(int);  // 0x0052B570

extern "C" int __cdecl strncmp(const char*,const char*,unsigned int);

void __fastcall sub_0054A9B0(D2GameStrc*,const char*,unsigned char);  // 0x0054A9B0

enum { MODE_MASK = 15 };

struct D2GameStatisticsStrc;

struct D2UnitInfoStrc;

struct HASHKEY_NONE;

struct D2GameHashLinkStrc;

struct D2GameHashListStrc;

int __cdecl sub_005377B0_CountFlaggedClients(); // 0x005377B0

void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct); // 0x0061AA20

extern int gnFrameRate_00731010; // 0x00731010

void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0052C410

void __fastcall GAME_SaveAllPlayers(D2GameStrc* pGame); // 0x0052CA10

void __stdcall GAME_RemoveUntilableRooms(D2GameStrc* pGame); // 0x0052D240

void __stdcall GAME_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected); // 0x0052D350

void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame); // 0x0052D7B0

void __fastcall CLIENTS_SynchronizePlayer(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x005380D0

void __fastcall LEVEL_FreeDrlgDeletes(D2GameStrc* pGame); // 0x0053A820

void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame); // 0x0053B000

unsigned int __fastcall ARENA_NeedsClientUpdate(D2GameStrc* pGame); // 0x0053FCA0

void __fastcall EVENT_IterateEvents(D2GameStrc* pGame); // 0x005414D0

void __fastcall SUNITINACTIVE_DeleteExpiredItemNodes(D2GameStrc* pGame, int nAct); // 0x00542AC0

void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame); // 0x00543E10

void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct); // 0x00558B90

void __fastcall PLAYERLIST_InitializePlayerRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055B620

int __stdcall D2Common_10073(D2ActiveRoomStrc* pRoom); // 0x0061A460

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

struct D2GameStatisticsStrc
{
    int nGamesCount;
    int nActiveMonsters;
    int nInactiveMonsters;
    int nPlayersCount;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

extern "C" const char gszGameSourceFile; // 0x006D5D1C

static unsigned int gnPeakMemoryUsage_00883D48; // 0x00883D48

static unsigned int gnPreviousMemUsageTick_00883D68; // 0x00883D68

void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType);

struct D2PoolSystemStrc;

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                              // 0x0040B380

int __cdecl sub_0040A040_GetPoolSystemCount(D2PoolSystemStrc* pSystem);                                     // 0x0040A040

void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);            // 0x00542B40

void __fastcall sub_6FC84D40(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket);                                 // 0x0054AA40

void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                  // 0x0054EC90

void __fastcall D2GAME_ITEMS_UpdateInventoryItems(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int bRefresh); // 0x0055DF00

D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                   // 0x0061A180

int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom);                                                      // 0x0061A4D0

void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet);                                           // 0x0061A510

static void GAME_UpdatePendingRooms(D2GameStrc* pGame);

static void GAME_DeleteInactiveItems(D2GameStrc* pGame);

static void GAME_UpdateAllClients(D2GameStrc* pGame);

static void GAME_UpdateFrameRate(D2GameStrc* pGame);

#define EVENTTYPE_STATREGEN 3

#define EVENTTYPE_DELAYEDPORTAL 11

struct D2SaveHeaderStrc;

struct D2StaticPathStrc;

struct D2PartyNodeStrc;

struct D2PartyStrc;

struct D2PartyControlStrc;

struct D2InactiveItemNodeStrc;

struct D2InactiveUnitListStrc;

struct D2QuestTimerStrc;

struct D2QuestInfoStrc;

struct D2DrlgCoordsStrc;

struct D2ObjectRoomCoordStrc;

struct D2ObjectControlStrc;

struct D2GSPacketSrv53;

struct D2ObjInitFnStrc;

struct D2UnkPlrMsgStrc;

struct D2PlayerDataStrc;

struct D2NpcEventStrc;

struct D2NpcGambleStrc;

struct D2NpcRecordStrc;

struct D2NpcControlStrc;

struct D2ArenaStrc;

struct D2RosterIterateStrc;

struct D2UnitProxyArgStrc;

struct D2GSPacketSrv8C;

struct D2GSPacketSrv8E;

enum D2C_MonStatsTxtFlagIndices
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};

typedef unsigned char (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuest);

struct D2QuestTimerStrc
{
    QUESTUPDATE pfUpdate;
    D2QuestDataStrc* pQuest;
    unsigned int dwTicks;
    unsigned int dwTimeout;
    D2QuestTimerStrc* pNext;
};

struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    D2QuestTimerStrc* pTimer;
    unsigned int dwTick;
};

struct D2ObjectRoomCoordStrc
{
    D2ActiveRoomStrc* pRoom;
    int nX;
    int nY;
    D2ObjectRoomCoordStrc* pNext;
};

struct D2GSPacketSrv53
{
    unsigned char nHeader;
    unsigned char nCycleIndex;
    unsigned char nCycleIndex1;
    unsigned char nCycleIndex2;
    unsigned char nCycleIndex3;
    unsigned char nTicks;
    unsigned char nTicks1;
    unsigned char nTicks2;
    unsigned char nTicks3;
    unsigned char nEclipse;
};

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc*, D2UnitStrc*, D2ClientStrc*, int);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc field_0;
    int field_4;
    int field_8;
};

extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2UnkPlrMsgStrc stru_6FD30708[20]; // 0x007319E8

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __stdcall SUNITPROXY_FillIGlobaltemCacheRecordForNpc(int nNpcId); // 0x00536D50

int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005387F0

void __fastcall D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(D2ClientStrc* pClient, char nHeader, char a3, int a4, char a5, int a6, int a7, short a8, short a9); // 0x0053B520

void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10); // 0x0053B570

void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket); // 0x0053C900

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055FDE0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall ENVIRONMENT_UpdateCycleIndex(D2DrlgActStrc* pAct, int nActNo); // 0x0061C040

void __stdcall ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(D2DrlgActStrc* pAct, int* pCycleIndex, int* pTicks, int* pEclipse); // 0x0061C330

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490

struct D2NpcEventStrc
{
    D2UnitStrc* pUnit;
    int field_4;
    int field_8;
    int field_C;
    D2NpcEventStrc* pNext;
};

struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
};

struct D2RosterIterateStrc
{
    int bFlag;
    D2UnitStrc* pUnit;
};

struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    unsigned char dwPlayerGUID1;
    unsigned char dwPlayerGUID1_1;
    unsigned char dwPlayerGUID1_2;
    unsigned char dwPlayerGUID1_3;
    unsigned char dwPlayerGUID2;
    unsigned char dwPlayerGUID2_1;
    unsigned char dwPlayerGUID2_2;
    unsigned char dwPlayerGUID2_3;
    unsigned char nFlags;
    unsigned char nFlags1;
};

struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char dwPlayerGUID;
    unsigned char dwPlayerGUID1;
    unsigned char dwPlayerGUID2;
    unsigned char dwPlayerGUID3;
    unsigned char dwCorpseGUID;
    unsigned char dwCorpseGUID1;
    unsigned char dwCorpseGUID2;
    unsigned char dwCorpseGUID3;
};

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern int gnVirtualPlayerCount_6FD4DC1C; // 0x00883D70

void __fastcall sub_0056DEB0(int a1, int a2, int a3, int a4); // 0x0056DEB0

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

void __fastcall SUNITMSG_SendRemoveObject(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600

unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0

void __fastcall D2GAME_PACKETS_SendPacket0x03_6FC3C810(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId); // 0x0053B390

void __stdcall UNITROOM_ClearUpdateQueue(D2ActiveRoomStrc* pRoom); // 0x0064C160

void __fastcall ARENA_ClearUpdateFlag(D2GameStrc* pGame); // 0x0053FAE0

void __fastcall SCMD_SendPlayerRelationshipCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DDF0

void __fastcall SCMD_SendCorpseAssignCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DF50

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __fastcall PLRMSG_InteractWithUnit(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00

void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID); // 0x00578460

void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId); // 0x00579C00

void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit); // 0x005350B0

void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId); // 0x005724C0

void __fastcall PLRMSG_SendWalkMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);

#define CLIENTS_MAX_UPDATES 55u

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

#pragma pack(push, 1)

struct D2SavePartPacketStrc
{
    unsigned char nHeader;
    unsigned char nPartDataSize;
    unsigned char bFirstPart;
    int nSaveHeaderSize;
    unsigned char aData[0x100];
};

#pragma pack(pop)

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258

unsigned long dword_6FD45848;                                                                               // 0x00883D5C

int __cdecl sub_0052B910();                                                                                 // 0x0052B910

void __fastcall GAME_CloseGame(int nGameGUID);                                                              // 0x0052E770

void __fastcall CLIENTS_RefreshUnitsUpdateList(D2ClientStrc* pClient, unsigned int nUpdateSize);            // 0x00537FD0

void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* pClient);                                              // 0x00538F10

int __fastcall CLIENTS_HasLoadedSave(D2ClientStrc* pClient);                                        // 0x00538FC0

void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);         // 0x00539270

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_PopHead(D2ClientStrc* pClient);                         // 0x005392A0

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc* pClient);                         // 0x005392E0

void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* pGame, D2ClientStrc* pClient);                   // 0x00530590

void __fastcall SCMD_SendUnitUpdates(D2ClientStrc* pClient);                           // 0x0053E130

int __fastcall PLRMSG_SendPlayerStatUpdates(D2UnitStrc* pUnit, D2UnitStrc* pUnit2, int bSkipHpCheck);                       // 0x00548760

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

void __stdcall TASK_FreeAllQueueSlots();                                                                    // 0x00564890

int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);    // 0x005B4A80

D2UnitStrc* __fastcall ACT4Q2_TrySpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx); // 0x005B4B60

void __fastcall D2GAME_PACKETS_SendPacket0x0A_RemoveObject(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0

extern "C" const char gszSGameDataTypeName[];                                                               // 0x0070F56C

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

void __cdecl sub_00409DD0_InitPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize);

void __stdcall GAME_SetReservedGameGUID(int hGame, unsigned short nGameId);                            // 0x0052C110

unsigned short __cdecl sub_0052C170_AllocGameId();

void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int a3);                    // 0x0052F940

void __fastcall sub_00536070_InitNpcControl(D2GameStrc* pGame);

void __fastcall CLIENTS_SetGameData(D2ClientStrc* pClient);                                            // 0x005379A0

void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int a2, unsigned int nFlags, unsigned char a4);         // 0x0053F4B0

void __fastcall PARTY_AllocPartyControl(D2GameStrc* pGame);                                                 // 0x0053FF90

void __fastcall EVENT_AllocEventQueue(D2GameStrc* pGame);                                            // 0x00541470

void __fastcall sub_00545D80_QuestInit(D2GameStrc* pGame);

int __fastcall sub_00546C60_AllocObjectControl(D2GameStrc* pGame);

void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame);                                         // 0x00547D20

void __fastcall sub_00564A00_QueueGame(void* pTask, int a2, unsigned int hGame);

void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct);                                // 0x005382E0

void __fastcall CLIENTS_SetGameOwner(D2ClientStrc* pClient);                                       // 0x00539000

void __fastcall LEVEL_LoadAct(D2GameStrc* pGame, unsigned char nAct);                              // 0x0053AFB0

void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient);                            // 0x0053ABE0

static inline D2GameLinkStrc* GAMELINK_NextLink(D2GameLinkStrc* pLink, int nLinkOffset)
{
    if ((int)pLink->pNext < 0)
        return (D2GameLinkStrc*)~(unsigned int)pLink->pNext;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)pLink - (char*)pLink->pPrevLink->pNext;
    return (D2GameLinkStrc*)((char*)pLink->pNext + nLinkOffset);
}

static inline void GAMELINK_Unlink(D2GameLinkStrc* pLink)
{
    if (pLink->pPrevLink)
    {
        GAMELINK_NextLink(pLink, -1)->pPrevLink = pLink->pPrevLink;
        pLink->pPrevLink->pNext = pLink->pNext;
        pLink->pPrevLink = 0;
        pLink->pNext = 0;
    }
}

// 0x00538E60
void __fastcall CLIENTS_CopySaveDataToClient(D2ClientStrc* ptClient, const void* pData, unsigned int nSize)
{
    D2_ASSERT(ptClient, 2921);

    if (ptClient->nSaveHeaderSize != nSize || ptClient->pSaveHeader)
    {
        if (ptClient->pSaveHeader)
        {
            FOG_FreeServerMemory(ptClient->pGame->pMemoryPool, ptClient->pSaveHeader, ".\\GAME\\Clients.cpp", 2926, 0);
        }

        ptClient->pSaveHeader = (D2SaveHeaderStrc*)sub_0040B430(ptClient->pGame->pMemoryPool, nSize, ".\\GAME\\Clients.cpp", 2928, 0);
        ptClient->nSaveHeaderSize = nSize;
    }

    memcpy(ptClient->pSaveHeader, pData, nSize);
}
