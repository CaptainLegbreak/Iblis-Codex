// build: context ??_GD2StormCmdDefStrc@@QAEPAXI@Z
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern char gszTypeNameCmdDef_0074C47C[]; // 0x0074C47C

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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
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

struct D2StormCmdDefStrc
{
    D2StormLinkStrc tLink;
    char unk0x08[0x10];

    ~D2StormCmdDefStrc()
    {
        tLink.Unlink();
    }
};

struct D2StormCmdDefListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_006C4760_DeleteAll();
};

// 0x006C4760
void D2StormCmdDefListStrc::sub_006C4760_DeleteAll()
{
    while (D2StormCmdDefStrc* pRecord = (D2StormCmdDefStrc*)Head())
    {
        pRecord->~D2StormCmdDefStrc();
        SMemFree(pRecord, gszTypeNameCmdDef_0074C47C, -2, 0);
    }
}

#include "gen/data/Source/Storm/006C4760_sub_006C4760_DeleteAll.inc"
