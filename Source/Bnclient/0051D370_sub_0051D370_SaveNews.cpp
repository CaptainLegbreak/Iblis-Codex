typedef unsigned int size_t;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2Storm408ElemStrc
{
    int unk0x00;
    unsigned int nStamp;
    char szText[0x400];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;
};

extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) void __stdcall GetSystemTime(D2SystemTimeStrc* pSystemTime);               // 0x006CC38C

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall sub_00519DB0_HandOnDownload(const char* szFile, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, int nArg5, int nArg6); // 0x00519DB0

extern "C" const char gszBNNewsFile_006DF228[];                                                             // 0x006DF228
extern const char* gpszNewsName_0072FF80;                                                                   // 0x0072FF80
extern D2StormArray408Strc gtNewsItems_00881C30;                                                            // 0x00881C30
extern unsigned int gnNewsFirstIndex_00881C40;                                                              // 0x00881C40
extern unsigned int gnNewsCookie_00881C44;                                                                  // 0x00881C44

// build: context AddItemSize
static __forceinline bool AddItemSize(const D2Storm408ElemStrc* pItem, int* pnSize)
{
    *pnSize += sizeof(unsigned int);
    int nLen = strlen(pItem->szText);
    if (nLen >= 0x400)
        return false;
    *pnSize += nLen + 1;
    return true;
}

// 0x0051D370
int __cdecl sub_0051D370_SaveNews()
{
    unsigned int nEnd = gtNewsItems_00881C30.f_4;
    unsigned int nFirst = gnNewsFirstIndex_00881C40;
    unsigned int nCount = gtNewsItems_00881C30.f_4;
    unsigned int nNew = nCount - nFirst;
    D2_ASSERT(nNew < 0x100, 0x13B);

    int nSize = 8;
    int nLen;
    for (unsigned int i = nFirst; i < nCount; ++i)
    {
        if (!AddItemSize(&gtNewsItems_00881C30.f_8[i], &nSize))
            return 0;
    }

    char* pBuffer = (char*)FOG_Alloc(nSize, gszBNNewsFile_006DF228, 0x154, 0);
    if (pBuffer)
    {
        *(unsigned int*)pBuffer = gnNewsCookie_00881C44;
        char* pOut = pBuffer + 4;
        *(unsigned int*)pOut = nNew;
        pOut += 4;
        for (unsigned int i = gnNewsFirstIndex_00881C40; i < nEnd; ++i)
        {
            D2Storm408ElemStrc* pItem = &gtNewsItems_00881C30.f_8[i];
            *(unsigned int*)pOut = pItem->nStamp;
            pOut += 4;
            nLen = strlen(pItem->szText);
            strcpy(pOut, pItem->szText);
            pOut += nLen + 1;
        }

        D2SystemTimeStrc tSystemTime;
        D2FileTimeStrc tFileTime;
        GetSystemTime(&tSystemTime);
        SystemTimeToFileTime(&tSystemTime, &tFileTime);
        int nResult = sub_00519DB0_HandOnDownload(gpszNewsName_0072FF80, pBuffer, nSize, &tFileTime, -1, -1);
        FOG_Free(pBuffer, gszBNNewsFile_006DF228, 0x17B, 0);
        return nResult;
    }
    return 0;
}
