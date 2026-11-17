extern "C" int __cdecl vsprintf(char* buffer, const char* format, char* args); // 0x00682DA1
int __stdcall sub_0041CAF0_DisplayError(int code, const char* file, int line, const char* text, int recoverable, int exitCode); // 0x0041CAF0

// 0x0041CFB0
int __cdecl sub_0041CFB0_DisplayErrorFmt(int code, const char* file, int line, int recoverable, int exitCode, const char* format, ...)
{
    char buffer[0x400];
    char* args = (char*)(&format + 1);
    vsprintf(buffer, format, args);
    return sub_0041CAF0_DisplayError(code, file, line, buffer, recoverable, exitCode);
}
