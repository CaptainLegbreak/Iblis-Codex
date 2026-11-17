struct D2Device006B2030Strc;
struct D2DeviceVtbl006B2030Strc
{
    void* unk_00[40];
    long (__stdcall* SetTextureStageState)(D2Device006B2030Strc* pDevice, unsigned long nStage, unsigned long nType, unsigned long nValue);
};
struct D2Device006B2030Strc
{
    D2DeviceVtbl006B2030Strc* lpVtbl;
};
int gnFilterMode_00970E5C;        // 0x00970E5C
extern D2Device006B2030Strc* gpDevice_00970E78; // 0x00970E78

// 0x006B2030
void __fastcall sub_006B2030_SetFilterMode(int nMode)
{
    if (gnFilterMode_00970E5C && nMode == gnFilterMode_00970E5C)
    {
        return;
    }
    switch (nMode)
    {
    case 1:
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 16, 1);
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 17, 1);
        break;
    case 2:
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 16, 2);
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 17, 2);
        break;
    }
    gnFilterMode_00970E5C = nMode;
}
