#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
struct D2UnitStrc;







extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2MonStatsTxtRun* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                 // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860
D2CharStatsTxtRun* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId);                             // 0x004833E0
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nSkillId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540
void __fastcall D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode);       // 0x00553DC0
void __fastcall sub_6FCBDE90(D2UnitStrc* pUnit, int a2);                                                    // 0x005544B0
int __fastcall sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0
D2UnitStrc* __fastcall sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10
int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
void __fastcall sub_00571B70_SkillUpdate(D2UnitStrc* pUnit, int nSkillId);                                  // 0x00571B70
void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0
void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0
unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);               // 0x00622C40
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                                // 0x006277E0
int __stdcall sub_006417F0_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                          // 0x006417F0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill);                                                            // 0x006444A0
int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                            // 0x006444D0
int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500
int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);                                                        // 0x00644530
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);                      // 0x006449F0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                  // 0x00648C30
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps);                      // 0x00649070
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970
void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064EC10

static __forceinline D2SkillsTxt* sub_I16_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int sub_I16_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 2:
    case 4:
    case 5:
        return pUnit->pStaticPath->nXPos;

    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int sub_I16_IsMonster(D2UnitStrc* pUnit)
{
    return pUnit->dwUnitType == 1;
}

// 0x005D9F70
static int __stdcall sub_005D9F70_SetLeapVelocity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2SkillStrc* pSkillRead = pSkill;
    SKILLS_SetFlags(pSkillRead, 0x1101);
    PATH_SetMoveTestCollisionMask(pPath, 0);
    PATH_SetFootprintCollisionMask(pPath, 0);

    const int nX = SKILLS_GetParam1(pSkillRead);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    PATH_SetType(pPath, 9);

    int nVelocity;
    if ((!pUnit ? 6 : pUnit->dwUnitType) == 1)
    {
        D2MonStatsTxtRun* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        nVelocity = pMonStatsTxtRecord->nRun << 8;
    }
    else
    {
        nVelocity = sub_004833E0_GetCharStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nRunSpeed << 8;
    }

    PATH_SetVelocity(pPath, nVelocity, ".\\SKILLS\\SkillBar.cpp", 0x6C2);
    D2Common_10142(pPath, pUnit, 0);
    return 1;
}

static int __stdcall sub_005DA020_SandLeaperKnockback(D2GameStrc* pGame, int nX, int nY, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam4(pSkill));
    if (!pTarget)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 1);
    UNITS_SetAnimationFrame(pUnit, 12);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    PATH_RecacheRoomIfNeeded(pPath);
    PATH_SetNewDistance(pPath, 5);
    PATH_SetStepNum(pPath, 1);
    PATH_SetTargetUnit(pPath, 0);

    nX = 3 * nX - 2 * CLIENTS_GetUnitX(pTarget);
    nY = 3 * nY - 2 * CLIENTS_GetUnitY(pTarget);
    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (pTargetRoom && DUNGEON_IsRoomInTown(pTargetRoom))
    {
        return 0;
    }

    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    PATH_SetType(pPath, 8);
    D2COMMON_10190_PATH_SetDistance(pPath, 5);
    D2Common_10142(pPath, pUnit, 0);
    return 1;
}

static int __stdcall sub_005DA120_Leap(D2GameStrc* pGame, D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);

    const int bMonster = sub_I16_IsMonster(pUnit);
    int nBaseId;
    if (!bMonster || (nBaseId = sub_00463860(pUnit)) < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nBaseId = -1;
    }

    if (sub_I16_GetUnitX(pUnit) == nX && CLIENTS_GetUnitY(pUnit) == nY)
    {
        if (bMonster)
        {
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
            PATH_SetFootprintCollisionMask(pPath, 0x100);
            PATH_SetMoveTestCollisionMask(pPath, 0x3C01);
            PATH_SetType(pPath, 2);

            if (nBaseId == 0x4E)
            {
                sub_005DA020_SandLeaperKnockback(pGame, nX, nY, pUnit, pSkill);
            }
            else
            {
                SKILLS_SetFlags(pSkill, 0x200);
                pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) - 0x100;
            }
        }
        else
        {
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
            PATH_SetFootprintCollisionMask(pPath, 0x80);
            PATH_SetMoveTestCollisionMask(pPath, 0x1C09);
            PATH_SetType(pPath, 7);
            SKILLS_SetFlags(pSkill, 0x200);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
            EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 1, 0, 0);
        }

        sub_6FCBDE90(pUnit, 0);
        sub_00571B70_SkillUpdate(pUnit, SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillBar.cpp", 0x737));
        return 1;
    }

    if (!bMonster)
    {
        D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 10);
        return 0;
    }

    int nAnimFrame = 0;
    if (nBaseId == 0x4E)
    {
        nAnimFrame = 8;
    }
    else if (nBaseId == 0x21C)
    {
        nAnimFrame = sub_006417F0_GetDistanceToXY(pUnit, nX, nY) < 2 ? 12 : 10;
    }

    UNITS_SetAnimationFrame(pUnit, nAnimFrame);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    return 0;
}

