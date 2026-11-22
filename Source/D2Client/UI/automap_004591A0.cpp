#include "D2StateIds.h"
#include "D2LevelIds.h"
#include "D2DrlgTiles.h"
#include "D2ClientUi.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2Unicode.h"

#define AUTOMAP_SIZE_MINI 1

#define TOWNCEL_LUTGHOLEIN_MINI 0

#define TOWNCEL_LUTGHOLEIN_ALT_MINI 0x14

#define TOWNCEL_LUTGHOLEIN_FULL 0

#define TOWNCEL_LUTGHOLEIN_ALT_FULL 0x14

#define TOWNCEL_PANDFORT_MINI 0

#define TOWNCEL_PANDFORT_FULL 0

#define TOWNCEL_HARROGATH_MINI 0

#define TOWNCEL_HARROGATH_FULL 0

struct D2ActiveRoomStrc;

struct D2UnitStrc;

struct D2AutomapLayerStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
    D2AutomapLayerStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

void __cdecl sub_004584C0();                                                                         // 0x004584C0

void __cdecl sub_00458680_ResetAutomapCells();                                                                         // 0x00458680

void __cdecl sub_00458750();                                                                        // 0x00458750

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0

D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470

void __stdcall sub_00458F40_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer); // 0x00458F40

void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);                                              // 0x00643310

D2AutomapCellStrc* __cdecl sub_00457C30();                                                       // 0x00457C30

int __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot); // 0x00457B00

extern "C" const char szAutomapFile_006D66F0[];                                                             // 0x006D66F0

extern D2AutomapLayerStrc* gpAutomapNodes_007A5160;                                                         // 0x007A5160

extern D2AutomapLayerStrc* gpAutomapContext_007A5164;                                                       // 0x007A5164

extern int gdwGlobal_007A5150;                                                                              // 0x007A5150

extern int gnRevealSkip_007A51A4;                                                                           // 0x007A51A4

extern int gnPlayerX_007A5200;                                                                              // 0x007A5200

extern int gnPlayerY_007A51F8;                                                                              // 0x007A51F8

extern int gnLastX_007A51FC;                                                                                // 0x007A51FC

extern int gnLastY_007A51F4;                                                                                // 0x007A51F4

extern const int gaTownSkipCels_006D6608[];                                                                 // 0x006D6608

static D2AutomapLayerStrc* sub_00458D40_InitAutomapLayer(int nLayerNo);


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

struct D2CropRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};


int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90

static int __cdecl sub_004576C0();                                                                          // 0x004576C0

int __cdecl sub_00492C10();                                                                                 // 0x00492C10

void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510

extern int gnGlobal_0071146C;                                                                               // 0x0071146C

extern int gnGlobal_00711470;                                                                               // 0x00711470

extern int gnAutomapScale_00711254;                                                                         // 0x00711254

int gnAutomapOffsetX_007A5198;                                                                              // 0x007A5198

int gnAutomapOffsetY_007A519C;                                                                              // 0x007A519C

extern D2CelFileStrc* gpAutomapCel_007A5168;                                                                // 0x007A5168

extern int gdwGlobal_007A51E0;                                                                              // 0x007A51E0

extern int gnAutomapWidth_007A5220;                                                                         // 0x007A5220

extern int gnAutomapHeight_007A521C;                                                                        // 0x007A521C

extern int gdwAutoMapFade_007A51A8;                                                                         // 0x007A51A8

extern int gdwAutoMapFadeSaved_007A51AC;                                                                    // 0x007A51AC

extern "C" size_t __cdecl strlen(const char* szString);

extern const D2AutomapPointStrc gaAutomapCross_006D6638[13];                                                 // 0x006D6638

extern int gdwGlobal_007113E8;                                                                              // 0x007113E8

extern unsigned char gnAutomapColors_007A51B0[];                                                            // 0x007A51B0

extern int gnGlobal_007A51C8;                                                                               // 0x007A51C8

extern int gnGlobal_007A51CC;                                                                               // 0x007A51CC

extern int gnGlobal_007A51D0;                                                                               // 0x007A51D0

extern int gnGlobal_007A51D4;                                                                               // 0x007A51D4

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

int __fastcall sub_00457490_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0

short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit);                                    // 0x00465400

int __fastcall sub_00478D90_GetPetRelation(int nUnitId); // 0x00478D90

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30

