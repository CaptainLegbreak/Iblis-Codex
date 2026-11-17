struct D2CellFileStrc;
struct D2CompositeUnitStrc;

int __stdcall sub_005041B0_Destroy(D2CompositeUnitStrc* pComposite, int nFlag);                             // 0x005041B0

extern D2CellFileStrc* gpChatCellFile_0077BBFC;                                                             // 0x0077BBFC

// 0x0043DCE0
void __cdecl sub_0043DCE0_FreeChatCellFile()
{
    if (gpChatCellFile_0077BBFC)
        sub_005041B0_Destroy((D2CompositeUnitStrc*)gpChatCellFile_0077BBFC, 1);
    gpChatCellFile_0077BBFC = 0;
}
