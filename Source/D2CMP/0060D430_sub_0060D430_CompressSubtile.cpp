void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern const char gszSubTileFile_006E61F8[]; // 0x006E61F8
int __fastcall sub_0060D310_ScanRun(unsigned char nValue, const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D310
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D3A0
// 0x0060D430
unsigned char* __fastcall sub_0060D430_CompressSubtile(const unsigned char* pData, unsigned int* pSize)
{
    unsigned char* pBuffer;
    unsigned char* pOut;
    unsigned int nRow;
    const unsigned char* pNextRow;
    const unsigned char* pEnd;
    unsigned int nOpaque;
    unsigned int nTransparent;
    int bRunEnd;
    int bRestEnd;
    unsigned int i;
    unsigned int nSize;

    pBuffer = (unsigned char*)FOG_Alloc(0xC20, gszSubTileFile_006E61F8, 0x1C, 0);
    pOut = pBuffer;
    nRow = 0;
    pNextRow = pData + 32;
    pEnd = pData + 32;
    while (nRow < 32)
    {
        nTransparent = sub_0060D310_ScanRun(0, pData, pEnd, 127, &bRunEnd, &bRestEnd);
        pData += nTransparent;
        if (bRunEnd || bRestEnd)
        {
            *pOut++ = 0;
            *pOut++ = 0;
            pData = pNextRow;
            pNextRow += 32;
            pEnd += 32;
            ++nRow;
        }
        else if (nTransparent == 127)
        {
            *pOut++ = (unsigned char)nTransparent;
        }
        else
        {
            nOpaque = sub_0060D3A0_ScanOtherRun(pData, pEnd, 0, 127, &bRunEnd, &bRestEnd);
            *pOut++ = (unsigned char)nTransparent;
            *pOut++ = (unsigned char)nOpaque;
            for (i = 0; i < nOpaque; ++i)
            {
                *pOut++ = *pData++;
            }
            if (bRunEnd || bRestEnd)
            {
                *pOut++ = 0;
                *pOut++ = 0;
                pData = pNextRow;
                pNextRow += 32;
                pEnd += 32;
                ++nRow;
            }
        }
    }
    nSize = pOut - pBuffer;
    *pSize = nSize;
    return pBuffer;
}
