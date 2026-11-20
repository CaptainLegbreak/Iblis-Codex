#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

#define UF_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitFindArgStrc;
struct D2FieldStrc;
struct D2UnitFindDataStrc;
struct D2StaticPathStrc;
struct D2MissilesTxt;
struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2DrlgCoordsStrc;
struct UnitFindArgStrc;


struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

typedef int(__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit, D2UnitFindArgStrc* pUnitFindArg);

struct D2UnitFindDataStrc
{
    void* pMemPool;
    D2UnitStrc** pUnitsArray;
    D2ActiveRoomStrc* pRoom;
    UNITFINDTEST pfnUnitTest;
    D2UnitFindArgStrc* pUnitFindArg;
    int nIndex;
    int nFlags;
    int nMaxArrayEntries;
    int nX;
    int nY;
    int nSize;
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* pfn); // 0x006CC34C
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480


typedef int (__fastcall* UnitFilter)(D2UnitStrc*,D2UnitFindArgStrc*);

struct D2UnitFindArgStrc { unsigned int flags; int unk_04; D2UnitStrc* ignored; int x; int y; int radius; int maximum; int count; D2FieldStrc* field; UnitFilter filter; };

struct D2MissilesTxt { char unk_00[4]; unsigned char flags; };

extern const unsigned char gMissileMask_006CE26C; // 0x006CE26C
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
int __stdcall MONSTERS_IsUndead(D2UnitStrc*); // 0x0063E990
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int); // 0x0046ACE0
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc*,int); // 0x00451F30
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc*); // 0x0061AB00
int __stdcall D2Common_11098(D2FieldStrc*,int*,int*); // 0x0066A5D0
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc*,int,int,unsigned short); // 0x0064CB30

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

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

struct UnitFindArgStrc
{
    unsigned char unk0x00[0x20];
    int nX;
    int nY;
    int nRange;
};

inline int UnitGetType(D2UnitStrc* pUnit) { return pUnit ? pUnit->dwUnitType : 6; }

inline int UnitGetClassId(D2UnitStrc* pUnit) { return pUnit ? pUnit->dwClassId : -1; }

// 0x0065A590
int __stdcall UNITFINDS_AreUnitsInNeighboredRooms(D2UnitStrc* pDestUnit, D2UnitStrc* pSrcUnit)
{
    UF_ASSERT(pDestUnit, 24);
    UF_ASSERT(pSrcUnit, 25);

    D2ActiveRoomStrc* pSrcRoom = UNITS_GetRoom(pSrcUnit);
    if (pSrcRoom)
    {
        D2ActiveRoomStrc* pDestRoom = UNITS_GetRoom(pDestUnit);
        if (pDestRoom)
        {
            D2ActiveRoomStrc** ppRoomList;
            int nNumRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pSrcRoom, &ppRoomList, &nNumRooms);

            for (int i = 0; i < nNumRooms; ++i)
            {
                if (ppRoomList[i] == pDestRoom)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

static inline int UNITS_GetUnitTypeOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int UNITS_GetClassIdOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x0065A620
D2UnitStrc* __stdcall sub_0065A620_FindUnitInAdjacentRooms(D2ActiveRoomStrc* hRoom, int nUnitType, int nClassId)
{
    D2_ASSERT(hRoom, 0x31);
    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(hRoom, &ppRoomList, &nNumRooms);
    for (int i = 0; i < nNumRooms; ++i)
    {
        D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst;
        while (pUnit)
        {
            if (UNITS_GetUnitTypeOrInvalid_Inline(pUnit) == nUnitType && UNITS_GetClassIdOrInvalid_Inline(pUnit) == nClassId)
            {
                return pUnit;
            }
            pUnit = pUnit->pRoomNext;
        }
    }
    return 0;
}

// 0x0065A710
static int __stdcall sub_0065A710_IsInRoomRange(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRange)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    if (nX + nRange >= tCoords.nSubtileX)
    {
        if (nY + nRange >= tCoords.nSubtileY || nY - nRange <= tCoords.nSubtileY + tCoords.nSubtileHeight)
            return 1;
    }
    else if (nX - nRange <= tCoords.nSubtileX + tCoords.nSubtileWidth)
    {
        if (nY + nRange >= tCoords.nSubtileY || nY - nRange <= tCoords.nSubtileY + tCoords.nSubtileHeight)
            return 1;
    }
    return 0;
}

// 0x0065A790
int __stdcall UNITFINDS_GetTestedUnitsFromRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc** ppUnits, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg)
{
    int nUnitIndex = 0;
    D2UnitStrc* pUnit = pRoom->pUnitFirst;

    D2_ASSERT(!IsBadCodePtr((int (__stdcall*)())pfnUnitTest), 114);

    for (; pUnit; pUnit = pUnit->pRoomNext)
    {
        if (pfnUnitTest(pUnit, pUnitFindArg))
        {
            ppUnits[nUnitIndex] = pUnit;
            ++nUnitIndex;

            D2_ASSERT(nUnitIndex < 15, 120);
        }
    }

    return nUnitIndex;
}

// 0x0065A950
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg)
{
    D2_ASSERT(pUnitFindData, 226);

    pUnitFindData->pUnitsArray = (D2UnitStrc**)FOG_AllocPool(pMemPool, sizeof(D2UnitStrc*) * 15, ".\\UNITS\\UnitFinds.cpp", 228, 0);
    D2_ASSERT(pUnitFindData->pUnitsArray, 229);
    memset(pUnitFindData->pUnitsArray, 0, sizeof(D2UnitStrc*) * 15);

    pUnitFindData->pRoom = pRoom;
    pUnitFindData->nX = nX;
    pUnitFindData->nY = nY;
    pUnitFindData->pMemPool = pMemPool;
    pUnitFindData->nMaxArrayEntries = 15;
    pUnitFindData->nFlags = 0;
    pUnitFindData->nIndex = 0;
    pUnitFindData->nSize = nSize;
    pUnitFindData->pfnUnitTest = pfnUnitTest;
    pUnitFindData->pUnitFindArg = pUnitFindArg;
}

