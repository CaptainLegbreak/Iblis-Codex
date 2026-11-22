#include "D2Client.h"
#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmdParamsStrc;

union D2CdKeyWordStrc;

struct D2CmdArgStrc;

struct D2McpPacket02Strc;

struct D2McpPacket07Strc;

struct D2McpPacket04Strc;

struct D2McpPacket08Strc;

struct D2McpPacket09Strc;

struct D2McpPacket0BStrc;

struct D2McpPacket0CStrc;

struct D2McpPacket16Strc;

struct D2McpPacket05Strc;

struct D2LaunchRequestStrc;

struct D2McpPacket06Strc;

struct D2McpPacket0AStrc;

struct D2McpPacket18Strc;

struct D2McpPacket10Strc;

struct D2McpInfoStrc;

struct Unicode;

struct D2CmdParamsStrc
{
    char unk0x00[0x18];
    const char* szValue;
};

union D2CdKeyWordStrc
{
    unsigned int nValue;
    char szText[4];
};

struct D2CmdArgStrc
{
    unsigned int dwFlags;
    unsigned int dwId;
    const char* szName;
    void* pfnHandler;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern "C" __declspec(dllimport) int __stdcall GetUserNameA(char* szBuffer, unsigned long* pSize); // 0x006CC000

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" int __cdecl tolower(int nChar); // 0x0068523E

extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

void __fastcall sub_00449890_CdKeyChecksum(char* szKey, unsigned int* pChecksum); // 0x00449890

int __stdcall SCmdRegisterArgList(const D2CmdArgStrc* pArgList, unsigned int nCount); // 0x006C4E50

int __stdcall SCmdProcess(const char* szCmdLine, int bSkipProgName, int (__stdcall* pfnExtra)(const char*), int (__stdcall* pfnError)(const char*)); // 0x006C4FB0

unsigned short __stdcall sub_006BC120_Receive(void* pConnection, char* pBuffer, int nSize); // 0x006BC120

int __fastcall GAME_DispatchMcpPacket(const char* pPacket, unsigned int nSize); // 0x0044B190

int __fastcall GAME_RunInitHandlers(void* pArg); // 0x0044D9F0

int __stdcall sub_0044B5C0_OnExtraArgument(const char* szArgument); // 0x0044B5C0

int __stdcall sub_0044B5D0_OnArgumentError(const char* szArgument); // 0x0044B5D0

void __fastcall GAME_ShowLoadingMessage(int nError); // 0x0044E380

int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A890

int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A8B0

void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nLength); // 0x0045C850

void __fastcall SCMD_ProcessPackets(unsigned char* pPacket, int nLength); // 0x0045F7B0

void* gpConnection_00798FB4; // 0x00798FB4

extern const char* gpszLaunchModeNames_0070EE70[7]; // 0x0070EE70

extern const D2CmdArgStrc gtCommandLineArgs_006D5BE8[8]; // 0x006D5BE8

extern int (__cdecl* const gpfnLaunchInit_006D5BE0[1])(); // 0x006D5BE0

extern char gszCharName_007A05C4[]; // 0x007A05C4

int gdwGlobal_007A0460;                                                                                     // 0x007A0460

unsigned long gdwTick_007A0464;                                                                             // 0x007A0464

unsigned long gdwTick_007A045C;                                                                             // 0x007A045C

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

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" unsigned int __cdecl strlen(const char* pString);

extern unsigned short gwMcpRequestId_00798F8C; // 0x00798F8C

#pragma pack(push, 1)

struct D2McpPacket05Strc
{
    unsigned char f_0;
    unsigned short f_1;
    union
    {
        unsigned int dwFlags;
        int nValue;
    };
    union
    {
        struct
        {
            char szText[0x400];
        };
        struct
        {
            unsigned char nCount;
            int nToken;
            char szData[1];
        };
    };
};

#pragma pack(pop)

struct D2LaunchRequestStrc
{
    int nData[5];
    unsigned int dwFlags;
};

