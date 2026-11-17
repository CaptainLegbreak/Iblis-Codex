#include "D2Direct3D.h"

#define gnHandle_00989760 (gVideoVertices_00989750[0].color)
#define gnHandle_00989780 (gVideoVertices_00989750[1].color)
#define gnHandle_009897A0 (gVideoVertices_00989750[2].color)
#define gnHandle_009897C0 (gVideoVertices_00989750[3].color)
#define D2_IMPORT __declspec(dllimport)

struct D2ComObject006B9B30Strc;
struct D2ComObject006B9BD0Strc;
struct D2VideoBlitVertex;
struct D2ComObjectVtbl006B9B30Strc;
struct D2VideoHandleStrc;
struct D2ComObjectVtbl006B9BD0Strc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2VideoBlitVertex gVideoVertices_00989750[4]; // 0x00989750
extern void* gpBuffer_009897D0; // 0x009897D0
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern void* gpArray_009897D4[2]; // 0x009897D4
extern void* gpArray_009897DC[2]; // 0x009897DC
extern void* gpArray_009897E4[2]; // 0x009897E4
void __fastcall sub_006B3730_Allocate(void** ppFirst, void** ppSecond, int nCount, int nSize); // 0x006B3730
int __fastcall sub_006B58A0_Allocate(void** ppFirst, void** ppSecond, int nCount, int nSize); // 0x006B58A0

struct D2ComObjectVtbl006B9B30Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B9B30Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006B9B30Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B9B30Strc* pThis);
};

struct D2ComObject006B9B30Strc
{
    D2ComObjectVtbl006B9B30Strc* lpVtbl;
};

extern D2ComObject006B9B30Strc* gapObjectsD4_009897D4[2]; // 0x009897D4
extern D2ComObject006B9B30Strc* gapObjectsDC_009897DC[2]; // 0x009897DC
extern D2ComObject006B9B30Strc* gapObjectsE4_009897E4[2]; // 0x009897E4
extern D2ComObject006B9B30Strc* gapObjectsEC_009897EC[2]; // 0x009897EC
extern "C" D2_IMPORT void __stdcall SmackClose(void* handle);

struct D2VideoHandleStrc { void* handle; char type; };

struct D2ComObjectVtbl006B9BD0Strc
{
    void* unk_00[5];
    long (__stdcall* Set)(D2ComObject006B9BD0Strc* pThis, void* pValue);
};

struct D2ComObject006B9BD0Strc
{
    D2ComObjectVtbl006B9BD0Strc* lpVtbl;
};

extern void* gpBuffer_009897D4; // 0x009897D4
extern void* gpBuffer_009897D8; // 0x009897D8
void __fastcall sub_006B38A0_Copy(void* pTarget, void* pBuffer, int nSize); // 0x006B38A0

// 0x006B9A10
void __cdecl sub_006B9A10_Init()
{
    gnHandle_00989760 = -1;
    gnHandle_00989780 = -1;
    gnHandle_009897A0 = -1;
    gnHandle_009897C0 = -1;
    gpBuffer_009897D0 = FOG_Alloc(0x10000, ".\\Src\\d3dSmack.cpp", 0x38, 0);
    memset(gpBuffer_009897D0, 0, 0x10000);
}

// 0x006B9A50
char* __fastcall sub_006B9A50_InitBuffers(char* pBuffer)
{
    for (int i = 0; i < 2; ++i)
    {
        void** ppFirst = &gpArray_009897D4[i];
        void** ppSecond = &gpArray_009897DC[i];
        sub_006B3730_Allocate(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4A);
        D2_ASSERT(*ppSecond, 0x4B);
        ppFirst = &gpArray_009897E4[i];
        ppSecond = &gpArray_009897EC[i];
        int nResult = sub_006B58A0_Allocate(ppFirst, ppSecond, 256, 64);
        D2_ASSERT(*ppFirst, 0x4E);
        D2_ASSERT(*ppSecond, 0x4F);
        D2_ASSERT(nResult, 0x50);
    }
    return pBuffer + 0x10000;
}

// 0x006B9B30
void __cdecl sub_006B9B30_ReleaseObjects()
{
    for (int i = 0; i < 2; ++i)
    {
        RELEASE(gapObjectsDC_009897DC[i]);
        RELEASE(gapObjectsD4_009897D4[i]);
        RELEASE(gapObjectsEC_009897EC[i]);
        RELEASE(gapObjectsE4_009897E4[i]);
    }
}

// 0x006B9BB0
void __fastcall sub_006B9BB0_CloseSmack(D2VideoHandleStrc* video)
{
    if (video->type == 's' && video->handle) {
        SmackClose(video->handle);
        video->handle = 0;
    }
}

void* gpValue_009897DC; // 0x009897DC

void* gpValue_009897E0; // 0x009897E0

void* gpTarget_009897E4; // 0x009897E4

void* gpTarget_009897E8; // 0x009897E8

D2ComObject006B9BD0Strc* gpObject_009897EC; // 0x009897EC

D2ComObject006B9BD0Strc* gpObject_009897F0; // 0x009897F0

// 0x006B9BD0
void __cdecl sub_006B9BD0_Apply()
{
    if (gpBuffer_009897D4)
    {
        if (gnRenderFlags_0096F3A8 & gnRenderFlag_006CE290)
        {
            sub_006B38A0_Copy(gpTarget_009897E4, gpBuffer_009897D4, 0x40);
            sub_006B38A0_Copy(gpTarget_009897E8, gpBuffer_009897D8, 0x40);
        }
        else
        {
            gpObject_009897EC->lpVtbl->Set(gpObject_009897EC, gpValue_009897DC);
            gpObject_009897F0->lpVtbl->Set(gpObject_009897F0, gpValue_009897E0);
        }
    }
}
