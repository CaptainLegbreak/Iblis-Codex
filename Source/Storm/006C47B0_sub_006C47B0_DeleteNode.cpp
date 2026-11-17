extern const char gszCmdDef_0074C47C[]; // 0x0074C47C
int __stdcall SMemFree(void*,const char*,int,unsigned int); // 0x00412650
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

struct D2CmdListStrc {
 int offset; D2StormLinkStrc terminator;
 D2StormLinkStrc* Link(char* node) { return node ? (D2StormLinkStrc*)node : &terminator; }
 char* sub_006C47B0_DeleteNode(char* node);
};
// 0x006C47B0
char* D2CmdListStrc::sub_006C47B0_DeleteNode(char* node) {
 char* next=Link(node)->Next();
 ((D2StormLinkStrc*)node)->Unlink();
 SMemFree(node,gszCmdDef_0074C47C,-2,0);
 return next;
}
