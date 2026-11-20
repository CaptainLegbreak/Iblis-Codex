#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Win32Types.h"

struct D2DrlgStrc;
struct D2DrlgEnvironmentStrc;
struct D2DrlgActStrc;
struct D2DrlgCoordsStrc;
struct D2CoordStrc;
struct D2CommonLevelNodeStrc;

struct D2ActiveRoomStrc
{
    D2ActiveRoomStrc** ppRoomList;
    unsigned char unk_04[0x4];
    int pRoomTiles;
    unsigned char unk_0C[0x4];
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x14[0x10];
    int nNumRooms;
    char unk0x28[0xC];
    unsigned int dwFlags;
    char unk0x38[0x10];
    int* pUnk0x48;
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x6C[0x8];
    D2UnitStrc* pUnitFirst;
    int nUnk0x78;
    D2ActiveRoomStrc* pRoomNext;
};

struct D2DrlgActStrc
{
    char unk0x00[0x4];
    D2DrlgEnvironmentStrc* pEnvironment;
    char unk0x08[0x8];
    D2ActiveRoomStrc* pRoom;
    char unk0x14[0x34];
    D2DrlgStrc* pDrlg;
    char unk0x4C[0x4];
    int bClient;
    char unk0x54[0x8];
    void* pMemPool;
};

struct D2DrlgCoordsStrc
{
    union
    {
        int nSubtileX;
        int nTileXPos;
    };
    union
    {
        int nSubtileY;
        int nTileYPos;
    };
    union
    {
        int nSubtileWidth;
        int nTileWidth;
    };
    union
    {
        int nSubtileHeight;
        int nTileHeight;
    };
};

typedef tagRECT RECT;

struct D2CommonLevelNodeStrc
{
    char unk0x00[0x8];
    D2CommonLevelNodeStrc** ppChildren;
    unsigned short wLevelCounts[16];
    int nChildren;
    char unk0x30[0x14];
    unsigned char nMaxLevel;
};

typedef int (__stdcall* FARPROC)();

typedef int (__stdcall* ROOMCALLBACKFN)(D2ActiveRoomStrc* pRoom, void* pArgs);

typedef void (__fastcall* LEVELNODEFN)(D2CommonLevelNodeStrc* pNode);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern const LEVELNODEFN gpfnLevelNodeHandlers_00744384[]; // 0x00744384
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall DUNGEON_FreeRoom(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0061A840
void __fastcall ENVIRONMENT_FreeDrlgEnvironment(void* pMemPool, D2DrlgEnvironmentStrc* pEnvironment); // 0x0061BEC0
void __fastcall DRLG_FreeDrlg(D2DrlgStrc* pDrlg); // 0x00642190
void __stdcall DUNGEON_GameToClientTileDrawPositionCoords(int nX, int nY, int* pX, int* pY); // 0x006433C0
void __stdcall UNITROOM_SortUnitListByTargetY(D2ActiveRoomStrc* pRoom); // 0x0064C0C0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x0066AB00
D2ActiveRoomStrc* __fastcall sub_0066B2B0_GetLevelEntryRoom(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x0066B2B0
void __fastcall sub_0066B4C0(D2DrlgRoomStrc* pDrlgRoom, int bClient, unsigned int nFlags); // 0x0066B4C0
void __fastcall sub_0066C370_OnChildlessNode(void* pContext, D2CommonLevelNodeStrc* pNode); // 0x0066C370
int __fastcall DRLGLOGIC_GetRoomCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY); // 0x0066CE30

// 0x006195A0
D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc* pRoom, int nSourceLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord)
{
    D2_ASSERT(pRoom, 106);
    int nDestinationLevel;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    D2ActiveRoomStrc* pDestRoom = DRLGWARP_GetDestinationRoom(pRoom->pDrlgRoom, nSourceLevel, &nDestinationLevel, &pLvlWarpTxtRecord);
    D2_ASSERT(pDestRoom, 113);
    D2UnitStrc* pTile = pDestRoom->pUnitFirst;
    while (pTile)
    {
        const int nType = pTile ? pTile->dwUnitType : 6;
        const int nClassId = pTile ? pTile->dwClassId : -1;
        if (nType == 5 && nClassId == nDestinationLevel)
            break;
        pTile = pTile->ptRoomNext;
    }
    *ppLvlWarpTxtRecord = pLvlWarpTxtRecord;
    return pTile;
}

