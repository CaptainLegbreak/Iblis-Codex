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

void __stdcall sub_0052E8E0(void* pArg); // 0x0052E8E0

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

int __fastcall sub_6FC33EA0(int nClientId, char* szName); // 0x00538B70

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId); // 0x0052C060

int __fastcall sub_6FC33F90(const char* szName, char* szGameName); // 0x00538C60

int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize); // 0x0053EFC0

D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830;                                                 // 0x00883D50

void __fastcall sub_0053B220_SendHeaderOnly0xB0(int nClientId); // 0x0053B220

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

int __fastcall sub_0052F8B0_IsGameNameUnused(const char* szGameName); // 0x0052F8B0

D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId); // 0x00537810

int __fastcall sub_005381C0(D2GameStrc* pGame, int nClientId); // 0x005381C0

int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient); // 0x00538590

int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient); // 0x005385F0

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830

void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer); // 0x005392F0

void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave); // 0x00539DA0

void __fastcall sub_0053B1B0_SendGameInfo(void* pClientId, unsigned short nGameId, int nClients, const char* szGameName); // 0x0053B1B0

void __fastcall sub_0053C5D0(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053C5D0

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

int __stdcall sub_0052B5C0_SetServerHandler(D2NET_Unk_Callback pfCallback); // 0x0052B5C0

int __stdcall sub_005300F0_RemoveClientById(int nClientId, int a2, int a3); // 0x005300F0

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

void __fastcall sub_0052CBB0_FindOwnerClient(D2ClientStrc* client, void* context); // 0x0052CBB0

void __fastcall sub_0052CBD0_FindFirstClient(D2ClientStrc* client, void* context); // 0x0052CBD0

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

static int sub_0052DBC0_CountUnitsInLists(D2UnitStrc** pUnitLists);

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

int __stdcall sub_0052B4F0(int nClientId, int a2, int a3);                                                  // 0x0052B4F0

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

void __fastcall sub_6FC33910(D2ClientStrc* pClient);                                                        // 0x00538320

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

int __stdcall sub_0052B2D0_ObjectCallMode1(unsigned char* pBuffer, int nSize);                              // 0x0052B2D0

int __stdcall sub_0052B2F0_ObjectCallMode0(unsigned char* pBuffer, int nSize);                              // 0x0052B2F0

int __stdcall sub_0052B310_ObjectCallMode2(unsigned char* pBuffer, int nSize);                              // 0x0052B310

void __fastcall sub_0052CC20_Statistics(void* pData, int nSize);                                                       // 0x0052CC20

void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType);            // 0x0052CAF0

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag);                              // 0x00538670

void __fastcall CCMD_ProcessClientSystemMessage(void* pData, int nSize);                                    // 0x0053F100

void __fastcall ProcessClientMessage(void* pData, int nPacketSize);                                    // 0x0053F3D0

void __fastcall sub_6FC84CD0(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A9B0

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __fastcall sub_0052C210_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient);                      // 0x0052C210

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

void __fastcall sub_0052CA10(D2GameStrc* pGame); // 0x0052CA10

void __stdcall sub_0052D240(D2GameStrc* pGame); // 0x0052D240

void __stdcall sub_0052D350_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected); // 0x0052D350

void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame); // 0x0052D7B0

void __fastcall sub_6FC33670(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x005380D0

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

#include "gen/data/Source/D2Game/GAME/Game_0052D720.static/gnFrameRate_00731010.inc"

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                              // 0x0040B380

int __cdecl sub_0040A040_GetPoolSystemCount(D2PoolSystemStrc* pSystem);                                     // 0x0040A040

void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);            // 0x00542B40

void __fastcall sub_6FC84D40(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket);                                 // 0x0054AA40

void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                  // 0x0054EC90

void __fastcall sub_0055DF00_RecalcItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int bRefresh); // 0x0055DF00

D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                   // 0x0061A180

int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom);                                                      // 0x0061A4D0

void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet);                                           // 0x0061A510

static void sub_0052D160_UpdatePendingRooms(D2GameStrc* pGame);

static void sub_0052D310_DeleteInactiveItems(D2GameStrc* pGame);

static void sub_0052D440_UpdateAllClients(D2GameStrc* pGame);

static void sub_0052D720_UpdateFrameRate(D2GameStrc* pGame);

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

struct D2PartyStrc
{
    short nPartyId;
    short field_2;
    D2PartyNodeStrc* pPartyNodes;
    D2PartyStrc* pNext;
};

struct D2PartyControlStrc
{
    short field_0;
    short field_2;
    D2PartyStrc* pParties;
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

void __fastcall sub_6FC817D0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600

unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0

void __fastcall D2GAME_PACKETS_SendPacket0x03_6FC3C810(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId); // 0x0053B390

void __stdcall UNITROOM_ClearUpdateQueue(D2ActiveRoomStrc* pRoom); // 0x0064C160

void __fastcall sub_0053FAE0(D2GameStrc* pGame); // 0x0053FAE0

void __fastcall sub_0053DDF0(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DDF0

void __fastcall sub_0053DF50(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DF50

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __fastcall sub_6FC828D0(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00

void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID); // 0x00578460

void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId); // 0x00579C00

void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit); // 0x005350B0

void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId); // 0x005724C0

void __fastcall sub_6FC81E10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);


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

int __fastcall sub_00538FC0(D2ClientStrc* pClient);                                        // 0x00538FC0

void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);         // 0x00539270

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_PopHead(D2ClientStrc* pClient);                         // 0x005392A0

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc* pClient);                         // 0x005392E0

void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* pGame, D2ClientStrc* pClient);                   // 0x00530590

void __fastcall sub_0053E130_SendUnitUpdates(D2ClientStrc* pClient);                           // 0x0053E130

int __fastcall sub_6FC82360(D2UnitStrc* pUnit, D2UnitStrc* pUnit2, int bSkipHpCheck);                       // 0x00548760

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

void __stdcall TASK_FreeAllQueueSlots();                                                                    // 0x00564890

int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);    // 0x005B4A80

D2UnitStrc* __fastcall sub_005B4B60_SpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx); // 0x005B4B60

void __fastcall sub_0053BDA0_SendUnitRemoval(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0

extern "C" const char gszSGameDataTypeName[];                                                               // 0x0070F56C

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

void __cdecl sub_00409DD0_InitPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize);

void __stdcall sub_0052C110(int hGame, unsigned short nGameId);                            // 0x0052C110

unsigned short __cdecl sub_0052C170_AllocGameId();

void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int a3);                    // 0x0052F940

void __fastcall sub_00536070_InitNpcControl(D2GameStrc* pGame);

void __fastcall sub_005379A0_ResetClient(D2ClientStrc* pClient);                                            // 0x005379A0

void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int a2, unsigned int nFlags, unsigned char a4);         // 0x0053F4B0

void __fastcall PARTY_AllocPartyControl(D2GameStrc* pGame);                                                 // 0x0053FF90

void __fastcall sub_00541470_InitializeQueue(D2GameStrc* pGame);                                            // 0x00541470

void __fastcall sub_00545D80_QuestInit(D2GameStrc* pGame);

int __fastcall sub_00546C60_AllocObjectControl(D2GameStrc* pGame);

void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame);                                         // 0x00547D20

void __fastcall sub_00564A00_QueueGame(void* pTask, int a2, unsigned int hGame);

void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct);                                // 0x005382E0

void __fastcall sub_00539000(D2ClientStrc* pClient);                                       // 0x00539000

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

// 0x00520650
void* __cdecl sub_00520650()
{
    return gData_00882028;
}

// 0x00520AE0
int __cdecl sub_00520AE0()
{
    return gdwGlobal_00882528;
}

// 0x00520AF0
int __cdecl sub_00520AF0()
{
    return gdwGlobal_0072FFA8;
}

// 0x00520B00
void* __cdecl sub_00520B00()
{
    return gData_00882428;
}

// 0x00520B10
int __cdecl sub_00520B10()
{
    return gdwGlobal_008822A4;
}

// 0x00520B20
int __cdecl sub_00520B20()
{
    return gdwGlobal_008822A0;
}

// 0x00520C40
int __cdecl sub_00520C40()
{
    return 1;
}

// 0x005210E0
int __cdecl sub_005210E0()
{
    return 1;
}

// 0x005224E0
int __cdecl sub_005224E0()
{
    return gdwGlobal_00882538;
}

// 0x00523A00
int __cdecl sub_00523A00()
{
    return gdwGlobal_00730190;
}

// 0x00523AA0
int __cdecl sub_00523AA0()
{
    return gdwGlobal_00882750;
}

// 0x0052A600
int __fastcall sub_0052A600(void* pArg)
{
    return sub_00424E40(pArg);
}

// 0x0052BDC0
int __cdecl sub_0052BDC0()
{
    return gdwGlobal_00882D14;
}

// 0x0052BE20
void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...)
{
}

// 0x0052BE30
void __stdcall sub_0052BE30(int nUnused1, int nUnused2)
{
}

// 0x0052BE50
void __stdcall sub_0052BE50(int nUnused1, int nUnused2)
{
}

// 0x0052BEA0
void __stdcall sub_0052BEA0(int nUnused1)
{
}

// 0x0052BEB0
void __stdcall sub_0052BEB0(int nUnused1)
{
}

// 0x0052BEC0
void __stdcall sub_0052BEC0(int nUnused1, int nUnused2)
{
}

// 0x0052BEE0
void __stdcall sub_0052BEE0(int nUnused1, int nUnused2)
{
}

// 0x0052BF00
int __cdecl sub_0052BF00()
{
    return 0;
}

// 0x0052BF10
void __stdcall sub_0052BF10(int nUnused1)
{
}

// 0x0052BF20
void* __cdecl sub_0052BF20()
{
    return gData_006E0498;
}

// 0x0052BF30
void __stdcall sub_0052BF30(int nUnused1, int nUnused2)
{
}

// 0x0052BF50
int __cdecl sub_0052BF50()
{
    return 0;
}

// 0x0052BF60
int __cdecl sub_0052BF60()
{
    return 0;
}

// 0x0052BF70
int __cdecl sub_0052BF70()
{
    return 0;
}

// 0x0052BF90
void* __cdecl sub_0052BF90()
{
    return gData_006E0550;
}

// 0x0052BFA0
void* __cdecl sub_0052BFA0()
{
    return gData_006E0568;
}

// 0x0052C060
int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);
    return nGUID;
}

// 0x0052C0A0
void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList)
{
    D2_ASSERT(pGameDataTbl, 347);

    gpGameDataTbl_6FD45818 = pGameDataTbl;

    D2_ASSERT(pGameList, 349);
}

// 0x0052C0E0
void __stdcall GAME_SetServerCallbackFunctions(D2ServerCallbackFunctions* pD2ServerCallbackFunctions)
{
    if (pD2ServerCallbackFunctions)
    {
        gpD2EventCallbackTable_6FD45830 = pD2ServerCallbackFunctions;
        gbD2ServerCallbackFunctionsInitialized_6FD45834 = 1;
    }
    else
    {
        gpD2EventCallbackTable_6FD45830 = 0;
        gbD2ServerCallbackFunctionsInitialized_6FD45834 = 0;
    }
}

// 0x0052C110
void __stdcall sub_0052C110(int nGameGUID, unsigned short nGameId)
{
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] == D2GameReservedSlotHandle)
    {
        gnGamesGUIDs_6FD447F8[nGameId - 1] = nGameGUID;
        LeaveCriticalSection(&gCriticalSection_6FD45800);
        return;
    }

    D2_ASSERT(0, 394);
}

// 0x0052C260
static __declspec(noinline) void sub_0052C260_SendGameInit(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(pClient, 1, pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0);
    CLIENTS_SetClientState(pClient, 1);
}

// 0x0052C320
void __stdcall GAME_SetInitSeed(int nInitSeed)
{
    gnInitSeed_00731004 = nInitSeed;
}

// 0x0052C330
int __fastcall SrvVerifyCreateNewGame(int nClientId, D2GSPacketClt66* pPacket)
{
    const char* szGameName = pPacket->szGameName;
    const unsigned char nPlayerClass = pPacket->nPlayerClass;
    const char* szClientName = pPacket->szClientName;
    const unsigned int nGameFlags = *(const unsigned int*)pPacket->abGameFlags;
    char szCurrentGame[16];

    if (gpD2EventCallbackTable_6FD45830 && pPacket->nGameType)
    {
        return 0;
    }
    if (!CCMD_IsStringZeroTerminated(szClientName, 16))
    {
        return 0;
    }
    if (pPacket->nLocale > 14u)
    {
        return 0;
    }
    if (!CCMD_IsStringZeroTerminated(szGameName, 16))
    {
        return 0;
    }
    if (!(nGameFlags & 6))
    {
        return 0;
    }
    if (!sub_6FC33EA0(nClientId, szCurrentGame))
    {
        return 0;
    }
    if (!sub_6FC33F90(szClientName, szCurrentGame))
    {
        return 0;
    }
    return nPlayerClass < 7u;
}

// 0x0052C3E0
void __stdcall D2Game_10056(int a1)
{
    dword_6FD4581C = a1;
    dword_6FD45820 = 0;
}

// 0x0052C400
void __fastcall sub_0052C400_UpdatePing(int nClientId, int a2, int a3, int a4)
{
    CLIENTS_UpdatePing(nClientId, a2, a3, a4);
}

// 0x0052C410
void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2UnitStrc* hNewUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!hNewUnit)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x5A1);
        exit(-1);
    }
    for (D2ClientStrc* pOtherClient = pGame->pClientList; pOtherClient; pOtherClient = pOtherClient->pNext)
    {
        if (pOtherClient != pClient)
        {
            D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(pOtherClient, 0);
            if (pOtherPlayer)
            {
                SCMD_SendPlayerJoinAndPets(pClient, pOtherPlayer, pOtherClient);
                SCMD_SendPlayerJoinAndPets(pOtherClient, hNewUnit, pClient);
                if (pOtherPlayer->pInventory)
                {
                    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pOtherPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
                    {
                        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
                        if (nCorpseGUID != -1)
                            D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(pClient, sub_00451F50_GetUnitGUID(pOtherPlayer), nCorpseGUID, 1);
                    }
                }
            }
        }
    }
    SCMD_SendPlayerJoinAndPets(pClient, hNewUnit, pClient);
    ARENA_SendScoresToClient(pGame, pClient);
}

// 0x0052C500
void __fastcall GAME_SendPacket0x5CToAllConnectedClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
        {
            if (pClient->dwClientState == CLIENTSTATE_INGAME)
            {
                D2GAME_PACKETS_SendPacket0x5C_6FC3E090(pClient, sub_00451F50_GetUnitGUID(pPlayer));
            }
        }
    }
}

// 0x0052C550
int __fastcall GAME_VerifyJoinAct(int nClientId)
{
    return CLIENTS_CheckState(nClientId, 1) != 0;
}

// 0x0052C570
int __fastcall sub_0052C570_RemoveClientFromGame(D2GameStrc* pGame, int nClientId, int a3, int a4)
{
    if (pGame && sub_005381C0(pGame, nClientId))
    {
        ClientRemoveFromGame(pGame, nClientId, 1);
    }

    return sub_0052B4F0(nClientId, a3, a4);
}

