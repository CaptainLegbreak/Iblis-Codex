#include "SRP.h"
#include "D2BnCryptTypes.h"

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020

// 0x005281D0
int D2BigPowModStrc::sub_005281D0_ComputeServerKey(void* const& hClientPublic, void* const& hServerPublic, void* const& hSecret, void* const& hVerifier, void* const& hKey)
{
    unsigned int nHash;
    sub_00528030_HashToUInt(hServerPublic, &nHash);
    const unsigned int nScrambler = nHash;
    if (!nScrambler)
        return 0;
    void* hTemp = sub_0052A240_BigFromUnsigned(0);
    sub_0052A5B0_BigOpUnsigned_425330(hTemp, hVerifier, nScrambler, hModulus);
    sub_0052A560_BigOpPair_424F10_424ED0(hTemp, hClientPublic, hTemp, hModulus);
    if (sub_0052A2F0_BigCompareUnsigned(hTemp, 1) <= 0)
    {
        sub_0052A600(hTemp);
        return 0;
    }
    void* hCheck = sub_0052A240_BigFromUnsigned(0);
    sub_0052A370_BigOpUnsigned_423790(hCheck, hTemp, 1);
    if (!sub_0052A2E0_BigCompare(hCheck, hModulus))
    {
        sub_0052A600(hCheck);
        sub_0052A600(hTemp);
        return 0;
    }
    sub_0052A600(hCheck);
    sub_0052A590_BigOp_425330(hKey, hTemp, hSecret, hModulus);
    sub_0052A600(hTemp);
    return 1;
}

// 0x00528500
D2BigPairStrc::D2BigPairStrc()
{
    void* pMemory = SMemAlloc(sizeof(D2BigPowModStrc), ".\\SRP.cpp", 0x157, 0);
    pState = pMemory ? new (pMemory) D2BigPowModStrc : 0;
}

static __declspec(noinline) int sub_005284F0_IsValid(D2BigPowModStrc* pState)
{
    return pState->bValid != 0;
}

// 0x005285A0
int D2BigPairStrc::sub_005285A0_Init(int nSize1, const unsigned char* pData1, int nSize2, const unsigned char* pData2)
{
    if (pState->bValid)
    {
        sub_0052A600(pState->hModulus);
        sub_0052A600(pState->hBase);
    }
    pState->hBase = sub_0052A270_BigFromBinary(pData1, nSize1);
    pState->hModulus = sub_0052A270_BigFromBinary(pData2, nSize2);
    pState->bValid = 1;
    if (!sub_005284F0_IsValid(pState))
    {
        sub_0052A600(pState->hModulus);
        sub_0052A600(pState->hBase);
        pState->bValid = 0;
    }
    return pState->bValid;
}

// 0x00528660
void D2BigPairStrc::sub_00528660_MakeVerifier(const char* szName, const char* szPassword, unsigned char* pSalt, unsigned char* pVerifier)
{
    sub_00527E70_RandomBytes(pSalt, 0x20);
    void* hExp;
    pState->sub_00527F40_ComputePrivateKey(pSalt, szName, szPassword, &hExp);
    void* hVerifier = sub_0052A240_BigFromUnsigned(0);
    {
        void* hResult = hVerifier;
        pState->sub_00528010_PowMod(hExp, hResult);
    }
    sub_0052A2A0_BigToBinary(hVerifier, pVerifier, 0x20);
    sub_0052A600(hExp);
    sub_0052A600(hVerifier);
}
