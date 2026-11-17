#include "Storm.h"

typedef unsigned int size_t;
typedef unsigned char BOOLEAN;

struct D2ImageDosHeaderStrc
{
    unsigned short e_magic;
    unsigned short e_unk02[25];
    unsigned short e_res2[4];
    long e_lfanew;
};

struct D2ImageFileHeaderStrc
{
    unsigned short Machine;
    unsigned short NumberOfSections;
    unsigned long TimeDateStamp;
    unsigned long PointerToSymbolTable;
    unsigned long NumberOfSymbols;
    unsigned short SizeOfOptionalHeader;
    unsigned short Characteristics;
};

struct D2ImageDataDirStrc
{
    unsigned long VirtualAddress;
    unsigned long Size;
};

struct D2ImageOptionalHeaderStrc
{
    unsigned short Magic;
    unsigned char unk0x02[0x36];
    unsigned long SizeOfImage;
    unsigned char unk0x3C[0x20];
    unsigned long NumberOfRvaAndSizes;
    D2ImageDataDirStrc DataDirectory[16];
};

struct D2ImageOptionalHeader64Strc
{
    unsigned short Magic;
    unsigned char unk0x02[0x6A];
    unsigned long NumberOfRvaAndSizes;
    D2ImageDataDirStrc DataDirectory[16];
};

struct D2ImageNtHeadersStrc
{
    unsigned long Signature;
    D2ImageFileHeaderStrc FileHeader;
    D2ImageOptionalHeaderStrc OptionalHeader;
};

struct D2ImageDebugDirStrc
{
    unsigned long Characteristics;
    unsigned long TimeDateStamp;
    unsigned short MajorVersion;
    unsigned short MinorVersion;
    unsigned long Type;
    unsigned long SizeOfData;
    unsigned long AddressOfRawData;
    unsigned long PointerToRawData;
};

struct D2CvNb10Strc
{
    unsigned long dwCvSignature;
    unsigned long dwOffset;
    unsigned long dwSignature;
    unsigned long dwAge;
    char szPdbName[4];
};

struct D2CrashGuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct D2CvRsdsStrc
{
    unsigned long dwCvSignature;
    D2CrashGuidStrc tGuid;
    unsigned long dwAge;
    char szPdbName[4];
};

struct D2CrashModuleStrc
{
    void* f_0;
    unsigned long nSize;
    char szName[0x100];
    char szPath[0x100];
    unsigned long nTimeStamp;
    D2CrashGuidStrc tGuid;
    unsigned long nAge;
    unsigned long nUnknown220;
    unsigned long nVersion;
};

struct D2CrashModuleListStrc
{
    unsigned int nCount;
    D2CrashModuleStrc aModules[0x100];
};

struct D2ModuleStrc
{
    bool sub_00404AB0_VisitModule(void* pContext, const wchar_t* wszName, int nNameLength);                 // 0x00404AB0
};
extern "C" int __cdecl strncpy_s(char* szDest, size_t nDestSize, const char* szSource, size_t nCount);      // 0x006859D2
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);

BOOLEAN __stdcall sub_00404850_IsAtLeast1C(unsigned int nValue);
static bool __stdcall sub_004049A0_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage);
static bool sub_00404F80_ReadNb10(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv);
static bool sub_00404FF0_ReadRsds(const D2CvRsdsStrc* pCv, D2CrashModuleStrc* pModule);

static int sub_00404730_GetImageKind(const D2ImageOptionalHeaderStrc* pHeader)
{
    if (pHeader->Magic == 0x10B)
    {
        return 1;
    }
    if (pHeader->Magic == 0x20B)
    {
        return 2;
    }
    return 0;
}

static bool sub_00404760_IsDosHeaderValid(const D2ImageDosHeaderStrc* pImage)
{
    if (IsBadReadPtr(pImage, 0x40))
    {
        return false;
    }
    if (pImage->e_magic != 0x5A4D)
    {
        return false;
    }
    return true;
}

