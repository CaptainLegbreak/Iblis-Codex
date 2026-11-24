#include "D2GlideTypes.h"
#include "D2Direct3D.h"
#include "D2DrlgMaps.h"
#include "D2D3DTypes.h"

struct D2GraphicsDeviceStrc;
struct D2GraphicsVTableStrc
{
    void* unk_00[28];
    int (__stdcall *DrawPrimitive)(D2GraphicsDeviceStrc*, int, unsigned int, void*, unsigned int, unsigned int);
};
struct D2GraphicsDeviceStrc { D2GraphicsVTableStrc* pVTable; };

extern int gnRenderWidth; // 0x007C9138
extern int gnRenderHeight; // 0x007C913C
extern D2GraphicsDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2TLVertexStrc gVertex0_00971630; // 0x00971630
extern D2TLVertexStrc gtVertex1; // 0x00971650
extern D2TLVertexStrc gtVertex2; // 0x00971670
extern D2TLVertexStrc gtVertex3; // 0x00971690
void __fastcall D3D_BindTileTexture(D2GlideTileStrc* pTile); // 0x006BBA00
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc* pVertex, unsigned int nPacked, unsigned char nAlpha); // 0x006B9780

int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc*,int,int); // 0x005FDEA0
void __fastcall D3D_SetColorCombineMode(int); // 0x006B1EA0
void __fastcall D3D_SetAlphaBlendMode(int); // 0x006B1F40
void __fastcall D3D_SetTextureFilterMode(int); // 0x006B2030
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
int __stdcall sub_006B8950_Lit(int,D2TileLibraryEntryStrc*,int,int,const unsigned int*,unsigned char); // 0x006B8950
static int __stdcall sub_006B87A0_DrawNoPerspective(D2TileLibraryEntryStrc*,int,int,const unsigned int*,int,unsigned char);
// 0x006B87A0
static int __stdcall sub_006B87A0_DrawNoPerspective(D2TileLibraryEntryStrc* pTile, int nX, int nY, const unsigned int* pLight, int nPanels, unsigned char nAlpha)
{
    int nDrawn = 0;
    int n = gnRenderWidth;
    D2RectStrc tRect;
    tRect.nLeft = 0;
    tRect.nTop = 0;
    tRect.nRight = n;
    tRect.nBottom = gnRenderHeight - 47;
    tRect.nLeft -= 32;
    tRect.nBottom += 32;

    switch (nPanels)
    {
    case 1:
        tRect.nRight -= gnRenderWidth / 2;
        break;
    case 2:
        tRect.nLeft += gnRenderWidth / 2;
        break;
    }

    nY += 32;
    for (n = 0; n < pTile->nBlocks; ++n)
    {
        int nBlockX = pTile->pBlocks[n].nPosX;
        int x = nX + nBlockX;
        int y = nY + pTile->pBlocks[n].nPosY;
        if (x >= tRect.nLeft && x < tRect.nRight && y >= tRect.nTop && y < tRect.nBottom)
        {
            const int nCol = nBlockX >> 5;
            unsigned int nLeftLight = pLight[nCol];
            unsigned int nRightLight = pLight[nCol + 1];
            int nTop = y - 32;
            int nRight = x + 32;
            nDrawn = 1;
            D3D_BindTileTexture(&pTile->pBlocks[n]);
            gVertex0_00971630.fX = (float)x;
            gVertex0_00971630.fY = (float)nTop;
            gtVertex1.fX = (float)x;
            gtVertex1.fY = (float)y;
            gtVertex2.fX = (float)nRight;
            gtVertex2.fY = (float)y;
            gtVertex3.fX = (float)nRight;
            gtVertex3.fY = (float)nTop;
            sub_006B9780_SetColor(&gVertex0_00971630, nLeftLight, nAlpha);
            sub_006B9780_SetColor(&gtVertex1, nLeftLight, nAlpha);
            sub_006B9780_SetColor(&gtVertex2, nRightLight, nAlpha);
            sub_006B9780_SetColor(&gtVertex3, nRightLight, nAlpha);
            gpDevice_00970E78->pVTable->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, &gVertex0_00971630, 4, 28);
        }
    }
    return nDrawn;
}

static int __stdcall sub_006B8DF0_AlphaWall(D2TileLibraryEntryStrc*,int,int,const unsigned int*,int,unsigned char);
static int __stdcall sub_006B8DF0_AlphaWall(D2TileLibraryEntryStrc*,int,int,const unsigned int*,int,unsigned char); // 0x006B8DF0

// build: context sub_006B8DF0_AlphaWall
static int __stdcall sub_006B8DF0_AlphaWall(D2TileLibraryEntryStrc* t,int x,int y,const unsigned int* l,int panels,unsigned char alpha)
{
 if(!D2CMPTileValidate(t,1,0))return 0;
 D3D_SetColorCombineMode(1);D3D_SetAlphaBlendMode(alpha==255?1:4);D3D_SetTextureFilterMode(1);
 if(sub_006B9830_GetPerspective())return sub_006B8950_Lit(panels,t,x,y,l,alpha);
 return sub_006B87A0_DrawNoPerspective(t,x,y,l,panels,alpha);
}

// build: context sub_006B8E60_DrawAlphaWall
int __fastcall sub_006B8E60_DrawAlphaWall(D2TileLibraryEntryStrc* t,int x,int y,const unsigned int* l,int panels,unsigned char alpha)
{ return sub_006B8DF0_AlphaWall(t,x,y,l,panels,alpha); }

int __fastcall sub_006B8E90_DrawWall(D2TileLibraryEntryStrc* t,int x,int y,const unsigned int* l,int panels); // 0x006B8E90
