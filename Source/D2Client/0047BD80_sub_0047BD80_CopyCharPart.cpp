extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

// 0x0047BD80
static void sub_0047BD80_CopyCharPart(char* szDest, const char* szSource);

static __declspec(noinline) void sub_0047BD80_CopyCharPart(char* szDest, const char* szSource)
{
    if (*szSource != 0x2A)
    {
        const char* p = SStrChr(szSource, 0x2A);
        if (p)
        {
            memcpy(szDest, szSource, p - szSource);
            szDest[p - szSource] = 0;
            return;
        }
        SStrCopy(szDest, szSource, 0x7FFFFFFF);
        return;
    }
    SStrCopy(szDest, szSource, 0x7FFFFFFF);
}

void __cdecl sub_M04_Emit_0047BD80(char* szDest, const char* szSource)
{
    sub_0047BD80_CopyCharPart(szDest, szSource);
}
