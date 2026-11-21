#include "D2MissileIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Primitives.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2ClientTypes.h"
#include "D2GameObjs.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define SEED_STEP_HIFIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

struct D2GfxLightStrc;

struct D2ShrinesTxt;

struct D2ObjectDataStrc;

struct D2UnitTargetStrc;

struct D2ShrineHandlerStrc;

union D2SeedStrc;

struct D2PlayerDataStrc;

struct D2StaticPathStrc;

struct D2MissileStrc;

struct D2ShrineHandlerStrc
{
    void (__fastcall* pfnInit)(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxt);
    void (__fastcall* pfnOperate)(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ShrinesTxt* pShrinesTxt);
    int f_8;
    int f_C;
    int nSoundId;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" const char gszUnitSourceFile_006DAA8C[];

extern D2DrlgActStrc* gpAct_007A0634;

extern D2ShrineHandlerStrc gShrineHandlers_006DA8C0[]; // 0x006DA8C0

extern int gnShrineHandlerCount_0072779C; // 0x0072779C

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);

void __fastcall sub_00457460(D2UnitStrc* pUnit, int nArg, int nValue);

void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount);

void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);

unsigned char __fastcall sub_004BDEE0(D2UnitStrc* pUnit);

D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);

void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8);

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);

D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6);

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);

void __fastcall sub_004CB460(D2UnitStrc* pUnit);

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);

int __stdcall sub_00621B00_IsShrine(D2UnitStrc* pUnit);

D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit);

void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord);

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __stdcall sub_00624390_AnimInit(D2UnitStrc* pUnit);

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);

D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId);

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

extern "C" char* __cdecl _strrev(char* szString); // 0x00687860

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __fastcall sub_00481030_DoUnitAction(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3); // 0x00481030

void __cdecl sub_004A30A0_TriggerOnceD3(); // 0x004A30A0

void __cdecl sub_004A30C0_TriggerOnce219(); // 0x004A30C0

D2BitBufferStrc* __cdecl sub_004B32D0(); // 0x004B32D0

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500

int __fastcall sub_004BC5E0_UpdateEnvObject(D2UnitStrc* pUnit, int bNoRefresh); // 0x004BC5E0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath); // 0x00648730

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540

char __cdecl sub_004A3110_GetFlag025F(); // 0x004A3110

char __cdecl sub_004A3120_IsQuestUnitPresent(); // 0x004A3120

void __fastcall sub_004A3150_SpawnQuestUnits(int nX, int nY); // 0x004A3150

void sub_004BCB20_StepDoorFrame(D2UnitStrc* pUnit);

struct D2UnitStrc;




void __fastcall sub_004CB460_UpdateModeSound(D2UnitStrc* pUnit);                                                            // 0x004CB460


static void sub_004BCA90_FinishDoorMode(D2UnitStrc* pUnit);

static void sub_004BCB20_StepDoorFrame(D2UnitStrc* pUnit);

static void sub_004BCBB0_UpdateObjectFrame(D2UnitStrc* pUnit);

void __stdcall sub_004BD5C0_OperateShrine(D2UnitTargetStrc* pTarget, D2UnitStrc* pUnit); // 0x004BD5C0

static void __stdcall sub_004BC580_UpdateLight(D2UnitStrc* pUnit, unsigned short nDiameter, int nRed, int nGreen, int nBlue)
{
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!nDiameter)
    {
        if (pLight)
            sub_00464930_FreeLight(pUnit);
        return;
    }

    if (!pLight)
    {
        pLight = sub_00474160_MakeLightEntry(pUnit, 2, nDiameter >> 1, 0xFF, nRed, nGreen, nBlue);
        pUnit->pLight = pLight;
        if (!pLight)
            return;
    }

    sub_00474290(pLight, nDiameter >> 1);
}

