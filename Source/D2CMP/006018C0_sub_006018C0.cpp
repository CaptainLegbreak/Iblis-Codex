struct D2CelStrc
{
    int bFlip;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
    int unk0x14;
    void* pBlockPixelData;
};

struct D2CelFileStrc
{
    int nVersion;
    int dwFlags;
    int nFormat;
    int nTermination;
    int nDirections;
    int nCelsPerDirection;
};

typedef void (__stdcall* PixelDataFreeCallback)(void* pData);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
PixelDataFreeCallback gpfnPixelDataFree;                                                                    // 0x008E8CB8

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x006018C0
int __stdcall sub_006018C0(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1403);

    return pCel->nWidth;
}

// 0x006019F0
int __stdcall sub_006019F0(D2CelFileStrc* pCelFile)
{
    D2_ASSERT(pCelFile->nVersion == 6, 1489);

    return pCelFile->nCelsPerDirection;
}

// 0x00601A30
void __stdcall sub_00601A30_StorePixelFreeHandler(PixelDataFreeCallback pfnCallback)
{
    gpfnPixelDataFree = pfnCallback;
}

// 0x00601A40
PixelDataFreeCallback __stdcall sub_00601A40()
{
    return gpfnPixelDataFree;
}

// 0x00601B10
void* __stdcall sub_00601B10_GetCelPixels(D2CelStrc* pCel)
{
    D2_ASSERT(pCel, 1578);

    return pCel->pBlockPixelData;
}
