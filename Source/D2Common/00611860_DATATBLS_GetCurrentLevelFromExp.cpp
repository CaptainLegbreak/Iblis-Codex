struct D2ExperienceTxt
{
    unsigned int dwClass[7];
    unsigned int dwExpRatio;
};

struct D2ExperienceDataTbl
{
    D2ExperienceTxt tMax;
    D2ExperienceTxt aLevels[1];
};

extern D2ExperienceDataTbl* gpExperienceTxt;                                                                // 0x0096C8A8
extern char* gpSkillsCode_0096BC70;                                                                         // 0x0096BC70
extern int gnSkillsCodeSize_0096BC74;                                                                       // 0x0096BC74
extern int gnSkillsCodeSizeEx_0096BC78;                                                                     // 0x0096BC78
extern char* gpSkillDescCode_0096BC7C;                                                                      // 0x0096BC7C
extern int gnSkillDescCodeSize_0096BC80;                                                                    // 0x0096BC80
extern int gnSkillDescCodeSizeEx_0096BC84;                                                                  // 0x0096BC84

int __fastcall DATATBLS_AppendMemoryBuffer(char** ppCodes, int* pSize, int* pSizeEx, void* pBuffer, int nBufferSize); // 0x006118B0
int __fastcall DATATBLS_MapSkillsTxtKeywordToNumber(char* szKey);                                           // 0x00611930
int __fastcall sub_006119E0_SkillsCalcParamCount(int nValue);                                              // 0x006119E0
int __fastcall sub_006119F0_SkillsCalcLinkParse(char* szText, int* a2, int a3, int nKeywordNumber);          // 0x006119F0
int __stdcall DATATBLS_CompileExpression(const char* szFormulaString, char* pOutBuffer, int nOutBufferSize, int (__fastcall* pfnKeywordToNumber)(char*), int (__fastcall* pfnGetParameterCount)(int), int (__fastcall* pfnLinkParse)(char*, int*, int, int)); // 0x006C1AE0

static int DATATBLS_GetMaxLevelFromTable(D2ExperienceDataTbl* pExperienceTxt, int nClass)
{
    if (nClass < 0 || nClass >= 7)
    {
        nClass = 0;
    }

    return pExperienceTxt->tMax.dwClass[nClass];
}

// 0x00611860
unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience)
{
    if (nClass < 0 || nClass >= 7)
    {
        nClass = 0;
    }

    D2ExperienceDataTbl* pExperienceTxt = gpExperienceTxt;
    int nMaxLevel = DATATBLS_GetMaxLevelFromTable(pExperienceTxt, nClass);
    int nLevel = 0;
    while (dwExperience >= pExperienceTxt->aLevels[nLevel].dwClass[nClass] && nLevel < nMaxLevel)
    {
        ++nLevel;
    }

    return nLevel;
}

// 0x00611BD0
void __fastcall DATATBLS_SkillCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
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

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapSkillsTxtKeywordToNumber, sub_006119E0_SkillsCalcParamCount, sub_006119F0_SkillsCalcLinkParse);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpSkillsCode_0096BC70, &gnSkillsCodeSize_0096BC74, &gnSkillsCodeSizeEx_0096BC78, pBuffer, nBufferSize);
}

// 0x00611C70
void __fastcall DATATBLS_SkillDescCalcLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
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

    const int nBufferSize = DATATBLS_CompileExpression(pSrc, pBuffer, sizeof(pBuffer), DATATBLS_MapSkillsTxtKeywordToNumber, sub_006119E0_SkillsCalcParamCount, sub_006119F0_SkillsCalcLinkParse);
    if (nBufferSize <= 0)
    {
        *(int*)((char*)pRecord + nOffset) = -1;
        return;
    }

    *(int*)((char*)pRecord + nOffset) = DATATBLS_AppendMemoryBuffer(&gpSkillDescCode_0096BC7C, &gnSkillDescCodeSize_0096BC80, &gnSkillDescCodeSizeEx_0096BC84, pBuffer, nBufferSize);
}
