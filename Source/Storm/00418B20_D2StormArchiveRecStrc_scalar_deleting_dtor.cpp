int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

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

struct D2StormArchiveRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x254];

    ~D2StormArchiveRecStrc();                                                                               // 0x00418A50
    static void operator delete(void* pMemory);
};

struct D2StormFileRecStrc
{
    D2StormLinkStrc f_0;
    char unk0x08[0x150];

    ~D2StormFileRecStrc();                                                                                  // 0x00419070
    static void operator delete(void* pMemory);
};

struct D2StormRecord419000Strc
{
    D2StormLinkStrc f_0;

    ~D2StormRecord419000Strc();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

// build: symbol ??_GD2StormArchiveRecStrc@@QAEPAXI@Z 0x00418B20
// build: symbol ??_GD2StormFileRecStrc@@QAEPAXI@Z 0x00419150
// 0x00418B20
inline void D2StormArchiveRecStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// build: symbol ??_GD2StormRecord419000Strc@@QAEPAXI@Z 0x00419000
inline D2StormRecord419000Strc::~D2StormRecord419000Strc()
{
    f_0.Unlink();
}

// 0x00419150
inline void D2StormFileRecStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void sub_F21_EmitScalarDeletingDestructors(D2StormArchiveRecStrc* pArchive, D2StormFileRecStrc* pFile, D2StormRecord419000Strc* pRecord)
{
    delete pArchive;
    delete pFile;
    delete pRecord;
}
