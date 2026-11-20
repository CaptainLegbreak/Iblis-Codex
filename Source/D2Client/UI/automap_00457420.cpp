#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2TileLibraryEntryStrc;
struct D2AutomapCellStrc;
struct D2AutomapLayerStrc;
struct D2DrlgLevelStrc;
struct D2AutomapRoomStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2AutomapSaveStrc;
struct D2AutomapRecordStrc;

struct D2AutomapCellStrc
{
    unsigned int fSaved;
    unsigned short nCellNo;
    unsigned short xPixel;
    unsigned short yPixel;
    unsigned short wWeight;
    D2AutomapCellStrc* pPrev;
    D2AutomapCellStrc* pNext;
};

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

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall sub_00457640(int bForce); // 0x00457640
void __cdecl sub_00470290(); // 0x00470290
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
int __cdecl sub_00492C10(); // 0x00492C10
void __stdcall sub_005FDE10_FreeCache(int bFree); // 0x005FDE10
void __stdcall sub_005FFE30_FreeTileCache(int bFree); // 0x005FFE30
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gdwGlobal_007A5150; // 0x007A5150
extern D2AutomapLayerStrc* gpAutomapNodes_007A5160; // 0x007A5160
extern D2AutomapLayerStrc* gpAutomapContext_007A5164; // 0x007A5164
extern int gnRevealSkip_007A51A4; // 0x007A51A4
extern int gnMiniMapY_007A51D8; // 0x007A51D8
extern int gdwGlobal_007A51E0; // 0x007A51E0

struct D2DrlgLevelStrc
{
    char unk0x00[0x1D0];
    int eLevelId;
};

struct D2AutomapRoomStrc
{
    char unk0x00[0x34];
    int nPosX;
    int nPosY;
    char unk0x3C[0x1C];
    D2DrlgLevelStrc* pLevel;
};

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    int unk0x10;
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    int nTileType;
    D2DrlgTileDataStrc* unk0x20;
    int unk0x24;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nIntensity;
    int unk0x2C;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __stdcall sub_00642750_GetAutomapLevelType(int nLevelId); // 0x00642750
int __stdcall sub_00604B60_GetTileType(D2TileLibraryEntryStrc* pTile); // 0x00604B60
int __stdcall sub_00604B90_GetTileStyle(D2TileLibraryEntryStrc* pTile); // 0x00604B90
int __stdcall sub_00604C50_GetTileSequence(D2TileLibraryEntryStrc* pTile); // 0x00604C50
int __fastcall DATATBLS_GetAutomapCellId(void* pAutomapLevelType, int nAutomapTileType, int nStyle, int nSequence); // 0x0061FFF0
D2AutomapCellStrc* __cdecl sub_00457C30(); // 0x00457C30
void __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot); // 0x00457B00

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    struct D2UnitStrc* pUnitFirst;
};

D2AutomapRoomStrc* __fastcall sub_0061AAE0_GetAutomapRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0
D2DrlgTileDataStrc* __stdcall sub_006196A0_GetWallTiles(D2ActiveRoomStrc* pRoom, unsigned int* pCount); // 0x006196A0
void __stdcall sub_00458DC0_RevealRoomObjects(D2ActiveRoomStrc* pRoom, D2AutomapCellStrc** ppRoot); // 0x00458DC0






int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gbRevealAutomap_007A51A0; // 0x007A51A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __cdecl sub_00457F40_OpenAutomapFile(); // 0x00457F40
int __fastcall sub_004069B0_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0
int __fastcall sub_004069D0_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0
unsigned long __fastcall sub_004069F0_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0
int __fastcall sub_004069A0_CloseFile(void* hFile); // 0x004069A0
void __fastcall sub_00458440_CountCells(D2AutomapCellStrc* pCells, unsigned int* pCount); // 0x00458440
void __fastcall sub_00458470_StoreCells(D2AutomapCellStrc* pCells); // 0x00458470
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern D2AutomapRecordStrc* gpAutomapRecord_007A0638; // 0x007A0638
extern void* gpAutomapSaveBuffer_007A5154; // 0x007A5154
extern int gnAutomapCelFrames_007A5178[4]; // 0x007A5178
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
void __stdcall sub_00458F40_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer); // 0x00458F40