int __fastcall sub_004BC5E0_UpdateEnvObject(D2UnitStrc* pUnit, int bNoRefresh)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    if (!pTxt->nEnvEffect)
        return 0;

    switch (ENVIRONMENT_GetPeriodOfDayFromAct(gpAct_007A0634, 0))
    {
    case 0:
        if (pUnit->dwAnimMode == 2 || pUnit->dwAnimMode == 1)
        {
            pUnit->dwAnimMode = 0;
            if (!bNoRefresh)
                sub_00470610_Refresh(pUnit, 0);

            sub_00624390_AnimInit(pUnit);
            sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pUnit->dwAnimMode], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
            if (pTxt->nSelectable[pUnit->dwAnimMode])
                pUnit->dwFlags |= 2;
            else
                pUnit->dwFlags &= ~2;
            return 1;
        }
        return 0;

    case 1:
    case 2:
    case 3:
        if (pUnit->dwAnimMode == 0)
        {
            pUnit->dwAnimMode = 1;
            if (!bNoRefresh)
                sub_00470610_Refresh(pUnit, 0);

            sub_00624390_AnimInit(pUnit);
            sub_00457460(pUnit, 2, pTxt->nSelectable[pUnit->dwAnimMode]);
        }
        sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pUnit->dwAnimMode], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
        return 1;

    default:
        D2_ASSERT(0, 0x66);
    }
    return 0;
}

void __fastcall sub_004BC720_InitObject(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nObjectId, unsigned char nMode)
{
    pUnit->pLight = 0;
    pUnit->dwAnimMode = nMode;
    pUnit->pObjectData = (D2ObjectDataStrc*)FOG_Alloc(sizeof(D2ObjectDataStrc), gszUnitSourceFile_006DAA8C, 0x76, 0);
    memset(pUnit->pObjectData, 0, sizeof(D2ObjectDataStrc));
    pUnit->pObjectData->bPermanent = 0;
    pUnit->pObjectData->unk0x14 = 0;

    D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(nObjectId);
    if (pTxt->nSelectable[pUnit->dwAnimMode])
        pUnit->dwFlags |= 2;
    else
        pUnit->dwFlags &= ~2;

    pUnit->pObjectData->pObjectTxt = pTxt;
    UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
    if (pTxt->nHasCollision[pUnit->dwAnimMode])
        UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);

    if (pTxt->nIsAttackable0)
        pUnit->dwFlags |= 4;
    else
        pUnit->dwFlags &= ~4;

    UNITROOM_AddUnitToRoom(pUnit, pRoom);
    pUnit->dwFlags &= ~8;
    sub_00624390_AnimInit(pUnit);

    if (!pTxt->nBlocksLight[pUnit->dwAnimMode])
        pUnit->dwFlags |= 0x20;
    else
        pUnit->dwFlags &= ~0x20;

    if (pTxt->nOrderFlag[pUnit->dwAnimMode] == 1)
        pUnit->dwFlags |= 0x100000;

    switch (pUnit->dwClassId)
    {
    case 0x3B:
    {
        nMode = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nMode);
        D2_ASSERT(nTownLevelId <= 0xFF, 0x95);
        pUnit->pObjectData->InteractType = nTownLevelId;
        break;
    }
    case 0x3C:
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nLevelId == LEVEL_TRISTRAM)
            pUnit->pObjectData->InteractType = 4;
        else if (nLevelId == LEVEL_STONYFIELD)
            pUnit->pObjectData->InteractType = 0x26;
        break;
    }
    }

    if (!sub_004BC5E0_UpdateEnvObject(pUnit, 1))
        sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pUnit->dwAnimMode], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
}

// 0x004BCA90
static void sub_004BCA90_FinishDoorMode(D2UnitStrc* pUnit)
{
    const int nMode = pUnit->dwAnimMode;
    if (nMode == 3)
    {
        pUnit->dwAnimMode = 0;
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[0];
    }
    else if (nMode == 1)
    {
        UNITS_FreeCollisionPath(pUnit);
        pUnit->dwAnimMode = 2;
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[2];
    }
    else
    {
        D2_ASSERT(0, 0x11F);
    }

    sub_00470610_Refresh(pUnit, 0);
    sub_00624390_AnimInit(pUnit);
    if (pUnit->pObjectData->pObjectTxt->nSelectable[pUnit->dwAnimMode])
        pUnit->dwFlags |= 2;
    else
        pUnit->dwFlags &= ~2;
}

