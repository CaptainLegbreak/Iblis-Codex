#include "Storm.h"

struct D2Interface006B1C30Strc;
struct D2GraphicsDeviceStrc;
struct D2Interface006B1C30VtblStrc;
struct D2Config006B1C30Strc;
struct D2GfxPaletteViewStrc;
struct D2GraphicsVTableStrc;

extern int gdwGlobal_007B57E4; // 0x007B57E4
extern const unsigned int gdwMask_006CE278; // 0x006CE278
extern unsigned int gdwFlags_0096F3A8; // 0x0096F3A8

struct D2Interface006B1C30VtblStrc
{
    void* pfnSlots00[11];
    int (__stdcall* pfnMethod2C)(D2Interface006B1C30Strc* pThis, int nArg, int nMode);
};

struct D2Interface006B1C30Strc
{
    D2Interface006B1C30VtblStrc* pVtbl;
};

struct D2Config006B1C30Strc
{
    unsigned char unk_00[0x10];
    int nFlag10;
};

extern D2Config006B1C30Strc* gpConfig_007C9148; // 0x007C9148
extern D2Interface006B1C30Strc* gpInterface_00970E68; // 0x00970E68
extern int gnScreenHeight_007C913C; // 0x007C913C
extern unsigned int gdwColors_009702C0[]; // 0x009702C0

struct D2GfxPaletteViewStrc { unsigned int fields[72]; };

extern D2GfxPaletteViewStrc* gpGfxPaletteView_007C9150; // 0x007C9150
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2GraphicsVTableStrc
{
    void* unk_00[22];
    int (__stdcall *SetRenderState)(D2GraphicsDeviceStrc*, int, int);
    void* unk_5C[17];
    int (__stdcall *SetTextureState)(D2GraphicsDeviceStrc*, int, int, int);
};

struct D2GraphicsDeviceStrc { D2GraphicsVTableStrc* pVTable; };

extern D2GraphicsDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern int gnValue_0074C020; // 0x0074C020

// 0x006B1C10
void __fastcall sub_006B1C10_SetGlobal(int value)
{
    gdwGlobal_007B57E4 = value;
}

// 0x006B1C20
unsigned int __cdecl sub_006B1C20_GetMaskedFlags()
{
    return gdwFlags_0096F3A8 & gdwMask_006CE278;
}

#include "gen/data/Source/Storm/Unknown_006B1C10.inc"

// 0x006B1C30
int __cdecl sub_006B1C30_SetMode()
{
    if (gpConfig_007C9148->nFlag10)
        gpInterface_00970E68->pVtbl->pfnMethod2C(gpInterface_00970E68, 0, 1);
    else
        gpInterface_00970E68->pVtbl->pfnMethod2C(gpInterface_00970E68, 0, 9);
    return 1;
}

// 0x006B1C60
void __fastcall sub_006B1C60_GetScreenSize(int* width, int* height)
{
    *width = gnScreenWidth_007C9138;
    *height = gnScreenHeight_007C913C;
}

// 0x006B1D50
unsigned int __fastcall sub_006B1D50_GetColor(unsigned int index)
{
    return gdwColors_009702C0[index];
}

D2GfxPaletteViewStrc gPaletteView_0096F280; // 0x0096F280

// 0x006B1D60
void __fastcall sub_006B1D60_SetPaletteView(const D2GfxPaletteViewStrc* source)
{
    gPaletteView_0096F280 = *source;
    gpGfxPaletteView_007C9150 = &gPaletteView_0096F280;
}

// 0x006B1D80
void __fastcall sub_006B1D80_CopyRows(char* pSrc, char* pDst, int nBytes, int nRows, int nDstPitch, int nUnused)
{
    for (int i = 0; i < nRows; ++i)
    {
        memcpy(pDst, pSrc, nBytes);
        pSrc += nBytes;
        pDst += nDstPitch;
    }
}

int gnState_00970E54; // 0x00970E54

// 0x006B1EA0
void __fastcall sub_006B1EA0_SetState(int nState)
{
    if (gnState_00970E54 && nState == gnState_00970E54)
        return;
    switch (nState)
    {
    case 1:
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 1, 4);
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 4, 4);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 15, 1);
        break;
    case 2:
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 1, 3);
        gpDevice_00970E78->pVTable->SetTextureState(gpDevice_00970E78, 0, 4, 3);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 15, 0);
        break;
    }
    gnState_00970E54 = nState;
}

int gnState_00970E58; // 0x00970E58

D2GraphicsDeviceStrc* gpDevice_00970E78; // 0x00970E78

// 0x006B1F40
void __fastcall sub_006B1F40_SetBlendMode(int nState)
{
    if (gnState_00970E58 && nState == gnState_00970E58)
        return;
    switch (nState)
    {
    case 1:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 0);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 2);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 1);
        break;
    case 2:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 2);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 2);
        break;
    case 3:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 3);
        break;
    case 4:
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 27, 1);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 19, 5);
        gpDevice_00970E78->pVTable->SetRenderState(gpDevice_00970E78, 20, 6);
        break;
    }
    gnState_00970E58 = nState;
}

// 0x006B20C0
int __fastcall sub_006B20C0_SetOption(int nId, int nValue)
{
    if (nId != 11)
        return 0;
    gnValue_0074C020 = nValue;
    return 1;
}
