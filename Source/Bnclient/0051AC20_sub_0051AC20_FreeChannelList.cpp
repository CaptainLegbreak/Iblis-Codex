int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern int gnChannelList_008818C8;                                                                          // 0x008818C8

// 0x0051AC20
void __cdecl sub_0051AC20_FreeChannelList()
{
    if (gnChannelList_008818C8)
    {
        FOG_Free((void*)gnChannelList_008818C8, ".\\BnSend.cpp", 0x1EF, 0);
    }
    gnChannelList_008818C8 = 0;
}
