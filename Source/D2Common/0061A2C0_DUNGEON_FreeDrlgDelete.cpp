struct D2DrlgActStrc;
struct D2DrlgDeleteStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x18];
    D2DrlgDeleteStrc* pDrlgDelete;
    char unk0x1C[0x10];
    D2DrlgActStrc* pAct;
};

struct D2DrlgActStrc
{
    char unk0x00[0x5C];
    void* pMemPool;
};

struct D2DrlgDeleteStrc
{
    int nUnitType;
    int nUnitGUID;
    D2DrlgDeleteStrc* pNext;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0061A2C0
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 912);

    D2DrlgDeleteStrc* pDrlgDelete = pRoom->pDrlgDelete;
    void* pMemPool = pRoom->pAct->pMemPool;
    if (pDrlgDelete)
    {
        do
        {
            D2DrlgDeleteStrc* pFree = pDrlgDelete;
            pDrlgDelete = pDrlgDelete->pNext;
            FOG_FreePool(pMemPool, pFree, ".\\DUNGEON\\Dungeon.cpp", 924, 0);
        }
        while (pDrlgDelete);
        pRoom->pDrlgDelete = 0;
    }
}
