#include "D2CMP.h"

#define D2_ASSERT(expr,line) if(!(expr)){sub_00408A60(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}

struct D2StormEntry38Strc;
struct D2ChatStormLinkStrc;
struct D2ChatStormLinkAStrc;
struct D2ChatStormLinkBStrc;
struct D2ChatStormNodeStrc;
struct D2ChatStormBaseArrayAStrc;
struct D2ChatStormBaseArrayBStrc;
struct D2ChatStormListAStrc;
struct D2ChatStormListBStrc;
struct D2ChatStormHashTableStrc;
struct D2ChatStormCtorLinkStrc;
struct D2ChatStormListCStrc;
struct D2ChatStormListDStrc;
struct D2ChatStormListEStrc;
struct D2CommonStormSlotLinkStrc;
struct D2CommonStormSlotListAStrc;
struct D2CommonStormSlotListBStrc;
struct D2CommonMappingEntryNodeBaseStrc;
struct D2CommonMappingEntryNodeStrc;
struct D2CommonStringEntryNodeStrc;
struct D2CommonStormHashTableAStrc;
struct D2StormSlotLinkStrc;
struct D2StormSlotListStrc;
struct D2StormSlotArrayStrc;
struct D2GameHashTableStrc;
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern "C" void* __cdecl memcpy(void*,const void*,unsigned); // 0x006829C0
extern const char gszCelCmp[]; // 0x006E5DD0
void* __fastcall FOG_Alloc(unsigned size,const char* file,int line,int zero); // 0x0040B380
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;
    char* m_next;
    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
    D2StormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormSlotLinkStrc()
    {
        Unlink();
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormSlotLinkStrc m_terminator;
    D2StormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
    }
    void UnlinkAll();                                                                                       // 0x00602640
    D2StormSlotListStrc(const D2StormSlotListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2StormSlotListStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
};

struct D2StormSlotArrayStrc
{
    unsigned int f_0;
    unsigned int f_4;
    D2StormSlotListStrc* f_8;
    unsigned int f_C;
    void sub_00603300_SetCount(unsigned int nCount);                                                        // 0x00603300
    void sub_00603850_SetCount(unsigned int nCount);
    void sub_00602F10_ReallocData(unsigned int nAlloc);
};

struct D2GameHashTableStrc
{
    D2StormSlotListStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    virtual void InternalDelete(D2StormEntry38Strc* pNode);                                                 // 0x006036D0
    virtual D2StormEntry38Strc* InternalNew(D2StormSlotListStrc* pList, unsigned int nExtraBytes, unsigned int nFlags); // 0x00603610
    virtual ~D2GameHashTableStrc();                                                                         // 0x00603460
    virtual void Destroy();                                                                                 // 0x00603780
    void sub_00602800_InternalClear(int bWarn);
};

