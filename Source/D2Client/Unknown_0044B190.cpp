#include "D2Client.h"
#include "D2Structs.h"
#include "D2Drlg.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientNotifyStrc;
struct D2ClientCharRecordStrc;
struct D2RangeStrc;

#pragma pack(push, 1)
struct D2ClientCharRecordStrc
{
    char unk0x000[0x1F];
    char szText0x1F[0x18];
    char szText0x37[0x1B8];
    unsigned char aFlags[2];
    char unk0x1F1[0x34];
    D2ClientNotifyStrc* pNotify;
    char unk0x229[0x1C];
    char szText0x245[0x18];
};

#pragma pack(pop)


extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" size_t __cdecl strlen(const char* szString);
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl sub_0045AE90(); // 0x0045AE90
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode); // 0x0045AEA0
void __fastcall sub_00457640(int nValue); // 0x00457640
void __fastcall sub_00457440_Nop(int nResolution); // 0x00457440
void __fastcall sub_004549B0(int nResolution); // 0x004549B0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __cdecl sub_00466FF0(); // 0x00466FF0
void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom); // 0x0046C460
void __fastcall sub_00466820_SpawnRoomPresets(D2ActiveRoomStrc* pRoom); // 0x00466820
void __fastcall sub_0046BE60_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom); // 0x0046BE60
extern D2McpPacketHandler gpfnMcpHandlers_0070ED00[]; // 0x0070ED00
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_00711474; // 0x00711474
extern void (__fastcall* gpfnCallback_00799308)(void* pArg); // 0x00799308
extern int gaValues_007A0424[]; // 0x007A0424
extern int gnValueCount_007A044C; // 0x007A044C
extern int gdwGlobal_007A061C; // 0x007A061C
extern D2DrlgActStrc* gpAct_007A0634; // 0x007A0634
extern int gdwGlobal_007A0650; // 0x007A0650
extern int gdwGlobal_007A0654; // 0x007A0654
extern int gdwGlobal_007A0658; // 0x007A0658
extern int gdwGlobal_007A0670; // 0x007A0670
extern int gdwGlobal_007A0674; // 0x007A0674
extern int gnUiRecordRow_007A5218; // 0x007A5218
extern int gnAutomapHeight_007A521C; // 0x007A521C
extern int gnAutomapWidth_007A5220; // 0x007A5220

struct D2RangeStrc
{
    int nStart;
    int nLength;
};
int __cdecl sub_004F59A0(); // 0x004F59A0
void __stdcall WINDOW_ShowAll(); // 0x004F5F60
void __stdcall CLIENT_Initialize(int nArg, const char* szAddress); // 0x0052A750
int __fastcall sub_00451BB0_MessageLoop(int (__stdcall* pfnIdle)(int)); // 0x00451BB0
int __stdcall sub_0044BBB0_WaitConnect(int nUnused); // 0x0044BBB0
extern D2McpCallbackFn gpfnMcpCallback_007992F8; // 0x007992F8
extern D2McpCallbackFn gpfnMcpCallback_007992FC; // 0x007992FC

D2ClientCharRecordStrc* gpCharRecord_007A0438; // 0x007A0438

int gdwGlobal_007A065C; // 0x007A065C

int gdwGlobal_007A0660; // 0x007A0660

int gdwGlobal_007A0664; // 0x007A0664

int gdwGlobal_007A066C; // 0x007A066C

// 0x0044B190
int __fastcall sub_0044B190_DispatchPacket(const unsigned char* pPacket, unsigned int nSize)
{
    int nResult = 0;
    if (nSize <= 0)
        return nResult;
    const unsigned char nCmd = pPacket[0];
    if (nCmd >= 0x1A)
        return 0;
    D2McpPacketHandler pfnHandler = gpfnMcpHandlers_0070ED00[nCmd];
    if (pfnHandler)
        nResult = pfnHandler(pPacket, nSize);
    return nResult;
}

