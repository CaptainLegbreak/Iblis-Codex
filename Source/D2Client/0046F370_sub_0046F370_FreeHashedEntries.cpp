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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
D2HashedFileStrc gtHashedFile_007A8100;                                                                     // 0x007A8100
D2HashedFileStrc gtHashedFile_007A78F0;                                                                     // 0x007A78F0
int gdwGlobal_007A8918;                                                                                     // 0x007A8918
void* gpPoolBlock_007A80FC;                                                                                 // 0x007A80FC
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

// 0x0046F370
static void sub_0046F370_FreeHashedEntries(D2HashedFileStrc* pTable)
{
    for (int i = 0; i < 0x200; ++i)
    {
        D2HashedFileEntryStrc* pEntry = pTable->f_C[i];
        while (pEntry)
        {
            D2HashedFileEntryStrc* pNext = pEntry->pNext;
            if (pEntry->nUnk0x04 & 1)
            {
                unsigned char* pData = pEntry->pData;
                gdwGlobal_007A8918 -= pEntry->nSize + sizeof(D2HashedFileEntryStrc);
                FOG_Free(pData, ".\\ENGINE\\Gfx.cpp", 0xE3C, 0);
                FOG_Free(pEntry, ".\\ENGINE\\Gfx.cpp", 0xE3D, 0);
            }
            pEntry = pNext;
        }
    }
}

// 0x0046F3F0
void __cdecl sub_0046F3F0_FreeHashedFileA()
{
    sub_0046F370_FreeHashedEntries(&gtHashedFile_007A8100);
    gdwGlobal_007A8918 -= gtHashedFile_007A8100.nSize;
    if (gtHashedFile_007A8100.pData)
    {
        FOG_Free(gtHashedFile_007A8100.pData, ".\\ENGINE\\Gfx.cpp", 0xE50, 0);
    }
    memset(&gtHashedFile_007A8100, 0, sizeof(gtHashedFile_007A8100));
}

// 0x0046F440
void __cdecl sub_0046F440_FreeHashedFileB()
{
    sub_0046F370_FreeHashedEntries(&gtHashedFile_007A78F0);
    gdwGlobal_007A8918 -= gtHashedFile_007A78F0.nSize;
    if (gtHashedFile_007A78F0.pData)
    {
        FOG_Free(gtHashedFile_007A78F0.pData, ".\\ENGINE\\Gfx.cpp", 0xE61, 0);
    }
    memset(&gtHashedFile_007A78F0, 0, sizeof(gtHashedFile_007A78F0));
}

// 0x00470290
void __cdecl sub_00470290_FreeHashedFiles()
{
    sub_0046F3F0_FreeHashedFileA();
    sub_0046F440_FreeHashedFileB();
    if (gpPoolBlock_007A80FC)
    {
        FOG_FreePool(0, gpPoolBlock_007A80FC, ".\\ENGINE\\Gfx.cpp", 0x7F9, 0);
        gpPoolBlock_007A80FC = 0;
    }
}
