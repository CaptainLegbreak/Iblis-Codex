#pragma pack(push, 1)
struct D2ClientCacheEntryStrc
{
    char szName[0x3D];
    unsigned char nVariants;
    char unk0x3E[0x22];
    int nFirstVariant;
    char unk0x64[0x26];
    unsigned int nRefCount;
};
#pragma pack(pop)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static D2ClientCacheEntryStrc* sgptSoundHeaderTable;                                                     // 0x007BC9A0
static int gnCacheEntries_007BC9A4;                                                                         // 0x007BC9A4

void __cdecl sub_N10_EmitSetCacheTable(D2ClientCacheEntryStrc* pEntries, int nCount)
{
    sgptSoundHeaderTable = pEntries;
    gnCacheEntries_007BC9A4 = nCount;
}

D2ClientCacheEntryStrc* __fastcall sub_N10_EmitGetCacheEntry(int nIndex)
{
    if (sgptSoundHeaderTable && nIndex >= 0 && nIndex < gnCacheEntries_007BC9A4)
        return &sgptSoundHeaderTable[nIndex];
    return 0;
}

// 0x004822B0
void __fastcall sub_004822B0_AddVariantRefs(int nIndex, int nDelta)
{
    if (!nIndex)
        return;
    D2ClientCacheEntryStrc* pEntry = sub_N10_EmitGetCacheEntry(nIndex);
    if (!pEntry)
        return;
    if (!pEntry->nRefCount && nDelta == -1)
        return;
    for (int i = pEntry->nFirstVariant; i < pEntry->nFirstVariant + pEntry->nVariants; i++)
    {
        D2ClientCacheEntryStrc* pVariant = sub_N10_EmitGetCacheEntry(i);
        D2_ASSERT(pVariant->nRefCount > 0 || nDelta != -1, 0x1DC);
        pVariant->nRefCount += nDelta;
    }
}

// 0x00482370
void __fastcall sub_00482370_ClearVariantRefs(int nIndex)
{
    if (!nIndex)
        return;
    D2ClientCacheEntryStrc* pEntry = sub_N10_EmitGetCacheEntry(nIndex);
    if (!pEntry)
        return;
    for (int i = pEntry->nFirstVariant; i < pEntry->nFirstVariant + pEntry->nVariants; i++)
        sub_N10_EmitGetCacheEntry(i)->nRefCount = 0;
}
