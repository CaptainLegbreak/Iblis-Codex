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

extern unsigned char* gpMulTable_00880B5C; // 0x00880B5C

// 0x0050DB20
void __cdecl GLIDE_AllocBlendTable()
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
void __cdecl GLIDE_FreeBlendTable()
{
    if (gpBlendTable_00880B5C)
    {
        FOG_Free(gpBlendTable_00880B5C, ".\\Src\\glVertex.cpp", 30, 0);
        gpBlendTable_00880B5C = 0;
    }
}

// 0x0050DBE0
void __fastcall GLIDE_SetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[nIntensity << 8];
    pVertex->dwColor = 0xFF000000 | (pRow[gnGlideAmbient_00880B5A] << 16) | (pRow[gnGlideAmbient_00880B58] << 8) | pRow[gnGlideAmbient_00880B59];
}

// 0x0050DC30
void __fastcall GLIDE_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[(unsigned char)dwColor << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[(unsigned char)(dwColor >> 8)]) << 8 | pRow[(unsigned char)(dwColor >> 16)]) << 8) | pRow[dwColor >> 24];
}


// 0x0050DD30
int __cdecl GLIDE_IsPerspective()
{
    if (gpGfxSettings_007C9148->bPerspectiveCapable)
    {
        return gpGfxSettings_007C9148->bPerspectiveEnabled;
    }

    return 0;
}

// 0x0050DB70
void __cdecl GLIDE_BuildBlendTable()
{
    for (int y = 0; y < 256; ++y)
    {
        for (int x = 0; x < 256; ++x)
        {
            gpMulTable_00880B5C[y * 256 + x] = (unsigned char)(x * y / 255);
        }
    }
}
