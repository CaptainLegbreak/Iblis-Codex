#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2GameObjs.h"
#include "D2MissileIds.h"
#include "D2StatIds.h"
#include "D2Primitives.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"

struct D2AutomapCellStrc;

struct Pad40_00457460;

struct Obj00457460;

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

extern int gdwGlobal_007A51E4; // 0x007A51E4

extern int gdwGlobal_007A51E0; // 0x007A51E0

extern int gdwGlobal_007113E8; // 0x007113E8

struct Pad40_00457460 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00457460 {
    Pad40_00457460 tPad000;
    Pad40_00457460 tPad040;
    Pad40_00457460 tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwFlagsC4;
};

int gdwGlobal_007A51E8; // 0x007A51E8

int gaAutomapCellTable_007A3150[0x800]; // 0x007A3150

static int gnAutomapOffsetX_007A5198; // 0x007A5198

static int gnAutomapOffsetY_007A519C; // 0x007A519C

static int gnAutomapScale_00711254; // 0x00711254

struct D2GfxLightStrc;

struct D2ShrineHandlerStrc
{
    void (__fastcall* pfnInit)(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxt);
    void (__fastcall* pfnOperate)(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ShrinesTxt* pShrinesTxt);
    int f_8;
    int f_C;
    int nSoundId;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

extern D2DrlgActStrc* gpAct_007A0634;                                                                       // 0x007A0634

extern D2ShrineHandlerStrc gShrineHandlers_006DA8C0[];                                                      // 0x006DA8C0

extern int gnShrineHandlerCount_0072779C;                                                                   // 0x0072779C

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

void __fastcall sub_00457460(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x00457460

void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount);               // 0x0046C320

void __fastcall sub_0046F0C0(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x0046F0C0

char __fastcall sub_004BDEE0(D2UnitStrc* pUnit); // 0x004BDEE0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_00464930_FreeLight(D2UnitStrc* pUnit);                                                  // 0x00464930

void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610

D2GfxLightStrc* __fastcall sub_00474160_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00

void __fastcall sub_004CB460_UpdateModeSound(D2UnitStrc* pUnit);                                                            // 0x004CB460

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct);                                          // 0x0061AB70

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit);                              // 0x00621B70

void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord);    // 0x00621BB0

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830

int __stdcall sub_00624390_AnimInit(D2UnitStrc* ptUnit); // 0x00624390

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId);                                        // 0x006414B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

typedef char (__fastcall* D2ObjectClientFn)(D2UnitStrc* pUnit);

void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900

void __fastcall sub_00466CB0_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg);                             // 0x00466CB0

void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40

int __stdcall UNITROOM_IsUnitInRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit);                            // 0x0064C260

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634

extern D2ObjectClientFn gapfnObjectClientFn_007277F0[];                                                     // 0x007277F0

#define SEED_STEP_HIFIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

struct D2ShrinesTxt;

struct D2ObjectDataStrc;

struct D2UnitTargetStrc;

struct D2ShrineHandlerStrc;

union D2SeedStrc;

struct D2PlayerDataStrc;

struct D2StaticPathStrc;

struct D2MissileStrc;

extern "C" const char gszUnitSourceFile_006DAA8C[];

void __fastcall sub_004CB460(D2UnitStrc* pUnit);

int __stdcall sub_00621B00_IsShrine(D2UnitStrc* pUnit);

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

static void sub_004BCA90_FinishDoorMode(D2UnitStrc* pUnit);

void sub_004BCB20_StepDoorFrame(D2UnitStrc* pUnit); // 0x004BCB20

static void sub_004BCBB0_UpdateObjectFrame(D2UnitStrc* pUnit);

static void __stdcall sub_004BCDE0_SetDoorMode(int bSelectable, D2UnitStrc* pUnit, int nMode);

void __stdcall sub_004BD5C0_OperateShrine(D2UnitTargetStrc* pTarget, D2UnitStrc* pUnit); // 0x004BD5C0

static void __stdcall sub_004BC580_UpdateLight(D2UnitStrc* pUnit, unsigned short nDiameter, int nRed, int nGreen, int nBlue);

void __fastcall sub_004BC720_InitObject(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nObjectId, unsigned char nMode);

static void __stdcall sub_004BD550_PlayShrineSound(D2UnitStrc* pPlayer, D2UnitStrc* pUnit);

static void sub_004BD650_InitShrine(D2UnitStrc* pUnit);

void __fastcall sub_004BD6B0_SetShrine(D2UnitStrc* pUnit);

void __fastcall sub_004BD6D0_ObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget);

void __fastcall sub_004BDFF0_UpdateObject(D2UnitStrc* pUnit);



static void sub_004BCB20_StepDoorFrame(D2UnitStrc* pUnit);

static void sub_004BCF60_SetObjectMode(D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget);

static void sub_004BCF60_SetObjectMode(D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget);

