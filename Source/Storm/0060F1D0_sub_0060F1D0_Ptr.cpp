int __stdcall sub_00413590_StrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    char* Next()
    {
        return (char*)((((int)m_next <= 0) - 1) & (int)m_next);
    }
};
struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
};
struct D2StormListArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;
};
struct D2StormNamedNodeStrc
{
    unsigned int m_hashval;
    unsigned char unk_04[0x10];
    const char* m_key;
};
struct D2StormNameKeyStrc
{
    const char* m_str;
};
struct D2StormHashTable0060F1D0Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* sub_0060F1D0_Ptr(unsigned int nHashVal, const D2StormNameKeyStrc& tKey);
};

// 0x0060F1D0
char* D2StormHashTable0060F1D0Strc::sub_0060F1D0_Ptr(unsigned int nHashVal, const D2StormNameKeyStrc& tKey)
{
    for (char* pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].Head(); (int)pNode > 0; pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormNamedNodeStrc*)pNode)->m_hashval == nHashVal && !sub_00413590_StrCmpI(((D2StormNamedNodeStrc*)pNode)->m_key, tKey.m_str, 0x7FFFFFFF))
        {
            return pNode;
        }
    }
    return 0;
}
