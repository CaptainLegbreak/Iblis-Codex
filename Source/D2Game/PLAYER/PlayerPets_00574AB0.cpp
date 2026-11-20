#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
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

struct D2PlayerDataStrc
{
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
};


typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc*, SUNIT_IterateFn, void*); // 0x005538D0
void __fastcall sub_00574930_NotifyPetRevival(D2GameStrc*, D2UnitStrc*, void*); // 0x00574930
static __forceinline D2PetListStrc* GetPetList(D2PlayerPetStrc* pPets, int nType, int nCount)
{
    if (nType >= 0 && nType < nCount)
        return &pPets->pPetList[nType];
    return 0;
}
static __forceinline int GetUnitClassId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}
static __forceinline int GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}
// 0x00574AB0
int __fastcall sub_00574AB0_RevivePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet)
{
    D2PlayerDataStrc* ptInfo = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(ptInfo, 0x402);
    D2PlayerPetStrc* pPlayerPets = ptInfo->pPlayerPets;
    if (!pPlayerPets)
        return 0;
    const int nPetTypes = sgptDataTables->nPetTypeTxtRecordCount;
    for (int nPetType = 1; nPetType < nPetTypes; ++nPetType)
    {
        D2PetListStrc* pPetList = GetPetList(pPlayerPets, nPetType, nPetTypes);
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (pPetData->nUnitGUID == sub_00451F50_GetUnitGUID(pPet))
                {
                    pPetData->nFlags &= ~1;
                    D2PetArgStrc arg = {};
                    arg.nPetType = nPetType;
                    arg.nPetGUID = pPetData->nUnitGUID;
                    arg.nPetClass = GetUnitClassId(pPet);
                    arg.nUnitGUID = GetUnitGUID(pPlayer);
                    arg.nSeed = pPetData->petInfo.nSeed;
                    arg.nName = pPetData->petInfo.nName;
                    SUNIT_IterateLivingPlayers(pGame, sub_00574930_NotifyPetRevival, &arg);
                    return 1;
                }
            }
        }
    }
    return 0;
}
