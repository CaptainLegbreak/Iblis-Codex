struct D2BigLoginRecordStrc
{
    char szName[0x20];
    char szPassword[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abProof[0x14];
};

struct D2BnAccountLogonStrc
{
    unsigned char abPublic[0x20];
    char szAccountName[0x100];
};

extern D2BigLoginRecordStrc gtLoginRecord_00882680;                                                         // 0x00882680
char gszAccountName_00882540[0x100];                                                                        // 0x00882540
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x0041D2A0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize);           // 0x0051C5C0
void __cdecl sub_00524740_ClearKeySchedules();                                                              // 0x00524740
void __cdecl sub_005241A0_ClearHashContexts();                                                              // 0x005241A0

// 0x00522050
int __cdecl sub_00522050_SendAccountLogon()
{
    D2BnAccountLogonStrc tPacket;
    sub_0041D2A0_MemCopy(tPacket.abPublic, gtLoginRecord_00882680.abPublic, sizeof(tPacket.abPublic));
    const unsigned int nLength = SStrCopy(tPacket.szAccountName, gszAccountName_00882540, sizeof(tPacket.szAccountName));
    sub_0051C5C0_SendPacket(0x53, &tPacket, sizeof(tPacket.abPublic) + nLength + 1);
    return 1;
}

// 0x00522500
unsigned int __fastcall sub_00522500_GetNibble(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = (nIndex & 7) * 4;
    return (pKey[3 - (nIndex >> 3)] & (0xF << nShift)) >> nShift;
}

// 0x00522570
unsigned int __fastcall sub_00522570_GetBit(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = nIndex & 0x1F;
    return (pKey[3 - (nIndex >> 5)] & (1 << nShift)) >> nShift;
}

// 0x00522C20
void __cdecl sub_00522C20_ClearCryptState()
{
    sub_00524740_ClearKeySchedules();
    sub_005241A0_ClearHashContexts();
}
