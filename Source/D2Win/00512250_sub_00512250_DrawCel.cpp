struct D2ClipRect00512250Strc
{
    int nX1;
    int nX2;
    int nY1;
    int nY2;
};

struct D2CellFileStrc;

struct D2CelContext00512250Strc
{
    unsigned char unk_00[0x3C];
    D2CellFileStrc* pCelFile;
};

int __stdcall sub_006001F0_Prepare(D2CelContext00512250Strc* pContext, int a2, int a3); // 0x006001F0
int __fastcall sub_00511D70_GetCapsValue(int nArg, D2ClipRect00512250Strc** ppClip, int nY1, int nY2, int nFlags); // 0x00511D70
void __stdcall D2CMP_CelDrawEx(D2CelContext00512250Strc* pContext, int nX, int nY, int nX1, int nX2, int a6, int a7, int a8, int a9, int a10); // 0x00601650
int __stdcall sub_006018C0_CelGetWidth(D2CellFileStrc* pCelFile); // 0x006018C0
int __stdcall sub_006018F0_CelGetHeight(D2CellFileStrc* pCelFile); // 0x006018F0
int __stdcall sub_00601920_CelGetOffsetX(D2CellFileStrc* pCelFile); // 0x00601920
int __stdcall sub_00601950_CelGetOffsetY(D2CellFileStrc* pCelFile); // 0x00601950
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
const char* __fastcall sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char* szExpression, const char* szFile, int nLine); // 0x00408A60
extern const char gszAssertExpr_006CC837[]; // 0x006CC837
extern int gnValue_007C9154; // 0x007C9154
extern int gnValue_007C913C; // 0x007C913C
extern int gnValue_007C9138; // 0x007C9138

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

static __declspec(noinline) int __stdcall sub_00511E80_ClipCel(D2CellFileStrc* pCelFile, int nY, D2ClipRect00512250Strc* pClip, int nX, D2ClipRect00512250Strc* pOut);

// 0x00511E80
static int __stdcall sub_00511E80_ClipCel(D2CellFileStrc* pCelFile, int nY, D2ClipRect00512250Strc* pClip, int nX, D2ClipRect00512250Strc* pOut)
{
    const int nWidth = sub_006018C0_CelGetWidth(pCelFile);
    const int nHeight = sub_006018F0_CelGetHeight(pCelFile);

    const int nX1 = D2_MAX(pClip->nX1, 0);
    const int nX2 = D2_MIN(pClip->nX2, gnValue_007C9138);
    if (nX1 > nX2)
    {
        return 1;
    }

    nX += sub_00601920_CelGetOffsetX(pCelFile);
    if (nX >= nX2 || nWidth + nX < nX1)
    {
        return 1;
    }

    int nY1 = D2_MAX(pClip->nY1, 0);
    int nY2 = pClip->nY2;
    nY2 = D2_MIN(nY2, gnValue_007C913C);
    if (nY1 > nY2)
    {
        return 1;
    }

    nY += sub_00601950_CelGetOffsetY(pCelFile);
    if (nY < nY1 || nY - nHeight > nY2)
    {
        return 1;
    }

    pOut->nX1 = nX1;
    pOut->nX2 = nX2;
    if (nY <= nY2)
    {
        pOut->nY1 = 0;
    }
    else
    {
        pOut->nY1 = nY - nY2 - 1;
    }

    if (nY - nHeight >= nY1)
    {
        pOut->nY2 = nHeight - pOut->nY1;
    }
    else
    {
        pOut->nY2 = nY - pOut->nY1 - nY1 + 1;
    }

    if (pOut->nY2 <= 0)
    {
        sub_00408A60(gszAssertExpr_006CC837, sub_00408090(), 171);
        exit(-1);
    }
    return 0;
}

// 0x00512250
void __fastcall sub_00512250_DrawCel(D2CelContext00512250Strc* pContext, int nX, int nY, D2ClipRect00512250Strc* pClip, int nC)
{
    D2ClipRect00512250Strc tRect = {};
    if (!sub_006001F0_Prepare(pContext, 0, 1))
    {
        return;
    }

    if (sub_00511E80_ClipCel(pContext->pCelFile, nY, pClip, nX, &tRect))
    {
        return;
    }

    D2CMP_CelDrawEx(pContext, nX, nY, tRect.nX1, tRect.nX2, gnValue_007C9154, gnValue_007C913C, gnValue_007C9138, 0,
        sub_00511D70_GetCapsValue(nC, &pClip, tRect.nY1, tRect.nY2, 0));
}