void* gpAutomapSaveBuffer_007A5154; // 0x007A5154

int gdwAutoMapFade_007A51A8; // 0x007A51A8

int gdwAutoMapFadeSaved_007A51AC; // 0x007A51AC

unsigned char gnAutomapColors_007A51B0[1]; // 0x007A51B0

int gnGlobal_007A51C0; // 0x007A51C0

int gnGlobal_007A51C4; // 0x007A51C4

int gnGlobal_007A51C8; // 0x007A51C8

int gnGlobal_007A51CC; // 0x007A51CC

int gnGlobal_007A51D0; // 0x007A51D0

int gnGlobal_007A51D4; // 0x007A51D4

int gnMiniMapX_007A51DC; // 0x007A51DC

int gnGlobal_007A51EC; // 0x007A51EC

int gnGlobal_007A51F0; // 0x007A51F0

// 0x00457420
void __fastcall sub_00457420_FreeCaches(int bFree)
{
    sub_005FDE10_FreeCache(bFree);
    sub_005FFE30_FreeTileCache(bFree);
    sub_00470290();
}

// 0x00457440
void __fastcall sub_00457440_Nop(int nUnused)
{
}

// 0x00457520
void __cdecl sub_00457520_UpdateAutomapLayout()
{
    if (gnGlobal_007A51F0 != sub_00492C10() && gdwGlobal_007A5150 == 1)
    {
        gnGlobal_007A51F0 = sub_00492C10();
        sub_00457640(1);
        return;
    }
    if (gnGlobal_007A51EC != gdwGlobal_007A51E0 && gdwGlobal_007A5150 == 1)
    {
        gnGlobal_007A51EC = gdwGlobal_007A51E0;
        sub_00457640(1);
        return;
    }
    if (gdwGlobal_007A51E0)
    {
        gnMiniMapX_007A51DC = 0;
        gnMiniMapY_007A51D8 = sub_00492C10() ? 0x60 : 0;
    }
    else
    {
        gnMiniMapX_007A51DC = gnGlobal_0071146C * 2 / 3;
        gnMiniMapY_007A51D8 = 0x4E;
    }
    gnGlobal_007A51C0 = gnMiniMapX_007A51DC;
    gnGlobal_007A51C4 = gnMiniMapY_007A51D8;
    switch (gdwGlobal_007A5150)
    {
    case 1:
        gnGlobal_007A51C8 = gnMiniMapX_007A51DC - 8;
        gnGlobal_007A51D0 = gnGlobal_0071146C / 3 + gnMiniMapX_007A51DC;
        gnGlobal_007A51CC = gnMiniMapY_007A51D8;
        gnGlobal_007A51D4 = gnGlobal_00711470 / 3 + gnMiniMapY_007A51D8;
        break;
    default:
        gnGlobal_007A51D0 = gnGlobal_0071146C;
        gnGlobal_007A51C8 = -16;
        gnGlobal_007A51CC = -16;
        gnGlobal_007A51D4 = gnGlobal_00711470;
        break;
    }
}

// 0x004576C0
int __cdecl sub_004576C0()
{
    if (gdwGlobal_007A5150 == 1 && gdwAutoMapFade_007A51A8 == 1)
    {
        gdwAutoMapFade_007A51A8 = gdwAutoMapFadeSaved_007A51AC ? 0 : 2;
    }
    return gdwAutoMapFade_007A51A8;
}

// 0x004576F0
int __fastcall sub_004576F0(int nFade)
{
    if (gdwGlobal_007A5150 == 1 && nFade == 1)
    {
        nFade = gdwAutoMapFadeSaved_007A51AC ? 0 : 2;
        gdwAutoMapFade_007A51A8 = 1;
    }
    SRegSaveValue("Diablo II", "AutoMapFade", 0, nFade);
    gdwAutoMapFadeSaved_007A51AC = nFade;
    gdwAutoMapFade_007A51A8 = nFade;
    return nFade;
}

// 0x00458440
void __fastcall sub_00458440_CountCells(D2AutomapCellStrc* pCells, unsigned int* pCount)
{
    if (!pCells)
    {
        return;
    }
    sub_00458440_CountCells(pCells->pPrev, pCount);
    if (!pCells->fSaved)
    {
        *pCount += 6;
    }
    sub_00458440_CountCells(pCells->pNext, pCount);
}

