#include "D2Direct3D.h"
#include "D2DDrawTypes.h"
#include "D2Win32Types.h"

#define gnHandle_00989760 (gVideoVertices_00989750[0].dwColor)

#define gnHandle_00989780 (gVideoVertices_00989750[1].dwColor)

#define gnHandle_009897A0 (gVideoVertices_00989750[2].dwColor)

#define gnHandle_009897C0 (gVideoVertices_00989750[3].dwColor)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2TLVertexStrc gVideoVertices_00989750[4]; // 0x00989750

extern void* gpBuffer_009897D0; // 0x009897D0

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* pText, const char* pFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern void* gpArray_009897D4[2]; // 0x009897D4

extern void* gpArray_009897DC[2]; // 0x009897DC

extern void* gpArray_009897E4[2]; // 0x009897E4

void __fastcall sub_006B3730_Allocate(void** ppFirst, void** ppSecond, int nCount, int nSize); // 0x006B3730

int __fastcall sub_006B58A0_Allocate(void** ppFirst, void** ppSecond, int nCount, int nSize); // 0x006B58A0

extern D2D3DObjStrc* gapObjectsD4_009897D4[2]; // 0x009897D4

extern D2D3DObjStrc* gapObjectsDC_009897DC[2]; // 0x009897DC

extern D2D3DObjStrc* gapObjectsE4_009897E4[2]; // 0x009897E4

extern D2D3DObjStrc* gapObjectsEC_009897EC[2]; // 0x009897EC

extern void* gpBuffer_009897D4; // 0x009897D4

extern void* gpBuffer_009897D8; // 0x009897D8

void __fastcall sub_006B38A0_Copy(void* pTarget, void* pBuffer, int nSize); // 0x006B38A0

void __fastcall sub_006B9BB0_CloseSmack(D2SmackRecordStrc* video); // 0x006B9BB0

void __cdecl sub_006B9BD0_Apply(); // 0x006B9BD0

extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78

void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0

void __fastcall sub_006B1F40_SetBlendMode(int nState); // 0x006B1F40

void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030

static __declspec(noinline) void __stdcall sub_006B9EB0_CopyBlock(unsigned short* pSource, unsigned short* pDest, int nDestPitch);

extern "C" const char gszUnlockFailed_006FC284[]; // 0x006FC284

extern "C" const char gszLockFailed_006FC2A4[]; // 0x006FC2A4

void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0

static __declspec(noinline) void __stdcall sub_006B9EB0_CopyWithAlpha(const unsigned short* pSrc, unsigned char* pDst, int nPitch);

extern "C" __declspec(dllimport) void* __stdcall SmackOpen(const char* szName, unsigned int nFlags, unsigned int nExtraBuf); // 0x006CC604

extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack); // 0x006CC608

extern "C" __declspec(dllimport) void __stdcall SmackToBuffer(void* hSmack, unsigned int nLeft, unsigned int nTop, unsigned int nPitch, unsigned int nHeight, void* pBuffer, unsigned int nFlags); // 0x006CC60C

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

int __stdcall SFileLoadFileEx(void* hMpq, const char* szFileName, void** ppBuffer, int* pnSize, int nExtraBytes, int nFlags, void* pOverlapped); // 0x0041B680

int __stdcall sub_006C6A80_DecodeImage(int nMode, void* pData, int nSize, tagPALETTEENTRY* pPalette, unsigned char* pDest, int nDestSize, int* pWidth, int* pHeight, int* pDepth); // 0x006C6A80

void __cdecl sub_006B9F00_UploadFrameBuffer(); // 0x006B9F00

extern "C" const char szD3DSmackFile_006FC358[]; // 0x006FC358

extern unsigned short* gpD3DSmackBuffer_009897D0; // 0x009897D0

extern "C" void* gAllocation_009897D0; // 0x009897D0

// 0x006B9A10
void __cdecl sub_006B9A10_Init()
{
    gnHandle_00989760 = -1;
    gnHandle_00989780 = -1;
    gnHandle_009897A0 = -1;
    gnHandle_009897C0 = -1;
    gpBuffer_009897D0 = FOG_Alloc(0x10000, ".\\Src\\d3dSmack.cpp", 0x38, 0);
    memset(gpBuffer_009897D0, 0, 0x10000);
}

