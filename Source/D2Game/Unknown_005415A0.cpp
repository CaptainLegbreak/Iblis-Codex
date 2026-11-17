#include "D2Game.h"

struct Data00541860;
struct Unit00541860;

struct D2EventTimerStrc
{
    unsigned char nEventType;
    char padding0x01;
    unsigned short nFlags;
    int nExpireFrame;
    D2UnitStrc* pUnit;
    int nUnitGUID;
    int nUnitType;
    int dwEventCustomId;
    int dwEventCustomParam;
    D2EventTimerStrc* pNextFreeEventTimer;
    D2EventTimerStrc* unk0x20;
    D2EventTimerStrc* pNext;
};

D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980

struct Data00541860 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwValue28;
};

struct Unit00541860 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00541860* pData;
};

// 0x005415A0
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    int nEventFrame = 0;
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEvent)
        {
            const int nFrame = pEventTimer->nExpireFrame;
            if (nFrame > 0 && (nFrame < nEventFrame || !nEventFrame))
            {
                nEventFrame = nFrame;
            }
        }
        pEventTimer = pNext;
    }
    return nEventFrame;
}

// 0x00541860
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00541860(Unit00541860* pUnit) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        return pUnit->pData->dwValue28;
    }
    return 0;
}
