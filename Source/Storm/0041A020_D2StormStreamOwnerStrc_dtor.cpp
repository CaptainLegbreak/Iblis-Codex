extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);      // 0x00412650

struct D2StormOwnerLinkStrc
{
    D2StormOwnerLinkStrc* m_prevlink;
    char* m_next;

// build: symbol ??1D2StormOwnerLinkStrc@@QAE@XZ 0x00418C20
    ~D2StormOwnerLinkStrc()
    {
        Unlink();
    }
    D2StormOwnerLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormOwnerLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormOwnerLinkStrc*)(m_next + nLinkOffset);
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

struct D2StormFileRecStrc
{
    char unk0x00[0x144];
    int nRefCount;
    char unk0x148[0x10];

    ~D2StormFileRecStrc();                                                                                  // 0x00419070
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormAudioStreamStrc
{
    char unk0x00[0x4C];
    int nRefCount;

    ~D2StormAudioStreamStrc();                                                                              // 0x004199A0
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormStreamOwnerStrc
{
    D2StormOwnerLinkStrc f_0;
    char unk0x08[0x4];
    D2StormFileRecStrc* pFileRec;
    char unk0x10[0x20];
    D2StormAudioStreamStrc* pStream;

    ~D2StormStreamOwnerStrc();
};

// 0x0041A020
D2StormStreamOwnerStrc::~D2StormStreamOwnerStrc()
{
    D2StormFileRecStrc* pFile = pFileRec;
    if (pFile && --pFile->nRefCount == 0)
        delete pFile;
    D2StormAudioStreamStrc* pAudio = pStream;
    if (pAudio && --pAudio->nRefCount == 0)
        delete pAudio;
}
