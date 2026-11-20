#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2ItemsWorld.h"
struct D2InventoryStrc;
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
#pragma intrinsic(memcpy)



struct D2MercSaveDataStrc
{
    unsigned int nFlags;
    unsigned int nSeed;
    unsigned short wName;
    unsigned short nHirelingId;
    unsigned int nExperience;
    unsigned int unk0x10[4];
};


struct D2HirelingTxt
{
    char unk0x000[0x08];
    int dwClass;
    char unk0x00C[0x14];
    int dwExpPerLvl;
    char unk0x024[0xF0];
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);                       // 0x00553570
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600
void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc* pUnit, unsigned short wStat, int nValue); // 0x005718C0
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMerc, int nLevel); // 0x00572840
void __fastcall sub_005738D0(D2GameStrc* pGame, D2UnitStrc* pUnit);                                 // 0x005738D0
void __fastcall PLAYERPETS_UpdatePetInfo(D2UnitStrc* pPlayer, int nPetType, int nUnitGUID, D2PetInfoStrc* pPetInfo); // 0x005749B0
void __fastcall sub_6FC7D470(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet);        // 0x005751A0
D2UnitStrc* __fastcall D2GAME_MERCS_Create_6FCC8630(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short wName, int nSeed, unsigned short wVersion, int nBaseMonster, int bDead); // 0x005774F0
int __stdcall DATATBLS_GetMaxLevel(int nClass);                                                             // 0x00611830
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);     // 0x00627260
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0
D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel);  // 0x006562F0
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel); // 0x00663790

// 0x0056AA50
D2UnitStrc* __fastcall PLRSAVE2_ReadMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2MercSaveDataStrc* pData, unsigned int dwVersion)
{
    if (!pData->nExperience && !pData->nSeed && !pData->wName)
    {
        return 0;
    }

    D2MercSaveDataStrc hirelingData;
    void* const tArg1 = &hirelingData;
    memcpy(tArg1, pData, sizeof(hirelingData));

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, hirelingData.nHirelingId, 1);
    if (!pHirelingTxtRecord)
    {
        return 0;
    }

    hirelingData.wName += pHirelingTxtRecord->wNameFirst;
    if (hirelingData.wName > pHirelingTxtRecord->wNameLast)
    {
        hirelingData.wName = pHirelingTxtRecord->wNameFirst;
    }

    const unsigned int bDead = hirelingData.nFlags & 0x10000;
    D2UnitStrc* pMerc = D2GAME_MERCS_Create_6FCC8630(pGame, pPlayer, hirelingData.wName, hirelingData.nSeed, hirelingData.nHirelingId, pHirelingTxtRecord->dwClass, bDead);
    if (!pMerc)
    {
        return 0;
    }

    D2PetInfoStrc petInfo;
    petInfo.nSeed = hirelingData.nSeed;
    petInfo.nName = hirelingData.wName;
    petInfo.nHirelingId = hirelingData.nHirelingId;
    PLAYERPETS_UpdatePetInfo(pPlayer, 7, !pMerc ? -1 : pMerc->dwUnitId, &petInfo);

    STATLIST_UnitGetStatValue(pPlayer, 12, 0);
    const int nMaxLevel = DATATBLS_GetMaxLevel(0);
    int nLevel = 1;

    if ((unsigned int)STATLIST_UnitGetStatValue(pMerc, 13, 0) < hirelingData.nExperience)
    {
        STATLIST_SetUnitStat(pMerc, 13, hirelingData.nExperience, 0);
    }

    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, 13, hirelingData.nExperience);

    pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, hirelingData.nHirelingId, 1);
    while (pHirelingTxtRecord)
    {
        const int nNextLevel = nLevel + 1;
        if (nNextLevel > nMaxLevel || hirelingData.nExperience < MONSTERS_GetHirelingExpForNextLevel(nNextLevel, pHirelingTxtRecord->dwExpPerLvl))
        {
            MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pMerc, nLevel);

            if (bDead)
            {
                sub_6FC7D470(pGame, pPlayer, pMerc);
                pMerc->dwFlags |= 0x10000;
                SUNIT_SetCombatMode(pGame, pMerc, 12);
                sub_005738D0(pGame, pMerc);
            }

            if (!pMerc->pInventory)
            {
                INVENTORY_AllocInventory(0, pMerc);
            }

            return pMerc;
        }

        nLevel = nNextLevel;
        pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, hirelingData.nHirelingId, nLevel);
    }

    SUNIT_RemoveUnit(pGame, pMerc);
    return 0;
}
