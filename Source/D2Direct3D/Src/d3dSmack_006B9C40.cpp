#include "D2Direct3D.h"
#include "D2DDrawTypes.h"
#include "D2D3DTypes.h"

struct D2VideoBlitDevice;
struct D2VideoHandleStrc;
struct D2VideoBlitDeviceVtbl;
struct T004F51E0;
struct D2SmackRecordStrc;

struct D2VideoHandleStrc
{
    D2SmackStrc* handle;
    char type;
    unsigned char pad_0005[3];
    int x;
    int y;
};
void __fastcall sub_006B9BB0_CloseSmack(D2VideoHandleStrc* video); // 0x006B9BB0
void __cdecl sub_006B9BD0_Apply(); // 0x006B9BD0

struct D2VideoBlitDeviceVtbl
{
    void* slots_0000[28];
    long (__stdcall* DrawPrimitive)(D2VideoBlitDevice*, unsigned int,
        unsigned int, void*, unsigned int, unsigned int);
    void* slots_0074[9];
    long (__stdcall* SetTexture)(D2VideoBlitDevice*, unsigned int, void*);
};

struct D2VideoBlitDevice { D2VideoBlitDeviceVtbl* lpVtbl; };

extern D2VideoBlitDevice* gpDevice_00970E78; // 0x00970E78
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlendMode(int nState); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030
static __declspec(noinline) void __stdcall sub_006B9EB0_CopyBlock(unsigned short* pSource, unsigned short* pDest, int nDestPitch);
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" const char gszUnlockFailed_006FC284[]; // 0x006FC284
extern "C" const char gszLockFailed_006FC2A4[]; // 0x006FC2A4
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0
static __declspec(noinline) void __stdcall sub_006B9EB0_CopyWithAlpha(const unsigned short* pSrc, unsigned char* pDst, int nPitch);

struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct D2SmackRecordStrc
{
    void* f_0;
    unsigned char nType;
};

extern "C" __declspec(dllimport) void* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604
extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack); // 0x006CC608
extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680
int __stdcall sub_006C6A80_DecodeImage(int nMode, void* pData, int nSize, T004F51E0* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80
void __cdecl sub_006B9F00_UploadFrameBuffer(); // 0x006B9F00
extern "C" const char szD3DSmackFile_006FC358[]; // 0x006FC358
extern unsigned short* gpD3DSmackBuffer_009897D0; // 0x009897D0

D2TLVertexStrc gVideoVertices_00989750[4]; // 0x00989750

// 0x006B9C40
static void __stdcall sub_006B9C40_BlitVideo(D2VideoHandleStrc* video, int width, int height)
{
    const int top = video->y - height;
    const int bottom = video->y;
    sub_006B1EA0_SetState(1);
    sub_006B1F40_SetBlendMode(1);
    sub_006B2030_SetFilterMode(1);

    int x = video->x;
    int right = x + 256;
    gVideoVertices_00989750[0].fX = (float)x;
    gVideoVertices_00989750[0].fY = (float)top;
    gVideoVertices_00989750[0].fZ = 0.5f;
    gVideoVertices_00989750[0].fRhw = 1.0f;
    gVideoVertices_00989750[0].fU = 0.0f;
    gVideoVertices_00989750[0].fV = 0.0f;
    gVideoVertices_00989750[1].fX = (float)x;
    gVideoVertices_00989750[1].fY = (float)bottom;
    gVideoVertices_00989750[1].fZ = 0.5f;
    gVideoVertices_00989750[1].fRhw = 1.0f;
    gVideoVertices_00989750[1].fU = 0.0f;
    gVideoVertices_00989750[1].fV = 1.0f;
    gVideoVertices_00989750[2].fX = (float)right;
    gVideoVertices_00989750[2].fY = (float)bottom;
    gVideoVertices_00989750[2].fZ = 0.5f;
    gVideoVertices_00989750[2].fRhw = 1.0f;
    gVideoVertices_00989750[2].fU = 1.0f;
    gVideoVertices_00989750[2].fV = 1.0f;
    gVideoVertices_00989750[3].fX = (float)right;
    gVideoVertices_00989750[3].fY = (float)top;
    gVideoVertices_00989750[3].fZ = 0.5f;
    gVideoVertices_00989750[3].fRhw = 1.0f;
    gVideoVertices_00989750[3].fU = 1.0f;
    gVideoVertices_00989750[3].fV = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gpArray_009897EC[0]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gVideoVertices_00989750, 4, 0x1C);

    x += 256;
    right = x + width - 256;
    const float u = (float)((width - 256) * (1.0 / 256.0));
    gVideoVertices_00989750[0].fX = (float)x;
    gVideoVertices_00989750[0].fY = (float)top;
    gVideoVertices_00989750[0].fZ = 0.5f;
    gVideoVertices_00989750[0].fRhw = 1.0f;
    gVideoVertices_00989750[0].fU = 0.0f;
    gVideoVertices_00989750[0].fV = 0.0f;
    gVideoVertices_00989750[1].fX = (float)x;
    gVideoVertices_00989750[1].fY = (float)bottom;
    gVideoVertices_00989750[1].fZ = 0.5f;
    gVideoVertices_00989750[1].fRhw = 1.0f;
    gVideoVertices_00989750[1].fU = 0.0f;
    gVideoVertices_00989750[1].fV = 1.0f;
    gVideoVertices_00989750[2].fX = (float)right;
    gVideoVertices_00989750[2].fY = (float)bottom;
    gVideoVertices_00989750[2].fZ = 0.5f;
    gVideoVertices_00989750[2].fRhw = 1.0f;
    gVideoVertices_00989750[2].fU = u;
    gVideoVertices_00989750[2].fV = 1.0f;
    gVideoVertices_00989750[3].fX = (float)right;
    gVideoVertices_00989750[3].fY = (float)top;
    gVideoVertices_00989750[3].fZ = 0.5f;
    gVideoVertices_00989750[3].fRhw = 1.0f;
    gVideoVertices_00989750[3].fU = u;
    gVideoVertices_00989750[3].fV = 0.0f;
    gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, gpArray_009897EC[1]);
    gpDevice_00970E78->lpVtbl->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, gVideoVertices_00989750, 4, 0x1C);
}

