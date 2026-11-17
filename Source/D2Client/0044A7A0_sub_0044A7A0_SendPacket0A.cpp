#pragma pack(push, 1)
struct D2McpPacket0AStrc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket18Strc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket10Strc
{
    unsigned char f_0;
    int nValueB0;
    int nValue88;
    int f_9;
    int nCode;
};

struct D2McpPacket05Strc
{
    unsigned char f_0;
    unsigned short f_1;
    int nValue;
    unsigned char nCount;
    int nToken;
    char szData[1];
};
#pragma pack(pop)

struct D2McpInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int unk0x04;
    int nValue;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nByte0E;
    unsigned char unk0x0F;
    int nCount;
    int nToken;
    char unk0x18[0x10];
    char szName[0x20];
};

struct Unicode
{
    unsigned short wChar;

    Unicode();                                                                                              // 0x0042F530
};

extern "C" unsigned int __cdecl strlen(const char* pString);
void __stdcall sub_00449BF0_SetValue(int nValue);                                                           // 0x00449BF0
void __stdcall sub_00449DD0_SetValue(int nValue);                                                           // 0x00449DD0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
int __stdcall sub_006BC8A0_SendBuffer(void* pConnection, const unsigned char* pBuffer, int nSize);          // 0x006BC8A0
char* __fastcall sub_0040E080_AddressToString(int nAddress);                                                // 0x0040E080
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
void __stdcall sub_0044B230_FilterText(Unicode* pText);                                                     // 0x0044B230
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70

extern void* gpConnection_00798FB4;                                                                         // 0x00798FB4
extern unsigned short gwMcpRequestId_00798F8C;                                                              // 0x00798F8C
extern int gdwGlobal_00798FB0;                                                                              // 0x00798FB0
extern int gdwGlobal_00798F88;                                                                              // 0x00798F88
extern char gData_007992CC[];                                                                               // 0x007992CC
extern D2McpInfoStrc gMcpInfo_0079910C;                                                                     // 0x0079910C
extern int gdwGlobal_00799108;                                                                              // 0x00799108

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0044A7A0
void __fastcall sub_0044A7A0_SendPacket0A(const char* szText, unsigned short wRequestId)
{
    D2McpPacket0AStrc tPacket;
    sub_00449BF0_SetValue(0);
    gwMcpRequestId_00798F8C = wRequestId;
    tPacket.f_0 = 0x0A;
    tPacket.f_1 = wRequestId;
    SStrCopy(tPacket.szText, szText, sizeof(tPacket.szText));
    sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, SStrLen(tPacket.szText) + 4);
}

// 0x0044A810
void __fastcall sub_0044A810_SendPacket18(const char* szText)
{
    D2McpPacket18Strc tPacket;
    sub_00449BF0_SetValue(0);
    tPacket.f_0 = 0x18;
    SStrCopy(tPacket.szText, szText, sizeof(tPacket.szText));
    sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, SStrLen(tPacket.szText) + 2);
}

// 0x0044AF30
int __fastcall sub_0044AF30_McpIncoming10(D2McpPacket10Strc* pPacket, int nSize)
{
    const int nValueB0 = pPacket->nValueB0;
    const int nValue88 = pPacket->nValue88;
    const int nAddress = pPacket->f_9;
    const int nCode = pPacket->nCode;
    sub_00449BF0_SetValue(nCode);
    gdwGlobal_00798FB0 = nValueB0;
    gdwGlobal_00798F88 = nValue88;
    if (!nAddress)
    {
        if (nCode)
        {
            sub_00449BF0_SetValue(nCode);
            sub_00449DD0_SetValue(1);
            return 1;
        }
        sub_00449BF0_SetValue(0x28);
        sub_00449DD0_SetValue(1);
        return 1;
    }
    SStrCopy(gData_007992CC, sub_0040E080_AddressToString(nAddress), 0x12);
    sub_00449DD0_SetValue(1);
    return 1;
}

// 0x0044B2D0
int __fastcall sub_0044B2D0_McpIncoming05(D2McpPacket05Strc* pPacket, int nSize)
{
    const int nValue = pPacket->nValue;
    const int nToken = pPacket->nToken;
    if (pPacket->f_1 != gwMcpRequestId_00798F8C)
        return 1;
    gMcpInfo_0079910C.f_0 = gwMcpRequestId_00798F8C;
    gMcpInfo_0079910C.unk0x04 = nValue;
    gMcpInfo_0079910C.nCount = pPacket->nCount;
    gMcpInfo_0079910C.nToken = nToken;
    if (nToken == -2)
    {
        sub_00449BF0_SetValue(0x33);
        return 1;
    }
    if (nToken == -1)
    {
        sub_00449BF0_SetValue(0x32);
        return 1;
    }
    const char* pString = pPacket->szData;
    const char* szFirst = pString;
    pString += strlen(pString) + 1;
    const char* szSecond = pString;
    const unsigned int nSecondLength = strlen(pString);
    Unicode wszText[0x240];
    sub_00526F20_ToUnicode(wszText, szFirst, 0x240);
    sub_0044B230_FilterText(wszText);
    char szText[0x400];
    sub_00526F70(szText, wszText, 0x400);
    SStrCopy(gMcpInfo_0079910C.unk0x18, szText, 0x10);
    SStrCopy(gMcpInfo_0079910C.szName, szSecond, 0x10);
    gdwGlobal_00799108 = (unsigned int)(szSecond + nSecondLength + 1 - (const char*)pPacket) < (unsigned int)nSize;
    return 1;
}