// 0x0065AA00
void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData)
{
    if (pUnitFindData && pUnitFindData->pUnitsArray)
    {
        FOG_FreePool(pUnitFindData->pMemPool, pUnitFindData->pUnitsArray, ".\\UNITS\\UnitFinds.cpp", 255, 0);
        pUnitFindData->pUnitsArray = 0;
    }
}

static __forceinline int GetX(D2UnitStrc* unit) {
 switch(unit->dwUnitType) {case 2:case 4:case 5:return unit->pStaticPath->nXPos;default:return unit->pDynamicPath ? PATH_GetXPosition(unit->pDynamicPath):0;}
}

static __forceinline int GetY(D2UnitStrc* unit) {
 switch(unit->dwUnitType) {case 2:case 4:case 5:return unit->pStaticPath->nYPos;default:return unit->pDynamicPath ? PATH_GetYPosition(unit->pDynamicPath):0;}
}

// 0x0065AA40
int __stdcall UNITFINDS_TestUnit(D2UnitStrc* unit,D2UnitFindArgStrc* args)
{
 if(!args) return 0;
 if((args->flags&64) && args->count>=args->maximum) return 0;
 int x=GetX(unit);int y=GetY(unit);
 int dx=x-args->x;int dy=y-args->y;
 if(dx*dx+dy*dy>args->radius*args->radius) return 0;
 switch(unit->dwUnitType) {
  case 0: {
   if(!(args->flags&1))return 0;
   int mode=unit->dwAnimMode;
   if(args->flags&4096) {if(mode!=17)return 0;} else if(mode==17 || mode==0)return 0;
   if(unit==args->ignored)return 0;
   } break;
  case 1: {
   if(!(args->flags&2))return 0;
   int mode=unit->dwAnimMode;
   if(args->flags&4096) {if(mode!=12)return 0;} else if(mode==12 || mode==0)return 0;
   if((args->flags&4) && !MONSTERS_IsUndead(unit))return 0;
   } break;
  case 2:if(!(args->flags&16))return 0;break;
  case 3: {
   if(!(args->flags&8))return 0;
   D2MissilesTxt* record=DATATBLS_GetMissilesTxtRecord(unit->dwClassId);
   if(!record || (record->flags&gMissileMask_006CE26C))return 0;
   break;
  }
  case 4:if(!(args->flags&32))return 0;break;
  default:return 0;
 }
 unsigned int flags=args->flags;
 if((flags&128) && !sub_00451F30_TestUnitFlag(unit,4))return 0;
 if((flags&1024) && !sub_00451F30_TestUnitFlag(unit,8))return 0;
 if((flags&256) && DUNGEON_IsRoomInTown(UNITS_GetRoom(unit)))return 0;
 if(args->flags&512) {
  D2ActiveRoomStrc* room=UNITS_GetRoom(unit);
  if(room) {
   while(D2Common_11098(args->field,&x,&y)) {
    if(COLLISION_CheckMask(room,x,y,4)==4)return 0;
   }
  }
 }
 if((args->flags&2048) && args->filter(unit,args))return 0;
 ++args->count;
 return 1;
}

// build: context sub_0065A710_Shim
// calling-convention shim (not game code)
int __stdcall sub_0065A710_Shim(UnitFindArgStrc* pArg, D2ActiveRoomStrc** ppRooms, int nRooms)
{
    int nCount = 0;
    for (int i = 0; i < nRooms; ++i)
    {
        if (sub_0065A710_IsInRoomRange(ppRooms[i], pArg->nX, pArg->nY, pArg->nRange))
            ++nCount;
    }
    return nCount;
}
