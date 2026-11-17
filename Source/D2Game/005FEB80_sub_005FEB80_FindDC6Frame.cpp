struct T00481720;

void* __fastcall sub_0040A9E0(T00481720* pAsync);                                                     // 0x0040A9E0
int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections);                   // 0x00600C90

struct D2CmpSpriteContextStrc
{
    int nFrame;
    unsigned int dwFlags;
    int nType;
    char unk0x0C[0x24];
    int nFrames;
    char unk0x34[0x08];
    void* pFrame;
    int nDirection;
};

struct D2CmpDC6HeaderStrc
{
    char unk0x00[3];
    unsigned char nDirections;
    unsigned char nFrames;
    char unk0x05[7];
    int aOffsets[1];
    char unk0x10[0x80];
    T00481720* pAsync;
};

struct D2CmpDC6CacheEntryStrc
{
    char unk0x00[0x20];
    D2CmpDC6HeaderStrc tHeader;
};

struct D2CmpDC6FrameStrc
{
    int f_0;
    unsigned int nWidth;
    unsigned int nHeight;
    char unk0x0C[0x08];
    int nOffsetY;
    char unk0x18[0x04];
    int nLength;
};

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
        nIndex = sub_00600C90_GetDirectionIndex64(pContext->nDirection, pHeader->nDirections - 1);
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
        nIndex = sub_00600C90_GetDirectionIndex64(pContext->nDirection, pHeader->nDirections - 1);
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
        if (pFrame->f_0 != 0)
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

        nOffset += pFrame->nLength + pFrame->nOffsetY + 0x23;
        if (nOffset < 0)
        {
            return 0;
        }
    }

    return pFrame;
}

// 0x005FEC50
static __declspec(noinline) void* sub_005FEC50_GetCachedDC6Frame(D2CmpSpriteContextStrc* pContext, D2CmpDC6CacheEntryStrc* pEntry)
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