int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory);                                            // 0x0063D450

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit);                                      // 0x00464A60

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990

D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);               // 0x004795A0

unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                      // 0x00479BC0

int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord);                               // 0x0047A0C0

int __fastcall sub_0047A1E0(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A1E0

void __fastcall sub_0047A1B0_GetEntryPosition(D2StoredUnitRecordStrc* pEntry, int* pX, int* pY);            // 0x0047A1B0

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY);                                                   // 0x00643260

extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

static D2AutomapLayerStrc* sub_00458D40_InitAutomapLayer(int nLayerNo)
{
    D2AutomapLayerStrc* pLayer;
    for (pLayer = gpAutomapNodes_007A5160; pLayer; pLayer = pLayer->pNext)
    {
        if (pLayer->nLayerNo == nLayerNo)
            break;
    }

    if (!pLayer)
    {
        D2AutomapLayerStrc* pNew = (D2AutomapLayerStrc*)FOG_Alloc(sizeof(D2AutomapLayerStrc), szAutomapFile_006D66F0, 0x5ED, 0);
        memset(&pNew->fSaved, 0, 5 * sizeof(int));
        D2AutomapLayerStrc* pHead = gpAutomapNodes_007A5160;
        pNew->nLayerNo = nLayerNo;
        pNew->pNext = pHead;
        gpAutomapNodes_007A5160 = pNew;
        pLayer = pNew;
    }

    if (pLayer != gpAutomapContext_007A5164)
    {
        sub_004584C0();
        sub_00458680_ResetAutomapCells();
        gpAutomapContext_007A5164 = pLayer;
        sub_00458750();
    }

    return pLayer;
}

// 0x004591A0
void __stdcall sub_004591A0_AddTownCelsCallback(int nLevelId, int nPickedFile, int nX, int nY)
{
    const int nPrevLayerNo = gpAutomapContext_007A5164 ? gpAutomapContext_007A5164->nLayerNo : -1;
    D2AutomapLayerStrc* pLayer = sub_00458D40_InitAutomapLayer(DATATBLS_GetLevelDefRecord(nLevelId)->dwLayer);
    int nStepX;
    int nStepY;
    int nRows;
    const int* pSkip;
    int nColumns;
    int nOffsetX;
    int nOffsetY;
    int nCelNo;
    switch (nLevelId)
    {
    case LEVEL_LUTGHOLEIN:
        pLayer->fSaved = 1;
        switch (gdwGlobal_007A5150)
        {
        case AUTOMAP_SIZE_MINI:
            nCelNo = nPickedFile != 1 ? TOWNCEL_LUTGHOLEIN_ALT_MINI : TOWNCEL_LUTGHOLEIN_MINI;
            break;
        default:
            nCelNo = nPickedFile != 1 ? TOWNCEL_LUTGHOLEIN_ALT_FULL : TOWNCEL_LUTGHOLEIN_FULL;
            break;
        }
        pSkip = gaTownSkipCels_006D6608;
        nColumns = 5;
        nRows = 4;
        nOffsetX = 0x35;
        nOffsetY = -0x51;
        nStepX = 0xA0;
        nStepY = 0x64;
        nPickedFile = nCelNo;
        break;

    case LEVEL_THEPANDEMONIUMFORTRESS:
        pLayer->fSaved = 2;
        pSkip = 0;
        nColumns = 2;
        nRows = 2;
        nOffsetX = -3;
        nOffsetY = -0x32;
        nStepX = 0x88;
        nStepY = 0x5A;
        switch (gdwGlobal_007A5150)
        {
        case AUTOMAP_SIZE_MINI:
            nCelNo = TOWNCEL_PANDFORT_MINI;
            break;
        default:
            nCelNo = TOWNCEL_PANDFORT_FULL;
            break;
        }
        nPickedFile = nCelNo;
        break;

    case LEVEL_HARROGATH:
        pLayer->fSaved = 3;
        pSkip = 0;
        nColumns = 3;
        nRows = 2;
        nOffsetX = -0x14;
        nOffsetY = -0x9B;
        nStepX = 0xB4;
        nStepY = 0xAA;
        switch (gdwGlobal_007A5150)
        {
        case AUTOMAP_SIZE_MINI:
            nCelNo = TOWNCEL_HARROGATH_MINI;
            break;
        default:
            nCelNo = TOWNCEL_HARROGATH_FULL;
            break;
        }
        nPickedFile = nCelNo;
        break;

    default:
        D2_ASSERT(0, 0x751);
    }

    DUNGEON_GameTileToClientCoords(&nX, &nY);
    nX /= 10;
    nY /= 10;
    const int nHalfWidth = nStepX * nColumns / 2 + nOffsetX;
    int nPosY = nY - nStepY * nRows / 2 - nOffsetY;
    for (int nRow = 0; nRow < nRows; ++nRow)
    {
        int nPosX = nX - nHalfWidth;
        for (int nColumn = 0; nColumn < nColumns; ++nColumn)
        {
            {
                const int* p = pSkip;
                int nSkipCel;
                int bMore;
                if (p)
                {
                    nSkipCel = *p;
                    bMore = 1;
                }
                else
                {
                    bMore = 0;
                }
                while (bMore)
                {
                    if (nSkipCel == -1)
                        bMore = 0;
                    else if (nSkipCel == nPickedFile)
                        goto next;
                    else
                    {
                        ++p;
                        nSkipCel = *p;
                    }
                }
            }

            D2_ASSERT(nPosX >= -0x8000 && nPosX <= 0x7FFF, 0x777);
            D2_ASSERT(nPosY >= -0x8000 && nPosY <= 0x7FFF, 0x778);
            D2_ASSERT(nPickedFile >= -0x8000 && nPickedFile <= 0x7FFF, 0x779);
            {
                D2AutomapCellStrc* pCell = sub_00457C30();
                pCell->fSaved = 0;
                pCell->nCellNo = nPickedFile;
                pCell->xPixel = nPosX;
                pCell->yPixel = nPosY;
                sub_00457B00(pCell, &pLayer->pExtras);
            }
next:
            ++nPickedFile;
            nPosX += nStepX;
        }
        nPosY += nStepY;
    }

    if (nPrevLayerNo != -1)
        sub_00458D40_InitAutomapLayer(nPrevLayerNo);
}

