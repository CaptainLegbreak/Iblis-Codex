extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszExcelCppFile[];                                                                    // 0x006FC448

struct D2BinFileStrc
{
    char* pDataBuffer;
    char* pFirstRow;
    int nRecordCount;
    unsigned int nColumns;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413550
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                              // 0x0041D2A0

// 0x006BD640
D2BinFileStrc* __stdcall FOG_CreateBinFile(char* pDataBuffer, int nBufferSize)
{
    char* pCur = pDataBuffer;
    char* pEnd = pCur + nBufferSize;
    D2BinFileStrc* pBinFile = (D2BinFileStrc*)FOG_AllocPool(0, sizeof(D2BinFileStrc), gszExcelCppFile, 0x4D, 0);
    pBinFile->pDataBuffer = pCur;
    pBinFile->pFirstRow = 0;
    pBinFile->nRecordCount = 0;
    pBinFile->nColumns = 0;

    while (pCur < pEnd)
    {
        const char c = *pCur++;
        if (c == '\t')
        {
            pCur[-1] = 0;
            ++pBinFile->nColumns;
        }
        else if (c == '\r')
        {
            pCur[-1] = 0;
            D2_ASSERT(*pCur == '\n', 0x5C);
            ++pBinFile->nColumns;
            ++pCur;
            break;
        }
    }

    if (pCur >= pEnd)
    {
        FOG_Free(pBinFile->pDataBuffer, gszExcelCppFile, 0x9A, 0);
        FOG_FreePool(0, pBinFile, gszExcelCppFile, 0x9B, 0);
        return 0;
    }

    D2_ASSERT(pBinFile->nColumns <= 0x118, 0x67);
    pBinFile->pFirstRow = pCur;

    while (pCur < pEnd)
    {
        pDataBuffer = pCur;
        while (pCur < pEnd)
        {
            const char c = *pCur++;
            if (c == '\t')
            {
                pCur[-1] = 0;
            }
            else if (c == '\r')
            {
                pCur[-1] = 0;
                D2_ASSERT(*pCur == '\n', 0x75);
                ++pCur;
                ++pBinFile->nRecordCount;
                break;
            }
        }

        if (!SStrCmp(pDataBuffer, "Expansion", 10))
        {
            --pBinFile->nRecordCount;
            SMemCopy(pDataBuffer, pCur, pEnd - pCur);
            char* pNew = pDataBuffer;
            pEnd += pNew - pCur;
            pCur = pNew;
        }
    }

    return pBinFile;
}
