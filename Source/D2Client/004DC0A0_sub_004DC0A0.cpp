struct D2GfxDataStrc;

struct D2CltUnitEventStrc
{
    int nType;
    int f_4;
    int f_8;
    int nParam1;
    int nParam2;
    int nParam3;
    D2CltUnitEventStrc* pPrevious;
    D2CltUnitEventStrc* pNext;
};

struct D2UnitStrc
{
    unsigned int dwUnitType;
    int dwClassId;
    char unk0x08[0x4C];
    D2GfxDataStrc* pGfxData;
    char unk0x58[0x38];
    D2CltUnitEventStrc* pCltTimerList;
};

struct D2RosterInfoStrc
{
    int dwUnitId;
    unsigned int dwPartyFlags;
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

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern unsigned int gdwFadeTick_007C89CC;                                                                   // 0x007C89CC

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
void __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0);                       // 0x0040B3C0
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
D2GfxDataStrc* __cdecl sub_0046EBB0_AllocGfxData();                                                         // 0x0046EBB0
void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg);                                          // 0x00470610
D2RosterInfoStrc** __fastcall sub_0047A310_GetRosterInfoList(int nUnitId);                                  // 0x0047A310
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc* pUnit);                                         // 0x004DC0B0

// 0x004DC0A0
void __cdecl sub_004DC0A0()
{
    gdwFadeTick_007C89CC = 0;
}

// 0x004DC0C0
void __fastcall sub_004DC0C0_FreeCltUnitEvents(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2CltUnitEventStrc* pEvent = pUnit->pCltTimerList;
    while (pEvent)
    {
        D2CltUnitEventStrc* pNext = pEvent->pNext;
        sub_0040B480(sub_004DC0B0_GetUnitMemoryPool(pUnit), pEvent, ".\\UNIT\\CUnitEvent.cpp", 0x2F, 0);
        pEvent = pNext;
    }

    pUnit->pCltTimerList = 0;
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
    case 0:
    case 2:
        sub_00470610_Refresh(pUnit, 0);
        break;

    case 1:
        sub_00470610_Refresh(pUnit, 1);
        break;

    case 3:
    case 4:
        break;

    default:
        D2_ASSERT(0, 0x28);
        break;
    }
}

// 0x004DCF30
void __fastcall sub_004DCF30(D2ViewStrc* pView)
{
    if (pView->pCells)
    {
        sub_0040B3C0(pView->pCells, ".\\GAME\\Wall2.cpp", 0x55, 0);
    }

    pView->pCells = 0;
    pView->nField0xEAB0 = 0;
    pView->nField0xEA9C = 0;
    pView->nField0x38 = 0;
}

// 0x004DDDF0
void __cdecl sub_004DDDF0()
{
}
