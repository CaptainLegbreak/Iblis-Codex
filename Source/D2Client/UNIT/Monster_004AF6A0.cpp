#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Client.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"

extern "C" const unsigned short gwUniqueModNameIds[];                                                       // 0x00725188

extern "C" { Unicode gwszNameSeparator[1]; }                                                                // 0x007C0C58

int __fastcall sub_004AE380_IsMinionMonster(D2UnitStrc* pUnit);                                             // 0x004AE380

int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820

int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0

extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800

struct D2UnitStrc;

typedef unsigned int DWORD;

typedef char I20_check_unit_a[(I20_OFFSET(D2UnitStrc, dwAnimMode) == 0x10 && I20_OFFSET(D2UnitStrc, pSeed) == 0x20) ? 1 : -1];

typedef char I20_check_unit_b[(I20_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C && I20_OFFSET(D2UnitStrc, nActionFrame) == 0x4E) ? 1 : -1];

typedef char I20_check_unit_c[(I20_OFFSET(D2UnitStrc, dwFlags) == 0xC4 && I20_OFFSET(D2UnitStrc, nSeqCurrentFramePrecise) == 0x44) ? 1 : -1];

typedef char I20_check_txt_a[(I20_OFFSET(D2MonStatsTxt, nByte1A7) == 0x1A7 && I20_OFFSET(D2MonStats2Txt, nInfernoRollback) == 0x10A) ? 1 : -1];

typedef char I20_check_txt_b[(sizeof(D2SkillsTxt) == 0x23C && I20_OFFSET(D2DataTablesStrc, nSkillsTxtRecordCount) == 0xBA0) ? 1 : -1];

typedef char I20_check_txt_c[(I20_OFFSET(D2DataTablesStrc, pSkillsTxt) == 0xB98 && sizeof(D2MissileStrc) == 0x5C) ? 1 : -1];

typedef char I20_check_unit_d[(I20_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8) ? 1 : -1];

typedef char I20_check_misc[(I20_OFFSET(D2MissileStrc, nSkillLevel) == 0x30 && sizeof(D2MonAnimRecStrc) == 12) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                              // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

extern D2MonAnimRecStrc gaMonAnimRecords_00725220[];                                                        // 0x00725220

extern D2MonAnimRecStrc gaMonAnimRecordsMoving_007252E0[];                                                  // 0x007252E0

extern D2MonAnimRecStrc gMonAnimRecord_00725328;                                                            // 0x00725328

extern D2MonAnimRecStrc gMonAnimRecord_00725334;                                                            // 0x00725334

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390

int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

D2UnitStrc* __fastcall sub_004648F0_GetPathTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0

D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730

void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70

void __fastcall sub_004ADE60(D2UnitStrc* pUnit);                                                            // 0x004ADE60

void __stdcall sub_004AF1B0(D2UnitStrc* pUnit, int nMissile, int nX, int nY);                               // 0x004AF1B0

int __fastcall sub_004C68F0_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0

void __fastcall sub_004C72F0(D2UnitStrc* pUnit);                                                            // 0x004C72F0

void __fastcall sub_004CB460_UpdateModeSound(D2UnitStrc* pUnit);                                                            // 0x004CB460

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams);                           // 0x004CD540

D2UnitStrc* __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

D2UnitStrc* __fastcall sub_004CDC30(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

void __stdcall sub_004DA000_ResetGfxMotion(D2UnitStrc* pUnit);                                              // 0x004DA000

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                       // 0x00641530

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                           // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

void __stdcall sub_00648750(D2DynamicPathStrc* pPath, int nArg);                                            // 0x00648750

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int a4);                            // 0x00649EF0

struct D2MonStatsTxt;

struct D2SeqModeStrc;

struct D2UnitTargetStrc;

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2MonStats2Txt;

struct D2SkillsTxt;

struct D2MissileStrc;

struct Unicode;

struct D2SeqModeStrc
{
    int unk0x00;
    int nMode;
};

void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60

void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit); // 0x00623E00

enum { CASE_BOUND = 0x100 };

void __fastcall sub_004B13A0_UpdateMonsterClient(D2UnitStrc* pUnit);

static void sub_004AF6A0_MonsterAttackEvent(D2UnitStrc* pUnit);

int __fastcall UNITS_CanSwitchAI(int nMonsterId); // 0x00623470

int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wFlag); // 0x004AC7E0

extern D2MonCmdRecordStrc gMonCmdRecords_006DA4D8[];                                                        // 0x006DA4D8

int __cdecl sub_0044BF00();                                                                                 // 0x0044BF00

int __cdecl sub_0044BF10();                                                                                 // 0x0044BF10

void __cdecl sub_0044DA40();                                                                                // 0x0044DA40

void __fastcall sub_00457460(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x00457460

int __fastcall sub_00463860(D2UnitStrc* pUnit);                                                             // 0x00463860

void __fastcall sub_004643F0_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId); // 0x004643F0

void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit);                                       // 0x004647D0

void __fastcall sub_00464810_SetUnitFlag16(D2UnitStrc* pUnit);                                                // 0x00464810

void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930

void __fastcall sub_00464C90_SetCounter58(D2UnitStrc* pUnit);                                               // 0x00464C90

void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg);                // 0x00464E50

void __fastcall sub_00465BF0_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg);                        // 0x00465BF0

void __cdecl sub_00466FE0();                                                                                // 0x00466FE0

D2UnitStrc* __cdecl sub_00467A10();                                                             // 0x00467A10

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode);                                     // 0x0046C140

void __fastcall sub_0046F170_RemoveOverlays(D2UnitStrc* pUnit);                                             // 0x0046F170

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610

void __fastcall sub_00480490_RecacheUnitPath(D2UnitStrc* pUnit);                                            // 0x00480490

int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY);                           // 0x004804A0

void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY); // 0x004804E0

int __fastcall sub_00480780_SetPathTargetUnit(D2UnitStrc* pUnit, int nUnitType, int nUnitGUID);            // 0x00480780

void __fastcall sub_00480D20_SetModeOverlay(D2UnitStrc* pUnit, int nMode);                                  // 0x00480D20

void __fastcall sub_00480EC0_SetUnitModeNoOverlay(D2UnitStrc* pUnit, int nMode);                            // 0x00480EC0

