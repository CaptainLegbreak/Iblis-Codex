#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ClientMenus.h"
#include "D2Win32Types.h"
#include "D2UnitData.h"
#include "D2Path.h"
#include "D2CelContext.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum
{
    NUM_HOTKEYS = 114,
};

struct D2MsgRecordStrc
{
    int nTick;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
};

struct D2MsgRecordChunkStrc
{
    D2MsgRecordStrc tRecords[500];
    int nCount;
    int nIndex;
    D2MsgRecordChunkStrc* pNext;
};

struct D2PalShiftDataStrc
{
    int unk0x00;
    unsigned char aShift[8][0x100];
    unsigned char aShiftBlood[8][0x100];
};

struct T0044A980
{
    int nId;
    D2PalShiftDataStrc* pData;
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

int __cdecl sub_0044DC60();                                                                                 // 0x0044DC60

int __cdecl sub_0044DA90();                                                                                 // 0x0044DA90

int __fastcall sub_00451880_DispatchMsg(D2MsgRecordStrc* pRecord);                                          // 0x00451880

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0

int __fastcall sub_004638A0_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

int __fastcall sub_00463EB0_GetGfxField38(D2UnitStrc* pUnit);                                               // 0x00463EB0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int gnReplayEndTick_007A2774;                                                                               // 0x007A2774

int gdwGlobal_007A2788;                                                                                     // 0x007A2788

extern int gdwGlobal_007A5208;                                                                              // 0x007A5208

extern int gdwGlobal_007A520C;                                                                              // 0x007A520C

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90

extern D2WheelCallbackFn gpfnWheelUp_007A7404;                                                              // 0x007A7404

extern D2WheelCallbackFn gpfnWheelDown_007A7408;                                                            // 0x007A7408

extern T0044A980* gpPalShiftEntries_007B9578;                                                     // 0x007B9578

extern unsigned char gaGlobalPalShifts_007B9580[0x1E][0x100];                                               // 0x007B9580

extern int gbGlobalPalShifts_007BB380;                                                                      // 0x007BB380

extern D2UnitStrc* gpUnitHashTable_007A5E70[6 * 0x80];                                                    // 0x007A5E70

extern D2UnitStrc* gpUnitHashTable_007A5270[6 * 0x80];                                                    // 0x007A5270

extern D2UnitStrc* gpPlayerUnit_007A6A70;                                                                   // 0x007A6A70

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

struct D2UnitStrc;

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

void __stdcall sub_00643260(int* pX, int* pY);                                                   // 0x00643260

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __fastcall sub_004DAE60_UnitSupportsMode(D2UnitStrc* pUnit, int nMode);                                 // 0x004DAE60

int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0

int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0

int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0

int __stdcall sub_004DA0D0_GetGfxMotionField38(D2UnitStrc* pUnit);                                          // 0x004DA0D0

int __stdcall sub_004DA0F0_GetGfxMotionField3C(D2UnitStrc* pUnit);                                          // 0x004DA0F0

typedef int (__fastcall* SKILLSELECTPROC)(D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

extern SKILLSELECTPROC gpfSkillSelectProcs_00711F34[];                                                      // 0x00711F34

int __stdcall sub_O05_EmitArg_SkillId(D2UnitStrc* pUnit);

// 0x004519C0
void __cdecl sub_004519C0_ReplayRecords()
{
    if (!gdwGlobal_007A2788)
        return;
    if (!gpMsgRecordChunk_0070F7A0)
        return;
    const int nNow = sub_0044DA90();
    if (nNow >= gnReplayEndTick_007A2774)
    {
        gdwGlobal_007A2788 = 0;
        return;
    }
    D2MsgRecordChunkStrc* pChunk = gpMsgRecordChunk_0070F7A0;
    D2_ASSERT(pChunk->nIndex < 500, 0x189);
    if (!pChunk->pNext && pChunk->nCount == pChunk->nIndex)
        return;
    D2MsgRecordStrc* pRecord = &pChunk->tRecords[pChunk->nIndex];
    while (pRecord->nTick <= nNow)
    {
        sub_00451880_DispatchMsg(pRecord);
        pChunk = gpMsgRecordChunk_0070F7A0;
        pChunk->nIndex++;
        if (!pChunk->pNext && pChunk->nCount == pChunk->nIndex)
            return;
        if (pChunk->nIndex >= 500)
        {
            pChunk = pChunk->pNext;
            gpMsgRecordChunk_0070F7A0 = pChunk;
        }
        if (!pChunk)
            return;
        pRecord = &pChunk->tRecords[pChunk->nIndex];
    }
}

// 0x0045B1A0
void __fastcall sub_0045B1A0_DrawDiamond(int nX, int nY, unsigned char nColor)
{
    tagRECT tRect;
    tRect.left = nX - gdwGlobal_007A520C - 0x10;
    tRect.right = nX - gdwGlobal_007A520C + 0x10;
    tRect.top = nY - gdwGlobal_007A5208;
    tRect.bottom = nY - gdwGlobal_007A5208 + 0x10;
    D2GFX_UtilDiamond(&tRect, nColor);
}

// 0x004637F0
unsigned char* __fastcall sub_004637F0_GetMonsterComponents(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent;
    }
    return 0;
}

static __forceinline D2MonStatsTxt* MONSTATS_GetRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static __forceinline int MONSTATS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
        return nClassId;
    return pMonStatsTxtRecord->nBaseId;
}

