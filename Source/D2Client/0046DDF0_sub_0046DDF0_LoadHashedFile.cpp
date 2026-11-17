typedef unsigned int size_t;

struct D2HashedFileEntryStrc
{
    D2HashedFileEntryStrc* pNext;
    int nUnk0x04;
    int nSize;
    char szName[8];
    unsigned char* pData;
    unsigned char aHeader[2];
    unsigned char nCheck;
};

struct D2HashedFileStrc
{
    int f_0;
    unsigned char* pData;
    unsigned int nSize;
    D2HashedFileEntryStrc* f_C[0x200];
};

extern "C" size_t __cdecl strlen(const char* szString);
void* __stdcall sub_004FAC80();                                                                             // 0x004FAC80
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed);             // 0x00413CE0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern int gdwGlobal_007A8918;                                                                              // 0x007A8918
extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char gszPathFormat_006D4124[];                                                             // 0x006D4124
extern const char* gaszHashedFileNames_006D6C30[];                                                          // 0x006D6C30
extern D2HashedFileStrc gtHashedFile_007A78F0;                                                              // 0x007A78F0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0046DDF0
static void __stdcall sub_0046DDF0_LoadHashedFile(D2HashedFileStrc* pTable, const char* szFile)
{
    if (pTable->f_0)
    {
        return;
    }
    pTable->pData = (unsigned char*)sub_00517079_LoadFile(sub_004FAC80(), szFile, &pTable->nSize, ".\\ENGINE\\Gfx.cpp", 267);
    D2_ASSERT(pTable->pData, 268);
    unsigned char* pCursor = pTable->pData;
    int nRemaining = pTable->nSize;
    gdwGlobal_007A8918 += nRemaining;
    while (nRemaining)
    {
        D2HashedFileEntryStrc* pEntry = (D2HashedFileEntryStrc*)pCursor;
        if (pEntry->nUnk0x04)
        {
            pEntry->nUnk0x04 = 0;
        }
        D2_ASSERT(pEntry->nCheck <= 0x40, 294);
        pCursor += 0x18;
        pEntry->pData = pCursor;
        D2_ASSERT(strlen(pEntry->szName) < 8, 121);
        unsigned int nHash = SStrHash(pEntry->szName, 1, 0);
        unsigned int nBucket = nHash;
        for (int i = 0; i < 3; i++)
        {
            nBucket = (nBucket >> 8) ^ nHash;
        }
        nBucket &= 0x1FF;
        pEntry->pNext = pTable->f_C[nBucket];
        pTable->f_C[nBucket] = pEntry;
        pCursor += pEntry->nSize;
        nRemaining -= 0x18 + pEntry->nSize;
    }
    pTable->f_0 = 1;
}

// 0x0046F310
void __fastcall sub_0046F310_LoadGlobalHashedFile(unsigned char nIndex)
{
    char szPath[0x104];
    wsprintfA(szPath, gszPathFormat_006D4124, szDataGlobal_006D4118, gaszHashedFileNames_006D6C30[nIndex]);
    sub_0046DDF0_LoadHashedFile(&gtHashedFile_007A78F0, szPath);
}

#include "gen/data/Source/D2Client/0046DDF0_sub_0046DDF0_LoadHashedFile.inc"
