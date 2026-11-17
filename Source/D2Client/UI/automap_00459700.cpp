#include "D2Client.h"

struct D2AutomapCellStrc;

struct D2AutomapContextStrc
{
    int unk0x00;
    int nLayerKind;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
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

int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
int __cdecl sub_0045AFA0();                                                                                 // 0x0045AFA0
int __cdecl sub_0045AFB0();                                                                                 // 0x0045AFB0
void __fastcall sub_00459440(D2AutomapCellStrc* pCell, D2AutomapDrawStrc* pInfo);                  // 0x00459440

extern D2AutomapContextStrc* gpAutomapContext_007A5164;                                                     // 0x007A5164
int gdwGlobal_007A51E0;                                                                                     // 0x007A51E0
int gdwGlobal_007A51E4;                                                                                     // 0x007A51E4
extern int gdwGlobal_007A51E8;                                                                              // 0x007A51E8
int gdwGlobal_007A5150;                                                                                     // 0x007A5150
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnAutomapScale_00711254;                                                                         // 0x00711254
extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220
extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C
int gnAutomapViewX_007A5190;                                                                                // 0x007A5190
int gnAutomapViewY_007A5194;                                                                                // 0x007A5194
extern int gnAutomapBaseX_007A5188;                                                                         // 0x007A5188
extern int gnAutomapBaseY_007A518C;                                                                         // 0x007A518C
extern int gnAutomapOffsetX_007A5198;                                                                       // 0x007A5198
extern int gnAutomapOffsetY_007A519C;                                                                       // 0x007A519C
D2CelFileStrc* gpAutomapCel_007A5168;                                                                       // 0x007A5168
D2CelFileStrc* gpAutomapCel_007A516C;                                                                       // 0x007A516C
D2CelFileStrc* gpAutomapCel_007A5170;                                                                       // 0x007A5170
D2CelFileStrc* gpAutomapCel_007A5174;                                                                       // 0x007A5174
int gnMiniMapY_007A51D8;                                                                                    // 0x007A51D8
extern int gnMiniMapX_007A51DC;                                                                             // 0x007A51DC

// 0x00459700
void __cdecl sub_00459700_PaintAutomap()
{
    if (!gpAutomapContext_007A5164)
        return;
    int nShift = 0;
    switch (sub_0045AE90())
    {
    case 1:
        if (gdwGlobal_007A5150 != 1)
            nShift = -(gnGlobal_0071146C / 4);
        if (!gdwGlobal_007A51E0)
        {
            gdwGlobal_007A51E4 = 0;
            gdwGlobal_007A51E0 = 1;
        }
        break;
    case 2:
        if (gdwGlobal_007A5150 != 1)
            nShift = gnGlobal_0071146C / 4;
        if (gdwGlobal_007A51E0)
        {
            gdwGlobal_007A51E4 = gdwGlobal_007A51E0;
            gdwGlobal_007A51E0 = 0;
        }
        break;
    default:
        if (gdwGlobal_007A51E0 != gdwGlobal_007A51E4)
            gdwGlobal_007A51E0 = gdwGlobal_007A51E4;
        if (gdwGlobal_007A51E0 != gdwGlobal_007A51E8)
            gdwGlobal_007A51E0 = gdwGlobal_007A51E8;
        break;
    }

    const int nX = sub_0045AFA0() / gnAutomapScale_00711254 - gnAutomapWidth_007A5220 / 2 - nShift;
    const int nY = sub_0045AFB0() / gnAutomapScale_00711254 - gnAutomapHeight_007A521C / 2;
    gnAutomapViewX_007A5190 = nX;
    gnAutomapViewY_007A5194 = nY;
    gnAutomapOffsetX_007A5198 = gnAutomapBaseX_007A5188 + nX + 0x28;
    gnAutomapOffsetY_007A519C = gnAutomapBaseY_007A518C + nY + 0xF;

    D2AutomapDrawStrc tInfo;
    switch (gdwGlobal_007A5150)
    {
    case 1:
        tInfo.pCelFile = gpAutomapCel_007A5168;
        tInfo.nLeft = gnMiniMapX_007A51DC - 8;
        tInfo.nTop = gnMiniMapY_007A51D8 - 0x10;
        tInfo.nRight = gnMiniMapX_007A51DC + gnAutomapWidth_007A5220 / 3 + 8;
        tInfo.nBottom = gnMiniMapY_007A51D8 + gnAutomapHeight_007A521C / 3 + 0x10;
        tInfo.nXOffset = 4;
        tInfo.nYOffset = 8;
        gnAutomapScale_00711254 = 0x14;
        break;
    default:
        tInfo.pCelFile = gpAutomapCel_007A5168;
        tInfo.nLeft = -0x10;
        tInfo.nTop = -0x20;
        tInfo.nRight = gnAutomapWidth_007A5220 + 0x10;
        tInfo.nBottom = gnAutomapHeight_007A521C + 0x20;
        tInfo.nXOffset = 8;
        tInfo.nYOffset = 0x10;
        gnAutomapScale_00711254 = 0xA;
        break;
    }
    sub_00459440(gpAutomapContext_007A5164->pFloors, &tInfo);
    sub_00459440(gpAutomapContext_007A5164->pWalls, &tInfo);
    sub_00459440(gpAutomapContext_007A5164->pObjects, &tInfo);

    switch (gdwGlobal_007A5150)
    {
    case 1:
        switch (gpAutomapContext_007A5164->nLayerKind)
        {
        case 1:
            tInfo.pCelFile = gpAutomapCel_007A516C;
            tInfo.nLeft = gnMiniMapX_007A51DC - 0xA0;
            tInfo.nTop = gnMiniMapY_007A51D8 - 0x64;
            tInfo.nRight = gnMiniMapX_007A51DC + gnAutomapWidth_007A5220 / 3 + 0xA0;
            tInfo.nBottom = gnMiniMapY_007A51D8 + gnAutomapHeight_007A521C / 3 + 0x64;
            tInfo.nXOffset = 0x50;
            tInfo.nYOffset = 0x32;
            break;
        case 2:
            tInfo.pCelFile = gpAutomapCel_007A5170;
            tInfo.nLeft = gnMiniMapX_007A51DC - 0x88;
            tInfo.nTop = gnMiniMapY_007A51D8 - 0x5A;
            tInfo.nRight = gnMiniMapX_007A51DC + gnAutomapWidth_007A5220 / 3 + 0x88;
            tInfo.nBottom = gnMiniMapY_007A51D8 + gnAutomapHeight_007A521C / 3 + 0x5A;
            tInfo.nXOffset = 0x44;
            tInfo.nYOffset = 0x2D;
            break;
        case 3:
            tInfo.pCelFile = gpAutomapCel_007A5174;
            tInfo.nLeft = gnMiniMapX_007A51DC - 0xB4;
            tInfo.nTop = gnMiniMapY_007A51D8 - 0xAA;
            tInfo.nRight = gnMiniMapX_007A51DC + gnAutomapWidth_007A5220 / 3 + 0xB4;
            tInfo.nBottom = gnMiniMapY_007A51D8 + gnAutomapHeight_007A521C / 3 + 0xAA;
            tInfo.nXOffset = 0x5A;
            tInfo.nYOffset = 0x55;
            break;
        default:
            tInfo.pCelFile = gpAutomapCel_007A5168;
            tInfo.nLeft = gnMiniMapX_007A51DC - 8;
            tInfo.nTop = gnMiniMapY_007A51D8 - 0x10;
            tInfo.nRight = gnMiniMapX_007A51DC + gnAutomapWidth_007A5220 / 3 + 8;
            tInfo.nBottom = gnMiniMapY_007A51D8 + gnAutomapHeight_007A521C / 3 + 0x10;
            tInfo.nXOffset = 4;
            tInfo.nYOffset = 8;
            break;
        }
        gnAutomapScale_00711254 = 0x14;
        break;
    default:
        switch (gpAutomapContext_007A5164->nLayerKind)
        {
        case 1:
            tInfo.pCelFile = gpAutomapCel_007A516C;
            tInfo.nLeft = -0xA0;
            tInfo.nTop = -0x64;
            tInfo.nRight = gnAutomapWidth_007A5220 + 0xA0;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0x64;
            tInfo.nXOffset = 0x50;
            tInfo.nYOffset = 0x32;
            break;
        case 2:
            tInfo.pCelFile = gpAutomapCel_007A5170;
            tInfo.nLeft = -0x88;
            tInfo.nTop = -0x5A;
            tInfo.nRight = gnAutomapWidth_007A5220 + 0x88;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0x5A;
            tInfo.nXOffset = 0x44;
            tInfo.nYOffset = 0x2D;
            break;
        case 3:
            tInfo.pCelFile = gpAutomapCel_007A5174;
            tInfo.nLeft = -0xB4;
            tInfo.nTop = -0xAA;
            tInfo.nRight = gnAutomapWidth_007A5220 + 0xB4;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0xAA;
            tInfo.nXOffset = 0x5A;
            tInfo.nYOffset = 0x55;
            break;
        default:
            tInfo.pCelFile = gpAutomapCel_007A5168;
            tInfo.nLeft = -0x10;
            tInfo.nTop = -0x20;
            tInfo.nRight = gnAutomapWidth_007A5220 + 0x10;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0x20;
            tInfo.nXOffset = 8;
            tInfo.nYOffset = 0x10;
            break;
        }
        gnAutomapScale_00711254 = 0xA;
        break;
    }
    sub_00459440(gpAutomapContext_007A5164->pExtras, &tInfo);
}
