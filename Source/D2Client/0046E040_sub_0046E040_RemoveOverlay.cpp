extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;

struct D2StateNodeStrc
{
    int dwType;
    int unk0x04;
    int nCurrent;
    char unk0x0C[0x2C];
    int nStateId;
    int bSelected;
    void* pResource;
    char unk0x44[0x60];
    D2StateNodeStrc* pNext;
};

struct D2StateOwnerStrc
{
    char unk0x00[0x2C];
    D2StateNodeStrc* pFirst;
};

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall sub_0063A250(D2UnitStrc* pUnit);                                                              // 0x0063A250

// 0x0046DF40
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

extern "C" const char gszGfxFile_006D6C1C[];                                                                // 0x006D6C1C
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2StateOwnerStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit);                                    // 0x00463E10
void __fastcall sub_004743D0_ReleaseOverlayResource(void* pResource);                                       // 0x004743D0

static __declspec(noinline) void __stdcall sub_0046E040_RemoveOverlay(D2UnitStrc* pUnit, D2StateNodeStrc* pOverlay);

// 0x0046E040
static void __stdcall sub_0046E040_RemoveOverlay(D2UnitStrc* pUnit, D2StateNodeStrc* pOverlay)
{
    D2StateOwnerStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x1BF);

    D2StateNodeStrc* pPrevious = 0;
    D2StateNodeStrc* pNode = pGfxData->pFirst;
AdvanceToNextNode:
    if (pNode && pNode != pOverlay)
    {
        pPrevious = pNode;
        pNode = pNode->pNext;
        goto AdvanceToNextNode;
    }

    if (!pNode)
    {
        return;
    }

    if (pNode->pResource)
    {
        sub_004743D0_ReleaseOverlayResource(pNode->pResource);
        pNode->pResource = 0;
    }

    if (pPrevious)
    {
        pPrevious->pNext = pNode->pNext;
    }
    else
    {
        pGfxData->pFirst = pNode->pNext;
    }

    if (pNode->dwType == 8)
    {
        sub_0046DF40_RecalcStateOverlays(pGfxData, pUnit, pNode);
    }

    FOG_Free(pNode, gszGfxFile_006D6C1C, 0x1E1, 0);
}

// build: context sub_0046E040_Shim
// calling-convention shim (not game code)
void __stdcall sub_0046E040_Shim(D2UnitStrc* pUnit, D2StateNodeStrc* pOverlay)
{
    sub_0046E040_RemoveOverlay(pUnit, pOverlay);
}
