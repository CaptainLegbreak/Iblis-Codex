extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" unsigned int __cdecl strlen(const char* szString);
extern const char gszM134CmdA[];
extern const char gszM134CmdB[];
void __stdcall sub_M134_Use(const char* szText);

// 0x0047B3B0
static int __stdcall sub_0047B3B0_CompareCommand(const char* szText, const char* szCommand)
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

void __fastcall sub_M134_Emit_0047C100(const char* szText)
{
    if (!sub_0047B3B0_CompareCommand(szText, gszM134CmdA))
        return;
    if (!sub_0047B3B0_CompareCommand(szText, gszM134CmdB))
        sub_M134_Use(szText);
}
