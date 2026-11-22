#include "D2Client.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HintCursorStrc;
struct D2HintKeyListStrc;
struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2HintKeyListStrc
{
    int unk0x00;
    int nCount;
};

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x10];
    int nValue;
    char unk0x20[8];
    D2HintKeyListStrc* pKeyList;
    int unk0x2C;
    int nState;
    char unk0x34[9];
    char f_3D[4];
    char unk0x41[4];
    char bArmed[4];
    char nSavedValue[4];
    char nGroup[4];
    char nStart[4];
    char nEnd[4];
};

int __cdecl sub_00481820(); // 0x00481820
D2HintCursorStrc* __fastcall sub_00481860(int nId); // 0x00481860
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue); // 0x004B9B50
extern D2TimedHintNodeStrc* gpTimedHintList_007C5458; // 0x007C5458

int __fastcall SOUNDHDR_GetGroupStart(int nId); // 0x00481890

// 0x004B9EF0
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount)
{
    if (!nKey)
    {
        return;
    }
    D2TimedHintNodeStrc* pHead = gpTimedHintList_007C5458;
    D2TimedHintNodeStrc* pNode = pHead;
    if (!pHead)
    {
        return;
    }

    D2TimedHintEntryStrc* pEntry;
    for (; pNode; pNode = pNode->pNext)
    {
        pEntry = pNode->pEntry;
        if (pEntry->nKey == nKey)
        {
            break;
        }
    }
    if (!pNode)
    {
        return;
    }

    for (pNode = pHead; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pOther = pNode->pEntry;
        if (pOther->nKey == nKey)
        {
            D2HintKeyListStrc* pKeyList = pOther->pKeyList;
            if (pKeyList && pKeyList->nCount)
            {
                return;
            }
            break;
        }
    }

    D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
    if (nGroup == 0xFF)
    {
        if (pCursor->nRefreshCountAll > nCount)
        {
            nCount = pCursor->nRefreshCountAll;
        }
    }
    else if (!nGroup)
    {
        if (pCursor->nRefreshCount > nCount)
        {
            nCount = pCursor->nRefreshCount;
        }
    }

    if (*(int*)pEntry->bArmed)
    {
        if (nGroup == *(int*)pEntry->nGroup && sub_00481820() + nOffset + nCount >= *(unsigned int*)pEntry->nEnd)
        {
            return;
        }

        if (!*(int*)pEntry->nGroup && nGroup)
        {
            return;
        }
    }

    if (!nGroup)
    {
        *(int*)pEntry->f_3D = 1;
    }

    if (!nCount)
    {
        D2_ASSERT(!nOffset, 0x25C);
        sub_004B9B50_SetValue(nKey, nGroup);
        return;
    }

    unsigned int nStart = sub_00481820() + nOffset;
    *(unsigned int*)pEntry->nStart = nStart;
    *(int*)pEntry->nSavedValue = pEntry->nValue;
    *(int*)pEntry->nGroup = nGroup;
    *(unsigned int*)pEntry->nEnd = nStart + nCount;
    *(int*)pEntry->bArmed = 1;
}

// 0x004BA890
void __fastcall sub_004BA890_RefreshHintsById(int nHintId)
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nHintId == nHintId)
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            *(int*)pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}


// 0x004BA950
void __fastcall sub_004BA950_RefreshHintsInRangeA(int nGroupA, int nGroupB)
{
    D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458;
    if (!gpTimedHintList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (SOUNDHDR_GetGroupStart(pEntry->nHintId) != nGroupA && SOUNDHDR_GetGroupStart(pEntry->nHintId) != nGroupB
            && pEntry->nHintId >= 0x34 && pEntry->nHintId <= 0x47)
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            *(int*)pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}


// 0x004BA9D0
void __fastcall sub_004BA9D0_RefreshHintsInRangeB(int nGroupA, int nGroupB)
{
    D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458;
    if (!gpTimedHintList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (SOUNDHDR_GetGroupStart(pEntry->nHintId) != nGroupA && SOUNDHDR_GetGroupStart(pEntry->nHintId) != nGroupB
            && pEntry->nHintId >= 0x48 && pEntry->nHintId <= 0xC9)
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            *(int*)pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}

