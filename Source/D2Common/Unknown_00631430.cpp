#include "D2Common.h"

extern char* gpItemsCode_0096BCC8; // 0x0096BCC8
extern int gnItemsCodeSize_0096BCCC; // 0x0096BCCC
extern int gnItemsCodeSizeEx_0096BCD0; // 0x0096BCD0
int __fastcall DATATBLS_MapItemsTxtKeywordToNumber(char* szKey); // 0x00631430
int __cdecl sub_00631490(); // 0x00631490
int __fastcall ITEMS_ResolveItemCalcKeyword(char* szText, int* a2, int a3, int nKeywordNumber); // 0x006314A0
int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0
int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, char* pOutBuffer, int nOutBufferSize, int (__fastcall* pfnKeywordToNumber)(char*), int (__cdecl* pfnGetParameterCount)(), int (__fastcall* pfnLinkParse)(char*, int*, int, int)); // 0x006C1AE0

// 0x00631430
int __fastcall DATATBLS_MapItemsTxtKeywordToNumber(char* szKey)
{
    if (!SStrCmpI(szKey, "min", 32))
    {
        return 0;
    }
    else if (!SStrCmpI(szKey, "max", 32))
    {
        return 1;
    }
    else if (!SStrCmpI(szKey, "rand", 32))
    {
        return 2;
    }
    else if (!SStrCmpI(szKey, "stat", 32))
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

// 0x00631530
void __fastcall DATATBLS_ItemCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    char szBuffer[0x400];

    if (!pRecord)
    {
        return;
    }

    if (!pSrc)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, szBuffer, sizeof(szBuffer), DATATBLS_MapItemsTxtKeywordToNumber, sub_00631490, ITEMS_ResolveItemCalcKeyword);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpItemsCode_0096BCC8, &gnItemsCodeSize_0096BCCC, &gnItemsCodeSizeEx_0096BCD0, szBuffer, nBufferSize);
}