// 0x00458470
void __fastcall sub_00458470_StoreCells(D2AutomapCellStrc* pCells)
{
    if (!pCells)
    {
        return;
    }
    sub_00458470_StoreCells(pCells->pPrev);
    if (!pCells->fSaved)
    {
        unsigned short* pBuffer = (unsigned short*)gpAutomapSaveBuffer_007A5154;
        *pBuffer = pCells->nCellNo;
        ++pBuffer;
        *pBuffer = pCells->xPixel;
        ++pBuffer;
        *pBuffer = pCells->yPixel;
        ++pBuffer;
        gpAutomapSaveBuffer_007A5154 = pBuffer;
    }
    sub_00458470_StoreCells(pCells->pNext);
}

// 0x00459140
void __cdecl sub_00459140_Refresh()
{
    gnRevealSkip_007A51A4 = 2;
}

// 0x0045A5C0
void __cdecl sub_0045A5C0_FreeAutomap()
{
    sub_004584C0_ResetA();
    sub_00458680_ResetB();
    for (int i = 0; i < 4; ++i)
    {
        if (gpAutomapCels_007A5168[i])
        {
            sub_00478A00(gpAutomapCels_007A5168[i]);
        }
        gpAutomapCels_007A5168[i] = 0;
    }
    D2AutomapLayerStrc* pLayer = gpAutomapNodes_007A5160;
    while (pLayer)
    {
        D2AutomapLayerStrc* pFree = pLayer;
        pLayer = pLayer->pNext;
        FOG_Free(pFree, ".\\UI\\automap.cpp", 0xC06, 0);
    }
    gpAutomapNodes_007A5160 = 0;
    gpAutomapContext_007A5164 = 0;
}

// 0x0045A620
void __cdecl sub_0045A620_InitAutomapColors()
{
    gnAutomapColors_007A51B0[0] = D2Win_10034_MixRGB(0, 0, 0xFF);
    gnAutomapColors_007A51B0[1] = D2Win_10034_MixRGB(0xFF, 0, 0);
    gnAutomapColors_007A51B0[2] = D2Win_10034_MixRGB(0xFF, 0, 0xFF);
    gnAutomapColors_007A51B0[3] = D2Win_10034_MixRGB(0, 0xFF, 0);
    gnAutomapColors_007A51B0[4] = D2Win_10034_MixRGB(0x44, 0x70, 0x74);
    gnAutomapColors_007A51B0[5] = D2Win_10034_MixRGB(0x48, 0xA0, 0x34);
    gnAutomapColors_007A51B0[6] = D2Win_10034_MixRGB(0xF4, 0xF4, 0xF4);
    gnAutomapColors_007A51B0[7] = D2Win_10034_MixRGB(0x80, 0x80, 0x80);
    gnAutomapColors_007A51B0[8] = D2Win_10034_MixRGB(0xF4, 0xF4, 0);
    gnAutomapColors_007A51B0[9] = D2Win_10034_MixRGB(0, 0, 0xFF);
    gnAutomapColors_007A51B0[10] = D2Win_10034_MixRGB(0, 0xFF, 0);
}

int gbRevealAutomap_007A51A0; // 0x007A51A0

// 0x00457CF0
static void __stdcall sub_00457CF0_RevealAutomapTile(D2DrlgTileDataStrc* pTileData, D2AutomapRoomStrc* pRoom, D2AutomapCellStrc** ppRoot)
{
    if (pTileData->dwFlags & 0x40000)
    {
        return;
    }
    pTileData->dwFlags |= 0x40000;
    void* pLevelType = sub_00642750_GetAutomapLevelType(pRoom->pLevel->eLevelId);
    const int nType = sub_00604B60_GetTileType(pTileData->pTile);
    const int nStyle = sub_00604B90_GetTileStyle(pTileData->pTile);
    const int nSequence = sub_00604C50_GetTileSequence(pTileData->pTile);
    const int nCell = DATATBLS_GetAutomapCellId(pLevelType, nType, nStyle, nSequence);
    if (nCell == -1)
    {
        return;
    }
    D2AutomapCellStrc* pCell = sub_00457C30();
    int nX = pRoom->nPosX + pTileData->nPosX;
    int nY = pRoom->nPosY + pTileData->nPosY;
    sub_00643310_MapToAutomapPos(&nX, &nY);
    nX /= 10;
    nY /= 10;
    D2_ASSERT(nX >= -0x8000 && nX <= 0x7FFF, 913);
    D2_ASSERT(nY >= -0x8000 && nY <= 0x7FFF, 914);
    D2_ASSERT(nCell >= -0x8000 && nCell <= 0x7FFF, 915);
    if (pTileData->nTileType >= 0x10)
    {
        nY += 0x18;
    }
    pCell->nCellNo = nCell;
    pCell->xPixel = nX;
    pCell->yPixel = nY;
    sub_00457B00(pCell, ppRoot);
}

