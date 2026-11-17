extern "C" const char gszEmptyAssertText;
extern "C" const char* __cdecl sub_00408090();
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strchr(const char* szString, int nChar);
void __fastcall sub_00654D50();

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
