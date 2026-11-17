struct JPEG_CORE_PROPERTIES
{
    int UseJPEGPROPERTIES;
    unsigned char* DIBBytes;
    int DIBWidth;
    int DIBHeight;
    int DIBPadBytes;
    int DIBChannels;
    int DIBColor;
    int DIBSubsampling;
    const char* JPGFile;
    unsigned char* JPGBytes;
    int JPGSizeBytes;
    int JPGWidth;
    int JPGHeight;
    int JPGChannels;
    int JPGColor;
    int JPGSubsampling;
    int JPGThumbWidth;
    int JPGThumbHeight;
    int cconversion_reqd;
    int upsampling_reqd;
    int jquality;
    int unk0x54[0x137B];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall ijlInit(JPEG_CORE_PROPERTIES* pProps);                      // 0x006CC5E0
extern "C" __declspec(dllimport) int __stdcall ijlWrite(JPEG_CORE_PROPERTIES* pProps, int nMode);          // 0x006CC5E4
extern "C" __declspec(dllimport) int __stdcall ijlFree(JPEG_CORE_PROPERTIES* pProps);                      // 0x006CC5E8
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern int gnScreenshotIndex_0072DC40;                                                                      // 0x0072DC40
unsigned long gdwLastScreenshotTick_007D5600;                                                               // 0x007D5600

void* __fastcall sub_00406960_CreateFile(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall sub_004069A0_CloseFile(void* hFile);                                                         // 0x004069A0
int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight);                                              // 0x004F59B0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer);                                                  // 0x004F6250

// 0x004F9FB0
static void __stdcall sub_004F9FB0_WriteScreenshotJpeg(unsigned char* pData, const char* szFile, int nWidth, int nHeight)
{
    char szName[256];
    JPEG_CORE_PROPERTIES tProps;
    while (1)
    {
        sprintf(szName, "Screenshot%03d.jpg", gnScreenshotIndex_0072DC40);
        ++gnScreenshotIndex_0072DC40;
        void* hFile = sub_00406960_CreateFile(szFile ? szFile : szName, 0x80000000, 0, 0, 3, 0x80, 0);
        if (hFile == (void*)-1)
        {
            break;
        }

        sub_004069A0_CloseFile(hFile);
        if (szFile)
        {
            return;
        }
    }

    memset(&tProps, 0, sizeof(tProps));
    ijlInit(&tProps);
    tProps.DIBWidth = nWidth;
    tProps.DIBHeight = nHeight;
    tProps.DIBBytes = pData;
    tProps.DIBColor = 1;
    tProps.DIBPadBytes = ((nWidth * 3 + 3) & ~3) - nWidth * 3;
    if (szFile)
    {
        tProps.JPGFile = szFile;
    }
    else
    {
        tProps.JPGFile = szName;
    }
    tProps.JPGWidth = nWidth;
    tProps.JPGHeight = nHeight;
    tProps.jquality = 100;
    ijlWrite(&tProps, 8);
    ijlFree(&tProps);
}

// 0x004FA0C0
void __fastcall sub_004FA0C0_SaveScreenshot(const char* szFile)
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick_007D5600 < 1000 && !szFile)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions(&nWidth, &nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        sub_004F9FB0_WriteScreenshotJpeg(pBuffer, szFile, nWidth, nHeight);
    }

    gdwLastScreenshotTick_007D5600 = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

// 0x004FA7A0
void __stdcall D2Win_10168_WINMAIN_CreateScreenshot()
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick_007D5600 < 1000)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions(&nWidth, &nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        sub_004F9FB0_WriteScreenshotJpeg(pBuffer, 0, nWidth, nHeight);
    }

    gdwLastScreenshotTick_007D5600 = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

#include "gen/data/Source/D2Win/004F9FB0_sub_004F9FB0_WriteScreenshotJpeg.inc"
