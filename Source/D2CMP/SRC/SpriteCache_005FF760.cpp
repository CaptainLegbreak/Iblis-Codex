#include "D2CmpTypes.h"
#include "D2WinTypes.h"
// build: context SpriteCache_BuildDccOrDc6Path
// build: context SpriteCache_IsCompressible

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
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsync);                                                 // 0x0040A9E0

extern int gbCmpCompressedDataMode;                                                                         // 0x00741EFC
extern "C" const char gszFmtDcc4_006E3618[];                                                                // 0x006E3618
extern "C" const char gszFmtDc64_006E3608[];                                                                // 0x006E3608
extern "C" const char gszOverlaysDir_006E35F0[];                                                            // 0x006E35F0
extern "C" const char gszFmtDc62_006E35E4[];                                                                // 0x006E35E4
extern "C" const char gszFmtItemsDc6_006E35D4[];                                                            // 0x006E35D4
extern "C" const char gszMissilesDir_006E35BC[];                                                            // 0x006E35BC
extern "C" const char gszFmtDcc2_006E35B0[];                                                                // 0x006E35B0
extern "C" const char gszObjectsDir_006E3628[];                                                             // 0x006E3628
extern "C" const char gszNoCompressName_006E363C[];                                                         // 0x006E363C
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

// 0x005FEC90
static __declspec(noinline) void __stdcall sub_005FEC90_InitDC6Frames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    char szName[0x104];
    char szPath[0x104];

    D2_ASSERT(pContext, 0x50D);
    D2_ASSERT(pEntry, 0x50E);
    D2_ASSERT(!(pFile->dwFlags & 1), 0x50F);
    D2_ASSERT(!pEntry->unk0x28, 0x512);

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
AsyncData* __fastcall sub_0040A620(void* pMemPool, const char* szFileName, int bAllowAsync, long nFileOffset, int nFileSize, void* pBuffer, D2CmpLoadDescStrc* pAsyncOpDesc, int nPriority, const char* szFile, int nLine); // 0x0040A620
unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData); // 0x0040AA40
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

static __declspec(noinline) int __stdcall sub_005FF760_LoadDCCFrames(D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteEntryStrc* pEntry);

// 0x005FF760
static int __stdcall sub_005FF760_LoadDCCFrames(D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteEntryStrc* pEntry)
{
    char szGfxName[0x104];
    char szGfxPath[0x104];

    if (!pFile || !pEntry || !pContext)
    {
        return 0;
    }

    int nStart;
    int nEnd;
    if ((pContext->nType == 6 && (pContext->dwFlags & 2)) || pContext->nType == 3)
    {
        if (nFrames != 1)
        {
            return 0;
        }

        nStart = sub_00600C90_GetDirectionIndex64(pContext->nDirection, pFile->nDirections);
        nEnd = nStart + 1;
    }
    else if (pContext->nType == 2)
    {
        nStart = 0;
        nEnd = 1;
    }
    else if (pContext->nType == 4)
    {
        nStart = pContext->nDirection;
        nEnd = nStart + 1;
    }
    else
    {
        if (pContext->nType == 1 && nFrames == 1)
        {
            nStart = sub_00600C90_GetDirectionIndex64(pContext->nDirection, pFile->nDirections);
        }
        else
        {
            nStart = nDirection * nFrames;
        }
        nEnd = nStart + nFrames;
    }

    int nSize = pFile->aOffsets[nEnd] - pFile->aOffsets[nStart];
    if (!nSize)
    {
        sub_005FE2B0_BuildGfxName(pContext, szGfxName);
        sub_005FE610_BuildGfxPath(szGfxName, pContext, szGfxPath);
        return 0;
    }

    if (pEntry->pAsync)
    {
        return 0;
    }

    unsigned char nFrameCount = (unsigned char)nFrames;
    unsigned char nFirstFrame = (unsigned char)nDirection;
    nFirstFrame *= nFrameCount;
    pEntry->nFrames = nFrameCount;
    pEntry->nFirstFrame = nFirstFrame;
    pEntry->nFramesPerDirection = (unsigned char)pFile->nFramesPerDirection;
    pEntry->nDirections = (unsigned char)pFile->nDirections + 1;

    const unsigned int nBase = pFile->aOffsets[nStart];
    for (unsigned int i = nStart; i <= (unsigned int)nEnd; ++i)
    {
        D2_ASSERT(i < 0x21, 0x34C);
        pEntry->aOffsets[i] = pFile->aOffsets[i] - nBase;
        D2_ASSERT(pEntry->aOffsets[i] >= 0, 0x34E);
    }

    if (pFile->dwFlags & 2)
    {
        D2CmpLoadDescStrc tDesc;
        memset(&tDesc, 0, sizeof(tDesc));
        tDesc.pfnCallback = (void*)sub_005FF6E0_SpriteLoadCallback;
        tDesc.pFile = pFile;
        tDesc.pFlags = &pEntry->nFlags;
        tDesc.nFirstFrame = nDirection * nFrames;
        tDesc.nFrames = nFrames;
        pEntry->nFlags |= 4;
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 0, pFile->aOffsets[nStart], nSize, 0, &tDesc, -2, gszSpriteCacheSourceFile, 0x369);
        nSize = FOG_AsyncDataGetBufferSize(pEntry->pAsync);
    }
    else
    {
        pEntry->pAsync = sub_0040A620(gCmpTileCache.pMemPool, szName, 0, pFile->aOffsets[nStart], nSize, 0, 0, -2, gszSpriteCacheSourceFile, 0x379);
    }

    D2_ASSERT(pEntry->pAsync, 0x37D);
    return nSize;
}

// 0x005FFE90
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
        sub_005FF760_LoadDCCFrames(pContext, nArg2, nArg3, szName, pFile, pEntry);
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

// build: context sub_005FFE90_Shim
// calling-convention shim (not game code)
int __stdcall sub_005FFE90_Shim(D2CmpSpriteFileStrc* pFile, int nArg2, int nArg3, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    return sub_005FFE90_LoadDC6Entry(pFile, nArg2, nArg3, szName, pContext);
}
