#include "Storm.h"

struct D2GammaControlStrc;
struct D2DDrawSurfaceStrc;
struct D2ComObject006B3730Strc;
struct D2SurfaceStrc;
struct D2GammaRampStrc;
struct D2GammaControlVTableStrc;
struct D2DDSurfaceDescStrc;
struct D2DDrawSurfaceVtblStrc;
struct D2DDPixelFormat006B3730Strc;
struct D2DDSurfaceDesc006B3730Strc;
struct D2ComObjectVtbl006B3730Strc;
struct D2SurfaceDescStrc;
struct D2SurfaceVtableStrc;
struct D2VideoKeyStrc;

struct D2GammaRampStrc { int red[128], green[128], blue[128]; };

struct D2GammaControlVTableStrc
{
    void* unk_00[4];
    int (__stdcall *SetGammaRamp)(D2GammaControlStrc*, int, D2GammaRampStrc*);
};

struct D2GammaControlStrc { D2GammaControlVTableStrc* pVTable; };

extern const unsigned int gnGammaMask_006CE278; // 0x006CE278
extern unsigned int gnCapabilities_0096F3A8; // 0x0096F3A8
extern int gnGammaScale_0074C020; // 0x0074C020
extern D2GammaControlStrc* gpGammaControl_00970E74; // 0x00970E74
void __fastcall sub_006BE190_BuildGammaTable(int nGamma, void* pTable, double dScale, int nStride, int nEntries, int nMask); // 0x006BE190
void __fastcall sub_006B20E0_ReportError(const char* szMessage, int nResult); // 0x006B20E0
extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nBytes);

struct D2DDrawSurfaceVtblStrc
{
    void* unk0x00[25];
    long (__stdcall* Lock)(D2DDrawSurfaceStrc* pThis, void* pDestRect, D2DDSurfaceDescStrc* pSurfaceDesc, unsigned long dwFlags, void* hEvent);
    void* unk0x68[6];
    long (__stdcall* Unlock)(D2DDrawSurfaceStrc* pThis, void* pRect);
};

struct D2DDrawSurfaceStrc
{
    D2DDrawSurfaceVtblStrc* lpVtbl;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern int gnScreenHeight_007C913C; // 0x007C913C
extern D2DDrawSurfaceStrc* gpSurface_00970E6C; // 0x00970E6C

struct D2DDPixelFormat006B3730Strc
{
    unsigned int aData[8];
};

struct D2DDSurfaceDesc006B3730Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int dwHeight;
    unsigned int dwWidth;
    unsigned int aUnk0x10[14];
    D2DDPixelFormat006B3730Strc tPixelFormat;
    unsigned int dwCaps;
    unsigned int aCaps2[3];
    unsigned int dwTextureStage;
};

struct D2ComObjectVtbl006B3730Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B3730Strc* pThis, const void* pIid, void** ppOut);
    unsigned long (__stdcall* AddRef)(D2ComObject006B3730Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B3730Strc* pThis);
    void* pfn0C;
    void* pfn10;
    void* pfn14;
    long (__stdcall* CreateSurface)(D2ComObject006B3730Strc* pThis, D2DDSurfaceDesc006B3730Strc* pDesc, D2ComObject006B3730Strc** ppSurface, void* pOuter);
};

struct D2ComObject006B3730Strc
{
    D2ComObjectVtbl006B3730Strc* lpVtbl;
};

extern D2ComObject006B3730Strc* gpDirectDraw_00970E60; // 0x00970E60
extern D2DDPixelFormat006B3730Strc gtWantedFormat_0074C024; // 0x0074C024
extern const unsigned char gIidTexture_006FF478[16]; // 0x006FF478

struct D2SurfaceDescStrc
{
    unsigned int nSize;
    unsigned int f_4[3];
    int nPitch;
    unsigned int unk_14[4];
    void* pPixels;
    unsigned int unk_28[21];
};

struct D2SurfaceVtableStrc
{
    void* unk_00[25];
    int (__stdcall* Lock)(D2SurfaceStrc*, void*, D2SurfaceDescStrc*, unsigned int, void*);
    void* unk_68[6];
    int (__stdcall* Unlock)(D2SurfaceStrc*, void*);
};

struct D2SurfaceStrc
{
    D2SurfaceVtableStrc* f_0;
};

