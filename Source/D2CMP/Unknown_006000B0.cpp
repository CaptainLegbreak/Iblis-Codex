#include "D2CmpTypes.h"
#include "D2WinTypes.h"
struct AsyncData;
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

struct D2CmpDC6CelStrc { char unk0x00[0x2C]; };

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

static __forceinline int SpriteCache_CopyName(char* szDst, const char* szSrc)
{
    strcpy(szDst, szSrc);
    return 1;
}

static int sub_005FE2B0_BuildGfxName(D2CmpSpriteContextStrc* pContext, char* szOut)
{
    switch (pContext->nType)
    {
    case 4:
        if (!pContext->pName)
        {
            break;
        }
        return SpriteCache_CopyName(szOut, pContext->pName);

    case 3:
        if (!pContext->pName)
        {
            break;
        }
        if (gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        return SpriteCache_CopyName(szOut, pContext->pName);

    case 6:
        if (!(pContext->dwFlags & 2))
        {
            break;
        }
        if (!pContext->pName)
        {
            break;
        }
        if (pContext->nOverlay != 0x7A && gbCmpCompressedDataMode)
        {
            pContext->dwGfxFlags |= 1;
        }
        return SpriteCache_CopyName(szOut, pContext->pName);

    case 0:
    case 1:
    case 2:
    {
        unsigned int dw;
        dw = pContext->dwName[0]; APPEND_CODE(szOut, dw);
        dw = pContext->dwName[1]; APPEND_CODE(szOut, dw);
        dw = pContext->dwName[2]; APPEND_CODE(szOut, dw);
        dw = pContext->dwName[3]; APPEND_CODE(szOut, dw);
        dw = pContext->dwName[4]; APPEND_CODE(szOut, dw);
        *szOut = 0;

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

static int __stdcall sub_005FE610_BuildGfxPath(const char* szName, D2CmpSpriteContextStrc* pContext, char* szOut)
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
            break;
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

static void __stdcall sub_005FEC90_InitDC6Frames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry);
static void __stdcall sub_005FEC90_InitDC6Frames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    char szName[0x104];
    char szPath[0x104];

    D2_ASSERT(pContext, 0x50D);
    D2_ASSERT(pEntry, 0x50E);
    D2_ASSERT(!(pFile->dwFlags & 1), 0x50F);
    D2_ASSERT(!pEntry->unk0x28, 0x512);
    D2_ASSERT(pEntry->nFrames, 0x513);
    D2_ASSERT(pEntry->nFramesPerDirection, 0x514);
    D2_ASSERT(pEntry->pAsync, 0x515);

    const int nSize = pEntry->nFrames * pEntry->nFramesPerDirection * sizeof(D2CmpDC6CelStrc);
    D2CmpDC6CelStrc* pCels = (D2CmpDC6CelStrc*)FOG_AllocPool(gCmpTileCache.pMemPool, nSize, gszSpriteCacheSourceFile, 0x517, 0);
    memset(pCels, 0, nSize);

    char* pData = (char*)FOG_AsyncDataGetBuffer(pEntry->pAsync);
    D2_ASSERT(pData, 0x524);

    int nOffset = pEntry->aOffsets[pEntry->nFirstFrame];
    D2CmpDC6FrameStrc* pFrame;
    for (unsigned int i = 0; i < (unsigned int)(pEntry->nFrames * pEntry->nFramesPerDirection); ++i, nOffset += pFrame->nLength + pFrame->nOffsetY_14 + 0x23)
    {
        pFrame = (D2CmpDC6FrameStrc*)(pData + nOffset);
        if (pFrame->unk0x00 != 0 || pFrame->nWidth > 0x100 || pFrame->nHeight > 0x100)
        {
            sub_005FE2B0_BuildGfxName(pContext, szName);
            sub_005FE610_BuildGfxPath(szName, pContext, szPath);
            D2_ASSERT(0, 0x58C);
        }

        pFrame->pCel = &pCels[i];
    }

    pEntry->unk0x28 = 1;
}


D2SpriteCacheNodeStrc* __fastcall sub_005FFC40_SpriteCacheAlloc(D2SpriteCacheStrc* pCache, unsigned int nSize, unsigned int nKey, int bLocked); // 0x005FFC40

struct D2SpriteLoadRequestStrc;
AsyncData* __fastcall sub_0040A620(void* hArchive, const char* szFileName, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8, const char* szFile, int nLine); // 0x0040A620
unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData); // 0x0040AA40
int __stdcall sub_005FF6E0_SpriteLoadCallback(void* hArg, int nArg, D2SpriteLoadRequestStrc* pRequest);    // 0x005FF6E0

extern D2CmpBlockTableBStrc gCmpBlockTableB;                                                                // 0x0088DB58

int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections);                   // 0x00600C90
D2CmpGfxHashEntryStrc* __fastcall sub_0060ADC0_GfxHashAdd(void* pMemPool, D2CmpBlockTableBStrc* pHash, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile); // 0x0060ADC0

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
        if (pFrame->unk0x00 != 0)
            return 0;
        if (pFrame->nWidth > 0x100)
            return 0;
        if (pFrame->nHeight > 0x100)
            return 0;
        nOffset += pFrame->nLength + pFrame->nOffsetY_14 + 0x23;
        if (nOffset < 0)
            return 0;
    }

    return pFrame;
}

