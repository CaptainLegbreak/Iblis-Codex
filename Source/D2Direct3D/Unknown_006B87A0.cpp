struct D2TileBlockStrc
{
    short nX;
    short nY;
    unsigned char unk_04[16];
};

struct D2RectStrc { int nLeft; int nTop; int nRight; int nBottom; };

struct D2TileStrc
{
    unsigned char unk_00[0x50];
    int nBlocks;
    D2TileBlockStrc* pBlocks;
};

struct D2TileVertexStrc
{
    float x, y, z, rhw;
    unsigned int nColor;
    unsigned int nSpecular;
    float u, v;
};

struct D2GraphicsDeviceStrc;
struct D2GraphicsVTableStrc
{
    void* unk_00[28];
    int (__stdcall *DrawPrimitive)(D2GraphicsDeviceStrc*, int, unsigned int, void*, unsigned int, unsigned int);
};
struct D2GraphicsDeviceStrc { D2GraphicsVTableStrc* pVTable; };

extern int gnScreenWidth_007C9138; // 0x007C9138
extern int gnScreenHeight_007C913C; // 0x007C913C
extern D2GraphicsDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2TileVertexStrc gVertex0_00971630; // 0x00971630
extern D2TileVertexStrc gVertex1_00971650; // 0x00971650
extern D2TileVertexStrc gVertex2_00971670; // 0x00971670
extern D2TileVertexStrc gVertex3_00971690; // 0x00971690
void __fastcall sub_006BBA00_BindTileTexture(D2TileBlockStrc* pTile); // 0x006BBA00
void __fastcall sub_006B9780_SetColor(D2TileVertexStrc* pVertex, unsigned int nPacked, unsigned char nAlpha); // 0x006B9780

int __stdcall sub_005FDEA0_CheckTile(D2TileStrc*,int,int); // 0x005FDEA0
void __fastcall sub_006B1EA0_SetState(int); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlendMode(int); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int); // 0x006B2030
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
int __stdcall sub_006B8950_Lit(int,D2TileStrc*,int,int,const unsigned int*,unsigned char); // 0x006B8950
__declspec(noinline) static int __stdcall sub_006B87A0_DrawNoPerspective(D2TileStrc*,int,int,const unsigned int*,int,unsigned char);
// 0x006B87A0
static int __stdcall sub_006B87A0_DrawNoPerspective(D2TileStrc* pTile, int nX, int nY, const unsigned int* pLight, int nPanels, unsigned char nAlpha)
{
    int nDrawn = 0;
    int n = gnScreenWidth_007C9138;
    D2RectStrc tRect;
    tRect.nLeft = 0;
    tRect.nTop = 0;
    tRect.nRight = n;
    tRect.nBottom = gnScreenHeight_007C913C - 47;
    tRect.nLeft -= 32;
    tRect.nBottom += 32;

    switch (nPanels)
    {
    case 1:
        tRect.nRight -= gnScreenWidth_007C9138 / 2;
        break;
    case 2:
        tRect.nLeft += gnScreenWidth_007C9138 / 2;
        break;
    }

    nY += 32;
    for (n = 0; n < pTile->nBlocks; ++n)
    {
        int nBlockX = pTile->pBlocks[n].nX;
        int x = nX + nBlockX;
        int y = nY + pTile->pBlocks[n].nY;
        if (x >= tRect.nLeft && x < tRect.nRight && y >= tRect.nTop && y < tRect.nBottom)
        {
            const int nCol = nBlockX >> 5;
            unsigned int nLeftLight = pLight[nCol];
            unsigned int nRightLight = pLight[nCol + 1];
            int nTop = y - 32;
            int nRight = x + 32;
            nDrawn = 1;
            sub_006BBA00_BindTileTexture(&pTile->pBlocks[n]);
            gVertex0_00971630.x = (float)x;
            gVertex0_00971630.y = (float)nTop;
            gVertex1_00971650.x = (float)x;
            gVertex1_00971650.y = (float)y;
            gVertex2_00971670.x = (float)nRight;
            gVertex2_00971670.y = (float)y;
            gVertex3_00971690.x = (float)nRight;
            gVertex3_00971690.y = (float)nTop;
            sub_006B9780_SetColor(&gVertex0_00971630, nLeftLight, nAlpha);
            sub_006B9780_SetColor(&gVertex1_00971650, nLeftLight, nAlpha);
            sub_006B9780_SetColor(&gVertex2_00971670, nRightLight, nAlpha);
            sub_006B9780_SetColor(&gVertex3_00971690, nRightLight, nAlpha);
            gpDevice_00970E78->pVTable->DrawPrimitive(gpDevice_00970E78, 6, 0x1C4, &gVertex0_00971630, 4, 28);
        }
    }
    return nDrawn;
}

__declspec(noinline) static int __stdcall sub_006B8DF0_AlphaWall(D2TileStrc*,int,int,const unsigned int*,int,unsigned char);
static int __stdcall sub_006B8DF0_AlphaWall(D2TileStrc*,int,int,const unsigned int*,int,unsigned char); // 0x006B8DF0

// build: context sub_006B8DF0_AlphaWall
static int __stdcall sub_006B8DF0_AlphaWall(D2TileStrc* t,int x,int y,const unsigned int* l,int panels,unsigned char alpha)
{
 if(!sub_005FDEA0_CheckTile(t,1,0))return 0;
 sub_006B1EA0_SetState(1);sub_006B1F40_SetBlendMode(alpha==255?1:4);sub_006B2030_SetFilterMode(1);
 if(sub_006B9830_GetPerspective())return sub_006B8950_Lit(panels,t,x,y,l,alpha);
 return sub_006B87A0_DrawNoPerspective(t,x,y,l,panels,alpha);
}

// build: context sub_006B8E60_DrawAlphaWall
int __fastcall sub_006B8E60_DrawAlphaWall(D2TileStrc* t,int x,int y,const unsigned int* l,int panels,unsigned char alpha)
{ return sub_006B8DF0_AlphaWall(t,x,y,l,panels,alpha); }

// build: context sub_006B8E90_DrawWall
int __fastcall sub_006B8E90_DrawWall(D2TileStrc* t,int x,int y,const unsigned int* l,int panels)
{
 if(!sub_005FDEA0_CheckTile(t,1,0))return 0;
 sub_006B1EA0_SetState(1);sub_006B1F40_SetBlendMode(1);sub_006B2030_SetFilterMode(1);
 if(sub_006B9830_GetPerspective())return sub_006B8950_Lit(panels,t,x,y,l,255);
 return sub_006B87A0_DrawNoPerspective(t,x,y,l,panels,255);
}
