#include "D2Multi.h"

struct SMSGHANDLER_PARAMS;
struct D2CompositeUnitStrc;

void __fastcall CHATDLG_UpdateScroll(int nDelta); // 0x00448BD0
extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C
void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0
extern D2CelFileStrc* gpChatCellFile; // 0x0077BBFC

// 0x0043DCE0
void __cdecl sub_0043DCE0_FreeChatCellFile()
{
    if (gpChatCellFile)
        D2Win_10142_CompUnitDestroy((D2CompositeUnitStrc*)gpChatCellFile, 1);
    gpChatCellFile = 0;
}