// 0x00458F40
void __stdcall sub_00458F40_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer)
{
    unsigned int nCount = 0;
    D2AutomapRoomStrc* pRoom = sub_0061AAE0_GetAutomapRoom(pActiveRoom);
    D2DrlgTileDataStrc* pTiles = sub_00619660_GetFloorTiles(pActiveRoom, &nCount);
    for (unsigned int i = 0; i < nCount; i++)
    {
        D2DrlgTileDataStrc* pTileData = &pTiles[i];
        if (!(pTileData->dwFlags & 8) && ((pTileData->dwFlags & 0x20000) || gbRevealAutomap_007A51A0 || bRevealAll))
        {
            sub_00457CF0_RevealAutomapTile(pTileData, pRoom, &pLayer->pFloors);
        }
    }
    pTiles = sub_006196A0_GetWallTiles(pActiveRoom, &nCount);
    for (unsigned int i = 0; i < nCount; i++)
    {
        D2DrlgTileDataStrc* pTileData = &pTiles[i];
        if (!(pTileData->dwFlags & 8) && ((pTileData->dwFlags & 0x20000) || gbRevealAutomap_007A51A0 || bRevealAll))
        {
            sub_00457CF0_RevealAutomapTile(pTileData, pRoom, &pLayer->pWalls);
        }
    }
    sub_00458DC0_RevealRoomObjects(pActiveRoom, &pLayer->pObjects);
}

// 0x00457E80
static void __stdcall sub_00457E80_AddUnitAutomapCell(int nCellNo, D2AutomapCellStrc** ppRoot, D2UnitStrc* pUnit)
{
    D2AutomapCellStrc* pCell = sub_00457C30();
    const int nX = UNITS_GetClientCoordX(pUnit) / 10 + 1;
    const int nY = UNITS_GetClientCoordY(pUnit) / 10 - 3;
    D2_ASSERT(nX >= -0x8000 && nX <= 0x7FFF, 0x3C5);
    D2_ASSERT(nY >= -0x8000 && nY <= 0x7FFF, 0x3C6);
    D2_ASSERT(nCellNo >= -0x8000 && nCellNo <= 0x7FFF, 0x3C7);
    pCell->nCellNo = nCellNo;
    pCell->xPixel = nX;
    pCell->yPixel = nY;
    sub_00457B00(pCell, ppRoot);
}

void __stdcall sub_00458DC0_RevealRoomObjects(D2ActiveRoomStrc* pRoom, D2AutomapCellStrc** ppRoot)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        const int nFlag = pUnit ? (pUnit->dwFlags >> 28) & 1 : 0;
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (!gbRevealAutomap_007A51A0)
        {
            if (!nFlag)
                continue;

            if (pUnit ? (pUnit->dwFlags >> 29) & 1 : 0)
                continue;
        }

        if (pUnit)
            pUnit->dwFlags |= 0x20000000;

        switch (nUnitType)
        {
        case UNIT_MONSTER:
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
                {
                    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nClassId].wMonStatsEx;
                    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
                    {
                        D2MonStats2Txt* pMonStats2Txt = &sgptDataTables->pMonStats2Txt[nMonStatsEx];
                        if (pMonStats2Txt && pMonStats2Txt->dwAutomapCel)
                            sub_00457E80_AddUnitAutomapCell(pMonStats2Txt->dwAutomapCel, ppRoot, pUnit);
                    }
                }
            }
            break;

        case UNIT_OBJECT:
        {
            const int nClassId = pUnit ? pUnit->dwClassId : -1;
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nClassId);
            if (!pObjectsTxt->dwAutomap)
                break;

            switch (nClassId)
            {
            case 0x10B:
            {
                const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (nAct == 2 || nAct == 3)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;
            }
            case 0x16E:
                if (pUnit && pUnit->dwAnimMode == 2)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;

            case 0x192:
                if (DUNGEON_GetLevelIdFromRoom(pRoom) == 0x4A)
                    sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;

            default:
                sub_00457E80_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;
            }
            break;
        }
        }
    }
}

