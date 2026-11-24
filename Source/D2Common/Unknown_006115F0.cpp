#include "D2Common.h"
#include "D2ProfileCounter.h"

struct D2GameStrc;
struct D2ProfileCounterStrc;


typedef int (__cdecl* PROFHOOK0096BC24FN)();

extern D2ProfileCounterStrc gaProfEntries[23]; // 0x00743800
void __cdecl PROFCORE_WriteProfileCounters(); // 0x006116B0
void __cdecl LOGGING_CloseLog(); // 0x00624B20
extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC; // 0x0096C7CC
extern D2TxtLinkStrc* gpMissilesLinker_0096C798; // 0x0096C798
extern D2TxtLinkStrc* gpSkillCalcLinker_0096BC6C; // 0x0096BC6C
extern D2TxtLinkStrc* gpMissileCalcLinker_0096BC8C; // 0x0096BC8C
int __stdcall FOG_GetLinkIndex(D2TxtLinkStrc* pLinker, unsigned int dwCode, int bLogError); // 0x006BD130

// 0x006115F0
void __cdecl sub_006115F0_Empty()
{
}

PROFHOOK0096BC24FN gpfnProfSecondaryHook; // 0x0096BC24

#include "gen/data/Source/D2Common/Unknown_006115F0.inc"
