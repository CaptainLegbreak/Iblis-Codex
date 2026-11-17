#include "D2Client.h"

#define FIELD(T, p, off) (*(T*)((unsigned char*)(p) + (off)))
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Tile;
struct Cell;
struct Context;
struct Node;
struct D2GridRectStrc;
struct D2GridOwnerStrc;
struct D2GridUnitStrc;
struct D2GridLightStrc;

struct RoomCoordinates
{
    int x;
    int y;
    int width;
    int height;
    int tileX;
    int tileY;
    int tileWidth;
    int tileHeight;
};

struct Node
{
    int type;
    int x;
    int y;
    void* object;
    Node* next;
};

void __stdcall DUNGEON_GetRoomCoordinates(Room* pRoom, RoomCoordinates* pCoords); // 0x00619730
extern const unsigned int gVar_006CE274_Flags; // 0x006CE274
static __declspec(noinline) void __stdcall sub_004DD550_AddFloor(Cell* cell, Room* room, Context* context, Tile* tile);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2GridCellStrc
{
    unsigned char nB0;
    unsigned char nB1;
    unsigned char nB2;
    unsigned char nB3;
    int nX;
    int nY;
};

struct D2GridLightStrc
{
    int bCorners;
    int bSmall;
    int bEffectA;
    int bEffectB;
    int nLimitA;
    char pad0x14[0x8];
    int f_1C;
    int nMode;
    D2GridOwnerStrc* pOwner;

    void __thiscall sub_B08_ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY);
    void __thiscall sub_004DDE80_UpdateBounds(D2GridUnitStrc* pUnit, int nSubX, int nSubY);     // 0x004DDE80
};

extern void* gpGlobal_007A0634; // 0x007A0634
extern int gnGlobal_0071146C; // 0x0071146C
unsigned char __stdcall sub_0061C0E0(void* pAct); // 0x0061C0E0
void __stdcall sub_0061C0B0(void* pAct, unsigned char* pR, unsigned char* pG, unsigned char* pB); // 0x0061C0B0
void __fastcall sub_00475AA0(int nX, int nY, unsigned char* pB0, unsigned char* pB1, unsigned char* pB2, unsigned char* pB3); // 0x00475AA0
int __stdcall sub_00477730(); // 0x00477730
void __stdcall sub_004DE070(D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE070
void __stdcall sub_004DE260(D2GridCellStrc* pCells, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE260
int __fastcall sub_00472280(int nSeed, int nZero, int nMax); // 0x00472280
static __declspec(noinline) void __stdcall sub_004DE190_BuildSmallGrid(int nSubX, int nSubY, int nZ, int bCorners, D2GridCellStrc* pCells, int nMode);

// 0x004DD550
static void __stdcall sub_004DD550_AddFloor(Cell* cell, Room* room, Context* context, Tile* tile)
{
    unsigned int index = FIELD(unsigned int, context, 0xEA64)++;
    if (index >= 3000)
    {
        return;
    }
    Node* node = &FIELD(Node, context, 4) + index;
    node->type = 1;
    node->object = tile;
    node->next = 0;
    {
        RoomCoordinates coordinates;
        DUNGEON_GetRoomCoordinates(room, &coordinates);
        node->x = 8 * (coordinates.x + 5 * FIELD(int, tile, 8));
        node->y = 8 * (coordinates.y + 5 * FIELD(int, tile, 12));
    }
    FIELD(unsigned int, context, 0) |= gVar_006CE274_Flags;
    Node* last = FIELD(Node*, cell, 16);
    if (!last)
    {
        FIELD(Node*, cell, 16) = node;
        return;
    }
    while (last->next)
    {
        last = last->next;
    }
    last->next = node;
}

void __stdcall sub_004DD550_Emit(Room* room, Context* context, Tile* tile, unsigned int count, Cell* cells)
{
    for (unsigned int i = 0; i < count; ++i, tile = (Tile*)((unsigned char*)tile + 48))
    {
        sub_004DD550_AddFloor((Cell*)((unsigned char*)cells + 36 * i), room, context, tile);
    }
}

// build: context sub_B08_FillCellsInline
static void sub_B08_FillCellsInline(D2GridCellStrc* pCells)
{
    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            pCells->nB0 = 0xFF;
            pCells->nB1 = 0xFF;
            pCells->nB3 = 0xFF;
            pCells->nB2 = 0xFF;
            ++pCells;
        }
    }
}

// 0x004DDEF0
static void __stdcall sub_004DDEF0_BuildLargeGrid(int nX, int nY, int bFlat, D2GridCellStrc* pCells)
{
    if (bFlat)
    {
        const unsigned char nB0 = sub_0061C0E0(gpGlobal_007A0634);
        unsigned char nB1, nB2, nB3;
        sub_0061C0B0(gpGlobal_007A0634, &nB1, &nB2, &nB3);
        for (int j = 0; j < 8; ++j)
        {
            for (int i = 0; i < 8; ++i)
            {
                pCells->nB1 = nB1;
                pCells->nB0 = nB0;
                pCells->nB3 = nB3;
                pCells->nB2 = nB2;
                ++pCells;
            }
        }
        return;
    }

    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            sub_00475AA0(8 * (nX + i - 1), 8 * (nY + j - 1), &pCells->nB0, &pCells->nB1, &pCells->nB2, &pCells->nB3);
            ++pCells;
        }
    }
}

