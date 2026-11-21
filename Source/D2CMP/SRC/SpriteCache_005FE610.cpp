#include "D2CmpTypes.h"
#include "D2CMP.h"
#include "D2WinTypes.h"
#include "D2CmpCache.h"

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

struct AsyncData;

void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsync);                                                 // 0x0040A9E0

extern int gbCmpCompressedDataMode;                                                                         // 0x00741EFC

extern "C" const char gszFmtDcc4_006E3618[];

extern "C" const char gszFmtDc64_006E3608[];

extern "C" const char gszOverlaysDir_006E35F0[];

extern "C" const char gszFmtDc62_006E35E4[];

extern "C" const char gszFmtItemsDc6_006E35D4[];                                                            // 0x006E35D4

extern "C" const char gszMissilesDir_006E35BC[];

extern "C" const char gszFmtDcc2_006E35B0[];

extern "C" const char gszObjectsDir_006E3628[];

extern "C" const char gszNoCompressName_006E363C[];

extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118

extern D2SpriteCacheStrc gCmpTileCache;                                                                     // 0x0089DB60

struct D2CmpDC6CelStrc { char unk0x00[0x2C]; };

#define APPEND_CODE(q, dw) \
    if ((char)(dw) != 0x20) { *q++ = (char)(dw); \
        if ((char)((dw) >> 8) != 0x20) { *q++ = (char)((dw) >> 8); \
            if ((char)((dw) >> 16) != 0x20) { *q++ = (char)((dw) >> 16); } } }

struct D2SpriteCacheNodeStrc;

struct D2SpriteCacheStrc;

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection); // 0x006CC214

static D2SpriteCacheNodeStrc* __stdcall sub_005FF0F0_SpriteCachePopHead(int bLocked, D2SpriteCacheStrc* pCache); // 0x005FF0F0

static void sub_005FF1B0_SpriteCacheUnlinkNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode); // 0x005FF1B0

D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked); // 0x005FF4A0

static __declspec(noinline) void __stdcall sub_005FEC90_InitDC6Frames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry); // 0x005FEC90

struct D2CmpBlockTableBStrc;

struct D2CmpGfxHashEntryStrc;



static int __stdcall sub_005FE610_BuildGfxPath(const char* szName, D2CmpSpriteContextStrc* pContext, char* szOut);

D2SpriteCacheNodeStrc* __fastcall sub_005FFC40_SpriteCacheAlloc(D2SpriteCacheStrc* pCache, unsigned int nSize, unsigned int nKey, int bLocked); // 0x005FFC40

struct D2SpriteLoadRequestStrc;

AsyncData* __fastcall sub_0040A620(void* hArchive, const char* szFileName, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8, const char* szFile, int nLine); // 0x0040A620

unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData); // 0x0040AA40

int __stdcall sub_005FF6E0_SpriteLoadCallback(void* hArg, int nArg, D2SpriteLoadRequestStrc* pRequest);    // 0x005FF6E0

extern D2CmpBlockTableBStrc gCmpBlockTableB;                                                                // 0x0088DB58

int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections);                   // 0x00600C90

D2CmpGfxHashEntryStrc* __fastcall sub_0060ADC0_GfxHashAdd(void* pMemPool, D2CmpBlockTableBStrc* pHash, D2CmpSpriteEntryStrc* pEntry, D2CmpSpriteContextStrc* pContext, D2CmpSpriteFileStrc* pFile); // 0x0060ADC0

__declspec(noinline) static void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry);

static __declspec(noinline) int __fastcall sub_005FF760_LoadDCCFrames(const char* szName, D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, int nDirection, int nFrames, D2CmpSpriteEntryStrc* pEntry);

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

// build: context sub_005FE2B0_BuildGfxName
static __declspec(noinline) int sub_005FE2B0_BuildGfxName(D2CmpSpriteContextStrc* pContext, char* szOut)
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

static __forceinline int SpriteCache_FlatPath(char* szOut, const char* szDir, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    if (gbCmpCompressedDataMode)
    {
        wsprintfA(szOut, "%s\\%s.dcc", szDir, szName);
        pContext->dwGfxFlags |= 1;
    }
    else
    {
        wsprintfA(szOut, "%s\\%s.dc6", szDir, szName);
    }
    return 1;
}

