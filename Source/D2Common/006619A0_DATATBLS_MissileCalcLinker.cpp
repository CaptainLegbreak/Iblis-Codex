extern char* gpMissCode_0096BC90;                                                                                  // 0x0096BC90
int gnMissCodeSize_0096BC94;                                                                                       // 0x0096BC94
int gnMissCodeSizeEx_0096BC98;                                                                                     // 0x0096BC98

int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0
int __fastcall DATATBLS_MapMissilesTxtKeywordToNumber(char* szKey);                                         // 0x00661800
int __fastcall sub_6FD62F20(char* szText, int* a2, int a3, int nKeywordNumber);                             // 0x00661880
int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, char* pOutBuffer, int nOutBufferSize, int (__fastcall* pfnKeywordToNumber)(char*), int (__cdecl* pfnGetParameterCount)(), int (__fastcall* pfnLinkParse)(char*, int*, int, int)); // 0x006C1AE0

// 0x006619A0
void __fastcall DATATBLS_MissileCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    char pBuffer[1024];

    if (!pRecord)
    {
        return;
    }

    if (!pSrc)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapMissilesTxtKeywordToNumber, 0, sub_6FD62F20);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpMissCode_0096BC90, &gnMissCodeSize_0096BC94, &gnMissCodeSizeEx_0096BC98, pBuffer, nBufferSize);
}
