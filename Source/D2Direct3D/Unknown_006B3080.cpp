struct D2TileLibraryEntryStrc;
struct D2ComObjectStrc;
struct BufferPool;
struct D2ComVtblStrc;

struct BufferPool { unsigned int count; char unknown[24]; };


extern unsigned int gRenderFlags; // 0x0096F3A8
extern const unsigned int gPrimaryRenderMask; // 0x006CE26C
extern const unsigned int gCompactRenderMask; // 0x006CE280
extern unsigned int gAvailableMemory; // 0x0096F4D0
extern unsigned int gPreferredMemory; // 0x0096F4D8
extern unsigned int gTileWidth; // 0x0096F4DC
extern unsigned int gTileHeight; // 0x009702B8
extern int gUseTileBuffers; // 0x00970E8C
extern int gUsePreferredMemory; // 0x00970E4C
extern unsigned int gBufferCopies; // 0x00970E80
extern unsigned int gPrimaryBudget; // 0x007C90C8
extern unsigned int gSecondaryBudget; // 0x007C90D4
extern unsigned int gLargeBudget; // 0x007C90E0
extern unsigned int gMediumBudget; // 0x007C90E4
extern unsigned int gSmallBudget; // 0x007C90E8
extern BufferPool gTilePool; // 0x0096FC9C
extern BufferPool gAuxiliaryPool; // 0x0096FC80
extern BufferPool gLargePool; // 0x00970EC8
extern BufferPool gMediumPool; // 0x00970EE4
extern BufferPool gSmallPool; // 0x00970F00
char* __fastcall sub_006B76D0_InitVertices(char*); // 0x006B76D0
char* __fastcall D3D_CreateSmackSurfaces(char*); // 0x006B9A50
char* __fastcall sub_006BAFC0(BufferPool*,char*,char*,unsigned int); // 0x006BAFC0
char* __fastcall sub_006BA9A0(BufferPool*,char*,char*,unsigned int); // 0x006BA9A0
char* __fastcall sub_006BA420(BufferPool*,char*,char*,unsigned int,unsigned int); // 0x006BA420
void __cdecl D3D_InitSprites(); // 0x006B7110
void __fastcall D3D_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile); // 0x006BBB90
void __stdcall TileSetHardwareFreeCallback(void*); // 0x00604A30

struct D2ComVtblStrc
{
    void* pfQueryInterface;
    void* pfAddRef;
    unsigned long (__stdcall* pfRelease)(D2ComObjectStrc* pThis);
    void* pfGetGammaRamp;
    long (__stdcall* pfSetGammaRamp)(D2ComObjectStrc* pThis, unsigned long dwFlags, void* pRamp);
};

struct D2ComObjectStrc
{
    D2ComVtblStrc* f_0;
};


extern D2ComObjectStrc* gpInterface_00970E78; // 0x00970E78
void __cdecl sub_006B9150_ReleaseResource(); // 0x006B9150
void __cdecl D3D_ReleaseTileSurfaces(); // 0x006BB640
void __cdecl sub_006B32B0_ReleaseRenderer(); // 0x006B32B0
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0

// 0x006B3080
void __cdecl sub_006B3080()
{
 unsigned int memory;
 gBufferCopies=2;
 gUsePreferredMemory=0;
 if((gRenderFlags&gPrimaryRenderMask) && gAvailableMemory<0xD00000) {
  gUsePreferredMemory=1;
  if(gPreferredMemory>=0x2000000)gPreferredMemory=0x2000000;
  memory=gAvailableMemory;
  if(memory<=gPreferredMemory)memory=gPreferredMemory;
 } else {
  memory=gAvailableMemory;
  if(memory>=0x2000000)memory=0x2000000;
 }
 char* current = 0;char* start;unsigned int remaining;
 if(gUseTileBuffers) {
  unsigned int width,height;
  if(gRenderFlags&gCompactRenderMask){width=160;height=80;}else{width=256;height=128;}
  gTileHeight=height;gTileWidth=width;
  unsigned int tileSize=2*width*height;
  unsigned int primary=memory/2<0x600000?memory/2:0x600000;
  unsigned int secondary=memory/8<0x300000?memory/8:0x300000;
  current=sub_006B76D0_InitVertices(current);
  gPrimaryBudget=primary;
  primary+=(unsigned int)current;
  current=sub_006BAFC0(&gTilePool,current,(char*)primary,tileSize);
  gSecondaryBudget=secondary;
  secondary+=(unsigned int)current;
  current=sub_006BA9A0(&gAuxiliaryPool,current,(char*)secondary,2048);
  start=current;remaining=memory-(unsigned int)current;
  current=sub_006BA420(&gLargePool,current,current+remaining*20/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420(&gMediumPool,current,start+remaining*75/100,128,128);
 } else {
  gPrimaryBudget=0;gSecondaryBudget=0;
  current=D3D_CreateSmackSurfaces(current);
  start=current;remaining=memory-(unsigned int)current;
  current=sub_006BA420(&gLargePool,current,current+remaining*70/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420(&gMediumPool,current,start+remaining*80/100,128,128);
 }
 gMediumBudget=gMediumPool.count*gBufferCopies*16384;
 sub_006BA420(&gSmallPool,current,(char*)memory,32,32);
 gSmallBudget=gSmallPool.count*gBufferCopies*1024;
 D3D_InitSprites();
 TileSetHardwareFreeCallback((void*)D3D_InvalidateTileCaches);
}

int gbVideoUp; // 0x00970E40

int gnVideoState; // 0x00970E44

D2ComObjectStrc* gpPrimarySurface; // 0x00970E68

D2ComObjectStrc* gpRenderSurface; // 0x00970E6C

D2ComObjectStrc* gpInterface; // 0x00970E70

D2ComObjectStrc* gpGammaControl; // 0x00970E74

D2ComObjectStrc* gpViewport; // 0x00970E7C

char gabGammaRamp[1536]; // 0x0096FCB8

