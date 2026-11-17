struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2UnitStrc;
struct D2ItemDropStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed;
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

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2ObjectsTxt
{
    char unk0x00[0xD0];
    unsigned int dwSizeX;
    unsigned int dwSizeY;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, int nSizeX, int nSizeY, int nMask); // 0x0064D800
D2UnitStrc* __fastcall ITEMS_DropRandomItemAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDrop); // 0x00559130
extern int gnArmorStandOrRackIds_00731EA0[];                                                                // 0x00731EA0
extern int gnArmorStandOrRackCount_00731EB0;                                                                // 0x00731EB0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
void __stdcall sub_00551150_SpawnFlies(D2GameStrc* pGame, D2UnitStrc* pObject);                            // 0x00551150

struct D2CoordInitStrc
{
    D2CoordStrc* pCoords;
    int nCount;
};

extern D2CoordInitStrc gaCoordInit_00731EB4[];                                                              // 0x00731EB4
extern int gnCoordInitCount_00731E64;                                                                       // 0x00731E64

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

static __forceinline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    }
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

static int __stdcall sub_005502F0_CanPlaceSmallObject(D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY, D2CoordStrc* pCoord, D2DrlgCoordsStrc* pDrlgCoords)
{
    if (pDrlgCoords->nSubtileWidth < 2 || pDrlgCoords->nSubtileHeight < 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 2
        && pDrlgCoords->nSubtileY + 2 < (unsigned short)pCoord->nY
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileX - nSizeX + pDrlgCoords->nSubtileWidth
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileY - nSizeY + pDrlgCoords->nSubtileHeight
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 2, nSizeY + 2, 0x3F11))
    {
        return 1;
    }
    return 0;
}

__declspec(noinline) static int __stdcall sub_00550220_CanPlaceObject(D2ActiveRoomStrc*,int,D2DrlgCoordsStrc*,D2CoordStrc*,int);
static int __stdcall sub_00550220_CanPlaceObject(D2ActiveRoomStrc*,int,D2DrlgCoordsStrc*,D2CoordStrc*,int); // 0x00550220
// 0x00550220
static int __stdcall sub_00550220_CanPlaceObject(D2ActiveRoomStrc* pRoom, int nSizeY, D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, int nSizeX)
{
    if (pDrlgCoords->nSubtileWidth < nSizeX + 2 || pDrlgCoords->nSubtileHeight < nSizeY + 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 1
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 1
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileX - nSizeX + pDrlgCoords->nSubtileWidth - 2
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileY - nSizeY + pDrlgCoords->nSubtileHeight - 2
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 7, nSizeY + 7, 0xC01)
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX, nSizeY, 0x3F11))
    {
        return 1;
    }
    return 0;
}

struct D2UnitStrc { char pad0[0x10]; int nMode; };
struct D2ObjOperateFnStrc { D2GameStrc* game;D2UnitStrc* object;D2ActiveRoomStrc* room;D2SeedStrc* seed;int unk10,x,y; };
extern int gaDirectionX_00731B7C[]; // 0x00731B7C
extern int gaDirectionY_00731B9C[]; // 0x00731B9C
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc*,D2ActiveRoomStrc*,int,int,int,int,int,int); // 0x005B2F20
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
// 0x005506D0
void __fastcall sub_005506D0_Populate(D2ObjOperateFnStrc* op)
{
    if(op->object && op->object->nMode) return;
    D2DrlgCoordsStrc room;
    DUNGEON_GetRoomCoordinates(op->room,&room);
    D2ObjectControlStrc* control=OBJRGN_GetObjectControlFromGame(op->game,op->room);
    int nTries=12;
    int count=30*((room.nSubtileWidth*room.nSubtileHeight)>>7)>>8;
    int distance=5;
    while(count>0) {
        if(nTries<=0) break;
        D2CoordStrc xy;
        xy.nX=room.nSubtileX+OBJECTS_RollLimited_Inline(&control->pSeed,room.nSubtileWidth-4);
        xy.nY=room.nSubtileY+OBJECTS_RollLimited_Inline(&control->pSeed,room.nSubtileHeight-4);
        D2CoordStrc coord;coord.nX=xy.nX;coord.nY=xy.nY;
        if(sub_00550220_CanPlaceObject(op->room,3,&room,&coord,3)==1) {
            unsigned int random=SEED_RollRandomNumber(op->seed);
            int monsterId=403;
            if(random&1) monsterId=404;
            if(D2GAME_SpawnMonster_6FC69F10(op->game,op->room,op->x,op->y,monsterId,1,-1,0)) {
                UNITS_ChangeAnimMode(op->object,2);--count;
            }
            int spawned=1;
            int placed=1;
            while(!OBJECTS_RollLimited_Inline(&control->pSeed,spawned>>1) && placed) {
                int tries=0;
                placed=0;
                int maximum=3*(count<4 ? 4 : count);
                while(!placed) {
                    if(tries>=maximum) break;
                    int direction=OBJECTS_RollLimited_Inline(&control->pSeed,8);
                    xy.nX+=2*(OBJECTS_RollLimited_Inline(&control->pSeed,distance)+distance)*gaDirectionX_00731B7C[direction];
                    xy.nY+=2*(OBJECTS_RollLimited_Inline(&control->pSeed,distance)+distance)*gaDirectionY_00731B9C[direction];
                    coord.nX=xy.nX;coord.nY=xy.nY;
                    placed=sub_00550220_CanPlaceObject(op->room,3,&room,&coord,3);
                    ++tries;
                }
                if(placed) {
                    unsigned int random=SEED_RollRandomNumber(op->seed);
                    int monsterId=403;
                    if(random&1) monsterId=404;
                    ++spawned;
                    if(D2GAME_SpawnMonster_6FC69F10(op->game,op->room,xy.nX,xy.nY,monsterId,1,-1,0)) {
                        UNITS_ChangeAnimMode(op->object,2);--count;
                    }
                }
            }
        }
        --nTries;
    }
}

#include "gen/data/Source/D2Game/005506D0_sub_005506D0_Populate.inc"