// 0x00458200
static void sub_00458200_WriteAutomapLayer(D2AutomapSaveStrc* pSave)
{
    void* hFile = sub_00457F40_OpenAutomapFile();
    if (hFile == (void*)-1)
    {
        return;
    }
    unsigned int anOffsets[100] = { 0 };
    unsigned long nCount = 0;
    sub_004069B0_ReadFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    if (nCount != sizeof(anOffsets))
    {
        memset(anOffsets, 0, sizeof(anOffsets));
        sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
        sub_004069D0_WriteFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    }
    unsigned int nOffset = anOffsets[pSave->nLayerNo];
    unsigned int nEnd = GetFileSize(hFile, 0);
    if (nOffset)
    {
        unsigned int nPrev;
        do
        {
            sub_004069F0_SetFilePointer(hFile, nOffset, 0, 0);
            nPrev = nOffset;
            sub_004069B0_ReadFile(hFile, &nOffset, 4, &nCount, 0);
        }
        while (nOffset);
        sub_004069F0_SetFilePointer(hFile, nPrev, 0, 0);
        sub_004069D0_WriteFile(hFile, &nEnd, 4, &nCount, 0);
    }
    else
    {
        anOffsets[pSave->nLayerNo] = nEnd;
    }
    sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
    sub_004069D0_WriteFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    sub_004069F0_SetFilePointer(hFile, nEnd, 0, 0);
    nEnd = 0;
    sub_004069D0_WriteFile(hFile, &nEnd, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nLayerNo, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->fSaved, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nUnk0x08, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->dwFloorSize, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->dwWallsSize, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->nObjects, 4, &nCount, 0);
    sub_004069D0_WriteFile(hFile, &pSave->dwExtraSize, 4, &nCount, 0);
    if (pSave->dwFloorSize)
        sub_004069D0_WriteFile(hFile, pSave->pFloors, pSave->dwFloorSize, &nCount, 0);
    if (pSave->dwWallsSize)
        sub_004069D0_WriteFile(hFile, pSave->pWalls, pSave->dwWallsSize, &nCount, 0);
    if (pSave->nObjects)
        sub_004069D0_WriteFile(hFile, pSave->pObjects, pSave->nObjects, &nCount, 0);
    if (pSave->dwExtraSize)
        sub_004069D0_WriteFile(hFile, pSave->pExtras, pSave->dwExtraSize, &nCount, 0);
    sub_004069A0_CloseFile(hFile);
}

void __cdecl sub_004584C0()
{
    D2AutomapLayerStrc* pLayer = gpAutomapContext_007A5164;
    if (!pLayer)
    {
        return;
    }
    D2AutomapSaveStrc tSave = { pLayer->nLayerNo };
    tSave.fSaved = pLayer->fSaved;
    tSave.nUnk0x08 = gpAutomapRecord_007A0638->nValue;
    sub_00458440_CountCells(pLayer->pFloors, &tSave.dwFloorSize);
    sub_00458440_CountCells(pLayer->pWalls, &tSave.dwWallsSize);
    sub_00458440_CountCells(pLayer->pObjects, &tSave.nObjects);
    sub_00458440_CountCells(pLayer->pExtras, &tSave.dwExtraSize);
    if (!tSave.dwFloorSize && !tSave.dwWallsSize && !tSave.nObjects && !tSave.dwExtraSize)
    {
        return;
    }
    if (tSave.dwFloorSize)
    {
        tSave.pFloors = FOG_Alloc(tSave.dwFloorSize, ".\\UI\\automap.cpp", 0x4EA, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pFloors;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pFloors);
    }
    if (tSave.dwWallsSize)
    {
        tSave.pWalls = FOG_Alloc(tSave.dwWallsSize, ".\\UI\\automap.cpp", 0x4F1, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pWalls;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pWalls);
    }
    if (tSave.nObjects)
    {
        tSave.pObjects = FOG_Alloc(tSave.nObjects, ".\\UI\\automap.cpp", 0x4F8, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pObjects;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pObjects);
    }
    if (tSave.dwExtraSize)
    {
        tSave.pExtras = FOG_Alloc(tSave.dwExtraSize, ".\\UI\\automap.cpp", 0x4FF, 0);
        gpAutomapSaveBuffer_007A5154 = tSave.pExtras;
        sub_00458470_StoreCells(gpAutomapContext_007A5164->pExtras);
    }
    sub_00458200_WriteAutomapLayer(&tSave);
    if (tSave.pFloors)
        FOG_Free(tSave.pFloors, ".\\UI\\automap.cpp", 0x509, 0);
    if (tSave.pWalls)
        FOG_Free(tSave.pWalls, ".\\UI\\automap.cpp", 0x50A, 0);
    if (tSave.pObjects)
        FOG_Free(tSave.pObjects, ".\\UI\\automap.cpp", 0x50B, 0);
    if (tSave.pExtras)
        FOG_Free(tSave.pExtras, ".\\UI\\automap.cpp", 0x50C, 0);
}

