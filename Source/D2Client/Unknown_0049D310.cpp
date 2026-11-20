#include "D2Unicode.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __stdcall sub_L04_EmitUse(const Unicode* pText);

// 0x0049D310
static __declspec(noinline) void __stdcall sub_0049D310_CopyTextLine(Unicode* pDest, int nMax, const Unicode** ppSrc)
{
    int i = 0;
    memset(pDest, 0, nMax * sizeof(Unicode));
    for (; i < nMax; ++i)
    {
        if ((*ppSrc)->wChar == 0x0A)
            break;
        pDest[i].wChar = (*ppSrc)->wChar;
        ++*ppSrc;
    }
    if (i < nMax)
    {
        const Unicode* pNext = *ppSrc;
        if (pNext->wChar == 0x0A)
            *ppSrc = pNext + 1;
    }
}

// build: context sub_L04_EmitCopyTextLine
void __stdcall sub_L04_EmitCopyTextLine(const Unicode* pText)
{
    const Unicode* p = pText;
    while (p->wChar)
    {
        Unicode wszLine[0x20];
        sub_0049D310_CopyTextLine(wszLine, 0x20, &p);
        sub_L04_EmitUse(wszLine);
    }
}
