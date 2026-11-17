struct Unicode
{
    unsigned short wChar;
};

// 0x00526F70
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount)
{
    char* pCurrentDest = szDest;
    while (nCount > 1 && pSource->wChar != 0)
    {
        const Unicode* pCurrentSource = pSource++;
        *pCurrentDest = (char)pCurrentSource->wChar;
        --nCount;
        ++pCurrentDest;
    }
    *pCurrentDest = '\0';
    return szDest;
}