// 0x00457450
int __fastcall sub_00457450_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x00457460
extern "C" __declspec(dllexport) void __fastcall sub_00457460(Obj00457460* pObj, unsigned int dwMask, int bSet) {
    if (pObj) {
        if (bSet) {
            pObj->dwFlagsC4 |= dwMask;
        } else {
            pObj->dwFlagsC4 &= ~dwMask;
        }
    }
}

// 0x00457750
int __fastcall sub_00457750_SaveAutomapCenters(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Centers", 0, nValue);
    gdwGlobal_007113E0 = nValue;
    return nValue;
}

// 0x00457780
int __fastcall sub_00457780_SaveAutomapLeft(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Left", 0, nValue);
    gdwGlobal_007A51E4 = nValue;
    gdwGlobal_007A51E8 = nValue;
    gdwGlobal_007A51E0 = nValue;
    return nValue;
}

// 0x004577C0
int __fastcall sub_004577C0_SaveAutomapParty(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Party", 0, nValue);
    gdwGlobal_007113E4 = nValue;
    return nValue;
}

// 0x004577F0
int __fastcall sub_004577F0_SaveAutomapPartyNames(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Party Names", 0, nValue);
    gdwGlobal_007113E8 = nValue;
    return nValue;
}

// 0x00457810
static inline void sub_00457810_SubtractAutomapOffset(int* pX, int* pY)
{
    *pX -= gnAutomapOffsetX_007A5198;
    *pY -= gnAutomapOffsetY_007A519C;
}

// 0x00457830
static inline void sub_00457830_ScaleAutomapPoint(int* pX, int* pY)
{
    *pX /= gnAutomapScale_00711254;
    *pY /= gnAutomapScale_00711254;
    *pX += 8;
    *pY -= 8;
    *pX -= gnAutomapOffsetX_007A5198;
    *pY -= gnAutomapOffsetY_007A519C;
}

void __fastcall sub_M117_Emit_00457810(int* pX, int* pY, int nScale)
{
    gnAutomapScale_00711254 = nScale;
    sub_00457810_SubtractAutomapOffset(pX, pY);
    sub_00457830_ScaleAutomapPoint(pX, pY);
    gnAutomapOffsetX_007A5198 = *pX;
    gnAutomapOffsetY_007A519C = *pY;
}

// 0x00457AC0
int __fastcall sub_00457AC0_CompareAutomapCells(const D2AutomapCellStrc* pA, const D2AutomapCellStrc* pB)
{
    int nResult = pA->yPixel - pB->yPixel;
    if (!nResult)
    {
        nResult = pA->xPixel - pB->xPixel;
        if (!nResult)
        {
            const int nCellA = pA->nCellNo;
            if (gaAutomapCellTable_007A3150[nCellA] != -1)
            {
                const int nCellB = pB->nCellNo;
                if (gaAutomapCellTable_007A3150[nCellA] != gaAutomapCellTable_007A3150[nCellB])
                {
                    nResult = nCellA - nCellB;
                }
            }
        }
    }

    return nResult;
}

// 0x004BC580
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

// 0x004BC5E0
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

// 0x004BC720
void __fastcall sub_004BC720_InitObject(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nObjectId, unsigned char nMode)
{
    pUnit->pLight = 0;
    pUnit->dwAnimMode = nMode;
    pUnit->pObjectData = (D2ObjectDataStrc*)FOG_Alloc(sizeof(D2ObjectDataStrc), ".\\UNIT\\Object.cpp", 0x76, 0);
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
        const int eLevelId = DUNGEON_GetTownLevelIdFromActNo(nMode);
        D2_ASSERT(eLevelId <= 0xFF, 0x95);
        pUnit->pObjectData->InteractType = eLevelId;
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

struct D2UnitStrc;

// 0x004BC8D0
void __fastcall sub_004BC8D0_UpdateObjectOverlay(D2UnitStrc* pUnit)
{
    if (!pUnit->pObjectData->pObjectTxt->nOverlay)
    {
        return;
    }

    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0x98:
        sub_00470390(pUnit, 0xB6, 3, 0, 0, 0, 0, 0);
        return;

    case 0x95:
        if (pUnit->dwAnimMode == 1)
        {
            sub_00470390(pUnit, 0xB6, 3, 0, 0, 0, 0, 0);
        }
        return;

    case 0x162:
    case 0x163:
    case 0x164:
    case 0x18D:
    case 0x195:
    case 0x196:
    case 0x197:
    case 0x1C7:
        if (pUnit->dwAnimMode == 0)
        {
            sub_00470390(pUnit, 0x47, 3, 0, 0, 0, 0, 0);
        }
        return;
    }
}

