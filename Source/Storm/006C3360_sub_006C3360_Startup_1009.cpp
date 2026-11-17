struct D2WSADataStrc
{
    unsigned short wVersion;
    unsigned short wHighVersion;
    char szDescription[0x101];
    char szSystemStatus[0x81];
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    char pad0x18A[2];
    char* lpVendorInfo;
};
struct D2Server006C3360Strc
{
    unsigned char unk_000[0x884];
    int bStarted884;
};
extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132
int __fastcall sub_006C3120_Start(D2Server006C3360Strc* pServer, int nValue); // 0x006C3120

// 0x006C3360
int __fastcall sub_006C3360_Startup(D2Server006C3360Strc* pServer, int nValue)
{
    D2WSADataStrc tWsaData;
    pServer->bStarted884 = 1;
    if (WSAStartup(0x101, &tWsaData))
    {
        return 0;
    }
    return sub_006C3120_Start(pServer, nValue);
}
