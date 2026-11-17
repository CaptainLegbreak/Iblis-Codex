struct D2ActiveRoomStrc;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __stdcall D2GFX_GetResolutionMode();                                                                    // 0x004F5160
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
int __cdecl sub_004F5140();                                                                                 // 0x004F5140
void __cdecl sub_00498630_DrawBorderFrameLeft();                                                            // 0x00498630
void __cdecl sub_00498700_DrawBorderFrameRight();                                                           // 0x00498700
void __cdecl sub_00496F80_DrawLifeOrb();                                                                    // 0x00496F80
void __cdecl sub_00497110_DrawManaOrb();                                                                    // 0x00497110
void __cdecl sub_00498EA0_DrawExperienceBar();                                                              // 0x00498EA0
void __cdecl sub_00497480_DrawButton();                                                                     // 0x00497480
void __cdecl sub_004975B0_DrawStaminaBar();                                                                 // 0x004975B0
void __cdecl sub_004977C0_DrawStateButton();                                                                // 0x004977C0
void __cdecl sub_00499040_DrawBelt();
void __cdecl sub_00496CF0_ValidateActiveSkills();                                                           // 0x00496CF0
void __cdecl sub_00497A40_DrawPanelText();
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom();                                                     // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
extern "C" void __cdecl sub_00498340_UpdateTooltip();                                                       // 0x00498340

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern void* gpBorderFrameCel_007BEF18;                                                                     // 0x007BEF18
void* gpCel_007BEF1C;                                                                                       // 0x007BEF1C
void* gpCel_007BEF74;                                                                                       // 0x007BEF74
extern int gnLevelTimer_007BEFEC;                                                                           // 0x007BEFEC
extern int gnLevelId_007BEFF0;                                                                              // 0x007BEFF0

// 0x004983D0
static __declspec(noinline) void sub_004983D0_DrawControlPanelFrame(int nOffset)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (D2GFX_GetResolutionMode() - 2)
    {
        if (!gpCel_007BEF1C)
        {
            gpCel_007BEF1C = sub_004520C0_LoadUiCelFile("Panel\\CtrlPnl7");
        }
        if (gpCel_007BEF74)
        {
            sub_00478A00(gpCel_007BEF74);
            gpCel_007BEF74 = 0;
        }
        if (gpBorderFrameCel_007BEF18)
        {
            sub_00478A00(gpBorderFrameCel_007BEF18);
            gpBorderFrameCel_007BEF18 = 0;
        }
        tContext.pCellFile = gpCel_007BEF1C;
        tContext.unk0x40 = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, 0, gnGlobal_00711470 - nOffset, -1, 5, 0);
        tContext.nFrame = 1;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x9B, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 2;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x1B, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 3;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x65, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 4;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x75, gnGlobal_00711470 - nOffset, -1, 5, 0);
    }
    else
    {
        if (gpCel_007BEF1C)
        {
            sub_00478A00(gpCel_007BEF1C);
            gpCel_007BEF1C = 0;
        }
        if (!gpCel_007BEF74)
        {
            gpCel_007BEF74 = sub_004520C0_LoadUiCelFile("Panel\\800CtrlPnl7");
        }
        tContext.pCellFile = gpCel_007BEF74;
        tContext.unk0x40 = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, 0, gnGlobal_00711470 - nOffset, -1, 5, 0);
        tContext.nFrame = 1;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xEB, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 2;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0x6B, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 3;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x15, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 4;
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0x95, gnGlobal_00711470, -1, 5, 0);
        tContext.nFrame = 5;
        sub_004F6480(&tContext, gnGlobal_0071146C - 0x75, gnGlobal_00711470 - nOffset, -1, 5, 0);
    }
}

// 0x00499450
void __cdecl sub_00499450_DrawControlPanel()
{
    int nOffset = 0;
    if (sub_004F5140() == 3)
    {
        nOffset = 1;
    }
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (sub_0045AE90() == 2 || sub_0045AE90() == 3)
        {
            sub_00498630_DrawBorderFrameLeft();
        }
        if (sub_0045AE90() == 1 || sub_0045AE90() == 3)
        {
            sub_00498700_DrawBorderFrameRight();
        }
    }
    sub_004983D0_DrawControlPanelFrame(nOffset);
    sub_00496F80_DrawLifeOrb();
    sub_00497110_DrawManaOrb();
    sub_00498EA0_DrawExperienceBar();
    sub_00497480_DrawButton();
    sub_004975B0_DrawStaminaBar();
    sub_004977C0_DrawStateButton();
    sub_00499040_DrawBelt();
    sub_00496CF0_ValidateActiveSkills();
    sub_00497A40_DrawPanelText();
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (gnLevelId_007BEFF0 != nLevelId)
        {
            gnLevelId_007BEFF0 = nLevelId;
            gnLevelTimer_007BEFEC = 0x3C;
        }
    }
    sub_00498340_UpdateTooltip();
}
