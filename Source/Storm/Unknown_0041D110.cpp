#include "D2StormLink.h"

struct D2StormHandlerNodeStrc
{
    D2StormLinkStrc f_0;
    int nValue;
};

struct D2StormFixedListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        char* pHead = m_terminator.Next();
        return pHead;
    }
    char* sub_0041CA10_DeleteNode(char* pNode);                                                             // 0x0041CA10
};

void __cdecl sub_0041C1A0_LockErrorState();                                                                 // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState();                                                               // 0x0041C1E0
extern D2StormFixedListStrc gHandlerList_00708420;                                                          // 0x00708420

// 0x0041D110
void __stdcall sub_0041D110_RemoveHandlers(int nValue)
{
    sub_0041C1A0_LockErrorState();
    char* pNode = gHandlerList_00708420.Head();
    while ((int)pNode > 0)
    {
        if (((D2StormHandlerNodeStrc*)pNode)->nValue == nValue)
            pNode = gHandlerList_00708420.sub_0041CA10_DeleteNode(pNode);
        else
            pNode = ((D2StormLinkStrc*)pNode)->m_next;
    }
    sub_0041C1E0_UnlockErrorState();
}
