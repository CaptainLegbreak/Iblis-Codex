#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
struct D2UnitStrc;





struct D2PetArgStrc
{
    int nPetGUID;
    int nUnitGUID;
    unsigned short nPetClass;
    short unk0x0A;
    int nPetType;
    int nSeed;
    int nName;
    int unk0x18;
};

struct D2PetInfoStrc
{
    int nSeed;
    int nName;
    int nHirelingId;
};

struct D2PetDataStrc
{
    unsigned int nFlags;
    int nUnitGUID;
    D2PetInfoStrc petInfo;
    D2PetDataStrc* pNext;
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData;
    int nCurrent;
    int nMax;
};

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList;
};


struct D2PetTypeTxt
{
    unsigned int dwHcIdx;
    unsigned char nPetFlags[4];
    short wGroup;
    char unk0x0A[0xD6];
};



typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3); // 0x0053E0E0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall sub_00554670_UpdateClientsOnRoomChange(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);               // 0x00554670
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00573780
void __fastcall PLAYERPETS_PlayerIterate_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x00574410
void __fastcall PLAYERPETS_PlayerIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg);  // 0x00574930
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID);                         // 0x00574A20
void __fastcall sub_6FC7D150(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax);           // 0x00575850
void __fastcall sub_6FC7DF40(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00575900
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);        // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2);                                      // 0x00620FA0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                             // 0x006492A0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling); // 0x006637B0

static __forceinline int sub_F05_UnitHasBeenDeleted(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 8) & 1;
}

static __forceinline int sub_F05_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static __forceinline int sub_F05_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_F05_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_F05_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static __forceinline int sub_F05_GetClassId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

static __forceinline int sub_I16_GetUnitIdRet(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static __forceinline int sub_I16_GetClassIdRet(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

static __forceinline D2PetListStrc* sub_F05_GetPetListInl(D2PlayerDataStrc* pPlayerData, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
        if (pPlayerPets)
        {
            return &pPlayerPets->pPetList[nPetType];
        }
    }
    return 0;
}

static void sub_00574450_KillPet(D2GameStrc* pGame, int nPetGUID)
{
    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, nPetGUID);
    if (!pPet)
    {
        return;
    }

    D2_ASSERT(!sub_F05_UnitHasBeenDeleted(pPet), 0x5A);

    pPet->dwFlags |= 0x4000000;

    if (sub_F05_CheckMonStatsFlag(pPet->dwClassId, 15))
    {
        SUNITDMG_KillMonster(pGame, pPet, 0, 0);
    }
    else
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pPet, 0, &modeChange);
        modeChange.pTargetUnit = SUNIT_GetOwner(pGame, pPet);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }

    D2PetArgStrc arg = {};
    arg.nPetGUID = nPetGUID;
    SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
}

static D2PetListStrc* __stdcall sub_00574540_GetPetListFromPetType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &pPlayerPets->pPetList[nPetType];
    }

    return 0;
}

static void __stdcall sub_00574570_ClearPetList(D2UnitStrc* pPlayer, D2PetListStrc* pPetList, int bIsHirelingList, int bKeepHireling, D2GameStrc* pGame)
{
    D2PetDataStrc* pPetData = pPetList->pPetData;
    while (pPetData)
    {
        D2PetDataStrc* pNext = pPetData->pNext;
        if (bIsHirelingList)
        {
            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet)
            {
                D2PetArgStrc arg = {};
                arg.nPetGUID = pPetData->nUnitGUID;
                SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
                DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPet), 1, pPet->dwUnitId);

                if (bKeepHireling)
                {
                    if (!(pPetData->nFlags & 1))
                    {
                        pPetData->nFlags |= 1;
                        pPetList->pPetData = pPetData;
                        if (UNITS_GetRoom(pPet))
                        {
                            D2ModeChangeStrc modeChange;
                            MONSTERMODE_GetModeChangeInfo(pPet, 0, &modeChange);
                            modeChange.pTargetUnit = SUNIT_GetOwner(pGame, pPet);
                            D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                        }

                        D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 0xDB), pPetData->petInfo.nName, MONSTERS_GetHirelingResurrectionCost(pPet));
                    }
                }
                else
                {
                    SUNIT_RemoveUnit(pGame, pPet);
                }
            }

            if (!bKeepHireling)
            {
                --pPetList->nCurrent;
                --pPetList->nMax;
                FOG_FreeServerMemory(pGame->pMemoryPool, pPetData, gszPlayerPetsSourceFile, 0xE8, 0);
            }
        }
        else
        {
            sub_00574450_KillPet(pGame, pPetData->nUnitGUID);
            --pPetList->nCurrent;
            --pPetList->nMax;
            FOG_FreeServerMemory(pGame->pMemoryPool, pPetData, gszPlayerPetsSourceFile, 0xE8, 0);
        }

        pPetData = pNext;
    }

    if (!pPetList->nCurrent)
    {
        pPetList->pPetData = 0;
    }
}

