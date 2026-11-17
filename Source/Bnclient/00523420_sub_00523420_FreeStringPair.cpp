struct D2BnHashCtxStrc
{
    unsigned int aState[5];
    int nBitCountLo;
    int nBitCountHi;
    unsigned int f_1C[16];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

// 0x00523420
static __forceinline void sub_00523420_FreeStringPair(char* szFirst, char* szSecond)
{
    if (szFirst)
    {
        memset(szFirst, 0, SStrLen(szFirst));
        SMemFree(szFirst, ".\\grid.cpp", 0x1B8, 0);
    }
    if (szSecond)
    {
        memset(szSecond, 0, SStrLen(szSecond));
        SMemFree(szSecond, ".\\grid.cpp", 0x1BE, 0);
    }
}

// 0x00523AC0
static __forceinline void sub_00523AC0_InitHashCtx(D2BnHashCtxStrc* pCtx)
{
    pCtx->aState[0] = 0x67452301;
    pCtx->aState[1] = 0xEFCDAB89;
    pCtx->aState[2] = 0x98BADCFE;
    pCtx->aState[3] = 0x10325476;
    pCtx->aState[4] = 0xC3D2E1F0;
    pCtx->nBitCountLo = 0;
    pCtx->nBitCountHi = 0;
}

void __fastcall sub_M103_Emit_00523420(char* szFirst, char* szSecond, D2BnHashCtxStrc* pCtx)
{
    sub_00523AC0_InitHashCtx(pCtx);
    sub_00523420_FreeStringPair(szFirst, szSecond);
}
