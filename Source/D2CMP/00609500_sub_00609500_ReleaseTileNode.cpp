extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

struct D2CmpTileNodeStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    void* pData;
    struct D2CmpTileNodeStrc* pNext;
};

// 0x00609500
static __forceinline void sub_00609500_ReleaseTileNode(D2CmpTileNodeStrc* pNode)
{
    D2_ASSERT(pNode, 0x31);
    if (pNode->pData)
    {
        FOG_Free(pNode->pData, ".\\SRC\\Tilecmp.cpp", 0x35, 0);
    }
    FOG_Free(pNode, ".\\SRC\\Tilecmp.cpp", 0x38, 0);
}

void __stdcall sub_M128_Emit_00609500(D2CmpTileNodeStrc* pNode)
{
    sub_00609500_ReleaseTileNode(pNode);
}
