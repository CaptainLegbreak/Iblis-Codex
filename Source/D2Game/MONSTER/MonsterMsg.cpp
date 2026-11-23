#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"

#define D2_ASSERT(expr,line) if(!(expr)) {sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
struct D2MonsterModeInfo;

void __fastcall SCMD_SendUnitActionAtPosition(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0
void __fastcall SCMD_SendSkillUseOnUnit(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned char nUnitType, int nUnitGUID, unsigned short a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D530
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005387F0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
static void __stdcall sub_00597D70_SendUsedSkill(D2UnitStrc* pMonster, D2UnitStrc* pTarget, D2ClientStrc* pClient);

struct D2MonsterModeInfo { int bTarget,bTargetCoords,bSimple,bIncludeCoords,nCoordMode,nTargetMode; };

extern D2MonsterModeInfo gMonsterModeInfo[]; // 0x006E1D90
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __stdcall PATH_GetType(D2DynamicPathStrc*); // 0x00648E30
int __stdcall PATH_GetLastPointX(D2DynamicPathStrc*); // 0x00648A40
int __stdcall PATH_GetLastPointY(D2DynamicPathStrc*); // 0x00648A60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc*); // 0x006487F0
unsigned char __stdcall D2COMMON_10191_PATH_GetDistance(D2DynamicPathStrc*); // 0x00648E60
unsigned char __stdcall sub_006490A0_GetPathStep(D2DynamicPathStrc*); // 0x006490A0
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005A5650
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc*,int); // 0x005A0180
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __fastcall D2GAME_PACKETS_SendPacket0x6D_6FC3D080(D2ClientStrc*,unsigned int,unsigned short,unsigned short,unsigned char); // 0x0053BB70
void __fastcall D2GAME_PACKETS_SendPacket0x68_6FC3CA90(D2ClientStrc*,unsigned char,int,char,char,int,char); // 0x0053B5F0
void __fastcall D2GAME_PACKETS_SendPacket0x67_6FC3CBC0(D2ClientStrc*,unsigned char,int,char,short,short,char); // 0x0053B710
void __fastcall D2GAME_PACKETS_SendPacket0x68_6FC3CCB0(D2ClientStrc*,unsigned char,int,char,char,int,char,char,char); // 0x0053B7F0
void __fastcall D2GAME_PACKETS_SendPacket0x67_6FC3CDE0(D2ClientStrc*,unsigned char,int,char,short,short,char,char,char); // 0x0053B910
void __fastcall D2GAME_PACKETS_SendPacket0x6A_6FC3CEE0(D2ClientStrc*,char,int,char,char,int,char); // 0x0053B9F0
void __fastcall D2GAME_PACKETS_SendPacket0x69_6FC3CF30(D2ClientStrc*,char,int,char,short,short,char,char); // 0x0053BA40
void __fastcall D2GAME_PACKETS_SendPacket0x6C_6FC3CF90(D2ClientStrc*,char,int,char,char,int,char,short,short); // 0x0053BAA0
void __fastcall D2GAME_PACKETS_SendPacket0x6B_6FC3D000(D2ClientStrc*,char,int,char,short,short,char,char,short,short); // 0x0053BB00

// 0x00597D70
static void __stdcall sub_00597D70_SendUsedSkill(D2UnitStrc* pMonster, D2UnitStrc* pTarget, D2ClientStrc* pClient)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pMonster);
    if (!pSkill)
    {
        return;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\MONSTER\\MonsterMsg.cpp", 150);
    const char nSkillLevel = SKILLS_GetSkillLevel(pMonster, pSkill, 1);
    const int nUnitGUID = !pMonster ? -1 : pMonster->dwUnitId;

    if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
    {
        SCMD_SendSkillUseOnUnit(pClient, 1, nUnitGUID, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId, nSkillId, 0, nSkillLevel, 0);
    }
    else
    {
        SCMD_SendUnitActionAtPosition(pClient, 1, nUnitGUID, D2COMMON_10175_PathGetFirstPointX(pMonster->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMonster->pDynamicPath), (unsigned short)nSkillId, 0, nSkillLevel, 0);
    }
}

void __fastcall sub_00597D70_EmitCaller(D2GameStrc* pGame, D2UnitStrc* pMonster, D2ClientStrc* pClient)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pMonster);
    if (pTarget && !CLIENTS_IsInUnitsRoom(pTarget, pClient))
    {
        pTarget = 0;
    }

    if (pMonster->dwAnimMode == 17 || UNITS_GetUsedSkill(pMonster))
    {
        sub_00597D70_SendUsedSkill(pMonster, pTarget, pClient);
        return;
    }

    SCMD_SendSkillUseOnUnit(pClient, 1, pMonster->dwUnitId, pTarget->dwUnitType, pTarget->dwUnitId, pMonster->dwAnimMode, 0, 0, 0);
}

static inline int GetUnitGUID(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }

