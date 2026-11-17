struct D2ActiveRoomStrc;

struct D2LevelsTxt
{
    char unk0x000[0x218];
    unsigned int dwBlankScreen;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern int gdwGlobal_0070F2BC;                                                                              // 0x0070F2BC
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gdwGlobal_007A048C;                                                                              // 0x007A048C
extern int gdwGlobal_007A04A8;                                                                              // 0x007A04A8
extern int gdwGlobal_007A04AC;                                                                              // 0x007A04AC
extern int gdwGlobal_007A04B0;                                                                              // 0x007A04B0
extern int gdwGlobal_007A04B4;                                                                              // 0x007A04B4
extern int gdwGlobal_007A04B8;                                                                              // 0x007A04B8
extern int gdwGlobal_007A061C;                                                                              // 0x007A061C
extern int gdwGlobal_007A0654;                                                                              // 0x007A0654
extern int gdwGlobal_007A0658;                                                                              // 0x007A0658
extern int gdwGlobal_007A0670;                                                                              // 0x007A0670
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C

int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
int __fastcall sub_00456300_CloseUIVars(int bArg1, int nArg2);                                              // 0x00456300
void __fastcall sub_00457640(int bForce);                                                                   // 0x00457640
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __cdecl sub_00466FF0();                                                                                // 0x00466FF0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                          // 0x0061DB70

// 0x0044C100
static __forceinline int sub_0044C100_IsInLeftPanel(int nX, int nY)
{
    int bLeftPanel = 0;
    if (sub_0045AE90() == 2 && nX > 0 && nX < gnGlobal_0071146C / 2 && nY > 0 && nY < gnGlobal_00711470 - 0x2F)
    {
        bLeftPanel = 1;
    }
    return bLeftPanel;
}

// 0x0044C140
static __forceinline int sub_0044C140_IsInRightPanel(int nX, int nY)
{
    int bRightPanel = 0;
    if (sub_0045AE90() == 1 && nX > gnGlobal_0071146C / 2 && nX < gnGlobal_0071146C && nY > 0 && nY < gnAutomapHeight_007A521C)
    {
        bRightPanel = 1;
    }
    return bRightPanel;
}

// 0x0044C340
void __cdecl sub_0044C340_ResetClickState()
{
    gdwGlobal_0070F2BC = 0x10;
    gdwGlobal_007A0654 = 0;
    gdwGlobal_007A0670 = 1;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
}

// 0x0044C6A0
void __cdecl sub_0044C6A0_Nothing()
{
}

// 0x0044C6B0
void __cdecl sub_0044C6B0()
{
    if (gdwGlobal_007A061C && !sub_00456300_CloseUIVars(0, 1))
    {
        sub_00457640(0);
        sub_00456300_CloseUIVars(1, 0);
    }
}

// 0x0044C950
unsigned int __cdecl sub_0044C950_GetLevelBlankScreen()
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (!pRoom)
    {
        return 0;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord, 0x5DE);
    return pLevelsTxtRecord->dwBlankScreen;
}

// 0x0044CD40
void __cdecl sub_0044CD40_ResetTimer()
{
    gdwGlobal_007A04B8 = gdwGlobal_007A048C;
    gdwGlobal_007A04A8 = 0x19;
    gdwGlobal_007A04B0 = 0;
    gdwGlobal_007A04AC = 0;
    gdwGlobal_007A04B4 = 0;
}

int __fastcall sub_M118_Emit_0044C100(int nX, int nY)
{
    const int bLeftPanel = sub_0044C100_IsInLeftPanel(nX, nY);
    const int bRightPanel = sub_0044C140_IsInRightPanel(nX, nY);
    return bLeftPanel || bRightPanel;
}