#pragma pack(push, 1)

struct D2McpPacket06Strc
{
    unsigned char f_0;
    unsigned short f_1;
    char szText[0x400];
};

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

void __stdcall sub_00449DD0_SetValue(int nValue); // 0x00449DD0

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __stdcall GAME_StripColorCodes(Unicode* pText); // 0x0044B230

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

extern int gdwGlobal_00798FB0; // 0x00798FB0

extern int gdwGlobal_00798F88; // 0x00798F88

extern char gData_007992CC[]; // 0x007992CC

extern D2McpInfoStrc gMcpInfo_0079910C; // 0x0079910C

extern int gdwGlobal_00799108; // 0x00799108

int __stdcall WINMAIN_ShowCommandLineHelp(const D2CmdParamsStrc* pParams, int nUnused); // 0x0044B4E0

int __stdcall WINMAIN_SetLaunchMode(const D2CmdParamsStrc* pParams, int nUnused); // 0x0044B600

const char* gpszHelpCaption_007A0454; // 0x007A0454

int gdwGlobal_007A0618; // 0x007A0618

static int s_bHelpChecked_007A0448; // 0x007A0448

struct D2ClientCharRecordStrc;

struct D2GameDataTableStrc;

struct D2ClientInterfaceStrc;

typedef void (__fastcall* D2McpCallback)(int nId, unsigned int nSize, const unsigned char* pData);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

void __stdcall sub_00449E30_SetValue(int nValue);                                                           // 0x00449E30

void __stdcall sub_00449E50_SetValue(int nValue);                                                           // 0x00449E50

void __stdcall sub_00449E70_SetMcpPacket(const char* pData, int nSize);                                     // 0x00449E70

void __cdecl sub_006115F0_Empty();                                                                          // 0x006115F0

void __cdecl sub_0052BDA0_Empty();                                                                          // 0x0052BDA0

void __cdecl sub_0052BDB0_Empty();                                                                          // 0x0052BDB0

void __cdecl PROFCORE_CloseLog();                                                                                // 0x00611600

int __stdcall GAME_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord);                   // 0x0044B8A0

void __cdecl sub_004519A0_ToggleFlags();                                                                    // 0x004519A0

void __cdecl WINMAIN_StartPlayback();                                                                  // 0x004518E0

int __cdecl CLIENT_GetConnectionStatus();                                                                   // 0x0052B050

int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0

void __stdcall SERVER_Initialize(int a1, int a2);                                                           // 0x0052B7A0

void __stdcall CLIENT_Initialize(int nArg, const char* szAddress);                                               // 0x0052A750

void __stdcall SERVER_SetMaxClientsPerGame(int nArg1);                                                   // 0x0052B250

int __stdcall SERVER_SetHackListEnabled(int nArg1);                                                    // 0x0052B280

void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList);                  // 0x0052C0A0

int __stdcall WINMAIN_PollSystemPackets(int nUnused);                                                  // 0x0044BAD0

int __stdcall WINMAIN_PumpSystemPackets(int nUnused);                                                  // 0x0044BD20

void __cdecl CLIENT_Release();                                                                                // 0x0052A7E0

void __cdecl SERVER_Release();                                                              // 0x0052B2A0

int __cdecl GAME_PopStateValue();                                                                        // 0x0044B480

void (__fastcall* gpfnCallback_00799308)(void* pArg);                                                       // 0x00799308

extern D2McpPacketHandler gpfnMcpHandlers_0070ED68[];                                                       // 0x0070ED68

void* gpInstance_007A0318;                                                                                  // 0x007A0318

extern D2ClientInterfaceStrc gtInterface_0070EE0C;                                                          // 0x0070EE0C

extern D2GameDataTableStrc gtGameDataTable_007A0690;                                                        // 0x007A0690

char gtGameList_007A0630[4];                                                                                // 0x007A0630

extern char gszAddress_0070EF20[];                                                                          // 0x0070EF20

