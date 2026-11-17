struct D2GameStrc;
struct D2UnitStrc { int dwUnitType; unsigned int dwClassId; char pMemoryPool[8]; int dwAnimMode; };
void __fastcall QUESTSFX_Bloodraven(D2GameStrc*, D2UnitStrc*); // 0x005DFD90
void __fastcall QUESTSFX_SpawnMephistoDeathControlMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFDB0
void __fastcall QUESTSFX_Andariel(D2GameStrc*, D2UnitStrc*); // 0x005DFE00
void __fastcall QUESTSFX_SpawnRadamentDeathMissile(D2GameStrc*, D2UnitStrc*); // 0x005DFE20
void __fastcall QUESTSFX_Izual(D2GameStrc*, D2UnitStrc*); // 0x005E0020
void __fastcall QUESTSFX_ShenkTheOverseer(D2GameStrc*, D2UnitStrc*); // 0x005E0040
void __fastcall sub_005E0060_QuestsFxEmpty(D2GameStrc*, D2UnitStrc*); // 0x005E0060
void __fastcall QUESTSFX_UberPrimeEvil(D2GameStrc*, D2UnitStrc*); // 0x005E0070

// 0x005A3250
void __fastcall MONSTERUNIQUE_QuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    switch (!pUnit ? -1 : pUnit->dwClassId)
    {
    case 156:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Andariel(pGame, pUnit);
        break;
    case 229:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnRadamentDeathMissile(pGame, pUnit);
        break;
    case 242:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_SpawnMephistoDeathControlMissile(pGame, pUnit);
        break;
    case 256:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Izual(pGame, pUnit);
        break;
    case 267:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_Bloodraven(pGame, pUnit);
        break;
    case 540:
    case 541:
    case 542:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) sub_005E0060_QuestsFxEmpty(pGame, pUnit);
        break;
    case 479:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_ShenkTheOverseer(pGame, pUnit);
        break;
    case 704:
    case 705:
    case 709:
        if ((!pUnit ? 0 : pUnit->dwAnimMode) == 0) QUESTSFX_UberPrimeEvil(pGame, pUnit);
        break;
    }
}
