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
    char unk0x0C[0x114];
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
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
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

// 0x004EF990
void __fastcall sub_004EF990_SetSkillPopUpText(D2UnitStrc* pUnit, int nSkillId, int nArg3, int nArg4, int nArg5, int nX, int nY)
{
    int bFound;
    int nHeight;
    int nWidth;
    char szNumber[32];

    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return;
    }

    Unicode wszText[1024];
    Unicode wszNumber[32];

    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x109C));

    bFound = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (sub_004EDEA0_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nArg3, nArg4, i, nArg5))
        {
            bFound = 1;
        }
    }

    if (bFound)
    {
        wsprintfA(szNumber, gszFormatD_006D57BC, nArg3);
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x109E));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }

    if (!nSkillId && pUnit->dwUnitType == 0 && pUnit->dwClassId == 6)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x5722));
    }

    D2SkillDescTxt* pSkillDescTxt = CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pSkillDescTxt ? 0x1506 : pSkillDescTxt->wStrShort));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));

    pSkillDescTxt = CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pSkillDescTxt ? 0x1506 : pSkillDescTxt->wStrName));

    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    sub_00502280_SetPopUpText(wszText, nX, nHeight + nY + 3, nArg5, 0);
}