// 0x00463860
int __fastcall sub_00463860(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return MONSTATS_GetBaseIdInline(pUnit->dwClassId);
    return -1;
}

// 0x00463920
static __forceinline D2UnitStrc** sub_00463920_GetClientHashTable(int nUnitType)
{
    return &gpUnitHashTable_007A5E70[nUnitType * 0x80];
}

// 0x00463930
static __forceinline D2UnitStrc** sub_00463930_GetServerHashTable(int nUnitType)
{
    return &gpUnitHashTable_007A5270[nUnitType * 0x80];
}

// 0x00463C60
static __forceinline void sub_00463C60_RemoveUnitFromRoom(D2UnitStrc* pUnit)
{
    if (gpGlobal_007A0634)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }
}

// 0x00463D70
void __cdecl sub_00463D70_Empty()
{
}

// 0x00463DD0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit()
{
    return gpPlayerUnit_007A6A70;
}

inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00463FE0
static int __stdcall sub_00463FE0_IsInObjectSelectBox(int nY, D2ObjectsTxt* pObjectsTxtRecord, int nX, D2UnitStrc* pUnit)
{
    int nUnitX = UNITS_InlineGetXPosition(pUnit);
    int nUnitY = UNITS_InlineGetYPosition(pUnit);
    sub_00643260(&nUnitX, &nUnitY);

    const int nLeft = pObjectsTxtRecord->dwLeft + nUnitX;
    const int nTop = pObjectsTxtRecord->dwTop + nUnitY;
    if (nX >= nLeft && nY >= nTop && nX <= pObjectsTxtRecord->dwWidth + nLeft && nY <= pObjectsTxtRecord->dwHeight + nTop)
    {
        return 1;
    }

    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    return nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

// 0x004642B0
static int __stdcall sub_004642B0_CheckSkillSelectProc(D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_Inl(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nSelectProc > 0 && pSkillsTxtRecord->nSelectProc < gnSkillSelectProcs_00711F50)
    {
        if (gpfSkillSelectProcs_00711F34[pSkillsTxtRecord->nSelectProc](pPlayer, pTarget))
        {
            return 1;
        }
    }

    return 0;
}

static __forceinline int OBJECTS_IsDeadInline(int nClassId, int nMode)
{
    const unsigned char nFlags = DATATBLS_GetObjectsTxtRecord(nClassId)->nFlags1B7;
    return (nFlags & 2) || (nMode == 2 && (nFlags & 1));
}

// 0x00464860
int __fastcall sub_00464860_IsUnitDead(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMode = pUnit->dwAnimMode;
        switch (pUnit->dwUnitType)
        {
        case UNIT_OBJECT:
            if (OBJECTS_IsDeadInline(pUnit->dwClassId, nMode))
            {
                return 1;
            }
            break;
        case UNIT_ITEM:
            return nMode == 3;
        case UNIT_MONSTER:
            if (!sub_004638A0_CheckMonStats2Flag(pUnit->dwClassId, 0x14) && nMode == 12)
            {
                return 1;
            }
            break;
        case UNIT_PLAYER:
            if (nMode == 17)
            {
                return 1;
            }
            break;
        case UNIT_MISSILE:
            if (pUnit->dwFlags & 0x10000)
            {
                return 1;
            }
            break;
        }
    }
    return 0;
}

