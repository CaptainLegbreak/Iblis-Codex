struct D2FileTimeStrc { unsigned long dwLowDateTime, dwHighDateTime; };
struct D2NewsItemStrc { unsigned int nFlags, nStamp; char szText[1024]; };
struct D2StormArray408Strc
{
    unsigned int f_0, f_4;
    D2NewsItemStrc* f_8;
    unsigned int f_C;
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount); // 0x0051D2F0
    void sub_0051D5D0_ReallocData(unsigned int nCount); // 0x0051D5D0
    void sub_0051D810_SetCount(unsigned int nCount); // 0x0051D810
};
int __fastcall sub_00519920_LoadCachedFile(const char*, D2FileTimeStrc*, void**, unsigned int*); // 0x00519920
int __stdcall SMemFree(void*, const char*, int, unsigned int); // 0x00412650
extern const char* gszNewsFile_0072FF80; // 0x0072FF80
extern const char gszNewsItemTypeName_0072FF8C[]; // 0x0072FF8C
D2StormArray408Strc gtNewsItems_00881C30;        // 0x00881C30
unsigned int gnNewsFirstIndex_00881C40;        // 0x00881C40
unsigned int gnNewsNewest_00881C44;        // 0x00881C44

extern "C" unsigned int __cdecl strlen(const char* pString);
extern "C" char* __cdecl strcpy(char* pDest, const char* pSource);

// 0x0051DA30
int __cdecl sub_0051DA30_LoadNews()
{
    D2FileTimeStrc fileTime;
    unsigned int nSize;
    int bResult = 0;
    void* pData = 0;
    if (sub_00519920_LoadCachedFile(gszNewsFile_0072FF80, &fileTime, &pData, &nSize))
    {
        const char* p = (const char*)pData;
        gnNewsNewest_00881C44 = *(const unsigned int*)p;
        p += sizeof(unsigned int);
        unsigned int nCount = *(const unsigned int*)p;
        p += sizeof(unsigned int);
        if (nCount <= 256)
        {
            gtNewsItems_00881C30.sub_0051D810_SetCount(0);
            if (gtNewsItems_00881C30.f_4 + nCount > gtNewsItems_00881C30.f_0)
                gtNewsItems_00881C30.sub_0051D5D0_ReallocData(gtNewsItems_00881C30.f_4 + nCount);
            gnNewsFirstIndex_00881C40 = 0;
            unsigned int nLastStamp = 0;
            unsigned int i;
            for (i = 0; i < nCount; ++i)
            {
                unsigned int nNewCount = gtNewsItems_00881C30.f_4 + 1;
                if (nNewCount > gtNewsItems_00881C30.f_0)
                {
                    unsigned int nChunk = gtNewsItems_00881C30.f_C;
                    if (!nChunk) nChunk = gtNewsItems_00881C30.sub_0051D2F0_CalcChunkSize(nNewCount);
                    unsigned int nAlloc = nNewCount;
                    const unsigned int nRemainder = nNewCount % nChunk;
                    if (nRemainder) nAlloc = nNewCount + nChunk - nRemainder;
                    gtNewsItems_00881C30.sub_0051D5D0_ReallocData(nAlloc);
                }
                D2NewsItemStrc* pItem = &gtNewsItems_00881C30.f_8[gtNewsItems_00881C30.f_4++];
                pItem->nFlags = 0;
                pItem->nStamp = *(const unsigned int*)p;
                p += sizeof(unsigned int);
                int nLength = strlen(p);
                if (nLength >= 1024) goto Cleanup;
                strcpy(pItem->szText, p);
                p += nLength + 1;
                if (nLastStamp > pItem->nStamp) break;
                nLastStamp = pItem->nStamp;
            }
            bResult = i == nCount;
        }
    }
Cleanup:
    if (!bResult)
    {
        if (gtNewsItems_00881C30.f_8)
            SMemFree(gtNewsItems_00881C30.f_8, gszNewsItemTypeName_0072FF8C, -2, 0);
        gtNewsItems_00881C30.f_0 = 0;
        gtNewsItems_00881C30.f_4 = 0;
        gtNewsItems_00881C30.f_8 = 0;
        gnNewsFirstIndex_00881C40 = 0;
        gnNewsNewest_00881C44 = 0;
    }
    if (pData) SMemFree(pData, ".\\BNNews.cpp", 299, 0);
    return bResult;
}
