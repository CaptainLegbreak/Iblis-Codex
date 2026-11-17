#include "D2Client.h"

typedef unsigned int size_t;

enum D2C_F06UiConstants
{
    UNIT_PLAYER = 0,
    UNIT_MONSTER = 1,
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
    PLAYER_MODE_WALK = 2,
    PLAYER_MODE_RUN = 3,
    PLAYER_MODE_6 = 6,
    BODYLOC_RARM = 4,
    BODYLOC_LARM = 5,
};

struct Unicode
{
    unsigned short wChar;
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    int lParam;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    SMSGHANDLER pfnHandler;
};
struct D2GfxLightStrc;

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
};

struct D2SkillsTxt
{
    short nSkillId;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
};

struct D2SkillListStrc
{
    void* pMemPool;
    D2SkillStrc* pFirstSkill;
    D2SkillStrc* pLeftSkill;
    D2SkillStrc* pRightSkill;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    D2InventoryStrc* pInventory;
    D2GfxLightStrc* pLight;
    char unk0x68[0x40];
    D2SkillListStrc* pSkills;
    char unk0xAC[0x18];
    unsigned int dwFlags;
    char unk0xC8[0x20];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int nOffsetX;
    int nOffsetY;
};

struct tagRECT
{
    int left;
    int top;
    int right;
    int bottom;
};

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

struct D2PacketBufferStrc
{
    int nMax;
    int nCount;
    int unk0x08;
    unsigned char* pData;
};

typedef void (__fastcall* D2PacketHandlerFn)(void* pArg, unsigned char* pPacket);

struct D2PacketTableEntryStrc
{
    void* pfnHandler;
    int nSize;
    D2PacketHandlerFn f_8;
};

struct D2MonStats2Txt
{
    char unk0x000[0x11E];
    unsigned char nLightRadius;
};

struct D2UnitTargetStrc
{
    int nParam1;
    int nParam2;
    int unk0x08[5];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void __fastcall sub_00451D10_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler);  // 0x00451D10
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
int __fastcall sub_004B3230_GetTickPair(int* pLow);                                                         // 0x004B3230
int __fastcall sub_004AE360_IsMonsterFlag8(D2UnitStrc* pUnit);                                              // 0x004AE360
int __fastcall sub_004AE380_IsMonsterFlag10(D2UnitStrc* pUnit);                                             // 0x004AE380
void __fastcall sub_004ADEA0_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, int nArg);    // 0x004ADEA0
D2AutomapCellStrc* __cdecl sub_00457C30();                                                       // 0x00457C30
void __fastcall sub_00457B00(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot);              // 0x00457B00
void __stdcall sub_00643510(int* pX, int* pY);                                                   // 0x00643510
void __stdcall sub_00643260(int* pX, int* pY);                                                   // 0x00643260
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x004F6380
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom();                                                  // 0x004646A0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __fastcall sub_00476AC0_GetViewShift(int* pX, int* pY);                                                 // 0x00476AC0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);                          // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);                         // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);                  // 0x00627910
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                  // 0x00643BC0
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);                 // 0x00643C50
D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(void* pArg);                                    // 0x00464770
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
void __fastcall sub_004742D0(D2GfxLightStrc* pLight, int nRadius);                           // 0x004742D0
void __fastcall sub_00474390_SetRecordBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem);                                           // 0x00627D40
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pItem);                                              // 0x00628660
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem);                                     // 0x006289C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __stdcall sub_00650C60_UpdatePath(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00650C60
void __fastcall sub_00461250_QueueMove(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00461250

extern Unicode gwszHoverName_007A2F38[];                                                                    // 0x007A2F38
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
int gnGlobal_007A5204;                                                                                      // 0x007A5204
int gdwGlobal_007A5208;                                                                                     // 0x007A5208
int gdwGlobal_007A520C;                                                                                     // 0x007A520C
extern int gdwGlobal_007A5210;                                                                              // 0x007A5210
extern int gnGlobal_007A5214;                                                                               // 0x007A5214
extern int gnGlobal_007A5230;                                                                               // 0x007A5230
extern D2PacketTableEntryStrc gtPacketTable_007114D0[];                                                     // 0x007114D0
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
int gnGlobal_007A5248;                                                                                      // 0x007A5248
int gnGlobal_007A524C;                                                                                      // 0x007A524C
int gnGlobal_007A5250;                                                                                      // 0x007A5250
extern int gnGlobal_007A5258;                                                                               // 0x007A5258
extern int gnGlobal_007A525C;                                                                               // 0x007A525C

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00451E10
void __fastcall sub_00451E10_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount)
{
    D2_ASSERT(hWnd, 0x166);
    for (unsigned int i = 0; i < nCount; ++i)
    {
        sub_00451D10_UnregisterMsgHandler(hWnd, pTable[i].nType, pTable[i].nId, pTable[i].pfnHandler);
    }
}

