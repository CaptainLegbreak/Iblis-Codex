extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

struct D2CelBlockStrc
{
    char unk0x00[0x28];
    unsigned char* pPixels;
};

struct D2CelStrc
{
    int bFlip;
    int nWidth;
    int nHeight;
    int nXOffset;
    int nYOffset;
    unsigned int nDataSize;
    D2CelBlockStrc* pBlockPixelData;
    unsigned int nLength;
};

struct D2CelFileStrc
{
    int nVersion;
    unsigned int dwFlags;
    int nFormat;
    int nTermination;
    int nDirections;
    int nCelsPerDirection;
    D2CelStrc* pCels[1];
};

// 0x00601340
void __stdcall D2CMP_CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, int nUnused)
{
    if (!pFile)
    {
        return;
    }

    const unsigned int dwFlags = pFile->dwFlags;
    D2_ASSERT(dwFlags & 1, 0x396);
    if (nSpecVersion == -1)
    {
        D2_ASSERT(pFile->nVersion == 6, 0x399);
    }
    else
    {
        D2_ASSERT(pFile->nVersion == nSpecVersion, 0x39B);
    }

    if (dwFlags & 2)
    {
        return;
    }

    const unsigned int nSize = pFile->nDirections * pFile->nCelsPerDirection * sizeof(D2CelBlockStrc);
    pFile->dwFlags = dwFlags | 2;
    D2CelBlockStrc* pBlocks = (D2CelBlockStrc*)FOG_Alloc(nSize, ".\\SRC\\CelCmp.cpp", 0x3A6, 0);
    memset(pBlocks, 0, nSize);
    unsigned int i = 0;
    if (i < (unsigned int)(pFile->nDirections * pFile->nCelsPerDirection))
    {
        D2CelBlockStrc* pBlock = pBlocks;
        D2CelStrc** ppCels = pFile->pCels;
        do
        {
            *ppCels = (D2CelStrc*)((char*)*ppCels + (unsigned int)pFile);
            (*ppCels)->pBlockPixelData = pBlock;
            ++i;
            ++pBlock;
            ++ppCels;
        }
        while (i < (unsigned int)(pFile->nDirections * pFile->nCelsPerDirection));
    }

    *ppOutFile = pFile;
}
