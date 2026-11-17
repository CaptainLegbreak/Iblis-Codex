struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
int __fastcall sub_00480C10_UnitEvent(int nEvent, D2UnitStrc* pUnit, int* pArgs, int nFlag);                // 0x00480C10

// 0x004C7630
int __fastcall sub_004C7630(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    int args[7];
    memset(args, 0, sizeof(args));
    args[0] = 0;
    args[1] = -1;
    int nType = 6;
    if (pTarget)
    {
        nType = pTarget->dwUnitType;
    }
    args[2] = nType;
    int nId;
    if (!pTarget)
    {
        nId = -1;
    }
    else
    {
        nId = pTarget->dwUnitId;
    }
    args[3] = nId;
    args[4] = 1;
    sub_00480C10_UnitEvent(0x16, pUnit, args, 1);
    return 1;
}
