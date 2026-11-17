typedef unsigned char Byte;
typedef unsigned int UInt;
void* __stdcall sub_00413020_Allocate(UInt size, const char* file, int line, UInt flags); // 0x00413020
int __stdcall SMemFree(void* buffer, const char* file, int line, UInt flags); // 0x00412650
void* __cdecl sub_006829C0_CopyBuffer(void* dest, const void* source, UInt size); // 0x006829C0
extern UInt gnSize_00882740; // 0x00882740
static const Byte* gpSource_00882744; // 0x00882744
extern UInt gnSize_00882748; // 0x00882748
static const Byte* gpSource_00882750; // 0x00882750
extern const char gszGrid_006E0200[]; // 0x006E0200

// calling-convention shim (not game code)
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

__declspec(noinline) static void __cdecl sub_00523350_CopyOutputs(Byte** first, Byte** second);
// 0x00523350
static void __cdecl sub_00523350_CopyOutputs(Byte** first, Byte** second)
{
    if (first)
    {
        Byte* allocated = (Byte*)sub_00413020_Allocate(gnSize_00882740, gszGrid_006E0200, 0x199, 0);
        *first = allocated;
        sub_006829C0_CopyBuffer(allocated, gpSource_00882744, gnSize_00882740);
    }
    if (second)
    {
        Byte* allocated = (Byte*)sub_00413020_Allocate(gnSize_00882748, gszGrid_006E0200, 0x19e, 0);
        *second = allocated;
        sub_006829C0_CopyBuffer(allocated, gpSource_00882750, gnSize_00882748);
    }
    if (first && !sub_005232B0_DecodeAndValidate(*first, gnSize_00882740))
    {
        SMemFree(*first, gszGrid_006E0200, 0x1a6, 0);
        *first = 0;
    }
    if (second && !sub_005232B0_DecodeAndValidate(*second, gnSize_00882748))
    {
        SMemFree(*second, gszGrid_006E0200, 0x1aa, 0);
        *second = 0;
    }
}

// build: context sub_00523350_Shim
// calling-convention shim (not game code)
void __cdecl sub_00523350_Shim(Byte** first, Byte** second)
{
    sub_00523350_CopyOutputs(first, second);
}
