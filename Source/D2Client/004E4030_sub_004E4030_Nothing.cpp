struct D2DrlgActStrc;

int __stdcall ENVIRONMENT_GetCycleIndexFromAct(D2DrlgActStrc* pAct);                                        // 0x0061C220
void __fastcall sub_00482370(int nId);                                                                      // 0x00482370
extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634

// 0x004E4030
void __cdecl sub_004E4030_Nothing()
{
}

// 0x004E41E0
int __cdecl sub_004E41E0_IsCycleOutside1To3()
{
    const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct_007A0634);
    return nCycle < 1 || nCycle > 3;
}

// 0x004E4220
void __cdecl sub_004E4220_TouchRange()
{
    for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
    {
        sub_00482370(nId);
    }
}
