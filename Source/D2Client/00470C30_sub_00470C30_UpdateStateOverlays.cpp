struct D2UnitStrc;

struct D2StateNodeStrc
{
    int dwType;
    int unk0x04;
    int nCurrent;
    int nNextOverlay;
    int nNextState;
    int nSpeed;
    int nFrame;
    int nFrames;
    char unk0x20[0x08];
    unsigned int dwDelay;
    unsigned int dwStamp;
    unsigned int f_30;
    char unk0x34[0x04];
    int nStateId;
    int bSelected;
    char unk0x40[0x64];
    D2StateNodeStrc* pNext;
};

struct D2StateOwnerStrc
{
    char unk0x00[0x2C];
    D2StateNodeStrc* pFirst;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260

D2StateOwnerStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                    // 0x00463E10
int __fastcall sub_0046DA60_GetUnitMode(D2UnitStrc* pUnit);                                                 // 0x0046DA60
void __stdcall sub_0046E040_RemoveOverlay(D2UnitStrc* pUnit, D2StateNodeStrc* pNode);                      // 0x0046E040
void __fastcall sub_00470390(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall sub_0063A250(D2UnitStrc* pUnit);                                                              // 0x0063A250

static __declspec(noinline) void __stdcall sub_0046DF40_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode);

static void __stdcall sub_0046DF40_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode)
{
    const int nStateId = pNode->nStateId;
    const int bHasState = STATES_CheckState(pUnit, nStateId);
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 0);
    }
    if (!sub_0063A250(pUnit))
    {
        pNode->nCurrent = 0;
        if (bHasState)
        {
            STATES_ToggleState(pUnit, nStateId, 1);
        }
    }
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 1);
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nStateId && pEntry->dwType == 8)
        {
            pEntry->bSelected = 0;
            pEntry->nCurrent = -1;
        }
    }

    int nNext = 0;
    int nLowest = 0;
    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwType == 8)
        {
            if ((!nNext || pEntry->nStateId < nNext) && pEntry->nStateId > nStateId)
            {
                nNext = pEntry->nStateId;
            }
            if (!nLowest || pEntry->nStateId < nLowest)
            {
                nLowest = pEntry->nStateId;
            }
        }
    }
    if (!nNext)
    {
        nNext = nLowest;
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nNext && pEntry->dwType == 8)
        {
            pEntry->bSelected = 1;
            pEntry->nCurrent = 0;
        }
    }
}

// 0x00470C30
void __fastcall sub_00470C30_UpdateStateOverlays(D2UnitStrc* pUnit)
{
    D2StateNodeStrc* pNode;
    int nNextOverlay;
    D2StateOwnerStrc* pOwner = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pOwner, 0x2FE);

    const unsigned int dwTick = GetTickCount();
    int nOverlay;
    int nState;
    for (;;)
    {
        for (pNode = pOwner->pFirst; pNode; pNode = pNode->pNext)
        {
            if (pNode->dwStamp != dwTick)
            {
                break;
            }
        }
        if (!pNode)
        {
            return;
        }

        pNode->dwStamp = dwTick;
        int bRemove = 0;
        switch (pNode->dwType)
        {
        case 0:
            if (sub_0046DA60_GetUnitMode(pUnit) != pNode->nCurrent)
            {
                bRemove = 1;
            }
            break;

        case 2:
            if (!pNode->nCurrent)
            {
                bRemove = 1;
            }
            break;

        case 1:
            if (!pNode->nCurrent)
            {
                bRemove = 1;
            }
            --pNode->nCurrent;
            break;

        case 6:
            if (!pNode->nCurrent)
            {
                if (GetTickCount() - pNode->f_30 < pNode->dwDelay)
                {
                    continue;
                }
                pNode->nCurrent = 1;
            }
            break;

        case 8:
            if (!STATES_CheckState(pUnit, pNode->nStateId))
            {
                bRemove = 1;
            }
            else if (pNode->bSelected)
            {
                if (pNode->nCurrent >= 50)
                {
                    sub_0046DF40_RecalcStateOverlays(pOwner, pUnit, pNode);
                }
                else
                {
                    ++pNode->nCurrent;
                }
            }
            break;
        }

        if (bRemove)
        {
            sub_0046E040_RemoveOverlay(pUnit, pNode);
            continue;
        }

        pNode->nFrame += pNode->nSpeed;
        if (pNode->nFrame < pNode->nFrames)
        {
            continue;
        }

        switch (pNode->dwType)
        {
        case 5:
            pNode->nSpeed = 0;
            pNode->nFrame = pNode->nFrames - 1;
            pNode->nCurrent = 1;
            break;

        case 2:
            pNode->nCurrent = 0;
            break;

        case 4:
            nOverlay = pNode->nCurrent;
            nNextOverlay = pNode->nNextOverlay;
            sub_0046E040_RemoveOverlay(pUnit, pNode);
            if (nOverlay != -1)
            {
                sub_00470390(pUnit, nOverlay, 3, 0, 0, 0, 0, 0);
            }
            if (nNextOverlay != -1)
            {
                sub_00470390(pUnit, nNextOverlay, 3, 0, 0, 0, 0, 0);
            }
            break;

        case 9:
            nOverlay = pNode->nCurrent;
            nNextOverlay = pNode->nNextOverlay;
            nState = pNode->nNextState;
            sub_0046E040_RemoveOverlay(pUnit, pNode);
            if (!STATES_CheckState(pUnit, nState))
            {
                break;
            }
            if (nOverlay != -1)
            {
                sub_00470390(pUnit, nOverlay, 8, 0, nState, 0, 0, 0);
            }
            if (nNextOverlay != -1)
            {
                sub_00470390(pUnit, nNextOverlay, 8, 0, nState, 0, 0, 0);
            }
            break;

        case 1:
        case 3:
        case 8:
            pNode->nFrame -= pNode->nFrames;
            break;

        case 6:
            pNode->nFrame -= pNode->nFrames;
            pNode->nCurrent = 0;
            pNode->f_30 = GetTickCount();
            break;

        case 7:
            sub_0046E040_RemoveOverlay(pUnit, pNode);
            sub_00470390(pUnit, 0x8C, 4, 0, 0x8D, 0x8E, 0, 0);
            break;
        }
    }
}
