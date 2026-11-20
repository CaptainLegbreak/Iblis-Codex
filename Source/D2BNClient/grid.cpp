#include "D2BNClient.h"

struct D2BnHashCtxStrc;

typedef unsigned char Byte;

typedef unsigned int UInt;

void* __stdcall sub_00413020_Allocate(UInt size, const char* file, int line, UInt flags); // 0x00413020
int __stdcall SMemFree(void* buffer, const char* file, int line, UInt flags); // 0x00412650
void* __cdecl sub_006829C0_CopyBuffer(void* dest, const void* source, UInt size); // 0x006829C0
extern UInt gnSize_00882740; // 0x00882740
extern UInt gnSize_00882748; // 0x00882748
extern const char gszGrid_006E0200[]; // 0x006E0200
void __fastcall sub_00522BC0_FillRandomBytes(unsigned char* pBuffer, int nSize); // 0x00522BC0
unsigned int __fastcall sub_00522E10_Decrypt(unsigned char* pBuffer, unsigned int nSize, unsigned char* pKey); // 0x00522E10
static __declspec(noinline) int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize);
__declspec(noinline) static void __cdecl sub_00523350_CopyOutputs(Byte** first, Byte** second);

struct D2BnHashCtxStrc
{
    unsigned int aState[5];
    int nBitCountLo;
    int nBitCountHi;
    unsigned int f_1C[16];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __stdcall SFileUnloadFile(void* pBuffer); // 0x00416710
int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0
unsigned int __fastcall sub_00522E10_Decrypt(unsigned char* data,unsigned int size,unsigned int key); // 0x00522E10
extern int gdwGlobal_00730190; // 0x00730190
static void* sub_00523480_LoadKeyFile(const char* szFileName, unsigned int* pSize);

static const Byte* gpSource_00882744; // 0x00882744

static const Byte* gpSource_00882750; // 0x00882750

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

// 0x005232B0
static int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize)
{
    unsigned char aKey[20];
    sub_00522BC0_FillRandomBytes(aKey, sizeof(aKey));
    unsigned int nLength = sub_00522E10_Decrypt(pBuffer, nSize, aKey);
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

// 0x00523350
static void __cdecl sub_00523350_CopyOutputs(Byte** first, Byte** second)
{
    if (first)
    {
        Byte* allocated = (Byte*)sub_00413020_Allocate(gnSize_00882740, gszGrid_006E0200, 0x199, 0);
        *first = allocated;
        sub_006829C0_CopyBuffer(allocated, gpSource_00882744, gnSize_00882740);
    }
    if (second)
    {
        Byte* allocated = (Byte*)sub_00413020_Allocate(gnSize_00882748, gszGrid_006E0200, 0x19e, 0);
        *second = allocated;
        sub_006829C0_CopyBuffer(allocated, gpSource_00882750, gnSize_00882748);
    }
    if (first && !sub_005232B0_DecodeAndValidate(*first, gnSize_00882740))
    {
        SMemFree(*first, gszGrid_006E0200, 0x1a6, 0);
        *first = 0;
    }
    if (second && !sub_005232B0_DecodeAndValidate(*second, gnSize_00882748))
    {
        SMemFree(*second, gszGrid_006E0200, 0x1aa, 0);
        *second = 0;
    }
}

// build: context sub_00523350_Shim
// calling-convention shim (not game code)
void __cdecl sub_00523350_Shim(Byte** first, Byte** second)
{
    sub_00523350_CopyOutputs(first, second);
}

// 0x00523420
static __forceinline void sub_00523420_FreeStringPair(char* szFirst, char* szSecond)
{
    if (szFirst)
    {
        memset(szFirst, 0, SStrLen(szFirst));
        SMemFree(szFirst, ".\\grid.cpp", 0x1B8, 0);
    }
    if (szSecond)
    {
        memset(szSecond, 0, SStrLen(szSecond));
        SMemFree(szSecond, ".\\grid.cpp", 0x1BE, 0);
    }
}

// 0x00523AC0
static __forceinline void sub_00523AC0_InitHashCtx(D2BnHashCtxStrc* pCtx)
{
    pCtx->aState[0] = 0x67452301;
    pCtx->aState[1] = 0xEFCDAB89;
    pCtx->aState[2] = 0x98BADCFE;
    pCtx->aState[3] = 0x10325476;
    pCtx->aState[4] = 0xC3D2E1F0;
    pCtx->nBitCountLo = 0;
    pCtx->nBitCountHi = 0;
}

void __fastcall sub_M103_Emit_00523420(char* szFirst, char* szSecond, D2BnHashCtxStrc* pCtx)
{
    sub_00523AC0_InitHashCtx(pCtx);
    sub_00523420_FreeStringPair(szFirst, szSecond);
}

unsigned int gnSize_00882740; // 0x00882740

void* gpCDKeyHandle_00882744; // 0x00882744

unsigned int gnSize_00882748; // 0x00882748

void* gpHandle_0088274C; // 0x0088274C

void* gpCDKeyHandle_00882750; // 0x00882750

unsigned int gnSize_00882754; // 0x00882754

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

#include "gen/data/Source/D2BNClient/grid.inc"
