union FOGASTNodeStrc
{
    unsigned char nType;
    unsigned char nRawValue;
};

struct FOGExpressionParserContextStrc
{
    unsigned char tPendingOperationsASTs[64];
    int tLinkerIndex[64];
    int nPendingOps;
    int nPendingParameters;
};

static __declspec(noinline) FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushRawConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue);

// 0x006C19C0
static FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushRawConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue)
{
    if (-128 <= nValue && nValue <= 127)
    {
        if (pExpressionBufferPos - pExpressionBufferStart >= szBufferSize)
        {
            pExpressionBufferStart->nType = 0;
            return 0;
        }
        pExpressionBufferPos->nType = 7;
        ++pExpressionBufferPos;
        pExpressionBufferPos->nRawValue = (unsigned char)nValue;
        ++pExpressionBufferPos;
    }
    else if (-32768 <= nValue && nValue <= 32767)
    {
        if (pExpressionBufferPos - pExpressionBufferStart + 3 >= szBufferSize)
        {
            pExpressionBufferStart->nType = 0;
            return 0;
        }
        pExpressionBufferPos->nType = 8;
        ++pExpressionBufferPos;
        *(short*)pExpressionBufferPos = (short)nValue;
        pExpressionBufferPos += 2;
    }
    else
    {
        if (pExpressionBufferPos - pExpressionBufferStart + 5 >= szBufferSize)
        {
            pExpressionBufferStart->nType = 0;
            return 0;
        }
        pExpressionBufferPos->nType = 9;
        ++pExpressionBufferPos;
        *(int*)pExpressionBufferPos = nValue;
        pExpressionBufferPos += 4;
    }

    ++pCalc->nPendingParameters;
    return pExpressionBufferPos;
}

// build: context sub_006C19C0_Shim

// calling-convention shim (not game code)
FOGASTNodeStrc* __fastcall sub_006C19C0_Shim(FOGASTNodeStrc* pBuffer, int nValue, int nSize, FOGExpressionParserContextStrc* pCalc)
{
    return DATATBLS_ExpressionBuffer_PushRawConstant(pBuffer + nSize / 2, pBuffer, nSize, pCalc, nValue);
}
