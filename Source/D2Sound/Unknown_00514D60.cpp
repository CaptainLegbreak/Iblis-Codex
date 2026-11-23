#include "D2Sound.h"

extern int gnNpcSpeech;                                                                              // 0x008817BC

// 0x00514D60
int __fastcall sub_00514D60_SetNpcSpeech(int nValue)
{
    SRegSaveValue("Diablo II", "NPC Speech", 0, nValue);
    gnNpcSpeech = nValue;
    return nValue;
}