extern D2SurfaceStrc* gpPrimarySurface_00970E68; // 0x00970E68
extern D2SurfaceStrc* gpRenderSurface_00970E6C; // 0x00970E6C
void __cdecl sub_00410610_WriteLogLine(const char*,...); // 0x00410610

struct T004013C0 { int unk00; int mode; };
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __stdcall sub_006B4C90_ShowVideoConfiguration(void*); // 0x006B4C90
int __stdcall SRegLoadString(const char*,const char*,unsigned int,char*,unsigned int); // 0x00414E50
int __stdcall SRegLoadValue(const char*,const char*,unsigned int,unsigned long*); // 0x00414F10
int __stdcall SRegLoadData(const char*,const char*,unsigned int,void*,unsigned int,unsigned int*); // 0x00414DE0

#pragma pack(push, 1)
struct D2VideoKeyStrc { unsigned int words[5]; unsigned short tail; };

#pragma pack(pop)

extern const D2VideoKeyStrc gVideoKey_006DD634; // 0x006DD634

// 0x006B3570
void __fastcall sub_006B3570_SetGamma(int nGamma)
{
    D2GammaRampStrc ramp;
    if (gnCapabilities_0096F3A8 & gnGammaMask_006CE278)
    {
        sub_006BE190_BuildGammaTable(nGamma, (unsigned short*)ramp.red, gnGammaScale_0074C020, 2, 256, 65535);
        memcpy(ramp.green, ramp.red, sizeof(ramp.red));
        memcpy(ramp.blue, ramp.red, sizeof(ramp.red));
        if (gpGammaControl_00970E74)
        {
            int nResult = gpGammaControl_00970E74->pVTable->SetGammaRamp(gpGammaControl_00970E74, 0, &ramp);
            if (nResult)
                sub_006B20E0_ReportError("Failed to set gamma ramp", nResult);
        }
    }
}

// 0x006B3610
int __fastcall sub_006B3610_ReadScreenRGB(unsigned char* pDst)
{
    D2DDSurfaceDescStrc tDesc = { sizeof(D2DDSurfaceDescStrc) };
    if (!gpSurface_00970E6C)
    {
        return 0;
    }

    long hResult = gpSurface_00970E6C->lpVtbl->Lock(gpSurface_00970E6C, 0, &tDesc, 0x11, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError("Lock failed!", hResult);
        return 0;
    }

    int nPitch = tDesc.lPitch / 4;
    unsigned char* pOutRow = pDst;
    unsigned int* pSrcRow = (unsigned int*)tDesc.lpSurface;
    for (int y = 0; y < gnScreenHeight_007C913C; ++y)
    {
        unsigned char* pOut = pOutRow;
        unsigned int* pSrc = pSrcRow;
        for (int x = 0; x < gnScreenWidth_007C9138; ++x)
        {
            unsigned int dwPixel = *pSrc++;
            *pOut++ = (unsigned char)(dwPixel >> 16);
            *pOut++ = (unsigned char)(dwPixel >> 8);
            *pOut++ = (unsigned char)dwPixel;
        }
        pOutRow += gnScreenWidth_007C9138 * 3;
        pSrcRow += nPitch;
    }

    hResult = gpSurface_00970E6C->lpVtbl->Unlock(gpSurface_00970E6C, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError("Unlock failed!", hResult);
        return 0;
    }
    return 1;
}

// 0x006B3730
int __fastcall sub_006B3730_CreateMemoryTexture(D2ComObject006B3730Strc** ppSurface, D2ComObject006B3730Strc** ppTexture, unsigned int nWidth, unsigned int nHeight)
{
    D2DDSurfaceDesc006B3730Strc tDesc = { sizeof(tDesc) };
    tDesc.dwFlags = 0x1007;
    tDesc.dwCaps = 0x840;
    tDesc.tPixelFormat = gtWantedFormat_0074C024;
    tDesc.dwWidth = nWidth;
    tDesc.dwHeight = nHeight;
    long hResult = gpDirectDraw_00970E60->lpVtbl->CreateSurface(gpDirectDraw_00970E60, &tDesc, ppSurface, 0);
    if (hResult)
    {
        sub_006B20E0_ReportError("CreateSurface (memory surface)", hResult);
        return 0;
    }
    hResult = (*ppSurface)->lpVtbl->QueryInterface(*ppSurface, gIidTexture_006FF478, (void**)ppTexture);
    if (hResult)
    {
        sub_006B20E0_ReportError("Failed to get texture interface for memory surface", hResult);
        (*ppSurface)->lpVtbl->Release(*ppSurface);
        return 0;
    }
    return 1;
}

