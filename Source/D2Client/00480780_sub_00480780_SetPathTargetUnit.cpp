struct D2DynamicPathStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x24];
    D2DynamicPathStrc* pDynamicPath;
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
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

struct D2ClientCacheNodeStrc
{
    int nId;
    D2ClientCacheNodeStrc* pNext;
};

struct D2ClientCacheEntryStrc
{
    unsigned char unk0x00[0x4C];
    unsigned char bLocked;
    unsigned char unk0x4D[0x2F];
    unsigned char dwLastUse[4];
    unsigned char unk0x80[0x0A];
    unsigned char nRefCount[4];
};

struct D2ClientTabStrc
{
    unsigned char bSelected[4];
    unsigned char bEnabled[4];
    unsigned char unk0x08[0x0A];
};

struct D2ClientStateStrc
{
    char unk0x00[0x11D];
    unsigned char bFlag0x11D;
    char unk0x11E[0x0B];
    unsigned char bFlag0x129;
    unsigned char bFlag0x12A;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar);                                                  // 0x00453A90
int __fastcall sub_004538D0(int nUIVar);                                                             // 0x004538D0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __cdecl sub_0047A560();                                                                                 // 0x0047A560
void __fastcall sub_004823E0_ReleaseCacheEntry(int nId);                                                    // 0x004823E0
void __stdcall sub_004873A0_HandleClick(SMSGHANDLER_PARAMS* pMsg);                                          // 0x004873A0
void __cdecl sub_00487990_ResetHover();                                                                     // 0x00487990
void __fastcall sub_0049FF90_Close(int nArg, D2ClientStateStrc* pState);                                    // 0x0049FF90
int __cdecl sub_004B34A0();                                                                                 // 0x004B34A0
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId);                                                // 0x004B3230
void __cdecl sub_004B3ED0();                                                                                // 0x004B3ED0
void __fastcall sub_004CB9C0_Request(int nArg, int nId);                                                    // 0x004CB9C0
int __fastcall sub_004DF9D0_CheckCacheEntry(int nId);                                                       // 0x004DF9D0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern D2ClientTabStrc gaTabs_0072211A[];                                                                   // 0x0072211A
extern int gnGlobal_00722158;                                                                               // 0x00722158
extern int gnGlobal_00721E3C;                                                                               // 0x00721E3C
extern int gnGlobal_00721E40;                                                                               // 0x00721E40
extern int gnGlobal_00721E44;                                                                               // 0x00721E44
extern int gnGlobal_00721E48;                                                                               // 0x00721E48
extern int gnGlobal_00721E4C;                                                                               // 0x00721E4C
extern int gnGlobal_00721E50;                                                                               // 0x00721E50
extern D2ClientCacheEntryStrc* gpCacheEntries_007BC9A0;                                                     // 0x007BC9A0
extern int gnCacheEntries_007BC9A4;                                                                         // 0x007BC9A4
extern D2ClientCacheNodeStrc* gpCacheList_007BC9B8;                                                         // 0x007BC9B8
extern unsigned int gdwGlobal_007BC9BC;                                                                     // 0x007BC9BC
extern unsigned int gdwCacheUsed_007BC9D0;                                                                  // 0x007BC9D0
int gnGlobal_007BCA4C;                                                                                      // 0x007BCA4C
struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
    unsigned short pad0x16;
};

