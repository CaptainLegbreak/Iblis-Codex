struct D2UnitStrc;
struct D2GameStrc;

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

D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit);                                    // 0x00553980

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
