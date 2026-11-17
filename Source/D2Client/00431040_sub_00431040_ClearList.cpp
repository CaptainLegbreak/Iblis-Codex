struct D2WinControlStrc;
extern "C" const char gszEmptyAssertText;  // 0x006CC837
extern D2WinControlStrc* gpList_00779964;  // 0x00779964
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc*,const char*);
// 0x00431040
void __cdecl sub_00431040_ClearList() {
#ifdef MOVED_TEST
 sub_004FCF80_SetTextA(gpList_00779964,&gszEmptyAssertText+4);
#else
 sub_004FCF80_SetTextA(gpList_00779964,&gszEmptyAssertText);
#endif
}
