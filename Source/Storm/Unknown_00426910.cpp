#include "Storm.h"
#include "D2StormAutoLink.h"

struct D2GameStrc;
struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2GameLinkStrc;
struct D2StormGameArrayStrc;
struct D2StormHashObjectChunkStrc;
struct D2GameListStrc;
struct D2StormChunkListStrc;

extern unsigned short gwValue_0077905C;

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
extern char gszTypeNameBreakCmd_007088D8[]; // 0x007088D8
extern "C" const char gszSGameDataTypeName[]; // 0x0070F56C
extern char gszTypeNameHashObjectChunk_0070F5F4[]; // 0x0070F5F4

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink;
    D2GameStrc* pNext;

    D2GameLinkStrc()
    {
        pPrevLink = 0;
        pNext = 0;
    }
};

struct D2GameStrc
{
    unsigned int dwHashValue;
    D2GameLinkStrc tLinkToSlot;
    D2GameLinkStrc tLinkToFull;
    char unk0x14[0x1DE0];
};

struct D2StormGameArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2GameStrc* m_data;
    unsigned int m_chunk;

    D2StormGameArrayStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
};

struct D2StormHashObjectChunkStrc
{
    D2StormGameArrayStrc m_array;
    D2StormLinkStrc f_10;
};

struct D2GameListStrc
{
    int m_linkoffset;
    D2GameLinkStrc m_terminator;

    void sub_004502A0_LinkNode(D2GameStrc* pNode, unsigned int nLinkType, D2GameStrc* pExisting);          // 0x004502A0
    D2GameStrc* sub_00450390_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

struct D2StormChunkListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_004508A0_LinkNode(D2StormHashObjectChunkStrc* pNode, unsigned int nLinkType, D2StormHashObjectChunkStrc* pExisting); // 0x004508A0
    D2StormHashObjectChunkStrc* sub_00450FA0_NewNode(unsigned int nLocation, unsigned int nExtraBytes, unsigned int nFlags);
};

inline void* operator new(unsigned int nSize, void* pWhere) throw();

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

#include "gen/data/Source/Storm/Unknown_00426910.inc"
