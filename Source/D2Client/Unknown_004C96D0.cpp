#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
struct D2ByteRecordStrc;
struct D2UnitStrc;

struct D2GfxLightStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct D2MissilesTxt;
struct D2StatesTxt;
struct D2MissileStrc;







typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
void __fastcall SCMD_SetLightColorBytes(D2ByteRecordStrc* pRecord, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390
void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0
void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0
int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall sub_0064A710(D2UnitStrc*,int); // 0x0064A710
void __stdcall sub_0064A760(D2UnitStrc*,int); // 0x0064A760
extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0
extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0
int __fastcall sub_00471EC0_DrawUnit(D2UnitStrc* pUnit, unsigned int dwColor, int nX, int nY, int nArg, int bOverlay); // 0x00471EC0
int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
void __stdcall PATH_GetClientCoordsVelocity(D2UnitStrc* pUnit, int* pX, int* pY); // 0x00648300

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

// 0x004C96D0
int __fastcall sub_004C96D0(D2UnitStrc* pUnit,int nSkillId,int nSkillLevel)
{
 if(!SKILLS_GetSkillsTxtRecord(nSkillId)) return 0;
 const int nMissile=SKILLDESC_GetCltMissileId(pUnit,nSkillId);
 if(nMissile<0 || nMissile>=sgptDataTables->nMissilesTxtRecordCount) return 0;
 if(pUnit) pUnit->dwFlags|=0x40;
 D2UnitStrc* pTarget=CUNIT_GetPathTargetUnit(pUnit);
 if(!pTarget) return 0;
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.dwFlags=1;
 params.pOwner=pUnit;
 params.nX=CLIENTS_GetUnitX(pTarget);
 params.nY=CLIENTS_GetUnitY(pTarget);
 params.nSkill=nSkillId;
 params.nSkillLevel=nSkillLevel;
 params.nMissile=nMissile;
 D2UnitStrc* pMissile=MISSILE_CreateClientMissile(&params);
 if(!pMissile) return 0;
 sub_0064A710(pMissile,!pTarget ? 6 : pTarget->dwUnitType);
 sub_0064A760(pMissile,!pTarget ? -1 : pTarget->dwUnitId);
 return 1;
}
