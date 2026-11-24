#include "D2Client.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

struct D2ClientListEntryStrc
{
    unsigned char nId[4];
    unsigned char unk0x04[6];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
void __cdecl UI_RegisterKeyConfigHandlers();                                                                                // 0x00454980
unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB);                                                     // 0x00469AA0
int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, int* pKey);                          // 0x00469C20
const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB);                                          // 0x0046A530
void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset);                                                // 0x004A5D70
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl WINDOW_GetWindow();                                                                                // 0x004F59A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern int gnScreenWidth;                                                                               // 0x0071146C
extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[];                                                      // 0x0072472C
extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[];                                                      // 0x00724738
extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[];                                                      // 0x00724780
extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[];                                                      // 0x0072478C
extern int gbRedraw;                                                                               // 0x007C0280
extern int gnKeyConfigSelected;                                                                               // 0x007C02B0
extern int gbKeyCaptureActive;                                                                               // 0x007C02B8
extern unsigned long gdwMessageTick;                                                                     // 0x007C02C8
extern void* gpLevelCel;                                                                             // 0x007C02DC

// 0x004A63B0
void __stdcall sub_004A63B0_WheelMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    int nSteps = (short)pMsg->wParamHigh / 120;
    if (nSteps)
    {
        int nKey = 0;
// build: symbol ?gpListEntries@* 0x00724264
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
        if (CMDTBL_QueryKey(*(int*)gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (nSteps < 0) + 0x103, &nKey))
        {
            TEXT_UnregisterKeyConfigHandlers(1);
        }
        else if ((unsigned short)nKey)
        {
            gwGlobal_007C02C4 = nKey;
            gdwMessageTick = GetTickCount();
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}