void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(pPlayerData, 0x14F);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = sub_00574540_GetPetListFromPetType(pPlayerPets, nPetType);
        sub_00574570_ClearPetList(pUnit, pPetList, nPetType == 7, 0, pGame);
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerPets->pPetList, gszPlayerPetsSourceFile, 0x161, 0);
    FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerPets, gszPlayerPetsSourceFile, 0x162, 0);
    pPlayerData->pPlayerPets = 0;
}

static void __stdcall sub_00574850_RemovePetFromList(D2PetListStrc* pPetList, int bKillPet, D2GameStrc* pGame, int nUnitGUID)
{
    D2PetDataStrc* pPrevious = 0;
    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nUnitGUID)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pPetData->pNext;
            }
            else
            {
                pPetList->pPetData = pPetData->pNext;
            }

            D2PetArgStrc arg = {};
            arg.nPetGUID = nUnitGUID;
            SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);

            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet)
            {
                if (bKillPet)
                {
                    sub_00574450_KillPet(pGame, pPetData->nUnitGUID);
                }
                else
                {
                    pPet->dwFlags &= 0x7FFFFFFF;
                }
            }

            FOG_FreeServerMemory(pGame->pMemoryPool, pPetData, gszPlayerPetsSourceFile, 0x25C, 0);

            --pPetList->nCurrent;
            D2_ASSERT(pPetList->nCurrent >= 0, 0x260);
            return;
        }

        pPrevious = pPetData;
    }
}

static void __stdcall sub_00574C60_KillPetList(D2PetListStrc* pPetList, D2GameStrc* pGame)
{
    D2PetDataStrc* pPetData = pPetList->pPetData;
    while (pPetData)
    {
        D2PetDataStrc* pNext = pPetData->pNext;
        sub_00574450_KillPet(pGame, pPetData->nUnitGUID);
        FOG_FreeServerMemory(pGame->pMemoryPool, pPetData, gszPlayerPetsSourceFile, 0x4A5, 0);
        pPetData = pNext;
    }

    pPetList->pPetData = 0;
    pPetList->nCurrent = 0;
}

static void __stdcall sub_00574CC0_RelocatePet(D2GameStrc* pGame, D2UnitStrc* pPet, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2ActiveRoomStrc* pPetRoom = UNITS_GetRoom(pPet);
    if (pRoom)
    {
        if (pPet->nAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
        {
            sub_00650BE0_PlaceUnit(pPet->pDynamicPath, pPet, 0, 0, 0);
        }
    }

    sub_00650BE0_PlaceUnit(pPet->pDynamicPath, pPet, pRoom, nX, nY);

    if (pRoom != pPetRoom)
    {
        UNITS_SetCurrentRoomInvalid(pPet, 1);
        sub_00554670_UpdateClientsOnRoomChange(pGame, pPet, pPetRoom);
    }

    pPet->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPet)));
    pPet->pDrlgAct = pGame->pAct[pPet->nAct];
    UNITROOM_RefreshUnit(pPet);

    pPet->dwFlagEx |= 0x10000;
    UNITROOM_RefreshUnit(pPet);

    MONSTER_UpdateAiCallbackEvent(pGame, pPet);
    if (!MONSTERS_IsDead(pPet) && pPet->pDynamicPath)
    {
        PATH_SetFootprintCollisionMask(pPet->pDynamicPath, 0x100);
    }
}

static void __stdcall sub_00574D90_RelocatePetList(D2GameStrc* pGame, D2PetListStrc* pPetList, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (!(pPetData->nFlags & 1))
        {
            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet)
            {
                sub_00574CC0_RelocatePet(pGame, pPet, pRoom, nX, nY);
            }
        }
    }
}

