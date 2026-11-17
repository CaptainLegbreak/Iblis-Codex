typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct D2InventoryStrc;
struct D2SkillStrc;

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x002[0x02];
    unsigned char nFlags[8];
    char nCharClass;
    char unk0x00D[0x0B];
    short nITypeA[3];
    short nITypeB[3];
    short nETypeA[2];
    char unk0x028[0x06];
    short wSrvDoFunc;
    char unk0x030[0x154];
    short wStartMana;
    short unk0x186;
    unsigned char nManaShift;
    char unk0x189;
    short wMana;
    short wLevelMana;
    short unk0x18E;
    unsigned int dwDelay;
    char unk0x194[0x48];
    unsigned char nEType;
    char unk0x1DD[0x4B];
    unsigned char nRestrict;
    char unk0x229;
    short nState[3];
    char unk0x230[0x0C];
};

struct D2SkillDescTxt
{
    char unk0x00[2];
    char nSkillPage;
};

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt;
    D2SkillStrc* pNextSkill;
    char unk0x08[0x20];
    int nSkillLevel;
    int nLevelBonus;
    int nQuantity;
    int nOwnerGUID;
    int nCharges;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszSkillsSourceFile[];                                                                // 0x006DAB88
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SKILLS_HasFlag(pSkillsTxt, nFlag) ((pSkillsTxt)->nFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])

D2SkillDescTxt* __fastcall sub_004A89D0(int nSkillId);                         // 0x004A89D0
int __stdcall DATATBLS_GetMaxLevel(int nClass);                                                             // 0x00611830
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit);                                                        // 0x006235A0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);             // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                     // 0x00629BB0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem);                                                         // 0x0062E6F0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit);                                                 // 0x0063A400
int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit);                                      // 0x0063A510
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit);                                           // 0x00644150
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

static __declspec(noinline) int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

// 0x00644180
static int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill || !pSkill->pSkillsTxt)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;

    int nSkillId = pSkillsTxtRecord->nSkillId;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    int nSkillLevel = pSkill->nLevelBonus;
    nSkillLevel += SKILLS_GetShrineSkillLevelBonus(pUnit);
    nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 127, 0);

    if (pUnit && pUnit->dwUnitType == 0)
    {
        const int nClassId = pUnit->dwClassId;
        if (pSkillsTxtRecord->nCharClass == nClassId)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 83, nClassId);

            D2SkillDescTxt* pSkillDescTxtRecord = sub_004A89D0(nSkillId);
            if (pSkillDescTxtRecord->nSkillPage)
            {
                const int nTab = (!pUnit ? -1 : pUnit->dwClassId) * 8 + pSkillDescTxtRecord->nSkillPage - 1;
                nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 188, nTab);
            }

            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus > 3)
            {
                nBonus = 3;
            }
            nSkillLevel += nBonus;
        }
        else
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
    }
    else
    {
        if (pSkill->nSkillLevel <= 0)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
        }
        else
        {
            int nBonus = STATLIST_UnitGetStatValue(pUnit, 97, nSkillId);
            if (nBonus)
            {
                if (nBonus > 3)
                {
                    nBonus = 3;
                }
                nSkillLevel += nBonus;
            }
        }
    }

    const unsigned char nEType = pSkillsTxtRecord->nEType;
    if (nEType > 0)
    {
        nSkillLevel += STATLIST_UnitGetStatValue(pUnit, 126, nEType);
    }

    return nSkillLevel + STATLIST_UnitGetStatValue(pUnit, 107, nSkillId);
}

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus)
{
    int nSkillLevel = 0;
    int nMaxLevel = 0;

    if (pUnit && pSkill)
    {
        nSkillLevel = pSkill->nSkillLevel;
        if (bBonus && pSkill->nOwnerGUID == -1)
        {
            nSkillLevel += SKILLS_GetBonusSkillLevel(pUnit, pSkill);
        }

        nSkillLevel = D2_MAX(nSkillLevel, 0);
        return D2_MIN(nSkillLevel, DATATBLS_GetMaxLevel(0));
    }

    return 0;
}
