#pragma once
// Game server state: arena settings, gamble inventories, object populating regions, monster spawn arguments and the server callback table

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Path.h"

struct D2ActiveRoomStrc;
struct D2ClientInfoStrc;
struct D2FileTimeStrc;
struct D2GameStrc;
struct D2InventoryStrc;
struct D2RoomCoordListStrc;
struct D2ArenaStrc;
struct D2NpcGambleStrc;
struct D2ObjectRegionStrc;
struct D2UnkMonCreateStrc;
struct D2ServerCallbackFunctions;

struct D2ArenaStrc
{
    int nAlternateStartTown; // 0x00
    int nType; // 0x04
    union
    {
        unsigned int fFlags; // 0x08
        struct
        {
            unsigned char bFlag0 : 1;
            unsigned char bArenaMode : 1;
            unsigned char bUpdateClients : 1;
            unsigned char bFlag3 : 1;
            unsigned char bFlag4 : 1;
            unsigned char bTemplate : 1;
            unsigned char bFlag40 : 1;
            unsigned char bFlag80 : 1;
        };
    };
    unsigned char nTemplate; // 0x0C
    unsigned char unk0x0D; // 0x0D
    unsigned short unk0x0E; // 0x0E
};

struct D2NpcGambleStrc
{
    D2InventoryStrc* pInventory; // 0x00
    int dwGUID; // 0x04
    D2NpcGambleStrc* pNext; // 0x08
};

struct D2ObjectRegionStrc
{
    unsigned char nAct; // 0x00
    unsigned char unk0x01; // 0x01
    unsigned short unk0x02; // 0x02
    int unk0x04; // 0x04
    int nPopulatedRooms; // 0x08
    int unk0x0C; // 0x0C
    int nHealingShrines; // 0x10
    int nShrines; // 0x14
    int nWells; // 0x18
    int nTrapMonsterId; // 0x1C
    D2CoordStrc wellCoordinates[4]; // 0x20
    D2CoordStrc shrineCoordinates[10]; // 0x40
};

struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame; // 0x00
    D2ActiveRoomStrc* pRoom; // 0x04
    D2RoomCoordListStrc* pRoomCoordList; // 0x08
    int nMonsterId; // 0x0C
    int nAnimMode; // 0x10
    int nUnitGUID; // 0x14
    int nX; // 0x18
    int nY; // 0x1C
    int nMaxSearchRings; // 0x20
    short nFlags; // 0x24
    unsigned short unk0x26; // 0x26
};

typedef void (__fastcall* D2EnterGameFn)(int nGameId, char* szName, int nClass, int nLevel, int nSaveFlags);
typedef void (__fastcall* FnUpdateCharacterLadder)(const char* szCharName, int nClassId, int nLevel, unsigned __int64 nExperience, unsigned int nFlags, D2FileTimeStrc* pSaveCreationTimestamp);
typedef const char* (__stdcall* FnLoadComplete)();
typedef void (__fastcall* D2LeaveGameFn)(D2ClientInfoStrc** ppClientInfo, int nGameId, int nClassId, int nLevel, __int64 nExperience, int nSaveFlags, const char* szCharName, const char* szPreview, int bUnlockCharacter, int a10, int a11, const char* szAccountName, int nCharSaveTransactionToken, int a14, int a15, int a16, int a17, int a18, D2FileTimeStrc* pSaveCreationTimestamp);
typedef void (__fastcall* RealmSaveCallback)(unsigned int*, const char*, char*, void*, int, unsigned int);
typedef void (__fastcall* RealmUpdateCallback)(unsigned int*, const char*, char*);

struct D2ServerCallbackFunctions
{
    void (__fastcall* pfCloseGame)(int nGameId, int nProgramId, int nLastUnitGUID, int nSeconds); // 0x00
    D2LeaveGameFn pfLeaveGame; // 0x04
    void (__fastcall* pfGetDatabaseCharacter)(D2ClientInfoStrc** ppClientInfo, const char* szCharName, int dwClientId, const char* szAccountName); // 0x08
    RealmSaveCallback pfSaveDatabaseCharacter; // 0x0C
    void* pfServerLogMessage; // 0x10
    D2EnterGameFn pfEnterGame; // 0x14
    int (__fastcall* pfFindPlayerToken)(const char* szClientName, int nTokenId, int nGameId, char* pszInOutAccountName, int* pOutCharSaveTransactionToken, int* a6, int* a7, int* a8, int* a9); // 0x18
    void* pfSaveDatabaseGuild; // 0x1C
    void (__fastcall* pfUnlockDatabaseCharacter)(D2ClientInfoStrc** ppClientInfo, const char* szCharName, const char* szAccountName); // 0x20
    void* unk0x24; // 0x24
    FnUpdateCharacterLadder pfUpdateCharacterLadder; // 0x28
    void* unk0x2C; // 0x2C
    void* unk0x30; // 0x30
    int (__stdcall* pfGetValue)(); // 0x34
    RealmUpdateCallback pfUpdate; // 0x38
    FnLoadComplete pfLoadComplete; // 0x3C
    void* unk0x40; // 0x40
    void* unk0x44; // 0x44
    void* unk0x48; // 0x48
    void* unk0x4C; // 0x4C
    void* unk0x50; // 0x50
    void (__fastcall* pfGetTime)(D2FileTimeStrc* pTime); // 0x54
};

D2_CHECK_SIZE(D2ArenaStrc, 0x10);
D2_CHECK_SIZE(D2NpcGambleStrc, 0x0C);
D2_CHECK_SIZE(D2ObjectRegionStrc, 0x90);
D2_CHECK_SIZE(D2UnkMonCreateStrc, 0x28);
D2_CHECK_SIZE(D2ServerCallbackFunctions, 0x58);
