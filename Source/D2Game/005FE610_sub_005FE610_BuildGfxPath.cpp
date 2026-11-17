extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
#pragma intrinsic(strcpy)

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
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
    char unk0x30[0x14];
    unsigned int dwGfxFlags;
};

struct D2CmpSpriteFileStrc { unsigned int dwFlags; };

struct D2CmpDC6CelStrc { char unk0x00[0x2C]; };

struct D2CmpSpriteEntryStrc
{
    char unk0x00[0x21];
    unsigned char nFrames;
    unsigned char nFirstFrame;
    char unk0x23;
    unsigned char nFramesPerDirection;
    char unk0x25[3];
    int f_28;
    int aOffsets[0x21];
    AsyncData* pAsync;
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

static __declspec(noinline) void __stdcall sub_005FEC90_InitDC6Frames(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry); // 0x005FEC90

// build: context sub_005FEC90_InitDC6Frames
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

// build: context sub_M320_Emit_005FEC90
void __stdcall sub_M320_Emit_005FEC90(D2CmpSpriteFileStrc* pFile, D2CmpSpriteContextStrc* pContext, D2CmpSpriteEntryStrc* pEntry)
{
    sub_005FEC90_InitDC6Frames(pFile, pContext, pEntry);
}
