struct D2InventoryStrc;
struct D2ActInfoStrc;
struct D2TileStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
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

struct D2PanelGfxStrc
{
    int unk0x00[15];
    int f_3C;
    int unk0x40[2];
};

struct D2HintCursorStrc
{
    char unk0x00[0x50];
    int aValues[1];
};

struct D2TimedHintStrc
{
    int bActive;
    void* pOwner;
    int nEndTickA;
    int bActive2;
    int nArgE;
    int nEndTickF;
    int nArgG;
    int nEndTickC;
};

struct D2FloorTileViewStrc
{
    char unk0x00[0x3C];
    int nOffsetX;
    int nOffsetY;
    void __thiscall sub_004DE410_DrawFloorTile(D2TileStrc* pTile, int nArg, int nScreenX, int nScreenY, int nX, int nY);
    void __thiscall sub_004DE630_DrawTileAt(int nX, int nY);
    void __thiscall sub_004DE6C0_DrawTileTriple(int nX, int nY, int nStepX, int nStepY);
};

struct D2CellPosStrc
{
    int nX;
    int nY;
    char unk0x08[0x10];
    int f_18;
};

struct D2CellNodeStrc
{
    unsigned int dwFlags;
    int nA;
    int nB;
    D2CellPosStrc* pPos;
    D2CellNodeStrc* pNext;
};

struct D2GridCellStrc
{
    int unk0x00[4];
    D2CellNodeStrc* pNodes;
    int f_14;
    int unk0x18[3];
};

struct D2CellGridViewStrc
{
    int unk0x00;
    int nOffsetX;
    int nOffsetY;
    int unk0x0C[6];
    int nScrollX;
    int nScrollY;
    char unk0x2C[0xEA7C];
    D2GridCellStrc* pCells;
    char unk0xEAAC[0x04];
    int nSize;
    void __thiscall sub_004DF510_DrawCellNodes();
};

struct D2AddressInfoStrc
{
    short nUnk0x00;
    short f_2;
    int nMagic;
    int nUnk0x08;
    short f_C;
    short nVersion;
    int f_10;
};

struct D2AddressQueryStrc
{
    char unk0x00[0x50];
    char bFamilyMatch;
    char unk0x51[0x1B];
    int nSocket;
    int nParam;
    int nResult;
    int nParamOut;
    char unk0x7C[0x05];
    char f_81;
    char unk0x82[0x04];
    char nState[4];
};

struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int f_4;
    char unk0x08[0x2C];
    unsigned int nKey;
};

