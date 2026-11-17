struct D2UiControlAStrc;
struct D2UiControlBStrc;
struct D2UiControlCStrc;

void __cdecl sub_00453EE0_ClosePanel();                                                                     // 0x00453EE0
void __fastcall sub_004B8100(void* pObj);                                                                   // 0x004B8100
void __cdecl sub_004A02F0_ToggleListDialogUI();                                                             // 0x004A02F0
void __cdecl sub_004B69E0();                                                                                // 0x004B69E0

extern void* gpGlobal_007A27A0;                                                                             // 0x007A27A0
extern D2UiControlAStrc* gpGoldControlA_007A27A4;                                                           // 0x007A27A4
extern D2UiControlBStrc* gpGoldControlB_007A27A8;                                                           // 0x007A27A8
extern D2UiControlCStrc* gpGoldControlC_007A27AC;                                                           // 0x007A27AC
extern D2UiControlCStrc* gpGoldControlD_007A27B0;                                                           // 0x007A27B0
extern int gbGoldPanelFlag_007A27B4;                                                                        // 0x007A27B4

// 0x00454570
void __cdecl sub_00454570_ClearGoldPanel()
{
    gpGlobal_007A27A0 = 0;
    gpGoldControlA_007A27A4 = 0;
    gpGoldControlB_007A27A8 = 0;
    gpGoldControlD_007A27B0 = 0;
    gpGoldControlC_007A27AC = 0;
    gbGoldPanelFlag_007A27B4 = 0;
}

// 0x004545A0
void __cdecl sub_004545A0_ClosePanel()
{
    sub_00453EE0_ClosePanel();
}

// 0x004545B0
void __cdecl sub_004545B0_UpdateGoldPanel()
{
    if (gpGlobal_007A27A0)
        sub_004B8100(gpGlobal_007A27A0);
}

// 0x004549B0
void __cdecl sub_004549B0_ToggleListDialog()
{
    sub_004A02F0_ToggleListDialogUI();
    sub_004B69E0();
}
