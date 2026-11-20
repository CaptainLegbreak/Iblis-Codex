#include "D2Game.h"
#include "D2Structs.h"

struct D2GfxLightStrc;

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nX;
    int nY;
};


struct D2SkillsTxt
{
    char unk0x000[0x48];
    short wSrvMissileA;
    char pad4A[0x1A];
    int dwAuraRangeCalc;
    char unk0x068[0xAC];
    int dwCltCalc[3];
    char unk0x120[0x18];
    int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2MissilesTxt
{
    char unk0x000[0x38];
    int dwParam[5];
    char pad4C[0x0C];
    int dwCltParam[5];
    char unk0x06C[0x138];
};

struct D2StatesTxt
{
    char unk0x00[0x20];
    unsigned char nColorPri;
    unsigned char nColorShift;
    unsigned char nLightRGB[3];
    char unk0x25[0x17];
};

struct D2DataTablesStrc
{
    char unk0x000[0xBC];
    D2StatesTxt* pStatesTxt;
    char unk0x0C0[0x04];
    int nStatesTxtRecordCount;
    char unk0x0C8[0xA9C];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

struct D2MissileStrc
{
    unsigned int dwFlags;
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    D2UnitStrc* pTarget;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int nLoops;
    int unk0x38;
    int unk0x3C;
    int nFrame;
    int nActivateFrame;
    int nAttBonus;
    int nRange;
    int nLightRadius;
    MissileInitFunc pInitFunc;
    int nInitArg;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __fastcall sub_00465C60_CheckUnitPair(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
void __fastcall sub_00474390_SetRecordBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390
void __fastcall sub_00480420_RefreshPathTarget(D2UnitStrc* pUnit);                                          // 0x00480420
int __fastcall sub_004C52E0_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __fastcall sub_004C70D0_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0
void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile, int nArg);                                // 0x004E2ED0
int __fastcall sub_004F21B0_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId);                               // 0x004F21B0
int __cdecl sub_004F51C0_IsHighVideoMode();                                                                 // 0x004F51C0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0
int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

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

__forceinline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

__forceinline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}
D2UnitStrc* __fastcall sub_0059FA30(D2GameStrc*,D2MissileStrc*);  // 0x0059FA30
extern int data_006E31E8[16],data_006E31A8[16];  // 0x006E31A8
// build: symbol ?data_006E31E8@@3PAHA 0x006E31E8
// 0x005CCD10
int __fastcall sub_005CCD10(D2GameStrc* game,D2UnitStrc* unit,int skill,int level)
{
 D2MissileStrc params;
 D2SkillsTxt* record=SKILLS_GetSkillsTxtRecord(skill);
 if(!record) return 0;
 const int missileId=record->wSrvMissileA;
 D2MissilesTxt* missileRecord=SKILLS_GetMissilesTxtRecord(missileId);
 if(missileRecord) {
  if(unit) unit->dwFlags|=0x40;
  memset(&params,0,sizeof(params));
  params.dwFlags=31;
  params.pOwner=unit;
  params.pOrigin=unit;
  params.nMissile=missileId;
  params.nX=UNITS_GetXPosition(unit);
  params.nY=CLIENTS_GetUnitY(unit);
  params.nSkillLevel=level;
  params.nLoops=SKILLS_EvaluateSkillFormula(unit,record->dwCalc[0],skill,level);
  params.nVelocity=missileRecord->dwParam[0]<<6;
  int step=SKILLS_EvaluateSkillFormula(unit,record->dwCalc[1],skill,level);
  if(step<1) step=1;
  for(int i=0;i<16;i+=2) {
   params.nTargetX=data_006E31E8[i];
   params.nTargetY=data_006E31A8[i];
   sub_0059FA30(game,&params);
  }
  params.nVelocity=missileRecord->dwParam[1]<<6;
  if(step>1) {
   for(int i=0;i<15;i+=step) {
    params.nTargetX=data_006E31E8[i+1];
    params.nTargetY=data_006E31A8[i+1];
    sub_0059FA30(game,&params);
   }
  }
  return 1;
 }
 return 0;
}

#include "gen/data/Source/D2Game/SKILLS/SkillMonst_005CCD10.inc"
