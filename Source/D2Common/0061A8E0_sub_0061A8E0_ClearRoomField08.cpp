extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ActiveRoomStrc
{
    char unk0x00[0x08];
    int pRoomTiles;
};

// 0x0061A8E0
void __fastcall sub_0061A8E0_ClearRoomField08(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 0x4EC);
    pRoom->pRoomTiles = 0;
}
