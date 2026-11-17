struct D2DynamicPathStrc;
struct D2AnimSeqTxt;

struct T00552FD0
{
    char unk0x00[0x10];
    unsigned char pFrameFlags[0x90];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    D2DynamicPathStrc* pDynamicPath;
    D2AnimSeqTxt* pAnimSeq;
    int dwSeqFrameCount;
    int dwSeqFrame;
    int dwSeqSpeed;
    int dwSeqMode;
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    char unk0x4E[0x02];
    T00552FD0* pAnimData;
};

struct D2GameStrc
{
    char unk0x00[0xA8];
    int dwGameFrame;
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent);        // 0x006634C0

#define EVENTTYPE_MODECHANGE 0
#define EVENTTYPE_ENDANIM 1

// 0x00553B10
void __fastcall sub_00553B10(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    const int nCalc = (100 - a3) * (nFrame - (pUnit->nSeqCurrentFramePrecise >> 8)) / 100;
    pUnit->nSeqCurrentFramePrecise = (nFrame - nCalc) << 8;

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

    {
        T00552FD0* pAnimData = pUnit->pAnimData;
        int nIndex = nCalc - 1;
        int nAnimFrame = nCalc << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}
