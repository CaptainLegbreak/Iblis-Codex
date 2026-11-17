extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue);
extern int gaDirectionIndex64_006E45A0[][64];                                                               // 0x006E45A0

struct D2CelStrc;

struct D2CmpCelFileViewStrc
{
    int nVersion;
    char unk0x04[0x0C];
    unsigned int nDirections;
    unsigned int nFrames;
    D2CelStrc* pCels[1];
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame;
    char unk0x04[0x30];
    D2CmpCelFileViewStrc* pCelFile;
    char unk0x38[0x08];
    unsigned int nDirection;
};

// 0x00601810
int __stdcall sub_00601810_IsGfxFrameValid(D2CmpCelContextStrc* pContext)
{
    D2CmpCelFileViewStrc* pCelFile = pContext->pCelFile;
    if (!pCelFile)
    {
        return 0;
    }

    if (pCelFile->nVersion != 6)
    {
        return 0;
    }

    if (pContext->nDirection >= 0x40)
    {
        return 0;
    }

    if (pContext->nFrame > pCelFile->nFrames)
    {
        return 0;
    }

    return 1;
}

// 0x00601840
D2CelStrc* __stdcall D2CMP_CelGetHandle(D2CmpCelContextStrc* pContext)
{
    D2_ASSERT(pContext, 0x566);
    D2_ASSERT(sub_00601810_IsGfxFrameValid(pContext), 0x567);

    D2CmpCelFileViewStrc* pCelFile = pContext->pCelFile;
    const unsigned int nDirection = pContext->nDirection;
    const unsigned int nDirections = pCelFile->nDirections;
    const int nIndex = gaDirectionIndex64_006E45A0[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
    return pCelFile->pCels[nIndex * pCelFile->nFrames + pContext->nFrame];
}
