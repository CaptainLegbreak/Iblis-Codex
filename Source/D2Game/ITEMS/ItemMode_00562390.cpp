#include "D2Structs.h"
#include "D2GameStrc.h"
struct D2ClientStrc;
struct D2InventoryStrc;
struct D2SkillStrc;



struct D2BooksTxt
{
    char unk0x00[0x08];
    int dwScrollSkillId;
    int dwBookSkillId;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char szItemModeCpp[];                                                                      // 0x006E1164

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                               // 0x00627F80
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex);                                               // 0x006374B0
void __fastcall sub_0055BF50_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine);         // 0x0055BF50
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall sub_00628C20(D2UnitStrc* pItem);                                                              // 0x00628C20
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);       // 0x005678A0
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY); // 0x005BF240
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill);                                                      // 0x006450F0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity);                                      // 0x00645120
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);     // 0x005531C0
void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520
void __fastcall sub_00561E70_RemoveFromBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);       // 0x00561E70
void __fastcall sub_0055EDC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX);                                 // 0x0055EDC0
static __declspec(noinline) int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc* pItem);
static int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc* pItem);                                           // 0x0055E050

static int sub_0055E050_GetBookSkillIdChecked(D2UnitStrc* pItem)
{
    int nSkillId = -1;
    if (ITEMSIsA(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFA4);
        nSkillId = pBooksTxtRecord->dwBookSkillId;
    }
    else if (ITEMSIsA(pItem, 0x16))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFAB);
        nSkillId = pBooksTxtRecord->dwScrollSkillId;
    }

    return nSkillId;
}

static __forceinline D2InventoryStrc* UNITS_GetInventory(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pInventory;
}

// 0x00562390
int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc)
{
    D2_ASSERT(pGame, 0x1325);
    D2_ASSERT(pUnit, 0x1326);

    *pItemStatus = 0;
    sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x132B);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if ((!pItem ? 6 : pItem->dwUnitType) != 4 || INVENTORY_GetCursorItem(UNITS_GetInventory(pUnit)))
    {
        return 0;
    }

    if (pItem->dwAnimMode != 2 || !sub_00628C20(pItem))
    {
        *pItemStatus = 1;
        return 0;
    }

    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 0;
    }

    D2UnitStrc* pTarget = pUnit;
    if (bUseOnMerc && pUnit->dwUnitType == 0 && pGame->bExpansion)
    {
        if (!ITEMSIsA(pItem, 0x4C) && !ITEMSIsA(pItem, 0x51) && !ITEMSIsA(pItem, 0x50))
        {
            return 0;
        }

        D2UnitStrc* pPet = sub_6FC7E8B0(pGame, pUnit, 7, 0);
        if (pPet)
        {
            pTarget = pPet;
        }
    }

    if (!SKILLITEM_pSpell_Handler(pGame, pTarget, pItem, pItem, nX, nY))
    {
        return 0;
    }

    const int nBeltX = UNITS_GetXPosition(pItem);
    const int nSkillId = sub_0055E050_GetBookSkillIdChecked(pItem);
    if (nSkillId != -1)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (pSkill)
        {
            int nQuantity = SKILLS_GetQuantity(pSkill) - 1;
            if (nQuantity <= 0)
            {
                if (UNITS_GetRightSkill(pUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, 0, -1);
                }
                nQuantity = 0;
            }

            SKILLS_SetQuantity(pSkill, nQuantity);
            const int nUnitGUID = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, szItemModeCpp, 0x136D), nUnitType, nUnitGUID, nSkillId, nQuantity);
        }
    }

    sub_0055BF50_ClearTargetingFlags(pUnit, szItemModeCpp, 0x1370);
    sub_00561E70_RemoveFromBelt(pGame, pUnit, pItem);
    sub_0055EDC0(pGame, pUnit, nBeltX);
    return 1;
}
