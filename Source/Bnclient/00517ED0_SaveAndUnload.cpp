extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl abs(int nValue);
extern "C" long __cdecl strtol(const char* szString, char** ppEnd, int nRadix);                             // 0x0068676E
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix);                  // 0x006867B2
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);                        // 0x00413590
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
int __stdcall sub_00414D90_RegDeleteValue(const char* szKeyName, const char* szValueName, unsigned int nFlags); // 0x00414D90
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, void* pData, unsigned int nSize); // 0x00415000
char* __stdcall sub_00518300_LoadGatewayFile(unsigned int* pSize);                                          // 0x00518300
void __cdecl sub_00518C70_LogIndent(int nChannel, int nDelta);                                              // 0x00518C70
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40

extern "C" const char szConfiguration_006DEC7C[];                                                           // 0x006DEC7C
extern "C" const char szDiabloGateways_006DEC8C[];                                                          // 0x006DEC8C
extern "C" const char szOverrideGateways_006DECAC[];                                                        // 0x006DECAC
extern "C" const char szWritingDefaultGateways_006DED24[];                                                  // 0x006DED24
extern "C" const char szGatewayIsClosest_006DED44[];                                                        // 0x006DED44
extern "C" const char szFindClosestGateway_006DED78[];                                                      // 0x006DED78
extern "C" const char szAutoPickGateway_006DED9C[];                                                         // 0x006DED9C
extern "C" const char szObsoleteGatewayList_006DEDC0[];                                                     // 0x006DEDC0

class BNGatewayAccess
{
public:
    void __stdcall SaveAndUnload();
    int __stdcall GMT(int nGateway);
    const char* __stdcall Name(int nGateway);
    const char* __stdcall Realm(int nGateway);
    void __stdcall Load();
    void __stdcall UpdateGatewaysFromIni(char* szText);                                                     // 0x00518850

private:
    int GetSystemTimeZone();                                                                                // 0x00517E60
    const char* Nth(int nGateway);
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

// build: symbol ?Nth@BNGatewayAccess@@AAEPBDH@Z 0x00517FD0
// 0x00517ED0
void __stdcall BNGatewayAccess::SaveAndUnload()
{
    if (m_bModified && m_pGatewayList)
    {
        sub_00518D40_Log("Recording gateway list selection");
        char* pCurGateway = m_pGatewayList;
        pCurGateway += SStrLen(pCurGateway) + 1;
        pCurGateway[0] = m_nCurGateway / 10 + '0';
        pCurGateway[1] = m_nCurGateway % 10 + '0';
        const char* szValueName = m_bOverride ? szOverrideGateways_006DECAC : szDiabloGateways_006DEC8C;
        D2_ASSERT(!m_pGatewayList[m_nGatewayListSize - 1] && !m_pGatewayList[m_nGatewayListSize - 2], 0xB9);
        SRegSaveData(szConfiguration_006DEC7C, szValueName, 0x82, m_pGatewayList, m_nGatewayListSize);
    }

    if (m_pGatewayList)
    {
        SMemFree(m_pGatewayList, ".\\BNetGW.cpp", 0xC6, 0);
        m_pGatewayList = 0;
        m_nGatewayListSize = 0;
    }

    if (m_pRealms)
    {
        SMemFree(m_pRealms, ".\\BNetGW.cpp", 0xCC, 0);
        m_pRealms = 0;
    }
}

// 0x00518060
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

// 0x005180A0
const char* __stdcall BNGatewayAccess::Name(int nGateway)
{
    const char* szEntry = Nth(nGateway);
    if (*szEntry)
    {
        szEntry += SStrLen(szEntry) + 1;
        if (*szEntry)
        {
            szEntry += SStrLen(szEntry) + 1;
        }
    }

    return szEntry;
}

// 0x005180E0
const char* __stdcall BNGatewayAccess::Realm(int nGateway)
{
    const char* szName = Nth(nGateway);
    const char* szRealm = (const char*)m_pRealms;
    while (*szRealm)
    {
        if (!SStrCmpI(szRealm, szName, 0x7FFFFFFF))
        {
            return szRealm + SStrLen(szRealm) + 1;
        }

        szRealm += SStrLen(szRealm) + 1;
        if (!*szRealm)
        {
            break;
        }

        szRealm += SStrLen(szRealm) + 1;
    }

    return &gszEmptyAssertText;
}
