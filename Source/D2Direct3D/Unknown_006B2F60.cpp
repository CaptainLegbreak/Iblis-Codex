#include "D2Direct3D.h"
#include "D2D3DTypes.h"

struct D2Object006BB3E0Strc;

struct D2Object006BADC0Strc;

struct D2DDrawDeviceStrc;

class CRegKeyInline;

struct D2Cache006BA830Strc;

struct D2DDCaps006B3420Strc;

struct D2DDSurfaceDesc006B3420Strc;

struct D2ComObject006B3420Strc;


extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern D2DDrawDeviceStrc gaDDrawDevices[]; // 0x0096F4E0

class CRegKeyInline
{
public:
    void* m_hKey;

    CRegKeyInline() : m_hKey(0) {}
    ~CRegKeyInline() { Close(); }

    long Close()
    {
        long lRes = 0;
        if (m_hKey != 0)
        {
            lRes = RegCloseKey(m_hKey);
            m_hKey = 0;
        }
        return lRes;
    }

    long Create(void* hKeyParent, const char* lpszKeyName, char* lpszClass = 0, unsigned long dwOptions = 0,
        unsigned long samDesired = 0x20006, void* lpSecAttr = 0, unsigned long* lpdwDisposition = 0)
    {
        unsigned long dw;
        void* hKey = 0;
        long lRes = RegCreateKeyExA(hKeyParent, lpszKeyName, 0, lpszClass, dwOptions, samDesired, lpSecAttr, &hKey, &dw);
        if (lpdwDisposition != 0)
            *lpdwDisposition = dw;
        if (lRes == 0)
        {
            lRes = Close();
            m_hKey = hKey;
        }
        return lRes;
    }

    long SetDWORDValue(const char* pszValueName, unsigned long dwValue)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 4, (const unsigned char*)&dwValue, sizeof(unsigned long));
    }

    long SetStringValue(const char* pszValueName, const char* pszValue, unsigned long dwType = 1)
    {
        if (!pszValue)
            sub_006B1A30_ThrowAtlException(0x80004005);
        return RegSetValueExA(m_hKey, pszValueName, 0, dwType, (const unsigned char*)pszValue, (lstrlenA(pszValue) + 1) * sizeof(char));
    }

    long SetBinaryValue(const char* pszValueName, const void* pValue, unsigned long nBytes)
    {
        return RegSetValueExA(m_hKey, pszValueName, 0, 3, (const unsigned char*)pValue, nBytes);
    }
};

struct D2Cache006BA830Strc
{
    int unk0x00[7];
};

void __cdecl D3DSPRITE_ReleaseSprites(); // 0x006B5B10

void __cdecl sub_006B7250_ReleaseAll(); // 0x006B7250

void __cdecl D3DSMACK_ReleaseSmackSurfaces(); // 0x006B9B30

void __fastcall sub_006BA830_FreeCache(D2Cache006BA830Strc* pCache, int bFree); // 0x006BA830

void __fastcall D3DSUBTILECACHE_SubtileCacheDestroy(D2Object006BADC0Strc* pObject, int bFree); // 0x006BADC0

void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2Object006BB3E0Strc* pObject, int bFree); // 0x006BB3E0

extern int gdwGlobal_00970E8C; // 0x00970E8C

extern D2Object006BADC0Strc gObject_0096FC80; // 0x0096FC80

extern D2Object006BB3E0Strc gObject_0096FC9C; // 0x0096FC9C

extern D2Cache006BA830Strc gtTextureCache1; // 0x00970EC8

extern D2Cache006BA830Strc gtTextureCache2; // 0x00970EE4

extern D2Cache006BA830Strc gtTextureCache3; // 0x00970F00

void __cdecl D3DCORE_ReleaseResources(); // 0x006B3320

extern void* ghDDrawWindow_007C9140; // 0x007C9140

struct D2DDCaps006B3420Strc
{
    unsigned int dwCaps;
    unsigned int dwCaps2;
    unsigned int dwCaps3;
    unsigned int dwCaps4;
};

struct D2DDSurfaceDesc006B3420Strc
{
    unsigned int dwSize;
    unsigned int dwFlags;
    unsigned int aUnk0x08[24];
    D2DDCaps006B3420Strc tCaps;
    unsigned int dwTextureStage;
};

