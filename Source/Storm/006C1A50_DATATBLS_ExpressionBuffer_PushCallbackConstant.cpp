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

static __declspec(noinline) FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushCallbackConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue);

// 0x006C1A50
static FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushCallbackConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue)
{
    if (-128 <= nValue && nValue <= 127)
    {
        if (pExpressionBufferPos - pExpressionBufferStart >= szBufferSize)
        {
            pExpressionBufferStart->nType = 0;
            return 0;
        }
        pExpressionBufferPos->nType = 4;
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
        pExpressionBufferPos->nType = 5;
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
        pExpressionBufferPos->nType = 6;
        ++pExpressionBufferPos;
        *(int*)pExpressionBufferPos = nValue;
        pExpressionBufferPos += 4;
    }

    ++pCalc->nPendingParameters;
    return pExpressionBufferPos;
}

// build: context sub_006C1A50_Shim
// calling-convention shim (not game code)
FOGASTNodeStrc* __stdcall sub_006C1A50_Shim(FOGASTNodeStrc* pPos, FOGASTNodeStrc* pStart, int nSize, FOGExpressionParserContextStrc* pCalc, int nValue)
{
    return DATATBLS_ExpressionBuffer_PushCallbackConstant(pPos, pStart, nSize, pCalc, nValue);
}