static void __stdcall sub_004BCDE0_SetDoorMode(int bSelectable, D2UnitStrc* pUnit, int nMode)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    D2_ASSERT(nMode < 8, 0x210);

    const unsigned int nOpenFrames = pTxt->dwFrameCnt[1];
    if (nMode == 0 && pUnit->dwAnimMode == 2 && pTxt->dwFrameCnt[3] != 0x100)
    {
        pUnit->nSeqCurrentFramePrecise = pTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 3);
        sub_00470610_Refresh(pUnit, 0);
        pUnit->dwFlags &= ~2;
        UNITS_BlockCollisionPath(pUnit, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
    }
    else if (nMode == 2 && pUnit->dwAnimMode == 0 && nOpenFrames != 0x100)
    {
        UNITS_ChangeAnimMode(pUnit, 1);
        sub_00470610_Refresh(pUnit, 0);
        pUnit->dwFlags &= ~2;
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[2];
    }
    else
    {
        if (bSelectable)
            pUnit->dwFlags |= 2;
        else
            pUnit->dwFlags &= ~2;

        const int nCurrentMode = pUnit->dwAnimMode;
        if (nMode != nCurrentMode)
        {
            if (nMode == 4 || nMode == 2 || nMode == 5)
            {
                if (nCurrentMode != 5 && nCurrentMode != 2 && nCurrentMode != 4)
                    UNITS_FreeCollisionPath(pUnit);
            }
            else if (nMode == 0 && nCurrentMode != 0)
            {
                UNITS_BlockCollisionPath(pUnit, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            }

            UNITS_ChangeAnimMode(pUnit, nMode);
            sub_00470610_Refresh(pUnit, 0);
        }
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[nMode];
    }

    if (!pTxt->nBlocksLight[pUnit->dwAnimMode])
        pUnit->dwFlags |= 0x20;
    else
        pUnit->dwFlags &= ~0x20;
}

static void sub_004BCF60_SetObjectMode(D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    if (pTxt->nIsDoor)
    {
        sub_004BCDE0_SetDoorMode(pTarget->nParam1, pUnit, pTarget->nParam2);
    }
    else
    {
        UNITS_ChangeAnimMode(pUnit, pTarget->nParam2);
        sub_00470610_Refresh(pUnit, 0);
        if (pTxt->nOverlay)
        {
            const int nClassId = pUnit->dwClassId;
            if ((nClassId == 0x162 || nClassId == 0x163 || nClassId == 0x18D || nClassId == 0x195
                || nClassId == 0x197 || nClassId == 0x196 || nClassId == 0x164) && pUnit->dwAnimMode == 0)
                sub_00470390(pUnit, 0x47, 3, 0, 0, 0, 0, 0);
        }

        if (pTxt->nSelectable[pUnit->dwAnimMode])
            pUnit->dwFlags |= 2;
        else
            pUnit->dwFlags &= ~2;

        if (!pTxt->nHasCollision[pUnit->dwAnimMode])
            UNITS_FreeCollisionPath(pUnit);

        if (pTxt->nOrderFlag[pUnit->dwAnimMode] == 1)
            pUnit->dwFlags |= 0x100000;

        sub_004BC580_UpdateLight(pUnit, pTxt->nLit[pTarget->nParam2], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
    }

    sub_004CB460(pUnit);
    sub_00624390_AnimInit(pUnit);
    if (!pTxt->nBlocksLight[pUnit->dwAnimMode])
        pUnit->dwFlags |= 0x20;
    else
        pUnit->dwFlags &= ~0x20;
}

static void __stdcall sub_004BD550_PlayShrineSound(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
    D2_ASSERT(pShrinesTxt, 0x34D);
    D2_ASSERT(pShrinesTxt->bCode < gnShrineHandlerCount_0072779C, 0x34E);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->bCode];
    if (pHandler->nSoundId)
        sub_004B9A00(pHandler->nSoundId, pPlayer, 0, 0, 0);
}

static void sub_004BD650_InitShrine(D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
    D2_ASSERT(pShrinesTxt, 0x37A);
    D2_ASSERT(pShrinesTxt->bCode < gnShrineHandlerCount_0072779C, 0x37B);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->bCode];
    if (pHandler->pfnInit)
        pHandler->pfnInit(pUnit, pShrinesTxt);
}

