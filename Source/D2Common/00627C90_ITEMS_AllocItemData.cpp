struct D2ItemDataStrc
{
    char unk0x00[0x0C];
    int dwOwnerGUID;
    char unk0x10[0x64];
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    char unk0x04[0x10];
    D2ItemDataStrc* pItemData;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

// 0x00627C90
void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == 4)
    {
        D2ItemDataStrc* pItemData = (D2ItemDataStrc*)sub_0040B430(pMemPool, sizeof(D2ItemDataStrc), ".\\ITEMS\\Items.cpp", 210, 0);
        D2_ASSERT(pItemData, 213);
        memset(pItemData, 0, sizeof(D2ItemDataStrc));
        pItemData->dwOwnerGUID = -1;
        pItem->pItemData = pItemData;
    }
}
