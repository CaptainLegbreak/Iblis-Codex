struct T00481720;
struct D2CmpBlockTableBStrc;
struct D2SpriteCacheNodeStrc;
struct D2CmpGfxHashEntryStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
#pragma intrinsic(strcpy)

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
struct AsyncData;
void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsync);                                                 // 0x0040A9E0

extern int gbCmpCompressedDataMode;                                                                         // 0x00741EFC
extern "C" const char gszFmtDcc4_006E3618[];
extern "C" const char gszFmtDc64_006E3608[];
extern "C" const char gszOverlaysDir_006E35F0[];
extern "C" const char gszFmtDc62_006E35E4[];
extern "C" const char gszFmtItemsDc6_006E35D4[];
extern "C" const char gszMissilesDir_006E35BC[];
extern "C" const char gszFmtDcc2_006E35B0[];
extern "C" const char gszObjectsDir_006E3628[];
extern "C" const char gszNoCompressName_006E363C[];
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char gszMonstersDir_006D6CAC[];                                                            // 0x006D6CAC
extern "C" const char gszCharsDir_006DCC34[];                                                               // 0x006DCC34
extern "C" const char gszSpriteCacheSourceFile[];                                                           // 0x006E364C

struct D2SpriteCacheStrc { void* pMemPool; };
extern D2SpriteCacheStrc gCmpTileCache;                                                                     // 0x0089DB60

struct D2CmpSpriteContextStrc
{
    int nFrame;
    unsigned int dwFlags;
    int nType;
    int nIndex;
    int nMode;
    int nOverlay;
    union
    {
        struct
        {
            char szToken[4];
            char szComponent[4];
            char szArmorType[4];
            char szMode[4];
            char szHitClass[4];
        };
        unsigned int dwName[5];
    };
    const char* pName;
    int nFrames;
    void* pCel;
    char unk0x38[0x04];
    void* pFrame;
    int nDirection;
    unsigned int dwGfxFlags;
};

struct D2CmpSpriteFileStrc
{
    unsigned int dwFlags;
    char unk0x04[0x10];
    int nDirections;
    int nFramesPerDirection;
    unsigned int aOffsets[1];
};

struct D2CmpDC6CelStrc { char unk0x00[0x2C]; };

struct D2CmpSpriteEntryStrc
{
    int nType;
    int nArg04;
    int nArg08;
    int nArg0C;
    int nArg10;
    int nArg14;
    int nArg18;
    int nArg1C;
    unsigned char nFlags;
    unsigned char nFrames;
    unsigned char nFirstFrame;
    unsigned char nDirections;
    unsigned char nFramesPerDirection;
    char unk0x25[3];
    int f_28;
    int aOffsets[0x21];
    AsyncData* pAsync;
    struct D2SpriteCacheNodeStrc* pHolder;
};

struct D2CmpDC6FrameStrc
{
    int f_0;
    unsigned int nWidth;
    unsigned int nHeight;
    char unk0x0C[0x08];
    int nOffsetY;
    D2CmpDC6CelStrc* pCel;
    int nLength;
};

#define APPEND_CODE(q, dw) \
    if ((char)(dw) != 0x20) { *q++ = (char)(dw); \
        if ((char)((dw) >> 8) != 0x20) { *q++ = (char)((dw) >> 8); \
            if ((char)((dw) >> 16) != 0x20) { *q++ = (char)((dw) >> 16); } } }

static __forceinline int SpriteCache_IsCompressible(D2CmpSpriteContextStrc* pContext)
{
    switch (pContext->nType)
    {
    case 1:
        switch (pContext->nIndex)
        {
        case 0xF3: case 0x11C: case 0x14D: case 0x220: case 0x22F: case 0x23A: case 0x2C1: case 0x2C5:
            if (!pContext->nMode)
            {
                return 0;
            }
            break;

        case 0xF2: case 0xFB: case 0x16F: case 0x209: case 0x2C0:
            return 0;
        }
        break;

    case 2:
        if (pContext->nIndex == 0x156 || pContext->nIndex == 0x233)
        {
            return 0;
        }
        break;
    }

    return 1;
}

__declspec(noinline) static int sub_005FE2B0_BuildGfxName(D2CmpSpriteContextStrc* pContext, char* szOut);

