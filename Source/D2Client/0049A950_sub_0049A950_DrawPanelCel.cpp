struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct Unicode;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        int wParam;
        struct
        {
            unsigned short wParamLow;
            unsigned short wParamHigh;
        };
    };
    union
    {
        int lParam;
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
    };
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

struct D2ClientListEntryStrc
{
    unsigned char nId[4];
    unsigned char unk0x04[6];
};

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2TextNodeStrc
{
    void* pOwned[6];
    unsigned char unk0x18[10];
    unsigned char pNext[4];
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short nCount;
};

struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void* __cdecl sub_00454600();                                                                               // 0x00454600
void __cdecl sub_00454980();                                                                                // 0x00454980
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __cdecl sub_00466FE0();                                                                                // 0x00466FE0
void __fastcall sub_00467430(D2RectStrc* pRect);                                                            // 0x00467430
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
void __fastcall sub_00469D70(int nId, int nB);                                                              // 0x00469D70
int __fastcall sub_00469D90(int nA, int nB);                                                                // 0x00469D90
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);                               // 0x004786A0
void __cdecl sub_0049FE10();                                                                                // 0x0049FE10
int __cdecl sub_004A08C0();                                                                                 // 0x004A08C0
void __cdecl sub_004A2550();                                                                                // 0x004A2550
bool __stdcall sub_004A2970(int nX, int nY);                                                                // 0x004A2970
void __fastcall sub_004A3FE0(int nMode);                                                                    // 0x004A3FE0
void __fastcall sub_004A45C0(int nStep);                                                                    // 0x004A45C0
void __cdecl sub_004A5D00();                                                                                // 0x004A5D00
void __fastcall sub_004A6260(int nId);                                                                      // 0x004A6260
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __fastcall sub_004EF990(D2UnitStrc* pUnit, int nId, int nA, int nB, int nState, int nX, int nY);       // 0x004EF990
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007225FC;                                                                               // 0x007225FC
extern D2ClientListEntryStrc* gpListEntries_00724264;                                                       // 0x00724264
extern int gnGlobal_007246D4;                                                                               // 0x007246D4
extern int gnGlobal_00724728;                                                                               // 0x00724728
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072472C[];                                                      // 0x0072472C
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724738[];                                                      // 0x00724738
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724780[];                                                      // 0x00724780
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072478C[];                                                      // 0x0072478C
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_007BF030;                                                                               // 0x007BF030
extern int gnGlobal_007BF07D;                                                                               // 0x007BF07D
extern char gbGlobal_007BF085;                                                                              // 0x007BF085
extern char gData_007BF1B0[];                                                                               // 0x007BF1B0
extern unsigned long gnGlobal_007BF1F6;                                                                     // 0x007BF1F6
extern int gnGlobal_007BF1FA;                                                                               // 0x007BF1FA
extern unsigned long gnGlobal_007BF22C;                                                                     // 0x007BF22C
extern int gnGlobal_007BF23F;                                                                               // 0x007BF23F
extern int gnGlobal_007BF278;                                                                               // 0x007BF278
extern int gnGlobal_007BF298;                                                                               // 0x007BF298
char gbGlobal_007BF2B0;                                                                                     // 0x007BF2B0
char gbGlobal_007BF2B3;                                                                                     // 0x007BF2B3
extern unsigned long gnGlobal_007C0259;                                                                     // 0x007C0259
int gnGlobal_007C02B0;                                                                                      // 0x007C02B0
extern int gnGlobal_007C02B8;                                                                               // 0x007C02B8

// 0x0049A950
void __cdecl sub_0049A950_DrawPanelCel()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = (gnGlobal_007BF030 != 0) + 10;
    tContext.unk0x40 = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 278, 421 - gnGlobal_007A285C, -1, 5, 0);
}

