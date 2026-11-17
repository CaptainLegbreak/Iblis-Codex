inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650

extern "C" const char gszTypeNameAllocRec_00711480[];                                                      // 0x00711480

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
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

struct D2ClientAllocRecStrc
{
    D2StormLinkStrc f_0;
    int unk0x08[0x4A];

    static void operator delete(void* pMemory);
};

struct D2ClientAllocRecListStrc
{
    int nLinkOffset;
    D2StormLinkStrc tTerminator;

    D2StormLinkStrc* Link(D2ClientAllocRecStrc* pNode)
    {
        return pNode ? &pNode->f_0 : &tTerminator;
    }
    D2ClientAllocRecStrc* Next(D2ClientAllocRecStrc* pNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        return (int)pLink->m_next <= 0 ? 0 : (D2ClientAllocRecStrc*)pLink->m_next;
    }

    void sub_0045BBE0_LinkNode(D2ClientAllocRecStrc* pNode, unsigned int nLinkType, D2ClientAllocRecStrc* pExisting); // 0x0045BBE0
    D2ClientAllocRecStrc* sub_0045BDD0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
    D2ClientAllocRecStrc* sub_0045BE90_DeleteNode(D2ClientAllocRecStrc* pNode);
};

// 0x0045BDD0
D2ClientAllocRecStrc* D2ClientAllocRecListStrc::sub_0045BDD0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(D2ClientAllocRecStrc) + nExtraBytes, gszTypeNameAllocRec_00711480, -2, nFlags | 8);
    D2ClientAllocRecStrc* pNode = pMemory ? new (pMemory) D2ClientAllocRecStrc : 0;
    if (nLocation)
        sub_0045BBE0_LinkNode(pNode, nLocation, 0);
    return pNode;
}

// build: symbol ??_GD2ClientAllocRecStrc@@QAEPAXI@Z 0x0045BE30
inline void D2ClientAllocRecStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0045BE90
D2ClientAllocRecStrc* D2ClientAllocRecListStrc::sub_0045BE90_DeleteNode(D2ClientAllocRecStrc* pNode)
{
    D2ClientAllocRecStrc* pNext = Next(pNode);
    pNode->~D2ClientAllocRecStrc();
    SMemFree(pNode, gszTypeNameAllocRec_00711480, -2, 0);
    return pNext;
}

// build: context sub_W10_EmitDeleteAllocRec
void sub_W10_EmitDeleteAllocRec(D2ClientAllocRecStrc* pNode)
{
    delete pNode;
}

#include "gen/data/Source/D2Client/0045BDD0_sub_0045BDD0_NewNode.inc"
