struct D2ScmdStrc
{
    char unk0x00[0x2C];
    char* szBuffer;
    unsigned int nBufferSize;
    char unk0x34[0x3C - 0x34];
    char* szName;
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

static __declspec(noinline) void __stdcall sub_006C3DA0_SetName(D2ScmdStrc* pScmd, const char* szName, unsigned int* pnLength);

// 0x006C3DA0
static void __stdcall sub_006C3DA0_SetName(D2ScmdStrc* pScmd, const char* szName, unsigned int* pnLength)
{
    *pnLength = SStrLen(szName);
    if (pScmd->szName)
    {
        SMemFree(pScmd->szName, ".\\SOURCE\\SCMD.CPP", 0x8B, 0);
    }
    pScmd->szName = (char*)SMemAlloc(SStrLen(szName) + 1, ".\\SOURCE\\SCMD.CPP", 0x8C, 0);
    SStrCopy(pScmd->szName, szName, 0x7FFFFFFF);
    if (pScmd->szBuffer)
    {
        SStrCopy(pScmd->szBuffer, szName, pScmd->nBufferSize);
    }
}

// build: context sub_006C3DA0_Shim
// calling-convention shim (not game code)
void __stdcall sub_006C3DA0_Shim(D2ScmdStrc* pScmd, const char* szName, unsigned int* pnLength)
{
    sub_006C3DA0_SetName(pScmd, szName, pnLength);
}
