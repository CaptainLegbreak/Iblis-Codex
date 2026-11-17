struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char f_1C[64];
};

struct D2BigLoginRecordStrc
{
    char szName[0x20];
    char szPassword[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abProof[0x14];
};

struct D2BigPowModStrc
{
    void* pUnknown0x00;
    void* hBase;
    void* hModulus;

    void sub_00527F40_ComputePrivateKey(const unsigned char* pSalt, const char* szName, const char* szPassword, void** phResult);
    void sub_005282A0_ComputeProof(const char* szName, const unsigned char* pSalt, const unsigned char* pClientPublic, const unsigned char* pServerPublic, const unsigned char* pKey, unsigned char* pProof);
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;

    void sub_00527E70_RandomBytes(unsigned char* pBuffer, unsigned int nSize);                              // 0x00527E70
    void sub_005286D0_InitLogin(D2BigLoginRecordStrc* pRecord, const char* szName, const char* szPassword);
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __fastcall sub_00529F50_Sha1Init(D2SrpSha1ContextStrc* pContext);                                      // 0x00529F50
void __fastcall sub_00529F80_Sha1Update(D2SrpSha1ContextStrc* pContext, const unsigned char* pData, unsigned int nLength); // 0x00529F80
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext);            // 0x0052A040
void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue);                                         // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize);                         // 0x0052A270
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize);            // 0x0052A2A0
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3);           // 0x0052A590
int __fastcall sub_0052A600(void* pArg);                                                                    // 0x0052A600

extern const char* gpszSrpSeparator_00730ADC;                                                               // 0x00730ADC

// 0x00527F40
void D2BigPowModStrc::sub_00527F40_ComputePrivateKey(const unsigned char* pSalt, const char* szName, const char* szPassword, void** phResult)
{
    D2SrpSha1ContextStrc tContext;
    unsigned char abDigest[0x14];
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)szName, SStrLen(szName));
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)gpszSrpSeparator_00730ADC, SStrLen(gpszSrpSeparator_00730ADC));
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)szPassword, SStrLen(szPassword));
    sub_0052A040_Sha1Final(abDigest, &tContext);
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, pSalt, 0x20);
    sub_00529F80_Sha1Update(&tContext, abDigest, 0x14);
    sub_0052A040_Sha1Final(abDigest, &tContext);
    *phResult = sub_0052A270_BigFromBinary(abDigest, 0x14);
}

// 0x005282A0
void D2BigPowModStrc::sub_005282A0_ComputeProof(const char* szName, const unsigned char* pSalt, const unsigned char* pClientPublic, const unsigned char* pServerPublic, const unsigned char* pKey, unsigned char* pProof)
{
    D2SrpSha1ContextStrc tContext;
    unsigned char abHashBase[0x14];
    unsigned char abBuffer[0x20];
    unsigned char abHash[0x14];

    unsigned int nLength = sub_0052A2A0_BigToBinary(hModulus, abBuffer, 0x20);
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, abBuffer, nLength);
    sub_0052A040_Sha1Final(abHash, &tContext);

    nLength = sub_0052A2A0_BigToBinary(hBase, abBuffer, 0x20);
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, abBuffer, nLength);
    sub_0052A040_Sha1Final(abHashBase, &tContext);

    for (int i = 0; i < 0x14; ++i)
        abBuffer[i] = abHashBase[i] ^ abHash[i];

    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)szName, SStrLen(szName));
    sub_0052A040_Sha1Final(abHash, &tContext);

    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, abBuffer, 0x14);
    sub_00529F80_Sha1Update(&tContext, abHash, 0x14);
    sub_00529F80_Sha1Update(&tContext, pSalt, 0x20);
    sub_00529F80_Sha1Update(&tContext, pClientPublic, 0x20);
    sub_00529F80_Sha1Update(&tContext, pServerPublic, 0x20);
    sub_00529F80_Sha1Update(&tContext, pKey, 0x28);
    sub_0052A040_Sha1Final(pProof, &tContext);
}

// 0x005286D0
void D2BigPairStrc::sub_005286D0_InitLogin(D2BigLoginRecordStrc* pRecord, const char* szName, const char* szPassword)
{
    SStrCopy(pRecord->szName, szName, 0x7FFFFFFF);
    SStrCopy(pRecord->szPassword, szPassword, 0x7FFFFFFF);
    sub_00527E70_RandomBytes(pRecord->abPrivate, 0x20);
    void* hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    void* hPublic = sub_0052A240_BigFromUnsigned(0);
    sub_0052A590_BigOp_425330(hPublic, pState->hBase, hPrivate, pState->hModulus);
    sub_0052A600(hPrivate);
    sub_0052A2A0_BigToBinary(hPublic, pRecord->abPublic, 0x20);
    sub_0052A600(hPublic);
}

#include "gen/data/Source/Bnclient/00527F40_sub_00527F40_ComputePrivateKey.inc"
