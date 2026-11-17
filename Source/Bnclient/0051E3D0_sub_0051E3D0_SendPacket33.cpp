unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
int __fastcall sub_0051C5C0_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0

struct D2BnPacket33HeaderStrc
{
    int nValue;
    int nZero;
};

// 0x0051E3D0
int __fastcall sub_0051E3D0_SendPacket33(const char* szText, int nValue)
{
    D2BnPacket33HeaderStrc tHeader;
    char szPacketText[0x104];
    tHeader.nValue = nValue;
    tHeader.nZero = 0;
    char* pText = szPacketText;
    pText += SStrCopy(pText, szText, sizeof(szPacketText)) + 1;
    sub_0051C5C0_SendPacket(0x33, &tHeader, (unsigned int)(pText - (char*)&tHeader));
    return 1;
}
