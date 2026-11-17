#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

struct D2PaletteColorStrc { unsigned char red, green, blue, alpha; };

typedef void* (__stdcall* SBMPALLOCPROC)(unsigned int nSize);

extern const char gszSBmpSource[];                                                                          // 0x006FCC58
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                          // 0x0041C340
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                 // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);           // 0x00413020
unsigned int __stdcall sub_00416370_StormGetFileSize(void* hFile, unsigned int* pnSizeHigh);                // 0x00416370
int __stdcall sub_004198D0(void* pArg);                                                                     // 0x004198D0
int __stdcall sub_00419980(const char* szFileName, void** phFile);                                        // 0x00419980
int __stdcall SFileReadFile(void* hFile, void* pBuffer, unsigned int nToRead, unsigned int* pnRead, void* pOverlapped); // 0x0041B050
int __stdcall sub_006C6A80_DecodeImage(int nType, const unsigned char* pData, unsigned int nDataSize, D2PaletteColorStrc* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth); // 0x006C6A80

// 0x006C6E70
int __stdcall SBmpAllocLoadImage(const char* szFileName, D2PaletteColorStrc* pPalette, unsigned char** ppBuffer, int* pWidth, int* pHeight, int* pBitDepth, int nRequestedBitDepth, SBMPALLOCPROC pfAlloc)
{
    if (ppBuffer)
        *ppBuffer = 0;
    if (pWidth)
        *pWidth = 0;
    if (pHeight)
        *pHeight = 0;
    if (pBitDepth)
        *pBitDepth = 0;

    VALIDATEBEGIN;
    VALIDATE(szFileName);
    __assume((szFileName) != 0);
    VALIDATE(*szFileName);
    __assume((*szFileName) != 0);
    VALIDATE(ppBuffer);
    __assume((ppBuffer) != 0);
    VALIDATEEND;

    void* hFile;
    if (!nValid || !sub_00419980(szFileName, &hFile))
        return 0;

    unsigned int nFileSize = sub_00416370_StormGetFileSize(hFile, 0);
    unsigned char* pFileData = (unsigned char*)SMemAlloc(nFileSize, gszSBmpSource, 0x5B6, 0);
    SFileReadFile(hFile, pFileData, nFileSize, 0, 0);
    sub_004198D0(hFile);

    int bResult = 0;
    int nWidth;
    int nHeight;
    int nBitDepth;
    if (sub_006C6A80_DecodeImage(0, pFileData, nFileSize, 0, 0, 0, &nWidth, &nHeight, &nBitDepth))
    {
        if (!nRequestedBitDepth)
            nRequestedBitDepth = nBitDepth;
        else if (nRequestedBitDepth != nBitDepth)
            goto done;

        int nBufferSize = nWidth * nHeight * nRequestedBitDepth / 8;
        if (pfAlloc)
            *ppBuffer = (unsigned char*)pfAlloc(nBufferSize);
        else
            *ppBuffer = (unsigned char*)SMemAlloc(nBufferSize, szFileName, -4, 0);

        if (*ppBuffer)
        {
            sub_006C6A80_DecodeImage(0, pFileData, nFileSize, pPalette, *ppBuffer, nBufferSize, 0, 0, 0);
            if (pWidth)
                *pWidth = nWidth;
            if (pHeight)
                *pHeight = nHeight;
            if (pBitDepth)
                *pBitDepth = nRequestedBitDepth;
            bResult = 1;
        }
    }

done:
    SMemFree(pFileData, gszSBmpSource, 0x5F3, 0);
    return bResult;
}
