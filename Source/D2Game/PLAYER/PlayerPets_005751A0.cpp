#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


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



typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304

void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3); // 0x0053E0E0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0
void __fastcall PLAYERPETS_PlayerIterate_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x00574410
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID);                         // 0x00574A20
void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int bKillPet);   // 0x005750E0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling);                         // 0x006637B0
#define PETFLAG_DEAD 1

static D2PetListStrc* __stdcall sub_00574540_GetPetListFromPetType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &pPlayerPets->pPetList[nPetType];
    }

    return 0;
}

// 0x005751A0
void __fastcall sub_6FC7D470(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 672);

    const int nPetGUID = !pPet ? -1 : pPet->dwUnitId;

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    const int nPetType = PLAYERPETS_GetPetTypeFromPetGUID(pPlayer, nPetGUID);

    if (nPetType != PETTYPE_HIREABLE)
    {
        PLAYERPETS_RemovePet(pGame, pPlayer, nPetGUID, 0);
    }

    D2PetListStrc* pPetList = sub_00574540_GetPetListFromPetType(pPlayerPets, nPetType);
    if (!pPetList)
    {
        return;
    }

    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nPetGUID)
        {
            pPetData->nFlags |= PETFLAG_DEAD;
            D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 698), pPetData->petInfo.nName, MONSTERS_GetHirelingResurrectionCost(pPet));
            break;
        }
    }

    D2PetArgStrc arg = {};
    arg.nPetGUID = nPetGUID;
    SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
}
