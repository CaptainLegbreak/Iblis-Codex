#include "D2GameTypes.h"


int __fastcall sub_0040C720_ReleaseReferences(int nArg);                                                                      // 0x0040C720
void __fastcall sub_00469A60_ResetKeyConfig(int nArg);                                                                     // 0x00469A60
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
extern "C" void __cdecl sub_00517ABB(void* pMemory);                                                        // 0x00517ABB

extern void* gpCelFile_007C02BC;                                                                            // 0x007C02BC

// 0x0040D530
int __cdecl sub_0040D530_Call0040C720()
{
    return sub_0040C720_ReleaseReferences(1);
}

// 0x004A5010
void __cdecl sub_004A5010_Call00469A60()
{
    sub_00469A60_ResetKeyConfig(0);
}

// 0x004A51E0
void __cdecl sub_004A51E0_FreeCelFile()
{
    if (gpCelFile_007C02BC)
    {
        sub_00478A00(gpCelFile_007C02BC);
        gpCelFile_007C02BC = 0;
    }
}

// 0x005EF1E0
int __fastcall sub_005EF1E0_BaalThroneGetAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}

// build: context sub_00600C60_CallFree
void __fastcall sub_00600C60_CallFree(void* pMemory)
{
    sub_00517ABB(pMemory);
}
