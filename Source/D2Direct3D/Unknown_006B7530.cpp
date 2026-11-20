#include "D2Direct3D.h"
#include "D2D3DTypes.h"
#define WRITE_CORNER(i) pVertices[i].dwColor=PackGridColor(pPoints[i],nAlpha); pVertices[i].fX=(float)pPoints[i].nX; pVertices[i].fY=(float)pPoints[i].nY;
struct D2DrawDeviceStrc;
struct D2TileLibraryEntryStrc;
struct D2TexturedVertexStrc;
struct D2RectStrc;
struct D2ClipRectStrc;
struct D2TilePartStrc;
struct D2TileContextStrc;
struct D2QuadVertexStrc;
struct D2DrawVtableStrc;
struct D2PerspectiveTileStrc;
struct D2PerspectiveSpriteStrc;
struct Vertex;
struct BufferDescription;
struct VertexBuffer;
struct GraphicsInterface;
struct IndexStrip;
struct D2GridPointStrc;
struct D2RendererSettingsStrc;

extern D2TexturedVertexStrc gaVertices_00970F48[4]; // 0x00970F48
__declspec(noinline) static int __stdcall sub_006B7530_DrawGlyph(int nX, int nY, char nChar);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
__declspec(noinline) static void __stdcall sub_006B7FD0_GetPanelRect(D2RectStrc* pRect, int nSide, int* pOffset, int bFlag);

struct D2ClipRectStrc { int left,top,right,bottom; };

struct D2TilePartStrc { short x,y; char unknown004[16]; };

struct D2TileContextStrc { char unknown000[0x50]; int count; D2TilePartStrc* parts; };

struct D2DrawVtableStrc { void* unknown000[28]; int (__stdcall* DrawPrimitive)(D2DrawDeviceStrc*,int,unsigned int,void*,unsigned int,unsigned int); };

struct D2DrawDeviceStrc { D2DrawVtableStrc* vtable; };

extern D2QuadVertexStrc gaQuadVertices[4]; // 0x00971630
extern D2DrawDeviceStrc* gpDrawDevice; // 0x00970E78
void __fastcall sub_006BBA00_BindTilePart(D2TilePartStrc*); // 0x006BBA00
void __fastcall sub_006B9730_SetQuadColor(D2QuadVertexStrc*,unsigned char,int); // 0x006B9730

struct D2PerspectiveTileStrc { short nX,nY; char unknown04[0x10]; };

struct D2PerspectiveSpriteStrc { char unknown00[0x50]; int nTiles; D2PerspectiveTileStrc* pTiles; };

extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2TLVertexStrc gaPerspectiveVertices[15]; // 0x00971450
extern unsigned short gaPerspectiveIndices[22]; // 0x0074C0D0
void __fastcall sub_006B9860_Project(int nX,int nY,int nZ,int* pOutX,int* pOutY); // 0x006B9860
void __fastcall sub_006B9730_SetColor(D2TLVertexStrc* pVertex,unsigned char nIndex,unsigned char nAlpha); // 0x006B9730
void __fastcall sub_006BBA00_SelectTile(D2PerspectiveTileStrc* pTile); // 0x006BBA00
int __stdcall sub_005FDEA0_CheckSurface(void*, int, int); // 0x005FDEA0
void __fastcall sub_006B1F40_SetBlendMode(int); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int); // 0x006B2030
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
int __stdcall sub_006B8950_DrawAlternate(void*, void*, int, int, int, unsigned char); // 0x006B8950
int __stdcall sub_006B87A0_DrawNormal(void*, void*, int, int, int, unsigned char); // 0x006B87A0
static __declspec(noinline) int __stdcall sub_006B8DF0_DrawConfigured(void*, int, int, int, void*, unsigned char);

struct Vertex { float x,y,z,rhw; unsigned int diffuse,specular; float u,v; };

struct BufferDescription { unsigned int size,caps,format,count; };

