#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2CelContext.h"
#include "D2LevelTxt.h"
struct D2StoredUnitRecordStrc;
struct D2UnitStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};





extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                      // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
short __fastcall sub_00465400_GetPlayerRosterField22(D2UnitStrc* pUnit); // 0x00465400
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit);                                     // 0x00464A60
int __fastcall sub_00478EE0_CountPets(D2UnitStrc* pOwner, int nPetType);                                 // 0x00478EE0
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny);                  // 0x00478F20
int __fastcall sub_00479080_GetPetLife(int nUnitId);                                                       // 0x00479080
D2StoredUnitRecordStrc* __fastcall sub_004795A0_GetNextEntry(D2StoredUnitRecordStrc* pEntry);              // 0x004795A0
extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
int __fastcall sub_00479BA0(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479BA0
unsigned short __fastcall sub_00479BC0_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                      // 0x00479BC0
int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord);                              // 0x0047A0C0
int __fastcall sub_0047A150_GetPartyLife(int nUnitId);                                                     // 0x0047A150
D2CelFileStrc* __fastcall sub_00493240_PetIconForType(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle); // 0x00493240
void __stdcall sub_00493100_DrawNumber(int nValue, int nX);                                                // 0x00493100
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB);                                         // 0x0046A530
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
int __fastcall sub_00501820(const Unicode* wszText);                                             // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2CelFileStrc* gapHirelingIcons_007BEEB0[7];                                                         // 0x007BEEB0

static int gnGlobal_007BEECC;                                                                               // 0x007BEECC
static unsigned char gnLifeColorHigh_007BEED0;                                                              // 0x007BEED0
static unsigned char gnLifeColorMid_007BEED1;                                                               // 0x007BEED1
static unsigned char gnLifeColorLow_007BEED2;                                                               // 0x007BEED2
static unsigned char gbLifeColorsInit_007BEED3;                                                             // 0x007BEED3
static int gnPopupX_007BEED4;                                                                               // 0x007BEED4
static int gnPopupY_007BEED8;                                                                               // 0x007BEED8
static int gbPopupShown_007BEEDC;                                                                           // 0x007BEEDC
static int gnGlobal_007BEEE0;                                                                               // 0x007BEEE0
static unsigned char gbGlobal_007BEEE4;                                                                     // 0x007BEEE4
static int gdwPopupTick_007BEEE8;                                                                           // 0x007BEEE8

static void __stdcall sub_00492FA0_DrawFittedText(int nX, int nY, int nColor, Unicode* pText)
{
    const int nOldFont = sub_00502EF0(6);
    Unicode* pEnd = &pText[31];
    while (sub_00501820(pText) > 0x42)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    nX += 0x16 - sub_00501820(pText) / 2;
    if (nX < 0)
        nX = 0;
    sub_00502320(pText, nX, nY, nColor, 0);
    sub_00502EF0(nOldFont);
}

static void __stdcall sub_00493020_DrawPetTypeName(int nX, int nY, int nPetType)
{
    D2PetTypeTxt* pPetTypeTxt = (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount) ? &sgptDataTables->pPetTypeTxt[nPetType] : 0;
    if (pPetTypeTxt && pPetTypeTxt->wStringId > 0 && pPetTypeTxt->wStringId != 0x1506)
    {
        Unicode wszName[32];
        sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(pPetTypeTxt->wStringId));
        sub_00492FA0_DrawFittedText(nX, nY, 0, wszName);
    }
}

static void __stdcall sub_004930A0_DrawRosterName(const char* szName, int nX, int nY)
{
    unsigned short wszName[32];
    for (int i = 0; i < 32; ++i)
    {
        wszName[i] = 0;
    }
    sub_00526320_ToUnicode((Unicode*)wszName, szName, 32);
    sub_00492FA0_DrawFittedText(nX, nY, 0, (Unicode*)wszName);
}

