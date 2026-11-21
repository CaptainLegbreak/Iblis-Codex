#include "D2Common.h"

extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" char* __cdecl strchr(const char* szString, int nChar);
void __fastcall sub_00654D50();

// 0x00668510
static void sub_00668510_MakeCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

unsigned int __stdcall sub_M91_Emit_00668510(const char* szText)
{
    unsigned int dwCode;
    sub_00668510_MakeCode(szText, (char*)&dwCode);
    return dwCode;
}

// 0x00668560
static char* sub_006543C0_StripQuotes(char* szText)
{
    if (*szText == '"')
        ++szText;
    for (char* p = szText; *p; ++p)
    {
        if (*p == '"')
            *p = 0;
    }
    return szText;
}

static char* sub_006543F0_NextStrToken(char** ppString, char chSeparator)
{
    char* szToken = *ppString;
    *ppString = strchr(szToken, chSeparator);
    if (*ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    return szToken;
}

char* __stdcall sub_M116_Emit_006543C0(char* szText, char** ppOut)
{
    ppOut[0] = sub_006543C0_StripQuotes(sub_006543F0_NextStrToken(&szText, ','));
    ppOut[1] = sub_006543F0_NextStrToken(&szText, ',');
    return szText;
}

void __fastcall sub_00654EF0_UnloadTCEx()
{
    sub_00654D50();
}

void __cdecl sub_00654F00_AssertFail()
{
    D2_ASSERT(0, 0x6AE);
}

// 0x00668590
static char* sub_00668590_NextSetToken(char** ppString, const char* szSet)
{
    char* szToken = *ppString;
    *ppString += strcspn(szToken, szSet);
    if (**ppString)
    {
        **ppString = 0;
        ++*ppString;
    }
    else
    {
        *ppString = 0;
    }
    return szToken;
}

char* __stdcall sub_M133_Emit_00668590(char* szText, const char* szSet, char** ppOut)
{
    ppOut[0] = sub_00668590_NextSetToken(&szText, szSet);
    ppOut[1] = sub_00668590_NextSetToken(&szText, szSet);
    return szText;
}

// 0x006690E0
void __fastcall DATATBLS_CubeMainParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn)
{
    int nValue = 0;

    if (pRecord && pSrc && *pSrc)
    {
        if (*pSrc == '-' || *pSrc >= '0' && *pSrc <= '9')
        {
            *(int*)pRecord = atoi(pSrc);
        }
        else
        {
            if (gTxtLink_0096C800)
            {
                nValue = FOG_GetRowFromTxt(gTxtLink_0096C800, pSrc, 0);
                if (nValue >= 0)
                {
                    *(int*)pRecord = nValue;
                    return;
                }
            }

            *(int*)pRecord = 0;
        }
    }
}