struct VertexBuffer {
 virtual long __stdcall QueryInterface(const void*,void**) = 0;
 virtual unsigned long __stdcall AddRef() = 0;
 virtual unsigned long __stdcall Release() = 0;
 virtual long __stdcall Lock(unsigned int,Vertex**,unsigned int*) = 0;
 virtual long __stdcall Unlock() = 0;
};

struct GraphicsInterface {
 virtual long __stdcall QueryInterface(const void*,void**) = 0;
 virtual unsigned long __stdcall AddRef() = 0;
 virtual unsigned long __stdcall Release() = 0;
 virtual void __stdcall Unused0C() = 0;
 virtual void __stdcall Unused10() = 0;
 virtual void __stdcall Unused14() = 0;
 virtual void __stdcall Unused18() = 0;
 virtual void __stdcall Unused1C() = 0;
 virtual void __stdcall Unused20() = 0;
 virtual long __stdcall CreateVertexBuffer(BufferDescription*,VertexBuffer**,unsigned int,void*) = 0;
};

struct IndexStrip { unsigned short indices[12];unsigned short last; };

extern int gTileWidth; // 0x0096F4DC
extern int gTileHeight; // 0x009702B8
extern GraphicsInterface* gGraphics; // 0x00970E64
extern VertexBuffer* gGridBuffer; // 0x00971734
extern IndexStrip gIndexStrips[5]; // 0x009716B0
extern const char gCreateFailure[]; // 0x006FC2C4
extern const char gLockFailure[]; // 0x006FC330
extern const char gUnlockFailure[]; // 0x006FC310
void __fastcall sub_006B39B0_ShowD3DError(const char*,long); // 0x006B39B0
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0

struct D2GridPointStrc { unsigned char nScale,nRed,nGreen,nBlue; int nX,nY; };

struct D2RendererSettingsStrc { int unknown00,unknown04; int bFlat; };

extern D2RendererSettingsStrc* gpRendererSettings_007C9148; // 0x007C9148
extern D2VertexBufferStrc* gpGridBuffer_00971734; // 0x00971734
extern unsigned short gaFlatIndices_0074C3D0[4]; // 0x0074C3D0
extern unsigned short gaGridIndices_009716B0[65]; // 0x009716B0
extern unsigned char gaPaletteRows_00971740[256][256]; // 0x00971740
int __fastcall sub_006BB870_BindTileTexture(D2TileLibraryEntryStrc* pTile); // 0x006BB870
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere,int hResult); // 0x006B20E0
extern int gnOriginX_00981740; // 0x00981740
extern int gnOriginY_00981744; // 0x00981744
extern int gnScale_00989748; // 0x00989748

static __forceinline unsigned int PackGridColor(const D2GridPointStrc& point,unsigned char nAlpha);

// 0x006B7530
static int __stdcall sub_006B7530_DrawGlyph(int nX, int nY, char nChar)
{
    if (nX > 640)
    {
        return 0;
    }

    if (nX < 0)
    {
        return gaGlyphWidths_00970FC8[nChar];
    }

    if ((unsigned char)(nChar - 0x20) <= 0x5F)
    {
        const int nRight = nX + 8;
        const int nBottom = nY + 16;
        gaVertices_00970F48[0].nX = (float)nX;
        gaVertices_00970F48[0].nY = (float)nY;
        gaVertices_00970F48[1].nX = (float)nX;
        gaVertices_00970F48[1].nY = (float)nBottom;
        gaVertices_00970F48[2].nX = (float)nRight;
        gaVertices_00970F48[2].nY = (float)nBottom;
        gaVertices_00970F48[3].nX = (float)nRight;
        gaVertices_00970F48[3].nY = (float)nY;

        nChar -= 0x20;
        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, gapGlyphTextures_009712D0[nChar]);
        gpD3DDevice_00970E78->lpVtbl->DrawPrimitive(gpD3DDevice_00970E78, 6, 0x1C4, gaVertices_00970F48, 4, 0x1C);
        return gaGlyphWidths_00970FC8[nChar];
    }

    return gaGlyphWidths_00970FC8[0];
}

