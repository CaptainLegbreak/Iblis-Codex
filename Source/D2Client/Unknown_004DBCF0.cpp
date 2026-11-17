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
    D2CompEntryStrc* pEntry;
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

extern unsigned int gaCompTokens_007C8920[];                                                                // 0x007C8920
extern unsigned int gaMonModeTokens_007C8980[];                                                             // 0x007C8980
int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

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

static __declspec(noinline) int __stdcall sub_004DBB80_FillMonsterCelContext(D2CompEntryListStrc* pList, unsigned int dwCode0, D2CelContextStrc* pToken, int nMode, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow);

static int __stdcall sub_004DBB80_FillMonsterCelContext(D2CompEntryListStrc* pList, unsigned int dwCode0, D2CelContextStrc* pToken, int nMode, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow)
{
    D2_ASSERT(dwCode0, 0x3E2);
    D2_ASSERT(pList, 0x3E3);

    const int nClass = pClassInfo->nClass;
    pToken->nClass = nClass;
    pToken->nMode = nMode;
    const unsigned char nComponent = pToken->nComponent;
    pToken->nType = 1;
    pToken->dwCode = dwCode0;
    pToken->nArg1C = gaCompTokens_007C8920[nComponent];
    pToken->dwToken = 0x2074696C;
    pToken->nArg18 = pArgRec->nArg18;

    D2CompEntryStrc* pListEntry = pList->pEntry;
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

// 0x004DBCF0
int __fastcall sub_004DBCF0_FillMonsterCelContextEx(D2CelContextStrc* pToken, int nArg40, int nArg0, unsigned char nComponent, int nMode, unsigned int dwCode0, D2CompEntryListStrc* pList, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow)
{
    pToken->nArg40 = nArg40;
    pToken->nArg0 = nArg0;
    pToken->nComponent = nComponent;
    return sub_004DBB80_FillMonsterCelContext(pList, dwCode0, pToken, nMode, pClassInfo, pArgRec, nRow);
}
