struct T004F51E0
{
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct D2Palette256Strc
{
    unsigned char data[0x100];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                   // 0x006CC260
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
void __stdcall D2GFX_SetPalette(T004F51E0* pPalette);                                              // 0x004F63D0

extern int dword_6F8BE008;                                                                                  // 0x0072DE50
int dword_6F90E290;                                                                                         // 0x007D5638
unsigned char gStatesPalette_6F9626C0[128][0x100];                                                          // 0x007D6468
extern T004F51E0 gRGBAPalette_0081E668[];                                                          // 0x0081E668
extern D2Palette256Strc gShadowsLightGammaPalette_0081EA68[49];                                             // 0x0081EA68
int dword_6F96A7C0;                                                                                         // 0x00841B68
unsigned long dword_6F96A7C4;                                                                               // 0x00841B6C
extern int gdwGlobal_00841B70;                                                                              // 0x00841B70

// 0x004FB0C0
unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex)
{
    return gStatesPalette_6F9626C0[nIndex];
}

// 0x004FB0D0
void __stdcall D2Win_10179()
{
    if (!dword_6F8BE008)
    {
        return;
    }

    if (dword_6F96A7C0)
    {
        if (GetTickCount() - dword_6F96A7C4 <= 2000)
        {
            return;
        }

        dword_6F96A7C4 = GetTickCount();

        --dword_6F90E290;
        if (dword_6F90E290 > 0)
        {
            D2GFX_SetPalette(gRGBAPalette_0081E668);
            return;
        }

        dword_6F96A7C0 = 0;
    }

    dword_6F8BE008 = 0;
    D2GFX_SetPalette(gRGBAPalette_0081E668);
}

// 0x004FB130
void __fastcall D2Win_10176(int bTimed)
{
    if (bTimed)
    {
        dword_6F96A7C0 = 1;
        dword_6F96A7C4 = GetTickCount();
        dword_6F90E290 = 2;
        dword_6F8BE008 = 1;
        D2GFX_SetPalette(gRGBAPalette_0081E668);
    }
    else
    {
        dword_6F96A7C0 = 0;
        dword_6F8BE008 = 0;
        D2GFX_SetPalette(gRGBAPalette_0081E668);
    }
}

// 0x004FB1C0
void __fastcall sub_004FB1C0_CopyRowTable(unsigned char (*pRows)[0x100])
{
    memcpy(pRows, gShadowsLightGammaPalette_0081EA68, sizeof(gShadowsLightGammaPalette_0081EA68));
}

// 0x004FB590
void __fastcall sub_004FB590(int nValue)
{
    gdwGlobal_00841B70 = nValue;
}

#include "gen/data/Source/D2Win/004FB0C0_D2Win_10175_GetPL2Shift.inc"