int __fastcall sub_Emit_006B7530(const char* szText, int nX, int nY)
{
    int nWidth = 0;
    while (*szText)
    {
        nWidth += sub_006B7530_DrawGlyph(nX + nWidth, nY, *szText++);
    }
    return nWidth;
}

// 0x006B7FD0
static void __stdcall sub_006B7FD0_GetPanelRect(D2RectStrc* pRect, int nSide, int* pOffset, int bFlag)
{
    D2_ASSERT(pRect, 0x53);

    pRect->nLeft = 0;
    pRect->nRight = gnScreenWidth_007C9138;
    pRect->nTop = 0;
    pRect->nBottom = gnScreenHeight_007C913C - 47;

    if (!bFlag)
    {
        pRect->nLeft = -32;
        pRect->nBottom += 32;
        switch (nSide)
        {
        case 1:
            pRect->nRight += -(gnScreenWidth_007C9138 / 2);
            break;
        case 2:
            pRect->nLeft = gnScreenWidth_007C9138 / 2 - 32;
            break;
        }
        return;
    }

    D2_ASSERT(pOffset, 0x69);

    const int nShift = gnScreenWidth_007C9138 / 4;
    switch (nSide)
    {
    case 1:
        *pOffset = -nShift;
        pRect->nRight -= nShift;
        pRect->nLeft += nShift;
        break;
    case 2:
        *pOffset = nShift;
        pRect->nRight -= nShift;
        pRect->nLeft += nShift;
        break;
    }
}

void __fastcall sub_Emit_006B7FD0(D2RectStrc* pRect, int nSide)
{
    int nOffset;
    sub_006B7FD0_GetPanelRect(pRect, nSide, &nOffset, 1);
    sub_006B7FD0_GetPanelRect(pRect, nSide, 0, 0);
}

// 0x006B8220
int __fastcall sub_006B8220_DrawTileParts(D2TileContextStrc* pTile, int nX, int nY, int nLight, int nColorMode, int nViewMode)
{
    D2ClipRectStrc tRect;
    tRect.left = 0;
    tRect.top = 0;
    tRect.right = gnScreenWidth_007C9138;
    tRect.bottom = gnScreenHeight_007C913C - 47;
    tRect.left -= 32;
    tRect.bottom += 32;

    int bDrawn = 0;
    switch (nViewMode)
    {
    case 1:
        tRect.right -= gnScreenWidth_007C9138 / 2;
        break;
    case 2:
        tRect.left += gnScreenWidth_007C9138 / 2;
        break;
    }

    nY += 32;
    for (int i = 0; i < pTile->count; ++i)
    {
        int nLeft = pTile->parts[i].x + nX;
        int nBottom = pTile->parts[i].y + nY;
        if (nLeft >= tRect.left && nLeft < tRect.right && nBottom >= tRect.top && nBottom < tRect.bottom)
        {
            int nTop = nBottom - 32;
            bDrawn = 1;
            int nRight = nLeft + 32;
            sub_006BBA00_BindTilePart(&pTile->parts[i]);
            gaQuadVertices[0].x = (float)nLeft;
            gaQuadVertices[0].y = (float)nTop;
            gaQuadVertices[1].x = (float)nLeft;
            gaQuadVertices[1].y = (float)nBottom;
            gaQuadVertices[2].x = (float)nRight;
            gaQuadVertices[2].y = (float)nBottom;
            gaQuadVertices[3].x = (float)nRight;
            gaQuadVertices[3].y = (float)nTop;
            sub_006B9730_SetQuadColor(gaQuadVertices, (unsigned char)nLight, nColorMode);
            gaQuadVertices[1].color = gaQuadVertices[0].color;
            gaQuadVertices[2].color = gaQuadVertices[0].color;
            gaQuadVertices[3].color = gaQuadVertices[0].color;
            gpDrawDevice->vtable->DrawPrimitive(gpDrawDevice, 6, 0x1C4, gaQuadVertices, 4, 0x1C);
        }
    }

    return bDrawn;
}

