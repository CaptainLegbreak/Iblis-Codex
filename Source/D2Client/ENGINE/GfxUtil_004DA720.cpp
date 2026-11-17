#include "D2Client.h"

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    int unk0x08[22];
    D2InventoryStrc* pInventory;
    int unk0x64[25];
    unsigned int dwFlagEx;
};

struct D2CelContextStrc
{
    int nArg0;
    unsigned char nFlags;
    unsigned char nComponent;
    short unk0x06;
    int nType;
    int nClass;
    int nMode;
    int nOverlay;
    int nArg18;
    int nArg1C;
    unsigned int dwToken;
    unsigned int dwModeToken;
    unsigned int dwCode;
    const char* szName;
    int nFrames;
    int nArg34;
    int unk0x38;
    D2CelStrc* pCel;
    int nArg40;
    int unk0x44;
};

struct D2CompRecordStrc
{
    unsigned char nComponent;
    char unk0x01[4];
    char szCode[4];
};

struct D2CompEntryStrc
{
    unsigned char nCount;
    char unk0x01[0x1B];
    D2CompRecordStrc aComps[16];
};

struct D2CompEntryListStrc
{
    int unk0x00[5];
    D2CompEntryStrc* f_14;
};

struct D2CompArgStrc
{
    int unk0x00[4];
    int nArg18;
};

struct D2MonCompInfoStrc
{
    short nClass;
    char unk0x02[2];
    unsigned char aComp[4][16];
};

struct D2ArmorCompsStrc
{
    unsigned char n0;
    unsigned char n1;
    unsigned char n2;
    unsigned char n3;
    unsigned char n4;
    unsigned char n5;
    unsigned char n6;
    unsigned char n7;
};

struct D2OverlaySourceStrc
{
    int unk0x00;
    int nOverlay;
    int unk0x08[4];
    int nArg0;
};

struct D2ItemsTxt
{
    char szFlippyFile[0x20];
    char szInvFile[0x20];
    char szUniqueInvFile[0x20];
    char szSetInvFile[0x20];
    unsigned int dwAltCode;
    char unk0x84[0x0C];
    unsigned int dwAltCode2;
};

struct D2SetItemsTxt
{
    char unk0x00[0x42];
    char szFlippyFile[0x20];
    char szInvFile[0x20];
};

struct D2UniqueItemsTxt
{
    char unk0x00[0x3A];
    char szFlippyFile[0x20];
    char szInvFile[0x20];
};

struct D2MissilesTxt
{
    char unk0x000[0x138];
    char szCelFile[0x6C];
};

struct D2OverlayTxt
{
    char unk0x00[2];
    char szFilename[0x82];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB64];
    D2MissilesTxt* pMissilesTxt;
    char unk0xB68[0x04];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x4C];
    D2OverlayTxt* pOverlayTxt;
    int nOverlayTxtRecordCount;
};

union D2CompCodeStrc
{
    unsigned int dwCode;
    struct
    {
        char c0;
        char c1;
        char c2;
        char c3;
    };
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gaPlrModeTokens_007C88D0[];                                                             // 0x007C88D0
extern unsigned int gaCompTokens_007C8920[];                                                                // 0x007C8920
extern unsigned int gaObjModeTokens_007C8960[8];                                                            // 0x007C8960
extern unsigned int gaMonModeTokens_007C8980[];                                                             // 0x007C8980
extern unsigned int gaClassTokens_007C89C0[3];                                                              // 0x007C89C0
unsigned int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                           // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
D2InventoryStrc* __fastcall sub_0046DB30_GetCompInventory(D2UnitStrc* pUnit, int* pOut);                    // 0x0046DB30
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                 // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                 // 0x0046FA80
D2CompEntryStrc* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode);                         // 0x0046E570
void* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                                // 0x00463E10
int __fastcall sub_004DAA00_GetModeArg(D2UnitStrc* pUnit, int nType, int nClass);                           // 0x004DAA00
unsigned char __fastcall sub_004DA770_GetMonComponentIndex(D2UnitStrc* pUnit, unsigned char nComponent);    // 0x004DA770
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004DAAB0_GetArmorComponents(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int bSkip, unsigned char* pComponents); // 0x004DAAB0
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc);               // 0x0063C050
int __stdcall sub_0062A4E0_TestItem(D2UnitStrc* pItem);                                                     // 0x0062A4E0
void __fastcall sub_004DAA70_GetItemMode(D2UnitStrc* pUnit, int* pMode);                                    // 0x004DAA70
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
D2SetItemsTxt* __fastcall sub_00483440_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
D2UniqueItemsTxt* __fastcall sub_00483470_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);                               // 0x0063A7B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem);                // 0x0063C8F0
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset();                                                      // 0x0045AFD0
extern "C" int __cdecl sub_0045AFC0();                                                          // 0x0045AFC0
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2);            // 0x004709A0