// 0x005FE2B0
static int sub_005FE2B0_BuildGfxName(D2CmpSpriteContextStrc* pContext, char* szOut)
{
    switch (pContext->nType)
    {
    case 4:
    {
        if (!pContext->pName)
        {
            *szOut = 0;
            return 0;
        }
        strcpy(szOut, pContext->pName);
        return 1;
    }

    case 3:
    {
        if (!pContext->pName)
        {
            *szOut = 0;
            return 0;
        }
        if (gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        strcpy(szOut, pContext->pName);
        return 1;
    }

    case 6:
    {
        if (!(pContext->dwFlags & 2))
        {
            *szOut = 0;
            return 0;
        }
        if (!pContext->pName)
        {
            *szOut = 0;
            return 0;
        }
        if (pContext->nOverlay != 0x7A && gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        strcpy(szOut, pContext->pName);
        return 1;
    }

    case 0:
    case 1:
    case 2:
    {
        char* p = szOut;
        unsigned int dw;
        dw = pContext->dwName[0]; APPEND_CODE(p, dw);
        dw = pContext->dwName[1]; APPEND_CODE(p, dw);
        dw = pContext->dwName[2]; APPEND_CODE(p, dw);
        dw = pContext->dwName[3]; APPEND_CODE(p, dw);
        dw = pContext->dwName[4]; APPEND_CODE(p, dw);
        *p = 0;

        if (SpriteCache_IsCompressible(pContext) && gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        return 1;
    }
    }

    *szOut = 0;
    return 0;
}

static __forceinline int SpriteCache_BuildDccOrDc6Path(char* szOut, const char* szDir, const char* szName, D2CmpSpriteContextStrc* pContext, int bAllowDcc)
{
    if (bAllowDcc)
    {
        if (gbCmpCompressedDataMode)
        {
            wsprintfA(szOut, gszFmtDcc2_006E35B0, szDir, szName);
            pContext->dwGfxFlags |= 1;
            return 1;
        }
        wsprintfA(szOut, gszFmtDc62_006E35E4, szDir, szName);
        return 1;
    }
    wsprintfA(szOut, gszFmtDc62_006E35E4, szDir, szName);
    return 1;
}

// build: context sub_005FE610_BuildGfxPath
static __declspec(noinline) int __stdcall sub_005FE610_BuildGfxPath(const char* szName, D2CmpSpriteContextStrc* pContext, char* szOut)
{
    int bCompressed;

    if (!szName[0])
    {
        *szOut = 0;
        return 0;
    }

    switch (pContext->nType)
    {
    case 3:
        if (!pContext->pName)
        {
            break;
        }
        return SpriteCache_BuildDccOrDc6Path(szOut, gszMissilesDir_006E35BC, pContext->pName, pContext, 1);

    case 4:
    {
        const int nMode = pContext->nMode;
        if (!pContext->pName)
        {
            break;
        }
        if (nMode == 4)
        {
            wsprintfA(szOut, gszFmtItemsDc6_006E35D4, szDataGlobal_006D4118, szName);
            return 1;
        }
        if (nMode == 3)
        {
            wsprintfA(szOut, "%s\\items\\%s.dc6", szDataGlobal_006D4118, szName);
            return 1;
        }
        break;
    }

    case 6:
        if (!(pContext->dwFlags & 2))
        {
            *szOut = 0;
            return 0;
        }
        return SpriteCache_BuildDccOrDc6Path(szOut, gszOverlaysDir_006E35F0, szName, pContext, pContext->nOverlay != 0x7A);

    default:
    {
        bCompressed = gbCmpCompressedDataMode;
        if (bCompressed && !SStrCmpI(szName, gszNoCompressName_006E363C, 0x7FFFFFFF))
        {
            bCompressed = 0;
            pContext->dwGfxFlags &= ~1;
        }

        const char* szBase;
        switch (pContext->nType)
        {
        case 0:
            szBase = gszCharsDir_006DCC34;
            break;

        case 1:
            szBase = gszMonstersDir_006D6CAC;
            switch (pContext->nIndex)
            {
            case 0xF3: case 0x11C: case 0x14D: case 0x220: case 0x22F: case 0x23A: case 0x2C1: case 0x2C5:
                if (pContext->nMode)
                {
                    break;
                }
            case 0xF2: case 0xFB: case 0x16F: case 0x209: case 0x2C0:
                bCompressed = 0;
                break;
            }
            break;

        case 2:
            if (pContext->nIndex == 0x156 || pContext->nIndex == 0x233)
            {
                bCompressed = 0;
            }
            szBase = gszObjectsDir_006E3628;
            break;

        default:
            goto Fail;
        }

        char szToken[4];
        char szComponent[4];
        szToken[3] = 0;
        szComponent[3] = 0;
        szToken[0] = pContext->szToken[0] == 0x20 ? 0 : pContext->szToken[0];
        szToken[1] = pContext->szToken[1] == 0x20 ? 0 : pContext->szToken[1];
        szToken[2] = pContext->szToken[2] == 0x20 ? 0 : pContext->szToken[2];
        szComponent[0] = pContext->szComponent[0] == 0x20 ? 0 : pContext->szComponent[0];
        szComponent[1] = pContext->szComponent[1] == 0x20 ? 0 : pContext->szComponent[1];
        szComponent[2] = pContext->szComponent[2] == 0x20 ? 0 : pContext->szComponent[2];

        if (bCompressed)
        {
            wsprintfA(szOut, gszFmtDcc4_006E3618, szBase, szToken, szComponent, szName);
            pContext->dwGfxFlags |= 1;
            return 1;
        }
        wsprintfA(szOut, gszFmtDc64_006E3608, szBase, szToken, szComponent, szName);
        return 1;
    }
    }

Fail:
    *szOut = 0;
    return 0;
}

// 0x005FEC90
static __declspec(noinline) void __stdcall sub_005FEC90_InitDC6Frames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    char szName[0x104];
    char szPath[0x104];

    D2_ASSERT(pContext, 0x50D);
    D2_ASSERT(pEntry, 0x50E);
    D2_ASSERT(!(pFile->dwFlags & 1), 0x50F);
    D2_ASSERT(!pEntry->f_28, 0x512);

    const int nSize = pEntry->nFrames * pEntry->nFramesPerDirection * sizeof(D2CmpDC6CelStrc);
    D2CmpDC6CelStrc* pCels = (D2CmpDC6CelStrc*)FOG_AllocPool(gCmpTileCache.pMemPool, nSize, ".\\SRC\\SpriteCache.cpp", 0x517, 0);
    memset(pCels, 0, nSize);

    char* pData = (char*)FOG_AsyncDataGetBuffer(pEntry->pAsync);
    D2_ASSERT(pData, 0x524);

    int nOffset = pEntry->aOffsets[pEntry->nFirstFrame];
    D2CmpDC6FrameStrc* pFrame;
    for (unsigned int i = 0; i < (unsigned int)(pEntry->nFrames * pEntry->nFramesPerDirection); ++i, nOffset += pFrame->nLength + pFrame->nOffsetY + 0x23)
    {
        pFrame = (D2CmpDC6FrameStrc*)(pData + nOffset);
        if (pFrame->f_0 != 0 || pFrame->nWidth > 0x100 || pFrame->nHeight > 0x100)
        {
            sub_005FE2B0_BuildGfxName(pContext, szName);
            sub_005FE610_BuildGfxPath(szName, pContext, szPath);
            D2_ASSERT(0, 0x58C);
        }

        pFrame->pCel = &pCels[i];
    }

    pEntry->f_28 = 1;
}

struct D2CmpDC6HeaderStrc
{
    unsigned char nFlags;
    char unk0x01[2];
    unsigned char nDirections;
    unsigned char nFrames;
    char unk0x05[3];
    int bFramesReady;
    int aOffsets[1];
    char unk0x10[0x80];
    AsyncData* pAsync;
};

struct D2SpriteCacheNodeStrc
{
    D2CmpSpriteEntryStrc* f_0;
    int unk0x04;
    D2CmpGfxHashEntryStrc* pRecord;
};

struct D2CmpGfxHashEntryStrc
{
    char unk0x00[0x24];
    D2SpriteCacheNodeStrc* pHolder;
};

D2SpriteCacheNodeStrc* __fastcall sub_005FFC40_SpriteCacheAlloc(D2SpriteCacheStrc* pCache, unsigned int nSize, unsigned int nKey, int bLocked); // 0x005FFC40

struct D2CmpLoadDescStrc
{
    void* pfnCallback;
    D2CmpSpriteFileStrc* pFile;
    unsigned char* pFlags;
    int nFirstFrame;
    int nFrames;
    int unk0x14;
    int unk0x18;
};

struct D2SpriteLoadRequestStrc;
AsyncData* __fastcall sub_0040A620(void* hArchive, const char* szFileName, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8, const char* szFile, int nLine); // 0x0040A620
int __fastcall sub_0040AA40(AsyncData* pAsync);                                                       // 0x0040AA40
int __stdcall sub_005FF6E0_SpriteLoadCallback(void* hArg, int nArg, D2SpriteLoadRequestStrc* pRequest);    // 0x005FF6E0

extern D2CmpBlockTableBStrc gCmpBlockTableB;                                                                // 0x0088DB58

int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections);                   // 0x00600C90
D2CmpGfxHashEntryStrc* __fastcall sub_0060ADC0_GfxHashAdd(void* pMemPool, D2CmpBlockTableBStrc* pHash, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile); // 0x0060ADC0

// 0x005FEB80
static void* __stdcall sub_005FEB80_FindDC6Frame(void* pData, D2CmpSpriteContextStrc* pContext, D2CmpDC6HeaderStrc* pHeader)
{
    if (!pData)
        return 0;
    if (!pHeader)
        return 0;
    if ((unsigned int)pContext->nFrame >= pHeader->nFrames)
        return 0;

    int nIndex;
    D2CmpDC6FrameStrc* pFrame = (D2CmpDC6FrameStrc*)pData;
    if (pContext->nType == 6 && (pContext->dwFlags & 2))
        nIndex = sub_00600C90_GetDirectionIndex64(pContext->nDirection, pHeader->nDirections - 1);
    else if (pContext->nType == 2)
        nIndex = 0;
    else if (pContext->nType == 4)
        nIndex = pContext->nDirection;
    else
        nIndex = sub_00600C90_GetDirectionIndex64(pContext->nDirection, pHeader->nDirections - 1);

    if (nIndex >= pHeader->nDirections - 1)
        return 0;

    int nOffset = pHeader->aOffsets[nIndex];
    if (nOffset < 0)
        return 0;

    const int nFrame = pContext->nFrame;
    for (int i = 0; i <= nFrame; ++i)
    {
        pFrame = (D2CmpDC6FrameStrc*)((char*)pData + nOffset);
        if (pFrame->f_0 != 0)
            return 0;
        if (pFrame->nWidth > 0x100)
            return 0;
        if (pFrame->nHeight > 0x100)
            return 0;
        nOffset += pFrame->nLength + pFrame->nOffsetY + 0x23;
        if (nOffset < 0)
            return 0;
    }

    return pFrame;
}

__declspec(noinline) static void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry);
// 0x005FEC50
static void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    if (pEntry && pEntry->pAsync)
    {
        D2CmpDC6HeaderStrc* pHeader = (D2CmpDC6HeaderStrc*)&pEntry->nFlags;
        void* pData = FOG_AsyncDataGetBuffer(pHeader->pAsync);
        if (pData)
        {
            pContext->nFrames = pHeader->nFrames;
            return sub_005FEB80_FindDC6Frame(pData, pContext, pHeader);
        }

        return 0;
    }

    return 0;
}

