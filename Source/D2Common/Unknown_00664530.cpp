#include "D2Common.h"

struct D2OverlayTxt;
struct D2MonStatsTxt;
struct D2MonStats2CompStrc;
struct D2MonStats2Txt;

struct D2OverlayTxt
{
    unsigned short wOverlay;
    char szFilename[64];
    unsigned short wVersion;
    unsigned int dwFrames;
    unsigned char nPreDraw;
    unsigned char pad0x49[3];
    unsigned int dw1ofN;
    unsigned char nDir;
    unsigned char nOpen;
    unsigned char nBeta;
    unsigned char pad0x53;
    unsigned int dwOffsetX;
    unsigned int dwOffsetY;
    unsigned int dwHeight[4];
    unsigned int dwAnimRate;
    unsigned int dwInitRadius;
    unsigned int dwRadius;
    unsigned int dwLoopWaitTime;
    unsigned char nTrans;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nNumDirections;
    unsigned char nLocalBlood;
    unsigned short pad0x82;
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    void* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
    unsigned char unk_A9C[0x11C];
    D2TxtLinkStrc* pOverlayLinker;
    D2OverlayTxt* pOverlayTxt;
    int nOverlayTxtRecordCount;
};

extern D2DataTablesStrc gtDataTables_0096BC30; // 0x0096BC30
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

struct D2MonStatsTxt
{
    char unk0x00[0x18];
    short nMonStatsEx;
    char unk0x1A[0x18E];
};

struct D2MonStats2CompStrc
{
    unsigned char nComposit[12];
};

struct D2MonStats2Txt
{
    char unk0x00[0x15];
    unsigned char nComponentChoiceCounts[16];
    char unk0x25;
    D2MonStats2CompStrc unk0x26[16];
    char unk0xE6[0x4E];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nIndex); // 0x006117D0

static D2OverlayTxt* DATATBLS_GetOverlayTxtRecord(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }

    return 0;
}

// 0x00664530
void __fastcall DATATBLS_UnloadOverlayTxt()
{
    FOG_FreeLinker(gtDataTables_0096BC30.pOverlayLinker);
    DATATBLS_UnloadBin(gtDataTables_0096BC30.pOverlayTxt);
    gtDataTables_0096BC30.pOverlayTxt = 0;
}

// 0x00664560
unsigned int __stdcall DATATBLS_GetFramesFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dwFrames;
}

// 0x006645A0
int __stdcall DATABLS_GetPreDrawFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->nPreDraw;
}

// 0x006645E0
unsigned int __stdcall DATATBLS_GetOffsetXFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dwOffsetX;
}

// 0x00664620
unsigned int __stdcall DATATBLS_GetOffsetYFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dwOffsetY;
}

// 0x00664660
int __stdcall DATATBLS_GetTransFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->nTrans;
}

// 0x006646A0
int __stdcall DATATBLS_GetRadiusAndColorFromOverlayTxt(int nOverlayId, int* pInitRadius, int* pRadius, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        *pInitRadius = 0;
        *pRadius = 0;
        *pRed = 0;
        *pGreen = 0;
        *pBlue = 0;
        return 0;
    }

    {
        *pInitRadius = pOverlayTxt->dwInitRadius;
        *pRadius = pOverlayTxt->dwRadius;
        *pRed = pOverlayTxt->nRed;
        *pGreen = pOverlayTxt->nGreen;
        *pBlue = pOverlayTxt->nBlue;
        return *pRadius || *pInitRadius;
    }
}

// 0x00664740
unsigned int __stdcall DATATBLS_Get1OfNFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dw1ofN;
}

// 0x00664780
int __stdcall DATATBLS_GetDirFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->nDir;
}

// 0x006647C0
int __stdcall D2COMMON_11068_GetCompInfo(D2UnitStrc* pMonster, int nComponent)
{
    if (!pMonster || pMonster->dwUnitType != 1)
    {
        return 0;
    }

    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pMonster->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    return pMonStats2TxtRecord->nComponentChoiceCounts[nComponent];
}

static D2MonStats2Txt* MONSTERS_GetMonStats2TxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].nMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x00664930
int __stdcall D2Common_11070(int nMonsterId, unsigned int nComponent, unsigned int nIndex)
{
    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERS_GetMonStats2TxtRecordInline(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nComponentChoiceCounts[nComponent] <= nIndex)
    {
        return 0;
    }

    return DATATBLS_GetCodeFromCompCodeTxt(pMonStats2TxtRecord->unk0x26[nComponent].nComposit[nIndex]);
}

// 0x00664800
int __fastcall sub_00664800_GetCompChoiceCount(int nMonsterId, unsigned int nComponent)
{
    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERS_GetMonStats2TxtRecordInline(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    return pMonStats2TxtRecord->nComponentChoiceCounts[nComponent];
}
