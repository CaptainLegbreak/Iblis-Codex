#include "D2Client.h"
#include "D2ClientUi.h"
struct D2ActiveRoomStrc;

struct D2AutomapLayerStrc
{
    int nLayerNo;
    int fSaved;
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
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
void __stdcall sub_00458F40_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer); // 0x00458F40
D2AutomapCellStrc* __cdecl sub_00457C30();                                                       // 0x00457C30
int __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot); // 0x00457B00

extern D2AutomapLayerStrc* gpAutomapNodes_007A5160;                                                         // 0x007A5160
extern D2AutomapLayerStrc* gpAutomapContext_007A5164;                                                       // 0x007A5164
extern int gdwGlobal_007A5150;                                                                              // 0x007A5150
extern int gnRevealSkip_007A51A4;                                                                           // 0x007A51A4
extern int gnPlayerX_007A5200;                                                                              // 0x007A5200
extern int gnPlayerY_007A51F8;                                                                              // 0x007A51F8
extern int gnLastX_007A51FC;                                                                                // 0x007A51FC
extern int gnLastY_007A51F4;                                                                                // 0x007A51F4

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

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
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

// 0x00459150
void __stdcall sub_00459150_RevealRoomCallback(D2ActiveRoomStrc* pRoom)
{
    const int nPrevLayerNo = gpAutomapContext_007A5164 ? gpAutomapContext_007A5164->nLayerNo : -1;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    D2AutomapLayerStrc* pLayer = sub_00458D40_InitAutomapLayer(DATATBLS_GetLevelDefRecord(nLevelId)->dwLayer);
    sub_00458F40_RevealRoomTiles(pRoom, 1, pLayer);
    if (nPrevLayerNo != -1)
        sub_00458D40_InitAutomapLayer(nPrevLayerNo);
}

// build: context sub_004591A0_AddTownCelsCallback
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
