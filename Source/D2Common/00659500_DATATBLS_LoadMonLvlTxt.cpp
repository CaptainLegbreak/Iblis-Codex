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
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpMonlvlTxt;                                                                                   // 0x0096C7A0
extern int gnMonlvlTxtRecordCount;                                                                          // 0x0096C7A4

// 0x00659500
void __fastcall DATATBLS_LoadMonLvlTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "AC", 2, 0, 0, 0 },
        { "AC(N)", 2, 0, 4, 0 },
        { "AC(H)", 2, 0, 8, 0 },
        { "TH", 2, 0, 24, 0 },
        { "TH(N)", 2, 0, 28, 0 },
        { "TH(H)", 2, 0, 32, 0 },
        { "HP", 2, 0, 48, 0 },
        { "HP(N)", 2, 0, 52, 0 },
        { "HP(H)", 2, 0, 56, 0 },
        { "DM", 2, 0, 72, 0 },
        { "DM(N)", 2, 0, 76, 0 },
        { "DM(H)", 2, 0, 80, 0 },
        { "XP", 2, 0, 96, 0 },
        { "XP(N)", 2, 0, 100, 0 },
        { "XP(H)", 2, 0, 104, 0 },
        { "L-AC", 2, 0, 12, 0 },
        { "L-AC(N)", 2, 0, 16, 0 },
        { "L-AC(H)", 2, 0, 20, 0 },
        { "L-TH", 2, 0, 36, 0 },
        { "L-TH(N)", 2, 0, 40, 0 },
        { "L-TH(H)", 2, 0, 44, 0 },
        { "L-HP", 2, 0, 60, 0 },
        { "L-HP(N)", 2, 0, 64, 0 },
        { "L-HP(H)", 2, 0, 68, 0 },
        { "L-DM", 2, 0, 84, 0 },
        { "L-DM(N)", 2, 0, 88, 0 },
        { "L-DM(H)", 2, 0, 92, 0 },
        { "L-XP", 2, 0, 108, 0 },
        { "L-XP(N)", 2, 0, 112, 0 },
        { "L-XP(H)", 2, 0, 116, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpMonlvlTxt = DATATBLS_CompileTxt(hArchive, "monlvl", pTbl, &gnMonlvlTxtRecordCount, 120);
}
