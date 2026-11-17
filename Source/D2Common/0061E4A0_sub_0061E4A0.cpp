extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* sz);
extern "C" const char gszPathFormat_006D4124[];                                                             // 0x006D4124

// 0x0061E4A0
static void sub_0061E4A0(char* szPath, const char* szDirectory)
{
    char szBuffer[60];
    const int nLength = strlen(szPath);
    if (nLength)
    {
        for (int i = 0; i < nLength; ++i)
        {
            if (szPath[i] == '/')
                szPath[i] = '\\';
        }
    }
    if (nLength > 1)
    {
        wsprintfA(szBuffer, gszPathFormat_006D4124, szDirectory, szPath);
        strcpy(szPath, szBuffer);
    }
}

void __fastcall sub_Z16_EmitFixPathSlashes(char* pRecords, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        sub_0061E4A0(pRecords, "DATA\\GLOBAL\\TILES");
        pRecords += 0x3C;
    }
}
