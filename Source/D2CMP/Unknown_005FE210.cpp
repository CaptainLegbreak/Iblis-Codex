#include "D2CMP.h"

#include "D2CmpTypes.h"
#include "D2CmpDC6CacheEntry.h"

struct Config;

struct D2CmpSpriteContextStrc;

struct D2CmpDC6HeaderStrc;

struct D2CmpDC6CacheEntryStrc;

struct D2CmpDC6FrameStrc;

typedef char* va_list;

extern "C" int __cdecl vsprintf(char*,const char*,va_list);

extern "C" char* __cdecl strcat(char*,const char*);

struct Config { int enabled; const char* compressed; const char* standard; };

extern Config extensions; // 0x00741EFC

enum { DISABLED = 0 };

void* __fastcall sub_0040A9E0(AsyncData* pAsync); // 0x0040A9E0

int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections); // 0x00600C90


// 0x005FEB80
static void* __stdcall sub_005FEB80_FindDC6Frame(void* pData, D2CmpSpriteContextStrc* pContext, D2CmpDC6HeaderStrc* pHeader)
{
    if (!pData)
    {
        return 0;
    }

    if (!pHeader)
    {
        return 0;
    }

    if ((unsigned int)pContext->nFrame >= pHeader->nFrames)
    {
        return 0;
    }

    int nIndex;
    D2CmpDC6FrameStrc* pFrame = (D2CmpDC6FrameStrc*)pData;
    if (pContext->nType == 6 && (pContext->dwFlags & 2))
    {
        nIndex = CelGameDirToFileDir(pContext->nDirection, pHeader->nDirections - 1);
    }
    else if (pContext->nType == 2)
    {
        nIndex = 0;
    }
    else if (pContext->nType == 4)
    {
        nIndex = pContext->nDirection;
    }
    else
    {
        nIndex = CelGameDirToFileDir(pContext->nDirection, pHeader->nDirections - 1);
    }

    if (nIndex >= pHeader->nDirections - 1)
    {
        return 0;
    }

    int nOffset = pHeader->aOffsets[nIndex];
    if (nOffset < 0)
    {
        return 0;
    }

    const int nFrame = pContext->nFrame;
    for (int i = 0; i <= nFrame; ++i)
    {
        pFrame = (D2CmpDC6FrameStrc*)((char*)pData + nOffset);
        if (pFrame->nFlip != 0)
        {
            return 0;
        }

        if (pFrame->nWidth > 0x100)
        {
            return 0;
        }

        if (pFrame->nHeight > 0x100)
        {
            return 0;
        }

        nOffset += pFrame->nLength + pFrame->nOffsetY_14 + 0x23;
        if (nOffset < 0)
        {
            return 0;
        }
    }

    return pFrame;
}

// 0x005FEC50
static void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpDC6CacheEntryStrc* pEntry)
{
    if (pEntry && pEntry->tHeader.pAsync)
    {
        D2CmpDC6HeaderStrc* pHeader = &pEntry->tHeader;
        void* pData = sub_0040A9E0(pHeader->pAsync);
        if (pData)
        {
            pContext->nFrames = pHeader->nFrames;
            return sub_005FEB80_FindDC6Frame(pData, pContext, pHeader);
        }

        return 0;
    }

    return 0;
}

void __stdcall sub_P04_Emit_005FEC50(D2CmpSpriteContextStrc* pContext, D2CmpDC6CacheEntryStrc* pEntry)
{
    pContext->pFrame = sub_005FEC50_GetCachedDC6Frame(pContext, pEntry);
}
