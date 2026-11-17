void __fastcall sub_00522BC0_FillRandomBytes(unsigned char* pBuffer, int nSize); // 0x00522BC0
unsigned int __fastcall sub_00522E10_Decrypt(unsigned char* pBuffer, unsigned int nSize, unsigned char* pKey); // 0x00522E10

// build: context sub_GetTerminatedLength
static __forceinline unsigned int sub_GetTerminatedLength(const unsigned char* pString, unsigned int nSize)
{
    unsigned int nMax = 0x80;
    unsigned int nLength = 0;
    if (nSize <= nMax)
    {
        nMax = nSize;
    }

    if (!nMax)
    {
        return 0;
    }

    do
    {
        --nMax;
        ++nLength;
        if (!*pString++)
        {
            return nLength;
        }
    }
    while (nMax);

    return 0;
}

static __declspec(noinline) int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize);

// 0x005232B0
static int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize)
{
    unsigned char aKey[20];
    sub_00522BC0_FillRandomBytes(aKey, sizeof(aKey));
    unsigned int nLength = sub_00522E10_Decrypt(pBuffer, nSize, aKey);
    if (!nLength)
    {
        return 0;
    }

    if (nLength >= nSize)
    {
        return 0;
    }

    pBuffer[nLength] = 0;
    ++nLength;
    if (!sub_GetTerminatedLength(pBuffer, nLength))
    {
        return 0;
    }

    return 1;
}

// build: context sub_005232B0_Shim
// calling-convention shim (not game code)
int __fastcall sub_005232B0_Shim(unsigned char* pBuffer, unsigned int nSize)
{
    return sub_005232B0_DecodeAndValidate(pBuffer, nSize);
}
