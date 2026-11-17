struct D2InventoryStrc;
struct D2SkillStrc;
struct D2SkillListStrc;

struct D2SkillsTxt
{
    char unk0x000[0x168];
    unsigned char nWeapSel;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[0x34];
    int dwSeqFrame;
    char unk0x3C[0x24];
    D2InventoryStrc* pInventory;
    char unk0x64[0x44];
    D2SkillListStrc* pSkills;
};

int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
D2SkillStrc* __fastcall SKILLS_GetUsedSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x006439A0
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill);                            // 0x00644140
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc);               // 0x0063C050
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask);                         // 0x00463720

// 0x00623990
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2)
{
    D2UnitStrc* pItem;
    int nBodyLoc;
    int bIsLeftHandItem;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem);

    if (UNITS_CanDualWield(pUnit))
    {
        D2SkillStrc* pSkill = SKILLS_GetUsedSkillFromSkillList(pUnit->pSkills);
        if (!pSkill)
        {
            return pItem;
        }
        D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
        if (!pSkillsTxtRecord)
        {
            return pItem;
        }

        D2UnitStrc* pWeapon = 0;
        switch (pSkillsTxtRecord->nWeapSel)
        {
        case 1:
            pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
            break;

        case 2:
        {
            const int nFlags = SKILLS_GetFlags(pSkill) & 0x2000;
            pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
            D2UnitStrc* pHandItem = sub_0063C050_GetBodyLocItem(pInventory, 6);
            if (!pWeapon || !ITEMS_CheckItemTypeId(pWeapon, 45) || pHandItem && ITEMS_CheckItemTypeId(pHandItem, 45) && nFlags)
            {
                pWeapon = pHandItem;
            }
            break;
        }

        case 3:
        {
            const int nFrame = pUnit->dwSeqFrame >> 8;
            int bOther;
            if (sub_00463720_TestUnitFlagEx(pUnit, 0x4000000))
            {
                bOther = nFrame % 2;
            }
            else
            {
                bOther = nFrame > 5;
            }

            if (nFrame && (!a2 || bOther))
            {
                pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
            }
            else
            {
                pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
            }
            break;
        }

        case 4:
            pItem = 0;
            break;

        default:
            pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 5);
            if (!pWeapon || !ITEMS_CheckItemTypeId(pWeapon, 45))
            {
                pWeapon = sub_0063C050_GetBodyLocItem(pInventory, 6);
            }
            break;
        }

        if (ITEMS_CheckItemTypeId(pWeapon, 45) && sub_0062A4E0_TestItem(pWeapon))
        {
            return pWeapon;
        }
        return pItem;
    }
    return pItem;
}
