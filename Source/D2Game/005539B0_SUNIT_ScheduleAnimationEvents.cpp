struct D2AnimSeqTxt;

struct D2AnimFrameTableStrc
{
    char unk0x00[0x10];
    unsigned char pFrameFlags[144];
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

struct D2UnitStrc
{
    char unk0x00[0x30];
    void* pAnimSeq;
    int dwSeqFrameCount;
    int dwSeqFrame;
    int dwSeqSpeed;
    int dwSeqMode;
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    short nActionFrame;
    D2AnimFrameTableStrc* pAnimData;
};

enum
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_ENDANIM = 1,
};

int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit);                                                       // 0x00623B10
void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent);        // 0x006634C0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

// 0x005539B0
void __fastcall SUNIT_ScheduleAnimationEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nFrame = pGame->dwGameFrame;
    const int nFrameBonus = UNITS_GetFrameBonus(pUnit) << 8;
    int nAnimFrame = nFrameBonus;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    D2AnimFrameTableStrc* pAnimData = pUnit->pAnimData;
    int nIndex = nFrameBonus >> 8;
    int nParam = 0;
    while (nAnimFrame + nAnimSpeed < nFrameCount)
    {
        ++nFrame;
        nAnimFrame += nAnimSpeed;
        for (int i = nAnimFrame >> 8; nIndex <= i; ++nIndex)
        {
            if (nIndex >= 144)
            {
                break;
            }

            D2AnimSeqTxt* pSequence = (D2AnimSeqTxt*)pUnit->pAnimSeq;
            int nEvent;
            if (pSequence)
            {
                DATATBLS_GetSequenceEvent(pSequence, nIndex << 8, &nEvent);
            }
            else
            {
                nEvent = pAnimData->pFrameFlags[nIndex];
            }

            if (nEvent)
            {
                switch (nEvent)
                {
                case 1:
                case 2:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, nParam);
                    ++nParam;
                    break;

                case 3:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }
            }
        }
    }

    if (nFrame == pGame->dwGameFrame)
    {
        ++nFrame;
    }

    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    pUnit->nSeqCurrentFramePrecise = pGame->dwGameFrame << 8;
}
