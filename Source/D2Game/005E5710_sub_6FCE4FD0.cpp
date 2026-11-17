struct D2UnitStrc;

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40

// 0x005E5710
void __fastcall sub_6FCE4FD0(D2UnitStrc* pUnit, void* a2, void* a3)
{
    if (!pUnit || MONSTERS_IsDead(pUnit))
    {
        *(int*)a2 = 1;
    }
}
