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

struct D2HotspotStrc
{
    char unk0x00[0x10];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    char unk0x20[0x04];
    char bFlag0x24;
    char bFlag0x25;
    char unk0x26[0x02];
};

extern int gnGlobal_007278FC;                                                                               // 0x007278FC
extern D2HotspotStrc gaHotspots_00727902[];                                                                 // 0x00727902
extern int gnGlobal_007C5474;                                                                               // 0x007C5474
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __cdecl sub_004BFAF0();                                                                                 // 0x004BFAF0
int __cdecl sub_004C02F0();                                                                                 // 0x004C02F0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __fastcall sub_00489190(SMSGHANDLER_PARAMS* pMsg);                                                      // 0x00489190
int __stdcall sub_004890B0_ClickRectMsg(SMSGHANDLER_PARAMS* pMsg);                                          // 0x004890B0

// 0x004C0450
static int sub_004C0450_ClickHotspots(int nX, int nY)
{
    int bHit = 0;
    int n;
    for (int i = 0; i < (n = *(volatile int*)&gnGlobal_007278FC); i++)
    {
        if (gaHotspots_00727902[i].bFlag0x25 && nX >= gaHotspots_00727902[i].nLeft && nX <= gaHotspots_00727902[i].nRight && nY >= gaHotspots_00727902[i].nTop && nY <= gaHotspots_00727902[i].nBottom)
        {
            sub_004B9A00(1, 0, 0, 0, 0);
            if (!i)
                sub_004BFAF0();
            else
                sub_004C02F0();
            bHit = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        gaHotspots_00727902[i].bFlag0x25 = 0;
        gaHotspots_00727902[i].bFlag0x24 = 0;
    }
    return bHit;
}

void __stdcall sub_004C04E0_OnHotspotClick(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    const int nX = pMsg->nXPos;
    const int nY = pMsg->nYPos;
    if (gnGlobal_007C5474 == 2)
    {
        if (sub_004C0450_ClickHotspots(nX, nY))
            return;
        if (sub_00489190(pMsg))
            sub_004C02F0();
        return;
    }
    if (sub_004890B0_ClickRectMsg(pMsg))
        return;
    sub_004C0450_ClickHotspots(nX, nY);
}

#include "gen/data/Source/D2Client/004C0450_sub_004C0450_ClickHotspots.inc"
