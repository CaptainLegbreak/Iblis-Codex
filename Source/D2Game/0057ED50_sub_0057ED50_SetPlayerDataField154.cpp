struct D2PlayerDataStrc
{
    char unk0x000[0x154];
    int nField154;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2PlayerDataStrc* pPlayerData;
};

// 0x0057ED50
void __fastcall sub_0057ED50_SetPlayerDataField154(D2UnitStrc* pUnit, int nValue)
{
    if (pUnit && pUnit->dwUnitType == 0 && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nField154 = nValue;
    }
}