int __fastcall sub_00457450_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

static int __cdecl sub_004576C0()
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
        tData.nDirection = 0;

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
            switch (sub_00463DD0_GetPlayerUnit()->nAct)
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

static inline int AUTOMAP_GetUnitType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static inline int AUTOMAP_GetUnitClassId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

static inline int AUTOMAP_GetUnitAnimMode(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

static inline int AUTOMAP_UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

static inline int AUTOMAP_GetUnitClassIdR(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static inline int AUTOMAP_GetUnitAnimModeR(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return pUnit->dwAnimMode;
}

static int sub_00459BC0_GetAutomapUnitColor(D2UnitStrc* pUnit, unsigned char* pColor)
{
    switch (AUTOMAP_GetUnitType(pUnit))
    {
    case 0:
        if (pUnit && pUnit->dwAnimMode == 0x11)
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!pInventory || INVENTORY_GetOwnerId(pInventory) != pUnit->dwUnitId)
            {
                return 0;
            }

            *pColor = gnAutomapColors_007A51B0[2];
            return 1;
        }

        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            *pColor = gnAutomapColors_007A51B0[0];
            return 1;
        }

        {
            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                *pColor = gnAutomapColors_007A51B0[3];
                return 1;
            }
        }

        *pColor = gnAutomapColors_007A51B0[1];
        return 1;

    case 1:
    {
        if (pUnit)
        {
            if (pUnit->dwAnimMode == 0xC)
            {
                return 0;
            }

            if (AUTOMAP_UnitHasFlag(pUnit, 0x200000))
            {
                return 0;
            }
        }

        if (sub_00457490_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B)
                {
                    return 0;
                }
            }

            *pColor = gnAutomapColors_007A51B0[6];
            return 1;
        }

        int nClass;
        int nMode;
        int nType = AUTOMAP_GetUnitType(pUnit);
        nClass = AUTOMAP_GetUnitClassIdR(pUnit);
        nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UI\\automap.cpp", 0x92D);
        if (!nType && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && sub_004639D0_GetOwnerUnit(pUnit))
        {
            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                *pColor = gnAutomapColors_007A51B0[4];
                return 1;
            }

            *pColor = gnAutomapColors_007A51B0[1];
            return 1;
        }

        switch (sub_00478D90_GetPetRelation(!pUnit ? -1 : pUnit->dwUnitId))
        {
        case 0:
        case 3:
            return 0;

        case 1:
            if (sub_00451F30_TestUnitFlag(pUnit, 0x200))
            {
                *pColor = gnAutomapColors_007A51B0[4];
                return 1;
            }
            *pColor = gnAutomapColors_007A51B0[4];
            return 1;

        case 2:
            if (!gdwGlobal_007113E4)
            {
                return 0;
            }
            *pColor = gnAutomapColors_007A51B0[5];
            return 1;
        }

        return 1;
    }

    case 2:
        switch (AUTOMAP_GetUnitClassId(pUnit))
        {
        case 0x3B:
            *pColor = gnAutomapColors_007A51B0[8];
            return 1;

        case 0x3C:
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            if (nLevelId == LEVEL_HELL1 || nLevelId == LEVEL_HELL2 || nLevelId == LEVEL_HELL3 || nLevelId == LEVEL_ID_ACT5_BARRICADE_1
                || nLevelId == LEVEL_ARREATPLATEAU || nLevelId == LEVEL_TUNDRAWASTELANDS)
            {
                return 0;
            }
        }
            *pColor = gnAutomapColors_007A51B0[8];
            return 1;

        case 0x10B:
            *pColor = 0;
            return 1;
        }
        break;
    }

    return 0;
}

