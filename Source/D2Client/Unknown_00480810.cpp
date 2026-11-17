struct D2UnitStrc {
    int dwUnitType; unsigned char pad04[8]; int dwUnitId;
    unsigned char pad10[0xB4]; unsigned int dwFlags, dwFlagsEx;
};
D2UnitStrc* __fastcall sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_004786A0_SendUnitPacket(unsigned char header, int type, int id); // 0x004786A0
void __fastcall sub_00465F00_RemoveUnit(int id, int type); // 0x00465F00
void __stdcall sub_00627460_SetUnitValue(D2UnitStrc* unit, int value); // 0x00627460
void __stdcall sub_004DA350_ClearUnit(D2UnitStrc* unit); // 0x004DA350
void __fastcall sub_00470C30_ReleaseUnitState(D2UnitStrc* unit); // 0x00470C30
void __fastcall sub_00463390_ReleasePlayer(D2UnitStrc* unit); // 0x00463390
void __fastcall sub_004B13A0_ReleaseMonster(D2UnitStrc* unit); // 0x004B13A0
void __fastcall sub_004BDFF0_ReleaseObject(D2UnitStrc* unit); // 0x004BDFF0
void __fastcall sub_004D2C70_ReleaseMissile(D2UnitStrc* unit); // 0x004D2C70
void __fastcall sub_004C1AD0_ReleaseItem(D2UnitStrc* unit); // 0x004C1AD0
D2UnitStrc* __fastcall sub_00463990_FindUnit(int id, int type); // 0x00463990
D2UnitStrc* __fastcall sub_004639B0_FindServerUnit(int id, int type); // 0x004639B0
void __fastcall sub_0045FA40_FreeUnit(D2UnitStrc* unit); // 0x0045FA40

inline int GetUnitType(D2UnitStrc* unit)
{
    return unit ? unit->dwUnitType : 6;
}
inline int GetUnitId(D2UnitStrc* unit)
{
    return unit ? unit->dwUnitId : -1;
}
inline int IsDeferredUnit(D2UnitStrc* unit)
{
    if (!unit) return 0;
    return (unit->dwFlags >> 23) & 1;
}
inline int HasQueuedUnitPacket(D2UnitStrc* unit)
{
    if (!unit) return 0;
    return (unit->dwFlagsEx >> 5) & 1;
}
inline int IsServerUnit(D2UnitStrc* unit)
{
    if (!unit) return 0;
    return (unit->dwFlags >> 21) & 1;
}

// 0x00480810
void __fastcall sub_00480810_OnUnitA(D2UnitStrc* unit)
{
    if (sub_00463DD0_GetPlayerUnit() != unit && IsDeferredUnit(unit))
    {
        if (HasQueuedUnitPacket(unit))
        {
            const int packetId = GetUnitId(unit);
            const int packetType = GetUnitType(unit);
            sub_004786A0_SendUnitPacket(0x4B, packetType, packetId);
            unit->dwFlags &= 0xFF7FFFFF;
            unit->dwFlagsEx &= 0xFFFFFFDF;
        }
        if (IsServerUnit(unit))
            sub_00465F00_RemoveUnit(GetUnitId(unit), GetUnitType(unit));
        return;
    }
    sub_00627460_SetUnitValue(unit, 0);
    sub_004DA350_ClearUnit(unit);
    int type, server;
    int id;
    if (!unit)
    {
        id = -1;
        type = 6;
        server = 0;
    }
    else
    {
        server = unit->dwFlags >> 21;
        type = unit->dwUnitType;
        id = unit->dwUnitId;
        server &= 1;
    }
    sub_00470C30_ReleaseUnitState(unit);
    switch (unit->dwUnitType)
    {
    case 0: sub_00463390_ReleasePlayer(unit); break;
    case 1: sub_004B13A0_ReleaseMonster(unit); break;
    case 2: sub_004BDFF0_ReleaseObject(unit); break;
    case 3: sub_004D2C70_ReleaseMissile(unit); break;
    case 4: sub_004C1AD0_ReleaseItem(unit); break;
    }
    D2UnitStrc* found = server ? sub_004639B0_FindServerUnit(id, type) : sub_00463990_FindUnit(id, type);
    if (found)
        sub_0045FA40_FreeUnit(found);
}