// 0x00619970
int __stdcall DUNGEON_DoRoomsTouchOrOverlap(D2ActiveRoomStrc* ptFirst, D2ActiveRoomStrc* ptSecond)
{
    D2_ASSERT(ptFirst, 318);
    D2_ASSERT(ptSecond, 321);
    if (ptFirst->nTileXPos > ptSecond->nTileXPos + ptSecond->nTileWidth)
        return 0;
    if (ptFirst->nTileXPos + ptFirst->nTileWidth < ptSecond->nTileXPos)
        return 0;
    if (ptFirst->nTileYPos > ptSecond->nTileYPos + ptSecond->nTileHeight)
        return 0;
    return ptFirst->nTileYPos + ptFirst->nTileHeight >= ptSecond->nTileYPos;
}

// 0x006199F0
int __stdcall DUNGEON_AreTileCoordinatesInsideRoom(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(pRoom, 360);
    if (nX >= pRoom->nTileXPos && nX < pRoom->nTileXPos + pRoom->nTileWidth
        && nY >= pRoom->nTileYPos && nY < pRoom->nTileYPos + pRoom->nTileHeight)
        return 1;
    return 0;
}

// 0x00619B60
D2ActiveRoomStrc* __stdcall DUNGEON_GetAdjacentRoomByTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(pRoom, 431);
    for (unsigned int i = 0; i < (unsigned int)pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pTemp = pRoom->ppRoomList[i];
        D2_ASSERT(pTemp, 435);
        if (DUNGEON_AreTileCoordinatesInsideRoom(pTemp, nX, nY))
            return pTemp;
    }
    return 0;
}

// 0x00619BD0
void __stdcall DUNGEON_CallRoomCallback(D2ActiveRoomStrc* ptRoom, ROOMCALLBACKFN pfnRoomCallback, void* pArgs)
{
    D2_ASSERT(ptRoom, 448);
    D2_ASSERT(!IsBadCodePtr((FARPROC)pfnRoomCallback), 450);
    for (unsigned int i = 0; i < (unsigned int)ptRoom->nNumRooms; ++i)
    {
        if (!pfnRoomCallback(ptRoom->ppRoomList[i], pArgs))
            break;
    }
}

// 0x00619C40
void __stdcall D2Common_10052(D2ActiveRoomStrc* pRoom, RECT* pRect)
{
    int nTemp;
    D2_ASSERT(pRoom, 464);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->nTileXPos, pRoom->nTileYPos, &nTemp, (int*)&pRect->top);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->nTileXPos, pRoom->nTileHeight + pRoom->nTileYPos, (int*)&pRect->left, &nTemp);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->nTileXPos + pRoom->nTileWidth, pRoom->nTileYPos, (int*)&pRect->right, &nTemp);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->nTileXPos + pRoom->nTileWidth, pRoom->nTileHeight + pRoom->nTileYPos, &nTemp, (int*)&pRect->bottom);
    D2_ASSERT(pRect->top <= pRect->bottom, 474);
    D2_ASSERT(pRect->left <= pRect->right, 475);
}

// 0x00619DF0
int __fastcall DUNGEON_AreSubtileCoordinatesInsideRoom(D2DrlgCoordsStrc* ptCoords, int nX, int nY)
{
    D2_ASSERT(ptCoords, 530);
    if (nX >= ptCoords->nSubtileX && nX < ptCoords->nSubtileX + ptCoords->nSubtileWidth
        && nY >= ptCoords->nSubtileY && nY < ptCoords->nSubtileY + ptCoords->nSubtileHeight)
        return 1;
    return 0;
}

// 0x00619EA0
D2UnitStrc* __stdcall DUNGEON_GetFirstUnitInRoom(D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptRoom, 585);
    UNITROOM_SortUnitListByTargetY(ptRoom);
    return ptRoom->pUnitFirst;
}

