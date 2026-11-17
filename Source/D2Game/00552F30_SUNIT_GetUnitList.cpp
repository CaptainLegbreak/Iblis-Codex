struct D2GameStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08;
    int dwUnitId;
};

#define UNIT_LIST_MASK 0x7F

extern const int s_anUnitListOffset_006E10E0[6];                                                            // 0x006E10E0
D2UnitStrc* __stdcall sub_K11_EmitUse(D2UnitStrc** ppList);

// 0x00552F30
static D2UnitStrc** __stdcall SUNIT_GetUnitList(D2GameStrc* pGame, int nUnitType, int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
    {
        return (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }
    return 0;
}

D2UnitStrc* __fastcall sub_K11_Emit00552F30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return sub_K11_EmitUse(SUNIT_GetUnitList(pGame, pUnit->dwUnitType, pUnit->dwUnitId));
}
