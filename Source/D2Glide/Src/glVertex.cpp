#include "D2Glide.h"

struct D2GlideSettingsStrc;
extern unsigned char* gpBlendTable; // 0x00880B5C
extern int* gpnPerspectiveTable; // 0x00880B6C

struct D2GlideSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
};
extern unsigned char* sgbSmack8BitBuffer; // 0x00880BF0
extern D2GlideSettingsStrc* gpGfxSettings; // 0x007C9148

extern unsigned char* gpMulTable_00880B5C; // 0x00880B5C

// 0x0050DB20
void __cdecl GLIDE_AllocBlendTable()
{
    gpBlendTable = (unsigned char*)FOG_Alloc(0x10000, ".\\Src\\glVertex.cpp", 0x17, 0);
}


unsigned char* gpBlendTable; // 0x00880B5C

int* gpnPerspectiveTable; // 0x00880B6C

unsigned char* gpGlideSmackBufferB; // 0x00880B70

unsigned char* gpGlideSmackBufferC; // 0x00880B74

unsigned char gbGlideAmbientGreen; // 0x00880B58

unsigned char gbGlideAmbientBlue; // 0x00880B59

unsigned char gbGlideAmbientRed; // 0x00880B5A

// 0x0050DB40
void __cdecl GLIDE_FreeBlendTable()
{
    if (gpBlendTable)
    {
        FOG_Free(gpBlendTable, ".\\Src\\glVertex.cpp", 30, 0);
        gpBlendTable = 0;
    }
}

// 0x0050DBE0
void __fastcall GLIDE_SetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity)
{
    const unsigned char* pRow = &gpBlendTable[nIntensity << 8];
    pVertex->dwColor = 0xFF000000 | (pRow[gbGlideAmbientRed] << 16) | (pRow[gbGlideAmbientGreen] << 8) | pRow[gbGlideAmbientBlue];
}

// 0x0050DC30
void __fastcall GLIDE_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor)
{
    const unsigned char* pRow = &gpBlendTable[(unsigned char)dwColor << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[(unsigned char)(dwColor >> 8)]) << 8 | pRow[(unsigned char)(dwColor >> 16)]) << 8) | pRow[dwColor >> 24];
}


// 0x0050DD30
int __cdecl GLIDE_IsPerspective()
{
    if (gpGfxSettings->bPerspectiveCapable)
    {
        return gpGfxSettings->bPerspectiveEnabled;
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
