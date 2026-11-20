#include "D2Glide.h"

struct D2GlideSettingsStrc;
extern unsigned char* gpBlendTable_00880B5C; // 0x00880B5C
extern int* gpnPerspectiveTable_00880B6C; // 0x00880B6C

struct T00508FE0
{
    float fX;
    float fY;
    unsigned int dwColor;
};

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

// 0x0050DC80
void __cdecl sub_0050DC80_AllocPerspectiveTable()
{
    gpnPerspectiveTable_00880B6C = (int*)FOG_Alloc(0x8000, ".\\Src\\glPerspective.cpp", 0x38, 0);
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
void __fastcall sub_0050DBE0_GlideSetVertexAmbientColor(T00508FE0* pVertex, unsigned char nIntensity)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[nIntensity << 8];
    pVertex->dwColor = 0xFF000000 | (pRow[gnGlideAmbient_00880B5A] << 16) | (pRow[gnGlideAmbient_00880B58] << 8) | pRow[gnGlideAmbient_00880B59];
}

// 0x0050DC30
void __fastcall sub_0050DC30_GlideSetVertexColor(T00508FE0* pVertex, unsigned int dwColor)
{
    const unsigned char* pRow = &gpBlendTable_00880B5C[(unsigned char)dwColor << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[(unsigned char)(dwColor >> 8)]) << 8 | pRow[(unsigned char)(dwColor >> 16)]) << 8) | pRow[dwColor >> 24];
}

// 0x0050DCA0
void __cdecl sub_0050DCA0_FreePerspectiveTable()
{
    if (gpnPerspectiveTable_00880B6C)
    {
        FOG_Free(gpnPerspectiveTable_00880B6C, ".\\Src\\glPerspective.cpp", 63, 0);
        gpnPerspectiveTable_00880B6C = 0;
    }
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

// 0x0050DF70
void __cdecl sub_0050DF70_GlideSmackFree()
{
    if (gpGlideSmackBufferB_00880B70)
    {
        FOG_Free(gpGlideSmackBufferB_00880B70, ".\\Src\\glSmack.cpp", 86, 0);
        gpGlideSmackBufferB_00880B70 = 0;
    }
    if (gpGlideSmackBufferC_00880B74)
    {
        FOG_Free(gpGlideSmackBufferC_00880B74, ".\\Src\\glSmack.cpp", 91, 0);
        gpGlideSmackBufferC_00880B74 = 0;
    }
    if (sgbSmack8BitBuffer)
    {
        FOG_Free(sgbSmack8BitBuffer, ".\\Src\\glSmack.cpp", 96, 0);
        sgbSmack8BitBuffer = 0;
    }
}
