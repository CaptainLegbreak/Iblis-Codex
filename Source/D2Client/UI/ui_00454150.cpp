#include "D2Structs.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
#pragma function(memset)

enum D2C_StatIds
{
    STAT_GOLD = 14,
    STAT_GOLDBANK = 15,
};

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0);
};

struct D2InventoryStrc;


struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

extern "C" const char gszNew_006CC82C[];                                                                    // 0x006CC82C

struct D2UiControlBaseStrc
{
    static void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, gszNew_006CC82C, -1, 0);
    }
};

struct D2UiControlAStrc : D2UiControlBaseStrc
{
    int unk0x04[2];

    D2UiControlAStrc(int nX, int nY, int nFlag, int (__cdecl* pfnCallback)());                              // 0x004BC480
    virtual void sub_Virtual00();
};

struct D2UiControlBStrc : D2UiControlBaseStrc
{
    int unk0x04[2];

    D2UiControlBStrc(int nX, int nY, int nWidth, int nArg4, int nValue, int nArg6, int (__cdecl* pfnCallback)(), int nArg8); // 0x004BBD80
    virtual void sub_Virtual00();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual void sub_Virtual2C();
    virtual void sub_Virtual30();
    virtual void sub_Virtual34();
    virtual void SetValue(int nValue);
    virtual void sub_Virtual3C();
    virtual void sub_Virtual40();
    virtual void SetActive(int bActive);
};

struct D2UiControlCStrc : D2UiControlBaseStrc
{
    int unk0x04[2];

    D2UiControlCStrc(int nX, int nY, int nFlag, int (__cdecl* pfnCallback)());                              // 0x004BB0F0
    virtual void sub_Virtual00();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual void sub_Virtual2C();
    virtual void SetActive(int bActive);
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __cdecl sub_00453EE0_ClosePanel();                                                                     // 0x00453EE0
void __fastcall sub_0046AA20_SetHotkeyHandlers(int nArg1, int nArg2);                                                         // 0x0046AA20
void __cdecl sub_004A7A90_SetFlag();                                                                                // 0x004A7A90
void __fastcall sub_004898A0(int nMode);                                                                    // 0x004898A0
void* __fastcall sub_004B7CD0_CreatePanel(int nX, int nY, int (__cdecl* pfnCallback)(), int nArg4, int nArg5, int nArg6); // 0x004B7CD0
void __fastcall sub_004B8370(void* pPanel, int nValue);                                                     // 0x004B8370
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pDest, const Unicode* pFormat, ...);                 // 0x005269D0
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
T0044CB60* __fastcall sub_00502970_SplitText(Unicode* pText, int* pLineCount, int nWidth);             // 0x00502970
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x004B85F0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __fastcall sub_004B7C00_AddControl(void* pPanel, void* pControl, int nArg3, int nArg4);                // 0x004B7C00
extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0
int __cdecl sub_00453FC0_GoldPanelClose();                                                                                 // 0x00453FC0
int __cdecl sub_00453FD0();                                                                                 // 0x00453FD0
int __cdecl sub_00453FE0_GoldSpinnerChanged();                                                                                 // 0x00453FE0
int __cdecl sub_00454080_ConfirmGoldDialog();                                                                                 // 0x00454080
int __cdecl sub_00454140_ClosePanelCallback();                                                                                 // 0x00454140

