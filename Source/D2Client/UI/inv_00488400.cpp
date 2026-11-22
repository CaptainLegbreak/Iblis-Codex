#include "D2Structs.h"
#include "D2CelContext.h"
struct D2CelFileStrc;
struct D2UnitStrc;
typedef unsigned int size_t;
struct Unicode;
struct D2InventoryStrc;



#pragma pack(push, 2)
struct D2PanelButtonStrc
{
    int bActive;
    int nValue;
    unsigned short nString;
    int nCel;
    unsigned short nFrame;
    int nType;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2PanelTabStrc
{
    int nX;
    int nY;
    unsigned short nString;
    int bSelected;
    int bEnabled;
};
#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                     // 0x00681EF0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall sub_004B3230_GetTickPair(int* pUnitId);                                                // 0x004B3230
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
void __stdcall sub_00483FF0_DrawUnitInventory(D2UnitStrc* pUnit);                                           // 0x00483FF0
D2CelFileStrc* __cdecl sub_00454600_GetBuySellButtonCells(); // 0x00454600
int __fastcall sub_00502EF0(int nFont);                                                                     // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
int __cdecl sub_004B3500();                                                                                 // 0x004B3500
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

extern int gnGlobal_007BCBEC;                                                                               // 0x007BCBEC
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0
extern D2PanelButtonStrc gaPanelButtons_007BC9E0[];                                                         // 0x007BC9E0
extern void* gpCelFile_007C0DC8;                                                                            // 0x007C0DC8
extern void* gpCellFile_007BCC24;                                                                           // 0x007BCC24
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnButtonCount_00722160;                                                                          // 0x00722160
extern int gnButtonRow_0072215C;                                                                            // 0x0072215C
extern int ganButtonX_00722168[][4];                                                                        // 0x00722168
extern int gnGlobal_00722158;                                                                               // 0x00722158
extern D2PanelTabStrc gaTabs_00722110[];                                                                    // 0x00722110

extern int gdwGlobal_007A6ABC;                                                                              // 0x007A6ABC
extern int gnGlobal_007A6ADC;                                                                               // 0x007A6ADC
extern int gdwGlobal_007A6AE0;                                                                              // 0x007A6AE0
extern int gdwGlobal_007A6AF0;                                                                              // 0x007A6AF0

__declspec(noinline) void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem);
// 0x00468070
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem)
{
    gdwGlobal_007A6ABC = (int)pItem;
    gnGlobal_007A6ADC = 5;
    if (!pItem)
    {
        gdwGlobal_007A6AE0 = 0;
        gdwGlobal_007A6AF0 = 1;
    }
    else
    {
        gdwGlobal_007A6AE0 = 0;
        gdwGlobal_007A6AF0 = 1;
        gdwGlobal_007A6AF0 = 4;
    }
}

// 0x00488400
void __cdecl sub_00488400_DrawPanel()
{
    if (gnGlobal_007BCBEC == 1)
    {
        gaPanelButtons_007BC9E0[0].nValue = 0;
        gaPanelButtons_007BC9E0[1].nValue = 0;
        gaPanelButtons_007BC9E0[2].nValue = 0;
        gaPanelButtons_007BC9E0[3].nValue = 0;
        gdwGlobal_007BCBF0 = 1;
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        gnGlobal_007BCBEC = 0;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCelFile_007C0DC8;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnGlobal_007A2858 + 0x100, gnGlobal_00711470 + gnGlobal_007A285C - 0x30, -1, 5, 0);

    int nUnitId;
    if (sub_004B3230_GetTickPair(&nUnitId))
    {
        D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
        if (pUnit)
        {
            sub_00483FF0_DrawUnitInventory(pUnit);
        }
    }

    tContext.pCellFile = sub_00454600_GetBuySellButtonCells();
    for (int i = 0; i < gnButtonCount_00722160; ++i)
    {
        tContext.nFrame = gaPanelButtons_007BC9E0[i].nValue + gaPanelButtons_007BC9E0[i].nFrame;
        sub_004F6480(&tContext, ganButtonX_00722168[gnButtonRow_0072215C][i] + gnGlobal_007A2858 - 1,
            gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, -1, 5, 0);
    }

    const int nOldFont = sub_00502EF0(1);
    for (int i = 0; i < gnGlobal_00722158; ++i)
    {
        int nColor = 0;
        if (gaTabs_00722110[i].bSelected)
        {
            nColor = 4;
        }
        if (gaTabs_00722110[i].bEnabled)
        {
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(gaTabs_00722110[i].nString);
            const int nWidth = sub_00501820(wszText);
            tContext.pCellFile = gpCellFile_007BCC24;
            if (nColor == 4)
            {
                tContext.nFrame = i;
            }
            else if (nColor == 0)
            {
                tContext.nFrame = i + 4;
            }
            sub_004F6480(&tContext, i * 0x50 + gnGlobal_007A2858, gnGlobal_00711470 + gnGlobal_007A285C - 0x1C1, -1, 5, 0);
            if (!sub_004B3500())
            {
                sub_00502320(wszText, gaTabs_00722110[i].nX - nWidth / 2 + gnGlobal_007A2858,
                    gaTabs_00722110[i].nY + gnGlobal_007A285C + gnGlobal_00711470 - 0x1E0, nColor, 0);
            }
        }
    }
    sub_00502EF0(nOldFont);
}
