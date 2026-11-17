struct D2UnitStrc;

struct D2GfxListNodeStrc
{
    char unk0x00[0x10];
    D2GfxListNodeStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x28];
    D2GfxListNodeStrc* pList;
};

#define GFX_INDEX_COUNT 16

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_004DB1C0_SetGfxByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue);              // 0x004DB1C0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

// 0x0046EAC0
static void __stdcall sub_0046EAC0_ResetGfxIndex(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(nIndex < GFX_INDEX_COUNT, 0x65F);
    for (int i = 0; i < GFX_INDEX_COUNT; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x668);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x66D, 0);
        pNode = pNext;
    }
    pGfxData->pList = 0;
}

// 0x0046F000
void __fastcall sub_0046F000_ResetGfx(D2UnitStrc* pUnit)
{
    for (int i = 0; i < GFX_INDEX_COUNT; ++i)
    {
        sub_0046EAC0_ResetGfxIndex(pUnit, i);
    }
}
