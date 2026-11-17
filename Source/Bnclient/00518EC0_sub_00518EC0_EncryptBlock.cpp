extern unsigned int* gpCacheTable_00881888; // 0x00881888

static __declspec(noinline) void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey);

// 0x00518EC0
static void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    unsigned int nCount = nLength >> 2;
    if (nCount != 0)
    {
        const unsigned int* pTable = gpCacheTable_00881888;
        do
        {
            --nCount;
            unsigned int ch = *pData;
            dwSeed += pTable[0x400 + (dwKey & 0xFF)];
            *pData = ch ^ (dwKey + dwSeed);
            dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
            dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
            ++pData;
        } while (nCount != 0);
    }
}

unsigned int __stdcall sub_00518FA0_HashString(unsigned int nHashType, const char* szString); // 0x00518FA0

// build: context sub_00518EC0_Shim
// calling-convention shim (not game code)
void __cdecl sub_00518EC0_Shim(unsigned int* pData, unsigned int nSize)
{
    sub_00518EC0_EncryptBlock(pData, nSize, sub_00518FA0_HashString(3, "x"));
}