struct D2SlotStrc
{
    int f_0;
    int unk0x04;
    D2SlotObjectStrc* pObject;
    char unk0x0C[0x14];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" const char gszGfxUtilSourceFile[];                                                               // 0x006DB974

extern int gnGlobal_007278FC;                                                                               // 0x007278FC
extern D2HotspotStrc gaHotspots_00727902[];                                                                 // 0x00727902
extern int gnGlobal_007C5474;                                                                               // 0x007C5474
extern int gnGlobal_007C5480;                                                                               // 0x007C5480
extern void* gpfnEventTable_00727DB4[2];                                                                    // 0x00727DB4
extern int gnGlobal_007C89D8;                                                                               // 0x007C89D8
extern int gnGlobal_007C89E0;                                                                               // 0x007C89E0
extern D2TimedHintStrc gTimedHint_007C89E4;                                                                 // 0x007C89E4
extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
extern int gdwGlobal_007C8C78;                                                                              // 0x007C8C78
extern D2SlotStrc gaSlots_007C8A78[16];                                                                     // 0x007C8A78

int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
int __cdecl sub_00463DF0();                                                                                 // 0x00463DF0
void __fastcall sub_0046EE80(D2UnitStrc* pUnit, int nX, int nY);                                            // 0x0046EE80
void __fastcall sub_00471620(D2CellPosStrc* pPos);                                                          // 0x00471620
void __fastcall sub_00475AA0(int nA, int nB, unsigned char* pByte0, unsigned char* pByte1, unsigned char* pByte2, unsigned char* pByte3); // 0x00475AA0
int __cdecl sub_004817F0();                                                                                 // 0x004817F0
int __cdecl sub_00481810();                                                                                 // 0x00481810
int __cdecl sub_00481820();                                                                                 // 0x00481820
D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
int __fastcall sub_004B9590(void* pEntry);                                                                  // 0x004B9590
void* __fastcall sub_004B9610(int nId);                                                                     // 0x004B9610
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __cdecl sub_004BA8F0();                                                                                // 0x004BA8F0
void __cdecl sub_004BFDD0();                                                                                // 0x004BFDD0
void __cdecl sub_004C0090();                                                                                // 0x004C0090
int __fastcall sub_004DBB50(D2PanelGfxStrc* pGfx, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5, int* pOut, int nArg7, int nArg8); // 0x004DBB50
void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0
int __fastcall sub_004DC110(void* pArg1, int nArg2, int nArg3, int nArg4, void* pfnCallback, int nArg6, int nArg7); // 0x004DC110
void __fastcall sub_004DC7B0(D2CellPosStrc* pPos, unsigned int nColor, int nArg);                           // 0x004DC7B0
void __stdcall sub_004DEF80(D2GridCellStrc* pCell, int nArg, D2CellGridViewStrc* pView);                    // 0x004DEF80
int __cdecl sub_004F51D0();                                                                                 // 0x004F51D0
void __stdcall sub_004F6980(int nHandle, int nX, int nY, int nArg4, int nArg5);                             // 0x004F6980
int __fastcall sub_00515710(int nHandle);                                                                   // 0x00515710
int __fastcall sub_00516760(int nSocket, int* pParam, D2AddressInfoStrc* pInfo);                            // 0x00516760
int __stdcall sub_006001F0(D2PanelGfxStrc* pGfx, int nArg2, int nArg3);                                     // 0x006001F0
D2TileStrc* __stdcall sub_00619720(void* pAct);                                                             // 0x00619720
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
void __stdcall sub_006275B0(D2UnitStrc* pUnit);                                                         // 0x006275B0
void __stdcall sub_006277F0(D2UnitStrc* pUnit, D2UnitStrc* pItem);                               // 0x006277F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
D2UnitStrc* __stdcall sub_0063BEF0(D2InventoryStrc* pInventory);                                    // 0x0063BEF0
int __stdcall sub_0063BDB0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);                   // 0x0063BDB0
D2UnitStrc* __stdcall sub_0063BDE0(D2InventoryStrc* pInventory, int nBodyLoc);                              // 0x0063BDE0
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc);                                     // 0x0063BE30
void __stdcall sub_00643260(int* pX, int* pY);                                                   // 0x00643260

// 0x004BFBC0
void __fastcall sub_004BFBC0_HitTestHotspots(int nX, int nY)
{
    for (int i = 0; i < gnGlobal_007278FC; i++)
    {
        gaHotspots_00727902[i].bFlag0x25 = 0;
        gaHotspots_00727902[i].bFlag0x24 = 0;
    }

    for (int i = 0; i < gnGlobal_007278FC; i++)
    {
        if (nX >= gaHotspots_00727902[i].nLeft && nX <= gaHotspots_00727902[i].nRight && nY >= gaHotspots_00727902[i].nTop && nY <= gaHotspots_00727902[i].nBottom)
        {
            sub_004B9A00(1, 0, 0, 0, 0);
            gaHotspots_00727902[i].bFlag0x25 = 1;
            gaHotspots_00727902[i].bFlag0x24 = 1;
        }
    }
}