// 0x004DA720
static __declspec(noinline) void sub_004DA720_CopyCompCode(D2CompCodeStrc* pDst, const char* pSrc)
{
    if (!pSrc[0])
    {
        const char c = 0x20;
        pDst->c0 = c;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c0 = pSrc[0];
    if (!pSrc[1])
    {
        const char c = 0x20;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c1 = pSrc[1];
    if (!pSrc[2])
    {
        const char c = 0x20;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c2 = pSrc[2];
    pDst->c3 = 0x20;
}

// 0x004DA8E0
static void __stdcall sub_004DA8E0_SetMissileCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken)
{
    if (!pUnit)
        return;

    const int nClassId = pUnit->dwClassId;
    D2MissilesTxt* pRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nClassId] : 0;
    if (pRecord)
        pToken->szName = pRecord->szCelFile;
}

// 0x004DABC0
static void sub_004DABC0_SetItemCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(sub_0046DAC0_GetItemClassId(pUnit));
    if (!pItemsTxtRecord)
        return;

    if (pToken->nMode == 4)
    {
        const unsigned char nInvGfx = sub_006283F0_GetInvGfxIndex(pUnit);
        if (ITEMS_CheckItemFlag(pUnit, 0x10, 0x196, ".\\ENGINE\\GfxUtil.cpp") && ITEMS_GetItemQuality(pUnit) == 5)
        {
            D2SetItemsTxt* pSet = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pUnit));
            if (pSet && pSet->szInvFile[0])
            {
                pToken->nFlags |= 0x10;
                pToken->szName = pSet->szInvFile;
                return;
            }

            if (pItemsTxtRecord->szSetInvFile[0])
            {
                pToken->nFlags |= 0x10;
                pToken->szName = pItemsTxtRecord->szSetInvFile;
                return;
            }
        }

        if (ITEMS_CheckItemFlag(pUnit, 0x10, 0x1AE, ".\\ENGINE\\GfxUtil.cpp") && ITEMS_GetItemQuality(pUnit) == 7)
        {
            const int nIndex = ITEMS_GetFileIndex(pUnit);
            if (nIndex > 0)
            {
                D2UniqueItemsTxt* pUnique = sub_00483470_GetUniqueItemsTxtRecord(nIndex);
                if (pUnique && pUnique->szInvFile[0])
                {
                    pToken->nFlags |= 1;
                    pToken->szName = pUnique->szInvFile;
                    return;
                }
            }

            if (pItemsTxtRecord->szUniqueInvFile[0])
            {
                pToken->nFlags |= 1;
                pToken->szName = pItemsTxtRecord->szUniqueInvFile;
                return;
            }
        }

        if (sub_0062E8D0_HasAltInvGfx(pUnit))
        {
            pToken->szName = sub_0062E920_GetAltInvGfxName(pUnit, nInvGfx);
            return;
        }

        pToken->szName = pItemsTxtRecord->szInvFile;
        return;
    }

    if (pToken->nMode == 3)
    {
        pToken->szName = pItemsTxtRecord->szFlippyFile;
        if (ITEMS_GetItemQuality(pUnit) == 7)
        {
            if (ITEMS_GetFileIndex(pUnit) >= 0)
            {
                D2UniqueItemsTxt* pUnique = sub_00483470_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pUnit));
                if (pUnique && pUnique->szFlippyFile[0])
                    pToken->szName = pUnique->szFlippyFile;
            }
        }
        else if (ITEMS_GetItemQuality(pUnit) == 5)
        {
            D2SetItemsTxt* pSet = sub_00483440_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pUnit));
            if (pSet && pSet->szFlippyFile[0])
                pToken->szName = pSet->szFlippyFile;
        }
    }
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