static void __stdcall sub_00493A00_DrawLifeBar(int nPetType, int nX, int nUnitId)
{
    int nLife = nPetType ? sub_00479080_GetPetLife(nUnitId) : sub_0047A150_GetPartyLife(nUnitId);
    if (!nLife)
        return;

    const int nXEnd = nX + 0x2E;
    nLife = nLife <= 0 ? 0 : nLife;
    const int nPct = nLife < 100 ? nLife : 100;
    const int nXFill = nX + nPct * 0x2E / 100;
    if (!gbLifeColorsInit_007BEED3)
    {
        gbLifeColorsInit_007BEED3 = 1;
        gnLifeColorHigh_007BEED0 = D2Win_10034_MixRGB(0, 0x80, 0);
        gnLifeColorMid_007BEED1 = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
        gnLifeColorLow_007BEED2 = D2Win_10034_MixRGB(0xFF, 0, 0);
    }
    unsigned char nColor = gnLifeColorHigh_007BEED0;
    if (nPct < 50)
        nColor = gnLifeColorMid_007BEED1;
    if (nPct < 25)
        nColor = gnLifeColorLow_007BEED2;
    D2GFX_DrawBox(nX, 0xE, nXFill, 0x13, nColor, 5);
    D2GFX_DrawBox(nXFill, 0xE, nXEnd, 0x13, 0, 5);
}

static void __stdcall sub_00493B00_DrawUnitName(D2UnitStrc* pUnit, int nX, int nY)
{
    if (pUnit)
    {
        unsigned short wszName[32];
        memset(wszName, 0, sizeof(wszName));
        sub_00526790((Unicode*)wszName, sub_00464A60_GetUnitName(pUnit), 32);
        wszName[31] = 0;
        sub_00492FA0_DrawFittedText(nX, nY, 0, (Unicode*)wszName);
    }
}

static int __stdcall sub_00493B50_DrawRosterIcons(int* pnY, int* pbAlternate, D2UnitStrc* pPlayer, int* pnX)
{
    int bDrawn = 0;
    const unsigned short nIndex = sub_00465400_GetPlayerRosterField22(pPlayer);
    int nPlayerId;
    int nUnitId;
    if (!pPlayer)
        nPlayerId = -1;
    else
        nPlayerId = pPlayer->dwUnitId;

    if (nIndex != 0xFFFF && !gnGlobal_007BEECC)
    {
        for (D2StoredUnitRecordStrc* pEntry = sub_004795A0_GetNextEntry(0); pEntry; pEntry = sub_004795A0_GetNextEntry(pEntry))
        {
            if (nIndex != sub_00479BC0_GetEntryIndex(pEntry))
                continue;

            nUnitId = sub_0047A0C0_GetRecordUnitId(pEntry);
            if (nUnitId == nPlayerId)
                continue;

            D2CelFileStrc* pCelFile;
            switch (sub_00479BA0(pEntry))
            {
            case 0:
                pCelFile = gapHirelingIcons_007BEEB0[0];
                break;
            case 1:
                pCelFile = gapHirelingIcons_007BEEB0[1];
                break;
            case 2:
                pCelFile = gapHirelingIcons_007BEEB0[2];
                break;
            case 3:
                pCelFile = gapHirelingIcons_007BEEB0[3];
                break;
            case 4:
                pCelFile = gapHirelingIcons_007BEEB0[4];
                break;
            case 5:
                pCelFile = gapHirelingIcons_007BEEB0[5];
                break;
            case 6:
                pCelFile = gapHirelingIcons_007BEEB0[6];
                break;
            default:
                continue;
            }

            if (!pCelFile)
                continue;

            sub_00493A00_DrawLifeBar(0, *pnX, nUnitId);
            sub_004930A0_DrawRosterName(sub_004795C0_GetEntryName(pEntry), *pnX, *pnY);
            if (*pbAlternate)
            {
                *pnY -= *pbAlternate;
                *pbAlternate = 0;
            }
            else
            {
                *pbAlternate = 10;
                *pnY += 10;
            }
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = pCelFile;
            sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
            *pnX += 0x38;
            bDrawn = 1;
        }

        if (bDrawn)
            return 1;
    }

    return 0;
}

