#include "D2Client.h"
#include "D2StormTypes.h"

struct D2ClientListEntryStrc
{
    unsigned char nId[4];
    unsigned char unk0x04[6];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30
int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey);               // 0x00469C20
void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset);                                                // 0x004A5D70
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
extern int gnKeyConfigSelected;                                                                               // 0x007C02B0
unsigned long gdwMessageTick;                                                                            // 0x007C02C8

// 0x004A60B0
void __stdcall sub_004A60B0_KeyDownMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    unsigned short wKey = 0;
    if (!(pMsg->lParam & 0x40000000))
    {
        if (pMsg->wParam == 0x1B)
        {
            TEXT_UnregisterKeyConfigHandlers(1);
            sub_004B9A00(1, 0, 0, 0, 0);
// build: symbol ?gbKeyConfigReady@* 0x00724728
            gbKeyConfigReady = 0;
        }
        else
        {
// build: symbol ?gpListEntries@* 0x00724264
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
            if (CMDTBL_QueryKey(*(int*)gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (unsigned short)pMsg->wParam, &wKey))
            {
                TEXT_UnregisterKeyConfigHandlers(1);
                sub_004B9A00(2, 0, 0, 0, 0);
                if (pMsg->wParam == 0x0D || pMsg->wParam == 0x2E || pMsg->wParam == 0x08 || pMsg->wParam == 0x20)
                {
                    gbKeyConfigReady = 0;
                    goto store_key;
                }
            }
            gbKeyConfigReady = 1;
        }
store_key:
        if (wKey)
        {
            gwGlobal_007C02C4 = wKey;
            gdwMessageTick = GetTickCount();
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A61A0
void __stdcall sub_004A61A0_KeyUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    unsigned short wKey = 0;
    if (gbKeyConfigReady)
    {
        if (CMDTBL_QueryKey(*(int*)gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (unsigned short)pMsg->wParam, &wKey))
        {
            TEXT_UnregisterKeyConfigHandlers(1);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    else
    {
        gbKeyConfigReady = 1;
    }

    if (wKey)
    {
        gwGlobal_007C02C4 = wKey;
        gdwMessageTick = GetTickCount();
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}
