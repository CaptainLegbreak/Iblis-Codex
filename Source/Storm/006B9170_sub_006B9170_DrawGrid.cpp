// build: context PackGridColor

struct D2TLVertexStrc { float fX,fY,fZ,fRhw; unsigned int dwColor,dwSpecular; float fU,fV; };
struct D2GridPointStrc { unsigned char nScale,nRed,nGreen,nBlue; int nX,nY; };
struct D2VertexBufferStrc;
struct D2VertexBufferVtbl
{
    void* previous[3];
    long (__stdcall* Lock)(D2VertexBufferStrc*,unsigned int,D2TLVertexStrc**,unsigned int*);
    long (__stdcall* Unlock)(D2VertexBufferStrc*);
};
struct D2VertexBufferStrc { D2VertexBufferVtbl* lpVtbl; };
struct D2D3DDeviceStrc;
struct D2D3DDeviceVtbl
{
    void* previous[35];
    long (__stdcall* DrawIndexedPrimitiveVB)(D2D3DDeviceStrc*,int,D2VertexBufferStrc*,unsigned short*,unsigned int,unsigned int);
};
struct D2D3DDeviceStrc { D2D3DDeviceVtbl* lpVtbl; };
struct D2RendererSettingsStrc { int unknown00,unknown04; int bFlat; };
extern D2RendererSettingsStrc* gpRendererSettings_007C9148; // 0x007C9148
extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78
extern D2VertexBufferStrc* gpGridBuffer_00971734; // 0x00971734
extern unsigned short gaFlatIndices_0074C3D0[4]; // 0x0074C3D0
extern unsigned short gaGridIndices_009716B0[65]; // 0x009716B0
extern unsigned char gaPaletteRows_00971740[256][256]; // 0x00971740
extern const char gszLockFailure_006FC330[]; // 0x006FC330
extern const char gszUnlockFailure_006FC310[]; // 0x006FC310
struct D2TileLibraryEntryStrc;
int __fastcall sub_006BB870_BindTileTexture(D2TileLibraryEntryStrc* pTile); // 0x006BB870
void __fastcall sub_006B1EA0_SetState(int nState); // 0x006B1EA0
void __fastcall sub_006B1F40_SetBlendMode(int nState); // 0x006B1F40
void __fastcall sub_006B2030_SetFilterMode(int nMode); // 0x006B2030
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere,int hResult); // 0x006B20E0
static __forceinline unsigned int PackGridColor(const D2GridPointStrc& point,unsigned char nAlpha)
{
    const unsigned char* pRow=gaPaletteRows_00971740[point.nScale];
    return (((((unsigned int)nAlpha<<8)|pRow[point.nRed])<<8)|pRow[point.nGreen])<<8|pRow[point.nBlue];
}
#define WRITE_CORNER(i) pVertices[i].dwColor=PackGridColor(pPoints[i],nAlpha); pVertices[i].fX=(float)pPoints[i].nX; pVertices[i].fY=(float)pPoints[i].nY;

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
        long nResult=gpGridBuffer_00971734->lpVtbl->Lock(gpGridBuffer_00971734,0x21,&pVertices,0);
        if(nResult) { sub_006B20E0_DDrawLogError(gszLockFailure_006FC330,nResult);return; }
        WRITE_CORNER(0)
        WRITE_CORNER(5)
        WRITE_CORNER(35)
        WRITE_CORNER(30)
        nResult=gpGridBuffer_00971734->lpVtbl->Unlock(gpGridBuffer_00971734);
        if(nResult) { sub_006B20E0_DDrawLogError(gszUnlockFailure_006FC310,nResult);return; }
        gpDevice_00970E78->lpVtbl->DrawIndexedPrimitiveVB(gpDevice_00970E78,6,gpGridBuffer_00971734,gaFlatIndices_0074C3D0,4,0x1c);
    }
    else
    {
        long nResult=gpGridBuffer_00971734->lpVtbl->Lock(gpGridBuffer_00971734,0x21,&pVertices,0);
        if(nResult) { sub_006B20E0_DDrawLogError(gszLockFailure_006FC330,nResult);return; }
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
        if(nResult) { sub_006B20E0_DDrawLogError(gszUnlockFailure_006FC310,nResult);return; }
        gpDevice_00970E78->lpVtbl->DrawIndexedPrimitiveVB(gpDevice_00970E78,5,gpGridBuffer_00971734,gaGridIndices_009716B0,65,0x1c);
    }
    }
    }
}

#include "gen/data/Source/Storm/006B9170_sub_006B9170_DrawGrid.inc"
