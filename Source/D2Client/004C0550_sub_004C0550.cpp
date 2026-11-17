#pragma pack(push, 1)
struct D2PacketRecord7Strc
{
    unsigned char nHeader;
    int nValue;
    unsigned char nType;
    unsigned char bFlag;
};
#pragma pack(pop)

struct D2InventoryStrc;

struct D2UnitStrc
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __cdecl sub_004C0380_OpenPanel();                                                                      // 0x004C0380
void __cdecl sub_004C0090();                                                                                // 0x004C0090
void __cdecl sub_004B3FB0_Close();                                                                          // 0x004B3FB0
void __fastcall sub_004B8020(void* pRes);                                                                   // 0x004B8020
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);                     // 0x0063C180
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00

static int gnFlag_007C5470;                                                                                 // 0x007C5470
static int gnValue_007C547C;                                                                                // 0x007C547C
extern int gnGlobal_007C5474;                                                                               // 0x007C5474
extern void* gpGlobal_007C5484;                                                                             // 0x007C5484

// 0x004C0550
void __fastcall sub_004C0550(D2PacketRecord7Strc* pPacket)
{
    switch (pPacket->nType)
    {
    case 0:
        gnFlag_007C5470 = 0;
        gnValue_007C547C = pPacket->nValue;
        sub_004C0380_OpenPanel();
        return;

    case 1:
        sub_004C0090();
        return;

    case 4:
        gnGlobal_007C5474 = 2;
        if (gpGlobal_007C5484)
        {
            sub_004B8020(gpGlobal_007C5484);
            gpGlobal_007C5484 = 0;
        }
        return;

    case 5:
    {
        D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
        INVENTORY_SetCursorItem(pInventory, 0);
    }
        if (pPacket->bFlag)
        {
            sub_004B9A00(5, 0, 0, 0, 0);
        }
        else
        {
            sub_004B9A00(3, 0, 0, 0, 0);
        }
        sub_004C0090();
        return;

    case 6:
    case 7:
        sub_004C0090();
        sub_004B3FB0_Close();
        return;

    default:
        D2_ASSERT(0, 0x354);
    }
}
