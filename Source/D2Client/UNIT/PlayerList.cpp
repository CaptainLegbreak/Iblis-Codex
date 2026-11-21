#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CltUnitEventStrc;
struct D2RosterInfoStrc;


struct D2RosterInfoStrc
{
    int dwUnitId;
    unsigned short wPartyFlags;
    unsigned short wPartyFlagsHigh;
    D2RosterInfoStrc* pNext;
};

struct D2ViewStrc
{
    char unk0x00[0x38];
    int nField0x38;
    char unk0x3C[0xEA60];
    int nField0xEA9C;
    char unk0xEAA0[8];
    void* pCells;
    char unk0xEAAC[4];
    int nField0xEAB0;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern unsigned int gdwFadeTick_007C89CC; // 0x007C89CC
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
D2GfxDataStrc* __cdecl sub_0046EBB0_AllocGfxData(); // 0x0046EBB0
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg); // 0x00470610
D2RosterInfoStrc** __fastcall sub_0047A310_GetRosterInfoList(int nUnitId); // 0x0047A310
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

// 0x004DC0A0
void __cdecl sub_004DC0A0()
{
    gdwFadeTick_007C89CC = 0;
}

// 0x004DC270
D2RosterInfoStrc** __cdecl sub_004DC270_AllocRosterInfoList()
{
    D2RosterInfoStrc** ppRosterInfo = (D2RosterInfoStrc**)FOG_Alloc(sizeof(D2RosterInfoStrc*), ".\\UNIT\\PlayerList.cpp", 0x25, 0);
    D2_ASSERT(ppRosterInfo, 0x27);
    *ppRosterInfo = 0;
    return ppRosterInfo;
}

// 0x004DC320
void __fastcall sub_004DC320_AddRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    D2RosterInfoStrc** ppSearch = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (ppSearch)
    {
        for (D2RosterInfoStrc* pRosterInfo = *ppSearch; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
        {
            if (pRosterInfo->dwUnitId == nUnitId2)
            {
                return;
            }
        }
    }

    D2RosterInfoStrc* pNew = (D2RosterInfoStrc*)FOG_Alloc(sizeof(D2RosterInfoStrc), ".\\UNIT\\PlayerList.cpp", 0x74, 0);
    memset(pNew, 0, sizeof(D2RosterInfoStrc));
    pNew->dwUnitId = nUnitId2;
    pNew->pNext = *ppRosterInfo;
    *ppRosterInfo = pNew;
}

// 0x004DC510
void __fastcall sub_004DC510_InitGfxData(D2UnitStrc* pUnit)
{
    pUnit->pGfxData = sub_0046EBB0_AllocGfxData();
    D2_ASSERT(pUnit->pGfxData, 0x16);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_OBJECT:
        sub_00470610_Refresh(pUnit, 0);
        break;

    case UNIT_MONSTER:
        sub_00470610_Refresh(pUnit, 1);
        break;

    case UNIT_MISSILE:
    case UNIT_ITEM:
        break;

    default:
        D2_ASSERT(0, 0x28);
        break;
    }
}

// 0x004DDDF0
void __cdecl sub_004DDDF0()
{
}

// 0x004DC0B0
D2RosterInfoStrc* __fastcall sub_004DC0B0_GetNextRosterInfo(D2RosterInfoStrc* pRosterInfo)
{
    if (!pRosterInfo)
    {
        return 0;
    }
    return pRosterInfo->pNext;
}

// 0x004DC2B0
void __fastcall sub_004DC2B0_FreeRosterInfoList(D2RosterInfoStrc** ppRosterInfo)
{
    if (ppRosterInfo)
    {
        D2RosterInfoStrc* pRosterInfo = *ppRosterInfo;
        while (pRosterInfo)
        {
            D2RosterInfoStrc* pNext = pRosterInfo->pNext;
            FOG_Free(pRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x3C, 0);
            pRosterInfo = pNext;
        }
        FOG_Free(ppRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x40, 0);
    }
}

// 0x004DC2F0
static inline D2RosterInfoStrc* sub_004DC2F0_FindRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo;
        }
    }
    return 0;
}

D2RosterInfoStrc* __stdcall sub_M121_Emit_004DC2F0(int nUnitId1, int nUnitId2) { return sub_004DC2F0_FindRosterInfo(nUnitId1, nUnitId2); }

// 0x004DC380
void __fastcall sub_004DC380_RemoveRosterInfo(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    D2RosterInfoStrc* pPrevious = 0;
    if (!ppRosterInfo)
    {
        return;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pRosterInfo->pNext;
            }
            else
            {
                *ppRosterInfo = pRosterInfo->pNext;
            }
            FOG_Free(pRosterInfo, ".\\UNIT\\PlayerList.cpp", 0x97, 0);
            return;
        }
        pPrevious = pRosterInfo;
    }
}

// 0x004DC480
unsigned short __fastcall sub_004DC480_GetRosterFlags16(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo->wPartyFlags;
        }
    }
    return 0;
}

// 0x004DCA20
int __fastcall sub_004DCA20_Forward(D2UnitStrc* pUnit)
{
    return sub_00471450(pUnit);
}
