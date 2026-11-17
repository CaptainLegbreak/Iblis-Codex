struct D2TxtLinkStrc;

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker);                                                      // 0x006BD0B0

extern int DATATBLS_LoadFromBin;                                                                            // 0x00744308
extern void* gpPettypeTxt;                                                                                  // 0x0096C818
extern D2TxtLinkStrc* gpPettypeLinker;                                                                      // 0x0096C81C

static void DATATBLS_UnloadBinInline(void* pBinFile)
{
    if (pBinFile)
    {
        if (DATATBLS_LoadFromBin)
            FOG_FreePool(0, (char*)pBinFile - 4, ".\\DATATBLS\\DataTbls.cpp", 0x924, 0);
        else
            FOG_FreePool(0, pBinFile, ".\\DATATBLS\\DataTbls.cpp", 0x926, 0);
    }
}

// 0x00619100
void __fastcall sub_00619100_UnloadPetTypeTxt()
{
    DATATBLS_UnloadBinInline(gpPettypeTxt);
    FOG_FreeLinker(gpPettypeLinker);
}
