#include "D2MCPClient.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2McpPacket02Strc;
struct D2McpPacket07Strc;
struct D2McpPacket04Strc;
struct D2McpPacket08Strc;
struct D2McpPacket09Strc;
struct D2McpPacket0BStrc;
struct D2McpPacket0CStrc;
struct D2McpPacket16Strc;
struct D2McpPacket01Strc;
struct D2LaunchThreadRecordStrc;
struct D2McpPacket03Strc;
struct D2McpCreateGameStrc;

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

struct D2McpPacket01Strc
{
    unsigned char f_0;
    int nValue01;
    int nValue05;
    int nValue09;
    int nValue0D;
    int nValue11;
    int nValue15;
    int nValue19;
    int nValue1D;
    int nValue21;
    int nValue25;
    int nValue29;
    int nValue2D;
    int nValue31;
    int nValue35;
    int nValue39;
    int nValue3D;
    char szText[0x400];
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" unsigned int __cdecl strlen(const char* pString);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern void* gpConnection_00798FB4; // 0x00798FB4
extern unsigned short gwMcpRequestId_00798F8C; // 0x00798F8C

#pragma pack(push, 1)
struct D2McpPacket03Strc
{
    unsigned char f_0;
    unsigned short wRequestId;
    int nValue;
    unsigned char nByte07;
    unsigned char nByte08;
    unsigned char nByte09;
    char szText[0x400];
};

#pragma pack(pop)
struct D2McpCreateGameStrc
{
    char szName[0x10];
    char szPassword[0x10];
    char szDescription[0x20];
    int nValue40;
    unsigned char nByte44;
    unsigned char nByte45;
    unsigned char nByte46;
};

extern int gnGlobal_00798FB0; // 0x00798FB0

// 0x0044A170
static char* __stdcall sub_0044A170_AppendText(char* pDest, const char* szText, unsigned int nMax, unsigned int* pnSize)
{
    const unsigned int nLength = strlen(szText);
    *pnSize += nLength + 1;
    D2_ASSERT(*pnSize < nMax, 0x26);
    strcpy(pDest, szText);
    return pDest + nLength + 1;
}

// 0x0044A1D0
int __fastcall sub_0044A1D0_StartConnect(D2LaunchThreadRecordStrc* pRecord)
{
    D2McpPacket01Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 1;
    tPacket.nValue01 = pRecord->nData[0];
    tPacket.nValue05 = pRecord->nData[1];
    tPacket.nValue09 = pRecord->nData[2];
    tPacket.nValue0D = pRecord->nData[3];
    tPacket.nValue11 = pRecord->nData[6];
    tPacket.nValue15 = pRecord->nData[7];
    tPacket.nValue19 = pRecord->nData[8];
    tPacket.nValue1D = pRecord->nData[9];
    tPacket.nValue21 = pRecord->nData[10];
    tPacket.nValue25 = pRecord->nData[11];
    tPacket.nValue29 = pRecord->nData[12];
    tPacket.nValue2D = pRecord->nData[13];
    tPacket.nValue31 = pRecord->nData[14];
    tPacket.nValue35 = pRecord->nData[15];
    tPacket.nValue39 = pRecord->nData[16];
    tPacket.nValue3D = pRecord->nData[17];
    sub_0044A170_AppendText(tPacket.szText, (const char*)&pRecord->nData[0x12], sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 0x41;
    D2_ASSERT(nTotal < 0xFFFF, 0x5C);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044A2E0_Forward3(const char* szText, int nValue, unsigned short wValue)
{
    D2McpPacket02Strc tPacket;
    sub_00449BF0_SetValue(0);
    sub_00449C20_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 2;
    tPacket.nValue = nValue;
    tPacket.wValue = wValue;
    sub_0044A170_AppendText(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 7;
    D2_ASSERT(nTotal < 0xFFFF, 0x7E);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044A380_Forward1(const char* szText)
{
    D2McpPacket07Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 7;
    sub_0044A170_AppendText(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x9A);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044A4E0_SendConnect(const char* szName, const char* szRealm, unsigned short wRequestId)
{
    D2McpPacket04Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 4;
    tPacket.f_1 = wRequestId;
    gwMcpRequestId_00798F8C = wRequestId;
    char* pText = sub_0044A170_AppendText(tPacket.szText, szName, sizeof(tPacket.szText), &nSize);
    sub_0044A170_AppendText(pText, szRealm, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0xE9);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044A680_SendPacket08(const char* szText, unsigned short wRequestId)
{
    D2McpPacket08Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 8;
    tPacket.f_1 = wRequestId;
    sub_0044A170_AppendText(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0x148);
    gwMcpRequestId_00798F8C = wRequestId;
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044A710_SendPacket09(const char* szText, unsigned short wRequestId)
{
    D2McpPacket09Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 9;
    tPacket.f_1 = wRequestId;
    sub_0044A170_AppendText(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0x169);
    gwMcpRequestId_00798F8C = wRequestId;
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044A870_SendPacket0B(const char* szText1, const char* szText2)
{
    D2McpPacket0BStrc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 0x0B;
    char* pText = sub_0044A170_AppendText(tPacket.szText, szText1, sizeof(tPacket.szText), &nSize);
    sub_0044A170_AppendText(pText, szText2, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x1C2);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044A900_SendPacket0C(const char* szText)
{
    D2McpPacket0CStrc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 0x0C;
    sub_0044A170_AppendText(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x1DE);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

int __fastcall sub_0044AAE0_SendSelect(const char* szName, int nB, int nC)
{
    D2McpPacket16Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 0x16;
    tPacket.nValue01 = nB;
    tPacket.nValue05 = nC;
    sub_0044A170_AppendText(tPacket.szText, szName, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 9;
    D2_ASSERT(nTotal < 0xFFFF, 0x27B);
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}

// 0x0044A400
int __fastcall sub_0044A400_SendCreateGame(D2McpCreateGameStrc* pRecord, unsigned short wRequestId)
{
    D2McpPacket03Strc tPacket;
    sub_00449BF0_SetValue(0);
    tPacket.nValue = pRecord->nValue40;
    tPacket.wRequestId = wRequestId;
    tPacket.nByte07 = pRecord->nByte44;
    tPacket.nByte08 = pRecord->nByte45;
    unsigned int nSize = 0;
    tPacket.f_0 = 3;
    tPacket.nByte09 = pRecord->nByte46;
    gwMcpRequestId_00798F8C = wRequestId;
    char* pText = sub_0044A170_AppendText(tPacket.szText, pRecord->szName, sizeof(tPacket.szText), &nSize);
    pText = sub_0044A170_AppendText(pText, pRecord->szPassword, sizeof(tPacket.szText), &nSize);
    sub_0044A170_AppendText(pText, pRecord->szDescription, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 10;
    D2_ASSERT(nTotal < 0xFFFF, 0xC1);
    gnGlobal_00798FB0 = 0;
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nTotal);
}
