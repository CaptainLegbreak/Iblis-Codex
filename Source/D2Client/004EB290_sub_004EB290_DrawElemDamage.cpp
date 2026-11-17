struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};

struct D2InventoryStrc;
struct D2SkillStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x58];
    D2InventoryStrc* pInventory;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x1DA];
    unsigned char nEType;
};

struct D2SkillDescTxt
{
    char unk0x00[0x18];
    unsigned int dwDescCalc1;
    unsigned int dwDescCalc2;
};

struct D2ItemsTxt
{
    char unk0x00[0xFE];
    unsigned char nMinMisDam;
    unsigned char nMaxMisDam;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC
extern "C" const char szFmtRange_006D9D70[];                                                                // 0x006D9D70
extern "C" const char szFmtRangeKK_006DBEAC[];                                                              // 0x006DBEAC
extern "C" const char szFmtRangeK_006DBEB8[];                                                               // 0x006DBEB8
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem);               // 0x0063C8F0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647BC0
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4);            // 0x00647D00
int __fastcall sub_004CC7C0_GetSkillBonus(int nSkillId, int nSkillLevel);                                   // 0x004CC7C0
short __stdcall sub_00629860_GetStrengthFactor(D2UnitStrc* pItem);                                          // 0x00629860
short __stdcall sub_006298A0_GetDexterityFactor(D2UnitStrc* pItem);                                         // 0x006298A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall sub_0063A380(D2UnitStrc* pUnit);                                        // 0x0063A380
int __stdcall sub_0063A3A0(D2UnitStrc* pUnit);                                         // 0x0063A3A0

extern "C" const char szSkillDescFile_006DBF24[];                                                         // 0x006DBF24
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                         // 0x004A89D0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bTotal);       // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bTotal);       // 0x00644E40
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00

__declspec(noinline) static int sub_004E6FB0_GetETypeColor(int nEType);
// 0x004E6FB0
static int sub_004E6FB0_GetETypeColor(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 1;
    case 2:
        return 9;
    case 3:
    case 4:
        return 3;
    case 5:
        return 2;
    }
    return 0;
}

static __declspec(noinline) void __stdcall sub_004E96E0_DrawDamageRange(int nMin, int nMax, int nColor, int nY, int nLeft, int nRight)
{
    if (nMin >= nMax)
    {
        nMax = nMin + 1;
    }

    Unicode wszText[32];
    char szText[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, szFmtRange_006D9D70, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, szFmtRangeKK_006DBEAC, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, szFmtRangeK_006DBEB8, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText, szText, 32);
    int nWidth = 0;
    int nHeight = 0;
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    nWidth = nWidth * 11 / 7;
    if (nWidth > nRight - nLeft)
    {
        sub_00502EF0(6);
        --nY;
    }
    else
    {
        sub_00502EF0(1);
    }
    sub_004A7080(gnGlobal_007A2858 + nLeft, gnGlobal_00711470 + gnGlobal_007A285C + nY - 480, gnGlobal_007A2858 + nRight, wszText, nColor);
}

// 0x004EB290
void __fastcall sub_004EB290_DrawElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDesc = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDesc)
    {
        return;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    const int nLevel = *(volatile int*)&nSkillLevel;
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1);
    const int nColor = sub_004E6FB0_GetETypeColor(pSkillsTxt->nEType);

    int nFrames = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDesc->dwDescCalc1, SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 3114), nLevel);
    if (!nFrames)
    {
        nFrames = 1;
    }

    int nDivisor = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDesc->dwDescCalc2, SKILLS_GetSkillIdFromSkill(pSkill, szSkillDescFile_006DBF24, 3119), nLevel);
    if (!nDivisor)
    {
        nDivisor = 1;
    }

    sub_004E96E0_DrawDamageRange((nFrames * nMin * 25 / nDivisor) >> 8, (nFrames * nMax * 25 / nDivisor) >> 8, nColor, nY, nLeft, nRight);
}