void __fastcall sub_006BA390_PlaySmack(D2VideoHandleStrc* video)
{
    switch (video->type)
    {
    case 's':
        {
            D2SmackStrc* smack = video->handle;
            if (smack)
            {
                if (!SmackWait(smack))
                {
                    if (!ghDDrawWindow_007C9140)
                        return;
                    SmackDoFrame(smack);
                    sub_006B9F00_PresentFrame();
                    if (smack->nFrameNum == smack->nFrames)
                        sub_006B9BB0_CloseSmack(video);
                    else
                        SmackNextFrame(smack);
                    if (gbRenderPaused_007C9144)
                        return;
                    sub_006B9BD0_Apply();
                }
                if (!gbRenderPaused_007C9144)
                    sub_006B9C40_BlitVideo(video, smack->nWidth, smack->nHeight);
            }
        }
        break;
    case 'p':
        if (!gbRenderPaused_007C9144)
            sub_006B9C40_BlitVideo(video, 468, 60);
        break;
    }
}

// 0x006B9EB0
static void __stdcall sub_006B9EB0_CopyBlock(unsigned short* pSource, unsigned short* pDest, int nDestPitch)
{
    for (unsigned int nRow = 64; nRow; --nRow)
    {
        const unsigned short* pIn = pSource;
        const int nDelta = (char*)pDest - (char*)pSource;
        for (unsigned int i = 256; i; --i)
        {
            *(unsigned short*)((char*)pIn + nDelta) = *pIn | 0x8000;
            ++pIn;
        }
        pDest = (unsigned short*)((char*)pDest + nDestPitch);
        pSource += 512;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_006B9EB0_Shim(unsigned short* pSource, unsigned short* pDest, int nDestPitch)
{
    sub_006B9EB0_CopyBlock(pSource, pDest, nDestPitch);
}

unsigned char* gpFrameBuffer_009897D0; // 0x009897D0

D2DDSurfaceStrc* gpMemSurfaceA_009897D4; // 0x009897D4

D2DDSurfaceStrc* gpMemSurfaceB_009897D8; // 0x009897D8

static void __stdcall sub_006B9EB0_CopyWithAlpha(const unsigned short* pSrc, unsigned char* pDst, int nPitch)
{
    for (int nRow = 64; nRow; --nRow)
    {
        unsigned short* pOut = (unsigned short*)pDst;
        for (int i = 0; i < 256; ++i)
        {
            pOut[i] = pSrc[i] | 0x8000;
        }
        pDst += nPitch;
        pSrc += 512;
    }
}

// 0x006B9F00
void __cdecl sub_006B9F00_UploadFrameBuffer()
{
    D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
    if (!gpMemSurfaceA_009897D4)
    {
        return;
    }

    long hResult = gpMemSurfaceA_009897D4->lpVtbl->Lock(gpMemSurfaceA_009897D4, 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszLockFailed_006FC2A4, hResult);
    }
    sub_006B9EB0_CopyWithAlpha((const unsigned short*)gpFrameBuffer_009897D0, (unsigned char*)tDesc.lpSurface, tDesc.lPitch);
    hResult = gpMemSurfaceA_009897D4->lpVtbl->Unlock(gpMemSurfaceA_009897D4, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszUnlockFailed_006FC284, hResult);
    }

    if (!gpMemSurfaceB_009897D8)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x1DB);
        exit(-1);
    }

    hResult = gpMemSurfaceB_009897D8->lpVtbl->Lock(gpMemSurfaceB_009897D8, 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszLockFailed_006FC2A4, hResult);
    }
    sub_006B9EB0_CopyWithAlpha((const unsigned short*)(gpFrameBuffer_009897D0 + 0x200), (unsigned char*)tDesc.lpSurface, tDesc.lPitch);
    hResult = gpMemSurfaceB_009897D8->lpVtbl->Unlock(gpMemSurfaceB_009897D8, 0);
    if (hResult)
    {
        sub_006B20E0_DDrawLogError(gszUnlockFailed_006FC284, hResult);
    }
}

