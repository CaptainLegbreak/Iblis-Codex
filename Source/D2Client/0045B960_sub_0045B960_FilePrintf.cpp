typedef char* va_list;
#define va_start(ap, v) (ap = (va_list)&v + sizeof(v))

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, va_list args); // 0x006CC4AC
extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8

// 0x0045B960
void __cdecl sub_0045B960_FilePrintf(void* hFile, const char* szFormat, ...)
{
    char szBuffer[256];
    va_list args;
    va_start(args, szFormat);
    unsigned long nWritten = wvsprintfA(szBuffer, szFormat, args);
    WriteFile(hFile, szBuffer, nWritten, &nWritten, 0);
}