// 0x004DAD80
static unsigned int sub_004DAD80_GetWeaponClassToken(D2UnitStrc* pUnit, int nComponent)
{
    if (nComponent >= 0x10)
        return 0x2074696C;

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (STATES_IsUnitShapeShiftedInline(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
        pInventory = pOwner->pInventory;
    else
        pInventory = pUnit->pInventory;

    int nWeaponClassId;
    const int nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, -1, 1);
    if (nWeaponClass == 0x20776278)
    {
        if (nComponent == 5 || nComponent == 6)
        {
            D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, 5);
            if (!pItem)
                return 0x2074696C;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInline(pItem));
            if (!pItemsTxtRecord)
                return 0x2074696C;
            if (pItemsTxtRecord->dwAltCode2)
                return pItemsTxtRecord->dwAltCode2;
            return pItemsTxtRecord->dwAltCode;
        }
    }
    else if (nWeaponClass == 0x20776F62 && nComponent == 5)
    {
        return 0x2074696C;
    }

    if (nComponent == 7 && STATES_CheckState(pUnit, 0x65) && INVENTORY_GetEquippedShield(pInventory, 0))
        return 0x20687368;

    return 0;
}

static int __stdcall sub_004DB7B0_ResolveUnitCelContext(D2UnitStrc* pUnit, D2CelContextStrc* pToken, int nMode, int* pItemId)
{
    int nType = 6;
    int nClass;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
        nClass = pUnit->dwClassId;
        int nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\GfxUtil.cpp", 0x2F0);
        pToken->nType = nType;
        pToken->nClass = nClass;
        if (nMode == -1)
            nMode = nAnimMode;
        pToken->nMode = nMode;
    }
    else
    {
        pToken->nType = nType;
    }

    switch (nType)
    {
    case 0:
    case 1:
    case 2:
    {
        *pItemId = -1;
        int nOut;
        D2InventoryStrc* pInventory = sub_0046DB30_GetCompInventory(pUnit, &nOut);
        pToken->nArg1C = gaCompTokens_007C8920[pToken->nComponent];
        int nWeaponClassId;
        pToken->dwCode = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, pToken->nMode, 0);
        if (!sub_0046E5A0_FindGfxNode(pUnit, pToken->dwCode, pToken->nMode) && !sub_0046FA80_LoadGfxNode(pUnit, pToken->dwCode, pToken->nMode))
            return 0;

        D2CompEntryStrc* pEntry = sub_0046E570_GetGfxEntry(pUnit, pToken->nMode);
        if (!pEntry)
            return 0;

        if (!sub_00463E10_GetGfxData(pUnit))
            return 0;

        pToken->dwToken = 0x2074696C;
        pToken->nArg18 = sub_004DAA00_GetModeArg(pUnit, pToken->nType, pToken->nClass);

        D2CompRecordStrc* pComp = pEntry->aComps;
        for (int i = 0; i < pEntry->nCount; ++i, ++pComp)
        {
            if (pComp->nComponent >= 0x10)
                return 0;
            if (pComp->nComponent == pToken->nComponent)
                goto found;
        }
        return 0;

found:

        switch (nType)
        {
        case 0:
        {
            if (pUnit == sub_00463DD0())
                pToken->nFlags |= 8;

            if (!pInventory)
            {
                pToken->dwToken = 0x2074696C;
                return 0;
            }

            pToken->dwModeToken = gaPlrModeTokens_007C88D0[pToken->nMode];
            D2ArmorCompsStrc tComps;
            sub_004DAAB0_GetArmorComponents(pUnit, pInventory, nType, &tComps.n0);
            D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, pToken->nComponent);
            if (sub_0064F420_HasBodyLocFallback(pToken->nComponent))
            {
                if (pToken->nMode != 0x11 && pToken->nMode != 0)
                    pToken->dwToken = gaClassTokens_007C89C0[sub_0064F500_GetFallbackIndex(pToken->nComponent, &tComps.n0)];
                else
                    pToken->dwToken = 0x2074696C;
            }
            else
            {
                pToken->dwToken = sub_004DAD80_GetWeaponClassToken(pUnit, pToken->nComponent);
                if (pItem && !pToken->dwToken && sub_0062A4E0_TestItem(pItem))
                    pToken->dwToken = ITEMS_GetAltGfx(pItem);
                else if (!pToken->dwToken)
                    pToken->dwToken = 0x2074696C;
            }

            if (!pToken->dwToken)
                return 0;
            break;
        }
        case 1:
        {
            const int nMonMode = pToken->nMode;
            pToken->dwModeToken = gaMonModeTokens_007C8980[nMonMode];
            const unsigned char nComp = pComp->nComponent;
            const unsigned char nIndex = sub_004DA770_GetMonComponentIndex(pUnit, nComp);
            if (nMonMode != 0 && nMonMode != 0xC)
                pToken->dwToken = D2Common_11069(pUnit, nComp, nIndex);
            else if (sub_004638A0_CheckMonStats2Flag(pToken->nClass, 0x10))
                pToken->dwToken = D2Common_11069(pUnit, nComp, nIndex);
            break;
        }
        case 2:
            pToken->dwModeToken = gaObjModeTokens_007C8960[pToken->nMode];
            break;
        }

        D2CompCodeStrc tCode;
        tCode.dwCode = 0;
        sub_004DA720_CopyCompCode(&tCode, pComp->szCode);
        pToken->dwCode = tCode.dwCode;
        if (!pToken->nArg1C || !pToken->nArg18 || !tCode.dwCode)
            return 0;

        if (!pToken->dwModeToken)
            pToken->dwModeToken = 0x20787878;
        if (!pToken->dwToken)
            pToken->dwToken = 0x2074696C;

        int nItemId;
        if (DATATBLS_GetItemRecordFromItemCode(pToken->dwToken, &nItemId))
            *pItemId = nItemId;
        return 1;
    }
    case 3:
        sub_004DA8E0_SetMissileCelName(pUnit, pToken);
        return 1;
    case 4:
        sub_004DAA70_GetItemMode(pUnit, &pToken->nMode);
        sub_004DABC0_SetItemCelName(pUnit, pToken);
        return 1;
    case 6:
    {
        const int nOverlay = pToken->nOverlay;
        pToken->nFlags |= 2;
        D2OverlayTxt* pRecord = (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount) ? &sgptDataTables->pOverlayTxt[nOverlay] : 0;
        if (pRecord)
            pToken->szName = pRecord->szFilename;
        return 1;
    }
    }

    return 0;
}

