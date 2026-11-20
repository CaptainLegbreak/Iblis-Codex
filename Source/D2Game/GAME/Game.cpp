#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"

#pragma intrinsic(_ReadWriteBarrier)

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define MAX_MSG_SIZE 516
#define PCLASS_AMAZON 0
#define PCLASS_SORCERESS 1
#define PCLASS_NECROMANCER 2
#define PCLASS_BARBARIAN 4
#define PCLASS_DRUID 5
#define PCLASS_ASSASSIN 6
#define UNIT_PLAYER 0

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


struct D2ActiveRoomStrc
{
    char unk0x00[0x34];
    unsigned int dwFlags;
};

struct D2FileTimeStrc { unsigned int dwLowDateTime; unsigned int dwHighDateTime; };

struct D2ClientStrc
{
    int dwClientId;
    int dwClientState;
    unsigned char unk_08[0x188];
    D2FileTimeStrc nSaveCreationTimestamp;
    char unk198[0x310];
    D2ClientStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x18];
    D2CriticalSectionStrc* lpCriticalSection;
    D2PoolSystemStrc* pMemoryPool;
    unsigned char unk_20[0x8];
    unsigned short nGameId;
    char szGameName[16];
    unsigned char unk_3A[0x36];
    int bExpansion;
    int dwGameType;
    char unk78[0x10];
    D2ClientStrc* pClientList;
    unsigned short nClients;
    unsigned char unk_8E[0x2];
    int dwLastUsedUnitGUID[6];
    int dwGameFrame;
    unsigned char unk_AC[0x10];
    D2DrlgActStrc* pAct[NUM_ACTS];
    char unk0xD0[0x20];
    D2MonsterRegionStrc* pMonReg[1024];
    unsigned char unk_10F0[0x30];
    D2UnitStrc* pUnitList[5][128];
    unsigned char unk_1B20[0x298];
    unsigned int nLastUpdateSystemTimeMs;
    unsigned int nCreationTimeMs_Or_CPUTargetRatioFP10;
};

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
extern D2CriticalSectionStrc gCriticalSection_6FD45800; // 0x00882D18
extern D2GameStrc* gpGame_6FD457FC; // 0x00882D34
extern int gnGamesGUIDs_6FD447F8[1024]; // 0x00882D38
void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc*, D2UnitStrc*, D2ClientStrc*); // 0x0053C940
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc*); // 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc*); // 0x0063D610
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc*); // 0x0063D630
void __fastcall D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(D2ClientStrc*, int, int, unsigned char); // 0x0053DFB0
void __fastcall ARENA_SendScoresToClient(D2GameStrc*, D2ClientStrc*); // 0x0053FC70
int __fastcall CLIENTS_CheckState(int nClientId, int nState); // 0x00538930
int __fastcall sub_6FC33EA0(int nClientId, char* szName); // 0x00538B70

typedef int (__stdcall* FARPROC)();

typedef const char* (__stdcall* FnLoadComplete)();

typedef void (__fastcall* FnUpdateCharacterLadder)(const char*, int, int, unsigned __int64, unsigned int, D2FileTimeStrc*);

struct D2ServerCallbackFunctions
{
    void (__fastcall* pfCloseGame)(int nGameId, int nProgramId, int nLastUnitGUID, int nSeconds);
    void* pfLeaveGame;
    void* pfGetDatabaseCharacter;
    void* pfSaveDatabaseCharacter;
    void* pfServerLogMessage;
    void* pfEnterGame;
    int (__fastcall* pfFindPlayerToken)(const char* szClientName, int nTokenId, int nGameId, char* pszInOutAccountName, int* pOutCharSaveTransactionToken, int* a6, int* a7, int* a8, int* a9);
    unsigned char unk_1C[0xC];
    FnUpdateCharacterLadder pfUpdateCharacterLadder;
    unsigned char unk_2C[0x10];
    FnLoadComplete pfLoadComplete;
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId); // 0x0052C060
int __fastcall sub_6FC33F90(const char* szName, char* szGameName); // 0x00538C60
int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize); // 0x0053EFC0
extern D2ServerCallbackFunctions* gpD2EventCallbackTable_6FD45830; // 0x00883D50
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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);
extern "C" const char szD2NetCpp_006E0488[];
extern int gnConnectionMode_00882D10;
extern int gbD2ServerCallbackFunctionsInitialized_6FD45834;
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