void __fastcall sub_004BD6B0_SetShrine(D2UnitStrc* pUnit)
{
    UNITS_SetShrineTxtRecordInObjectData(pUnit, DATATBLS_GetShrinesTxtRecord(pUnit->pObjectData->InteractType));
    sub_004BD650_InitShrine(pUnit);
}

void __fastcall sub_004BD6D0_ObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget)
{
    switch (nCommand)
    {
    case 3:
        sub_004BCF60_SetObjectMode(pUnit, pTarget);
        if (sub_00621B00_IsShrine(pUnit))
            sub_004BD650_InitShrine(pUnit);
        return;

    case 0x15:
        sub_004BD5C0_OperateShrine(pTarget, pUnit);
        return;

    default:
        D2_ASSERT(0, 0x39C);
    }
}

void __fastcall sub_004BDFF0_UpdateObject(D2UnitStrc* pUnit)
{
    sub_004BCBB0_UpdateObjectFrame(pUnit);
    if (pUnit->pObjectData->pObjectTxt->nClientFn <= 3 || sub_004BDEE0(pUnit))
        sub_004CB460(pUnit);
}

// 0x004BCB20
static void sub_004BCB20_StepDoorFrame(D2UnitStrc* pUnit)
{
    const int nMode = pUnit->dwAnimMode;
    const int nFrameCnt = pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode];
    if (nMode == 1)
    {
        if (pUnit->nSeqCurrentFramePrecise == nFrameCnt - 0x100)
        {
            sub_004BCA90_FinishDoorMode(pUnit);
            return;
        }
        pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;
        if (pUnit->nSeqCurrentFramePrecise > nFrameCnt - 0x100)
            pUnit->nSeqCurrentFramePrecise = nFrameCnt - 0x100;
        return;
    }

    if (nMode == 3)
    {
        const int nFrame = pUnit->nSeqCurrentFramePrecise;
        if (nFrame <= 0)
        {
            sub_004BCA90_FinishDoorMode(pUnit);
            return;
        }
        if (pUnit->wAnimSpeed > nFrame)
            pUnit->nSeqCurrentFramePrecise = 0;
        else
            pUnit->nSeqCurrentFramePrecise = nFrame - pUnit->wAnimSpeed;
        return;
    }

    D2_ASSERT(0, 0x155);
}