static __forceinline int IsVisible(const D2RectStrc& rect, const D2TLVertexStrc& v)
{
    return v.fX >= rect.nLeft && v.fX < rect.nRight && v.fY >= rect.nTop && v.fY < rect.nBottom;
}

// 0x006B83A0
int __fastcall sub_006B83A0_DrawPerspective(D2PerspectiveSpriteStrc* pSprite,int nX,int nY,int nColor,unsigned char nAlpha,int nSide)
{
    int nResult=0;
    int nOffset=0;

    int nOne=1;
    D2RectStrc rect;
    sub_006B7FD0_GetPanelRect(&rect,nSide,&nOffset,1);
    nX <<= 13;
    nY <<= 13;
    for(int i=0;i<pSprite->nTiles;++i)
    {
        const int nTileX=pSprite->pTiles[i].nX >> 5;
        const int nTileY=(pSprite->pTiles[i].nY+96) >> 5;
        const int nOffsetX=((nTileX+2*nTileY)<<16)-0x38000;
        const int nOffsetY=(((nTileY<<nOne)-nTileX)<<16)+0x18000;
        int nDrawY=nOffsetY+nY;
        int nDrawX=nOffsetX+nX;
        int nOutX;
        sub_006B9860_Project(nDrawX,nDrawY,0,&nOutX,&nSide);
        gaPerspectiveVertices[0].fX=(float)nOutX;
        gaPerspectiveVertices[0].fY=(float)nSide;
        sub_006B9860_Project(nX+nOffsetX+0x20000,nY+nOffsetY+0x20000,0,&nOutX,&nSide);
        gaPerspectiveVertices[12].fX=(float)nOutX;
        gaPerspectiveVertices[12].fY=(float)nSide;
        sub_006B9860_Project(nX+nOffsetX+0x30000,nY+nOffsetY+0x10000,0,&nOutX,&nSide);
        gaPerspectiveVertices[14].fX=(float)nOutX;
        gaPerspectiveVertices[14].fY=(float)nSide;
        sub_006B9860_Project(nX+nOffsetX+0x10000,nY+nOffsetY-0x10000,0,&nOutX,&nSide);
        gaPerspectiveVertices[2].fX=(float)nOutX;
        gaPerspectiveVertices[2].fY=(float)nSide;
        if(IsVisible(rect,gaPerspectiveVertices[0]))
        {
Draw:
            sub_006BBA00_SelectTile(&pSprite->pTiles[i]);
            const float fOffset=(float)nOffset;
            D2TLVertexStrc* pVertex=gaPerspectiveVertices;
            int nStartY=nDrawY;
            int nStartX=nDrawX;
            do
            {
                int nRowX=nStartX;

                int nRowY=*(volatile int*)&nStartY;
                for(int j=0;j<3;++j)
                {
                    sub_006B9860_Project(nRowX,nRowY,0,&nOutX,&nSide);
                    pVertex->fY=(float)nSide;
                    pVertex->fX=(float)nOutX+fOffset;
                    sub_006B9730_SetColor(pVertex,nColor,nAlpha);
                    ++pVertex;
                    nRowX+=0x8000;
                    nRowY-=0x8000;
                }
                nStartX+=0x8000;
                nStartY+=0x8000;
            } while ((int)pVertex < (int)(gaPerspectiveVertices + 15));
            gpDevice_00970E78->lpVtbl->DrawIndexedPrimitive(gpDevice_00970E78,5,0x1c4,gaPerspectiveVertices,15,gaPerspectiveIndices,22,0x1c);
            nResult=1;
        }
        else if(IsVisible(rect,gaPerspectiveVertices[12])) goto Draw;
        else if(IsVisible(rect,gaPerspectiveVertices[14])) goto Draw;
        else if(IsVisible(rect,gaPerspectiveVertices[2])) goto Draw;
    }
    return nResult;
}

#include "gen/data/Source/D2Direct3D/Unknown_006B7530.inc"

