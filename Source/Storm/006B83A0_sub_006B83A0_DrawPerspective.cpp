// build: context IsVisible

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RectStrc { int nLeft; int nTop; int nRight; int nBottom; };

extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C

__declspec(noinline) static void __stdcall sub_006B7FD0_GetPanelRect(D2RectStrc* pRect, int nSide, int* pOffset, int bFlag); // 0x006B7FD0

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

struct D2TLVertexStrc { float fX, fY, fZ, fRhw; unsigned int dwColor, dwSpecular; float fU, fV; };
struct D2PerspectiveTileStrc { short nX,nY; char unknown04[0x10]; };
struct D2PerspectiveSpriteStrc { char unknown00[0x50]; int nTiles; D2PerspectiveTileStrc* pTiles; };
struct D2D3DDeviceStrc;
struct D2D3DDeviceVtbl
{
    void* unknown00[29];
    long (__stdcall* DrawIndexedPrimitive)(D2D3DDeviceStrc*,int,unsigned int,D2TLVertexStrc*,unsigned int,unsigned short*,unsigned int,unsigned int);
};
struct D2D3DDeviceStrc { D2D3DDeviceVtbl* lpVtbl; };
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2TLVertexStrc gaPerspectiveVertices[15]; // 0x00971450
extern unsigned short gaPerspectiveIndices[22]; // 0x0074C0D0
void __fastcall sub_006B9860_Project(int nX,int nY,int nZ,int* pOutX,int* pOutY); // 0x006B9860
void __fastcall sub_006B9730_SetColor(D2TLVertexStrc* pVertex,unsigned char nIndex,unsigned char nAlpha); // 0x006B9730
void __fastcall sub_006BBA00_SelectTile(D2PerspectiveTileStrc* pTile); // 0x006BBA00

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

#include "gen/data/Source/Storm/006B83A0_sub_006B83A0_DrawPerspective.inc"
