struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern D2TxtLinkStrc* gTxtLink_0096BDC8;                                                                    // 0x0096BDC8
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
void* gpSoundsTxt;                                                                                          // 0x0096BDC4
int gnSoundsTxtRecordCount;                                                                                 // 0x0096BDCC
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
extern D2TxtLinkStrc* gpSoundsLinker;                                                                       // 0x0096BDC8
extern int gnSoundsGuard;                                                                                   // 0x0096C8B4

// 0x00659BB0
void __fastcall DATATBLS_LoadSoundsTxt(void* hArchive)
{
    if (gnSoundsGuard)
    {
        D2BinFieldStrc pTbl[] =
        {
            { "Sound", 17, 0, 0, &gTxtLink_0096BDC8 },
            { gszTxtField_end, 0, 0, 0, 0 },
        };

        gTxtLink_0096BDC8 = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 3225);
        gpSoundsTxt = DATATBLS_CompileTxt(hArchive, "sounds", pTbl, &gnSoundsTxtRecordCount, 2);
    }
}
