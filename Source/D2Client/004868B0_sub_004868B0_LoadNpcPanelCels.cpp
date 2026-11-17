struct D2InventoryStrc;
struct D2CellFileStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2NpcButtonStrc
{
    int nId;
    int bActive;
    char unk0x08[0x0C];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl sub_0044DB30();                                                                                 // 0x0044DB30
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __cdecl sub_00468830();                                                                                 // 0x00468830
void __fastcall sub_00478590(char nValue);                                                                  // 0x00478590
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __fastcall sub_00480930(int nType, int nUnitId);                                                       // 0x00480930
void __cdecl sub_004B90B0();                                                                                // 0x004B90B0
int __cdecl sub_004B9180();                                                                                 // 0x004B9180
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __fastcall sub_004C21F0(D2UnitStrc* pItem);                                                            // 0x004C21F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gnGlobal_00721E4C;                                                                               // 0x00721E4C
extern int gnGlobal_00721E50;                                                                               // 0x00721E50
extern int gnGlobal_00721E54;                                                                               // 0x00721E54
extern int gnButtonCount_00722160;                                                                          // 0x00722160
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
D2NpcButtonStrc gaNpcButtons_007BC9E0[4];                                                                   // 0x007BC9E0
int gnGlobal_007BCA48;                                                                                      // 0x007BCA48
extern int gnGlobal_007BCA4C;                                                                               // 0x007BCA4C
extern int gnGlobal_007BCAF0;                                                                               // 0x007BCAF0
D2CellFileStrc* gpCellFile_007BCB04;                                                                        // 0x007BCB04
extern int gnGlobal_007BCBD8;                                                                               // 0x007BCBD8
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
int gdwGlobal_007BCBF0;                                                                                     // 0x007BCBF0
extern int gdwGlobal_007BCBF4;                                                                              // 0x007BCBF4
extern int gdwGlobal_007BCBF8;                                                                              // 0x007BCBF8
extern unsigned char gnSelectedTab_007BCC04;                                                                // 0x007BCC04
int gbQuestTimerActive_007BCC10;                                                                            // 0x007BCC10
extern int gnQuestTimerValue_007BCC14;                                                                      // 0x007BCC14
extern unsigned long gdwQuestTimerTicks_007BCC18;                                                           // 0x007BCC18
D2CellFileStrc* gpHoradricCel_007BCC1C;                                                                     // 0x007BCC1C
extern D2CellFileStrc* gpCellFile_007BCC24;                                                                 // 0x007BCC24
extern D2CellFileStrc* gpCellFile_007BCC28;                                                                 // 0x007BCC28
void* gpCelGoldCoinBtn_007BCC34;                                                                            // 0x007BCC34
extern D2CellFileStrc* gpCellFile_007BCC38;                                                                 // 0x007BCC38
int gnGlobal_007BCC40;                                                                                      // 0x007BCC40
extern int gnGlobal_007BCC4C;                                                                               // 0x007BCC4C
int gnGlobal_007BCC50;                                                                                      // 0x007BCC50
int gnGlobal_007BCC54;                                                                                      // 0x007BCC54
extern int gnGlobal_007BCD34;                                                                               // 0x007BCD34
extern int gnGlobal_007BCE14;                                                                               // 0x007BCE14
extern "C" int gnFlag_007BCE28;                                                                             // 0x007BCE28
extern int gnGlobal_007BCE30;                                                                               // 0x007BCE30
void* gpCelInvArmor_007BCE68;                                                                               // 0x007BCE68
void* gpCelInvBelt_007BCE6C;                                                                                // 0x007BCE6C
void* gpCelInvBoots_007BCE70;                                                                               // 0x007BCE70
void* gpCelInvHelmGlove_007BCE74;                                                                           // 0x007BCE74
void* gpCelInvRingAmulet_007BCE78;                                                                          // 0x007BCE78
void* gpCelInvWeapons_007BCE7C;                                                                             // 0x007BCE7C
void* gpCelTradeBtn_007BCE80;                                                                               // 0x007BCE80
void* gpCelInvChar6Tab_007BCE84;                                                                            // 0x007BCE84
void* gpCelNpcInv_007BCE88;                                                                                 // 0x007BCE88
extern void* gpCel_007BCE8C;                                                                                // 0x007BCE8C
static int gbGlobal_007BCE90;                                                                               // 0x007BCE90
extern int gnGlobal_007BCE9C;                                                                               // 0x007BCE9C

// 0x004868B0
void __cdecl sub_004868B0_LoadNpcPanelCels()
{
    gpCelInvArmor_007BCE68 = sub_004520C0_LoadUiCelFile("Panel\\inv_armor");
    gpCelInvBelt_007BCE6C = sub_004520C0_LoadUiCelFile("Panel\\inv_belt");
    gpCelInvBoots_007BCE70 = sub_004520C0_LoadUiCelFile("Panel\\inv_boots");
    gpCelInvHelmGlove_007BCE74 = sub_004520C0_LoadUiCelFile("Panel\\inv_helm_glove");
    gpCelInvRingAmulet_007BCE78 = sub_004520C0_LoadUiCelFile("Panel\\inv_ring_amulet");
    gpCelInvWeapons_007BCE7C = sub_004520C0_LoadUiCelFile("Panel\\inv_weapons");
    gpCelTradeBtn_007BCE80 = sub_004520C0_LoadUiCelFile("Panel\\tradebtn");
    gpCelGoldCoinBtn_007BCC34 = sub_004520C0_LoadUiCelFile("Panel\\goldcoinbtn");
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        gpCelInvChar6Tab_007BCE84 = sub_004520C0_LoadUiCelFile("Panel\\invchar6Tab");
        gnGlobal_007BCC4C = 0;
        gpCelNpcInv_007BCE88 = sub_004520C0_LoadUiCelFile("Panel\\NPCInv");
    }
    else
    {
        gpCelInvChar6Tab_007BCE84 = 0;
        gnGlobal_007BCC4C = 0;
        gpCelNpcInv_007BCE88 = 0;
    }
}

