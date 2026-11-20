#include "D2Structs.h"
struct D2UnitEventStrc
{
    char unk0x00[0x1C];
    D2UnitEventStrc* pNext;
};


struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x005C0A90
void __fastcall SUNITEVENT_FreeEventList(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2UnitEventStrc* pUnitEvent = pUnit->pSrvUnitEventsList;
    while (pUnitEvent)
    {
        D2UnitEventStrc* pNext = pUnitEvent->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pUnitEvent, ".\\UNIT\\SUnitEvent.cpp", 61, 0);
        pUnitEvent = pNext;
    }

    pUnit->pSrvUnitEventsList = 0;
}
