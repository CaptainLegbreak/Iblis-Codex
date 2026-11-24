typedef unsigned int U32;
typedef unsigned char U8;
struct D2TileBlockStrc { short x,y; unsigned char unk_04[16]; };
struct D2TileStrc { U32 type; unsigned char unk_04[0x4c]; int count; D2TileBlockStrc* blocks; };
struct D2RectStrc { int left,top,right,bottom; };
struct D2Point3Strc { int x,y,z; };
struct D2WallEdgeStrc { D2Point3Strc a,b; };
struct D2TLVertexStrc { float x,y,z,rhw; U32 color,specular; float u,v; };
struct D2D3DDeviceStrc;
struct D2D3DDeviceVtbl {
 void* unk_00[28];
 long (__stdcall* DrawPrimitive)(D2D3DDeviceStrc*,int,U32,void*,U32,U32);
 long (__stdcall* DrawIndexedPrimitive)(D2D3DDeviceStrc*,int,U32,void*,U32,unsigned short*,U32,U32);
};
struct D2D3DDeviceStrc { D2D3DDeviceVtbl* vtbl; };
extern int gnWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern int gaGeometry[10][6][3]; // 0x0074C100
extern D2TLVertexStrc gaGrid[15]; // 0x00971450
extern D2TLVertexStrc gatQuad[4]; // 0x00971630
extern unsigned short gaIndices[22]; // 0x0074C0D0
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern const char gszAssert_006CC837[]; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
__declspec(noreturn) void __cdecl sub_00681E09_Exit(int);
void __cdecl sub_00681E09_Exit(int); // 0x00681E09
void __fastcall sub_006B9860_Project(int,int,int,int*,int*); // 0x006B9860
void __fastcall sub_006B9780_SetColor(D2TLVertexStrc*,U32,U8); // 0x006B9780
void __fastcall D3D_BindTileTexture(D2TileBlockStrc*); // 0x006BBA00
int __stdcall D2CMPTileValidate(D2TileStrc*,int,int); // 0x005FDEA0
void __fastcall D3D_SetColorCombineMode(int); // 0x006B1EA0
void __fastcall D3D_SetAlphaBlendMode(int); // 0x006B1F40
void __fastcall D3D_SetTextureFilterMode(int); // 0x006B2030
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
#define D3D_VERTEX_IN_RECT(v, r) ((v).x >= (r).left && (v).x < (r).right && (v).y >= (r).top && (v).y < (r).bottom)
#define D2ASSERT(c,l) if(!(c)) { sub_00408A60(gszAssert_006CC837,sub_00408090(),l); sub_00681E09_Exit(-1); }
static void __stdcall sub_006B7FD0_Viewport(int,volatile D2RectStrc*,int*,int);
static void __stdcall sub_006B7FD0_Viewport(int,volatile D2RectStrc*,int*,int); // 0x006B7FD0
// 0x006B7FD0
static void __stdcall sub_006B7FD0_Viewport(int nSide, D2RectStrc* pRect, int* pOffset, int bFlag)
{
    D2ASSERT(pRect, 0x53);

    pRect->left = 0;
    pRect->right = gnWidth_007C9138;
    pRect->top = 0;
    pRect->bottom = gnHeight_007C913C - 47;

    if (!bFlag)
    {
        pRect->bottom += 32;
        pRect->left = -32;
        switch (nSide)
        {
        case 1:
            pRect->right += -(gnWidth_007C9138 / 2);
            break;
        case 2:
            pRect->left = gnWidth_007C9138 / 2 - 32;
            break;
        }
        return;
    }

    D2ASSERT(pOffset, 0x69);

    const int nShift = gnWidth_007C9138 / 4;
    switch (nSide)
    {
    case 1:
        *pOffset = -nShift;
        pRect->right -= nShift;
        pRect->left += nShift;
        break;
    case 2:
        *pOffset = nShift;
        pRect->right -= nShift;
        pRect->left += nShift;
        break;
    }
}
int __stdcall sub_006B87A0_Flat(D2TileStrc*,int,int,U32*,int,U8); // 0x006B87A0

