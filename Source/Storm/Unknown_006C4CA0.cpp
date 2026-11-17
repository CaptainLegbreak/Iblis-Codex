struct sub_006C4CA0_Node
{
    int m_prevlink;
    sub_006C4CA0_Node* m_next;
    int unk_08;
    int nId;
    char unk_10[0x28];
    int nValue;
};

struct sub_006C4CA0_List
{
    int m_linkoffset;
    int m_prevlink;
    sub_006C4CA0_Node* m_next;
};

extern sub_006C4CA0_List gList_0074C48C; // 0x0074C48C
extern sub_006C4CA0_List gList_0074C498; // 0x0074C498

// 0x006C4CA0
int __stdcall sub_006C4CA0_FindValue(int nId)
{
    for (int i = 0; i <= 1; ++i)
    {
        sub_006C4CA0_List* pList = i ? &gList_0074C498 : &gList_0074C48C;
        for (sub_006C4CA0_Node* pNode = pList->m_next; (int)pNode > 0; pNode = pNode->m_next)
        {
            if (pNode->nId == nId)
                return pNode->nValue;
        }
    }
    return 0;
}