// 0x0052C5B0
static int IsClientNameValid(const char* szClientName, int nLength)
{
    int bContainsSpecialCharacter = 0;
    for (int i = 0; i < nLength; ++i)
    {
        switch (*szClientName++)
        {
        case '\'':
        case '-':
        case '_':
            if (bContainsSpecialCharacter || i == 0 || *szClientName == '\0')
            {
                return 0;
            }
            bContainsSpecialCharacter = 1;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I':
        case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
        case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i':
        case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
        case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            break;
        case '\0':
            return i != 0;
        default:
            return 0;
        }
    }
    return 0;
}

// 0x0052C690
int __fastcall SrvVerifyJoinGame(int nClientId, unsigned short nGameId, unsigned char nPlayerClass, const char* szClientName, int nTokenId, char* pszInOutAccountName, int* pOutCharSaveTransactionToken, unsigned char nLocale, int* a9, int* a10, int* a11, int* a12, int a13)
{
    if (!CCMD_IsStringZeroTerminated(szClientName, 16))
    {
        return 0;
    }
    if (nLocale >= 14)
    {
        return 0;
    }
    char szGameName[16];
    if (!sub_6FC33EA0(nClientId, szGameName))
    {
        return 0;
    }
    if (!sub_6FC33F90(szClientName, szGameName))
    {
        return 0;
    }
    if (!GAME_GetGameGUIDFromGameId(nGameId))
    {
        return 0;
    }
    if (nPlayerClass >= 7)
    {
        return 0;
    }
    if (!IsClientNameValid(szClientName, 16))
    {
        return 0;
    }
    if (gpD2EventCallbackTable_6FD45830)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfFindPlayerToken), 1883);
        if (!gpD2EventCallbackTable_6FD45830->pfFindPlayerToken(szClientName, nTokenId, nGameId, pszInOutAccountName, pOutCharSaveTransactionToken, a9, a10, a11, a12))
        {
            return 0;
        }
    }
    return 1;
}

// 0x0052C7C0
static inline void sub_0052C7C0_RemoveGameGUID(int nGameGUID)
{
    EnterCriticalSection(&gCriticalSection_6FD45800);
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] == nGameGUID)
        {
            gnGamesGUIDs_6FD447F8[i] = 0;
        }
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);
}

// 0x0052C7F0
void __fastcall SrvFreeGame(int nGameGUID, D2GameStrc* pGame)
{
    EnterCriticalSection(&gCriticalSection_6FD45800);

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] == nGameGUID)
        {
            gnGamesGUIDs_6FD447F8[i] = 0;
        }
    }

    LeaveCriticalSection(&gCriticalSection_6FD45800);

    MONSTERREGION_FreeAll(pGame->pMemoryPool, pGame->pMonReg);
    OBJRGN_FreeObjectControl(pGame);
    QUESTS_QuestFree(pGame);
    SUNITPROXY_FreeNpcControl(pGame);
    CLIENTS_FreeClientsFromGame(pGame);
    LEVEL_RemoveAllUnits(pGame);
    SUNITINACTIVE_FreeInactiveUnitLists(pGame);
    EVENT_FreeEventQueue(pGame);
    PARTY_FreePartyControl(pGame);
    ARENA_FreeArena(pGame);

    for (int i = 0; i < NUM_ACTS; ++i)
    {
        if (pGame->pAct[i])
        {
            DUNGEON_FreeAct(pGame->pAct[i]);
            pGame->pAct[i] = 0;
        }
    }

    if (pGame->pMemoryPool)
    {
        FOG_DestroyMemoryPoolSystem((D2PoolSystemStrc*)pGame->pMemoryPool);
    }

    D2CriticalSectionStrc* pCriticalSection = pGame->lpCriticalSection;
    pGame->lpCriticalSection = 0;
    LeaveCriticalSection(pCriticalSection);
    DeleteCriticalSection(pCriticalSection);
    FOG_FreePool(0, pCriticalSection, ".\\GAME\\Game.cpp", 0x8DA, 0);
}

// 0x0052C8E0
int __fastcall GAME_VerifyEndGame(int nClientId)
{
    return CLIENTS_CheckState(nClientId, 4) != 0;
}

// 0x0052C900
void __fastcall sub_0052C900_SaveClientAndGamePlayers(D2ClientStrc* pClient, D2GameStrc* pGame)
{
    if (!pClient)
        return;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer || !D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(pClient), 1))
        return;
    D2ClientStrc* volatile pNext; // volatile only keeps pNext in its stack slot across the loop body, as the original does
    D2ClientStrc* i = pGame->pClientList;
    for (; i; i = pNext)
    {
        pNext = i->pNext;
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (pPlayer)
        {
            if (i != pClient)
                D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(i), 0);
            if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder && pGame->dwGameType)
            {
                unsigned char nBackgroundColor, nForegroundColor, nEmblemType;
                CLIENTS_GetGuildEmblem(i, &nBackgroundColor, &nForegroundColor, &nEmblemType);
                const int nClassId = pPlayer->dwClassId;
                gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder(CLIENTS_GetName(i), nClassId, STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0), (unsigned int)STATLIST_GetUnitBaseStat(pPlayer, STAT_EXPERIENCE, 0), CLIENTS_GetFlags(i), &i->nSaveCreationTimestamp);
            }
        }
    }
}

// 0x0052CA10
void __fastcall sub_0052CA10(D2GameStrc* pGame)
{
    D2ClientStrc* i = pGame->pClientList;
    while (i)
    {
        D2ClientStrc* pNext = i->pNext;
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (pPlayer)
        {
            D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(i), 0);
            if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder && pGame->dwGameType)
            {
                unsigned char nBackgroundColor, nForegroundColor, nEmblemType;
                CLIENTS_GetGuildEmblem(i, &nBackgroundColor, &nForegroundColor, &nEmblemType);
                const int nClassId = pPlayer->dwClassId;
                gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder(CLIENTS_GetName(i), nClassId, STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0), (unsigned int)STATLIST_GetUnitBaseStat(pPlayer, STAT_EXPERIENCE, 0), CLIENTS_GetFlags(i), &i->nSaveCreationTimestamp);
            }
        }
        i = pNext;
    }
}

// 0x0052CAF0
void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType)
{
    if (!pClient)
        return;

    const int nClientId = CLIENTS_GetClientId(pClient);

    D2GSPacketSrv5A tPacket = {};
    tPacket.nHeader = 0x5A;
    tPacket.nType = nEventType;
    tPacket.nColor = 4;
    *(int*)tPacket.abParam = 0;
    CLIENTS_CopyAccountNameToBuffer(pClient, &tPacket.szText[16]);
    tPacket.szText[31] = '\0';
    SStrCopy(tPacket.szText, CLIENTS_GetName(pClient), 16);
    sub_6FC84D40(pGame, &tPacket);

    ClientRemoveFromGame(pGame, CLIENTS_GetClientId(pClient), 1);
    sub_0053B220_SendHeaderOnly0xB0(nClientId);
    D2NET_10016(nClientId);
}

// 0x0052CBB0
void __fastcall sub_0052CBB0_FindOwnerClient(D2ClientStrc* pClient, void* pContext)
{
    D2ClientStrc** ppClient = (D2ClientStrc**)pContext;
    if (CLIENT_IsGameOwner(pClient))
    {
        *ppClient = pClient;
    }
}

// 0x0052CBD0
void __fastcall sub_0052CBD0_FindFirstClient(D2ClientStrc* pClient, void* pContext)
{
    D2ClientStrc** ppClient = (D2ClientStrc**)pContext;
    if (!*ppClient)
    {
        *ppClient = pClient;
    }
}

// 0x0052CBE0
int __fastcall GAME_VerifyDisconnect(int nClientId)
{
    char szClientName[16];
    return sub_6FC33EA0(nClientId, szClientName) != 0;
}

void __fastcall sub_M117_Emit_0052C7C0(int nGameGUID)
{
    sub_0052C7C0_RemoveGameGUID(nGameGUID + 1);
}

// 0x0052CC10
void __fastcall sub_0052CC10_SendHeaderAndRelease(int nClientId)
{
    sub_0053B220_SendHeaderOnly0xB0(nClientId);
    D2NET_10016(nClientId);
}

// 0x0052CC20
void __fastcall sub_0052CC20_Statistics(void* pData,int nSize) {
 if (!gpD2EventCallbackTable_6FD45830) return;
 Request* request=(Request*)pData;
 int client=request->client;
 ShortResponse response;
 char received[16];
 switch(request->command) {
 case 0xFA:
  sub_0052B490_ObjectCall_6BED90(client,(int)received,16);
  InterlockedIncrement(&gnCounter_00883D64);
  response.command=REPLY_FA;
  sub_0052B330(2,client,&response,16);
  break;
 case 0xFB:
  sub_0052B490_ObjectCall_6BED90(client,(int)received,16);
  response.command=REPLY_FB;
  sub_0052B330(2,client,&response,16);
  D2NET_10016(client);
  InterlockedDecrement(&gnCounter_00883D64);
  break;
 case 0xFC:
  sub_0052B490_ObjectCall_6BED90(client,(int)received,16);
  response.command=REPLY_FC;
  sub_0052B330(2,client,&response,16);
  break;
 case 1:
 case 0xFD:
  if(gpD2EventCallbackTable_6FD45830->unk0x30 && gpD2EventCallbackTable_6FD45830->pfServerLogMessage) {
   ServerInfo info;
   Reply reply;
   ((void (__fastcall*)(ServerInfo*))gpD2EventCallbackTable_6FD45830->unk0x30)(&info);
   reply.command=request->command;
   reply.a=info.a;reply.b=info.b;reply.c=info.c;reply.d=info.d;reply.e=info.e;
   reply.f=info.f;reply.g=info.g;reply.h=info.h;reply.i=info.i;reply.j=info.j;
   SStrCopy(reply.description,info.description,128);
   reply.a9=info.a8;
   reply.f10b=info.ac;
   reply.f10f=info.b0;
   reply.f113=info.b8-gnCounter_00883D64;
   reply.f117=info.bc;
   reply.ad=reply.f10b+reply.f10f;
   reply.b1=info.b4;
   reply.b5=reply.f113+reply.f117;
   reply.b9=info.c0;
   reply.bd=info.ec;
   reply.c1=info.f0;
   reply.e1=info.f110;
   reply.e5=info.c4;reply.e9=info.c8;reply.ed=info.cc;reply.f1=info.d0;
   reply.f5=info.d4;reply.f7=info.d6;reply.fb=info.da;reply.ff=info.de;
   reply.f103=info.e2;reply.f107=info.e6;
   memset(reply.reserved,0,0x4A);
   int packetSize;
   switch(reply.command) {
   case 1: packetSize=0x165; break;
   default: packetSize=0xBD; break;
   }
   sub_0052B330(2,client,&reply,packetSize);
  }
  break;
 }
}

// 0x0052CFE0
void __fastcall GAME_ProcessNetworkMessages()
{
    unsigned char buffer[512];
    int nSize;

    do
    {
        nSize = sub_0052B2F0_ObjectCallMode0(buffer, 512);
        if (nSize != -1)
        {
            CCMD_ProcessClientSystemMessage(buffer, nSize);
        }
    } while (nSize != -1);

    do
    {
        nSize = sub_0052B2D0_ObjectCallMode1(buffer, 512);
        if (nSize != -1)
        {
            ProcessClientMessage(buffer, nSize);
        }
    } while (nSize != -1);

    do
    {
        nSize = sub_0052B310_ObjectCallMode2(buffer, 512);
        if (nSize != -1)
        {
            sub_0052CC20_Statistics(buffer, nSize);
        }
    } while (nSize != -1);
}

// 0x0052D090
static inline void sub_0052D090_CompressRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc* pNextUnit = 0;
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNextUnit)
    {
        pNextUnit = pUnit->ptRoomNext;
        SUNITINACTIVE_CompressUnitIfNeeded(pGame, pUnit);
    }
}

// 0x0052D0C0
static inline void GAME_PopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
    OBJECTS_PopulationHandler(pGame, pRoom);
    D2GAME_PopulateRoom_6FC67190(pGame, pRoom);
}

// 0x0052D0F0
void __fastcall GAME_ActivateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    MONSTERREGION_TrySpawnWanderingMonster(pGame, pRoom);

    if (!(pRoom->dwFlags & 1))
    {
        SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
        SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
        OBJECTS_PopulationHandler(pGame, pRoom);
        D2GAME_PopulateRoom_6FC67190(pGame, pRoom);
        pRoom->dwFlags |= 1;
        D2Common_10075(pRoom, 1);
    }
    else
    {
        if (!D2Common_10074(pRoom))
        {
            SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
            D2Common_10075(pRoom, 1);
        }
    }
}

// 0x0052D2E0
static inline void sub_0052D2E0_RefreshActs(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i])
        {
            DUNGEON_UpdateAndFreeInactiveRooms(pGame->pAct[i]);
        }
    }
}

void __fastcall sub_M118_Emit_0052D000(D2GameStrc* pGame, int nAct)
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]); pRoom; pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct + 1]))
    {
        if (D2Common_10074(pRoom))
        {
            GAME_PopulateRoom(pGame, pRoom);
        }
        else
        {
            sub_0052D090_CompressRoomUnits(pGame, pRoom);
        }
    }
    sub_0052D2E0_RefreshActs(pGame);
}

// 0x0052D160
static void sub_0052D160_UpdatePendingRooms(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0xC60);

    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i] && pGame->pAct[i]->bHasPendingRoomsUpdates)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[i]); pRoom; pRoom = pRoom->pRoomNext)
            {
                MONSTERREGION_TrySpawnWanderingMonster(pGame, pRoom);

                if (!(pRoom->dwFlags & 1))
                {
                    SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
                    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
                    OBJECTS_PopulationHandler(pGame, pRoom);
                    D2GAME_PopulateRoom_6FC67190(pGame, pRoom);
                    pRoom->dwFlags |= 1;
                    D2Common_10075(pRoom, 1);
                }
                else if (!D2Common_10074(pRoom))
                {
                    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
                    D2Common_10075(pRoom, 1);
                }
            }

            pGame->pAct[i]->bHasPendingRoomsUpdates = 0;
        }
    }
}

// 0x0052D240
void __stdcall sub_0052D240(D2GameStrc* pGame)
{
    for (int i = 0; i < NUM_ACTS; ++i)
    {
        if (pGame->pAct[i])
        {
            D2ActiveRoomStrc* pNextRoom = 0;
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[i]); pRoom; pRoom = pNextRoom)
            {
                pNextRoom = pRoom->pRoomNext;
                if (D2Common_10081_GetTileCountFromRoom(pRoom) > 10 && DUNGEON_TestRoomCanUnTile(pGame->pAct[i], pRoom))
                {
                    D2UnitStrc* pNextUnit = 0;
                    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNextUnit)
                    {
                        pNextUnit = pUnit->ptRoomNext;
                        SUNITINACTIVE_CompressUnitIfNeeded(pGame, pUnit);
                    }

                    DUNGEON_RemoveRoomFromAct(pGame->pAct[i], pRoom);
                }
            }
        }
    }
}

// 0x0052D310
static __declspec(noinline) void sub_0052D310_DeleteInactiveItems(D2GameStrc* pGame)
{
    if (!(pGame->dwGameFrame % 1500))
    {
        for (int i = 0; i < 5; ++i)
        {
            ITEMS_DeleteInactiveItems(pGame, i);
            SUNITINACTIVE_DeleteExpiredItemNodes(pGame, i);
        }
    }
}

