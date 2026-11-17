typedef unsigned int size_t;

struct D2HashedFileEntryStrc
{
    D2HashedFileEntryStrc* pNext;
    unsigned int nFlags;
    int nSize;
    union
    {
        char szName[8];
        unsigned int dwName[2];
    };
    unsigned char* pData;
    int nUnk0x18;
};

struct D2HashedFileStrc
{
    int f_0;
    unsigned char* pData;
    unsigned int nSize;
    D2HashedFileEntryStrc* f_C[0x200];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);
extern "C" char* __cdecl _strlwr(char* szString);
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void* __stdcall D2Win_GetArchive();                                                                         // 0x004FAC80
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine);
extern int gdwGlobal_007A8918;                                                                              // 0x007A8918
extern D2HashedFileStrc gtHashedFile_007A78F0;
void __stdcall sub_M274_EmitBuildPath(char* szPath, int nMode);

static __declspec(noinline) unsigned int sub_0046DB90_HashName(const char* szName)
{
    D2_ASSERT(strlen(szName) < 8, 0x79);
    const unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nBucket = (nHash >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    return nBucket & 0x1FF;
}

// 0x0046DBF0
static __declspec(noinline) void __fastcall sub_0046DBF0_GetBaseName(const char* szPath, char* szDest)
{
    const int nPathLength = strlen(szPath);
    if (szPath[nPathLength - 4] == 0x2E)
    {
        const char* pExt = szPath + nPathLength - 4;
        int nLength = 0;
        while (*pExt != 0x5C)
        {
            --pExt;
            ++nLength;
        }
        --nLength;
        strncpy(szDest, pExt + 1, nLength);
        szDest[nLength] = 0;
    }
}

// 0x0046DC40
D2HashedFileEntryStrc* __stdcall sub_0046DC40_FindHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    sub_0046DBF0_GetBaseName(szPath, szName);
    _strlwr(szName);
    for (D2HashedFileEntryStrc* pEntry = pTable->f_C[sub_0046DB90_HashName(szName)]; pEntry; pEntry = pEntry->pNext)
    {
        if (*(unsigned int*)&szName[0] == pEntry->dwName[0] && *(unsigned int*)&szName[4] == pEntry->dwName[1])
        {
            return pEntry;
        }
    }
    return 0;
}

// 0x0046DCC0
static D2HashedFileEntryStrc* __stdcall sub_0046DCC0_LoadHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    char* pName = szName;
    sub_0046DBF0_GetBaseName(szPath, pName);
    _strlwr(pName);
    if (!sub_0046DC40_FindHashedEntry(pTable, pName))
    {
        D2HashedFileEntryStrc* pEntry = (D2HashedFileEntryStrc*)FOG_Alloc(sizeof(D2HashedFileEntryStrc), ".\\ENGINE\\Gfx.cpp", 0xDC, 0);
        memset(pEntry, 0, sizeof(D2HashedFileEntryStrc));
        pEntry->nFlags |= 1;
        strcpy(pEntry->szName, szName);
        pEntry->pData = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szPath, (unsigned int*)&pEntry->nSize, ".\\ENGINE\\Gfx.cpp", 0xE0);
        if (!pEntry->pData)
        {
            return 0;
        }

        D2_ASSERT(pEntry->pData[2] <= 0x40, 0xEC);
        const unsigned int nBucket = sub_0046DB90_HashName(szName);
        pEntry->pNext = pTable->f_C[nBucket];
        pTable->f_C[nBucket] = pEntry;
        gdwGlobal_007A8918 += pEntry->nSize + sizeof(D2HashedFileEntryStrc);
        return pEntry;
    }
    return 0;
}

int __stdcall sub_M274_Emit_0046DCC0(int nMode, int nUnused)
{
    char szPath[0x110];
    sub_M274_EmitBuildPath(szPath, nMode);
    D2HashedFileStrc* const pTable = &gtHashedFile_007A78F0;
    if (!sub_0046DC40_FindHashedEntry(pTable, szPath))
    {
        if (!sub_0046DCC0_LoadHashedEntry(pTable, szPath))
            return 0;
    }
    return 3;
}
