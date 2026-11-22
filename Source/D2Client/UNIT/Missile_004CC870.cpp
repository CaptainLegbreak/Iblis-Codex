#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2ClientGame.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"

union D2SeedStrc;
struct D2MissilesTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection); // 0x006488A0

static inline D2MissilesTxt* CLTMISS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// 0x004CC870
void __fastcall sub_004CC870_InitFromOwner(D2UnitStrc* pMissile, int nInitArg)
{
    D2UnitStrc* pOwner = (D2UnitStrc*)nInitArg;
    if (!pMissile)
        return;

    D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pOwner)
        return;

    int nOffset = 0;
    if (pMissilesTxtRecord->dwCltParam[1] > 0)
        nOffset = SEED_RollLimitedRandomNumber(&pOwner->pSeed, pMissilesTxtRecord->dwCltParam[1]) - pMissilesTxtRecord->dwCltParam[1] / 2;

    sub_004DA1D0_SetMotionVectorA(pMissile, 0, 0, nOffset);
    PATH_SetDirection(pMissile->pDynamicPath, PATH_GetDirection(pOwner->pDynamicPath));
    D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
    pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nAnimLen) << 8;
}