// 0x0061A7E0
int __fastcall sub_0061A7E0_HasEntryMissingFrom(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    for (int i = 0; i < pRoom2->nUnk0x78; ++i)
    {
        int j = 0;
        while (j < pRoom1->nUnk0x78 && pRoom1->pUnk0x48[j] != pRoom2->pUnk0x48[i])
            ++j;
        if (j >= pRoom1->nUnk0x78)
            return 1;
    }
    return 0;
}

// 0x0061A910
void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1271);
    D2ActiveRoomStrc* pPreviousRoom = 0;
    D2ActiveRoomStrc* pCurrentRoom;
    for (pCurrentRoom = pAct->pRoom; pCurrentRoom; pCurrentRoom = pCurrentRoom->pRoomNext)
    {
        if (pCurrentRoom == pRoom)
            break;
        pPreviousRoom = pCurrentRoom;
    }
    D2_ASSERT(pCurrentRoom, 1282);
    if (pPreviousRoom)
        pPreviousRoom->pRoomNext = pCurrentRoom->pRoomNext;
    else
        pAct->pRoom = pCurrentRoom->pRoomNext;
    for (int i = 0; i < pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pNearRoom = pRoom->ppRoomList[i];
        if (pNearRoom != pRoom)
        {
            for (int nCounter = 0; nCounter < pNearRoom->nNumRooms; ++nCounter)
            {
                if (pNearRoom->ppRoomList[nCounter] == pRoom)
                {
                    pNearRoom->ppRoomList[nCounter] = pNearRoom->ppRoomList[pNearRoom->nNumRooms - 1];
                    --pNearRoom->nNumRooms;
                    break;
                }
            }
        }
    }
    sub_0066B4C0(pRoom->pDrlgRoom, pAct->bClient, pRoom->dwFlags);
    DUNGEON_FreeRoom(pAct->pMemPool, pRoom);
}

// 0x0061AD70
void __stdcall DUNGEON_GetPortalLevelArrayFromPortalFlags(void* pMemPool, int nFlags, int** ppLevels, int* pnLevels)
{
    int pLevels[32];
    int nPortalLevels;
    int nCurrentFlag = 1;
    int nCount = 0;
    int* pPortalLevels = DATATBLS_GetPortalLevels(&nPortalLevels);
    D2_ASSERT(nPortalLevels <= 32, 1546);
    for (int i = 0; i < nPortalLevels; ++i)
    {
        if (nFlags & nCurrentFlag)
        {
            pLevels[nCount] = pPortalLevels[i];
            ++nCount;
        }
        nCurrentFlag <<= 1;
    }
    if (nCount)
    {
        *ppLevels = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nCount, ".\\DUNGEON\\Dungeon.cpp", 1556, 0);
        memcpy(*ppLevels, pLevels, sizeof(int) * nCount);
    }
    else
    {
        *ppLevels = 0;
    }
    *pnLevels = nCount;
}

// 0x0061AFD0
void __stdcall DUNGEON_FreeAct(D2DrlgActStrc* ptAct)
{
    D2_ASSERT(ptAct, 58);
    if (ptAct->pDrlg)
    {
        DRLG_FreeDrlg(ptAct->pDrlg);
        ptAct->pDrlg = 0;
    }
    D2ActiveRoomStrc* pRoom = ptAct->pRoom;
    while (pRoom)
    {
        D2ActiveRoomStrc* pNext = pRoom->pRoomNext;
        DUNGEON_FreeRoom(ptAct->pMemPool, pRoom);
        pRoom = pNext;
    }
    if (ptAct->pEnvironment)
    {
        ENVIRONMENT_FreeDrlgEnvironment(ptAct->pMemPool, ptAct->pEnvironment);
        ptAct->pEnvironment = 0;
    }
    FOG_FreePool(ptAct->pMemPool, ptAct, ".\\DUNGEON\\Dungeon.cpp", 82, 0);
}