// build: context sub_006B8DF0_DrawConfigured
// calling-convention shim (not game code)
static int __stdcall sub_006B8DF0_DrawConfigured(void* pSurface, int nA, int nB, int nC, void* pImage, unsigned char nAlpha)
{
    if (!sub_005FDEA0_CheckSurface(pSurface, 1, 0)) return 0;
    sub_006B1EA0_SetMode(1);
    sub_006B1F40_SetBlendMode(nAlpha == 255 ? 1 : 4);
    sub_006B2030_SetFilterMode(1);
    if (sub_006B9830_GetPerspective())
        return sub_006B8950_DrawAlternate(pImage, pSurface, nA, nB, nC, nAlpha);
    return sub_006B87A0_DrawNormal(pImage, pSurface, nA, nB, nC, nAlpha);
}

// 0x006B8E60
int __fastcall sub_006B8E60_DrawRelay(void* pSurface, int nA, int nB, int nC, void* pImage, unsigned char nAlpha)
{
    return sub_006B8DF0_DrawConfigured(pSurface, nA, nB, nC, pImage, nAlpha);
}

// 0x006B8F10
void __cdecl sub_006B8F10()
{
    float xStep = (float)(160.0 / gTileWidth);
    xStep = (float)(xStep / 10.0);
    float yStep = (float)(80.0 / gTileHeight);
    yStep = (float)(yStep / 10.0);

    BufferDescription description = { sizeof(BufferDescription) };
    description.caps = 0x10800;
    description.format = 0x1C4;
    description.count = 36;
    long result = gGraphics->CreateVertexBuffer(&description, &gGridBuffer, 4, 0);
    if (result)
    {
        sub_006B39B0_ShowD3DError(gCreateFailure, result);
        return;
    }

    Vertex* data;
    result = gGridBuffer->Lock(0x21, &data, 0);
    if (result)
    {
        sub_006B20E0_DDrawLogError(gLockFailure, result);
        return;
    }

    for (int row = 0; row < 6; ++row)
    {
        for (int column = 0; column < 6; ++column)
        {
            int xBorder = 0;
            int yBorder = 0;
            if (column == 0)
            {
                xBorder = 1;
                yBorder = 1;
            }
            else if (column == 5)
            {
                xBorder = -1;
                yBorder = -1;
            }

            if (row == 0)
            {
                --xBorder;
                ++yBorder;
            }
            else if (row == 5)
            {
                ++xBorder;
                --yBorder;
            }

            float u = (float)(xBorder + 80) / gTileWidth;
            u += (column - row) * xStep;
            float v = (float)yBorder / gTileHeight;
            v += (column + row) * yStep;
            data->z = 0.5f;
            data->rhw = 1.0f;
            data->u = u;
            data->v = v;
            ++data;
        }
    }

    result = gGridBuffer->Unlock();
    if (result)
    {
        sub_006B20E0_DDrawLogError(gUnlockFailure, result);
        return;
    }

    unsigned short indices[5][12];
    for (int row = 0; row < 5; ++row)
    {
        for (int column = 0; column < 6; ++column)
        {
            unsigned short* pTop = &indices[row][column * 2];
            unsigned short* pBottom = &indices[row][column * 2 + 1];
            *pTop = row * 6 + (unsigned short)column;
            *pBottom = row * 6 + (unsigned short)column + 6;
        }
    }

    IndexStrip* pStrip = gIndexStrips;
    for (int row = 0; row < 5; ++row)
    {
        const unsigned short* pSource = indices[row];
        for (int i = 0; i < 6; ++i)
        {
            ((int*)pStrip->indices)[i] = ((int*)pSource)[i];
        }
        pStrip->last = pStrip->indices[11];
        ++pStrip;
    }
}

static __forceinline unsigned int PackGridColor(const D2GridPointStrc& point,unsigned char nAlpha)
{
    const unsigned char* pRow=gaPaletteRows_00971740[point.nScale];
    return (((((unsigned int)nAlpha<<8)|pRow[point.nRed])<<8)|pRow[point.nGreen])<<8|pRow[point.nBlue];
}