// 0x004BCBB0
static void sub_004BCBB0_UpdateObjectFrame(D2UnitStrc* pUnit)
{
    D2ObjectsTxt* pTxt = pUnit->pObjectData->pObjectTxt;
    int nMode = pUnit->dwAnimMode;
    const int nFrameCnt = pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode];
    if (nFrameCnt == 0x100)
        return;

    const int nCycle = pUnit->pObjectData->pObjectTxt->nCycleAnim[nMode];
    if (!nCycle)
    {
        if (pTxt->nIsDoor)
        {
            sub_004BCB20_StepDoorFrame(pUnit);
            return;
        }

        if (pUnit->nSeqCurrentFramePrecise >= nFrameCnt - 0x100)
        {
            if (pUnit->dwClassId == 0xBD && (nMode == 2 || nMode == 3))
            {
                ++nMode;
                pUnit->dwAnimMode = nMode;
                pUnit->nSeqCurrentFramePrecise = pTxt->nStart[nMode] << 8;
                sub_00470610_Refresh(pUnit, 0);
                sub_00624390_AnimInit(pUnit);
                return;
            }

            if (nMode != 1)
                return;

            pUnit->dwAnimMode = 2;
            if (pTxt->nOrderFlag[2] == 1)
                pUnit->dwFlags |= 0x100000;

            if (pTxt->dwParm[7])
            {
                if (pTxt->dwParm[7] == 0xFF)
                    sub_0046C320_SpawnAroundUnit(pUnit, MONSTER_MINISPIDER, 4);
                else
                    sub_0046C320_SpawnAroundUnit(pUnit, MONSTER_RAT, 4);
            }

            pUnit->nSeqCurrentFramePrecise = pTxt->nStart[2] << 8;
            sub_00470610_Refresh(pUnit, 0);
            sub_00624390_AnimInit(pUnit);
            if (pTxt->nOverlay)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId == 0x162 || nClassId == 0x163 || nClassId == 0x18D || nClassId == 0x195
                    || nClassId == 0x197 || nClassId == 0x196 || nClassId == 0x164)
                    sub_0046F0C0(pUnit, 0, 0x47);
            }

            sub_00457460(pUnit, 2, pTxt->nSelectable[pUnit->dwAnimMode]);
            sub_004BC580_UpdateLight(pUnit, pTxt->nLit[2], pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
            if (!pTxt->nHasCollision[pUnit->dwAnimMode] && pTxt->nHasCollision[1])
                UNITS_FreeCollisionPath(pUnit);
            return;
        }
    }

    if (pUnit->dwClassId == 0x0C)
    {
        pUnit->nSeqCurrentFramePrecise -= pUnit->wAnimSpeed;
        if (pUnit->nSeqCurrentFramePrecise < 0)
            pUnit->nSeqCurrentFramePrecise += nFrameCnt;
        return;
    }

    if (pUnit->dwClassId == 0xBD && nMode == 3)
    {
        pUnit->nSeqCurrentFramePrecise -= pUnit->wAnimSpeed;
        if (pUnit->nSeqCurrentFramePrecise >= 0)
            return;

        pUnit->dwAnimMode = 4;
        pUnit->nSeqCurrentFramePrecise = pTxt->nStart[4] << 8;
        sub_00470610_Refresh(pUnit, 0);
        sub_00624390_AnimInit(pUnit);
        return;
    }

    pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;
    const int nFrame = pUnit->nSeqCurrentFramePrecise;
    if (nFrame >= nFrameCnt)
    {
        if (!nCycle)
            pUnit->nSeqCurrentFramePrecise = nFrameCnt - 0x100;
        else
            pUnit->nSeqCurrentFramePrecise = (pTxt->nStart[pUnit->dwAnimMode] << 8) - nFrameCnt + nFrame;
    }
}

void __fastcall sub_M256_Emit_004BCB20(D2UnitStrc* pUnit)
{
    sub_004BCB20_StepDoorFrame(pUnit);
}

static inline unsigned int SEED_RollRandomNumberLoFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x004BD090
void __fastcall sub_004BD090_OperateReverseNameShrine(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ShrinesTxt* pShrinesTxt)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        strncpy(pPlayerData->szName, _strrev(pPlayerData->szName), 16);
    }
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x004BD0C0
void __fastcall sub_004BD0C0_SpawnMissileGrid(D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nArg)
{
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 3;
            tMissileParams.nX = UNITS_GetUnitXPosition(pUnit);
            tMissileParams.nY = UNITS_GetUnitYPosition(pUnit);
            tMissileParams.nTargetX = (i & 1) ? 5 * i : -5 * i;
            tMissileParams.nTargetY = (j & 1) ? 5 * j : -5 * j;
            tMissileParams.pOwner = pOwner;
            tMissileParams.nMissile = MISSILE_FIREBALL;
            int nLevel = STATLIST_UnitGetStatValue(pOwner, STAT_LEVEL, 0) / 5;
            if (nLevel < 1)
            {
                nLevel = 1;
            }
            else if (nLevel > 8)
            {
                nLevel = 8;
            }
            tMissileParams.nSkillLevel = nLevel;
            sub_004CD540_CreateMissile(&tMissileParams);
        }
    }
}

// 0x004BD220
void __fastcall sub_004BD220_SpawnMissileStar(D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nArg)
{
    int aOffsetX[6] = { -6, -6, 0, 0, 6, 6 };
    int aOffsetY[6] = { 6, -6, 6, -6, 6, -6 };
    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x520;
        tMissileParams.nX = UNITS_GetUnitXPosition(pUnit);
        tMissileParams.nY = UNITS_GetUnitYPosition(pUnit);
        tMissileParams.nTargetX = tMissileParams.nX + aOffsetX[i];
        tMissileParams.nTargetY = tMissileParams.nY + aOffsetY[i];
        tMissileParams.pOwner = pOwner;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nGfxArg = 1;
        tMissileParams.nMissile = MISSILE_EXPLOSIVEPOTION;
        int nLevel = STATLIST_UnitGetStatValue(pOwner, STAT_LEVEL, 0) / 5;
        if (nLevel < 1)
        {
            nLevel = 1;
        }
        else if (nLevel > 8)
        {
            nLevel = 8;
        }
        tMissileParams.nSkillLevel = nLevel;
        sub_004CD540_CreateMissile(&tMissileParams);
    }
}

