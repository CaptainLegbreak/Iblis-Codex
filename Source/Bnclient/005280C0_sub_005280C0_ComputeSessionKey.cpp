struct D2BigPowModStrc
{
    void* pUnknown0x00;
    void* hBase;
    void* hModulus;

    void sub_00528010_PowMod(void* const& hExp, void* const& hResult);                                      // 0x00528010
    void sub_00528030_HashToUInt(void* const& hBig, unsigned int* pValue);                                  // 0x00528030
    int sub_005280C0_ComputeSessionKey(void* const& hSecret, void* const& hPublic, void* const& hExp, void* const& hKey);
};

void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue);                                         // 0x0052A240
int __fastcall sub_0052A2E0_BigCompare(void* hLeft, void* hRight);                                          // 0x0052A2E0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue);                            // 0x0052A2F0
int __fastcall sub_0052A350_BigOp_423790(void* hResult, void* hLeft, void* hRight);                         // 0x0052A350
int __fastcall sub_0052A3B0_BigOp_423AC0(void* hResult, void* hLeft, void* hRight);                         // 0x0052A3B0
void __fastcall sub_0052A430_BigOpUnsigned_424F10(void* hResult, void* hLeft, unsigned int nValue);         // 0x0052A430
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3);           // 0x0052A590
int __fastcall sub_0052A600(void* pArg);                                                                    // 0x0052A600

// 0x005280C0
int D2BigPowModStrc::sub_005280C0_ComputeSessionKey(void* const& hSecret, void* const& hPublic, void* const& hExp, void* const& hKey)
{
    if (sub_0052A2E0_BigCompare(hPublic, hModulus) < 0)
    {
        if (sub_0052A2F0_BigCompareUnsigned(hPublic, 0))
        {
            unsigned int nScrambler;
            sub_00528030_HashToUInt(hPublic, &nScrambler);
            if (nScrambler)
            {
                void* hPower = sub_0052A240_BigFromUnsigned(0);
                void* hResult = hPower;
                sub_00528010_PowMod(hExp, hResult);
                void* hBase = sub_0052A240_BigFromUnsigned(0);
                void* hTemp = sub_0052A240_BigFromUnsigned(0);
                if (sub_0052A2E0_BigCompare(hPublic, hPower) < 0)
                {
                    sub_0052A350_BigOp_423790(hTemp, hPublic, hModulus);
                    sub_0052A3B0_BigOp_423AC0(hBase, hTemp, hPower);
                }
                else
                {
                    sub_0052A3B0_BigOp_423AC0(hBase, hPublic, hPower);
                }
                sub_0052A430_BigOpUnsigned_424F10(hTemp, hExp, nScrambler);
                sub_0052A350_BigOp_423790(hTemp, hTemp, hSecret);
                sub_0052A590_BigOp_425330(hKey, hBase, hTemp, hModulus);
                sub_0052A600(hTemp);
                sub_0052A600(hBase);
                sub_0052A600(hPower);
                return 1;
            }
        }
    }
    return 0;
}