static void __stdcall sub_0045A760_DrawAutomapText(unsigned char nColor, const char* szText, int nX, int nY)
{
    if (!strlen(szText))
    {
        return;
    }

    if (nColor >= 0xD)
    {
        nColor = 0;
    }

    const int nOldFont = sub_00502EF0(6);
    Unicode wszText[0x17];
    memset(wszText, 0, sizeof(wszText));
    sub_00526320_ToUnicode(wszText, szText, 0x17);
    sub_00502320(wszText, nX - sub_00501820(wszText) / 2, nY - 10, nColor, 0);
    sub_00502EF0(nOldFont);
}

static void __stdcall sub_0045A7F0_DrawAutomapCross(unsigned char nColor, int nX, int nY)
{
    if (gdwGlobal_007A5150 == 1)
    {
        nX -= 1;
        nY += 5;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross_006D6638[i].nX * 2, nY + gaAutomapCross_006D6638[i].nY * 2,
            nX + gaAutomapCross_006D6638[i + 1].nX * 2, nY + gaAutomapCross_006D6638[i + 1].nY * 2, nColor, 0xFF);
    }
}

// 0x0045A860
static void sub_0045A860_DrawAutomapUnit(D2UnitStrc* pUnit)
{
    int nUnitType;
    if (!pUnit)
    {
        nUnitType = 6;
    }
    else
    {
        nUnitType = pUnit->dwUnitType;
    }
    unsigned char nColor = 0;
    if (nUnitType == 0 && sub_00464820_IsDeadOrDying(pUnit) && !STATES_CheckState(pUnit, STATE_PLAYERBODY))
    {
        return;
    }

    if (!sub_00459BC0_GetAutomapUnitColor(pUnit, &nColor))
    {
        return;
    }

    const int nClientX = UNITS_GetClientCoordX(pUnit);
    const int nClientY = UNITS_GetClientCoordY(pUnit);
    const int nX = nClientX / gnAutomapScale_00711254 - gnAutomapOffsetX_007A5198 + 8;
    const int nY = nClientY / gnAutomapScale_00711254 - gnAutomapOffsetY_007A519C - 8;
    if (nX < gnGlobal_007A51C8 || nX > gnGlobal_007A51D0 || nY < gnGlobal_007A51CC || nY > gnGlobal_007A51D4)
    {
        return;
    }

    switch (nUnitType)
    {
    case 0:
        if (gdwGlobal_007113E4 || nColor != gnAutomapColors_007A51B0[3])
        {
            sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        }

        if (gdwGlobal_007113E8 && gdwGlobal_007113E4 && pUnit != sub_00463DD0_GetPlayerUnit())
        {
            if (nColor == gnAutomapColors_007A51B0[3])
            {
                if (gdwGlobal_007113E4)
                {
                    sub_0045A760_DrawAutomapText(2, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
                }
            }
            else
            {
                sub_0045A760_DrawAutomapText(1, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
            }
        }
        break;

    case 1:
    {
        sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        if (!gdwGlobal_007113E8)
        {
            break;
        }

        if (sub_00457490_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            const int nOldFont = sub_00502EF0(6);
            const Unicode* wszName = sub_00464A60_GetUnitName(pUnit);
            sub_00502320(wszName, nX - sub_00501820(wszName) / 2, nY - 10, 4, 0);
            sub_00502EF0(nOldFont);
        }

        if (!gdwGlobal_007113E8 || !gdwGlobal_007113E4)
        {
            break;
        }

        {
            int nType = AUTOMAP_GetUnitType(pUnit);
            int nClass = AUTOMAP_GetUnitClassIdR(pUnit);
            int nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UI\\automap.cpp", 0xA15);
            if (nType || !STATES_CheckStateMaskOnUnit(pUnit, 0x25))
            {
                break;
            }

            D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pUnit);
            if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
            {
                break;
            }

            const unsigned short nPlayerRoster = sub_00465400_GetPlayerRosterField22(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)sub_00465400_GetPlayerRosterField22(pUnit))
            {
                break;
            }

            sub_0045A760_DrawAutomapText(1, UNITS_GetPlayerData(pOwner)->szName, nX, nY);
        }
        break;
    }

    case 2:
        if (gdwGlobal_007113E8 && pUnit && pUnit->dwClassId == 0x10B)
        {
            const int nOldFont = sub_00502EF0(6);
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(0xCF3);
            sub_00502320(wszText, nX - sub_00501820(wszText) / 2, nY - 10, nColor, 0);
            sub_00502EF0(nOldFont);
        }
        else
        {
            sub_0045A7F0_DrawAutomapCross(nColor, nX, nY);
        }
        break;
    }
}

