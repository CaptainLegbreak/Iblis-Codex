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

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...);                             // 0x00684BD5
extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName);                                      // 0x006B0192
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress);                                                // 0x006B013E
extern "C" int __stdcall WSACleanup();                                                                      // 0x006B0138
extern "C" int __stdcall WSAGetLastError();                                                                 // 0x006B0168
int __fastcall FOG_SOCKET_WSAStartup();                                                                     // 0x0040D890
extern char gszResolvedHostIP_0075D040[];                                                                   // 0x0075D040

// 0x0040E0D0
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName)
{
    int bStarted = 0;
    int a, b, c, d;
    if (sscanf(szHostName, "%d.%d.%d.%d", &a, &b, &c, &d) == 4)
    {
        return szHostName;
    }
    D2HostentStrc* pHost = gethostbyname(szHostName);
    if (!pHost || !pHost->h_addr_list || !pHost->h_addr_list[0])
    {
        if (WSAGetLastError() != 0x276D || !FOG_SOCKET_WSAStartup())
        {
            return 0;
        }
        pHost = gethostbyname(szHostName);
        if (!pHost || !pHost->h_addr_list || !pHost->h_addr_list[0])
        {
            WSACleanup();
            return 0;
        }
        bStarted = 1;
    }
    strcpy(gszResolvedHostIP_0075D040, inet_ntoa(*(D2InAddrStrc*)pHost->h_addr_list[0]));
    if (bStarted)
    {
        WSACleanup();
    }
    return gszResolvedHostIP_0075D040;
}