// 0x0052D350
void __stdcall sub_0052D350_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected)
{
    if (!gbCheckHeartbeat_00730FFC)
    {
        return;
    }

    *pbDisconnected = 0;
    const unsigned int nTickCount = GetTickCount();
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNext = pClient->pNext;
        const int bHardcore = CLIENTS_CheckFlag(pClient, 4);
        if (nTickCount > pClient->dwLastPacketTick && (bHardcore && nTickCount - pClient->dwLastPacketTick > 10000 && pClient->dwPingsCount > 10 || nTickCount - pClient->dwLastPacketTick > 45000 || pClient->dw504) && gpD2EventCallbackTable_6FD45830)
        {
            D2GAME_SAVE_WriteFile_6FC8A500(pGame, CLIENTS_GetPlayerFromClient(pClient, 0), CLIENTS_GetName(pClient), 0);
            *pbDisconnected = 1;
            SrvDisconnectClient(pGame, pClient, 0);
        }
        pClient = pNext;
    }

    if (*pbDisconnected)
    {
        sub_0052CA10(pGame);
    }
}

// 0x0052D440
static void sub_0052D440_UpdateAllClients(D2GameStrc* pGame)
{
    {
        int bUpdateLadder = 0;
        int bPlayerDisconnected = 0;

        if (!(pGame->dwGameFrame % 8192))
        {
            bUpdateLadder = 1;
        }

        D2_ASSERT(ARENA_NeedsClientUpdate(pGame), 0xD31);

        sub_0052D350_CheckClientHeartbeats(pGame, &bPlayerDisconnected);

        if (bUpdateLadder && !bPlayerDisconnected)
        {
            sub_0052CA10(pGame);
        }
    }

    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNext = pClient->pNext;

        switch (pClient->dwClientState)
        {
        case 3:
        {
            sub_6FC33670(pGame, pClient);

            if (D2Common_10073(pClient->hRoom) && CLIENTS_GetPlayerFromClient(pClient, 0))
            {
                GAME_LogMessage(6, "[JOIN 6] %d clientid, sUpdateClients: SCMD_STARTACT - Player(%s)", pClient->dwClientId, pClient->szName);
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pPlayer, 0, 1);
                }

                GAME_SynchronizePlayerWithClients(pGame, pClient);
                PLAYERLIST_InitializePlayerRelations(pGame, CLIENTS_GetPlayerFromClient(pClient, 1));

                if (gpD2EventCallbackTable_6FD45830)
                {
                    pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                    if (pPlayer && gpD2EventCallbackTable_6FD45830->pfEnterGame)
                    {
                        const int nClassId = pPlayer->dwClassId;
                        gpD2EventCallbackTable_6FD45830->pfEnterGame(pGame->nGameId, pClient->szName, nClassId, STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0), pClient->nSaveFlags);
                    }
                }

                D2GSPacketSrv5A packet5A = {};
                packet5A.nHeader = 0x5A;
                packet5A.nType = 2;
                packet5A.nColor = 4;
                *(int*)packet5A.abParam = 0;
                packet5A.szText[16] = '\0';

                char szAccountName[256];
                CLIENTS_CopyAccountNameToBuffer(pClient, szAccountName);
                if (strlen(szAccountName) != 0)
                {
                    SStrCopy(&packet5A.szText[16], szAccountName, 16);
                    packet5A.szText[31] = '\0';
                }

                SStrCopy(packet5A.szText, pClient->szName, 16);
                sub_6FC84D40(pGame, &packet5A);
            }
            break;
        }
        case 4:
        {
            sub_6FC33670(pGame, pClient);
            break;
        }
        case 5:
        {
            sub_6FC33670(pGame, pClient);

            if (D2Common_10073(pClient->hRoom))
            {
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pPlayer, 0, 1);
                }
            }
            break;
        }
        }

        pClient = pNext;
    }
}

// 0x0052D720
static void sub_0052D720_UpdateFrameRate(D2GameStrc* pGame)
{
    const unsigned int nTickCount = GetTickCount();
    const unsigned int nTickDiff = nTickCount - pGame->nPreviousUpdateTickCount;
    if (nTickDiff >= 1000)
    {
        pGame->nFrameRate = 1000 * pGame->nFramesSinceLastFrameRateUpdate / nTickDiff;
        pGame->nFramesSinceLastFrameRateUpdate = 0;
        pGame->nPreviousUpdateTickCount = nTickCount;
        gnFrameRate_00731010 = pGame->nFrameRate;

        const unsigned int nMemoryUsage = sub_0040A040_GetPoolSystemCount((D2PoolSystemStrc*)pGame->pMemoryPool);
        if (nTickCount - gnPreviousMemUsageTick_00883D68 > 10000)
        {
            gnPreviousMemUsageTick_00883D68 = nTickCount;
            gnPeakMemoryUsage_00883D48 = nMemoryUsage;
        }
        else if (nMemoryUsage > gnPeakMemoryUsage_00883D48)
        {
            gnPeakMemoryUsage_00883D48 = nMemoryUsage;
        }
    }

    ++pGame->nFramesSinceLastFrameRateUpdate;
}

// 0x0052D7B0
void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i] && ENVIRONMENT_UpdateCycleIndex(pGame->pAct[i], i))
        {
            int nCycleIndex;
            int nTicks;
            int nEclipse;
            ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(pGame->pAct[i], &nCycleIndex, &nTicks, &nEclipse);
            D2GSPacketSrv53 packet53;
            packet53.nHeader = 0x53;
            *(int*)&packet53.nCycleIndex = nCycleIndex;
            *(int*)&packet53.nTicks = nTicks;
            packet53.nEclipse = nEclipse;
            for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
            {
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_UpdatePlayerItems_6FC4BB90(pGame, pPlayer, 1);
                    if (pClient->dwClientState == 4 && pClient->bAct == i)
                        D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);
                }
            }
        }
    }
}

// 0x0052D870
void __fastcall GAME_UpdateProgress(D2GameStrc* pGame)
{
    const int nDebugBreakTrigger = pGame->nDebugBreakTrigger;
    ++pGame->dwGameFrame;

    if (nDebugBreakTrigger == 1)
    {
        *((unsigned char*)0) = 0;
    }
    else if (nDebugBreakTrigger == 2)
    {
        *((unsigned char*)0xC0000001) = 0;
    }
    else if (nDebugBreakTrigger == 3)
    {
        D2_ASSERT(0, 0xE1C);
    }
    else if (nDebugBreakTrigger == 4)
    {
        FOG_Alloc(0x70000000, ".\\GAME\\Game.cpp", 0xE20, 0);
    }

    GAME_UpdateEnvironment(pGame);
    sub_0052D720_UpdateFrameRate(pGame);
    sub_0052D160_UpdatePendingRooms(pGame);
    EVENT_IterateEvents(pGame);
    sub_0052D440_UpdateAllClients(pGame);
    LEVEL_UpdateQueuedUnitsInAllActs(pGame);
    LEVEL_FreeDrlgDeletes(pGame);

    if (!(pGame->dwGameFrame % 20))
    {
        QUESTS_QuestUpdater(pGame);
    }

    if (!(pGame->dwGameFrame % 12))
    {
        sub_0052D240(pGame);
    }

    if (!(pGame->dwGameFrame % 11))
    {
        for (int i = 0; i < 5; ++i)
        {
            if (pGame->pAct[i])
            {
                DUNGEON_UpdateAndFreeInactiveRooms(pGame->pAct[i]);
            }
        }
    }

    sub_0052D310_DeleteInactiveItems(pGame);
}

// 0x0052D980
static void sub_0052D980_SyncPlayerStats(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetHead(pClient);
    int bSkipHpCheck = 0;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        if (pPacketData && pClient->nPlayerSyncCount >= 10)
        {
            bSkipHpCheck = 1;
        }

        if (pClient->nPlayerSyncCount >= 20)
        {
            bSkipHpCheck = 1;
        }

        D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 0xF05);

        if (sub_6FC82360(pPlayer, pPlayer, bSkipHpCheck))
        {
            pClient->nPlayerSyncCount = 0;
        }
    }
}

// 0x0052DA00
static void sub_0052DA00_RefreshUnitsUpdate(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetHead(pClient);
    if (pPacketData)
    {
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pPlayer && pClient->nPlayerSyncCount >= 10)
        {
            D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 0xF19);

            const int nUpdateSize = (499 - pPacketData->nPacketSize) / 9;
            if (nUpdateSize > 0)
            {
                D2_ASSERT(nUpdateSize <= CLIENTS_MAX_UPDATES, 0xF23);
                CLIENTS_RefreshUnitsUpdateList(pClient, nUpdateSize);
                sub_0053E130_SendUnitUpdates(pClient);
            }
        }
    }
}

// 0x0052DA90
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x1063);
    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
    LeaveCriticalSection(pGame->lpCriticalSection);
}

// 0x0052DAD0
void __cdecl sub_0052DAD0_AssertFail()
{
    D2_ASSERT(0, 0x1165);
}

// 0x0052DAF0
extern "C" __declspec(dllexport) int __cdecl sub_0052DAF0() {
    return 1;
}

// 0x0052DB00
extern "C" __declspec(dllexport) int __cdecl sub_0052DB00() {
    return 1;
}

// 0x0052DB10
int __fastcall GAME_ReceiveSaveFilePart(int nClientId, D2GSPacketClt6B* pPacket)
{
    return CLIENTS_AttachSaveFile(nClientId, pPacket->saveData, pPacket->nSize, pPacket->dwTotalSize, 0, 0, 0);
}

int __fastcall sub_0052B800_IsConnectionMode2()
{
    return gnConnectionMode_00882D10 == 2;
}

int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize)
{
    int nResult;

    EnterCriticalSection(pCriticalSection);

    D2NetPacketRecStrc* pPacket = *ppPacketList;
    if (pPacket && (gnConnectionMode_00882D10 != 2 || GetTickCount() - pPacket->dwTickCount >= 500))
    {
        memcpy(pBuffer, pPacket, nBufferSize < MAX_MSG_SIZE ? nBufferSize : MAX_MSG_SIZE);
        nResult = pPacket->nPacketSize;
        *ppPacketList = pPacket->pNext;
        FOG_Free(pPacket, szD2NetCpp_006E0488, 0x46, 0);
    }
    else
    {
        nResult = -1;
    }

    LeaveCriticalSection(pCriticalSection);
    return nResult;
}

void __cdecl sub_0052B8F0_Nop()
{
}

void __cdecl sub_0052B900_Nop()
{
}

bool __stdcall sub_0052BDD0_AlwaysTrue(int nUnused)
{
    return true;
}

unsigned int __fastcall sub_0052BE00_GetBits12(unsigned int nValue)
{
    return (nValue >> 12) & 7;
}

char* __fastcall sub_0052BE10_GetField0D0(D2Net52BE10Strc* pRecord)
{
    return pRecord->aData;
}

void __stdcall sub_0052BE40_Stub(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18)
{
}

void __stdcall sub_0052BE60_Stub(int a1, int a2, int a3, int a4)
{
}

void __cdecl sub_0052BE70_Stub()
{
}

void __stdcall sub_0052BE80_Stub(int a1, int a2, int a3)
{
}

int __stdcall sub_0052BE90_Stub(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 0;
}

void __stdcall sub_0052BED0_Stub(int a1, int a2, int a3, int a4, int a5)
{
}

void __cdecl sub_0052BEF0_Stub()
{
}

void __stdcall sub_0052BF40_Stub(int a1, int a2, int a3, int a4)
{
}

void __stdcall sub_0052BFB0_Stub(int a1, int a2, int a3, int a4)
{
}

const char* __fastcall sub_0052BFC0_GetLoadComplete()
{
    if (!gbD2ServerCallbackFunctionsInitialized_6FD45834)
    {
        return gData_006E0498;
    }
    return gpD2EventCallbackTable_6FD45830->pfLoadComplete();
}

// 0x0052DB30
int __fastcall sub_0052BFE0_GetGamesCount()
{
    int nResult = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] != 0 && gnGamesGUIDs_6FD447F8[i] != -1)
        {
            ++nResult;
        }
    }
    return nResult;
}

// 0x0052DB80
int __cdecl sub_0052DB80_CountFlaggedClients()
{
    return sub_005377B0_CountFlaggedClients();
}

// 0x0052DB90
int __cdecl sub_0052DB90()
{
    return gdwGlobal_00731010;
}

// 0x0052DBA0
void __stdcall GAME_GetMemoryUsage(int* pCurrentMemoryUsage, int* pPeakMemoryUsageInLast10s)
{
    *pCurrentMemoryUsage = sub_0040A040_GetPoolSystemCount(0);
    *pPeakMemoryUsageInLast10s = gnPeakMemoryUsageInLast10s_6FD45828;
}

// 0x0052DBC0
static int sub_0052DBC0_CountUnitsInLists(D2UnitStrc** pUnitLists)
{
    int nUnits = 0;
    for (int i = 0; i < 128; ++i)
    {
        if (D2UnitStrc* pFirstUnit = pUnitLists[i])
        {
            ++nUnits;
            for (D2UnitStrc* pUnit = SUNIT_GetNextUnitFromList(pFirstUnit); pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                ++nUnits;
            }
        }
    }
    return nUnits;
}

// 0x0052DC00
int __stdcall sub_0052DC00_PassThrough(int a1)
{
    return a1;
}

// 0x0052DC10
int __cdecl sub_0052DC10()
{
    return gdwGlobal_00731008;
}

// 0x0052DC20
static void __stdcall sub_0052DC20_AddUnitDescription(int bCount, int nClassId, D2UnitDescriptionListStrc* pList)
{
    D2UnitDescriptionListStrc* pHead = pList;
    D2_ASSERT(pList, 0x139E);
    do
    {
        if (pList->nClassId == nClassId)
        {
            if (bCount)
            {
                ++pList->nCount;
            }
            else
            {
                ++pList->nDefaultCount;
            }
            return;
        }
        pList = pList->pNext;
    }
    while (pList);

    D2UnitDescriptionListStrc* pNew = (D2UnitDescriptionListStrc*)sub_0040B430(0, sizeof(D2UnitDescriptionListStrc), ".\\GAME\\Game.cpp", 0x13AF, 0);
    if (pNew)
    {
        memset(pNew, 0, sizeof(D2UnitDescriptionListStrc));
        pNew->nClassId = nClassId;
        pNew->nCount = 0;
        pNew->nDefaultCount = 0;
        if (bCount)
        {
            pNew->nCount = 1;
        }
        else
        {
            pNew->nDefaultCount = 1;
        }
        pNew->pNext = pHead->pNext;
        pHead->pNext = pNew;
    }
}

static inline D2MonStatsTxt* DESC_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x0052DCF0
void __fastcall GAME_GetPlayerDescription(char* szDescription, int nClassId)
{
    switch (nClassId)
    {
    case PCLASS_AMAZON: strcpy(szDescription, "Amazon"); break;
    case PCLASS_SORCERESS: strcpy(szDescription, "Sorceress"); break;
    case PCLASS_NECROMANCER: strcpy(szDescription, "Necromancer"); break;
    case PCLASS_PALADIN: strcpy(szDescription, "Paladin"); break;
    case PCLASS_BARBARIAN: strcpy(szDescription, "Barbarian"); break;
    case PCLASS_DRUID: strcpy(szDescription, "Druid"); break;
    case PCLASS_ASSASSIN: strcpy(szDescription, "Assassin"); break;
    default: strcpy(szDescription, "Invalid Class"); break;
    }
}

