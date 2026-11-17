void __stdcall sub_0041C340_SetLastError(unsigned long dwError); // 0x0041C340
int __stdcall sub_004135D0_CopyString(char* szDest, const char* szSource, unsigned int nMaxLength); // 0x004135D0

struct D2ScmdNode006C4DC0Strc;

struct D2ScmdLink006C4DC0Strc
{
    D2ScmdLink006C4DC0Strc* m_prevlink;
    D2ScmdNode006C4DC0Strc* m_next;
};

struct D2ScmdNode006C4DC0Strc
{
    D2ScmdLink006C4DC0Strc tLink;
    unsigned int dwFlags;
    int nId;
    unsigned char unk_10[0x2C];
    const char* szText;
};

struct D2ScmdList006C4DC0Strc
{
    int m_linkoffset;
    D2ScmdLink006C4DC0Strc m_terminator;
};

extern D2ScmdList006C4DC0Strc gtList_0074C48C; // 0x0074C48C
extern D2ScmdList006C4DC0Strc gtList_0074C498; // 0x0074C498

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
        D2ScmdList006C4DC0Strc* pList = i ? &gtList_0074C498 : &gtList_0074C48C;
        for (D2ScmdNode006C4DC0Strc* pNode = pList->m_terminator.m_next; (int)pNode > 0; pNode = pNode->tLink.m_next)
        {
            if (pNode->nId == nId)
            {
                if (pNode->szText)
                {
                    sub_004135D0_CopyString(szBuffer, pNode->szText, nBufferSize);
                }
                return 1;
            }
        }
    }
    return 0;
}
