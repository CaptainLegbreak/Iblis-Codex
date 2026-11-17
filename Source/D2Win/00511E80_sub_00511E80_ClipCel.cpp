extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2CelStrc;
struct D2CmpCelContextStrc;

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

struct D2DDrawClipRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2DDrawCelClipStrc
{
    int nLeft;
    int nRight;
    int f_8;
    int nRows;
};

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_00601920(D2CelStrc* pCel);                                                               // 0x00601920
int __stdcall sub_00601950(D2CelStrc* pCel);                                                               // 0x00601950
void __stdcall sub_00601650_DrawCelClipped(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nClipTop, int nClipRows, int nArg13); // 0x00601650
int __fastcall sub_00511D70_GetCapsValue(int nIndex, int* pType);                                           // 0x00511D70

extern int gnScreenWidth_007C9138;                                                                          // 0x007C9138
extern int gnScreenHeight_007C913C;                                                                         // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154

// 0x00511E80
static int __fastcall sub_00511E80_ClipCel(D2CelStrc* pCel, int nY, int nX, D2DDrawCelClipStrc* pOut, const D2DDrawClipRectStrc* pClip)
{
    int nWidth = sub_006018C0(pCel);
    int nHeight = sub_006018F0(pCel);

    const int nLeft = D2_MAX(pClip->nLeft, 0);
    const int nRight = D2_MIN(pClip->nRight, gnScreenWidth_007C9138);
    if (nLeft <= nRight)
    {
        nX += sub_00601920(pCel);
        if (nX < nRight && nWidth + nX >= nLeft)
        {
            const int nTop = D2_MAX(pClip->nTop, 0);
            const int nBottom = D2_MIN(pClip->nBottom, gnScreenHeight_007C913C);
            if (nTop <= nBottom)
            {
                nY += sub_00601950(pCel);
                if (nY >= nTop && nY - nHeight <= nBottom)
                {
                    pOut->nLeft = nLeft;
                    pOut->nRight = nRight;
                    if (nY <= nBottom)
                        pOut->f_8 = 0;
                    else
                        pOut->f_8 = nY - nBottom - 1;
                    if (nY - nHeight >= nTop)
                        pOut->nRows = nHeight - pOut->f_8;
                    else
                        pOut->nRows = nY - pOut->f_8 - nTop + 1;

                    D2_ASSERT(pOut->nRows > 0, 0xAB);
                    return 0;
                }
            }
        }
    }

    return 1;
}

void __fastcall sub_M366_Emit_00512250(D2CelContextStrc* pContext, int nX, int nY, const D2DDrawClipRectStrc* pClip, int nDrawMode)
{
    D2DDrawCelClipStrc tOut;
    tOut.nLeft = 0;
    tOut.nRight = 0;
    tOut.f_8 = 0;
    tOut.nRows = 0;
    if (!sub_006001F0(pContext, 0, 9))
        return;
    if (sub_00511E80_ClipCel(pContext->pCel, nY, nX, &tOut, pClip))
        return;
    const int nCaps = sub_00511D70_GetCapsValue(nDrawMode, (int*)&pClip);
    sub_00601650_DrawCelClipped((D2CmpCelContextStrc*)pContext, nX, nY, tOut.nLeft, tOut.nRight, gpScreenBuffer_007C9154,
        gnScreenHeight_007C913C, gnScreenWidth_007C9138, 0, nCaps, tOut.f_8, tOut.nRows, 0);
}