static int __stdcall sub_006B8950_Lit(int,D2TileStrc*,int,int,U32*,U8);
static int __stdcall sub_006B8950_Lit(int,D2TileStrc*,int,int,U32*,U8); // 0x006B8950
// 0x006B8950
static int __stdcall sub_006B8950_Lit(int nScreenPanels, D2TileStrc* pTile, int nPosX, int nPosY, U32* pLight, U8 nAlpha)
{
    int nResult = 0;
    int nOffset = 0;
    D2RectStrc tRect;
    sub_006B7FD0_Viewport(nScreenPanels, &tRect, &nOffset, 1);

    nPosY <<= 13;
    nPosX <<= 13;
    const int nType = pTile->type;
    D2ASSERT(nType >= 0 && nType <= 9, 0x213);

    for (int i = 0; i < pTile->count; ++i)
    {
        const int nCol = pTile->blocks[i].x >> 5;
        const int nHeight = pTile->blocks[i].y;
        D2ASSERT(nCol >= 0 && nCol <= 4, 0x21B);

        const int nX0 = gaGeometry[nType][nCol][0] + nPosX;
        const int nY0 = gaGeometry[nType][nCol][1] + nPosY;
        const int nZ0 = gaGeometry[nType][nCol][2] - nHeight;
        const int nX1 = gaGeometry[nType][nCol + 1][0] + nPosX;
        const int nY1 = gaGeometry[nType][nCol + 1][1] + nPosY;
        const int nZ1 = gaGeometry[nType][nCol + 1][2] - nHeight;
        int nScreenX;
        int nScreenY;

        sub_006B9860_Project(nX0, nY0, nZ0, &nScreenX, &nScreenY);
        gaGrid[0].x = (float)nScreenX;
        gaGrid[0].y = (float)nScreenY;
        sub_006B9860_Project(nX0, nY0, nZ0 - 0x20, &nScreenX, &nScreenY);
        gaGrid[12].x = (float)nScreenX;
        gaGrid[12].y = (float)nScreenY;
        sub_006B9860_Project(nX1, nY1, nZ1 - 0x20, &nScreenX, &nScreenY);
        gaGrid[14].x = (float)nScreenX;
        gaGrid[14].y = (float)nScreenY;
        sub_006B9860_Project(nX1, nY1, nZ1, &nScreenX, &nScreenY);
        gaGrid[2].x = (float)nScreenX;
        gaGrid[2].y = (float)nScreenY;

        if (D3D_VERTEX_IN_RECT(gaGrid[0], tRect)
            || D3D_VERTEX_IN_RECT(gaGrid[12], tRect)
            || D3D_VERTEX_IN_RECT(gaGrid[14], tRect)
            || D3D_VERTEX_IN_RECT(gaGrid[2], tRect))
        {
            const int nMidX = (nX0 + nX1) >> 1;
            const int nMidY = (nY0 + nY1) >> 1;
            const int nMidZ = (nZ0 + nZ1) >> 1;
            U32 aColors[3];
            aColors[0] = pLight[nCol];
            aColors[2] = pLight[nCol + 1];
            const int nMixA = (unsigned char)(((unsigned char)(aColors[2] >> 24) + (unsigned char)(aColors[0] >> 24)) >> 1);
            const int nMixR = (unsigned char)(((unsigned char)(aColors[2] >> 16) + (unsigned char)(aColors[0] >> 16)) >> 1);
            const int nMixG = (unsigned char)(((unsigned char)(aColors[2] >> 8) + (unsigned char)(aColors[0] >> 8)) >> 1);
            const int nMixB = (unsigned char)(((unsigned char)aColors[2] + (unsigned char)aColors[0]) >> 1);
            aColors[1] = (((((nMixA << 8) + nMixR) << 8) + nMixG) << 8) + nMixB;
            D3D_BindTileTexture(&pTile->blocks[i]);

            for (int nGridRow = 0; nGridRow < 5; ++nGridRow)
            {
                const int nDepth = nGridRow << 3;
                if (nGridRow != 0 && nGridRow != 4)
                {
                    sub_006B9860_Project(nX0, nY0, nZ0 - nDepth, &nScreenX, &nScreenY);
                    gaGrid[nGridRow * 3].x = (float)nScreenX;
                    gaGrid[nGridRow * 3].y = (float)nScreenY;
                    sub_006B9860_Project(nX1, nY1, nZ1 - nDepth, &nScreenX, &nScreenY);
                    gaGrid[nGridRow * 3 + 2].x = (float)nScreenX;
                    gaGrid[nGridRow * 3 + 2].y = (float)nScreenY;
                }

                sub_006B9860_Project(nMidX, nMidY, nMidZ - nDepth, &nScreenX, &nScreenY);
                gaGrid[nGridRow * 3 + 1].x = (float)nScreenX;
                gaGrid[nGridRow * 3 + 1].y = (float)nScreenY;
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    D2TLVertexStrc* pVertex = &gaGrid[nGridRow * 3 + nGridCol];
                    pVertex->x = pVertex->x + (float)nOffset;
                    sub_006B9780_SetColor(pVertex, aColors[nGridCol], nAlpha);
                }
            }

            gpDevice_00970E78->vtbl->DrawIndexedPrimitive(gpDevice_00970E78, 5, 0x1c4, gaGrid, 15, gaIndices, 22, 0x1c);
            nResult = 1;
        }
    }

    return nResult;
}
static int __stdcall sub_006B8DF0_AlphaWall(D2TileStrc*,int,int,U32*,int,U8);
static int __stdcall sub_006B8DF0_AlphaWall(D2TileStrc*,int,int,U32*,int,U8); // 0x006B8DF0

// build: context sub_006B8DF0_AlphaWall
static int __stdcall sub_006B8DF0_AlphaWall(D2TileStrc* t,int x,int y,U32* l,int panels,U8 alpha)
{
 if(!D2CMPTileValidate(t,1,0))return 0;
 D3D_SetColorCombineMode(1);D3D_SetAlphaBlendMode(alpha==255?1:4);D3D_SetTextureFilterMode(1);
 if(sub_006B9830_GetPerspective())return sub_006B8950_Lit(panels,t,x,y,l,alpha);
 return sub_006B87A0_Flat(t,x,y,l,panels,alpha);
}

// build: context sub_006B8E60_DrawAlphaWall
int __fastcall sub_006B8E60_DrawAlphaWall(D2TileStrc* t,int x,int y,U32* l,int panels,U8 alpha)
{ return sub_006B8DF0_AlphaWall(t,x,y,l,panels,alpha); }

int __fastcall sub_006B8E90_DrawWall(D2TileStrc* t,int x,int y,U32* l,int panels); // 0x006B8E90

#include "gen/data/Source/D2Direct3D/Unknown_006B8950.inc"