typedef void(__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern UnitDescriptionFunction gpfGetDescription_6FD2CA64[5]; // 0x0073107C
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

struct Unicode
{
    unsigned short wChar;
};





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
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
    char* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
    }
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
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
#ifdef MOVED_TEST
    int movedPadding;
#endif
    unsigned int m_slotmask;

    unsigned int sub_0052E0E0_Mask(unsigned int value);
    void sub_0044FA00_InternalClear(int bWarn);                                                             // 0x0044FA00
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

struct D2GameDataTableStrc
{
    char unk0x00[0x44];
    D2HashKeyNoneStrc f_44;
    char unk0x45[0x3];
    unsigned int nSequence;
    int bWrapped;
    D2CriticalSectionStrc f_50;

    void DeleteUnlock(D2GameStrc* pGame, int nLockHandle);                                                  // 0x0052E5D0
    D2GameStrc* Ptr(unsigned int nHashValue, const D2HashKeyNoneStrc* pKey);                                // 0x0052E650
    unsigned int sub_0052E6D0_GenerateHandle();

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

    __forceinline char* Next()
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

#include "gen/data/Source/D2Game/GAME/Game.inc"

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
static __forceinline void sub_0052C7C0_RemoveGameGUID(int nGameGUID)
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
        FOG_DestroyMemoryPoolSystem(pGame->pMemoryPool);
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
    D2ClientStrc* volatile pNext;
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
                gpD2EventCallbackTable_6FD45830->pfUpdateCharacterLadder(CLIENTS_GetName(i), nClassId, STATLIST_GetUnitBaseStat(pPlayer, 12, 0), (unsigned int)STATLIST_GetUnitBaseStat(pPlayer, 13, 0), CLIENTS_GetFlags(i), &i->nSaveCreationTimestamp);
            }
        }
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

// 0x0052DA90
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x1063);
    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
    LeaveCriticalSection(pGame->lpCriticalSection);
}

// 0x0052DAF0
extern "C" __declspec(dllexport) int __cdecl sub_0052DAF0() {
    return 1;
}

// 0x0052DB00
extern "C" __declspec(dllexport) int __cdecl sub_0052DB00() {
    return 1;
}

unsigned long gdwPlayerPos_00883D4C; // 0x00883D4C

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

void D2NetLockStrc::Lock(int nUnused)
{
    EnterCriticalSection(&tLock);
}

void D2NetLockStrc::Unlock(int nUnused)
{
    LeaveCriticalSection(&tLock);
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

// 0x0052DB90
int __cdecl sub_0052DB90()
{
    return gdwGlobal_00731010;
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

void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType)
{
    int nGUID = 0;
    EnterCriticalSection(&gCriticalSection_6FD45800);
    if (gnGamesGUIDs_6FD447F8[nGameId - 1] && gnGamesGUIDs_6FD447F8[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs_6FD447F8[nGameId - 1];
    }
    LeaveCriticalSection(&gCriticalSection_6FD45800);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    D2UnitStrc** pUnitList = 0;
    if (!pGame)
    {
        return;
    }

    switch (eType)
    {
    case 0:
        pUnitList = pGame->pUnitList[0];
        break;
    case 1:
        pUnitList = pGame->pUnitList[1];
        break;
    case 2:
        pUnitList = pGame->pUnitList[2];
        break;
    case 3:
        pUnitList = pGame->pUnitList[3];
        break;
    case 4:
        pUnitList = pGame->pUnitList[4];
        break;
    }

    for (int i = 0; i < 128; ++i)
    {
        for (D2UnitStrc* pUnit = pUnitList[i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
        {
            sub_0052DC20_AddUnitDescription(1, pUnit->dwClassId, pUnitDescriptionsList);
        }
    }

    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);

    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfGetDescription_6FD2CA64[eType]), 0x1450);
    for (D2UnitDescriptionListStrc* pNode = pUnitDescriptionsList->pNext; pNode; pNode = pNode->pNext)
    {
        gpfGetDescription_6FD2CA64[eType](pNode->szDescription, pNode->nClassId);
    }
}

static __forceinline D2MonStatsTxt* DESC_GetMonStatsTxtRecord(int nMonsterId)
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

// 0x0052DF40
void __fastcall GAME_UnlockDebugGame()
{
    GAME_LeaveGamesCriticalSection(gpGame_6FD457FC);
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

D2GameDataTableStrc* gpGameDataTbl_6FD45818; // 0x00883D38

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
                const unsigned int nClients = ptGame->nClients;
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

int dword_6FD45844; // 0x00883D58

int gnTargetMsPerFrame_6FD457F8; // 0x00883D60

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