// 0x005FE610
static __declspec(noinline) int __stdcall sub_005FE610_BuildGfxPath(const char* szName, D2CmpSpriteContextStrc* pContext, char* szOut)
{
    if (!*szName)
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
        return SpriteCache_FlatPath(szOut, "DATA\\GLOBAL\\MISSILES", pContext->pName, pContext);

    case 4:
    {
        if (!pContext->pName)
        {
            break;
        }
        const int nMode = pContext->nMode;
        if (nMode == 4)
        {

            if (pContext->dwFlags & 2)
            {
                wsprintfA(szOut, gszFmtItemsDc6_006E35D4, "DATA\\GLOBAL", szName);
                return 1;
            }
            wsprintfA(szOut, gszFmtItemsDc6_006E35D4, "DATA\\GLOBAL", szName);
            return 1;
        }
        if (nMode == 3)
        {
            wsprintfA(szOut, "%s\\items\\%s.dc6", "DATA\\GLOBAL", szName);
            return 1;
        }
        break;
    }

    case 6:
        if (!(pContext->dwFlags & 2))
        {
            break;
        }
        if (pContext->nOverlay == 0x7A)
        {
            wsprintfA(szOut, "%s\\%s.dc6", "DATA\\GLOBAL\\OVERLAYS", szName);
            return 1;
        }
        return SpriteCache_FlatPath(szOut, "DATA\\GLOBAL\\OVERLAYS", szName, pContext);

    default:
    {
        int bDcc = gbCmpCompressedDataMode;
        if (bDcc && !SStrCmpI(szName, "OYTRlitTNhth", 0x7FFFFFFF))
        {
            bDcc = 0;
            pContext->dwGfxFlags &= ~1;
        }

        const char* szDir;
        switch (pContext->nType)
        {
        case 0:
            szDir = "DATA\\GLOBAL\\CHARS";
            break;

        case 1:
            szDir = "DATA\\GLOBAL\\MONSTERS";
            switch (pContext->nIndex)
            {
            case 0xF3: case 0x11C: case 0x14D: case 0x220: case 0x22F: case 0x23A: case 0x2C1: case 0x2C5:
                if (!pContext->nMode)
                {
                    bDcc = 0;
                }
                break;

            case 0xF2: case 0xFB: case 0x16F: case 0x209: case 0x2C0:
                bDcc = 0;
                break;
            }
            break;

        case 2:
            if (pContext->nIndex == 0x156 || pContext->nIndex == 0x233)
            {
                bDcc = 0;
            }
            szDir = "DATA\\GLOBAL\\OBJECTS";
            break;

        default:
            goto Fail;
        }

        char szToken[4];
        char szComponent[4];
        szToken[3] = 0;
        szComponent[3] = 0;
        szToken[0] = pContext->szToken[0] == ' ' ? 0 : pContext->szToken[0];
        szToken[1] = pContext->szToken[1] == ' ' ? 0 : pContext->szToken[1];
        szToken[2] = pContext->szToken[2] == ' ' ? 0 : pContext->szToken[2];
        szComponent[0] = pContext->szComponent[0] == ' ' ? 0 : pContext->szComponent[0];
        szComponent[1] = pContext->szComponent[1] == ' ' ? 0 : pContext->szComponent[1];
        szComponent[2] = pContext->szComponent[2] == ' ' ? 0 : pContext->szComponent[2];

        if (bDcc)
        {
            wsprintfA(szOut, "%s\\%s\\%s\\%s.dcc", szDir, szToken, szComponent, szName);
            pContext->dwGfxFlags |= 1;
        }
        else
        {
            wsprintfA(szOut, "%s\\%s\\%s\\%s.dc6", szDir, szToken, szComponent, szName);
        }
        return 1;
    }
    }

Fail:
    *szOut = 0;
    return 0;
}

// build: context sub_005FEC90_InitDC6Frames
static __declspec(noinline) void __stdcall sub_005FEC90_InitDC6Frames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    char szName[0x104];
    char szPath[0x104];

    D2_ASSERT(pContext, 0x50D);
    D2_ASSERT(pEntry, 0x50E);
    D2_ASSERT(!(pFile->dwFlags & 1), 0x50F);
    D2_ASSERT(!pEntry->unk0x28, 0x512);

    const int nSize = pEntry->nFrames * pEntry->nFramesPerDirection * sizeof(D2CmpDC6CelStrc);
    D2CmpDC6CelStrc* pCels = (D2CmpDC6CelStrc*)FOG_AllocPool(gCmpTileCache.pMemPool, nSize, ".\\SRC\\SpriteCache.cpp", 0x517, 0);
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

// build: context sub_M320_Emit_005FEC90
void __stdcall sub_M320_Emit_005FEC90(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    sub_005FEC90_InitDC6Frames(pFile, pContext, pEntry);
}