// 0x0052DDF0
void __fastcall GAME_GetMonsterDescription(char* szDescription, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DESC_GetMonStatsTxtRecord(nClassId);
    if (pMonStatsTxtRecord)
    {
        const Unicode* pName = D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr);
        sub_00526F70(szDescription, pName, 64);
    }
    else
        sprintf(szDescription, "Monster %d", nClassId);
}

// 0x0052DE40
void __fastcall GAME_GetObjectDescription(char* szDescription, int nClassId)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
    if (pObjectsTxtRecord)
        strcpy(szDescription, pObjectsTxtRecord->szName);
    else
        sprintf(szDescription, "Object %d", nClassId);
}

// 0x0052DE80
void __fastcall GAME_GetItemDescription(char* szDescription, int nClassId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (pItemsTxtRecord)
    {
        const Unicode* pName = D2LANG_GetStringFromTblIndex(pItemsTxtRecord->wNameStr);
        sub_00526F70(szDescription, pName, 64);
    }
    else
        sprintf(szDescription, "Item %d", nClassId);
}

// 0x0052DEC0
void __fastcall GAME_GetMissileDescription(char* szDescription, int nClassId)
{
    sprintf(szDescription, "Missile %d", nClassId);
}

// 0x0052DED0
void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext)
{
    D2_ASSERT(pGame, 5496);
    D2_ASSERT(!IsBadCodePtr((FARPROC)pFn), 5497);

    for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
    {
        if (pClient->dwClientState == CLIENTSTATE_INGAME)
        {
            pFn(pClient, pContext);
        }
    }
}

// 0x0052DF40
void __fastcall GAME_UnlockDebugGame()
{
    GAME_LeaveGamesCriticalSection(gpGame_6FD457FC);
}

// 0x0052DF80
void __stdcall sub_0052DF80(int a1)
{
    gnTargetFrameRate_6FD2CA60 = a1;
    gnTargetMsPerFrame_6FD457F8 = 1000 / a1;
}

// 0x0052DFA0
void __stdcall GAME_SetGlobalAct(int nAct)
{
    gnAct_6FD45824 = nAct;
}

// 0x0052DFB0
void __fastcall GAME_SendUnitRemovalToClient(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2_ASSERT(pClientRoom, 5566);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pRoom = ppRoomList[i];
        D2_ASSERT(pRoom, 5571);

        if (pUnitRoom == pRoom)
        {
            sub_0053BDA0_SendUnitRemoval(pClient, 0x0A, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            return;
        }
    }
}

// 0x0052E050
void __fastcall GAME_RemoveUnit(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    GAME_ForEachIngameClient(pGame, GAME_SendUnitRemovalToClient, pUnit);
    SUNIT_RemoveUnit(pGame, pUnit);
}

// 0x0052E070
int __cdecl sub_0052E070()
{
    return 0;
}

// 0x0052E080
int __cdecl sub_0052E080()
{
    return 0;
}

// 0x0052E090
int __stdcall sub_00646000_AlwaysZero(int nUnused)
{
    return 0;
}

// 0x0052E0A0
void D2GameDataTableStrc::SyncEnterLock(int* pLockHandle, int bForWriting)
{
    EnterCriticalSection(&f_50);
    *pLockHandle = bForWriting ? 1 : -1;
}

// 0x0052E0D0
int __stdcall sub_0052E0D0_IsOne(int nValue)
{
    return nValue == 1;
}

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}

// 0x0052E0E0
unsigned int D2StormHashTableStrc::sub_0052E0E0_Mask(unsigned int value) {return m_slotmask & value;}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0052E100
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x0052E110
static void __stdcall GAME_SendSaveFilePart(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (!sub_00538FC0(pClient))
    {
        return;
    }

    if (pClient->nSaveHeaderSendDelay)
    {
        --pClient->nSaveHeaderSendDelay;
        return;
    }

    const unsigned char* pSaveData = (const unsigned char*)pClient->pSaveHeader;
    pClient->nSaveHeaderSendDelay = 5;
    if (!pSaveData)
    {
        return;
    }

    const unsigned char* pData = &pSaveData[pClient->nSaveHeaderDataSentBytes];
    int nDataSize = pClient->nSaveHeaderSize - pClient->nSaveHeaderDataSentBytes;
    if (nDataSize >= 255)
    {
        nDataSize = 255;
    }

    D2SavePartPacketStrc* pPacket = (D2SavePartPacketStrc*)sub_0040B430(pClient->pGame->pMemoryPool, sizeof(D2SavePartPacketStrc), ".\\GAME\\Game.cpp", 0x904, 0);
    pPacket->nHeader = 0xB3;
    pPacket->nPartDataSize = nDataSize;
    pPacket->bFirstPart = pClient->nSaveHeaderDataSentBytes == 0;
    pPacket->nSaveHeaderSize = pClient->nSaveHeaderSize;
    unsigned char* pPacketData = pPacket->aData;

    for (int i = 0; i < nDataSize; ++i)
    {
        *pPacketData++ = *pData++;
    }

    if (sub_0052B330(0, pClient->dwClientId, pPacket, nDataSize + 0x7))
    {
        pClient->nSaveHeaderDataSentBytes += nDataSize;

        if (pClient->nSaveHeaderDataSentBytes == pClient->nSaveHeaderSize)
        {
            CLIENTS_FreeSaveHeader(pClient);
        }

        pClient->nSaveHeaderSendFailures = 0;
    }
    else
    {
        ++pClient->nSaveHeaderSendFailures;
    }

    sub_0040B480(pClient->pGame->pMemoryPool, pPacket, ".\\GAME\\Game.cpp", 0x92A, 0);

    if (pClient->nSaveHeaderSendFailures >= 3)
    {
        CLIENTS_FreeSaveHeader(pClient);
        SrvDisconnectClient(pGame, pClient, 0);
    }
}

// 0x0052E260
static void sub_0052E260_SendRemainingSaveParts(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        while (sub_00538FC0(pClient))
        {
            GAME_SendSaveFilePart(pGame, pClient);
        }
    }
}

// 0x0052E2A0
void __fastcall GAME_SaveAndSendClientSaves(D2GameStrc* pGame)
{
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        D2ClientStrc* pClient = pGame->pClientList;
        while (pClient)
        {
            D2ClientStrc* pNextClient = pClient->pNext;

            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pPlayer)
            {
                D2GAME_SAVE_WriteFile_6FC8A500(pGame, pPlayer, CLIENTS_GetName(pClient), 0);
                sub_0052E260_SendRemainingSaveParts(pGame, pClient);
            }

            pClient = pNextClient;
        }
    }
}

// 0x0052E320
static void __stdcall GAME_SendClientPackets(D2GameStrc* ptGame, int bSyncPlayer, D2ClientStrc* ptClient)
{
    D2_ASSERT(ptGame, 0xF37);
    D2_ASSERT(ptClient, 0xF38);

    if (bSyncPlayer && ptClient->dwClientState == CLIENTSTATE_INGAME)
    {
        if (gdwPlayerPos_00883D4C)
        {
            sub_0052DA00_RefreshUnitsUpdate(ptClient);
        }

        sub_0052D980_SyncPlayerStats(ptClient);
    }

    if (ptGame->nGameType == 1 || ptGame->nGameType == 2)
    {
        GAME_SendSaveFilePart(ptGame, ptClient);
    }

    int nCounter = 0;
    int bError = 0;
    do
    {
        D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_PopHead(ptClient);
        if (!pPacketData || !pPacketData->nPacketSize)
        {
            break;
        }

        if ((unsigned int)sub_0052B330(1, ptClient->dwClientId, pPacketData->packetData, pPacketData->nPacketSize) > 0)
        {
            ++nCounter;
            pPacketData->nPacketSize = 0;
            pPacketData->pNext = ptClient->pPacketDataPool;
            ptClient->pPacketDataPool = pPacketData;
            ptClient->nSaveHeaderSendFailures = 0;
        }
        else
        {
            sub_0052B910();
            bError = 1;
            ++ptClient->nSaveHeaderSendFailures;
            CLIENTS_PacketDataList_Reset(ptClient, pPacketData);
            if (ptClient->nSaveHeaderSendFailures >= 3)
            {
                SrvDisconnectClient(ptGame, ptClient, 0);
                return;
            }
        }
    }
    while ((ptGame->nGameType != 1 && ptGame->nGameType != 2 || nCounter < 3) && !bError);
}

// 0x0052E440
void __fastcall GAME_SendAllClientPackets(D2GameStrc* pGame)
{
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNextClient = pClient->pNext;
        GAME_SendClientPackets(pGame, 1, pClient);
        pClient = pNextClient;
    }
}

// 0x0052E470
void D2GameDataTableStrc::SyncLeaveLock(int nLockHandle)
{
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// build: symbol ?Unlink@D2GameDataTableStrc@@QAEXPAUD2GameStrc@@@Z 0x0052E490
void D2GameDataTableStrc::Unlink(D2GameStrc* pGame)
{
    if (pGame->tLinkToSlot.pNext)
    {
        GAMELINK_Unlink(&pGame->tLinkToSlot);
        GAMELINK_Unlink(&pGame->tLinkToFull);
    }
}

// build: symbol ?RawNext@D2GameListStrc@@QAEPAUD2GameStrc@@PAU2@@Z 0x0052E510
D2GameStrc* D2GameListStrc::RawNext(D2GameStrc* pGame)
{
    D2GameLinkStrc* pLink = pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    return pLink->pNext;
}

// build: symbol ?Next@D2GameListStrc@@QAEPAUD2GameStrc@@PAU2@@Z 0x0052E530
D2GameStrc* D2GameListStrc::Next(D2GameStrc* pGame)
{
    D2GameLinkStrc* pLink = pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    D2GameStrc* pNext = pLink->pNext;
    return (int)pNext > 0 ? pNext : 0;
}

// 0x0052E570
void D2GameDataTableStrc::Unlock(int nLockHandle)
{
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E590
void D2GameDataTableStrc::sub_0052E590(D2GameStrc* pGame)
{
    Unlink(pGame);
    InternalDelete(pGame);
}

// 0x0052E5B0
void D2GameDataTableStrc::sub_0052E5B0(D2GameStrc* pGame)
{
    Unlink(pGame);
    InternalDelete(pGame);
}

// 0x0052E5D0
void D2GameDataTableStrc::DeleteUnlock(D2GameStrc* pGame, int nLockHandle)
{
    Unlink(pGame);
    InternalDelete(pGame);
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E600
D2GameStrc* D2GameListStrc::DeleteNode(D2GameStrc* pGame)
{
    D2GameStrc* pNext = InlineNext(pGame);
    ((D2GameNodeStrc*)pGame)->~D2GameNodeStrc();
    SMemFree(pGame, gszSGameDataTypeName, -2, 0);
    return pNext;
}

// 0x0052E650
char* D2StormHashTable0052E650Strc::sub_0052E650_Ptr(unsigned int nHashVal, int nKey)
{
    for (char* pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].Head(); _ReadWriteBarrier(), (int)pNode > 0; pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormHashNodeStrc*)pNode)->m_hashval == nHashVal)
        {
            return pNode;
        }
    }
    return 0;
}

// 0x0052E6B0
D2GameStrc* D2GameDataTableStrc::sub_0052E6B0(unsigned int nHashValue)
{
    return Ptr(nHashValue, &f_44);
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

// 0x0052E6D0
unsigned int D2GameDataTableStrc::sub_0052E6D0_GenerateHandle()
{
    while (1)
    {
        nSequence += 1;
        if (!nSequence)
        {
            bWrapped = 1;
            continue;
        }

        if (!bWrapped)
        {
            return nSequence;
        }

        if (!Ptr(nSequence, &f_44))
        {
            return nSequence;
        }
    }
}

// 0x0052E710
D2GameStrc* D2GameDataTableStrc::Lock(unsigned int nHashValue, int* pLockHandle, int bForWriting)
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

// 0x0052E770
void __fastcall GAME_CloseGame(int nGameGUID)
{
    if (gpGameDataTbl_6FD45818)
    {
        int hLock;
        D2GameStrc* pGame = gpGameDataTbl_6FD45818->LockInline(nGameGUID, &hLock, 0);
        if (pGame)
        {
            if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfCloseGame)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfCloseGame), 0x107C);
                gpD2EventCallbackTable_6FD45830->pfCloseGame(pGame->nGameId, pGame->bExpansion ? 0x44325850 : 0x44324456, pGame->dwLastUsedUnitGUID[UNIT_PLAYER], pGame->dwGameFrame / 25);
            }

            D2_ASSERT(pGame->lpCriticalSection, 0x108D);
            EnterCriticalSection(pGame->lpCriticalSection);

            SrvFreeGame(nGameGUID, pGame);

            gpGameDataTbl_6FD45818->DeleteUnlock(pGame, hLock);
        }
    }
}

// 0x0052E860
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return 0;
    }

    int hLock;
    D2GameStrc* pGame = gpGameDataTbl_6FD45818->LockInline(nGameGUID, &hLock, 1);
    if (pGame)
    {
        D2_ASSERT(pGame->lpCriticalSection, 0x1181);
        EnterCriticalSection(pGame->lpCriticalSection);
        if (hLock)
        {
            LeaveCriticalSection(&gpGameDataTbl_6FD45818->f_50);
        }
    }
    return pGame;
}

// 0x0052E8E0
void __stdcall sub_0052E8E0(void* pArg)
{
    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != -1)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(nGUID))
            {
                const unsigned int nClients = (unsigned short)ptGame->nClients;
                const unsigned short nGameId = ptGame->nGameId;
                char szGameName[16];
                SStrCopy(szGameName, ptGame->szGameName, 0x7FFFFFFF);

                D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                sub_0053B1B0_SendGameInfo(pArg, nGameId, nClients, szGameName);
            }
        }
    }

    sub_0053B1B0_SendGameInfo(pArg, 0xFFFF, 0, &gszEmptyAssertText);
}

// 0x0052E9B0
void __fastcall sub_0052E9B0(void* pArg)
{
    sub_0052E8E0(pArg);
}

// 0x0052E9C0
void __stdcall GAME_CloseAllGames()
{
    TASK_FreeAllQueueSlots();

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != D2GameReservedSlotHandle)
        {
            D2GameStrc* ptGame = GAME_LockGame(nGUID);
            D2_ASSERT(ptGame, 0x1206);

            D2ClientStrc* pClient = ptGame->pClientList;
            while (pClient)
            {
                D2ClientStrc* pNextClient = pClient->pNext;

                sub_0053B220_SendHeaderOnly0xB0(pClient->dwClientId);
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                D2GAME_SAVE_WriteFile_6FC8A500(ptGame, pPlayer, CLIENTS_GetName(pClient), 1);
                sub_0052E260_SendRemainingSaveParts(ptGame, pClient);
                sub_0053B240_SendHeaderOnly0x06(pClient->dwClientId);
                ClientRemoveFromGame(ptGame, pClient->dwClientId, 0);

                pClient = pNextClient;
            }

            D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
            LeaveCriticalSection(ptGame->lpCriticalSection);

            GAME_CloseGame(nGUID);
        }
    }
}

// 0x0052EAE0
int __stdcall sub_0052EAE0()
{
    int nExpansionGames = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                if (pGame->bExpansion)
                {
                    ++nExpansionGames;
                }
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return nExpansionGames;
}

