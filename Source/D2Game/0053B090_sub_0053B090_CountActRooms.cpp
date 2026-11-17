extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BitBufferStrc;
struct D2DrlgActStrc;

struct D2ActiveRoomStrc
{
    char unk0x00[0x7C];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2GameStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2MonsterDataStrc
{
    char unk0x00[0x3C];
    int nField3C;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                    // 0x0061A180
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits);                             // 0x00410EB0
int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize);                  // 0x0052B330

// 0x0053B090
int __fastcall sub_0053B090_CountActRooms(D2GameStrc* pGame, unsigned char nAct)
{
    D2_ASSERT(nAct < 5, 0x294);
    D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]);
    int nCount = 0;
    while (pRoom)
    {
        pRoom = pRoom->pRoomNext;
        ++nCount;
    }
    return nCount;
}

// 0x0053B140
void __fastcall sub_0053B140_WriteVarLength16(D2BitBufferStrc* pBuffer, unsigned short nValue)
{
    if (nValue < 0x100)
    {
        BITMANIP_Write(pBuffer, 0, 1);
        BITMANIP_Write(pBuffer, nValue, 8);
    }
    else
    {
        BITMANIP_Write(pBuffer, 1, 1);
        BITMANIP_Write(pBuffer, nValue, 16);
    }
}

// 0x0053B180
int* __fastcall sub_0053B180_GetMonsterDataField3C(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != 1)
    {
        return 0;
    }
    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return 0;
    }
    return &pMonsterData->nField3C;
}

// 0x0053B1A0
static __forceinline void sub_0053B1A0_SendToClient(int nClientId, void* pPacket, int nSize)
{
    sub_0052B330(0, nClientId, pPacket, nSize);
}

void __stdcall sub_M121_Emit_0053B1A0(int nClientId, void* pPacket, int nSize) { sub_0053B1A0_SendToClient(nClientId, pPacket, nSize); }
