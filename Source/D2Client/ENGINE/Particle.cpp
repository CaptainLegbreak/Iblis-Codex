#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2CelContext.h"
#include "D2TxtTables.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2GfxMotionStrc
{
    unsigned char nFlags0 : 5;
    unsigned char bFlag5 : 1;
};

struct D2GfxNodeStrc
{
    int unk0x00[3];
    D2GfxNodeStrc* pNext;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
unsigned int gaPlrModeTokens_007C88D0[20];                                                                  // 0x007C88D0
unsigned int gaCompTokens_007C8920[16];                                                                     // 0x007C8920
unsigned int gaObjModeTokens_007C8960[8];                                                                   // 0x007C8960
unsigned int gaMonModeTokens_007C8980[16];                                                                  // 0x007C8980
unsigned int gaClassTokens_007C89C0[3];                                                                     // 0x007C89C0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit);                                   // 0x0046F060
D2TokRecord* __stdcall DATATBLS_GetMonModeTxtRecord(unsigned int nIndex, int bGetMode);                     // 0x0065B500
D2TokRecord* __stdcall DATATBLS_GetCompositTxtRecord(int nComposit);                                        // 0x0065B5E0
D2TokRecord* __stdcall DATATBLS_GetArmTypeTxtRecord(int nId);                                               // 0x0065B620

// 0x004DA070
D2GfxMotionStrc* __fastcall sub_004DA070_GetGfxMotion(D2UnitStrc* pUnit)
{
    return sub_0046F060_GetGfxMotion(pUnit);
}

// 0x004DA700
int __fastcall sub_004DA700_GetGfxMotionFlag5(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->bFlag5;
    }
    return 0;
}

// 0x004DA790
void __cdecl sub_004DA790_InitModeTokens()
{
    memset(gaCompTokens_007C8920, 0, sizeof(gaCompTokens_007C8920));
    for (unsigned int i = 0; i < 16; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetCompositTxtRecord(i);
        D2_ASSERT(pRecord, 0x36);
        gaCompTokens_007C8920[i] = pRecord->dwCode;
    }

    memset(gaPlrModeTokens_007C88D0, 0, sizeof(gaPlrModeTokens_007C88D0));
    for (unsigned int i = 0; i < 20; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetPlrModeTypeTxtRecord(i, 1);
        D2_ASSERT(pRecord, 0x3F);
        gaPlrModeTokens_007C88D0[i] = pRecord->dwCode;
    }

    memset(gaMonModeTokens_007C8980, 0, sizeof(gaMonModeTokens_007C8980));
    for (unsigned int i = 0; i < 16; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetMonModeTxtRecord(i, 1);
        D2_ASSERT(pRecord, 0x48);
        gaMonModeTokens_007C8980[i] = pRecord->dwCode;
    }

    memset(gaObjModeTokens_007C8960, 0, sizeof(gaObjModeTokens_007C8960));
    for (unsigned int i = 0; i < 8; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetObjModeTypeTxtRecord(i, 1);
        D2_ASSERT(pRecord, 0x51);
        gaObjModeTokens_007C8960[i] = pRecord->dwCode;
    }

    memset(gaClassTokens_007C89C0, 0, sizeof(gaClassTokens_007C89C0));
    for (unsigned int i = 0; i < 3; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetArmTypeTxtRecord(i);
        D2_ASSERT(pRecord, 0x5A);
        gaClassTokens_007C89C0[i] = pRecord->dwCode;
    }
}

// 0x004DA9C0
void __fastcall sub_004DA9C0_FreeNodeList(D2GfxNodeStrc** ppHead, int* pBytes)
{
    D2GfxNodeStrc* pNode = *ppHead;
    while (pNode)
    {
        D2GfxNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\GfxUtil.cpp", 0xA8, 0);
        *pBytes -= sizeof(D2GfxNodeStrc);
        pNode = pNext;
    }
    *ppHead = 0;
}

// 0x004DAD20
void __fastcall sub_004DAD20_SetOverlayCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken)
{
    const int nOverlay = pToken->nOverlay;
    D2OverlayTxt* pRecord = (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount) ? &sgptDataTables->pOverlayTxt[nOverlay] : 0;
    if (pRecord)
        pToken->szName = pRecord->szFilename;
}
