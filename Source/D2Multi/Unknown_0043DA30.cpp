#include "D2Multi.h"

struct SMSGHANDLER_PARAMS;
struct D2CompositeUnitStrc;

void __fastcall sub_00448BD0_UpdateScroll(int nDelta); // 0x00448BD0
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0
extern D2CellFileStrc* gpChatCellFile_0077BBFC; // 0x0077BBFC

// 0x0043DA30
int __stdcall sub_0043DA30_ScrollForward(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00448BD0_UpdateScroll(1);
    return 1;
}

// 0x0043DAD0
int __fastcall sub_0043DAD0_SetMainState(int bSet)
{
    sub_004F9740_SetControlState(gpControlMain_0077BC4C, bSet);
    return 1;
}

// 0x0043DCE0
void __cdecl sub_0043DCE0_FreeChatCellFile()
{
    if (gpChatCellFile_0077BBFC)
        D2Win_10142_CompUnitDestroy((D2CompositeUnitStrc*)gpChatCellFile_0077BBFC, 1);
    gpChatCellFile_0077BBFC = 0;
}
