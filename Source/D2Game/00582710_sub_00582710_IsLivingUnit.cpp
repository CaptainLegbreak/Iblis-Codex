struct D2UnitStrc { unsigned int type; unsigned char padding[12]; unsigned int mode; };
int __stdcall MONSTERS_IsDead(D2UnitStrc* unit); // 0x0063EA40

// 0x00582710
int __fastcall sub_00582710_IsLivingUnit(D2UnitStrc* unit, void* unused)
{
    int result = 1;
    if (!unit)
        result = 0;
    else if (unit->type == 1)
    {
        if (MONSTERS_IsDead(unit))
            result = 0;
    }
    else if (unit->type != 0 || !unit->mode || unit->mode == 17)
        result = 0;
    return result;
}