static __declspec(noinline) int __fastcall sub_005FF760_LoadDCCFrames(const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, D2CmpSpriteEntryStrc* pEntry);

// calling-convention shim (not game code)
static int __fastcall sub_005FF760_LoadDCCFrames(const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, D2CmpSpriteEntryStrc* pEntry)
{
    if (!pFile || !pEntry)
    {
        return 0;
    }

    pEntry->pHolder = sub_005FFC40_SpriteCacheAlloc((D2SpriteCacheStrc*)szName, (unsigned int)pFile, 0, 0);
    for (const int* pOffset = pEntry->aOffsets; *pOffset; ++pOffset)
    {
        pEntry->nFlags += (unsigned char)sub_0040AA40((AsyncData*)pOffset);
    }

    sub_0040AA40((AsyncData*)&pContext);
    sub_0040AA40((AsyncData*)&nDirection);
    sub_0040AA40((AsyncData*)&nFrames);
    return pEntry->nFlags;
}

// 0x005FFE90
static int __stdcall sub_005FFE90_LoadDC6Entry(D2CmpSpriteFileStrc* pFile, int nArg2, int nArg3, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    if (!pFile)
        return 0;

    D2SpriteCacheNodeStrc* pHolder = sub_005FFC40_SpriteCacheAlloc(&gCmpTileCache, sizeof(D2CmpSpriteEntryStrc), 0, 0);
    if (!pHolder)
        return 0;

    D2CmpSpriteEntryStrc* pEntry = pHolder->f_0;
    memset(pEntry, 0, sizeof(D2CmpSpriteEntryStrc));
    pEntry->nType = pContext->nType;
    pEntry->nArg0C = pContext->dwName[0];
    pEntry->nArg18 = pContext->dwName[3];
    pEntry->nArg10 = pContext->dwName[1];
    pEntry->nArg14 = pContext->dwName[2];
    pEntry->nArg1C = pContext->dwName[4];
    pEntry->pHolder = pHolder;
    if (!(pFile->dwFlags & 1))
    {
        pEntry->nArg08 = pContext->nIndex;
        pEntry->nArg04 = pContext->nMode;
        sub_005FF760_LoadDCCFrames(szName, pFile, pContext, nArg2, nArg3, pEntry);
    }

    D2CmpGfxHashEntryStrc* pRecord = sub_0060ADC0_GfxHashAdd(gCmpTileCache.pMemPool, &gCmpBlockTableB, pHolder->f_0, pContext, pFile);
    D2_ASSERT(pRecord, 0x5D1);
    pHolder->pRecord = pRecord;
    pRecord->pHolder = pHolder;
    if (pFile->dwFlags & 1)
    {
        pEntry->nFlags |= 1;
        return 0;
    }

    if (!pEntry->f_28)
        sub_005FEC90_InitDC6Frames(pFile, pContext, pEntry);

    pContext->pFrame = sub_005FEC50_GetCachedDC6Frame(pContext, pEntry);
    return pContext->pFrame != 0;
}

