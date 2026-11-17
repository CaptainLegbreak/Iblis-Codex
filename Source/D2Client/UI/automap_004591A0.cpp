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
    int nLayerNo;
    int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
    D2AutomapLayerStrc* pNext;
};

struct D2LevelDefBin
{
    unsigned int dwQuestFlag;
    unsigned int dwQuestFlagEx;
    int dwLayer;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __cdecl sub_004584C0_ResetA();                                                                         // 0x004584C0
void __cdecl sub_00458680_ResetB();                                                                         // 0x00458680
void __cdecl sub_00458750_Rebuild();                                                                        // 0x00458750
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470
void __stdcall sub_00458F40_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer); // 0x00458F40
void __stdcall sub_00643310_MapToAutomapPos(int* pX, int* pY);                                              // 0x00643310
D2AutomapCellStrc* __cdecl sub_00457C30();                                                       // 0x00457C30
void __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot);              // 0x00457B00

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

static __declspec(noinline) D2AutomapLayerStrc* sub_00458D40_InitAutomapLayer(int nLayerNo);
static D2AutomapLayerStrc* sub_00458D40_InitAutomapLayer(int nLayerNo); // 0x00458D40

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
        sub_004584C0_ResetA();
        sub_00458680_ResetB();
        gpAutomapContext_007A5164 = pLayer;
        sub_00458750_Rebuild();
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
    case 0x28:
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

    case 0x67:
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

    case 0x6D:
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
