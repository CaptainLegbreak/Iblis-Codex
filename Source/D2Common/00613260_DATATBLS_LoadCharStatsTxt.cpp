struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_int[];                                                                    // 0x006E67EC
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void __fastcall sub_006117B0();                                                                 // 0x006117B0
extern D2TxtLinkStrc* gTxtLink_0096C7CC;                                                                    // 0x0096C7CC
extern D2TxtLinkStrc* gTxtLink_0096BC3C;                                                                    // 0x0096BC3C
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpCharstatsTxt;                                                                                // 0x0096C7F4
int gnCharstatsTxtRecordCount;                                                                              // 0x0096C7F8
void __fastcall sub_00612600(void* pTable, int nRecordCount, int nRecordSize, int nNameOffset, int a5, int nNameLength);// 0x00612600

// 0x00613260
void __stdcall DATATBLS_LoadCharStatsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "class", 1, 15, 32, 0 },
        { "str", 4, 0, 48, 0 },
        { "dex", 4, 0, 49, 0 },
        { "vit", 4, 0, 51, 0 },
        { gszTxtField_int, 4, 0, 50, 0 },
        { "stamina", 4, 0, 52, 0 },
        { "hpadd", 4, 0, 53, 0 },
        { "PercentStr", 4, 0, 54, 0 },
        { "PercentDex", 4, 0, 56, 0 },
        { "PercentVit", 4, 0, 57, 0 },
        { "PercentInt", 4, 0, 55, 0 },
        { "ManaRegen", 4, 0, 58, 0 },
        { "ToHitFactor", 2, 0, 60, 0 },
        { "WalkVelocity", 4, 0, 64, 0 },
        { "RunVelocity", 4, 0, 65, 0 },
        { "RunDrain", 4, 0, 66, 0 },
        { "LifePerLevel", 4, 0, 67, 0 },
        { "StaminaPerLevel", 4, 0, 68, 0 },
        { "ManaPerLevel", 4, 0, 69, 0 },
        { "LifePerVitality", 4, 0, 70, 0 },
        { "StaminaPerVitality", 4, 0, 71, 0 },
        { "ManaPerMagic", 4, 0, 72, 0 },
        { "BlockFactor", 4, 0, 73, 0 },
        { "basewclass", 9, 0, 76, 0 },
        { "StrAllSkills", 22, 0, 82, (void*)sub_006117B0 },
        { "StrSkillTab1", 22, 0, 84, (void*)sub_006117B0 },
        { "StrSkillTab2", 22, 0, 86, (void*)sub_006117B0 },
        { "StrSkillTab3", 22, 0, 88, (void*)sub_006117B0 },
        { "StrClassOnly", 22, 0, 90, (void*)sub_006117B0 },
        { "StartSkill", 20, 0, 172, &gTxtLink_0096C7CC },
        { "Skill 1", 20, 0, 174, &gTxtLink_0096C7CC },
        { "Skill 2", 20, 0, 176, &gTxtLink_0096C7CC },
        { "Skill 3", 20, 0, 178, &gTxtLink_0096C7CC },
        { "Skill 4", 20, 0, 180, &gTxtLink_0096C7CC },
        { "Skill 5", 20, 0, 182, &gTxtLink_0096C7CC },
        { "Skill 6", 20, 0, 184, &gTxtLink_0096C7CC },
        { "Skill 7", 20, 0, 186, &gTxtLink_0096C7CC },
        { "Skill 8", 20, 0, 188, &gTxtLink_0096C7CC },
        { "Skill 9", 20, 0, 190, &gTxtLink_0096C7CC },
        { "Skill 10", 20, 0, 192, &gTxtLink_0096C7CC },
        { "StatPerLevel", 4, 0, 80, 0 },
        { "item1loc", 13, 0, 96, &gTxtLink_0096BC3C },
        { "item2loc", 13, 0, 104, &gTxtLink_0096BC3C },
        { "item3loc", 13, 0, 112, &gTxtLink_0096BC3C },
        { "item4loc", 13, 0, 120, &gTxtLink_0096BC3C },
        { "item5loc", 13, 0, 128, &gTxtLink_0096BC3C },
        { "item6loc", 13, 0, 136, &gTxtLink_0096BC3C },
        { "item7loc", 13, 0, 144, &gTxtLink_0096BC3C },
        { "item8loc", 13, 0, 152, &gTxtLink_0096BC3C },
        { "item9loc", 13, 0, 160, &gTxtLink_0096BC3C },
        { "item10loc", 13, 0, 168, &gTxtLink_0096BC3C },
        { "item1", 9, 0, 92, 0 },
        { "item1count", 4, 0, 97, 0 },
        { "item2", 9, 0, 100, 0 },
        { "item2count", 4, 0, 105, 0 },
        { "item3", 9, 0, 108, 0 },
        { "item3count", 4, 0, 113, 0 },
        { "item4", 9, 0, 116, 0 },
        { "item4count", 4, 0, 121, 0 },
        { "item5", 9, 0, 124, 0 },
        { "item5count", 4, 0, 129, 0 },
        { "item6", 9, 0, 132, 0 },
        { "item6count", 4, 0, 137, 0 },
        { "item7", 9, 0, 140, 0 },
        { "item7count", 4, 0, 145, 0 },
        { "item8", 9, 0, 148, 0 },
        { "item8count", 4, 0, 153, 0 },
        { "item9", 9, 0, 156, 0 },
        { "item9count", 4, 0, 161, 0 },
        { "item10", 9, 0, 164, 0 },
        { "item10count", 4, 0, 169, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpCharstatsTxt = DATATBLS_CompileTxt(hArchive, "charstats", pTbl, &gnCharstatsTxtRecordCount, 196);
    sub_00612600(gpCharstatsTxt, gnCharstatsTxtRecordCount, 196, 32, 0, 16);
}
