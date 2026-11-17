struct D2BitOutputStrc
{
    int f_0;
    int nCodeMask;
    int nInitialCodeWidth;
    int nBits;
    int nBitCount;
    int unknown14[2];
    int nClearCode;
    int unknown20;
    int nNextCode;
    void* f_28;
    int unknown2C;
    int nBlockLength;
    unsigned char pBlock[256];
};
void __stdcall sub_0041D2A0_CopyBytes(void*, const void*, unsigned int); // 0x0041D2A0
static __declspec(noinline) void sub_006C5A60_FlushBlock(D2BitOutputStrc*, unsigned char**);

static void sub_006C5A60_FlushBlock(D2BitOutputStrc* pState, unsigned char** ppOutput)
{
    if (pState->nBlockLength)
    {
        pState->pBlock[0] = (unsigned char)pState->nBlockLength;
        ++pState->nBlockLength;
        sub_0041D2A0_CopyBytes(*ppOutput, pState->pBlock, pState->nBlockLength);
        *ppOutput += pState->nBlockLength;
        pState->nBlockLength = 0;
    }
}

static __declspec(noinline) void __fastcall sub_006C5A90_EmitCode(D2BitOutputStrc*, unsigned char**, int);

static void __fastcall sub_006C5A90_EmitCode(D2BitOutputStrc* pState, unsigned char** ppOutput, int nCode)
{
    pState->nBits |= nCode << pState->nBitCount;
    pState->nBitCount += pState->f_0;
    while (pState->nBitCount >= 8)
    {
        ++pState->nBlockLength;
        pState->pBlock[pState->nBlockLength] = (unsigned char)pState->nBits;
        if (pState->nBlockLength >= 255)
            sub_006C5A60_FlushBlock(pState, ppOutput);
        pState->nBits >>= 8;
        pState->nBitCount -= 8;
    }
    if (pState->nNextCode > pState->nCodeMask)
    {
        ++pState->f_0;
        pState->nCodeMask = pState->f_0 == 12 ? 4096 : (1 << pState->f_0) - 1;
    }
}

void __stdcall sub_0041D300_ZeroBytes(void*, unsigned int); // 0x0041D300
static __declspec(noinline) void __stdcall sub_006C6330_ResetDictionary(unsigned char**, D2BitOutputStrc*);

static void __stdcall sub_006C6330_ResetDictionary(unsigned char** ppOutput, D2BitOutputStrc* pState)
{
    sub_0041D300_ZeroBytes(pState->f_28, 0x4E2C);
    int nCode = pState->nClearCode;
    pState->nNextCode = nCode + 2;
    sub_006C5A90_EmitCode(pState, ppOutput, nCode);
    int nWidth = pState->nInitialCodeWidth;
    pState->f_0 = nWidth;
    pState->nCodeMask = (1 << nWidth) - 1;
}

__declspec(noinline) static void __stdcall sub_006C6370_AddChar(unsigned char** ppOutput, int nChar, D2BitOutputStrc* pState);

static void __stdcall sub_006C6370_AddChar(unsigned char** ppOutput, int nChar, D2BitOutputStrc* pState)
{
    if (pState->unknown14[1])
    {
        pState->unknown14[0] = nChar;
        pState->unknown14[1] = 0;
        return;
    }

    const int nPrefix = pState->unknown14[0];
    int nIndex = (nChar << 4) + nPrefix;
    if (nIndex >= 5003)
    {
        nIndex -= 5003;
    }

    const int nKey = (nPrefix << 8) | nChar;
    if (((int*)pState->f_28)[nIndex])
    {
        if (((int*)pState->unknown2C)[nIndex] == nKey)
        {
            nChar = ((int*)pState->f_28)[nIndex];
            goto lSetPrefix;
        }

        const int nStep = !nIndex ? 1 : 5003 - nIndex;
        do
        {
            nIndex -= nStep;
            if (nIndex < 0)
            {
                nIndex += 5003;
            }

            if (!((int*)pState->f_28)[nIndex])
            {
                goto lNotFound;
            }
        }
        while (((int*)pState->unknown2C)[nIndex] != nKey);

        pState->unknown14[0] = ((int*)pState->f_28)[nIndex];
        return;
    }

lNotFound:
    sub_006C5A90_EmitCode(pState, ppOutput, pState->unknown14[0]);
    if (pState->nNextCode < 4096)
    {
        ((int*)pState->f_28)[nIndex] = pState->nNextCode;
        ++pState->nNextCode;
        ((int*)pState->unknown2C)[nIndex] = nKey;
        pState->unknown14[0] = nChar;
        return;
    }

    sub_006C6330_ResetDictionary(ppOutput, pState);

lSetPrefix:
    pState->unknown14[0] = nChar;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                   // 0x00412650

// 0x006C6470
int __fastcall sub_006C6470_CompressLzw(int nSize, const unsigned char* pData, unsigned char* pOutput)
{
    int nCount = nSize;
    const unsigned char* pIn = pData;
    unsigned char* pStart = pOutput;
    D2BitOutputStrc tState;
    sub_0041D300_ZeroBytes(&tState, sizeof(tState));
    tState.f_0 = 9;
    tState.nInitialCodeWidth = 9;
    tState.nCodeMask = 0x1FF;
    tState.nClearCode = 0x100;
    tState.unknown20 = 0x101;
    tState.nNextCode = 0x102;
    tState.unknown14[1] = 1;
    tState.f_28 = SMemAlloc(0x4E2C, ".\\SOURCE\\SBMP.CPP", 0x388, 8);
    tState.unknown2C = (int)SMemAlloc(0x4E2C, ".\\SOURCE\\SBMP.CPP", 0x389, 8);
    sub_006C5A90_EmitCode(&tState, &pOutput, tState.nClearCode);

    while (nCount)
    {
        --nCount;
        sub_006C6370_AddChar(&pOutput, *pIn, &tState);
        ++pIn;
    }

    if (!tState.unknown14[1])
    {
        sub_006C5A90_EmitCode(&tState, &pOutput, tState.unknown14[0]);
    }

    sub_006C5A90_EmitCode(&tState, &pOutput, tState.unknown20);
    if (tState.nBitCount > 0)
    {
        ++tState.nBlockLength;
        tState.pBlock[tState.nBlockLength] = (unsigned char)tState.nBits;
    }

    sub_006C5A60_FlushBlock(&tState, &pOutput);
    SMemFree(tState.f_28, ".\\SOURCE\\SBMP.CPP", 0x3A4, 0);
    SMemFree((void*)tState.unknown2C, ".\\SOURCE\\SBMP.CPP", 0x3A5, 0);
    return pOutput - pStart;
}
