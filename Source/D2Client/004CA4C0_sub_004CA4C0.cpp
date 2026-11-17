extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TimedHintEntryStrc;

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* f_0;
    D2TimedHintNodeStrc* pNext;
};

struct D2UnitStrc
{
    char unk0x00[0x4C];
    short wAnimSpeed;
    char unk0x4E[0x2A];
    D2TimedHintNodeStrc* pHintList;
};

struct D2DirRateStrc
{
    int nValue;
    unsigned int nRate;
};

struct D2SkillsTxt
{
    char unk0x00[0x148];
    int dwParam[8];
    char unk0x168[0xD4];
};

struct D2DataTablesStrc
{
    char unk0x00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x04];
    int nSkillsTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern D2DirRateStrc gaDirRate_00727ED8[];                                                                  // 0x00727ED8

void __fastcall sub_00516950_LinkEntry(D2TimedHintNodeStrc** ppList, D2TimedHintEntryStrc* pEntry);       // 0x00516950
void __fastcall sub_00516980_RemoveNode(D2TimedHintNodeStrc** ppList, D2TimedHintEntryStrc* pEntry);      // 0x00516980
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce);                 // 0x004BA790
int __fastcall sub_004B9CA0_GetHintIdByKey(void* pKey);                                                     // 0x004B9CA0
int __fastcall sub_004818F0_GetCacheKind(int nIndex);                                                       // 0x004818F0

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004CA4C0
int __fastcall sub_004CA4C0(D2UnitStrc* pUnit, unsigned int nDirection)
{
    D2_ASSERT(pUnit, 0xB5C);
    nDirection &= 0xF;
    if (nDirection <= 0xD)
        return gaDirRate_00727ED8[nDirection].nValue;
    D2_ASSERT(0, 0xB60);
}

// 0x004CA500
unsigned int __fastcall sub_004CA500_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection)
{
    D2_ASSERT(pUnit, 0xB6B);
    nDirection &= 0xF;
    if (nDirection <= 0xD)
    {
        int nSpeed = pUnit->wAnimSpeed;
        if (!nSpeed)
            nSpeed = 1;
        return ((gaDirRate_00727ED8[nDirection].nRate << 8) + 0x80) / nSpeed;
    }
    D2_ASSERT(0, 0xB6F);
}

// 0x004CA810
int __fastcall sub_004CA810_GetModeSound(D2UnitStrc* pUnit, int nMode)
{
    D2_ASSERT(pUnit, 0xC08);
    int nSound = 0;
    switch (nMode & 0xF)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        nSound = 0x18E;
        break;
    case 10:
    case 11:
        nSound = 0x191;
        break;
    }
    return nSound;
}

// 0x004CA8A0
void __fastcall sub_004CA8A0_AddUnitHint(D2UnitStrc* pUnit, D2TimedHintEntryStrc* pEntry)
{
    D2_ASSERT(pUnit, 0xC2C);
    sub_00516950_LinkEntry(&pUnit->pHintList, pEntry);
}

// 0x004CA8D0
void __fastcall sub_004CA8D0_NotifyUnitHint(D2UnitStrc* pUnit, D2TimedHintEntryStrc* pEntry)
{
    D2_ASSERT(pUnit, 0xC2C);
    sub_00516980_RemoveNode(&pUnit->pHintList, pEntry);
}

// 0x004CA9C0
void __fastcall sub_004CA9C0_ReleaseUnitHints(D2UnitStrc* pUnit, int bForce)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2TimedHintNodeStrc* pNode = pUnit->pHintList;
    while (pNode)
    {
        D2TimedHintNodeStrc* pNext = pNode->pNext;
        sub_004BA790_ReleaseUnitSfx(pNode->f_0, pUnit, bForce);
        pNode = pNext;
    }
}

// 0x004CAA10
void __fastcall sub_004CAA10_PurgeUnitHints(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2TimedHintNodeStrc* pNode = pUnit->pHintList;
    while (pNode)
    {
        D2TimedHintEntryStrc* pEntry = pNode->f_0;
        D2TimedHintNodeStrc* pNext = pNode->pNext;
        if (sub_004818F0_GetCacheKind(sub_004B9CA0_GetHintIdByKey(pEntry)))
            sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 0);
        pNode = pNext;
    }
}

// 0x004CC7C0
int __fastcall sub_004CC7C0_GetSkillMissileRange(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxt = DATATBLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    if (nLevel <= 0)
        return 0;
    return pSkillsTxt->dwParam[2] + (nLevel - 1) * pSkillsTxt->dwParam[3];
}

#include "gen/data/Source/D2Client/004CA4C0_sub_004CA4C0.inc"
