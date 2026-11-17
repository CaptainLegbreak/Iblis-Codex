extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2TickTimerStrc
{
    unsigned int dwStart;
    unsigned int dwDuration;

    unsigned int sub_0044DFB0_GetRemaining();
};

// 0x0044DDC0
char* __fastcall sub_0044DDC0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0044DE30
char* __fastcall sub_0044DE30_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0044DF00
void __fastcall sub_0044DF00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0044DF20
void __fastcall sub_0044DF20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0044DFB0
unsigned int D2TickTimerStrc::sub_0044DFB0_GetRemaining()
{
    unsigned int dwNow = GetTickCount();
    if (dwNow >= dwStart + dwDuration)
    {
        dwStart = 0;
        dwDuration = 0;
        return 0;
    }
    return dwStart + dwDuration - dwNow;
}
