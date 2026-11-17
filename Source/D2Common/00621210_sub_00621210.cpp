struct D2AnimSeqTxt;

struct D2AnimDataRecordStrc
{
    char szAnimDataName[8];
    unsigned int dwFrames;
    int dwAnimSpeed;
    unsigned char pFrameFlags[144];
};

struct D2UnitStrc
{
    char unk0x00[0x30];
    D2AnimSeqTxt* pAnimSeq;
    int dwSeqFrameCount;
    int dwSeqFrame;
    int dwSeqSpeed;
    int dwSeqMode;
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    unsigned char nActionFrame;
    char unk0x4F[0x01];
    D2AnimDataRecordStrc* pAnimData;
    char unk0x54[0x70];
    unsigned int dwFlags;
};

void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt* pMonSeqTxt, int nTargetFramePoint, int nCurrentFramePoint, int* pMode, int* pFrame, int* pDirection, int* pEvent); // 0x00663410
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0
int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit);                                          // 0x006633D0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit);                                                // 0x006633F0
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit);                                                       // 0x00623B10

// 0x00621210
static int __stdcall sub_00621210(D2UnitStrc* pUnit, int nPrevFrame)
{
    const int nOldMode = pUnit->dwSeqMode;
    int nFrame;
    int nDirection;
    int nEvent;
    DATATBLS_ComputeSequenceAnimation(pUnit->pAnimSeq, pUnit->dwSeqFrame, nPrevFrame, &nPrevFrame, &nFrame, &nDirection, &nEvent);
    pUnit->nSeqCurrentFramePrecise = nFrame << 8;
    pUnit->dwSeqMode = nPrevFrame;
    pUnit->nActionFrame = nEvent;
    return nPrevFrame != nOldMode;
}

// 0x00621260
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->pAnimSeq = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
        if (pUnit->pAnimSeq)
        {
            pUnit->dwSeqFrameCount = DATATBLS_GetSeqFramePointsCount(pUnit);
            pUnit->dwSeqFrame = 0;
            pUnit->dwSeqSpeed = 0x100;
            pUnit->dwFrameCountPrecise = DATATBLS_GetSeqFrameCount(pUnit) << 8;
            sub_00621210(pUnit, 0);
            pUnit->dwFlags |= 0x4000;
        }
    }
}

void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit)
{
    pUnit->nActionFrame = 0;

    if (pUnit->pAnimSeq)
    {
        const int nOldFrame = pUnit->dwSeqFrame;
        pUnit->dwFlags &= ~0x4000;
        pUnit->dwSeqFrame += pUnit->dwSeqSpeed;
        if (pUnit->dwSeqFrame >= pUnit->dwSeqFrameCount)
            pUnit->dwSeqFrame -= pUnit->dwSeqFrameCount;
        pUnit->dwFrameCountPrecise -= pUnit->dwSeqSpeed;
        if (sub_00621210(pUnit, nOldFrame))
            pUnit->dwFlags |= 0x4000;
    }
    else
    {
        int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
        if (pUnit->wAnimSpeed >= 0x100)
            nFrame++;

        pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

        while (pUnit->nSeqCurrentFramePrecise >= pUnit->dwFrameCountPrecise)
        {
            const int nFrameCount = pUnit->dwFrameCountPrecise >> 8;
            for (int i = nFrame; i < nFrameCount; i++)
            {
                if (pUnit->pAnimData && i < 144)
                {
                    if (pUnit->pAnimData->pFrameFlags[i] == 1)
                        pUnit->nActionFrame = 1;
                    if (pUnit->pAnimData->pFrameFlags[i] == 2)
                        pUnit->nActionFrame = 2;
                    if (pUnit->pAnimData->pFrameFlags[i] == 3)
                        pUnit->nActionFrame = 3;
                    if (pUnit->pAnimData->pFrameFlags[i] == 4)
                        pUnit->nActionFrame = 4;
                }
            }
            nFrame = 0;
            pUnit->nSeqCurrentFramePrecise -= pUnit->dwFrameCountPrecise;
            pUnit->nSeqCurrentFramePrecise += UNITS_GetFrameBonus(pUnit) << 8;
        }

        const int nLastFrameReached = pUnit->nSeqCurrentFramePrecise >> 8;
        for (; nFrame <= nLastFrameReached; nFrame++)
        {
            if (pUnit->pAnimData && nFrame < 144)
            {
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 1)
                    pUnit->nActionFrame = 1;
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 2)
                    pUnit->nActionFrame = 2;
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 3)
                    pUnit->nActionFrame = 3;
                if (pUnit->pAnimData->pFrameFlags[nFrame] == 4)
                    pUnit->nActionFrame = 4;
            }
        }
    }
}
