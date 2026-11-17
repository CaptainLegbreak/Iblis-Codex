// build: ob1

struct T0051755C { T0051755C* pPrevLink; int pNext; };
// 0x006C40F0
T0051755C* __fastcall sub_006C40F0_ResetLink(T0051755C* pLink)
{
    pLink->pPrevLink = 0;
    pLink->pNext = 0;
    return pLink;
}
