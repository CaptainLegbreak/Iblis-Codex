extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
int __fastcall FOG_SOCKET_WSACleanup();                                                                     // 0x0040D8D0
void __cdecl sub_00408900_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900
void __cdecl sub_0040F960_CloseLogFiles();                                                                  // 0x0040F960

// 0x00408A60
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    sub_00408900_RaiseErrorReport(6, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    sub_0040F960_CloseLogFiles();
}
