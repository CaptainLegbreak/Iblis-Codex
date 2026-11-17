extern "C" int __cdecl memcmp(const void* pBuf1, const void* pBuf2, unsigned int nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x00683840

// 0x0041D200
int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize)
{
    return memcmp(pLocation1, pLocation2, nSize);
}

// 0x0041D2A0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize)
{
    memcpy(pDest, pSource, nSize);
}

// 0x0041D2C0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith)
{
    memset(pLocation, nFillWith, nLength);
}

// 0x0041D2E0
void __stdcall SMemMove(void* pDest, const void* pSource, unsigned int nSize)
{
    memmove(pDest, pSource, nSize);
}

// 0x0041D300
void __stdcall SMemZero(void* pLocation, unsigned int nLength)
{
    memset(pLocation, 0, nLength);
}
