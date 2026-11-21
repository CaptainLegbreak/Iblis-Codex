#include "Fog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HandleTable006BCC10Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

struct D2HandleTable006BCC10Strc
{
    unsigned char unk_000[0x100];
    int nCount;
    int nStride;
    int bLive;
    unsigned char unk_10C[0x10];
    unsigned char* pEntries;
};

static void sub_006BCD50_MakeCode(const char* szText, char* szCode);

// 0x006BCC10
unsigned short* __fastcall sub_006BCC10_GetEntry(D2HandleTable006BCC10Strc* pTable, int nHandle)
{
    unsigned short* pResult = 0;
    if (nHandle != -1)
    {
        const short nIndex = (short)(nHandle >> 16);
        D2_ASSERT(nIndex >= 0 && nIndex < pTable->nCount, 0xDB);
        D2_ASSERT(pTable->bLive, 0xDE);
        unsigned short* pEntry = (unsigned short*)(pTable->pEntries + pTable->nStride * nIndex);
        const unsigned short nTag = (unsigned short)nHandle;
        if (*pEntry && (!nTag || *pEntry == nTag))
        {
            pResult = pEntry;
        }
    }
    return pResult;
}

// 0x006BCD50
static void sub_006BCD50_MakeCode(const char* szText, char* szCode)
{
    if (!szText[0])
    {
        szCode[0] = ' ';
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[0] = szText[0];
    if (!szText[1])
    {
        szCode[1] = ' ';
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[1] = szText[1];
    if (!szText[2])
    {
        szCode[2] = ' ';
        szCode[3] = ' ';
        return;
    }
    szCode[2] = szText[2];
    if (!szText[3])
    {
        szCode[3] = ' ';
        return;
    }
    szCode[3] = szText[3];
}

// calling-convention shim (not game code)
unsigned int __stdcall sub_006BCD50_Shim(const char* szText)
{
    unsigned int dwCode;
    sub_006BCD50_MakeCode(szText, (char*)&dwCode);
    return dwCode;
}
