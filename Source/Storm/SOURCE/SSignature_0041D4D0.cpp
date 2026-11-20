#include "Storm.h"

struct D2StormBigStrc;

void __stdcall SBigNew(D2StormBigStrc** ppBig);                                                             // 0x00423950
void __stdcall SBigDel(D2StormBigStrc* pBig);                                                               // 0x00424E40
int __stdcall sub_00423850(void* hBig, const void* pData, unsigned int nSize);                              // 0x00423850
void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead);            // 0x00423B30
void __stdcall SBigPowMod(D2StormBigStrc* pResult, D2StormBigStrc* pBase, D2StormBigStrc* pExponent, D2StormBigStrc* pModulus); // 0x00425330

struct D2StormHandleStrc
{
    D2StormBigStrc* hHandle;

    D2StormHandleStrc()
    {
        SBigNew(&hHandle);
    }
    // 0x0041D330
    ~D2StormHandleStrc()
    {
        SBigDel(hHandle);
    }
    void* ReadFill(void* pBuffer, unsigned int nSize)
    {
        unsigned int nRead;
        SBigToBinaryBuffer(hHandle, pBuffer, nSize, &nRead);
        if (nRead < nSize)
            sub_0041D300_ZeroMemory((char*)pBuffer + nRead, nSize - nRead);
        return pBuffer;
    }
};

struct D2StormHandlePairStrc
{
    D2StormHandleStrc hFirst;
    D2StormHandleStrc hSecond;

    D2StormHandlePairStrc();
    ~D2StormHandlePairStrc();
    void sub_004260A0_PowModBuffer(void* pBuffer, unsigned int nSize);
};

// 0x0041D4D0
D2StormHandlePairStrc::D2StormHandlePairStrc()
{
}

// 0x0041D530
D2StormHandlePairStrc::~D2StormHandlePairStrc()
{
}

// 0x004260A0
void D2StormHandlePairStrc::sub_004260A0_PowModBuffer(void* pBuffer, unsigned int nSize)
{
    D2StormHandleStrc tInput;
    sub_00423850(tInput.hHandle, pBuffer, nSize);
    D2StormHandleStrc tOutput;
    SBigPowMod(tOutput.hHandle, tInput.hHandle, hSecond.hHandle, hFirst.hHandle);
    tOutput.ReadFill(pBuffer, nSize);
}
