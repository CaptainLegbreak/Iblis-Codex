#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2TileLibraryEntryStrc;
struct D2DrlgCoordStrc;
struct D2RoomCoordListStrc;
struct D2DrlgCoordsStrc;
struct D2StaticPathStrc;
struct D2StormLinkStrc;
struct D2StormListStrc;
struct D2ClientAllocRecStrc;
struct D2ClientAllocRecListStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct tagRECT
{
    int left;
    int top;
    int right;
    int bottom;
};

struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2RoomCoordListStrc
{
    D2DrlgCoordStrc pBox[2];
    int bNode;
    int bRoomActive;
    int nIndex;
    D2RoomCoordListStrc* pNext;
};

struct D2DrlgTileDataStrc
{
    int nWidth;
    int nHeight;
    int nPosX;
    int nPosY;
    D2RoomCoordListStrc* pCoordList;
    unsigned int dwFlags;
    D2TileLibraryEntryStrc* pTile;
    int nTileType;
    D2DrlgTileDataStrc* pNext;
    int unk0x24;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nIntensity;
    int unk0x2C;
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

D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount); // 0x006196A0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom); // 0x0061AD50
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY); // 0x00643310
int __stdcall TILE_GetFlags16(D2TileLibraryEntryStrc* pTile); // 0x00604BC0
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __fastcall sub_0045B1A0_DrawDiamond(int nX, int nY, unsigned char nColor);
D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom();
extern int gdwGlobal_007A5208; // 0x007A5208
extern int gdwGlobal_007A520C; // 0x007A520C

enum D2C_M106RoomDbgConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2StaticPathStrc
{
    void* pRoom;
    int nTargetX;
    int nTargetY;
    int nXPos;
    int nYPos;
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
};

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __cdecl sub_00463DE0_GetStoredUnit(); // 0x00463DE0
int __cdecl sub_004F5140(); // 0x004F5140
void __stdcall sub_0045B4F0_DrawRoomCollision(D2ActiveRoomStrc* pRoom); // 0x0045B4F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom); // 0x0045B5F0

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
};

struct D2StormListStrc {
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    void sub_0045BB70(D2StormLinkStrc* link);
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2ClientAllocRecStrc
{
    D2StormLinkStrc f_0;
    int unk0x08[0x4A];

    static void operator delete(void* pMemory);
};

struct D2ClientAllocRecListStrc
{
    int nLinkOffset;
    D2StormLinkStrc tTerminator;

    D2StormLinkStrc* Link(D2ClientAllocRecStrc* pNode)
    {
        return pNode ? &pNode->f_0 : &tTerminator;
    }
    D2ClientAllocRecStrc* Next(D2ClientAllocRecStrc* pNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        return (int)pLink->m_next <= 0 ? 0 : (D2ClientAllocRecStrc*)pLink->m_next;
    }