// 0x004C01E0
void __cdecl sub_004C01E0_DrawPanelUnit()
{
    if (gnGlobal_007C5474)
    {
        if (sub_00463DF0())
        {
            sub_004C0090();
            return;
        }

        sub_004BFDD0();
        if (gnGlobal_007C5474 == 2)
        {
            D2UnitStrc* pUnit = sub_00463990(gnGlobal_007C5480, 4);
            if (pUnit)
            {
                D2PanelGfxStrc tGfx;
                int nOut;
                memset(&tGfx, 0, sizeof(tGfx));
                if (sub_004DBB50(&tGfx, pUnit, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tGfx, 0, 1) && tGfx.f_3C)
                {
                    unsigned int nWidth;
                    unsigned int nHeight;
                    sub_004DBEA0(pUnit, 0, 0, &nWidth, &nHeight);
                    UNITS_ChangeAnimMode(pUnit, 0);
                    int nOffsetY = 0;
                    if (nHeight < 0x70)
                    {
                        nOffsetY = (0x72 - nHeight) >> 1;
                    }
                    sub_0046EE80(pUnit, 0xA7 - (nWidth >> 1), nOffsetY + 0x6A);
                    UNITS_ChangeAnimMode(pUnit, 4);
                }
            }
        }
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x31D);
        exit(-1);
    }
}

// 0x004C0EC0
void __fastcall sub_004C0EC0_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp)
{
    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwUnitType == 0)
    {
        sub_0063BEF0(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp") || bForce)
    {
        sub_006277F0(pUnit, pItem);
    }

    if (bClamp)
    {
        sub_006275B0(pUnit);
    }
}

// 0x004C1C50
int __fastcall sub_004C1C50_PlaceBodyItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc)
{
    if (!pItem)
    {
        return 0;
    }

    if (sub_0063BDE0(pInventory, nBodyLoc))
    {
        sub_0063BE30(pInventory, nBodyLoc);
    }

    return sub_0063BDB0(pInventory, pItem, nBodyLoc) != 0;
}

// 0x004C7C40
int __fastcall sub_004C7C40_RegisterTableEvent(void* pArg1, int nArg2, int nArg3, int nArg4, unsigned int nIndex, int nArg6, int nArg7)
{
    if (nIndex <= 1)
    {
        void* pfnCallback = gpfnEventTable_00727DB4[nIndex];
        if (pfnCallback)
        {
            return sub_004DC110(pArg1, nArg2, nArg3, nArg4, pfnCallback, nArg6, nArg7);
        }
    }

    return 0;
}

// 0x004DCD40
void __fastcall sub_004DCD40_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG)
{
    if (gnGlobal_007C89D8)
    {
        D2HintCursorStrc* pCursor = sub_00481860(gnGlobal_007C89D8);
        void* pEntry = sub_004B9610(gnGlobal_007C89D8);
        if (pEntry && sub_004B9590(pEntry))
        {
            const int nValue = nIndex > 0 ? pCursor->aValues[nIndex] : 0;
            const int nOffset = 4 * (gnGlobal_007C89D8 - sub_004817F0());
            *(int*)(sub_00481810() + nOffset) = nValue;
            gnGlobal_007C89E0 = sub_00481820();
        }
    }

    sub_004BA8F0();
    gTimedHint_007C89E4.bActive = 1;
    gTimedHint_007C89E4.pOwner = pOwner;
    gTimedHint_007C89E4.nEndTickA = sub_0044DB00() + nDelayA;
    gTimedHint_007C89E4.bActive2 = 1;
    gTimedHint_007C89E4.nArgE = nArgE;
    gTimedHint_007C89E4.nEndTickF = sub_0044DB00() + nDelayF;
    gTimedHint_007C89E4.nArgG = nArgG;
    gTimedHint_007C89E4.nEndTickC = sub_0044DB00() + nDelayC;
}

// 0x004DE630
void __thiscall D2FloorTileViewStrc::sub_004DE630_DrawTileAt(int nX, int nY)
{
    int nScreenX = nX;
    int nScreenY = nY + 5;
    sub_00643260(&nScreenX, &nScreenY);
    nScreenY += 0x28;
    D2_ASSERT(gpGlobal_007A0634, 0xDF);
    nScreenX += nOffsetX;
    nScreenY += nOffsetY;
    D2TileStrc* pTile = sub_00619720(gpGlobal_007A0634);
    if (pTile)
    {
        sub_004DE410_DrawFloorTile(pTile, 1, nScreenX, nScreenY, nX, nY);
    }
}