// 0x005FF0F0
static D2SpriteCacheNodeStrc* __stdcall sub_005FF0F0_SpriteCachePopHead(int bLocked, D2SpriteCacheStrc* pCache)
{
    D2SpriteCacheNodeStrc* pNode = 0;
    if (bLocked)
    {
        if (!pCache->pHeadB)
            return 0;
        pNode = pCache->pHeadB;
        if (pNode->dwFlags & 2)
            return 0;
        pCache->pHeadB = pCache->pHeadB->pNext;
        if (pCache->pHeadB)
            pCache->pHeadB->pPrev = 0;
        else
            pCache->pTailB = 0;
    }
    else
    {
        if (!pCache->pHeadA)
            return 0;
        pNode = pCache->pHeadA;
        if (pNode->dwFlags & 2)
            return 0;
        pCache->pHeadA = pCache->pHeadA->pNext;
        if (pCache->pHeadA)
            pCache->pHeadA->pPrev = 0;
        else
            pCache->pTailA = 0;
    }
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

D2SpriteCacheNodeStrc* __fastcall sub_005FF4A0_SpriteCachePurge(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode, int bLocked)
{
    if (!pCache->nCount)
    {
        return 0;
    }
    if (!pNode)
    {
        if (!pCache->pHeadB)
        {
            pNode = sub_005FF0F0_SpriteCachePopHead(0, pCache);
        }
        else
        {
            if (!pCache->pHeadA)
            {
                pNode = sub_005FF0F0_SpriteCachePopHead(bLocked, pCache);
            }
            else if (bLocked)
            {
                pNode = sub_005FF0F0_SpriteCachePopHead(pCache->pHeadB->dwTick < pCache->pHeadA->dwTick, pCache);
            }
            else
            {
                pNode = sub_005FF0F0_SpriteCachePopHead(0, pCache);
            }
        }
        if (!pNode)
        {
            return 0;
        }
        if (pNode->dwFlags & 2)
        {
            return 0;
        }
    }
    else
    {
        if (pNode->dwFlags & 2)
        {
            return 0;
        }
        sub_005FF1B0_SpriteCacheUnlinkNode(pCache, pNode);
    }
    EnterCriticalSection(&pCache->tLock);
    pCache->nTotalSize -= pNode->nSize;
    LeaveCriticalSection(&pCache->tLock);
    if (pNode->nKey)
    {
        ((D2SpriteCacheFreeFn)pCache->nArg)(pNode->nKey);
        pNode->nKey = 0;
    }
    if (pNode->pData)
    {
        FOG_FreePool(pCache->pMemPool, pNode->pData, gszSpriteCacheSourceFile, 0x9E8, 0);
        pNode->pData = 0;
    }
    if (!pCache->f_28)
    {
        pCache->nCount -= 1;
        pCache->f_24 = pNode;
        pCache->f_28 = pNode;
    }
    else
    {
        pCache->f_28->pNext = pNode;
        pNode->pPrev = pCache->f_28;
        pCache->nCount -= 1;
        pCache->f_28 = pNode;
    }
    return pNode;
}

// 0x005FF1B0
static void sub_005FF1B0_SpriteCacheUnlinkNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* ptBlock)
{
    D2_ASSERT(ptBlock, 0xAFC);
    if (ptBlock->dwFlags & 1)
    {
        if (!pCache->pHeadB)
        {
            return;
        }
        if (ptBlock == pCache->pHeadB)
        {
            sub_005FF0F0_SpriteCachePopHead(1, pCache);
            return;
        }
        if (ptBlock == pCache->pTailB)
        {
            pCache->pTailB = pCache->pTailB->pPrev;
            pCache->pTailB->pNext = 0;
        }
        else
        {
            if (!ptBlock->pPrev && !ptBlock->pNext)
            {
                return;
            }
            ptBlock->pPrev->pNext = ptBlock->pNext;
            ptBlock->pNext->pPrev = ptBlock->pPrev;
        }
    }
    else
    {
        if (!pCache->pHeadA)
        {
            return;
        }
        if (ptBlock == pCache->pHeadA)
        {
            sub_005FF0F0_SpriteCachePopHead(0, pCache);
            return;
        }
        if (ptBlock == pCache->pTailA)
        {
            pCache->pTailA = pCache->pTailA->pPrev;
            pCache->pTailA->pNext = 0;
        }
        else
        {
            if (!ptBlock->pPrev && !ptBlock->pNext)
            {
                return;
            }
            ptBlock->pPrev->pNext = ptBlock->pNext;
            ptBlock->pNext->pPrev = ptBlock->pPrev;
        }
    }
    ptBlock->pNext = 0;
    ptBlock->pPrev = 0;
}

void __fastcall sub_005FF5B0_SpriteCacheTouchNode(D2SpriteCacheStrc* pCache, D2SpriteCacheNodeStrc* pNode)
{
    if (!pCache->nCount)
    {
        return;
    }
    pCache->f_4C += 1;
    EnterCriticalSection(&pCache->tLock);
    D2_ASSERT(pNode, 0xA10);
    sub_005FF1B0_SpriteCacheUnlinkNode(pCache, pNode);
    pNode->dwFlags &= ~1;
    if (!pCache->pTailA)
    {
        pCache->pHeadA = pNode;
    }
    else
    {
        pCache->pTailA->pNext = pNode;
        pNode->pPrev = pCache->pTailA;
    }
    pCache->pTailA = pNode;
    pNode->dwTick = GetTickCount();
    LeaveCriticalSection(&pCache->tLock);
}

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

int __stdcall sub_Emit_005FFE90(D2CmpSpriteFileStrc* pFile, int nArg2, int nArg3, const char* szName, D2CmpSpriteContextStrc* pContext)
{
    return sub_005FFE90_LoadDC6Entry(pFile, nArg2, nArg3, szName, pContext);
}