// 0x004DBB50
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode)
{
    pToken->nArg34 = nArg34;
    pToken->nArg40 = nArg40;
    pToken->nArg0 = nArg0;
    pToken->nComponent = nComponent;
    return sub_004DB7B0_ResolveUnitCelContext(pUnit, pToken, nMode, pItemId);
}

// build: context sub_004DBB80_FillMonsterCelContext
static int __stdcall sub_004DBB80_FillMonsterCelContext(D2CompEntryListStrc* pList, unsigned int dwCode0, D2CelContextStrc* pToken, int nMode, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow)
{
    D2_ASSERT(dwCode0, 0x3E2);
    D2_ASSERT(pList, 0x3E3);

    pToken->nClass = pClassInfo->nClass;
    pToken->nMode = nMode;
    const unsigned char nComponent = pToken->nComponent;
    pToken->nType = 1;
    pToken->dwCode = dwCode0;
    pToken->nArg1C = gaCompTokens_007C8920[nComponent];
    pToken->dwToken = 0x2074696C;
    pToken->nArg18 = pArgRec->nArg18;

    D2CompEntryStrc* pListEntry = pList->f_14;
    D2_ASSERT(pListEntry, 0x3F0);

    const unsigned int nCount = pListEntry->nCount;
    D2CompRecordStrc* pComp = pListEntry->aComps;
    for (unsigned int i = 0; i < nCount; ++i, ++pComp)
    {
        D2_ASSERT(pComp->nComponent < 0x10, 0x3FB);
        if (pComp->nComponent == nComponent)
            goto found;
    }
    return 0;

found:

    pToken->dwModeToken = gaMonModeTokens_007C8980[nMode];
    const int nClass = pToken->nClass;
    const unsigned char nIndex = pClassInfo->aComp[nRow][nComponent];
    if (nMode != 0 && nMode != 0xC)
        pToken->dwToken = sub_00664930_GetMonComponentToken(nClass, nComponent, nIndex);
    else if (sub_004638A0_CheckMonStats2Flag(nClass, 0x10))
        pToken->dwToken = sub_00664930_GetMonComponentToken(nClass, nComponent, nIndex);

    D2CompCodeStrc tCode;
    tCode.dwCode = 0;
    sub_004DA720_CopyCompCode(&tCode, pComp->szCode);
    pToken->dwCode = tCode.dwCode;
    D2_ASSERT(pToken->nArg1C, 0x425);
    D2_ASSERT(pToken->nArg18, 0x426);
    D2_ASSERT(tCode.dwCode, 0x427);
    if (!pToken->dwToken)
        pToken->dwToken = 0x20787878;
    if (!pToken->dwModeToken)
        pToken->dwModeToken = 0x20787878;
    return 1;
}