// 0x0052EB50
void __stdcall sub_0052EB50(short* pCount, int nArraySize)
{
    memset(pCount, 0, 2 * nArraySize + 2);

    for (int i = 0; i < 1024; ++i)
    {
        const int nGameGuid = gnGamesGUIDs_6FD447F8[i];
        if (nGameGuid && nGameGuid != D2GameReservedSlotHandle)
        {
            D2GameStrc* ptGame = GAME_LockGame(nGameGuid);
            if (ptGame)
            {
                int nIndex = ptGame->nClients;
                D2_ASSERT(ptGame->lpCriticalSection, 4196);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                if (nIndex > nArraySize)
                {
                    nIndex = nArraySize;
                }

                ++pCount[nIndex];
            }
        }
    }
}

// 0x0052EBE0
void __stdcall sub_0052EBE0(unsigned short* pCount, int nMaxCount)
{
    memset(pCount, 0, sizeof(*pCount) * nMaxCount);

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != -1)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                const int nSecondsPassed = ptGame->dwGameFrame / 25;

                D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                int nIndex = nSecondsPassed / 300;
                if (nIndex >= nMaxCount)
                {
                    nIndex = nMaxCount - 1;
                }

                ++pCount[nIndex];
            }
        }
    }
}

// 0x0052EC90
int __stdcall sub_0052EC90(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    D2_ASSERT(pGame, 4806);
    const int nClients = pGame->nClients;
    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);
    return nClients;
}

// 0x0052ED10
int __stdcall GAME_GetGameInformation(unsigned short nGameId, D2GameInfoStrc* pGameInfo)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    if (!ptGame)
    {
        return 0;
    }

    pGameInfo->nGameId = ptGame->nGameId;
    pGameInfo->nInitSeed = ptGame->dwInitSeed;
    pGameInfo->nClients = ptGame->nClients;
    pGameInfo->dwLastUsedUnitGUID[0] = ptGame->dwLastUsedUnitGUID[0];
    pGameInfo->dwLastUsedUnitGUID[1] = ptGame->dwLastUsedUnitGUID[1];
    pGameInfo->dwLastUsedUnitGUID[2] = ptGame->dwLastUsedUnitGUID[2];
    pGameInfo->dwLastUsedUnitGUID[3] = ptGame->dwLastUsedUnitGUID[3];
    pGameInfo->dwLastUsedUnitGUID[4] = ptGame->dwLastUsedUnitGUID[4];
    pGameInfo->dwLastUsedUnitGUID[5] = ptGame->dwLastUsedUnitGUID[5];

    pGameInfo->nPlayers = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[0]);
    pGameInfo->nMonsters = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[1]);
    pGameInfo->nObjects = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[2]);
    pGameInfo->nItems = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[3]);
    pGameInfo->nMissiles = sub_0052DBC0_CountUnitsInLists(ptGame->pUnitList[4]);

    if (ptGame->nTotalPathTypesCount)
    {
        pGameInfo->nPathTowardPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_TOWARD] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathClockPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_MON_CIRCLE_CW] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathCounterPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_MON_CIRCLE_CCW] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathAStarPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_ASTAR] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathFoWallPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_WALL_FOLLOW] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathTotalCalls = ptGame->nTotalPathTypesCount;
        if ((unsigned int)ptGame->nTotalPathTypesCount > 200 && pGameInfo->nPathTotalCalls)
        {
            memset(ptGame->dwPathTypesCount, 0, sizeof(ptGame->dwPathTypesCount) + sizeof(ptGame->nTotalPathTypesCount));
        }
    }

    SStrCopy(pGameInfo->szGameName, ptGame->szGameName, 16);
    pGameInfo->nTime = (GetTickCount() - ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10) / 1000 / 60;
    pGameInfo->nFrames = ptGame->dwGameFrame / 100;
    pGameInfo->nFrameRate = ptGame->nFrameRate;
    pGameInfo->nArenaTemplate = ptGame->nArenaTemplate;
    pGameInfo->nMaxLevelDifference = ptGame->nMaxLevelDifference;
    pGameInfo->nMaxPlayers = ptGame->nMaxPlayers;
    SStrCopy(pGameInfo->szGamePassword, ptGame->szGamePassword, 16);
    SStrCopy(pGameInfo->szGameDescription, ptGame->szGameDesc, 32);
    pGameInfo->nArenaFlags = ARENA_GetFlags(ptGame);
    pGameInfo->pMemoryPool = ptGame->pMemoryPool;

    D2_ASSERT(ptGame->lpCriticalSection, 4196);
    LeaveCriticalSection(ptGame->lpCriticalSection);
    return 1;
}

// 0x0052EF70
int __stdcall GAME_GetGameServerGameIds(unsigned short* pServerToken, int nMaxCount)
{
    int nServerTokenCount = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (nServerTokenCount >= nMaxCount)
        {
            break;
        }

        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]);
            if (pGame)
            {
                pServerToken[nServerTokenCount] = pGame->nGameId;
                ++nServerTokenCount;
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return nServerTokenCount;
}

// 0x0052EFF0
int __stdcall GAME_GetPlayerUnitsCount(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    int nUnits = 0;
    if (pGame)
    {
        nUnits = sub_0052DBC0_CountUnitsInLists(pGame->pUnitList[0]);
        D2_ASSERT(pGame->lpCriticalSection, 4196);
        LeaveCriticalSection(pGame->lpCriticalSection);
    }
    return nUnits;
}

// 0x0052F080
int __stdcall sub_0052F080_GetPlayerUnitInfo(unsigned short nGameId, D2UnitInfoStrc* pUnitInfo, int nMaxCount)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - GAME_ID_BIAS] && gnGamesGUIDs_6FD447F8[nGameId - GAME_ID_BIAS] != -1)
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - GAME_ID_BIAS];
    LeaveCriticalSection(&gCriticalSection_6FD45800);
    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    int nCount = 0;
    if (ptGame)
    {
        for (int i = 0; i < BUCKETS; ++i)
        {
            if (nCount >= nMaxCount) break;
            for (D2UnitStrc* pUnit = ptGame->pUnitList[0][i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                if (nCount >= nMaxCount) break;
                SUNIT_FillUnitInfo(pUnit, &pUnitInfo[nCount]);
                ++nCount;
            }
        }
        D2_ASSERT(ptGame->lpCriticalSection, UNLOCK_LINE);
        LeaveCriticalSection(ptGame->lpCriticalSection);
    }
    return nCount;
}

// 0x0052F160
void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    D2UnitStrc** pUnitList = 0;
    if (ptGame)
    {
        switch (eType)
        {
        case 0:
            pUnitList = ptGame->pUnitList[0];
            break;
        case 1:
            pUnitList = ptGame->pUnitList[1];
            break;
        case 2:
            pUnitList = ptGame->pUnitList[2];
            break;
        case 3:
            pUnitList = ptGame->pUnitList[3];
            break;
        case 4:
            pUnitList = ptGame->pUnitList[4];
            break;
        }

        D2UnitDescriptionListStrc* pList = pUnitDescriptionsList;
        for (int i = 0; i < 128; ++i)
        {
            for (D2UnitStrc* pUnit = pUnitList[i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                const int v_dwClassId_147 = pUnit ? pUnit->dwClassId : -1;
                sub_0052DC20_AddUnitDescription(1, v_dwClassId_147, pList);
            }
        }

        D2_ASSERT(ptGame->lpCriticalSection, 4196);
        LeaveCriticalSection(ptGame->lpCriticalSection);

        const unsigned int nType = eType;
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfGetDescription_6FD2CA64[nType]), 0x1450);
        for (D2UnitDescriptionListStrc* pNode = pList->pNext; pNode; pNode = pNode->pNext)
        {
            gpfGetDescription_6FD2CA64[nType](pNode->szDescription, pNode->nClassId);
        }
    }
}

// 0x0052F2C0
int __stdcall sub_0052F2C0(unsigned short nGameId, int nMaxCount, D2UnitInfoStrc* pUnitInfo, int* pUnitType, int* pUnitGUID)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    int nUnitInfoCount = 0;
    if (!ptGame)
    {
        return 0;
    }

    {
        for (int i = 0; i < nMaxCount; ++i)
        {
            D2UnitStrc* pUnit = SUNIT_GetServerUnit(ptGame, pUnitType[i], pUnitGUID[i]);
            if (pUnit)
            {
                SUNIT_FillUnitInfo(pUnit, &pUnitInfo[nUnitInfoCount]);

                if (pUnitType[i])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfGetDescription_6FD2CA64[pUnitType[i]]), 0x1472);
                    gpfGetDescription_6FD2CA64[pUnitType[i]](pUnitInfo[nUnitInfoCount].szDescription, pUnit->dwClassId);
                }

                ++nUnitInfoCount;
            }
        }

        D2_ASSERT(ptGame->lpCriticalSection, 4196);
        LeaveCriticalSection(ptGame->lpCriticalSection);
    }

    return nUnitInfoCount;
}

// 0x0052F3E0
void __stdcall GAME_GetStatistics(D2GameStatisticsStrc* pStats)
{
    pStats->nGamesCount = 0;
    pStats->nActiveMonsters = 0;
    pStats->nInactiveMonsters = 0;
    pStats->nPlayersCount = 0;

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]))
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (D2UnitStrc* k = ptGame->pUnitList[UNIT_MONSTER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nActiveMonsters;
                    }

                    for (D2UnitStrc* k = ptGame->pUnitList[UNIT_PLAYER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nPlayersCount;
                    }
                }

                D2_ASSERT(ptGame->lpCriticalSection, 4196);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                ++pStats->nGamesCount;
            }
        }
    }
}

// 0x0052F4C0
void __stdcall GAME_SendMessageToAllClients(int a1, int nPacketParam, const char* szMessage)
{
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != -1)
        {
            D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]);
            D2_ASSERT(ptGame, 0x1063);
            switch (a1)
            {
            case 1:
            {
                D2GSPacketSrv5A packet5A = {};
                packet5A.nHeader = 0x5A;
                packet5A.nType = 0x0F;
                packet5A.nColor = 4;
                *(int*)packet5A.abParam = nPacketParam;
                packet5A.szText[16] = 0;
                sub_6FC84D40(ptGame, &packet5A);
                break;
            }
            default:
                if (strlen(szMessage) > 255)
                {
                    char szCopy[256];
                    strncpy(szCopy, szMessage, 255);
                    szCopy[255] = '\0';
                    sub_6FC84CD0(ptGame, szCopy, 1);
                }
                else
                {
                    sub_6FC84CD0(ptGame, szMessage, 1);
                }
                break;
            }

            D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
            LeaveCriticalSection(ptGame->lpCriticalSection);
        }
    }
}

// 0x0052F630
void __stdcall sub_0052F630(unsigned short gameId,unsigned char* message)
{
    int guid = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[gameId-1] && gnGamesGUIDs_6FD447F8[gameId-1] != -1) guid = gnGamesGUIDs_6FD447F8[gameId-1];
    LeaveCriticalSection(&gCriticalSection_6FD45800);
    D2GameStrc* ptGame = GAME_LockGame(guid);
    D2_ASSERT(ptGame,0x1564);
    message[255] = 0;
    if (!strncmp("<ABEND> ",(const char*)message,8)) ptGame->nDebugBreakTrigger = message[8] & MODE_MASK;
    sub_0054A9B0(ptGame,(const char*)message,1);
    D2_ASSERT(ptGame->lpCriticalSection,0x1064);
    LeaveCriticalSection(ptGame->lpCriticalSection);
}

// 0x0052F6E0
D2GameStrc* __fastcall GAME_LockDebugGame()
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);

    if (*gnGamesGUIDs_6FD447F8 && *gnGamesGUIDs_6FD447F8 != D2GameReservedSlotHandle)
    {
        nGUID = *gnGamesGUIDs_6FD447F8;
    }

    LeaveCriticalSection(&gCriticalSection_6FD45800);

    gpGame_6FD457FC = GAME_LockGame(nGUID);
    return gpGame_6FD457FC;
}

// 0x0052F720
unsigned long __stdcall sub_0052F720_MessageThreadProc(D2MessageThreadArgsStrc* pArgs)
{
    GAME_SendMessageToAllClients(pArgs->nParam1, pArgs->nParam2, pArgs->szMessage);
    return 1;
}

// 0x0052F740
void __fastcall sub_0052F740_SendMessageToAllClientsAsync(int a1, int nPacketParam, const char* szMessage)
{
    unsigned long nThreadId;
    D2MessageThreadArgsStrc* pArgs = (D2MessageThreadArgsStrc*)FOG_AllocPool(0, sizeof(D2MessageThreadArgsStrc), ".\\GAME\\Game.cpp", 5665, 0);
    if (pArgs)
    {
        pArgs->nParam1 = a1;
        pArgs->nParam2 = nPacketParam;
        strncpy(pArgs->szMessage, szMessage, 0xFF);
        pArgs->szMessage[0xFF] = 0;
        CreateThread(0, 0, sub_0052F720_MessageThreadProc, pArgs, 0, &nThreadId);
    }
}

// 0x0052F7B0
int __fastcall GAME_FindGameWithName(const char* szGameName)
{
    for (int i = 0; i < 1024; ++i)
    {
        const int nGameGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGameGUID)
        {
            D2GameStrc* pGame = GAME_LockGame(nGameGUID);
            if (pGame)
            {
                if (!SStrCmpI(pGame->szGameName, szGameName, 0x7FFFFFFF))
                {
                    D2_ASSERT(pGame->lpCriticalSection, 4196);
                    LeaveCriticalSection(pGame->lpCriticalSection);
                    return nGameGUID;
                }
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return 0;
}

// 0x0052F840
unsigned int __fastcall sub_0052F840()
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (*gnGamesGUIDs_6FD447F8 && *gnGamesGUIDs_6FD447F8 != D2GameReservedSlotHandle)
    {
        nGUID = *gnGamesGUIDs_6FD447F8;
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    gpGame_6FD457FC = pGame;
    if (!pGame)
    {
        return 0;
    }

    const unsigned int nInitSeed = pGame->dwInitSeed;
    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);
    return nInitSeed;
}

// 0x0052F8B0
int __fastcall sub_0052F8B0_IsGameNameUnused(const char* szGameName)
{
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs_6FD447F8[i] && gnGamesGUIDs_6FD447F8[i] != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs_6FD447F8[i]);
            if (pGame)
            {
                if (!SStrCmpI(szGameName, pGame->szGameName, 16))
                {
                    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                    LeaveCriticalSection(pGame->lpCriticalSection);
                    return 0;
                }

                D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return 1;
}

// 0x0052F940
void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int dwFlags)
{
    if (sub_0052F8B0_IsGameNameUnused(szGameName))
    {
        SStrCopy(pGame->szGameName, szGameName, 0x7FFFFFFF);
        return;
    }

    char szName[16];
    size_t nLength = strlen(szGameName);
    if (0xF - nLength < 3)
        nLength = 0xB;
    memcpy(szName, szGameName, nLength);
    sprintf(&szName[nLength], "~%d", szGameName, 0);

    int nCounter = 1;
    while (!sub_0052F8B0_IsGameNameUnused(szName) && nCounter < 100)
    {
        sprintf(szName, "%s~%d", szGameName, nCounter);
        nCounter += 1;
    }
    D2_ASSERT(nCounter < 100, 0x263);

    SStrCopy(pGame->szGameName, szName, 0x7FFFFFFF);
}

