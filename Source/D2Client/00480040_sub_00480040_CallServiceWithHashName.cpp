struct _FILETIME
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    void (__fastcall* pfnCall)(const char* szName, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
extern "C" __declspec(dllimport) void __stdcall GetSystemTimeAsFileTime(_FILETIME* pTime);                  // 0x006CC358

extern D2ClientServiceStrc* gpService_007BC998;                                                             // 0x007BC998

// 0x00480040
void __stdcall sub_00480040_CallServiceWithHashName(const unsigned char* pHash, int nArg2, int nArg3)
{
    char szName[40];
    for (unsigned int i = 0; i < 16; ++i)
        sprintf(&szName[i * 2], "%02x", pHash[i]);
    SStrCopy(&szName[32], ".mod", 5);
    if (!gpService_007BC998)
        return;
    _FILETIME tTime;
    GetSystemTimeAsFileTime(&tTime);
    gpService_007BC998->pfnCall(szName, nArg2, nArg3, &tTime, -1, -1);
}
