#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#define TEST_OFFSET 0
#define LIGHT_LIMIT 60
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;
struct D2StaticPathStrc;
struct D2GfxLightStrc;
struct D2UnitSfxNodeStrc;




extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
extern "C" void* __cdecl memset(void*,int,unsigned int);
int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile);                                                       // 0x0064A210
int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile);                                                       // 0x0064A280
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                       // 0x004639D0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
void __fastcall sub_004CD390_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004D30C0_CltDoCommon(D2UnitStrc* pMissile);
int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);
void __fastcall sub_004742D0_ResetLightSize(D2GfxLightStrc* pLight, int nSize);
int __fastcall sub_00474350_GetLightSize(D2GfxLightStrc* pLight);
void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce);
struct D2OwnerStrc_004CA990;
extern "C" void* __fastcall sub_004CA990_GetLinkFirst(D2OwnerStrc_004CA990* pOwner);

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}
inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                        // 0x0045C4B0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit);                                                            // 0x00464810
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);         // 0x0064CB30
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
#define SPAWN_FLAGS 0x2001
#define COLLISION_MASK 0x45
// 0x004D59E0
void __fastcall sub_004D59E0_CltDoSeededSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pRecord || pRecord->wCltSubMissile[0] < 0) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    D2UnitStrc* pOwner = sub_004639D0_GetOwnerUnit(pMissile);
    if (!pOwner) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    int nSkill = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkill = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
    if (!pSkill) {
        sub_004CD390_CltDoDefault(pMissile);
        return;
    }
    int nLevel = MISSILE_GetLevel(pMissile);
    int nRange = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile),pSkill->dwCalc[0],nSkill,nLevel);
    int nPeriod = SKILLS_EvaluateSkillFormula(sub_004639D0_GetOwnerUnit(pMissile),pSkill->dwCalc[1],nSkill,nLevel);
    if (nPeriod < 1) nPeriod = 1;
    int nElapsed = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nElapsed % nPeriod != 0) {
        sub_004D30C0_CltDoCommon(pMissile);
        return;
    }
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        SEED_InitLowSeed(pSeed,CLIENTS_GetUnitX(pMissile)+nElapsed);
        --nRange;
        int nDoubleRange = 2*nRange;
        int nX = ITEMS_RollLimitedRandomNumber(pSeed,nDoubleRange)-nRange;
        nX += CLIENTS_GetUnitX(pMissile);
        int nY = ITEMS_RollLimitedRandomNumber(pSeed,nDoubleRange)-nRange;
        nY += CLIENTS_GetUnitY(pMissile);
        if (!COLLISION_CheckMask(pRoom,nX,nY,COLLISION_MASK)) {
            D2MissileStrc params;
            memset(&params,0,sizeof(params));
            params.dwFlags = SPAWN_FLAGS;
            params.pOwner = pOwner;
            params.nSkill = MISSILE_GetSkill(pMissile);
            params.nSkillLevel = MISSILE_GetLevel(pMissile);
            params.nMissile = pRecord->wCltSubMissile[0];
            params.nX = nX;
            params.nY = nY;
            D2UnitStrc* pSub = sub_004CD540_CreateMissile(&params);
            if (pSub) sub_00464810_SetUnitFlag16(pSub);
            if (pRecord->wCltSubMissile[1] >= 0) {
                params.nMissile = pRecord->wCltSubMissile[1];
                sub_004CD540_CreateMissile(&params);
            }
        }
    }
    sub_004D30C0_CltDoCommon(pMissile);
}