// 0x004BCA50
void __fastcall sub_004BCA50_ReleaseUnit(D2UnitStrc* pUnit)
{
    sub_0046EC10_FreeGfxData(pUnit);
    if (gpGlobal_007A0634)
    {
        UNITS_FreeCollisionPath(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
        sub_00464930_FreeLight(pUnit);
    }

    FOG_Free(pUnit->pPlayerData, ".\\UNIT\\Object.cpp", 0xFE, 0);
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

// 0x004BCF60
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
            const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
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

    sub_004CB460_UpdateModeSound(pUnit);
    sub_00624390_AnimInit(pUnit);
    if (!pTxt->nBlocksLight[pUnit->dwAnimMode])
        pUnit->dwFlags |= 0x20;
    else
        pUnit->dwFlags &= ~0x20;
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

// 0x004BD550
static void __stdcall sub_004BD550_PlayShrineSound(D2UnitStrc* pPlayer, D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
    D2_ASSERT(pShrinesTxt, 0x34D);
    D2_ASSERT(pShrinesTxt->bCode < gnShrineHandlerCount_0072779C, 0x34E);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->bCode];
    if (pHandler->nSoundId)
        sub_004B9A00(pHandler->nSoundId, pPlayer, 0, 0, 0);
}

// 0x004BD5C0
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

// 0x004BD650
static void sub_004BD650_InitShrine(D2UnitStrc* pUnit)
{
    D2ShrinesTxt* pShrinesTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
    D2_ASSERT(pShrinesTxt, 0x37A);
    D2_ASSERT(pShrinesTxt->bCode < gnShrineHandlerCount_0072779C, 0x37B);

    D2ShrineHandlerStrc* pHandler = &gShrineHandlers_006DA8C0[pShrinesTxt->bCode];
    if (pHandler->pfnInit)
        pHandler->pfnInit(pUnit, pShrinesTxt);
}

// 0x004BD6B0
void __fastcall sub_004BD6B0_SetShrine(D2UnitStrc* pUnit)
{
    UNITS_SetShrineTxtRecordInObjectData(pUnit, DATATBLS_GetShrinesTxtRecord(pUnit->pObjectData->InteractType));
    sub_004BD650_InitShrine(pUnit);
}

// 0x004BD6D0
void __fastcall sub_004BD6D0_ObjectCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget)
{
    switch (nCommand)
    {
    case 3:
        sub_004BCF60_SetObjectMode(pUnit, pTarget);
        if (UNITS_IsShrine(pUnit))
            sub_004BD650_InitShrine(pUnit);
        return;

    case 0x15:
        sub_004BD5C0_OperateShrine(pTarget, pUnit);
        return;

    default:
        D2_ASSERT(0, 0x39C);
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

// 0x004BDEE0
char __fastcall sub_004BDEE0(D2UnitStrc* pUnit)
{
    D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
    unsigned char nClientFn = pTxt->nClientFn;
    D2_ASSERT(nClientFn < 0x13, 0x546);
    if (nClientFn)
    {
        return gapfnObjectClientFn_007277F0[nClientFn](pUnit);
    }

    return 1;
}

// 0x004BDFE0
void __fastcall sub_004BDFE0_SetObjectName(D2UnitStrc* pUnit, const char* szName)
{
    SStrCopy(pUnit->pObjectData->szOwner, szName, 0x10);
}

// 0x004BDFF0
void __fastcall sub_004BDFF0_UpdateObject(D2UnitStrc* pUnit)
{
    sub_004BCBB0_UpdateObjectFrame(pUnit);
    if (pUnit->pObjectData->pObjectTxt->nClientFn <= 3 || sub_004BDEE0(pUnit))
        sub_004CB460_UpdateModeSound(pUnit);
}

// 0x004C1A70
void __fastcall sub_004C1A70_ReleaseItemUnit(D2UnitStrc* pUnit)
{
    sub_0046EC10_FreeGfxData(pUnit);
    if (ITEMS_CheckIfSocketable(pUnit))
    {
        sub_00466CB0_RemoveInventoryUnits(pUnit, 0);
        INVENTORY_FreeInventory(pUnit->pInventory);
        pUnit->pInventory = 0;
    }

    if (gpGlobal_007A0634)
    {
        UNITS_FreeCollisionPath(pUnit);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (UNITROOM_IsUnitInRoom(pRoom, pUnit))
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
    }
}

// 0x004C1AD0
void __fastcall sub_004C1AD0_UpdateAnim(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x348);
    switch (pUnit->dwAnimMode)
    {
    case 5:
        if (UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            pUnit->dwAnimMode = 3;
            break;
        }

        UNITS_UpdateFrame(pUnit);
        return;

    case 3:
        pUnit->dwFlags |= 2;
        if (sub_0046E100(pUnit, 0x46))
        {
            return;
        }
        break;

    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
        pUnit->dwFlags &= ~2;
        return;

    default:
        D2_ASSERT(0, 0x362);
    }

    sub_00470390(pUnit, 0x46, 6, 8, 0, 0, 8, 0);
}

#include "gen/data/Source/D2Client/UNIT/Object.inc"
