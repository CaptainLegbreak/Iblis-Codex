extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
void __stdcall SStrCopy(char* szDest, const char* szSource, int nMax);                                      // 0x004135D0
char gaszHistory_0077B1D8[10][0x100];                                                                       // 0x0077B1D8
int gnHistoryCount_0077BD50;                                                                                // 0x0077BD50
void __stdcall sub_A09_Use(const char* szText);

// 0x0043E6E0
static int __stdcall sub_0043E6E0_CompareCommand(const char* szText, const char* szCommand)
{
    if (strlen(szText) < strlen(szCommand))
        return -1;

    unsigned int nLength = strlen(szCommand);
    while (nLength--)
    {
        const int nDiff = toupper(*szText) - toupper(*szCommand);
        if (nDiff)
            return nDiff > 0 ? 1 : -1;
        ++szText;
        ++szCommand;
    }
    return 0;
}

// 0x0043F510
static void sub_0043F510_PushHistory(const char* szText)
{
    memmove(gaszHistory_0077B1D8[1], gaszHistory_0077B1D8[0], 0x900);
    strcpy(gaszHistory_0077B1D8[0], szText);
    if (++gnHistoryCount_0077BD50 >= 10)
        gnHistoryCount_0077BD50 = 10;
}

// 0x0043F870
static void __stdcall sub_0043F870_GetArgument(int nSize, char* szDest, const char* szText)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

void __fastcall sub_A09_Emit_004423B0(char* szText)
{
    sub_0043F510_PushHistory(szText);
    if (!sub_0043E6E0_CompareCommand(szText, "/ignore "))
        return;
    if (!sub_0043E6E0_CompareCommand(szText, "/filtermsg "))
    {
        char szArg[0x104];
        sub_0043F870_GetArgument(0x104, szArg, szText);
        sub_A09_Use(szArg);
    }
}