// build: context sub_B08_BuildSmallFlatGrid
static void __stdcall sub_B08_BuildSmallFlatGrid(int nX, int nY, int bCorners, D2GridCellStrc* pCells, int nMode)
{
    switch (nMode)
    {
    case 1:
        nX -= gnGlobal_0071146C / 4;
        break;
    case 2:
        nX += gnGlobal_0071146C / 4;
        break;
    }

    for (int j = 0; j < 6; ++j)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (!bCorners || ((i == 0 || i == 5) && (j == 0 || j == 5)))
            {
                pCells->nB0 = 0xFF;
                pCells->nX = 16 * (i - j) + nX;
                pCells->nY = nY + 8 * (i + j);
                pCells->nB1 = 0xFF;
                pCells->nB3 = 0xFF;
                pCells->nB2 = 0xFF;
            }
            ++pCells;
        }
    }
}

// 0x004DE190
static void __stdcall sub_004DE190_BuildSmallGrid(int nSubX, int nSubY, int nZ, int bCorners, D2GridCellStrc* pCells, int nMode)
{
    int nShift = 0;
    switch (nMode)
    {
    case 1:
        nShift = -(gnGlobal_0071146C / 4);
        break;
    case 2:
        nShift = gnGlobal_0071146C / 4;
        break;
    }

    for (int j = 0; j < 6; ++j)
    {
        const int nY = nSubY + j;
        for (int i = 0; i < 6; ++i, ++pCells)
        {
            if (!bCorners || (i == 0 && j == 0) || (i == 5 && j == 0) || (i == 5 && j == 5) || (i == 0 && j == 5))
            {
                sub_004F6760((nSubX + i) << 16, nY << 16, nZ, &pCells->nX, &pCells->nY);
                pCells->nX += nShift;
                pCells->nB0 = 0xFF;
                pCells->nB1 = 0xFF;
                pCells->nB3 = 0xFF;
                pCells->nB2 = 0xFF;
            }
        }
    }
}

// build: context D2GridLightStrc::sub_B08_ApplyUnitLight
void __thiscall D2GridLightStrc::sub_B08_ApplyUnitLight(D2GridUnitStrc* pUnit, int nArg, int nX, int nY, int nSubX, int nSubY)
{
    if (pUnit->dwFlags & 0x408)
    {
        return;
    }

    D2GridRectStrc* pRect = &pOwner->tRect;
    D2_ASSERT(pRect, 0x76);
    if (nX < pRect->nLeft || nX >= pRect->nRight || nY < pRect->nTop || nY >= pRect->nBottom)
    {
        return;
    }

    D2GridInfoStrc* pInfo = pUnit->pInfo;
    if (pInfo->nBusy)
    {
        return;
    }

    D2GridCellStrc tLarge[8 * 8];
    D2GridCellStrc tSmall[6 * 6];
    if (sub_00477730() < 4)
    {
        if (pInfo->wFlags & 0x100)
        {
            sub_B08_FillCellsInline(tLarge);
        }
        else
        {
            sub_004DDEF0_BuildLargeGrid(nSubX, nSubY, 0, tLarge);
        }
        sub_004F68E0(pUnit->pInfo, tLarge, nX, nY, nSubX, nSubY, 0xFF, nMode, nArg);
    }
    else
    {
        if (bSmall)
        {
            if (pInfo->wFlags & 0x100)
            {
                sub_004DE190_BuildSmallGrid(nSubX, nSubY, 0, bCorners, tSmall, nMode);
            }
            else
            {
                sub_004DE260(tSmall, nSubX, nSubY, 0, nMode, bCorners);
            }
        }
        else
        {
            if (pInfo->wFlags & 0x100)
            {
                sub_B08_BuildSmallFlatGrid(nX, nY, bCorners, tSmall, nMode);
            }
            else
            {
                sub_004DE070(tSmall, nX, nY, nSubX, nSubY, 0, nMode, bCorners);
            }
        }
        sub_004F68E0(pUnit->pInfo, tSmall, nX, nY, nSubX, nSubY, 0xFF, nMode, nArg);
    }

    if (pInfo->wFlags & 2)
    {
        const int nRoll = sub_00472280(f_1C, 0, 1000);
        const int nFixX = nSubX << 16;
        const int nFixY = nSubY << 16;
        if (bEffectA && nRoll < nLimitA)
        {
            sub_00472DA0(nX, nY, nFixX, nFixY);
        }
        if (bEffectB && nRoll < 100)
        {
            sub_00472EC0(nX, nY, nFixX, nFixY);
        }
    }

    sub_004DDE80_UpdateBounds(pUnit, nSubX, nSubY);
}
