#include "D2Client.h"

#pragma pack(push, 1)
struct D2McpPacketValueStrc
{
    unsigned char f_0;
    int nValue;
};

struct D2McpIncoming03Strc
{
    unsigned char f_0;
    unsigned short f_1;
    int nValueB0;
    int nCode;
};

struct D2McpIncoming04Strc
{
    unsigned char f_0;
    unsigned short f_1;
    int nValueB0;
    int f_7;
    int nValue88;
    int nCode;
};

struct D2McpIncoming0AStrc
{
    unsigned char f_0;
    unsigned short f_1;
    int nCode;
};

struct D2McpIncoming08Strc
{
    unsigned char f_0;
    unsigned short f_1;
    unsigned char aData[1];
};

struct D2McpIncoming09Strc
{
    unsigned char f_0;
    unsigned short f_1;
    unsigned char nByte03;
    unsigned char aData[1];
};

struct D2McpIncoming0EStrc
{
    unsigned char f_0;
    char szText[1];
};
#pragma pack(pop)

typedef void (__fastcall* D2McpCallbackFn)(unsigned short wRequestId, unsigned char* pData);

extern "C" unsigned int __cdecl strlen(const char* pString);
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130
void __stdcall sub_00449C40_SetValue(int nValue);                                                           // 0x00449C40
void __stdcall sub_00449C60_SetValue(int nValue);                                                           // 0x00449C60
void __stdcall sub_00449C80_SetValue(int nValue);                                                           // 0x00449C80
void __stdcall sub_00449C90_SetValue(int nValue);                                                           // 0x00449C90
void __stdcall sub_00449CC0_SetValue(int nValue);                                                           // 0x00449CC0
void __stdcall sub_00449D10_SetTexts(int nResult, const char* szText1, const char* szText2);                // 0x00449D10
void __stdcall sub_00449D90_SetValue(int nValue);                                                           // 0x00449D90
void __stdcall sub_00449DB0_SetValue(int nValue);                                                           // 0x00449DB0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

extern void* ghConnectEvent_007992EC;                                                                       // 0x007992EC
unsigned short gwMcpRequestId_00798F8C;                                                                     // 0x00798F8C
unsigned short gwRequestId_00798F80;                                                                        // 0x00798F80
int gdwGlobal_00798FB0;                                                                                     // 0x00798FB0
int gdwGlobal_00798F88;                                                                                     // 0x00798F88
char gData_007992CC[20];                                                                                    // 0x007992CC
D2McpCallbackFn gpfnMcpCallback_007992F8;                                                                   // 0x007992F8
D2McpCallbackFn gpfnMcpCallback_007992FC;                                                                   // 0x007992FC

// 0x0044AB80
int __fastcall sub_0044AB80_McpIncoming1B(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    SetEvent(ghConnectEvent_007992EC);
    return 1;
}

// 0x0044ABA0
int __fastcall sub_0044ABA0_McpIncoming02(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    sub_00449C20_SetValue(1);
    return 1;
}

// 0x0044ABC0
int __fastcall sub_0044ABC0_McpIncoming07(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    sub_00449C40_SetValue(1);
    return 1;
}

// 0x0044ABE0
int __fastcall sub_0044ABE0_McpIncoming03(D2McpIncoming03Strc* pPacket, int nSize)
{
    const int nValueB0 = pPacket->nValueB0;
    if (pPacket->f_1 == gwMcpRequestId_00798F8C)
    {
        sub_00449BF0_SetValue(pPacket->nCode);
        gwRequestId_00798F80 = gwMcpRequestId_00798F8C;
        gdwGlobal_00798FB0 = nValueB0;
    }
    return 1;
}

// 0x0044AC20
int __fastcall sub_0044AC20_McpIncoming04(D2McpIncoming04Strc* pPacket, int nSize)
{
    const int nValueB0 = pPacket->nValueB0;
    const int nAddress = pPacket->f_7;
    const int nValue88 = pPacket->nValue88;
    const int nCode = pPacket->nCode;
    if (pPacket->f_1 == gwMcpRequestId_00798F8C)
    {
        gwRequestId_00798F80 = gwMcpRequestId_00798F8C;
        gdwGlobal_00798FB0 = nValueB0;
        gdwGlobal_00798F88 = nValue88;
        if (!nAddress)
        {
            if (nCode)
            {
                sub_00449BF0_SetValue(nCode);
                return 1;
            }
            sub_00449BF0_SetValue(0x28);
            return 1;
        }
        SStrCopy(gData_007992CC, sub_0040E080_AddressToString(nAddress), 0x12);
    }
    return 1;
}

// 0x0044ADF0
int __fastcall sub_0044ADF0_McpIncoming08(D2McpIncoming08Strc* pPacket, int nSize)
{
    if (gpfnMcpCallback_007992F8)
        gpfnMcpCallback_007992F8(pPacket->f_1, pPacket->aData);
    return 1;
}

// 0x0044AE10
int __fastcall sub_0044AE10_McpIncoming09(D2McpIncoming09Strc* pPacket, int nSize)
{
    if (gpfnMcpCallback_007992FC)
        gpfnMcpCallback_007992FC(pPacket->f_1, pPacket->aData);
    return 1;
}

// 0x0044AE30
int __fastcall sub_0044AE30_McpIncoming0A(D2McpIncoming0AStrc* pPacket, int nSize)
{
    if (pPacket->f_1 == gwMcpRequestId_00798F8C)
    {
        sub_00449BF0_SetValue(pPacket->nCode);
        sub_00449C60_SetValue(1);
    }
    return 1;
}

// 0x0044AE60
int __fastcall sub_0044AE60_McpIncoming18(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    sub_00449C80_SetValue(1);
    return 1;
}

// 0x0044AE80
int __fastcall sub_0044AE80_McpIncoming0B(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    sub_00449C90_SetValue(1);
    return 1;
}

// 0x0044AEA0
int __fastcall sub_0044AEA0_McpIncoming0C(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    sub_00449CC0_SetValue(1);
    return 1;
}

// 0x0044AEC0
int __fastcall sub_0044AEC0_McpIncoming0E(D2McpIncoming0EStrc* pPacket, int nSize)
{
    const char* szText = pPacket->szText;
    sub_00449D10_SetTexts(1, szText, szText + strlen(szText) + 1);
    return 1;
}

// 0x0044AEF0
int __fastcall sub_0044AEF0_McpIncoming0D(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    sub_00449D90_SetValue(1);
    return 1;
}

// 0x0044AF10
int __fastcall sub_0044AF10_McpIncoming0F(D2McpPacketValueStrc* pPacket, int nSize)
{
    sub_00449BF0_SetValue(pPacket->nValue);
    sub_00449DB0_SetValue(1);
    return 1;
}