// 0x004BD360
void __fastcall sub_004BD360_SpawnMissileStar(D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nArg)
{
    int aOffsetX[6] = { -6, -6, 0, 0, 6, 6 };
    int aOffsetY[6] = { 6, -6, 6, -6, 6, -6 };
    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x520;
        tMissileParams.nX = UNITS_GetUnitXPosition(pUnit);
        tMissileParams.nY = UNITS_GetUnitYPosition(pUnit);
        tMissileParams.nTargetX = tMissileParams.nX + aOffsetX[i];
        tMissileParams.nTargetY = tMissileParams.nY + aOffsetY[i];
        tMissileParams.pOwner = pOwner;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nGfxArg = 1;
        tMissileParams.nMissile = MISSILE_CHOKINGGASPOITION;
        int nLevel = STATLIST_UnitGetStatValue(pOwner, STAT_LEVEL, 0) / 5;
        if (nLevel < 1)
        {
            nLevel = 1;
        }
        else if (nLevel > 8)
        {
            nLevel = 8;
        }
        tMissileParams.nSkillLevel = nLevel;
        sub_004CD540_CreateMissile(&tMissileParams);
    }
}

// 0x004BD4A0
void __fastcall sub_004BD4A0_InitShrineOverlays(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxt)
{
    D2_ASSERT(pShrinesTxt->bCode < gnShrineHandlerCount_0072779C, 0x337);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->bCode];
    if (pHandler->f_8 != -1)
    {
        sub_0046F0C0(pUnit, 0, pHandler->f_8);
        if (!pUnit || !pUnit->dwAnimMode)
        {
            sub_00470390(pUnit, pHandler->f_8, 3, 0, 0, 0, 0, 0);
        }
    }

    if (pHandler->f_C != -1)
    {
        sub_0046F0C0(pUnit, 0, pHandler->f_C);
        if (!pUnit || !pUnit->dwAnimMode)
        {
            sub_00470390(pUnit, pHandler->f_C, 3, 0, 0, 0, 0, 0);
        }
    }
}

// 0x004BD730
char __fastcall sub_004BD730_AnimCycle(D2UnitStrc* pUnit)
{
    if (!pUnit->dwFlagEx)
    {
        pUnit->dwTickCount = SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwFlagEx = 1;
    }

    if (!(pUnit->dwTickCount & 0x3F) && pUnit->dwAnimMode != 1)
    {
        pUnit->dwAnimMode = 1;
        sub_00624390_AnimInit(pUnit);
    }

    ++pUnit->dwTickCount;

    if (pUnit->dwAnimMode == 2)
    {
        pUnit->dwTickCount += SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwAnimMode = 0;
        sub_00624390_AnimInit(pUnit);
    }

    return 1;
}

// 0x004BD7C0
char __fastcall sub_004BD7C0_AnimCycleUpdate(D2UnitStrc* pUnit)
{
    if (!pUnit->dwFlagEx)
    {
        pUnit->dwTickCount = SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwFlagEx = 1;
    }

    if (!(pUnit->dwTickCount & 0x3F) && pUnit->dwAnimMode != 1)
    {
        pUnit->dwAnimMode = 1;
        sub_00624390_AnimInit(pUnit);
    }

    ++pUnit->dwTickCount;

    if (pUnit->dwAnimMode == 2)
    {
        pUnit->dwTickCount += SEED_RollRandomNumberLoFirst(&pUnit->pSeed) & 0x3F;
        pUnit->dwAnimMode = 0;
        sub_00624390_AnimInit(pUnit);
    }

    sub_004CB460(pUnit);
    return 1;
}

