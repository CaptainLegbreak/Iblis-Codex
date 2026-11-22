#include "D2Win.h"
#include "D2Unicode.h"

struct D2WinListStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20
void __fastcall D2Win_10137(D2WinListStrc* pList, const Unicode* wszText, D2WinMsgHandler a3, char a4, int a5, int a6, int a7); // 0x00506EC0

// 0x005077F0
void __fastcall D2Win_10138(D2WinListStrc* pList, const char* szText, D2WinMsgHandler a3, char a4, int a5, int a6, int a7)
{
    Unicode wszText[256];
    for (int i = 0; i < 256; i++)
        wszText[i].wChar = 0;
    sub_00526F20_ToUnicode(wszText, szText, 256);
    D2Win_10137(pList, wszText, a3, a4, a5, a6, a7);
}
