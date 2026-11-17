struct T0044CB60
{
    void* pText;
    T0044CB60* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x005028A0
void __fastcall sub_005028A0_FreeTextLines(T0044CB60* pLines)
{
    while (pLines)
    {
        T0044CB60* pNext = pLines->pNext;
        FOG_Free(pLines->pText, ".\\Src\\D2WinFont.cpp", 0x579, 0);
        FOG_Free(pLines, ".\\Src\\D2WinFont.cpp", 0x57A, 0);
        pLines = pNext;
    }
}
