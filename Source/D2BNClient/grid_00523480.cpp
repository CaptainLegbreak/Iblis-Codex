int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped); // 0x0041B650
int __stdcall SFileUnloadFile(void* pBuffer); // 0x00416710
void __fastcall sub_00522BC0_FillRandomBytes(char* szBuffer, int nSize); // 0x00522BC0
unsigned int __fastcall sub_00522E10(char* pBuffer, unsigned int nSize, const void* pKey); // 0x00522E10

static __declspec(noinline) int sub_005232B0_Validate(char* pBuffer, unsigned int nSize);

// build: context sub_005232B0_Validate
static int sub_005232B0_Validate(char* pBuffer, unsigned int nSize)
{
    char aKey[20];
    sub_00522BC0_FillRandomBytes(aKey, sizeof(aKey));
    unsigned int nLength = sub_00522E10(pBuffer, nSize, aKey);
    if (!nLength || nLength >= nSize)
        return 0;
    pBuffer[nLength] = 0;
    ++nLength;

    unsigned int nMax = 0x80;
    int nCount = 0;
    if (nLength <= nMax)
    {
        if (!nLength)
            return 0;
        nMax = nLength;
    }
    do
    {
        const char c = *pBuffer;
        --nMax;
        ++nCount;
        ++pBuffer;
        if (!c)
            return nCount != 0;
    }
    while (nMax);
    return 0;
}

static __declspec(noinline) void* sub_00523480_LoadFile(const char* szFileName, unsigned int* pSize);
// build: base-profile
// 0x00523480
static void* sub_00523480_LoadFile(const char* szFileName, unsigned int* pSize)
{
    void* pBuffer;
    *pSize = 0x400;
    SFileLoadFile(szFileName, &pBuffer, pSize, 1, 0);
    if (pBuffer && *pSize)
    {
        if (sub_005232B0_Validate((char*)pBuffer, *pSize))
            return pBuffer;
        if (pBuffer)
            SFileUnloadFile(pBuffer);
    }
    return 0;
}

// calling-convention shim (not game code)
void* __fastcall sub_00523480_Shim(const char* szFileName, unsigned int* pSize)
{
    return sub_00523480_LoadFile(szFileName, pSize);
}
