struct D2DrlgRoomStrc;

struct D2ActiveRoomStrc
{
    D2ActiveRoomStrc** ppRoomList;
    char unk0x04[8];
    int nTileCount;
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x14[16];
    int nNumRooms;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
int __fastcall sub_0066BCF0(D2DrlgRoomStrc* pDrlgRoom);                                        // 0x0066BCF0
int __fastcall DRLGROOM_ReorderNearRoomList(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc** ppRoomList);      // 0x0066BD00

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00619800
static void __stdcall sub_00619800(void* pMemory, D2ActiveRoomStrc* pRoom)
{
    const int nNear = sub_0066BCF0(pRoom->pDrlgRoom);
    pRoom->ppRoomList = (D2ActiveRoomStrc**)FOG_AllocPool(pMemory, sizeof(D2ActiveRoomStrc*) * nNear, ".\\DUNGEON\\Dungeon.cpp", 256, 0);
    pRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pRoom->pDrlgRoom, pRoom->ppRoomList);
    for (unsigned int i = 0; i < pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pAdjacentRoom = pRoom->ppRoomList[i];
        D2_ASSERT(pAdjacentRoom, 264);
        if (pAdjacentRoom != pRoom)
            pAdjacentRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pAdjacentRoom->pDrlgRoom, pAdjacentRoom->ppRoomList);
    }
}

struct sub_Z16_EmitRoomHolder
{
    char unk0x00[0x5C];
    void* pMemory;
};

D2ActiveRoomStrc* __fastcall sub_Z16_EmitUpdateRoomsNear(sub_Z16_EmitRoomHolder* pOther, D2ActiveRoomStrc* pRoom)
{
    sub_00619800(pOther->pMemory, pRoom);
    return pRoom;
}