void __fastcall sub_004AC840(D2UnitStrc* pUnit, int nFlag);                                                 // 0x004AC840

void __fastcall sub_004ADE40(D2UnitStrc* pUnit);                                                            // 0x004ADE40

void __fastcall sub_004ADE50(D2UnitStrc* pUnit);                                                            // 0x004ADE50

void __fastcall sub_004ADE70(D2UnitStrc* pUnit);                                                            // 0x004ADE70

void __fastcall sub_004AE210_SetMonsterLight(D2UnitStrc* pUnit);                                            // 0x004AE210

void __fastcall sub_004AF890_SpawnBloodMissiles(D2UnitStrc* pUnit, int nArg1, int nArg2);                   // 0x004AF890


int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);          // 0x004B9A00

D2UnitStrc* __fastcall sub_004C5420_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4); // 0x004C5420

void __fastcall sub_004C6EB0_StartSkillOnUnit(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand);              // 0x004C6EB0

void __fastcall sub_004C6F40(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand);                                // 0x004C6F40

int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit);                                          // 0x004DA0F0

void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200

void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0

void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit);                                     // 0x004DA690

void __fastcall sub_004DA6E0_SetMotionFlag20(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit);                                       // 0x006272E0

int __stdcall STATES_CheckStateMaskShatterOnUnit(D2UnitStrc* pUnit);                                       // 0x0063A6F0

unsigned char __stdcall sub_0063E7A0_GetByteTableEntry(unsigned char nIndex);                               // 0x0063E7A0

int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

void __stdcall sub_00648730(D2DynamicPathStrc* pDynamicPath);                                // 0x00648730

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);                                        // 0x006487F0

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0

void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648DC0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70

void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int a3);                         // 0x00649970

void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int bForGameLogic);                             // 0x00649F70

void __stdcall PATH_AddCollisionFootprintForOptionalUnit(D2UnitStrc* pUnit);                                // 0x0064A0E0

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath);                                   // 0x00650590

static void sub_004AE1D0_RefreshMonsterMode(D2UnitStrc* pUnit);                                             // 0x004AE1D0

static void sub_004AFB60_ReplaySequence(D2UnitStrc* pUnit);                                                // 0x004AFB60

static int sub_004AFBC0_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord);                    // 0x004AFBC0

static void sub_004AFC10_CreateDeathMissiles(D2UnitStrc* pUnit);                                            // 0x004AFC10

static void sub_004AFCE0_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode);                              // 0x004AFCE0

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

// 0x004ADEA0
void __fastcall sub_004ADEA0_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId)
{
    wszName->wChar = 0;

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    unsigned char* pUniqueMods = pMonsterData->nMonUmod;
    if (!pUniqueMods)
    {
        return;
    }

    if (sub_004AE380_IsMinionMonster(pUnit))
    {
        if (nNameId)
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3995));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3221));
        }
        else
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(3221));
        }
        return;
    }

    const int nOldFont = sub_00502EF0(6);
    int nWidth = 0;
    int nCount = 0;
    int nTextLength = 0;
    if (nNameId)
    {
        nCount = 1;
        Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(nNameId));
        nTextLength = sub_00526800((const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
        nWidth = sub_00501820(D2LANG_GetStringFromTblIndex(nNameId));
    }

    switch (pUnit->dwClassId)
    {
    case 704:
    case 704 + 1:
    case 704 + 2:
    case 704 + 3:
    case 704 + 4:
    case 704 + 5:
        return;
    }

    for (int i = 0; i < 9; ++i)
    {
        const int nMod = pUniqueMods[i];
        if (!gwUniqueModNameIds[nMod])
        {
            continue;
        }

        if (nCount && nTextLength + 1 < nLength - 1)
        {
            Unicode::strcat(wszName, gwszNameSeparator);
            ++nTextLength;
            nWidth += sub_00501820(gwszNameSeparator);
        }

        if (nTextLength < nLength - 1)
        {
            const Unicode* wszMod = D2LANG_GetStringFromTblIndex(gwUniqueModNameIds[nMod]);
            if (sub_00526800((const unsigned short*)wszMod) + nTextLength < nLength - 1)
            {
                nTextLength += sub_00526800((const unsigned short*)wszMod);
                nWidth += sub_00501820(wszMod);
                Unicode::strcat(wszName, wszMod);
                ++nCount;
            }
        }

        if (nWidth > 480)
        {
            sub_00502EF0(nOldFont);
            return;
        }
    }

    sub_00502EF0(nOldFont);
}

static __forceinline unsigned int sub_J20_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2SkillsTxt* sub_J20_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline unsigned int sub_J20_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }

    return 0;
}

static __forceinline int sub_J20_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static __forceinline int sub_J20_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_J20_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static void sub_004AE400_CastRandomCurse(D2UnitStrc* pUnit)
{
    const int nIndex = sub_J20_SeedStep(&pUnit->pSeed) % 5;
    D2_ASSERT(nIndex < 5, 0x174);

    const int nSkill = gaRandomCurseSkills_006DA5DC[nIndex];
    D2UnitStrc* pMissile = sub_004CDB40_SubmitRequest(pUnit, nSkill, sub_J20_UnitX(pUnit), sub_J20_UnitY(pUnit), 0, 1);
    if (pMissile)
    {
        UNITS_StoreOwner(pMissile, pUnit);
        UNITS_StoreOwner(pUnit, pMissile);
        sub_004DA000_ResetGfxMotion(pMissile);
        sub_004DA620(pMissile, 1);
        pMissile->dwFlagEx |= 0x40000;
    }
}

static void sub_004AF2E0_MonsterSkillEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    const int nMissile = D2Common_11050(pUnit, 1);
    if (nMissile == -1)
    {
        return;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x20;
    switch (nMissile)
    {
    case MISSILE_MUMMY1:
    case MISSILE_MUMMY2:
    case MISSILE_MUMMY3:
    case MISSILE_MUMMY4:
        tMissile.dwFlags = 0x34;
        tMissile.nVelocity = 2;
        break;
    }
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nSkillLevel = 1;

    D2UnitStrc* pTarget = sub_004648F0_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!pPath)
        {
            return;
        }
        tMissile.nTargetX = D2COMMON_10175_PathGetFirstPointX(pPath);
        tMissile.nTargetY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        tMissile.nTargetX = CLIENTS_GetUnitX(pTarget);
        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
    }

    if (nMissile == MISSILE_PANTHERPOTORANGE || nMissile == MISSILE_PANTHERPOTGREEN)
    {
        if (pTarget)
        {
            sub_004CDC30(pUnit, nMissile, 0, 0, 0, 0, 0, 1, 0);
        }
    }
    else if (nMissile == MISSILE_CATAPULTCHARGEDBALL_ON)
    {
        sub_004AE3C0(pUnit);
        sub_004AE400_CastRandomCurse(pUnit);
    }
    else
    {
        sub_004CD540_CreateMissile(&tMissile);
    }

    sub_004AF1B0(pUnit, nMissile, tMissile.nTargetX, tMissile.nTargetY);
}

