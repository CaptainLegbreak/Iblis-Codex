struct D2ItemTypesTxt
{
    char unk0x00[0x04];
    short nEquiv1;
    short nEquiv2;
    char unk0x08[0xDC];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern void* gpItemTypesTxt_0087D82C;                                                                       // 0x0087D82C

// 0x00504A20
int __stdcall sub_6F8A32B0(int a1, int nItemType)
{
    if (!nItemType)
    {
        return 1;
    }

    if (!a1)
    {
        return 0;
    }

    int itemTypeStack[64];

    itemTypeStack[0] = a1;
    int nStackIndex = 1;
    while (nStackIndex)
    {
        const int v5 = itemTypeStack[nStackIndex - 1];
        --nStackIndex;

        if (nItemType == v5)
        {
            return 1;
        }

        D2ItemTypesTxt* pItemTypesTxtRecord = &((D2ItemTypesTxt*)gpItemTypesTxt_0087D82C)[v5];
        if (pItemTypesTxtRecord->nEquiv1)
        {
            itemTypeStack[nStackIndex] = pItemTypesTxtRecord->nEquiv1;
            ++nStackIndex;

            if (pItemTypesTxtRecord->nEquiv2)
            {
                itemTypeStack[nStackIndex] = pItemTypesTxtRecord->nEquiv2;
                ++nStackIndex;
            }
        }

        D2_ASSERT(nStackIndex < 64, 2898);
    }

    return 0;
}
