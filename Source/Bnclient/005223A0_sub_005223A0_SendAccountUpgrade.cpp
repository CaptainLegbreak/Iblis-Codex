struct D2BigLoginRecordStrc
{
    char szName[0x20];
    char szPassword[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abProof[0x14];
};

struct D2BigPowModStrc;

struct D2BigPairStrc
{
    D2BigPowModStrc* pState;
    void sub_00528660_MakeVerifier(const char* szName, const char* szPassword, unsigned char* pSalt, unsigned char* pVerifier); // 0x00528660
};

int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0

int gdwGlobal_00882538;                                                                                     // 0x00882538
extern unsigned char gabNewVerifier_00882640[0x40];                                                         // 0x00882640
extern D2BigLoginRecordStrc gtLoginRecord_00882680;                                                         // 0x00882680
extern D2BigPairStrc gtBigPair_0088273C;                                                                    // 0x0088273C

// 0x005223A0
int __fastcall sub_005223A0_SendAccountUpgrade(int bRetry)
{
    if (bRetry && (unsigned int)++gdwGlobal_00882538 > 1)
        return 0;

    gtBigPair_0088273C.sub_00528660_MakeVerifier(gtLoginRecord_00882680.szName, gtLoginRecord_00882680.szPassword, gabNewVerifier_00882640, gabNewVerifier_00882640 + 0x20);
    sub_0051C5C0_SendPacket(0x57, 0, 0);
    return 1;
}
