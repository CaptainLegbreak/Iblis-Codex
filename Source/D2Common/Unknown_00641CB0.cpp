#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"

struct D2ActiveRoomStrc { char unk_00[0x74]; D2UnitStrc* pUnitFirst; };
struct D2DrlgCoordsStrc { int nSubtileX,nSubtileY,nSubtileWidth,nSubtileHeight,nTileX,nTileY,nTileWidth,nTileHeight; };
typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc*,void*);
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*,D2DrlgCoordsStrc*); // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,int*); // 0x00619790
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
// build: context IsNearRoomY
static __forceinline int IsNearRoomY(const D2DrlgCoordsStrc* pCoords,int nY,int nRadius) {
 return nY+nRadius>=pCoords->nSubtileY || nY-nRadius<=pCoords->nSubtileHeight+pCoords->nSubtileY;
}
static int sub_00641930_IsPointNearRoom(D2ActiveRoomStrc*,int,int,int); // 0x00641930
// 0x00641930
static int sub_00641930_IsPointNearRoom(D2ActiveRoomStrc* pRoom,int nX,int nY,int nRadius) {
 D2DrlgCoordsStrc tCoords;
 DUNGEON_GetRoomCoordinates(pRoom,&tCoords);
 if(nX+nRadius>=tCoords.nSubtileX) return IsNearRoomY(&tCoords,nY,nRadius);
 if(nX-nRadius<=tCoords.nSubtileWidth+tCoords.nSubtileX) return IsNearRoomY(&tCoords,nY,nRadius);
 return 0;
}
// build: context GetX
inline int GetX(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case 2:case 4:case 5:return pUnit->pStaticPath->nXPos;}
 return pUnit->pDynamicPath?PATH_GetXPosition(pUnit->pDynamicPath):0;
}
// build: context GetY
inline int GetY(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case 2:case 4:case 5:return pUnit->pStaticPath->nYPos;}
 return pUnit->pDynamicPath?PATH_GetYPosition(pUnit->pDynamicPath):0;
}
// build: context D2_ABS
inline int D2_ABS(int n) { return n < 0 ? -n : n; }
// build: context IsTarget
static __forceinline int IsTarget(D2UnitStrc* pUnit) {
 switch(pUnit ? pUnit->dwUnitType : 6) {
 case 0: return pUnit->dwAnimMode!=0 && pUnit->dwAnimMode!=17;
 case 1: return pUnit->dwAnimMode!=0 && pUnit->dwAnimMode!=12;
 case 2: return 0;
 case 3: return 1;
 case 4: return 0;
 }
 return 0;
}
// 0x00641CB0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom,int nX,int nY,D2UnitFindCallback pCallback,void* pArg,int nSize) {
 if(!pRoom) return 0;
 if(nSize<1 || nSize>3) return 0;
 nSize=(nSize-1)*3;
 D2ActiveRoomStrc** ppRoomList;
 int nRooms;
 DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRoomList,&nRooms);
 for(int i=0;i<nRooms;++i) {
  if(!sub_00641930_IsPointNearRoom(ppRoomList[i],nX,nY,2)) continue;
  for(D2UnitStrc* pUnit=ppRoomList[i]->pUnitFirst;pUnit;pUnit=pUnit->pRoomNext) {
   if(IsTarget(pUnit)) {
    int nUnitSize=UNITS_GetUnitSizeX(pUnit);
    if(nUnitSize>=3) nUnitSize=3;
    else if(nUnitSize<=0) continue;
    int nUnitX=GetX(pUnit);
    int nUnitY=GetY(pUnit);
    int bInRange=0;
    switch(nSize+nUnitSize) {
    case 1:
     if(nX==nUnitX && nY==nUnitY) { if(pCallback(pUnit,pArg)) return pUnit; }
     break;
    case 2: case 4:
     if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=1) bInRange=1;
     break;
    case 3: case 7:
     if(nX>=nUnitX-1 && nX<=nUnitX+1 && nY>=nUnitY-1 && nY<=nUnitY+1) bInRange=1;
     break;
    case 5:
     if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=2) bInRange=1;
     break;
    case 6: case 8: {
     int dx=D2_ABS(nX-nUnitX); int dy=D2_ABS(nY-nUnitY);
     if((dx<=2 && dy<=1) || (dy<=2 && dx<=1)) bInRange=1;
     break;
    }
    case 9:
     if(nX>=nUnitX-2 && nX<=nUnitX+2 && nY>=nUnitY-2 && nY<=nUnitY+2) bInRange=1;
     break;
    default: break;
    }
    if(bInRange && pCallback(pUnit,pArg)) return pUnit;
   }
  }
 }
 return 0;
}
