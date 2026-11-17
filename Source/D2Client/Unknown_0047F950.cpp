#include "D2Client.h"

void __cdecl sub_K04_EmitUse(int* pValue);

// 0x0047F950
static int __stdcall sub_0047F950_CheckBlockSignature(const char* pEnd, const char* pBegin, int* pSize, const char* pBase)
{
    *pSize = pEnd - pBegin - 4;
    if (pEnd >= pBegin + 4)
    {
        unsigned int dwTag;
        SMemCopy(&dwTag, pBase + *pSize, 4);
        return dwTag == 0x5349474E;
    }
    return 0;
}

int __cdecl sub_K04_EmitCheckBlockSignature(const char* pBegin, const char* pEnd, const char* pBase)
{
    int nSize;
    const int bOk = sub_0047F950_CheckBlockSignature(pEnd, pBegin, &nSize, pBase);
    sub_K04_EmitUse(&nSize);
    return bOk;
}
