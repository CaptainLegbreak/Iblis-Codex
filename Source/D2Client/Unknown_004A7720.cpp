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

extern int gnScreenWidth;                                                                               // 0x0071146C
extern int gnScreenHeight;                                                                               // 0x00711470
extern int gnPanelOffsetX;                                                                               // 0x007A2858
extern int gnPanelOffsetY;                                                                               // 0x007A285C
static int gbStatScreenButtonDown;                                                                               // 0x007C02F4
extern D2BeltSlotStrc gaStatButtons[4];                                                                  // 0x00724A48
int __cdecl D2GFX_GetResolutionMode();
int __fastcall sub_00498DC0(SMSGHANDLER_PARAMS* pMsg);
int __cdecl sub_00468830();
void __cdecl UI_CancelCursorItemUse();
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);              // 0x006253B0
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS* pMsg);
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);

static int sub_004A76C0_ClaimLeftPanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (D2GFX_GetResolutionMode() == 2 && !sub_00498DC0(pMsg) && pMsg->nXpos <= gnScreenWidth / 2 && pMsg->nYpos < gnScreenHeight - 0x2F)
    {
        if (sub_00468830() == 6)
            UI_CancelCursorItemUse();
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

// 0x004A7720
void __stdcall sub_004A7720_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if (nX >= gnPanelOffsetX + 0x80 && nX <= gnPanelOffsetX + 0xA0 && nY >= gnScreenHeight + gnPanelOffsetY - 0x5C && nY <= gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        gbStatScreenButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (nX >= gnPanelOffsetX && nX <= gnScreenWidth / 2 - 1 && nY >= gnPanelOffsetY && nY <= gnScreenHeight + gnPanelOffsetY - 0x31)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
        {
            for (int i = 0; i < 4; ++i)
            {
                if (nY > gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1F6 && nY < gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0 && nX > gaStatButtons[i].nX + gnPanelOffsetX && nX < gaStatButtons[i].nX + gnPanelOffsetX + 0x28)
                {
                    gaStatButtons[i].bActive = 1;
                    sub_00467F20_MsgHandler(pMsg);
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    sub_004B9A00(5, 0, 0, 0, 0);
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }
            }
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!sub_004A76C0_ClaimLeftPanelClick(pMsg))
        pMsg->bReturn = 0;
}

#include "gen/data/Source/D2Client/Unknown_004A7720.inc"