static D2MonAnimRecStrc* sub_004AF400_GetMonsterAnimRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    if (nClassId == 0xF3 && nMode == 0xB || nClassId == 0x14D && nMode == 0xB)
    {
        return &gMonAnimRecord_00725328;
    }

    if (nClassId == 0x21F && nMode == 0xA || nClassId == 0x220 && nMode == 0xA || nClassId == 0x23A && nMode == 0xA)
    {
        return &gMonAnimRecord_00725334;
    }

    D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
    if (!pMonStats2Txt)
    {
        return 0;
    }

    if (pMonStats2Txt->nModeEnabledWhenMovingFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
    {
        return &gaMonAnimRecordsMoving_007252E0[nMode];
    }

    if (!nMode && sub_0063E8D0(pUnit, nMode))
    {
        return &gaMonAnimRecordsMoving_007252E0[0];
    }

    return &gaMonAnimRecords_00725220[pUnit->dwAnimMode];
}

// build: context sub_004AF4C0_UpdateMonsterFrame
static void sub_004AF4C0_UpdateMonsterFrame(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2Txt;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = sub_J20_GetSkillsTxt(SKILLS_GetSkillIdFromSkill(pSkill, gszMonsterSourceFile_006DA5C8, 0x3B5));
    if (!pSkillsTxt)
    {
        return;
    }

    int nFlags = SKILLS_GetFlags(pSkill);
    int bCheckFrame = 1;
    if ((nFlags & 1) && sub_004807C0(pUnit))
    {
        if (pSkillsTxt->wSrvDoFunc != 0x43)
        {
            nFlags |= 2;
            SKILLS_SetFlags(pSkill, nFlags);
        }
        sub_004C68F0_DoUsedSkill(pUnit);
        bCheckFrame = 0;
    }

    const int nActionFrame = pUnit->nActionFrame;
    if (nActionFrame != 4)
    {
        if (!bCheckFrame || sub_00451F30_TestUnitFlag(pUnit, 0x40) || nActionFrame != 1 && nActionFrame != 2 && nActionFrame != 3)
        {
            switch (pSkillsTxt->wSrvDoFunc)
            {
            case 0x5F:
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt)
                {
                    return;
                }

                sub_004C68F0_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise >> 8) > pMonStats2Txt->nInfernoAnim)
                {
                    pUnit->nSeqCurrentFramePrecise = pMonStats2Txt->nInfernoRollback << 8;
                }
                return;

            case 0x7E:
                sub_004C68F0_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise & ~0xFF) >= 0xC00)
                {
                    pUnit->nSeqCurrentFramePrecise = 0x800;
                }
                return;

            case 0x98:
            {
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt || !STATES_CheckState(pUnit, STATE_INFERNO))
                {
                    return;
                }

                const int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
                if (nFrame >= pMonStats2Txt->nInfernoAnim)
                {
                    sub_004C68F0_DoUsedSkill(pUnit);
                }

                if (nFrame >= pMonStats2Txt->nInfernoRollback)
                {
                    pUnit->nSeqCurrentFramePrecise = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) + pMonStats2Txt->nInfernoRollback - 4) << 8;
                }
                return;
            }
            }
            return;
        }
    }

    sub_004C68F0_DoUsedSkill(pUnit);
}

// 0x004AF6A0
static void sub_004AF6A0_MonsterAttackEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    const int nId = sub_00463860_GetMonsterId(pUnit);
    const int nMonsterId = (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) ? nId : -1;

    if (nMode == 0xD && nMonsterId != MONSTER_SANDLEAPER1)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath)
        {
            sub_00650590(pPath);
            sub_00648750(pPath, 0);
            sub_00648DC0(pPath);
            sub_00480E70_SetUnitMode(pUnit, 3);
        }
        return;
    }

    if (sub_004648F0_GetPathTargetUnit(pUnit))
    {
        sub_00465BF0(pUnit, 0);
    }

    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if (pMonStatsTxt->nByte1A7)
    {
        switch (sub_J20_GetAnimMode(pUnit))
        {
        case 8:
            if (nMonsterId == MONSTER_VULTURE1)
            {
                return;
            }
        case 5:
        case 9:
            if (nMonsterId == MONSTER_TRAPPEDSOUL1 || nMonsterId == MONSTER_TRAPPEDSOUL2)
            {
                sub_00480E70_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 10:
            if (nMonsterId == MONSTER_BATDEMON1)
            {
                sub_00480E70_SetUnitMode(pUnit, 0xB);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 11:
            if (nMonsterId == MONSTER_BATDEMON1)
            {
                return;
            }
            break;

        case 2:
            if (nMonsterId == MONSTER_ICEGLOBE || nMonsterId == MONSTER_WILLOWISP1)
            {
                return;
            }
            break;

        case 4:
            if (nMonsterId == MONSTER_TRAPPEDSOUL1 || nMonsterId == MONSTER_TRAPPEDSOUL2)
            {
                sub_00480E70_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            if (nMonsterId == MONSTER_CATAPULT1)
            {
                sub_004AE3C0(pUnit);
                sub_004AE400_CastRandomCurse(pUnit);
            }
            break;

        case 14:
            if (nMonsterId == MONSTER_FROGDEMON1)
            {
                return;
            }
            break;

        case 12:
            if (nMonsterId == MONSTER_MAGGOTQUEEN1)
            {
                return;
            }
            break;
        }
    }

    if (sub_J20_HasUnitFlagBit(pUnit))
    {
        sub_00480E70_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
        return;
    }

    if (!sub_00463720_TestUnitFlagEx(pUnit, 0x2000))
    {
        sub_00480E70_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
    }
}

static __declspec(noinline) void sub_004AE1D0_RefreshMonsterMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const unsigned int nMode = pUnit->dwAnimMode;
        if (nMode < 0x10 && nMode && nMode != 0xC)
        {
            sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 0);
            sub_00480490_RecacheUnitPath(pUnit);
            sub_00480E70_SetUnitMode(pUnit, 1);
        }
    }
}

