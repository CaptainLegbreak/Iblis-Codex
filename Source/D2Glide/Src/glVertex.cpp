#include "D2Glide.h"

struct D2GlideSettingsStrc;
extern unsigned char* gpBlendTable_00880B5C; // 0x00880B5C
extern int* gpnPerspectiveTable_00880B6C; // 0x00880B6C

struct D2GlideSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
};
extern unsigned char* sgbSmack8BitBuffer; // 0x00880BF0
extern D2GlideSettingsStrc* gpGfxSettings_007C9148; // 0x007C9148

// 0x0050DB20
void __cdecl sub_0050DB20_AllocBlendTable()
{
    gpBlendTable_00880B5C = (unsigned char*)FOG_Alloc(0x10000, ".\\Src\\glVertex.cpp", 0x17, 0);
}


unsigned char* gpBlendTable_00880B5C; // 0x00880B5C

int* gpnPerspectiveTable_00880B6C; // 0x00880B6C

unsigned char* gpGlideSmackBufferB_00880B70; // 0x00880B70

unsigned char* gpGlideSmackBufferC_00880B74; // 0x00880B74

unsigned char gnGlideAmbient_00880B58; // 0x00880B58

unsigned char gnGlideAmbient_00880B59; // 0x00880B59

unsigned char gnGlideAmbient_00880B5A; // 0x00880B5A

// 0x0050DB40
void __cdecl sub_0050DB40_FreeBlendTable()
{
    if (gpBlendTable_00880B5C)
    {
        FOG_Free(gpBlendTable_00880B5C, ".\\Src\\glVertex.cpp", 30, 0);
        gpBlendTable_00880B5C = 0;
    }
}

// 0x0050DBE0
void __fastcall sub_0050DBE0_GlideSetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[nIntensity << 8];
    pVertex->dwColor = 0xFF000000 | (pRow[gnGlideAmbient_00880B5A] << 16) | (pRow[gnGlideAmbient_00880B58] << 8) | pRow[gnGlideAmbient_00880B59];
}

// 0x0050DC30
void __fastcall sub_0050DC30_GlideSetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[(unsigned char)dwColor << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[(unsigned char)(dwColor >> 8)]) << 8 | pRow[(unsigned char)(dwColor >> 16)]) << 8) | pRow[dwColor >> 24];
}


// 0x0050DD30
int __cdecl sub_0050DD30_GlideIsPerspective()
{
    if (gpGfxSettings_007C9148->bPerspectiveCapable)
    {
        return gpGfxSettings_007C9148->bPerspectiveEnabled;
    }

    return 0;
}

