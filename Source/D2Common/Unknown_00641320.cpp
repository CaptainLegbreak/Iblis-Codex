#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"

struct D2GfxLightStrc;
struct D2BinFieldStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2MissilesTxt;
struct D2StatesTxt;
struct D2MissileStrc;
struct D2DrlgCoordsStrc;
struct D2PlayerDataStrc;

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
extern void* gpShrinesTxt; // 0x0096D468







typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390
void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0
void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0
int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
int __cdecl D2GFX_IsHardwareRenderMode(); // 0x004F51C0


int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile); // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730
int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel); // 0x00663270
unsigned int __stdcall sub_00620510(D2UnitStrc*); // 0x00620510
extern int gnUnitDistanceTable[64]; // 0x006EB180
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510


void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc*,void*);
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,int*); // 0x00619790
// build: symbol ?SKILLS_IsPointNearRoom@* 0x004C5BD0
static int SKILLS_IsPointNearRoom(D2ActiveRoomStrc*,int,int,int); // 0x00641930
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0


void __fastcall PLAYER_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2); // 0x00460780

// 0x00641320
void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Code", 4, 0, 0, 0 },
        { "Arg0", 2, 0, 4, 0 },
        { "Arg1", 2, 0, 8, 0 },
        { "Duration in frames", 2, 0, 12, 0 },
        { "reset time in minutes", 4, 0, 16, 0 },
        { "rarity", 4, 0, 17, 0 },
        { "view name", 1, 31, 18, 0 },
        { "niftyphrase", 1, 127, 50, 0 },
        { "effectclass", 4, 0, 178, 0 },
        { "LevelMin", 2, 0, 180, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpShrinesTxt = DATATBLS_CompileTxt(hArchive, "shrines", pTbl, &gnShrinesTxtRecordCount, 184);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }
    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

static inline int SizeDifference(D2UnitStrc* a,D2UnitStrc* b)
{
 const unsigned int first=sub_00620510(a)/2;
 const unsigned int second=sub_00620510(b)/2;
 int value=first+second;
 return value<0 ? -value:value;
}

// 0x00641530
int __stdcall sub_00641530(D2UnitStrc* a,D2UnitStrc* b)
{
 const int rawX=CLIENTS_GetUnitXInline(b)-CLIENTS_GetUnitXInline(a);
 int dx=rawX>=0 ? rawX : -rawX;
 int dy=CLIENTS_GetUnitYInline(b)-CLIENTS_GetUnitYInline(a);
 if(dy<0) dy=-dy;
 const int sizeA=sub_00620510(a);
 const int sizeB=sub_00620510(b);
 if(dx<8 && dy<8 && sizeA<4 && sizeB<4) {
  int distance=gnUnitDistanceTable[dx+8*dy];
  if(distance<0) return 0;
  if(sizeA==3 || sizeB==3) --distance;
  if(distance<0) distance=0;
  if(sizeA<=1 || sizeB<=1) ++distance;
  return distance;
 }
 dx-=SizeDifference(a,b);
 dy-=SizeDifference(a,b);
 if(dx<0) dx=0;
 if(dy<0) dy=0;
 return dx>dy ? dy+2*dx : dx+2*dy;
}

#include "gen/data/Source/D2Common/Unknown_00641320.inc"

inline int UNITS_InlineGetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_InlineGetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x006416D0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    int nX = UNITS_InlineGetX(pOther) - UNITS_InlineGetX(pUnit);
    int nXDiff = nX >= 0 ? nX : -nX;
    int nY = UNITS_InlineGetY(pOther) - UNITS_InlineGetY(pUnit);
    int nYDiff = nY < 0 ? -nY : nY;

    int nSize1 = UNITS_GetUnitSizeX(pUnit);
    int nSize2 = UNITS_GetUnitSizeX(pOther);
    nXDiff = nXDiff - nSize1 / 2 - nSize2 / 2;
    nYDiff = nYDiff - nSize1 / 2 - nSize2 / 2;

    if (nXDiff < 0)
    {
        nXDiff = 0;
    }

    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    return (nXDiff > nYDiff ? nYDiff + 2 * nXDiff : nXDiff + 2 * nYDiff) / 2;
}

