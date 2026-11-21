#include "Fog.h"

struct Fog64IntStack;
struct CalcEntry;
struct FOGExpressionParserContextStrc;
union FOGASTNodeStrc;

struct Fog64IntStack { int data[64]; int size; };

typedef int (__fastcall* CalcParam)(int, void*);

typedef int (__fastcall* CalcFunction)(int, int, int, void*);

struct CalcEntry { CalcFunction function; int parameters; };

static void sub_006C0B80(Fog64IntStack*, int); // 0x006C0B80
static int __fastcall sub_006C0BA0(Fog64IntStack*); // 0x006C0BA0

typedef int (__fastcall* D2CalcOperandCountFn)(int nFunctionId);

struct FOGExpressionParserContextStrc
{
    unsigned char tPendingOperationsASTs[64];
    int tLinkerIndex[64];
    int nPendingOps;
    int nPendingParameters;
};
static unsigned char* __stdcall DATATBLS_Evaluate_HandleNewOp(unsigned char* pASTBufferPos, unsigned char* pASTBufferStart, int nASTBufferSize, FOGExpressionParserContextStrc* pContext, unsigned char nNewASTType, D2CalcOperandCountFn pfnGetFunctionParametersCount, int nTokenAssociatedValue);

union FOGASTNodeStrc
{
    unsigned char nType;
    unsigned char nRawValue;
};

static FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushRawConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue);
static FOGASTNodeStrc* __stdcall DATATBLS_ExpressionBuffer_PushCallbackConstant(FOGASTNodeStrc* pExpressionBufferPos, FOGASTNodeStrc* pExpressionBufferStart, int szBufferSize, FOGExpressionParserContextStrc* pCalc, int nValue);

// 0x006C0B80
static void sub_006C0B80(Fog64IntStack* s, int value)
{
    if (s->size < 64)
    {
        s->data[s->size] = value;
        ++s->size;
    }
}

// 0x006C0BA0
static int __fastcall sub_006C0BA0(Fog64IntStack* s)
{
    if (s->size <= 0)
    {
        return 0;
    }
    return s->data[--s->size];
}

// 0x006C0BC0
int __stdcall DATATBLS_CalcEvaluateExpression(const unsigned char* start, int length, CalcParam param, CalcEntry* table, int tableSize, void* userData)
{
    if (length <= 0) return 0;
    const unsigned char* p = start;
    Fog64IntStack stack;
    stack.size = 0;
    if (p - start >= length) goto Done;
    do
    {
        unsigned char op = *p++;
        switch (op)
        {
        case 4:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, param(*(unsigned char*)p, userData));
            p += 1;
            break;
        case 5:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, param(*(short*)p, userData));
            p += 2;
            break;
        case 6:
            if (!param) goto Done;
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, param(*(int*)p, userData));
            p += 4;
            break;
        case 7:
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, *(signed char*)p);
            p += 1;
            break;
        case 8:
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, *(short*)p);
            p += 2;
            break;
        case 9:
            if (p - start >= length) goto Done;
            sub_006C0B80(&stack, *(int*)p);
            p += 4;
            break;
        case 1:
        {
            int index = *p++;
            if (index >= tableSize) { sub_006C0B80(&stack, 0); break; }
            int count = table[index].parameters;
            if (count == 3)
            {
                int c = sub_006C0BA0(&stack);
                int b = sub_006C0BA0(&stack);
                int a = sub_006C0BA0(&stack);
                sub_006C0B80(&stack, table[index].function(a, b, c, userData));
            }
            else if (count == 2) goto Two;
            else if (count == 1)
            {
                int a = sub_006C0BA0(&stack);
                sub_006C0B80(&stack, table[index].function(a, 0, 0, userData));
            }
            else if (count == 0)
                sub_006C0B80(&stack, table[index].function(0, 0, 0, userData));
            else sub_006C0B80(&stack, 0);
            break;
        Two:
            {
                int b = sub_006C0BA0(&stack);
                int a = sub_006C0BA0(&stack);
                sub_006C0B80(&stack, table[index].function(a, b, 0, userData));
            }
            break;
        }
        case 16:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a + b);
            break;
        }
        case 17:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a - b);
            break;
        }
        case 18:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a * b);
            break;
        }
        case 19:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            if (b) sub_006C0B80(&stack, a / b);
            else sub_006C0B80(&stack, 0);
            break;
        }
        case 21:
            sub_006C0B80(&stack, -sub_006C0BA0(&stack));
            break;
        case 22:
        {
            int ifFalse = sub_006C0BA0(&stack);
            int ifTrue = sub_006C0BA0(&stack);
            int condition = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, condition ? ifTrue : ifFalse);
            break;
        }
        case 20:
        {
            int exponent = sub_006C0BA0(&stack);
            int base = sub_006C0BA0(&stack);
            int result = base;
            if (exponent > 0)
            {
                for (int i = 1; i < exponent; ++i) result *= base;
            }
            else result = 1;
            sub_006C0B80(&stack, result);
            break;
        }
        case 10:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a < b);
            break;
        }
        case 12:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a <= b);
            break;
        }
        case 11:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a > b);
            break;
        }
        case 13:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a >= b);
            break;
        }
        case 14:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a == b);
            break;
        }
        case 15:
        {
            int b = sub_006C0BA0(&stack);
            int a = sub_006C0BA0(&stack);
            sub_006C0B80(&stack, a != b);
            break;
        }
        default:
            if (stack.size) return sub_006C0BA0(&stack);
            return 0;
        }
    } while (p - start < length);
Done:
    return 0;
}


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

extern "C" int __stdcall EmitOperandCountComparison(
    unsigned char nToken, D2CalcOperandCountFn pfnGetOperandCount,
    int nFunctionId, int nAvailableOperands)
{
    return nAvailableOperands >= sub_006C1820_GetOperandCount(
        nToken, pfnGetOperandCount, nFunctionId);
}

static inline int DATATABLS_CheckPrecendence(unsigned char nPreviousCalcType, unsigned char nNewCalcType)
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
