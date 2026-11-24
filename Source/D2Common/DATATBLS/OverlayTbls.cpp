#include "D2Common.h"
#include "D2Records.h"
#include "D2DataTbls.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2TxtTables.h"

extern "C" const char gszTxtField_Filename[];                                                               // 0x006D90F4
extern D2DataTablesStrc sgtDataTables;                                                                        // 0x0096BC30
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0

struct D2MonStatsTxt;
struct D2MonStats2CompStrc;
struct D2MonStats2Txt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

static D2OverlayTxt* DATATBLS_GetOverlayTxtRecord(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }

    return 0;
}

// 0x00664150
void __fastcall DATATBLS_LoadOverlayTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "overlay", 17, 0, 0, &sgtDataTables.pOverlayLinker },
        { gszTxtField_Filename, 1, 64, 2, 0 },
        { gszTxtField_version, 3, 0, 66, 0 },
        { "Frames", 2, 0, 68, 0 },
        { "PreDraw", 4, 0, 72, 0 },
        { "1ofN", 2, 0, 76, 0 },
        { "Dir", 4, 0, 80, 0 },
        { "Open", 4, 0, 81, 0 },
        { "Beta", 4, 0, 82, 0 },
        { "Xoffset", 2, 0, 84, 0 },
        { "Yoffset", 2, 0, 88, 0 },
        { "Height1", 2, 0, 92, 0 },
        { "Height2", 2, 0, 96, 0 },
        { "Height3", 2, 0, 100, 0 },
        { "Height4", 2, 0, 104, 0 },
        { "AnimRate", 2, 0, 108, 0 },
        { "LoopWaitTime", 2, 0, 120, 0 },
        { "Trans", 4, 0, 124, 0 },
        { "InitRadius", 2, 0, 112, 0 },
        { "Radius", 2, 0, 116, 0 },
        { "Red", 4, 0, 125, 0 },
        { "Green", 4, 0, 126, 0 },
        { "Blue", 4, 0, 127, 0 },
        { "NumDirections", 4, 0, 128, 0 },
        { "LocalBlood", 4, 0, 129, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    sgtDataTables.pOverlayLinker = FOG_AllocLinker(".\\DATATBLS\\OverlayTbls.cpp", 56);
    sgtDataTables.pOverlayTxt = (D2OverlayTxt*)DATATBLS_CompileTxt(hArchive, "overlay", pTbl, &sgtDataTables.nOverlayTxtRecordCount, 0x84);
}

#include "gen/data/Source/D2Common/DATATBLS/OverlayTbls.inc"
// 0x00664530
void __fastcall DATATBLS_UnloadOverlayTxt()
{
    FOG_FreeLinker(sgtDataTables.pOverlayLinker);
    DATATBLS_UnloadBin(sgtDataTables.pOverlayTxt);
    sgtDataTables.pOverlayTxt = 0;
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

