#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"
#include "D2ClientUiRecords.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
struct Unicode;
struct D2HotkeySlotTableStrc;
struct D2SkillsTxt;
struct D2SkillIconStateStrc;
struct D2UiCelFileStrc;
struct D2WeatherLayerStateStrc;
struct D2MonsterDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __cdecl GAME_ResetMouseState(); // 0x0044DA40

extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300
extern int gbSkillSelectRight; // 0x007C07FC
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyOwners[16]; // 0x007C0768
extern int gaHotkeyLeft[16]; // 0x007C07B8

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140
extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2SkillIconStateStrc gtHotkeySlots; // 0x007C0300

struct D2WeatherLayerStateStrc
{
    void* apCelFiles[4];
};

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry); // 0x004B1680
extern unsigned char gnCharClass; // 0x007A0522
extern D2UiCelFileStrc gaPanelCels[7]; // 0x00724BF0
extern D2WeatherLayerStateStrc gtSplashCels; // 0x007A89B0
extern D2WeatherLayerStateStrc gtBubbleCels; // 0x007A893C
extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
extern int gnAutomapWidth; // 0x007A5220
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

int gnSelectedHotkey; // 0x007C0708

static int SPELLSEL_IsHotkeyUsable(int nSlot); // 0x004A9FC0



static void SPELLSEL_AssignFreeHotkey(int nSlot, int nIndex); // 0x004AA0F0



unsigned char gbNpcEntriesProcessed; // 0x007C0C6A



// 0x004B17A0
void __cdecl sub_004B17A0()
{
// build: symbol ?gnNpcEntryCount@* 0x0072554C
    for (int i = 0; i < gnNpcEntryCount; ++i)
        sub_004B1680(&gaNpcEntries[i]);
    gbNpcEntriesProcessed = 1;
}

// 0x004B1D70
int __cdecl sub_004B1D70_FindNpcEntry()
{
    int i = 0;
    int bFound = 0;
    while (i < gnNpcEntryCount && !bFound)
    {
// build: symbol ?gnInteractNpcClassId@* 0x007C0D2D
        if (gaNpcEntries[i].nId == gnInteractNpcClassId)
            bFound = 1;
        else
            ++i;
    }

    if (bFound == 1)
        return i;
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_004A9BD0.inc"