static __forceinline bool sub_00404780_IsNtHeaderValid(const D2ImageNtHeadersStrc* pNt)
{
    if (IsBadReadPtr(pNt, 4))
    {
        return false;
    }
    if (pNt->Signature != 0x4550)
    {
        return false;
    }
    if (IsBadReadPtr(&pNt->FileHeader, 0x14))
    {
        return false;
    }
    if (IsBadReadPtr(&pNt->OptionalHeader, pNt->FileHeader.SizeOfOptionalHeader))
    {
        return false;
    }
    if (!sub_00404730_GetImageKind(&pNt->OptionalHeader))
    {
        return false;
    }
    return true;
}

__declspec(noinline) static bool sub_004047D0_GetDebugDirectory(const D2ImageOptionalHeaderStrc* pHeader, unsigned long* pRva, unsigned long* pSize);
static bool sub_004047D0_GetDebugDirectory(const D2ImageOptionalHeaderStrc* pHeader, unsigned long* pRva, unsigned long* pSize)
{
    const int nKind = sub_00404730_GetImageKind(pHeader);
    if (!nKind)
    {
        return false;
    }
    *pRva = 0;
    *pSize = -1;
    unsigned long nRva;
    unsigned long nSize;
    if (nKind == 2)
    {
        const D2ImageOptionalHeader64Strc* pHeader64 = (const D2ImageOptionalHeader64Strc*)pHeader;
        if (pHeader64->NumberOfRvaAndSizes <= 6)
        {
            return false;
        }
        nSize = pHeader64->DataDirectory[6].Size;
        nRva = pHeader64->DataDirectory[6].VirtualAddress;
    }
    else
    {
        if (pHeader->NumberOfRvaAndSizes <= 6)
        {
            return false;
        }
        nSize = pHeader->DataDirectory[6].Size;
        nRva = pHeader->DataDirectory[6].VirtualAddress;
    }
    *pSize = nSize;
    *pRva = nRva;
    return (!nRva && !nSize) || (nRva && sub_00404850_IsAtLeast1C(*pSize));
}

BOOLEAN __stdcall sub_00404850_IsAtLeast1C(unsigned int nValue)
{
    return nValue >= 0x1C;
}

static void sub_00404860_SetNb10Info(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv)
{
    pModule->nTimeStamp = pCv->dwSignature;
    memset(&pModule->tGuid, 0, sizeof(pModule->tGuid));
}

static void sub_00404890_CopyRsdsGuid(D2CrashModuleStrc* pModule, const D2CvRsdsStrc* pCv)
{
    pModule->tGuid = pCv->tGuid;
}

static bool sub_004048C0_ReadCodeView(const unsigned long* pCv, D2CrashModuleStrc* pModule, unsigned int nSize)
{
    if (nSize < 4)
    {
        return false;
    }
    if (IsBadReadPtr(pCv, nSize))
    {
        return false;
    }
    if (*pCv == 0x3031424E)
    {
        return sub_00404F80_ReadNb10(pModule, (const D2CvNb10Strc*)pCv);
    }
    if (*pCv == 0x53445352)
    {
        return sub_00404FF0_ReadRsds((const D2CvRsdsStrc*)pCv, pModule);
    }
    return false;
}

static bool __stdcall sub_00404900_FindCodeView(const D2ImageDosHeaderStrc* pImage, const D2ImageDebugDirStrc* pDirs, D2CrashModuleStrc* pModule, unsigned long nSize)
{
    const unsigned int nCount = nSize / sizeof(D2ImageDebugDirStrc);
    for (unsigned int i = 0; i < nCount; i++)
    {
        const unsigned long* pData = (const unsigned long*)((const char*)pImage + pDirs[i].AddressOfRawData);
        if (pDirs[i].Type == 2 && sub_004048C0_ReadCodeView(pData, pModule, pDirs[i].SizeOfData))
        {
            return true;
        }
    }
    return false;
}