// 0x00452580
int __fastcall sub_00452580_GetHoverMonsterName(D2UnitStrc* pUnit, int nArg)
{
    int nTick;
    if (sub_0045AE90() == 3)
    {
        return 0;
    }
    if (sub_004B3230_GetTickPair(&nTick))
    {
        return 0;
    }
    gwszHoverName_007A2F38[0].wChar = 0;
    if (!sub_004AE360_IsMonsterFlag8(pUnit) && !sub_004AE380_IsMonsterFlag10(pUnit))
    {
        return 0;
    }
    sub_004ADEA0_GetMonsterName(pUnit, gwszHoverName_007A2F38, 0x100, nArg);
    return 1;
}

// 0x00457E40
void __stdcall sub_00457E40_AddAutomapCell(unsigned short nCellNo, unsigned short xPixel, unsigned short yPixel, D2AutomapCellStrc** ppRoot, unsigned int fSaved)
{
    D2AutomapCellStrc* pCell = sub_00457C30();
    pCell->fSaved = fSaved;
    pCell->nCellNo = nCellNo;
    pCell->xPixel = xPixel;
    pCell->yPixel = yPixel;
    sub_00457B00(pCell, ppRoot);
}

// 0x0045AFF0
void __fastcall sub_0045AFF0_ScreenToMap(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    if (sub_004F51D0_IsPerspective())
    {
        nY += nY / -40;
        int nHalfWidth = gnGlobal_0071146C / 2;
        nX += (40 - nY / 4) * (nX - nHalfWidth) / nHalfWidth;
    }
    nY += gdwGlobal_007A5208;
    nX += gdwGlobal_007A520C - gnGlobal_007A5214;
    sub_00643510(&nX, &nY);
    *pX = nX;
    *pY = nY;
}

// 0x0045B1E0
void __stdcall sub_0045B1E0_DrawUnitTileRect(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2TileRectStrc* pTileRect = sub_00619620(pRoom, pUnit);
    if (!pTileRect)
    {
        return;
    }
    int nX = UNITS_GetXPositionInline(pUnit);
    int nY = UNITS_GetYPositionInline(pUnit);
    sub_00643260(&nX, &nY);
    int nLeft = pTileRect->nX - gdwGlobal_007A520C + nX;
    int nTop = pTileRect->nY - gdwGlobal_007A5208 + nY;
    int nRight = pTileRect->nWidth + nLeft;
    int nBottom = pTileRect->nHeight + nTop;
    D2GFX_DrawLine(nLeft, nTop, nLeft, nBottom, 0xFF, 0xFF);
    D2GFX_DrawLine(nLeft, nTop, nRight, nTop, 0xFF, 0xFF);
    D2GFX_DrawLine(nLeft, nBottom, nRight, nBottom, 0xFF, 0xFF);
    D2GFX_DrawLine(nRight, nTop, nRight, nBottom, 0xFF, 0xFF);
    nX += 1;
    tagRECT tRect;
    tRect.left = nX - gdwGlobal_007A520C - 0x10;
    tRect.right = nX - gdwGlobal_007A520C + 0x10;
    tRect.top = nY - gdwGlobal_007A5208;
    tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
    D2GFX_UtilDiamond(&tRect, 0xFF);
    nX = UNITS_GetXPositionInline(pUnit);
    nY = UNITS_GetYPositionInline(pUnit);
    nX += pTileRect->nOffsetX;
    nY += pTileRect->nOffsetY;
    sub_00643260(&nX, &nY);
    nX += 1;
    tRect.left = nX - gdwGlobal_007A520C - 0x10;
    tRect.right = nX - gdwGlobal_007A520C + 0x10;
    tRect.top = nY - gdwGlobal_007A5208;
    tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
    D2GFX_UtilDiamond(&tRect, 0x2D);
}

// 0x0045B3E0
void __cdecl sub_0045B3E0_DrawRoomTileRects()
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->pRoomNext)
            {
                if (pUnit->dwUnitType == UNIT_TILE)
                {
                    sub_0045B1E0_DrawUnitTileRect(pUnit);
                }
            }
        }
    }
}