// 0x006B9A50
char* __fastcall sub_006B9A50_InitBuffers(char* pBuffer)
{
    for (int i = 0; i < 2; ++i)
    {
        void** ppFirst = &gpArray_009897D4[i];
        void** ppSecond = &gpArray_009897DC[i];
        sub_006B3730_Allocate(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4A);
        D2_ASSERT(*ppSecond, 0x4B);
        ppFirst = &gpArray_009897E4[i];
        ppSecond = &gpArray_009897EC[i];
        int nResult = sub_006B58A0_Allocate(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4E);
        D2_ASSERT(*ppSecond, 0x4F);
        D2_ASSERT(nResult, 0x50);
    }
    return pBuffer + 0x10000;
}

// 0x006B9B30
void __cdecl sub_006B9B30_ReleaseObjects()
{
    for (int i = 0; i < 2; ++i)
    {
        RELEASE(gapObjectsDC_009897DC[i]);
        RELEASE(gapObjectsD4_009897D4[i]);
        RELEASE(gapObjectsEC_009897EC[i]);
        RELEASE(gapObjectsE4_009897E4[i]);
    }
}

// 0x006B9BB0
void __fastcall sub_006B9BB0_CloseSmack(D2SmackRecordStrc* pRecord)
{
    if (pRecord->nType == 's' && pRecord->hSmack)
    {
        SmackClose(pRecord->hSmack);
        pRecord->hSmack = 0;
    }
}

D2D3DTextureStrc* gpValue_009897DC; // 0x009897DC

D2D3DTextureStrc* gpValue_009897E0; // 0x009897E0

void* gpTarget_009897E4; // 0x009897E4

void* gpTarget_009897E8; // 0x009897E8

D2D3DTextureStrc* gpObject_009897EC; // 0x009897EC

D2D3DTextureStrc* gpObject_009897F0; // 0x009897F0

// 0x006B9BD0
void __cdecl sub_006B9BD0_Apply()
{
    if (gpBuffer_009897D4)
    {
        if (gnRenderFlags_0096F3A8 & gnRenderFlag_006CE290)
        {
            sub_006B38A0_Copy(gpTarget_009897E4, gpBuffer_009897D4, 0x40);
            sub_006B38A0_Copy(gpTarget_009897E8, gpBuffer_009897D8, 0x40);
        }
        else
        {
            gpObject_009897EC->lpVtbl->Load(gpObject_009897EC, gpValue_009897DC);
            gpObject_009897F0->lpVtbl->Load(gpObject_009897F0, gpValue_009897E0);
        }
    }
}

// 0x006B9C40
static void __stdcall sub_006B9C40_BlitVideo(D2SmackRecordStrc* video, int width, int height)
{
    const int top = video->nY - height;
    const int bottom = video->nY;
    sub_006B1EA0_SetState(1);
    sub_006B1F40_SetBlendMode(1);
    sub_006B2030_SetFilterMode(1);

    int x = video->nX;
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

void __fastcall sub_006BA390_PlaySmack(D2SmackRecordStrc* video)
{
    switch (video->nType)
    {
    case 's':
        {
            D2SmackStrc* smack = (D2SmackStrc*)video->hSmack;
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
        if (pSmack->hSmack)
        {
            return;
        }
        pSmack->hSmack = SmackOpen(szFile, 0xFE000, -1);
        if (!pSmack->hSmack)
        {
            break;
        }
        SmackToBuffer(pSmack->hSmack, 0, 0, 0x400, 0x80, gpD3DSmackBuffer_009897D0, 0x80000000);
        return;

    case 'p':
    {
        void* pBuffer = 0;
        int nSize = 0;
        if (!SFileLoadFileEx(0, szFile, &pBuffer, &nSize, 0, 3, 0) || !pBuffer)
        {
            break;
        }

        tagPALETTEENTRY aPalette[256];
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

    if (pSmack->nType == 's' && pSmack->hSmack)
    {
        SmackClose(pSmack->hSmack);
        pSmack->hSmack = 0;
    }
}

// 0x006B9B00
extern "C" void __cdecl sub_006B9B00_FreeGlobal()
{
    if (gAllocation_009897D0)
    {
        FOG_Free(gAllocation_009897D0, ".\\Src\\d3dSmack.cpp", 0x5E, 0);
        gAllocation_009897D0 = 0;
    }
}