#include "gen/data/Source/Storm/Unknown_006B3570.inc"

// 0x006B3800
void __cdecl sub_006B3800_Flush()
{
    D2SurfaceStrc* pSurface = gpRenderSurface_00970E6C ? gpRenderSurface_00970E6C : gpPrimarySurface_00970E68;
    D2SurfaceDescStrc desc;
    desc.nSize = sizeof(desc);
    memset((char*)&desc + sizeof(desc.nSize), 0, sizeof(desc) - sizeof(desc.nSize));
    int nResult = pSurface->f_0->Lock(pSurface, 0, &desc, 0x21, 0);
    if (nResult)
    {
        sub_006B20E0_ReportError("Failed to lock render surface for clear", nResult);
        return;
    }
    int nHeight = gnScreenHeight_007C913C;
    int nPitch = desc.nPitch;
    char* pPixels = (char*)desc.pPixels;
    while (nHeight)
    {
        --nHeight;
        memset(pPixels, 0, nPitch);
        pPixels += nPitch;
    }
    pSurface->f_0->Unlock(pSurface, 0);
}

// 0x006B39B0
void __fastcall sub_006B39B0_ShowD3DError(const char* text,long result)
{
    const char* name;
    switch(result) {
    case (long)0x887602BC: name="D3DERR_BADMAJORVERSION"; break;
    case (long)0x887602BD: name="D3DERR_BADMINORVERSION"; break;
    case (long)0x887602C1: name="D3DERR_INVALID_DEVICE"; break;
    case (long)0x887602C2: name="D3DERR_INITFAILED"; break;
    case (long)0x887602C3: name="D3DERR_DEVICEAGGREGATED"; break;
    case (long)0x887602C6: name="D3DERR_EXECUTE_CREATE_FAILED"; break;
    case (long)0x887602C7: name="D3DERR_EXECUTE_DESTROY_FAILED"; break;
    case (long)0x887602C8: name="D3DERR_EXECUTE_LOCK_FAILED"; break;
    case (long)0x887602C9: name="D3DERR_EXECUTE_UNLOCK_FAILED"; break;
    case (long)0x887602CA: name="D3DERR_EXECUTE_LOCKED"; break;
    case (long)0x887602CB: name="D3DERR_EXECUTE_NOT_LOCKED"; break;
    case (long)0x887602CC: name="D3DERR_EXECUTE_FAILED"; break;
    case (long)0x887602CD: name="D3DERR_EXECUTE_CLIPPED_FAILED"; break;
    case (long)0x887602D0: name="D3DERR_TEXTURE_NO_SUPPORT"; break;
    case (long)0x887602D1: name="D3DERR_TEXTURE_CREATE_FAILED"; break;
    case (long)0x887602D2: name="D3DERR_TEXTURE_DESTROY_FAILED"; break;
    case (long)0x887602D3: name="D3DERR_TEXTURE_LOCK_FAILED"; break;
    case (long)0x887602D4: name="D3DERR_TEXTURE_UNLOCK_FAILED"; break;
    case (long)0x887602D5: name="D3DERR_TEXTURE_LOAD_FAILED"; break;
    case (long)0x887602D6: name="D3DERR_TEXTURE_SWAP_FAILED"; break;
    case (long)0x887602D7: name="D3DERR_TEXTURE_LOCKED"; break;
    case (long)0x887602D8: name="D3DERR_TEXTURE_NOT_LOCKED"; break;
    case (long)0x887602D9: name="D3DERR_TEXTURE_GETSURF_FAILED"; break;
    case (long)0x887602DA: name="D3DERR_MATRIX_CREATE_FAILED"; break;
    case (long)0x887602DB: name="D3DERR_MATRIX_DESTROY_FAILED"; break;
    case (long)0x887602DC: name="D3DERR_MATRIX_SETDATA_FAILED"; break;
    case (long)0x887602DD: name="D3DERR_MATRIX_GETDATA_FAILED"; break;
    case (long)0x887602DE: name="D3DERR_SETVIEWPORTDATA_FAILED"; break;
    case (long)0x887602DF: name="D3DERR_INVALIDCURRENTVIEWPORT"; break;
    case (long)0x887602E0: name="D3DERR_INVALIDPRIMITIVETYPE"; break;
    case (long)0x887602E1: name="D3DERR_INVALIDVERTEXTYPE"; break;
    case (long)0x887602E2: name="D3DERR_TEXTURE_BADSIZE"; break;
    case (long)0x887602E3: name="D3DERR_INVALIDRAMPTEXTURE"; break;
    case (long)0x887602E4: name="D3DERR_MATERIAL_CREATE_FAILED"; break;
    case (long)0x887602E5: name="D3DERR_MATERIAL_DESTROY_FAILED"; break;
    case (long)0x887602E6: name="D3DERR_MATERIAL_SETDATA_FAILED"; break;
    case (long)0x887602E7: name="D3DERR_MATERIAL_GETDATA_FAILED"; break;
    case (long)0x887602E8: name="D3DERR_INVALIDPALETTE"; break;
    case (long)0x887602E9: name="D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY"; break;
    case (long)0x887602EA: name="D3DERR_ZBUFF_NEEDS_VIDEOMEMORY"; break;
    case (long)0x887602EB: name="D3DERR_SURFACENOTINVIDMEM"; break;
    case (long)0x887602EE: name="D3DERR_LIGHT_SET_FAILED"; break;
    case (long)0x887602EF: name="D3DERR_LIGHTHASVIEWPORT"; break;
    case (long)0x887602F0: name="D3DERR_LIGHTNOTINTHISVIEWPORT"; break;
    case (long)0x887602F8: name="D3DERR_SCENE_IN_SCENE"; break;
    case (long)0x887602F9: name="D3DERR_SCENE_NOT_IN_SCENE"; break;
    case (long)0x887602FA: name="D3DERR_SCENE_BEGIN_FAILED"; break;
    case (long)0x887602FB: name="D3DERR_SCENE_END_FAILED"; break;
    case (long)0x88760302: name="D3DERR_INBEGIN"; break;
    case (long)0x88760303: name="D3DERR_NOTINBEGIN"; break;
    case (long)0x88760304: name="D3DERR_NOVIEWPORTS"; break;
    case (long)0x88760305: name="D3DERR_VIEWPORTDATANOTSET"; break;
    case (long)0x88760306: name="D3DERR_VIEWPORTHASNODEVICE"; break;
    case (long)0x88760307: name="D3DERR_NOCURRENTVIEWPORT"; break;
    case 0: name="D3D_OK"; break;
    default: sub_006B20E0(text,result); return;
    }
    sub_00410610_WriteLogLine("***** Direct3D error: %s - %s (0x%x)",text,name,result);
}

