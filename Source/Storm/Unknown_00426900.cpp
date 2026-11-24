#include "Storm.h"
#include "D2GameTypes.h"

struct SEvtBreakCmdStrc;
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
struct D2CriticalSectionStrc;
struct SEvtLinkStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);
extern "C" const char gszIgnoreListSourceFile_006E6290[];

struct SEvtLinkStrc
{
    SEvtLinkStrc* pPrevLink;
    SEvtBreakCmdStrc* pNext;

    SEvtLinkStrc() { pPrevLink = 0; pNext = 0; }
    SEvtLinkStrc* NextLink(int nLinkOffset = -1)
    {
        if ((int)pNext < 0)
            return (SEvtLinkStrc*)~(unsigned int)pNext;
        if (nLinkOffset < 0)
            nLinkOffset = (int)this - (int)pPrevLink->pNext;
        return (SEvtLinkStrc*)((int)pNext + nLinkOffset);
    }
    void Unlink()
    {
        if (pPrevLink)
        {
            NextLink()->pPrevLink = pPrevLink;
            pPrevLink->pNext = pNext;
            pPrevLink = 0;
            pNext = 0;
        }
    }
};

struct SEvtBreakCmdStrc
{
    SEvtLinkStrc f_0;
    void* pData;
};

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
void* __stdcall SMemAlloc(unsigned int nSize, const char* szLogName, int nLogLine, unsigned int nFlags); // 0x00413020
extern "C" const char gszBREAKCMDTypeName[]; // 0x007088D8
extern D2CriticalSectionStrc gtSEvtLock; // 0x0077930C

inline void* __cdecl operator new(unsigned int nSize, void* pWhere);

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) { return pWhere; }

#include "gen/data/Source/Storm/Unknown_00426900.inc"

// 0x00515110
void __cdecl sub_00515110_Nop()
{
}

// 0x00515EC0
void __cdecl sub_00515EC0_Nop()
{
}

// 0x00515ED0
void __cdecl sub_00515ED0_Nop()
{
}

// 0x0043CBF0
void __cdecl sub_0043CBF0_Nop()
{
}

// 0x0042B9D0
void __cdecl sub_0042B9D0_Nop()
{
}

// 0x00650EA0
void __cdecl sub_00650EA0_Nop()
{
}

