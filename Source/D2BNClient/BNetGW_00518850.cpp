#include "D2BNClient.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix);                  // 0x006867B2
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax);                     // 0x004135D0
unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750
void __cdecl sub_00518D40_Log(const char* szFormat, ...);                                                   // 0x00518D40

extern "C" const char szBNetGWFile_006DEC6C[];                                                              // 0x006DEC6C
extern "C" const char szZero_006D5D64[];                                                                    // 0x006D5D64

class BNGatewayAccess
{
public:
    void __stdcall SaveAndUnload();                                                                         // 0x00517ED0
    int __stdcall GMT(int nGateway);                                                                        // 0x00518060
    void __stdcall Load();                                                                                  // 0x005186D0
    void __stdcall UpdateGatewaysFromIni(char* szText);

private:
    int GetSystemTimeZone();                                                                                // 0x00517E60
    char* SkipToEOL(char* pText, char* pEnd);                                                               // 0x00518390
    char* FindSection(char* pText, const char* szSection);                                                  // 0x005183F0
    char* FindKey(char* pSection, const char* szKey);                                                       // 0x005184C0
    void PickClosestZone(int nTimeZone);                                                                    // 0x00518580

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
    char* m_pGatewayList;
    int m_nGatewayListSize;
    unsigned int m_nVersion;
    int m_bOverride;
    void* m_pRealms;
};

// 0x00518850
void __stdcall BNGatewayAccess::UpdateGatewaysFromIni(char* szText)
{
    int nIndex = 0;
    char szKey[16];
    struct { char* pLine; char* szTextCopy; } tLocals;
    tLocals.szTextCopy = szText;
    tLocals.pLine = 0;
    char* pEnd = strlen(tLocals.szTextCopy) + tLocals.szTextCopy;

    char* pVersionSection = FindSection(tLocals.szTextCopy, "Server List Version");
    D2_ASSERT(pVersionSection, 0x277);
    pVersionSection = FindKey(pVersionSection, "VER");
    D2_ASSERT(pVersionSection, 0x27C);

    char* pNumberEnd = pVersionSection;
    const unsigned int nVersion = strtoul(pVersionSection, (&pNumberEnd), 10);
    pVersionSection = 0;
    {
        char* pDest = 0;
        if (nVersion <= m_nVersion)
        {
            return;
        }
        else
        {
            char* pName = 0;
            {
                int nTimeZone = 0;

                sub_00518D40_Log("Parsing new gateway list (version %d)", nVersion);
                if (m_pGatewayList)
                    {
                    nTimeZone = GMT(m_nCurGateway) * 60;
                }
                else
                {
                    nTimeZone = GetSystemTimeZone();
                }
                m_bModified = 0;

                SaveAndUnload();
                m_nVersion = nVersion;
                m_bOverride = 0;
                m_bModified = 1;

                const int nSize = 2 * strlen(tLocals.szTextCopy);
                pVersionSection = (char*)SMemAlloc(nSize, szBNetGWFile_006DEC6C, 0x297, 0);
                sprintf(pVersionSection, "%d", nVersion);
                pDest = pVersionSection + SStrLen(pVersionSection) + 1;
                *pDest = '0';
                pDest++;
                *pDest++ = '0';
                *pDest = '\0';

                pDest++;
                char* pGateways = FindSection((tLocals.szTextCopy), "Server Gateways");
                nIndex = 1;
                sprintf(szKey, "%d", nIndex);
                tLocals.pLine = FindKey(pGateways, szKey);
                if (tLocals.pLine)
                {
                    while (1)
                    {
                        int nLen = SkipToEOL((tLocals.pLine), pEnd) - tLocals.pLine;
                        SStrCopy(pDest, (tLocals.pLine), nLen + 1);
                        pName = pDest;
                        char* pSection = FindSection(tLocals.szTextCopy, pName);
                        if (pSection)
                        {
                            pDest += 1;
                            pDest += nLen;

                            char* pZone = FindKey(pSection, "ZONE");
                            if (pZone)
                            {
                                nLen = SkipToEOL(pZone, pEnd) - pZone;
                                SStrCopy(pDest, pZone, nLen + 1);
                            }
                            else
                            {
                                nLen = 1;
                                SStrCopy(pDest, szZero_006D5D64, 2);
                            }
                            pDest += nLen;
                            pDest = pDest + 1;

                            pZone = FindKey(pSection, "ENU");
                            if (pZone)
                            {
                                nLen = SkipToEOL(pZone, pEnd) - pZone;
                                SStrCopy(pDest, pZone, nLen + 1);
                            }
                            else
                            {
                                nLen = strlen(pName);
                                SStrCopy(pDest, pName, 1 + nLen);
                            }
                            pDest += nLen + 1;
                        }

                        nIndex = nIndex + 1;
                        sprintf(szKey, "%d", nIndex);
                        tLocals.pLine = FindKey(pGateways, szKey);
                        if (!tLocals.pLine)
                            break;
                    }

                }

                *pDest = '\0';
                pDest = 1 + pDest;
                nIndex = pDest - pVersionSection;
                D2_ASSERT(nIndex < nSize, 0x2E6);
                if (!pVersionSection[nIndex - 1] && !(nIndex - 2)[pVersionSection])
                {
                    m_pGatewayList = pVersionSection;
                    m_nGatewayListSize = pDest - pVersionSection;
                    PickClosestZone(nTimeZone);
                    SaveAndUnload();
                    Load();
                }
                else
                {
                    sub_00408A60((&gszEmptyAssertText), sub_00408090(), 0x2E8); exit(-1);
                }
            }
        }
    }

}