static __declspec(noinline) void sub_004AFB60_ReplaySequence(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pSequenceRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    const int nCount = DATATBLS_GetSeqFramePointsCount(pUnit) >> 8;
    for (int i = 0; i < nCount; ++i)
    {
        int nMode;
        int nFrame;
        int nDirection;
        int nEvent;
        DATATBLS_ComputeSequenceAnimation(pSequenceRecord, i << 8, i << 8, &nMode, &nFrame, &nDirection, &nEvent);
        pUnit->dwAnimMode = nMode;
        sub_00470610_Refresh(pUnit, 0);
    }
}

static __declspec(noinline) int sub_004AFBC0_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord)
{
    if (!pUnit || !pRecord)
        return 0;

    if (pRecord->bSet)
    {
        const int nIndex = pRecord->nIndex;
        if (nIndex < 0x10)
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2Txt)
                return pMonStats2Txt->nModeEnabledWhenMovingFlags[nIndex >> 3] & gdwBitMasks[nIndex & 7];
        }
    }
    return 0;
}

static __declspec(noinline) void sub_004AFC10_CreateDeathMissiles(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return;

    D2MissileStrc tMissile;
    if (STATES_CheckState(pUnit, STATE_UBERMINION) && !STATES_CheckState(pUnit, STATE_FREEZE))
    {
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2020;
        tMissile.pOwner = pUnit;
        tMissile.pOrigin = pUnit;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = MISSILE_SUICIDEFIREEXPLODE;
        sub_004CD540_CreateMissile(&tMissile);
        tMissile.nMissile = MISSILE_SUICIDECORPSEEXPLODE;
        sub_004CD540_CreateMissile(&tMissile);
        return;
    }

    const int nMissile = (unsigned char)UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId)->nType + 0x10F;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x2020;
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nSkillLevel = 1;
    tMissile.nMissile = nMissile;
    sub_004CD540_CreateMissile(&tMissile);
    tMissile.nMissile = MISSILE_ICEBREAKSMOKE;
    sub_004CD540_CreateMissile(&tMissile);
}

static __forceinline int sub_J10_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_J10_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __declspec(noinline) void sub_004AFCE0_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode == 12)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~14;
        }
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        if (sub_004DA0F0_GetGfxMotionField3C(pUnit))
        {
            return;
        }
        sub_004DA000_ResetGfxMotion(pUnit);
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        sub_004DA6E0_SetMotionFlag20(pUnit, 1);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, 2, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0xA0, 0);
    }
    else if (nMode == 14 || nMode == 10)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 14;
        }
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 1);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x3C01);
        if (!sub_004DA0F0_GetGfxMotionField3C(pUnit))
        {
            return;
        }
        sub_004DA690_ReplaceMotionFlag1With8(pUnit);
        sub_004DA6E0_SetMotionFlag20(pUnit, 0);
        sub_004DA200_SetMotionVectorB(pUnit, 0, 0, -8, 1);
        sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0, 0);
    }
}

__declspec(noinline) void __fastcall sub_00464E50_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg)
{
    if (!pUnit)
        return;

    if (nArg > 0)
        sub_00470390(pUnit, nOverlay, 1, 0, nArg, 0, 0, 0);
    else
        sub_00470390(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);

    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

static __forceinline int sub_n5b_IsClassId(D2UnitStrc* pUnit, int nClassId)
{
    return pUnit->dwClassId == nClassId;
}

static __forceinline int sub_n5b_Distance(int nDelta)
{
    if (nDelta < 0)
        nDelta = -nDelta;
    return nDelta;
}

static __forceinline int sub_n5b_IsTypeFlag1(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        return pUnit->pMonsterData->nClientFlags & 1;
    return 0;
}

static __forceinline D2MonStatsTxt* sub_n5b_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline D2MonStats2Txt* sub_n5b_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

__declspec(noinline) int __fastcall sub_00463860(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_n5b_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
            return pUnit->dwClassId;
        return pMonStatsTxtRecord->nBaseId;
    }
    return -1;
}

static __forceinline int sub_n5b_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return nMonsterId;
    return -1;
}

static __forceinline void sub_b1_WalkTo(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand, int nMode)
{
    if (sub_004AE080(pUnit, 1) || !sub_004804A0_SetPathTargetPos(pUnit, pCommand->nX, pCommand->nY)
        || STATES_CheckState(pUnit, STATE_ATTACHED) || !sub_0046C140_TestMonModeFlag(pUnit->dwClassId, nMode))
    {
        sub_004AE1D0_RefreshMonsterMode(pUnit);
        return;
    }

    sub_00480E70_SetUnitMode(pUnit, nMode);
}

