#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"

struct D2ModeChangeStrc;



struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
    int nX;
    int nY;
    int unk0x14;
    int unk0x18;
    int unk0x1C;
};

struct D2PetArgStrc
{
    int nPetGUID;
    int unk0x04[6];
};

struct D2PetInfoStrc
{
    char unk0x00[0x04];
    unsigned short wName;
    char unk0x06[0x0C - 0x04 - 2];
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

struct D2PlayerDataStrc
{
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};



typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern const unsigned int gdwBitMasks[];                                                                    // 0x006CE268
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3); // 0x0053E0E0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall PLAYERPETS_PlayerIterate_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x00574410
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID);                         // 0x00574A20
void __fastcall sub_6FC7DF40(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00575900
void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);        // 0x005A7C20
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling);                                  // 0x006637B0

static __forceinline int sub_E09_UnitHasBeenDeleted(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 8) & 1;
}

static __forceinline int sub_E09_CheckMonStatsFlag(int nMonsterId, int nFlag)
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

// build: context sub_00574450_KillPet
static void sub_00574450_KillPet(D2GameStrc* pGame, int nPetGUID)
{
    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, nPetGUID);
    if (!pPet)
    {
        return;
    }

    D2_ASSERT(!sub_E09_UnitHasBeenDeleted(pPet), 0x5A);

    pPet->dwFlags |= 0x4000000;

    if (sub_E09_CheckMonStatsFlag(pPet->dwClassId, 15))
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

// 0x00574540
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

                        D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 0xDB), pPetData->petInfo.wName, MONSTERS_GetHirelingResurrectionCost(pPet));
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

// 0x005746D0
void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* ptInfo = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(ptInfo, 0x14F);

    D2PlayerPetStrc* pPlayerPets = ptInfo->pPlayerPets;
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
    ptInfo->pPlayerPets = 0;
}

// 0x00574850
static void __stdcall sub_00574850_RemovePetFromList(D2PetListStrc* pPetList, int bKillPet, int nUnitGUID, D2GameStrc* pGame)
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
        sub_00574850_RemovePetFromList(pPetList, bKillPet, nPetGUID, pGame);

        D2PetArgStrc arg = {};
        arg.nPetGUID = nPetGUID;
        SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
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
