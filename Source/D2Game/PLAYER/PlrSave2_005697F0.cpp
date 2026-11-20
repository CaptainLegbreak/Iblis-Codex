#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
// build: ob1


struct D2InventoryStrc;
struct D2CorpseStrc;
struct D2BitBufferStrc;



struct D2CorpseSaveStrc
{
    unsigned int nUnk;
    int nX;
    int nY;
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall sub_00531BB0_WriteItemList(void* pArg1, void* pArg2, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0

// 0x005697B0
int __fastcall sub_005697B0(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppCursor, const unsigned char* pEnd, int nArg5, int nArg6, int nArg7)
{
    unsigned char* pCursor = *ppCursor;
    const int nWritten = sub_00531BB0_WriteItemList(pGame, pUnit, pCursor, pEnd - pCursor, nArg5, nArg6, nArg7);
    if (nWritten < 0)
    {
        return 3;
    }

    *ppCursor = pCursor + nWritten;
    return 0;
}
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall sub_0062FDC0_GetRepairCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int a6); // 0x0062FDC0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);                                 // 0x0063CD60
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory);                              // 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse);                                     // 0x0063D610
int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse);                                       // 0x0063D630
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pUnit);                                              // 0x0063DFD0

// 0x005697F0
int __fastcall PLRSAVE2_WriteCorpsesSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a5, int a6)
{
    unsigned char* pSection = *ppSection;
    unsigned short bHasCorpseWithItems = 0;
    D2UnitStrc* pBestUnit = 0;
    unsigned int nBestValue = 0;

    if (!pPlayer->pInventory)
    {
        return 2;
    }

    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 0, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        D2InventoryStrc* pInventory;
        if (pUnit && (pInventory = pUnit->pInventory) != 0 && INVENTORY_GetItemCount(pInventory) > 0)
        {
            D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
            unsigned int nValue = 1;
            for (; pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pItem);
                if (!ITEMSIsA(pInvItem, 4))
                {
                    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
                    nValue += sub_0062FDC0_GetRepairCost(pPlayer, pInvItem, 3, pQuestFlags, 0x201, 0);
                }
            }

            if (nValue >= nBestValue)
            {
                nBestValue = nValue;
                pBestUnit = pUnit;
            }
        }
    }

    D2UnitStrc* pUnit = 0;
    if (pBestUnit)
    {
        bHasCorpseWithItems = 1;
        pUnit = pBestUnit;
    }

    if (pSection + 4 > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pSection = 'MJ';
    pSection += 2;

    *(unsigned short*)pSection = bHasCorpseWithItems;
    pSection += 2;

    if (pUnit && bHasCorpseWithItems)
    {
        if (pSection + 12 > pEnd)
        {
            return 1;
        }

        D2CorpseSaveStrc tCorpse;
        tCorpse.nX = CLIENTS_GetUnitX(pUnit);
        tCorpse.nY = CLIENTS_GetUnitY(pUnit);
        *(D2CorpseSaveStrc*)pSection = tCorpse;

        pSection += 12;
        if (sub_005697B0(pGame, pUnit, &pSection, pEnd, 0, a5, a6))
        {
            return 4;
        }
    }

    *ppSection = pSection;
    return 0;
}