// 0x004AFF60
void __fastcall sub_004AFF60_MonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pCommand)
{
    int nMonId;
    D2MonStats2Txt* pMonStats2Txt;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pUnit->dwAnimMode == 0xD)
    {
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_ResetToPreviousType(pPath);
    }

    if (!sub_00464820_IsDeadOrDying(pUnit))
    {
        PATH_AddCollisionFootprintForOptionalUnit(pUnit);
    }
    else if (nCommand != 8 && nCommand != 9)
    {
        sub_00649FF0(pUnit, 0);
        sub_004AE210_SetMonsterLight(pUnit);
        pUnit->dwFlagEx &= ~0x40000;
    }

    int bUpdateVelocity = 0;
    if (nCommand != 0x13 && nCommand != 0x16 && nCommand != 0x15 && pCommand)
    {
        bUpdateVelocity = 1;
        if (pCommand->nPathValue > 0)
        {
            PATH_SetType(pPath, pCommand->nPathValue);
            if (nCommand == 0x14)
            {
                PATH_SetNewDistance(pPath, (unsigned char)pCommand->nPathByte);
                PATH_SetStepNum(pPath, (unsigned char)pCommand->nZero);
            }
        }
        UNITS_SetUsedSkill(pUnit, 0);
        sub_004ADE40(pUnit);
    }

    if (!sub_n5b_GetMonStatsTxtRecord(pUnit->dwClassId))
        return;

    pMonStats2Txt = sub_n5b_GetMonStats2TxtRecord(pUnit->dwClassId);
    if (!pMonStats2Txt)
        return;

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    const int nBaseId = sub_00463860(pUnit);
    if (nBaseId >= 0 && nBaseId < nMonStatsCount)
        nMonId = nBaseId;
    else
        nMonId = -1;

    int nValue;
    D2MonCmdRecordStrc* pRecord = &gMonCmdRecords_006DA4D8[nCommand];
    switch (nCommand)
    {
    case 1:
    case 0x17:
        D2_ASSERT(pCommand, 0x6E2);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 1);
        if (sub_004AE080(pUnit, 1) || !sub_004804A0_SetPathTargetPos(pUnit, pCommand->nX, pCommand->nY))
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        if (nCommand == 1)
            sub_00480E70_SetUnitMode(pUnit, 2);
        else
            sub_00480E70_SetUnitMode(pUnit, 0xF);
        break;

    case 0:
    case 0x18:
    {
        D2_ASSERT(pCommand, 0x6F7);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 1);
        nValue = pCommand->nX;
        sub_004643F0_SetTargetByGUID(pUnit, nValue, pCommand->nY);
        if (sub_004AE080(pUnit, 1) || !sub_00480780_SetPathTargetUnit(pUnit, nValue, pCommand->nY))
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        if (nCommand == 0)
            sub_00480E70_SetUnitMode(pUnit, 2);
        else
            sub_00480E70_SetUnitMode(pUnit, 0xF);
        break;
    }

    case 5:
    case 0xA:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x1B:
    case 0x1D:
    {
        D2_ASSERT(pCommand, 0x70F);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        nValue = pCommand->nX;
        if (nMonId == MONSTER_ICEGLOBE)
            break;

        sub_004643F0_SetTargetByGUID(pUnit, nValue, pCommand->nY);
        if (nMonId == MONSTER_FINGERMAGE1 && nCommand == 0xA)
        {
            D2UnitStrc* pTargetUnit = sub_004648F0_GetPathTargetUnit(pUnit);
            sub_00464E50_SetOverlayWithSound(pTargetUnit, 0xA9, 0);
        }

        sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 0);
        if (nMonId == MONSTER_VULTURE1)
            sub_004AFCE0_UpdateCollisionForMode(pUnit, nCommand);
        else if (nMonId == MONSTER_CHARSI && nCommand == 0xD)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x38);

        if ((!pUnit ? -1 : pUnit->dwClassId) == 0x195 && nCommand == 0xD)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);

        if (pUnit->dwClassId == 0x195 && nCommand == 0xF)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x30);

        if (nMonId == MONSTER_WARRIV1)
        {
            if (nCommand == 0xD)
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);
        }
        else if (nMonId == MONSTER_FARA && nCommand == 0xD)
        {
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 4);
        }

        sub_00480E70_SetUnitMode(pUnit, pRecord->nIndex);
        if (sub_004AFBC0_HasMonStatsFlag(pUnit, pRecord))
            sub_00480780_SetPathTargetUnit(pUnit, nValue, pCommand->nY);
        break;
    }

    case 4:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x11:
    case 0x1A:
    case 0x1C:
        D2_ASSERT(pCommand, 0x741);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        if ((pCommand->nX || pCommand->nY)
            && (pCommand->nX != CLIENTS_GetUnitX(pUnit) || pCommand->nY != CLIENTS_GetUnitY(pUnit)))
        {
            UNITS_UpdateDirectionAndSpeed(pUnit, pCommand->nX, pCommand->nY);
        }

        sub_00480E70_SetUnitMode(pUnit, pRecord->nIndex);
        if (sub_004AFBC0_HasMonStatsFlag(pUnit, pRecord))
            sub_004804A0_SetPathTargetPos(pUnit, pCommand->nX, pCommand->nY);

        if (nMonId == MONSTER_VULTURE1)
            sub_004AFCE0_UpdateCollisionForMode(pUnit, nCommand);
        break;

    case 6:
    {
        if (!pCommand)
            break;

        sub_004AC840(pUnit, pCommand->nZero & 0x80);
        pCommand->nZero &= 0x7F;
        if (pCommand->nZero > 1)
            ++pCommand->nZero;

        int bBlood = 1;
        if (pCommand->nZero)
        {
            const int nOldValue = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
            if (nOldValue == pCommand->nZero)
                bBlood = 0;
            else
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nZero << 8, 0);
        }

        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        pUnit->dwLastHitClass = pCommand->nParam18;
        PATH_RecacheRoomIfNeeded(pPath);
        sub_00480E70_SetUnitMode(pUnit, 3);
        if (bBlood)
            sub_004AF890_SpawnBloodMissiles(pUnit, 1, 0);

        sub_00464C90_SetCounter58(pUnit);
        sub_004ADE70(pUnit);
        break;
    }

    case 0x13:
        D2_ASSERT(pCommand, 0x781);
        sub_004AC840(pUnit, pCommand->nY & 0x80);
        pCommand->nY &= 0x7F;
        if (pCommand->nY > 1)
            ++pCommand->nY;

        if (pCommand->nY)
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nY << 8, 0);

        pUnit->dwLastHitClass = pCommand->nX;
        sub_004AF890_SpawnBloodMissiles(pUnit, 1, 1);
        sub_00464C90_SetCounter58(pUnit);
        sub_00480D20_SetModeOverlay(pUnit, 0xD);
        sub_004CC5B0_RequestMode(pUnit, 0xD, 1);
        sub_004ADE70(pUnit);
        break;

    case 0x14:
        D2_ASSERT(pCommand, 0x79A);
        if (pCommand->nPathByte)
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nPathByte << 8, 0);

        pUnit->dwLastHitClass = pCommand->nParam18;
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_SetType(pPath, 0xB);
        D2COMMON_10190_PATH_SetDistance(pPath, (unsigned char)pCommand->nZero);
        D2COMMON_10170_PathSetTargetPos(pPath, (unsigned short)pCommand->nX, (unsigned short)pCommand->nY);
        D2Common_10142(pPath, pUnit, 0);
        sub_00480E70_SetUnitMode(pUnit, 0xD);
        break;

    case 0x12:
        D2_ASSERT(pCommand, 0x7B0);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        PATH_RecacheRoomIfNeeded(pPath);
        sub_004643F0_SetTargetByGUID(pUnit, pCommand->nX, pCommand->nY);
        sub_00465BF0_SetPathTargetToTargetUnit(pUnit, 0);
        sub_00480E70_SetUnitMode(pUnit, 6);
        break;

    case 8:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        pUnit->dwLastHitClass = pCommand->nParam18;
        if (sub_00467A10() == pUnit)
        {
            if (!(sub_0044BF00() & 8) && !(sub_0044BF10() & 8))
            {
                sub_00466FE0();
            }
            else
            {
                sub_0044DA40();
                sub_00467A70_RefreshHoverUnit(0);
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
        if (STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags &= ~2;
            pUnit->dwFlags |= 0x20;
        }

        if (STATES_CheckStateMaskShatterOnUnit(pUnit))
        {
            sub_004AFC10_CreateDeathMissiles(pUnit);
            pUnit->dwLastHitClass = (pUnit->dwLastHitClass & 0xF) | 0xA0;
        }

        if (!(pMonStats2Txt->nFlags[2] & gdwBitMasks[3]))
            PATH_SetUnitDeadCollision(pUnit, 0);

        nValue = pUnit->dwClassId;
        D2MonStatsTxt* pDeadMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nValue);
        if (!pDeadMonStatsTxt)
            return;

        switch (pDeadMonStatsTxt->nSplEndDeath)
        {
        case 1:
            if (pDeadMonStatsTxt->wMinion[0] >= 0 && pDeadMonStatsTxt->wMinion[0] < sgptDataTables->nMonStatsTxtRecordCount)
            {
                D2UnitStrc* pSpawned = sub_00466730_SpawnPresetUnit(nValue, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, 0);
                if (pSpawned)
                    pSpawned->dwFlags &= ~2;

                pSpawned->dwLastHitClass = pUnit->dwLastHitClass;
                sub_00480E70_SetUnitMode(pSpawned, 0);
                sub_004AEDD0(pUnit, pDeadMonStatsTxt->wMinion[0]);
            }
            break;
        }

        switch (nMonId)
        {
        case MONSTER_THORNHULK1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x4F, 0);
        LABEL_MODE0:
            sub_00480E70_SetUnitMode(pUnit, 0);
        LABEL_CLEAR:
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        case MONSTER_MAGGOTEGG1:
            if (pUnit->dwAnimMode == 0xE)
            {
                sub_00480EC0_SetUnitModeNoOverlay(pUnit, 0);
                pUnit->dwFlags &= ~2;
                pUnit->nSeqCurrentFramePrecise = 0xE00;
                sub_00464930_FreeLight(pUnit);
            }
            else
            {
                sub_00480E70_SetUnitMode(pUnit, 0);
                pUnit->dwFlags &= ~2;
                sub_00464930_FreeLight(pUnit);
            }
            break;

        case MONSTER_CANTOR1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x4E, 0);
            goto LABEL_MODE0;

        case MONSTER_FROGDEMON1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x52, 0);
            goto LABEL_MODE0;

        case MONSTER_VULTURE1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x92, 0);
            sub_00480E70_SetUnitMode(pUnit, 0);
            if (!sub_004DA0F0_GetGfxMotionField3C(pUnit))
                goto LABEL_CLEAR;

            sub_004DA690_ReplaceMotionFlag1With8(pUnit);
            sub_004DA6E0_SetMotionFlag20(pUnit, 0);
            sub_004DA200_SetMotionVectorB(pUnit, 0, 0, -0x10, 1);
            sub_004DA2A0_SetMotionVectorC(pUnit, 0, 0, 0, 0);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        case MONSTER_TENTACLE1:
        case MONSTER_TENTACLEHEAD1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x9D, 0);
            goto LABEL_MODE0;

        case MONSTER_DOPPLEZON:
            sub_004C5420_RequestAtTarget(pUnit, 0x148, 0, 1);
            goto LABEL_MODE0;

        case MONSTER_HYDRA1:
        case MONSTER_HYDRA2:
        case MONSTER_HYDRA3:
            sub_0046F170_RemoveOverlays(pUnit);
            sub_00464E50_SetOverlayWithSound(pUnit, (!pUnit ? -1 : pUnit->dwClassId) - 0xAD, 0);
            goto LABEL_MODE0;

        case MONSTER_MAGGOTQUEEN1:
        {
            D2MonCommandStrc tCommand = {};
            tCommand.nX = 0xD8;
            tCommand.nArg = 1;
            sub_004AFF60_MonsterCommand(0x15, pUnit, &tCommand);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;
        }

        case MONSTER_WILLOWISP1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xB8, 0);
            goto LABEL_MODE0;

        case MONSTER_DOOMKNIGHT1:
        case MONSTER_DOOMKNIGHT2:
        case MONSTER_DOOMKNIGHT3:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xBB, 0);
            goto LABEL_MODE0;

        case MONSTER_BONEFETISH1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xBC, 0);
            sub_00464E50_SetOverlayWithSound(pUnit, 0xBD, 0);
            goto LABEL_MODE0;

        case MONSTER_SHADOWWARRIOR:
        case MONSTER_SHADOWMASTER:
            sub_00464E50_SetOverlayWithSound(pUnit, 0x10F, 0);
            goto LABEL_MODE0;

        case MONSTER_MEGADEMON1:
        case MONSTER_VENOMLORD:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xB9, 0);
            goto LABEL_MODE0;

        case MONSTER_MINION1:
        {
            unsigned char nDirection = UNITS_GetDirection(pUnit);
            switch (sub_0063E7A0_GetByteTableEntry(nDirection) % 4)
            {
            case 0:
                sub_004B9A00(0x51C, pUnit, 0, 0, 0);
                break;
            case 1:
                sub_004B9A00(0x51F, pUnit, 0, 0, 0);
                break;
            case 2:
                sub_004B9A00(0x522, pUnit, 0, 0, 0);
                break;
            case 3:
                sub_004B9A00(0x525, pUnit, 0, 0, 0);
                break;
            }
            sub_00480E70_SetUnitMode(pUnit, 0);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;
        }

        case MONSTER_SUICIDEMINION1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xCC, 0);
            sub_004B9A00(0x973, pUnit, 0, 0, 0);
            goto LABEL_MODE0;

        case MONSTER_PLAGUEPOPPY:
        case MONSTER_CYCLEOFLIFE:
        case MONSTER_VINECREATURE:
            sub_004CDB40_SubmitRequest(pUnit, 0x1D6, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
            sub_00480E70_SetUnitMode(pUnit, 0);
            sub_004B9A00(0x316, pUnit, 0, 0, 0);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        case MONSTER_CATAPULT1:
        {
            int nOverlay;
            switch (pUnit->dwClassId)
            {
            case 0x1F1:
            case 0x1F3:
                nOverlay = 0xE1;
                break;
            case 0x1F2:
                nOverlay = 0xE2;
                break;
            default:
                goto LABEL_MODE0;
            }
            sub_00464E50_SetOverlayWithSound(pUnit, nOverlay, 0);
            goto LABEL_MODE0;
        }

        case MONSTER_SUCCUBUS1:
        case MONSTER_SUCCUBUSWITCH1:
            sub_00464E50_SetOverlayWithSound(pUnit, 0xE5, 0);
            goto LABEL_MODE0;

        case MONSTER_SIEGEBEAST1:
        {
            D2DynamicPathStrc* pDeadPath = pPath;
            D2COMMON_10160_PathUpdateDirection(pDeadPath, (PATH_GetDirection(pDeadPath) + 0x20) % 0x40);
            goto LABEL_MODE0;
        }

        case MONSTER_BAALCLONE:
            sub_004CDB40_SubmitRequest(pUnit, 0x266, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        case MONSTER_BAALCRABSTAIRS:
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags |= 0x20;
            sub_00480E70_SetUnitMode(pUnit, 0xC);
            pUnit->dwFlags &= ~2;
            sub_00464930_FreeLight(pUnit);
            break;

        default:
            goto LABEL_MODE0;
        }
        break;
    }

    case 9:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (!(pMonStats2Txt->nFlags[2] & gdwBitMasks[3]))
            PATH_SetUnitDeadCollision(pUnit, 0);

        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
        if (sub_004648F0_GetPathTargetUnit(pPlayer) == pUnit)
            UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);

        if (nMonId == MONSTER_MAGGOTQUEEN1 && pUnit->dwAnimMode == 0xE)
        {
            UNITS_SetUsedSkill(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_QUEENDEATH));
        }
        else
        {
            sub_00480E70_SetUnitMode(pUnit, 0xC);
            sub_00464810_SetUnitFlag16(pUnit);
        }

        if (pUnit->dwClassId != 0xD3 && nMonId != MONSTER_CATAPULT1 && nMonId != MONSTER_SHADOWWARRIOR && nMonId != MONSTER_SHADOWMASTER)
            sub_0046F170_RemoveOverlays(pUnit);

        if (nMonId == MONSTER_BARRICADETOWER)
            sub_00464810_SetUnitFlag16(sub_004CDB40_SubmitRequest(pUnit, 0x1A8, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1));

        switch (nMonId)
        {
        case MONSTER_BONEWALL:
        case MONSTER_BAALCRABSTAIRS:
        case MONSTER_BAALCLONE:
            pUnit->dwFlagEx |= 0x40000;
            break;
        }

        pUnit->dwFlags &= ~2;
        pUnit->dwFlags |= 0x20;
        if (STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags &= ~4;
            pUnit->dwFlags |= 0x20;
        }

        sub_00464930_FreeLight(pUnit);
        break;
    }

    case 7:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        if (pCommand && pCommand->nZero)
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nZero << 8, 0);

        if (sub_00451F30_TestUnitFlag(pUnit, 0x200))
            pUnit->dwFlags |= 2;
        else
            sub_00457460(pUnit, 2, pMonStats2Txt->nFlags[0] & gdwBitMasks[3]);

        sub_00457460(pUnit, 0x20, !(pMonStats2Txt->nFlags[1] & gdwBitMasks[6]));
        sub_004647D0_UpdateAttackableFlag(pUnit);
        if (!pCommand)
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        sub_004804E0_SetPosition(pUnit, (unsigned short)pCommand->nX, (unsigned short)pCommand->nY, 0, 0, 0);
        if (sub_n5b_Distance(CLIENTS_GetUnitX(pUnit) - pCommand->nX) <= 1 && sub_n5b_Distance(CLIENTS_GetUnitY(pUnit) - pCommand->nY) <= 1)
        {
            sub_004AE1D0_RefreshMonsterMode(pUnit);
            break;
        }

        sub_b1_WalkTo(pUnit, pCommand, 2);
        break;
    }

    case 0x16:
    {
        D2_ASSERT(pCommand, 0x911);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        nValue = pCommand->nX;
        SKILLS_AssignSkill(pUnit, nValue, pCommand->nArg, 0, gszMonsterSourceFile_006DA5C8, 0x914);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nValue);
        UNITS_SetUsedSkill(pUnit, pSkill);
        nValue = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
        if (nValue == 0xE)
            sub_004AFB60_ReplaySequence(pUnit);

        pCommand->nY = -1;
        sub_00480E70_SetUnitMode(pUnit, nValue);
        sub_004C6EB0_StartSkillOnUnit(pUnit, pCommand);
        break;
    }

    case 0x15:
    {
        D2_ASSERT(pCommand, 0x924);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        nValue = pCommand->nX;
        SKILLS_AssignSkill(pUnit, nValue, pCommand->nArg, 0, gszMonsterSourceFile_006DA5C8, 0x929);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nValue);
        UNITS_SetUsedSkill(pUnit, pSkill);
        nValue = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
        if (nValue == 0xE)
            sub_004AFB60_ReplaySequence(pUnit);

        pCommand->nY = -1;
        sub_00480E70_SetUnitMode(pUnit, nValue);
        sub_004C6F40(pUnit, pCommand);
        break;
    }

    default:
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        sub_004AE1D0_RefreshMonsterMode(pUnit);
        break;
    }

    if (bUpdateVelocity && pCommand && pCommand->nArg)
    {
        const int nVelocity = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
        if (nVelocity != pCommand->nArg)
        {
            STATLIST_DeactivateTemporaryStates(pUnit);
            STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, pCommand->nArg - nVelocity, 0);
            UnitUpdateAnimRateAndVel(pUnit, gszMonsterSourceFile_006DA5C8, 0x946);
        }
    }

    sub_004ADE50(pUnit);
    if (sub_n5b_IsTypeFlag1(pUnit))
    {
        if (pUnit->dwAnimMode != 1)
            sub_004AE1D0_RefreshMonsterMode(pUnit);

        if (pPath)
            sub_00648730(pPath);
    }
}