static void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry);
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

static int __fastcall sub_005FF760_LoadDCCFrames(const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, D2CmpSpriteEntryStrc* pEntry);

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
        pEntry->nFlags += (unsigned char)FOG_AsyncDataGetBufferSize((AsyncData*)pOffset);
    }

    FOG_AsyncDataGetBufferSize((AsyncData*)&pContext);
    FOG_AsyncDataGetBufferSize((AsyncData*)&nDirection);
    FOG_AsyncDataGetBufferSize((AsyncData*)&nFrames);
    return pEntry->nFlags;
}

static int __stdcall sub_005FFE90_LoadDC6Entry(D2CmpSpriteFileStrc* pFile, int nArg2, int nArg3, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    if (!pFile)
        return 0;

    D2SpriteCacheNodeStrc* pHolder = sub_005FFC40_SpriteCacheAlloc(&gCmpTileCache, sizeof(D2CmpSpriteEntryStrc), 0, 0);
    if (!pHolder)
        return 0;

    D2CmpSpriteEntryStrc* pEntry = pHolder->pEntry;
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

    D2CmpGfxHashEntryStrc* pRecord = sub_0060ADC0_GfxHashAdd(gCmpTileCache.pMemPool, &gCmpBlockTableB, pHolder->pEntry, pContext, pFile);
    D2_ASSERT(pRecord, 0x5D1);
    pHolder->pRecord = pRecord;
    pRecord->pHolder = pHolder;
    if (pFile->dwFlags & 1)
    {
        pEntry->nFlags |= 1;
        return 0;
    }

    if (!pEntry->unk0x28)
        sub_005FEC90_InitDC6Frames(pFile, pContext, pEntry);

    pContext->pFrame = sub_005FEC50_GetCachedDC6Frame(pContext, pEntry);
    return pContext->pFrame != 0;
}

D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0
void __fastcall sub_005FF630_ResizeCacheEntry(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int nDelta, int nArg); // 0x005FF630
int __stdcall sub_00600D30_CanConvertDirections(int nDirections, int nNewDirections); // 0x00600D30
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

static int __stdcall sub_005FFFA0_LoadDC6CacheEntry(D2CmpSpriteFileStrc* pFile, int nDirection, int nFrames, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    D2SpriteCacheNodeStrc* pHolder = sub_005FFC40_SpriteCacheAlloc(&gCmpTileCache, sizeof(D2CmpSpriteEntryStrc), 0, 1);
    if (pHolder)
    {
        D2CmpSpriteEntryStrc* pEntry = pHolder->pEntry;
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
            D2CmpGfxHashEntryStrc* pRecord = sub_0060ADC0_GfxHashAdd(gCmpTileCache.pMemPool, &gCmpBlockTableB, pHolder->pEntry, pContext, pFile);
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

void __stdcall sub_Emit_006000B0(int nDirection, unsigned int nFrames, char* szName, int bDC6, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile, char* szPath)
{
    sub_006000B0_LoadConvertedEntry(nDirection, nFrames, szName, bDC6, pContext, pFile, szPath);
}
