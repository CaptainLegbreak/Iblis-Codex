#include "D2ClientUi.h"
#include "D2ClientSound.h"
#include "D2HintKeyList.h"
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TimedHintEntryStrc;
struct D2TimedHintNodeStrc;
struct D2HintKeyListStrc;

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
    unsigned char unk_59[0x3];
};

D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860
int __fastcall SOUNDHDR_GetGroupStart(int nId); // 0x00481890
void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
extern D2TimedHintNodeStrc* gpClientSoundList; // 0x007C5458
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820
void __fastcall sub_004B9B50_SetValue(int nKey, int nValue); // 0x004B9B50

static void __fastcall CLIENT_ArmHintInline(int nKey, int nGroup, int nOffset, unsigned int nCount)
{
    if (!nKey)
    {
        return;
    }
    D2TimedHintNodeStrc* pHead = gpClientSoundList;
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

    D2SoundsTxt* pSoundTxt = SOUNDHDR_GetSoundRecord(pEntry->nHintId);
    if (nGroup == 0xFF)
    {
        if (pSoundTxt->nFadeIn > nCount)
        {
            nCount = pSoundTxt->nFadeIn;
        }
    }
    else if (!nGroup)
    {
        if (pSoundTxt->nFadeOut > nCount)
        {
            nCount = pSoundTxt->nFadeOut;
        }
    }

    if (*(int*)pEntry->bArmed)
    {
        if (nGroup == *(int*)pEntry->nGroup && DLIGHTMAP_GetSoundTick() + nOffset + nCount >= *(unsigned int*)pEntry->nEnd)
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

    unsigned int nStart = DLIGHTMAP_GetSoundTick() + nOffset;
    *(unsigned int*)pEntry->nStart = nStart;
    *(int*)pEntry->nSavedValue = pEntry->nValue;
    *(int*)pEntry->nGroup = nGroup;
    *(unsigned int*)pEntry->nEnd = nStart + nCount;
    *(int*)pEntry->bArmed = 1;
}

// 0x004BAAB0
void __cdecl sub_004BAAB0_RefreshGroupTimers()
{
    for (D2TimedHintNodeStrc* pNode = gpClientSoundList; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        D2SoundsTxt* pSoundTxt = SOUNDHDR_GetSoundRecord(pEntry->nHintId);
        *(int*)pEntry->f_3D = 1;
        unsigned char nCount = pSoundTxt->nFadeOut;
        if (nCount && pEntry->nState == 1)
        {
            CLIENT_ArmHintInline(pEntry->nKey, 0, 0, nCount);
        }
    }
}
