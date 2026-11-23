#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"

struct SGAMEDATA;
struct D2MsgHandlerEntryStrc;
struct D2PanelAnimEntryStrc;

extern int gbHasSelectedUnit; // 0x007A6A94
extern int gbHoverLocked; // 0x007A6A98
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

enum D2C_W04CursorConstants
{
    NUM_CURSOR_CELLS = 7,
};


struct D2PanelAnimEntryStrc
{
    void* pData;
    void (__cdecl* pfnDraw)();
    const char* f_8;
    char unk0x0C[0x10];
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __cdecl WINDOW_GetWindow(); // 0x004F59A0
void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
extern D2MsgHandlerEntryStrc gaCursorMsgHandlers[]; // 0x00711FEC
extern D2PanelAnimEntryStrc gaPanelAnim[]; // 0x00712020
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern int gbCursorVisible; // 0x007A6B08

// 0x00467640
int __fastcall sub_00467640_UnitIsOfTypeMonster(D2UnitStrc* pUnit, SGAMEDATA* pGame)
{
    if ((pUnit ? pUnit->dwUnitType : UNIT_INVALID) != 1)
    {
        return 0;
    }
    return 1;
}

int gnSelectedUnitId; // 0x007A6A78

int gnSelectedUnitType; // 0x007A6A8C

// 0x00467A10
D2UnitStrc* __cdecl sub_00467A10()
{
    if (gbHasSelectedUnit)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnSelectedUnitId, gnSelectedUnitType);
        if (pUnit && sub_00466870(pUnit, 0, 0, 0))
        {
            return pUnit;
        }
        gbHoverLocked = 0;
        gbHasSelectedUnit = 0;
        return 0;
    }

    return 0;
}

static int gnCursorY; // 0x007A6AAC

static int gnCursorX; // 0x007A6AB0

static int gnCursorOffsetX; // 0x007A6AB4

static void* gapCursorCels[NUM_CURSOR_CELLS]; // 0x007A6AC0

static int gnCursorAnim; // 0x007A6ADC

static int gnCursorAnimFrame; // 0x007A6AE0

static unsigned short gwGlobal_007A6AE4; // 0x007A6AE4

static int gdwLastMouseMoveTick; // 0x007A6AE8

static int gnCursorState; // 0x007A6AF0

int __cdecl sub_W04_EmitReadStatics()
{
    return gnCursorY + gnCursorX + gnCursorOffsetX + gnCursorAnim + gnCursorAnimFrame + gwGlobal_007A6AE4 + gdwLastMouseMoveTick + gnCursorState + (gapCursorCels[0] ? 1 : 0);
}

#include "gen/data/Source/D2Client/Unknown_00467640.inc"