// 0x006B9170
void __fastcall sub_006B9170_DrawGrid(D2TileLibraryEntryStrc* pTexture,D2GridPointStrc* pPoints,int nArg1,int nArg2,int nArg3,int nArg4,unsigned char nAlphaInput,int nArg6,int nFilter)
{
    if(!sub_006BB870_BindTileTexture(pTexture)) return;
    {
    sub_006B1EA0_SetState(1);
    int nBlend=1;
    const unsigned char nAlpha = nAlphaInput;
    if(nAlpha!=255) nBlend=4;
    sub_006B1F40_SetBlendMode(nBlend);
    if(nFilter) sub_006B2030_SetFilterMode(2);
    else sub_006B2030_SetFilterMode(1);
    {
    D2TLVertexStrc* pVertices;
    if(gpRendererSettings_007C9148->bFlat)
    {
        long nResult=gpGridBuffer_00971734->lpVtbl->Lock(gpGridBuffer_00971734,0x21,(void**)&pVertices,0);
        if(nResult) { sub_006B20E0_DDrawLogError(gLockFailure,nResult);return; }
        WRITE_CORNER(0)
        WRITE_CORNER(5)
        WRITE_CORNER(35)
        WRITE_CORNER(30)
        nResult=gpGridBuffer_00971734->lpVtbl->Unlock(gpGridBuffer_00971734);
        if(nResult) { sub_006B20E0_DDrawLogError(gUnlockFailure,nResult);return; }
        gpDevice_00970E78->lpVtbl->DrawIndexedPrimitiveVB(gpDevice_00970E78,6,gpGridBuffer_00971734,gaFlatIndices_0074C3D0,4,0x1c);
    }
    else
    {
        long nResult=gpGridBuffer_00971734->lpVtbl->Lock(gpGridBuffer_00971734,0x21,(void**)&pVertices,0);
        if(nResult) { sub_006B20E0_DDrawLogError(gLockFailure,nResult);return; }
        const D2GridPointStrc* pPoint=pPoints;
        for(int nPoint=0;nPoint<36;++nPoint)
        {
            pVertices->dwColor=PackGridColor(*pPoint,nAlpha);
            pVertices->fX=(float)pPoint->nX;
            pVertices->fY=(float)pPoint->nY;
            ++pVertices;
            ++pPoint;
        }
        nResult=gpGridBuffer_00971734->lpVtbl->Unlock(gpGridBuffer_00971734);
        if(nResult) { sub_006B20E0_DDrawLogError(gUnlockFailure,nResult);return; }
        gpDevice_00970E78->lpVtbl->DrawIndexedPrimitiveVB(gpDevice_00970E78,5,gpGridBuffer_00971734,gaGridIndices_009716B0,65,0x1c);
    }
    }
    }
}

int gnTrigTable_00981748[0x2000]; // 0x00981748

// 0x006B9910
void __fastcall sub_006B9910_ProjectPoint(int nX, int nY, int nUnused, int* pScreenX, int* pScreenY, int bAlternate)
{
    int nA = ((nX - gnOriginX_00981740) * 24) >> 16;
    int nB = ((nY - gnOriginY_00981744) * 24) >> 16;
    int nSum = (nB + nA) * 724;
    int nDepth = (nSum * -512) >> 10;
    int nAngle = (nSum * 886) >> 20;
    int nCos = gnTrigTable_00981748[(nAngle - 0x1000) & 0x1FFF];

    int nHeight = (nDepth * nCos) >> 20;
    *pScreenX = (((nB - nA) * nCos * 724) >> 20) + gnScreenWidth_007C9138 / 2;

    *pScreenY = gnScreenHeight_007C913C / 2 + nHeight - 16;

    int nValue = nHeight - (((nDepth + 0x37400) * gnTrigTable_00981748[(nAngle - 0xF80) & 0x1FFF]) >> 20);

    if (bAlternate)
    {
        gnScale_00989748 = (nValue * 0x4CC) >> 10;
    }
    else
    {
        gnScale_00989748 = (nValue * 0x466) >> 10;
    }
}