static void sub_0045AB60_DrawAutomapPartyMember(D2StoredUnitRecordStrc* pEntry)
{
    int nX = 0;
    int nY = 0;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));
    const unsigned char nEntryAct = DRLG_GetActNoFromLevelId(sub_0047A1E0(pEntry));
    if (DRLG_GetActNoFromLevelId(nLevelId) != nEntryAct)
    {
        return;
    }

    sub_0047A1B0_GetEntryPosition(pEntry, &nX, &nY);
    DUNGEON_GameSubtileToClientCoords(&nX, &nY);
    nX = nX / gnAutomapScale_00711254 - gnAutomapOffsetX_007A5198 + 8;
    nY = nY / gnAutomapScale_00711254 - gnAutomapOffsetY_007A519C - 8;
    if (nX < gnGlobal_007A51C8 || nX > gnGlobal_007A51D0 || nY < gnGlobal_007A51CC || nY > gnGlobal_007A51D4)
    {
        return;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross_006D6638[i].nX * 2, nY + gaAutomapCross_006D6638[i].nY * 2,
            nX + gaAutomapCross_006D6638[i + 1].nX * 2, nY + gaAutomapCross_006D6638[i + 1].nY * 2, gnAutomapColors_007A51B0[3], 0xFF);
    }

    if (gdwGlobal_007113E8)
    {
        sub_0045A760_DrawAutomapText(2, sub_004795C0_GetEntryName(pEntry), nX, nY);
    }
}

void __cdecl sub_0045AC90_DrawAutomapUnits()
{
    D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc** ppRooms = 0;
    int nRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(UNITS_GetRoom(pPlayer), &ppRooms, (unsigned int*)&nRooms);
    const int nCount = nRooms;
    for (int i = 0; i < nCount; ++i)
    {
        for (D2UnitStrc* pUnit = ppRooms[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            sub_0045A860_DrawAutomapUnit(pUnit);
        }
    }

    const unsigned short nIndex = sub_00479BC0_GetEntryIndex(pEntry);
    if (nIndex == 0xFFFF || !gdwGlobal_007113E4)
    {
        return;
    }

    for (pEntry = sub_004795A0_GetNextEntry(pEntry); pEntry; pEntry = sub_004795A0_GetNextEntry(pEntry))
    {
        if (!sub_00463990(sub_0047A0C0_GetRecordUnitId(pEntry), 0) && nIndex == sub_00479BC0_GetEntryIndex(pEntry))
        {
            sub_0045AB60_DrawAutomapPartyMember(pEntry);
        }
    }
}

struct D2StoredUnitRecordStrc;

#include "gen/data/Source/D2Client/UI/automap_004591A0.inc"