// 0x00449920
int __fastcall WINMAIN_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue)
{
    D2CdKeyWordStrc tWord;
    char szValue[8];
    char szKey[20];
    *pProduct = 0;
    *pValue = 0;
    strcpy(szKey, szCdKey);
    const char* p = szKey;
    while (*p)
    {
        if (gnCdKeyMap_006D59F0[(unsigned char)*p++] > 0x17)
        {
            return 0;
        }
    }

    sub_00449890_CdKeyChecksum(szKey, &tWord.nValue);
    unsigned int nHash = 3;
    for (unsigned int i = 0; i < 16; ++i)
    {
        const char c = tolower(szKey[i]);
        int nDigit;
        if (c >= 'a')
        {
            nDigit = c - 0x57;
        }
        else
        {
            nDigit = c - '0';
        }
        nHash += (2 * nHash) ^ nDigit;
    }

    if ((unsigned char)nHash != tWord.nValue)
    {
        return 0;
    }

    for (int i = 15; i >= 0; --i)
    {
        const int j = (i + 7) & 0xF;
        const char c = szKey[i];
        szKey[i] = szKey[j];
        szKey[j] = c;
    }

    tWord.nValue = 0x13AC9741;
    for (int i = 15; i >= 0; --i)
    {
        szKey[i] = toupper(szKey[i]);
        if (szKey[i] <= '7')
        {
            szKey[i] ^= tWord.nValue & 7;
            tWord.nValue >>= 3;
        }
        else if (szKey[i] < 'A')
        {
            szKey[i] ^= i & 1;
        }
    }

    SStrCopy(tWord.szText, szKey, 3);
    SStrCopy(szValue, &szKey[2], 7);
    *pProduct = strtoul(tWord.szText, 0, 16);
    *pValue = strtoul(szValue, 0, 16);
    return 1;
}

// 0x0044B420
void __cdecl WINMAIN_ShutdownInterface()
{
    sub_0052BDB0_Empty();
    PROFCORE_CloseLog();
}

// 0x0044C6E0
void __cdecl WINMAIN_DrainPacketQueues()
{
    unsigned char pBuffer[0x200];
    int nLength;
    do
    {
        nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
        SCMD_HandleSystemPacket(pBuffer, nLength);
        Sleep(0);
    }
    while (nLength != -1);

    do
    {
        nLength = CLIENT_DequeueGamePacket(pBuffer, sizeof(pBuffer));
        SCMD_ProcessPackets(pBuffer, nLength);
        Sleep(0);
    }
    while (nLength != -1);
}

// 0x00449B70
int __cdecl WINMAIN_PollMcpConnection()
{
    char szBuffer[0x400];
    if (!gpConnection_00798FB4)
    {
        return 0;
    }

    const unsigned short nLength = sub_006BC120_Receive(gpConnection_00798FB4, szBuffer, sizeof(szBuffer));
    if (nLength)
    {
        GAME_DispatchMcpPacket(szBuffer, nLength);
    }
    return 1;
}

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
int __fastcall WINMAIN_SendMcpCharCreate(const char* szText, int nValue, unsigned short wValue)
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
int __fastcall WINMAIN_SendMcpCharLogon(const char* szText)
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
int __fastcall WINMAIN_SendMcpJoinGame(const char* szName, const char* szRealm, unsigned short wRequestId)
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

// 0x0044A590
void __fastcall WINMAIN_SendMcpGameListRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId)
{
    D2McpPacket05Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 5;
    tPacket.f_1 = wRequestId;
    tPacket.dwFlags = pRequest->dwFlags;
    gwMcpRequestId_00798F8C = wRequestId;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, (const char*)pRequest->nData, &nSize);
    nSize += 7;
    sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nSize);
}

// 0x0044A610
int __fastcall WINMAIN_SendMcpGameInfoRequest(char* szText, unsigned short wRequestId)
{
    D2McpPacket06Strc tPacket;
    sub_00449BF0_SetValue(0);
    unsigned int nSize = 0;
    tPacket.f_0 = 6;
    tPacket.f_1 = wRequestId;
    gwMcpRequestId_00798F8C = wRequestId;
    sub_0044A170_AppendText(sizeof(tPacket.szText), tPacket.szText, szText, &nSize);
    nSize += 3;
    return sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, nSize);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
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