// 0x00486980
void __cdecl sub_00486980_FreeNpcPanelCels()
{
    if (gpHoradricCel_007BCC1C)
    {
        sub_00478A00(gpHoradricCel_007BCC1C);
        gpHoradricCel_007BCC1C = 0;
    }
    if (gpCelInvArmor_007BCE68)
    {
        sub_00478A00(gpCelInvArmor_007BCE68);
        gpCelInvArmor_007BCE68 = 0;
    }
    if (gpCelInvBelt_007BCE6C)
    {
        sub_00478A00(gpCelInvBelt_007BCE6C);
        gpCelInvBelt_007BCE6C = 0;
    }
    if (gpCelInvBoots_007BCE70)
    {
        sub_00478A00(gpCelInvBoots_007BCE70);
        gpCelInvBoots_007BCE70 = 0;
    }
    if (gpCelInvHelmGlove_007BCE74)
    {
        sub_00478A00(gpCelInvHelmGlove_007BCE74);
        gpCelInvHelmGlove_007BCE74 = 0;
    }
    if (gpCelInvRingAmulet_007BCE78)
    {
        sub_00478A00(gpCelInvRingAmulet_007BCE78);
        gpCelInvRingAmulet_007BCE78 = 0;
    }
    if (gpCelInvWeapons_007BCE7C)
    {
        sub_00478A00(gpCelInvWeapons_007BCE7C);
        gpCelInvWeapons_007BCE7C = 0;
    }
    if (gpCelTradeBtn_007BCE80)
    {
        sub_00478A00(gpCelTradeBtn_007BCE80);
        gpCelTradeBtn_007BCE80 = 0;
    }
    if (gpCelGoldCoinBtn_007BCC34)
    {
        sub_00478A00(gpCelGoldCoinBtn_007BCC34);
        gpCelGoldCoinBtn_007BCC34 = 0;
    }
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0() && gpCelInvChar6Tab_007BCE84)
    {
        sub_00478A00(gpCelInvChar6Tab_007BCE84);
        gpCelInvChar6Tab_007BCE84 = 0;
    }
    if (gpCelNpcInv_007BCE88)
    {
        sub_00478A00(gpCelNpcInv_007BCE88);
        gpCelNpcInv_007BCE88 = 0;
    }
    if (gpCel_007BCE8C)
    {
        sub_00478A00(gpCel_007BCE8C);
        gpCel_007BCE8C = 0;
    }
    gpCelInvArmor_007BCE68 = 0;
    gpCelInvBelt_007BCE6C = 0;
    gpCelInvBoots_007BCE70 = 0;
    gpCelInvHelmGlove_007BCE74 = 0;
    gpCelInvRingAmulet_007BCE78 = 0;
    gpCelInvWeapons_007BCE7C = 0;
    gpCelTradeBtn_007BCE80 = 0;
    gpCelGoldCoinBtn_007BCC34 = 0;
}

