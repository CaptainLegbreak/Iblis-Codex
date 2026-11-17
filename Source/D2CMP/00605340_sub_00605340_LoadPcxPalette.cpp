extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C
extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

unsigned char __stdcall sub_00605210_FindNearestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

extern "C" const char gszNewline_006FFCB0[];                                                                // 0x006FFCB0
extern unsigned char gaPcxPalette_008E9938[256 * 4];                                                        // 0x008E9938

struct D2PcxRgbStrc
{
    unsigned char nR;
    unsigned char nG;
    unsigned char nB;
};

struct D2PcxPaletteStrc
{
    unsigned char f_0;
    D2PcxRgbStrc aColors[256];
};

// 0x00605340
int __fastcall sub_00605340_LoadPcxPalette(const char* szFileName)
{
    void* hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        OutputDebugStringA("Unable to open ");
        OutputDebugStringA(szFileName);
        OutputDebugStringA(gszNewline_006FFCB0);
        return 0;
    }

    unsigned char header[128];
    memset(header, 0, sizeof(header));
    unsigned long nRead = 0;
    ReadFile(hFile, header, sizeof(header), &nRead, 0);
    if (nRead != sizeof(header) || header[0] != 0x0A || header[1] != 5 || header[3] != 8)
    {
        OutputDebugStringA("File is not a valid 256-color PCX file.\n");
        CloseHandle(hFile);
        return 0;
    }

    D2PcxPaletteStrc palette;
    memset(&palette, 0, sizeof(palette));
    SetFilePointer(hFile, -(long)sizeof(palette), 0, 2);
    ReadFile(hFile, &palette, sizeof(palette), &nRead, 0);
    if (nRead != sizeof(palette) || palette.f_0 != 0x0C)
    {
        OutputDebugStringA("Unable to extract palette from\n");
        CloseHandle(hFile);
        return 0;
    }

    for (unsigned int i = 0; i < 256; ++i)
    {
        gaPcxPalette_008E9938[i * 4 + 0] = palette.aColors[i].nR;
        gaPcxPalette_008E9938[i * 4 + 1] = palette.aColors[i].nG;
        gaPcxPalette_008E9938[i * 4 + 2] = palette.aColors[i].nB;
    }

    CloseHandle(hFile);
    return 1;
}

// 0x00605DE0
void __stdcall sub_00605DE0_BuildDarkenTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 32; ++i)
    {
        for (unsigned int j = 0; j < 256; ++j)
        {
            pData[0x400 + i * 256 + j] = sub_00605210_FindNearestColor(pData, 256,
                pData[j * 4 + 0] * (i + 1) >> 5,
                pData[j * 4 + 1] * (i + 1) >> 5,
                pData[j * 4 + 2] * (i + 1) >> 5);
        }
    }
}
