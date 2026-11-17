#include "D2Client.h"

typedef unsigned int size_t;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemPool;
    int dwUnitId;
    int dwAnimMode;
    void* pPlayerData;
    unsigned char nAct;
};

struct D2AutomapCellStrc
{
    int fSaved;
    short nCellNo;
    short xPixel;
    short yPixel;
    short nWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

struct D2AutomapDrawStrc
{
    D2CelFileStrc* pCelFile;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    int nXOffset;
    int nYOffset;
};

struct D2GfxDataStrc
{
    int nFrame;
    int unk0x04[12];
    D2CelFileStrc* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct D2CropRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                     // 0x00681EF0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
static int __cdecl sub_004576C0();                                                                          // 0x004576C0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __cdecl sub_00492C10();                                                                                 // 0x00492C10
void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, D2CropRectStrc* pCropRect, int eDrawMode); // 0x004F6510

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnAutomapScale_00711254;                                                                         // 0x00711254
int gnAutomapOffsetX_007A5198;                                                                              // 0x007A5198
int gnAutomapOffsetY_007A519C;                                                                              // 0x007A519C
extern int gdwGlobal_007A5150;                                                                              // 0x007A5150
extern D2CelFileStrc* gpAutomapCel_007A5168;                                                                // 0x007A5168
extern int gdwGlobal_007A51E0;                                                                              // 0x007A51E0
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
extern int gdwAutoMapFade_007A51A8;                                                                         // 0x007A51A8
extern int gdwAutoMapFadeSaved_007A51AC;                                                                    // 0x007A51AC

int __fastcall sub_00457450_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

static __declspec(noinline) int __cdecl sub_004576C0()
{
    if (gdwGlobal_007A5150 == 1 && gdwAutoMapFade_007A51A8 == 1)
    {
        gdwAutoMapFade_007A51A8 = gdwAutoMapFadeSaved_007A51AC ? 0 : 2;
    }
    return gdwAutoMapFade_007A51A8;
}

// 0x00459440
void __fastcall sub_00459440(D2AutomapCellStrc* pCell, D2AutomapDrawStrc* pInfo)
{
    if (!pCell)
    {
        return;
    }

    int nShift = 0;
    switch (sub_0045AE90())
    {
    case 1:
        nShift = -(gnGlobal_0071146C / 4);
        break;
    case 2:
        nShift = gnGlobal_0071146C / 4;
        break;
    }

    int nX = pCell->xPixel * 10 / gnAutomapScale_00711254;
    int nY = pCell->yPixel * 10 / gnAutomapScale_00711254;
    nX -= gnAutomapOffsetX_007A5198;
    nY -= gnAutomapOffsetY_007A519C;

    if (nY >= pInfo->nTop)
    {
        sub_00459440(pCell->pPrev, pInfo);
    }

    if (nY >= pInfo->nTop && nY <= pInfo->nBottom && nX >= pInfo->nLeft && nX <= pInfo->nRight)
    {
        int nDrawMode = 5;
        D2GfxDataStrc tData;
        memset(&tData, 0, sizeof(tData));
        tData.nFrame = pCell->nCellNo;
        tData.pCellFile = pInfo->pCelFile;
        tData.unk0x40 = 0;

        switch (sub_004576C0())
        {
        case 1:
            if (pInfo->pCelFile == gpAutomapCel_007A5168 && !gdwGlobal_007A5150)
            {
                const int nPosX = pInfo->nXOffset + nX;
                const int nPosY = pInfo->nYOffset + nY;
                const int nHalfHeight = gnAutomapHeight_007A521C / 2;
                const int nCenterY = nHalfHeight - 10;
                const int nHalfWidth = gnAutomapWidth_007A5220 / 2;
                if (nPosX >= nHalfWidth + nShift - 0x8C && nPosX <= nHalfWidth + nShift + 0x8C && nPosY >= nHalfHeight - 0x96 && nPosY <= nHalfHeight + 0x82)
                {
                    const int nDistX = sub_00457450_Abs(nHalfWidth - nPosX + nShift);
                    const int nDistY = sub_00457450_Abs(nCenterY - nPosY);
                    const int nDist = (nDistX > nDistY ? nDistY + 2 * nDistX : nDistX + 2 * nDistY) / 2;
                    if (nDist < 0x96)
                    {
                        nDrawMode = sub_004576C0() == 2 ? 1 : 2;
                        if (nDist < 0x64)
                        {
                            nDrawMode = 1;
                            if (nDist < 0x32)
                            {
                                nDrawMode = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            nDrawMode = 1;
            break;
        case 3:
            switch (sub_00463DD0()->nAct)
            {
            case 0:
            case 2:
                switch (gdwGlobal_007A5150)
                {
                case 1:
                    nDrawMode = 1;
                    break;
                default:
                    nDrawMode = 2;
                    break;
                }
                break;
            }
            break;
        }

        D2CropRectStrc tRect;
        switch (gdwGlobal_007A5150)
        {
        case 1:
            if (gdwGlobal_007A51E0)
            {
                tRect.nLeft = 0;
                tRect.nTop = (sub_00492C10() ? 0x60 : 0) - 0x15;
            }
            else
            {
                tRect.nLeft = gnGlobal_0071146C - 0x119;
                tRect.nTop = 0x39;
            }
            tRect.nRight = tRect.nLeft + 0x117;
            tRect.nBottom = tRect.nTop + 0xE1;
            break;
        default:
            tRect.nLeft = 0;
            tRect.nRight = gnGlobal_0071146C - 1;
            tRect.nTop = 0;
            tRect.nBottom = gnGlobal_00711470 - 1;
            break;
        }
        TEXTURE_CelDrawClipped(&tData, nX, nY, &tRect, nDrawMode);
    }

    if (nY <= pInfo->nBottom)
    {
        sub_00459440(pCell->pNext, pInfo);
    }
}
