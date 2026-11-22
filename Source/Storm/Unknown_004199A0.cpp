#include "Storm.h"

struct D2StormStreamLinkStrc;
struct FILEREC;
struct D2StormSoundBufferStrc;
struct AUDIOSTREAM;
struct D2StormUIntArrayStrc;
struct D2StormUCharArrayStrc;
struct D2StormBigBufferStrc;
struct D2StormBigDataStrc;
struct D2StormOwnerLinkStrc;
struct REQUEST;

extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2StormStreamLinkStrc
{
    D2StormStreamLinkStrc* m_prevlink;
    char* m_next;

// build: symbol ??1D2StormStreamLinkStrc@@QAE@XZ 0x00418BE0
    ~D2StormStreamLinkStrc()
    {
        Unlink();
    }
    D2StormStreamLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormStreamLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormStreamLinkStrc*)(m_next + nLinkOffset);
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

struct FILEREC
{
    char unk0x00[0x144];
    int nRefCount;
    char unk0x148[0x10];

    ~FILEREC();                                                                                  // 0x00419070
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormSoundBufferStrc
{
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct AUDIOSTREAM
{
    D2StormStreamLinkStrc f_0;
    FILEREC* pFileRec;
    char unk0x0C[0x30];
    D2StormSoundBufferStrc* pBuffer;
    int nUnk0x40;
    int bBufferOwned;
    int nUnk0x48;
    int nRefCount;
    ~AUDIOSTREAM();
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
};

struct D2StormUIntArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned int* f_8;
    unsigned int f_C;

    ~D2StormUIntArrayStrc()
    {
        if (f_8)
            SMemFree(f_8, gszTypeNameUInt_00708874, -2, 0);
    }
};

struct D2StormUCharArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char* f_8;
    unsigned int f_C;

    ~D2StormUCharArrayStrc()
    {
        if (f_8)
            SMemFree(f_8, gszTypeNameUChar_00708880, -2, 0);
    }
};

struct D2StormBigBufferStrc
{
    D2StormUIntArrayStrc m_array;
    unsigned int m_offset;
};

struct D2StormBigDataStrc
{
    D2StormBigBufferStrc m_primary;
    D2StormBigBufferStrc m_stack[16];
    unsigned int m_used;
    D2StormUCharArrayStrc m_output;

    ~D2StormBigDataStrc();
};

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

struct REQUEST
{
    D2StormOwnerLinkStrc f_0;
    char unk0x08[0x4];
    FILEREC* pFileRec;
    char unk0x10[0x20];
    AUDIOSTREAM* pStream;

    ~REQUEST();
};

// build: symbol ??1D2StormBigBufferStrc@@QAE@XZ 0x00421810
// 0x004199A0
AUDIOSTREAM::~AUDIOSTREAM()
{
    FILEREC* pFile = pFileRec;
    if (pFile && --pFile->nRefCount == 0)
        delete pFile;
    if (pBuffer && bBufferOwned)
        pBuffer->Release();
}

// 0x00421D80
D2StormBigDataStrc::~D2StormBigDataStrc()
{
}

// 0x0041A020
REQUEST::~REQUEST()
{
    FILEREC* pFile = pFileRec;
    if (pFile && --pFile->nRefCount == 0)
        delete pFile;
    AUDIOSTREAM* pAudio = pStream;
    if (pAudio && --pAudio->nRefCount == 0)
        delete pAudio;
}