D2AutomapLayerStrc* gpAutomapContext_007A5164; // 0x007A5164

void __stdcall sub_00457E40_AddAutomapCell(unsigned short nCellNo, unsigned short xPixel, unsigned short yPixel, D2AutomapCellStrc** ppRoot, unsigned int fSaved)
{
    D2AutomapCellStrc* pCell = sub_00457C30();
    pCell->fSaved = fSaved;
    pCell->nCellNo = nCellNo;
    pCell->xPixel = xPixel;
    pCell->yPixel = yPixel;
    sub_00457B00(pCell, ppRoot);
}

// 0x004586E0
static void __stdcall sub_004586E0_UnlinkAutomapLayer(void* hFile, unsigned int* pOffsets, unsigned int nPrev)
{
    unsigned long nCount = 0;
    if (nPrev)
    {
        sub_004069F0_SetFilePointer(hFile, nPrev, 0, 0);
        nPrev = 0;
        sub_004069D0_WriteFile(hFile, &nPrev, 4, &nCount, 0);
    }
    else
    {
        pOffsets[gpAutomapContext_007A5164->nLayerNo] = 0;
        sub_004069F0_SetFilePointer(hFile, 0, 0, 0);
        sub_004069D0_WriteFile(hFile, pOffsets, 0x190, &nCount, 0);
    }
}