// 0x004049A0
static bool __stdcall sub_004049A0_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage)
{
    pModule->f_0 = (void*)pImage;
    if (!sub_00404760_IsDosHeaderValid(pImage))
    {
        return false;
    }
    const D2ImageNtHeadersStrc* pNt = (const D2ImageNtHeadersStrc*)((const char*)pImage + pImage->e_lfanew);
    if (!sub_00404780_IsNtHeaderValid(pNt))
    {
        return false;
    }
    pModule->nSize = pNt->OptionalHeader.SizeOfImage;
    pModule->nUnknown220 = pNt->FileHeader.TimeDateStamp;
    if (pImage->e_res2[2] == 0xB74F && pImage->e_res2[3] == 0x2D98)
    {
        pModule->nVersion = (pImage->e_res2[1] << 16) + pImage->e_res2[0];
        if (pModule->nVersion)
        {
            pModule->nVersion *= 0xFDCA75BB;
        }
    }
    unsigned long nRva = 0;
    unsigned long nSize = 0;
    if (sub_004047D0_GetDebugDirectory(&pNt->OptionalHeader, &nRva, &nSize) && nRva && nSize)
    {
        const D2ImageDebugDirStrc* pDirs = (const D2ImageDebugDirStrc*)((const char*)pImage + nRva);
        if (!IsBadReadPtr(pDirs, nSize) && sub_00404850_IsAtLeast1C(nSize))
        {
            sub_00404900_FindCodeView(pImage, pDirs, pModule, nSize);
        }
    }
    return true;
}

bool D2ModuleStrc::sub_00404AB0_VisitModule(void* pContext, const wchar_t* wszName, int nNameLength)
{
    D2CrashModuleStrc tModule;
    tModule.f_0 = 0;
    tModule.nSize = 0;
    tModule.nTimeStamp = 0;
    memset(&tModule.tGuid, 0, sizeof(tModule.tGuid));
    tModule.nAge = 0;
    tModule.nUnknown220 = 0;
    tModule.nVersion = 0;
    tModule.szName[0] = 0;
    tModule.szPath[0] = 0;
    const int nLength = WideCharToMultiByte(0xFDE9, 0, wszName, nNameLength, tModule.szName, sizeof(tModule.szName), 0, 0);
    if (nLength < 0)
    {
        tModule.szName[0] = 0;
    }
    else if (nLength > sizeof(tModule.szName) - 1)
    {
        tModule.szName[sizeof(tModule.szName) - 1] = 0;
    }
    else
    {
        tModule.szName[nLength] = 0;
    }
    char* pName = 0;
    char* pSep = strrchr(tModule.szName, '/');
    if (pSep > pName)
    {
        pName = pSep;
    }
    pSep = strrchr(tModule.szName, '\\');
    if (pSep && pSep > pName)
    {
        pName = pSep;
    }
    pSep = strrchr(tModule.szName, ':');
    if (pSep && pSep > pName)
    {
        pName = pSep;
    }
    pName = pName ? pName + 1 : tModule.szName;
    memcpy(tModule.szName, pName, sizeof(tModule.szName));
    if (!sub_004049A0_ReadImageInfo(&tModule, (const D2ImageDosHeaderStrc*)this))
    {
        return true;
    }
    D2CrashModuleListStrc* pList = (D2CrashModuleListStrc*)pContext;
    if (!pList)
    {
        return false;
    }
    pList->aModules[pList->nCount] = tModule;
    ++pList->nCount;
    return pList->nCount < 0x100;
}

static bool sub_00404F80_ReadNb10(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv)
{
    if (IsBadReadPtr(pCv, 0x14))
    {
        return false;
    }
    if (IsBadStringPtrA(pCv->szPdbName, 0x104))
    {
        return false;
    }
    strncpy_s(pModule->szPath, sizeof(pModule->szPath), pCv->szPdbName, -1);
    pModule->nAge = pCv->dwAge;
    sub_00404860_SetNb10Info(pModule, pCv);
    return true;
}

static bool sub_00404FF0_ReadRsds(const D2CvRsdsStrc* pCv, D2CrashModuleStrc* pModule)
{
    if (IsBadReadPtr(pCv, 0x1C))
    {
        return false;
    }
    if (IsBadStringPtrA(pCv->szPdbName, 0x104))
    {
        return false;
    }
    strncpy_s(pModule->szPath, sizeof(pModule->szPath), pCv->szPdbName, -1);
    pModule->nAge = pCv->dwAge;
    sub_00404890_CopyRsdsGuid(pModule, pCv);
    return true;
}