// 0x0045B440
void __cdecl sub_0045B440_UpdateAutomapOrigin()
{
    int nShiftX;
    int nShiftY;
    gnGlobal_007A5204 = -0xA0;
    if (gdwGlobal_007A5210 == 2)
    {
        gnGlobal_007A5204 = gnGlobal_0071146C / 2 - 0xA0;
    }
    else if (gdwGlobal_007A5210 == 3)
    {
        gnGlobal_007A5204 = 0;
    }
    D2UnitStrc* pPlayer = sub_00463DD0();
    int nX = UNITS_GetClientCoordX(pPlayer);
    int nY = UNITS_GetClientCoordY(pPlayer);
    gdwGlobal_007A520C = nX - gnGlobal_0071146C / 2;
    gdwGlobal_007A5208 = nY - gnGlobal_00711470 / 2 + 0x10;
    if (sub_00476AC0_GetViewShift(&nShiftX, &nShiftY))
    {
        gdwGlobal_007A520C += nShiftX;
        gdwGlobal_007A5208 += nShiftY;
    }
}

// 0x0045B4F0
void __stdcall sub_0045B4F0_DrawRoomCollision(D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    for (int nY = tCoords.nSubtileY + 2; nY < tCoords.nSubtileY + tCoords.nSubtileHeight + 5; nY += 5)
    {
        for (int nX = tCoords.nSubtileX + 3; nX < tCoords.nSubtileX + tCoords.nSubtileWidth + 5; nX += 5)
        {
            int nCollision = sub_0061B130_GetCollision(pRoom, nX, nY);
            int nScreenX = nX;
            int nScreenY = nY;
            sub_00643260(&nScreenX, &nScreenY);
            tagRECT tRect;
            tRect.left = nScreenX - gdwGlobal_007A520C - 0x10;
            tRect.right = nScreenX - gdwGlobal_007A520C + 0x10;
            tRect.top = nScreenY - gdwGlobal_007A5208;
            tRect.bottom = nScreenY - gdwGlobal_007A5208 + 0x10;
            D2GFX_UtilDiamond(&tRect, 0x46);
            nScreenX = nScreenX - 7 - gdwGlobal_007A520C;
            nScreenY = nScreenY - gdwGlobal_007A5208;
            D2GFX_OutputString(nScreenX, nScreenY, gszFormatInt_006D57BC, nCollision);
        }
    }
}

// 0x0045D3E0
void __fastcall sub_0045D3E0_RefreshItemStats(D2UnitStrc* pUnit)
{
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }
    int nLeftSkillId = pUnit->pSkills->pLeftSkill ? pUnit->pSkills->pLeftSkill->pSkillsTxt->nSkillId : 0;
    int nRightSkillId = pUnit->pSkills->pRightSkill ? pUnit->pSkills->pRightSkill->pSkillsTxt->nSkillId : 0;
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        int bStatNotDynamic = 0;
        if (pCheckedItem && pCheckedItem->dwUnitType == UNIT_ITEM && STATLIST_GetOwner(pCheckedItem, &bStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pCheckedItem);
            STATLIST_MergeStatLists(pUnit, pCheckedItem, bStatNotDynamic);
        }
    }
    SKILLS_SetLeftActiveSkill(pUnit, nLeftSkillId, -1);
    SKILLS_SetRightActiveSkill(pUnit, nRightSkillId, -1);
}

// 0x0045FA40
void __fastcall sub_0045FA40(void* pArg)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pArg);
    if (!pBuffer)
    {
        return;
    }
    D2_ASSERT(pBuffer->nCount <= pBuffer->nMax, 0x1525);
    for (int i = 0; i < pBuffer->nCount; ++i)
    {
        unsigned char* pPacket = pBuffer->pData + gnGlobal_007A5230 * i;
        int nSize;
        if (!sub_0052B920(pPacket, gnGlobal_007A5230, &nSize))
        {
            return;
        }
        D2_ASSERT(pPacket[0] < 0xAF, 0x1531);
        D2PacketTableEntryStrc* pEntry = &gtPacketTable_007114D0[pPacket[0]];
        if (pEntry->nSize != -1)
        {
            D2_ASSERT((unsigned short)nSize == pEntry->nSize, 0x1534);
        }
        D2_ASSERT(pEntry->f_8, 0x1536);
        pEntry->f_8(pArg, pPacket);
    }
    if (pBuffer->nCount)
    {
        memset(pBuffer->pData, 0, pBuffer->nCount * gnGlobal_007A5230);
    }
    pBuffer->nCount = 0;
}

// 0x0045FE30
void __stdcall sub_0045FE30_ButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nLeft = gnGlobal_007A2858 + 0x110;
    int nBottom = 0x136 - gnGlobal_007A285C;
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gnGlobal_007A524C = 1;
        gnGlobal_007A5248 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_0044DA70();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004601F0
