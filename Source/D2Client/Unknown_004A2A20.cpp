#include "D2StormTypes.h"
#define SOUND_ID 4
int __stdcall sub_004A2970_IsMouseOnButton(int nX, int nY);
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
extern char gbGlobal_007BF2B0;  // 0x007BF2B0
// 0x004A2A20
void __stdcall sub_004A2A20(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if ((unsigned char)sub_004A2970_IsMouseOnButton(nX, nY))
    {
        gbGlobal_007BF2B0 = 1;
        sub_004B9A00(SOUND_ID, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        gbGlobal_007BF2B0 = 0;
        pMsg->bReturn = 0;
    }
}