// 0x0052FA50
void __fastcall SrvJoinGame(int dwClientId, unsigned short nGameId, int nClass, const char* szClientName, int a5, const char* szAccountName, int nCharSaveTransactionToken, int nLocale, int a8, int a9, int a11, int a12, int a13)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return;
    }

    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    if (!nGUID)
    {
        return;
    }

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    if (!pGame)
    {
        GAME_LogMessage(6, "[JOIN]  SrvJoinGame: ERROR cannot loc game - Game(%d), ClientID(%d), Player(%s)", nGameId, dwClientId, szClientName);
        return;
    }

    SERVER_SetClientGameGUID(dwClientId, nGUID);

    D2ClientStrc* pClient = ClientAddToGame(pGame, dwClientId, nClass, szClientName, szAccountName, nCharSaveTransactionToken, nLocale, a8, a9);
    if (!pClient)
    {
        if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfUnlockDatabaseCharacter)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfUnlockDatabaseCharacter), 1972);
            gpD2EventCallbackTable_6FD45830->pfUnlockDatabaseCharacter(&pGame->pClientInfo, szClientName, szAccountName);
        }
        GAME_LeaveGamesCriticalSection(pGame);
        sub_0053B220_SendHeaderOnly0xB0(dwClientId);
        D2NET_10016(dwClientId);
        GAME_LogMessage(6, "[JOIN]  SrvJoinGame: ERROR adding Client to game - Game(%d), ClientID(%d), Player(%s)", nGameId, dwClientId, szClientName);
        return;
    }

    sub_0052C260_SendGameInit(pGame, pClient);
    pClient->bAct = gnAct_6FD45824;
    GAME_LeaveGamesCriticalSection(pGame);

    if (gpD2EventCallbackTable_6FD45830 && gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter)
    {
        GAME_LogMessage(6, "[JOIN 2] %d clientid, %d game, Requesting char from db", dwClientId, nGameId);
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter), 2023);
        gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter(&pClient->pClientInfo, szClientName, dwClientId, szAccountName);
        sub_6FC33910(pClient);
    }
    else
    {
        D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
    }
}

// 0x0052FC20
int __stdcall GAME_UpdateGamesProgress(int a1)
{
    D2LargeIntegerUnion aCounter[2];
    int bQueryPerformance = 0;
    QueryPerformanceCounter(&aCounter[0]);

    const int nSysTimeMs = timeGetTime() & 0x7FFFFFFF;
    if (!dword_6FD45844)
    {
        dword_6FD45844 = nSysTimeMs;
    }

    const int nElapsed = nSysTimeMs - dword_6FD45844;
    if (nElapsed < gnTargetMsPerFrame_6FD457F8)
    {
        return 0;
    }

    unsigned int nLate = nElapsed - gnTargetMsPerFrame_6FD457F8;
    if (a1 && nLate >= gnTargetMsPerFrame_6FD457F8)
    {
        nLate = gnTargetMsPerFrame_6FD457F8;
    }

    dword_6FD45844 = nSysTimeMs - nLate;

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != -1)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(nGUID))
            {
                bQueryPerformance = 1;

                if (!dword_6FD2CA10)
                {
                    if (ptGame->nLastUpdateSystemTimeMs)
                    {
                        ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = ((nSysTimeMs - ptGame->nLastUpdateSystemTimeMs) << 10) / gnTargetMsPerFrame_6FD457F8;
                        if (ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 < 10)
                        {
                            ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 10;
                        }
                        else if (ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 > 0x800)
                        {
                            ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 0x800;
                        }
                    }

                    ptGame->nLastUpdateSystemTimeMs = nSysTimeMs;
                }
                else
                {
                    ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 0x400;
                }

                GAME_UpdateProgress(ptGame);

                D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(ptGame->lpCriticalSection);
            }
        }
    }

    if (bQueryPerformance)
    {
        QueryPerformanceCounter(&aCounter[1]);
        aCounter[0].QuadPart = aCounter[1].QuadPart - aCounter[0].QuadPart;
    }
    else
    {
        aCounter[0].QuadPart = 0;
    }
    return aCounter[0].LowPart;
}

// 0x0052FD90
int __stdcall GAME_UpdateClients(int bForceUpdate1, int bForceUpdate2)
{
    D2LargeIntegerUnion aCounter[2];
    int bQueryPerformance = 0;
    QueryPerformanceCounter(&aCounter[0]);

    const unsigned long nTickCount = GetTickCount();
    if (!bForceUpdate1 && !bForceUpdate2)
    {
        if (nTickCount - dword_6FD45848 < 40)
        {
            return 0;
        }

        dword_6FD45848 = nTickCount;
    }

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs_6FD447F8[i];
        if (nGUID && nGUID != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(nGUID);
            if (pGame)
            {
                D2ClientStrc* pClient = pGame->pClientList;
                bQueryPerformance = 1;
                while (pClient)
                {
                    D2ClientStrc* pNextClient = pClient->pNext;
                    GAME_SendClientPackets(pGame, 1, pClient);
                    pClient = pNextClient;
                }

                if (!pGame->nClients)
                {
                    if (!pGame->nTickCountSinceNoClients)
                    {
                        pGame->nTickCountSinceNoClients = nTickCount;
                    }

                    if (nTickCount - pGame->nTickCountSinceNoClients > 300000 || pGame->dwGameFrame > 1500 && pGame->dwGameFrame < 7500)
                    {
                        GAME_LeaveGamesCriticalSection(pGame);
                        GAME_CloseGame(nGUID);
                    }
                    else
                    {
                        GAME_LeaveGamesCriticalSection(pGame);
                    }
                }
                else
                {
                    pGame->nTickCountSinceNoClients = 0;
                    GAME_LeaveGamesCriticalSection(pGame);
                }
            }
        }
    }

    if (bQueryPerformance)
    {
        QueryPerformanceCounter(&aCounter[1]);
        aCounter[0].QuadPart = aCounter[1].QuadPart - aCounter[0].QuadPart;
    }
    else
    {
        aCounter[0].QuadPart = 0;
    }
    return aCounter[0].LowPart;
}

// 0x0052FEE0
D2GameStrc* __fastcall GAME_GetGameByClientId(int nClientId)
{
    const int nGameGUID = SERVER_GetClientGameGUID(nClientId);

    D2GameStrc* pGame = GAME_LockGame(nGameGUID);
    if (!pGame)
    {
        return 0;
    }

    if (sub_005381C0(pGame, nClientId))
    {
        return pGame;
    }

    GAME_LeaveGamesCriticalSection(pGame);

    return 0;
}

// 0x0052FF20
void D2StormHashTableStrc::sub_0052FF20_GrowListArray()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = 2 * nOldCount;
    D2StormListAStrc tTempList;
    tTempList.ChangeLinkOffset(4);

    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.m_data[i].Head()) != 0)
            tTempList.LinkToTail(pNode);
    }

    m_slotlistarray.sub_00450110_SetCount(nNewCount);
    for (unsigned int i = 0; i < nNewCount; i++)
        m_slotlistarray.m_data[i].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;

    char* pNode;
    while ((pNode = tTempList.Head()) != 0)
        m_slotlistarray.m_data[((D2StormHashNodeStrc*)pNode)->m_hashval & m_slotmask].LinkToTail(pNode);
}

// 0x005300F0
int __stdcall sub_005300F0_RemoveClientById(int nClientId, int a2, int a3)
{
    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (pGame)
    {
        if (!sub_005381C0(pGame, nClientId))
        {
            GAME_LeaveGamesCriticalSection(pGame);
        }
        else
        {
            if (sub_005381C0(pGame, nClientId))
            {
                ClientRemoveFromGame(pGame, nClientId, 1);
            }

            D2_ASSERT(pGame->lpCriticalSection, 4196);
            LeaveCriticalSection(pGame->lpCriticalSection);
        }
    }
    return sub_0052B4F0(nClientId, a2, a3);
}

// 0x00530190
void __fastcall SrvJoinAct(int nClientId)
{
    D2ClientStrc* pClient;
    const int nGameGUID = SERVER_GetClientGameGUID(nClientId);
    D2GameStrc* pGame = GAME_LockGame(nGameGUID);
    if (pGame)
    {
        if (!sub_005381C0(pGame, nClientId))
        {
            GAME_LeaveGamesCriticalSection(pGame);
        }
        else
        {
            pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
            const int nErrorCode = sub_00539760(pClient, pGame, 1, 0, 0, 0);
            if (nErrorCode)
            {
                D2GAME_PACKETS_SendSystemError(nClientId, nErrorCode);
                ClientRemoveFromGame(pGame, nClientId, 1);
                sub_0052B4F0(nClientId, (int)".\\GAME\\Game.cpp", 0x672);
                GAME_LeaveGamesCriticalSection(pGame);
                return;
            }

            sub_0052C210_ClientEnterAct(pGame, pClient);
            sub_005394A0(pClient, CLIENTS_GetPlayerFromClient(pClient, 1), pGame, 0, 0, 0);
            CLIENTS_SetClientState(pClient, 3);
            GAME_LeaveGamesCriticalSection(pGame);
            GAME_LogMessage(6, "[JOIN 5] %d clientid, SrvJoinAct: Added to game.", nClientId);
            return;
        }
    }

    GAME_LogMessage(6, "[JOIN]  SrvJoinAct: No game found for client(%d)", nClientId);
}

// 0x00530270
void __fastcall SrvDisconnectClientById(int nClientId, int nEventType)
{
    if (!nClientId)
    {
        return;
    }

    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (!pGame)
    {
        return;
    }

    if (!sub_005381C0(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    SrvDisconnectClient(pGame, pClient, nEventType);
    GAME_LeaveGamesCriticalSection(pGame);
}

// 0x005302D0
int __stdcall GAME_DisconnectClientByName(const char* szClientName, int nEventType)
{
    const int nClientId = CLIENTS_GetClientIdByName(szClientName);
    if (!nClientId)
    {
        return 0;
    }

    SrvDisconnectClientById(nClientId, nEventType);
    return 1;
}

// 0x00530300
void __stdcall sub_00530300(int nClientId)
{
    if (!nClientId)
        return;

    const int nGUID = SERVER_GetClientGameGUID(nClientId);
    D2GameStrc* pGame = GAME_LockGame(nGUID);
    if (!pGame)
        return;

    if (!sub_005381C0(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    D2GSPacketSrv5A tPacket = {};
    tPacket.nHeader = 0x5A;
    tPacket.nType = 0;
    tPacket.nColor = 4;
    *(int*)tPacket.abParam = 0;
    tPacket.szText[16] = 0;
    SStrCopy(tPacket.szText, CLIENTS_GetName(pClient), 16);
    sub_6FC84D40(pGame, &tPacket);
    ClientRemoveFromGame(pGame, CLIENTS_GetClientId(pClient), 1);
    GAME_LeaveGamesCriticalSection(pGame);
}

// 0x005303D0
void __fastcall SrvEndGame(int nClientId, int bSendLeaveMessage)
{
    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (!pGame)
    {
        return;
    }

    if (!sub_005381C0(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    const unsigned int bOwner = CLIENT_IsGameOwner(pClient);
    if (bOwner || pGame->nGameType)
    {
        sub_0052CA10(pGame);
    }

    if (pClient)
    {
        while (1)
        {
            D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 5);
            sub_0052E260_SendRemainingSaveParts(pGame, pClient);
            D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 6);
            sub_0053B220_SendHeaderOnly0xB0(nClientId);
            GAME_SendClientPackets(pGame, 0, pClient);

            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nType = 3;
            packet5A.nColor = 4;
            *(int*)packet5A.abParam = 0;
            CLIENTS_CopyAccountNameToBuffer(pClient, &packet5A.szText[16]);
            packet5A.szText[31] = '\0';
            SStrCopy(packet5A.szText, CLIENTS_GetName(pClient), 16);
            ClientRemoveFromGame(pGame, nClientId, !bOwner);

            if (bSendLeaveMessage)
            {
                sub_6FC84D40(pGame, &packet5A);
            }

            if (!bOwner)
            {
                break;
            }

            pClient = sub_00539070_GetClientList(pGame);
            if (!pClient)
            {
                break;
            }

            nClientId = CLIENTS_GetClientId(pClient);
        }
    }

    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
    LeaveCriticalSection(pGame->lpCriticalSection);

    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        Sleep(100);
    }

    D2NET_10016(nClientId);
}

// 0x00530590
void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* game, D2ClientStrc* client)
{
    D2ClientStrc* owner = 0;
    GAME_ForEachIngameClient(game, sub_0052CBB0_FindOwnerClient, &owner);
    if (!owner)
    {
        if (!client)
        {
            D2ClientStrc* first = 0;
            GAME_ForEachIngameClient(game, sub_0052CBD0_FindFirstClient, &first);
            if (first)
            {
                SrvEndGame(CLIENTS_GetClientId(first), 0);
            }
            return;
        }
        SrvEndGame(CLIENTS_GetClientId(client), 0);
        return;
    }
    SrvEndGame(CLIENTS_GetClientId(owner), 0);
}

// 0x00530600
int D2StormHashTable00530600Strc::sub_00530600(unsigned int nSlot)
{
    D2StormSlotList00530600Strc* const& pSlotLists = m_slotlistarray.m_data;
    if (m_slotmask >= 0x3FF)
    {
        return 0;
    }

    if (m_fullnessIndicator > 3)
    {
        m_fullnessIndicator -= 3;
    }
    else
    {
        m_fullnessIndicator = 0;
    }

    for (char* pNode = pSlotLists[nSlot].m_terminator.Next(); (int)pNode > 0; )
    {
        ++m_fullnessIndicator;
        if (m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            sub_0052FF20_GrowListArray();
            return 1;
        }

        D2StormSlotList00530600Strc* pList = &pSlotLists[nSlot];
        D2StormSlotLink00530600Strc* pLink = pNode ? (D2StormSlotLink00530600Strc*)(pNode + pList->m_linkoffset) : &pList->m_terminator;
        pNode = pLink->m_next;
    }

    return 0;
}

// 0x00530690
int __stdcall GAME_Initialize()
{
    SRegLoadValue("Diablo II", "PlayerPos", 0, &gdwPlayerPos_00883D4C);
    for (int i = 0; i < 1024; ++i)
    {
        gnGamesGUIDs_6FD447F8[i] = 0;
    }
    InitializeCriticalSection(&gCriticalSection_6FD45800);
    CLIENTS_Initialize();
    sub_0052B5C0_SetServerHandler((D2NET_Unk_Callback)sub_005300F0_RemoveClientById);
    SUNITPROXY_FillGlobalItemCache();
    return 1;
}

// 0x005306E0
int __stdcall SrvRecvDatabaseCharacter(int nClientId, const unsigned char* pSaveData, unsigned short nSaveSize, unsigned short nTotalSize, int nResult, int a6, D2FileTimeStrc* pSaveCreationTimestamp, int nCharSaveTransactionToken)
{
    GAME_LogMessage(6, "[JOIN 3] %d clientid, %d csresult - Recv'ed char from CS", nClientId, nResult);

    if (nTotalSize && !CLIENTS_AttachSaveFile(nClientId, pSaveData, nSaveSize, nTotalSize, nResult == 0, 1, a6))
    {
        GAME_LogMessage(6, "[JOIN]  SrvRecvDatabaseCharacter: Didn't recv full char from db - CSResult(%d), ClientID(%d)", nResult, nClientId);
        return 1;
    }

    if (nResult)
    {
        GAME_LogMessage(6, "[JOIN]  SrvRecvDatabaseCharacter: Did not recv CSDATA_SUCCESS - CSResult(%d), ClientID(%d)", nResult, nClientId);
        sub_005300F0_RemoveClientById(nClientId, (int)".\\GAME\\Game.cpp", 0x407);
        return 0;
    }

    if (!nTotalSize)
    {
        sub_005300F0_RemoveClientById(nClientId, (int)".\\GAME\\Game.cpp", 0x414);
        return 0;
    }

    D2GameStrc* pGame = sub_0052FEE0_LockGameByClientId(nClientId);
    if (!pGame)
    {
        return 0;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    if (!pClient)
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return 0;
    }

    if (pClient->nCharSaveTransactionToken != nCharSaveTransactionToken)
    {
        GAME_LeaveGamesCriticalSection(pGame);
        sub_005300F0_RemoveClientById(nClientId, (int)".\\GAME\\Game.cpp", 0x479);
        return 0;
    }

    pClient->nSaveCreationTimestamp = *pSaveCreationTimestamp;
    GAME_LeaveGamesCriticalSection(pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
    return nTotalSize;
}

// 0x00530820
D2GameStrc* D2GameDataTableStrc::sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags)
{
    unsigned int nSlot = nHashVal & m_hashmask;
    if (sub_00530600(nSlot))
    {
        nSlot = nHashVal & m_hashmask;
    }

    D2GameHashListStrc* pList = &m_slotlistarray[nSlot];
    D2GameStrc* pNode = sub_NewNode(pList, nExtraBytes, nFlags);

    D2GameHashLinkStrc* pLink;
    if (pNode)
    {
        pLink = (D2GameHashLinkStrc*)((char*)pNode + m_linkoffset);
    }
    else
    {
        pLink = &m_terminator;
    }

    pLink->Unlink();

    D2GameHashLinkStrc* pPrev = m_terminator.m_prevlink;
    pLink->m_prevlink = pPrev;
    pLink->m_next = pPrev->m_next;
    pPrev->m_next = pNode;
    m_terminator.m_prevlink = pLink;

    pNode->dwHashValue = nHashVal;
    return pNode;
}

// 0x005308C0
D2GameStrc* D2GameDataTableStrc::sub_005308C0_NewHandle(unsigned int* pHandle)
{
    const unsigned int nHandle = sub_0052E6D0_GenerateHandle();
    *pHandle = nHandle;
    return sub_00530820_New(nHandle, (HASHKEY_NONE*)&f_44, 0, 0);
}

// 0x005308F0
D2GameStrc* D2GameDataTableStrc::sub_005308F0_NewLock(unsigned int* pHandle, int* pLockedHandle)
{
    EnterCriticalSection(&f_50);
    *pLockedHandle = 1;
    const unsigned int nHandle = sub_0052E6D0_GenerateHandle();
    *pHandle = nHandle;
    return sub_00530820_New(nHandle, (HASHKEY_NONE*)&f_44, 0, 0);
}

inline unsigned __int64 sub_I08_RollGameSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// build: context sub_0052C280_InitGameSeed
static void sub_0052C280_InitGameSeed(D2GameStrc* pGame)
{
    if (gnInitSeed_00731004 == -1)
    {
        pGame->InitSeed = 0;
        D2LargeIntegerUnion tCount;
        QueryPerformanceCounter(&tCount);
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, SEED_GetRandomValue(tCount.LowPart));
        pGame->dwInitSeed = SEED_GetRandomValue((int)sub_I08_RollGameSeed(&pGame->pGameSeed));
    }
    else
    {
        pGame->InitSeed = 1;
        pGame->dwInitSeed = gnInitSeed_00731004;
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, gnInitSeed_00731004);
    }
}