    void sub_0045BBE0_LinkNode(D2ClientAllocRecStrc* pNode, unsigned int nLinkType, D2ClientAllocRecStrc* pExisting); // 0x0045BBE0
    D2ClientAllocRecStrc* sub_0045BDD0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
    D2ClientAllocRecStrc* sub_0045BE90_DeleteNode(D2ClientAllocRecStrc* pNode);
};

inline void* operator new(unsigned int nSize, void* pWhere) throw();

// 0x0045B5F0
void __stdcall sub_0045B5F0(D2ActiveRoomStrc* pRoom)
{
    int nTiles;
    D2DrlgTileDataStrc* pTiles = DUNGEON_GetWallTilesFromRoom(pRoom, &nTiles);
    D2_ASSERT(pTiles || !nTiles, 725);

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    for (unsigned int i = 0; i < (unsigned int)nTiles; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles[i];
        if (!pTile->pCoordList)
        {
            continue;
        }

        int nX = (pTile->nPosX + tCoords.nTileXPos) * 5 + 3;
        int nY = (pTile->nPosY + tCoords.nTileYPos) * 5 + 3;
        sub_00643260(&nX, &nY);

        if (pTile->nTileType == 15 || (pTile->dwFlags & 0x1C000) != 0x4000)
        {
            continue;
        }

        if (TILE_GetFlags16(pTile->pTile) & 4)
        {
            const int nDiamondX = nX + 0x20;
            tagRECT tRect;
            tRect.left = nDiamondX - gdwGlobal_007A520C - 0x10;
            tRect.right = nDiamondX - gdwGlobal_007A520C + 0x10;
            tRect.top = nY - gdwGlobal_007A5208;
            tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
            D2GFX_UtilDiamond(&tRect, 0x78);
        }
        else if (pTile->dwFlags & 0x800)
        {
            sub_0045B1A0_DrawDiamond(nX + 0x10, nY + 8, 0x78);
        }
        else
        {
            sub_0045B1A0_DrawDiamond(nX, nY, 0xFF);
        }

        nX -= gdwGlobal_007A520C + 7;
        nY -= gdwGlobal_007A5208;
        D2GFX_OutputString(nX, nY, gszFormatInt_006D57BC, pTile->pCoordList->nIndex);
    }

    if (pRoom == sub_004646A0_GetPlayerRoom())
    {
        int aX[4];
        int aY[4];
        for (D2RoomCoordListStrc* pCoordList = DUNGEON_GetRoomCoordList(pRoom); pCoordList; pCoordList = pCoordList->pNext)
        {
            aX[0] = aX[1] = pCoordList->pBox[0].nPosX;
            aX[2] = aX[3] = pCoordList->pBox[0].nWidth;
            aY[0] = aY[2] = pCoordList->pBox[0].nPosY;
            aY[1] = aY[3] = pCoordList->pBox[0].nHeight;

            for (int j = 0; j < 4; ++j)
            {
                DUNGEON_GameTileToClientCoords(&aX[j], &aY[j]);
                aX[j] -= gdwGlobal_007A520C;
                aY[j] -= gdwGlobal_007A5208;
            }

            if (pRoom == sub_004646A0_GetPlayerRoom())
            {
                D2GFX_DrawLine(aX[0], aY[0], aX[0], aY[0] + 0x10, 0x78, 0xFF);
                D2GFX_DrawLine(aX[1], aY[1], aX[1] + 0x10, aY[1], 0x78, 0xFF);
                D2GFX_DrawLine(aX[2], aY[2], aX[2] - 0x10, aY[2], 0x78, 0xFF);
                D2GFX_DrawLine(aX[3], aY[3], aX[3], aY[3] - 0x10, 0x78, 0xFF);
            }

            D2GFX_DrawLine(aX[0], aY[0], aX[1], aY[1], 0x78, 0xFF);
            D2GFX_DrawLine(aX[0], aY[0], aX[2], aY[2], 0x78, 0xFF);
            D2GFX_DrawLine(aX[1], aY[1], aX[3], aY[3], 0x78, 0xFF);
            D2GFX_DrawLine(aX[2], aY[2], aX[3], aY[3], 0x78, 0xFF);
        }
    }
}

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

// 0x0045B8B0
void __cdecl sub_0045B8B0_DrawLogicalRoom()
{
    if (sub_004F5140() == 3)
        return;

    D2UnitStrc* pPlayer = sub_00463DE0_GetStoredUnit();
    int nX = UNITS_GetXPositionInline(pPlayer);
    int nY = UNITS_GetYPositionInline(pPlayer);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    D2GFX_OutputString(10, 0x37, "Logical Room->%d", sub_0061B130_GetCollision(pRoom, nX, nY));
    sub_0045B4F0_DrawRoomCollision(pRoom);
    sub_0045B5F0(pRoom);
}

// 0x0045BA90
extern "C" void* __fastcall sub_0045BA90(void* value) { return value; }

// 0x0045BB70
void D2StormListStrc::sub_0045BB70(D2StormLinkStrc* link)
{
    if(!link) link=&m_terminator;
    link->Unlink();
}

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x0045BDD0
D2ClientAllocRecStrc* D2ClientAllocRecListStrc::sub_0045BDD0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2ClientAllocRecStrc) + nExtraBytes, gszTypeNameAllocRec_00711480, -2, nFlags | 8);
    D2ClientAllocRecStrc* pNode = pMemory ? new (pMemory) D2ClientAllocRecStrc : 0;
    if (nLocation)
        sub_0045BBE0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

// build: symbol ??_GD2ClientAllocRecStrc@@QAEPAXI@Z 0x0045BE30
inline void D2ClientAllocRecStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0045BE90
D2ClientAllocRecStrc* D2ClientAllocRecListStrc::sub_0045BE90_DeleteNode(D2ClientAllocRecStrc* pNode)
{
    D2ClientAllocRecStrc* pNext = Next(pNode);
    pNode->~D2ClientAllocRecStrc();
    SMemFree(pNode, gszTypeNameAllocRec_00711480, -2, 0);
    return pNext;
}

// build: context sub_W10_EmitDeleteAllocRec
void sub_W10_EmitDeleteAllocRec(D2ClientAllocRecStrc* pNode)
{
    delete pNode;
}

#include "gen/data/Source/D2Client/Unknown_0045B5F0.inc"