// 0x00477530
unsigned char* __fastcall sub_00477530_GetPalShift(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2PalShiftDataStrc* pData = gpPalShiftEntries_007B9578[pUnit->dwClassId].pData;
        if (!pData)
            return 0;
        int nMode = sub_00463EB0_GetGfxField38(pUnit);
        switch (nMode)
        {
        case 0:
        case 1:
            switch (pUnit->dwClassId)
            {
            case 0x16B:
            case 0x16C:
                return pData->aShift[nMode];
            }
            return 0;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        default:
            if (gbGlobalPalShifts_007BB380)
            {
                nMode -= 8;
                D2_ASSERT(nMode >= 0 && nMode < 0x1E, 0x160);
                return gaGlobalPalShifts_007B9580[nMode];
            }
            break;
        }
        if (sub_0044DC60())
        {
            D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2TxtRecord && pMonStats2TxtRecord->nLocalBlood == 2)
                return pData->aShiftBlood[nMode];
        }
        return pData->aShift[nMode];
    }
    return 0;
}

D2UnitStrc* __fastcall sub_M109_Emit_00463920(int nUnitType, int nHash)
{
    return sub_00463920_GetClientHashTable(nUnitType)[nHash] ? sub_00463930_GetServerHashTable(nUnitType)[nHash] : 0;
}

void __fastcall sub_M109_Emit_00463C60(D2UnitStrc* pUnit)
{
    sub_00463C60_RemoveUnitFromRoom(pUnit);
}

int __fastcall sub_Q03_Emit_ObjectSelectBox(D2UnitStrc* pUnit, int nX, int nY)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
    if (pObjectsTxtRecord->nIsDoor)
    {
        return sub_00463FE0_IsInObjectSelectBox(nY, pObjectsTxtRecord, nX, pUnit);
    }

    return 0;
}

static int __stdcall sub_004640A0_GetUnitSelectRect(unsigned int nFrame, D2RectStrc* pRect, D2UnitStrc* pUnit, int nMode)
{
    if (sub_004DAE60_UnitSupportsMode(pUnit, nMode))
    {
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));

        int nOut;
        if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, nMode, -1) && sub_006001F0(&tContext, 0, 1))
        {
            D2CelStrc* pCell = tContext.pCel;
            if (pCell)
            {
                D2_ASSERT(nFrame <= tContext.nFrames, 0x5DF);

                const int nOffsetX = sub_00601920(pCell) - 12;
                pRect->nLeft = nOffsetX + UNITS_GetClientCoordX(pUnit);
                pRect->nRight = sub_006018C0(pCell) + pRect->nLeft + 24;
                const int nTop = sub_00601950(pCell) + UNITS_GetClientCoordY(pUnit) + 12;
                pRect->nTop = nTop;
                pRect->nBottom = nTop - sub_006018F0(pCell) - 24;

                const int nWidth = pRect->nRight - pRect->nLeft;
                if (nWidth < 32)
                {
                    const int nPad = (32 - nWidth) >> 1;
                    pRect->nRight += nPad;
                    pRect->nLeft -= nPad;
                }

                const int nHeight = nTop - pRect->nBottom;
                if (nHeight < 32)
                {
                    const int nPad = (32 - nHeight) >> 1;
                    pRect->nBottom -= nPad;
                    pRect->nTop += nPad;
                }

                const int nGfxOffsetX = sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
                const int nGfxOffsetY = sub_004DA0D0_GetGfxMotionField38(pUnit) + sub_004DA0F0_GetGfxMotionField3C(pUnit);
                pRect->nLeft += nGfxOffsetX;
                pRect->nRight += nGfxOffsetX;
                pRect->nTop += nGfxOffsetY;
                pRect->nBottom += nGfxOffsetY;
                return 1;
            }
        }
    }

    return 0;
}

int __fastcall sub_Q03_Emit_UnitSelectRect(D2UnitStrc* pUnit, int nX)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);

    D2RectStrc tRect;
    for (int nMode = 0; nMode < 16; ++nMode)
    {
        if (sub_004640A0_GetUnitSelectRect(nFrameNo, &tRect, pUnit, nMode) && nX >= tRect.nLeft && nX <= tRect.nRight)
        {
            return 1;
        }
    }

    return 0;
}

int __stdcall sub_O05_Emit_004642B0(D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    if (sub_004642B0_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pPlayer)))
    {
        return 1;
    }

    return sub_004642B0_CheckSkillSelectProc(pPlayer, pTarget, sub_O05_EmitArg_SkillId(pTarget)) != 0;
}

#include "gen/data/Source/D2Client/UNIT/CUnit_004519C0.inc"
