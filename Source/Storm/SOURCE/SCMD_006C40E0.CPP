// build: ob1

struct T0051755C { T0051755C* pPrevLink; int pNext; };
struct T0051755C_1 { int nLinkOffset; T0051755C head; };
// 0x006C40E0
int __fastcall sub_006C40E0_Head(T0051755C_1* pList)
{
    return pList->head.pNext <= 0 ? 0 : pList->head.pNext;
}
