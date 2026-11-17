struct SMSGHANDLER_PARAMS;

void __fastcall sub_00448BD0_UpdateScroll(int nDelta); // 0x00448BD0

// 0x0043DA30
int __stdcall sub_0043DA30_ScrollForward(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00448BD0_UpdateScroll(1);
    return 1;
}