// 0x00493CE0
static int __stdcall sub_00493CE0_DrawSummonIcon(D2UnitStrc* pPlayer, int* pbAlternate, int* pnX, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = sub_00493240_PetIconForType(pPlayer, 7, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(7, *pnX, nUnitId);
    sub_00493B00_DrawUnitName(sub_00463990(nUnitId, 1), *pnX, *pnY);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    gnPopupX_007BEED4 = *pnX;
    gnPopupY_007BEED8 = *pnY;
    if (gnGlobal_007BEEE0 && gdwPopupTick_007BEEE8 && GetTickCount() - gdwPopupTick_007BEEE8 >= 700)
        gbPopupShown_007BEEDC = 1;

    if (gbPopupShown_007BEEDC)
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 7, 0);
    else
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);

    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493E10_DrawPetIcon(D2UnitStrc* pPlayer, int* pnX, int* pbAlternate, int nPetType, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = sub_00493240_PetIconForType(pPlayer, nPetType, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(nPetType, *pnX, nUnitId);
    sub_00493020_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493EB0_DrawPetCountIcon(D2UnitStrc* pPlayer, int* pnY, int* pbAlternate, int* pnX, int nPetType)
{
    const int nCount = sub_00478EE0_CountPets(pPlayer, nPetType);
    if (!nCount)
        return 0;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    int bSingle = 0;
    tContext.pCellFile = sub_00493240_PetIconForType(pPlayer, nPetType, &nUnitId, &bSingle);
    if (!tContext.pCellFile)
        return 0;

    if (nCount == 1 && bSingle)
        sub_00493A00_DrawLifeBar(nPetType, *pnX, sub_00478F20_FindPetIdByOwner(pPlayer, nPetType, 0));

    sub_00493100_DrawNumber(nCount, *pnX);
    sub_00493020_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493F80_DrawPetIcon3(D2UnitStrc* pPlayer, int* pnX, int* pbAlternate, int nPetType, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = sub_00493240_PetIconForType(pPlayer, nPetType, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(nPetType, *pnX, nUnitId);
    sub_00493020_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

void __cdecl sub_00494020_DrawPetIcons()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nY = 0x48;
    int bAlternate = 0;
    int nX = 0xF;
    const int nMode = sub_0045AE90();
    if (nMode != 3 && nMode != 2 && !sub_004538D0(9) && !sub_004538D0(0xB) && gnGlobal_007BEECC != 2)
    {
        if (sub_0044DCC0() && !sub_004538D0(0x23) && gnGlobal_007BEECC != 2 && sub_00478F20_FindPetIdByOwner(pPlayer, 7, 0) != -1)
            sub_00455F20(0x23, 0, 0);

        int bAny = sub_00493B50_DrawRosterIcons(&nY, &bAlternate, pPlayer, &nX);
        bAny |= sub_00493CE0_DrawSummonIcon(pPlayer, &bAlternate, &nX, &nY);
        for (int i = 0; i < sgptDataTables->nPetTypeTxtRecordCount; ++i)
        {
            D2PetTypeTxt* pPetTypeTxt = (i >= 0 && i < sgptDataTables->nPetTypeTxtRecordCount) ? &sgptDataTables->pPetTypeTxt[i] : 0;
            if (!pPetTypeTxt)
                continue;

            switch (pPetTypeTxt->nIconType)
            {
            case 1:
                bAny |= sub_00493E10_DrawPetIcon(pPlayer, &nX, &bAlternate, i, &nY);
                break;
            case 2:
                bAny |= sub_00493EB0_DrawPetCountIcon(pPlayer, &nY, &bAlternate, &nX, i);
                break;
            case 3:
                bAny |= sub_00493F80_DrawPetIcon3(pPlayer, &nX, &bAlternate, i, &nY);
                break;
            }
        }

        if (!bAny)
            sub_00455F20(0x13, 1, 0);

        if (gbGlobal_007BEEE4 && !sub_004538D0(0x24) && sub_00455F20(0x24, 0, 0))
        {
            SRegSaveValue("Diablo II", "PopupHireling", 0, 1);
            gbGlobal_007BEEE4 = 0;
        }

        if (gnGlobal_007BEEE0 && gbPopupShown_007BEEDC)
        {
            Unicode wszText[0x100];
            wszText[0].wChar = 0;
            const Unicode* wszSuffix = D2LANG_GetStringFromTblIndex(0x58A2);
            const Unicode* wszFormat = D2LANG_GetStringFromTblIndex(0x58A3);
            const Unicode* wszMiddle = D2LANG_GetStringFromTblIndex(0xF9E);
            sub_005269D0(0x100, wszText, wszFormat, sub_0046A530_GetKeyName(0x36, 1));
            sub_00526700(wszText, wszMiddle);
            sub_00526700(wszText, wszSuffix);
            D2Win_10129_DrawFramedText(wszText, gnPopupX_007BEED4, gnPopupY_007BEED8 + 0x24, 0, 0);
        }
    }
    else
    {
        gbPopupShown_007BEEDC = 0;
        gnGlobal_007BEEE0 = 0;
    }
}