// 0x0049AA50
int __stdcall sub_0049AA50_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    int nLeft = nX + gnGlobal_007A2858;
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth)
    {
        int nBottom = nY - gnGlobal_007A285C;
        if (nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0049CEC0
void __stdcall sub_0049CEC0_KeyMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->uMessage == 0x102 && pMsg->wParam == 9)
    {
        return;
    }

    if (pMsg->uMessage == 0x104 && pMsg->wParam == 0x73)
    {
        return;
    }

    if (!gbGlobal_007BF085 && sub_00463DD0() && UNITS_GetRoom(sub_00463DD0()))
    {
        sub_004786A0_SendIntInt(0x49, gnGlobal_007BF07D, 0);
        gbGlobal_007BF085 = 1;
    }

    sub_00455F20(20, 1, 1);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0049D440
void __cdecl sub_0049D440_LoadTextSettings()
{
    memset(gData_007BF1B0, 0, 0x9F);
    unsigned long nValue;
    if (!SRegLoadValue("Diablo II", "Text Display Beta", 0, &nValue))
    {
        gnGlobal_007BF1F6 = 1;
    }
    else
    {
        gnGlobal_007BF1F6 = nValue;
    }
}

// 0x0049D4D0
void __stdcall sub_0049D4D0_FreeTextList(D2TextListStrc* pList)
{
    int nCount = 0;
    D2TextNodeStrc* pNode = pList->pFirst;
    if (pNode)
    {
        do
        {
            D2TextNodeStrc* pCurrent = pNode;
            pNode = *(D2TextNodeStrc**)pNode->pNext;
            for (int i = 0; i < 6; ++i)
            {
                if (pCurrent->pOwned[i])
                {
                    FOG_Free(pCurrent->pOwned[i], ".\\UI\\text.cpp", 1715, 0);
                }
            }

            FOG_Free(pCurrent, ".\\UI\\text.cpp", 1718, 0);
            ++nCount;
        }
        while (pNode);

        pList->pFirst = pNode;
    }

    D2_ASSERT((unsigned short)nCount == pList->nCount, 1741);
    pList->nCount = 0;
}

// 0x0049DA10
void __stdcall sub_0049DA10_EatMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0049E810
void __cdecl sub_0049E810_SetPanelRect()
{
    D2RectStrc tRect;
    tRect.nTop = gnGlobal_007225FC;
    tRect.nBottom = (gnGlobal_007225FC + 182 < gnGlobal_00711470 - 53) ? gnGlobal_007225FC + 182 : gnGlobal_00711470 - 53;
    tRect.nLeft = gnGlobal_007BF278 - 10;
    tRect.nRight = gnGlobal_007BF278 + 335;
    sub_00467430(&tRect);
    sub_00466FE0();
}

// 0x0049FE60
void __stdcall sub_0049FE60_CloseMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    sub_00455F20(16, 2, 0);
    sub_0049FE10();
}

// 0x004A1770
void __stdcall sub_004A1770_KeyUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007BF1FA = 0;
    if (GetTickCount() - gnGlobal_007BF22C < 100)
    {
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BF23F = 0;
        return;
    }

    if (sub_004A08C0())
    {
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x004A1870
void __stdcall sub_004A1870_HotkeyMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00469D90(7, 1))
    {
        unsigned short nKey = sub_00469AA0(7, 1);
        if (nKey != 0xFFFF && nKey <= 0xDF && pMsg->wParam == nKey)
        {
            return;
        }
    }

    sub_004A1770_KeyUpMsgHandler(pMsg);
}

// 0x004A18C0
void __stdcall sub_004A18C0_KeyDownMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam != 0x73)
    {
        sub_004A1870_HotkeyMsgHandler(pMsg);
    }
}

// 0x004A26B0
int __stdcall sub_004A26B0_OpenPanel(int nArg)
{
    if (gnGlobal_007BF298 == 2)
    {
        gnGlobal_007BF298 = 0;
        gbGlobal_007BF2B0 = 0;
        gbGlobal_007BF2B3 = 0;
    }

    sub_004A2550();
    sub_00455F20(15, 1, nArg);
    return 1;
}

// 0x004A2840
void __stdcall sub_004A2840_OpenPanelMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gnGlobal_007BF298 == 2)
    {
        gnGlobal_007BF298 = 0;
        gbGlobal_007BF2B0 = 0;
        gbGlobal_007BF2B3 = 0;
    }

    sub_004A2550();
    sub_00455F20(15, 1, 1);
    gnGlobal_007C0259 = GetTickCount();
}

// 0x004A4110
void __stdcall sub_004A4110_ButtonUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (sub_004A2970(nX, nY) && gbGlobal_007BF2B0)
    {
        sub_00455F20(17, 1, 0);
        sub_004A3FE0(0);
        gbGlobal_007BF2B0 = 0;
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    gbGlobal_007BF2B0 = 0;
    pMsg->bUseResult = 0;
}

