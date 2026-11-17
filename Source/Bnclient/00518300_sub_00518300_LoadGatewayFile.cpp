extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl abs(int nValue);
extern "C" long __cdecl strtol(const char* szString, char** ppEnd, int nRadix);                             // 0x0068676E
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped); // 0x0041B650
int __cdecl sub_00518C70_StartLogging(int nChannel, int nIndent);                                           // 0x00518C70
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40

class BNGatewayAccess
{
public:
    void __stdcall SaveAndUnload();                                                                         // 0x00517ED0
    int __stdcall GMT(int nGateway);
    const char* __stdcall Name(int nGateway);                                                               // 0x005180A0
    const char* __stdcall Realm(int nGateway);                                                              // 0x005180E0
    void __stdcall Load();                                                                                  // 0x005186D0
    void __stdcall UpdateGatewaysFromIni(char* szText);                                                     // 0x00518850

private:
    int GetSystemTimeZone();                                                                                // 0x00517E60
    const char* Nth(int nGateway);                                                                          // 0x00517FD0
    void GetGatewayList(const char* szValueName);                                                           // 0x00518190
    void GetBattlenetRealmsList();                                                                          // 0x005182B0
    void PickClosestZone(int nTimeZone);

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
    char* m_pGatewayList;
    int m_nGatewayListSize;
    unsigned int m_nDefaultGateway;
    int m_bOverride;
    void* m_pRealms;
};

int __stdcall BNGatewayAccess::GMT(int nGateway)
{
    const char* szEntry = Nth(nGateway);
    if (*szEntry)
    {
        szEntry += SStrLen(szEntry) + 1;
    }

    char* pEnd;
    return strtol(szEntry, &pEnd, 10);
}

// 0x00518300
char* __stdcall sub_00518300_LoadGatewayFile(unsigned int* pSize)
{
    void* pBuffer;
    unsigned int nSize = 0;
    D2_ASSERT(SFileLoadFile("DATA\\GLOBAL\\gateways.txt", &pBuffer, &nSize, 0, 0), 0x1F9);
    unsigned int* const pOut = *(unsigned int* volatile*)&pSize;
    *pOut = *(volatile unsigned int*)&nSize;
    return (char*)pBuffer;
}

// 0x00518580
void BNGatewayAccess::PickClosestZone(int nTimeZone)
{
    sub_00518C70_StartLogging(2, 4);
    sub_00518D40_Log("Find gateway closest to %02d.%02d", nTimeZone / 60, nTimeZone % 60);

    int nBest = 1;
    int nBestDistance = 0x564;
    for (int i = 1; i <= m_nNumGateways; ++i)
    {
        const int nDistance = abs(GMT(i) * 60 - nTimeZone);
        if (nDistance < nBestDistance)
        {
            nBest = i;
            nBestDistance = nDistance;
        }
    }

    const int nGMT = GMT(nBest);
    const char* szName = Nth(nBest);
    sub_00518D40_Log("Gateway %d (%s at GMT %02d) is closest to %02d.%02d", nBest, szName, nGMT, nTimeZone / 60, nTimeZone % 60);
    sub_00518C70_StartLogging(2, -4);

    if (m_pGatewayList && nBest >= 1 && nBest <= m_nNumGateways)
    {
        if (nBest > 99)
        {
            nBest = 99;
        }
        m_nCurGateway = nBest;
        m_bModified = 1;
    }
}
