struct D2UnitStrc;
struct D2ActiveRoomStrc { char unk_00[0x74]; D2UnitStrc* pUnitFirst; };
struct D2DynamicPathStrc;
struct D2StaticPathStrc { char unk_00[12]; int nX; int nY; };
struct D2UnitStrc {
 int dwUnitType; int dwClassId; char unk_08[8]; int dwAnimMode;
 char unk_14[0x18]; union { D2DynamicPathStrc* pDynamicPath; D2StaticPathStrc* pStaticPath; };
 char unk_30[0xB8]; D2UnitStrc* pRoomNext;
};
struct D2DrlgCoordsStrc { int nSubtileX,nSubtileY,nSubtileWidth,nSubtileHeight,nTileX,nTileY,nTileWidth,nTileHeight; };
typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc*,void*);
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*,D2DrlgCoordsStrc*); // 0x00619730
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,int*); // 0x00619790
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
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
inline int GetX(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case 2:case 4:case 5:return pUnit->pStaticPath->nX;}
 return pUnit->pDynamicPath?PATH_GetXPosition(pUnit->pDynamicPath):0;
}
inline int GetY(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case 2:case 4:case 5:return pUnit->pStaticPath->nY;}
 return pUnit->pDynamicPath?PATH_GetYPosition(pUnit->pDynamicPath):0;
}
inline int D2_ABS(int n) { return n < 0 ? -n : n; }

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
// 0x006419A0
static int sub_006419A0_IsUnitAlive(D2UnitStrc* pUnit) {
 if(!pUnit) return 0;
 switch(pUnit->dwUnitType) {
 case 0:
  if(pUnit->dwAnimMode==0 || pUnit->dwAnimMode==17) return 0;
  return 1;
 case 1:
  if(pUnit->dwAnimMode==0 || pUnit->dwAnimMode==12) return 0;
  return 1;
 case 2: return 0;
 case 3: return 1;
 case 4: return 0;
 default: return 0;
 }
}
// 0x006419F0
D2UnitStrc* __stdcall D2Common_10406(D2UnitStrc* pSource,D2UnitFindCallback pCallback,void* pArg) {
 int nSize=UNITS_GetUnitSizeX(pSource);
 if(nSize<1 || nSize>3) return 0;
 int nSizeIndex=3*(nSize-1);
 D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pSource);
 if(!pRoom) return 0;
 int nX=CLIENTS_GetUnitX(pSource);
 int nY=CLIENTS_GetUnitY(pSource);
 D2ActiveRoomStrc** ppRooms;
 int nRooms;
 DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRooms,&nRooms);
 for(int i=0;i<nRooms;++i) {
  if(!sub_00641930_IsPointNearRoom(ppRooms[i],nX,nY,2)) continue;
  for(D2UnitStrc* pUnit=ppRooms[i]->pUnitFirst;pUnit;pUnit=pUnit->pRoomNext) {
   if(!sub_006419A0_IsUnitAlive(pUnit)) continue;
   int nUnitSize=UNITS_GetUnitSizeX(pUnit);
   if(nUnitSize>=3) nUnitSize=3;
   else if(nUnitSize<=0) continue;
   int nUnitX=GetX(pUnit);
   int nUnitY=GetY(pUnit);
   int bInRange=0;
   switch(nSizeIndex+nUnitSize) {
   case 1:
    if(nX==nUnitX && nY==nUnitY) { if(pUnit!=pSource && pCallback(pUnit,pArg)) return pUnit; }
    break;
   case 2: case 4:
    if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=1) bInRange=1;
    break;
   case 3: case 7: {
    const int rangeX=*(const volatile int*)&nX;
    if(rangeX>=nUnitX-1 && rangeX<=nUnitX+1) {
     const int rangeY=*(const volatile int*)&nY;
     if(rangeY>=nUnitY-1 && rangeY<=nUnitY+1) bInRange=1;
    }
    break;
   }
   case 5:
    if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=2) bInRange=1;
    break;
   case 6: {
    int dx=D2_ABS(nX-nUnitX); int dy=D2_ABS(nY-nUnitY);
    if((dx<=2 && dy<=1) || (dy<=2 && dx<=1)) bInRange=1;
    break;
   }
   case 8: {
    int dx=D2_ABS(nX-nUnitX); int dy=D2_ABS(nY-nUnitY);
    if((dx<=2 && dy<=1) || (dy<=2 && dx<=1)) bInRange=1;
    break;
   }
   case 9: {
    const int rangeX=*(const volatile int*)&nX;
    if(rangeX>=nUnitX-2 && rangeX<=nUnitX+2) {
     const int rangeY=*(const volatile int*)&nY;
     if(rangeY>=nUnitY-2 && rangeY<=nUnitY+2) bInRange=1;
    }
    break;
   }
   default: break;
   }
   if(bInRange && pUnit!=pSource && pCallback(pUnit,pArg)) return pUnit;
  }
 }
 return 0;
}
