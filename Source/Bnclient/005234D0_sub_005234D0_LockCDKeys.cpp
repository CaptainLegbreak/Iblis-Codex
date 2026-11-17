extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped); // 0x0041B650
int __stdcall SFileUnloadFile(void* pBuffer);                                                               // 0x00416710
int __cdecl sub_0051BEC0_IsExpansion();                                                                     // 0x0051BEC0
unsigned int __fastcall sub_00522E10(char* szOut, unsigned int nSize, char* pKey);                         // 0x00522E10

unsigned int gnSize_00882740;                                                                               // 0x00882740
void* gpCDKeyHandle_00882744;                                                                               // 0x00882744
unsigned int gnSize_00882748;                                                                               // 0x00882748
void* gpHandle_0088274C;                                                                                    // 0x0088274C
void* gpCDKeyHandle_00882750;                                                                               // 0x00882750
unsigned int gnSize_00882754;                                                                               // 0x00882754
extern int gdwGlobal_00730190;                                                                              // 0x00730190

static void* sub_00523480_LoadKeyFile(const char* szFileName, unsigned int* pSize);

// calling-convention shim (not game code)
void __fastcall sub_00522BC0_FillRandomBytes(unsigned char* pBuffer, int nSize); // 0x00522BC0

// build: context sub_GetTerminatedLength
static __forceinline unsigned int sub_GetTerminatedLength(const unsigned char* pString, unsigned int nSize)
{
    unsigned int nMax = 0x80;
    unsigned int nLength = 0;
    if (nSize <= nMax)
    {
        nMax = nSize;
    }

    if (!nMax)
    {
        return 0;
    }

    do
    {
        --nMax;
        ++nLength;
        if (!*pString++)
        {
            return nLength;
        }
    }
    while (nMax);

    return 0;
}

static __declspec(noinline) int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize);

// 0x005232B0
static int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize)
{
    unsigned char aKey[20];
    sub_00522BC0_FillRandomBytes(aKey, sizeof(aKey));
    unsigned int nLength = sub_00522E10((char*)pBuffer, nSize, (char*)aKey);
    if (!nLength)
    {
        return 0;
    }

    if (nLength >= nSize)
    {
        return 0;
    }

    pBuffer[nLength] = 0;
    ++nLength;
    if (!sub_GetTerminatedLength(pBuffer, nLength))
    {
        return 0;
    }

    return 1;
}

// 0x00523480
static void* sub_00523480_LoadKeyFile(const char* szFileName, unsigned int* pSize)
{
    void* pBuffer;

    *pSize = 0x400;
    SFileLoadFile(szFileName, &pBuffer, pSize, 1, 0);
    if (pBuffer && *pSize)
    {
        if (sub_005232B0_DecodeAndValidate((unsigned char*)pBuffer, *pSize))
        {
            return pBuffer;
        }

        if (pBuffer)
        {
            SFileUnloadFile(pBuffer);
        }
    }

    return 0;
}

// 0x005234D0
void __cdecl sub_005234D0_LockCDKeys()
{
    char szPath[260];
    int i;

    if (gpCDKeyHandle_00882744 || gpCDKeyHandle_00882750)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x213);
        exit(-1);
    }

    sprintf(szPath, "%s\\%s.gid", "font", "font");
    gpCDKeyHandle_00882744 = sub_00523480_LoadKeyFile(szPath, &gnSize_00882740);
    if (!gpCDKeyHandle_00882744)
    {
        char szKey[] = "vwaxdnirosucflbgt\\.";
        char aIndex[] = { 4, 2, 16, 2, 17, 15, 13, 8, 14, 2, 13, 17, 9, 12, 3, 17, 11, 10, 7, 9, 8, 7, 17, 1, 2, 0, 6, 5, 4, 3, 18, 1, 2, 0, 19 };

        for (i = 0; aIndex[i] < 19; i++)
        {
            szPath[i] = szKey[aIndex[i]];
        }
        szPath[i] = 0;

        gpCDKeyHandle_00882744 = sub_00523480_LoadKeyFile(szPath, &gnSize_00882740);
    }

    sprintf(szPath, "%s\\%s.clh", "font", "font");
    gpCDKeyHandle_00882750 = sub_00523480_LoadKeyFile(szPath, &gnSize_00882748);
    if (!gpCDKeyHandle_00882750)
    {
        char szKey[] = "vwaxdnirosucflbgt\\.";
        char aIndex[] = { 4, 2, 16, 2, 17, 15, 13, 8, 14, 2, 13, 17, 9, 12, 3, 17, 11, 10, 7, 9, 8, 7, 17, 11, 10, 7, 6, 5, 4, 3, 18, 1, 2, 0, 19 };

        for (i = 0; aIndex[i] < 19; i++)
        {
            szPath[i] = szKey[aIndex[i]];
        }
        szPath[i] = 0;

        gpCDKeyHandle_00882750 = sub_00523480_LoadKeyFile(szPath, &gnSize_00882748);
    }

    if (sub_0051BEC0_IsExpansion())
    {
        char szKey[] = "vwaxdnirosucflbgt\\.mpyeh8";
        char aIndex[] = { 4, 2, 16, 2, 17, 15, 13, 8, 14, 2, 13, 17, 11, 23, 2, 7, 9, 17, 2, 19, 17, 11, 8, 12, 17, 2, 19, 14, 13, 3, 14, 8, 1, 18, 11, 8, 12, 39 };

        for (i = 0; aIndex[i] < sizeof(szKey); i++)
        {
            szPath[i] = szKey[aIndex[i]];
        }
        szPath[i] = 0;

        gpHandle_0088274C = sub_00523480_LoadKeyFile(szPath, &gnSize_00882754);
    }

    gdwGlobal_00730190 = 0;

    if (szPath[0])
    {
        char* p = szPath;
        do
        {
            *p++ = 0;
        }
        while (*p);
    }
}

#include "gen/data/Source/Bnclient/005234D0_sub_005234D0_LockCDKeys.inc"
