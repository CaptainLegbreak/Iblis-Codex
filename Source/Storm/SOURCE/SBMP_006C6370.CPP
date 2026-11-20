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

// 0x006C5A60
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

// 0x006C5A90
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

void __stdcall SMemZero(void*, unsigned int); // 0x0041D300
static __declspec(noinline) void __stdcall ClearBlock(unsigned char**, D2BitOutputStrc*);

// 0x006C6330
static void __stdcall ClearBlock(unsigned char** ppOutput, D2BitOutputStrc* pState)
{
    SMemZero(pState->f_28, 0x4E2C);
    int nCode = pState->nClearCode;
    pState->nNextCode = nCode + 2;
    sub_006C5A90_EmitCode(pState, ppOutput, nCode);
    int nWidth = pState->nInitialCodeWidth;
    pState->f_0 = nWidth;
    pState->nCodeMask = (1 << nWidth) - 1;
}

__declspec(noinline) static void __stdcall sub_006C6370_AddChar(unsigned char** ppOutput, int nChar, D2BitOutputStrc* pState);
static void __stdcall sub_006C6370_AddChar(unsigned char** ppOutput, int nChar, D2BitOutputStrc* pState); // 0x006C6370

// 0x006C6370
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
            pState->unknown14[0] = ((int*)pState->f_28)[nIndex];
            return;
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
    }
    else
    {
        ClearBlock(ppOutput, pState);
    }

    pState->unknown14[0] = nChar;
}

// build: context sub_006C6370_Shim
// calling-convention shim (not game code)
extern "C" void __stdcall sub_006C6370_Shim(D2BitOutputStrc* pState, unsigned char** ppOutput, int nChar)
{
    sub_006C6370_AddChar(ppOutput, nChar, pState);
}
