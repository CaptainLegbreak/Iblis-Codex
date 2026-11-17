extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2ActiveRoomStrc;
struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom;
    int nConvX;
    int nConvY;
    int nX;
    int nY;
    unsigned char unk_14[8];
    unsigned char bFlag1C;
};
struct D2UnitStrc
{
    unsigned char unk_00[0x2C];
    D2StaticPathStrc* pPath;
};
void __stdcall sub_00643260(int* pX, int* pY); // 0x00643260

struct D2CoordStrc { int nX; int nY; };

// 0x00620AE0
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, D2CoordStrc tCoord)
{
    D2_ASSERT(pUnit, 0x866);
    D2StaticPathStrc* pPath = pUnit->pPath;
    pPath->nX = tCoord.nX;
    pPath->nY = tCoord.nY;
    pPath->bFlag1C = 0;
    pPath->pRoom = pRoom;
    int nConvX = tCoord.nX;
    int nConvY = tCoord.nY;
    sub_00643260(&nConvX, &nConvY);
    pPath->nConvX = nConvX;
    pPath->nConvY = nConvY;
}
