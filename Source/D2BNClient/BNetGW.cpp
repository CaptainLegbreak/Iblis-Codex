#include "D2BNClient.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
class BNGatewayAccess;
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2SystemTimeStrc
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
};

struct D2TimeZoneInformationStrc
{
    long f_0;
    unsigned short wszStandardName[32];
    D2SystemTimeStrc tStandardDate;
    long nStandardBias;
    unsigned short wszDaylightName[32];
    D2SystemTimeStrc tDaylightDate;
    long nDaylightBias;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" unsigned int __cdecl strlen(const char* szString);
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
void __cdecl sub_00518D40_Log(const char* szFormat, ...); // 0x00518D40
char* __stdcall sub_00518300_LoadGatewayFile(unsigned int* pSize); // 0x00518300

class BNGatewayAccess
{
public:
    BNGatewayAccess& operator=(const BNGatewayAccess& source);
    void __stdcall SetCurGateway(int nGateway);
    void __stdcall UpdateGatewaysFromIni(char* szText);                                                     // 0x00518850

private:
    int GetSystemTimeZone();
    void GetBattlenetRealmsList();
    void WriteDefaultGatewayList();
    char* SkipToEOL(char* pText, char* pEnd);                                                               // 0x00518390
    char* SkipEOL(char* pText, char* pEnd);                                                                 // 0x005183C0
    char* FindSection(char* pText, const char* szSection);
    char* FindKey(char* pSection, const char* szKey);

    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
    char* m_pGatewayList;
    int unk0x14[3];
    void* m_pRealms;
};

// build: symbol ??4BNGatewayAccess@@QAEAAV0@ABV0@@Z 0x00517E40
// 0x00517E40
BNGatewayAccess& BNGatewayAccess::operator=(const BNGatewayAccess& source)
{
    memcpy(this, &source, sizeof(BNGatewayAccess));
    return *this;
}

// 0x00517E60
int BNGatewayAccess::GetSystemTimeZone()
{
    D2TimeZoneInformationStrc tTimeZone;
    SMemZero(&tTimeZone, sizeof(tTimeZone));
    GetTimeZoneInformation(&tTimeZone);
    const unsigned short nLangId = GetUserDefaultLangID();
    if ((nLangId & 0x3FF) == 9 && (nLangId >> 10) == 3)
        return 480;
    return tTimeZone.f_0;
}

// 0x00518150
void __stdcall BNGatewayAccess::SetCurGateway(int nGateway)
{
    if (m_pGatewayList && nGateway >= 1 && nGateway <= m_nNumGateways)
    {
        if (nGateway > 99)
            nGateway = 99;
        m_nCurGateway = nGateway;
        unk0x04 = 1;
    }
}

// 0x005182B0
void BNGatewayAccess::GetBattlenetRealmsList()
{
    unsigned int nSize = 0;
    D2_ASSERT(SFileLoadFile("Data\\Global\\Realms.bin", &m_pRealms, &nSize, 0, 0), 0x188);
}

// 0x00518360
void BNGatewayAccess::WriteDefaultGatewayList()
{
    unsigned int nSize;
    sub_00518D40_Log(szWritingDefaultGateways_006DED24);
    char* szText = sub_00518300_LoadGatewayFile(&nSize);
    if (szText)
        UpdateGatewaysFromIni(szText);
}

// 0x005183F0
char* BNGatewayAccess::FindSection(char* pText, const char* szSection)
{
    const int nTextLength = strlen(pText);
    const int nSectionLength = strlen(szSection);
    char* p = pText;
    while (*p)
    {
        while (*p && *p != '[')
            ++p;
        D2_ASSERT(*p, 0x246);
        if (!_strnicmp(p + 1, szSection, nSectionLength))
            return SkipEOL(SkipToEOL(p + nSectionLength + 2, pText + nTextLength), pText + nTextLength);
        p += nSectionLength;
    }
    return 0;
}

inline char* BnSkipToEOL(char* p, char* pEnd)
{
    while (p < pEnd && *p && *p != '\r' && *p != '\n')
        ++p;
    return p;
}

inline char* BnSkipEOL(char* p, char* pEnd)
{
    while (p < pEnd && *p && (*p == '\r' || *p == '\n'))
        ++p;
    return p;
}

// 0x005184C0
char* BNGatewayAccess::FindKey(char* pSection, const char* szKey)
{
    const int nSectionLength = strlen(pSection);
    const int nKeyLength = strlen(szKey);
    char* p = pSection;
    while (*p && *p != ']')
    {
        if (!_strnicmp(p, szKey, nKeyLength))
            return p + nKeyLength + 1;
        p = BnSkipEOL(BnSkipToEOL(p, pSection + nSectionLength), pSection + nSectionLength);
    }
    return 0;
}

// 0x00518390
extern "C" __declspec(dllexport) const char* __stdcall sub_00518390(const char* pText, const char* pEnd) {
    while (pText < pEnd && *pText && *pText != '\r' && *pText != '\n') {
        pText++;
    }
    return pText;
}

// 0x005183C0
extern "C" __declspec(dllexport) const char* __stdcall sub_005183C0(const char* pText, const char* pEnd) {
    while (pText < pEnd && *pText && (*pText == '\r' || *pText == '\n')) {
        pText++;
    }
    return pText;
}