static inline int UNITS_ApproxDistance(int nXDiff, int nYDiff)
{
    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

// 0x006417F0
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY)
{
    int nDX = nX - UNITS_InlineGetX(pUnit);
    int nXDiff = nDX < 0 ? -nDX : nDX;
    int nDY = nY - UNITS_InlineGetY(pUnit);
    int nYDiff = nDY < 0 ? -nDY : nDY;

    if (nXDiff < 0)
    {
        nXDiff = 0;
    }

    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    return UNITS_ApproxDistance(nXDiff, nYDiff);
}

static inline int U04_IsNearRoomY(const D2DrlgCoordsStrc* pCoords, int nY, int nRadius)
{
    return nY + nRadius >= pCoords->nSubtileY || nY - nRadius <= pCoords->nSubtileHeight + pCoords->nSubtileY;
}

// 0x00641930
static int SKILLS_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (nX + nRadius >= tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    if (nX - nRadius <= tCoords.nSubtileWidth + tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    return 0;
}

int __fastcall sub_U04_Emit_00641930(D2ActiveRoomStrc** ppRooms, int nCount, int nX, int nY)
{
    for (int i = 0; i < nCount; ++i)
    {
        if (SKILLS_IsPointNearRoom(ppRooms[i], nX, nY, 2))
        {
            return i;
        }
    }
    return -1;
}

static inline int IsNearRoomY(const D2DrlgCoordsStrc* pCoords,int nY,int nRadius) {
 return nY+nRadius>=pCoords->nSubtileY || nY-nRadius<=pCoords->nSubtileHeight+pCoords->nSubtileY;
}

inline int GetX(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return pUnit->pStaticPath->nXPos;}
 return pUnit->pDynamicPath?PATH_GetXPosition(pUnit->pDynamicPath):0;
}

inline int GetY(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return pUnit->pStaticPath->nYPos;}
 return pUnit->pDynamicPath?PATH_GetYPosition(pUnit->pDynamicPath):0;
}

inline int D2_ABS(int n) { return n < 0 ? -n : n; }

// 0x006419A0
static int DRLG_IsUnitAlive(D2UnitStrc* pUnit) {
 if(!pUnit) return 0;
 switch(pUnit->dwUnitType) {
 case UNIT_PLAYER:
  if(pUnit->dwAnimMode==PLRMODE_DEATH || pUnit->dwAnimMode==PLRMODE_DEAD) return 0;
  return 1;
 case UNIT_MONSTER:
  if(pUnit->dwAnimMode==MONMODE_DEATH || pUnit->dwAnimMode==MONMODE_DEAD) return 0;
  return 1;
 case UNIT_OBJECT: return 0;
 case UNIT_MISSILE: return 1;
 case UNIT_ITEM: return 0;
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
  if(!SKILLS_IsPointNearRoom(ppRooms[i],nX,nY,2)) continue;
  for(D2UnitStrc* pUnit=ppRooms[i]->pUnitFirst;pUnit;pUnit=pUnit->ptRoomNext) {
   if(!DRLG_IsUnitAlive(pUnit)) continue;
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
    // volatile: the original reads the coordinates from their stack slots here
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

inline D2PlayerDataStrc* UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x00641F20
void __fastcall UNITS_SetInteractData(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        if (D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit))
        {
            pPlayerData->nState = 1;
        }

        PLAYER_SetPlayerMode(nMode, pUnit, nArg1, nArg2);
    }
}

// 0x006432C0
void __stdcall DUNGEON_ClientToGameTileCoords(int* pX, int* pY)
{
    const int nX = *pX;
    const int nY = *pY;
    *pX = (2 * nY + nX) / 160;
    *pY = (2 * nY - nX) / 160;
}