// 0x004DE6C0
void __thiscall D2FloorTileViewStrc::sub_004DE6C0_DrawTileTriple(int nX, int nY, int nStepX, int nStepY)
{
    const int nBaseX = nX / 5 * 5;
    const int nBaseY = nY / 5 * 5;
    sub_004DE630_DrawTileAt(nBaseX, nBaseY);
    sub_004DE630_DrawTileAt(nBaseX + nStepX, nBaseY + nStepY);
    sub_004DE630_DrawTileAt(nBaseX + 2 * nStepX, nBaseY + 2 * nStepY);
}

// 0x004DF510
void __thiscall D2CellGridViewStrc::sub_004DF510_DrawCellNodes()
{
    const int nCells = nSize;
    int nCount = nCells * nCells;
    D2GridCellStrc* pCell = pCells;
    const int nArg = sub_0045AE90();
    while (nCount--)
    {
        for (D2CellNodeStrc* pNode = pCell->pNodes; pNode; pNode = pNode->pNext)
        {
            if (!(pNode->dwFlags & 3))
            {
                unsigned char nByte0;
                unsigned char nByte1;
                unsigned char nByte2;
                unsigned char nByte3;
                sub_00475AA0(pNode->nA, pNode->nB, &nByte0, &nByte1, &nByte2, &nByte3);
                sub_004DC7B0(pNode->pPos, (((nByte3 << 8 | nByte2) << 8 | nByte1) << 8) | nByte0, 0);
            }
            else
            {
                const int bMode = sub_004F51D0();
                if (pNode->dwFlags & 1)
                {
                    if (bMode)
                    {
                        sub_004F6980(pNode->pPos->f_18, pNode->nA, pNode->nB, 4, nArg);
                    }
                    else
                    {
                        sub_004F6980(pNode->pPos->f_18, nOffsetX - nScrollX + pNode->pPos->nX, pNode->pPos->nY - nScrollY + nOffsetY, 4, nArg);
                    }
                }
                else if (pNode->dwFlags & 2)
                {
                    sub_00471620(pNode->pPos);
                }
            }
        }

        if (pCell->f_14)
        {
            sub_004DEF80(pCell, 1, this);
        }
        ++pCell;
    }
}

// 0x004DF630
int __fastcall sub_004DF630_QueryAddress(D2AddressQueryStrc* pQuery)
{
    D2_ASSERT(*(int*)pQuery->nState == 2, 0x5D);

    D2AddressInfoStrc tInfo;
    int nParam = pQuery->nParam;
    int nResult = sub_00516760(pQuery->nSocket, &nParam, &tInfo);
    if (nResult && tInfo.nVersion == 0x10 && tInfo.nMagic == 0x5622)
    {
        pQuery->nResult = nResult;
        pQuery->nParamOut = nParam;
        pQuery->bFamilyMatch = tInfo.f_2 == 2;
        return 1;
    }

    pQuery->f_81 = 1;
    return 0;
}

// 0x004DF9D0
D2SlotStrc* __fastcall sub_004DF9D0_FindBestSlot(int nOwner)
{
    if (!gdwGlobal_007C8C78)
    {
        return 0;
    }

    D2SlotStrc* pBest = 0;
    for (int i = 0; i < 16; i++)
    {
        D2SlotStrc* pSlot = &gaSlots_007C8A78[i];
        if (sub_00515710(pSlot->f_0) && pSlot->pObject && pSlot->pObject->f_4 == nOwner)
        {
            if (!pBest || pSlot->pObject->nKey < pBest->pObject->nKey)
            {
                pBest = pSlot;
            }
        }
    }

    return pBest;
}

#include "gen/data/Source/D2Client/004BFBC0_sub_004BFBC0_HitTestHotspots.inc"
