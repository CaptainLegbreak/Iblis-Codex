#include "D2BNClient.h"

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650
extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix);                  // 0x006867B2

class BNGatewayAccess
{
public:
    const char* __stdcall DNS(int nGateway);

private:
    const char* sub_00517FD0_GetGatewayEntry(int nGateway);                                                 // 0x00517FD0
    void GetGatewayList(const char* szValueName);

    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
    char* m_pGatewayList;
    unsigned int m_nGatewayListSize;
    unsigned int m_nDefaultGateway;
    int unk0x1C;
    void* m_pRealms;
};

// 0x00518040
const char* __stdcall BNGatewayAccess::DNS(int nGateway)
{
    return sub_00517FD0_GetGatewayEntry(nGateway);
}

// 0x00518190
void BNGatewayAccess::GetGatewayList(const char* szValueName)
{
    D2_ASSERT(!m_pGatewayList, 0x146);
    unsigned int nSize = 0;
    if (!SRegLoadData(szConfiguration_006DEC7C, szValueName, 0x82, 0, 0, &nSize) || !nSize)
        return;
    m_nGatewayListSize = nSize;
    m_pGatewayList = (char*)SMemAlloc(nSize, ".\\BNetGW.cpp", 0x156, 0);
    if (!SRegLoadData(szConfiguration_006DEC7C, szValueName, 0x82, m_pGatewayList, m_nGatewayListSize, 0))
    {
        SMemFree(m_pGatewayList, ".\\BNetGW.cpp", 0x15E, 0);
        m_pGatewayList = 0;
        m_nGatewayListSize = 0;
    }
    m_nDefaultGateway = 0;
    if (m_pGatewayList)
    {
        char* pEnd = m_pGatewayList;
        m_nDefaultGateway = strtoul(m_pGatewayList, &pEnd, 10);
        if (m_pGatewayList == pEnd)
            m_nDefaultGateway = 0;
    }
}
