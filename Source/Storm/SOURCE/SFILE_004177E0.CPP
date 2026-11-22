#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2StormLink.h"

#define STORM_DELETEOP static void operator delete(void* pMemory) { if (pMemory) SMemFree(pMemory, "delete", -1, 0); }

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
struct Node;
struct List;
struct REQUEST;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern "C" const char gszIgnoreListSourceFile_006E6290[];

void* __stdcall sub_00413020(unsigned,const char*,int,unsigned); // 0x00413020
extern "C" const char eventName[]; // 0x007083D8

struct Node { Node* previous; char* next; int payload; Node() { previous=0; next=0; } };

struct List {
    void sub_00417C70(char*,unsigned,char*);
    Node* sub_00418F90(unsigned,unsigned,unsigned);
};

enum { ALLOC_FLAG = 8 };

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);
void __stdcall SErrReportResourceLeak(const char* szName); // 0x0041D1E0
void __stdcall SErrReportNamedResourceLeak(const char* szName, const char* szDetail); // 0x0041D010
void __cdecl sub_00419F30();

extern D2StormListStrc gRequestList_00708360; // 0x00708360
extern D2StormListStrc gDdaList_00708384; // 0x00708384
extern D2StormListStrc gFileList_0070836C; // 0x0070836C
extern D2StormListStrc gArchiveList_00708354; // 0x00708354

inline void* __cdecl operator new(unsigned int size,void* where) throw();

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

// 0x004177E0
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

// 0x00417B40
void D2StormListBaseStrc::sub_00417B40_Initialize() {
 m_linkoffset=0;
 m_terminator.m_prevlink=&m_terminator;
 m_terminator.m_next=(char*)~(unsigned int)&m_terminator;
}

// 0x00417C30
void D2ChatStormListAStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x004186B0
D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

inline void* __cdecl operator new(unsigned int size,void* where) throw() { return where; }

// build: symbol ?sub_00417C70@List@@QAEXPADI0@Z 0x00417C70
// 0x00418F90
Node* List::sub_00418F90(unsigned linkType,unsigned extra,unsigned flags)
{
    void* memory=sub_00413020(sizeof(Node)+extra,eventName,-2,flags|ALLOC_FLAG);
    Node* node=new(memory) Node;
    if(linkType) sub_00417C70((char*)node,linkType,0);
    return node;
}

#include "gen/data/Source/Storm/SOURCE/SFILE_004177E0.inc"

void* ghStormThread_00779034; // 0x00779034

void* ghStormEvent_00779054; // 0x00779054

int gbThreadStop_00778F24; // 0x00778F24

REQUEST* gpCurrentRequest_0077902C; // 0x0077902C

unsigned int* gpCryptTable_00779048; // 0x00779048

char* gpStormExplodeWork; // 0x0077903C

unsigned char* gpStreamBuffer_00779050; // 0x00779050

inline void REQUEST::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

inline void AUDIOSTREAM::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// build: symbol ??1ARCHIVEREC@@QAE@XZ 0x00418A50
// build: symbol ??1AUDIOSTREAM@@QAE@XZ 0x004199A0
// build: symbol ??1FILEREC@@QAE@XZ 0x00419070
// build: symbol ??1REQUEST@@QAE@XZ 0x0041A020
// 0x0041A110
int __cdecl SFileDestroy()
{
    sub_00419F30();
    if (ghStormThread_00779034)
    {
        gbThreadStop_00778F24 = 1;
        SetEvent(ghStormEvent_00779054);
        WaitForSingleObject(ghStormThread_00779034, 1000);
        if (ghStormEvent_00779054)
        {
            CloseHandle(ghStormEvent_00779054);
            ghStormEvent_00779054 = 0;
        }
        if (ghStormThread_00779034)
        {
            CloseHandle(ghStormThread_00779034);
            ghStormThread_00779034 = 0;
        }
    }
    if (gpCurrentRequest_0077902C)
    {
        delete gpCurrentRequest_0077902C;
        gpCurrentRequest_0077902C = 0;
    }
    while (gRequestList_00708360.Head())
        delete (REQUEST*)gRequestList_00708360.Head();
    while (AUDIOSTREAM* pStream = (AUDIOSTREAM*)gDdaList_00708384.Head())
    {
        SErrReportResourceLeak("AUDIOSTREAM");
        delete pStream;
    }
    while (FILEREC* pFile = (FILEREC*)gFileList_0070836C.Head())
    {
        SErrReportNamedResourceLeak("HSFILE", pFile->szName);
        delete pFile;
    }
    while (ARCHIVEREC* pArchive = (ARCHIVEREC*)gArchiveList_00708354.Head())
    {
        SErrReportNamedResourceLeak("HSARCHIVE", pArchive->szName);
        delete pArchive;
    }
    if (gpCryptTable_00779048)
    {
        SMemFree(gpCryptTable_00779048, ".\\SOURCE\\SFILE.CPP", 0xE24, 0);
        gpCryptTable_00779048 = 0;
    }
    if (gpStormExplodeWork)
    {
        SMemFree(gpStormExplodeWork, ".\\SOURCE\\SFILE.CPP", 0xE2A, 0);
        gpStormExplodeWork = 0;
    }
    if (gpStreamBuffer_00779050)
    {
        SMemFree(gpStreamBuffer_00779050, ".\\SOURCE\\SFILE.CPP", 0xE30, 0);
        gpStreamBuffer_00779050 = 0;
    }
    return 1;
}
