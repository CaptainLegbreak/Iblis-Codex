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