void __stdcall sub_004601F0_TwoButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nLeft = gnGlobal_007A2858 + 0xCE;
    int nBottom = 0x136 - gnGlobal_007A285C;
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gnGlobal_007A524C = 1;
        gnGlobal_007A5248 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    nLeft = gnGlobal_007A2858 + 0x152;
    nBottom = 0x136 - gnGlobal_007A285C;
    nX = sub_00468730();
    nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gnGlobal_007A5250 = 1;
        gnGlobal_007A5248 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_0044DA70();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004602E0
void __stdcall sub_004602E0_TwoButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gnGlobal_007A524C = 0;
    gnGlobal_007A5250 = 0;
    if (gnGlobal_007A5248)
    {
        int nLeft = gnGlobal_007A2858 + 0xCE;
        int nBottom = 0x136 - gnGlobal_007A285C;
        int nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gnGlobal_007A5258 = 1;
            gnGlobal_007A5248 = 0;
        }
        nLeft = gnGlobal_007A2858 + 0x152;
        nBottom = 0x136 - gnGlobal_007A285C;
        nX = sub_00468730();
        nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gnGlobal_007A525C = 1;
            gnGlobal_007A5248 = 0;
        }
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    sub_0044DA70();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00460930
void __fastcall sub_00460930_SetUnitLightRadius(D2UnitStrc* pUnit, int nDelta)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!pLight)
    {
        return;
    }
    int nRadius;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nRadius = 0xD;
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }
        nRadius = sub_0063EBD0_GetLightRadius(pUnit);
        if (nRadius < pMonStats2TxtRecord->nLightRadius)
        {
            nRadius = pMonStats2TxtRecord->nLightRadius;
        }
    }
    nRadius += nDelta;
    sub_004742D0(pLight, nRadius > 0 ? nRadius : 0);
}

// 0x004609A0
void __fastcall sub_004609A0_SetUnitLightColor(D2UnitStrc* pUnit, int nColor)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!pLight)
    {
        return;
    }
    unsigned char nRed = 0xFF;
    unsigned char nGreen = 0xFF;
    unsigned char nBlue = 0xFF;
    if (nColor)
    {
        nRed = (unsigned char)(nColor >> 16);
        nGreen = (unsigned char)(nColor >> 8);
        nBlue = (unsigned char)nColor;
    }
    sub_00474390_SetRecordBytes(pLight, nRed, nGreen, nBlue);
}

// 0x00462EE0
unsigned char __stdcall sub_00462EE0_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == BODYLOC_LARM || nBodyLoc == BODYLOC_RARM)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        if (pRightArmItem && pLeftArmItem && !ITEMS_CheckWeaponIfTwoHanded(pRightArmItem)
            && !ITEMS_CheckWeaponIfTwoHanded(pLeftArmItem) && pItem != INVENTORY_GetLeftHandWeapon(pInventory))
        {
            return 6;
        }
    }
    return ITEMS_GetComponent(pItem);
}

// 0x00463180
void __fastcall sub_00463180_UpdatePathAndMove(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3)
{
    int nMode = pUnit->dwAnimMode;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTargetUnit = 0;
    int bMove = 0;
    int nX = 0;
    int nY = 0;
    if (nMode >= PLAYER_MODE_WALK && (nMode <= PLAYER_MODE_RUN || nMode == PLAYER_MODE_6))
    {
        bMove = 1;
        pTargetUnit = sub_004648F0_GetTargetUnit(pUnit);
        if (!pTargetUnit)
        {
            sub_004C52E0_GetTargetPosition(pUnit, &nX, &nY);
        }
    }
    sub_00650C60_UpdatePath(pPath, pUnit, nArg1, nArg2, nArg3);
    if (bMove)
    {
        D2UnitTargetStrc tTarget;
        memset(&tTarget, 0, sizeof(tTarget));
        if (pTargetUnit)
        {
            tTarget.nParam1 = pTargetUnit->dwUnitType;
            tTarget.nParam2 = pTargetUnit->dwUnitId;
            sub_00461250_QueueMove(nMode == PLAYER_MODE_RUN ? 0x18 : 0, pUnit, &tTarget, 0);
        }
        else
        {
            tTarget.nParam1 = nX;
            tTarget.nParam2 = nY;
            sub_00461250_QueueMove(nMode == PLAYER_MODE_RUN ? 0x17 : 1, pUnit, &tTarget, 0);
        }
    }
}

#include "gen/data/Source/D2Client/UI/automap_00451E10.inc"