int __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bForce); // 0x005FF4A0
void __fastcall sub_005FF630_ResizeCacheEntry(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int nDelta, int nArg); // 0x005FF630
unsigned int __stdcall sub_00600D30_CanConvertDirections(unsigned int nFrom, unsigned int nTo);             // 0x00600D30
void* __fastcall sub_0060ACE0_GfxHashFind(D2CmpBlockTableBStrc* pHash, D2CmpSpriteContextStrc* pContext, int* pDirection, unsigned int* pFrames, D2CmpSpriteFileStrc* pFile); // 0x0060ACE0
extern int gbCmpDisableConvert_0089DB58;                                                                    // 0x0089DB58

static int __stdcall sub_005FFA20_LoadDC6Frames(D2CmpSpriteFileStrc* pFile, int nDirection, const char* szName, int nFrames, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext)
{
    D2_ASSERT(pFile, 0x38F);
    D2_ASSERT(pEntry, 0x390);
    D2_ASSERT(pContext, 0x391);

    const int nType = pContext->nType;
    unsigned int nStart = 0;
    unsigned int nEnd = 0;
    if (nType == 1 || nType == 0)
    {
        if (nType == 1 && nFrames == 1 && pFile->nDirections != 1)
        {
            return -1;
        }

        nStart = nDirection * nFrames;
        nEnd = nStart + nFrames;
    }

    const int nSize = pFile->aOffsets[nEnd] - pFile->aOffsets[nStart];
    D2_ASSERT(nSize, 0x3A9);
    D2_ASSERT(!pEntry->pAsync, 0x3AA);

    pEntry->nFirstFrame = (unsigned char)(nDirection * nFrames);
    pEntry->nFrames = (unsigned char)nFrames;
    pEntry->nFramesPerDirection = (unsigned char)pFile->nFramesPerDirection;
    pEntry->nDirections = (unsigned char)pFile->nDirections + 1;

    const unsigned int nBase = pFile->aOffsets[nStart];
    for (unsigned int i = nStart; i <= nEnd; ++i)
    {
        D2_ASSERT(i < 0x21, 0x3C1);
        const int nOffset = pFile->aOffsets[i] - nBase;
        pEntry->aOffsets[i] = nOffset;
        D2_ASSERT(nOffset >= 0, 0x3C3);
    }

    if (pFile->dwFlags & 2)
    {
        D2CmpLoadDescStrc tDesc = { 0 };
        tDesc.pFile = pFile;
        pEntry->nFlags |= 4;
        tDesc.nFrames = nFrames;
        tDesc.pFlags = &pEntry->nFlags;
        tDesc.pfnCallback = (void*)sub_005FF6E0_SpriteLoadCallback;
        tDesc.nFirstFrame = nDirection * nFrames;
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 1, pFile->aOffsets[nStart], nSize, 0, (int)&tDesc, -2, gszSpriteCacheSourceFile, 0x3DA);
    }
    else
    {
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 1, pFile->aOffsets[nStart], nSize, 0, 0, -2, gszSpriteCacheSourceFile, 0x3E6);
    }

    if (!pEntry->pAsync)
    {
        return -1;
    }

    return nSize;
}

