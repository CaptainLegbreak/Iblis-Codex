#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct D2ClientCharRecordStrc;
struct D2StormLinkStrc;
struct D2StormListStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2FlagWordStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

struct D2ClientCharRecordStrc
{
    char unk0x00[0x19];
    char aState[4];
    char unk0x1D[2];
    char szName[0x1D0];
};
void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc* pSystem, int bFreePoolAlloc); // 0x00409FF0
int __stdcall sub_0044B6B0(D2ClientCharRecordStrc* pRecord); // 0x0044B6B0
int __cdecl sub_00451330(); // 0x00451330
void __cdecl sub_004F8FE0(); // 0x004F8FE0
int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc); // 0x004F8FC0
int __stdcall sub_00451B30_WindowProc(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam); // 0x00451B30
void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80
void __stdcall sub_00619300(void* pArg, int bArg); // 0x00619300
void __cdecl sub_00619140(); // 0x00619140
void __cdecl sub_00451290(); // 0x00451290
void __cdecl sub_006116B0_WriteProfileCounters(); // 0x006116B0
void __cdecl sub_0044BB80(); // 0x0044BB80
extern D2ClientCharRecordStrc* gpCharRecord_007A0438; // 0x007A0438
extern int (__cdecl* gpfnLaunchStates_0070EE54[])(); // 0x0070EE54
extern unsigned short gwValue_0077905C;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

struct D2FlagWordStrc
{
    unsigned short wFlags;
};

struct D2UnitStrc
{
    int dwUnitType;
};

void* ghInstance_007A043C; // 0x007A043C

char gszModulePath_007A0320[260]; // 0x007A0320

int gnLaunchResult_007A0440; // 0x007A0440

// 0x0044B8A0
int __stdcall sub_0044B8A0_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord)
{
    gpCharRecord_007A0438 = pRecord;
    sub_00409B80(0);
    FOG_SetMemoryPoolSystemMode(0, 1);
    ghInstance_007A043C = hInstance;
    GetModuleFileNameA(hInstance, gszModulePath_007A0320, 0x104);
    if (!sub_0044B6B0(pRecord))
        return 0;
    if (!sub_00451330())
        return 0;
    sub_004F8FE0();
    D2Win_10014_SetWndProc((WNDPROC)sub_00451B30_WindowProc);
    if (!sub_005259C0(sub_004FAC80(sub_00408F20_HasExpansionMpq()), 0))
        return 0;
    int nLanguage;
    sub_00525260(&nLanguage, 0);
    sub_00619300(sub_004FAC80(0), *(int*)pRecord->aState == 6);
    gnLaunchState_0070EE4C = 3;
    gdwGlobal_0070EE8C = 1;
    while (gnLaunchState_0070EE4C != 1)
    {
        gnLaunchState_0070EE4C = gpfnLaunchStates_0070EE54[gnLaunchState_0070EE4C]();
        D2_ASSERT(gnLaunchState_0070EE4C < 7, 0x28E);
        D2_ASSERT(gnLaunchState_0070EE4C > 0, 0x28F);
    }
    sub_004FA550();
    sub_00619140();
    sub_00524E40();
    sub_00451290();
    sub_006116B0_WriteProfileCounters();
    sub_0044BB80();
    int nResult;
    if (gdwGlobal_0070EE8C)
    {
        nResult = 0;
    }
    else
    {
        switch (*(int*)pRecord->aState)
        {
        case 0:
        case 8:
        case 9:
            nResult = 4;
            break;
        case 2:
        case 3:
        case 6:
        case 7:
            nResult = 3;
            break;
        default:
            gnLaunchResult_007A0440 = 4;
            return 4;
        }
    }
    gnLaunchResult_007A0440 = nResult;
    return nResult;
}

#include "gen/data/Source/D2Client/Unknown_0044B8A0.inc"

unsigned short __stdcall sub_004166F0_GetWord()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0044BDD0
char* __fastcall sub_00416800_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

// 0x0044BE30
unsigned short __fastcall sub_0044BE30_SetFlagBits(D2FlagWordStrc* pFlags, unsigned short nValue)
{
    pFlags->wFlags = (pFlags->wFlags & 0xE0FF) | (nValue << 8);
    return pFlags->wFlags;
}

// 0x0044BE50
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    return nUnitType;
}
