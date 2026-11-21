struct D2ScmdNode006C4CF0Strc;
struct sub_006C4010_Link;
struct sub_006C40B0_Link;
struct sub_006C40B0_List;
struct sub_006C40D0_Link;
struct sub_006C4140_Link;
struct sub_006C4140_List;
struct sub_006C4160_LinkStrc;
struct sub_006C4160_List;
struct sub_006C4230_LinkStrc;
struct sub_006C4230_List;
struct TSLink006C4290;
struct TSList006C4290;
struct sub_006C4470_Pair;
struct D2ScmdLink006C4CF0Strc;
struct D2ScmdList006C4CF0Strc;

struct sub_006C4010_Link
{
    sub_006C4010_Link* m_prevlink;
    char* m_next;
};

struct sub_006C40B0_Link
{
    sub_006C40B0_Link* pPrev;
    unsigned int dwNext;
};

struct sub_006C40B0_List
{
    int unk_00;
    sub_006C40B0_Link tLink;
};

struct sub_006C40D0_Link
{
    sub_006C40D0_Link* m_prevlink;
    char* m_next;
};

struct sub_006C4140_Link
{
    sub_006C4140_Link* m_prevlink;
    char* m_next;
};

struct sub_006C4140_List
{
    int m_linkoffset;
    sub_006C4140_Link m_terminator;
};

struct sub_006C4160_LinkStrc
{
    sub_006C4160_LinkStrc* m_prevlink;
    char* m_next;
};

struct sub_006C4160_List
{
    int m_linkoffset;
    sub_006C4160_LinkStrc m_terminator;

    sub_006C4160_LinkStrc* sub_006C4160_Link(sub_006C4160_LinkStrc* pLink);
};

struct sub_006C4230_LinkStrc
{
    sub_006C4230_LinkStrc* m_prevlink;
    char* m_next;
};

struct sub_006C4230_List
{
    int m_linkoffset;
    sub_006C4230_LinkStrc m_terminator;

    char* sub_006C4230_Next(sub_006C4230_LinkStrc* pLink);
};

struct TSLink006C4290
{
    TSLink006C4290* m_prevlink;
    int m_next;

    __forceinline TSLink006C4290* NextLink(int linkoffset)
    {
        if (m_next < 0)
            return (TSLink006C4290*)~m_next;
        if (linkoffset < 0)
            linkoffset = (int)this - m_prevlink->m_next;
        return (TSLink006C4290*)(m_next + linkoffset);
    }

    __forceinline void Unlink()
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

struct TSList006C4290
{
    int m_linkoffset;
    TSLink006C4290 m_terminator;

    void sub_006C4290(TSLink006C4290* link);
};

struct sub_006C4470_Pair
{
    int nFirst;
    int nSecond;
};


extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

struct D2ScmdLink006C4CF0Strc
{
    D2ScmdLink006C4CF0Strc* m_prevlink;
    D2ScmdNode006C4CF0Strc* m_next;
};

struct D2ScmdNode006C4CF0Strc
{
    D2ScmdLink006C4CF0Strc tLink;
    unsigned int dwFlags;
    int nId;
    unsigned char unk_10[0x28];
    int nValue;
    union
    {
        void* pBuffer;
        const char* szText;
    };
};

struct D2ScmdList006C4CF0Strc
{
    int m_linkoffset;
    D2ScmdLink006C4CF0Strc m_terminator;

    void sub_006C4760_DeleteAll(); // 0x006C4760
};


extern D2ScmdList006C4CF0Strc gtList_0074C48C; // 0x0074C48C
extern D2ScmdList006C4CF0Strc gtList_0074C498; // 0x0074C498
extern int gnValue_00989C38; // 0x00989C38

// 0x006C4010
char* __fastcall sub_006C4010_Head(sub_006C4010_Link* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x006C40B0
void __fastcall sub_006C40B0_InitList(sub_006C40B0_List* pList)
{
    sub_006C40B0_Link* pLink = &pList->tLink;
    pLink->pPrev = pLink;
    pList->tLink.dwNext = ~(unsigned int)pLink;
}

// 0x006C40C0
void* __fastcall sub_006C40C0_Identity(void* p)
{
    return p;
}

// 0x006C40D0
char* __fastcall sub_006C40D0_Head(sub_006C40D0_Link* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x006C4140
void __fastcall sub_006C4140_InitList(sub_006C4140_List* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_linkoffset = 0;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x006C4160
sub_006C4160_LinkStrc* sub_006C4160_List::sub_006C4160_Link(sub_006C4160_LinkStrc* pLink)
{
    return pLink ? pLink : &m_terminator;
}

// 0x006C4230
char* sub_006C4230_List::sub_006C4230_Next(sub_006C4230_LinkStrc* pLink)
{
    sub_006C4230_LinkStrc* pCurrent = pLink ? pLink : &m_terminator;
    return (int)pCurrent->m_next > 0 ? pCurrent->m_next : 0;
}

// 0x006C4290
void TSList006C4290::sub_006C4290(TSLink006C4290* link)
{
    if (!link)
        link = &m_terminator;
    link->Unlink();
}

// 0x006C4470
sub_006C4470_Pair* __fastcall sub_006C4470_Clear(sub_006C4470_Pair* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
    return pPair;
}

// 0x006C4CF0
int __cdecl sub_006C4CF0_FreeBuffers()
{
    for (int i = 0; i <= 1; ++i)
    {
        D2ScmdList006C4CF0Strc* pList = i ? &gtList_0074C498 : &gtList_0074C48C;
        for (D2ScmdNode006C4CF0Strc* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->tLink.m_next)
        {
            if ((pNode->dwFlags & 0x30000) == 0x20000 && pNode->pBuffer)
            {
                SMemFree(pNode->pBuffer, ".\\SOURCE\\SCMD.CPP", 0x212, 0);
                pNode->pBuffer = 0;
            }
        }
    }
    gtList_0074C48C.sub_006C4760_DeleteAll();
    gtList_0074C498.sub_006C4760_DeleteAll();
    gnValue_00989C38 = 0;
    return 1;
}

void __stdcall sub_0041C340_SetLastError(unsigned long dwError); // 0x0041C340
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0

// 0x006C4CA0
int __stdcall sub_006C4CA0_FindValue(int nId)
{
    for (int i = 0; i <= 1; ++i)
    {
        D2ScmdList006C4CF0Strc* pList = i ? &gtList_0074C498 : &gtList_0074C48C;
        for (D2ScmdNode006C4CF0Strc* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->tLink.m_next)
        {
            if (pNode->nId == nId)
                return pNode->nValue;
        }
    }
    return 0;
}

// 0x006C4DC0
int __stdcall sub_006C4DC0_GetText(int nId, char* szBuffer, unsigned int nBufferSize)
{
    if (szBuffer)
    {
        *szBuffer = 0;
    }

    int nValid = (szBuffer ? -1 : 0) & (nBufferSize ? -1 : 0);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return nValid;
    }

    for (int i = 0; i <= 1; ++i)
    {
        D2ScmdList006C4CF0Strc* pList = i ? &gtList_0074C498 : &gtList_0074C48C;
        for (D2ScmdNode006C4CF0Strc* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->tLink.m_next)
        {
            if (pNode->nId == nId)
            {
                if (pNode->szText)
                {
                    SStrCopy(szBuffer, pNode->szText, nBufferSize);
                }
                return 1;
            }
        }
    }
    return 0;
}
