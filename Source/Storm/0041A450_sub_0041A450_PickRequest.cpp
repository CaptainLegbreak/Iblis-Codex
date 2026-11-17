struct D2StormLink0041A450Strc
{
    D2StormLink0041A450Strc* m_prevlink;
    char* m_next;
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    char* Prev()
    {
        return m_prevlink->m_prevlink->Next();
    }
};

struct D2StormArchive0041A450Strc
{
    unsigned char unk_000[0x124];
    unsigned int nBaseOffset;
};

struct D2StormFile0041A450Strc
{
    unsigned char unk_000[0x114];
    D2StormArchive0041A450Strc* f_114;
};

struct D2StormRequest0041A450Strc
{
    D2StormLink0041A450Strc f_0;
    void* hEvent;
    D2StormFile0041A450Strc* pFile;
    unsigned int nPosition;
    unsigned int nFileOffset;
    unsigned int nDueTime;
    int bClampDue;
    unsigned char* pDest;
    unsigned int f_24;
    void* pBuffer;
    unsigned int f_2C;
    void* pStream;
};

struct D2StormListStrc
{
    int m_linkoffset;
    void* m_prevlink;
    char* m_next;
    char* Head()
    {
        char* pHead = (int)m_next <= 0 ? 0 : m_next;
        return pHead;
    }
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern D2StormListStrc gRequestList_00708360;                                                               // 0x00708360
extern int gnValue_00708350;                                                                                // 0x00708350

// 0x0041A450
void __stdcall sub_0041A450_PickRequest(D2StormArchive0041A450Strc* pLastArchive, unsigned int nLastOffset, D2StormRequest0041A450Strc** ppDue, D2StormRequest0041A450Strc** ppNear, int* pnDistance)
{
    *ppDue = 0;
    *ppNear = 0;
    *pnDistance = 0x7FFFFFFF;
    unsigned int nBest = 0xFFFFFFFF;
    unsigned long nNow = GetTickCount();
    for (D2StormRequest0041A450Strc* p = (D2StormRequest0041A450Strc*)gRequestList_00708360.Head(); (int)p > 0; p = (D2StormRequest0041A450Strc*)p->f_0.m_next)
    {
        if (p->f_24)
        {
            if (p->f_0.Prev() && p->f_24 == ((D2StormRequest0041A450Strc*)p->f_0.Prev())->f_24)
                continue;
        }

        unsigned int nDistance = 0;
        if (gnValue_00708350 && !p->pStream)
        {
            D2StormArchive0041A450Strc* pArchive = p->pFile->f_114;
            unsigned int nSkip = 0;
            if (pArchive && nLastOffset > pArchive->nBaseOffset)
                nSkip = nLastOffset - pArchive->nBaseOffset;
            if (pArchive == pLastArchive)
            {
                if (p->nFileOffset < nSkip)
                    nDistance = p->nFileOffset + 0x8000000;
                else
                    nDistance = p->nFileOffset - nSkip;
            }
            else
            {
                nDistance = 0xFFFFFFFE;
            }
        }
        if (nDistance <= nBest)
        {
            nBest = nDistance;
            *ppDue = p;
        }

        int nTime = p->nDueTime - nNow;
        if (p->bClampDue && nTime >= 1000)
            nTime = 1000;
        if (nTime < *pnDistance)
        {
            *pnDistance = nTime;
            *ppNear = p;
        }
    }
}
