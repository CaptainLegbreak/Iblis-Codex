#include "D2StatIds.h"
#include "D2Client.h"
#include "D2StormTypes.h"

#pragma pack(push, 2)
struct D2BeltSlotStrc
{
    int nX;
    int nY;
    int bActive;
    unsigned short wCode;
};
#pragma pack(pop)

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_007C02F4;                                                                               // 0x007C02F4
extern D2BeltSlotStrc gtSlots_00724A48[4];                                                                  // 0x00724A48
int __cdecl D2GFX_GetResolutionMode();
int __fastcall sub_00498DC0(SMSGHANDLER_PARAMS* pMsg);
int __cdecl sub_00468830();
void __cdecl sub_00453EC0();
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);              // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg);
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg);                       // 0x00455F20
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);
void __cdecl sub_0044DA70();

static int sub_004A76C0_ClaimLeftPanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (D2GFX_GetResolutionMode() == 2 && !sub_00498DC0(pMsg) && pMsg->nXpos <= gnGlobal_0071146C / 2 && pMsg->nYpos < gnGlobal_00711470 - 0x2F)
    {
        if (sub_00468830() == 6)
            sub_00453EC0();
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

// 0x004A78C0
void __stdcall sub_004A78C0_OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    sub_00467FA0_MsgHandler(pMsg);
    gnGlobal_007C02F4 = 0;
    if (nX >= gnGlobal_007A2858 + 0x80 && nX <= gnGlobal_007A2858 + 0xA0 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x5C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        sub_00455F20(2, 1, 0);
        return;
    }
    if (nX >= gnGlobal_007A2858 && nX <= gnGlobal_0071146C / 2 - 1 && nY >= gnGlobal_007A285C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x31)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
        {
            const int nScreenH = gnGlobal_00711470;
            for (int i = 0; i < 4; ++i)
            {
                gtSlots_00724A48[i].bActive = 0;
                if (nY > gtSlots_00724A48[i].nY + gnGlobal_007A285C + nScreenH - 0x1F6 && nY < gtSlots_00724A48[i].nY + gnGlobal_007A285C + nScreenH - 0x1E0 && nX > gtSlots_00724A48[i].nX + gnGlobal_007A2858 && nX < gtSlots_00724A48[i].nX + gnGlobal_007A2858 + 0x28)
                {
                    int nCount = STATLIST_UnitGetStatValue(pPlayer, STAT_STATPTS, 0);
                    if (GetKeyState(0x10) >= 0)
                        nCount = 1;
                    else if (!nCount)
                        break;
                    do
                    {
                        const int nStack = nCount < 0x20 ? nCount : 0x20;
                        nCount -= nStack;
                        sub_004785B0_SendPacket3(0x3A, ((unsigned char)(nStack - 1) << 8) | gtSlots_00724A48[i].wCode);
                    }
                    while (nCount);
                    break;
                }
            }
        }
        sub_0044DA70();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!sub_004A76C0_ClaimLeftPanelClick(pMsg))
        pMsg->bReturn = 0;
}
