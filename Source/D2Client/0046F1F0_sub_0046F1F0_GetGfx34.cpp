extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GfxNodeTargetStrc
{
    char unk0x00[0x14];
    int nValue;
};

struct D2GfxListNodeStrc
{
    int nMode;
    int nId;
    D2GfxNodeTargetStrc* pTarget;
    char unk0x0C[0x4];
    D2GfxListNodeStrc* pNext;
};

struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    char unk0x08[0x9C];
    D2UnitOverlayStrc* pNext;
};

struct D2GfxEntryStrc
{
    unsigned char nValue;
    unsigned char unk0x01;
};

#define GFX_ENTRY_COUNT 20

struct D2GfxDataStrc
{
    D2GfxEntryStrc tEntries[GFX_ENTRY_COUNT];
    D2GfxListNodeStrc* pList;
    D2UnitOverlayStrc* pOverlays;
    int nUnk0x30;
    int nUnk0x34;
    int nUnk0x38;
};

// 0x0046F1F0
int __fastcall sub_0046F1F0_GetGfx34(D2GfxDataStrc* pGfxData)
{
    D2_ASSERT(pGfxData, 0xCF1);
    return pGfxData->nUnk0x34;
}

// 0x0046F250
int __fastcall sub_0046F250_GetGfx38(D2GfxDataStrc* pGfxData)
{
    D2_ASSERT(pGfxData, 0xD0A);
    return pGfxData->nUnk0x38;
}

// 0x0046F360
void __cdecl sub_0046F360_Empty()
{
}

// 0x0046F9B0
void __cdecl sub_0046F9B0_Empty()
{
}

// 0x0046F9C0
void __cdecl sub_0046F9C0_Empty()
{
}
