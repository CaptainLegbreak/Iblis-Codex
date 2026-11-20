#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2HoverCoordStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2ViewStrc* gpView_007A0640; // 0x007A0640
extern int gdwGlobal_007A6A98; // 0x007A6A98
int __cdecl sub_004A0000(); // 0x004A0000
D2UnitStrc* __cdecl sub_0049E8B0_GetTextUnit(); // 0x0049E8B0
void __fastcall sub_0049DA30(D2UnitStrc* pUnit); // 0x0049DA30
void __cdecl sub_0049DA50_ClearFlag(); // 0x0049DA50
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __fastcall sub_00475FF0_SetViewDirty(D2ViewStrc* pView); // 0x00475FF0
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
static __declspec(noinline) void sub_00466DE0_SetHoverUnit(D2UnitStrc* pUnit);
int __fastcall sub_00463EE0_IsPointInTileRect(D2UnitStrc* pUnit, int nX, int nY); // 0x00463EE0
int __cdecl sub_0044BF30(); // 0x0044BF30
int __cdecl sub_0044DAA0(); // 0x0044DAA0
unsigned int __cdecl sub_0044DAC0(); // 0x0044DAC0
void __fastcall sub_0044DAD0(int nValue); // 0x0044DAD0

static __declspec(noinline) int __stdcall sub_00467000_CheckWarpTileHover(D2UnitStrc* pPlayer, D2HoverCoordStrc tY1, int nX2, int nY2, D2UnitStrc* pUnit, int nX1, int* pnFlag);

int gdwGlobal_007A6A94; // 0x007A6A94

static int gnSelectedUnitType_007A6A8C; // 0x007A6A8C

static unsigned int gnSelectedUnitId_007A6A78; // 0x007A6A78

static __forceinline unsigned int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x00466DE0
static void sub_00466DE0_SetHoverUnit(D2UnitStrc* pUnit)
{
    char szBuffer[0x200];

    if (gdwGlobal_007A6A98)
    {
        return;
    }

    if (sub_004A0000() && sub_0049E8B0_GetTextUnit() == pUnit)
    {
        sub_0049DA30(pUnit);
        return;
    }

    sub_0049DA50_ClearFlag();

    int bSame = 0;
    int nHoverType;
    unsigned int nHoverId;
    if (pUnit)
    {
        D2_ASSERT(sub_00466870(pUnit, 0, 0, 0), 0x4F);
        nHoverType = pUnit->dwUnitType;
        nHoverId = pUnit->dwUnitId;
    }

    if (pUnit && gdwGlobal_007A6A94 && nHoverType == gnSelectedUnitType_007A6A8C && nHoverId == gnSelectedUnitId_007A6A78)
    {
        bSame = 1;
    }

    if (!bSame && gdwGlobal_007A6A94 && gnSelectedUnitType_007A6A8C == 5)
    {
        D2UnitStrc* pOld = sub_00463990(gnSelectedUnitId_007A6A78, 5);
        if (pOld)
        {
            DUNGEON_UpdateWarpRoomDeselect(UNITS_GetRoom(pOld), pOld->dwClassId);
            sub_00475FF0_SetViewDirty(gpView_007A0640);
        }
    }

    if (!pUnit)
    {
        gdwGlobal_007A6A94 = 0;
        return;
    }

    nHoverType = pUnit->dwUnitType;
    nHoverId = UNITS_GetUnitIdInline(pUnit);
    gnSelectedUnitType_007A6A8C = nHoverType;
    gnSelectedUnitId_007A6A78 = nHoverId;
    gdwGlobal_007A6A94 = 1;

    switch (gnSelectedUnitType_007A6A8C)
    {
    case 5:
        if (!bSame)
        {
            DUNGEON_UpdateWarpRoomSelect(UNITS_GetRoom(pUnit), !pUnit ? -1 : pUnit->dwClassId);
            sub_00475FF0_SetViewDirty(gpView_007A0640);
        }
        break;

    case 2:
        if (!UnitIsDoor(pUnit) || pUnit->dwAnimMode == 4)
        {
            break;
        }

    {
        const unsigned int dwTick = GetTickCount();
        if (dwTick - pUnit->dwTickCount <= 0x1F4)
        {
            break;
        }

        sprintf(szBuffer, "msg at %d\n", dwTick);
        OutputDebugStringA(szBuffer);
        pUnit->dwTickCount = dwTick;
        sub_00478680_SendPacket5(0x3D, gnSelectedUnitId_007A6A78);
        break;
    }

    case 1:
        if (!bSame)
        {
            const int nClassId = pUnit->dwClassId;
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pMonStatsTxtRecord)
            {
                D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
                if (pMonStats2TxtRecord
                    && !(pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
                    && pMonStatsTxtRecord->nAlign != 1
                    && (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[1]))
                {
                    if (!(pMonStats2TxtRecord->nFlags[2] & gdwBitMasks[1]))
                    {
                        gdwGlobal_00711F94 = nClassId;
                    }
                    gdwGlobal_00711F90 = nClassId;
                }
            }
        }
        break;
    }
}

void __fastcall sub_00467A70_RefreshHoverUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (sub_00466870(pUnit, 0, 0, 0))
        {
            gdwGlobal_007A6A98 = 0;
            sub_00466DE0_SetHoverUnit(pUnit);
            gdwGlobal_007A6A98 = 1;
        }
        else
        {
            gdwGlobal_007A6A98 = 0;
            gdwGlobal_007A6A94 = 0;
        }
    }
    else
    {
        gdwGlobal_007A6A94 = 0;
        gdwGlobal_007A6A98 = 1;
    }
}

int gdwGlobal_007A6AA0; // 0x007A6AA0

// 0x00467000
static int __stdcall sub_00467000_CheckWarpTileHover(D2UnitStrc* pPlayer, D2HoverCoordStrc tY1, int nX2, int nY2, D2UnitStrc* pUnit, int nX1, int* pnFlag)
{
    if (pUnit && pUnit->dwUnitType == 5
        && sub_00463EE0_IsPointInTileRect(pUnit, nX1, tY1.nValue)
        && sub_00463EE0_IsPointInTileRect(pUnit, nX2, nY2)
        && UNITS_IsInMovingMode(pPlayer)
        && sub_0044BF30())
    {
        if (sub_0044DAA0() < sub_0044DAC0())
        {
            sub_0044DAD0(sub_0044DAA0() + 0x1F4);
            return 1;
        }

        if (!*pnFlag)
        {
            sub_0044DAD0(sub_0044DAA0() + 0x1F4);
            *pnFlag = 1;
        }
    }

    return 0;
}

int __stdcall sub_662F_Emit_00467AC0(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nPX, int nPY, int nX, int nY)
{
    D2HoverCoordStrc tY1;
    tY1.nValue = nPY;
    return sub_00467000_CheckWarpTileHover(pPlayer, tY1, nX, nY, pUnit, nPX, &gdwGlobal_007A6AA0);
}
