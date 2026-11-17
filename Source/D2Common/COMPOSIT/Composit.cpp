#include "D2Common.h"

#define CP_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2InventoryStrc;
struct D2CompositStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x60 - 8];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC8 - 0x64];
    unsigned int dwFlagEx;
};

struct D2CompositStrc
{
    int nWeaponClassCode;
    int nWeaponClassId;
};

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
int __stdcall COMPOSIT_GetWeaponClassCode(D2UnitStrc* pUnit, int nUnitType, int nClass, int nMode, D2InventoryStrc* pInventory, int* pWeaponClassId); // 0x0064F060
extern const D2CompositStrc gaWeaponClassCodeTable[13]; // 0x006EB748
extern "C" const char gszCompositSourceFile[]; // 0x006EB7B0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// 0x0064F020
int __stdcall COMPOSIT_GetWeaponClassIdFromCode(int nWeaponClassCode)
{
    for (int i = 0; i < 13; ++i)
    {
        if (gaWeaponClassCodeTable[i].nWeaponClassCode == nWeaponClassCode)
        {
            return gaWeaponClassCodeTable[i].nWeaponClassId;
        }
    }

    return 0;
}

// 0x0064F420
int __stdcall COMPOSIT_IsArmorComponent(int nComponent)
{
    return nComponent == 1 || nComponent == 2 || nComponent == 3 || nComponent == 4 || nComponent == 8 || nComponent == 9;
}

// 0x0064F500
unsigned int __stdcall COMPOSIT_GetArmorTypeFromComponent(int nComponent, unsigned char* pArmorComponents)
{
    CP_ASSERT(nComponent < 16, 613);

    switch (nComponent)
    {
    case 1:
        return pArmorComponents[2];

    case 2:
        return pArmorComponents[3];

    case 3:
        return pArmorComponents[0];

    case 4:
        return pArmorComponents[1];

    case 8:
        return pArmorComponents[4];

    case 9:
        return pArmorComponents[5];

    default:
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 628);
        exit(-1);
    }
}

#include "gen/data/Source/D2Common/COMPOSIT/Composit.inc"

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x0064F380
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5)
{
    if (!pUnit)
    {
        return ' hth';
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;

    if (nAnimMode == -1)
    {
        nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    }

    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        const int nMode = nAnimMode;
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\COMPOSIT\\Composit.cpp", 566);

        if (!a5)
        {
            nAnimMode = nMode;
        }
    }

    return COMPOSIT_GetWeaponClassCode(pUnit, nType, nClass, nAnimMode, pInventory, pWeaponClassId);
}

// 0x0064F460
int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    int nMode = -1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);

    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\COMPOSIT\\Composit.cpp", 566);
    }

    COMPOSIT_GetWeaponClassCode(pUnit, nType, nClass, nMode, pInventory, &nWeaponClassId);

    return nWeaponClassId == 1 || nWeaponClassId == 7;
}