// 0x0044A7A0
void __fastcall WINMAIN_SendMcpCharDelete(const char* szText, unsigned short wRequestId)
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
void __fastcall WINMAIN_SendMcpCharUpgrade(const char* szText)
{
    D2McpPacket18Strc tPacket;
    sub_00449BF0_SetValue(0);
    tPacket.f_0 = 0x18;
    SStrCopy(tPacket.szText, szText, sizeof(tPacket.szText));
    sub_006BC8A0_SendBuffer(gpConnection_00798FB4, &tPacket.f_0, SStrLen(tPacket.szText) + 2);
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

// 0x0044AF30
int __fastcall WINMAIN_HandleMcpServerAddress(D2McpPacket10Strc* pPacket, int nSize)
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
// build: symbol ?FOG_inet_ntoa@* 0x0040E080
    SStrCopy(gData_007992CC, FOG_inet_ntoa(nAddress), 0x12);
    sub_00449DD0_SetValue(1);
    return 1;
}

// 0x0044B2D0
int __fastcall WINMAIN_HandleMcpGameList(D2McpPacket05Strc* pPacket, int nSize)
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
    GAME_StripColorCodes(wszText);
    char szText[0x400];
    sub_00526F70(szText, wszText, 0x400);
    SStrCopy(gMcpInfo_0079910C.unk0x18, szText, 0x10);
    SStrCopy(gMcpInfo_0079910C.szName, szSecond, 0x10);
    gdwGlobal_00799108 = (unsigned int)(szSecond + nSecondLength + 1 - (const char*)pPacket) < (unsigned int)nSize;
    return 1;
}

// 0x0044B400
D2ClientInterfaceStrc* __fastcall WINMAIN_InitInterface(void* hInstance)
{
    sub_006115F0_Empty();
    sub_0052BDA0_Empty();
    gpInstance_007A0318 = hInstance;
    return &gtInterface_0070EE0C;
}

// 0x0044B430
int __fastcall WINMAIN_RunLauncher(D2ClientCharRecordStrc* pRecord)
{
    return GAME_LauncherRun(gpInstance_007A0318, pRecord);
}

// 0x0044B4E0
int __stdcall WINMAIN_ShowCommandLineHelp(const D2CmdParamsStrc* pParams, int nUnused)
{
    if (!s_bHelpChecked_007A0448)
    {
        s_bHelpChecked_007A0448 = 1;
        unsigned long nSize = 0xF;
        char szUser[0x10];
        GetUserNameA(szUser, &nSize);
        if (SStrCmp(szUser, "rseis", 0x7FFFFFFF))
        {
            MessageBoxA(0, "Available command line options:\n  -set[default command line]\t\tSet new default command line string\n  -lng[lngfile]\t\t\tUse \"lngfile\" for language resources\n", gpszHelpCaption_007A0454, 0);
        }
    }
    return 0;
}

// 0x0044B550
int __stdcall WINMAIN_RunMemoryTest(const D2CmdParamsStrc* pParams, int nUnused)
{
    char* pMemory = (char*)FOG_Alloc(0x6000000, ".\\CORE\\WINMAIN.CPP", 0x121, 0);
    for (char* p = pMemory; p < pMemory + 0x6000000; p += 0x1000)
        *p = 0;
    FOG_Free(pMemory, ".\\CORE\\WINMAIN.CPP", 0x124, 0);
    return 1;
}

// 0x0044B5A0
int __stdcall WINMAIN_HandleToggleFlagsOption(const D2CmdParamsStrc* pParams, int nUnused)
{
    sub_004519A0_ToggleFlags();
    return 1;
}

