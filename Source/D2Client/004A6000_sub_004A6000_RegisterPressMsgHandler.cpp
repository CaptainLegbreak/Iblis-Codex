struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}

    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count); // 0x00526790
};

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

struct D2MsgHandlerEntryStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl sub_0044DA30();                                                                                 // 0x0044DA30
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __cdecl sub_00454980();                                                                                // 0x00454980
unsigned short __fastcall sub_00469AA0(int nA, int nB);                                                     // 0x00469AA0
int __fastcall sub_00469C20_QueryKey(int nId, int nMode, int nCommand, int* pKey);                          // 0x00469C20
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB);                                          // 0x0046A530
void __stdcall sub_004A4AD0_Press(int nX, int nY);                                                          // 0x004A4AD0
void __stdcall sub_004A5D70_RegisterMsgHandlers(int bReset);                                                // 0x004A5D70
int __cdecl sub_004A65E0_IsInLeftButton();                                                                  // 0x004A65E0
int __cdecl sub_004A6690_IsInRightButton();                                                                 // 0x004A6690
int __cdecl D2GFX_GetResolutionMode();                                                                      // 0x004F5160
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2ClientListEntryStrc* gpListEntries_00724264;                                                       // 0x00724264
extern int gnGlobal_007246D4;                                                                               // 0x007246D4
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072472C[];                                                      // 0x0072472C
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724738[];                                                      // 0x00724738
extern D2MsgHandlerEntryStrc gaMsgHandlers_00724780[];                                                      // 0x00724780
extern D2MsgHandlerEntryStrc gaMsgHandlers_0072478C[];                                                      // 0x0072478C
extern int gnGlobal_007C0280;                                                                               // 0x007C0280
extern int gnGlobal_007C02B0;                                                                               // 0x007C02B0
extern int gnGlobal_007C02B8;                                                                               // 0x007C02B8
extern unsigned short gwGlobal_007C02C4;                                                                    // 0x007C02C4
extern unsigned long gnGlobal_007C02C8;                                                                     // 0x007C02C8
extern void* gpGlobal_007C02DC;                                                                             // 0x007C02DC

// build: symbol ?$S1@?4??sub_004A8DF0_DrawKeyLabel@@YIXHHHH@Z@4IA 0x007C0830
// 0x004A6000
void __stdcall sub_004A6000_RegisterPressMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724738, 6);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072478C, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_00724780, 1);
    sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaMsgHandlers_0072472C, 1);
    sub_00454980();
    gnGlobal_007C02B8 = 0;
    gnGlobal_007C0280 = 1;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A63B0
void __stdcall sub_004A63B0_WheelMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DA30())
    {
        pMsg->bUseResult = 0;
        return;
    }

    int nSteps = (short)pMsg->wParamHigh / 120;
    if (nSteps)
    {
        int nKey = 0;
        if (sub_00469C20_QueryKey(*(int*)gpListEntries_00724264[gnGlobal_007C02B0].nId, gnGlobal_007246D4, (nSteps < 0) + 0x103, &nKey))
        {
            sub_004A5D70_RegisterMsgHandlers(1);
        }
        else if ((unsigned short)nKey)
        {
            gwGlobal_007C02C4 = nKey;
            gnGlobal_007C02C8 = GetTickCount();
        }
    }

    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6A70
void __cdecl sub_004A6A70_DrawLeftPanelButton()
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    tContext.nFrame = 2;
    if (sub_004A65E0_IsInLeftButton() && !sub_004538D0(9))
    {
        sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0xF92), gnGlobal_0071146C / 2 - 0xB3, gnGlobal_00711470 - 0x32, 0, 1);
    }

    sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xC2, gnGlobal_00711470 - 8, -1, 5, 0);
}

// 0x004A6DA0
void __cdecl sub_004A6DA0_DrawRightPanelButton()
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.unk0x40 = 0;
    tContext.pCellFile = gpGlobal_007C02DC;
    tContext.nFrame = 2;
    if (sub_004A6690_IsInRightButton() && !sub_004538D0(9))
    {
        sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0xF93), gnGlobal_0071146C / 2 + 0xB2, gnGlobal_00711470 - 0x32, 0, 1);
    }

    sub_004F6480(&tContext, gnGlobal_0071146C / 2 + 0xA3, gnGlobal_00711470 - 8, -1, 5, 0);
}

// 0x004A8DF0
void __fastcall sub_004A8DF0_DrawKeyLabel(int nKeyId, int nX, int nY, int nColor)
{
    if (sub_00469AA0(nKeyId, 1) == 0xFFFF)
    {
        return;
    }

    static Unicode wszBuf[16]; // 0x007C0810
    const Unicode* wszText = sub_0046A530_GetKeyName(nKeyId, 1);
    int nWidth = sub_00501820(wszText);
    if (nWidth > 40)
    {
        Unicode::strncpy(wszBuf, wszText, 16);
        wszText = wszBuf;
        Unicode* pEnd = &wszBuf[sub_00526800(wszText)];
        do
        {
            --pEnd;
            pEnd->wChar = 0;
            nWidth = sub_00501820(wszBuf);
        }
        while (nWidth > 40);
    }

    if (nWidth > 13)
    {
        nX += 13 - nWidth;
    }

    sub_00502320(wszText, nX, nY, nColor, 0);
}
