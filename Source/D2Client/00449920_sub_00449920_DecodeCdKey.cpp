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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258
extern "C" __declspec(dllimport) int __stdcall GetUserNameA(char* szBuffer, unsigned long* pSize);          // 0x006CC000
extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);                              // 0x006841E9
extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E
extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix);                   // 0x006867B2
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __fastcall sub_00449890_CdKeyChecksum(char* szKey, unsigned int* pChecksum);                           // 0x00449890
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413550
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall SCmdRegisterArgList(const D2CmdArgStrc* pArgList, unsigned int nCount);                       // 0x006C4E50
int __stdcall SCmdProcess(const char* szCmdLine, int bSkipProgName, int (__stdcall* pfnExtra)(const char*), int (__stdcall* pfnError)(const char*)); // 0x006C4FB0
unsigned short __stdcall sub_006BC120_Receive(void* pConnection, char* pBuffer, int nSize);                 // 0x006BC120
int __fastcall sub_0044B190_DispatchPacket(const char* pPacket, unsigned int nSize);                        // 0x0044B190
int __fastcall sub_0044D9F0_RunInitHandlers(void* pArg);                                                    // 0x0044D9F0
int __stdcall sub_0044B5C0_OnExtraArgument(const char* szArgument);                                         // 0x0044B5C0
int __stdcall sub_0044B5D0_OnArgumentError(const char* szArgument);                                         // 0x0044B5D0
int __stdcall WINDOW_GetState();                                                                            // 0x004F6070
void __cdecl sub_0052CFE0();                                                                                // 0x0052CFE0
void __fastcall sub_0044E380_SetConnectionError(int nError);                                                // 0x0044E380
int __cdecl sub_0052A640_IsConnected();                                                                     // 0x0052A640
int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize);                   // 0x0052A890
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize);                 // 0x0052A8B0
void __fastcall sub_0045C850_HandleSystemPacket(unsigned char* pPacket, int nLength);                       // 0x0045C850
void __fastcall sub_0045F7B0_HandleGamePacket(unsigned char* pPacket, int nLength);                         // 0x0045F7B0

extern const unsigned char gnCdKeyMap_006D59F0[256];                                                        // 0x006D59F0
extern void* gpConnection_00798FB4;                                                                         // 0x00798FB4
const char* gpszHelpCaption_007A0454;                                                                       // 0x007A0454
extern const char* gpszLaunchModeNames_0070EE70[7];                                                         // 0x0070EE70
extern int gnLaunchState_0070EE4C;                                                                          // 0x0070EE4C
extern const D2CmdArgStrc gtCommandLineArgs_006D5BE8[8];                                                    // 0x006D5BE8
extern int (__cdecl* const gpfnLaunchInit_006D5BE0[1])();                                                   // 0x006D5BE0
extern "C" const char gszStringFormat_006FFC58[];                                                           // 0x006FFC58
extern char gszCharName_007A05C4[];                                                                         // 0x007A05C4
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern int gdwGlobal_007A0460;                                                                              // 0x007A0460
int gdwGlobal_007A0618;                                                                                     // 0x007A0618
extern unsigned long gdwTick_007A0464;                                                                      // 0x007A0464
extern unsigned long gdwTick_007A045C;                                                                      // 0x007A045C

static int s_bHelpChecked_007A0448;                                                                         // 0x007A0448

// 0x00449920
int __fastcall sub_00449920_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue)
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

// 0x00449B70
int __cdecl sub_00449B70_PollMcpConnection()
{
    char szBuffer[0x400];
    if (!gpConnection_00798FB4)
    {
        return 0;
    }

    const unsigned short nLength = sub_006BC120_Receive(gpConnection_00798FB4, szBuffer, sizeof(szBuffer));
    if (nLength)
    {
        sub_0044B190_DispatchPacket(szBuffer, nLength);
    }
    return 1;
}

// 0x0044B4E0
int __stdcall sub_0044B4E0_ShowCommandLineHelp(const D2CmdParamsStrc* pParams, int nUnused)
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

// 0x0044B600
int __stdcall sub_0044B600_SetLaunchMode(const D2CmdParamsStrc* pParams, int nUnused)
{
    for (unsigned int i = 0; i < 7; ++i)
    {
        if (gpszLaunchModeNames_0070EE70[i] && !_stricmp(gpszLaunchModeNames_0070EE70[i], pParams->szValue))
        {
            gnLaunchState_0070EE4C = i;
            return 1;
        }
    }
    return sub_0044B4E0_ShowCommandLineHelp(pParams, nUnused);
}

// 0x0044B6B0
int __stdcall sub_0044B6B0_ProcessCommandLine(void* pArg)
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

    if (!sub_0044D9F0_RunInitHandlers(pArg))
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
int __stdcall sub_0044BAD0_PollSystemPackets(int nUnused)
{
    unsigned char pBuffer[0x200];
    if ((gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1) || !WINDOW_GetState())
    {
        if (GetTickCount() - gdwTick_007A0464 > 10000)
        {
            sub_0044E380_SetConnectionError(6);
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
    sub_0045C850_HandleSystemPacket(pBuffer, nLength);
    return gdwGlobal_007A0618 != 0;
}

// 0x0044BD20
int __stdcall sub_0044BD20_PumpSystemPackets(int nUnused)
{
    unsigned char pBuffer[0x200];
    WINDOW_GetState();
    if (gdwGlobal_007A0610 == 0 || gdwGlobal_007A0610 == 1)
    {
        sub_0052CFE0();
    }

    const int nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
    sub_0045C850_HandleSystemPacket(pBuffer, nLength);
    if (GetTickCount() - gdwTick_007A045C > 10000)
    {
        return 1;
    }
    return gdwGlobal_007A0618 == 0;
}

// 0x0044C6E0
void __cdecl sub_0044C6E0_DrainPacketQueues()
{
    unsigned char pBuffer[0x200];
    int nLength;
    do
    {
        nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
        sub_0045C850_HandleSystemPacket(pBuffer, nLength);
        Sleep(0);
    }
    while (nLength != -1);

    do
    {
        nLength = CLIENT_DequeueGamePacket(pBuffer, sizeof(pBuffer));
        sub_0045F7B0_HandleGamePacket(pBuffer, nLength);
        Sleep(0);
    }
    while (nLength != -1);
}

#include "gen/data/Source/D2Client/00449920_sub_00449920_DecodeCdKey.inc"