void* __stdcall SMemAlloc(unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x00413020
void* __stdcall SMemReAlloc(void* pLocation, unsigned int nAmount, const char* szLogFileName, int nLogLine, unsigned int nFlags); // 0x004133D0

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw();

// 0x00600FB0
void __stdcall CelFileConvertOldToNew(unsigned* cell,unsigned** output,unsigned* outputSize)
{
 unsigned* pOldFile = cell;
 D2_ASSERT(pOldFile[1]&1,0x2cb);
 D2_ASSERT(pOldFile[0]==5,0x2cc);
 pOldFile[1]|=2;
 for(unsigned i=0;i<pOldFile[4]*(pOldFile[5]);++i) {
  unsigned* frame=(unsigned*)(pOldFile[13+i]+(unsigned)pOldFile);
  pOldFile[13+i]=(unsigned)frame;
  if(frame[7])frame[8]+=(unsigned)pOldFile;else frame[8]=0;
 }
 unsigned count=pOldFile[4]*pOldFile[5];
 unsigned header=24+4*count;
 unsigned size=header;
 for(unsigned i=0;i<count;++i) {
  unsigned* frame=(unsigned*)pOldFile[13+i];
  size+=frame[9]+frame[7]+35;
 }
 unsigned* result=(unsigned*)FOG_Alloc(size,gszCelCmp,0x2e3,0);
 result[0]=6;
 result[1]=((unsigned char)pOldFile[1]&4)|1;
 result[2]=0;result[3]=0;
 result[4]=pOldFile[4];result[5]=pOldFile[5];
 unsigned char* cursor=(unsigned char*)result+header;
 for(unsigned i=0;i<count;++i) {
  result[6+i]=(unsigned)(cursor-(unsigned char*)result);
  unsigned* out=(unsigned*)cursor;
  out[0]=((unsigned*)pOldFile[13+i])[1];
  out[1]=((unsigned*)pOldFile[13+i])[3];
  out[2]=((unsigned*)pOldFile[13+i])[4];
  out[3]=((unsigned*)pOldFile[13+i])[5];
  out[4]=((unsigned*)pOldFile[13+i])[6];
  out[5]=((unsigned*)pOldFile[13+i])[7];
  out[7]=((unsigned*)pOldFile[13+i])[9];
  memcpy(out+8,(unsigned*)pOldFile[13+i]+10,out[7]);
  cursor+=out[7]+35;
  if(((unsigned*)pOldFile[13+i])[8]) {
   memcpy(cursor,(unsigned*)pOldFile[13+i]+8,((unsigned*)pOldFile[13+i])[7]);
   out[6]=(unsigned)(cursor-(unsigned char*)result);
   cursor+=((unsigned*)pOldFile[13+i])[7];
  }else out[6]=0;
 }
 *output=result;*outputSize=size;
}

bool D2ChatStormLinkStrc::sub_0060E0C0_IsLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::sub_0060E0B0_GetKey()
{
    return f_14;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::sub_0060E230_Count()
{
    return f_4;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::sub_0060E250_Count()
{
    return f_4;
}

void D2ChatStormListAStrc::sub_0060E260_InitializeTerminator()
{
    InitializeTerminator();
}

// 0x006020C0
char* D2ChatStormListAStrc::sub_0060E440_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E270_InitializeTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::sub_0060E5D0_Head()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::sub_0060E610_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::sub_0060E6D0_Head()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::sub_0060EE30_Destroy()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::sub_0060ED60_Clear()
{
    sub_0060EB70_InternalClear(0);
}

// 0x00602800
void D2GameHashTableStrc::sub_00602800_InternalClear(int bWarn)
{
    m_fullnessIndicator = 0;
    m_fulllist.UnlinkAll();
    for (unsigned int i = 0; i < m_slotlistarray.f_4; ++i)
    {
        for (;;)
        {
            char* pNode = m_slotlistarray.f_8[i].Head();
            if (!pNode)
                break;
            if (bWarn)
                m_slotlistarray.f_8[i].sub_006C4290(pNode);
            else
                InternalDelete((D2StormEntry38Strc*)pNode);
        }
    }
}

// 0x00603850
void D2StormSlotArrayStrc::sub_00603850_SetCount(unsigned int nCount)
{
    sub_00603300_SetCount(nCount);
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00602BD0
void __fastcall sub_00602BD0(D2StormSlotListStrc* destination,const D2StormSlotListStrc* source)
{
    new(destination) D2StormSlotListStrc(*source);
}

// 0x00602F10
void D2StormSlotArrayStrc::sub_00602F10_ReallocData(unsigned int nAlloc)
{
    D2StormSlotListStrc* pOld = f_8;
    for (unsigned int i = nAlloc; i < f_4; i++)
        pOld[i].~D2StormSlotListStrc();
    f_0 = nAlloc;
    void* pNew = SMemReAlloc(pOld, nAlloc * sizeof(D2StormSlotListStrc), gszTypeNameCelSlotList, -2, 0x10);
    f_8 = (D2StormSlotListStrc*)pNew;
    if (!pNew)
    {
        f_8 = (D2StormSlotListStrc*)SMemAlloc(nAlloc * sizeof(D2StormSlotListStrc), gszTypeNameCelSlotList, -2, 0);
        if (pOld)
        {
            unsigned int nCopy = nAlloc >= f_4 ? f_4 : nAlloc;
            for (unsigned int i = 0; i < nCopy; i++)
            {
                new (&f_8[i]) D2StormSlotListStrc(pOld[i]);
                pOld[i].~D2StormSlotListStrc();
            }
            SMemFree(pOld, gszTypeNameCelSlotList, -2, 0);
        }
    }
}

#include "gen/data/Source/D2CMP/SRC/CelCmp_00600FB0.inc"

// 0x00603510
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x00603550
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}