// 0x005FFFA0
static int __stdcall sub_005FFFA0_LoadDC6CacheEntry(D2CmpSpriteFileStrc* pFile, int nDirection, int nFrames, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    D2SpriteCacheNodeStrc* pHolder = sub_005FFC40_SpriteCacheAlloc(&gCmpTileCache, sizeof(D2CmpSpriteEntryStrc), 0, 1);
    if (pHolder)
    {
        D2CmpSpriteEntryStrc* pEntry = pHolder->f_0;
        memset(pEntry, 0, sizeof(D2CmpSpriteEntryStrc));
        pEntry->nArg0C = pContext->dwName[0];
        pEntry->nArg18 = pContext->dwName[3];
        pEntry->nArg10 = pContext->dwName[1];
        pEntry->nArg14 = pContext->dwName[2];
        pEntry->nArg1C = pContext->dwName[4];
        pEntry->pHolder = pHolder;
        int nSize = 0;
        if (!(pFile->dwFlags & 1))
        {
            pEntry->nArg08 = pContext->nIndex;
            pEntry->nArg04 = pContext->nMode;
            nSize = sub_005FFA20_LoadDC6Frames(pFile, nDirection, szName, nFrames, pEntry, pContext);
            if (nSize != -1)
            {
                sub_005FF630_ResizeCacheEntry(&gCmpTileCache, pHolder, nSize, 1);
            }
        }

        if (nSize != -1)
        {
            D2CmpGfxHashEntryStrc* pRecord = sub_0060ADC0_GfxHashAdd(gCmpTileCache.pMemPool, &gCmpBlockTableB, pHolder->f_0, pContext, pFile);
            D2_ASSERT(pRecord, 0x630);
            pHolder->pRecord = pRecord;
            pRecord->pHolder = pHolder;
            if (pFile->dwFlags & 1)
            {
                pEntry->nFlags |= 1;
                return 0;
            }

            pEntry->nFlags |= 2;
            return 1;
        }

        sub_005FF4A0_SpriteCachePurge(&gCmpTileCache, pHolder, 1);
        return 0;
    }

    return 0;
}