extern int gnGoldPanelMode_007A279C;                                                                        // 0x007A279C
void* gpGlobal_007A27A0;                                                                                    // 0x007A27A0
extern D2UiControlAStrc* gpGoldControlA_007A27A4;                                                           // 0x007A27A4
extern D2UiControlBStrc* gpGoldControlB_007A27A8;                                                           // 0x007A27A8
extern D2UiControlCStrc* gpGoldControlC_007A27AC;                                                           // 0x007A27AC
extern D2UiControlCStrc* gpGoldControlD_007A27B0;                                                           // 0x007A27B0
extern int gbGoldPanelFlag_007A27B4;                                                                        // 0x007A27B4
extern int gnGoldPanelValue_007A2A68;                                                                       // 0x007A2A68

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00454150
void __fastcall sub_00454150_OpenGoldPanel(int nMode)
{
    if (!sub_00463DD0_GetPlayerUnit())
    {
        sub_00453EE0_ClosePanel();
        return;
    }
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        sub_00453EE0_ClosePanel();
        return;
    }
    if (gpGlobal_007A27A0)
    {
        return;
    }
    if (!gbGoldPanelFlag_007A27B4)
    {
        sub_0046AA20_SetHotkeyHandlers(0, 1);
        gbGoldPanelFlag_007A27B4 = 1;
    }
    gnGoldPanelValue_007A2A68 = 0;

    int nStringId;
    int nGold;
    switch (nMode)
    {
    case 0:
        sub_004A7A90_SetFlag();
        nStringId = 0xFC1;
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 1:
        nStringId = 0xFC1;
        sub_004898A0(1);
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 2:
        nStringId = 0xFCE;
        sub_004898A0(2);
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 3:
        nStringId = 0xFD1;
        sub_004898A0(3);
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 4:
        nStringId = 0xFD2;
        sub_004898A0(4);
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLDBANK, 0);
        break;
    default:
        sub_00453EE0_ClosePanel();
        return;
    }

    gnGoldPanelMode_007A279C = nMode;
    gpGlobal_007A27A0 = sub_004B7CD0_CreatePanel(0xD7, 0x8C, sub_00453FC0_GoldPanelClose, 0, 0, 1);
    sub_004B8370(gpGlobal_007A27A0, 1);
    sub_00502EF0(1);

    Unicode wszText[0x100];
    memset(wszText, 0, sizeof(wszText));
    if (nMode == 5)
    {
        sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(nStringId), STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLDBANK, 0) + STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0));
    }
    else
    {
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringId));
    }

    int nLineCount;
    T0044CB60* pLine = sub_00502970_SplitText(wszText, &nLineCount, 0xC8);
    while (pLine)
    {
        sub_004B85F0_AddTextLine(gpGlobal_007A27A0, pLine->pText, 0x18, 0, 4, 1, 0, 0);
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine->pText, ".\\UI\\ui.cpp", 0x1827, 0);
        FOG_Free(pLine, ".\\UI\\ui.cpp", 0x1828, 0);
        pLine = pNext;
    }

    gpGoldControlA_007A27A4 = new D2UiControlAStrc(0xDF, 0xDB, 0, sub_00453FE0_GoldSpinnerChanged);
    sub_004B7C00_AddControl(gpGlobal_007A27A0, gpGoldControlA_007A27A4, 0, 0);
    gpGoldControlB_007A27A8 = new D2UiControlBStrc(0x102, 0xE4, 0x64, 1, nGold, 0xA, sub_00453FD0, 1);
    sub_004B7C00_AddControl(gpGlobal_007A27A0, gpGoldControlB_007A27A8, 0, 0);
    if (gpGoldControlB_007A27A8)
    {
        gpGoldControlB_007A27A8->SetActive(1);
    }
    gpGoldControlC_007A27AC = new D2UiControlCStrc(0xFA, 0x11F, 0, sub_00454080_ConfirmGoldDialog);
    sub_004B7C00_AddControl(gpGlobal_007A27A0, gpGoldControlC_007A27AC, 0, 0);
    gpGoldControlC_007A27AC->SetActive(1);
    gpGoldControlD_007A27B0 = new D2UiControlCStrc(0x163, 0x11F, 1, sub_00454140_ClosePanelCallback);
    sub_004B7C00_AddControl(gpGlobal_007A27A0, gpGoldControlD_007A27B0, 0, 0);

    if (nMode == 2)
    {
        sub_004B90B0_SendState();
        return;
    }
    if (nMode == 3 || nMode == 7 || nMode == 6)
    {
        if (gpGoldControlB_007A27A8)
        {
            gpGoldControlB_007A27A8->SetValue(nGold);
        }
    }
}