// 0x0044B220
void __fastcall sub_0044B220_SetCallback(void (__fastcall* pfnCallback)(void* pArg))
{
    gpfnCallback_00799308 = pfnCallback;
}

// 0x0044B440
void __fastcall sub_0044B440_PushValue(int nValue)
{
    D2_ASSERT(gnValueCount_007A044C < 5, 0xAA);
    gaValues_007A0424[gnValueCount_007A044C] = nValue;
    gnValueCount_007A044C += 1;
}

// 0x0044B7B0
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify()
{
    return gpCharRecord_007A0438->pNotify;
}

// 0x0044B7C0
const char* __cdecl sub_0044B7C0_GetRecordText1F()
{
    if (gpCharRecord_007A0438 && strlen(gpCharRecord_007A0438->szText0x1F) >= 1)
        return gpCharRecord_007A0438->szText0x1F;
    return 0;
}

// 0x0044B7F0
const char* __cdecl sub_0044B7F0_GetRecordText245()
{
    if (gpCharRecord_007A0438 && strlen(gpCharRecord_007A0438->szText0x245) >= 1)
        return gpCharRecord_007A0438->szText0x245;
    return 0;
}

// 0x0044B820
const char* __cdecl sub_0044B820_GetRecordText37()
{
    if (gpCharRecord_007A0438 && strlen(gpCharRecord_007A0438->szText0x37) >= 1)
        return gpCharRecord_007A0438->szText0x37;
    return 0;
}

// 0x0044B850
int __cdecl sub_0044B850_IsHardcore()
{
    return gpCharRecord_007A0438->aFlags[0] & 4;
}

// 0x0044B860
void __cdecl sub_0044B860()
{
    *(unsigned short*)gpCharRecord_007A0438->aFlags |= 8;
}

// 0x0044B880
void __fastcall sub_0044B880_SetValue(int nValue)
{
    gdwGlobal_0070EE8C = nValue;
}

// 0x0044BA20
void __fastcall sub_0044BA20(int nResolution)
{
    if (nResolution == D2GFX_GetResolutionMode())
        return;
    switch (nResolution)
    {
    case 0:
        gnGlobal_0071146C = 640;
        gnGlobal_00711470 = 480;
        gnUiRecordRow_007A5218 = 0;
        break;
    case 2:
        gnGlobal_0071146C = 800;
        gnGlobal_00711470 = 600;
        gnUiRecordRow_007A5218 = 1;
        break;
    }
    gnAutomapWidth_007A5220 = gnGlobal_0071146C;
    gnAutomapHeight_007A521C = gnGlobal_00711470 - 40;
    gnGlobal_00711474 = gnGlobal_0071146C;
    sub_004F90A0(nResolution);
    sub_0045AEA0_SetPanelSlide(sub_0045AE90());
    sub_00457640(1);
    sub_00457440_Nop(nResolution);
    sub_004549B0(nResolution);
}

// 0x0044BE80
void __fastcall sub_0044BE80(int bAlwaysRun)
{
    gdwGlobal_007A0660 = bAlwaysRun;
}

// 0x0044BEA0
void __fastcall sub_0044BEA0_SetValue(int nValue)
{
    gdwGlobal_007A0664 = nValue;
}

// 0x0044BEC0
unsigned short __cdecl sub_0044BEC0_GetClickFlags()
{
    int nFlags = 0;
    if (gdwGlobal_007A065C)
        nFlags = 8;
    if (gdwGlobal_007A0660)
        nFlags |= 8;
    if (gdwGlobal_007A0664)
        nFlags |= 4;
    return nFlags;
}

// 0x0044BEF0
void __cdecl sub_0044BEF0()
{
    gdwGlobal_007A0658 = 1;
}

// 0x0044BFE0
int __cdecl sub_0044BFE0()
{
    return gdwGlobal_007A066C != 0;
}

