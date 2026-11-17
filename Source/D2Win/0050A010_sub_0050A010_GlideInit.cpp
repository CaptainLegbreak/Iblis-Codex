struct D2GfxSettingsStrc;
struct D2TileDrawFunctionsStrc;

struct D2CriticalSectionStrc
{
    char unk0x00[0x18];
};

struct D2GlideTexSlotStrc
{
    int nCache;
    int nId;
};

struct D2GlideTexCacheEntryStrc
{
    int nId;
    int f_4;
    D2GlideTexSlotStrc* pOwner;
    int nOwnerIndex;
    int f_10;
    D2GlideTexCacheEntryStrc* pNext;
    D2GlideTexCacheEntryStrc* pPrev;
};

struct D2GlideTexCacheStrc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTexCacheEntryStrc* pHead;
    D2GlideTexCacheEntryStrc* pTail;
    D2GlideTexCacheEntryStrc* f_14;
    D2GlideTexCacheEntryStrc* f_18;
    D2GlideTexCacheEntryStrc* pEntries;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);     // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* pfnExit)());                                                   // 0x00683824
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
extern D2CriticalSectionStrc* gpRenderCriticalSection_007C9134;                                             // 0x007C9134
extern D2GfxSettingsStrc* gpGfxSettings_007C9148;                                                           // 0x007C9148
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C;                                               // 0x007C914C
void (__stdcall* gpfGlideFn_0087EB04)();                                                                    // 0x0087EB04
void (__stdcall* gpfGlideFn_0087EB3C)(int a1);                                                              // 0x0087EB3C
extern int gbGlideInit_0087EFCC;                                                                            // 0x0087EFCC
D2GlideTexCacheStrc gaGlideTexCaches_0087F048[4];                                                           // 0x0087F048

void __cdecl sub_00509FD0_GlideAtExit();                                                                    // 0x00509FD0
void __cdecl sub_0050C760_GlideInitC();                                                                     // 0x0050C760
void __cdecl sub_0050D540_GlideInitD();                                                                     // 0x0050D540
void __cdecl sub_0050DB20_AllocBlendTable();                                                                // 0x0050DB20
void __cdecl sub_0050DB70_GlideInitB();                                                                     // 0x0050DB70
void __cdecl sub_0050DC80_AllocPerspectiveTable();                                                          // 0x0050DC80
void __cdecl sub_0050DCD0_FillPerspectiveTable();                                                           // 0x0050DCD0
void __cdecl sub_0050DF10_GlideSmackInit();                                                                 // 0x0050DF10
void __cdecl sub_0050F870_GlideBlocksInit();                                                                // 0x0050F870

// 0x0050A010
int __fastcall sub_0050A010_GlideInit(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pTileDrawFunctions)
{
    D2_ASSERT(!gbGlideInit_0087EFCC, 0x2A6);

    gpGfxSettings_007C9148 = pSettings;
    gpTileDrawFunctions_007C914C = pTileDrawFunctions;
    sub_0050F870_GlideBlocksInit();
    sub_0050DC80_AllocPerspectiveTable();
    sub_0050DB20_AllocBlendTable();
    gpfGlideFn_0087EB04();
    gbGlideInit_0087EFCC = 1;
    gpfGlideFn_0087EB3C(0);
    atexit(sub_00509FD0_GlideAtExit);
    sub_0050DB70_GlideInitB();
    sub_0050DCD0_FillPerspectiveTable();
    sub_0050C760_GlideInitC();
    sub_0050D540_GlideInitD();
    sub_0050DF10_GlideSmackInit();
    gpRenderCriticalSection_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\glCore.cpp", 0x2D5, 0);
    InitializeCriticalSection(gpRenderCriticalSection_007C9134);
    return 1;
}

// 0x0050A110
void __fastcall sub_0050A110_ReleaseTexSlots(D2GlideTexSlotStrc* pSlots)
{
    for (int i = 0; i < 5; ++i)
    {
        const int nCache = pSlots[i].nCache - 1;
        if (nCache >= 0)
        {
            const int nId = pSlots[i].nId - 1;
            if (nId >= 0)
            {
                gaGlideTexCaches_0087F048[nCache + 1].pEntries[nId].pOwner = 0;
            }
        }
    }
}
