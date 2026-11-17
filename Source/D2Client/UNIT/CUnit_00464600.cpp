#include "D2Client.h"

struct D2SkillsTxt
{
    char unk0x00[0x10];
    unsigned char nAnim;
    unsigned char unk0x11[5];
    unsigned char nSeqInput;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[2];
    int dwAnimMode;
    int unk0x14[9];
    int dwSeqFrame;
    int unk0x3C[9];
    D2InventoryStrc* pInventory;
};

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140

struct D2ModeArgStrc
{
    int nValue;
};

// build: context sub_004645B0_CanInterruptSequence
static int __stdcall sub_004645B0_CanInterruptSequence(D2UnitStrc* pUnit, D2ModeArgStrc tUnused)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAnim != 0x12)
    {
        return 1;
    }

    if (!pSkillsTxtRecord->nSeqInput || pSkillsTxtRecord->nSeqInput == 0xFF)
    {
        return 0;
    }

    return (pUnit->dwSeqFrame >> 8) >= pSkillsTxtRecord->nSeqInput;
}

// 0x00464600
int __fastcall sub_00464600_CanStartMode(D2UnitStrc* pUnit, int nArg)
{
    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return 0;
    }

    if (pUnit->dwUnitType != 0)
    {
        return 0;
    }

    switch (pUnit->dwAnimMode)
    {
    case 0:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 17:
    case 19:
        return 0;

    case 18:
    {
        D2ModeArgStrc tArg = { nArg };
        return sub_004645B0_CanInterruptSequence(pUnit, tArg);
    }

    case 13:
        if (pUnit->dwClassId == 3)
        {
            return 0;
        }
        break;

    case 14:
        if (pUnit->dwClassId == 6)
        {
            return 0;
        }
        break;

    case 15:
    case 16:
    {
        const int nClass = pUnit->dwClassId;
        if (nClass == 4 || nClass == 6 || nClass == 5)
        {
            return 0;
        }
        break;
    }

    default:
        break;
    }

    return 1;
}
