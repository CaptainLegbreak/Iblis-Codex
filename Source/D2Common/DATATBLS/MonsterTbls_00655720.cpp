#include "D2Records.h"
#ifdef MOVED_TEST
#define FIELD_TEXT(x) ((x)+1)
#define FIXTURE_LINE(x) ((x)+2)
#else
#define FIELD_TEXT(x) (x)
#define FIXTURE_LINE(x) (x)
#endif

struct D2HirelingTxt
{
    unsigned short wVersion;
    unsigned short pad0x02;
    int nId;
    int dwClass;
    int dwAct;
    int dwDifficulty;
    int dwSeller;
    char unk0x018[0xD3 - 0x018];
    char szNameFirst[32];
    char szNameLast[32];
    char pad113;
#ifdef MOVED_TEST
    char moved_padding[4];
#endif
    unsigned short wNameFirst;
    unsigned short wNameLast;
};

struct D2TxtLinkStrc;
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
unsigned short __stdcall sub_00524D30_FindString(const char* szKey, const wchar_t** ppText);               // 0x00524D30
D2TxtLinkStrc* gpHireDescLinker_0096BCE8;                                                                   // 0x0096BCE8
extern D2TxtLinkStrc* gpSkillsLinker_0096C7CC;                                                              // 0x0096C7CC
int __cdecl sub_00408F20_HasExpansionMpq();
extern "C" const char gszField_006DCCF0[]; // 0x006DCCF0
extern "C" const char gszField_006DCD90[]; // 0x006DCD90
extern "C" const char gszField_006D9060[]; // 0x006D9060
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), FIXTURE_LINE(line)); exit(-1); }