// 0x00530930
int __stdcall SrvCreateNewEmptyGame(char* szGameName, const char* szPassword, const char* szGameDescription, unsigned int nFlags, unsigned char nArenaTemplate, unsigned char nMaxLevelDifference, unsigned char nMaxPlayers, unsigned short* pGameId)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return 0;
    }

    const unsigned short nGameId = sub_0052C170_AllocGameId();
    if (!nGameId)
    {
        return 0;
    }

    D2GameDataTableStrc* pGameDataTbl = gpGameDataTbl_6FD45818;
    EnterCriticalSection(&pGameDataTbl->f_50);
    const unsigned int hGame = pGameDataTbl->sub_0052E6D0_GenerateHandle();
    D2GameStrc* pGame = pGameDataTbl->sub_00530820_New(hGame, (HASHKEY_NONE*)&pGameDataTbl->f_44, 0, 0);
    LeaveCriticalSection(&gpGameDataTbl_6FD45818->f_50);

    D2_ASSERT(pGame, 793);
    pGame->lpCriticalSection = (D2CriticalSectionStrc*)FOG_AllocPool(0, sizeof(D2CriticalSectionStrc), ".\\GAME\\Game.cpp", 796, 0);
    InitializeCriticalSection(pGame->lpCriticalSection);

    sub_00409DD0_InitPoolSystem(&pGame->pMemoryPool, szGameName, 0x8000, 0x1000);

    memset(pGame->pUnitList[0], 0, sizeof(pGame->pUnitList[0]));
    memset(pGame->pUnitList[1], 0, sizeof(pGame->pUnitList[1]));
    memset(pGame->pUnitList[2], 0, sizeof(pGame->pUnitList[2]));
    memset(pGame->pUnitList[3], 0, sizeof(pGame->pUnitList[3]));
    memset(pGame->pUnitList[4], 0, sizeof(pGame->pUnitList[4]));
    memset(pGame->dwUniqueFlags, 0, sizeof(pGame->dwUniqueFlags));

    pGame->nGameId = nGameId;
    pGame->unk0x24 = 1;

    GAME_ResolveGameNameConflict(pGame, szGameName, 0);
    SStrCopy(pGame->szGamePassword, szPassword, 16);
    SStrCopy(pGame->szGameDesc, szGameDescription, 32);

    pGame->nArenaTemplate = nArenaTemplate;
    pGame->nMaxLevelDifference = nMaxLevelDifference;
    pGame->nMaxPlayers = nMaxPlayers;

    if (nFlags & 0x100000)
    {
        pGame->bExpansion = 1;
    }
    else
    {
        pGame->bExpansion = 0;
    }

    pGame->wItemFormat = pGame->bExpansion != 0 ? 101 : 2;
    pGame->dwGameType = (nFlags & 0x200000) != 0;

    pGame->dwLastUsedUnitGUID[0] = 0;
    pGame->dwLastUsedUnitGUID[1] = 0;
    pGame->dwLastUsedUnitGUID[2] = 0;
    pGame->dwLastUsedUnitGUID[3] = 0;
    pGame->dwLastUsedUnitGUID[4] = 0;
    pGame->dwLastUsedUnitGUID[5] = 0;
    pGame->nUberFields[0] = 0;
    pGame->nUberFields[1] = 0;
    pGame->nUberFields[2] = 0;
    pGame->nUberFields[3] = 0;
    pGame->nUberFields[4] = 0;
    pGame->nUberFields[5] = 0;
    pGame->nUberFields[6] = 0;
    pGame->nUberFields[7] = 0;

    pGame->nDifficulty = (nFlags >> 12) & 7;

    sub_0052C280_InitGameSeed(pGame);
    sub_00541470_InitializeQueue(pGame);
    ARENA_AllocArena(pGame, 0, nFlags, 0);
    sub_005379A0_ResetClient((D2ClientStrc*)pGame);
    PARTY_AllocPartyControl(pGame);
    MONSTERREGION_InitializeForGame(pGame);
    pGame->dwObjSeed = sub_00546C60_AllocObjectControl(pGame);
    sub_00536070_InitNpcControl(pGame);
    sub_00545D80_QuestInit(pGame);

    sub_0052C110(hGame, nGameId);

    pGame->nSyncTimer = sub_00410A80_GetTimeSeconds();
    if (pGame->nSyncTimer <= 1)
    {
        pGame->nSyncTimer = 2;
    }

    void* pTask = FOG_Alloc(0x14, ".\\GAME\\Game.cpp", 922, 0);
    sub_00564A00_QueueGame(pTask, 0, hGame);
    pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = GetTickCount();
    *pGameId = pGame->nGameId;
    return 1;
}

// 0x00530BF0
void __fastcall sSrvSendGameInit(int nClientId, char* szGameName, unsigned char nGameType, unsigned char nCharTemplate, const char* szClientName, int nArena, unsigned int nFlags, int nArenaTemplate, int nUnused1, int nUnused2, unsigned char nDifficulty, unsigned char nLocale, int nUnused3, int nUnused4)
{
    if (!gpGameDataTbl_6FD45818)
    {
        return;
    }

    D2GameDataTableStrc* pGameDataTbl = gpGameDataTbl_6FD45818;
    EnterCriticalSection(&pGameDataTbl->f_50);
    const unsigned int hGame = pGameDataTbl->sub_0052E6D0_GenerateHandle();
    D2GameStrc* pGame = pGameDataTbl->sub_00530820_New(hGame, (HASHKEY_NONE*)&pGameDataTbl->f_44, 0, 0);
    LeaveCriticalSection(&gpGameDataTbl_6FD45818->f_50);

    if (!pGame)
    {
        return;
    }

    pGame->lpCriticalSection = (D2CriticalSectionStrc*)FOG_AllocPool(0, sizeof(D2CriticalSectionStrc), ".\\GAME\\Game.cpp", 1241, 0);
    InitializeCriticalSection(pGame->lpCriticalSection);

    pGame->pMemoryPool = 0;

    memset(pGame->pUnitList[0], 0, sizeof(pGame->pUnitList[0]));
    memset(pGame->pUnitList[1], 0, sizeof(pGame->pUnitList[1]));
    memset(pGame->pUnitList[2], 0, sizeof(pGame->pUnitList[2]));
    memset(pGame->pUnitList[3], 0, sizeof(pGame->pUnitList[3]));
    memset(pGame->pUnitList[4], 0, sizeof(pGame->pUnitList[4]));
    memset(pGame->dwUniqueFlags, 0, sizeof(pGame->dwUniqueFlags));

    pGame->unk0x24 = 1;

    pGame->nGameId = sub_0052C170_AllocGameId();
    GAME_ResolveGameNameConflict(pGame, szGameName, nClientId);
    pGame->nGameType = nGameType;
    pGame->dwLastUsedUnitGUID[0] = 0;
    pGame->dwLastUsedUnitGUID[1] = 0;
    pGame->dwLastUsedUnitGUID[2] = 0;
    pGame->dwLastUsedUnitGUID[3] = 0;
    pGame->dwLastUsedUnitGUID[4] = 0;
    pGame->dwLastUsedUnitGUID[5] = 0;
    pGame->nDifficulty = nDifficulty;
    pGame->nArenaTemplate = nArenaTemplate;

    if (nFlags & 0x100000)
    {
        pGame->bExpansion = 1;
    }
    else
    {
        pGame->bExpansion = 0;
    }

    pGame->wItemFormat = pGame->bExpansion != 0 ? 101 : 2;
    pGame->dwGameType = (nFlags & 0x200000) != 0;

    sub_0052C280_InitGameSeed(pGame);
    sub_00541470_InitializeQueue(pGame);
    ARENA_AllocArena(pGame, nArena, nFlags, nArenaTemplate);
    sub_005379A0_ResetClient((D2ClientStrc*)pGame);

    D2ClientStrc* pClient = ClientAddToGame(pGame, nClientId, nCharTemplate, szClientName, &gszEmptyAssertText, 0, nLocale, nUnused3, nUnused4);
    SERVER_SetClientGameGUID(nClientId, hGame);

    if (pGame->nGameType == 1)
    {
        sub_00539000(pClient);
    }

    PARTY_AllocPartyControl(pGame);
    MONSTERREGION_InitializeForGame(pGame);
    pGame->dwObjSeed = sub_00546C60_AllocObjectControl(pGame);
    sub_00536070_InitNpcControl(pGame);
    sub_00545D80_QuestInit(pGame);

    sub_0052C110(hGame, pGame->nGameId);

    D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(pClient, 1, pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0);
    CLIENTS_SetClientState(pClient, 1);
    CLIENTS_SetActNo(pClient, gnAct_6FD45824);

    pGame->nSyncTimer = sub_00410A80_GetTimeSeconds();
    if (pGame->nSyncTimer <= 1)
    {
        pGame->nSyncTimer = 2;
    }

    void* pTask = FOG_Alloc(0x14, ".\\GAME\\Game.cpp", 1371, 0);
    sub_00564A00_QueueGame(pTask, 0, hGame);

    D2_ASSERT(!gpD2EventCallbackTable_6FD45830 || !gpD2EventCallbackTable_6FD45830->pfGetDatabaseCharacter, 1378);

    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
}

// 0x00530EA0
void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case 14:
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case 15:
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x00531D60
void __fastcall sub_00531D60_ByteToHex(char* szOut, unsigned char nByte)
{
    char szHex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    szOut[0] = szHex[nByte >> 4];
    szOut[1] = szHex[nByte & 0xF];
}

// 0x00531DE0
char* __fastcall sub_00531DE0_BytesToHexString(char* szOut, const unsigned char* pData, int nLength)
{
    if (nLength <= 0)
    {
        return 0;
    }

    *szOut = '0';
    ++szOut;
    *szOut = 'x';
    ++szOut;
    do
    {
        sub_00531D60_ByteToHex(szOut, *pData);
        szOut += 2;
        ++pData;
        --nLength;
    }
    while (nLength);

    *szOut = 0;
    return szOut;
}

// 0x00532E70
void __stdcall sub_00532E70_ForwardIfSet(int a1, int a2, unsigned char a3)
{
    if (a3)
    {
        sub_0056DEB0(a1, a2, a3, 1);
    }
}

// 0x00532E90
int __fastcall sub_6FC8AEC0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned char* pSection, int a5, int a6, int* pSkillCount)
{
    *pSkillCount = 0;

    if (*(unsigned short*)pSection != 0x6669)
        return 5;

    const unsigned char* pData = pSection + 2;
    const int nClassId = CLIENTS_GetClassId(pClient);
    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        if (pData[i])
        {
            D2GAME_SetSkills_6FD14C60(pUnit, nSkillId, pData[i], 1);
        }
    }

    sub_0053C5D0(pClient, pUnit);

    const int nCount = SKILLS_GetPlayerSkillCount(nClassId) + 2;
    sub_6FD14C30(pUnit);
    *pSkillCount = nCount;
    return 0;
}

// 0x00534A50
void __fastcall PLAYER_RemoveAllPlayers(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pPlayer = pGame->pUnitList[UNIT_PLAYER][i];
        while (pPlayer)
        {
            D2UnitStrc* pCurrent = pPlayer;
            pPlayer = SUNIT_GetNextUnitFromList(pPlayer);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

// 0x00534AB0
void __fastcall sub_00534AB0_ClearTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget == SUNIT_GetTargetUnit(pGame, pUnit))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
}

// 0x00534AD0
void __fastcall sub_00534AD0_ResetModeAndEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    sub_6FC817D0(pGame, pUnit, 0, PLRMODE_NEUTRAL, nX, nY, 1);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_DELAYEDPORTAL, pGame->dwGameFrame + 250, 0, 0);
}