struct D2ComObject006B3420Strc
{
    virtual void __stdcall Unused00() = 0;
    virtual void __stdcall Unused04() = 0;
    virtual void __stdcall Unused08() = 0;
    virtual void __stdcall Unused0C() = 0;
    virtual void __stdcall Unused10() = 0;
    virtual void __stdcall Unused14() = 0;
    virtual long __stdcall CreateSurface(D2DDSurfaceDesc006B3420Strc* pDesc, D2ComObject006B3420Strc** ppSurface, void* pOuter) = 0;
    virtual void __stdcall Unused1C() = 0;
    virtual void __stdcall Unused20() = 0;
    virtual void __stdcall Unused24() = 0;
    virtual void __stdcall Unused28() = 0;
    virtual void __stdcall Unused2C() = 0;
    virtual void __stdcall Unused30() = 0;
    virtual void __stdcall Unused34() = 0;
    virtual void __stdcall Unused38() = 0;
    virtual void __stdcall Unused3C() = 0;
    virtual void __stdcall Unused40() = 0;
    virtual void __stdcall Unused44() = 0;
    virtual void __stdcall Unused48() = 0;
    virtual void __stdcall Unused4C() = 0;
    virtual void __stdcall Unused50() = 0;
    virtual long __stdcall SetDisplayMode(unsigned int nWidth, unsigned int nHeight, unsigned int nBpp, unsigned int nRefresh, unsigned int dwFlags) = 0;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0

extern int gbVideoUp; // 0x00970E40

extern int gnVideoState; // 0x00970E44

extern D2ComObject006B3420Strc* gpDirectDraw4; // 0x00970E60

extern D2ComObject006B3420Strc* gpPrimary_00970E68; // 0x00970E68

extern const unsigned int gdwBitMask7_006CE284; // 0x006CE284

extern const unsigned int gdwBitMask8; // 0x006CE288

extern int gnRenderHeight; // 0x007C913C

// 0x006B2F60
void __fastcall sub_006B2F60_SaveVideoConfig(int nRender, int nDevice)
{
    int aDeviceName[0x104 / 4];
    int aFlags[0x104 / 4];
    int aGuid[0x104 / 4];
    sprintf((char*)aDeviceName, "DeviceName");
    sprintf((char*)aFlags, "dwFlags");
    sprintf((char*)aGuid, "GUID");

    CRegKeyInline tKey;
    if (tKey.Create((void*)0x80000001, "SOFTWARE\\Blizzard Entertainment\\Diablo II\\VideoConfig") == 0)
    {
        tKey.SetDWORDValue("Render", nRender);
        tKey.SetStringValue((const char*)aDeviceName, gaDDrawDevices[nDevice].szName);
        tKey.SetDWORDValue((const char*)aFlags, gaDDrawDevices[nDevice].dwFlags);
        tKey.SetBinaryValue((const char*)aGuid, gaDDrawDevices[nDevice].guid, 0x10);
    }
}

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
char* __fastcall D3DSMACK_CreateSmackSurfaces(char*); // 0x006B9A50
char* __fastcall D3DFLOORCACHE_FloorCacheInit(BufferPool*,char*,char*,unsigned int); // 0x006BAFC0
char* __fastcall D3DSUBTILECACHE_SubtileCacheInit(BufferPool*,char*,char*,unsigned int); // 0x006BA9A0
char* __fastcall sub_006BA420(BufferPool*,char*,char*,unsigned int,unsigned int); // 0x006BA420
void __cdecl D3DSPRITE_InitSprites(); // 0x006B7110
void __fastcall D3DFLOORCACHE_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile); // 0x006BBB90
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
void __cdecl D3DFLOORCACHE_ReleaseTileSurfaces(); // 0x006BB640
int gbVideoUp; // 0x00970E40
int gnVideoState; // 0x00970E44
D2ComObjectStrc* gpPrimarySurface; // 0x00970E68
D2ComObjectStrc* gpRenderSurface; // 0x00970E6C
D2ComObjectStrc* gpInterface; // 0x00970E70
D2ComObjectStrc* gpGammaControl; // 0x00970E74
D2ComObjectStrc* gpViewport; // 0x00970E7C
char gabGammaRamp[1536]; // 0x0096FCB8

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
  current=D3DFLOORCACHE_FloorCacheInit(&gTilePool,current,(char*)primary,tileSize);
  gSecondaryBudget=secondary;
  secondary+=(unsigned int)current;
  current=D3DSUBTILECACHE_SubtileCacheInit(&gAuxiliaryPool,current,(char*)secondary,2048);
  start=current;remaining=memory-(unsigned int)current;
  current=sub_006BA420(&gLargePool,current,current+remaining*20/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420(&gMediumPool,current,start+remaining*75/100,128,128);
 } else {
  gPrimaryBudget=0;gSecondaryBudget=0;
  current=D3DSMACK_CreateSmackSurfaces(current);
  start=current;remaining=memory-(unsigned int)current;
  current=sub_006BA420(&gLargePool,current,current+remaining*70/100,256,256);
  gLargeBudget=gLargePool.count*gBufferCopies*65536;
  current=sub_006BA420(&gMediumPool,current,start+remaining*80/100,128,128);
 }
 gMediumBudget=gMediumPool.count*gBufferCopies*16384;
 sub_006BA420(&gSmallPool,current,(char*)memory,32,32);
 gSmallBudget=gSmallPool.count*gBufferCopies*1024;
 D3DSPRITE_InitSprites();
 TileSetHardwareFreeCallback((void*)D3DFLOORCACHE_InvalidateTileCaches);
}

// 0x006B32B0
void __cdecl sub_006B32B0_ReleaseRenderer()
{
    if (gdwGlobal_00970E8C)
    {
        sub_006B7250_ReleaseAll();
        D3DFLOORCACHE_FloorCacheDestroy(&gObject_0096FC9C, 1);
        D3DSUBTILECACHE_SubtileCacheDestroy(&gObject_0096FC80, 1);
    }
    else
    {
        D3DSMACK_ReleaseSmackSurfaces();
    }

    sub_006BA830_FreeCache(&gtTextureCache1, 1);
    sub_006BA830_FreeCache(&gtTextureCache2, 1);
    sub_006BA830_FreeCache(&gtTextureCache3, 1);
    D3DSPRITE_ReleaseSprites();
}

#include "gen/data/Source/D2Direct3D/Unknown_006B2F60.inc"
