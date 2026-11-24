#include "Bnclient.h"
#include "D2BnCryptTypes.h"

struct D2Blob32Strc
{
    unsigned char abData[0x20];
};

struct D2BigRecordStrc
{
    D2Blob32Strc tFirst;
    D2Blob32Strc tSecond;
    char szName[0x20];
    D2Blob32Strc tThird;
};

void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3);           // 0x0052A590
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize);            // 0x0052A2A0
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize);                         // 0x0052A270
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue);                            // 0x0052A2F0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

// 0x00528010
void D2BigPowModStrc::sub_00528010_PowMod(void* const& hExp, void* const& hResult)
{
    sub_0052A590_BigOp_425330(hResult, hBase, hExp, hModulus);
}

// 0x00528550
int D2BigPairStrc::sub_00528550_ReadBoth(unsigned int* pnFirst, void* pFirst, unsigned int* pnSecond, void* pSecond)
{
    if (!pState->bValid)
        return 0;
    *pnFirst = sub_0052A2A0_BigToBinary(pState->hBase, pFirst, 0x20);
    *pnSecond = sub_0052A2A0_BigToBinary(pState->hModulus, pSecond, 0x20);
    return 1;
}

// 0x00528970
int __stdcall sub_00528970_FillRecord(D2BigRecordStrc* pRecord, const char* szName, const D2Blob32Strc* pFirst, const D2Blob32Strc* pSecond, const D2Blob32Strc* pThird)
{
    SStrCopy(pRecord->szName, szName, 0x7FFFFFFF);
    pRecord->tFirst = *pFirst;
    pRecord->tSecond = *pSecond;
    pRecord->tThird = *pThird;
    void* hBig = sub_0052A270_BigFromBinary(pThird, 0x20);
    const int nResult = sub_0052A2F0_BigCompareUnsigned(hBig, 0);
    GAME_DeleteBigNum(hBig);
    return nResult == 1;
}
