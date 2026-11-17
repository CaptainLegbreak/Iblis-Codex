struct D2ActiveRoomStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0xC4 - 0x04];
    unsigned int dwFlags;
};

D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                   // 0x004648F0
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

// 0x004F2060
int __fastcall sub_004F2060_CheckTargetSetFlag(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int bOk = 0;
    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        switch (pTarget->dwUnitType)
        {
        case 0:
        case 1:
            bOk = sub_00465C60_CheckUnitPair(pUnit, pTarget);
            break;
        }
    }

    if (!bOk)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return 1;
}
