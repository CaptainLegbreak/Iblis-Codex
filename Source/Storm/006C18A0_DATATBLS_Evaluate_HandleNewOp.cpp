typedef int (__fastcall* D2CalcOperandCountFn)(int nFunctionId);

struct FOGExpressionParserContextStrc
{
    unsigned char tPendingOperationsASTs[64];
    int tLinkerIndex[64];
    int nPendingOps;
    int nPendingParameters;
};

extern "C" const unsigned char gaASTOperatorPrecedence_006FC874[];                                          // 0x006FC874

__declspec(noinline)
// 0x006C1820
static int __stdcall sub_006C1820_GetOperandCount(
    unsigned char nToken, D2CalcOperandCountFn pfnGetOperandCount, int nFunctionId)
{
    switch (nToken)
    {
    case 22:
        return 3;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        return 2;
    case 21:
        return 1;
    case 1:
        if (pfnGetOperandCount)
            return pfnGetOperandCount(nFunctionId);
        return 2;
    default:
        return 0;
    }
}

static __forceinline int DATATABLS_CheckPrecendence(unsigned char nPreviousCalcType, unsigned char nNewCalcType)
{
    if (nPreviousCalcType == 1 || nNewCalcType == 1 || nPreviousCalcType >= 23)
    {
        return 0;
    }
    else
    {
        return gaASTOperatorPrecedence_006FC874[nPreviousCalcType] >= nNewCalcType;
    }
}

static __declspec(noinline) unsigned char* __stdcall DATATBLS_Evaluate_HandleNewOp(unsigned char* pASTBufferPos, unsigned char* pASTBufferStart, int nASTBufferSize, FOGExpressionParserContextStrc* pContext, unsigned char nNewASTType, D2CalcOperandCountFn pfnGetFunctionParametersCount, int nTokenAssociatedValue);

// 0x006C18A0
static unsigned char* __stdcall DATATBLS_Evaluate_HandleNewOp(unsigned char* pASTBufferPos, unsigned char* pASTBufferStart, int nASTBufferSize, FOGExpressionParserContextStrc* pContext, unsigned char nNewASTType, D2CalcOperandCountFn pfnGetFunctionParametersCount, int nTokenAssociatedValue)
{
    while (pContext->nPendingOps > 0)
    {
        const unsigned char nPreviousASTType = pContext->tPendingOperationsASTs[pContext->nPendingOps - 1];
        if (!DATATABLS_CheckPrecendence(nPreviousASTType, nNewASTType))
        {
            break;
        }

        const int nParams = sub_006C1820_GetOperandCount(nPreviousASTType, pfnGetFunctionParametersCount, nTokenAssociatedValue);
        if (pContext->nPendingParameters < nParams)
        {
            *pASTBufferStart = 0;
            return 0;
        }
        if (pASTBufferPos - pASTBufferStart >= nASTBufferSize)
        {
            *pASTBufferStart = 0;
            return 0;
        }

        *pASTBufferPos = nPreviousASTType;
        pContext->nPendingOps--;
        pContext->nPendingParameters += 1 - nParams;
        pASTBufferPos++;
    }

    if (nNewASTType != 23 && nNewASTType != 3)
    {
        if (nNewASTType)
        {
            if (pContext->nPendingOps >= 64)
            {
                *pASTBufferStart = 0;
                return 0;
            }
            pContext->tPendingOperationsASTs[pContext->nPendingOps] = nNewASTType;
            pContext->tLinkerIndex[pContext->nPendingOps] = nTokenAssociatedValue;
            pContext->nPendingOps++;
        }
    }

    if (!nNewASTType)
    {
        if (pASTBufferPos == pASTBufferStart)
        {
            return 0;
        }
        if (pASTBufferPos - pASTBufferStart >= nASTBufferSize)
        {
            *pASTBufferStart = 0;
            return 0;
        }
        *pASTBufferPos = 0;
        pASTBufferPos++;
    }

    return pASTBufferPos;
}

unsigned char* __fastcall sub_006C18A0_EmitCaller(FOGExpressionParserContextStrc* pContext, unsigned char* pPos, unsigned char* pStart, int nSize, unsigned char nType, D2CalcOperandCountFn pfn, int nValue)
{
    return DATATBLS_Evaluate_HandleNewOp(pPos, pStart, nSize, pContext, nType, pfn, nValue);
}
