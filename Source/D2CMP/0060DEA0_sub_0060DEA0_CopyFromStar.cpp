// 0x0060DEA0
void __stdcall sub_0060DEA0_CopyFromStar(const char* szSource, char* szDest, unsigned int nSize)
{
    for (unsigned int i = 0; szSource[i]; ++i)
    {
        if (szSource[i] == '*')
        {
            unsigned int n = i;
            for (; szSource[n] && n - i <= 16 && n < nSize - 1; ++n)
            {
                szDest[n - i] = szSource[n];
            }
            szDest[n] = 0;
            return;
        }
    }
}
