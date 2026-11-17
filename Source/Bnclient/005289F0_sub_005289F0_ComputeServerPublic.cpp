struct D2BigServerRecordStrc
{
    unsigned char abSalt[0x20];
    unsigned char abVerifier[0x20];
    char szName[0x20];
    unsigned char abClientPublic[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abServerPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abClientProof[0x14];
    unsigned char abServerProof[0x14];
};

struct D2BigPowModStrc
{
    void* pUnknown0x00;
    void* hBase;
    void* hModulus;

    void sub_00528480_HashThreeBlocks(const unsigned char* pFirst, const unsigned char* pSecond, const unsigned char* pThird, unsigned char* pDigest); // 0x00528480
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    void sub_00527E70_RandomBytes(unsigned char* pBuffer, unsigned int nSize);                              // 0x00527E70
    void sub_005289F0_ComputeServerPublic(D2BigServerRecordStrc* pRecord);
    void sub_00528C60_ComputeServerProof(D2BigServerRecordStrc* pRecord);
};

void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue);                                         // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize);                         // 0x0052A270
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize);            // 0x0052A2A0
int __fastcall sub_0052A2E0_BigCompare(void* hLeft, void* hRight);                                          // 0x0052A2E0
int __fastcall sub_0052A350_BigOp_423790(void* hResult, void* hLeft, void* hRight);                         // 0x0052A350
int __fastcall sub_0052A3B0_BigOp_423AC0(void* hResult, void* hLeft, void* hRight);                         // 0x0052A3B0
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3);           // 0x0052A590
int __fastcall sub_0052A600(void* pArg);                                                                    // 0x0052A600

// 0x005289F0
void D2BigPairStrc::sub_005289F0_ComputeServerPublic(D2BigServerRecordStrc* pRecord)
{
    void* hVerifier = sub_0052A270_BigFromBinary(pRecord->abVerifier, 0x20);
    sub_00527E70_RandomBytes(pRecord->abPrivate, 0x20);
    void* hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    void* hPublic = sub_0052A240_BigFromUnsigned(0);
    sub_0052A590_BigOp_425330(hPublic, pState->hBase, hPrivate, pState->hModulus);
    sub_0052A350_BigOp_423790(hPublic, hPublic, hVerifier);
    while (sub_0052A2E0_BigCompare(hPublic, pState->hModulus) > 0)
        sub_0052A3B0_BigOp_423AC0(hPublic, hPublic, pState->hModulus);
    sub_0052A600(hPrivate);
    sub_0052A600(hVerifier);
    sub_0052A2A0_BigToBinary(hPublic, pRecord->abServerPublic, 0x20);
    sub_0052A600(hPublic);
}

// 0x00528C60
void D2BigPairStrc::sub_00528C60_ComputeServerProof(D2BigServerRecordStrc* pRecord)
{
    pState->sub_00528480_HashThreeBlocks(pRecord->abClientPublic, pRecord->abClientProof, pRecord->abKey, pRecord->abServerProof);
}