// 0x0044B5B0
int __stdcall WINMAIN_HandlePlaybackOption(const D2CmdParamsStrc* pParams, int nUnused)
{
    WINMAIN_StartPlayback();
    return 1;
}

// 0x0044B5C0
int __stdcall WINMAIN_HandleExtraArgument(int nArg)
{
    WINMAIN_ShowCommandLineHelp(0, 0);
    return 0;
}

// 0x0044B5D0
int __stdcall WINMAIN_HandleArgumentError(int nArg)
{
    return WINMAIN_ShowCommandLineHelp(0, 0);
}

// 0x0044B600
int __stdcall WINMAIN_SetLaunchMode(const D2CmdParamsStrc* pParams, int nUnused)
{
    for (unsigned int i = 0; i < 7; ++i)
    {
        if (gpszLaunchModeNames_0070EE70[i] && !_stricmp(gpszLaunchModeNames_0070EE70[i], pParams->szValue))
        {
            gnLaunchState_0070EE4C = i;
            return 1;
        }
    }
    return WINMAIN_ShowCommandLineHelp(pParams, nUnused);
}

// 0x0044B6B0
int __stdcall WINMAIN_ProcessCommandLine(void* pArg)
{
    char szCmdLine[0x104];
    SCmdRegisterArgList(gtCommandLineArgs_006D5BE8, 8);
    for (unsigned int i = 0; i < sizeof(gpfnLaunchInit_006D5BE0) / sizeof(gpfnLaunchInit_006D5BE0[0]); ++i)
    {
        if (!gpfnLaunchInit_006D5BE0[i]())
        {
            return 0;
        }
    }

    if (!GAME_RunInitHandlers(pArg))
    {
        return 0;
    }

    if (SRegLoadString("Diablo II", "Default Command Line", 0, szCmdLine, sizeof(szCmdLine)))
    {
        SCmdProcess(szCmdLine, 0, sub_0044B5C0_OnExtraArgument, sub_0044B5D0_OnArgumentError);
    }

    {
        unsigned long nSize = 0xF;
        if (!gszCharName_007A05C4[0] && !GetUserNameA(gszCharName_007A05C4, &nSize))
        {
            wsprintfA(gszCharName_007A05C4, gszStringFormat_006FFC58, "noname");
        }
    }
    return 1;
}

// 0x0044BAD0
int __stdcall WINMAIN_PollSystemPackets(int nUnused)
{
    unsigned char pBuffer[0x200];
    if ((gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1) || !WINDOW_GetState())
    {
        if (GetTickCount() - gdwTick_007A0464 > 10000)
        {
            GAME_ShowLoadingMessage(6);
            gdwGlobal_007A0460 = 1;
            gdwGlobal_007A0618 = 0;
            return 1;
        }

        if (!sub_0052A640_IsConnected())
        {
            return 1;
        }
    }

    const int nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
    SCMD_HandleSystemPacket(pBuffer, nLength);
    return gdwGlobal_007A0618 != 0;
}

// 0x0044BBB0
int __stdcall WINMAIN_WaitConnect(int nUnused)
{
    if ((gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1) || !WINDOW_GetState())
    {
        const int nStatus = CLIENT_GetConnectionStatus();
        if (nStatus == 0)
        {
            GAME_ShowLoadingMessage(6);
            gdwGlobal_007A0460 = 1;
            gdwGlobal_007A0618 = 0;
            return 1;
        }
        return nStatus == 2;
    }
    return 0;
}

