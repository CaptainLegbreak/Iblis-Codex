#include "D2GameTypes.h"


int __fastcall EXCEPTIONS_ReleaseSymbols(int nArg);                                                                      // 0x0040C720
void __fastcall CMDTBL_ResetKeyConfig(int nArg);                                                                     // 0x00469A60
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel);                                                                   // 0x00478A00
extern "C" void __cdecl sub_00517ABB(void* pMemory);                                                        // 0x00517ABB

extern void* gpCelFile_007C02BC;                                                                            // 0x007C02BC

// 0x0040D530
int __cdecl sub_0040D530_Call0040C720()
{
    return EXCEPTIONS_ReleaseSymbols(1);
}

// 0x004A5010
void __cdecl TEXT_ResetKeyConfigDefaults()
{
    CMDTBL_ResetKeyConfig(0);
}

// 0x004A51E0
void __cdecl TEXT_FreeTextSliderCel()
{
    if (gpCelFile_007C02BC)
    {
        ARCHIVE_FreeClientCellFile(gpCelFile_007C02BC);
        gpCelFile_007C02BC = 0;
    }
}

// 0x005EF1E0
int __fastcall AITHINK_BaalThroneCheckAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}

void __fastcall sub_00600C60_CallFree(void* pMemory); // 0x00600C60
