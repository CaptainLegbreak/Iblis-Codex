#include "D2Client.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;
struct D2HintCursorStrc;
struct D2HintKeyListStrc;
struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __cdecl sub_00463DF0(); // 0x00463DF0
void __cdecl sub_0048A6F0_ClearValue(); // 0x0048A6F0
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __fastcall sub_004B8020(void* pRes); // 0x004B8020
D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370(void* pPanel, int nValue); // 0x004B8370
void __fastcall sub_004B85F0_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8); // 0x004B85F0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __cdecl sub_004B8A30_OnCancel(); // 0x004B8A30
int __cdecl sub_004B8A80_OnClose(); // 0x004B8A80
extern D2ClientDialogStrc* gpDialog_007C0E6C; // 0x007C0E6C
extern unsigned long gdwTick_007C0E70; // 0x007C0E70
extern unsigned long gdwGlobal_007C0E78; // 0x007C0E78
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __cdecl sub_004B8BA0_OnClose2(); // 0x004B8BA0

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

extern D2ClientDialogStrc* gpDialog_007C0E64;

extern unsigned long gdwGlobal_007C0E68;

extern char gbGlobal_007C0E74;

extern int gnGlobal_007C0E7C;

extern char gbGlobal_007C0E80;

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

