#include "D2Client.h"

struct D2GameStrc;

struct D2AutomapRecordStrc
{
    unsigned int nUnk0x00;
    unsigned int nValue;
};

typedef void (__stdcall* AUTOMAPFN)(void* pRoom);
typedef void (__stdcall* TOWNAUTOMAPFN)(int nLevelId, int nPickedFile, int nX, int nY);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

void __stdcall sub_0044DB60_PreloadActTiles(unsigned char nAct);                                            // 0x0044DB60
void __cdecl sub_00452130_InitColors();                                                                     // 0x00452130
void __fastcall sub_00454790_SetValue(int nValue);                                                          // 0x00454790
void __fastcall sub_004565E0_DrawLoadingScreen(int bAdvanceFrame);                                          // 0x004565E0
void __stdcall sub_00459150_RevealRoomCallback(D2ActiveRoomStrc* pRoom);
void __stdcall sub_004591A0_AddTownCelsCallback(int nLevelId, int nPickedFile, int nX, int nY);
void __cdecl sub_0045A620_InitAutomapColors();                                                              // 0x0045A620
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom();                                                     // 0x004646A0
void __fastcall sub_0046F310_LoadGlobalHashedFile(unsigned char nIndex);                                    // 0x0046F310
void __cdecl sub_0046F440_FreeHashedFileB();                                                                // 0x0046F440
void __cdecl sub_00475B40_InitLightTables();                                                                // 0x00475B40
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap);   // 0x006194A0
unsigned long gdwDelayEnd_007A04BC;                                                                         // 0x007A04BC
extern unsigned char gnDifficulty_007A060C;                                                                 // 0x007A060C
unsigned char gbEnvironmentPending_007A060E;                                                                // 0x007A060E
D2DrlgActStrc* gpAct_007A0634;                                                                              // 0x007A0634
D2AutomapRecordStrc* gpAutomapRecord_007A0638;                                                              // 0x007A0638
int gnTownLevelId_007A063C;                                                                                 // 0x007A063C

// 0x0044E100
void __fastcall sub_0044E100_LoadAct(unsigned char nAct, unsigned int dwGameSeed, unsigned int dwObjectSeed, int nTownLevelId)
{
    sub_0044DB60_PreloadActTiles(nAct);
    if (gpAct_007A0634)
        DUNGEON_FreeAct(gpAct_007A0634);

    gpAct_007A0634 = DUNGEON_AllocAct(nAct, dwGameSeed, 1, 0, gnDifficulty_007A060C, 0, nTownLevelId,
        (AUTOMAPFN)sub_00459150_RevealRoomCallback, sub_004591A0_AddTownCelsCallback);

    if (gbEnvironmentPending_007A060E && nAct == 1 && gpAct_007A0634)
        ENVIRONMENT_InitializeEnvironment(gpAct_007A0634, sub_004646A0_GetPlayerRoom(), 5, 0, 1);

    gbEnvironmentPending_007A060E = 0;
    sub_00454790_SetValue(nAct);
    sub_004565E0_DrawLoadingScreen(1);

    *gpAutomapRecord_007A0638 = D2AutomapRecordStrc();
    gpAutomapRecord_007A0638->nUnk0x00 = dwGameSeed;
    gpAutomapRecord_007A0638->nValue = dwObjectSeed;

    sub_0045A620_InitAutomapColors();
    sub_00475B40_InitLightTables();
    sub_00452130_InitColors();
    gnTownLevelId_007A063C = nTownLevelId;
    sub_0046F440_FreeHashedFileB();
    sub_0046F310_LoadGlobalHashedFile(nAct);
    gnClearScreenCount_0070F2C0 = 1;

    const unsigned long dwEnd = GetTickCount() + 10000;
    if (dwEnd > gdwDelayEnd_007A04BC)
        gdwDelayEnd_007A04BC = dwEnd;
}