// 0x004BD860
char __fastcall sub_004BD860_TimedSpecial(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 7000, 12000) + dwTick;
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[5];
        UNITS_ChangeAnimMode(pUnit, 3);
        sub_00470610_Refresh(pUnit, 0);
    }

    if (pUnit->dwAnimMode == 3 && pUnit->nSeqCurrentFramePrecise >= (int)pUnit->pObjectData->pObjectTxt->dwFrameCnt[3] - 0x100)
    {
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    sub_004CB460(pUnit);
    return 0;
}

// 0x004BD900
char __fastcall sub_004BD900_TimedSpecialRandom(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount < dwTick)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(pSeed, 23000, 33000) + dwTick;
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[5];
        unsigned int nRoll;
        SEED_STEP_HIFIRST(pSeed, nRoll);
        if (nRoll & 1)
        {
            UNITS_ChangeAnimMode(pUnit, 3);
        }
        else
        {
            UNITS_ChangeAnimMode(pUnit, 4);
        }
        sub_00470610_Refresh(pUnit, 0);
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if ((nMode == 3 || nMode == 4) && pUnit->nSeqCurrentFramePrecise >= (int)pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode] - 0x100)
    {
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    sub_004CB460(pUnit);
    return 0;
}

// 0x004BD9C0
char __fastcall sub_004BD9C0_TimedSpecialExact(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 20000, 30000) + dwTick;
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[5];
        UNITS_ChangeAnimMode(pUnit, 3);
        sub_00470610_Refresh(pUnit, 0);
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode >= 3 && pUnit->nSeqCurrentFramePrecise == pUnit->pObjectData->pObjectTxt->dwFrameCnt[nMode] - 0x100)
    {
        pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[0];
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    sub_004CB460(pUnit);
    return 0;
}

// 0x004BDA60
char __fastcall sub_004BDA60_TimedOperate(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode == 0)
    {
        if (pUnit->dwTickCount < dwTick)
        {
            pUnit->dwTickCount = dwTick + 10000;
            pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[1];
            UNITS_ChangeAnimMode(pUnit, 1);
            sub_00470610_Refresh(pUnit, 0);
        }
    }
    else if (nMode >= 1 && pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 4500, 7500) + dwTick;
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    return 1;
}

// 0x004BDAF0
char __fastcall sub_004BDAF0_AlwaysOne(D2UnitStrc* pUnit)
{
    return 1;
}

// 0x004BDB00
char __fastcall sub_004BDB00_TimedOperateShort(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode == 0)
    {
        if (pUnit->dwTickCount < dwTick)
        {
            pUnit->dwTickCount = dwTick + 3000;
            pUnit->nSeqCurrentFramePrecise = pUnit->pObjectData->pObjectTxt->nStart[1];
            UNITS_ChangeAnimMode(pUnit, 1);
            sub_00470610_Refresh(pUnit, 0);
        }
    }
    else if (nMode >= 1 && pUnit->dwTickCount < dwTick)
    {
        pUnit->dwTickCount = OBJECTS_RollRandomNumber(&pUnit->pSeed, 2500, 7500) + dwTick;
        UNITS_ChangeAnimMode(pUnit, 0);
        sub_00470610_Refresh(pUnit, 0);
    }

    return 1;
}

// 0x004BDB90
char __fastcall sub_004BDB90_AlwaysOne(D2UnitStrc* pUnit)
{
    return 1;
}

// 0x004BDBA0
char __fastcall sub_004BDBA0_RemoveWhenFar(D2UnitStrc* pUnit)
{
    const unsigned int dwTick = GetTickCount();
    if (pUnit->dwTickCount)
    {
        if (dwTick - pUnit->dwTickCount <= 1000)
        {
            return 1;
        }

        if (sub_006416D0_UnitEdgeDistance(pUnit, sub_00463DD0_GetPlayerUnit()) > 25)
        {
            sub_00465F00_RemoveClientUnit(pUnit->dwUnitId, 2);
            return 0;
        }
    }

    pUnit->dwTickCount = dwTick;
    return 1;
}

// 0x004BDBF0
char __fastcall sub_004BDBF0_TriggerOnce219(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode)
    {
        sub_004A30C0_TriggerOnce219();
    }

    return 1;
}

