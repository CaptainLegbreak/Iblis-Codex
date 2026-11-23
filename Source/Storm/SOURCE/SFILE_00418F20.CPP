#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2StormLink.h"

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

extern "C" const char gszStormFileRecTypeName[]; // 0x007083C0

inline void* operator new(unsigned int, void* pWhere) throw() { return pWhere; }

// build: context FILEREC::FILEREC
inline FILEREC::FILEREC()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
    pBuffer0x10C = 0;
    hFile = (void*)-1;
    archive = 0;
    pBuffer0x12C = 0;
    pBuffer0x138 = 0;
}

// 0x00418F20
char* D2StormFixedListStrc::sub_00418F20_NewNode(unsigned int nLinkType, unsigned int nExtraBytes, unsigned int nFlags)
{
    void* pMemory = SMemAlloc(sizeof(FILEREC) + nExtraBytes, gszStormFileRecTypeName, -2, nFlags | 8);
    FILEREC* pRecord = pMemory ? new (pMemory) FILEREC : 0;
    if (nLinkType)
        sub_00417B80_LinkNode((char*)pRecord, nLinkType, 0);
    return (char*)pRecord;
}