// 0x004B11F0
int __fastcall sub_004B11F0_CheckStatus(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return 0;
    if (!UNITS_CanSwitchAI(pUnit->dwClassId))
        return 0;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (sub_004AC7E0(pUnit, 8))
            return 0;
        if (pUnit->dwUnitType == UNIT_MONSTER && sub_004AC7E0(pUnit, 2))
            return 0;
    }
    return 1;
}

static D2MonStatsTxt* MONSTATS_GetRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2MonStatsTxt* MONSTATS_GetUnitRecord(D2UnitStrc* pUnit, int nType)
{
    if (pUnit && nType == UNIT_MONSTER)
    {
        return MONSTATS_GetRecord(pUnit->dwClassId);
    }

    return 0;
}

// 0x004B1280
int __fastcall sub_004B1280_HandleSequenceStop(D2UnitStrc* pUnit, D2SeqModeStrc* pMode)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nType = pUnit->dwUnitType;

    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetUnitRecord(pUnit, nType);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        switch (pMonStatsTxtRecord->nSplEndDeath)
        {
        case 1:
            if (!pUnit->dwAnimMode && UNITS_IsAtEndOfFrameCycle(pUnit))
            {
                D2UnitTargetStrc tTarget = {};
                sub_004AFF60_MonsterCommand(9, pUnit, &tTarget);
            }
            break;
        }
    }

    int nResult = 0;
    switch (pMode->nMode)
    {
    case 0:
        UNITS_StopSequence(pUnit);
        break;

    case 1:
        nResult = UNITS_IsAtEndOfFrameCycle(pUnit);
        if (!nResult)
        {
            UNITS_StopSequence(pUnit);
        }
        break;

    case 2:
        if (!UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            UNITS_StopSequence(pUnit);
            break;
        }

        pUnit->nSeqCurrentFramePrecise = pUnit->dwFrameCountPrecise - 0x100;
        pUnit->wAnimSpeed = 0;
        if (!pUnit->dwAnimMode)
        {
            pUnit->dwFlags |= 0x20;
        }
        break;

    case 3:
        pUnit->nSeqCurrentFramePrecise = 0x100;
        pUnit->wAnimSpeed = 0;
        break;
    }

    return nResult;
}