struct D2HirelingTableGlobals
{
    D2HirelingTxt* f_0;
    int nCount;
    int indices[2][256];
};
extern D2HirelingTableGlobals gHirelingTables;  // 0x0096BDD0
#define gpHirelingTxt (gHirelingTables.f_0)
#define gnHirelingTxtRecordCount (gHirelingTables.nCount)
#define gaHirelingIds (gHirelingTables.indices)
// 0x00655720
void __fastcall sub_00655720_LoadHirelingTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { FIELD_TEXT(gszField_006DCCF0), 3, 0, 0x0, 0 },
        { FIELD_TEXT("id"), 2, 0, 0x4, 0 },
        { FIELD_TEXT("class"), 2, 0, 0x8, 0 },
        { FIELD_TEXT("act"), 2, 0, 0xC, 0 },
        { FIELD_TEXT("difficulty"), 2, 0, 0x10, 0 },
        { FIELD_TEXT("seller"), 2, 0, 0x14, 0 },
        { FIELD_TEXT(gszField_006DCD90), 2, 0, 0x18, 0 },
        { FIELD_TEXT("level"), 2, 0, 0x1C, 0 },
        { FIELD_TEXT("namefirst"), 1, 32, 0xD3, 0 },
        { FIELD_TEXT("namelast"), 1, 32, 0xF3, 0 },
        { FIELD_TEXT("exp/lvl"), 2, 0, 0x20, 0 },
        { FIELD_TEXT("hp"), 2, 0, 0x24, 0 },
        { FIELD_TEXT("hp/lvl"), 2, 0, 0x28, 0 },
        { FIELD_TEXT("defense"), 2, 0, 0x2C, 0 },
        { FIELD_TEXT("def/lvl"), 2, 0, 0x30, 0 },
        { FIELD_TEXT("str"), 2, 0, 0x34, 0 },
        { FIELD_TEXT("str/lvl"), 2, 0, 0x38, 0 },
        { FIELD_TEXT("dex"), 2, 0, 0x3C, 0 },
        { FIELD_TEXT("dex/lvl"), 2, 0, 0x40, 0 },
        { FIELD_TEXT("ar"), 2, 0, 0x44, 0 },
        { FIELD_TEXT("ar/lvl"), 2, 0, 0x48, 0 },
        { FIELD_TEXT("share"), 2, 0, 0x4C, 0 },
        { FIELD_TEXT("dmg-min"), 2, 0, 0x50, 0 },
        { FIELD_TEXT("dmg-max"), 2, 0, 0x54, 0 },
        { FIELD_TEXT("dmg/lvl"), 2, 0, 0x58, 0 },
        { FIELD_TEXT("resist"), 2, 0, 0x5C, 0 },
        { FIELD_TEXT("resist/lvl"), 2, 0, 0x60, 0 },
        { FIELD_TEXT("hiredesc"), 13, 0, 0xD2, &gpHireDescLinker_0096BCE8 },
        { FIELD_TEXT("defaultchance"), 2, 0, 0x64, 0 },
        { FIELD_TEXT("skill1"), 19, 0, 0x78, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode1"), 4, 0, 0xC0, 0 },
        { FIELD_TEXT("chance1"), 2, 0, 0x90, 0 },
        { FIELD_TEXT("chanceperlvl1"), 2, 0, 0xA8, 0 },
        { FIELD_TEXT("level1"), 4, 0, 0xC6, 0 },
        { FIELD_TEXT("lvlperlvl1"), 4, 0, 0xCC, 0 },
        { FIELD_TEXT("skill2"), 19, 0, 0x7C, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode2"), 4, 0, 0xC1, 0 },
        { FIELD_TEXT("chance2"), 2, 0, 0x94, 0 },
        { FIELD_TEXT("chanceperlvl2"), 2, 0, 0xAC, 0 },
        { FIELD_TEXT("level2"), 4, 0, 0xC7, 0 },
        { FIELD_TEXT("lvlperlvl2"), 4, 0, 0xCD, 0 },
        { FIELD_TEXT("skill3"), 19, 0, 0x80, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode3"), 4, 0, 0xC2, 0 },
        { FIELD_TEXT("chance3"), 2, 0, 0x98, 0 },
        { FIELD_TEXT("chanceperlvl3"), 2, 0, 0xB0, 0 },
        { FIELD_TEXT("level3"), 4, 0, 0xC8, 0 },
        { FIELD_TEXT("lvlperlvl3"), 4, 0, 0xCE, 0 },
        { FIELD_TEXT("skill4"), 19, 0, 0x84, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode4"), 4, 0, 0xC3, 0 },
        { FIELD_TEXT("chance4"), 2, 0, 0x9C, 0 },
        { FIELD_TEXT("chanceperlvl4"), 2, 0, 0xB4, 0 },
        { FIELD_TEXT("level4"), 4, 0, 0xC9, 0 },
        { FIELD_TEXT("lvlperlvl4"), 4, 0, 0xCF, 0 },
        { FIELD_TEXT("skill5"), 19, 0, 0x88, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode5"), 4, 0, 0xC4, 0 },
        { FIELD_TEXT("chance5"), 2, 0, 0xA0, 0 },
        { FIELD_TEXT("chanceperlvl5"), 2, 0, 0xB8, 0 },
        { FIELD_TEXT("level5"), 4, 0, 0xCA, 0 },
        { FIELD_TEXT("lvlperlvl5"), 4, 0, 0xD0, 0 },
        { FIELD_TEXT("skill6"), 19, 0, 0x8C, &gpSkillsLinker_0096C7CC },
        { FIELD_TEXT("mode6"), 4, 0, 0xC5, 0 },
        { FIELD_TEXT("chance6"), 2, 0, 0xA4, 0 },
        { FIELD_TEXT("chanceperlvl6"), 2, 0, 0xBC, 0 },
        { FIELD_TEXT("level6"), 4, 0, 0xCB, 0 },
        { FIELD_TEXT("lvlperlvl6"), 4, 0, 0xD1, 0 },
        { FIELD_TEXT("head"), 2, 0, 0x68, 0 },
        { FIELD_TEXT("torso"), 2, 0, 0x6C, 0 },
        { FIELD_TEXT("weapon"), 2, 0, 0x70, 0 },
        { FIELD_TEXT("shield"), 2, 0, 0x74, 0 },
        { FIELD_TEXT(gszField_006D9060), 0, 0, 0x0, 0 },
    };
    gpHirelingTxt = (D2HirelingTxt*)DATATBLS_CompileTxt(hArchive, FIELD_TEXT("hireling"), pTbl, &gnHirelingTxtRecordCount, sizeof(D2HirelingTxt));
    for (int i = 0; i < 256; ++i)
    {
        gaHirelingIds[0][i] = -1;
        gaHirelingIds[1][i] = -1;
    }
    const int bExpansion = sub_00408F20_HasExpansionMpq();
    for (int i = 0; i < gnHirelingTxtRecordCount; ++i)
    {
        const wchar_t* pUnicode = 0;
        gpHirelingTxt[i].wNameFirst = sub_00524D30_FindString(gpHirelingTxt[i].szNameFirst, &pUnicode);
        gpHirelingTxt[i].wNameLast = sub_00524D30_FindString(gpHirelingTxt[i].szNameLast, &pUnicode);
        if (bExpansion)
        {
            D2_ASSERT(gpHirelingTxt[i].wNameFirst > 0, 0x816);
            D2_ASSERT(gpHirelingTxt[i].wNameLast > gpHirelingTxt[i].wNameFirst, 0x817);
            D2_ASSERT(gpHirelingTxt[i].nId < 256, 0x818);
        }
        if (gpHirelingTxt[i].nId < 256)
        {
            const int nVersion = gpHirelingTxt[i].wVersion >= 100;
            if (gaHirelingIds[nVersion][gpHirelingTxt[i].nId] < 0)
                gaHirelingIds[nVersion][gpHirelingTxt[i].nId] = i;
        }
    }
}
