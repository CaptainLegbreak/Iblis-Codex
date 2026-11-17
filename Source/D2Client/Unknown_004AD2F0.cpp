struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    unsigned int dwUnitId;
    unsigned int dwAnimMode;
};

void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit);                                             // 0x0046B3C0
void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit);                                       // 0x0046B530
void __fastcall sub_0046B680_SpawnMissileTrio(D2UnitStrc* pUnit);                                           // 0x0046B680
void __fastcall sub_0046B710(D2UnitStrc* pUnit);                                                            // 0x0046B710
void __fastcall sub_0046B850(D2UnitStrc* pUnit);                                                            // 0x0046B850
void __fastcall sub_0046B9A0_SpawnMissileTrio2(D2UnitStrc* pUnit);                                          // 0x0046B9A0
void __fastcall sub_0046BA50_SpawnMissile(D2UnitStrc* pUnit);                                               // 0x0046BA50
void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit);                                     // 0x0046BA90
void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit);                                     // 0x0046BB10
void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit);                                     // 0x0046BB90
void __fastcall sub_0046BC10_HintAndMissile(D2UnitStrc* pUnit);                                             // 0x0046BC10
int __fastcall sub_0046BC70_SetTimerUnitId(D2UnitStrc* pUnit);                                              // 0x0046BC70
void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit);                                        // 0x0046BC90

// 0x004AD2F0
void __fastcall sub_004AD2F0_UnitClassEvent(D2UnitStrc* pUnit, int nUnused, int nUnused2)
{
    if (!pUnit)
    {
        return;
    }

    switch (pUnit->dwClassId)
    {
    case 0x9C:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BA50_SpawnMissile(pUnit);
        }
        break;

    case 0x2D:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B710(pUnit);
        }
        break;

    case 0xE5:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BA90_PlayerRequestAtUnit15B(pUnit);
        }
        break;

    case 0xD3:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BB90_PlayerRequestAtUnit16B(pUnit);
        }
        break;

    case 0xF2:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B9A0_SpawnMissileTrio2(pUnit);
        }
        break;

    case 0xF3:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BC70_SetTimerUnitId(pUnit);
        }
        break;

    case 0x100:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BC10_HintAndMissile(pUnit);
        }
        break;

    case 0x16E:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B850(pUnit);
        }
        break;

    case 0x11C:
        if (pUnit->dwAnimMode == 0x0E)
        {
            sub_0046BB10_PlayerRequestAtUnit161(pUnit);
        }
        break;

    case 0x10B:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B680_SpawnMissileTrio(pUnit);
        }
        break;

    case 0x1DF:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B3C0_UnitRequest25A(pUnit);
        }
        break;

    case 0x220:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BC90_RequestAtMonster220(pUnit);
        }
        break;

    case 0x21C:
    case 0x21D:
    case 0x21E:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B530_SpawnMissileAtObject(pUnit);
        }
        break;
    }
}