int __fastcall sub_004DBCF0_FillMonsterCelContextEx(D2CelContextStrc* pToken, int nArg40, int nArg0, unsigned char nComponent, int nMode, unsigned int dwCode0, D2CompEntryListStrc* pList, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow)
{
    pToken->nArg40 = nArg40;
    pToken->nArg0 = nArg0;
    pToken->nComponent = nComponent;
    return sub_004DBB80_FillMonsterCelContext(pList, dwCode0, pToken, nMode, pClassInfo, pArgRec, nRow);
}

// 0x004DBD30
int __fastcall sub_004DBD30_GetComponentsMaxHeight(D2UnitStrc* pUnit, unsigned char* pList, unsigned char* pComponents, int* pMax, int nArg40, int nArg0)
{
    int nCount = 0;
    for (int i = 0; i < pList[0]; ++i)
    {
        const int nComponent = pComponents[i];
        D2_ASSERT(nComponent < 0x10, 0x59D);
        D2CelContextStrc tToken;
        memset(&tToken, 0, sizeof(tToken));
        tToken.nArg40 = nArg40;
        tToken.nArg0 = nArg0;
        tToken.nArg34 = 0;
        tToken.nComponent = nComponent;
        int nItemId;
        if (sub_004DB7B0_ResolveUnitCelContext(pUnit, &tToken, -1, &nItemId) && sub_006001F0(&tToken, 0, 1) && tToken.pCel)
        {
            const int nHeight = sub_00601950(tToken.pCel) - sub_0045AFD0_GetMouseYOffset() + UNITS_GetClientCoordY(pUnit);
            if (nHeight > *pMax)
                *pMax = nHeight;
            ++nCount;
        }
    }
    return nCount;
}

// build: context sub_004DBE20_GetOverlayFrameCount
int __fastcall sub_004DBE20_GetOverlayFrameCount(D2UnitStrc* pUnit, D2OverlaySourceStrc* pSrc)
{
    int nItemId;
    D2CelContextStrc tToken;
    memset(&tToken, 0, sizeof(tToken));
    tToken.nOverlay = pSrc->nOverlay;
    const int nArg0 = pSrc->nArg0;
    tToken.nArg40 = UNITS_GetDirection(pUnit);
    tToken.nArg34 = 0;
    tToken.nArg0 = nArg0;
    tToken.nComponent = 1;
    if (!sub_004DB7B0_ResolveUnitCelContext(0, &tToken, -1, &nItemId))
        return 1;
    if (!sub_006001F0(&tToken, 0, 1))
        return 1;
    return tToken.nFrames << 8;
}

// 0x004DBEA0
void __fastcall sub_004DBEA0_GetUnitCelSize(D2UnitStrc* pUnit, int nArg40, int nArg0, int* pWidth, int* pHeight)
{
    D2CelContextStrc tToken;
    memset(&tToken, 0, sizeof(tToken));
    tToken.nArg0 = nArg0;
    tToken.nArg34 = 0;
    tToken.nArg40 = nArg40;
    tToken.nComponent = 1;
    if (sub_004DB7B0_ResolveUnitCelContext(pUnit, &tToken, -1, &nArg0) && sub_006001F0(&tToken, 0, 1) && tToken.pCel)
    {
        *pWidth = sub_006018C0(tToken.pCel);
        *pHeight = sub_006018F0(tToken.pCel);
    }
}

int __fastcall sub_004DBF20_HitTestUnitCel(D2UnitStrc* pUnit, int nX, int nY)
{
    nX -= sub_0045AFC0();
    nY -= sub_0045AFD0_GetMouseYOffset();
    if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 0))
        return 0;

    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    const int nFrame = nFrameNo;
    D2CelContextStrc tToken;
    memset(&tToken, 0, sizeof(tToken));
    tToken.nArg40 = UNITS_GetDirection(pUnit);
    tToken.nArg34 = 0;
    tToken.nArg0 = nFrame;
    tToken.nComponent = 1;
    int nItemId;
    if (!sub_004DB7B0_ResolveUnitCelContext(pUnit, &tToken, -1, &nItemId))
        return 0;
    if (!sub_006001F0(&tToken, 0, 1))
        return 0;
    if (!tToken.pCel)
        return 0;
    return sub_004DAB40_CheckCel(tToken.pCel, nX, nY, 0);
}
