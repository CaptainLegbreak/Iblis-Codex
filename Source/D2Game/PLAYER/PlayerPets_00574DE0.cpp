#include "D2Game.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1
struct D2PetDataStrc;
struct D2PetListStrc;
struct D2PlayerPetStrc;
struct D2PlayerDataStrc;
struct D2PetTypeTxt;


struct D2PetDataStrc
{
    unsigned char nFlags;
    char unk0x01[0x03];
    int nUnitGUID;
    char unk0x08[0x0C];
    D2PetDataStrc* pNext;
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData;
    int nCurrent;
    int nPetMax;
};

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList;
};



typedef int (__stdcall* FARPROC)();

typedef void(__fastcall* PetCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005746D0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_00575A80_InitPetTypeMax(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575A80

struct D2PetTypeTxt
{
    unsigned int dwHcIdx;
    unsigned char nPetFlags[4];
    char unk0x08[0xD8];
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4); // 0x005750E0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053CDF0

inline D2PetListStrc* PLAYERPETS_GetPetListFromPetType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &pPlayerPets->pPetList[nPetType];
    }

    return 0;
}

// 0x00574DE0
void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetCallback pCallback, void* a4)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);

    D2_ASSERT(!IsBadCodePtr((FARPROC)pCallback), 1461);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (!(pPetData->nFlags & 1))
                {
                    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
                    if (pPet)
                    {
                        pCallback(pGame, pPlayer, pPet, a4);
                    }
                }
            }
        }
    }
}

// 0x00575AF0
void __fastcall PLAYERPETS_AllocPetList(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 154);

    if (pPlayerData->pPlayerPets)
    {
        PLAYERPETS_FreePetsFromPlayerData(pGame, pPlayer);
    }

    D2PlayerPetStrc* pPlayerPets = (D2PlayerPetStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PlayerPetStrc), gszPlayerPetsSourceFile, 162, 0);
    pPlayerPets->pPetList = 0;
    pPlayerData->pPlayerPets = pPlayerPets;
    pPlayerPets->pPetList = (D2PetListStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PetListStrc) * sgptDataTables->nPetTypeTxtRecordCount, gszPlayerPetsSourceFile, 166, 0);
    memset(pPlayerPets->pPetList, 0, sizeof(D2PetListStrc) * sgptDataTables->nPetTypeTxtRecordCount);
    sub_00575A80_InitPetTypeMax(pGame, pPlayer);
}

// 0x00575590
static void __stdcall sub_00575590_RemoveDeadPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2PlayerPetStrc* pPlayerPets)
{
    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList && nPetType != PETTYPE_HIREABLE)
        {
            D2PetDataStrc* pPetData = pPetList->pPetData;
            while (pPetData)
            {
                D2PetDataStrc* pNext = pPetData->pNext;
                D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
                if (!pPet || SUNIT_IsDead(pPet))
                {
                    PLAYERPETS_RemovePet(pGame, pPlayer, pPetData->nUnitGUID, 0);
                }
                pPetData = pNext;
            }
        }
    }
}

// 0x00575630
void __fastcall sub_6FC7E640(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pPlayer)->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    sub_00575590_RemoveDeadPets(pGame, pPlayer, pPlayerPets);

    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 1411);
    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
            if (pPetTypeTxtRecord && pPetTypeTxtRecord->nPetFlags[0] & gdwBitMasks[2])
            {
                for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
                {
                    if (!(pPetData->nFlags & 1))
                    {
                        D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
                        if (pPet)
                        {
                            sub_6FC3E200(pClient, pPet);
                        }
                    }
                }
            }
        }
    }
}
