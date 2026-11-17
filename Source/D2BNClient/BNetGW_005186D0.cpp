#include "D2BNClient.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl abs(int nValue);
extern "C" long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix);                             // 0x006867B2
int __stdcall SStrLen(const char* szString);                                                                // 0x00413750
int __cdecl sub_00518C70_StartLogging(int nChannel, int nIndent);                                           // 0x00518C70
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40

void __stdcall sub_00414D90_RegDeleteValue(const char* szKeyName, const char* szValueName, unsigned int dwFlags); // 0x00414D90
char* __stdcall sub_00518300_LoadGatewayFile(unsigned int* pSize);                                          // 0x00518300

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

// build: symbol ?PickClosestZone@BNGatewayAccess@@AAEXH@Z 0x00518580
// 0x005186D0
void __stdcall BNGatewayAccess::Load()
{
    if (m_pGatewayList)
    {
        return;
    }

    int nOffset;

    m_nNumGateways = 0;
    m_nCurGateway = 0;
    m_pRealms = 0;
    m_pGatewayList = 0;
    m_nGatewayListSize = 0;
    m_nDefaultGateway = 0;
    m_szEmpty[0] = 0;
    GetBattlenetRealmsList();
    m_bOverride = 0;
    GetGatewayList("Override Battle.net gateways");
    if (m_pGatewayList)
    {
        m_bOverride = 1;
    }
    else
    {
        GetGatewayList("Diablo II Battle.net gateways");
    }

    if (m_pGatewayList && m_nDefaultGateway < 1000)
    {
        sub_00518D40_Log("Obsolete gateway list (%d) - autodeleting", m_nDefaultGateway);
        m_bModified = 0;
        SaveAndUnload();
        sub_00414D90_RegDeleteValue("Configuration", "Diablo II Battle.net gateways", 2);
    }

    if (!m_pGatewayList)
    {
        sub_00518D40_Log("Writing default gateway list");
        char* szText = sub_00518300_LoadGatewayFile((unsigned int*)&nOffset);
        if (szText)
        {
            UpdateGatewaysFromIni(szText);
        }
    }

    D2_ASSERT(m_nDefaultGateway >= 1000, 0x5B);

    const char* szEntry = m_pGatewayList;
    int nStrings = -2;
    for (nOffset = 0; nOffset < m_nGatewayListSize; ++nStrings)
    {
        const int nLength = SStrLen(szEntry) + 1;
        nOffset += nLength;
        szEntry += nLength;
    }

    --nStrings;
    D2_ASSERT(nStrings % 3 == 0, 0x6C);
    m_nNumGateways = nStrings / 3;

    char* pEnd;
    const char* szList = m_pGatewayList;
    szList += SStrLen(szList) + 1;
    m_nCurGateway = strtoul(szList, &pEnd, 10);
    m_bModified = 0;
    if (m_nCurGateway < 1 || m_nCurGateway > m_nNumGateways)
    {
        sub_00518D40_Log("Auto-picking gateway based on GMT");
        PickClosestZone(GetSystemTimeZone());
    }
}