D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2PetListStrc* pPetList = sub_F05_GetPetListInl(pPlayerData, nPetType);
        if (pPetList)
        {
            D2PetDataStrc* pPetData;
            for (pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (a4 || !(pPetData->nFlags & 1))
                {
                    break;
                }
            }

            if (pPetData)
            {
                return SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            }
        }
    }

    return 0;
}

static __forceinline D2UnitStrc* sub_F05_GetFirstPetInl(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int bIncludeDead)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2PetListStrc* pPetList = sub_F05_GetPetListInl(pPlayerData, nPetType);
        if (pPetList)
        {
            D2PetDataStrc* pPetData;
            for (pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (bIncludeDead || !(pPetData->nFlags & 1))
                {
                    break;
                }
            }

            if (pPetData)
            {
                return SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            }
        }
    }

    return 0;
}

void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int bKillPet)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x276);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    const int nPetType = PLAYERPETS_GetPetTypeFromPetGUID(pPlayer, nPetGUID);
    if (nPetType == 0 && bKillPet)
    {
        sub_00574450_KillPet(pGame, nPetGUID);
    }

    D2PetListStrc* pPetList = sub_00574540_GetPetListFromPetType(pPlayerPets, nPetType);
    if (pPetList)
    {
        sub_00574850_RemovePetFromList(pPetList, bKillPet, pGame, nPetGUID);

        D2PetArgStrc arg = {};
        arg.nPetGUID = nPetGUID;
        SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
    }
}

// build: context sub_00575380_RemoveDistantPets
static void __stdcall sub_00575380_RemoveDistantPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMaxDistance, D2PetListStrc* pPetList)
{
    D2PetDataStrc* pPetData = pPetList->pPetData;
    while (pPetData)
    {
        D2PetDataStrc* pNext = pPetData->pNext;
        if (!(pPetData->nFlags & 1))
        {
            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet && PATH_ComputeSquaredDistance(sub_F05_GetUnitX(pPlayer), sub_F05_GetUnitY(pPlayer), sub_F05_GetUnitX(pPet), sub_F05_GetUnitY(pPet)) > nMaxDistance)
            {
                PLAYERPETS_RemovePet(pGame, pPlayer, pPetData->nUnitGUID, 1);
            }
        }

        pPetData = pNext;
    }
}

void __fastcall PLAYERPETS_UpdatePetsForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nX, int nY)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pPlayer)->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = sub_00574540_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
            if (pPetTypeTxtRecord)
            {
                if (pPetTypeTxtRecord->nPetFlags[0] & gdwBitMasks[0])
                {
                    sub_00574D90_RelocatePetList(pGame, pPetList, pRoom, nX, nY);
                }
                else if (pPetTypeTxtRecord->nPetFlags[0] & gdwBitMasks[1])
                {
                    sub_00575380_RemoveDistantPets(pGame, pPlayer, 0x640, pPetList);
                }
                else
                {
                    sub_00574C60_KillPetList(pPetList, pGame);
                }
            }
        }
    }
}

// build: context sub_00575720_RemoveGroupPets
static void __stdcall sub_00575720_RemoveGroupPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType)
{
    if (!pPlayer || pPlayer->dwUnitType != 0)
    {
        return;
    }

    D2PetTypeTxt* pPetTypeTxtRecord = 0;
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
    }

    if (!pPetTypeTxtRecord)
    {
        return;
    }

    const int nGroup = pPetTypeTxtRecord->wGroup;
    if (nGroup <= 0)
    {
        return;
    }

    for (int nOtherPetType = 0; nOtherPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nOtherPetType)
    {
        if (nOtherPetType != nPetType)
        {
            D2PetTypeTxt* pOtherPetTypeTxtRecord = 0;
            if (nOtherPetType >= 0 && nOtherPetType < sgptDataTables->nPetTypeTxtRecordCount)
            {
                pOtherPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nOtherPetType];
            }

            if (pOtherPetTypeTxtRecord && pOtherPetTypeTxtRecord->wGroup == nGroup)
            {
                for (D2UnitStrc* pOtherPet = sub_6FC7E8B0(pGame, pPlayer, nOtherPetType, 1); pOtherPet; pOtherPet = sub_F05_GetFirstPetInl(pGame, pPlayer, nOtherPetType, 1))
                {
                    PLAYERPETS_RemovePet(pGame, pPlayer, sub_F05_GetUnitId(pOtherPet), 1);
                }
            }
        }
    }
}