// 0x00486AE0
int __cdecl sub_00486AE0_GetPanelX()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_007A2858 + 0x113;
    }
    return gnGlobal_007A2858 + 0x110;
}

// 0x00486B30
int __cdecl sub_00486B30_IsNpcStateA()
{
    switch (gdwGlobal_007BCBF0)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
        return 0;
    }
    return 0;
}

// 0x00486B80
int __cdecl sub_00486B80_IsNpcStateB()
{
    switch (gdwGlobal_007BCBF0)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
    case 0x11:
        return 0;
    }
    return 0;
}

// 0x00486D10
int __cdecl sub_00486D10_CheckTick()
{
    if (!sub_0044DB30() || sub_0044DB30() == 1)
    {
        return 1;
    }
    if (sub_004B9180())
    {
        sub_004B90B0();
        return 0;
    }
    if (GetTickCount() - gnGlobal_007BCA48 > 0xFA)
    {
        gnGlobal_007BCA48 = GetTickCount();
        return 1;
    }
    return 0;
}

// 0x00486E10
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E || nX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x10E)
    {
        return 0;
    }
    if (nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x60 || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 0;
    }
    return 1;
}

// 0x00487990
void __cdecl sub_00487990_ResetHover()
{
    gnGlobal_00721E3C = -1;
    gnGlobal_00721E40 = -1;
    gnGlobal_00721E44 = -1;
    gnGlobal_00721E48 = -1;
    gnGlobal_00721E4C = -1;
    gnGlobal_00721E50 = -1;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
}

// 0x00487B30
void __cdecl sub_00487B30_ResetNpcState()
{
    gdwGlobal_007BCBF0 = 0;
    gnSelectedTab_007BCC04 = 0;
    gnGlobal_007BCE30 = 0;
    gnGlobal_007BCA4C = 0;
    gnGlobal_007BCBD8 = 0;
    if (gpCellFile_007BCB04)
    {
        sub_00478A00(gpCellFile_007BCB04);
        gpCellFile_007BCB04 = 0;
    }
    gnGlobal_007BCA48 = 0;
}

// 0x00487B80
void __cdecl sub_00487B80_SetNpcStateTrade()
{
    gnSelectedTab_007BCC04 = 0;
    gdwGlobal_007BCBF0 = 0x13;
}

// 0x00487BE0
int __cdecl sub_00487BE0_ResetButtons()
{
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    return 1;
}

// 0x00487C20
void __cdecl sub_00487C20_ResetButtonsFromState5()
{
    if (gdwGlobal_007BCBF0 == 5)
    {
        gaNpcButtons_007BC9E0[0].bActive = 0;
        gaNpcButtons_007BC9E0[1].bActive = 0;
        gaNpcButtons_007BC9E0[2].bActive = 0;
        gaNpcButtons_007BC9E0[3].bActive = 0;
        gdwGlobal_007BCBF0 = 1;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    }
}

// 0x00487C60
void __cdecl sub_00487C60_SetNpcState6()
{
    D2_ASSERT(gdwGlobal_007BCBF0 == 5, 0x1EA1);
    gdwGlobal_007BCBF0 = 6;
}

// 0x00487CC0
void __cdecl sub_00487CC0_SelectFirstButton()
{
    gnGlobal_007BCC40 = -1;
    for (int i = 0; i < gnButtonCount_00722160; ++i)
    {
        if (gaNpcButtons_007BC9E0[i].bActive)
        {
            gnGlobal_007BCC40 = i;
            break;
        }
    }
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
}

// 0x00487D30
void __cdecl sub_00487D30_SetNpcState7()
{
    gdwGlobal_007BCBF0 = 7;
}

