#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum
{
    NUM_HOTKEYS = 114,
};


struct D2MonStatsTxt
{
    short unk0x00;
    short nBaseId;
    char unk0x04[0x1A4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
};

struct D2ObjectsTxt
{
    char unk0x000[0x1B7];
    unsigned char nFlags1B7;
};

struct D2MonStats2Txt
{
    char unk0x000[0x11C];
    unsigned char nLocalBlood;
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

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

struct D2HotkeyStrc
{
    unsigned char nCommand[4];
    unsigned short nKey;
    unsigned char unk0x06[4];
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
