#include "D2GameTypes.h"
#define SUBMISSILE_ID 375
struct D2UnitStrc;
typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730
// 0x004D1820
int __fastcall sub_004D1820_SpawnSubMissile(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        D2MissileStrc params;
        memset(&params, 0, sizeof(params));
        params.pOwner = pOwner;
        params.pOrigin = pMissile;
        params.nMissile = SUBMISSILE_ID;
        params.nSkill = MISSILE_GetSkill(pMissile);
        params.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2UnitStrc* pNew = sub_004CD540_CreateMissile(&params);
        if (pNew)
            MISSILE_SetTargetX(pNew, MISSILE_GetTargetX(pMissile));
    }
    return 1;
}