// 0x004BDC10
char __fastcall sub_004BDC10_QuestObject(D2UnitStrc* pUnit)
{
    if (!pUnit || !pUnit->dwAnimMode)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && QUESTRECORD_GetQuestState(sub_004B32D0(), 0x27, 0) && !QUESTRECORD_GetQuestState(sub_004B32D0(), 0x27, 4)
            && sub_006416D0_UnitEdgeDistance(pUnit, sub_00463DD0_GetPlayerUnit()) < 25)
        {
            if (pPlayer->pDynamicPath)
            {
                D2Common_10153(pPlayer->pDynamicPath);
            }

            sub_00481030_DoUnitAction(0x13, pPlayer, 2, pUnit->dwUnitId, 0);
            UNITS_ChangeAnimMode(pUnit, 2);
            sub_00470610_Refresh(pUnit, 0);
        }
    }

    return 1;
}

// 0x004BDCA0
char __fastcall sub_004BDCA0_TriggerOnceD3(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode)
    {
        sub_004A30A0_TriggerOnceD3();
    }

    return 1;
}

// 0x004BDCC0
char __fastcall sub_004BDCC0_UpdateEnvObject(D2UnitStrc* pUnit)
{
    if (GetTickCount() > pUnit->dwTickCount)
    {
        sub_004BC5E0_UpdateEnvObject(pUnit, 0);
        pUnit->dwTickCount = GetTickCount() + 500;
    }

    return 1;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x004BDCF0
char __fastcall sub_004BDCF0_TimedOverlay(D2UnitStrc* pUnit)
{
    if (GetTickCount() > pUnit->dwTickCount)
    {
        if (!pUnit->dwAnimMode)
        {
            sub_00470390(pUnit, 0x48, 3, 0, 0, 0, 0, 0);
            pUnit->dwTickCount = GetTickCount() + 500;
        }
        else
        {
            sub_0046F0C0(pUnit, 0, 0x48);
            pUnit->dwTickCount = GetTickCount() + 500;
        }
    }
    return 1;
}

// 0x004BDD50
char __fastcall sub_004BDD50_RandomSound(D2UnitStrc* pUnit)
{
    if (GetTickCount() > pUnit->dwTickCount)
    {
        unsigned int nRoll;
        SEED_STEP_HIFIRST(&pUnit->pSeed, nRoll);
        if (nRoll % 100 < 10)
        {
            sub_004B9A00(0x9C9, pUnit, 0, 0, 0);
        }
        SEED_STEP_HIFIRST(&pUnit->pSeed, nRoll);
        pUnit->dwTickCount = GetTickCount() + nRoll % 60 * 1000;
    }
    return 1;
}

// 0x004BDE00
char __fastcall sub_004BDE00_FinishOperate(D2UnitStrc* pUnit)
{
    if (pUnit->dwAnimMode == 1 && pUnit->nSeqCurrentFramePrecise == pUnit->pObjectData->pObjectTxt->nStart[1] << 8)
    {
        pUnit->dwAnimMode = 2;
        pUnit->nSeqCurrentFramePrecise = 0;
        sub_00470610_Refresh(pUnit, 0);
        sub_00624390_AnimInit(pUnit);
    }
    return 1;
}

// 0x004BDE40
char __fastcall sub_004BDE40_ReportPosition(D2UnitStrc* pUnit)
{
    if (sub_004A3110_GetFlag025F() && !sub_004A3120_IsQuestUnitPresent())
    {
        sub_004A3150_SpawnQuestUnits(CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit));
    }
    return 1;
}


static void __stdcall sub_004BD5C0_OperateShrine(D2UnitTargetStrc* pTarget, D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = 0;
    int nIndex;
    if (UNITS_IsShrine(pUnit))
    {
        pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
        nIndex = pShrinesTxt->bCode;
    }
    else
    {
        nIndex = DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nShrineFunction;
    }

    D2UnitStrc* pPlayer = sub_00463990(pTarget->nParam1, 0);
    if (!pPlayer)
        return;

    if (nIndex > 0 && nIndex < gnShrineHandlerCount_0072779C && gShrineHandlers_006DA8C0[nIndex].pfnOperate)
        gShrineHandlers_006DA8C0[nIndex].pfnOperate(pUnit, pPlayer, pShrinesTxt);

    sub_004BD550_PlayShrineSound(pPlayer, pUnit);
}


