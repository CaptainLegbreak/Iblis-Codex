#include "D2Client.h"
#include "D2Structs.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PacketRecord7Strc;

extern int gnUseItemDialogState; // 0x007C5474
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __cdecl USEITEM_ShowConfirmation(); // 0x004BFAF0
int __cdecl USEITEM_ClosePanel(); // 0x004C02F0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __stdcall ROSTERPETS_HandleRectClick(SMSGHANDLER_PARAMS* pMsg); // 0x004890B0

#pragma pack(push, 1)
struct D2PacketRecord7Strc
{
    unsigned char nHeader;
    int nValue;
    unsigned char nType;
    unsigned char bFlag;
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __cdecl USEITEM_OpenPanel(); // 0x004C0380
void __cdecl sub_004B3FB0_CloseNpc2(); // 0x004B3FB0
void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
extern void* gpUseItemConfirmDialog; // 0x007C5484

static int USEITEM_ClickHotspots(int nX, int nY); // 0x004C0450



static int USEITEM_ClickHotspots(int nX, int nY); // 0x004C0450


static int gnFlag_007C5470; // 0x007C5470

static int gnValue_007C547C; // 0x007C547C

// 0x004C0550
void __fastcall sub_004C0550(D2PacketRecord7Strc* pPacket)
{
    switch (pPacket->nType)
    {
    case 0:
        gnFlag_007C5470 = 0;
        gnValue_007C547C = pPacket->nValue;
        USEITEM_OpenPanel();
        return;

    case 1:
        sub_004C0090();
        return;

    case 4:
        gnUseItemDialogState = 2;
        if (gpUseItemConfirmDialog)
        {
            DIALOG_DestroyDialog(gpUseItemConfirmDialog);
            gpUseItemConfirmDialog = 0;
        }
        return;

    case 5:
    {
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
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
        sub_004B3FB0_CloseNpc2();
        return;

    default:
        D2_ASSERT(0, 0x354);
    }
}
