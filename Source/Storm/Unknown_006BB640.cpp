#include "Storm.h"
#include "D2DDrawTypes.h"
#include "D2D3DTypes.h"

#define RELEASE(p) if (p) { p->lpVtbl->Release((D2ComObject006BB640Strc*)p); p = 0; }

struct D2ComObject006BB640Strc;
struct D2ComObjectVtbl006BB640Strc;
struct D2ComPtr006BB640Strc;
struct D2CacheBindingStrc;
struct D2CacheNodeStrc;
struct D2CacheListStrc;

struct D2ComObjectVtbl006BB640Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006BB640Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006BB640Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006BB640Strc* pThis);
};

struct D2ComObject006BB640Strc
{
    D2ComObject006BB640Strc* unk;
};

struct D2ComPtr006BB640Strc
{
    D2ComObjectVtbl006BB640Strc* lpVtbl;
};

extern D2ComPtr006BB640Strc* gpSurface_00989C00; // 0x00989C00

struct D2CacheBindingStrc
{
    int unk_00;
    short wSlot;
    short unk_06;
    int f_8[2];
    const unsigned char* pData;
};

struct D2CacheNodeStrc
{
    int id;
    D2CacheBindingStrc* binding;
    D2DDSurfaceStrc* pSurface;
    D2D3DTextureStrc* pTexture;
    D2CacheNodeStrc* next;
    D2CacheNodeStrc* previous;
};

struct D2CacheListStrc
{
    int capacity;
    int count;
    D2CacheNodeStrc* firstUsed;
    D2CacheNodeStrc* lastUsed;
    D2CacheNodeStrc* firstFree;
    D2CacheNodeStrc* lastFree;
    D2CacheNodeStrc* pNodes;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall sub_006B1DC0_Blit8To16(const unsigned char* pSource, unsigned short* pDest, int nWidth, int nHeight, int nPitch, int nUnused); // 0x006B1DC0
void __fastcall sub_006B20E0_DDrawLogError(const char* szWhere, int hResult); // 0x006B20E0
void __fastcall sub_006B38A0_Copy(D2DDSurfaceStrc* pDst, D2DDSurfaceStrc* pSrc, unsigned int nRows); // 0x006B38A0
void __fastcall sub_006BACB0_TouchCacheNode(D2CacheListStrc* pList, int nSlot); // 0x006BACB0
int __fastcall sub_006BAF00_AllocateCacheNode(D2CacheListStrc* pList); // 0x006BAF00
static void sub_006BB6B0_DecodeTile(const unsigned char* source, unsigned char* destination); // 0x006BB6B0
extern "C" const char gszFailedToUnlockMemorySurface_006FC284[]; // 0x006FC284
extern "C" const char gszFailedToLockMemorySurface_006FC2A4[]; // 0x006FC2A4
extern const unsigned int gnRenderFlag_006CE290; // 0x006CE290
extern D2D3DDeviceStrc* gpD3DDevice_00970E78; // 0x00970E78
extern D2D3DTextureStrc* gpMemoryTexture_00989C04; // 0x00989C04

D2ComPtr006BB640Strc* gpSurface_00989BF8; // 0x00989BF8

D2ComPtr006BB640Strc* gpTexture_00989BFC; // 0x00989BFC

D2ComPtr006BB640Strc* gpTexture_00989C04; // 0x00989C04

// 0x006BB640
void __cdecl sub_006BB640_ReleaseSurfaces()
{
    RELEASE(gpTexture_00989BFC);
    RELEASE(gpSurface_00989BF8);
    RELEASE(gpTexture_00989C04);
    RELEASE(gpSurface_00989C00);
}

D2CacheListStrc gTexCache_0096FC80; // 0x0096FC80

unsigned char gabTileBuffer_009897F8[0x400]; // 0x009897F8

D2DDSurfaceStrc* gpMemorySurface_00989C00; // 0x00989C00

static __declspec(noinline) void sub_006BB6B0_DecodeTile(const unsigned char* source, unsigned char* destination)
{
    int rows = 32;
    unsigned char* row = destination;
    unsigned char* pixel = destination;
    const unsigned char* input = source;
    memset(destination, 0, 1024);
    do
    {
        unsigned char skip = *input++;
        unsigned char count = *input++;
        if (!skip && !count)
        {
            --rows;
            row += 32;
            pixel = row;
        }
        else
        {
            pixel += skip;
            while (count--)
                *pixel++ = *input++;
        }
    } while (rows);
}

// 0x006BBA00
void __fastcall sub_006BBA00_BindTileTexture(D2CacheBindingStrc* pTile)
{
    D2_ASSERT(pTile->wSlot >= 0, 0x1EF);

    if (!pTile->wSlot)
    {
        sub_006BB6B0_DecodeTile(pTile->pData, gabTileBuffer_009897F8);
        pTile->wSlot = sub_006BAF00_AllocateCacheNode(&gTexCache_0096FC80);
        const int nIndex = pTile->wSlot - 1;
        D2_ASSERT(nIndex >= 0, 0x1FC);
        D2_ASSERT(nIndex < gTexCache_0096FC80.capacity, 0x1FD);

        D2CacheNodeStrc* pNode = &gTexCache_0096FC80.pNodes[pTile->wSlot - 1];
        pNode->binding = pTile;

        D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
        long hResult = gpMemorySurface_00989C00->lpVtbl->Lock(gpMemorySurface_00989C00, 0, &tDesc, 0x21, 0);
        if (hResult)
        {
            sub_006B20E0_DDrawLogError(gszFailedToLockMemorySurface_006FC2A4, hResult);
        }

        D2_ASSERT(tDesc.dwFlags & 8, 0x20B);

        sub_006B1DC0_Blit8To16(gabTileBuffer_009897F8, (unsigned short*)tDesc.lpSurface, 0x20, 0x20, tDesc.lPitch >> 1, 0x20);

        hResult = gpMemorySurface_00989C00->lpVtbl->Unlock(gpMemorySurface_00989C00, 0);
        if (hResult)
        {
            sub_006B20E0_DDrawLogError(gszFailedToUnlockMemorySurface_006FC284, hResult);
        }

        if (gnRenderFlags_0096F3A8 & gnRenderFlag_006CE290)
        {
            sub_006B38A0_Copy(pNode->pSurface, gpMemorySurface_00989C00, 0x20);
        }
        else
        {
            pNode->pTexture->lpVtbl->Load(pNode->pTexture, gpMemoryTexture_00989C04);
        }

        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
    }
    else
    {
        D2CacheNodeStrc* pNode = &gTexCache_0096FC80.pNodes[pTile->wSlot - 1];
        sub_006BACB0_TouchCacheNode(&gTexCache_0096FC80, pTile->wSlot);
        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
    }
}
