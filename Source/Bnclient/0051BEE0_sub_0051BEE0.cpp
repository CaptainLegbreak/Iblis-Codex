extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HostentStrc
{
    char* h_name;
    char** h_aliases;
    short h_addrtype;
    short h_length;
    char** h_addr_list;
};

struct D2InAddrStrc
{
    unsigned long s_addr;
};

struct D2BnDnsArgsStrc
{
    char* szResult;
    const char* f_4;
};

extern "C" int __cdecl isdigit(int c);                                                                      // 0x00686F0F
extern "C" unsigned long __stdcall inet_addr(const char* szAddress);                                        // 0x006B0150
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName);                                      // 0x006B0192
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" void __cdecl srand(unsigned int nSeed);                                                          // 0x00687454
extern "C" int __cdecl rand();                                                                              // 0x00687461
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40
void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...);                                              // 0x0051A480
extern "C" const char gszSemicolon_006CDA54[];                                                              // 0x006CDA54
unsigned long gnDnsAddr_00881C08;                                                                           // 0x00881C08
char* gapDnsAddrList_00881C0C[2];                                                                           // 0x00881C0C
D2HostentStrc gDnsHostent_00881C14;                                                                         // 0x00881C14

// 0x0051BEE0
unsigned long __stdcall sub_0051BEE0(void* pArguments)
{
    D2BnDnsArgsStrc* pArgs = (D2BnDnsArgsStrc*)pArguments;
    char* szOut = pArgs->szResult;
    const char* szHost = pArgs->f_4;
    D2HostentStrc* pHost;
    if (isdigit(*szHost))
    {
        const unsigned long nAddr = inet_addr(szHost);
        if (nAddr == 0xFFFFFFFF)
        {
            sub_00518D40_Log("ERROR GetServersList: inet_addr failed to convert IP (%d)", WSAGetLastError());
            return 0;
        }
        gDnsHostent_00881C14.h_addr_list = gapDnsAddrList_00881C0C;
        gapDnsAddrList_00881C0C[0] = (char*)&gnDnsAddr_00881C08;
        gapDnsAddrList_00881C0C[1] = 0;
        pHost = &gDnsHostent_00881C14;
        gnDnsAddr_00881C08 = nAddr;
    }
    else
    {
        pHost = gethostbyname(szHost);
        if (!pHost)
        {
            sub_00518D40_Log("ERROR GetServersList: gethostbyname failed to get server list (%d)", WSAGetLastError());
            return 0;
        }
    }

    char** ppList = pHost->h_addr_list;
    int nCount = 0;
    sub_0051A480_DebugLog(&gszEmptyAssertText);
    sub_0051A480_DebugLog("Original servlist:");
    while (ppList[nCount])
    {
        sub_0051A480_DebugLog("%d --> %s", nCount, inet_ntoa(*(D2InAddrStrc*)ppList[nCount]));
        ++nCount;
    }
    sub_0051A480_DebugLog(&gszEmptyAssertText);
    sub_0051A480_DebugLog("Scrambled servlist:");

    srand(GetTickCount());
    for (int j = 0; j < nCount - 1; ++j)
    {
        const int k = rand() * (nCount - 1 - j) / 0x8000 + j;
        D2_ASSERT(j <= k, 0x1AD);
        sub_0051A480_DebugLog("%d <-> %d SWAP", j, k);
        const unsigned long nTemp = ((D2InAddrStrc*)ppList[j])->s_addr;
        ((D2InAddrStrc*)ppList[j])->s_addr = ((D2InAddrStrc*)ppList[k])->s_addr;
        ((D2InAddrStrc*)ppList[k])->s_addr = nTemp;
    }
    sub_0051A480_DebugLog(&gszEmptyAssertText);

    char* p = szOut;
    for (char** pp = pHost->h_addr_list; *pp; ++pp)
    {
        p += SStrCopy(p, inet_ntoa(*(D2InAddrStrc*)*pp), 0x7FFFFFFF);
        p += SStrCopy(p, gszSemicolon_006CDA54, 0x7FFFFFFF);
    }
    if (p > szOut)
        p[-1] = 0;
    return 1;
}
