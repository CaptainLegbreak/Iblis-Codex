extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46
void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile);                                             // 0x00516E84
void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

extern unsigned char gabItemPalettes_00842710[9][0x6900];                                                     // 0x00842710

// 0x00505470
static void sub_00505470_LoadItemPalette(const char* szName, int nIndex)
{
    char szPath[256];
    strcpy(szPath, "Data\\Global\\Items\\Palette\\");
    strcat(szPath, szName);
    strcat(szPath, ".dat");
    void* hFile;
    D2_ASSERT(ARCHIVE_OpenFile(0, szPath, &hFile, 1), 0xDD8);
    ARCHIVE_ReadFileToBuffer(0, hFile, gabItemPalettes_00842710[nIndex], 0x1500);
    ARCHIVE_CloseFile(0, hFile);
}

// 0x00505550
void __cdecl sub_00505550_LoadItemPalettes()
{
    sub_00505470_LoadItemPalette("grey", 1);
    sub_00505470_LoadItemPalette("grey2", 2);
    sub_00505470_LoadItemPalette("gold", 3);
    sub_00505470_LoadItemPalette("brown", 4);
    sub_00505470_LoadItemPalette("greybrown", 5);
    sub_00505470_LoadItemPalette("invgrey", 6);
    sub_00505470_LoadItemPalette("invgrey2", 7);
    sub_00505470_LoadItemPalette("invgreybrown", 8);
}
