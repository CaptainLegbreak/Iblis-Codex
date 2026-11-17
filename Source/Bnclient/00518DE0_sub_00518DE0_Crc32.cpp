extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                         // 0x0041C340

extern unsigned int gdwCacheCrcTable_0072FB80[];                                                            // 0x0072FB80

#define VALIDATEBEGIN int nValid = -1
#define VALIDATE(x) nValid &= (x) ? -1 : 0
#define VALIDATEEND if (!nValid) { sub_0041C340_SetLastError(0x57); return 0; }

#define CACHE_CRC32(dwCrc, pBytes, nCount) \
    dwCrc = 0xFFFFFFFF; \
    for (; nCount; --nCount, ++pBytes) \
        dwCrc = (dwCrc >> 8) ^ gdwCacheCrcTable_0072FB80[(*pBytes ^ dwCrc) & 0xFF]; \
    dwCrc = ~dwCrc

// 0x00518DE0
static __declspec(noinline) unsigned int sub_00518DE0_Crc32(const void* pData, unsigned int nSize)
{
    VALIDATEBEGIN;
    VALIDATE(pData || !nSize);
    D2_ASSERT(pData || !nSize, 0x91);
    VALIDATEEND;

    const unsigned char* pBytes = (const unsigned char*)pData;
    unsigned int dwCrc;
    CACHE_CRC32(dwCrc, pBytes, nSize);
    return dwCrc;
}

unsigned int __cdecl sub_M294_Emit_00518DE0(const void* pData, unsigned int nSize)
{
    return sub_00518DE0_Crc32(pData, nSize);
}

#include "gen/data/Source/Bnclient/00518DE0_sub_00518DE0_Crc32.inc"
