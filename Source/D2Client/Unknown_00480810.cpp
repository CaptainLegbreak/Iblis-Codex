#include "D2Structs.h"
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void __fastcall sub_00465F00_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00
void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* unit, int value); // 0x00627460
void __stdcall sub_004DA350_UpdateMotion(D2UnitStrc* unit); // 0x004DA350
void __fastcall sub_00470C30_UpdateStateOverlays(D2UnitStrc* unit); // 0x00470C30
void __fastcall sub_00463390_UpdatePlayerMode(D2UnitStrc* unit); // 0x00463390
void __fastcall sub_004B13A0_UpdateMonsterClient(D2UnitStrc* unit); // 0x004B13A0
void __fastcall sub_004BDFF0_UpdateObject(D2UnitStrc* unit); // 0x004BDFF0
void __fastcall sub_004D2C70_CltDoMissile(D2UnitStrc* unit); // 0x004D2C70
void __fastcall sub_004C1AD0_UpdateAnim(D2UnitStrc* unit); // 0x004C1AD0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0
void __fastcall sub_0045FA40_FreeUnit(D2UnitStrc* unit); // 0x0045FA40

inline int GetUnitType(D2UnitStrc* unit)
{
    return unit ? unit->dwUnitType : UNIT_INVALID;
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
    return (unit->dwFlagEx >> 5) & 1;
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
            sub_004786A0_SendDwords2(0x4B, packetType, packetId);
            unit->dwFlags &= 0xFF7FFFFF;
            unit->dwFlagEx &= 0xFFFFFFDF;
        }
        if (IsServerUnit(unit))
            sub_00465F00_RemoveServerSideUnit(GetUnitId(unit), GetUnitType(unit));
        return;
    }
    STATLIST_UpdateStatListsExpiration(unit, 0);
    sub_004DA350_UpdateMotion(unit);
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
    sub_00470C30_UpdateStateOverlays(unit);
    switch (unit->dwUnitType)
    {
    case UNIT_PLAYER: sub_00463390_UpdatePlayerMode(unit); break;
    case UNIT_MONSTER: sub_004B13A0_UpdateMonsterClient(unit); break;
    case UNIT_OBJECT: sub_004BDFF0_UpdateObject(unit); break;
    case UNIT_MISSILE: sub_004D2C70_CltDoMissile(unit); break;
    case UNIT_ITEM: sub_004C1AD0_UpdateAnim(unit); break;
    }
    D2UnitStrc* found = server ? sub_004639B0_FindServerSideUnit(id, type) : sub_00463990(id, type);
    if (found)
        sub_0045FA40_FreeUnit(found);
}