// 0x00458750
void __cdecl sub_00458750()
{
    if (!gpAutomapContext_007A5164)
    {
        return;
    }
    void* hFile = sub_00457F40_OpenAutomapFile();
    if (hFile == (void*)-1)
    {
        return;
    }
    unsigned int anOffsets[100] = { 0 };
    unsigned long nCount = 0;
    sub_004069B0_ReadFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    if (nCount == sizeof(anOffsets))
    {
        unsigned int nRecord = 0;
        unsigned int nLink = anOffsets[gpAutomapContext_007A5164->nLayerNo];
        unsigned short* pData;
        unsigned int nWords;
        unsigned int i;
        while (nLink)
        {
            D2AutomapSaveStrc tSave = { 0 };
            sub_004069F0_SetFilePointer(hFile, nLink, 0, 0);
            sub_004069B0_ReadFile(hFile, &nLink, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nLayerNo, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.fSaved, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nUnk0x08, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.dwFloorSize, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.dwWallsSize, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.nObjects, 4, &nCount, 0);
            sub_004069B0_ReadFile(hFile, &tSave.dwExtraSize, 4, &nCount, 0);
            if (tSave.nLayerNo != gpAutomapContext_007A5164->nLayerNo)
            {
                sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                break;
            }
            if (tSave.dwFloorSize)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.dwFloorSize, ".\\UI\\automap.cpp", 0x575, 0);
                nWords = tSave.dwFloorSize / 2;
                sub_004069B0_ReadFile(hFile, pData, tSave.dwFloorSize, &nCount, 0);
                D2_ASSERT(nCount == tSave.dwFloorSize, 0x57A);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gnAutomapCelFrames_007A5178[0])
                    {
                        sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pFloors, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x586, 0);
            }
            if (tSave.dwWallsSize)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.dwWallsSize, ".\\UI\\automap.cpp", 0x58A, 0);
                nWords = tSave.dwWallsSize / 2;
                sub_004069B0_ReadFile(hFile, pData, tSave.dwWallsSize, &nCount, 0);
                D2_ASSERT(nCount == tSave.dwWallsSize, 0x58F);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gnAutomapCelFrames_007A5178[0])
                    {
                        sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pWalls, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x59B, 0);
            }
            if (tSave.nObjects)
            {
                if (tSave.nUnk0x08 == gpAutomapRecord_007A0638->nValue)
                {
                    pData = (unsigned short*)FOG_Alloc(tSave.nObjects, ".\\UI\\automap.cpp", 0x5A2, 0);
                    nWords = tSave.nObjects / 2;
                    sub_004069B0_ReadFile(hFile, pData, tSave.nObjects, &nCount, 0);
                    D2_ASSERT(nCount == tSave.nObjects, 0x5A7);
                    for (i = 0; i < nWords; i += 3)
                    {
                        if ((short)pData[i] >= gnAutomapCelFrames_007A5178[0])
                        {
                            sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                            break;
                        }
                        sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pObjects, 1);
                    }
                    FOG_Free(pData, ".\\UI\\automap.cpp", 0x5B3, 0);
                }
                else
                {
                    sub_004069F0_SetFilePointer(hFile, tSave.nObjects, 0, 1);
                }
            }
            if (tSave.dwExtraSize)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.dwExtraSize, ".\\UI\\automap.cpp", 0x5BD, 0);
                nWords = tSave.dwExtraSize / 2;
                sub_004069B0_ReadFile(hFile, pData, tSave.dwExtraSize, &nCount, 0);
                D2_ASSERT(nCount == tSave.dwExtraSize, 0x5C2);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gnAutomapCelFrames_007A5178[tSave.fSaved])
                    {
                        sub_004586E0_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    sub_00457E40_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext_007A5164->pExtras, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x5CE, 0);
            }
            nRecord = nLink;
        }
    }
    sub_004069A0_CloseFile(hFile);
}

D2AutomapLayerStrc* gpAutomapNodes_007A5160; // 0x007A5160

int gnRevealSkip_007A51A4; // 0x007A51A4

int gnPlayerX_007A5200; // 0x007A5200

int gnPlayerY_007A51F8; // 0x007A51F8

int gnLastX_007A51FC; // 0x007A51FC

int gnLastY_007A51F4; // 0x007A51F4

// 0x00458D40
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
        D2AutomapLayerStrc* pNew = (D2AutomapLayerStrc*)FOG_Alloc(sizeof(D2AutomapLayerStrc), ".\\UI\\automap.cpp", 0x5ED, 0);
        memset(&pNew->fSaved, 0, 5 * sizeof(int));
        D2AutomapLayerStrc* pHead = gpAutomapNodes_007A5160;
        pNew->nLayerNo = nLayerNo;
        pNew->pNext = pHead;
        gpAutomapNodes_007A5160 = pNew;
        pLayer = pNew;
    }

    if (pLayer != gpAutomapContext_007A5164)
    {
        sub_004584C0_ResetA();
        sub_00458680_ResetB();
        gpAutomapContext_007A5164 = pLayer;
        sub_00458750_Rebuild();
    }

    return pLayer;
}

// 0x00459020
void __cdecl sub_00459020_UpdateAutomapReveal()
{
    if (gnRevealSkip_007A51A4)
    {
        gnRevealSkip_007A51A4 -= 1;
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2_ASSERT(pPlayer, 0x696);
    gnPlayerX_007A5200 = UNITS_GetClientCoordX(pPlayer);
    gnPlayerY_007A51F8 = UNITS_GetClientCoordY(pPlayer);

    int nDiffX = gnLastX_007A51FC - gnPlayerX_007A5200;
    if (nDiffX < 0)
        nDiffX = -nDiffX;

    int nDiffY = gnLastY_007A51F4 - gnPlayerY_007A51F8;
    if (nDiffY < 0)
        nDiffY = -nDiffY;

    const int nDistance = (nDiffX > nDiffY ? nDiffY + 2 * nDiffX : nDiffX + 2 * nDiffY) / 2;
    if (nDistance < 0x50)
        return;

    gnLastX_007A51FC = gnPlayerX_007A5200;
    gnLastY_007A51F4 = gnPlayerY_007A51F8;

    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (!pRoom)
        return;

    D2ActiveRoomStrc** ppRoomList = 0;
    unsigned int nNumRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    const int nLayerNo = DATATBLS_GetLevelDefRecord(DUNGEON_GetLevelIdFromRoom(pRoom))->dwLayer;
    D2AutomapLayerStrc* pLayer = sub_00458D40_InitAutomapLayer(nLayerNo);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if (nLayerNo == DATATBLS_GetLevelDefRecord(DUNGEON_GetLevelIdFromRoom(ppRoomList[i]))->dwLayer)
            sub_00458F40_RevealRoomTiles(ppRoomList[i], 0, pLayer);
    }
}

