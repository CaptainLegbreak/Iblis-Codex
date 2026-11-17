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
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
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

// 0x004EB460
void __fastcall sub_004EB460_DrawThrowDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2UnitStrc* pItem;
    if (!INVENTORY_GetEquippedShield(pUnit->pInventory, &pItem))
    {
        return;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    int nMin = pItemsTxtRecord->nMinMisDam;
    int nMax = pItemsTxtRecord->nMaxMisDam;
    D2SkillStrc* pThrowSkill = SKILLS_GetSkillById(pUnit, 0x75, -1);
    if (pThrowSkill && STATES_CheckState(pUnit, 0x65))
    {
        const int nLevel = SKILLS_GetSkillLevel(pUnit, pThrowSkill, 1);
        nMin += SKILLS_GetMinPhysDamage(pUnit, 0x75, nLevel, 1) >> 8;
        nMax += SKILLS_GetMaxPhysDamage(pUnit, 0x75, nLevel, 1) >> 8;
    }

    int nColor = 0;
    int nBonus = sub_004CC7C0_GetSkillBonus(pSkillsTxt->nSkillId, nSkillLevel);
    int nFactor = sub_00629860_GetStrengthFactor(pItem);
    if (nFactor)
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFactor / 100;
    }
    nFactor = sub_006298A0_GetDexterityFactor(pItem);
    if (nFactor)
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFactor / 100;
    }

    nBonus += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
    const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
    const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
    if (sub_0063A380(pUnit))
    {
        nColor = 3;
    }
    const int nDrawColor = sub_0063A3A0(pUnit) ? 1 : nColor;
    if (nBonus <= -90)
    {
        nBonus = -90;
    }

    sub_004E96E0_DrawDamageRange(nMin + (nBonus * nMin + nMinPercent) / 100, nMax + (nBonus * nMax + nMaxPercent) / 100, nDrawColor, nY, nLeft, nRight);
}
