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
D2TxtLinkStrc* gTxtLink_0096C85C;                                                                           // 0x0096C85C
extern D2TxtLinkStrc* gTxtLink_0096BCD8;                                                                    // 0x0096BCD8
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpMonpropTxt;                                                                                  // 0x0096C860
extern int gnMonpropTxtRecordCount;                                                                         // 0x0096C864
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
extern D2TxtLinkStrc* gpMonpropLinker;                                                                      // 0x0096C85C

// 0x00658720
void __fastcall DATATBLS_LoadMonPropTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 18, 0, 0, &gTxtLink_0096C85C },
        { "prop1", 19, 0, 4, &gTxtLink_0096BCD8 },
        { "par1", 2, 0, 8, 0 },
        { "chance1", 4, 0, 292, 0 },
        { "min1", 2, 0, 12, 0 },
        { "max1", 2, 0, 16, 0 },
        { "prop2", 19, 0, 20, &gTxtLink_0096BCD8 },
        { "chance2", 4, 0, 293, 0 },
        { "par2", 2, 0, 24, 0 },
        { "min2", 2, 0, 28, 0 },
        { "max2", 2, 0, 32, 0 },
        { "prop3", 19, 0, 36, &gTxtLink_0096BCD8 },
        { "chance3", 4, 0, 294, 0 },
        { "par3", 2, 0, 40, 0 },
        { "min3", 2, 0, 44, 0 },
        { "max3", 2, 0, 48, 0 },
        { "prop4", 19, 0, 52, &gTxtLink_0096BCD8 },
        { "chance4", 4, 0, 295, 0 },
        { "par4", 2, 0, 56, 0 },
        { "min4", 2, 0, 60, 0 },
        { "max4", 2, 0, 64, 0 },
        { "prop5", 19, 0, 68, &gTxtLink_0096BCD8 },
        { "chance5", 4, 0, 296, 0 },
        { "par5", 2, 0, 72, 0 },
        { "min5", 2, 0, 76, 0 },
        { "max5", 2, 0, 80, 0 },
        { "prop6", 19, 0, 84, &gTxtLink_0096BCD8 },
        { "chance6", 4, 0, 297, 0 },
        { "par6", 2, 0, 88, 0 },
        { "min6", 2, 0, 92, 0 },
        { "max6", 2, 0, 96, 0 },
        { "prop1 (N)", 19, 0, 100, &gTxtLink_0096BCD8 },
        { "chance1 (N)", 4, 0, 298, 0 },
        { "par1 (N)", 2, 0, 104, 0 },
        { "min1 (N)", 2, 0, 108, 0 },
        { "max1 (N)", 2, 0, 112, 0 },
        { "prop2 (N)", 19, 0, 116, &gTxtLink_0096BCD8 },
        { "chance2 (N)", 4, 0, 299, 0 },
        { "par2 (N)", 2, 0, 120, 0 },
        { "min2 (N)", 2, 0, 124, 0 },
        { "max2 (N)", 2, 0, 128, 0 },
        { "prop3 (N)", 19, 0, 132, &gTxtLink_0096BCD8 },
        { "chance3 (N)", 4, 0, 300, 0 },
        { "par3 (N)", 2, 0, 136, 0 },
        { "min3 (N)", 2, 0, 140, 0 },
        { "max3 (N)", 2, 0, 144, 0 },
        { "prop4 (N)", 19, 0, 148, &gTxtLink_0096BCD8 },
        { "chance4 (N)", 4, 0, 301, 0 },
        { "par4 (N)", 2, 0, 152, 0 },
        { "min4 (N)", 2, 0, 156, 0 },
        { "max4 (N)", 2, 0, 160, 0 },
        { "prop5 (N)", 19, 0, 164, &gTxtLink_0096BCD8 },
        { "chance5 (N)", 4, 0, 302, 0 },
        { "par5 (N)", 2, 0, 168, 0 },
        { "min5 (N)", 2, 0, 172, 0 },
        { "max5 (N)", 2, 0, 176, 0 },
        { "prop6 (N)", 19, 0, 180, &gTxtLink_0096BCD8 },
        { "chance6 (N)", 4, 0, 303, 0 },
        { "par6 (N)", 2, 0, 184, 0 },
        { "min6 (N)", 2, 0, 188, 0 },
        { "max6 (N)", 2, 0, 192, 0 },
        { "prop1 (H)", 19, 0, 196, &gTxtLink_0096BCD8 },
        { "chance1 (H)", 4, 0, 304, 0 },
        { "par1 (H)", 2, 0, 200, 0 },
        { "min1 (H)", 2, 0, 204, 0 },
        { "max1 (H)", 2, 0, 208, 0 },
        { "prop2 (H)", 19, 0, 212, &gTxtLink_0096BCD8 },
        { "chance2 (H)", 4, 0, 305, 0 },
        { "par2 (H)", 2, 0, 216, 0 },
        { "min2 (H)", 2, 0, 220, 0 },
        { "max2 (H)", 2, 0, 224, 0 },
        { "prop3 (H)", 19, 0, 228, &gTxtLink_0096BCD8 },
        { "chance3 (H)", 4, 0, 306, 0 },
        { "par3 (H)", 2, 0, 232, 0 },
        { "min3 (H)", 2, 0, 236, 0 },
        { "max3 (H)", 2, 0, 240, 0 },
        { "prop4 (H)", 19, 0, 244, &gTxtLink_0096BCD8 },
        { "chance4 (H)", 4, 0, 307, 0 },
        { "par4 (H)", 2, 0, 248, 0 },
        { "min4 (H)", 2, 0, 252, 0 },
        { "max4 (H)", 2, 0, 256, 0 },
        { "prop5 (H)", 19, 0, 260, &gTxtLink_0096BCD8 },
        { "chance5 (H)", 4, 0, 308, 0 },
        { "par5 (H)", 2, 0, 264, 0 },
        { "min5 (H)", 2, 0, 268, 0 },
        { "max5 (H)", 2, 0, 272, 0 },
        { "prop6 (H)", 19, 0, 276, &gTxtLink_0096BCD8 },
        { "chance6 (H)", 4, 0, 309, 0 },
        { "par6 (H)", 2, 0, 280, 0 },
        { "min6 (H)", 2, 0, 284, 0 },
        { "max6 (H)", 2, 0, 288, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C85C = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2953);
    gpMonpropTxt = DATATBLS_CompileTxt(hArchive, "monprop", pTbl, &gnMonpropTxtRecordCount, 312);
}
