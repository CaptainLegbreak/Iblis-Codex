#include "D2Client.h"
#include "D2FogTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2Win32Types.h"
#include "D2Win32System.h"

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

struct D2LaunchAddressStrc;

void* __stdcall D2QSSOCKET_GetSafeSock(int nKey); // 0x006BC810

int __fastcall FOG_SOCKET_GetPeerName(void* pHandle, D2LaunchAddressStrc* pAddress, int* pSize); // 0x0040DEE0

extern int gnLaunchKey_00798FB4; // 0x00798FB4

// build: symbol ?COMCALLBACK_NibbleToHex@* 0x00449840
unsigned int __fastcall COMCALLBACK_NibbleToHex(unsigned int nValue)
{
    unsigned int nResult = nValue & 0xF;
    if (nResult >= 10)
        nResult += 0x37;
    else
        nResult += 0x30;
    return nResult;
}

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
int __fastcall WINMAIN_SendMcpCharCreate(int nA, int nB, int nC); // 0x0044A2E0
int __fastcall WINMAIN_SendMcpCharLogon(int nA); // 0x0044A380
extern int gnValue_00798F5C; // 0x00798F5C
extern int gnValue_00798F7C; // 0x00798F7C
extern int gnValue_00798F84; // 0x00798F84
extern int gnValue_00799100; // 0x00799100
extern int gnValue_00799104; // 0x00799104
extern int gnValue_00799298; // 0x00799298
extern int gnValue_0079929C; // 0x0079929C
extern int gnValue_007992A0; // 0x007992A0
void* ghThread;                                                                                    // 0x007992A4
extern int gnValue_007992A8; // 0x007992A8
extern int gnValue_007992E0; // 0x007992E0
extern int gnValue_007992E8; // 0x007992E8
extern int gnValue_007992F0; // 0x007992F0
int gnResult_00798F58; // 0x00798F58
char gszText_00798F60[28]; // 0x00798F60
char gszText_00799294[4]; // 0x00799294
unsigned short __cdecl CHATDLG_GetRequestId();                                                         // 0x00449BD0
void __cdecl CHATDLG_ClearReply();                                                                     // 0x00449D60
void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40
int __stdcall CHATDLG_RequestCharLogon(const char* szName);                                                    // 0x00449E10
void __stdcall D2QSSOCKET_DestroyRecord(void* pConnection);                                                             // 0x006BC780
extern unsigned short gwMcpReplyRequestId;                                                                 // 0x00798F80
extern void* gpMcpConnection;                                                                         // 0x00798FB4
extern char gabMcpReply[];                                                                               // 0x00799108
extern void* ghConnectEvent;                                                                       // 0x007992EC

// 0x00449AD0
void __cdecl D2MCPClientCloseMCP()
{
    if (gpMcpConnection)
    {
        D2QSSOCKET_DestroyRecord(gpMcpConnection);
        gpMcpConnection = 0;
    }
    if (ghThread)
    {
        WaitForSingleObject(ghThread, 0xFFFFFFFF);
        CloseHandle(ghThread);
        ghThread = 0;
    }
    if (ghConnectEvent)
    {
        CloseHandle(ghConnectEvent);
        ghConnectEvent = 0;
    }
}

// 0x00449B30
int __cdecl sub_00449B30_QueryAddress()
{
    void* pHandle = D2QSSOCKET_GetSafeSock(gnLaunchKey_00798FB4);
    if (!pHandle)
        return 0;
    D2LaunchAddressStrc tAddress;
    int nSize = sizeof(tAddress);
    return FOG_SOCKET_GetPeerName(pHandle, &tAddress, &nSize);
}

// 0x00449BD0
unsigned short __cdecl CHATDLG_GetRequestId()
{
    return gwMcpReplyRequestId;
}

// 0x00449BF0
void __stdcall CHATDLG_SetMcpResult(int nValue)
{
    gnValue_0079929C = nValue;
}

// 0x00449C20
void __stdcall CHATDLG_SetCharCreateReceived(int nValue)
{
    gnValue_007992E8 = nValue;
}

// 0x00449C40
void __stdcall CHATDLG_SetCharLogonReceived(int nValue)
{
    gnValue_007992E0 = nValue;
}

// 0x00449C60
void __stdcall CHATDLG_SetCharDeleteReceived(int nValue)
{
    gnValue_00799298 = nValue;
}

// 0x00449C80
void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue)
{
    gnValue_007992F0 = nValue;
}

// 0x00449C90
void __stdcall sub_00449C90_SetValue(int nValue)
{
    gnValue_00799100 = nValue;
}

// 0x00449CC0
void __stdcall sub_00449CC0_SetValue(int nValue)
{
    gnValue_007992A0 = nValue;
}

// 0x00449CD0
int __stdcall CHATDLG_GetMcpTexts(char* szText1, char* szText2)
{
    strcpy(szText1, gszText_00799294);
    strcpy(szText2, gszText_00798F60);
    return gnResult_00798F58;
}

// 0x00449D10
void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2)
{
    strcpy(gszText_00799294, szText1);
    strcpy(gszText_00798F60, szText2);
    gnResult_00798F58 = nResult;
}

// 0x00449D60
void __cdecl CHATDLG_ClearReply()
{
    memset(gabMcpReply, 0, 0x18C);
}

// 0x00449D90
void __stdcall sub_00449D90_SetValue(int nValue)
{
    gnValue_007992A8 = nValue;
}

// 0x00449DB0
void __stdcall sub_00449DB0_SetValue(int nValue)
{
    gnValue_00798F5C = nValue;
}

// 0x00449DD0
void __stdcall sub_00449DD0_SetValue(int nValue)
{
    gnValue_00798F84 = nValue;
}

// 0x00449DF0
int __stdcall CHATDLG_RequestCharCreate(int nA, int nB, int nC)
{
    return WINMAIN_SendMcpCharCreate(nA, nB, nC);
}

// 0x00449E10
int __stdcall CHATDLG_RequestCharLogon(int nA)
{
    return WINMAIN_SendMcpCharLogon(nA);
}

// 0x00449E30
void __stdcall sub_00449E30_SetValue(int nValue)
{
    gnValue_00799104 = nValue;
}

// 0x00449E50
void __stdcall sub_00449E50_SetValue(int nValue)
{
    gnValue_00798F7C = nValue;
}
