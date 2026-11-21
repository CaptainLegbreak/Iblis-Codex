// 0x0060DE30
void __stdcall sub_0060DE30_CopyUntilStar(const char* szSource, char* szDest, unsigned int nSize)
{
	unsigned int i = 0;
	while (szSource[i] != '*' && szSource[i] && i <= 16 && i < nSize - 1)
	{
		szDest[i] = szSource[i];
		++i;
	}
	szDest[i] = 0;
}

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
