struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

#define BODYLOC_BELT 8
#define ITEMTYPE_BELT 19

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn);                                    // 0x006CC34C
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0
int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20

void (__cdecl* gpfnCallback_007A6B10)();                                                                    // 0x007A6B10
void (__cdecl* gpfnCallback_007A740C)();                                                                    // 0x007A740C
void (__cdecl* gpfnCallback_007A7414)();                                                                    // 0x007A7414
void (__cdecl* gpfnCallback_007A6B14)();                                                                    // 0x007A6B14
void (__cdecl* gpfnCallback_007A7410)();                                                                    // 0x007A7410

// 0x00468F00
void __cdecl sub_00468F00()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, BODYLOC_BELT);
        if (pItem && ITEMS_CheckItemTypeId(pItem, ITEMTYPE_BELT))
        {
            sub_00455F20(0x1F, 2, 0);
        }
    }
}

// 0x00469230
void __cdecl sub_00469230()
{
    if (gpfnCallback_007A6B10)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A6B10), 0x339);
        gpfnCallback_007A6B10();
    }
}

// 0x00469270
void __cdecl sub_00469270()
{
    if (gpfnCallback_007A740C)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A740C), 0x345);
        gpfnCallback_007A740C();
    }
}

// 0x004692B0
void __cdecl sub_004692B0()
{
    if (gpfnCallback_007A7414)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A7414), 0x350);
        gpfnCallback_007A7414();
    }
}

// 0x004692F0
void __cdecl sub_004692F0()
{
    if (gpfnCallback_007A6B14)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A6B14), 0x35D);
        gpfnCallback_007A6B14();
    }
}

// 0x00469330
void __cdecl sub_00469330()
{
    if (gpfnCallback_007A7410)
    {
        D2_ASSERT(!IsBadCodePtr(gpfnCallback_007A7410), 0x369);
        gpfnCallback_007A7410();
    }
}
