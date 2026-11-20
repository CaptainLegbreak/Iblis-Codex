#include "D2Constants.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
struct D2AiCmdStrc;

struct D2MinionListStrc
{
    int dwMinionGUID;
    D2MinionListStrc* pNext;
};

struct D2AiControlStrc
{
    int nAiSpecialState;
    void* pAiParamFn;
    unsigned short nAiFlags;
    unsigned char unk0x0A[2];
    int dwOwnerGUID;
    unsigned int dwOwnerType;
    int dwAiParam[3];
    D2AiCmdStrc* pCurrentCmd;
    D2AiCmdStrc* pLastCmd;
    D2GameStrc* pGame;
    int dwOwnerGUIDEx;
    int dwOwnerTypeEx;
    D2MinionListStrc* pMinionList;
};



D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

// build: context sub_GetUnitTypeOrInvalid
static __forceinline int sub_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return UNIT_INVALID;
    return pUnit->dwUnitType;
}

__forceinline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit || sub_GetUnitTypeOrInvalid(pUnit) != UNIT_MONSTER)
        return 0;
    if (!pUnit->pMonsterData)
        return 0;
    return pUnit->pMonsterData->pAiControl;
}

extern const char gszAiGeneral_006E1B24[]; // 0x006E1B24
void __fastcall FOG_FreePool(void* pool,void* memory,const char* file,int line,int zero); // 0x0040B480
// 0x0058F260
void __fastcall AIGENERAL_DetachOwnedMinions(D2UnitStrc* pUnit)
{
 D2AiControlStrc* control=AIGENERAL_GetAiControlFromUnit(pUnit);
 if(!control || !control->pGame) return;
 D2UnitStrc* owner=SUNIT_GetServerUnit(control->pGame,control->dwOwnerTypeEx,control->dwOwnerGUIDEx);
 if(!owner || owner!=pUnit) return;
 const int ownerType=sub_GetUnitTypeOrInvalid(owner);
 if(ownerType!=UNIT_MONSTER) return;
 D2AiControlStrc* ownerControl=AIGENERAL_GetAiControlFromUnit(owner);
 D2MinionListStrc* node=ownerControl->pMinionList;
 D2GameStrc* game=ownerControl->pGame;
 while(node) {
  D2MinionListStrc* next=node->pNext;
  D2UnitStrc* minion=SUNIT_GetServerUnit(game,UNIT_MONSTER,node->dwMinionGUID);
  const int type=sub_GetUnitTypeOrInvalid(minion);
  if(type==UNIT_MONSTER) {
   D2AiControlStrc* minionControl=AIGENERAL_GetAiControlFromUnit(minion);
   minionControl->dwOwnerGUIDEx=-1;
   minionControl->dwOwnerTypeEx=1;
   minionControl->pGame=game;
  }
  FOG_FreePool(game->pMemoryPool,node,gszAiGeneral_006E1B24,567,0);
  node=next;
 }
 ownerControl->pMinionList=0;
}
