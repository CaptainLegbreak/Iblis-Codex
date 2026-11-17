// 0x006C9A38
int __fastcall sub_006C9A38_StringLength(char* pString)
{
    int nLength = 0;
    while (*pString)
    {
        ++pString;
        ++nLength;
    }
    return nLength;
}
