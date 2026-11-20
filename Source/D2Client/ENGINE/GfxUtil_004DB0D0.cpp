#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2GfxCodeRecordStrc;
struct D2GfxCodeTableStrc;
struct D2OverlayTxt;
struct D2MonStats2Txt;
struct D2MissilesTxt;
struct D2MonGfxCacheStrc;

#pragma pack(push, 1)
struct D2GfxCodeRecordStrc
{
    unsigned char nCode;
    unsigned char unk0x01;
    unsigned char nValue;
    unsigned char unk0x03[6];
};

struct D2GfxCodeTableStrc
{
    unsigned char nCount;
    unsigned char unk0x01[0x1B];
    D2GfxCodeRecordStrc f_1C[1];
};

#pragma pack(pop)

struct D2OverlayTxt
{
    char unk0x00[0x80];
    unsigned char nNumDirections;
    unsigned char nLocalBlood;
    unsigned short pad0x82;
};



struct D2MonGfxCacheStrc
{
    int nModeFlags[16];
    char unk0x40[0x60];
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gdwGlobal_007A8928; // 0x007A8928
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2MonGfxCacheStrc* __fastcall sub_0046F9D0_GetMonGfxCache(int nMonsterId); // 0x0046F9D0
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

// 0x004DB0D0
int __fastcall sub_004DB0D0_UpdateGfxEntry(const unsigned char* pData, int nCode)
{
    int nResult = 0;
    if (pData && nCode < 0x10)
    {
        const D2GfxCodeTableStrc* pTable = (const D2GfxCodeTableStrc*)pData;
        pData += 0x1C;
        for (int i = 0; i < pTable->nCount; ++i)
        {
            if (((const D2GfxCodeRecordStrc*)pData)->nCode == nCode)
            {
                nResult = ((const D2GfxCodeRecordStrc*)pData)->nValue;
                break;
            }
            pData += sizeof(D2GfxCodeRecordStrc);
        }
    }
    return nResult;
}

// build: context DATATBLS_GetOverlayTxtRecordInline
static D2OverlayTxt* DATATBLS_GetOverlayTxtRecordInline(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }

    return 0;
}

// 0x004DAD50
static int sub_004DAD50_GetOverlayDirections(int nOverlay)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecordInline(nOverlay);
    if (!pOverlayTxt)
    {
        return 1;
    }

    return pOverlayTxt->nNumDirections;
}

// 0x004DAF70
static int __stdcall sub_004DAF70_GetUnitModeDirections(D2UnitStrc* pUnit, int nMode, int nClassId, int nUnitType)
{
    if (nMode < 0)
    {
        return 1;
    }

    int nDirections = 1;
    switch (nUnitType)
    {
    case 0:
        if (!gdwGlobal_007A8928 && pUnit == sub_00463DD0())
        {
            nDirections = 16;
        }
        else
        {
            nDirections = 8;
        }
        break;

    case 1:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (pMonStats2TxtRecord)
        {
            nDirections = pMonStats2TxtRecord->nModeDirections[nMode];
            if (nDirections == 8)
            {
                D2MonGfxCacheStrc* pCache = sub_0046F9D0_GetMonGfxCache(nClassId);
                if (pCache && !pCache->nModeFlags[nMode])
                {
                    nDirections = 4;
                }
            }
        }
        break;
    }

    case 3:
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nClassId);
        if (pMissilesTxtRecord)
        {
            nDirections = pMissilesTxtRecord->nNumDirections;
        }
        break;
    }

    case 6:
        nDirections = sub_004DAD50_GetOverlayDirections(nClassId);
        break;
    }

    return nDirections;
}

// build: context UNITS_GetUnitTypeInline
static int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

// build: context UNITS_GetClassIdInline
static int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x004DB1E0
static void __stdcall sub_004DB1E0_SetDeathDirection(unsigned int nDirection, int bSet, D2UnitStrc* pUnit, int nDirCount, int nSrcDirCount)
{
    if (!bSet)
    {
        return;
    }

    int nUnitType = UNITS_GetUnitTypeInline(pUnit);
    int nClassId = UNITS_GetClassIdInline(pUnit);
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\GfxUtil.cpp", 0x53C);
    switch (nUnitType)
    {
    case 0:
        if ((nMode == 0 || nMode == 17) && nDirCount != nSrcDirCount)
        {
            sub_006488A0_SetDirection(pUnit->pDynamicPath, nDirection);
        }
        break;

    case 1:
        if ((nMode == 0 || nMode == 12) && nDirCount != nSrcDirCount)
        {
            sub_006488A0_SetDirection(pUnit->pDynamicPath, nDirection);
        }
        break;
    }
}

// 0x004DB290
// calling-convention shim (not game code)
static void sub_004DB290_ConvertDirection(int nSrcDirCount, int nDirCount, unsigned int* pDirection)
{
    if (nSrcDirCount == 8)
    {
        if (nDirCount == 4)
        {
            const unsigned int nIndex = *pDirection * 8 >> 6;
            *pDirection = (unsigned int)sub_00600CB0_ConvertDirection(nIndex, 8, nDirCount, 0) * 64 / 8;
        }
    }
    else if (nSrcDirCount == 16 && nDirCount == 8)
    {
        const unsigned int nIndex = *pDirection * 16 >> 6;
        *pDirection = (unsigned int)sub_00600CB0_ConvertDirection(nIndex, 16, nDirCount, 0) * 64 / 16;
    }
}

// 0x004DB2E0
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nMode, unsigned int* pDirection, int* pIndex, int* pDirCount, int nSrcDirCount, int bSet)
{
    if (*pDirection >= 64)
    {
        *pDirCount = 1;
        *pIndex = 0;
        return;
    }

    *pDirCount = sub_004DAF70_GetUnitModeDirections(pUnit, nMode, nClassId, nUnitType);
    if (bSet)
    {
        sub_004DB290_ConvertDirection(nSrcDirCount, *pDirCount, pDirection);
        sub_004DB1E0_SetDeathDirection(*pDirection, bSet, pUnit, *pDirCount, nSrcDirCount);
    }
    *pIndex = sub_00600E20_GetDirectionIndex64B(*pDirection, nSrcDirCount);
}