static __forceinline int SpriteCache_ShouldConvert(D2CmpSpriteContextStrc* pContext, int nDirection, unsigned int nFrames)
{
    unsigned int bConvert = 1;
    if (!(pContext->nType == 6 && (pContext->dwFlags & 2)))
    {
        if (!pContext->nType
            && (!(pContext->dwFlags & 8) || !pContext->nMode || pContext->nMode == 0x11 || gbCmpDisableConvert_0089DB58))
        {
            bConvert = 0;
        }
    }

    if (nDirection || nFrames <= 1 || !bConvert)
    {
        return 0;
    }

    return 1;
}

// 0x006000B0
static void __stdcall sub_006000B0_LoadConvertedEntry(int nDirection, unsigned int nFrames, char* szName, int bDC6, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile, char* szPath)
{
    if (!pFile || !pContext)
    {
        return;
    }

    if (!SpriteCache_ShouldConvert(pContext, nDirection, nFrames))
    {
        return;
    }

    unsigned int const tArg1 = nFrames * 2;
    const unsigned int nConverted = sub_00600D30_CanConvertDirections(nFrames, tArg1);
    pContext->nDirection = (unsigned int)pFile->nDirections > 1 ? (nConverted << 6) / (unsigned int)pFile->nDirections : 1;

    if (sub_0060ACE0_GfxHashFind(&gCmpBlockTableB, pContext, &nDirection, &nFrames, pFile))
    {
        return;
    }

    D2_ASSERT(nDirection == 1, 0x686);
    D2_ASSERT(nFrames > 1, 0x687);

    if (!*szName && !sub_005FE2B0_BuildGfxName(pContext, szName))
    {
        return;
    }

    if (!*szPath && !sub_005FE610_BuildGfxPath(szName, pContext, szPath))
    {
        return;
    }

    if (bDC6)
    {
        sub_005FFFA0_LoadDC6CacheEntry(pFile, nDirection, nFrames, szPath, pContext);
    }
    else
    {
        sub_005FFE90_LoadDC6Entry(pFile, nDirection, nFrames, szPath, pContext);
    }
}