// 0x0044BC30
int __cdecl WINMAIN_StartSession()
{
    gdwGlobal_007A0618 = 0;
    if (gdwGlobal_007A0610 == 0)
    {
        SERVER_Initialize(1, 1);
        CLIENT_Initialize(1, 0);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
        SERVER_SetHackListEnabled(0);
        GAME_InitGameDataTable(&gtGameDataTable_007A0690, gtGameList_007A0630);
        gnSubsystemActive_007A0458 = 1;
        GAME_Initialize();
    }
    else if (gdwGlobal_007A0610 == 1)
    {
        SERVER_Initialize(2, 1);
        CLIENT_Initialize(2, 0);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
        SERVER_SetHackListEnabled(0);
        GAME_InitGameDataTable(&gtGameDataTable_007A0690, gtGameList_007A0630);
        gnSubsystemActive_007A0458 = 1;
        GAME_Initialize();
    }
    else if (gdwGlobal_007A0610 == 4)
    {
        CLIENT_Initialize(0, gszAddress_0070F028);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
    }
    else if (gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 8)
    {
        SERVER_Initialize(0, 1);
        SERVER_SetMaxClientsPerGame(8);
        SERVER_SetHackListEnabled(0);
        CLIENT_Initialize(0, gszAddress_0070EF20);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
        GAME_InitGameDataTable(&gtGameDataTable_007A0690, gtGameList_007A0630);
        gnSubsystemActive_007A0458 = 1;
        GAME_Initialize();
    }
    else
    {
        CLIENT_Initialize(0, gszAddress_0070EF20);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
    }

    gdwTick_007A0464 = GetTickCount();
    gdwGlobal_007A0460 = 0;
    SCMD_RunMessageLoop(WINMAIN_PollSystemPackets);
    return GAME_PopStateValue();
}

// 0x0044BD20
int __stdcall WINMAIN_PumpSystemPackets(int nUnused)
{
    unsigned char pBuffer[0x200];
    WINDOW_GetState();
    if (gdwGlobal_007A0610 == 0 || gdwGlobal_007A0610 == 1)
    {
        sub_0052CFE0();
    }

    const int nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
    SCMD_HandleSystemPacket(pBuffer, nLength);
    if (GetTickCount() - gdwTick_007A045C > 10000)
    {
        return 1;
    }
    return gdwGlobal_007A0618 == 0;
}

// 0x0044BD90
int __cdecl WINMAIN_StopSession()
{
    gdwTick_007A045C = GetTickCount();
    SCMD_RunMessageLoop(WINMAIN_PumpSystemPackets);
    CLIENT_Release();
    if (gdwGlobal_007A0610 == 0 || gdwGlobal_007A0610 == 1 || gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 8)
        SERVER_Release();
    return GAME_PopStateValue();
}

// 0x0044B150
int __fastcall WINMAIN_HandleMcpCreateQueue(const unsigned char* pPacket, unsigned int nSize)
{
    sub_00449E30_SetValue(*(const int*)(pPacket + 1));
    sub_00449E50_SetValue(1);
    return 1;
}

// 0x0044B170
int __fastcall WINMAIN_HandleMcpCharList(const unsigned char* pPacket, unsigned int nSize)
{
    sub_00449E70_SetMcpPacket((const char*)pPacket, nSize);
    return 1;
}

// 0x0044B180
int __fastcall WINMAIN_HandleMcpCharListExpanded(const unsigned char* pPacket, unsigned int nSize)
{
    sub_00449E70_SetMcpPacket((const char*)pPacket, nSize);
    return 1;
}

// 0x0044B1C0
int __fastcall WINMAIN_DispatchConnectPacket(const unsigned char* pPacket, unsigned int nSize, void* pArg)
{
    int nResult = 0;
    if (nSize <= 0)
        return nResult;
    const unsigned char nCmd = pPacket[0];
    if (nCmd >= 0x1A)
        return 0;
    D2McpPacketHandler pfnHandler = gpfnMcpHandlers_0070ED68[nCmd];
    if (pfnHandler)
        nResult = pfnHandler(pPacket, nSize);
    return nResult;
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

// 0x0044B120
int __fastcall WINMAIN_HandleMcpMotd(const unsigned char* pPacket, unsigned int nSize)
{
    if (nSize < 2)
        return 0;
    if (gpfnCallback_00799308)
        ((D2McpCallback)gpfnCallback_00799308)(pPacket[1], nSize - 2, pPacket + 2);
    return 1;
}

#include "gen/data/Source/D2Client/CORE/WINMAIN.inc"