// 0x0061B060
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* ptAct, int nLevelId, int nTileIndex, int* pX, int* pY, int nUnitSize)
{
    D2CoordStrc tCoord;
    D2_ASSERT(ptAct, 556);
    int nX = 0;
    int nY = 0;
    D2ActiveRoomStrc* pRoom = sub_0066B2B0_GetLevelEntryRoom(ptAct->pDrlg, nLevelId, nTileIndex, &nX, &nY);
    if (pRoom)
    {
        DUNGEON_GameTileToSubtileCoords(&nX, &nY);
        tCoord.nX = nX + 3;
        tCoord.nY = nY + 3;
        D2_ASSERT(COLLISION_GetFreeCoordinates(pRoom, &tCoord, nUnitSize, 0x1C09, 0), 568);
        *pX = tCoord.nX;
        *pY = tCoord.nY;
        return sub_00463740_FindRoomAtPoint(pRoom, *pX, *pY);
    }
    return 0;
}

// 0x0061B130
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2ActiveRoomStrc* pFoundRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pFoundRoom)
        return 0;
    return DRLGLOGIC_GetRoomCoordListIndex(pFoundRoom->pDrlgRoom, nX, nY);
}

static inline int sub_F45_IsFirstAtLevel(D2CommonLevelNodeStrc* pNode, int nLevel)
{
    for (int i = 0; i <= nLevel; ++i)
    {
        if (pNode->wLevelCounts[i])
            return 0;
    }
    return 1;
}

static inline void sub_F45_VisitChild(D2CommonLevelNodeStrc* pChild, int nLevel)
{
    if (pChild->nMaxLevel >= nLevel && sub_F45_IsFirstAtLevel(pChild, nLevel))
        gpfnLevelNodeHandlers_00744384[nLevel](pChild);
    ++pChild->wLevelCounts[nLevel];
}

// 0x0061B390
void __fastcall sub_0061B390_WalkLevels(void* pContext, D2CommonLevelNodeStrc* pNode, unsigned char nLevel)
{
    if (!pNode->nChildren)
        sub_0066C370_OnChildlessNode(pContext, pNode);
    if (nLevel < 3)
    {
        for (int i = 0; i < pNode->nChildren; ++i)
        {
            D2CommonLevelNodeStrc* pChild = pNode->ppChildren[i];
            sub_0061B390_WalkLevels(pContext, pChild, nLevel + 1);
            sub_F45_VisitChild(pChild, nLevel);
        }
    }
    else
    {
        for (int i = 0; i < pNode->nChildren; ++i)
            sub_F45_VisitChild(pNode->ppChildren[i], nLevel);
    }
}

#include "gen/data/Source/D2Common/DUNGEON/Dungeon_006195A0.inc"

// 0x00619A50
int __stdcall DUNGEON_CheckRoomsOverlapping_BROKEN(D2ActiveRoomStrc* pPrimary, D2ActiveRoomStrc* pSecondary)
{
    D2_ASSERT(pPrimary, 379);

    const D2DrlgCoordsStrc* pFirst = (D2DrlgCoordsStrc*)&pPrimary->nTileXPos;
    const D2DrlgCoordsStrc* pSecond = (D2DrlgCoordsStrc*)&pPrimary->nTileXPos;
    const int nX2 = pSecond->nTileXPos;
    const int nX1 = pFirst->nTileXPos;
    if (nX1 > nX2 + pSecond->nTileWidth)
        return 0;
    if (nX1 + pFirst->nTileWidth < nX2)
        return 0;
    const int nY2 = pSecond->nTileYPos;
    if (pFirst->nTileYPos > nY2 + pSecond->nTileHeight)
        return 0;
    if (pFirst->nTileYPos + pFirst->nTileHeight < nY2)
        return 0;
    if (nX1 == nX2 + pSecond->nTileWidth)
        return 1;
    if (nX1 + pFirst->nTileWidth == nX2)
        return 2;
    if (pFirst->nTileYPos == nY2 + pSecond->nTileHeight)
        return 3;
    return 4;
}

// 0x0061A8E0
void __fastcall sub_0061A8E0_ClearRoomField08(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 0x4EC);
    pRoom->pRoomTiles = 0;
}
