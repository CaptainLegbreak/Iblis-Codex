extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

struct D2ScmdNode006C4CF0Strc;

struct D2ScmdLink006C4CF0Strc
{
    D2ScmdLink006C4CF0Strc* m_prevlink;
    D2ScmdNode006C4CF0Strc* m_next;
};

struct D2ScmdNode006C4CF0Strc
{
    D2ScmdLink006C4CF0Strc tLink;
    unsigned int dwFlags;
    unsigned char unk_0C[0x30];
    void* pBuffer;
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