// 0x006BA010
void __fastcall sub_006BA010_D3DDecodeSmacker(const char* szFile, D2SmackRecordStrc* pSmack, unsigned char nType)
{
    if (!gbRenderPaused_007C9144)
    {
        D2_ASSERT(gpD3DSmackBuffer_009897D0, 0x94);
        memset(gpD3DSmackBuffer_009897D0, 0, 0x10000);
        sub_006B9F00_UploadFrameBuffer();
        sub_006B9BD0_Apply();
    }

    pSmack->nType = nType;
    switch (nType)
    {
    case 's':
        if (pSmack->f_0)
        {
            return;
        }
        pSmack->f_0 = SmackOpen(szFile, 0xFE000, -1);
        if (!pSmack->f_0)
        {
            break;
        }
        SmackToBuffer(pSmack->f_0, 0, 0, 0x400, 0x80, gpD3DSmackBuffer_009897D0, 0x80000000);
        return;

    case 'p':
    {
        void* pBuffer = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pBuffer, &nSize, 0, 3, 0) || !pBuffer)
        {
            break;
        }

        T004F51E0 aPalette[256];
        unsigned char aPixels[60][468];
        int nWidth;
        int nHeight;
        int nDepth;
        const int bDecoded = sub_006C6A80_DecodeImage(2, pBuffer, nSize, aPalette, aPixels[0], 0x6DB0, &nWidth, &nHeight, &nDepth);
        SMemFree(pBuffer, szD3DSmackFile_006FC358, 0xDA, 0);
        if (!bDecoded || nWidth != 468 || nHeight != 60 || nDepth != 8)
        {
            break;
        }

        unsigned short (*pRows)[0x200] = (unsigned short (*)[0x200])gpD3DSmackBuffer_009897D0;
        for (int y = 0; y < 60; ++y)
        {
            for (int x = 0; x < 468; ++x)
            {
                const int nIndex = aPixels[y][x];
                pRows[y][x] = ((aPalette[nIndex].peGreen & 0xF8) << 2) | ((aPalette[nIndex].peRed & 0xF8) << 7) | (aPalette[nIndex].peBlue >> 3);
            }
        }

        if (!gbRenderPaused_007C9144)
        {
            sub_006B9F00_UploadFrameBuffer();
            sub_006B9BD0_Apply();
        }
        return;
    }

    default:
        return;
    }

    if (pSmack->nType == 's' && pSmack->f_0)
    {
        SmackClose(pSmack->f_0);
        pSmack->f_0 = 0;
    }
}
