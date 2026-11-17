struct D2UnitStrc;
struct D2SkillStrc;
struct Unicode { unsigned short wChar; Unicode(unsigned short ch = 0) : wChar(ch) {} };
struct D2SkillsTxt {
    char unk00[0x12c]; short nMaxLevel;
    char unk12e[0x174-0x12e]; short wReqLevel;
    char unk176[0x194-0x176]; short wSkillDesc;
    char unk196[0x23c-0x196];
};
struct D2SkillDescTxt {
    char unk00[8]; unsigned short wStrName; unsigned short wStrShort; unsigned short wStrLong;
    char unk0e[0x120-0xe];
};
struct D2DataTablesStrc {
    char unk00[0xb8c]; D2SkillDescTxt* pSkillDescTxt;
    char unkB90[4]; int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt; char unkB9c[4]; int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char*, const char*, ...); // 0x006CC468
extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode*, int); // 0x004521C0
int __stdcall sub_004ED480_HasClassSkill(D2UnitStrc*); // 0x004ED480
int __fastcall sub_004EDEA0_AddSkillLine(D2UnitStrc*, Unicode*, D2SkillsTxt*, int, int, int, int, int); // 0x004EDEA0
void __fastcall sub_00502280_SetPopUpText(const Unicode*, int, int, int, int); // 0x00502280
void __fastcall D2Win_10131_GetTextDimensions(const Unicode*, int*, int*); // 0x00502520
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode*, const char*, int); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode*, const Unicode*); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode*, const Unicode*); // 0x005267E0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
static inline D2SkillsTxt* GetSkillsRecord(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}
static inline D2SkillDescTxt* GetSkillDescription(int nSkillId) {
    D2SkillsTxt* pRecord = GetSkillsRecord(nSkillId);
    if (pRecord) {
        int nDesc = pRecord->wSkillDesc;
        if (nDesc >= 0 && nDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return &sgptDataTables->pSkillDescTxt[nDesc];
    }
    return 0;
}
static inline int GetMaximumSkillLevel(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) {
        int nLevel = sgptDataTables->pSkillsTxt[nSkillId].nMaxLevel;
        if (nLevel > 0) return nLevel;
    }
    return 20;
}
// 0x004EF410
void __fastcall sub_004EF410_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int bFound;
    int nHeight;
    int nWidth;
    char szNumber[32];
    if (!pUnit) return;
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt) return;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    D2SkillStrc* pBonusSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    int bBonusOnly;
    if (pBonusSkill) {
        if (SKILLS_GetSkillLevel(pUnit, pBonusSkill, 1) && !SKILLS_GetSkillLevel(pUnit, pBonusSkill, 0))
            bBonusOnly = 1;
        else bBonusOnly = 0;
    } else bBonusOnly = 0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x109c));
    bFound = 0;
    for (int i = 16; i >= 10; --i) {
        if (sub_004EDEA0_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel + 1, nArg, i, 1))
            bFound = 1;
    }
    if (bFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    int bCurrentFound = 0;
    for (int i = 0; i < 6; ++i) {
        if (sub_004EDEA0_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bCurrentFound = 1;
    }
    if (bCurrentFound) {
        if (nSkillLevel <= 0) {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10ad));
        } else {
            wsprintfA(szNumber, gszFormatD_006D57BC, nSkillLevel);
            sub_00526320_ToUnicode(wszNumber, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x109e));
            sub_00526700(wszText, wszNumber);
        }
        if (bBonusOnly) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1112));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    }
    int bRemainingFound = 0;
    for (int i = 6; i < 10; ++i) {
        if (sub_004EDEA0_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bRemainingFound = 1;
    }
    if (bRemainingFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0) >= GetMaximumSkillLevel(nSkillId)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1111));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    } else {
        int nRequired = pSkillsTxt->wReqLevel + nSkillLevel;
        Unicode wszRequired[32];
        if (nRequired) {
            wsprintfA(szNumber, gszFormatD_006D57BC, nRequired);
            sub_00526320_ToUnicode(wszRequired, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105b));
            sub_00526700(wszText, wszRequired);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        }
    }
    D2SkillDescTxt* pDescription = GetSkillDescription(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrLong));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    Unicode wszName[256];
    pDescription = GetSkillDescription(nSkillId);
    sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrName));
    sub_004521C0_PrefixLevelText(wszName, 2);
    sub_00526700(wszText, wszName);
    if (bBonusOnly) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1113));
    }
    if (!sub_004ED480_HasClassSkill(pUnit)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    sub_00502280_SetPopUpText(wszText, nX, nHeight + nY + 3, 1, 0);
}