// 0x00597E20
void __fastcall MONSTERMSG_SendMonsterModeUpdate(D2GameStrc* pGame,D2UnitStrc* pUnit,D2ClientStrc* hClient)
{
 unsigned char nDirection=0,nHitClass=0,nExtra=0,nStep=0;
 D2_ASSERT(pUnit,0xD4);
 D2_ASSERT(hClient,0xD5);
 int nMode=pUnit->dwAnimMode;
 D2MonsterModeInfo* pInfo=&gMonsterModeInfo[nMode];
 D2UnitStrc* pTarget=SUNIT_GetTargetUnit(pGame,pUnit);
 if((pTarget && !CLIENTS_IsInUnitsRoom(pTarget,hClient)) || !pInfo->bTarget) pTarget=0;
 if(nMode==14 || UNITS_GetUsedSkill(pUnit)) { sub_00597D70_SendUsedSkill(pUnit,pTarget,hClient); return; }
 D2DynamicPathStrc* hPath=pUnit->pDynamicPath;
 D2_ASSERT(hPath,0xE6);
 int nX,nY,nSendMode,nHeader;
 if(pTarget) {
  nSendMode=pInfo->nTargetMode;
  nX=pTarget->dwUnitType;nY=pTarget->dwUnitId;
  nHeader=0x68;
  switch(nMode) { case 2:case 15: {
   int nPathType=PATH_GetType(hPath);
   switch(nPathType) { case 5:case 6: {
    nSendMode=pInfo->nCoordMode;nHeader=0x67;
    nX=PATH_GetLastPointX(hPath);nY=PATH_GetLastPointY(hPath);
   } }
  } }
 } else {
  nHeader=0x67;nSendMode=pInfo->nCoordMode;
  if(pInfo->bTargetCoords) {nX=PATH_GetLastPointX(hPath);nY=PATH_GetLastPointY(hPath);}
  else {nX=PATH_GetXPosition(hPath);nY=PATH_GetYPosition(hPath);}
 }
 switch(nMode) {
 case 6: if(!pTarget) {nX=0;nY=-1;} break;
 case 0: nDirection=PATH_GetDirection(hPath);nHitClass=pUnit->dwLastHitClass;break;
 case 12: nDirection=PATH_GetDirection(hPath);break;
 case 13: nDirection=D2COMMON_10191_PATH_GetDistance(hPath);nHitClass=MONSTERMODE_GetHpPercent128(pUnit);nExtra=pUnit->dwLastHitClass;break;
 case 3:
  nDirection=MONSTERMODE_GetHpPercent128(pUnit);
  if(nDirection>1) --nDirection;
  if(MONSTERUNIQUE_CheckMonTypeFlag(pUnit,0x100)) nDirection|=0x80;
  nHitClass=pUnit->dwLastHitClass;break;
 default: nStep=sub_006490A0_GetPathStep(hPath);break;
 }
 if(nMode==1) {
  nDirection=MONSTERMODE_GetHpPercent128(pUnit);
  int nGUID=pUnit->dwUnitId;
  D2GAME_PACKETS_SendPacket0x6D_6FC3D080(hClient,nGUID,CLIENTS_GetUnitX(pUnit),CLIENTS_GetUnitY(pUnit),nDirection);
  STATLIST_SetUnitStat(pUnit,STAT_PIERCE_IDX,sub_006253B0_GetBaseStat(pUnit,0x148,0)+1,0);
  return;
 }
 if(nMode==13) {
  int nGUID=pUnit->dwUnitId;
  if(nHeader==0x68) D2GAME_PACKETS_SendPacket0x68_6FC3CCB0(hClient,0x68,nGUID,nSendMode,nX,nY,nDirection,nHitClass,nExtra);
  else D2GAME_PACKETS_SendPacket0x67_6FC3CDE0(hClient,(unsigned char)nHeader,nGUID,nSendMode,nX,nY,nDirection,nHitClass,nExtra);
  return;
 }
 if(!pInfo->bSimple) {
 if(pInfo->bIncludeCoords) {
  if(nHeader==0x68) {
   int nGUID=pUnit->dwUnitId;
   D2GAME_PACKETS_SendPacket0x6C_6FC3CF90(hClient,0x6C,nGUID,nSendMode,nX,nY,nDirection,CLIENTS_GetUnitX(pUnit),CLIENTS_GetUnitY(pUnit));
  } else {
   int nGUID=pUnit->dwUnitId;
   D2GAME_PACKETS_SendPacket0x6B_6FC3D000(hClient,0x6B,nGUID,nSendMode,nX,nY,nDirection,nHitClass,CLIENTS_GetUnitX(pUnit),CLIENTS_GetUnitY(pUnit));
  }
  return;
 }
 int nGUID=pUnit->dwUnitId;
 if(nHeader==0x68) D2GAME_PACKETS_SendPacket0x6A_6FC3CEE0(hClient,0x6A,nGUID,nSendMode,nX,nY,nDirection);
 else D2GAME_PACKETS_SendPacket0x69_6FC3CF30(hClient,0x69,nGUID,nSendMode,nX,nY,nDirection,nHitClass);
 return;
 }
 if(pInfo->bSimple) {
  int nGUID=pUnit->dwUnitId;
  if(nHeader==0x68) D2GAME_PACKETS_SendPacket0x68_6FC3CA90(hClient,0x68,nGUID,nSendMode,nX,nY,nStep);
  else D2GAME_PACKETS_SendPacket0x67_6FC3CBC0(hClient,(unsigned char)nHeader,nGUID,nSendMode,nX,nY,nStep);
  return;
 }

}

#include "gen/data/Source/D2Game/MONSTER/MonsterMsg.inc"
struct D2ClientStrc;
