struct D2BitOutputStrc
{
    int f_0;
    int nCodeMask;
    int unknown08;
    int nBits;
    int nBitCount;
    int unknown14[4];
    int nNextCode;
    int unknown28[2];
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

void __fastcall EmitCodeContext(unsigned char** ppOutput, D2BitOutputStrc* pState, int nCode)
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
