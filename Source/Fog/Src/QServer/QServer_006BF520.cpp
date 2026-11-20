#include "D2NetTypes.h"

struct D2StormServerStrc
{
    int nMode;
};

extern "C" int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006B0132
int __fastcall sub_006C3360_Startup(D2StormServerStrc* pServer, int nValue); // 0x006C3360
int __fastcall sub_006C3B50_StartServer(D2StormServerStrc* pServer, int nValue); // 0x006C3B50
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

__declspec(noinline) static void sub_006BF520_StartServer(D2StormServerStrc* pServer, int nValue);
static void sub_006BF520_StartServer(D2StormServerStrc* pServer, int nValue); // 0x006BF520

// 0x006BF520
static void sub_006BF520_StartServer(D2StormServerStrc* pServer, int nValue)
{
    D2WSADataStrc tWsaData;
    if (WSAStartup(0x101, &tWsaData))
    {
        return;
    }

    if (pServer->nMode)
    {
        sub_006C3360_Startup(pServer, nValue);
    }
    else
    {
        sub_006C3B50_StartServer(pServer, nValue);
    }
}

void __fastcall sub_Emit_006BF520(D2StormServerStrc* pServer, int nValue)
{
    sub_006BF520_StartServer(pServer, nValue);
    sub_006BF520_StartServer(pServer, nValue);
}
