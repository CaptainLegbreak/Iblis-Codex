extern "C" const char gszEmptyAssertText;                                                    // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                       // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);    // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __security_cookie;                                                   // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie);                    // 0x00681A48
int __fastcall sub_00406900(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900
int __stdcall sub_00416230_GetFileName(void* hFile, char* szFileName, unsigned int nSize);   // 0x00416230

// 0x00516F85
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead)
{
    D2_ASSERT(hFile, 0x87);

    int dwBytes;
    if (!sub_00406900(hFile, pBuffer, dwBytesToRead, &dwBytes, 0, 0, 0))
    {
        char szArchivePath[0x104];
        sub_00416230_GetFileName(hFile, szArchivePath, sizeof(szArchivePath));
        D2_ASSERT(0, 0x8F);
    }

    D2_ASSERT(dwBytesToRead == dwBytes, 0x92);
}
