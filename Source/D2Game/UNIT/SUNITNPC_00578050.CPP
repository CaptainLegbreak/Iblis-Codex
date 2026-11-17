#include "D2Game.h"

struct D2UnitStrc { int dwUnitType; int dwClassId; };
struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; };
struct D2PlayerDataStrc { char unk00[0x10]; D2BitBufferStrc* pQuestData[3]; };
extern const char gszEmptyAssertText; // 0x006CC837
extern const char gszNpcSourceFile[]; // 0x006E15F0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
void __fastcall sub_0053D740_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType); // 0x0053D740
void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520
int __fastcall sub_00557FF0_InventoryContainsItem(D2UnitStrc* pUnit, D2UnitStrc* pItem, void* pInventory); // 0x00557FF0
int __fastcall sub_00576D90_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost); // 0x00576D90
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005761C0
void __fastcall sub_005762B0_RepairItemCallback(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005762B0
int __stdcall ITEMS_GetAllRepairCosts(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void (__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*)); // 0x0062FE60
int __stdcall sub_0062FDC0_GetRepairCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062FDC0
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem); // 0x0062E660
int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840
unsigned int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwMask, unsigned int nLine, const char* szFile); // 0x006280A0

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define SEND_0x2A(nResult, nLine, bSuccess) sub_0053D740_SendPacket0x2A(SUNIT_GetClientFromPlayer(pUnit, gszNpcSourceFile, nLine), 0x2A, nResult, STATLIST_UnitGetStatValue(pUnit, 14, 0), -1, bSuccess)

// 0x00578050
int __fastcall D2GAME_NPC_Repair_6FCC95B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID, int nItemGUID, unsigned short nUnused, int nRepairFlags)
{
    D2_ASSERT(pGame, 0x9BC);

    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, 1, nNpcGUID);
    if (!pNpc || pInteractUnit != pNpc)
    {
        SEND_0x2A(9, 0x9C5, 0);
        return 1;
    }

    if (pNpc->dwClassId != 257 && pNpc->dwClassId != 154 && pNpc->dwClassId != 178 && pNpc->dwClassId != 511 && pNpc->dwClassId != 253)
    {
        SEND_0x2A(9, 0x9D2, 0);
        return 1;
    }

    if (nRepairFlags & 0x80000000)
    {
        const int nDifficulty = pGame->nDifficulty;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[nDifficulty];
        const int nNpcId = pNpc->dwClassId;
        const int nRepairCosts = ITEMS_GetAllRepairCosts(pGame, pUnit, nNpcId, nDifficulty, pQuestFlags, 0);
        if (!nRepairCosts)
        {
            SEND_0x2A(2, 0x9DD, 1);
            return 0;
        }

        if (!sub_00576D90_SpendGold(pGame, pUnit, nRepairCosts))
        {
            SEND_0x2A(12, 0x9E4, 0);
            return 1;
        }

        const int nNpcClassId = pNpc->dwClassId;
        ITEMS_GetAllRepairCosts(pGame, pUnit, nNpcClassId, pGame->nDifficulty, sub_00543520(pGame, pUnit), sub_005762B0_RepairItemCallback);
        SEND_0x2A(2, 0x9E8, 1);
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem || !sub_00557FF0_InventoryContainsItem(pUnit, pItem, 0))
    {
        SEND_0x2A(9, 0x9F0, 0);
        return 3;
    }

    const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
    const int nDurability = STATLIST_UnitGetStatValue(pItem, 72, 0);
    if (!ITEMS_IsRepairable(pItem))
    {
        SEND_0x2A(9, 0xA05, 0);
        return 1;
    }

    {
        int nQuantity;
        if (!ITEMS_CheckIfStackable(pItem) || !ITEMS_CheckIfThrowable(pItem) || ITEMS_IsEthereal(pItem) || (nQuantity = STATLIST_UnitGetStatValue(pItem, 70, 0)) >= ITEMS_GetTotalMaxStack(pItem))
        {
            int bHasChargedSkills;
            if (!ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) || bHasChargedSkills)
            {
                if (!nMaxDurability)
                {
                    goto lNotRepairable;
                }

                if (nDurability >= nMaxDurability)
                {
lNotRepairable:
                    SEND_0x2A(9, 0xA21, 0);
                    return 1;
                }
            }
        }
    }

    const int nVendorId = pNpc->dwClassId;
    const int nTransactionCosts = sub_0062FDC0_GetRepairCost(pUnit, pItem, pGame->nDifficulty, sub_00543520(pGame, pUnit), nVendorId, 3);
    if (!sub_00576D90_SpendGold(pGame, pUnit, nTransactionCosts))
    {
        const int nGold = STATLIST_UnitGetStatValue(pUnit, 14, 0);
        if (nMaxDurability > nDurability)
        {
            const int nDivisor = ((unsigned int)nTransactionCosts << 10) / (unsigned int)(nMaxDurability - nDurability);
            if (nGold > 0 && nDivisor < nGold << 10 && nDivisor > 0)
            {
                const int nRepairDurability = (nGold << 10) / nDivisor;
                if (!ITEMS_CheckItemFlag(pItem, 0x100, 0xA43, gszNpcSourceFile))
                {
                    if (sub_00576D90_SpendGold(pGame, pUnit, nGold))
                    {
                        const int nNewDurability = D2_MIN(nMaxDurability, nDurability + nRepairDurability);

                        STATLIST_SetUnitStat(pItem, 72, nNewDurability, 0);
                        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(SUNIT_GetClientFromPlayer(pUnit, gszNpcSourceFile, 0xA4A), pItem, 1, 72, nNewDurability, 0);
                        SEND_0x2A(2, 0xA4B, 1);
                        return 0;
                    }
                }
            }

            SEND_0x2A(12, 0xA50, 0);
            return 0;
        }

        SEND_0x2A(12, 0xA54, 0);
        return 0;
    }

    D2GAME_NPC_RepairItem_6FCC6970(pGame, pItem, pUnit);
    SEND_0x2A(2, 0xA5C, 1);
    return 0;
}
