struct D2UnitStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit);                                                 // 0x00451F60
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140

int ganSkillState_007C0A38[128];                                                                            // 0x007C0A38
unsigned long gdwLastTick_007C0C54;                                                                         // 0x007C0C54

// 0x004AB7B0
int __cdecl sub_004AB7B0_CheckTickElapsed()
{
    unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastTick_007C0C54 > 1000)
    {
        gdwLastTick_007C0C54 = dwTick;
        return 1;
    }
    return 0;
}

// 0x004ABF10
void __cdecl sub_004ABF10_ClearSkillStates()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        for (int i = 0; i < SKILLS_GetPlayerSkillCount(sub_00451F60_UnitClassId(pPlayer)); ++i)
        {
            if (ganSkillState_007C0A38[i] == 1)
            {
                ganSkillState_007C0A38[i] = 0;
            }
        }
    }
}