D2InvRectStrc gInvRect_007BCAA0;                                                                            // 0x007BCAA0
#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)
#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)
#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)
#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)
extern D2InventoryGridInfoStrc gGrid_007BCA30;                                                              // 0x007BCA30
#define gnGlobal_007BCA34 (gGrid_007BCA30.nGridLeft)
#define gnGlobal_007BCA38 (gGrid_007BCA30.nGridRight)
#define gnGlobal_007BCA3C (gGrid_007BCA30.nGridTop)
#define gnGlobal_007BCA40 (gGrid_007BCA30.nGridBottom)
D2InventoryGridInfoStrc gGrid_007BCB18;                                                                     // 0x007BCB18
#define gnGlobal_007BCB1C (gGrid_007BCB18.nGridLeft)
#define gnGlobal_007BCB20 (gGrid_007BCB18.nGridRight)
#define gnGlobal_007BCB24 (gGrid_007BCB18.nGridTop)
#define gnGlobal_007BCB28 (gGrid_007BCB18.nGridBottom)
extern D2InventoryGridInfoStrc gGrid_007BCB70;                                                              // 0x007BCB70
#define gnGlobal_007BCB74 (gGrid_007BCB70.nGridLeft)
#define gnGlobal_007BCB78 (gGrid_007BCB70.nGridRight)
#define gnGlobal_007BCB7C (gGrid_007BCB70.nGridTop)
#define gnGlobal_007BCB80 (gGrid_007BCB70.nGridBottom)
int gnGlobal_007BCBD8;                                                                                      // 0x007BCBD8
extern int gnGlobal_007BCBE0;                                                                               // 0x007BCBE0
extern int gdwGlobal_007BCBE4;                                                                              // 0x007BCBE4
extern int gdwGlobal_007BCBE8;                                                                              // 0x007BCBE8
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern int gdwGlobal_007BCBF4;                                                                              // 0x007BCBF4
extern int gdwGlobal_007BCBF8;                                                                              // 0x007BCBF8
extern unsigned char gnSelectedTab_007BCC04;                                                                // 0x007BCC04
unsigned char gnMaxTab_007BCC05;                                                                            // 0x007BCC05
int gnGlobal_007BCC08;                                                                                      // 0x007BCC08
int gnGlobal_007BCE9C;                                                                                      // 0x007BCE9C
extern void* gpCellFile_007BEF24;                                                                           // 0x007BEF24
unsigned char gabSlots_007BEFB4[4];                                                                         // 0x007BEFB4

// 0x00480780
int __fastcall sub_00480780_SetPathTargetUnit(D2UnitStrc* pUnit, int nUnitType, int nUnitId)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = sub_00463990(nUnitId, nUnitType);
    PATH_SetTargetUnit(pPath, pTarget);
    if (!pTarget)
    {
        return 0;
    }
    return D2Common_10142(pPath, pUnit, 0);
}

// 0x004824A0
int __stdcall sub_004824A0_FreeCacheEntries(unsigned int nFree, int bTwoPasses, int bCheckAge)
{
    const unsigned int nTarget = gdwCacheUsed_007BC9D0 - nFree;
    const unsigned int dwNow = gdwGlobal_007BC9BC;
    while (gdwCacheUsed_007BC9D0 > nTarget)
    {
        int bFreed = 0;
        int nPass = 0;
        do
        {
            for (D2ClientCacheNodeStrc* pNode = gpCacheList_007BC9B8; pNode; pNode = pNode->pNext)
            {
                const int nId = pNode->nId;
                D2ClientCacheEntryStrc* pEntry = (gpCacheEntries_007BC9A0 && nId >= 0 && nId < gnCacheEntries_007BC9A4) ? &gpCacheEntries_007BC9A0[nId] : 0;
                if (nPass == 0 && (*(int*)pEntry->nRefCount || pEntry->bLocked))
                {
                    continue;
                }
                if (bCheckAge && dwNow - *(unsigned int*)pEntry->dwLastUse < 750)
                {
                    continue;
                }
                if (!sub_004DF9D0_CheckCacheEntry(nId))
                {
                    sub_004823E0_ReleaseCacheEntry(nId);
                    bFreed = 1;
                    break;
                }
            }
            if (!bTwoPasses)
            {
                break;
            }
            ++nPass;
        }
        while (nPass <= 1);

        if (!bFreed)
        {
            return 0;
        }
    }
    return 1;
}

// 0x00487A10
void __stdcall sub_00487A10_SelectItemPageTab(unsigned char nTab)
{
    if (nTab >= 5)
    {
        nTab = 0;
    }
    if (gnGlobal_007BCC08)
    {
        return;
    }
    int nUnitId;
    if (!sub_004B3230_GetSelectedUnitId(&nUnitId))
    {
        return;
    }
    D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    int anCounts[5] = {};
    for (; pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        const unsigned char nPage = ITEMS_GetInvPage(INVENTORY_UnitIsItem(pItem));
        if (nPage < 5)
        {
            ++anCounts[nPage];
        }
    }

    int nTries = 0;
    gnSelectedTab_007BCC04 = nTab;
    for (int i = 0; i < gnGlobal_00722158; ++i)
    {
        *(int*)gaTabs_0072211A[i].bSelected = 0;
        *(int*)gaTabs_0072211A[i].bEnabled = anCounts[i] != 0;
    }

    if (!anCounts[nTab])
    {
        do
        {
            ++gnSelectedTab_007BCC04;
            ++nTries;
            if (gnSelectedTab_007BCC04 > gnMaxTab_007BCC05 || gnSelectedTab_007BCC04 == 0xFF)
            {
                gnSelectedTab_007BCC04 = 0;
            }
            if (anCounts[gnSelectedTab_007BCC04])
            {
                break;
            }
        }
        while (nTries < 4);
    }
    *(int*)gaTabs_0072211A[gnSelectedTab_007BCC04].bSelected = 1;
}