struct SpriteFile
{
    unsigned int flags;
    unsigned int version;
    unsigned int compression;
    unsigned int format;
    unsigned int reserved;
    unsigned int directions;
    unsigned int frames;
    unsigned int offsets[33];
    char name[32];
};
struct HashNode { char pad00[0x20]; D2CmpSpriteEntryStrc* entry; void* link; };
struct HashTable { int unused; };
struct SpriteCache { int unused; };
extern HashTable gHash_0088DB58; // 0x0088DB58
extern SpriteCache gCache_0089DB60; // 0x0089DB60
extern int gWarn_008ADBB0; // 0x008ADBB0
extern int __fastcall FOG_AsyncDataTestLoaded(AsyncData*); // 0x0040A7F0
extern void* __stdcall D2CMP_CelGetHandle(D2CmpSpriteContextStrc*); // 0x00601840
extern HashNode* __fastcall sub_0060ACE0_GfxHashFind(HashTable*, D2CmpSpriteContextStrc*, unsigned int*, unsigned int*, SpriteFile*); // 0x0060ACE0
extern void __fastcall sub_005FF5B0_SpriteCacheTouchNode(SpriteCache*, void*); // 0x005FF5B0
extern unsigned int __stdcall sub_00600CB0_ConvertDirection(unsigned int, unsigned int, unsigned int, int); // 0x00600CB0
#define SPRITE_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern HashTable gFileHash_0088CB20; // 0x0088CB20
extern SpriteCache gFileCache_0088DB20; // 0x0088DB20
extern unsigned int gaFileOffsets_0089DBB0[]; // 0x0089DBB0
HashNode* __fastcall sub_0060AF90_CelDataHashFind(HashTable*, const char*); // 0x0060AF90
HashNode* __fastcall sub_0060B010_CelDataHashAdd(void*, HashTable*, int, const char*); // 0x0060B010
void __fastcall sub_00609380(SpriteCache*, void*); // 0x00609380
void* __fastcall sub_00609420(SpriteCache*, unsigned int, HashNode*); // 0x00609420
int __fastcall sub_0060BF20_LoadTileHeader(const char*, SpriteFile*); // 0x0060BF20
int __fastcall sub_004068E0(const char*, char**); // 0x004068E0
int __fastcall sub_00406900(char*, void*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); // 0x00406900
unsigned int __fastcall sub_00406930(char*, unsigned int*); // 0x00406930
void __fastcall sub_004068F0(char*); // 0x004068F0

static __declspec(noinline) SpriteFile* __stdcall sub_005FE990_LoadSpriteFile(D2CmpSpriteContextStrc*, char*, char*);

// 0x005FE990
static SpriteFile* __stdcall sub_005FE990_LoadSpriteFile(D2CmpSpriteContextStrc* context, char* name, char* path)
{
    SpriteFile* file = 0;
    *path = 0;
    if (!sub_005FE2B0_BuildGfxName(context, name))
        return 0;
    HashNode* node = sub_0060AF90_CelDataHashFind(&gFileHash_0088CB20, name);
    if (node)
    {
        sub_00609380(&gFileCache_0088DB20, node->link);
        file = *(SpriteFile**)node->link;
    }
    else
    {
        if (!sub_005FE610_BuildGfxPath(name, context, path))
            return 0;
        node = sub_0060B010_CelDataHashAdd((void*)gFileCache_0088DB20.unused, &gFileHash_0088CB20, 0, name);
        SPRITE_ASSERT(node, 0x413);
        node->link = sub_00609420(&gFileCache_0088DB20, 0xC0, node);
        SPRITE_ASSERT(node->link, 0x418);
        file = *(SpriteFile**)node->link;
        memset(file, 0, 0xC0);
        strcpy(file->name, name);
        if (*(unsigned char*)&context->dwGfxFlags & 1)
        {
            if (!sub_0060BF20_LoadTileHeader(path, file))
                *(unsigned char*)&file->flags |= 1;
        }
        else
        {
            sub_004068E0(path, &path);
            if (path)
            {
                unsigned int header[7];
                memset(header, 0, sizeof(header));
                sub_00406900(path, header, 0x18, 0, 0, 0, 0);
                unsigned int fileSize = sub_00406930(path, 0);
                file->directions = header[4];
                file->frames = header[5];
                file->compression = header[1];
                file->version = header[0];
                file->format = header[2];
                unsigned int dwTotalCels = file->frames * file->directions;
                SPRITE_ASSERT(dwTotalCels < 0x4000, 0x444);
                unsigned int nBytes = dwTotalCels * 4;
                sub_00406900(path, gaFileOffsets_0089DBB0, nBytes, 0, 0, 0, 0);
                sub_004068F0(path);
                SPRITE_ASSERT(file->directions < 0x21, 0x449);
                for (unsigned int i = 0; i < file->directions; ++i)
                {
                    unsigned int nIndex = i * file->frames;
                    file->offsets[i] = gaFileOffsets_0089DBB0[nIndex];
                }
                file->offsets[file->directions] = fileSize;
            }
            else
                *(unsigned char*)&file->flags |= 1;
        }
    }
    SPRITE_ASSERT(file, 0x45C);
    return file;
}

