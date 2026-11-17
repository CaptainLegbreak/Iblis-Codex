#pragma pack(push, 1)
struct D2HintCursorStrc
{
    char unk0x00[0x3E];
    unsigned char bFlag3E;
    char unk0x3F;
    unsigned char nRefreshCount;
};

struct D2HintTimerStrc
{
    int f_0;
};

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x1C];
    D2HintTimerStrc tTimer;
    char unk0x2C[0x4];
    int nState;
    char unk0x34[0x9];
    int f_3D;
    char unk0x41[0x4];
    int nArg45;
    char unk0x49[0x4];
    int nArg4D;
};
#pragma pack(pop)

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* f_0;
    D2TimedHintNodeStrc* pNext;
};

struct D2UnitStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0
void __fastcall sub_004CA8D0_NotifyUnitHint(D2UnitStrc* pOther, D2UnitStrc* pUnit);                         // 0x004CA8D0
void __fastcall sub_00516980_UpdateHintTimer(D2HintTimerStrc* pTimer, D2UnitStrc* pOther);                  // 0x00516980
extern D2TimedHintNodeStrc* gpTimedHintList_007C5458;                                                       // 0x007C5458

// 0x004BA760
static __declspec(noinline) void sub_004BA760_RefreshHint(D2TimedHintEntryStrc* pEntry)
{
    D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
    pEntry->f_3D = 1;
    unsigned char nCount = pCursor->nRefreshCount;
    if (nCount && pEntry->nState == 1)
    {
        sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
    }
}

// 0x004BA790
void __fastcall sub_004BA790_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce)
{
    D2_ASSERT(pUnit && pOther, 0xCE);
    sub_004CA8D0_NotifyUnitHint(pOther, pUnit);
    D2TimedHintNodeStrc* pNode;
    D2TimedHintEntryStrc* pEntry;
    for (pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        pEntry = pNode->f_0;
        if (pEntry->nKey == (int)pUnit)
            break;
    }
    if (!pNode)
        return;
    D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
    sub_00516980_UpdateHintTimer(&pEntry->tTimer, pOther);
    const int bReady = !pCursor->bFlag3E || (pEntry->nArg45 && !pEntry->nArg4D) ? 1 : 0;
    if (pEntry->tTimer.f_0)
        return;
    if (!bForce && bReady)
        return;
    sub_004BA760_RefreshHint(pEntry);
}