// 0x00488910
void __stdcall sub_00488910_ResetCursorMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if ((gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 4 || gdwGlobal_007BCBF0 == 9)
        && !sub_00453A90_GetUIVarUnchecked(5))
    {
        gnGlobal_007BCBE0 = 0;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gnGlobal_007BCE9C = 0;
        sub_004B3ED0();
        gnGlobal_007BCA4C = 0;
        gnGlobal_007BCBD8 = 0;
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        gnGlobal_00721E3C = -1;
        gnGlobal_00721E40 = -1;
        gnGlobal_00721E44 = -1;
        gnGlobal_00721E48 = -1;
        gnGlobal_00721E4C = -1;
        gnGlobal_00721E50 = -1;
    }
}

// 0x00488E70
void __stdcall sub_00488E70_KeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_00453A90_GetUIVarUnchecked(5) || sub_004B34A0())
    {
        return;
    }
    if (!(pMsg->lParam & 0x40000000))
    {
        sub_00455F20(5, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00489060
int __stdcall sub_00489060_ClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if (nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
    {
        sub_004873A0_HandleClick(pMsg);
        return 1;
    }
    return 0;
}

// 0x004894D0
void __stdcall sub_004894D0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xB)
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if ((nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
        || (nX > gnGlobal_007BCA34 && nX < gnGlobal_007BCA38 && nY >= gnGlobal_007BCA3C && nY <= gnGlobal_007BCA40)
        || (nX > gnGlobal_007BCB1C && nX < gnGlobal_007BCB20 && nY >= gnGlobal_007BCB24 && nY <= gnGlobal_007BCB28))
    {
        sub_004873A0_HandleClick(pMsg);
        return;
    }
    sub_00487990_ResetHover();
    sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
}

static inline int InRect(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX < nRight && nY >= nTop && nY <= nBottom;
}

// 0x0048A0F0
void __stdcall sub_0048A0F0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 != 0xE)
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    if (InRect(nX, nY, gnGlobal_007BCAA0, gnGlobal_007BCAA4, gnGlobal_007BCAA8, gnGlobal_007BCAAC)
        || InRect(nX, nY, gnGlobal_007BCB74, gnGlobal_007BCB78, gnGlobal_007BCB7C, gnGlobal_007BCB80))
    {
        sub_004873A0_HandleClick(pMsg);
    }
    else
    {
        gdwGlobal_007BCBE4 = 0;
        gdwGlobal_007BCBE8 = 0;
        gdwGlobal_007BCBF4 = 0;
        gdwGlobal_007BCBF8 = 0;
        sub_00502280_SetPopUpText(0, -1, -1, 0, 0);
    }
}

// 0x0048BD80
void __stdcall sub_0048BD80_ClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMaxY = gnGlobal_00711470 - 0x31;
    const int nHalfWidth = gnGlobal_0071146C / 2;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= 0 && nX <= nHalfWidth && nY >= 0 && nY <= nMaxY)
    {
        sub_00455F20(0x25, 1, 0);
        sub_0044DA70();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00497C50
void __stdcall sub_00497C50_DrawSlotIcon(int nFrame)
{
    int nX = gnGlobal_0071146C - 0x37;
    int nY = 0x9B;
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (!gabSlots_007BEFB4[i])
        {
            gabSlots_007BEFB4[i] = 1;
            nX -= 0x28 * i;
            break;
        }
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BEF24;
    tContext.unk0x40 = 0;
    tContext.nFrame = nFrame;
    if (sub_004538D0(0xA))
    {
        if (sub_0047A560())
        {
            nY = 0xC6;
        }
        nY += 0x1E;
    }
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x00498A20
int __fastcall sub_00498A20_CheckState(int nUnused, D2ClientStateStrc* pState, int nArg1, int nArg2)
{
    D2_ASSERT(pState, 2621);
    if (pState->bFlag0x129 == 1 || pState->bFlag0x12A == 1)
    {
        sub_0049FF90_Close(nArg2, pState);
        return 0;
    }
    if (pState->bFlag0x11D == 1)
    {
        return 1;
    }
    sub_004CB9C0_Request(nArg1, 0x14);
    return 0;
}

#include "gen/data/Source/D2Client/00480780_sub_00480780_SetPathTargetUnit.inc"