static __forceinline int CLIENT_GetClickFlags_inl()
{
    int nFlags = 0;
    if (gdwGlobal_007A065C)
        nFlags = 8;
    if (gdwGlobal_007A0660)
        nFlags |= 8;
    if (gdwGlobal_007A0664)
        nFlags |= 4;
    return nFlags;
}

// 0x0044C060
void __cdecl sub_0044C060_Refresh()
{
    gdwGlobal_0070F234 = 0x10;
    gdwGlobal_007A0650 = 0;
    gdwGlobal_007A066C = 0;
    gdwGlobal_007A0658 = 0;
    sub_00466FF0();
    if (gdwGlobal_007A061C)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == 0)
            sub_00462D00(2, sub_00468730(), sub_00468740(), CLIENT_GetClickFlags_inl());
    }
}

// 0x0044C2C0
void __cdecl sub_0044C2C0()
{
    gdwGlobal_0070F2BC = 8;
    if (gdwGlobal_007A061C && gdwGlobal_007A0654)
    {
        gdwGlobal_007A0670 = 1;
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        const int nFlags = CLIENT_GetClickFlags_inl();
        if (pPlayer && pPlayer->dwUnitType == 0)
            sub_00462D00(4, sub_00468730(), sub_00468740(), nFlags);
    }
}

// 0x0044C750
void __cdecl sub_0044C750_InitRooms()
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(gpAct_007A0634); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (!(pRoom->dwFlags & 1))
        {
            sub_0046C460_PopulateRoom(pRoom);
            sub_00466820_SpawnRoomPresets(pRoom);
            sub_0046BE60_ApplyDenOfEvilRoom(pRoom);
            pRoom->dwFlags |= 1;
        }
    }
}

// 0x0044C860
void __fastcall sub_0044C860_SetValue(int nValue)
{
    gdwGlobal_007A0674 = nValue;
}

#include "gen/data/Source/D2Client/Unknown_0044B190.inc"

int gaValues_007A0424[1]; // 0x007A0424

int gnValueCount_007A044C; // 0x007A044C

// 0x0044B1F0
void __fastcall sub_0044B1F0_SetMcpCallbackA(D2McpCallbackFn pfnCallback)
{
    gpfnMcpCallback_007992F8 = pfnCallback;
}

// 0x0044B200
void __fastcall sub_0044B200_SetMcpCallbackB(D2McpCallbackFn pfnCallback)
{
    gpfnMcpCallback_007992FC = pfnCallback;
}

// 0x0044B480
int __cdecl sub_0044B480_PopValue()
{
    D2_ASSERT(gnValueCount_007A044C, 0xB4);
    int nValue = gaValues_007A0424[0];
    --gnValueCount_007A044C;
    for (int i = 0; i < 3; ++i)
        gaValues_007A0424[i] = gaValues_007A0424[i + 1];
    return nValue;
}

// 0x0044B780
void __cdecl sub_0044B780_RaiseGameWindow()
{
    void* hWnd = (void*)sub_004F59A0();
    if (hWnd)
        SendMessageA(hWnd, 0x1C, 0, 0);
    WINDOW_ShowAll();
}

// 0x0044B870
void __cdecl sub_0044B870_SetLaunchState1()
{
    gnLaunchState_0070EE4C = 1;
}

// 0x0044BB70
int __stdcall sub_0044BB70_StartGame()
{
    gnSubsystemActive_007A0458 = 1;
    return GAME_Initialize();
}

// 0x0044BC10
int __fastcall sub_0044BC10_RunClient(int nArg, const char* szAddress)
{
    CLIENT_Initialize(nArg, szAddress);
    sub_00451BB0_MessageLoop(sub_0044BBB0_WaitConnect);
    return 1;
}

// 0x0044BE10
int __fastcall sub_0044BE10_GetRangeEnd(D2RangeStrc* pRange)
{
    return pRange->nLength + pRange->nStart;
}