static __forceinline unsigned int sub_I20_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline D2SkillsTxt* sub_I20_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static __forceinline int sub_I20_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static __forceinline int sub_I20_UnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static __forceinline int sub_I20_UnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004B13A0
void __fastcall sub_004B13A0_UpdateMonsterClient(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    if (STATES_CheckState(pUnit, STATE_FREEZE) && !sub_00464820_IsDeadOrDying(pUnit))
    {
        return;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    D2MonAnimRecStrc* pRecord = sub_004AF400_GetMonsterAnimRecord(pUnit);
    if (!pRecord)
    {
        return;
    }

    sub_004AF4C0_UpdateMonsterFrame(pUnit);

    int bResult = 0;
    switch (pRecord->nType)
    {
    case 1:
        bResult = sub_004807C0(pUnit);
        break;
    }

    if (nMode == 1 && !sub_004AE080(pUnit, nMode))
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath && PATH_GetTargetUnit(pPath))
        {
            int nUnitType;
            int nUnitGUID;
            PATH_GetTargetTypeAndGUID(pPath, &nUnitType, &nUnitGUID);
            D2UnitStrc* pTarget = sub_00463990(nUnitGUID, nUnitType);
            PATH_SetTargetUnit(pPath, pTarget);
            if (pTarget)
            {
                D2Common_10213(pUnit);
            }
        }
        else
        {
            D2Common_10213(pUnit);
        }
    }

    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nClassId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if ((pMonStatsTxt->nMonStatsFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !sub_004638A0_CheckMonStats2Flag(nClassId, 0xD)
        && pUnit->dwAnimMode == 1 && !sub_00451F30_TestUnitFlag(pUnit, 0x200)
        && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && (unsigned int)sub_00641530(pUnit, pPlayer) < 7)
        {
            D2SeedStrc* pSeed = &pUnit->pSeed;
            if (pSeed && (int)SEED_RollLimitedRandomNumber(pSeed, 0x64) < 0xA)
            {
                D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
                if (pPath)
                {
                    D2Common_10216(pPath, CLIENTS_GetUnitX(pPlayer), CLIENTS_GetUnitY(pPlayer), 0);
                }
            }
        }
    }

    const int nRet = sub_004B1280(pUnit, pRecord);
    int bAttack = 0;
    switch (pRecord->nAction)
    {
    case 1:
        bAttack = bResult;
        break;

    case 2:
    case 3:
        bAttack = nRet;
        break;

    case 4:
        if (bResult && sub_006217C0(pUnit))
        {
            bAttack = 1;
        }
        break;
    }

    sub_004AF2E0_MonsterSkillEvent(pUnit);
    sub_004ADE60(pUnit);
    if (pUnit->pDynamicPath)
    {
        D2COMMON_10193_PATH_AdjustDirection(pUnit->pDynamicPath);
    }

    if (bAttack)
    {
        sub_004AF6A0_MonsterAttackEvent(pUnit);
    }

    if (!pUnit->dwAnimMode && pUnit->dwClassId == 0x210 && sub_00451F30_TestUnitFlag(pUnit, 1))
    {
        pUnit->dwFlags &= ~1;
        sub_00466730_SpawnPresetUnit(0x1DE, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 2, 0);
    }

    if (sub_0063A340(pUnit))
    {
        sub_004C72F0(pUnit);
    }

    sub_004CB460_UpdateModeSound(pUnit);
    sub_004CAF60(pUnit);
}

// 0x004B15F0
Unicode Unicode::sub_004B15F0() const
{
    return Unicode(wChar < CASE_BOUND ? gaCaseTable_00730778[wChar] : wChar);
}

#include "gen/data/Source/D2Client/UNIT/Monster_004AF6A0.inc"
