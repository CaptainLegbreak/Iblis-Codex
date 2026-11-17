#include "D2Client.h"

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned short nXPos;
    unsigned short nYPos;
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

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
static int gnGlobal_007C02F4;                                                                               // 0x007C02F4
extern D2BeltSlotStrc gtSlots_00724A48[4];                                                                  // 0x00724A48
int __cdecl D2GFX_GetResolutionMode();
int __fastcall sub_00498DC0(SMSGHANDLER_PARAMS* pMsg);
int __cdecl sub_00468830();
void __cdecl sub_00453EC0();
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);              // 0x006253B0
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS* pMsg);
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);

static int sub_004A76C0_ClaimLeftPanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (D2GFX_GetResolutionMode() == 2 && !sub_00498DC0(pMsg) && pMsg->nXPos <= gnGlobal_0071146C / 2 && pMsg->nYPos < gnGlobal_00711470 - 0x2F)
    {
        if (sub_00468830() == 6)
            sub_00453EC0();
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

// 0x004A7720
void __stdcall sub_004A7720_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXPos;
    const int nY = pMsg->nYPos;
    if (nX >= gnGlobal_007A2858 + 0x80 && nX <= gnGlobal_007A2858 + 0xA0 && nY >= gnGlobal_00711470 + gnGlobal_007A285C - 0x5C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x3C)
    {
        gnGlobal_007C02F4 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (nX >= gnGlobal_007A2858 && nX <= gnGlobal_0071146C / 2 - 1 && nY >= gnGlobal_007A285C && nY <= gnGlobal_00711470 + gnGlobal_007A285C - 0x31)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (STATLIST_GetUnitBaseStat(pPlayer, 4, 0))
        {
            for (int i = 0; i < 4; ++i)
            {
                if (nY > gtSlots_00724A48[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1F6 && nY < gtSlots_00724A48[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0 && nX > gtSlots_00724A48[i].nX + gnGlobal_007A2858 && nX < gtSlots_00724A48[i].nX + gnGlobal_007A2858 + 0x28)
                {
                    gtSlots_00724A48[i].bActive = 1;
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
