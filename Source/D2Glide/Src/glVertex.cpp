#include "D2Glide.h"
#include "D2DrlgMaps.h"

struct D2GlideSettingsStrc;

unsigned char* gpBlendTable; // 0x00880B5C

int* gpnPerspectiveTable; // 0x00880B6C

struct D2GlideSettingsStrc
{
    int bPerspectiveEnabled;
    int bPerspectiveCapable;
};

extern unsigned char* sgbSmack8BitBuffer; // 0x00880BF0

extern D2GlideSettingsStrc* gpGfxSettings; // 0x007C9148

extern unsigned char* gpMulTable_00880B5C; // 0x00880B5C

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall sub_00511FB0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette); // 0x00511FB0

extern int gnProjectOriginX; // 0x00880B60

extern int gnProjectOriginY; // 0x00880B68

unsigned char* gpGlideSmackBufferB; // 0x00880B70

unsigned char* gpGlideSmackBufferC; // 0x00880B74

unsigned char gbGlideAmbientGreen; // 0x00880B58

unsigned char gbGlideAmbientBlue; // 0x00880B59

unsigned char gbGlideAmbientRed; // 0x00880B5A

extern int gnGlideSpriteScale; // 0x00880B64

void __fastcall GLPERSPECTIVE_SetProjectOrigin(int nX, int nY); // 0x0050DD50

void __cdecl sub_0050DF00_ResetSpriteScale(); // 0x0050DF00

void __stdcall sub_0050F980_DecodeTileBlocks(D2TileLibraryEntryStrc* pTile, unsigned char* pDst); // 0x0050F980

int __fastcall sub_00512410_ForwardToDrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nScreenMode, void* pPalette); // 0x00512410

// 0x0050DB20
void __cdecl GLVERTEX_AllocBlendTable()
{
    gpBlendTable = (unsigned char*)FOG_Alloc(0x10000, ".\\Src\\glVertex.cpp", 0x17, 0);
}

// 0x0050DB40
void __cdecl GLVERTEX_FreeBlendTable()
{
    if (gpBlendTable)
    {
        FOG_Free(gpBlendTable, ".\\Src\\glVertex.cpp", 30, 0);
        gpBlendTable = 0;
    }
}

// 0x0050DB70
void __cdecl GLVERTEX_BuildBlendTable()
{
    for (int y = 0; y < 256; ++y)
    {
        for (int x = 0; x < 256; ++x)
        {
            gpMulTable_00880B5C[y * 256 + x] = (unsigned char)(x * y / 255);
        }
    }
}

// 0x0050DBC0
void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue)
{
    gbGlideAmbientRed = nRed;
    gbGlideAmbientGreen = nGreen;
    gbGlideAmbientBlue = nBlue;
}

// 0x0050DBE0
void __fastcall GLVERTEX_SetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity)
{
    const unsigned char* pRow = &gpBlendTable[nIntensity << 8];
    pVertex->dwColor = 0xFF000000 | (pRow[gbGlideAmbientRed] << 16) | (pRow[gbGlideAmbientGreen] << 8) | pRow[gbGlideAmbientBlue];
}

// 0x0050DC30
void __fastcall GLVERTEX_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor)
{
    const unsigned char* pRow = &gpBlendTable[(unsigned char)dwColor << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[(unsigned char)(dwColor >> 8)]) << 8 | pRow[(unsigned char)(dwColor >> 16)]) << 8) | pRow[dwColor >> 24];
}

// 0x0050DD30
int __cdecl GLVERTEX_IsPerspective()
{
    if (gpGfxSettings->bPerspectiveCapable)
    {
        return gpGfxSettings->bPerspectiveEnabled;
    }

    return 0;
}