static __forceinline int sub_M392_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

int __fastcall SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = sub_I16_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);

    const int bMonster = sub_M392_GetUnitType(pUnit) == 1;

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (sub_005DA120_Leap(pGame, pSkill, pUnit) && !bMonster)
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags = 9;
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
            sub_6FD10200(pGame, pUnit, 0, 0, nDamage, &damage, 0);
        }
    }
    else
    {
        if (nSkillFlags & 0x80)
        {
            return sub_005D9F70_SetLeapVelocity(pGame, pUnit, pSkill);
        }

        if (!bMonster)
        {
            SKILLS_SetFlags(pSkill, 0);
        }
    }

    return 1;
}

// 0x005DA490
static D2UnitStrc* __stdcall sub_005DA490_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2GameStrc* const pGameA = *(D2GameStrc* volatile*)&pGame;
    D2UnitStrc* const pUnitA = *(D2UnitStrc* volatile*)&pUnit;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGameA, pUnitA);
    if (pTarget && !UNITS_IsInMeleeRange(pUnitA, pTarget, 0))
    {
        pTarget = 0;
    }

    if (!pTarget)
    {
        const int nUnitType = SKILLS_GetParam3(pSkill);
        const int nUnitGUID = SKILLS_GetParam4(pSkill);
        if (nUnitType != 6)
        {
            pTarget = SUNIT_GetServerUnit(*(D2GameStrc* volatile*)&pGame, nUnitType, nUnitGUID);
        }

        if (!pTarget)
        {
            D2UnitStrc* const pUnitAgain = *(D2UnitStrc* volatile*)&pUnit;
            const int nRange = sub_6FD15460(pUnitAgain);
            pTarget = sub_6FD107F0(*(D2GameStrc* volatile*)&pGame, pUnitAgain, 0, 0, nRange, 0x20003, -1, 0);
        }
    }

    if (pTarget)
    {
        SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
        const int nTargetGUID = *(const volatile int*)&pTarget->dwUnitId;
        SKILLS_SetParam4(pSkill, nTargetGUID);
    }
    else
    {
        SKILLS_SetParam3(pSkill, 6);
    }

    return pTarget;
}

static int __stdcall sub_005DA660_LeapAttackHit(D2GameStrc* pGame, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    D2SkillsTxt* pSkillsTxtRecord = sub_I16_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pDefender = sub_005DA490_FindLeapAttackTarget(pGame, pUnit, pSkill);
    if (!pDefender)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pDefender, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & 1)
    {
        damage.wResultFlags |= 8;
        damage.dwHitClass = sub_00623C20(pUnit);
        damage.dwHitFlags |= 0x20;
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);

        unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
        if (!nSrcDam)
        {
            nSrcDam = 0x80;
        }

        SUNITDMG_AllocCombat(pGame, pUnit, pDefender, &damage, nSrcDam);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pDefender, 0);

        if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
        {
            UNITS_SetOverlay(pDefender, pSkillsTxtRecord->wSrvOverlay, 0);
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, 0x15);
        if (pStatList)
        {
            D2Common_10474(pDefender, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
    }

    return 1;
}

int __fastcall SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (sub_005DA120_Leap(pGame, pSkill, pUnit))
        {
            if (!sub_005DA490_FindLeapAttackTarget(pGame, pUnit, pSkill))
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
                EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 4, 0, 0);
                return 0;
            }

            D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 16);
        }

        return 1;
    }

    if (nSkillFlags & 0x80)
    {
        return sub_005D9F70_SetLeapVelocity(pGame, pUnit, pSkill);
    }

    if (SKILLS_GetFlags(pSkill) & 0x200)
    {
        return sub_005DA660_LeapAttackHit(pGame, nSkillId, nSkillLevel, pUnit);
    }

    SKILLS_SetFlags(pSkill, 0x1000);
    return 1;
}
