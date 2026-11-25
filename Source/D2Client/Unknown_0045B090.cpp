#include "TALLOCREC.h"

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// The memory report's list members (TSLink and TSList for TALLOCREC), in the order the object has them.
// build: symbol ?Next@?$TSLink@UTALLOCREC@@@@QAEPAUTALLOCREC@@XZ 0x0045B9D0
// build: symbol ?RawNext@?$TSLink@UTALLOCREC@@@@QAEPAUTALLOCREC@@XZ 0x0045B9E0
// build: symbol ?Unlink@?$TSLink@UTALLOCREC@@@@QAEXXZ 0x0045B9F0
// build: symbol ??1?$TSLink@UTALLOCREC@@@@QAE@XZ 0x0045BA30
// build: symbol ?Next@?$TSLinkedNode@UTALLOCREC@@@@QAEPAUTALLOCREC@@XZ 0x0045BAA0
// build: symbol ?InitializeTerminator@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXXZ 0x0045BA80
// build: symbol ?Head@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@XZ 0x0045BAB0
// build: symbol ??0?$TSLink@UTALLOCREC@@@@QAE@XZ 0x0045BAC0
// build: symbol ??0?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAE@XZ 0x0045BBC0
// build: symbol ?UnlinkAll@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXXZ 0x0045BD00
// build: symbol ??1?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAE@XZ 0x0045BD40
template TALLOCREC* TSLink<TALLOCREC>::Next();
template TALLOCREC* TSLink<TALLOCREC>::RawNext();
template void TSLink<TALLOCREC>::Unlink();
template TSLink<TALLOCREC>::~TSLink();
template TALLOCREC* TSLinkedNode<TALLOCREC>::Next();
template void TSList<TALLOCREC>::InitializeTerminator();
template TALLOCREC* TSList<TALLOCREC>::Head();
template TSLink<TALLOCREC>::TSLink();
template TSList<TALLOCREC>::TSList();
template TSList<TALLOCREC>::~TSList();
// build: symbol ?NextLink@?$TSLink@UTALLOCREC@@@@QAEPAU1@H@Z 0x0045B9A0
// build: symbol ?Link@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAU?$TSLink@UTALLOCREC@@@@PBUTALLOCREC@@@Z 0x0045BB30
// build: symbol ?Next@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@PBU2@@Z 0x0045BB50
// build: symbol ?UnlinkNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXPAUTALLOCREC@@@Z 0x0045BB70
// build: symbol ?LinkNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEXPAUTALLOCREC@@I0@Z 0x0045BBE0
// build: symbol ?RawNext@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@PBU2@@Z 0x0045BC90
// build: symbol ?NewNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@III@Z 0x0045BDD0
// build: symbol ??0?$TSLinkedNode@UTALLOCREC@@@@QAE@XZ 0x0045BCB0
// build: symbol ??1?$TSLinkedNode@UTALLOCREC@@@@QAE@XZ 0x0045BCC0
// build: symbol ??0TALLOCREC@@QAE@XZ 0x0045BD80
// build: symbol ??1TALLOCREC@@QAE@XZ 0x0045BD90
// build: symbol ??_GTALLOCREC@@QAEPAXI@Z 0x0045BE30
// build: symbol ?DeleteNode@?$TSList@UTALLOCREC@@U?$TSGetLink@UTALLOCREC@@@@@@QAEPAUTALLOCREC@@PAU2@@Z 0x0045BE90
// build: symbol ??_R0?AUTALLOCREC@@@8 0x00711478
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
template TSLink<TALLOCREC>* TSLink<TALLOCREC>::NextLink(int);
template TSLink<TALLOCREC>* TSList<TALLOCREC>::Link(const TALLOCREC*);
template TALLOCREC* TSList<TALLOCREC>::Next(const TALLOCREC*);
template void TSList<TALLOCREC>::UnlinkNode(TALLOCREC*);
template void TSList<TALLOCREC>::LinkNode(TALLOCREC*, unsigned int, TALLOCREC*);
template TALLOCREC* TSList<TALLOCREC>::RawNext(const TALLOCREC*);
template void TSList<TALLOCREC>::UnlinkAll();
template TALLOCREC* TSList<TALLOCREC>::NewNode(unsigned int, unsigned int, unsigned int);
template TALLOCREC* TSList<TALLOCREC>::DeleteNode(TALLOCREC*);

// Two of the object's members are still unplaced: a second unlink and a list reset. They are probably members of
// TSLink or TSList the template here doesn't have, so they keep their own names.
struct D2AllocRecLinkStrc
{
    TSLink<TALLOCREC>* m_prevlink;
    TALLOCREC* m_next;

    void sub_0045BAD0_Unlink();
};

struct D2AllocRecListResetStrc
{
    int m_linkoffset;
    TSLink<TALLOCREC> m_terminator;

    void sub_0045BB10_Initialize();
};

// 0x0045BAD0
void D2AllocRecLinkStrc::sub_0045BAD0_Unlink()
{
    ((TSLink<TALLOCREC>*)this)->Unlink();
}

// 0x0045BB10
void D2AllocRecListResetStrc::sub_0045BB10_Initialize()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (TALLOCREC*)~(unsigned int)&m_terminator;
}