// 0x005356F0
void __fastcall sub_005356F0_CountPlayersInLevelCb(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    D2UnitProxyArgStrc* pCount = (D2UnitProxyArgStrc*)pArg;
    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == pCount->nLevelId && pUnit && pUnit->dwAnimMode != PLRMODE_DEATH && pUnit->dwAnimMode != PLRMODE_DEAD)
    {
        ++pCount->nCounter;
    }
}

// 0x00535730
int __fastcall sub_00535730_CountPlayersInLevel(D2GameStrc* pGame, int nLevelId)
{
    D2UnitProxyArgStrc arg = {};
    arg.nLevelId = nLevelId;
    SUNIT_IterateLivingPlayers(pGame, sub_005356F0_CountPlayersInLevelCb, &arg);
    return arg.nCounter;
}

// 0x00535760
void __fastcall PLAYER_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingPlayers)
{
    if (!SUNIT_IsDead(pUnit))
    {
        ++*((int*)pLivingPlayers);
    }
}

// 0x00535790
int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame)
{
    int nLivingPlayers = 0;
    SUNIT_IterateLivingPlayers(pGame, PLAYER_CountLivingPlayers, &nLivingPlayers);

    switch (pGame->nGameType)
    {
    case 1:
    case 2:
    case 3:
        if (gnVirtualPlayerCount_6FD4DC1C > nLivingPlayers)
        {
            return gnVirtualPlayerCount_6FD4DC1C;
        }
        break;
    }

    return nLivingPlayers;
}

// 0x00535AF0
void __fastcall sub_00535AF0_RosterFlagCb(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2RosterIterateStrc* pRosterIterate = (D2RosterIterateStrc*)pArgs;
    if (PLAYERLIST_CheckFlag(pRosterIterate->pUnit, pUnit, 8))
    {
        pRosterIterate->bFlag = 1;
    }
}

// 0x00535B50
void __fastcall sub_00535B50_RosterFlagCb2(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2RosterIterateStrc* pRosterIterate = (D2RosterIterateStrc*)pArgs;
    if (PLAYERLIST_CheckFlag(pUnit, pRosterIterate->pUnit, 8))
    {
        pRosterIterate->bFlag = 1;
    }
}

// 0x00535B80
int __fastcall sub_00535B80_IteratePlayersRoster(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pGame || !pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2RosterIterateStrc rosterIterate = {};
    rosterIterate.bFlag = 0;
    rosterIterate.pUnit = pUnit;
    SUNIT_IterateLivingPlayers(pGame, sub_00535B50_RosterFlagCb2, &rosterIterate);
    return rosterIterate.bFlag;
}

// 0x00535EA0
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex)
{
    D2NpcRecordStrc* pRecords = pGame->pNpcControl->pFirstRecord;
    for (*pIndex = 0; *pIndex < MAX_NPC_RECORDS; ++*pIndex)
    {
        if (pRecords[*pIndex].nNPC == nNpcClassId)
        {
            return &pRecords[*pIndex];
        }
    }

    D2_ASSERT(nNpcClassId, 114);
    return 0;
}

// 0x00535F10
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex)
{
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, pIndex);
}

// 0x00536820
void __fastcall SUNITPROXY_CountPlayersInLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    D2UnitProxyArgStrc* pUnitProxyArg = (D2UnitProxyArgStrc*)pArg;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && pUnitProxyArg->nLevelId == DUNGEON_GetLevelIdFromRoom(pRoom))
    {
        ++pUnitProxyArg->nCounter;
    }
}

// 0x00536B20
D2InventoryStrc* __fastcall SUNITPROXY_GetNpcInventory(D2GameStrc* pGame, int nNpc)
{
    int nUnused;
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, nNpc, &nUnused)->pInventory;
}

// 0x00536C50
D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nUnused);
    if (!pNpcRecord || !pNpcRecord->bGambleInit)
    {
        return 0;
    }

    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
    {
        if (pGamble->dwGUID == nPlayerGUID)
        {
            return pGamble->pInventory;
        }
    }

    return 0;
}

static D2MonStatsTxt* SUNITPROXY_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x00536F80
void __fastcall SUNITPROXY_FillGlobalItemCache()
{
    const int nRecordCount = sgptDataTables->nMonStatsTxtRecordCount;
    for (int i = 0; i < nRecordCount; ++i)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = SUNITPROXY_GetMonStatsTxtRecordInline(i);
        int bInteract = 0;
        if (pMonStatsTxtRecord)
            bInteract = pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7];
        if (bInteract)
        {
            switch (i)
            {
            case MONSTER_HALBU:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(12);
                break;
            case MONSTER_ALKOR:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(7);
                break;
            case MONSTER_CHARSI:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(2);
                break;
            case MONSTER_FARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(3);
                break;
            case MONSTER_ASHEARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(10);
                break;
            case MONSTER_HRATLI:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(6);
                break;
            case MONSTER_AKARA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(0);
                break;
            case MONSTER_DROGNAN:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(5);
                break;
            case MONSTER_LYSANDER:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(4);
                break;
            case MONSTER_ORMUS:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(8);
                break;
            case MONSTER_GHEED:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(1);
                break;
            case MONSTER_ELZIX:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(9);
                break;
            case MONSTER_JAMELLA:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(13);
                break;
            case MONSTER_DREHYA:
            case MONSTER_NIHLATHAK:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(16);
                break;
            case MONSTER_MALAH:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(14);
                break;
            case MONSTER_LARZUK:
                SUNITPROXY_FillIGlobaltemCacheRecordForNpc(15);
                break;
            default:
                break;
            }
        }
    }
}

// 0x005384E0
void __fastcall sub_005384E0_RemoveUnitIfNotAdjacent(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(pClient, 2131);

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2_ASSERT(pClientRoom, 2137);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

    unsigned int i = 0;
    for (; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pRoom = ppRoomList[i];
        D2_ASSERT(pRoom, 2142);
        if (pUnitRoom == pRoom)
        {
            break;
        }
    }

    if (i >= nNumRooms)
    {
        sub_00571600(pUnit, pClient);
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

// 0x0053ABE0
void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    D2GAME_PACKETS_SendPacket0x03_6FC3C810(pClient, 3, nAct, pGame->dwInitSeed, pGame->dwObjSeed, DUNGEON_GetTownLevelIdFromAct(pGame->pAct[nAct]));

    int nCycleIndex;
    int nTicks;
    int nEclipse;
    ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(pGame->pAct[nAct], &nCycleIndex, &nTicks, &nEclipse);

    D2GSPacketSrv53 packet53;
    packet53.nHeader = 0x53;
    *(int*)&packet53.nCycleIndex = nCycleIndex;
    *(int*)&packet53.nTicks = nTicks;
    packet53.nEclipse = nEclipse;
    D2GAME_SendPacket0x53_6FC3DF50(pClient, &packet53);
}

// 0x0053B000
void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        D2DrlgActStrc* pAct = pGame->pAct[i];
        if (pAct && pAct->bHasPendingUnitListUpdates)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
            {
                for (D2UnitStrc* pUnit = pRoom->pUnitUpdate; pUnit; pUnit = pUnit->pChangeNextUnit)
                {
                    sub_00553220(pGame, pUnit);
                }

                UNITROOM_ClearUpdateQueue(pRoom);
            }

            pGame->pAct[i]->bHasPendingUnitListUpdates = 0;
        }
    }

    sub_0053FAE0(pGame);
}

// 0x0053DE20
void __fastcall sub_0053DE20_SendPacket0x8CToAllPlayers(D2GameStrc* pGame, int dwPlayerId1, int dwPlayerId2, short wRelationState)
{
    D2GSPacketSrv8C packet8C;
    packet8C.nHeader = 0x8C;
    *(int*)&packet8C.dwPlayerGUID1 = dwPlayerId1;
    *(int*)&packet8C.dwPlayerGUID2 = dwPlayerId2;
    *(short*)&packet8C.nFlags = wRelationState;
    SUNIT_IterateLivingPlayers(pGame, sub_0053DDF0, &packet8C);
}

// 0x0053DF80
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign)
{
    D2GSPacketSrv8E packet8E;
    packet8E.nHeader = 0x8E;
    *(int*)&packet8E.dwPlayerGUID = nUnitId;
    *(int*)&packet8E.dwCorpseGUID = nCorpseId;
    packet8E.nType = bAssign;
    SUNIT_IterateLivingPlayers(pGame, sub_0053DF50, &packet8E);
}

// 0x005404C0
void __fastcall sub_005404C0_AddLivingMemberLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    if (!SUNIT_IsDead(pUnit))
        *(int*)pArgs += STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
}

// 0x005404F0
void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits)
{
    if (pUnit && !SUNIT_IsDead(pUnit))
    {
        ++*((int*)pLivingUnits);
    }
}

// 0x00543E10
void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;
    ++pQuestControl->dwTick;
    if (pQuestControl->dwTick == -1)
    {
        for (D2QuestTimerStrc* i = pQuestControl->pTimer; i; i = i->pNext)
            i->dwTicks = -1 - i->dwTicks;
    }
    pQuestControl->bExecuting = 1;
    D2QuestTimerStrc* pTimer = pQuestControl->pTimer;
    D2QuestTimerStrc* pPrev = 0;
    while (pTimer)
    {
        D2QuestTimerStrc* pNext = pTimer->pNext;
        if (pTimer->dwTicks < pQuestControl->dwTick)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)pTimer->pfUpdate), 0x3F0);
            if (pTimer->pfUpdate(pGame, pTimer->pQuest) == 1)
            {
                if (!pPrev)
                {
                    pQuestControl->pTimer = pTimer->pNext;
                    FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x3F7, 0);
                    pTimer = 0;
                }
                else
                {
                    pPrev->pNext = pTimer->pNext;
                    FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x3FE, 0);
                    pTimer = pPrev;
                }
            }
            else
            {
                pTimer->dwTicks = pQuestControl->dwTick + pTimer->dwTimeout;
            }
        }
        pPrev = pTimer;
        pTimer = pNext;
    }
    pQuestControl->bExecuting = 0;
}

// 0x00546E90
void __fastcall OBJRGN_FreeObjectControl(D2GameStrc* ptGame)
{
    D2_ASSERT(ptGame, 0xB6);
    D2ObjectControlStrc* pObjectControl = ptGame->pObjectControl;
    if (!pObjectControl)
        return;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = pObjectControl->pObjectRoomCoord;
    while (pObjectRoomCoord)
    {
        D2ObjectRoomCoordStrc* pNext = pObjectRoomCoord->pNext;
        FOG_FreeServerMemory(ptGame->pMemoryPool, pObjectRoomCoord, ".\\OBJECTS\\objrgn.cpp", 0xC1, 0);
        pObjectRoomCoord = pNext;
    }
    pObjectControl->pObjectRoomCoord = 0;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
        FOG_FreeServerMemory(ptGame->pMemoryPool, pObjectControl->pObjectRegion[i], ".\\OBJECTS\\objrgn.cpp", 0xE2, 0);
    for (int i = 0; i < 8; ++i)
    {
        if (pObjectControl->pShrineSubTypeIds[i])
            FOG_FreeServerMemory(ptGame->pMemoryPool, pObjectControl->pShrineSubTypeIds[i], ".\\OBJECTS\\objrgn.cpp", 0xE8, 0);
    }
    FOG_FreeServerMemory(ptGame->pMemoryPool, ptGame->pObjectControl, ".\\OBJECTS\\objrgn.cpp", 0xEC, 0);
}

// 0x00547210
void __fastcall OBJECTS_InitFunction17_Waypoint(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = pOp->pGame->pObjectControl;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = pObjectControl->pObjectRoomCoord;
    while (pObjectRoomCoord)
    {
        if (pObjectRoomCoord->pRoom == pOp->pRoom
            || (pOp->pRoom && pObjectRoomCoord->nX >= pOp->pRoom->tCoords.nSubtileX && pObjectRoomCoord->nX < pOp->pRoom->tCoords.nSubtileX + pOp->pRoom->tCoords.nSubtileWidth
                && pObjectRoomCoord->nY >= pOp->pRoom->tCoords.nSubtileY && pObjectRoomCoord->nY < pOp->pRoom->tCoords.nSubtileY + pOp->pRoom->tCoords.nSubtileHeight))
        {
            if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
            {
                UNITS_ChangeAnimMode(pOp->pObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);
                EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
            }
            FOG_FreeServerMemory(pOp->pGame->pMemoryPool, pObjectRoomCoord, ".\\OBJECTS\\objrgn.cpp", 0x19B, 0);
            pObjectControl->pObjectRoomCoord = 0;
            return;
        }
        pObjectRoomCoord = pObjectRoomCoord->pNext;
    }
    if (DUNGEON_IsRoomInTown(pOp->pRoom))
        UNITS_ChangeAnimMode(pOp->pObject, 2);
}

// 0x00548180
void __fastcall sub_6FC81E10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    if (pUnit != CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
        {
            const int nTargetGUID = pTarget->dwUnitId;
            const int nTargetType = pTarget->dwUnitType;
            const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
            D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(pClient, 0x10, 0, nUnitGUID, (unsigned char)stru_6FD30708[nAnimMode].field_8, nTargetType, nTargetGUID, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        }
        else
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            int nY;
            if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
                nY = pUnit->pStaticPath->tGameCoords.nY;
            else
                nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
            int nX;
            if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
                nX = pUnit->pStaticPath->tGameCoords.nX;
            else
                nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
            const int nUnitId = pUnit->dwUnitId;
            D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(pClient, 0x0F, 0, nUnitId, (unsigned char)stru_6FD30708[nAnimMode].field_4, D2COMMON_10175_PathGetFirstPointX(pPath), D2COMMON_10176_PathGetFirstPointY(pPath), 0, nX, nY);
        }
    }
}

// 0x00549FA0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0B_6FC83EE0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return nSize != 1 ? 3 : 0;
}

// 0x0054AA90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x13_InteractWithEntity_6FC84D70(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = *(unsigned int*)((char*)pPacket + 1);
    const int nUnitGUID = *(int*)((char*)pPacket + 5);
    if (nUnitType >= 6)
    {
        return 2;
    }

    return sub_6FC828D0(pUnit, nUnitType, nUnitGUID, 0, pGame);
}

// 0x0054BBA0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x34_IdentifyItemsWithNpc_6FC86BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 5)
    {
        return 3;
    }

    D2GAME_NPC_IdentifyAllItems_6FCC9C90(pGame, pUnit, *(int*)((char*)pPacket + 1));
    return 0;
}

// 0x0054BC00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x62_ResurrectMerc_6FC86C00(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (nSize != 5)
    {
        return 3;
    }

    D2GAME_NPC_ResurrectMerc_6FCC9350(pGame, pUnit, *(int*)((char*)pPacket + 1));
    return 0;
}

// 0x0054C590
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x48_TurnOffBusyState_6FC87E20(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!UNITS_GetPlayerData(pUnit)->bBusy)
    {
        return 2;
    }

    PLAYER_ResetBusyState(pUnit);
    return 0;
}

// 0x0054C690
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4D_PlayNpcMessage_6FC880A0(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }

    const int nMonsterId = *(unsigned short*)((char*)pPacket + 1);
    if (nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 2;
    }

    PLRINTRO_MaskNpcIntroFlag(pGame, pUnit, nMonsterId);
    return 0;
}

#include "gen/data/Source/D2Game/GAME/Game.inc"
