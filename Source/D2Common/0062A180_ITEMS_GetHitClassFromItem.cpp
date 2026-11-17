extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2ItemsTxt
{
    char unk0x000[0x13C];
    unsigned char nHitClass;
};

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

// 0x0062A180
unsigned char __stdcall ITEMS_GetHitClassFromItem(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x118F);
    D2_ASSERT(pItem->dwUnitType == 4, 0x1190);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1192);
    return pItemsTxtRecord->nHitClass;
}

// 0x0062A2F0
static __declspec(noinline) int sub_0062A2F0_IsPlainQuality(int nQuality)
{
    switch (nQuality)
    {
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 0;
    }
    return 1;
}

int __stdcall sub_M88_Emit_0062A2F0(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if (!sub_0062A2F0_IsPlainQuality(ITEMS_GetItemQuality(pItem1)))
        return 0;
    if (!sub_0062A2F0_IsPlainQuality(ITEMS_GetItemQuality(pItem2)))
        return 0;
    return 1;
}