int gbConfigured_00970EB8; // 0x00970EB8

int gbSeen_00970EBC; // 0x00970EBC

char gszDevice_0096F3BC[264]; // 0x0096F3BC

unsigned long gnFlags_0096F3A8; // 0x0096F3A8

unsigned int gGuid_0096F3AC[4]; // 0x0096F3AC

// 0x006B4E80
int __fastcall sub_006B4E80_LoadVideoConfiguration(void* window) {
    T004013C0* info=sub_00407360_GetSystemInfo();
    if (!info) { sub_00408A60(gszEmpty_006CC837,sub_00408090(),1032); exit(-1); }
    if (info->mode==1) return 0;
    D2VideoKeyStrc key=gVideoKey_006DD634;
    if (gbSeen_00970EBC && !gbConfigured_00970EB8) {
        sub_006B4C90_ShowVideoConfiguration(window);
        gbConfigured_00970EB8=1;
    }
    gbSeen_00970EBC=1;
    for (;;) {
        if (!SRegLoadString((const char*)&key,"DeviceName",0,gszDevice_0096F3BC,256)) {
            if (gbConfigured_00970EB8) return 0;
            int result=sub_006B4C90_ShowVideoConfiguration(window);
            gbConfigured_00970EB8=1;
            if (result!=2) return 0;
        } else if (!SRegLoadValue((const char*)&key,"dwFlags",0,&gnFlags_0096F3A8)) {
            if (gbConfigured_00970EB8) return 0;
            int result=sub_006B4C90_ShowVideoConfiguration(window);
            gbConfigured_00970EB8=1;
            if (result!=2) return 0;
        } else break;
    }
    if (!(gnFlags_0096F3A8 & gdwBitMasks_006CE268[0])) {
        unsigned int length=16;
        if (!SRegLoadData((const char*)&key,"GUID",0,gGuid_0096F3AC,16,&length) || length!=16) return 0;
    }
    return 1;
}