// 0x004A4780
int __stdcall sub_004A4780_IsAbovePanelLine(int nY)
{
    int nHalf = (gnGlobal_0071146C - 620) / 2;
    return nY < nHalf + (gnGlobal_0071146C - nHalf * 2 - 49) / 3 * 2 + 18;
}

// 0x004A5A40
void __stdcall sub_004A5A40_PrevEntryMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    D2ClientListEntryStrc* pEntries = gpListEntries_00724264;
    int nOldIndex = gnGlobal_007C02B0;
    do
    {
        sub_004A45C0(-1);
    }
    while (*(int*)pEntries[gnGlobal_007C02B0].nId == 0x39);

    if (nOldIndex != gnGlobal_007C02B0)
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5AB0
void __stdcall sub_004A5AB0_NextEntryMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    D2ClientListEntryStrc* pEntries = gpListEntries_00724264;
    int nOldIndex = gnGlobal_007C02B0;
    do
    {
        sub_004A45C0(1);
    }
    while (*(int*)pEntries[gnGlobal_007C02B0].nId == 0x39);

    if (nOldIndex != gnGlobal_007C02B0)
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5B30
void __stdcall sub_004A5B30_SetFlagMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    if (gnGlobal_007246D4 == 0)
    {
        gnGlobal_007246D4 = 1;
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5B90
void __stdcall sub_004A5B90_ClearFlagMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    if (gnGlobal_007246D4 == 1)
    {
        gnGlobal_007246D4 = 0;
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5BF0
void __stdcall sub_004A5BF0_SelectEntryMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    if (gnGlobal_00724728)
    {
        if (!(pMsg->lParam & 0x40000000))
        {
            sub_00469D70(*(int*)gpListEntries_00724264[gnGlobal_007C02B0].nId, gnGlobal_007246D4);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    else
    {
        gnGlobal_00724728 = 1;
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5D70
void __stdcall sub_004A5D70_RegisterMsgHandlers(int bReset)
{
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724738, 6);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724780, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
    if (bReset)
    {
        sub_00454980();
        gnGlobal_007C02B8 = 0;
    }
}

// 0x004A5F70
void __stdcall sub_004A5F70_ApplyEntryMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    if (gnGlobal_00724728)
    {
        if (!(pMsg->lParam & 0x40000000) && *(int*)gpListEntries_00724264[gnGlobal_007C02B0].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
            gnGlobal_00724728 = 0;
        }
    }
    else
    {
        gnGlobal_00724728 = 1;
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6310
void __stdcall sub_004A6310_ToggleMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    sub_004A6260(0x100);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6350
void __stdcall sub_004A6350_CommandMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    switch (pMsg->wParamHigh)
    {
    case 1:
        sub_004A6260(0x101);
        break;
    case 2:
        sub_004A6260(0x102);
        break;
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6580
int __fastcall sub_004A6580_IsInPanelButton(int nMode, int nX, int nY)
{
    if (nMode == 2)
    {
        int nHalf = gnGlobal_0071146C / 2;
        if (nX <= nHalf + 40 || nX >= nHalf + 74)
        {
            return 0;
        }
    }
    else if (nX < 41 || nX > 41 + 32)
    {
        return 0;
    }

    if (nY <= gnGlobal_00711470 - 139 || nY >= gnGlobal_00711470 - 102)
    {
        return 0;
    }

    return 1;
}

// 0x004A7080
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor)
{
    int nSpan = nRight - nLeft + 1;
    int nWidth = sub_00501820(wszText);
    if (nWidth < nSpan)
    {
        nLeft += (nSpan - nWidth) >> 1;
    }

    sub_00502320(wszText, nLeft, nY, nColor, 0);
}

// 0x004A8D50
void __fastcall sub_004A8D50_UpdateButton(short* pId, int nState, int nA, int nB, int nX, int nY)
{
    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
    {
        nState = nState == 1;
    }
    else
    {
        nState = 1;
    }

    nMouseX = sub_00468730();
    nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
    {
        sub_004EF990(sub_00463DD0(), *pId, nA, nB, nState, nX, nY);
    }
}

#include "gen/data/Source/D2Client/0049A950_sub_0049A950_DrawPanelCel.inc"
