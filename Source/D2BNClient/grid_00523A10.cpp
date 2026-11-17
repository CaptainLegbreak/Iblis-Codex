// build: base-profile
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48
void __fastcall sub_00522BC0_FillRandomBytes(char* buffer, int size); // 0x00522BC0
unsigned int __fastcall sub_00522E10_DecodeHash(void* data, unsigned int size, const char* key); // 0x00522E10
int __stdcall SFileLoadFile(const char* filename, void** buffer, unsigned int* size, unsigned int extraSize, void* overlapped); // 0x0041B650
int __stdcall SFileUnloadFile(void* buffer); // 0x00416710

static inline unsigned int CountTerminatedBytes(unsigned char*& data, unsigned int length)
{
    unsigned int remaining = 128;
    unsigned int count = 0;
    if (length <= remaining)
    {
        remaining = length;
        if (!length)
            return 0;
    }
    do
    {
        unsigned char c = *data;
        --remaining;
        ++count;
        ++data;
        if (!c)
            return count;
    } while (remaining);
    return 0;
}
__declspec(noinline) static int sub_005232B0_DecodeAndValidate(unsigned char* data, unsigned int size);
// 0x005232B0
static int sub_005232B0_DecodeAndValidate(unsigned char* data, unsigned int size)
{
    char key[20];
    sub_00522BC0_FillRandomBytes(key, 20);
    unsigned int length = sub_00522E10_DecodeHash(data, size, key);
    if (!length)
        return 0;
    if (length >= size)
        return 0;
    data[length] = 0;
    ++length;
    unsigned int count = CountTerminatedBytes(data, length);
    if (!count)
        return 0;
    return 1;
}

// build: context sub_00523480_LoadAndDecode
void* __fastcall sub_00523480_LoadAndDecode(const char* filename, unsigned int* size)
{
    void* data;
    *size = 1024;
    SFileLoadFile(filename, &data, size, 1, 0);
    if (data && *size)
    {
        if (sub_005232B0_DecodeAndValidate((unsigned char*)data, *size))
            return data;
        if (data)
            SFileUnloadFile(data);
    }
    return 0;
}
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern unsigned int gnKeySize_00882740; // 0x00882740
extern const void* gpKeyData_00882744; // 0x00882744

// 0x00523A10
unsigned int __cdecl sub_00523A10_HashKey()
{
    char* szKey = (char*)SMemAlloc(gnKeySize_00882740, ".\\grid.cpp", 0x199, 0);
    memcpy(szKey, gpKeyData_00882744, gnKeySize_00882740);
    if (!sub_005232B0_DecodeAndValidate((unsigned char*)szKey, gnKeySize_00882740))
    {
        SMemFree(szKey, ".\\grid.cpp", 0x1A6, 0);
        szKey = 0;
    }
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    if (szKey)
    {
        memset(szKey, 0, SStrLen(szKey));
        SMemFree(szKey, ".\\grid.cpp", 0x1B8, 0);
    }
    return dwHash;
}
