struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0xDC];
    D2UnitPacketListStrc* pMsgFirst;
    D2UnitPacketListStrc* pMsgLast;
};

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

// 0x00571790
static __forceinline void sub_00571790_AppendUnitMessage(D2UnitStrc* pUnit, D2UnitPacketListStrc* pMsg)
{
    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

void __fastcall sub_M120_Emit_00571790(D2UnitStrc* pUnit, D2UnitPacketListStrc* pMsg)
{
    sub_00571790_AppendUnitMessage(pUnit, pMsg);
}
