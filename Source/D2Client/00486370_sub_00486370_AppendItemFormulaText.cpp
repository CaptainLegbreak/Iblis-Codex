struct D2UnitStrc;

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

struct D2ItemFormulaRecordStrc
{
    char unk0x00[0x9E];
    short nStat;
    char unk0xA0[0x04];
    unsigned int nCalc;
    char unk0xA8[0x0C];
    unsigned char nDescType;
    char unk0xB5;
    unsigned short wStringId;
};

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc);       // 0x00627C20
int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue);                              // 0x0062A5D0
int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue);                              // 0x0062A620

extern "C" const char szFmtLong_006D9BE8[];                                                                 // 0x006D9BE8
static D2UnitStrc* gdwGlobal_007BCBF4;                                                                      // 0x007BCBF4

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00486370
static void __stdcall sub_00486370_AppendItemFormulaText(D2UnitStrc* pItem, D2ItemFormulaRecordStrc* pRecord, Unicode* pBuffer)
{
    if (!pItem || !pRecord || !pRecord->nDescType)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || pRecord->wStringId == 0x1506)
    {
        return;
    }

    const Unicode* pSeparator = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pLineEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    switch (pRecord->nDescType)
    {
    case 1:
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        sub_00526700(pBuffer, pLineEnd);
        break;

    case 2:
    {
        char szValue[10];
        UnicodeChar wszValue[10];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        switch (pRecord->nStat)
        {
        case 6:
        case 74:
            nValue = ITEMS_GetBonusLifeBasedOnClass(pPlayer, nValue);
            break;
        case 8:
        case 26:
            nValue = ITEMS_GetBonusManaBasedOnClass(pPlayer, nValue);
            break;
        }
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf(szValue, 10, szFmtLong_006D9BE8, nValue);
        sub_00526F20_ToUnicode(wszValue, szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 3:
    {
        char szValue[10];
        UnicodeChar wszValue[10];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf(szValue, 10, szFmtLong_006D9BE8, nValue);
        sub_00526F20_ToUnicode(wszValue, szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 4:
    {
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        UnicodeChar wszText[0x200];
        sub_005269D0(0x200, wszText, D2LANG_GetStringFromTblIndex(pRecord->wStringId), nValue);
        sub_00526700(pBuffer, wszText);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }
    }
}

void __stdcall sub_Q05_Emit_00486370(D2ItemFormulaRecordStrc* pRecord, Unicode* pOut)
{
    Unicode wszBuffer[0x400];
    sub_00486370_AppendItemFormulaText(gdwGlobal_007BCBF4, pRecord, wszBuffer);
    sub_005267E0(pOut, wszBuffer);
}