void __stdcall sub_00459150_RevealRoomCallback(D2ActiveRoomStrc* pRoom)
{
    const int nPrevLayerNo = gpAutomapContext_007A5164 ? gpAutomapContext_007A5164->nLayerNo : -1;
    D2ActiveRoomStrc* pActiveRoom = pRoom;
    D2AutomapLayerStrc* pLayer = sub_00458D40_InitAutomapLayer(DATATBLS_GetLevelDefRecord(DUNGEON_GetLevelIdFromRoom(pActiveRoom))->dwLayer);
    sub_00458F40_RevealRoomTiles(pActiveRoom, 1, pLayer);
    if (nPrevLayerNo != -1)
        sub_00458D40_InitAutomapLayer(nPrevLayerNo);
}

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
    int nCel;
    switch (nLevelId)
    {
    case 0x28:
        pLayer->fSaved = 1;
        pSkip = gaTownSkipCels_006D6608;
        nColumns = 5;
        nRows = 4;
        nOffsetX = 0x35;
        nOffsetY = -0x51;
        nStepX = 0xA0;
        nStepY = 0x64;
        nCel = nPickedFile != 1 ? 0x14 : 0;
        break;

    case 0x67:
        pLayer->fSaved = 2;
        pSkip = 0;
        nColumns = 2;
        nRows = 2;
        nOffsetX = -3;
        nOffsetY = -0x32;
        nStepX = 0x88;
        nStepY = 0x5A;
        nCel = 0;
        break;

    case 0x6D:
        pLayer->fSaved = 3;
        pSkip = 0;
        nColumns = 3;
        nRows = 2;
        nOffsetX = -0x14;
        nOffsetY = -0x9B;
        nStepX = 0xB4;
        nStepY = 0xAA;
        nCel = 0;
        break;

    default:
        D2_ASSERT(0, 0x751);
    }

    sub_00643310_MapToAutomapPos(&nX, &nY);
    nX /= 10;
    nY /= 10;
    const int nHalfWidth = nStepX * nColumns / 2 + nOffsetX;
    int nPosY = nY - nStepY * nRows / 2 - nOffsetY;
    for (int nRow = 0; nRow < nRows; ++nRow)
    {
        int nPosX = nX - nHalfWidth;
        for (int nColumn = 0; nColumn < nColumns; ++nColumn)
        {
            if (pSkip)
            {
                for (const int* p = pSkip; *p != -1; ++p)
                {
                    if (*p == nCel)
                        goto next;
                }
            }

            D2_ASSERT(nPosX >= -0x8000 && nPosX <= 0x7FFF, 0x777);
            D2_ASSERT(nPosY >= -0x8000 && nPosY <= 0x7FFF, 0x778);
            D2_ASSERT(nCel >= -0x8000 && nCel <= 0x7FFF, 0x779);
            {
                D2AutomapCellStrc* pCell = sub_00457C30();
                pCell->fSaved = 0;
                pCell->nCellNo = nCel;
                pCell->xPixel = nPosX;
                pCell->yPixel = nPosY;
                sub_00457B00(pCell, &pLayer->pExtras);
            }
next:
            ++nCel;
            nPosX += nStepX;
        }
        nPosY += nStepY;
    }

    if (nPrevLayerNo != -1)
        sub_00458D40_InitAutomapLayer(nPrevLayerNo);
}

#include "gen/data/Source/D2Client/UI/automap_00457420.inc"