// 0x006001F0
int __stdcall sub_006001F0_LoadSprite(D2CmpSpriteContextStrc* context, int async, int flags)
{
    if (!context)
        return 0;
    context->pFrame = 0;
    if (context->pCel)
    {
        context->pFrame = D2CMP_CelGetHandle(context);
        return 1;
    }
    char name[0x104];
    char path[0x104];
    SpriteFile* file = sub_005FE990_LoadSpriteFile(context, name, path);
    unsigned int index = 0;
    unsigned int count = 0;
    HashNode* node = sub_0060ACE0_GfxHashFind(&gHash_0088DB58, context, &index, &count, file);
    int result = 1;
    int loaded = 0;
    if (count > 1 && index > 0)
    {
        if (node)
        {
            if (!node->entry->pAsync)
                return 0;
            loaded = FOG_AsyncDataTestLoaded(node->entry->pAsync);
        }
        if (!node || !loaded)
        {
            if (!(file->flags & 1))
            {
                const unsigned int directions = file->directions;
                unsigned int frameDirection = (unsigned int)context->nDirection * directions;
                const int directionFlags = *(unsigned char*)&context->dwFlags & 4;
                frameDirection >>= 6;
                unsigned int direction = sub_00600CB0_ConvertDirection(frameDirection, directions, count, directionFlags);
                if (file->directions > 1)
                    direction = (direction << 6) / file->directions;
                else
                    direction = 1;
                context->nDirection = direction;
                node = sub_0060ACE0_GfxHashFind(&gHash_0088DB58, context, &index, &count, file);
            }
        }
    }
    if (node)
    {
        D2CmpSpriteEntryStrc* entry = node->entry;
        if (!entry || (*(unsigned char*)&entry->nFlags & 1) || !entry->pAsync)
            return 0;
        if (async)
            return FOG_AsyncDataTestLoaded(entry->pAsync) != 0;
        sub_005FF5B0_SpriteCacheTouchNode(&gCache_0089DB60, node->link);
        if (*(int*)((char*)entry + 0x28) == 0)
            sub_005FEC90_InitDC6Frames((D2CmpSpriteFileStrc*)file, context, entry);
        context->pFrame = sub_005FEC50_GetCachedDC6Frame(context, entry);
        if (!context->pFrame)
        {
            if (!gWarn_008ADBB0)
                gWarn_008ADBB0 = 1;
            return 0;
        }
        if (!loaded && !index && count > 1)
        {
            if (!path[0] && !sub_005FE610_BuildGfxPath(name, context, path))
                return 0;
            sub_006000B0_LoadConvertedEntry(index, count, name, flags, context, (D2CmpSpriteFileStrc*)file, path);
        }
    }
    else
    {
        if (async)
            return 0;
        if (!path[0] && !sub_005FE610_BuildGfxPath(name, context, path))
            return 0;
        result = sub_005FFE90_LoadDC6Entry((D2CmpSpriteFileStrc*)file, index, count, path, context);
        if (result)
            sub_006000B0_LoadConvertedEntry(index, count, name, flags, context, (D2CmpSpriteFileStrc*)file, path);
    }
    return result;
}
