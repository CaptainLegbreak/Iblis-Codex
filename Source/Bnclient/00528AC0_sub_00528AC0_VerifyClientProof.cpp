extern "C" int __cdecl memcmp(const void* pBuffer1, const void* pBuffer2, unsigned int nSize);
extern "C" unsigned int __security_cookie;                                                                  // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie);                                   // 0x00681A48

struct D2BigServerRecordStrc
{
    unsigned char abSalt[0x20];
    unsigned char abVerifier[0x20];
    char szName[0x20];
    unsigned char abClientPublic[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abServerPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abProof[0x14];
};

struct D2BigServerHandlesStrc
{
    void* hClientPublic;
    void* hVerifier;
    void* hServerPublic;
    void* hPrivate;
};

struct D2BigPowModStrc
{
    int bValid;
    void* hBase;
    void* hModulus;

    void sub_00528030_HashToUInt(void* const& hBig, unsigned int* pValue);                                  // 0x00528030
    int sub_005281D0_ComputeServerKey(void* const& hClientPublic, void* const& hServerPublic, void* const& hSecret, void* const& hVerifier, void* const& hKey);
    void sub_005282A0_ComputeProof(const char* szName, const unsigned char* pSalt, const unsigned char* pClientPublic, const unsigned char* pServerPublic, const unsigned char* pKey, unsigned char* pProof); // 0x005282A0
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    int sub_00528AC0_VerifyClientProof(D2BigServerRecordStrc* pRecord, const unsigned char* pClientProof);
};

unsigned char* __fastcall sub_0052A120_HashInterleave(unsigned char* pDest, const unsigned char* pData, unsigned int nSize); // 0x0052A120
void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue);                                         // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize);                         // 0x0052A270
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize);            // 0x0052A2A0
int __fastcall sub_0052A600(void* pArg);                                                                    // 0x0052A600

int __fastcall sub_0052A2E0_BigCompare(void* hLeft, void* hRight);                                          // 0x0052A2E0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue);                            // 0x0052A2F0
void __fastcall sub_0052A370_BigOpUnsigned_423790(void* hResult, void* hLeft, unsigned int nValue);         // 0x0052A370
void __fastcall sub_0052A560_BigOpPair_424F10_424ED0(void* hResult, void* hLeft, void* hRight, void* hSecond); // 0x0052A560
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3);           // 0x0052A590
void __fastcall sub_0052A5B0_BigOpUnsigned_425330(void* hResult, void* hArg1, unsigned int nValue, void* hArg3); // 0x0052A5B0

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

// 0x00528AC0
int D2BigPairStrc::sub_00528AC0_VerifyClientProof(D2BigServerRecordStrc* pRecord, const unsigned char* pClientProof)
{
    unsigned char abKey[0x20];
    void* hKey = sub_0052A240_BigFromUnsigned(0);
    D2BigServerHandlesStrc tHandles;
    tHandles.hVerifier = sub_0052A270_BigFromBinary(pRecord->abVerifier, 0x20);
    tHandles.hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    tHandles.hServerPublic = sub_0052A270_BigFromBinary(pRecord->abServerPublic, 0x20);
    tHandles.hClientPublic = sub_0052A270_BigFromBinary(pRecord->abClientPublic, 0x20);
    pState->sub_005281D0_ComputeServerKey(tHandles.hClientPublic, tHandles.hServerPublic, tHandles.hPrivate, tHandles.hVerifier, hKey);
    sub_0052A600(tHandles.hClientPublic);
    sub_0052A600(tHandles.hServerPublic);
    sub_0052A600(tHandles.hPrivate);
    sub_0052A600(tHandles.hVerifier);
    const unsigned int nSize = sub_0052A2A0_BigToBinary(hKey, abKey, 0x20);
    sub_0052A600(hKey);
    sub_0052A120_HashInterleave(pRecord->abKey, abKey, nSize);
    pState->sub_005282A0_ComputeProof(pRecord->szName, pRecord->abSalt, pRecord->abClientPublic, pRecord->abServerPublic, pRecord->abKey, pRecord->abProof);
    return memcmp(pRecord->abProof, pClientProof, sizeof(pRecord->abProof)) == 0;
}
