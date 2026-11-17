struct D2UnitStrc;

struct D2GfxListNodeStrc
{
    char unk0x00[0x10];
    D2GfxListNodeStrc* pNext;
};

struct D2OverlayStrc
{
    char unk0x00[0x40];
    void* pResource;
    char unk0x44[0x60];
    D2OverlayStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x28];
    D2GfxListNodeStrc* pList;
    D2OverlayStrc* pOverlays;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x0046EB70
static void sub_0046EB70_FreeOverlays(D2GfxDataStrc* pGfxData)
{
    D2OverlayStrc* pOverlay = pGfxData->pOverlays;
    while (pOverlay)
    {
        D2OverlayStrc* pNext = pOverlay->pNext;
        if (pOverlay->pResource)
        {
            sub_004743D0_ReleaseOverlayResource(pOverlay->pResource);
        }
        FOG_Free(pOverlay, ".\\ENGINE\\Gfx.cpp", 0x690, 0);
        pOverlay = pNext;
    }
}

// 0x0046EC10
void __fastcall sub_0046EC10_FreeGfxData(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x814);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x81A, 0);
        pNode = pNext;
    }
    sub_0046EB70_FreeOverlays(pGfxData);
    FOG_Free(pGfxData, ".\\ENGINE\\Gfx.cpp", 0x820, 0);
}
