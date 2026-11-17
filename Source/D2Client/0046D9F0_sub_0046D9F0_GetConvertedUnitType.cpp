struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char pad0x08[0x58];
    D2InventoryStrc* pInventory;
    char pad0x64[0x64];
    unsigned int dwFlagEx;
};

#define UNIT_TYPES_COUNT 6
#define UNITFLAGEX_ISSHAPESHIFTED 0x00000008
#define LINE_ENGINE_TYPE 242
#define LINE_ENGINE_CLASS 278

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

static __forceinline int UNITS_IsShapeshifted_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & UNITFLAGEX_ISSHAPESHIFTED) != 0;
    }

    return 0;
}

// 0x0046D9F0
int __fastcall sub_0046D9F0_GetConvertedUnitType(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
        return pUnit->dwUnitType;
    }

    if (!pUnit)
    {
        return UNIT_TYPES_COUNT;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_TYPE);
    return nType;
}

// 0x0046DAC0
int __fastcall sub_0046DAC0_GetConvertedClassId(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
        return pUnit->dwClassId;
    }

    if (!pUnit)
    {
        return -1;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_CLASS);
    return nClass;
}
