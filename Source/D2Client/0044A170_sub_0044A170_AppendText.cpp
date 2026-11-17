#pragma pack(push, 1)
struct D2McpPacket02Strc
{
    unsigned char f_0;
    int nValue;
    unsigned short wValue;
    char szText[0x400];
};

struct D2McpPacket07Strc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket04Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket08Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket09Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

struct D2McpPacket0BStrc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket0CStrc
{
    unsigned char f_0;
    char szText[0x400];
};

struct D2McpPacket16Strc
{
    unsigned char f_0;
    int nValue01;
    int nValue05;
    char szText[0x400];
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __cdecl strlen(const char* pString);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

void __stdcall sub_00449BF0_SetValue(int nValue);                                                           // 0x00449BF0
void __stdcall sub_00449C20_SetValue(int nValue);                                                           // 0x00449C20
int __stdcall sub_006BC8A0_SendBuffer(void* pConnection, const unsigned char* pBuffer, int nSize);          // 0x006BC8A0

void* gpConnection_00798FB4;                                                                                // 0x00798FB4
extern unsigned short gwMcpRequestId_00798F8C;                                                              // 0x00798F8C

// 0x0044A170
static char* __stdcall sub_0044A170_AppendText(unsigned int nMax, char* pDest, const char* szText, unsigned int* pnSize)
{
    const unsigned int nLength = strlen(szText);
    *pnSize += nLength + 1;
    D2_ASSERT(*pnSize < nMax, 0x26);
    strcpy(pDest, szText);
    return pDest + nLength + 1;
}

// 0x0044A2E0
int __fastcall sub_0044A2E0_Forward3(const char* szText, int nValue, unsigned short wValue)
{
    D2McpPacket02Strc tPacket;
    sub_00449BF0_SetValue(0);
    sub_00449C20_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 2;
    tPacket.nValue = nValue;
    tPacket.wValue = wValue;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText, &nSize);
    const unsigned int nTotal = nSize + 7;
    D2_ASSERT(nTotal < 0xFFFF, 0x7E);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044A380
int __fastcall sub_0044A380_Forward1(const char* szText)
{
    D2McpPacket07Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 7;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText, &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x9A);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044A4E0
int __fastcall sub_0044A4E0_SendConnect(const char* szName, const char* szRealm, unsigned short wRequestId)
{
    D2McpPacket04Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 4;
    tPacket.f_1 = wRequestId;
    gwMcpRequestId_00798F8C = wRequestId;
    char* pText = sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szName, &nSize);
    sub_0044A170_AppendText(sizeof(tPacket.szText), pText, szRealm, &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0xE9);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044A680
int __fastcall sub_0044A680_SendPacket08(const char* szText, unsigned short wRequestId)
{
    D2McpPacket08Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 8;
    tPacket.f_1 = wRequestId;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText, &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0x148);
    gwMcpRequestId_00798F8C = wRequestId;
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044A710
int __fastcall sub_0044A710_SendPacket09(const char* szText, unsigned short wRequestId)
{
    D2McpPacket09Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 9;
    tPacket.f_1 = wRequestId;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText, &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0x169);
    gwMcpRequestId_00798F8C = wRequestId;
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044A870
int __fastcall sub_0044A870_SendPacket0B(const char* szText1, const char* szText2)
{
    D2McpPacket0BStrc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 0x0B;
    char* pText = sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText1, &nSize);
    sub_0044A170_AppendText(sizeof(tPacket.szText), pText, szText2, &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x1C2);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044A900
int __fastcall sub_0044A900_SendPacket0C(const char* szText)
{
    D2McpPacket0CStrc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 0x0C;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText, &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x1DE);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044AAE0
int __fastcall sub_0044AAE0_SendSelect(const char* szName, int nB, int nC)
{
    D2McpPacket16Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 0x16;
    tPacket.nValue01 = nB;
    tPacket.nValue05 = nC;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szName, &nSize);
    const unsigned int nTotal = nSize + 9;
    D2_ASSERT(nTotal < 0xFFFF, 0x27B);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}