void __fastcall sub_00575BC0(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x12F);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = sub_00574540_GetPetListFromPetType(pPlayerPets, nPetType);
        sub_00574570_ClearPetList(pPlayer, pPetList, nPetType == 7, nPetType == 7, pGame);
    }

    sub_6FC7DF40(pGame, pPlayer);
}

// 0x00575C70
static int __stdcall sub_00575C70_AppendPet(D2UnitStrc* pPet, D2PetInfoStrc* pPetInfo, D2UnitStrc* pPlayer, D2PetListStrc* ptPet, D2GameStrc* pGame)
{
    if (!ptPet->nMax)
    {
        sub_6FC7DF40(pGame, pPlayer);
        if (!ptPet->nMax)
        {
            sub_00574450_KillPet(pGame, sub_F05_GetUnitId(pPet));
            return 0;
        }
    }

    if (ptPet->nCurrent == ptPet->nMax)
    {
        D2_ASSERT(ptPet->pPetData, 0x312);

        sub_00574850_RemovePetFromList(ptPet, 1, pGame, ptPet->pPetData->nUnitGUID);
        D2_ASSERT(ptPet->nCurrent != ptPet->nMax, 0x316);
    }

    D2PetDataStrc* pPrevious = ptPet->pPetData;
    if (pPrevious)
    {
        while (pPrevious->pNext)
        {
            pPrevious = pPrevious->pNext;
        }
    }

    D2PetDataStrc* pPetData = (D2PetDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PetDataStrc), gszPlayerPetsSourceFile, 0x322, 0);
    memset(pPetData, 0, sizeof(D2PetDataStrc));

    pPetData->nUnitGUID = sub_F05_GetUnitId(pPet);

    pPetData->petInfo = *pPetInfo;

    if (pPrevious)
    {
        pPrevious->pNext = pPetData;
    }
    else
    {
        ptPet->pPetData = pPetData;
    }

    ++ptPet->nCurrent;
    D2_ASSERT(ptPet->nCurrent <= ptPet->nMax, 0x330);
    return 1;
}

// build: context PLAYERPETS_AddSummonedPet
void __fastcall PLAYERPETS_AddSummonedPet(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, int nPetMax)
{
    if (!pPlayer || pPlayer->dwUnitType != 0)
    {
        return;
    }

    if (nPetType <= 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    sub_00575720_RemoveGroupPets(pGame, pPlayer, nPetType);
    sub_6FC7D150(pGame, pPlayer, nPetType, nPetMax);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData || !pPlayerData->pPlayerPets)
    {
        return;
    }

    D2PetListStrc* pPetList = sub_00574540_GetPetListFromPetType(pPlayerData->pPlayerPets, nPetType);
    if (!pPetList)
    {
        return;
    }

    D2PetInfoStrc petInfo;
    petInfo.nSeed = 0;
    petInfo.nName = 0;
    petInfo.nHirelingId = 0;
    if (sub_00575C70_AppendPet(pPet, &petInfo, pPlayer, pPetList, pGame))
    {
        D2PetArgStrc arg = {};
        arg.nPetType = nPetType;
        arg.nPetGUID = sub_I16_GetUnitIdRet(pPet);
        arg.nPetClass = sub_I16_GetClassIdRet(pPet);
        arg.nUnitGUID = pPlayer->dwUnitId;
        SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_UpdateClient, &arg);
    }
}

// 0x00575E90
void __fastcall PLAYERPETS_AddPetWithInfo(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, D2PetInfoStrc* pPetInfo)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x3B5);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    D2PetListStrc* pPetList = sub_00574540_GetPetListFromPetType(pPlayerPets, nPetType);
    if (!pPetList)
    {
        return;
    }

    D2PetInfoStrc petInfo = *pPetInfo;
    if (sub_00575C70_AppendPet(pPet, &petInfo, pPlayer, pPetList, pGame))
    {
        D2PetArgStrc arg = {};
        arg.nPetType = nPetType;
        arg.nPetGUID = sub_I16_GetUnitIdRet(pPet);
        arg.nUnitGUID = sub_I16_GetUnitIdRet(pPlayer);
        arg.nPetClass = sub_I16_GetClassIdRet(pPet);
        arg.nSeed = pPetInfo->nSeed;
        arg.nName = pPetInfo->nName;
        SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_UpdateClient, &arg);
    }
}
