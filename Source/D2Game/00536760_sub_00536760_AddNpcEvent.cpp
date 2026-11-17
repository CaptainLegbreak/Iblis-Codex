struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2NpcEventStrc
{
    D2UnitStrc* pUnit;
    int field_4;
    int field_8;
    int field_C;
    D2NpcEventStrc* pNext;
};

struct D2NpcTradeStrc
{
    unsigned char bVendorInit;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char bTrader;
    int unk0x04;
    unsigned int dwTick;
};

struct D2NpcRecordStrc
{
    int nNPC;
    void* pInventory;
    void* pGamble;
    int bGambleInit;
    int unk0x10;
    D2NpcEventStrc* pEvent;
    int unk0x18;
    int bTrading;
    D2NpcTradeStrc tTrade;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                   // 0x006CC260
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0

// 0x00536760
static void __stdcall sub_00536760_AddNpcEvent(D2UnitStrc* pUnit, int nParam, int nAction, D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord)
{
    D2NpcEventStrc* pNpcEvent = (D2NpcEventStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2NpcEventStrc), ".\\UNIT\\sunitproxy.cpp", 0x263, 0);
    pNpcEvent->pNext = pNpcRecord->pEvent;
    pNpcEvent->pUnit = pUnit;
    pNpcEvent->field_C = 0;
    pNpcEvent->field_8 = nParam;
    pNpcEvent->field_4 = nAction;
    pNpcRecord->pEvent = pNpcEvent;
}

// 0x005367B0
void __fastcall sub_005367B0_QueueTradeEvent(D2UnitStrc* pNpc, D2GameStrc* pGame, D2UnitStrc* pUnit, int nParam, int nAction)
{
    const unsigned long dwTick = GetTickCount();
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
    if (pNpcRecord)
    {
        D2NpcTradeStrc* pTrade = &pNpcRecord->tTrade;
        if (pTrade && pTrade->bTrader == 1 && pTrade->bVendorInit == 1 && pNpcRecord->bTrading == 1)
        {
            sub_00536760_AddNpcEvent(pUnit, nParam, nAction, pGame, pNpcRecord);
            pTrade->dwTick = dwTick;
        }
    }
}
