struct Unicode
{
    unsigned short wChar;
};

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0
extern "C" const char gszOpenBracket_006E6438[];                                                            // 0x006E6438
extern "C" const char gszCloseBracket_006E6434[];                                                           // 0x006E6434
const Unicode* __fastcall D2LANG_GetStringByReferenceString(const char* szKey);                                       // 0x00524E20
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

// 0x00612600
void __fastcall sub_00612600(void* pTable, int nRecordCount, int nRecordSize, int nNameOffset, int a5, int nNameLength)
{
    Unicode wszClass[512];
    Unicode wszName[512];
    for (int n = 0; n < 512; ++n)
    {
        wszClass[n].wChar = 0;
    }
    for (int n = 0; n < 512; ++n)
    {
        wszName[n].wChar = 0;
    }
    Unicode wszOpen[16] = {};
    Unicode wszClose[16] = {};

    sub_00526320_ToUnicode(wszOpen, gszOpenBracket_006E6438, 16);
    sub_00526320_ToUnicode(wszClose, gszCloseBracket_006E6434, 16);

    for (int i = 0; i < nRecordCount; ++i)
    {
        char* pRecord = (char*)pTable + i * nRecordSize;
        memset(pRecord + a5, 0, nNameLength);

        const Unicode* pString = D2LANG_GetStringByReferenceString(pRecord + nNameOffset);
        if (!pString)
        {
            sub_005267E0(wszClass, wszOpen);
            sub_00526320_ToUnicode(wszName, pRecord + nNameOffset, nNameLength - 1);
            sub_00526700(wszClass, wszName);
            sub_00526700(wszClass, wszClose);
            sub_00526790((Unicode*)(pRecord + a5), wszClass, nNameLength);
        }
        else
        {
            sub_00526790((Unicode*)(pRecord + a5), pString, nNameLength);
        }
    }
}
