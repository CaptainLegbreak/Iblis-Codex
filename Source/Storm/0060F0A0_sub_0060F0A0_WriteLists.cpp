struct D2FileStrc;
struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;

    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};
struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
};
struct D2IgnoreKeyNodeStrc
{
    unsigned char unk_00[0x14];
    const char* m_key;
};
struct D2StormHashTableStrc
{
    void* pVtable;
    D2StormSlotListStrc m_fulllist;
    unsigned char unk_10[0x18];

    char* Head()
    {
        char* pHead = m_fulllist.m_terminator.Next();
        return pHead;
    }
    char* Next(char* pNode)
    {
        pNode += m_fulllist.m_linkoffset;
        D2StormLinkStrc* pLink = (D2StormLinkStrc*)pNode;
        return pLink->Next();
    }
};
struct D2IgnoreListStrc
{
    void* pVtable;
    D2StormHashTableStrc m_table;
    D2StormHashTableStrc m_table2;
    unsigned char unk_54[0x2C];
    char szFileName[0x104];
};
extern "C" D2FileStrc* __cdecl fopen(const char*, const char*); // 0x0068239A
extern "C" int __cdecl fclose(D2FileStrc*); // 0x00681FDC
extern "C" int __cdecl fprintf(D2FileStrc*, const char*, ...); // 0x00684C94
extern const char gszFileMode_006FF97C[]; // 0x006FF97C
extern const char gszFirstFormat_006CD90C[]; // 0x006CD90C
extern const char gszSecondFormat_006E62A8[]; // 0x006E62A8

// 0x0060F0A0
int __fastcall sub_0060F0A0_WriteLists(D2IgnoreListStrc* pList)
{
    D2FileStrc* pFile = fopen(pList->szFileName, gszFileMode_006FF97C);
    if (!pFile)
        return 0;
    for (char* pNode = pList->m_table.Head(); (int)pNode > 0; pNode = pList->m_table.Next(pNode))
        fprintf(pFile, gszFirstFormat_006CD90C, ((D2IgnoreKeyNodeStrc*)pNode)->m_key);
    for (char* pNode = pList->m_table2.Head(); (int)pNode > 0; pNode = pList->m_table2.Next(pNode))
        fprintf(pFile, gszSecondFormat_006E62A8, ((D2IgnoreKeyNodeStrc*)pNode)->m_key);
    fclose(pFile);
    return 1;
}

#include "gen/data/Source/Storm/0060F0A0_sub_0060F0A0_WriteLists.inc"
