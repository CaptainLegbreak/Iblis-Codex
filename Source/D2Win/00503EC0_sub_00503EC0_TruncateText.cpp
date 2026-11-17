struct Unicode
{
    unsigned short wChar;
};

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength);                                        // 0x005017D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70

// 0x00503EC0
int __stdcall sub_00503EC0_TruncateText(Unicode* wszText, int nMaxWidth)
{
    char szText[300];
    int nCount = 0;
    sub_00526F70(szText, wszText, 300);
    const int nLength = strlen(szText);
    int bTruncated = 0;
    while (nCount < nLength)
    {
        if (D2Win_10122(wszText, nCount + 1) >= nMaxWidth)
        {
            bTruncated = 1;
            break;
        }

        ++nCount;
    }

    szText[nCount] = 0;
    if (bTruncated)
    {
        strcat(szText, "...");
    }

    sub_00526F20_ToUnicode(wszText, szText, 299);
    return nCount;
}
