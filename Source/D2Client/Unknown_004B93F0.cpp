#include "D2ClientUi.h"

#pragma pack(push, 1)
struct D2TimedHintEntryStrc
{
    int bUsed;
    int nHintId;
    int nKey;
    char unk0x0C[0x20];
    void* f_2C;
    int nState;
    char unk0x34[0x09];
    int f_3D;
    char unk0x41[0x18];
};
#pragma pack(pop)

typedef char check_size_hintentry[(sizeof(D2TimedHintEntryStrc) == 0x59) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void __fastcall sub_00516950_LinkEntry(D2TimedHintNodeStrc** ppList, D2TimedHintEntryStrc* pEntry);       // 0x00516950
int __fastcall sub_004B9590(int nKey);                                                                      // 0x004B9590
int __fastcall sub_004DFA40_IsSoundPlaying(void* pSound);                                                   // 0x004DFA40
int __fastcall sub_004DF900_GetSoundPosition(void* pSound);                                                 // 0x004DF900
D2HintCursorStrc* __fastcall sub_00481860(int nId);                                                         // 0x00481860
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0
int __cdecl sub_004817F0();                                                                                 // 0x004817F0
int __cdecl sub_00481800();                                                                                 // 0x00481800

D2TimedHintEntryStrc gaHintEntries_007C0ED0[200];                                                           // 0x007C0ED0
extern D2TimedHintNodeStrc* gpTimedHintList_007C5458;                                                       // 0x007C5458
extern "C" { int gnSoundSerial_007C5460; }                                                                  // 0x007C5460

// 0x004B93F0
D2TimedHintEntryStrc* __cdecl sub_004B93F0_AllocHintEntry()
{
    for (int i = 0; i < 200; ++i)
    {
        D2TimedHintEntryStrc* pEntry = &gaHintEntries_007C0ED0[i];
        if (!pEntry->bUsed)
        {
            memset(pEntry, 0, sizeof(D2TimedHintEntryStrc));
            pEntry->bUsed = 1;
            sub_00516950_LinkEntry(&gpTimedHintList_007C5458, pEntry);
            gnSoundSerial_007C5460 += 1;
            pEntry->nKey = gnSoundSerial_007C5460;
            return pEntry;
        }
    }

    return 0;
}

// 0x004B95C0
int __fastcall sub_004B95C0_IsHintPlaying(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                void* pSound = pEntry->f_2C;
                if (pSound && sub_004B9590(nKey) && sub_004DFA40_IsSoundPlaying(pSound))
                {
                    return 1;
                }

                break;
            }
        }
    }

    return 0;
}

// 0x004B9D50
int __fastcall sub_004B9D50_GetPosition(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                D2_ASSERT(pEntry->f_2C, 0x45A);
                return sub_004DF900_GetSoundPosition(pEntry->f_2C);
            }
        }
    }

    return 0;
}

// 0x004BA840
void __fastcall sub_004BA840(int nHandle)
{
    if (nHandle)
    {
        for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nHandle)
            {
                D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
                pEntry->f_3D = 1;
                unsigned char nCount = pCursor->nRefreshCount;
                if (nCount && pEntry->nState == 1)
                {
                    sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
                }

                return;
            }
        }
    }
}

// 0x004BA8F0
void __cdecl sub_004BA8F0()
{
    D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458;
    if (!gpTimedHintList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nHintId >= sub_004817F0() && pEntry->nHintId <= sub_00481800())
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}

// 0x004BAA50
void __cdecl sub_004BAA50_RefreshHintRange()
{
    for (D2TimedHintNodeStrc* pNode = gpTimedHintList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (pEntry->nHintId >= 0xB76 && pEntry->nHintId <= 0x1230)
        {
            D2HintCursorStrc* pCursor = sub_00481860(pEntry->nHintId);
            pEntry->f_3D = 1;
            unsigned char nCount = pCursor->nRefreshCount;
            if (nCount && pEntry->nState == 1)
            {
                sub_004B9EF0_ArmHint(pEntry->nKey, 0, 0, nCount);
            }
        }
    }
}
