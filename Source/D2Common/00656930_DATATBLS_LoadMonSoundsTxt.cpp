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
D2TxtLinkStrc* gTxtLink_0096C6B8;                                                                           // 0x0096C6B8
extern D2TxtLinkStrc* gTxtLink_0096BDC8;                                                                    // 0x0096BDC8
extern D2TxtLinkStrc* gTxtLink_0096BC5C;                                                                    // 0x0096BC5C
extern D2TxtLinkStrc* gTxtLink_0096C7CC;                                                                    // 0x0096C7CC
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpMonsoundsTxt;                                                                                // 0x0096C6B4
extern int gnMonsoundsTxtRecordCount;                                                                       // 0x0096C6BC
D2TxtLinkStrc* __stdcall FOG_AllocLinker(const char* szFile, int nLine);                                    // 0x006BD040
extern D2TxtLinkStrc* gpMonsoundsLinker;                                                                    // 0x0096C6B8

// 0x00656930
void __fastcall DATATBLS_LoadMonSoundsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 17, 0, 0, &gTxtLink_0096C6B8 },
        { "Attack1", 19, 0, 4, &gTxtLink_0096BDC8 },
        { "Att1Del", 2, 0, 8, 0 },
        { "Att1Prb", 2, 0, 12, 0 },
        { "Attack2", 19, 0, 28, &gTxtLink_0096BDC8 },
        { "Att2Del", 2, 0, 32, 0 },
        { "Att2Prb", 2, 0, 36, 0 },
        { "Weapon1", 19, 0, 16, &gTxtLink_0096BDC8 },
        { "Wea1Del", 2, 0, 20, 0 },
        { "Wea1Vol", 2, 0, 24, 0 },
        { "Weapon2", 19, 0, 40, &gTxtLink_0096BDC8 },
        { "Wea2Del", 2, 0, 44, 0 },
        { "Wea2Vol", 2, 0, 48, 0 },
        { "HitSound", 19, 0, 52, &gTxtLink_0096BDC8 },
        { "HitDelay", 2, 0, 56, 0 },
        { "DeathSound", 19, 0, 60, &gTxtLink_0096BDC8 },
        { "DeaDelay", 2, 0, 64, 0 },
        { "Skill1", 19, 0, 68, &gTxtLink_0096BDC8 },
        { "Skill2", 19, 0, 72, &gTxtLink_0096BDC8 },
        { "Skill3", 19, 0, 76, &gTxtLink_0096BDC8 },
        { "Skill4", 19, 0, 80, &gTxtLink_0096BDC8 },
        { "Footstep", 19, 0, 84, &gTxtLink_0096BDC8 },
        { "FootstepLayer", 19, 0, 88, &gTxtLink_0096BDC8 },
        { "FsCnt", 2, 0, 92, 0 },
        { "FsOff", 2, 0, 96, 0 },
        { "FsPrb", 2, 0, 100, 0 },
        { "Neutral", 19, 0, 104, &gTxtLink_0096BDC8 },
        { "NeuTime", 2, 0, 108, 0 },
        { "Init", 19, 0, 112, &gTxtLink_0096BDC8 },
        { "Taunt", 19, 0, 116, &gTxtLink_0096BDC8 },
        { "Flee", 19, 0, 120, &gTxtLink_0096BDC8 },
        { "CvtMo1", 13, 0, 124, &gTxtLink_0096BC5C },
        { "CvtMo2", 13, 0, 132, &gTxtLink_0096BC5C },
        { "CvtMo3", 13, 0, 140, &gTxtLink_0096BC5C },
        { "CvtSk1", 19, 0, 128, &gTxtLink_0096C7CC },
        { "CvtSk2", 19, 0, 136, &gTxtLink_0096C7CC },
        { "CvtSk3", 19, 0, 144, &gTxtLink_0096C7CC },
        { "CvtTgt1", 13, 0, 125, &gTxtLink_0096BC5C },
        { "CvtTgt2", 13, 0, 133, &gTxtLink_0096BC5C },
        { "CvtTgt3", 13, 0, 141, &gTxtLink_0096BC5C },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gTxtLink_0096C6B8 = FOG_AllocLinker(".\\DATATBLS\\MonsterTbls.cpp", 2415);
    gpMonsoundsTxt = DATATBLS_CompileTxt(hArchive, "monsounds", pTbl, &gnMonsoundsTxtRecordCount, 148);
}
