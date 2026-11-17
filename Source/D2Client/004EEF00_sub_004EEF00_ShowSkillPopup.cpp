struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2SkillsTxt
{
    char unk0x00[0x194];
    short wSkillDesc;
    char unk0x196[0x23C - 0x196];
};

struct D2SkillDescTxt
{
    char unk0x00[0x08];
    unsigned short wStrName;
    unsigned short wStrShort;
    unsigned short wStrLong; char unk0x0E[0x112];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB8C];
    D2SkillDescTxt* pSkillDescTxt;
    char unk0xB90[0x4];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x4];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC

int __fastcall sub_004EDEA0_AddSkillLine(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nArg3, int nArg4, int nLine, int nArg5); // 0x004EDEA0
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return pRecord;
}

static inline D2SkillDescTxt* CLIENT_GetSkillDescTxtRecord(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}

struct D2SkillStrc;
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*,int,int); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*,D2SkillStrc*,int); // 0x006442A0
int __fastcall sub_004AA8B0_GetMaxSkillLevel(int); // 0x004AA8B0
void __fastcall sub_004521C0_SetTextColor(Unicode*,int); // 0x004521C0
int __stdcall sub_004ED480_CanLearnSkill(D2UnitStrc*); // 0x004ED480

// 0x004EEF00
void __fastcall sub_004EEF00_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int nHeight;
    int nWidth;
    char szNumber[32];
    if(!pUnit)return;
    D2SkillsTxt* pSkillsTxt=CLIENT_GetSkillsTxtRecord(nSkillId);
    if(!pSkillsTxt)return;
    D2SkillStrc* pBonusSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bGranted;
    if(pBonusSkill){
        if(SKILLS_GetSkillLevel(pUnit,pBonusSkill,1) && !SKILLS_GetSkillLevel(pUnit,pBonusSkill,0))bGranted=1;
        else bGranted=0;
    } else bGranted=0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText,D2LANG_GetStringFromTblIndex(0x109C));
    D2SkillStrc* pSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bMaxed;
    if(pSkill && SKILLS_GetSkillLevel(pUnit,pSkill,0)>=sub_004AA8B0_GetMaxSkillLevel(nSkillId))bMaxed=1;
    else bMaxed=0;
    int bFound=0;
    for(int i=16;i>=10;--i)
        if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bFound=1;
    if(bFound)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    if(!bMaxed)
    {
        int bNext=0;
        for(int i=0;i<6;++i)
            if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bNext=1;
        if(bNext)
        {
            int nPrefixId=0x109D;
            if(!nSkillLevel)nPrefixId=0x10AD;
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(nPrefixId));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    if(nSkillLevel>0)
    {
        int bCurrent=0;
        for(int i=0;i<6;++i)
            if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel,nArg,i,0))bCurrent=1;
        if(bCurrent)
        {
            wsprintfA(szNumber,gszFormatD_006D57BC,nSkillLevel);
            sub_00526320_ToUnicode(wszNumber,szNumber,32);
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x109E));
            sub_00526700(wszText,wszNumber);
            if(bGranted)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1112));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    int bSynergy=0;
    for(int i=6;i<10;++i)
        if(sub_004EDEA0_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bSynergy=1;
    if(bSynergy)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    D2SkillDescTxt* pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrLong));
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    Unicode wszName[1024];
    pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_005267E0(wszName,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrName));
    sub_004521C0_SetTextColor(wszName,2);
    sub_00526700(wszText,wszName);
    if(bGranted)
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1113));
    }
    if(!sub_004ED480_CanLearnSkill(pUnit))
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText,&nWidth,&nHeight);
    sub_00502280_SetPopUpText(wszText,nX-24,nHeight+nY+3,0,0);
}