// 0x00487D40
void __cdecl sub_00487D40_ResetButtonsFromState7()
{
    D2_ASSERT(gdwGlobal_007BCBF0 == 7, 0x1ED3);
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
}

// 0x004888C0
int __cdecl sub_004888C0_CanUseCursor()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4 || gdwGlobal_007BCBF0 == 3)
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
        {
            return 0;
        }
        const int nMode = sub_00468830();
        if (nMode == 7 || nMode == 1 || nMode == 4)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00489190
int __fastcall sub_00489190_ClickNpcPanel(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gbGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

// 0x004892F0
void __cdecl sub_004892F0_FreeNpcCels()
{
    if (gpCellFile_007BCB04)
    {
        sub_00478A00(gpCellFile_007BCB04);
        gpCellFile_007BCB04 = 0;
    }
    if (gpCellFile_007BCC24)
    {
        sub_00478A00(gpCellFile_007BCC24);
        gpCellFile_007BCC24 = 0;
    }
    if (gpCellFile_007BCC28)
    {
        sub_00478A00(gpCellFile_007BCC28);
        gpCellFile_007BCC28 = 0;
    }
    if (sub_0044DCC0() && gpCellFile_007BCC38)
    {
        sub_00478A00(gpCellFile_007BCC38);
        gpCellFile_007BCC38 = 0;
    }
}

// 0x004897E0
void __fastcall sub_004897E0_UpdateSound(int bFirst, int bSecond)
{
    if ((gnGlobal_007BCD34 || gnGlobal_007BCE14) && (!bFirst || !bSecond))
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    else if ((!gnGlobal_007BCD34 && bFirst) || (bSecond && !gnGlobal_007BCE14))
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    gnGlobal_007BCD34 = bFirst;
    gnGlobal_007BCE14 = bSecond;
}

// 0x00489860
int __cdecl sub_00489860_IsNpcState4()
{
    return gdwGlobal_007BCBF0 == 4;
}

// 0x0048A050
void __cdecl sub_0048A050_CloseQuestPanel()
{
    gbQuestTimerActive_007BCC10 = 0;
    sub_00455F20(0x1A, 1, 0);
    if (!gnGlobal_007BCC54)
    {
        sub_00478600_SendShorts(0x4F, 0x17, 0, 0);
        gnGlobal_007BCC54 = 1;
    }
    if (gnGlobal_007BCC50)
    {
        if (sub_00463990(gnGlobal_00721E54, 2))
        {
            sub_00480930(2, gnGlobal_00721E54);
        }
        gnGlobal_007BCC50 = 0;
    }
}

// 0x0048A600
void __cdecl sub_0048A600_FreeHoradricCel()
{
    if (gpHoradricCel_007BCC1C)
    {
        sub_00478A00(gpHoradricCel_007BCC1C);
        gpHoradricCel_007BCC1C = 0;
    }
    gbQuestTimerActive_007BCC10 = 0;
    gnQuestTimerValue_007BCC14 = 0;
    gdwQuestTimerTicks_007BCC18 = 0;
}

// 0x0048A680
void __cdecl sub_0048A680_Clear()
{
    gnGlobal_007BCAF0 = 0;
}

// 0x0048A6A0
void __cdecl sub_0048A6A0_ResetNpcCursor()
{
    gnGlobal_007BCE9C = 0;
    gdwGlobal_007BCBF0 = 0;
    gnGlobal_007BCA4C = 0;
    gnGlobal_007BCBD8 = 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || !INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        sub_00468070_SetCursorItemState(0);
    }
}

// 0x0048A6F0
void __cdecl sub_0048A6F0_Clear()
{
    gnFlag_007BCE28 = 0;
}

// 0x0048A730
void __cdecl sub_0048A730_ResetEquipSounds()
{
    if (!sub_00408F20_HasExpansionMpq() || !sub_0044DCC0())
    {
        return;
    }
    sub_004B9A00(1, 0, 0, 0, 0);
    sub_00478590(0x60);
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pItem)
    {
        sub_004C21F0(pItem);
    }
    pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pItem)
    {
        sub_004C21F0(pItem);
    }
}

#include "gen/data/Source/D2Client/004868B0_sub_004868B0_LoadNpcPanelCels.inc"
